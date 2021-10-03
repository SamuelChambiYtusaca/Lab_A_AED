#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agregar.h"
#include "mostrar.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent, Agenda *_agenda)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , agenda(_agenda)

{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    this->agenda->~Agenda();
    delete ui;
}

void MainWindow::on_actionSalir_2_triggered()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    Agregar agregarC(this,this->agenda);
    agregarC.setModal(true);
    agregarC.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(this->agenda->eliminar()){
        QMessageBox::information(this,"Exito","Contacto eliminado con exito.");
    }else{
        QMessageBox::critical(this,"Error","Algo ocurrio mal.");
    }
    return;
}

void MainWindow::on_pushButton_2_clicked()
{
    Mostrar mostrarC(this,this->agenda);
    mostrarC.setModal(true);
    mostrarC.exec();
}

