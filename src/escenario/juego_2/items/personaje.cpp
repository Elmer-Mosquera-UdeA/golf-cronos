#include "personaje.h"
#include <QPixmap>


Personaje::Personaje() {
    QPixmap imagen(":/resources/imgs/game-over.png");


    setPixmap(imagen.scaled( 50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation ));

}
