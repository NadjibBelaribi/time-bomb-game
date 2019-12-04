#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    options *o = new options;
    o->showNormal();
     this->window()->close();
}

void MainWindow::on_leaveButton_clicked()
{
    this->window()->close();
}
