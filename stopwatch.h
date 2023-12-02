#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "qobject.h"
#include "QElapsedTimer"
#include "QTime"

class Stopwatch : public QObject{

    Q_OBJECT

public:
    QElapsedTimer timer;
    QString lap_out;
    qint64 last_lap = 0;
    int laps = 1;

    void add_lap(qint64 time){
        last_lap = time;
        QString laps_qstring = QString::number(laps);
        QString time_qstring = QTime::fromMSecsSinceStartOfDay(time).toString("hh:mm:ss");
        lap_out = "Lap: " + laps_qstring + " Time: " + time_qstring + "\n";
        laps += 1;

        emit lapschanged(lap_out);
    }
    void clear_laps(){
        laps = 1;
        last_lap = 0;
    }

Q_SIGNALS:
    QString lapschanged(const QString &lap_out);

};


#endif // STOPWATCH_H
