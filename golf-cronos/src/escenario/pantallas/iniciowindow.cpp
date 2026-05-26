#include "iniciowindow.h"
#include "ui_iniciowindow.h"

InicioWindow::InicioWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InicioWindow)
{
    ui->setupUi(this);
    setWindowTitle("Golf En El Paneta Cronos");
}

InicioWindow::~InicioWindow()
{
    delete ui;
}
