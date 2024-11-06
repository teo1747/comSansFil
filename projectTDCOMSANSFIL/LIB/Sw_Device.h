/*
*
* Copyright (c) 2009-2021 ODALID - https://odalid.com
*
*/

/** \file
* Fonction ODALID
* \author Vincent T.
* \version 0.1
* \date 18 Novembre 2021
*
*/

#ifndef SW_DEVICE_H
#define SW_DEVICE_H

#include "TypeDefs.h"
#include "Hardware.h"
#include "Librairie.h"

#if defined (__cplusplus)
extern "C" {
#endif

/**
* \brief foncion pour obtenir la version de LibraryExtension
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t GetLibraryExtension(
                                        LIB_VERSION *Version 		/**< [Out] Version LibraryExtension. */
                                        );

/**
* \brief foncion pour Ouvrir la communication avec le lecteur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t OpenCOM(
                            ReaderName *pName 		 		/**< [In] Information sur le lecteur . */
							);

/**
* \brief foncion pour fermer la communication avec le lecteur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t CloseCOM(
                                ReaderName *pName       /**< [In] Information sur le lecteur . */
								);

/**
* \brief foncion pour fermer la communication avec le lecteur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t GestionDeconnection(
										ReaderName *pName, 
										int16_t statusconnection, 
										uint8_t nbreconnection
										);

#define LED_ON              0x17                            /**< ???. */
#define LED_OFF             0x00                            /**< ???. */
#define LED_GREEN_OFF       0x00                            /**< ???. */
#define LED_GREEN_ON        LED1_ON                         /**< ???. */
#define LED_YELLOW_OFF      0x00                            /**< ???. */
#define LED_YELLOW_ON       LED2_ON                         /**< ???. */
#define LED_RED_OFF         0x00                            /**< ???. */
#define LED_RED_ON          LED3_ON                         /**< ???. */
#define BUZZER_OFF          0x00                            /**< ???. */
#define BUZZER_ON           0x08                            /**< ???. */
#define GACHE1_OFF          0x00                            /**< ???. */
#define GACHE1_ON           LED1_ON                         /**< ???. */
#define GACHE2_OFF          0x00                            /**< ???. */
#define GACHE2_ON           LED2_ON                         /**< ???. */
#define GACHE3_OFF          0x00                            /**< ???. */
#define GACHE3_ON           LED3_ON                         /**< ???. */
#define GACHE4_OFF          0x00                            /**< ???. */
#define GACHE4_ON           LED4_ON                         /**< ???. */
#define LED1_ON             0x01                            /**< ???. */
#define LED2_ON             0x02                            /**< ???. */
#define LED3_ON             0x04                            /**< ???. */
#define LED4_ON             0x10                            /**< ???. */



/**
* \brief fonction permettant de visualiser les erreurs
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB char* GetErrorMessage(
									int16_t status
									);

/**
* \brief Fonction permettant d obtenir la version du firmware du lecteur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t Version(
                            ReaderName *pName       /**< [In] Information sur le lecteur . */
							);

/**
* \brief fonction permettant de recuperer les parametrse de configuration du composant RF
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t Get_Property(
                                    ReaderName *pName,      /**< [In] Information sur le lecteur . */
                                    uint8_t AddReg,         /**< [In] Adresse . */
                                    uint8_t *Reg            /**< [Out] Registre . */
									);

/**
* \brief fonction permettant d'envoyer les parametres de configuration du composant RF
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t Set_Property(
                                    ReaderName *pName,                  /**< [In] Information sur le lecteur . */
                                    uint8_t AddReg,                     /**< [In] Adresse . */
                                    uint8_t Reg                         /**< [In] Registre . */
									);
									
/**
* \brief fonction permettant d activer ou de desactiver le champ radio du lecteur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t RF_Power_Control(
                                        ReaderName *pName,              /**< [In] Information sur le lecteur . */
                                        BOOL RFOnOff,                   /**< [In] Activation ou desactivation . */
                                        uint8_t Delay                   /**< [In] Delay de desactivation . */
										);
										
/**
* \brief fonction permettant de selectionner le type de modulation en fonction du type de cart
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t RF_Config_Card_Mode(
                                        ReaderName *pName,              /**< [In] Information sur le lecteur . */
                                        uint8_t Type                    /**< [In] Type de carte / modulation . */
                                        );

/**
* \brief fonction permettant de passer le lecteur en mode bootloader
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t Boot(
                            ReaderName *pName                           /**< [In] Information sur le lecteur . */
                            );

/**
* \brief fonction permettant de pioter les LEDs / Buzze
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t LEDBuzzer(
                                ReaderName *pName,              /**< [In] Information sur le lecteur . */
                                uint8_t LEDBuzzer               /**< [In] Numeros LED / buzzer . */
                                );

/**
* \brief fonction permettant de piloter l'afficheur
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t LCD(
                        ReaderName *pName,                      /**< [In] Information sur le lecteur . */
                        uint8_t line,                           /**< [In] Numero de la ligne . */
                        char *Send                              /**< [In] Information a afficher . */
                        );



#if defined (__cplusplus)
}
#endif

#endif /*SW_DEVICE_H*/
