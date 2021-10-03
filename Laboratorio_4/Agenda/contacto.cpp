#include "contacto.h"

Contacto::Contacto(){
    this->nombre = "";
    this->numero = "";
}

Contacto::Contacto(QString _nombre, QString _numero):
    nombre(_nombre),
    numero(_numero)
{}

QString Contacto::getNombre(){
    return this->nombre;
}

void Contacto::setNombre(QString _nombre){
    this->nombre = _nombre;
    return;
}

QString Contacto::getNumero(){
    return this->numero;
}

void Contacto::setNumero(QString _num){
    this->numero = _num;
    return;
}
