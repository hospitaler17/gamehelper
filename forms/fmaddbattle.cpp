#include "fmaddbattle.h"
#include "ui_fmaddbattle.h"

FmAddBattle::FmAddBattle(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FmAddBattle)
{
    ui->setupUi(this);
}

FmAddBattle::~FmAddBattle()
{
    delete ui;
}
