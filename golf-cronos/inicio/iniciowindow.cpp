#include "iniciowindow.h"
#include "ui_iniciowindow.h"

InicioWindow::InicioWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InicioWindow)
{
    ui->setupUi(this);
}

InicioWindow::~InicioWindow()
{
    delete ui;
}
