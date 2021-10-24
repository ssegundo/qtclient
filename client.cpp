#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) //constructor
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    //instaciar socket
    clientSocket = new QTcpSocket(this);
    //inicializando el datastream (canal)
    in.setDevice(clientSocket);
    connect(ui->pBtn_Close, &QAbstractButton::clicked, this, &QWidget::close);
    // Procesar datos recibidos
    connect(clientSocket, &QIODevice::readyRead, this, &Client::readMessage);
    // Boton conectar
    connect(ui->pBtn_Connect, &QAbstractButton::clicked, this, &Client::requestMessage);
    // Capturando errores de comunicación
}

Client::~Client()   //destructor
{
    delete ui;
}

/**
 * @brief Client::requestMessage
 * Este slot inicia la comunicacion con el Servidor
 * y se solicita un mensaje
 */

void Client::requestMessage()
{
    qDebug() << "requestMessage() start ...";
    QString ipAddress = ui->lEdt_ip->text();
    QString port = ui->lEdt_port->text();
    qDebug() << "ip= "<< ipAddress << ", port= " << port;

    clientSocket->connectToHost(ipAddress,port.toInt());
    qDebug() << "requestMessage() end ...";
}

/**
 * @brief Client::readMessage
 * Este slot inicia la lectura del mensaje que ha llegado al cliente
*/
void Client::readMessage()
{
    qDebug() << "readMessage() start ...";
    in.startTransaction();
    QString message;
    in >> message;
    if(!in.commitTransaction()){
        qDebug() << "Error in datastream";
        return;
    }
    qDebug() << "message= "<< message;
    ui->lbl_Message->setText(message);
    qDebug() << "read   Message() end ...";
}

void Client::showError()
{
    qDebug() <<"showError() start ...";
    qDebug() <<"showError() end ...";
}
