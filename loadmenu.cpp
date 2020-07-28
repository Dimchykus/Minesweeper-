#include "loadmenu.h"
#include "ui_loadmenu.h"
#include <QTimer>
#include <QDebug>
QTimer *timer;
#include "mainwindow.h"
#include <QPixmap>

LoadMenu::LoadMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadMenu)
{

//    QPixmap pix = QPixmap (":/g/img/1.jpg");
//    if(pix.isNull() == true)
//    {
//        qDebug() << "error";
//    }
//    ui->label->setPixmap(pix);
//    //QTimer *timer;
//    timer = new QTimer(this);
//        connect(timer, SIGNAL(timeout()), this, SLOT(loading()));
//        timer->start(40);
//        srand(time(0));

    //QPixmap pix(":/g/img/1.jpg");
    //ui->label->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

}
//int iteratot;
//void LoadMenu::loading(){
//    iteratot++;
//    qInfo() << iteratot;
//       if(iteratot >= 40){
//           close();


//       }
//}



LoadMenu::~LoadMenu()
{
    delete ui;
}
