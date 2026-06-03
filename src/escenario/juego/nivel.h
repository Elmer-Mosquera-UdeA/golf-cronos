#ifndef NIVEL_H
#define NIVEL_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


// items

class Pelota;
class Hoyo;
class Obstaculo;
class Portal;

class Nivel : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Nivel(QObject *parent = nullptr);
    ~Nivel();

    void limpiarNivel();
    void cargarNivel1();

private:
    QTimer *timerPrincipal;
    QPixmap fondoEscalado;

    Pelota *pelota;
    Hoyo *hoyo;

    QList<Obstaculo*> obstaculos;
    QList<Portal*> portales;

    QTimer *timerPrincipal;
    QPixmap fondoEscalado;

    // Variables para el tiro con el mouse
    bool mousePresionado;
    QPointF puntoInicioTiro;

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void actualizarJuego();
};

#endif