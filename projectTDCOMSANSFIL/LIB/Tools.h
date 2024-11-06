/*
*
* Copyright (c) 2009-2021 ODALID - https://odalid.com
*
*/

/** \file
* Outils
* \author Vincent T.
* \version 0.1
* \date 18 Novembre 2021
*
*/

#ifndef TOOLS_H
#define TOOLS_H

#include "TypeDefs.h"
#include "Hardware.h"
#include "Librairie.h"
#include <unistd.h>

#if defined (__cplusplus)
extern "C" {
#endif

#ifdef _WIN32
    #define DELAYS_MS(ms) Sleep ((ms))                              /**< Delais en milliseconde. */
    #define DELAYS_S(sec) Sleep ((sec) * 1000)                      /**< Delais en seconde. */
#else
    #define DELAYS_MS(ms) usleep ((ms) * 1000)                      /**< Delais en milliseconde. */
    #define DELAYS_S(sec) sleep ((sec))                             /**< Delais en seconde. */
#endif

#if defined (__cplusplus)
}
#endif

#endif /*TOOLS_H*/
