#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mYWindow; }
QT_END_NAMESPACE

class mYWindow : public QMainWindow
{
    Q_OBJECT

public:
    mYWindow(QWidget *parent = nullptr);
    ~mYWindow();

private slots:
    void on_Connect_clicked();

    void on_Disconnect_clicked();

    void on_Mise_a_jour_clicked();






private:
    Ui::mYWindow *ui;
};
#endif // MYWINDOW_H
