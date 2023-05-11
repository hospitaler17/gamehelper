#include "fmaddspells.h"
#include "ui_fmaddspells.h"

FmAddSpells::FmAddSpells(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FmAddSpells)
{
    ui->setupUi(this);
}

FmAddSpells::~FmAddSpells()
{
    delete ui;
}
