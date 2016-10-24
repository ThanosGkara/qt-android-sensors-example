#include <QDateTime>
#include <QVariant>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit_1->setReadOnly(true);
    ui->textEdit_bottom->setReadOnly(true);
    ui->textEdit_3->setReadOnly(true);
    ui->textEdit_4->setReadOnly(true);
    ui->textEdit_5->setReadOnly(true);
    ui->textEdit_6->setReadOnly(true);

    accel = new QAccelerometer(this);
    compass = new QCompass(this);
    mag_meter = new QMagnetometer(this);
    gyro = new QGyroscope(this);
    rotation = new QRotationSensor(this);
    presure = new QPressureSensor(this);

    connect(accel, SIGNAL(readingChanged()), this, SLOT(update_accel()));
    connect(compass, SIGNAL(readingChanged()), this, SLOT(update_compass()));
    connect(mag_meter, SIGNAL(readingChanged()), this, SLOT(update_mag_meter()));
    connect(gyro, SIGNAL(readingChanged()), this, SLOT(update_gyroscope()));
    connect(rotation, SIGNAL(readingChanged()), this, SLOT(update_rotation()));
    connect(presure, SIGNAL(readingChanged()), this, SLOT(upate_presure()));

    accel->setDataRate(1);
    accel->start();

    compass->setDataRate(1);
    compass->start();

    mag_meter->setDataRate(1);
    mag_meter->start();

    gyro->setDataRate(1);
    gyro->start();

    rotation->setDataRate(1);
    rotation->start();

    presure->setDataRate(1);
    presure->start();

//    qrangelist compass_data_rates = compass->availableDataRates();
//    qrangelist accel_data_rates = accel->availableDataRates();
//    qrangelist mag_data_rates = mag_meter->availableDataRates();
//    qrangelist gyro_data_rates = gyro->availableDataRates();

    if (compass->isBusy())
    {
        ui->textEdit_bottom->append("QCompass is busy...");
    }
    if(compass->isConnectedToBackend())
    {
        ui->textEdit_bottom->append("QCompass is connected to backend...");
    }
    if(compass->isActive())
    {
        ui->textEdit_bottom->append("QCompass isActive...");
    }

    if (mag_meter->isBusy())
    {
        ui->textEdit_bottom->append("QMagnetometer is busy...");
    }
    if(mag_meter->isConnectedToBackend())
    {
        ui->textEdit_bottom->append("QMagnetometer is connected to backend...");
    }
    if(mag_meter->isActive())
    {
        ui->textEdit_bottom->append("QMagnetometer isActive...");
    }

    if (gyro->isBusy())
    {
        ui->textEdit_bottom->append("QGyroscope is busy...");
    }
    if(gyro->isConnectedToBackend())
    {
        ui->textEdit_bottom->append("QGyroscope is connected to backend...");
    }
    if(gyro->isActive())
    {
        ui->textEdit_bottom->append("QGyroscope isActive...");
    }

    if (rotation->isBusy())
    {
        ui->textEdit_bottom->append("QRotationSensor is busy...");
    }
    if(rotation->isConnectedToBackend())
    {
        ui->textEdit_bottom->append("QRotationSensor is connected to backend...");
    }
    if(rotation->isActive())
    {
        ui->textEdit_bottom->append("QRotationSensor isActive...");
    }

    if (presure->isBusy())
    {
        ui->textEdit_bottom->append("QPressureSensor is busy...");
    }
    if(presure->isConnectedToBackend())
    {
        ui->textEdit_bottom->append("QPressureSensor is connected to backend...");
    }
    if(presure->isActive())
    {
        ui->textEdit_bottom->append("QPressureSensor isActive...");
    }

    ui->textEdit_bottom->append("Reading Sensors......");
}

MainWindow::~MainWindow()
{
    delete accel;
    delete compass;
    delete mag_meter;
    delete gyro;
    delete rotation;
    delete presure;
    delete ui;
}

void MainWindow::update_accel()
{
    QString text;

    accel_reading = accel->reading();
//    text = tr("%1\nAcceleration:\n  x = %2\n  y = %3\n  z = %4").arg(QDateTime::currentDateTime().toString()).arg(accel_reading->x()).arg(accel_reading->y()).arg(accel_reading->z());
    text = tr("Acceleration:\n  x = %1\n  y = %2\n  z = %3").arg(accel_reading->x()).arg(accel_reading->y()).arg(accel_reading->z());
    ui->textEdit->setText(text);

}

void MainWindow::update_compass()
{
    QString text;
    compass_reading = compass->reading();

    if(compass_reading != 0)
    {
//      text = QDateTime::currentDateTime().toString() +
        text = "Compass:  \nazimuth = " + QString::number(compass_reading->azimuth())
               + "\ncalibration level = " + QString::number(compass_reading->calibrationLevel());

        ui->textEdit_1->setText(text);
    }
    else
    {
            text = "Compass: UNAVAILABLE";
            ui->textEdit_1->setText(text);
    }

}

void MainWindow::update_mag_meter()
{
    QString text;
    mag_meter_reading = mag_meter->reading();

    if(mag_meter !=0)
    {
        text = tr("Magnetometer:\n  x = %1\n  y = %2\n  z = %3").arg(mag_meter_reading->x()).arg(mag_meter_reading->y()).arg(mag_meter_reading->z());
        ui->textEdit_3->setText(text);
    }
    else
    {
            text = "Magnetometer: UNAVAILABLE";
            ui->textEdit_3->setText(text);
    }
}

void MainWindow::update_gyroscope()
{
    QString text;
    gyro_reading = gyro->reading();

    if(gyro_reading !=0)
    {
        text = tr("Gyroscope:\n  x = %1\n  y = %2\n  z = %3").arg(gyro_reading->x()).arg(gyro_reading->y()).arg(gyro_reading->z());
        ui->textEdit_4->setText(text);
    }
    else
    {
            text = "Gyroscope: UNAVAILABLE";
            ui->textEdit_4->setText(text);
    }
}

void MainWindow::update_rotation()
{
    QString text;
    rotation_reading = rotation->reading();

    if(gyro_reading !=0)
    {
        text = tr("Rotation:\n  x = %1\n  y = %2\n  z = %3").arg(rotation_reading->x()).arg(rotation_reading->y()).arg(rotation_reading->z());
        ui->textEdit_5->setText(text);
    }
    else
    {
            text = "Rotation: UNAVAILABLE";
            ui->textEdit_5->setText(text);
    }
}

void MainWindow::upate_presure()
{
    QString text;
    presure_reader = presure->reading();

    if(presure_reader != 0)
    {
        text = tr("Presusre: %1\nTemperature: %2").arg(presure_reader->pressure()).arg(presure_reader->temperature());
        ui->textEdit_6->setText(text);
    }
    else
    {
            text = "Altitude: UNAVAILABLE";
            ui->textEdit_6->setText(text);
    }
}

void MainWindow::error(int erreur) {
    QMessageBox::critical(this, "Erreur", "Erreur num : " + QString::number(erreur).toUtf8());
}
