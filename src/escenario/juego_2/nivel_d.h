#ifndef NIVEL_D_H
#define NIVEL_D_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Nivel_D : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Nivel_D(QObject *parent = nullptr);
    ~Nivel_D();

private:
    QTimer *timerPrincipal;
    QPixmap fondoEscalado;

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void actualizarJuego();
};

#endif