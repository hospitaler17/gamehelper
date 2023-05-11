#ifndef FMADDSPELLS_H
#define FMADDSPELLS_H

#include <QWidget>

namespace Ui {
class FmAddSpells;
}

class FmAddSpells : public QWidget
{
    Q_OBJECT

public:
    explicit FmAddSpells(QWidget *parent = 0);
    ~FmAddSpells();

private:
    Ui::FmAddSpells *ui;
};

#endif // FMADDSPELLS_H
