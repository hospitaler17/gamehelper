#include "fmaddperson.h"
#include "ui_fmaddperson.h"

FmAddPerson::FmAddPerson(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FmAddPerson)
{
    ui->setupUi(this);

}

FmAddPerson::~FmAddPerson()
{
    delete ui;
}

void FmAddPerson::on_pb_spells_clicked()
{
    FmAddSpells * fmAddSpells = new FmAddSpells();
    //TODO: передать модель со способностями
    fmAddSpells->setWindowModality(Qt::ApplicationModal);
    fmAddSpells->show();
}
