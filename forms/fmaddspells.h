#ifndef FMADDSPELLS_H
#define FMADDSPELLS_H

#include <QWidget>

#include "forms/baseform.h"

namespace Ui {
class FmAddSpells;
}

class FmAddSpells : public BaseForm
{
    Q_OBJECT

public:
    explicit FmAddSpells(BaseForm *parent = 0);
    ~FmAddSpells();

protected:
    virtual void initParams();

private:
    Ui::FmAddSpells *ui;

};

#endif // FMADDSPELLS_H
