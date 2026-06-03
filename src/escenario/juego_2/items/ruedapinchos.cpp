#include "ruedapinchos.h"

RuedaPinchos::RuedaPinchos() {

    QPixmap imagen(":/resources/imgs/rueda_pinchos.png");
    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
