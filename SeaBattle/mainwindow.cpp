#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("/home/volgin/MyFolder/SeaBattle/FileSeaField.txt"); // Путь к проверке файла.(Свой путь)
    if(!file.open(QFile::WriteOnly | QFile::Text)){
       QMessageBox::warning(this,"title","file not open");
    }
    QTextStream out(&file);
    QString text=ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("/home/volgin/MyFolder/SeaBattle/FileSeaField.txt"); // Путь к проверке файла.(Свой путь)
    if(!file.open(QFile::ReadOnly | QFile::Text)){
       QMessageBox::warning(this,"title","file not open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
QVector <QVector <int> > myVector(n,QVector<int>(n)); // Созданеи двумерного вектора.
 QFile file("/home/volgin/MyFolder/SeaBattle/FileSeaField.txt");
 if(!file.open(QFile::ReadOnly | QFile::Text)){
    QMessageBox::warning(this,"title","file not open");
 }

  QTextStream in(&file);
  QString text;
   // Считывание файла в матрицу и замена  *->1.
   for(int i = 0; i < 10; ++i){
       text=in.readLine();
       for (int j = 0; j < 10; ++j) {
       //Проверка на постаронние символы.
       if(text.at(j)=='*'||text.at(j)=='0'){
          if(text.at(j)=='*'){
            myVector[i+1][j+1]=1;
          }else{
              myVector[i+1][j+1]=0;
          }
       }else{
            GlobalError=false;
       }

       }
   }
   file.close();
   if(GlobalError){
   // Проверка массива.
   for (int i = 1; i <11; i++) // Цикл, который идёт по строкам
   {
           for (int j = 1; j < 11; j++){ // Цикл, который идёт по элементам
             if(myVector[i][j]==1){
                 myVector[i][j]=2;
                ChekBattleShip(myVector,i,j);
             }
           }

   }



if(CountShipOne==4&&CountShipTwo==3&&CountShipTree==2&&CountShipFore==1&&GlobalError){
    ui->label->setStyleSheet("color: rgb(51,102,0)");
    ui->label->setText("Результат анализа поля: поле заполнено корректно.");
}else{
    ui->label->setStyleSheet("color: rgb(255, 0, 0)");
     ui->label->setText("Результат анализа поля: поле заполнено некорректно.");
}
   }
   else{
       ui->label->setStyleSheet("color: rgb(255, 0, 0)");
        ui->label->setText("Результат анализа поля: поле заполнено некорректно.");
   }
 // Сброс параметров для последующей проверки поля.
 CountBattleShip=0;
 CountShipOne=0;
 CountShipTwo=0;
 CountShipTree=0;
 CountShipFore=0;
 GlobalError=true;

}

void MainWindow::ChekFunc(QVector <QVector <int> > &myVector,int Sizey, int Sizex)
{
    if(myVector[Sizey][Sizex]==1){
        GlobalError=false;
    }
}
//Функция для определения типа коробля и его правильного расположения.
void MainWindow::ChekBattleShip(QVector <QVector <int> > &myVector,  int Sizey , int Sizex){

// Флаги на проверку расположения корабля в пространстве
bool Horizontal=false;
bool Vertical=false;

//Флаг для выхода из проверки
bool Flag=true;

//Переменная считающая длинну корабля
int Lengh=1;
int StartPosX=Sizex;
int EndPosX=0;
int StartPosY=Sizey;

    while(Flag){
        // Проверка горизонтального корабля
        if(myVector[Sizey][Sizex+1]==1){
            Horizontal=true;
            Lengh++;
            Sizex++;
            EndPosX=Sizex;
            myVector[Sizey][Sizex]=2;
               // Проверка вертикального корабля
        }else if(myVector[Sizey+1][Sizex]==1){
                Vertical=true;
                Lengh++;
                Sizey++;
                myVector[Sizey][Sizex]=2;
        }
        else {
            Flag=false;
        }
    }
//Проверка на соприкосновение коробля с другими обьектами.
if(Horizontal){
    for (int i = StartPosY-1; i < Sizey+2; ++i) {
        for (int j = StartPosX-1; j < StartPosX+Lengh+1; ++j) {
            ChekFunc(myVector,i,j);
        }
    }
}else if(Vertical)
{
    for (int i = Sizey-Lengh; i < Lengh+2; ++i) {
        for (int j = StartPosX-1; j < StartPosX+2; ++j) {
             ChekFunc(myVector,i,j);
        }
    }
}


//Подсчет кораблей на поле.
switch (Lengh) {
case 1:
    CountShipOne++;
    break;
case 2:
    CountShipTwo++;
    break;
case 3:
    CountShipTree++;
    break;
case 4:
    CountShipFore++;
    break;
default:
    GlobalError=true;
    break;

}



}




