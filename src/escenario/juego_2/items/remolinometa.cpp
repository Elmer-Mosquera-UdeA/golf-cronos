#include "remolinometa.h"

RemolinoMeta::RemolinoMeta() {
    QPixmap imagen(":/resources/imgs/pelota_roja.png");


    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
