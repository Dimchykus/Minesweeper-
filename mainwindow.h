#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void show_ui();
    ~MainWindow();

private slots:
void ButtonPressed(class Button** );


//void time_ui();

void on_Create_clicked();

void on_tableWidget_cellClicked(int row, int column);

void on_pushButton_clicked();

void on_checkBox_clicked();

private:
    Ui::MainWindow *ui;
};

class Button
{
public:
    int neib = 0;
    int bomb = 0;
    int clicked = 0;
    QPushButton *button;
};

int Bombs_near(int row,int column, int rows, int columns);
int ToCheck(int row,int column, int rows, int columns);


#endif // MAINWINDOW_H
