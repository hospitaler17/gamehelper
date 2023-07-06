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
//    _currentSpell = new Spell();
    delete _currentSpell;
    delete model;
    delete ui;
}

void FmAddSpells::initParams()
{
    _currentSpell = new Spell();
    model = new QStandardItemModel(0, TABLE_SPELLS_COLUMN_NAMES_COUNT);

    initTable();

    connect(ui->tableView,  SIGNAL(clicked(QModelIndex)),
            this,           SLOT(slotOnItemSelectionChanged(QModelIndex)));
    connect(ui->tableView,  SIGNAL(clicked(QModelIndex)),
            this,           SLOT(slotPrintCurrentSpellOnForm(QModelIndex)));

    formsSetEnabled(false);
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

bool FmAddSpells::checkEmptyFieldsOnForm()
{
    bool res = true;
    if(        ui->le_name->text().trimmed().isEmpty()
            || ui->pte_description->toPlainText().trimmed().isEmpty()
            || ui->sb_cooldawn->value() == 0)
        res = false;
    return res;
}

void FmAddSpells::slotOnItemSelectionChanged(QModelIndex index)
{
    _selectedSpell = index;
}

void FmAddSpells::slotPrintCurrentSpellOnForm(QModelIndex index)
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
            _person->removeSpellAt(i);
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
    formsSetEnabled(true);
    _workMode = MODE_CREATE;
}

void FmAddSpells::on_pb_edit_save_clicked()
{
    if( !checkEmptyFieldsOnForm() )
        return;

    if(_workMode == MODE_CREATE)
    {
        _currentSpell = new Spell();
        // добавим спелл к персонажу
        _currentSpell->setDescription(ui->pte_description->toPlainText());
        _currentSpell->setCooldawn(ui->sb_cooldawn->value());
        _currentSpell->setName(ui->le_name->text());
        _person->addSpell(_currentSpell);
    }
    else if (_workMode == MODE_EDIT)
    {
        _currentSpell->setDescription(ui->pte_description->toPlainText());
        _currentSpell->setCooldawn(ui->sb_cooldawn->value());
        _currentSpell->setName(ui->le_name->text());
        _person->editSpell(_currentSpell);
    }
    // добавим спелл к таблице
    initTable();
}

void FmAddSpells::initTable()
{
    //////////////////////////////////////////////////////////
    model->clear();
    for(int i = 0; i < _person->getSpells().count(); ++i)
    {
        QList<QStandardItem *> items;
        for(int j = 0; j < TABLE_SPELLS_COLUMN_NAMES_COUNT; ++j)
        {
            if(j == TSCN_NAME)
            {
                QString name = _person->getSpells().at(i)->name();
                QStandardItem * itemName = new QStandardItem(name);;
                model->setItem(i, j, itemName);
            }
            else if(j == TSCN_ID)
            {
                QString ID = QString::number(_person->getSpells().at(i)->ID());
                QStandardItem * itemID = new QStandardItem(ID);;
                model->setItem(i, j, itemID);
            }
        }
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

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableView->selectRow(0);
    ui->tableView->clicked(model->index(0,0));
}


void FmAddSpells::on_pb_load_and_add_file_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Добавить способность"), Common::getXMLsSubDir(OXT_SPELL));
    _currentSpell = new Spell();
    if(!path.isEmpty() && _currentSpell->readFromXML(path))
    {
        _person->addSpell(_currentSpell);
        initTable();
    }
}

void FmAddSpells::formsSetEnabled(const bool &value)
{
    ui->le_name->setEnabled(value);
    ui->pte_description->setEnabled(value);
    ui->sb_cooldawn->setEnabled(value);

    value? ui->frame_currentEdit->show(): ui->frame_currentEdit->hide();
}


void FmAddSpells::on_pb_edit_clicked()
{
    formsSetEnabled(true);
    _workMode = MODE_EDIT;
}

