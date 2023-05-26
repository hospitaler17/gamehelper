#ifndef FMADDPERSON_H
#define FMADDPERSON_H

#include <QWidget>


#include "forms/baseform.h"
#include "forms/fmaddspells.h"
#include "objects/person.h"
#include "objects/spell.h"

#include "xmlparser.h"

namespace Ui {
class FmAddPerson;
}

class FmAddPerson : public BaseForm
{
    Q_OBJECT

public:
    explicit FmAddPerson(QWidget *parent = 0);
    ~FmAddPerson();

protected:
    virtual void initParams();

private:
    Person * person;
private slots:

    void on_pb_spells_clicked();

    void on_pb_save_clicked();

private:
    Ui::FmAddPerson *ui;
};

#endif // FMADDPERSON_H
