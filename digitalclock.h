#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DigitalClock(QObject *parent = 0);
    
signals:
    
public slots:

private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
