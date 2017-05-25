begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/ssl_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *  * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from  *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *  * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2007 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.  * ECC cipher suite support in OpenSSL originally developed by  * SUN MICROSYSTEMS, INC., and contributed to the OpenSSL project.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright 2005 Nokia. All rights reserved.  *  * The portions of the attached software ("Contribution") is developed by  * Nokia Corporation and is licensed pursuant to the OpenSSL open source  * license.  *  * The Contribution, originally written by Mika Kousa and Pasi Eronen of  * Nokia Corporation, consists of the "PSK" (Pre-Shared Key) ciphersuites  * support (see RFC 4279) to OpenSSL.  *  * No patent licenses or other rights except those expressly stated in  * the OpenSSL open source license shall be deemed granted or received  * expressly, by implication, estoppel, or otherwise.  *  * No assurances are provided by Nokia that the Contribution does not  * infringe the patent or other intellectual property rights of any third  * party or that the license provides you with all the necessary rights  * to make use of the Contribution.  *  * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. IN  * ADDITION TO THE DISCLAIMERS INCLUDED IN THE LICENSE, NOKIA  * SPECIFICALLY DISCLAIMS ANY LIABILITY FOR CLAIMS BROUGHT BY YOU OR ANY  * OTHER ENTITY BASED ON INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS OR  * OTHERWISE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_SSL_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_SSL_LOCL_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"e_os.h"
end_include

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_COMP
end_ifndef

begin_include
include|#
directive|include
file|<openssl/comp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/stack.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_RSA
end_ifndef

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DSA
end_ifndef

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_include
include|#
directive|include
file|<openssl/symhacks.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_BUILD_SHLIBSSL
end_ifdef

begin_undef
undef|#
directive|undef
name|OPENSSL_EXTERN
end_undef

begin_define
define|#
directive|define
name|OPENSSL_EXTERN
value|OPENSSL_EXPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|PKCS1_CHECK
end_undef

begin_define
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l = ((unsigned long)(*((c)++)))     , \                          l|=(((unsigned long)(*((c)++)))<< 8), \                          l|=(((unsigned long)(*((c)++)))<<16), \                          l|=(((unsigned long)(*((c)++)))<<24))
end_define

begin_comment
comment|/* NOTE - c is not incremented as per c2l */
end_comment

begin_define
define|#
directive|define
name|c2ln
parameter_list|(
name|c
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|n
parameter_list|)
value|{ \                         c+=n; \                         l1=l2=0; \                         switch (n) { \                         case 8: l2 =((unsigned long)(*(--(c))))<<24; \                         case 7: l2|=((unsigned long)(*(--(c))))<<16; \                         case 6: l2|=((unsigned long)(*(--(c))))<< 8; \                         case 5: l2|=((unsigned long)(*(--(c))));     \                         case 4: l1 =((unsigned long)(*(--(c))))<<24; \                         case 3: l1|=((unsigned long)(*(--(c))))<<16; \                         case 2: l1|=((unsigned long)(*(--(c))))<< 8; \                         case 1: l1|=((unsigned long)(*(--(c))));     \                                 } \                         }
end_define

begin_define
define|#
directive|define
name|l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)    )&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16)&0xff), \                          *((c)++)=(unsigned char)(((l)>>24)&0xff))
end_define

begin_define
define|#
directive|define
name|n2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((unsigned long)(*((c)++)))<<24, \                          l|=((unsigned long)(*((c)++)))<<16, \                          l|=((unsigned long)(*((c)++)))<< 8, \                          l|=((unsigned long)(*((c)++))))
end_define

begin_define
define|#
directive|define
name|l2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16)&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8)&0xff), \                          *((c)++)=(unsigned char)(((l)    )&0xff))
end_define

begin_define
define|#
directive|define
name|l2n6
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>40)&0xff), \                          *((c)++)=(unsigned char)(((l)>>32)&0xff), \                          *((c)++)=(unsigned char)(((l)>>24)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16)&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8)&0xff), \                          *((c)++)=(unsigned char)(((l)    )&0xff))
end_define

begin_define
define|#
directive|define
name|l2n8
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>56)&0xff), \                          *((c)++)=(unsigned char)(((l)>>48)&0xff), \                          *((c)++)=(unsigned char)(((l)>>40)&0xff), \                          *((c)++)=(unsigned char)(((l)>>32)&0xff), \                          *((c)++)=(unsigned char)(((l)>>24)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16)&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8)&0xff), \                          *((c)++)=(unsigned char)(((l)    )&0xff))
end_define

begin_define
define|#
directive|define
name|n2l6
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((BN_ULLONG)(*((c)++)))<<40, \                          l|=((BN_ULLONG)(*((c)++)))<<32, \                          l|=((BN_ULLONG)(*((c)++)))<<24, \                          l|=((BN_ULLONG)(*((c)++)))<<16, \                          l|=((BN_ULLONG)(*((c)++)))<< 8, \                          l|=((BN_ULLONG)(*((c)++))))
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2c */
end_comment

begin_define
define|#
directive|define
name|l2cn
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \                         c+=n; \                         switch (n) { \                         case 8: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \                         case 7: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \                         case 6: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \                         case 5: *(--(c))=(unsigned char)(((l2)    )&0xff); \                         case 4: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \                         case 3: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \                         case 2: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \                         case 1: *(--(c))=(unsigned char)(((l1)    )&0xff); \                                 } \                         }
end_define

begin_define
define|#
directive|define
name|n2s
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|((s=(((unsigned int)(c[0]))<< 8)| \                             (((unsigned int)(c[1]))    )),c+=2)
end_define

begin_define
define|#
directive|define
name|s2n
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|((c[0]=(unsigned char)(((s)>> 8)&0xff), \                           c[1]=(unsigned char)(((s)    )&0xff)),c+=2)
end_define

begin_define
define|#
directive|define
name|n2l3
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|((l =(((unsigned long)(c[0]))<<16)| \                              (((unsigned long)(c[1]))<< 8)| \                              (((unsigned long)(c[2]))    )),c+=3)
end_define

begin_define
define|#
directive|define
name|l2n3
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|((c[0]=(unsigned char)(((l)>>16)&0xff), \                           c[1]=(unsigned char)(((l)>> 8)&0xff), \                           c[2]=(unsigned char)(((l)    )&0xff)),c+=3)
end_define

begin_comment
comment|/* LOCAL STUFF */
end_comment

begin_define
define|#
directive|define
name|SSL_DECRYPT
value|0
end_define

begin_define
define|#
directive|define
name|SSL_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|TWO_BYTE_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SEC_ESC_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|TWO_BYTE_MASK
value|0x7fff
end_define

begin_define
define|#
directive|define
name|THREE_BYTE_MASK
value|0x3fff
end_define

begin_define
define|#
directive|define
name|INC32
parameter_list|(
name|a
parameter_list|)
value|((a)=((a)+1)&0xffffffffL)
end_define

begin_define
define|#
directive|define
name|DEC32
parameter_list|(
name|a
parameter_list|)
value|((a)=((a)-1)&0xffffffffL)
end_define

begin_define
define|#
directive|define
name|MAX_MAC_SIZE
value|20
end_define

begin_comment
comment|/* up from 16 for SSLv3 */
end_comment

begin_comment
comment|/*  * Define the Bitmasks for SSL_CIPHER.algorithms.  * This bits are used packed as dense as possible. If new methods/ciphers  * etc will be added, the bits a likely to change, so this information  * is for internal library use only, even though SSL_CIPHER.algorithms  * can be publicly accessed.  * Use the according functions for cipher management instead.  *  * The bit mask handling in the selection and sorting scheme in  * ssl_create_cipher_list() has only limited capabilities, reflecting  * that the different entities within are mutually exclusive:  * ONLY ONE BIT PER MASK CAN BE SET AT A TIME.  */
end_comment

begin_comment
comment|/* Bits for algorithm_mkey (key exchange algorithm) */
end_comment

begin_comment
comment|/* RSA key exchange */
end_comment

begin_define
define|#
directive|define
name|SSL_kRSA
value|0x00000001L
end_define

begin_comment
comment|/* DH cert, RSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kDHr
value|0x00000002L
end_define

begin_comment
comment|/* DH cert, DSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kDHd
value|0x00000004L
end_define

begin_comment
comment|/* tmp DH key no DH cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kEDH
value|0x00000008L
end_define

begin_comment
comment|/* forward-compatible synonym */
end_comment

