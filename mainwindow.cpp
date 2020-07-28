#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <time.h>
#include <QMessageBox>
#include "loadmenu.h"

Button *p_buttons;
QString empty_cell = "   -";
QString bomb = "   X";
QString isflag = "    !";
bool flag = false;
bool win = false;
bool first_press = true;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tableWidget->setEnabled(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ButtonPressed(class Button** buttons)
{


}


short int arr_bombs[21][21];
short int arr_selected[21][21];
short int arr_ToCheck[21][21];
short int arr_near_bomb[21][21];
bool arr_flags[21][21];


void MainWindow::on_Create_clicked()
{


    int x = ui->spinBox_h->value();
    int y = ui->spinBox_w->value();


    ui->tableWidget->setRowCount(x);
    ui->tableWidget->setColumnCount(y);
    ui->tableWidget->setGeometry(0,0,y*40,x*40);

    ui->tableWidget->setEnabled(true);



  this->setGeometry(760,270,y*40,x*40+100);//y*40,x*40+100
    QFont fnt;
            fnt.setPointSize(8);
            fnt.setBold(true);
            fnt.setFamily("Arial");
     ui->tableWidget->setFont(fnt);
   ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
 // ui->tableWidget->setSelectionMode(QAbstractItemView::EditingState);
  QColor Grey(166,166,166);
QBrush brush_grey(Grey);

   for(int i=0;i<x;i++)
       {
           for(int j=0;j<y;j++)
            {
               ui->tableWidget->setItem(i,j,new QTableWidgetItem);
               ui->tableWidget->item(i,j)->setBackground(brush_grey);

            }
   }
   //ui->tableWidget->setStyleSheet("QTableWidget::item{border-left:6px solid #cacaca;border-top:6px solid #cacaca;border-bottom:6px solid #747474;border-right:6px solid #747474;background-color: #8d8d8d;}QTableWidget#item:pressed{background-color: #a8a8a8;border:0px;}");
  // ui->tableWidget->setStyleSheet("QTableWidget::item:hover{background-color: #a8a8a8;border:0px;}");
  // ui->tableWidget->setStyleSheet("QTableWidget::item{background-color: #000000;border:0px;}");
 //  ui->tableWidget->setStyleSheet("QTableWidget::item:focus{background-color: #ffffff;border:0px;}");


}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

if(win)
{
    return;
}
if(flag){
    if(arr_selected[row][column] == 1)
    {
        return;
    }
if(arr_flags[row][column] == true)
    {
    ui->tableWidget->item(row,column)->setText("");
    arr_flags[row][column] = false;
    return;
    }
    ui->tableWidget->item(row,column)->setText(isflag);
    arr_flags[row][column] = true;
    return;
}
QColor White(255,255,255);
QBrush brush_white(White);
    int bombs = ui->spinBox_bombs->value();
    const int all_bombs = bombs;
    //ui->pushButton->setEnabled(false);
    int rows = ui->tableWidget->rowCount();
    int columns = ui->tableWidget->columnCount();
    qDebug() <<rows<<"-"<<columns ;

    if(first_press)
    {
        srand(time(0));

         while(bombs != 0 )
            {
         int x = rand()%rows;
         int y = rand()%columns;
         if( x==row || y==row|| x==column || y == column|| arr_bombs[x][y] == 1)
         {
             continue;
         }
         arr_bombs[x][y] = 1;
         first_press = false;
         bombs--;
             }
    }
 //   ui->tableWidget->item(row,column)->setText(empty_cell);

    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<columns;j++)
            {
                if(row == i && column == j && arr_bombs[i][j] == 1)
                {
                    for(int i=0;i<rows;i++)
                    {
                            for(int j=0;j<columns;j++)
                            {
                               // ui->tableWidget->item(i,j)->setText(empty_cell);

                                if(arr_bombs[i][j] == 1)
                                {
                                     ui->tableWidget->item(i,j)->setText(bomb);
                                }

                            }
                    }
                    QMessageBox::information(this,"Sorry","You lose");
                    return;
                }else if(row == i && column == j && arr_selected[i][j] == 1)
                {
                    qDebug() << "Allredy selected";
                    return;
                }
            }
    }

int near = Bombs_near(row,column,rows,columns);

