#include "fmaddspells.h"
#include "ui_fmaddspells.h"


FmAddSpells::FmAddSpells(Person *person, BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FmAddSpells)
{
    ui->setupUi(this);
    _person = person;

    initParams();
}

FmAddSpells::~FmAddSpells()
{
    delete ui;
}

void FmAddSpells::initParams()
{
    model = new QStandardItemModel(0, TABLE_SPELLS_COLUMN_NAMES_COUNT);
    for(int i = 0; i < _person->getSpells().count(); ++i)
    {
        QList<QStandardItem *> items;
        for(int j = 0; j < TABLE_SPELLS_COLUMN_NAMES_COUNT; ++j)
        {
            QStandardItem * item = new QStandardItem();
            if(j == TSCN_NAME)
                item->setData(QVariant(_person->getSpells().at(i)->name()));
            else if (j == TSCN_DECRIPTION)
                item->setData(QVariant(_person->getSpells().at(i)->description()));
            else if (j == TSCN_COOLDAWN)
                item->setData(QVariant(_person->getSpells().at(i)->cooldawn()));
            items.append(item);
        }
        model->appendRow(items);
    }
    ui->tableView->setModel(model);

    QStringList labels;
    for(int j = 0; j < TABLE_SPELLS_COLUMN_NAMES_COUNT; ++j)
    {
        QString label;;
        if(j == TSCN_NAME)
            label = tr("Название");
        else if (j == TSCN_DECRIPTION)
            label = tr("Описание");
        else if (j == TSCN_COOLDAWN)
            label = tr("Откат, [х]");
        labels.append(label);
    }
    model->setHorizontalHeaderLabels(labels);

    connect(ui->tableView,    SIGNAL(clicked(QModelIndex)),
            this,               SLOT(slotOnItemSelectionChanged(QModelIndex)));

    ui->tableView->selectRow(0);
    ui->tableView->clicked(model->index(0,0));
}

void FmAddSpells::setCurrentSpell(Spell *spell)
{
    ui->sb_cooldawn->setValue(spell->cooldawn());
}

void FmAddSpells::slotOnItemSelectionChanged(QModelIndex index)
{
    int currentRow = index.row();

    for(int j = 0; j < TABLE_SPELLS_COLUMN_NAMES_COUNT; ++j)
    {
        if      (j == TSCN_NAME)
            ui->le_name->setText(model->data(model->index(currentRow, j)).toString());
        else if (j == TSCN_DECRIPTION)
            ui->pte_description->setPlainText(model->data(model->index(currentRow, j)).toString());
        else if (j == TSCN_COOLDAWN)
            ui->sb_cooldawn->setValue(model->data(model->index(currentRow, j)).toInt());
    }
}
