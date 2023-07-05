#ifndef FMADDSPELLS_H
#define FMADDSPELLS_H

#include <QWidget>
#include <QModelIndexList>
#include <QAbstractItemView>
#include <QAbstractItemModel>
#include <QStandardItemModel>

#include "forms/baseform.h"
#include "game/actors/person.h"
#include "objects/spell.h"

#define TABLE_SPELLS_COLUMN_NAMES_COUNT 3
enum TABLE_SPELLS_COLUMN_NAMES
{
    TSCN_ID = 0,
    TSCN_NAME = 1
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
    void loadSpellOnForm(Spell * spell);
    void clearFieldsOnForm();
protected slots:
    void slotOnItemSelectionChanged(QModelIndex index);

    void on_pb_save_and_exit_clicked();
    void on_pb_remove_clicked();
    void on_pb_cancel_clicked();
    void on_pb_add_clicked();
};

#endif // FMADDSPELLS_H
