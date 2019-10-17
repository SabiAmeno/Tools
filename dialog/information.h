#ifndef INFORMATION_H
#define INFORMATION_H

#include "ui_information.h"
#include <QDialog>

typedef enum
{
    INFO,
    WARN,
    ERROR
}Type;

typedef QPixmap*(*TIP_FUNC)();

class Prompt : public QDialog, private Ui::Information
{
    Q_OBJECT

public:
    explicit Prompt(Type t, QWidget *parent = 0);
    ~Prompt();

    static void information();
    static void warning();
    static void error();
protected:
    void paintEvent(QPaintEvent *);
private:
    void initMask();
    void startAnimation();
private:
    QPixmap* m_background;

    Type type;
    TIP_FUNC m_type_func;
};

#endif // INFORMATION_H
