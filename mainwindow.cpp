#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QPushButton"
#include "QElapsedTimer"
#include "QTimer"
#include "QTime"

QElapsedTimer timer;
QTimer send_timer;
QList<QString> lapsList;

//class секундомера с логикой
class Stopwatch{
public:
    QElapsedTimer timer;
    QList<QString> lapsList;
    qint64 last_lap = 0;
    int laps = 1;

    void add_lap(qint64 time){
        last_lap = time;
        QString laps_qstring = QString::number(laps);
        QString time_qstring = QString::number(time);
        //lapsList.push_back("Lap " + laps_qstring + ", time " + time_qstring);
        qDebug() << ("Lap " + laps_qstring + ", time " + time_qstring);
        laps += 1;

    }
};

Stopwatch stopwatch;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //настраиваем секундомер
    ui->lbl_time->setText("00:00:00");
    send_timer.setInterval(0);

    //настраиваем кнопку старт-стоп
    ui->pb_startstop->setCheckable(true);

    connect(ui->pb_startstop, &QPushButton::toggled, this, &MainWindow::on_pb_startstop_toggled);
    connect(ui->pb_lap, &QPushButton::clicked, this, &MainWindow::on_pb_laps_clicked);
    connect(&send_timer, &QTimer::timeout, this, &MainWindow::time_send);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startstop_toggled(bool checked){
    if(!checked){
        ui->pb_startstop->setText("Start");
        send_timer.stop();
    }
    else{
        ui->pb_startstop->setText("Stop");\
        stopwatch.timer.start();
        send_timer.start();
    }
}

void MainWindow::on_pb_laps_clicked()
{
    stopwatch.add_lap(stopwatch.timer.elapsed());
}

void MainWindow::time_send(){
    ui->lbl_time->setText(QTime::fromMSecsSinceStartOfDay(stopwatch.timer.elapsed()).toString("hh:mm:ss"));
    send_timer.setInterval(100);
}

