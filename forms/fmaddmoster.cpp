#include "fmaddmoster.h"
#include "ui_fmaddmoster.h"

FmAddMoster::FmAddMoster(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FmAddMoster)
{
    ui->setupUi(this);
}

FmAddMoster::~FmAddMoster()
{
    delete ui;
}

void FmAddMoster::on_pb_spells_2_clicked()
{
//    FmAddSpells * fmAddSpells = new FmAddSpells(/*person*/);
//    //TODO: передать модель со способностями
//    fmAddSpells->setWindowModality(Qt::ApplicationModal);
//    fmAddSpells->show();
}
