#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Stopwatch.h"

#include "QObject"
#include "QPushButton"
#include "QElapsedTimer"
#include "QTimer"
#include "QTime"
#include "QString"

QElapsedTimer timer;
QTimer send_timer;
QList<QString> lapsList;
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
    connect(&stopwatch, &Stopwatch::lapschanged, this, &MainWindow::laps_out);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::on_clear_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startstop_toggled(bool checked){
    if(!checked){
        ui->pb_startstop->setText("Start");
        send_timer.stop();
        stopwatch.clear_laps();
        ui->pb_clear->setEnabled(true);
    }
    else{
        ui->pb_startstop->setText("Stop");\
        stopwatch.timer.start();
        send_timer.start();
        ui->pb_clear->setEnabled(false);
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
void MainWindow::laps_out(const QString &lap){
    ui->tb_laps->append(lap);
}
void MainWindow::on_clear_clicked(){
    stopwatch.clear_laps();
    ui->lbl_time->setText("00:00:00");
}

