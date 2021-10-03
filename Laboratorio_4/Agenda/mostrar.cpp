#include "mostrar.h"
#include "node.h"
#include "ui_mostrar.h"

Mostrar::Mostrar(QWidget *parent, Agenda *_agenda) :
    QDialog(parent),
    ui(new Ui::Mostrar),
    agenda(_agenda)
{
    ui->setupUi(this);
}

Mostrar::~Mostrar()
{
    delete ui;
}

void Mostrar::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    QString content;
    Cola<Contacto*> *aux = this->agenda->contc();
    if(!aux->get_h())
        return;
    else{
        node<Contacto*>*aux = this->agenda->contc()->get_h();
        while(aux){
            content += "Nombre: " + aux->get_dato()->getNombre() + "\n";
            content += "Numero: " + aux->get_dato()->getNumero() + "\n";
            content += "<------------------------------------------>\n";
            aux = aux->get_sig();
        }
        ui->plainTextEdit->setPlainText(content);
        return;
    }
}


void Mostrar::on_pushButton_2_clicked()
{
    this->close();
}

