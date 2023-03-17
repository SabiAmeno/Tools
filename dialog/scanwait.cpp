#include "scanwait.h"
#include <QPainter>
#include <QMouseEvent>
#include "ui_ScanDialog.h"

//static int radius[] = {19,19,19,19, 19, 24, 28, 33};

ScanWait::ScanWait(QWidget *parent)
    : QWidget(parent)
{
//    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
//    setAttribute(Qt::WA_X11DoNotAcceptFocus);
//    setAttribute(Qt::WA_DeleteOnClose);
//    setAttribute(Qt::WA_TranslucentBackground);
//    setAttribute(Qt::WA_TransparentForMouseEvents,true);
//    setAttribute(Qt::WA_ShowWithoutActivating);

//    setFocusPolicy(Qt::NoFocus);
//    setFixedSize(100, 100);
    setMouseTracking(true);

    timer.setInterval(100);
    connect(&timer, &QTimer::timeout, this, &ScanWait::timeUpdate);

    m_exchange_ind = 0;
    is_hover = false;
}

void ScanWait::start()
{
    timer.start();
}

void ScanWait::stop()
{
    timer.stop();
}

void ScanWait::timeUpdate()
{
    m_exchange_ind++;

    update();
}

void ScanWait::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.save();
    painter.setBrush(Qt::green);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.setPen(QPen(Qt::red, 25));

    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);

    QFontMetrics fm(font);
    QSize s = fm.size(0, m_info);
    painter.drawText(-s.width() / 2, 0, m_info);

//    if(!is_hover)
//    {
    for(int i = 0;i < 3;++i)
    {
        painter.save();
        QPainterPath path;
        path.addEllipse(QPointF(45, 0), 6 + i * 2, 6 + i * 2);
        painter.rotate(45.0 * (i + m_exchange_ind));
        painter.fillPath(path, Qt::cyan);
        painter.restore();
    }
//    }
//    else
//    {
//        QPixmap pix(":/icons/pause.png");
//        painter.drawPixmap(QPointF(-pix.width()/2, -pix.height()/2), pix);
//    }

    for(int i = 0;i < 8;++i)
    {
        painter.save();
        QPainterPath path;
        path.addEllipse(QPointF(45, 0), 3, 3);
        painter.rotate(45.0 * i);
        painter.fillPath(path, Qt::green);
        painter.restore();
    }
    painter.restore();
}

void ScanWait::mouseMoveEvent(QMouseEvent *event)
{
//    QPointF pos = event->pos();
//    QPointF cp(width() / 2, height() / 2);
//    region = QRectF(QPointF(cp.x() - 50, cp.y() - 50), QSizeF(100, 100));

//    if(region.contains(pos))
//    {
//        is_hover = true;
//    }
//    else
//    {
//        is_hover = false;
//        region = QRectF(0, 0, 0, 0);
//    }

//    update();
}

void ScanWait::mousePressEvent(QMouseEvent *)
{
//    if(!is_hover)
//    {
//        return;
//    }

//    emit stop();
}

/////////////////////////////////////////////
ScanDialog::ScanDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Scan())
{
    ui->setupUi(this);

    m_sw = new ScanWait();
    ui->gridLayout->addWidget(m_sw);
    connect(ui->start_btn, SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->stop_btn, SIGNAL(clicked()), this, SLOT(Stop()));
}

ScanDialog::~ScanDialog()
{
    delete ui;
}

void ScanDialog::Start()
{
    m_sw->start();
}

void ScanDialog::Stop()
{
    m_sw->stop();
}



