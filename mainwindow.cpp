#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Stopwatch.h"

#include "QObject"
#include "QPushButton"
#include "QElapsedTimer"
#include "QTimer"
#include "QTime"
#include "QString"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qint64 send_interval = 10;
    stopwatch = new Stopwatch(send_interval);


    //настраиваем секундомер
    ui->lbl_time->setText("00:00:00:00");
    ui->pb_lap->setEnabled(false);

    //настраиваем кнопку старт-стоп
    ui->pb_startstop->setCheckable(true);

    connect(ui->pb_startstop, &QPushButton::toggled, this, &MainWindow::on_pb_startstop_toggled);
    connect(ui->pb_lap, &QPushButton::clicked, this, &MainWindow::on_pb_laps_clicked);
    connect(stopwatch, &Stopwatch::time_update, this, &MainWindow::time_updating);
    connect(stopwatch, &Stopwatch::lapschanged, this, &MainWindow::laps_out);
    connect(ui->pb_clear, &QPushButton::clicked, this, &MainWindow::on_clear_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete stopwatch;
}

void MainWindow::on_pb_startstop_toggled(bool checked){
    if(!checked){
        stopwatch->start_stop(checked);
        ui->pb_startstop->setText("Start");
        ui->pb_lap->setEnabled(false);
    }
    else{
        stopwatch->start_stop(checked);
        ui->pb_startstop->setText("Stop");
        ui->pb_lap->setEnabled(true);
    }
}

void MainWindow::on_pb_laps_clicked()
{
    stopwatch->add_lap();
}

void MainWindow::time_updating(const QString upgrtime){
    ui->lbl_time->setText(upgrtime);
}
void MainWindow::laps_out(const QString &lap){
    ui->tb_laps->append(lap);
}
void MainWindow::on_clear_clicked(){
    stopwatch->clear_laps();
    ui->lbl_time->setText("00:00:00:00");
}

