#ifndef SCANWAIT_H
#define SCANWAIT_H

#include <QObject>
#include <QDialog>
#include <QTimer>

namespace Ui {
    class Scan;
}

class ScanWait : public QWidget
{
    Q_OBJECT
public:
    ScanWait(QWidget* parent = nullptr);

    void updateInfo(const QString& info) {m_info = info;}

public slots:
    void start();
    void stop();

private slots:
    void timeUpdate();
protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
private:
private:
    QTimer timer;
    long long m_exchange_ind;

    QString m_info;

    bool is_hover;
    QRectF region;
};

class ScanDialog : public QDialog
{
    Q_OBJECT
public:
    ScanDialog(QWidget* parent = nullptr);

    ~ScanDialog();

private slots:
    void Start();
    void Stop();
private:
    ScanWait* m_sw;

    Ui::Scan* ui;
};

#endif // SCANWAIT_H
