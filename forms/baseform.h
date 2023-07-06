#ifndef BASEFORM_H
#define BASEFORM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QFileDialog>
#include <QDebug>

class BaseForm : public QWidget
{
    Q_OBJECT
public:
    explicit BaseForm(QWidget *parent = nullptr);

protected:
    virtual void initParams() = 0;

signals:

public slots:
};


#endif // BASEFORM_H
