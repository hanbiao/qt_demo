#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_port_currentIndexChanged(int index);

    void on_pushButton_open_clicked();

    void on_pushButton_check_clicked();

    void ReadDataInputSlot();

private:
    Ui::MainWindow *ui;
    //QSerialPort usedPort;
};

#endif // MAINWINDOW_H
