#ifndef JUEGOMODOUNOQGRAPHICSVIEW_H
#define JUEGOMODOUNOQGRAPHICSVIEW_H

#include <QGraphicsView>

#include <QMouseEvent>
#include <QEvent>
#include <QPointF>

class Nivel;

class JuegoModoUnoQGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit JuegoModoUnoQGraphicsView(QWidget *parent = nullptr);
    ~JuegoModoUnoQGraphicsView();
    // void ejecutarNivel();


signals:
    void tiroRealizado(const QPointF &origen, const QPointF &vectorTiro);

private:
    Nivel *nivelActual;
    bool isLeftClickPressed = false;

    // Puntos de cordenada para el calculo del vector libre
    QPointF clickInicialEscena;
    QPointF clickFinalEscena;

protected:
    // Captura los clics absolutos de la superficie física del View
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif

