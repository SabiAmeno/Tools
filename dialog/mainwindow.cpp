#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"

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

void MainWindow::on_pushButton_clicked(bool)
{
    Prompt::information();
}

void MainWindow::on_pushButton_2_clicked(bool)
{
    Prompt::warning();
}

void MainWindow::on_pushButton_3_clicked(bool)
{
    Prompt::error();
}
