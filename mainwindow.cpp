#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , pixmap_{715,281}
    , x_{40}
    , y_{40}
    , width_{5}
    , colour_{QColor(Qt::black)}  // default colour
{
    ui_->setupUi(this);
    //https://forum.qt.io/topic/70049/how-to-do-qpainter-paint-in-the-widget/2

    pixmap_.fill(QColor("white"));
    PaintRight();
    connect(ui_->upButton,&QPushButton::clicked,this,&MainWindow::PaintUp);
    connect(ui_->leftButton,&QPushButton::clicked,this,&MainWindow::PaintLeft);
    connect(ui_->downButton,&QPushButton::clicked,this,&MainWindow::PaintDown);
    connect(ui_->rightButton,&QPushButton::clicked,this,&MainWindow::PaintRight);
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

void MainWindow::PaintUp()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_,y_-20);
    ui_->label->setPixmap(pixmap_);
    y_-=20;
    QPushButton *a = new QPushButton;
}

void MainWindow::PaintLeft()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_-20,y_);
    ui_->label->setPixmap(pixmap_);
    x_-=20;
    QPushButton *a = new QPushButton;
}

void MainWindow::PaintDown()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_,y_+20);
    ui_->label->setPixmap(pixmap_);
    y_+=20;
    QPushButton *a = new QPushButton;
}


void MainWindow::PaintRight()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_+20,y_);
    ui_->label->setPixmap(pixmap_);
    x_+=20;
    QPushButton *a = new QPushButton;
}

MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui_->label->grab().save("image.png");
    delete ui_;
}


void MainWindow::on_editWidth_triggered()
{
    width_ = QInputDialog::getInt(this, "Pen width", "Enter width:", 10, 1);
}


void MainWindow::on_editColour_triggered()
{
    colour_ = QColorDialog::getColor(Qt::black, this, "Pen color");
}

