#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include"global.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }

    QString fileName="config.ini";
    QString app_path=QCoreApplication::applicationDirPath();
    //应用程序目录和配置文件名拼接，得到配置文件的完整路径
    QString config_path= QDir::toNativeSeparators(app_path + QDir::separator()+fileName);
    //创建一个 QSettings 对象，指定从配置文件路径 config_path 读取配置文件内容，并指定文件格式为 IniFormat（即 ini 格式）。
    QSettings settings(config_path ,QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://"+gate_host+":"+gate_port;
    MainWindow w;
    w.show();

    return a.exec();
}
