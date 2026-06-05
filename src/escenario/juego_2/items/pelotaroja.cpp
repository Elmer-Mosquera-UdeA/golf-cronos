#include "pelotaroja.h"
#include <QPixmap>

PelotaRoja::PelotaRoja() {

    QPixmap imagen(":/resources/imgs/pelota_roja.png");


    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
