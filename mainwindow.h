#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QAccelerometer>
#include <QAccelerometerReading>
#include <QMainWindow>
#include <QCompass>
#include <QCompassReading>
#include <QMagnetometer>
#include <QMagnetometerReading>
#include <QGyroscope>
#include <QGyroscopeReading>
#include <QRotationSensor>
#include <QRotationReading>
#include <QPressureSensor>
#include <QPressureReading>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void update_accel();
    void update_compass();
    void update_mag_meter();
    void update_gyroscope();
    void update_rotation();
    void upate_presure();
    void error(int);

private:
    Ui::MainWindow *ui;
    QAccelerometer *accel;
    QAccelerometerReading *accel_reading;
    QCompass *compass;
    QCompassReading *compass_reading;
    QMagnetometer *mag_meter;
    QMagnetometerReading *mag_meter_reading;
    QGyroscope *gyro;
    QGyroscopeReading *gyro_reading;
    QRotationSensor *rotation;
    QRotationReading *rotation_reading;
    QPressureSensor *presure;
    QPressureReading *presure_reader;
};

#endif // MAINWINDOW_H
