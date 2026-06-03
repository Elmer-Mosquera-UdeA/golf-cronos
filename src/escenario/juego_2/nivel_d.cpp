#include "nivel_d.h"

// Items de jeugo
// #include "../juego/items/pelota.h"
#include "items/personaje.h"
#include "items/ruedapinchos.h"


// CONSTRUCTOR
Nivel_D::Nivel_D(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1366, 768);

    QPixmap imagenFondo(":/resources/imgs/fondo_juego_m_u.png");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }



    Personaje *personaje1 = new Personaje;
    this->addItem(personaje1);


    RuedaPinchos *rueda1 = new RuedaPinchos;
    rueda1->setPos(100,50);
    this->addItem(rueda1);


    RuedaPinchos *rueda2 = new RuedaPinchos;
    rueda2->setPos(100,200);
    this->addItem(rueda2);










    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, &QTimer::timeout, this, &Nivel_D::actualizarJuego);

    timerPrincipal->start(16);
}


// Destructor
Nivel_D::~Nivel_D()
{
}

void Nivel_D::actualizarJuego()
{


}

void Nivel_D::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica clic
    QGraphicsScene::mousePressEvent(event);
}

void Nivel_D::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica arrastre
    QGraphicsScene::mouseMoveEvent(event);
}

void Nivel_D::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // lógica soltar

    QGraphicsScene::mouseReleaseEvent(event);
}

void Nivel_D::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    painter->drawPixmap(sceneRect().toRect(),fondoEscalado);
}