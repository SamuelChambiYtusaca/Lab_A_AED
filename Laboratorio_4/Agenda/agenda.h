#ifndef AGENDA_H
#define AGENDA_H
#include "contacto.h"
#include "cola.h"
class Agenda
{
public:
    Agenda();
    ~Agenda();
    void guardar(Contacto*);
    bool eliminar();
    Cola<Contacto*> *contc();
private:
    Cola<Contacto*> *contactos;

};

#endif // AGENDA_H
