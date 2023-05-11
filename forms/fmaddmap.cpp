#include "fmaddmap.h"
#include "ui_fmaddmap.h"

FmAddMap::FmAddMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FmAddMap)
{
    ui->setupUi(this);
}

FmAddMap::~FmAddMap()
{
    delete ui;
}
