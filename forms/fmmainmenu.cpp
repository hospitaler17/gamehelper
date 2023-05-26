#include "fmmainmenu.h"
#include "ui_fmmainmenu.h"

FmMainMenu::FmMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FmMainMenu)
{
    ui->setupUi(this);
    ui->submenu_1->setCurrentWidget(ui->page_submenu_1_empty);
    ui->menu->setCurrentWidget(ui->page_main_menu);

}

FmMainMenu::~FmMainMenu()
{
    delete ui;
}

void FmMainMenu::on_pb_editor_clicked()
{
    if(ui->submenu_1->currentWidget() != ui->page_submenu_1_editor)
        ui->submenu_1->setCurrentWidget(ui->page_submenu_1_editor);
    else
        ui->submenu_1->setCurrentWidget(ui->page_submenu_1_empty);
}

void FmMainMenu::on_pb_close_clicked()
{
    close();
}

void FmMainMenu::on_pb_start_game_clicked()
{
    if(ui->submenu_1->currentWidget() != ui->page_submenu_1_game)
        ui->submenu_1->setCurrentWidget(ui->page_submenu_1_game);
    else
        ui->submenu_1->setCurrentWidget(ui->page_submenu_1_empty);
}

void FmMainMenu::on_pb_edit_characters_clicked()
{
    FmAddPerson * fmAddPerson = new FmAddPerson();
    fmAddPerson->setWindowModality(Qt::ApplicationModal);
    fmAddPerson->setWindowTitle("Персонаж");
    fmAddPerson->show();
}

void FmMainMenu::on_pb_edit_monsters_clicked()
{
    FmAddMoster * fmAddMonster = new FmAddMoster();
    fmAddMonster->setWindowModality(Qt::ApplicationModal);
    fmAddMonster->setWindowTitle("Монстр");
    fmAddMonster->show();
}
