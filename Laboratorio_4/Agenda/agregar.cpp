#include "agregar.h"
#include "contacto.h"
#include "ui_agregar.h"
#include <QMessageBox>
Agregar::Agregar(QWidget *parent, Agenda *_agenda) :
    QDialog(parent),
    ui(new Ui::Agregar),
    agenda(_agenda)
{
    ui->setupUi(this);
}

Agregar::~Agregar()
{
    delete ui;
}

void Agregar::on_aceptar_clicked()
{
    QString nombre = ui->name->text();
    QString numero = ui->number->text();
    if(nombre.isEmpty() || numero.isEmpty()){
        QMessageBox::critical(this,"Error","Existen espacios llenados incorrectamente");
        return;
    }
    Contacto *nuevo = new Contacto(nombre,numero);
    this->agenda->guardar(nuevo);
    close();
}

