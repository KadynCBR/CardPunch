#include "digitalclock.h"

DigitalClock::DigitalClock(QObject *parent) :
    QLCDNumber(parent)
{
    setSegmentStyle(filled);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    showTime();

    setWindowTitle(tr("Punch Card"));
}

void DigitalClock::showTime() {
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second()%2) == 0)
        text[2] = ' ';
    display(text);
}
