#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
#include <QPlainTextEdit>
#include <QList>

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
         ui->plainTextEdit->appendPlainText(serialPortDescription);
         ui->plainTextEdit->appendPlainText(avariablePortList.at(i).portName());
         ui->plainTextEdit->appendPlainText(avariablePortList.at(i).serialNumber());
     }

}
