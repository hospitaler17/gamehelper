#ifndef FMADDSPELLS_H
#define FMADDSPELLS_H

#include <QWidget>
#include <QAbstractItemModel>
#include <QStandardItemModel>

#include "forms/baseform.h"
#include "objects/person.h"
#include "objects/spell.h"

#define TABLE_SPELLS_COLUMN_NAMES_COUNT 3
enum TABLE_SPELLS_COLUMN_NAMES
{
    TSCN_NAME = 0,
    TSCN_DECRIPTION = 1,
    TSCN_COOLDAWN = 2
};

namespace Ui {
class FmAddSpells;
}

class FmAddSpells : public BaseForm
{
    Q_OBJECT

public:
    explicit FmAddSpells(Person * person, BaseForm *parent = 0);
    ~FmAddSpells();

protected:
    virtual void initParams();

private:
    Ui::FmAddSpells *ui;

    Person * _person;
    Spell * currentSpell;
    QStandardItemModel * model;

    void setCurrentSpell(Spell * spell);

private slots:
    void slotOnItemSelectionChanged(QModelIndex index);

};

#endif // FMADDSPELLS_H
