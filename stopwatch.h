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
    QTimer send_timer;

    void add_lap();
    void clear_laps();
    void start_stop(bool checked);
    QString time_sender();
    void setting_send_timer(qint64 interv);

Q_SIGNALS:
    QString lapschanged(const QString &lap_out);

};


#endif // STOPWATCH_H
