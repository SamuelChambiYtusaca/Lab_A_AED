#ifndef CONTACTO_H
#define CONTACTO_H
#include<QObject>

class Contacto
{
public:
    Contacto();
    Contacto(QString, QString);
    QString getNombre();
    QString getNumero();
    void setNombre(QString);
    void setNumero(QString);
private:
    QString nombre;
    QString numero;
};

#endif // CONTACTO_H