begin_define
define|#
directive|define
name|SSL_kDHE
value|SSL_kEDH
end_define

begin_comment
comment|/* Kerberos5 key exchange */
end_comment

begin_define
define|#
directive|define
name|SSL_kKRB5
value|0x00000010L
end_define

begin_comment
comment|/* ECDH cert, RSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kECDHr
value|0x00000020L
end_define

begin_comment
comment|/* ECDH cert, ECDSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kECDHe
value|0x00000040L
end_define

begin_comment
comment|/* ephemeral ECDH */
end_comment

begin_define
define|#
directive|define
name|SSL_kEECDH
value|0x00000080L
end_define

begin_comment
comment|/* forward-compatible synonym */
end_comment

begin_define
define|#
directive|define
name|SSL_kECDHE
value|SSL_kEECDH
end_define

begin_comment
comment|/* PSK */
end_comment

begin_define
define|#
directive|define
name|SSL_kPSK
value|0x00000100L
end_define

begin_comment
comment|/* GOST key exchange */
end_comment

begin_define
define|#
directive|define
name|SSL_kGOST
value|0x00000200L
end_define

begin_comment
comment|/* SRP */
end_comment

begin_define
define|#
directive|define
name|SSL_kSRP
value|0x00000400L
end_define

begin_comment
comment|/* Bits for algorithm_auth (server authentication) */
end_comment

begin_comment
comment|/* RSA auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aRSA
value|0x00000001L
end_define

begin_comment
comment|/* DSS auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aDSS
value|0x00000002L
end_define

begin_comment
comment|/* no auth (i.e. use ADH or AECDH) */
end_comment

begin_define
define|#
directive|define
name|SSL_aNULL
value|0x00000004L
end_define

begin_comment
comment|/* Fixed DH auth (kDHd or kDHr) */
end_comment

begin_define
define|#
directive|define
name|SSL_aDH
value|0x00000008L
end_define

begin_comment
comment|/* Fixed ECDH auth (kECDHe or kECDHr) */
end_comment

begin_define
define|#
directive|define
name|SSL_aECDH
value|0x00000010L
end_define

begin_comment
comment|/* KRB5 auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aKRB5
value|0x00000020L
end_define

begin_comment
comment|/* ECDSA auth*/
end_comment

begin_define
define|#
directive|define
name|SSL_aECDSA
value|0x00000040L
end_define

begin_comment
comment|/* PSK auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aPSK
value|0x00000080L
end_define

begin_comment
comment|/* GOST R 34.10-94 signature auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aGOST94
value|0x00000100L
end_define

begin_comment
comment|/* GOST R 34.10-2001 signature auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aGOST01
value|0x00000200L
end_define

begin_comment
comment|/* SRP auth */
end_comment

begin_define
define|#
directive|define
name|SSL_aSRP
value|0x00000400L
end_define

begin_comment
comment|/* Bits for algorithm_enc (symmetric encryption) */
end_comment

begin_define
define|#
directive|define
name|SSL_DES
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SSL_3DES
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SSL_RC4
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SSL_RC2
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SSL_IDEA
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SSL_eNULL
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SSL_AES128
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|SSL_AES256
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|SSL_CAMELLIA128
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|SSL_CAMELLIA256
value|0x00000200L
end_define

begin_define
define|#
directive|define
name|SSL_eGOST2814789CNT
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|SSL_SEED
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|SSL_AES128GCM
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|SSL_AES256GCM
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|SSL_AES
value|(SSL_AES128|SSL_AES256|SSL_AES128GCM|SSL_AES256GCM)
end_define

begin_define
define|#
directive|define
name|SSL_CAMELLIA
value|(SSL_CAMELLIA128|SSL_CAMELLIA256)
end_define

begin_comment
comment|/* Bits for algorithm_mac (symmetric authentication) */
end_comment

begin_define
define|#
directive|define
name|SSL_MD5
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SSL_SHA1
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SSL_GOST94
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SSL_GOST89MAC
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SSL_SHA256
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SSL_SHA384
value|0x00000020L
end_define

begin_comment
comment|/* Not a real MAC, just an indication it is part of cipher */
end_comment

begin_define
define|#
directive|define
name|SSL_AEAD
value|0x00000040L
end_define

begin_comment
comment|/* Bits for algorithm_ssl (protocol version) */
end_comment

begin_define
define|#
directive|define
name|SSL_SSLV2
value|0x00000001UL
end_define

begin_define
define|#
directive|define
name|SSL_SSLV3
value|0x00000002UL
end_define

begin_define
define|#
directive|define
name|SSL_TLSV1
value|SSL_SSLV3
end_define

begin_comment
comment|/* for now */
end_comment

begin_define
define|#
directive|define
name|SSL_TLSV1_2
value|0x00000004UL
end_define

begin_comment
comment|/* Bits for algorithm2 (handshake digests and other extra flags) */
end_comment

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_MD5
value|0x10
end_define

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_SHA
value|0x20
end_define

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_GOST94
value|0x40
end_define

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_SHA256
value|0x80
end_define

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_SHA384
value|0x100
end_define

begin_define
define|#
directive|define
name|SSL_HANDSHAKE_MAC_DEFAULT
value|(SSL_HANDSHAKE_MAC_MD5 | SSL_HANDSHAKE_MAC_SHA)
end_define

begin_comment
comment|/*  * When adding new digest in the ssl_ciph.c and increment SSM_MD_NUM_IDX make  * sure to update this constant too  */
end_comment

