#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Stopwatch.h"

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
    void time_updating(const QString);
    void laps_out(const QString&);
    void on_clear_clicked();

public: Q_SIGNALS:
    void lapschanged(const QString&);

private:
    Ui::MainWindow *ui;
    Stopwatch* stopwatch;
};
#endif // MAINWINDOW_H
