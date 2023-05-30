#ifndef FMADDMOSTER_H
#define FMADDMOSTER_H

#include <QWidget>
#include <fmaddspells.h>

namespace Ui {
class FmAddMoster;
}

class FmAddMoster : public QWidget
{
    Q_OBJECT

public:
    explicit FmAddMoster(QWidget *parent = 0);
    ~FmAddMoster();

private slots:
    void on_pb_spells_2_clicked();

private:
    Ui::FmAddMoster *ui;
};

#endif // FMADDMOSTER_H
