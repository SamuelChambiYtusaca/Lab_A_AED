#ifndef AGREGAR_H
#define AGREGAR_H

#include <QDialog>
#include "agenda.h"
namespace Ui {
class Agregar;
}

class Agregar : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar(QWidget *parent = nullptr, Agenda *agenda = nullptr);
    ~Agregar();

private slots:
    void on_aceptar_clicked();

private:
    Ui::Agregar *ui;
    Agenda *agenda;
};

#endif // AGREGAR_H
