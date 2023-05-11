#ifndef FMADDPERSON_H
#define FMADDPERSON_H

#include <QWidget>

#include "forms/fmaddspells.h"

namespace Ui {
class FmAddPerson;
}

class FmAddPerson : public QWidget
{
    Q_OBJECT

public:
    explicit FmAddPerson(QWidget *parent = 0);
    ~FmAddPerson();

private slots:

    void on_pb_spells_clicked();

private:
    Ui::FmAddPerson *ui;
};

#endif // FMADDPERSON_H
