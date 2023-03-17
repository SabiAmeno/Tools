#include "udefdialog.h"
#include "ui_udefdialog.h"
#include <QMouseEvent>

udefDialog::udefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::udefDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    pressed = false;

    connect(ui->maximum, SIGNAL(clicked()), this, SLOT(setMaximumSize()));
    connect(ui->minimum, SIGNAL(clicked()), this, SLOT(setMinimumSize()));
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->close, SIGNAL(clicked()), this, SIGNAL(closed()));
}

udefDialog::~udefDialog()
{
    delete ui;
}

void udefDialog::setCenterWidget(QWidget *w)
{
    if(!w)
    {
        return;
    }

    ui->frame->layout()->addWidget(w);
}

void udefDialog::setMaximumSize()
{
    if(isMaximized())
    {
        showNormal();
    }
    else
    {
        showMaximized();
    }
}

void udefDialog::setMinimumSize()
{
    minimumSize();
}

void udefDialog::mousePressEvent(QMouseEvent* e)
{
    if(ui->widget->rect().contains(e->pos()))
    {
        last = e->globalPos();
        pressed = true;
    }
}
void udefDialog::mouseMoveEvent(QMouseEvent* e)
{
    if(!pressed)
    {
        return;
    }
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x() + dx, y() + dy);
}
void udefDialog::mouseReleaseEvent(QMouseEvent* e)
{
    if(!pressed)
    {
        return;
    }
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x() + dx, y() + dy);
    pressed = false;
}
