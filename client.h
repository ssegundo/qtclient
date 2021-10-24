#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

    void requestMessage();
    void showError();

private slots:
    void readMessage();

private:
    //Interfaz del GUI
    Ui::Client *ui;
    // variable socket cliente
    QTcpSocket *clientSocket = nullptr;
    // canal
    QDataStream in;

};
#endif // CLIENT_H
