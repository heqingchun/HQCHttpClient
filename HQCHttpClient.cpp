#include "HQCHttpClient.h"

HQCCHttpClient::HQCCHttpClient(QObject *parent) : QObject(parent){

}
QString HQCCHttpClient::StructUrl(const QString& path,const QMap<QString,QString> param){
    if(param.isEmpty()) return path;
    QString tempUrl = path + '?';
    for(int i = 0;i < param.size();++i){
        tempUrl += param.keys().at(i);
        tempUrl += '=';
        tempUrl += param.value(param.keys().at(i));
        tempUrl += '&';
    }
    tempUrl.chop(1);
    return tempUrl;
}
QPair<bool,QByteArray> HQCCHttpClient::Get(const QString& hostPort,const QString& path,const QMap<QString,QString> param,const QString& token
                                           ,const int& timeout){
    QElapsedTimer tempElapsedTimer;
    QJsonObject tempReturnObj;
    QJsonDocument tempReturnDoc;
    httplib::Client tempHttpClient(hostPort.toStdString());
    tempHttpClient.set_connection_timeout(0,300000); // 300 milliseconds
    tempHttpClient.set_read_timeout(timeout,0);
    tempHttpClient.set_write_timeout(timeout,0);
    tempHttpClient.set_default_headers({
      { "Accept-Encoding", "gzip, deflate" },
      { "Authorization",QString("Bearer " + token).toStdString() }
    });
    tempElapsedTimer.start();
    auto tempResult = tempHttpClient.Get(StructUrl(path,param).toStdString());
    if(tempElapsedTimer.elapsed() >= timeout * 1000){
        tempReturnObj.insert("timeout",true);
        tempReturnObj.insert("body","");
        tempReturnObj.insert("reason","");
        tempReturnObj.insert("status",-1);
        tempReturnObj.insert("version","");
        tempReturnObj.insert("location","");
        tempReturnObj.insert("content_length_",0);
        tempReturnObj.insert("content_provider_success_",false);
        tempReturnObj.insert("is_chunked_content_provider_",false);
        tempReturnDoc.setObject(tempReturnObj);
        return QPair<bool,QByteArray>(false,tempReturnDoc.toJson());
    }
    // successed
    tempReturnObj.insert("timeout",false);
    tempReturnObj.insert("body",QString::fromStdString(tempResult->body));
    tempReturnObj.insert("reason",QString::fromStdString(tempResult->reason));
    tempReturnObj.insert("status",tempResult->status);
    //res->headers;
    tempReturnObj.insert("version",QString::fromStdString(tempResult->version));
    tempReturnObj.insert("location",QString::fromStdString(tempResult->location));
    tempReturnObj.insert("content_length_",static_cast<int>(tempResult->content_length_));
    //res->content_provider_
    tempReturnObj.insert("content_provider_success_",tempResult->content_provider_success_);
    tempReturnObj.insert("is_chunked_content_provider_",tempResult->is_chunked_content_provider_);
    tempReturnDoc.setObject(tempReturnObj);
    return QPair<bool,QByteArray>(true,tempReturnDoc.toJson());
}
QPair<bool,QByteArray> HQCCHttpClient::Delete(const QString& hostPort,const QString& path,const QMap<QString,QString> param,const QString& token
                                              ,const int& timeout){
    QElapsedTimer tempElapsedTimer;
    QJsonObject tempReturnObj;
    QJsonDocument tempReturnDoc;
    httplib::Client tempHttpClient(hostPort.toStdString());
    tempHttpClient.set_connection_timeout(0,300000); // 300 milliseconds
    tempHttpClient.set_read_timeout(timeout,0);
    tempHttpClient.set_write_timeout(timeout,0);
    tempHttpClient.set_default_headers({
      { "Accept-Encoding", "gzip, deflate" },
      { "Authorization",QString("Bearer " + token).toStdString() }
    });
    tempElapsedTimer.start();
    auto tempResult = tempHttpClient.Delete(StructUrl(path,param).toStdString());
    if(tempElapsedTimer.elapsed() >= timeout * 1000){
        tempReturnObj.insert("timeout",true);
        tempReturnObj.insert("body","");
        tempReturnObj.insert("reason","");
        tempReturnObj.insert("status",-1);
        tempReturnObj.insert("version","");
        tempReturnObj.insert("location","");
        tempReturnObj.insert("content_length_",0);
        tempReturnObj.insert("content_provider_success_",false);
        tempReturnObj.insert("is_chunked_content_provider_",false);
        tempReturnDoc.setObject(tempReturnObj);
        return QPair<bool,QByteArray>(false,tempReturnDoc.toJson());
    }
    // successed
    tempReturnObj.insert("timeout",false);
    tempReturnObj.insert("body",QString::fromStdString(tempResult->body));
    tempReturnObj.insert("reason",QString::fromStdString(tempResult->reason));
    tempReturnObj.insert("status",tempResult->status);
    //res->headers;
    tempReturnObj.insert("version",QString::fromStdString(tempResult->version));
    tempReturnObj.insert("location",QString::fromStdString(tempResult->location));
    tempReturnObj.insert("content_length_",static_cast<int>(tempResult->content_length_));
    //res->content_provider_
    tempReturnObj.insert("content_provider_success_",tempResult->content_provider_success_);
    tempReturnObj.insert("is_chunked_content_provider_",tempResult->is_chunked_content_provider_);
    tempReturnDoc.setObject(tempReturnObj);
    return QPair<bool,QByteArray>(true,tempReturnDoc.toJson());
}
QPair<bool,QByteArray> HQCCHttpClient::Head(const QString& hostPort,const QString& path,const QMap<QString,QString> param,const QString& token
                                            ,const int& timeout){
    QElapsedTimer tempElapsedTimer;
    QJsonObject tempReturnObj;
    QJsonDocument tempReturnDoc;
    httplib::Client tempHttpClient(hostPort.toStdString());
    tempHttpClient.set_connection_timeout(0,300000); // 300 milliseconds
    tempHttpClient.set_read_timeout(timeout,0);
    tempHttpClient.set_write_timeout(timeout,0);
    tempHttpClient.set_default_headers({
      { "Accept-Encoding", "gzip, deflate" },
      { "Authorization",QString("Bearer " + token).toStdString() }
    });
    tempElapsedTimer.start();
    auto tempResult = tempHttpClient.Head(StructUrl(path,param).toStdString());
    if(tempElapsedTimer.elapsed() >= timeout * 1000){
        tempReturnObj.insert("timeout",true);
        tempReturnObj.insert("body","");
        tempReturnObj.insert("reason","");
        tempReturnObj.insert("status",-1);
        tempReturnObj.insert("version","");
        tempReturnObj.insert("location","");
        tempReturnObj.insert("content_length_",0);
        tempReturnObj.insert("content_provider_success_",false);
        tempReturnObj.insert("is_chunked_content_provider_",false);
        tempReturnDoc.setObject(tempReturnObj);
        return QPair<bool,QByteArray>(false,tempReturnDoc.toJson());
    }
    // successed
    tempReturnObj.insert("timeout",false);
    tempReturnObj.insert("body",QString::fromStdString(tempResult->body));
    tempReturnObj.insert("reason",QString::fromStdString(tempResult->reason));
    tempReturnObj.insert("status",tempResult->status);
    //res->headers;
    tempReturnObj.insert("version",QString::fromStdString(tempResult->version));
    tempReturnObj.insert("location",QString::fromStdString(tempResult->location));
    tempReturnObj.insert("content_length_",static_cast<int>(tempResult->content_length_));
    //res->content_provider_
    tempReturnObj.insert("content_provider_success_",tempResult->content_provider_success_);
    tempReturnObj.insert("is_chunked_content_provider_",tempResult->is_chunked_content_provider_);
    tempReturnDoc.setObject(tempReturnObj);
    return QPair<bool,QByteArray>(true,tempReturnDoc.toJson());
}
QPair<bool,QByteArray> HQCCHttpClient::Post(const QString& hostPort,const QString& path,const QMap<QString,QString> param,const QString& token
                                            ,const int& timeout,const QByteArray& data,const QString& contentType){
    QElapsedTimer tempElapsedTimer;
    QJsonObject tempReturnObj;
    QJsonDocument tempReturnDoc;
    httplib::Client tempHttpClient(hostPort.toStdString());
    tempHttpClient.set_connection_timeout(0,300000); // 300 milliseconds
    tempHttpClient.set_read_timeout(timeout,0);
    tempHttpClient.set_write_timeout(timeout,0);
    tempHttpClient.set_default_headers({
      { "Accept-Encoding", "gzip, deflate" },
      { "Authorization",QString("Bearer " + token).toStdString() }
    });
    tempElapsedTimer.start();
    auto tempResult = tempHttpClient.Post(StructUrl(path,param).toStdString(),data.toStdString(),contentType.toStdString());
    if(tempElapsedTimer.elapsed() >= timeout * 1000){
        tempReturnObj.insert("timeout",true);
        tempReturnObj.insert("body","");
        tempReturnObj.insert("reason","");
        tempReturnObj.insert("status",-1);
        tempReturnObj.insert("version","");
        tempReturnObj.insert("location","");
        tempReturnObj.insert("content_length_",0);
        tempReturnObj.insert("content_provider_success_",false);
        tempReturnObj.insert("is_chunked_content_provider_",false);
        tempReturnDoc.setObject(tempReturnObj);
        return QPair<bool,QByteArray>(false,tempReturnDoc.toJson());
    }
    // successed
    tempReturnObj.insert("timeout",false);
    tempReturnObj.insert("body",QString::fromStdString(tempResult->body));
    tempReturnObj.insert("reason",QString::fromStdString(tempResult->reason));
    tempReturnObj.insert("status",tempResult->status);
    //res->headers;
    tempReturnObj.insert("version",QString::fromStdString(tempResult->version));
    tempReturnObj.insert("location",QString::fromStdString(tempResult->location));
    tempReturnObj.insert("content_length_",static_cast<int>(tempResult->content_length_));
    //res->content_provider_
    tempReturnObj.insert("content_provider_success_",tempResult->content_provider_success_);
    tempReturnObj.insert("is_chunked_content_provider_",tempResult->is_chunked_content_provider_);
    tempReturnDoc.setObject(tempReturnObj);
    return QPair<bool,QByteArray>(true,tempReturnDoc.toJson());
}
QPair<bool,QByteArray> HQCCHttpClient::Put(const QString& hostPort,const QString& path,const QMap<QString,QString> param,const QString& token
                                           ,const int& timeout,const QByteArray& data,const QString& contentType){
    QElapsedTimer tempElapsedTimer;
    QJsonObject tempReturnObj;
    QJsonDocument tempReturnDoc;
    httplib::Client tempHttpClient(hostPort.toStdString());
    tempHttpClient.set_connection_timeout(0,300000); // 300 milliseconds
    tempHttpClient.set_read_timeout(timeout,0);
    tempHttpClient.set_write_timeout(timeout,0);
    tempHttpClient.set_default_headers({
      { "Accept-Encoding", "gzip, deflate" },
      { "Authorization",QString("Bearer " + token).toStdString() }
    });
    tempElapsedTimer.start();
    auto tempResult = tempHttpClient.Put(StructUrl(path,param).toStdString(),data.toStdString(),contentType.toStdString());
    if(tempElapsedTimer.elapsed() >= timeout * 1000){
        tempReturnObj.insert("timeout",true);
        tempReturnObj.insert("body","");
        tempReturnObj.insert("reason","");
        tempReturnObj.insert("status",-1);
        tempReturnObj.insert("version","");
        tempReturnObj.insert("location","");
        tempReturnObj.insert("content_length_",0);
        tempReturnObj.insert("content_provider_success_",false);
        tempReturnObj.insert("is_chunked_content_provider_",false);
        tempReturnDoc.setObject(tempReturnObj);
        return QPair<bool,QByteArray>(false,tempReturnDoc.toJson());
    }
    // successed
    tempReturnObj.insert("timeout",false);
    tempReturnObj.insert("body",QString::fromStdString(tempResult->body));
    tempReturnObj.insert("reason",QString::fromStdString(tempResult->reason));
    tempReturnObj.insert("status",tempResult->status);
    //res->headers;
    tempReturnObj.insert("version",QString::fromStdString(tempResult->version));
    tempReturnObj.insert("location",QString::fromStdString(tempResult->location));
    tempReturnObj.insert("content_length_",static_cast<int>(tempResult->content_length_));
    //res->content_provider_
    tempReturnObj.insert("content_provider_success_",tempResult->content_provider_success_);
    tempReturnObj.insert("is_chunked_content_provider_",tempResult->is_chunked_content_provider_);
    tempReturnDoc.setObject(tempReturnObj);
    return QPair<bool,QByteArray>(true,tempReturnDoc.toJson());
}
