#include "loadwindow.h"
#include "ui_loadwindow.h"
#include "mainwindow.h"
#include <QDebug>

int tim = 0;

loadwindow::loadwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loadwindow)
{
    ui->setupUi(this);



}

loadwindow::~loadwindow()
{
    delete ui;
}
