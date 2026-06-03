#ifndef JUEGOMODODOSQGRAPHICSVIEW_H
#define JUEGOMODODOSQGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QPixmap>
#include <QPainter>

class Nivel_D;

class JuegoModoDosQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit JuegoModoDosQGraphicsView(QWidget *parent = nullptr);
    ~JuegoModoDosQGraphicsView();



private:
    Nivel_D *nivelActual;
};

#endif // JUEGOMODODOSQGRAPHICSVIEW_H
