#include "juegomodounoqgraphicsview.h"
#include "../juego/nivel.h"

#include <QMessageBox>

JuegoModoUnoQGraphicsView::JuegoModoUnoQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    nivelActual = new Nivel(this);
    // Nivel internamente puede tener un slot para recibir <-- Alternativa
    // el nivel al seleccionar el modo de juego en la ventana previa

    setRenderHint(QPainter::Antialiasing);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);

    // TRUCO CLAVE -> El viewport captura la superficie total, barras y bordes del View
    this->viewport()->installEventFilter(this);

    connect(this, &JuegoModoUnoQGraphicsView::tiroRealizado, nivelActual, &Nivel::aplicarFuerzaTiro);

    setScene(nivelActual);
}

// Destructor
JuegoModoUnoQGraphicsView::~JuegoModoUnoQGraphicsView(){}

// void JuegoModoUnoQGraphicsView::ejecutarNivel() <-- Haremos esto
// {
//     Usaremos un switch para que apartir de una consulta sqlite se ejecute nivel 1 a nivel N
//
//
//     setScene(nivelActual);
//     //  Crearemos un metodo publicos
//     // de nivel para tener distintos niveles ejecutar nivel 1 u n
// }

bool JuegoModoUnoQGraphicsView::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this->viewport()) {

        // PRESIONAR CLICK
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                isLeftClickPressed = true;
                // Guardamos el punto de inicio convertido a la escena del juego
                clickInicialEscena = mapToScene(mouseEvent->pos());
                return true;
            }
        }

        // MOVER EL RATÓN
        else if (event->type() == QEvent::MouseMove) {
            if (isLeftClickPressed) {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                QPointF posActualEscena = mapToScene(mouseEvent->pos());
                // Aquí se puede actualizar una línea guía en el juego
            }
        }

        // SOLTAR CLICK
        else if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton && isLeftClickPressed) {
                isLeftClickPressed = false;

                clickFinalEscena = mapToScene(mouseEvent->pos());

                // Calculamos el vector libre
                QPointF vectorLibre = clickFinalEscena - clickInicialEscena;

                // Emitimos el evento hacia el nivel pasándole toda la física
                emit tiroRealizado(clickInicialEscena, vectorLibre);
                return true;
            }
        }
    }

    return QGraphicsView::eventFilter(obj, event);
}