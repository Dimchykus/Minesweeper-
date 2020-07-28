#ifndef LOADWINDOW_H
#define LOADWINDOW_H
#include <QTimer>
#include <QMainWindow>

namespace Ui {
class loadwindow;
}

class loadwindow : public QMainWindow
{
    Q_OBJECT

public:
    void delay();
     void hide_ui();
    void show_image();
    explicit loadwindow(QWidget *parent = nullptr);
    ~loadwindow();
private slots:


private:
    Ui::loadwindow *ui;
    QTimer *timer;

};

void Show_ui();


#endif // LOADWINDOW_H
