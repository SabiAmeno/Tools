#ifndef UDEFDIALOG_H
#define UDEFDIALOG_H

#include <QDialog>

namespace Ui {
class udefDialog;
}

class udefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit udefDialog(QWidget *parent = nullptr);
    ~udefDialog();

    void setCenterWidget(QWidget* w);

signals:
    void closed();
private slots:
    void setMaximumSize();
    void setMinimumSize();
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
private:
    Ui::udefDialog *ui;

    QPoint last;
    bool pressed;
};

#endif // UDEFDIALOG_H
