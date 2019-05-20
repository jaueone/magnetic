#ifndef DRIVESETING_H
#define DRIVESETING_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QGridLayout>
#include "my_control.h"
#include "camera.h"
#include "serial.h"

namespace Ui {
class DriveSeting;
}

class DriveSeting : public QWidget
{
    Q_OBJECT

public:
    explicit DriveSeting(QWidget *parent = nullptr);
    ~DriveSeting();

    void init();

    QString init_camera();

    QString init_serial();

    SerialSetting get_serial_setting();

    CameraSetting get_camera_setting();

    void load_setting();

    void scan_serial();

    void save_setting(SerialSetting setting_ser,CameraSetting setting_cam);

    unsigned short int CRC16(unsigned char* pchMsg, unsigned short int wDataLen);

    void check_self();
private slots:
    void accept_scan_serial();

    void on_pushButton_released();

    void on_serialPortInfoListBox_currentIndexChanged(int index);

    void on_pushButton_7_released();

    void on_pushButton_2_released();

    void on_pushButton_4_released();

    void on_pushButton_9_released();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

signals:
    void tell_window_step_page(int page);

private:
    Ui::DriveSeting *ui;
    QSerialPort *serial;
    HKCamera *camera;

    bool serial_check_self;
    bool camera_check_self;
};

#endif // DRIVESETING_H
