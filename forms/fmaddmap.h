#ifndef FMADDMAP_H
#define FMADDMAP_H

#include <QWidget>
#include "forms/baseform.h"

namespace Ui {
class FmAddMap;
}

class FmAddMap : public BaseForm
{
    Q_OBJECT

public:
    explicit FmAddMap(BaseForm *parent = 0);
    ~FmAddMap();

private:
    Ui::FmAddMap *ui;
};

#endif // FMADDMAP_H
