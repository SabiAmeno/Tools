#include "information.h"
#include <QPainter>
#include <QBitmap>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <iostream>

static QPixmap* pixmap_info()
{
    return new QPixmap(":/icons/confirm.png");
}

static QPixmap* pixmap_warn()
{
    return new QPixmap(":/icons/warn.png");
}

static QPixmap* pixmap_error()
{
    return new QPixmap(":/icons/error.png");
}

Prompt::Prompt(Type t, QWidget *parent) :
    QDialog(parent), type(t)
{
    setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);
    setAttribute(Qt::WA_X11DoNotAcceptFocus);
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    setFocusPolicy(Qt::NoFocus);

    QWidget* screen = QApplication::desktop()->screen();
    move(screen->width() / 2, screen->height() / 4 * 3);

    switch (t) {
    case INFO:
        m_type_func = pixmap_info;
        break;
    case WARN:
        m_type_func = pixmap_warn;
        break;
    case ERROR:
        m_type_func = pixmap_error;
        break;
    default:
        break;
    }

    initMask();
    startAnimation();
}

Prompt::~Prompt()
{
    delete m_background;
}

void Prompt::information()
{
    Prompt* info = new Prompt(INFO, QApplication::desktop());
    info->show();
}

void Prompt::warning()
{
    Prompt* info = new Prompt(WARN, QApplication::desktop());
    info->show();
}

void Prompt::error()
{
    Prompt* info = new Prompt(ERROR, QApplication::desktop());
    info->show();
}

void Prompt::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, m_background->width(), m_background->height(), *m_background);
}


void Prompt::initMask()
{
    m_background = m_type_func();

    resize(m_background->size());
    clearMask();
    setMask(m_background->mask());
}

void Prompt::startAnimation()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}
