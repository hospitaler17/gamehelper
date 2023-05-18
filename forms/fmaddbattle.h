#ifndef FMADDBATTLE_H
#define FMADDBATTLE_H

#include <QWidget>
#include "forms/baseform.h"


namespace Ui {
class FmAddBattle;
}

class FmAddBattle : public BaseForm
{
    Q_OBJECT

public:
    explicit FmAddBattle(BaseForm *parent = 0);
    ~FmAddBattle();

private:
    Ui::FmAddBattle *ui;
};

#endif // FMADDBATTLE_H
