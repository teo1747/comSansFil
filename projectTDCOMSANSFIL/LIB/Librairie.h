/*
*
* Copyright (c) 2009-2021 ODALID - https://odalid.com
*
*/

/** \file
* Librairie
* \author Vincent T.
* \version 0.1
* \date 18 Novembre 2021
*
*/

#ifndef LIBRAIRIE_H
#define LIBRAIRIE_H

#include "TypeDefs.h"

/**
* \struct LIB_VERSION
* \brief Objet contenant les informations du Reader
*
*/

typedef struct
{
    uint8_t VMajor;                 /*!< Version Majeur de la librairie Common */
    uint8_t VMinor;                 /*!< Version Mineur de la librairie Common */
    uint8_t VPatch;                 /*!< Version du Patch de la librairie Common */

}
LIB_VERSION;

#ifdef ODALID_LIB_EXPORTS
    #ifdef _WIN32
        #define ODALID_LIB __declspec(dllexport)                /**< Parametre pour generer librairie Windows. */
        #define DllExport __declspec(dllexport)                 /**< Parametre pour generer librairie Windows. */
    #else
        #define ODALID_LIB                                      /**< ???. */
        #define DllExport                                       /**< ???. */
    #endif
#else
	#if (defined (__GNUC__))
        #define ODALID_LIB                                      /**< ???. */
	#else
        #define ODALID_LIB __declspec(dllimport)                /**< ???. */
	#endif
    #define DllExport                                           /**< ???. */
#endif

#endif /*LIBRAIRIE_H*/
