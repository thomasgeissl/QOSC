#ifndef QOSCSENDER_H
#define QOSCSENDER_H

#include "osc/OscOutboundPacketStream.h"
#include "osc/OscTypes.h"
#include "ip/UdpSocket.h"
#include <QObject>
#include <QString>
#include "qoscmessage.h"
#include "qoscbundle.h"

class QOSCSender : public QObject
{
    Q_OBJECT
public:
    explicit QOSCSender(QString remoteHostS, unsigned int remotePortUI, QObject *parent = 0);
    void send(QOSCMessage *message);
    void send(QOSCBundle bundle);
protected:
private:
    UdpTransmitSocket *_socket;
    QString _remoteHostS;
    unsigned int _remotePortUI;
public slots:
    void setRemoteHost(QString remoteHostS);
    void setRemotePort(unsigned int remotePortUI);
    void setup();
};

#endif // QOSCSENDER_H
