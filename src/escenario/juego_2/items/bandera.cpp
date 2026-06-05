#include "bandera.h"

Bandera::Bandera() {
    QPixmap imagen(":/resources/imgs/Hoyo-con-bandera(1).png");


    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