begin_define
define|#
directive|define
name|SSL_MAX_DIGEST
value|6
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_DGST_MASK
value|(0xff<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_DGST_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_MD5
value|(SSL_HANDSHAKE_MAC_MD5<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_SHA1
value|(SSL_HANDSHAKE_MAC_SHA<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_SHA256
value|(SSL_HANDSHAKE_MAC_SHA256<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_SHA384
value|(SSL_HANDSHAKE_MAC_SHA384<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF_GOST94
value|(SSL_HANDSHAKE_MAC_GOST94<< TLS1_PRF_DGST_SHIFT)
end_define

begin_define
define|#
directive|define
name|TLS1_PRF
value|(TLS1_PRF_MD5 | TLS1_PRF_SHA1)
end_define

begin_comment
comment|/*  * Stream MAC for GOST ciphersuites from cryptopro draft (currently this also  * goes into algorithm2)  */
end_comment

begin_define
define|#
directive|define
name|TLS1_STREAM_MAC
value|0x04
end_define

begin_comment
comment|/*  * Export and cipher strength information. For each cipher we have to decide  * whether it is exportable or not. This information is likely to change  * over time, since the export control rules are no static technical issue.  *  * Independent of the export flag the cipher strength is sorted into classes.  * SSL_EXP40 was denoting the 40bit US export limit of past times, which now  * is at 56bit (SSL_EXP56). If the exportable cipher class is going to change  * again (eg. to 64bit) the use of "SSL_EXP*" becomes blurred even more,  * since SSL_EXP64 could be similar to SSL_LOW.  * For this reason SSL_MICRO and SSL_MINI macros are included to widen the  * namespace of SSL_LOW-SSL_HIGH to lower values. As development of speed  * and ciphers goes, another extension to SSL_SUPER and/or SSL_ULTRA would  * be possible.  */
end_comment

begin_define
define|#
directive|define
name|SSL_EXP_MASK
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|SSL_STRONG_MASK
value|0x000001fcL
end_define

begin_define
define|#
directive|define
name|SSL_NOT_EXP
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|SSL_EXPORT
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|SSL_STRONG_NONE
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|SSL_EXP40
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SSL_MICRO
value|(SSL_EXP40)
end_define

begin_define
define|#
directive|define
name|SSL_EXP56
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SSL_MINI
value|(SSL_EXP56)
end_define

begin_define
define|#
directive|define
name|SSL_LOW
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SSL_MEDIUM
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|SSL_HIGH
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|SSL_FIPS
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|SSL_NOT_DEFAULT
value|0x00000200L
end_define

begin_comment
comment|/* we have used 000003ff - 22 bits left to go */
end_comment

begin_comment
comment|/*-  * Macros to check the export status and cipher strength for export ciphers.  * Even though the macros for EXPORT and EXPORT40/56 have similar names,  * their meaning is different:  * *_EXPORT macros check the 'exportable' status.  * *_EXPORT40/56 macros are used to check whether a certain cipher strength  *          is given.  * Since the SSL_IS_EXPORT* and SSL_EXPORT* macros depend on the correct  * algorithm structure element to be passed (algorithms, algo_strength) and no  * typechecking can be done as they are all of type unsigned long, their  * direct usage is discouraged.  * Use the SSL_C_* macros instead.  */
end_comment

begin_define
define|#
directive|define
name|SSL_IS_EXPORT
parameter_list|(
name|a
parameter_list|)
value|((a)&SSL_EXPORT)
end_define

begin_define
define|#
directive|define
name|SSL_IS_EXPORT56
parameter_list|(
name|a
parameter_list|)
value|((a)&SSL_EXP56)
end_define

begin_define
define|#
directive|define
name|SSL_IS_EXPORT40
parameter_list|(
name|a
parameter_list|)
value|((a)&SSL_EXP40)
end_define

begin_define
define|#
directive|define
name|SSL_C_IS_EXPORT
parameter_list|(
name|c
parameter_list|)
value|SSL_IS_EXPORT((c)->algo_strength)
end_define

begin_define
define|#
directive|define
name|SSL_C_IS_EXPORT56
parameter_list|(
name|c
parameter_list|)
value|SSL_IS_EXPORT56((c)->algo_strength)
end_define

begin_define
define|#
directive|define
name|SSL_C_IS_EXPORT40
parameter_list|(
name|c
parameter_list|)
value|SSL_IS_EXPORT40((c)->algo_strength)
end_define

begin_define
define|#
directive|define
name|SSL_EXPORT_KEYLENGTH
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|(SSL_IS_EXPORT40(s) ? 5 : \                                  (a) == SSL_DES ? 8 : 7)
end_define

begin_define
define|#
directive|define
name|SSL_EXPORT_PKEYLENGTH
parameter_list|(
name|a
parameter_list|)
value|(SSL_IS_EXPORT40(a) ? 512 : 1024)
end_define

begin_define
define|#
directive|define
name|SSL_C_EXPORT_KEYLENGTH
parameter_list|(
name|c
parameter_list|)
value|SSL_EXPORT_KEYLENGTH((c)->algorithm_enc, \                                 (c)->algo_strength)
end_define

begin_define
define|#
directive|define
name|SSL_C_EXPORT_PKEYLENGTH
parameter_list|(
name|c
parameter_list|)
value|SSL_EXPORT_PKEYLENGTH((c)->algo_strength)
end_define

begin_comment
comment|/* Check if an SSL structure is using DTLS */
end_comment

begin_define
define|#
directive|define
name|SSL_IS_DTLS
parameter_list|(
name|s
parameter_list|)
value|(s->method->ssl3_enc->enc_flags& SSL_ENC_FLAG_DTLS)
end_define

begin_comment
comment|/* See if we need explicit IV */
end_comment

begin_define
define|#
directive|define
name|SSL_USE_EXPLICIT_IV
parameter_list|(
name|s
parameter_list|)
define|\
value|(s->method->ssl3_enc->enc_flags& SSL_ENC_FLAG_EXPLICIT_IV)
end_define

begin_comment
comment|/*  * See if we use signature algorithms extension and signature algorithm  * before signatures.  */
end_comment

begin_define
define|#
directive|define
name|SSL_USE_SIGALGS
parameter_list|(
name|s
parameter_list|)
define|\
value|(s->method->ssl3_enc->enc_flags& SSL_ENC_FLAG_SIGALGS)
end_define

begin_comment
comment|/*  * Allow TLS 1.2 ciphersuites: applies to DTLS 1.2 as well as TLS 1.2: may  * apply to others in future.  */
end_comment

begin_define
define|#
directive|define
name|SSL_USE_TLS1_2_CIPHERS
parameter_list|(
name|s
parameter_list|)
define|\
value|(s->method->ssl3_enc->enc_flags& SSL_ENC_FLAG_TLS1_2_CIPHERS)
end_define

begin_comment
comment|/*  * Determine if a client can use TLS 1.2 ciphersuites: can't rely on method  * flags because it may not be set to correct version yet.  */
end_comment

begin_define
define|#
directive|define
name|SSL_CLIENT_USE_TLS1_2_CIPHERS
parameter_list|(
name|s
parameter_list|)
define|\
value|((SSL_IS_DTLS(s)&& s->client_version<= DTLS1_2_VERSION) || \                 (!SSL_IS_DTLS(s)&& s->client_version>= TLS1_2_VERSION))
end_define

begin_comment
comment|/*  * Determine if a client should send signature algorithms extension:  * as with TLS1.2 cipher we can't rely on method flags.  */
end_comment

begin_define
define|#
directive|define
name|SSL_CLIENT_USE_SIGALGS
parameter_list|(
name|s
parameter_list|)
define|\
value|SSL_CLIENT_USE_TLS1_2_CIPHERS(s)
end_define

begin_comment
comment|/* Mostly for SSLv3 */
end_comment

begin_define
define|#
directive|define
name|SSL_PKEY_RSA_ENC
value|0
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_RSA_SIGN
value|1
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_DSA_SIGN
value|2
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_DH_RSA
value|3
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_DH_DSA
value|4
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_ECC
value|5
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_GOST94
value|6
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_GOST01
value|7
end_define

begin_define
define|#
directive|define
name|SSL_PKEY_NUM
value|8
end_define

begin_comment
comment|/*-  * SSL_kRSA<- RSA_ENC | (RSA_TMP& RSA_SIGN) |  *<- (EXPORT& (RSA_ENC | RSA_TMP)& RSA_SIGN)  * SSL_kDH<- DH_ENC& (RSA_ENC | RSA_SIGN | DSA_SIGN)  * SSL_kEDH<- RSA_ENC | RSA_SIGN | DSA_SIGN  * SSL_aRSA<- RSA_ENC | RSA_SIGN  * SSL_aDSS<- DSA_SIGN  */
end_comment

begin_comment
comment|/*- #define CERT_INVALID            0 #define CERT_PUBLIC_KEY         1 #define CERT_PRIVATE_KEY        2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_EC
end_ifndef

begin_comment
comment|/*  * From ECC-TLS draft, used in encoding the curve type in ECParameters  */
end_comment

begin_define
define|#
directive|define
name|EXPLICIT_PRIME_CURVE_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|EXPLICIT_CHAR2_CURVE_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|NAMED_CURVE_TYPE
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_NO_EC */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cert_pkey_st
block|{
name|X509
modifier|*
name|x509
decl_stmt|;
name|EVP_PKEY
modifier|*
name|privatekey
decl_stmt|;
comment|/* Digest to use when signing */
specifier|const
name|EVP_MD
modifier|*
name|digest
decl_stmt|;
comment|/* Chain for this certificate */
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|chain
expr_stmt|;
ifndef|#
directive|ifndef
name|OPENSSL_NO_TLSEXT
comment|/*-      * serverinfo data for this certificate.  The data is in TLS Extension      * wire format, specifically it's a series of records like:      *   uint16_t extension_type; // (RFC 5246, 7.4.1.4, Extension)      *   uint16_t length;      *   uint8_t data[length];      */
name|unsigned
name|char
modifier|*
name|serverinfo
decl_stmt|;
name|size_t
name|serverinfo_length
decl_stmt|;
endif|#
directive|endif
comment|/*      * Set if CERT_PKEY can be used with current SSL session: e.g.      * appropriate curve, signature algorithms etc. If zero it can't be used      * at all.      */
name|int
name|valid_flags
decl_stmt|;
block|}
name|CERT_PKEY
typedef|;
end_typedef

begin_comment
comment|/* Retrieve Suite B flags */
end_comment

begin_define
define|#
directive|define
name|tls1_suiteb
parameter_list|(
name|s
parameter_list|)
value|(s->cert->cert_flags& SSL_CERT_FLAG_SUITEB_128_LOS)
end_define

begin_comment
comment|/* Uses to check strict mode: suite B modes are always strict */
end_comment

begin_define
define|#
directive|define
name|SSL_CERT_FLAGS_CHECK_TLS_STRICT
define|\
value|(SSL_CERT_FLAG_SUITEB_128_LOS|SSL_CERT_FLAG_TLS_STRICT)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|ext_type
decl_stmt|;
comment|/*      * Per-connection flags relating to this extension type: not used if      * part of an SSL_CTX structure.      */
name|unsigned
name|short
name|ext_flags
decl_stmt|;
name|custom_ext_add_cb
name|add_cb
decl_stmt|;
name|custom_ext_free_cb
name|free_cb
decl_stmt|;
name|void
modifier|*
name|add_arg
decl_stmt|;
name|custom_ext_parse_cb
name|parse_cb
decl_stmt|;
name|void
modifier|*
name|parse_arg
decl_stmt|;
block|}
name|custom_ext_method
typedef|;
end_typedef

begin_comment
comment|/* ext_flags values */
end_comment

begin_comment
comment|/*  * Indicates an extension has been received. Used to check for unsolicited or  * duplicate extensions.  */
end_comment

begin_define
define|#
directive|define
name|SSL_EXT_FLAG_RECEIVED
value|0x1
end_define

begin_comment
comment|/*  * Indicates an extension has been sent: used to enable sending of  * corresponding ServerHello extension.  */
end_comment

begin_define
define|#
directive|define
name|SSL_EXT_FLAG_SENT
value|0x2
end_define

begin_define
define|#
directive|define
name|MAX_WARN_ALERT_COUNT
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|custom_ext_method
modifier|*
name|meths
decl_stmt|;
name|size_t
name|meths_count
decl_stmt|;
block|}
name|custom_ext_methods
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cert_st
block|{
comment|/* Current active set */
comment|/*      * ALWAYS points to an element of the pkeys array      * Probably it would make more sense to store      * an index, not a pointer.      */
name|CERT_PKEY
modifier|*
name|key
decl_stmt|;
comment|/*      * For servers the following masks are for the key and auth algorithms      * that are supported by the certs below. For clients they are masks of      * *disabled* algorithms based on the current session.      */
name|int
name|valid
decl_stmt|;
name|unsigned
name|long
name|mask_k
decl_stmt|;
name|unsigned
name|long
name|mask_a
decl_stmt|;
name|unsigned
name|long
name|export_mask_k
decl_stmt|;
name|unsigned
name|long
name|export_mask_a
decl_stmt|;
comment|/* Client only */
name|unsigned
name|long
name|mask_ssl
decl_stmt|;
ifndef|#
directive|ifndef
name|OPENSSL_NO_RSA
name|RSA
modifier|*
name|rsa_tmp
decl_stmt|;
name|RSA
modifier|*
function_decl|(
modifier|*
name|rsa_tmp_cb
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|int
name|is_export
parameter_list|,
name|int
name|keysize
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_DH
name|DH
modifier|*
name|dh_tmp
decl_stmt|;
name|DH
modifier|*
function_decl|(
modifier|*
name|dh_tmp_cb
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|int
name|is_export
parameter_list|,
name|int
name|keysize
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_ECDH
name|EC_KEY
modifier|*
name|ecdh_tmp
decl_stmt|;
comment|/* Callback for generating ephemeral ECDH keys */
name|EC_KEY
modifier|*
function_decl|(
modifier|*
name|ecdh_tmp_cb
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|int
name|is_export
parameter_list|,
name|int
name|keysize
parameter_list|)
function_decl|;
comment|/* Select ECDH parameters automatically */
name|int
name|ecdh_tmp_auto
decl_stmt|;
endif|#
directive|endif
comment|/* Flags related to certificates */
name|unsigned
name|int
name|cert_flags
decl_stmt|;
name|CERT_PKEY
name|pkeys
index|[
name|SSL_PKEY_NUM
index|]
decl_stmt|;
comment|/*      * Certificate types (received or sent) in certificate request message.      * On receive this is only set if number of certificate types exceeds      * SSL3_CT_NUMBER.      */
name|unsigned
name|char
modifier|*
name|ctypes
decl_stmt|;
name|size_t
name|ctype_num
decl_stmt|;
comment|/*      * signature algorithms peer reports: e.g. supported signature algorithms      * extension for server or as part of a certificate request for client.      */
name|unsigned
name|char
modifier|*
name|peer_sigalgs
decl_stmt|;
comment|/* Size of above array */
name|size_t
name|peer_sigalgslen
decl_stmt|;
comment|/*      * suppported signature algorithms. When set on a client this is sent in      * the client hello as the supported signature algorithms extension. For      * servers it represents the signature algorithms we are willing to use.      */
name|unsigned
name|char
modifier|*
name|conf_sigalgs
decl_stmt|;
comment|/* Size of above array */
name|size_t
name|conf_sigalgslen
decl_stmt|;
comment|/*      * Client authentication signature algorithms, if not set then uses      * conf_sigalgs. On servers these will be the signature algorithms sent      * to the client in a cerificate request for TLS 1.2. On a client this      * represents the signature algortithms we are willing to use for client      * authentication.      */
name|unsigned
name|char
modifier|*
name|client_sigalgs
decl_stmt|;
comment|/* Size of above array */
name|size_t
name|client_sigalgslen
decl_stmt|;
comment|/*      * Signature algorithms shared by client and server: cached because these      * are used most often.      */
name|TLS_SIGALGS
modifier|*
name|shared_sigalgs
decl_stmt|;
name|size_t
name|shared_sigalgslen
decl_stmt|;
comment|/*      * Certificate setup callback: if set is called whenever a certificate      * may be required (client or server). the callback can then examine any      * appropriate parameters and setup any certificates required. This      * allows advanced applications to select certificates on the fly: for      * example based on supported signature algorithms or curves.      */
name|int
function_decl|(
modifier|*
name|cert_cb
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|cert_cb_arg
decl_stmt|;
comment|/*      * Optional X509_STORE for chain building or certificate validation If      * NULL the parent SSL_CTX store is used instead.      */
name|X509_STORE
modifier|*
name|chain_store
decl_stmt|;
name|X509_STORE
modifier|*
name|verify_store
decl_stmt|;
comment|/* Raw values of the cipher list from a client */
name|unsigned
name|char
modifier|*
name|ciphers_raw
decl_stmt|;
name|size_t
name|ciphers_rawlen
decl_stmt|;
comment|/* Custom extension methods for server and client */
name|custom_ext_methods
name|cli_ext
decl_stmt|;
name|custom_ext_methods
name|srv_ext
decl_stmt|;
name|int
name|references
decl_stmt|;
comment|/*>1 only if SSL_copy_session_id is used */
comment|/* non-optimal, but here due to compatibility */
name|unsigned
name|char
modifier|*
name|alpn_proposed
decl_stmt|;
comment|/* server */
name|unsigned
name|int
name|alpn_proposed_len
decl_stmt|;
name|int
name|alpn_sent
decl_stmt|;
comment|/* client */
comment|/* Count of the number of consecutive warning alerts received */
name|unsigned
name|int
name|alert_count
decl_stmt|;
block|}
name|CERT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sess_cert_st
block|{
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|cert_chain
expr_stmt|;
comment|/* as received from peer (not for SSL2) */
comment|/* The 'peer_...' members are used only by clients. */
name|int
name|peer_cert_type
decl_stmt|;
name|CERT_PKEY
modifier|*
name|peer_key
decl_stmt|;
comment|/* points to an element of peer_pkeys (never                                  * NULL!) */
name|CERT_PKEY
name|peer_pkeys
index|[
name|SSL_PKEY_NUM
index|]
decl_stmt|;
comment|/*      * Obviously we don't have the private keys of these, so maybe we      * shouldn't even use the CERT_PKEY type here.      */
ifndef|#
directive|ifndef
name|OPENSSL_NO_RSA
name|RSA
modifier|*
name|peer_rsa_tmp
decl_stmt|;
comment|/* not used for SSL 2 */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_DH
name|DH
modifier|*
name|peer_dh_tmp
decl_stmt|;
comment|/* not used for SSL 2 */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_ECDH
name|EC_KEY
modifier|*
name|peer_ecdh_tmp
decl_stmt|;
endif|#
directive|endif
name|int
name|references
decl_stmt|;
comment|/* actually always 1 at the moment */
block|}
name|SESS_CERT
typedef|;
end_typedef

begin_comment
comment|/* Structure containing decoded values of signature algorithms extension */
end_comment

begin_struct
struct|struct
name|tls_sigalgs_st
block|{
comment|/* NID of hash algorithm */
name|int
name|hash_nid
decl_stmt|;
comment|/* NID of signature algorithm */
name|int
name|sign_nid
decl_stmt|;
comment|/* Combined hash and signature NID */
name|int
name|signandhash_nid
decl_stmt|;
comment|/* Raw values used in extension */
name|unsigned
name|char
name|rsign
decl_stmt|;
name|unsigned
name|char
name|rhash
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * #define MAC_DEBUG  */
end_comment

begin_comment
comment|/*  * #define ERR_DEBUG  */
end_comment

begin_comment
comment|/*  * #define ABORT_DEBUG  */
end_comment

begin_comment
comment|/*  * #define PKT_DEBUG 1  */
end_comment

begin_comment
comment|/*  * #define DES_DEBUG  */
end_comment

begin_comment
comment|/*  * #define DES_OFB_DEBUG  */
end_comment

begin_comment
comment|/*  * #define SSL_DEBUG  */
end_comment

begin_comment
comment|/*  * #define RSA_DEBUG  */
end_comment

begin_comment
comment|/*  * #define IDEA_DEBUG  */
end_comment

begin_define
define|#
directive|define
name|FP_ICC
value|(int (*)(const void *,const void *))
end_define

begin_define
define|#
directive|define
name|ssl_put_cipher_by_char
parameter_list|(
name|ssl
parameter_list|,
name|ciph
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((ssl)->method->put_cipher_by_char((ciph),(ptr)))
end_define

begin_comment
comment|/*  * This is for the SSLv3/TLSv1.0 differences in crypto/hash stuff It is a bit  * of a mess of functions, but hell, think of it as an opaque structure :-)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ssl3_enc_method
block|{
name|int
function_decl|(
modifier|*
name|enc
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mac
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|setup_key_block
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|generate_master_secret
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|change_cipher_state
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|final_finish_mac
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|finish_mac_length
decl_stmt|;
name|int
function_decl|(
modifier|*
name|cert_verify_mac
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|client_finished_label
decl_stmt|;
name|int
name|client_finished_label_len
decl_stmt|;
specifier|const
name|char
modifier|*
name|server_finished_label
decl_stmt|;
name|int
name|server_finished_label_len
decl_stmt|;
name|int
function_decl|(
modifier|*
name|alert_value
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|export_keying_material
function_decl|)
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
name|use_context
parameter_list|)
function_decl|;
comment|/* Various flags indicating protocol version requirements */
name|unsigned
name|int
name|enc_flags
decl_stmt|;
comment|/* Handshake header length */
name|unsigned
name|int
name|hhlen
decl_stmt|;
comment|/* Set the handshake header */
name|void
function_decl|(
modifier|*
name|set_handshake_header
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|long
name|len
parameter_list|)
function_decl|;
comment|/* Write out handshake message */
name|int
function_decl|(
modifier|*
name|do_write
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
block|}
name|SSL3_ENC_METHOD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSL_HM_HEADER_LENGTH
parameter_list|(
name|s
parameter_list|)
value|s->method->ssl3_enc->hhlen
end_define

begin_define
define|#
directive|define
name|ssl_handshake_start
parameter_list|(
name|s
parameter_list|)
define|\
value|(((unsigned char *)s->init_buf->data) + s->method->ssl3_enc->hhlen)
end_define

begin_define
define|#
directive|define
name|ssl_set_handshake_header
parameter_list|(
name|s
parameter_list|,
name|htype
parameter_list|,
name|len
parameter_list|)
define|\
value|s->method->ssl3_enc->set_handshake_header(s, htype, len)
end_define

begin_define
define|#
directive|define
name|ssl_do_write
parameter_list|(
name|s
parameter_list|)
value|s->method->ssl3_enc->do_write(s)
end_define

begin_comment
comment|/* Values for enc_flags */
end_comment

begin_comment
comment|/* Uses explicit IV for CBC mode */
end_comment

begin_define
define|#
directive|define
name|SSL_ENC_FLAG_EXPLICIT_IV
value|0x1
end_define

begin_comment
comment|/* Uses signature algorithms extension */
end_comment

begin_define
define|#
directive|define
name|SSL_ENC_FLAG_SIGALGS
value|0x2
end_define

begin_comment
comment|/* Uses SHA256 default PRF */
end_comment

begin_define
define|#
directive|define
name|SSL_ENC_FLAG_SHA256_PRF
value|0x4
end_define

begin_comment
comment|/* Is DTLS */
end_comment

begin_define
define|#
directive|define
name|SSL_ENC_FLAG_DTLS
value|0x8
end_define

begin_comment
comment|/*  * Allow TLS 1.2 ciphersuites: applies to DTLS 1.2 as well as TLS 1.2: may  * apply to others in future.  */
end_comment

begin_define
define|#
directive|define
name|SSL_ENC_FLAG_TLS1_2_CIPHERS
value|0x10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_COMP
end_ifndef

begin_comment
comment|/* Used for holding the relevant compression methods loaded into SSL_CTX */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ssl3_comp_st
block|{
name|int
name|comp_id
decl_stmt|;
comment|/* The identifier byte for this compression                                  * type */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Text name used for the compression type */
name|COMP_METHOD
modifier|*
name|method
decl_stmt|;
comment|/* The method :-) */
block|}
name|SSL3_COMP
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_BUF_FREELISTS
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|ssl3_buf_freelist_st
block|{
name|size_t
name|chunklen
decl_stmt|;
name|unsigned
name|int
name|len
decl_stmt|;
name|struct
name|ssl3_buf_freelist_entry_st
modifier|*
name|head
decl_stmt|;
block|}
name|SSL3_BUF_FREELIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ssl3_buf_freelist_entry_st
block|{
name|struct
name|ssl3_buf_freelist_entry_st
modifier|*
name|next
decl_stmt|;
block|}
name|SSL3_BUF_FREELIST_ENTRY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|ssl3_undef_enc_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|SSL_CIPHER
name|ssl2_ciphers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
name|SSL_CIPHER
name|ssl3_ciphers
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|SSL_METHOD
modifier|*
name|ssl_bad_method
parameter_list|(
name|int
name|ver
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|TLSv1_enc_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|TLSv1_1_enc_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|TLSv1_2_enc_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|SSLv3_enc_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|DTLSv1_enc_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SSL3_ENC_METHOD
name|DTLSv1_2_enc_data
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IMPLEMENT_tls_meth_func
parameter_list|(
name|version
parameter_list|,
name|func_name
parameter_list|,
name|s_accept
parameter_list|,
name|s_connect
parameter_list|, \
name|s_get_meth
parameter_list|,
name|enc_data
parameter_list|)
define|\
value|const SSL_METHOD *func_name(void)  \         { \         static const SSL_METHOD func_name##_data= { \                 version, \                 tls1_new, \                 tls1_clear, \                 tls1_free, \                 s_accept, \                 s_connect, \                 ssl3_read, \                 ssl3_peek, \                 ssl3_write, \                 ssl3_shutdown, \                 ssl3_renegotiate, \                 ssl3_renegotiate_check, \                 ssl3_get_message, \                 ssl3_read_bytes, \                 ssl3_write_bytes, \                 ssl3_dispatch_alert, \                 ssl3_ctrl, \                 ssl3_ctx_ctrl, \                 ssl3_get_cipher_by_char, \                 ssl3_put_cipher_by_char, \                 ssl3_pending, \                 ssl3_num_ciphers, \                 ssl3_get_cipher, \                 s_get_meth, \                 tls1_default_timeout, \&enc_data, \                 ssl_undefined_void_function, \                 ssl3_callback_ctrl, \                 ssl3_ctx_callback_ctrl, \         }; \         return&func_name##_data; \         }
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_ssl3_meth_func
parameter_list|(
name|func_name
parameter_list|,
name|s_accept
parameter_list|,
name|s_connect
parameter_list|,
name|s_get_meth
parameter_list|)
define|\
value|const SSL_METHOD *func_name(void)  \         { \         static const SSL_METHOD func_name##_data= { \                 SSL3_VERSION, \                 ssl3_new, \                 ssl3_clear, \                 ssl3_free, \                 s_accept, \                 s_connect, \                 ssl3_read, \                 ssl3_peek, \                 ssl3_write, \                 ssl3_shutdown, \                 ssl3_renegotiate, \                 ssl3_renegotiate_check, \                 ssl3_get_message, \                 ssl3_read_bytes, \                 ssl3_write_bytes, \                 ssl3_dispatch_alert, \                 ssl3_ctrl, \                 ssl3_ctx_ctrl, \                 ssl3_get_cipher_by_char, \                 ssl3_put_cipher_by_char, \                 ssl3_pending, \                 ssl3_num_ciphers, \                 ssl3_get_cipher, \                 s_get_meth, \                 ssl3_default_timeout, \&SSLv3_enc_data, \                 ssl_undefined_void_function, \                 ssl3_callback_ctrl, \                 ssl3_ctx_callback_ctrl, \         }; \         return&func_name##_data; \         }
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_ssl23_meth_func
parameter_list|(
name|func_name
parameter_list|,
name|s_accept
parameter_list|,
name|s_connect
parameter_list|,
name|s_get_meth
parameter_list|)
define|\
value|const SSL_METHOD *func_name(void)  \         { \         static const SSL_METHOD func_name##_data= { \         TLS1_2_VERSION, \         tls1_new, \         tls1_clear, \         tls1_free, \         s_accept, \         s_connect, \         ssl23_read, \         ssl23_peek, \         ssl23_write, \         ssl_undefined_function, \         ssl_undefined_function, \         ssl_ok, \         ssl3_get_message, \         ssl3_read_bytes, \         ssl3_write_bytes, \         ssl3_dispatch_alert, \         ssl3_ctrl, \         ssl3_ctx_ctrl, \         ssl23_get_cipher_by_char, \         ssl23_put_cipher_by_char, \         ssl_undefined_const_function, \         ssl23_num_ciphers, \         ssl23_get_cipher, \         s_get_meth, \         ssl23_default_timeout, \&TLSv1_2_enc_data, \         ssl_undefined_void_function, \         ssl3_callback_ctrl, \         ssl3_ctx_callback_ctrl, \         }; \         return&func_name##_data; \         }
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_ssl2_meth_func
parameter_list|(
name|func_name
parameter_list|,
name|s_accept
parameter_list|,
name|s_connect
parameter_list|,
name|s_get_meth
parameter_list|)
define|\
value|const SSL_METHOD *func_name(void)  \         { \         static const SSL_METHOD func_name##_data= { \                 SSL2_VERSION, \                 ssl2_new,
comment|/* local */
value|\                 ssl2_clear,
comment|/* local */
value|\                 ssl2_free,
comment|/* local */
value|\                 s_accept, \                 s_connect, \                 ssl2_read, \                 ssl2_peek, \                 ssl2_write, \                 ssl2_shutdown, \                 ssl_ok,
comment|/* NULL - renegotiate */
value|\                 ssl_ok,
comment|/* NULL - check renegotiate */
value|\                 NULL,
comment|/* NULL - ssl_get_message */
value|\                 NULL,
comment|/* NULL - ssl_get_record */
value|\                 NULL,
comment|/* NULL - ssl_write_bytes */
value|\                 NULL,
comment|/* NULL - dispatch_alert */
value|\                 ssl2_ctrl,
comment|/* local */
value|\                 ssl2_ctx_ctrl,
comment|/* local */
value|\                 ssl2_get_cipher_by_char, \                 ssl2_put_cipher_by_char, \                 ssl2_pending, \                 ssl2_num_ciphers, \                 ssl2_get_cipher, \                 s_get_meth, \                 ssl2_default_timeout, \&ssl3_undef_enc_method, \                 ssl_undefined_void_function, \                 ssl2_callback_ctrl,
comment|/* local */
value|\                 ssl2_ctx_callback_ctrl,
comment|/* local */
value|\         }; \         return&func_name##_data; \         }
end_define

begin_define
define|#
directive|define
name|IMPLEMENT_dtls1_meth_func
parameter_list|(
name|version
parameter_list|,
name|func_name
parameter_list|,
name|s_accept
parameter_list|,
name|s_connect
parameter_list|, \
name|s_get_meth
parameter_list|,
name|enc_data
parameter_list|)
define|\
value|const SSL_METHOD *func_name(void)  \         { \         static const SSL_METHOD func_name##_data= { \                 version, \                 dtls1_new, \                 dtls1_clear, \                 dtls1_free, \                 s_accept, \                 s_connect, \                 ssl3_read, \                 ssl3_peek, \                 ssl3_write, \                 dtls1_shutdown, \                 ssl3_renegotiate, \                 ssl3_renegotiate_check, \                 dtls1_get_message, \                 dtls1_read_bytes, \                 dtls1_write_app_data_bytes, \                 dtls1_dispatch_alert, \                 dtls1_ctrl, \                 ssl3_ctx_ctrl, \                 ssl3_get_cipher_by_char, \                 ssl3_put_cipher_by_char, \                 ssl3_pending, \                 ssl3_num_ciphers, \                 dtls1_get_cipher, \                 s_get_meth, \                 dtls1_default_timeout, \&enc_data, \                 ssl_undefined_void_function, \                 ssl3_callback_ctrl, \                 ssl3_ctx_callback_ctrl, \         }; \         return&func_name##_data; \         }
end_define

begin_struct
struct|struct
name|openssl_ssl_test_functions
block|{
name|int
function_decl|(
modifier|*
name|p_ssl_init_wbio_buffer
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|push
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|p_ssl3_setup_buffers
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|p_tls1_process_heartbeat
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|p_dtls1_process_heartbeat
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_UNIT_TEST
end_ifndef

begin_function_decl
name|void
name|ssl_clear_cipher_ctx
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_clear_bad_session
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CERT
modifier|*
name|ssl_cert_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CERT
modifier|*
name|ssl_cert_dup
parameter_list|(
name|CERT
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_cert_set_default_md
parameter_list|(
name|CERT
modifier|*
name|cert
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_inst
parameter_list|(
name|CERT
modifier|*
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_cert_clear_certs
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_cert_free
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SESS_CERT
modifier|*
name|ssl_sess_cert_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_sess_cert_free
parameter_list|(
name|SESS_CERT
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_set_peer_cert_type
parameter_list|(
name|SESS_CERT
modifier|*
name|c
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_get_new_session
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|session
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_get_prev_session
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|session
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SSL_SESSION
modifier|*
name|ssl_session_dup
parameter_list|(
name|SSL_SESSION
modifier|*
name|src
parameter_list|,
name|int
name|ticket
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cipher_id_cmp
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
name|a
parameter_list|,
specifier|const
name|SSL_CIPHER
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DECLARE_OBJ_BSEARCH_GLOBAL_CMP_FN
argument_list|(
name|SSL_CIPHER
argument_list|,
name|SSL_CIPHER
argument_list|,
name|ssl_cipher_id
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ssl_cipher_ptr_id_cmp
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
specifier|const
modifier|*
name|ap
parameter_list|,
specifier|const
name|SSL_CIPHER
modifier|*
specifier|const
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|ssl_bytes_to_cipher_list
argument_list|(
argument|SSL *s
argument_list|,
argument|unsigned char *p
argument_list|,
argument|int num
argument_list|,
argument|STACK_OF(SSL_CIPHER) **skp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|ssl_cipher_list_to_bytes
argument_list|(
name|SSL
operator|*
name|s
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|sk
argument_list|,
name|unsigned
name|char
operator|*
name|p
argument_list|,
name|int
argument_list|(
argument|*put_cb
argument_list|)
operator|(
specifier|const
name|SSL_CIPHER
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|ssl_create_cipher_list
argument_list|(
specifier|const
name|SSL_METHOD
operator|*
name|meth
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
operator|*
name|pref
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
operator|*
name|sorted
argument_list|,
specifier|const
name|char
operator|*
name|rule_str
argument_list|,
name|CERT
operator|*
name|c
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|ssl_update_cache
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cipher_get_evp
parameter_list|(
specifier|const
name|SSL_SESSION
modifier|*
name|s
parameter_list|,
specifier|const
name|EVP_CIPHER
modifier|*
modifier|*
name|enc
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
modifier|*
name|md
parameter_list|,
name|int
modifier|*
name|mac_pkey_type
parameter_list|,
name|int
modifier|*
name|mac_secret_size
parameter_list|,
name|SSL_COMP
modifier|*
modifier|*
name|comp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_get_handshake_digest
parameter_list|(
name|int
name|i
parameter_list|,
name|long
modifier|*
name|mask
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cipher_get_cert_index
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl_get_cipher_by_char
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ssl_cert_set0_chain
argument_list|(
name|CERT
operator|*
name|c
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|chain
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ssl_cert_set1_chain
argument_list|(
name|CERT
operator|*
name|c
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|chain
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ssl_cert_add0_chain_cert
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_add1_chain_cert
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_select_current
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|X509
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_set_current
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|long
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509
modifier|*
name|ssl_cert_get0_next_certificate
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_cert_set_cert_cb
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|ssl_verify_cert_chain
argument_list|(
name|SSL
operator|*
name|s
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|sk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ssl_add_cert_chain
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|CERT_PKEY
modifier|*
name|cpk
parameter_list|,
name|unsigned
name|long
modifier|*
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_build_cert_chain
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|X509_STORE
modifier|*
name|chain_store
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_set_cert_store
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
name|X509_STORE
modifier|*
name|store
parameter_list|,
name|int
name|chain
parameter_list|,
name|int
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_undefined_function
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_undefined_void_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_undefined_const_function
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CERT_PKEY
modifier|*
name|ssl_get_server_send_pkey
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_TLSEXT
end_ifndef

begin_function_decl
name|int
name|ssl_get_server_cert_serverinfo
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
name|serverinfo
parameter_list|,
name|size_t
modifier|*
name|serverinfo_length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EVP_PKEY
modifier|*
name|ssl_get_sign_pkey
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|SSL_CIPHER
modifier|*
name|c
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
modifier|*
name|pmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_cert_type
parameter_list|(
name|X509
modifier|*
name|x
parameter_list|,
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_set_cert_masks
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
specifier|const
name|SSL_CIPHER
modifier|*
name|cipher
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|ssl_get_ciphers_by_id
argument_list|(
name|SSL
operator|*
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ssl_verify_alarm_type
parameter_list|(
name|long
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_load_ciphers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_fill_hello_random
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|server
parameter_list|,
name|unsigned
name|char
modifier|*
name|field
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_enc_init
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_generate_key_material
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_enc
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|send_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl2_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|mac
parameter_list|,
name|int
name|send_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl2_get_cipher_by_char
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_put_cipher_by_char
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_part_read
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|long
name|f
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_do_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_set_certificate
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl2_return_error
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl2_write_error
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_num_ciphers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl2_get_cipher
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_new
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl2_free
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_accept
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_connect
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_read
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_peek
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_shutdown
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl2_clear
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl2_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl2_ctx_ctrl
parameter_list|(
name|SSL_CTX
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl2_callback_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl2_ctx_callback_ctrl
parameter_list|(
name|SSL_CTX
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_pending
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl2_default_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl3_get_cipher_by_char
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_put_cipher_by_char
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_init_finished_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_server_certificate
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_newsession_ticket
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_cert_status
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_finished
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|state_a
parameter_list|,
name|int
name|state_b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_setup_key_block
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_change_cipher_spec
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|state_a
parameter_list|,
name|int
name|state_b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_change_cipher_state
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_cleanup_key_block
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_do_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_alert
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_generate_master_secret
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_req_cert_type
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_get_message
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|st1
parameter_list|,
name|int
name|stn
parameter_list|,
name|int
name|mt
parameter_list|,
name|long
name|max
parameter_list|,
name|int
modifier|*
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_finished
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
specifier|const
name|char
modifier|*
name|sender
parameter_list|,
name|int
name|slen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_num_ciphers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl3_get_cipher
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_renegotiate
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_renegotiate_check
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_dispatch_alert
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_read_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|peek
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_write_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_final_finish_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|sender
parameter_list|,
name|int
name|slen
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_cert_verify_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|md_nid
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_finish_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_enc
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|send_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|n_ssl3_mac
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|unsigned
name|char
modifier|*
name|md
parameter_list|,
name|int
name|send_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_free_digest_list
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|ssl3_output_cert_chain
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|CERT_PKEY
modifier|*
name|cpk
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|SSL_CIPHER
modifier|*
name|ssl3_choose_cipher
argument_list|(
name|SSL
operator|*
name|ssl
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|clnt
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|srvr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ssl3_setup_buffers
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_setup_read_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_setup_write_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_release_read_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_release_write_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_digest_cached_records
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_new
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_free
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_accept
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_connect
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_read
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_peek
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_shutdown
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_clear
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_ctx_ctrl
parameter_list|(
name|SSL_CTX
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_callback_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_ctx_callback_ctrl
parameter_list|(
name|SSL_CTX
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_pending
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_record_sequence_update
parameter_list|(
name|unsigned
name|char
modifier|*
name|seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_do_change_cipher_spec
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl3_default_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl3_set_handshake_header
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|htype
parameter_list|,
name|unsigned
name|long
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_handshake_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_num_ciphers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl23_get_cipher
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_read
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_peek
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_put_cipher_by_char
parameter_list|(
specifier|const
name|SSL_CIPHER
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|ssl23_get_cipher_by_char
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl23_default_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|tls1_default_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_do_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_read_n
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|max
parameter_list|,
name|int
name|extend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_read_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|peek
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_do_compress
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_do_uncompress
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_write_pending
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|dtls1_set_message_header
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|unsigned
name|char
name|mt
parameter_list|,
name|unsigned
name|long
name|len
parameter_list|,
name|unsigned
name|long
name|frag_off
parameter_list|,
name|unsigned
name|long
name|frag_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_write_app_data_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_write_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_send_change_cipher_spec
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_read_failed
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_buffer_message
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|ccs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_retransmit_message
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|short
name|seq
parameter_list|,
name|unsigned
name|long
name|frag_off
parameter_list|,
name|int
modifier|*
name|found
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_get_queue_priority
parameter_list|(
name|unsigned
name|short
name|seq
parameter_list|,
name|int
name|is_ccs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_retransmit_buffered_messages
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_clear_received_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_clear_sent_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_get_message_header
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|struct
name|hm_header_st
modifier|*
name|msg_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_get_ccs_header
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|struct
name|ccs_header_st
modifier|*
name|ccs_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_reset_seq_numbers
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|rw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|dtls1_default_timeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|timeval
modifier|*
name|dtls1_get_timeout
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|struct
name|timeval
modifier|*
name|timeleft
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_check_timeout_num
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_handle_timeout
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|SSL_CIPHER
modifier|*
name|dtls1_get_cipher
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_start_timer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_stop_timer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_is_timer_expired
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_double_timeout
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_send_newsession_ticket
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dtls1_min_mtu
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dtls1_link_min_mtu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_hm_fragment_free
parameter_list|(
name|hm_fragment
modifier|*
name|frag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* some client-only functions */
end_comment

begin_function_decl
name|int
name|ssl3_client_hello
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_server_hello
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_certificate_request
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_new_session_ticket
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_cert_status
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_server_done
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_client_verify
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_client_certificate
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_do_client_cert_cb
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|X509
modifier|*
modifier|*
name|px509
parameter_list|,
name|EVP_PKEY
modifier|*
modifier|*
name|ppkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_client_key_exchange
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_key_exchange
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_server_certificate
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_check_cert_and_algorithm
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_TLSEXT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_NEXTPROTONEG
end_ifndef

begin_function_decl
name|int
name|ssl3_send_next_proto
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|dtls1_client_hello
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* some server-only functions */
end_comment

begin_function_decl
name|int
name|ssl3_get_client_hello
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_server_hello
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_hello_request
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_server_key_exchange
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_certificate_request
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_send_server_done
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_client_certificate
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_client_key_exchange
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_get_cert_verify
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_NEXTPROTONEG
end_ifndef

begin_function_decl
name|int
name|ssl3_get_next_proto
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ssl23_accept
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_connect
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_read_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl23_write_bytes
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_new
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls1_free
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls1_clear
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|tls1_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|tls1_callback_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_new
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_accept
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_connect
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_free
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dtls1_clear
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|dtls1_ctrl
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|cmd
parameter_list|,
name|long
name|larg
parameter_list|,
name|void
modifier|*
name|parg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_shutdown
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|dtls1_get_message
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|st1
parameter_list|,
name|int
name|stn
parameter_list|,
name|int
name|mt
parameter_list|,
name|long
name|max
parameter_list|,
name|int
modifier|*
name|ok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_get_record
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_dtls1_write
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|int
name|create_empty_fragement
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_dispatch_alert
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_init_wbio_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|push
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_free_wbio_buffer
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_change_cipher_state
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_setup_key_block
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_enc
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|snd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_final_finish_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|slen
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_cert_verify_mac
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|md_nid
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_mac
parameter_list|(
name|SSL
modifier|*
name|ssl
parameter_list|,
name|unsigned
name|char
modifier|*
name|md
parameter_list|,
name|int
name|snd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_generate_master_secret
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_export_keying_material
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
name|size_t
name|olen
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|,
name|size_t
name|llen
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|size_t
name|plen
parameter_list|,
name|int
name|use_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_alert_code
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_alert_code
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_ok
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ECDH
end_ifndef

begin_function_decl
name|int
name|ssl_check_srvr_ecc_cert_and_alg
parameter_list|(
name|X509
modifier|*
name|x
parameter_list|,
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|SSL_COMP
modifier|*
name|ssl3_comp_find
argument_list|(
name|STACK_OF
argument_list|(
name|SSL_COMP
argument_list|)
operator|*
name|sk
argument_list|,
name|int
name|n
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_EC
end_ifndef

begin_function_decl
name|int
name|tls1_ec_curve_id2nid
parameter_list|(
name|int
name|curve_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_ec_nid2curve_id
parameter_list|(
name|int
name|nid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_check_curve
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_shared_curve
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|nmatch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_set_curves
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|pext
parameter_list|,
name|size_t
modifier|*
name|pextlen
parameter_list|,
name|int
modifier|*
name|curves
parameter_list|,
name|size_t
name|ncurves
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_set_curves_list
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
name|pext
parameter_list|,
name|size_t
modifier|*
name|pextlen
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ECDH
end_ifndef

begin_function_decl
name|int
name|tls1_check_ec_tmp_key
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|long
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_NO_ECDH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_NO_EC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_TLSEXT
end_ifndef

begin_function_decl
name|int
name|tls1_shared_list
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|l1
parameter_list|,
name|size_t
name|l1len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|l2
parameter_list|,
name|size_t
name|l2len
parameter_list|,
name|int
name|nmatch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|ssl_add_clienthello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|limit
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|ssl_add_serverhello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|char
modifier|*
name|limit
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_clienthello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|data
parameter_list|,
name|unsigned
name|char
modifier|*
name|limit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_set_server_sigalgs
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_check_clienthello_tlsext_late
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_serverhello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|data
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_prepare_clienthello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_prepare_serverhello_tlsext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_HEARTBEATS
end_ifndef

begin_function_decl
name|int
name|tls1_heartbeat
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_heartbeat
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_process_heartbeat
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dtls1_process_heartbeat
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_SHA256
end_ifdef

begin_define
define|#
directive|define
name|tlsext_tick_md
value|EVP_sha1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tlsext_tick_md
value|EVP_sha256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|tls1_process_ticket
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|session_id
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|limit
parameter_list|,
name|SSL_SESSION
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls12_get_sigandhash
parameter_list|(
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
specifier|const
name|EVP_PKEY
modifier|*
name|pk
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls12_get_sigid
parameter_list|(
specifier|const
name|EVP_PKEY
modifier|*
name|pk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|tls12_get_hash
parameter_list|(
name|unsigned
name|char
name|hash_alg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_set_sigalgs_list
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_set_sigalgs
parameter_list|(
name|CERT
modifier|*
name|c
parameter_list|,
specifier|const
name|int
modifier|*
name|salg
parameter_list|,
name|size_t
name|salglen
parameter_list|,
name|int
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|tls1_check_chain
argument_list|(
name|SSL
operator|*
name|s
argument_list|,
name|X509
operator|*
name|x
argument_list|,
name|EVP_PKEY
operator|*
name|pk
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|chain
argument_list|,
name|int
name|idx
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tls1_set_cert_validity
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EVP_MD_CTX
modifier|*
name|ssl_replace_hash
parameter_list|(
name|EVP_MD_CTX
modifier|*
modifier|*
name|hash
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_clear_hash_ctx
parameter_list|(
name|EVP_MD_CTX
modifier|*
modifier|*
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_add_serverhello_renegotiate_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_serverhello_renegotiate_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_add_clienthello_renegotiate_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_clienthello_renegotiate_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ssl_get_algorithm2
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_save_sigalgs
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|dsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_process_sigalgs
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|tls12_get_psigalgs
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|sent
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
name|psigs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls12_check_peer_sigalg
parameter_list|(
specifier|const
name|EVP_MD
modifier|*
modifier|*
name|pmd
parameter_list|,
name|SSL
modifier|*
name|s
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|sig
parameter_list|,
name|EVP_PKEY
modifier|*
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssl_set_client_disabled
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_add_clienthello_use_srtp_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_clienthello_use_srtp_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_add_serverhello_use_srtp_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl_parse_serverhello_use_srtp_ext
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* s3_cbc.c */
end_comment

begin_function_decl
name|void
name|ssl3_cbc_copy_mac
parameter_list|(
name|unsigned
name|char
modifier|*
name|out
parameter_list|,
specifier|const
name|SSL3_RECORD
modifier|*
name|rec
parameter_list|,
name|unsigned
name|md_size
parameter_list|,
name|unsigned
name|orig_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_cbc_remove_padding
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|,
name|SSL3_RECORD
modifier|*
name|rec
parameter_list|,
name|unsigned
name|block_size
parameter_list|,
name|unsigned
name|mac_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tls1_cbc_remove_padding
parameter_list|(
specifier|const
name|SSL
modifier|*
name|s
parameter_list|,
name|SSL3_RECORD
modifier|*
name|rec
parameter_list|,
name|unsigned
name|block_size
parameter_list|,
name|unsigned
name|mac_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|ssl3_cbc_record_digest_supported
parameter_list|(
specifier|const
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_cbc_digest_record
parameter_list|(
specifier|const
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|md_out
parameter_list|,
name|size_t
modifier|*
name|md_out_size
parameter_list|,
specifier|const
name|unsigned
name|char
name|header
index|[
literal|13
index|]
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|data_plus_mac_size
parameter_list|,
name|size_t
name|data_plus_mac_plus_padding_size
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|mac_secret
parameter_list|,
name|unsigned
name|mac_secret_length
parameter_list|,
name|char
name|is_sslv3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tls_fips_digest_extra
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
name|cipher_ctx
parameter_list|,
name|EVP_MD_CTX
modifier|*
name|mac_ctx
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|size_t
name|orig_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|srp_verify_server_param
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* t1_ext.c */
end_comment

begin_function_decl
name|void
name|custom_ext_init
parameter_list|(
name|custom_ext_methods
modifier|*
name|meths
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|custom_ext_parse
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|server
parameter_list|,
name|unsigned
name|int
name|ext_type
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|ext_data
parameter_list|,
name|size_t
name|ext_size
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|custom_ext_add
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|int
name|server
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
name|pret
parameter_list|,
name|unsigned
name|char
modifier|*
name|limit
parameter_list|,
name|int
modifier|*
name|al
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|custom_exts_copy
parameter_list|(
name|custom_ext_methods
modifier|*
name|dst
parameter_list|,
specifier|const
name|custom_ext_methods
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|custom_exts_copy_flags
parameter_list|(
name|custom_ext_methods
modifier|*
name|dst
parameter_list|,
specifier|const
name|custom_ext_methods
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|custom_exts_free
parameter_list|(
name|custom_ext_methods
modifier|*
name|exts
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ssl_init_wbio_buffer
value|SSL_test_functions()->p_ssl_init_wbio_buffer
end_define

begin_define
define|#
directive|define
name|ssl3_setup_buffers
value|SSL_test_functions()->p_ssl3_setup_buffers
end_define

begin_define
define|#
directive|define
name|tls1_process_heartbeat
value|SSL_test_functions()->p_tls1_process_heartbeat
end_define

begin_define
define|#
directive|define
name|dtls1_process_heartbeat
value|SSL_test_functions()->p_dtls1_process_heartbeat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

