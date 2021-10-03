#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <QDialog>
#include "agenda.h"

namespace Ui {
class Mostrar;
}

class Mostrar : public QDialog
{
    Q_OBJECT

public:
    explicit Mostrar(QWidget *parent = nullptr, Agenda *agenda = nullptr);
    ~Mostrar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Mostrar *ui;
    Agenda *agenda;
};

#endif // MOSTRAR_H
