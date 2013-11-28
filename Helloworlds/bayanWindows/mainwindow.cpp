#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDesktopWidget>
#include <sstream>
#include <QDebug>


//just for fun and templates
/*template <typename T>
  std::string NumberToString1 ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

  template <typename T>
    char * NumberToString ( T Number )
    {
        return QString::number (Number).to();

    }
*/




MainWindow::MainWindow(bool flag, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //попробуем сделать 2 диалога таким образом, чтобы места хватило всем, на любом мониторе

    //получили размеры рабочего стола
    QDesktopWidget desktop;
    int desktopHeight=desktop.geometry().height();
    int desktopWidth=desktop.geometry().width();
    //ещё один способ
    /*
QDesktopWidget widget;
QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());
 // or screenGeometry(), depending on your needs
    */

desktopHeight-=80;
//desktopWidth-=20;

    char number = 5;
    int windowWidth = desktopWidth/number-15;


/*

    qDebug()<<desktopHeight;
    qDebug()<<desktopWidth;
    qDebug()<<windowWidth;

*/

    ui->setupUi(this);


    if (!flag) return;

    resize(windowWidth,desktopHeight );
    move (0,0);


    for (int i=0; i<number-1; i++)
    {
    //QDialog * mw = new QDialog (this);
        //MainWindow * mw = new MainWindow (0, this);
        //в этом виде все дочерние окна - дочерние для одного, самого левого


        MainWindow * mw = new MainWindow (0);
        //а в этом виде они все независимы друг от друга


        mw->show();
    mw->resize(windowWidth, desktopHeight);

    mw->move ((1+i)*(windowWidth+15), 0);
    }


/*
если и дальше идти этим путём - заполнять весь экран окнами, и понимать,
что окна будут рожать друг друга (то есть, не родительское кучу дочерних, как в этом примере,
а каждое окно может родить по окну, ичх не факт, что по одному, может их тогда распихивать не в ряд,
а по вертикали
то нужен один контроллер, который будет изменять ширину всех окон, как только появится новое.
Этот контроллер должен иметь ссылки на все окна. Это не может быть родительское окно, так как его могут закрыть
Это может быть просто класс контроллера, который строится первым открытым окном, и удаляется,
когда приложение закрыто.
выходит, что все вышеописаннные окна принадлежат одному приложению.





*/


}

MainWindow::~MainWindow()
{
    delete ui;
}
