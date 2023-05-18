#include "fmaddmap.h"
#include "ui_fmaddmap.h"

FmAddMap::FmAddMap(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::FmAddMap)
{
    ui->setupUi(this);
}

FmAddMap::~FmAddMap()
{
    delete ui;
}
