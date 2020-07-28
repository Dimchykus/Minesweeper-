#ifndef LOADMENU_H
#define LOADMENU_H

#include <QMainWindow>

namespace Ui {
class LoadMenu;
}

class LoadMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadMenu(QWidget *parent = nullptr);
    ~LoadMenu();
private slots:
private:
    Ui::LoadMenu *ui;


};

#endif // LOADMENU_H
