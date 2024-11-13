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


void mYWindow::on_Select_clicked(){

    uint16_t status = MI_OK;
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;
    uint32_t pvalue = 0;

    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    if(status == MI_OK){
        LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
        DELAYS_MS(10);
        LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON);

        uint8_t data[16];
        status = Mf_Classic_Read_Block(&MonLecteur, true, 9, data, true, 2 );
        if(status == MI_OK){
            QString prenom;
            for(int i=0 ; i<16 ; i++){

                if(data[i] == 0){
                    break;
                }
                prenom.append(QChar(data[i]));
            }
            ui->Surname->setText(prenom);
        }else{
            qDebug() << "error: Could not read your surname";
        }

        status = Mf_Classic_Read_Block(&MonLecteur, true, 10, data, true, 2 );
        if(status == MI_OK){
            QString nom;
            for(int i=0 ; i<16 ; i++){

                if(data[i] == 0){
                    break;
                }
                nom.append(QChar(data[i]));
            }
            ui->Name->setText(nom);
        }else{
            qDebug() << "error: Could not read your name";
        }

        status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &pvalue, AuthKeyA, 3);
        ui->Nombre_Unite->setText(QString::number(pvalue));

    }

}

void mYWindow::on_Payer_clicked(){

    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;
    uint32_t pvalue = 0;

    uint32_t Valeur_Decrementer = 0;
    Valeur_Decrementer = ui->Decrementer_Unite->value();
    ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    Mf_Classic_Decrement_Value(&MonLecteur, TRUE, 14, Valeur_Decrementer, 13, AuthKeyA, 3);
    Mf_Classic_Restore_Value(&MonLecteur, TRUE, 13, 14, AuthKeyA, 3);
    Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &pvalue, AuthKeyA, 3);
    ui->Nombre_Unite->setText(QString::number(pvalue));



    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(500);
    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON);


}

void mYWindow::on_Charger_clicked(){

    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;
    uint32_t pvalue = 0;

    uint32_t Valeur_Increment = 0;
    Valeur_Increment = ui->Decrementer_Unite->value();
    ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    Mf_Classic_Increment_Value(&MonLecteur, TRUE, 14, Valeur_Increment, 13, AuthKeyB, 3);
    Mf_Classic_Restore_Value(&MonLecteur, TRUE, 13, 14, AuthKeyB, 3);
    Mf_Classic_Read_Value(&MonLecteur, TRUE, 14, &pvalue, AuthKeyA, 3);
    ui->Nombre_Unite->setText(QString::number(pvalue));



    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(500);
    LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON);



}






