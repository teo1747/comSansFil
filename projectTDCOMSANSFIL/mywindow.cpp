#include "mywindow.h"
#include "ui_mywindow.h"
#include <QDebug>
#include "MfErrNo.h"
#include "Sw_Device.h"
#include "Sw_Mf_Classic.h"
#include "Tools.h"
#include "TypeDefs.h"
#include "Sw_ISO14443A-3.h"
#include <stdio.h>





mYWindow::mYWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mYWindow)
{
    ui->setupUi(this);
}

mYWindow::~mYWindow()
{
    delete ui;
}

ReaderName MonLecteur;

void  mYWindow::on_Connect_clicked(){

    int16_t status = MI_OK;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = OpenCOM(&MonLecteur);

    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(10);
    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON);
    qDebug() << "OpenCOM" << status;

    Version(&MonLecteur);
    ui->Affichage->setText(MonLecteur.version);
    ui->Affichage->update();
    LEDBuzzer(&MonLecteur, LED_RED_ON+LED_GREEN_OFF);
}

void mYWindow::on_Disconnect_clicked(){

    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(10);
    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON);
    CloseCOM(&MonLecteur);
    ui->Affichage->setText("Disconnected");
    ui->Affichage->update();




}

void mYWindow::on_Mise_a_jour_clicked(){

    uint16_t status = MI_OK;
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;

    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(1);
    LEDBuzzer(&MonLecteur, LED_GREEN_ON);

    ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    char DataIn1[16];
        strncpy(DataIn1, ui->Name->toPlainText().toUtf8().data(), 16);
    Mf_Classic_Write_Block(&MonLecteur, TRUE, 10, (uint8_t*)DataIn1, AuthKeyB, 2 );

    char DataIn[16];
        strncpy(DataIn, ui->Surname->toPlainText().toUtf8().data(), 16);
    Mf_Classic_Write_Block(&MonLecteur, TRUE, 9, (uint8_t*)DataIn, AuthKeyB, 2 );

}

