#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void on_pb_startstop_toggled(bool checked);
    void on_pb_laps_clicked();
    void time_send();

public: Q_SIGNALS:
   //void on_pb_clicked(bool checked = false);
   //void timer_stpwtch_timeout(QPrivateSignal);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
