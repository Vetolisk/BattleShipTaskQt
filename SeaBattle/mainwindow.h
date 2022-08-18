#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Сохранение файла из приложения.
    void on_pushButton_clicked();
    // Вывод файла в приложение.
    void on_pushButton_2_clicked();
    // Проверка файла.
    void on_pushButton_3_clicked();
    void ChekFunc(QVector<QVector<int> > &myVector, int Sizey, int Sizex);
    //Функция на проверку массива есть ли 1 или нет.
    void ChekBattleShip(QVector<QVector<int> > &myVector, int Sizey, int Sizex);

private:
    Ui::MainWindow *ui;
    // Размер поля с доп полями для предотвращения выхода за пределы вектора.
    int n=12;
    // Глобальная проверка
    bool GlobalError=true;
    // Типы кораблей
    int CountBattleShip=0;
    int CountShipOne=0;
    int CountShipTwo=0;
    int CountShipTree=0;
    int CountShipFore=0;

};
#endif // MAINWINDOW_H
