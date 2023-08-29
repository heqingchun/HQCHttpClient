#ifndef HQCCHTTPCLIENT_H
#define HQCCHTTPCLIENT_H

#include <QObject>
#include <QDebug>
#include <QElapsedTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include "httplib.h"

class HQCCHttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HQCCHttpClient(QObject *parent = nullptr);

signals:
public:
    QPair<bool,QByteArray> Get(const QString& hostPort,const QString& path,const QMap<QString,QString> param = QMap<QString,QString>()
                               ,const QString& token = QString(),const int& timeout = 5);

    QPair<bool,QByteArray> Delete(const QString& hostPort,const QString& path,const QMap<QString,QString> param = QMap<QString,QString>()
                                  ,const QString& token = QString(),const int& timeout = 5);

    QPair<bool,QByteArray> Head(const QString& hostPort,const QString& path,const QMap<QString,QString> param = QMap<QString,QString>()
                                ,const QString& token = QString(),const int& timeout = 5);

    QPair<bool,QByteArray> Post(const QString& hostPort,const QString& path,const QMap<QString,QString> param = QMap<QString,QString>()
                                ,const QString& token = QString(),const int& timeout = 5,const QByteArray& data = QByteArray()
                                 ,const QString& contentType = "application/json;charset=UTF-8");

    QPair<bool,QByteArray> Put(const QString& hostPort,const QString& path,const QMap<QString,QString> param = QMap<QString,QString>()
                               ,const QString& token = QString(),const int& timeout = 5,const QByteArray& data = QByteArray()
                                ,const QString& contentType = "application/json;charset=UTF-8");

private:
    QString StructUrl(const QString& path,const QMap<QString,QString> param);
};

#endif // HQCCHTTPCLIENT_H
