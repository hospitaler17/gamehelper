#ifndef FMADDBATTLE_H
#define FMADDBATTLE_H

#include <QWidget>

namespace Ui {
class FmAddBattle;
}

class FmAddBattle : public QWidget
{
    Q_OBJECT

public:
    explicit FmAddBattle(QWidget *parent = 0);
    ~FmAddBattle();

private:
    Ui::FmAddBattle *ui;
};

#endif // FMADDBATTLE_H
