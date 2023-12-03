#include "Stopwatch.h"

void Stopwatch::add_lap(){
            qint64 new_lap = curr_time;
            new_lap = new_lap - last_lap;
            last_lap += new_lap;
            QString laps_qstring = QString::number(laps);
            QString tmpstr;

            if((new_lap%1000)/10 < 10){
                tmpstr = "0" + QString::number((new_lap%1000)/10);
            }
            else{
                tmpstr = QString::number((new_lap%1000)/10);
            }
            QString time_qstring = QTime::fromMSecsSinceStartOfDay(new_lap).toString("hh:mm:ss") + ":" + tmpstr;
            lap_out = "Lap: " + laps_qstring + " Time: " + time_qstring + "\n";
            laps += 1;

            emit lapschanged(lap_out);
};

void Stopwatch::clear_laps(){
            laps = 1;
            last_lap = 0;
            curr_time = 0;
};

void Stopwatch::start_stop(bool checked){
            if(!checked){
                send_timer.stop();
                clear_laps();
            }
            else{
                send_timer.start();
            }
};

QString Stopwatch::time_sender(){
            curr_time += 10;
            qint64 tmp = curr_time;
            QString tmpstr;

            if((tmp%1000)/10 < 10){
                tmpstr = "0" + QString::number((tmp%1000)/10);
            }
            else{
                tmpstr = QString::number((tmp%1000)/10);
            }
            QString res = QTime::fromMSecsSinceStartOfDay(tmp).toString("hh:mm:ss") + ":" + tmpstr;
            return res;
};

void Stopwatch::setting_send_timer(qint64 interv){
            send_timer.setInterval(10);
}
