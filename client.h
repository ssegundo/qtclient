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
    void readMessage();
    void showError();

private:
    Ui::Client *ui;
    QTcpSocket *clientSocket = nullptr;
    //QDebug *q=nullptr;
};
#endif // CLIENT_H
