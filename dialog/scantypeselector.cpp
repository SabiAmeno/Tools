#include "scantypeselector.h"
#include "ui_scantypeselector.h"
#include "scanwait.h"

ScanTypeSelector::ScanTypeSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanTypeSelector)
{
    ui->setupUi(this);
}

ScanTypeSelector::~ScanTypeSelector()
{
    delete ui;
}

void ScanTypeSelector::on_mannual_scan_clicked()
{

}

void ScanTypeSelector::on_onekey_scan_clicked()
{
    hide();
    ScanDialog* sd = new ScanDialog();
    sd->show();
}
