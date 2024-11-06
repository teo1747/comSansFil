/*
*
* Copyright (c) 2009-2021 ODALID - https://odalid.com
*
*/

/** \file
* Fonction ISO14443A-3
* \author Vincent T.
* \version 0.1
* \date 18 Novembre 2021
*
*/

#ifndef SW_ISO14443A_3_H
#define SW_ISO14443A_3_H

#include "Librairie.h"
#include "TypeDefs.h"
#include "Hardware.h"

#if defined (__cplusplus)
extern "C" {
#endif

/**
* \brief fonction de prise de contact ISO14443-3A
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t ISO14443_3_A_PollCard(
                                            ReaderName *pName, 		/**< [In] Information sur le lecteur. */
                                            uint8_t *atq,           /**< [Out] atq[2]. */
                                            uint8_t *sak,           /**< [Out] saq[1]. */
                                            uint8_t *uid,           /**< [Out] uid[10]. */
                                            uint16_t *uid_len       /**< [Out] Longueur de l'uid. */
                                            );

/**
* \brief fonction de prise de contact ISO14443-3A pour reveiller la carte
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t ISO14443_3_A_PollCardWU(
                                            ReaderName *pName, 		/**< [In] Information sur le lecteur. */
                                            uint8_t *atq,           /**< [Out] atq[2]. */
                                            uint8_t *sak,           /**< [Out] saq[1]. */
                                            uint8_t *uid,           /**< [Out] uid[10]. */
                                            uint16_t *uid_len       /**< [Out] Longueur de l'uid. */
                                            );

/**
* \brief fonction de prise de mise en sommeil de la carte
* \return Status code
* \retval #MI_OK Operation successful ou erreur
*/
ODALID_LIB int16_t ISO14443_3_A_Halt(
                                        ReaderName *pName          /**< [In] Information sur le lecteur. */
                                        );

#if defined (__cplusplus)
}
#endif

#endif /*SW_ISO14443A_3_H*/