if(near == 0)
{
    arr_selected[row][column] = 1;
    ToCheck(row,column,rows,columns);
    ui->tableWidget->item(row,column)->setText(empty_cell);
    ui->tableWidget->item(row,column)->setBackground(brush_white);

}else
{
    ui->tableWidget->item(row,column)->setBackground(brush_white);
    arr_selected[row][column] = 1;

    ui->tableWidget->item(row,column)->setText("   "+QString::number(near));
}



for(int i=0;i<rows;i++)
{
        for(int j=0;j<columns;j++)
        {
            if(arr_selected[i][j] == 1 )
            {
                continue;
            }
            if(arr_ToCheck[i][j] == 1)
            {
                int bombs = Bombs_near(i,j,rows,columns);
                if(bombs > 0)
                {
                    ui->tableWidget->item(i,j)->setText("   "+QString::number(bombs));
                     arr_selected[i][j] = 1;
                     ui->tableWidget->item(i,j)->setBackground(brush_white);


                }else if(bombs == 0)
                {
                    ui->tableWidget->item(i,j)->setText(empty_cell);
                    arr_selected[i][j] = 1;
                    ui->tableWidget->item(i,j)->setBackground(brush_white);


                    ToCheck(i,j,rows,columns);
                    i=-1;
                    j=-1;
                }
              arr_selected[i][j] = 1;
              //ui->tableWidget->item(i,j)->setBackground(brush_white);

            }

        }
}

int win = 0;
for(int i=0;i<rows;i++)
{
        for(int j=0;j<columns;j++)
        {
           win += arr_selected[i][j];
           if(win == (rows*columns)-all_bombs)
           {
               QMessageBox::information(this,"Congratulations","You win");
               ui->label_4->setText("Win");
               win = true;
           }
        }
}
qDebug()<<"win:"<<win<<"  all:"<<rows*columns<< "  all_bombs:"<<all_bombs;
qDebug()<<"ready";
}


int Bombs_near(int row,int column, int rows, int columns)
{
    int count = 0;

    if(arr_bombs[row+1][column+1] == 1 && row+1 < rows && column+1 < columns) count++;

    if(arr_bombs[row-1][column-1] == 1 && row-1 >= 0 && column-1 >= 0) count++;

    if(arr_bombs[row-1][column+1] == 1 && row-1 >= 0 && column+1 < columns) count++;

    if(arr_bombs[row+1][column-1] == 1 && row+1 < rows && column-1 >= 0) count++;

    if(arr_bombs[row+1][column] == 1 && row+1 < rows ) count++;

    if(arr_bombs[row-1][column] == 1 && row-1 >= 0 ) count++;

    if(arr_bombs[row][column+1] == 1 && column+1 < columns ) count++;

    if(arr_bombs[row][column-1] == 1 && column-1 >= 0 ) count++;


    return count;
}

int ToCheck(int row,int column, int rows, int columns)
{
    if(row+1 < rows && column+1 < columns){ arr_ToCheck[row+1][column+1] = 1;}

    if(row-1 >= 0 && column-1 >= 0) {arr_ToCheck[row-1][column-1] = 1;}

    if(row-1 >= 0 && column+1 < columns) arr_ToCheck[row-1][column+1] = 1;

    if( row+1 < rows && column-1 >= 0) arr_ToCheck[row+1][column-1] = 1;

    if(row+1 < rows ) arr_ToCheck[row+1][column] = 1;

    if( row-1 >= 0 ) arr_ToCheck[row-1][column] = 1;

    if(column+1 < columns ) arr_ToCheck[row][column+1] = 1;
    if(arr_bombs[row][column+1] == 1 && column+1 <= columns ){arr_ToCheck[row][column] = 2;}

    if(column-1 >= 0 ) arr_ToCheck[row][column-1] = 1;

    return 0;
}

void MainWindow::on_pushButton_clicked()
{
    if(flag){
    flag = false;
     ui->checkBox->setChecked(false);
    }else
    {
        flag = true;
        ui->checkBox->setChecked(true);
    }
}

void MainWindow::on_checkBox_clicked()
{
    if(flag){
    flag = false;
     ui->checkBox->setChecked(false);
    }else
    {
        flag = true;
         ui->checkBox->setChecked(true);
    }
}
