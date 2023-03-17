#ifndef SCANTYPESELECTOR_H
#define SCANTYPESELECTOR_H

#include <QDialog>

namespace Ui {
class ScanTypeSelector;
}

class ScanTypeSelector : public QDialog
{
    Q_OBJECT

public:
    explicit ScanTypeSelector(QWidget *parent = nullptr);
    ~ScanTypeSelector();

private slots:
    void on_mannual_scan_clicked();

    void on_onekey_scan_clicked();

private:
    Ui::ScanTypeSelector *ui;
};

#endif // SCANTYPESELECTOR_H
