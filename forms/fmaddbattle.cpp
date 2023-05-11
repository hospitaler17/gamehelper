#include "fmaddbattle.h"
#include "ui_fmaddbattle.h"

FmAddBattle::FmAddBattle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FmAddBattle)
{
    ui->setupUi(this);
}

FmAddBattle::~FmAddBattle()
{
    delete ui;
}
