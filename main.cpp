#include "mainwindow.h"
#include "loadwindow.h"
#include <QApplication>
#include <QThread>
#include <QTimer>
#include <QSplashScreen>
bool close_ui = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    loadwindow load;
    w.setWindowTitle("MinesWeeper");
QSplashScreen *splash = new QSplashScreen;
splash->setPixmap(QPixmap(":/g/img/1.jpg"));
splash->show();
QTimer::singleShot(2500,splash,SLOT(close()));
QTimer::singleShot(2500,&w,SLOT(show()));

    return a.exec();
}

void Show_ui()
{


}




