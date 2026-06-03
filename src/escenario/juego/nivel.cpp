#include "nivel.h"

//Items
#include "items/pelota.h"
#include "items/portal.h"
#include "items/obstaculo.h"

// Procesamiento datos
#include <QtMath>

// Durante desarrollo para pruebas
#include <QMessageBox>

Nivel::Nivel(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1366, 768);

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Nivel::actualizarJuego);

    timerPrincipal->start(16);
}

Nivel::~Nivel()
{
}

// Implementación obligatoria para que se pinte el fondoEscalado en la escena
void Nivel::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    if (!fondoEscalado.isNull()) {
        painter->drawPixmap(0, 0, fondoEscalado);
    } else {
        // Fondo gris por defecto si la ruta de la imagen falla
        painter->fillRect(sceneRect(), Qt::gray);
    }
}

void Nivel::aplicarFuerzaTiro(const QPointF &origen, const QPointF &vector)
{
    // El Nivel toma el control total del vector recibido
    double magnitud = qSqrt(vector.x() * vector.x() + vector.y() * vector.y());
    double anguloRadianes = qAtan2(vector.y(), vector.x());
    double anguloGrados = qRadiansToDegrees(anguloRadianes);

    // Construimos el mensaje que se mostrará en el contexto del juego
    QString mensaje = QString(
                          "<h3>[Mensaje desde el OBJETO NIVEL]</h3>"
                          "<b>¡Vector Libre recibido con éxito!</b><br><br>"
                          "<b>Punto Origen en Escena:</b> (%1, %2)<br><br>"
                          "<b>Fuerza en X (Horizontal):</b> %3<br>"
                          "<b>Fuerza en Y (Vertical):</b> %4<br><br>"
                          "<b>Magnitud del Tiro:</b> %5 unidades<br>"
                          "<b>Ángulo de Inclinación:</b> %6°"
                          )
                          .arg(origen.x(), 0, 'f', 1)
                          .arg(origen.y(), 0, 'f', 1)
                          .arg(vector.x(), 0, 'f', 1)
                          .arg(vector.y(), 0, 'f', 1)
                          .arg(magnitud, 0, 'f', 1)
                          .arg(anguloGrados, 0, 'f', 1);

    // Mostramos la ventana utilizando los widgets del sistema pasándole nullptr o la vista activa
    QMessageBox::information(nullptr, "Lógica del Nivel Activa", mensaje);

    // --- TODO
    // El personaje laza la peltota ---


    // Los meotodos estaran desacomplados en principio para reducir el area de test y depuracion
    // pelota->reaccionTiro(vector.x(), vector.y());


}

void Nivel::actualizarJuego()
{
    // Lógica física de tu juego en cada tick del QTimer
}
