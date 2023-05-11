#ifndef FMADDMAP_H
#define FMADDMAP_H

#include <QWidget>

namespace Ui {
class FmAddMap;
}

class FmAddMap : public QWidget
{
    Q_OBJECT

public:
    explicit FmAddMap(QWidget *parent = 0);
    ~FmAddMap();

private:
    Ui::FmAddMap *ui;
};

#endif // FMADDMAP_H
