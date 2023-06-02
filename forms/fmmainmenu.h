#ifndef FMMAINMENU_H
#define FMMAINMENU_H

#include <QMainWindow>

#include "forms/fmaddperson.h"
#include "forms/fmaddbattle.h"
#include "forms/fmaddmoster.h"
#include "forms/fmaddmap.h"

namespace Ui {
class FmMainMenu;
}

class FmMainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit FmMainMenu(QWidget *parent = 0);
    ~FmMainMenu();

private slots:

    void on_pb_editor_clicked();

    void on_pb_close_clicked();

    void on_pb_start_game_clicked();

    void on_pb_edit_characters_clicked();

    void on_pb_edit_monsters_clicked();

private:
    Ui::FmMainMenu *ui;

    void initStandartDirs();
};

#endif // FMMAINMENU_H
