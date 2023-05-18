#include "fmaddspells.h"
#include "ui_fmaddspells.h"



FmAddSpells::FmAddSpells(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FmAddSpells)
{
    ui->setupUi(this);

}

FmAddSpells::~FmAddSpells()
{
    delete ui;
}

void FmAddSpells::initParams()
{
    qDebug() << "hi!";
}
