#include "nivel_d.h"


// Items de jeugo
// #include "../juego/items/pelota.h"
#include "items/personaje.h"
#include "items/ruedapinchos.h"
#include "items/pelotaroja.h"
#include "items/agenteia.h"
#include "items/bandera.h"
#include "items/centrodepoder.h"
#include "items/cratergris.h"
#include "items/craterhielo.h"
#include "items/craterrojo.h"
#include "items/cronometrotiempo.h"
#include "items/logrosvidas.h"
#include "items/momentopelota.h"
#include "items/pelotablanca.h"
#include "items/portal.h"
#include "items/remolinometa.h"

// CONSTRUCTOR
Nivel_D::Nivel_D(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1366, 768);

    QPixmap imagenFondo(":/resources/imgs/fondo-sin-laberinto2");
    if (!imagenFondo.isNull()) {
        fondoEscalado = imagenFondo.scaled(1366, 768, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }



    PelotaRoja *pelotaRoja = new PelotaRoja;
    this->addItem(pelotaRoja);


    RuedaPinchos *rueda1 = new RuedaPinchos;
    rueda1->setPos(100,50);
    this->addItem(rueda1);


    RuedaPinchos *rueda2 = new RuedaPinchos;
    rueda2->setPos(100,200);
    this->addItem(rueda2);

    AgenteIA *agenteia = new AgenteIA;
    agenteia->setPos(100,200);
    this->addItem(agenteia);

    Bandera *bandera = new Bandera;
    bandera->setPos(100,200);
    this->addItem(bandera);

    CentroDePoder *centrodepoder = new CentroDePoder;
    centrodepoder->setPos(100,200);
    this->addItem(centrodepoder);

    CraterGris *cratergris = new CraterGris;
    cratergris->setPos(100,200);
    this->addItem(cratergris);

    CraterHielo *craterhielo = new CraterHielo;
    craterhielo->setPos(100,200);
    this->addItem(craterhielo);

    CraterRojo *craterrojo = new CraterRojo;
    craterrojo->setPos(100,200);
    this->addItem(craterrojo);

    CronometroTiempo *cronometrotiempo = new CronometroTiempo;
    cronometrotiempo->setPos(100,200);
    this->addItem(cronometrotiempo);

    LogrosVidas *logrosvidas = new LogrosVidas;
    logrosvidas->setPos(100,200);
    this->addItem(logrosvidas);

    MomentoPelota *momentopelota = new MomentoPelota;
    momentopelota->setPos(100,200);
    this->addItem(momentopelota);

    PelotaBlanca *pelotablanca = new PelotaBlanca;
    pelotablanca->setPos(100,200);
    this->addItem(pelotablanca);

    Portal *portal = new Portal;
    portal->setPos(100,200);
    this->addItem(portal);

    RemolinoMeta *remolinometa = new RemolinoMeta;
    remolinometa->setPos(100,200);
    this->addItem(remolinometa);

    Personaje *personaje = new Personaje;
    personaje->setPos(100,200);
    this->addItem(personaje);











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
