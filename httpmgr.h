#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include<QString>
#include<QUrl>
#include<QObject>T
#include<QNetworkAccessManager>
#include<QJsonObject>//发送的字节流，json
#include<QJsonDocument>
//CRTP技术，编译检测类，声明类，运行时候动态实例，可以先生成
class HttpMgr:public QObject,public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public://公有
    ~HttpMgr();
private:
    friend class Singleton<HttpMgr>;
    HttpMgr();//单例，构造函数不能公有
    QNetworkAccessManager _manager;
    void PostHttpReq(QUrl url,QJsonObject json,ReqId req_id,Modules mod);
signals:
    void sig_http_finish(ReqId id,QString res,ErrorCodes err,Modules mod);

};

#endif // HTTPMGR_H
