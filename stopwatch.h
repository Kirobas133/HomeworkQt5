#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "qobject.h"
#include "QTime"
#include "QTimer"


class Stopwatch : public QObject{

    Q_OBJECT

private:
    QList<QString> lapsList;
    QString lap_out;
    qint64 last_lap = 0;
    int laps = 1;
    qint64 curr_time = 0;
public:
    QTimer* send_timer;
    Stopwatch(qint64 interv);
    ~Stopwatch();

    void add_lap();
    void clear_laps();
    void start_stop(bool checked);
    void time_sender();

Q_SIGNALS:
    QString lapschanged(const QString &lap_out);
    QString time_update(QString upgrtime);

};


#endif // STOPWATCH_H
