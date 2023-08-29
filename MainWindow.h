#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "HQCHttpClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private slots:
    void on_btnGet_clicked();

    void on_btnDelete_clicked();

    void on_btnHead_clicked();

    void on_btnPost_clicked();

    void on_btnPut_clicked();

private:
    Ui::CMainWindow *ui;
private:
    HQCCHttpClient *p_HttpClient = nullptr;
};
#endif // CMAINWINDOW_H
