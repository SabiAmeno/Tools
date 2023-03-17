#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "information.h"
#include "scantypeselector.h"
#include "udefdialog.h"
#include <QLabel>

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

void MainWindow::on_pushButton_4_clicked()
{
    ScanTypeSelector* scan = new ScanTypeSelector();
    scan->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    udefDialog* dlg = new udefDialog(this);
    ScanTypeSelector* scan = new ScanTypeSelector();
    dlg->setCenterWidget(scan);
    dlg->show();
}
