#include "MainWindow.h"
#include "ui_MainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    /*
    普通ASCII文档标记：text/html;
    JPEG图片标记：image/jpeg;
    GIF图片标记：image/gif;
    js文档标记：application/javascript;
    xml文件标记：application/xml;
    */
    ui->comboBoxContentType->addItem("application/json;charset=UTF-8");
    ui->comboBoxContentType->addItem("text/html;charset=UTF-8");
    ui->comboBoxContentType->addItem("image/jpeg;charset=UTF-8");
    ui->comboBoxContentType->addItem("application/javascript;charset=UTF-8");
    ui->comboBoxContentType->addItem("application/xml;charset=UTF-8");

    p_HttpClient = new HQCCHttpClient();
}

CMainWindow::~CMainWindow(){
    if(p_HttpClient) p_HttpClient->deleteLater();
    delete ui;
}


void CMainWindow::on_btnGet_clicked(){
    QMap<QString,QString> tempParam;
    tempParam.insert(ui->lineEditParamKey->text(),ui->lineEditParamValue->text());
    auto tempResult = p_HttpClient->Get(ui->lineEditHostPort->text(),ui->lineEditPath->text(),tempParam,ui->textEditToken->toPlainText(),5);
    if(!tempResult.first){
        qDebug()<<"请求出错";
    }
    ui->textEditMsg->insertPlainText(tempResult.second);
}

void CMainWindow::on_btnDelete_clicked(){
    QMap<QString,QString> tempParam;
    tempParam.insert(ui->lineEditParamKey->text(),ui->lineEditParamValue->text());
    auto tempResult = p_HttpClient->Delete(ui->lineEditHostPort->text(),ui->lineEditPath->text(),tempParam,ui->textEditToken->toPlainText(),5);
    if(!tempResult.first){
        qDebug()<<"请求出错";
    }
    ui->textEditMsg->insertPlainText(tempResult.second);
}

void CMainWindow::on_btnHead_clicked(){
    QMap<QString,QString> tempParam;
    tempParam.insert(ui->lineEditParamKey->text(),ui->lineEditParamValue->text());
    auto tempResult = p_HttpClient->Head(ui->lineEditHostPort->text(),ui->lineEditPath->text(),tempParam,ui->textEditToken->toPlainText(),5);
    if(!tempResult.first){
        qDebug()<<"请求出错";
    }
    ui->textEditMsg->insertPlainText(tempResult.second);
}

void CMainWindow::on_btnPost_clicked(){
    QMap<QString,QString> tempParam;
    tempParam.insert(ui->lineEditParamKey->text(),ui->lineEditParamValue->text());
    auto tempResult = p_HttpClient->Post(ui->lineEditHostPort->text(),ui->lineEditPath->text(),tempParam,ui->textEditToken->toPlainText(),5
                                         ,ui->textEditData->toPlainText().toUtf8(),ui->comboBoxContentType->currentText());
    if(!tempResult.first){
        qDebug()<<"请求出错";
    }
    ui->textEditMsg->insertPlainText(tempResult.second);
}

void CMainWindow::on_btnPut_clicked(){
    QMap<QString,QString> tempParam;
    tempParam.insert(ui->lineEditParamKey->text(),ui->lineEditParamValue->text());
    auto tempResult = p_HttpClient->Put(ui->lineEditHostPort->text(),ui->lineEditPath->text(),tempParam,ui->textEditToken->toPlainText(),5
                                         ,ui->textEditData->toPlainText().toUtf8(),ui->comboBoxContentType->currentText());
    if(!tempResult.first){
        qDebug()<<"请求出错";
    }
    ui->textEditMsg->insertPlainText(tempResult.second);
}
