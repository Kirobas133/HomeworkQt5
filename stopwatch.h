#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "qobject.h"
#include "QElapsedTimer"
#include "QTime"
#include "QTimer"


class Stopwatch : public QObject{

    Q_OBJECT

private:
    QElapsedTimer timer;

    QList<QString> lapsList;
    QString lap_out;
    qint64 last_lap = 0;
    int laps = 1;

public:
    QTimer send_timer;

    void add_lap(){
        qint64 new_lap = timer.elapsed();
        new_lap = new_lap - last_lap;
        last_lap += new_lap;
        QString laps_qstring = QString::number(laps);
        QString time_qstring = QTime::fromMSecsSinceStartOfDay(new_lap).toString("hh:mm:ss") + ":" + QString::number((new_lap%1000)/10);
        lap_out = "Lap: " + laps_qstring + " Time: " + time_qstring + "\n";
        laps += 1;

        emit lapschanged(lap_out);
    }
    void clear_laps(){
        laps = 1;
        last_lap = 0;
    }
    void start_stop(bool checked){
        if(!checked){
            send_timer.stop();
            clear_laps();
        }
        else{
            timer.start();
            send_timer.start();
        }
    }
    QString time_sender(){
        qint64 tmp = timer.elapsed();
        QString res = QTime::fromMSecsSinceStartOfDay(tmp).toString("hh:mm:ss") + ":" + QString::number((tmp%1000)/10);
        return res;
    }
    void setting_send_timer(qint64 interv){
        send_timer.setInterval(10);
    }

Q_SIGNALS:
    QString lapschanged(const QString &lap_out);

};


#endif // STOPWATCH_H
