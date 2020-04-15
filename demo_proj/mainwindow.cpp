#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
#include <QPlainTextEdit>
#include <QList>
#include <QByteArray>
#include <QSerialPort>

QSerialPort usedPort;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_port_currentIndexChanged(int index)
{
    return;
}

void MainWindow::on_pushButton_open_clicked()
{
    int portCnt;
    bool convertRtvl;
    /*
     * By default, for an empty combo box, counter property has a value of 0
     */
    portCnt = ui->comboBox_port->count();

    if(portCnt > 0)
    {
        /*
         * After setting the port, you can open it in read-only (r/o), write-only (w/o), or read-write (r/w) mode
         * returns true if successful; otherwise returns false and sets
         * an error code which can be obtained by calling the error() method
         */
        if(usedPort.open(QIODevice::ReadWrite))
        {
             int dataBit, stopBit;
             QString parityBit;
             usedPort.setBaudRate(ui->comboBox_baudrate->currentText().toLong(&convertRtvl,10));
             dataBit = ui->comboBox_databit->currentText().toLong(&convertRtvl,10);
             switch(dataBit)
             {
                case 7:
                    usedPort.setDataBits(QSerialPort::Data7);
                 break;
                case 8:
                    usedPort.setDataBits(QSerialPort::Data8);
                 break;
                default:
                    break;
             }
             parityBit = ui->comboBox_databit->currentText();
             if(parityBit == "NONE")
             {
                 usedPort.setParity(QSerialPort::NoParity);
             }else if(parityBit == "EVEN")
             {
                 usedPort.setParity(QSerialPort::EvenParity);
             }else if(parityBit == "ODD")
             {
                 usedPort.setParity(QSerialPort::OddParity);
             }
             stopBit = ui->comboBox_stopbit->currentText().toLong(&convertRtvl,10);
             switch(stopBit)
             {
                case 1:
                 usedPort.setStopBits(QSerialPort::OneStop);
                 break;
                case 2:
                 usedPort.setStopBits(QSerialPort::TwoStop);
                 break;
                default:
                 break;
             }
             usedPort.setFlowControl(QSerialPort::NoFlowControl);
             /*
              * This property SerialPortError holds the error status of the serial port.
              * this property can be used to figure out the reason why the operation failed
              * The error code is set to the default QSerialPort::NoError after a call to clearError()
              */
             usedPort.clearError();
             /*
              * Discards all characters from the output or input buffer,
              * terminate pending read or write
              */
             usedPort.clear();
             /*
              * This signal is emitted once every time new data is available for reading from the device.
              * such as when a new block of data has been appended to your device
              */
             connect(&usedPort, SIGNAL(readyRead()), this, SLOT(ReadDataInputSlot()));
             ui->plainTextEdit->appendPlainText("Open serialPort success");
        }
        else
        {
            ui->plainTextEdit->appendPlainText("Open serialPort error");
        }
    }
    else
    {
        ui->plainTextEdit->appendPlainText("No serialPort avariable now, Plese check first.");
    }

}

void MainWindow::ReadDataInputSlot()
{
    /*
     * Reads all remaining data from the device, and returns it as a byte array.
     * This function has no way of reporting errors
     */
    QByteArray arr = usedPort.readAll().toHex();
    QString showData(arr);
    ui->plainTextEdit->appendPlainText("Print Input Data: " + showData);
}


void MainWindow::on_pushButton_check_clicked()
{
    QSerialPortInfo serialPortInfo;
    QList<QSerialPortInfo> avariablePortList;

    avariablePortList = serialPortInfo.availablePorts();
    //avariablePortList = QSerialPortInfo::availablePorts();

    /*
     * Changes the text of the text edit to the string text.
     * Any previous text is removed.
     * @para: const QString &text
     * @Note: Setter function for property plainText
     */
    const QString text = "good lock";
    QString returnedPlainText;
    ui->plainTextEdit->setPlainText("hello world!");
    /*
     * Inserts text at the current cursor position
     * @para: const QString &text
     * @Note: Getter function for property plainText.
     */
    //ui->plainTextEdit->insertPlainText(text);
    /*
     * Returns the text of the text edit as plain text.
     * @para: const QString &text
     * @Note: Getter function for property plainText.
     */
    returnedPlainText = ui->plainTextEdit->toPlainText();
    /*
     * Appends a new paragraph with text to the end of the text edit.
     * @para: const QString &text
     * @Note: Setter function for property plainText
     */
    ui->plainTextEdit->appendPlainText(returnedPlainText);


    if(avariablePortList.isEmpty())
    {
        ui->plainTextEdit->setPlainText("No SerialPort Avaliable!");
        return;
    }
    /*
     *  QList is used throughout the Qt APIs for passing parameters and for returning values
     *  QList<T> is represented as an array of T* and the items are allocated on the heap
     *  The array representation allows very fast insertions and index-based access.
     */
    QString serialPortDescription;
    for (int i = 0; i < avariablePortList.size(); ++i)
    {
        //at() can be faster than operator[](), because it never causes a deep copy to occur.
        serialPortDescription = avariablePortList.at(i).description();
        ui->plainTextEdit->appendPlainText("description:   " + serialPortDescription);
        ui->plainTextEdit->appendPlainText("portname:   " + avariablePortList.at(i).portName());
        ui->comboBox_port->addItem(avariablePortList.at(i).portName());
        ui->plainTextEdit->appendPlainText("serialnumber:   " + avariablePortList.at(i).serialNumber());
        /*
         * Returns a list of available standard baud rates supported by the target platform.
         */
        QList<qint32> portSupportBaud = avariablePortList.at(i).standardBaudRates();
        ui->plainTextEdit->appendPlainText("supportedbaudrate: ");
        foreach(qint32 bardRate, portSupportBaud)
        {
            ui->plainTextEdit->insertPlainText(QByteArray::number(bardRate, 10) + "/");
        }
    }
    /*
     * Sets the port which stored in the serial port info instance serialPortInfo.
     */
    usedPort.setPort(avariablePortList.first());

}
