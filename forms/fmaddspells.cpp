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
    _currentSpell = new Spell();

    initTable();

    connect(ui->tableView,  SIGNAL(clicked(QModelIndex)),
            this,           SLOT(slotOnItemSelectionChanged(QModelIndex)));
    connect(ui->tableView,  SIGNAL(clicked(QModelIndex)),
            this,           SLOT(slotFrintCurrentSpellOnForm(QModelIndex)));



}

void FmAddSpells::setCurrentSpell(Spell *spell)
{
    ui->sb_cooldawn->setValue(spell->cooldawn());
    ui->le_name->setText(spell->name());
    ui->pte_description->setPlainText(spell->description());
}

void FmAddSpells::clearFieldsOnForm()
{
    ui->le_name->clear();
    ui->sb_cooldawn->setValue(0);
    ui->pte_description->clear();
}

void FmAddSpells::slotOnItemSelectionChanged(QModelIndex index)
{
    _selectedSpell = index;
}

void FmAddSpells::slotFrintCurrentSpellOnForm(QModelIndex index)
{
    quint64 ID = model->data(model->index(index.row(), TSCN_ID)).value<quint64>();

    for(int i = 0; i < _person->getSpells().count(); ++i)
    {
        if(ID == _person->getSpells().at(i)->ID())
        {
            setCurrentSpell(_person->getSpells().at(i));
            return;
        }
    }
}

void FmAddSpells::on_pb_save_and_exit_clicked()
{
    close();
}

void FmAddSpells::on_pb_remove_clicked()
{
    if ( !_selectedSpell.isValid() )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка"),
                             QString(tr("Выделите способность для удаления!")),
                             QMessageBox::Ok);
        return;
    }
    quint64 ID = model->data(model->index(_selectedSpell.row(), TSCN_ID)).value<quint64>();

    for(int i = 0; i < _person->getSpells().count(); ++i)
    {
        if(ID == _person->getSpells().at(i)->ID())
        {
            model->removeRow(_selectedSpell.row());

            delete _person->getSpells().at(i);
            _person->getSpells().removeAt(i);

            return;
        }
    }
}


void FmAddSpells::on_pb_cancel_clicked()
{
    clearFieldsOnForm();
}


void FmAddSpells::on_pb_add_clicked()
{
    clearFieldsOnForm();
    ui->tableView->clearSelection();
    ui->frame_currentEdit->show();
}


void FmAddSpells::on_pb_edit_save_clicked()
{
    // добавим спелл к персонажу
    if( !_selectedSpell.isValid() )
        _currentSpell->regenerateID();
    _currentSpell->setDescription(ui->pte_description->toPlainText());
    _currentSpell->setCooldawn(ui->sb_cooldawn->value());
    _currentSpell->setName(ui->le_name->text());
    _person->addSpell(_currentSpell);

    // добавим спелл к таблице
    initTable();
//    QStandardItem itemID = _currentSpell->ID();
//    model->appendRow();
}

void FmAddSpells::initTable()
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
            else if(j == TSCN_ID)
                item->setData(QVariant(_person->getSpells().at(i)->ID()));

            items.append(item);
        }
        model->appendRow(items);
    }
    ui->tableView->setModel(model);

    QStringList labels;
    for(int j = 0; j < TABLE_SPELLS_COLUMN_NAMES_COUNT; ++j)
    {
        QString label; label.clear();
        if(j == TSCN_NAME)
            label = tr("Название");
        else if(j == TSCN_ID)
            label = tr("ID");
        if( !label.isEmpty() )
            labels.append(label);
    }
    model->setHorizontalHeaderLabels(labels);

    ui->tableView->selectRow(0);
    ui->tableView->clicked(model->index(0,0));

    ui->tableView->hideColumn(TSCN_ID);

    ui->frame_currentEdit->hide();
}

