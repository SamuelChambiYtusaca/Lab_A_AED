#include "agenda.h"
#include <QtDebug>
Agenda::Agenda()
{
    this->contactos = new Cola<Contacto*>();
}

void Agenda::guardar(Contacto *nuevo){
    if(!contactos){
        qDebug() << "No se encuentra inicializado\n";
    }else{
        this->contactos->enqueue(nuevo);
    }
    return;
}

bool Agenda::eliminar(){
    if(!contactos){
        qDebug() << "No se encuentra inicializado\n";
        return 0;
    }else{
        this->contactos->dequeue();
    }
    return 1;
}

Cola<Contacto*>* Agenda::contc(){
    return this->contactos;
}

Agenda::~Agenda(){
    this->contactos->~Cola();
}
