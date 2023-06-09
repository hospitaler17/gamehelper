#ifndef FMADDSPELLS_H
#define FMADDSPELLS_H

#include <QWidget>
#include <QModelIndex>
#include <QModelIndexList>
#include <QAbstractItemView>
#include <QAbstractItemModel>
#include <QStandardItemModel>

#include "forms/baseform.h"
#include "game/actors//person.h"
#include "objects/spell.h"

#define TABLE_SPELLS_COLUMN_NAMES_COUNT 2
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
    void initParams();

private:
    Ui::FmAddSpells *ui;

    Person * _person;
    Spell * _currentSpell;
    QStandardItemModel * model;
    QModelIndex _selectedSpell;

    void setCurrentSpell(Spell * spell);
    void loadSpellOnForm(Spell * spell);
    void clearFieldsOnForm();
    bool checkEmptyFieldsOnForm();
protected slots:
    void slotOnItemSelectionChanged(QModelIndex index);
    void slotFrintCurrentSpellOnForm(QModelIndex index);

    void on_pb_save_and_exit_clicked();
    void on_pb_remove_clicked();
    void on_pb_cancel_clicked();
    void on_pb_add_clicked();
private slots:
    void on_pb_edit_save_clicked();
    void initTable();
    void on_pb_load_and_add_file_clicked();
};

#endif // FMADDSPELLS_H
