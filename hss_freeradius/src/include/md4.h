/*
 * md4.h        Structures and prototypes for md4.
 *
 * Version:     $Id: md4.h,v 1.6 2003/09/02 21:17:26 cparker Exp $
 *
 */


#ifndef _LRAD_MD4_H
#define _LRAD_MD4_H

#ifndef _LRAD_PROTO_H
#define _LRAD_PROTO_H
#include "autoconf.h"

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

/* GLOBAL.H - RSAREF types and constants
 */

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
  The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */
#ifndef PROTOTYPES
#  if __STDC__
#    define PROTOTYPES 1
#  else
#    define PROTOTYPES 0
#  endif
#endif

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;
#define _POINTER_T

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
   If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
  returns an empty list.
 */
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif
#endif /* _LRAD_PROTO_H */

/*
 *  FreeRADIUS defines to ensure globally unique MD4 function names,
 *  so that we don't pick up other MD4 libraries.
 */
#define MD4_CTX		librad_MD4_CTX
#define MD4Init		librad_MD4Init
#define MD4Update	librad_MD4Update
#define MD4Final       	librad_MD4Final

/* MD4.H - header file for MD4C.C
 */

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
   rights reserved.

   License to copy and use this software is granted provided that it
   is identified as the "RSA Data Security, Inc. MD4 Message-Digest
   Algorithm" in all material mentioning or referencing this software
   or this function.

   License is also granted to make and use derivative works provided
   that such works are identified as "derived from the RSA Data
   Security, Inc. MD4 Message-Digest Algorithm" in all material
   mentioning or referencing the derived work.

   RSA Data Security, Inc. makes no representations concerning either
   the merchantability of this software or the suitability of this
   software for any particular purpose. It is provided "as is"
   without express or implied warranty of any kind.

   These notices must be retained in any copies of any part of this
   documentation and/or software.
 */

/* MD4 context. */
typedef struct {
  uint32_t state[4];                                   /* state (ABCD) */
  uint32_t count[2];        /* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];                         /* input buffer */
} MD4_CTX;

void md4_calc (unsigned char *, const unsigned char *, unsigned int);
void MD4Init PROTO_LIST ((MD4_CTX *));
void MD4Update PROTO_LIST
  ((MD4_CTX *, const unsigned char *, unsigned int));
void MD4Final PROTO_LIST ((unsigned char [16], MD4_CTX *));

#endif /* _LRAD_MD4_H */
