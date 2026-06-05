#include "agenteia.h"
#include <QPixmap>

AgenteIA::AgenteIA() {
    QPixmap imagen(":/resources/imgs/Agente-IA.png");


    setPixmap(imagen.scaled( 200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation ));
}
