#include "juegomododosqgraphicsview.h"
#include <QGraphicsPixmapItem>

// Escena separada
#include "../juego_2/nivel_d.h"

JuegoModoDosQGraphicsView::JuegoModoDosQGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    nivelActual = new Nivel_D(this);

    setScene(nivelActual);

    setRenderHint(QPainter::Antialiasing);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);
}


// Destructor
JuegoModoDosQGraphicsView::~JuegoModoDosQGraphicsView() {}

