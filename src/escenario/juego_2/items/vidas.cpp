#include "vidas.h"

vidas::vidas() {

    QPixmap imagen(":/resources/imgs/rueda_pinchos.png");
    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
