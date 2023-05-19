#include "fmaddperson.h"
#include "ui_fmaddperson.h"

FmAddPerson::FmAddPerson(QWidget *parent) :
    BaseForm(parent),
    ui(new Ui::FmAddPerson)
{
    ui->setupUi(this);

    initParams();
}

FmAddPerson::~FmAddPerson()
{
    delete ui;
}

void FmAddPerson::initParams()
{
    for(int i = 0; i < PC_COUNTER; ++i)
    {
        ui->cbox_main_characteristic->insertItem(i, Common::getPersonCharacteristicDescription((PERSON_CHARACTERISTICS) i));
    }
    for(int i = 0; i < PT_COUNTER; ++i)
    {
        ui->cbox_type->insertItem(i, Common::getPersonTypeDescription((PERSON_TYPE) i));
    }
    person = new Person();
}

void FmAddPerson::on_pb_spells_clicked()
{
    FmAddSpells * fmAddSpells = new FmAddSpells(person);
    //TODO: передать модель со способностями
    fmAddSpells->setWindowModality(Qt::ApplicationModal);
    fmAddSpells->show();
}

void FmAddPerson::on_pb_save_clicked()
{
    // main
    person->setName(ui->le_name->text());
    person->setPersonClass(ui->le_class->text());
    person->setPathToIcon(ui->le_pic->text());
    person->setType((PERSON_TYPE) ui->cbox_type->currentIndex());

    person->setMaxHealth(ui->sb_health->value());
    person->setDamage(ui->sb_damage->value());

    // characteristic
    person->setInitiative(ui->sb_initiative->value());
    person->setStrength(ui->sb_strength->value());
    person->setAgility(ui->sb_agility->value());
    person->setIntelligence(ui->sb_intelligence->value());
    person->setCharisma(ui->sb_charisma->value());
    person->setMainChars((PERSON_CHARACTERISTICS) ui->cbox_main_characteristic->currentIndex());

    XMLParser * writer = new XMLParser();

    for(int i = 0; i < person->getSpells().count(); ++i)
        writer->writeXmlFile(person->getSpells().at(i), QString(QString::number(person->getSpells().at(i)->ID())+tr("_")+person->getSpells().at(i)->name()+tr(".xml")));

    writer->writeXmlFile(person, QString(QString::number(person->ID())+tr("_")+person->name()+tr(".xml")));
}
