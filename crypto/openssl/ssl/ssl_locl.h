begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/ssl_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2000 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
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
file|"openssl/e_os.h"
end_include

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_include
include|#
directive|include
file|<openssl/comp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bio.h>
end_include

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/stack.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

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

begin_define
define|#
directive|define
name|PKCS1_CHECK
end_define

begin_define
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l = ((unsigned long)(*((c)++)))     , \ 			 l|=(((unsigned long)(*((c)++)))<< 8), \ 			 l|=(((unsigned long)(*((c)++)))<<16), \ 			 l|=(((unsigned long)(*((c)++)))<<24))
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
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((unsigned long)(*(--(c))))<<24; \ 			case 7: l2|=((unsigned long)(*(--(c))))<<16; \ 			case 6: l2|=((unsigned long)(*(--(c))))<< 8; \ 			case 5: l2|=((unsigned long)(*(--(c))));     \ 			case 4: l1 =((unsigned long)(*(--(c))))<<24; \ 			case 3: l1|=((unsigned long)(*(--(c))))<<16; \ 			case 2: l1|=((unsigned long)(*(--(c))))<< 8; \ 			case 1: l1|=((unsigned long)(*(--(c))));     \ 				} \ 			}
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
value|(*((c)++)=(unsigned char)(((l)    )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24)&0xff))
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
value|(l =((unsigned long)(*((c)++)))<<24, \ 			 l|=((unsigned long)(*((c)++)))<<16, \ 			 l|=((unsigned long)(*((c)++)))<< 8, \ 			 l|=((unsigned long)(*((c)++))))
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
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \ 			 *((c)++)=(unsigned char)(((l)    )&0xff))
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
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)    )&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)    )&0xff); \ 				} \ 			}
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
value|((s=(((unsigned int)(c[0]))<< 8)| \ 			    (((unsigned int)(c[1]))    )),c+=2)
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
value|((c[0]=(unsigned char)(((s)>> 8)&0xff), \ 			  c[1]=(unsigned char)(((s)    )&0xff)),c+=2)
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
value|((l =(((unsigned long)(c[0]))<<16)| \ 			     (((unsigned long)(c[1]))<< 8)| \ 			     (((unsigned long)(c[2]))    )),c+=3)
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
value|((c[0]=(unsigned char)(((l)>>16)&0xff), \ 			  c[1]=(unsigned char)(((l)>> 8)&0xff), \ 			  c[2]=(unsigned char)(((l)    )&0xff)),c+=3)
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

begin_define
define|#
directive|define
name|SSL_MKEY_MASK
value|0x0000001FL
end_define

begin_define
define|#
directive|define
name|SSL_kRSA
value|0x00000001L
end_define

begin_comment
comment|/* RSA key exchange */
end_comment

begin_define
define|#
directive|define
name|SSL_kDHr
value|0x00000002L
end_define

begin_comment
comment|/* DH cert RSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kDHd
value|0x00000004L
end_define

begin_comment
comment|/* DH cert DSA CA cert */
end_comment

begin_define
define|#
directive|define
name|SSL_kFZA
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|SSL_kEDH
value|0x00000010L
end_define

begin_comment
comment|/* tmp DH key no DH cert */
end_comment

begin_define
define|#
directive|define
name|SSL_EDH
value|(SSL_kEDH|(SSL_AUTH_MASK^SSL_aNULL))
end_define

begin_define
define|#
directive|define
name|SSL_AUTH_MASK
value|0x000003e0L
end_define

begin_define
define|#
directive|define
name|SSL_aRSA
value|0x00000020L
end_define

begin_comment
comment|/* Authenticate with RSA */
end_comment

begin_define
define|#
directive|define
name|SSL_aDSS
value|0x00000040L
end_define

begin_comment
comment|/* Authenticate with DSS */
end_comment

begin_define
define|#
directive|define
name|SSL_DSS
value|SSL_aDSS
end_define

begin_define
define|#
directive|define
name|SSL_aFZA
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|SSL_aNULL
value|0x00000100L
end_define

begin_comment
comment|/* no Authenticate, ADH */
end_comment

begin_define
define|#
directive|define
name|SSL_aDH
value|0x00000200L
end_define

begin_comment
comment|/* no Authenticate, ADH */
end_comment

begin_define
define|#
directive|define
name|SSL_NULL
value|(SSL_eNULL)
end_define

begin_define
define|#
directive|define
name|SSL_ADH
value|(SSL_kEDH|SSL_aNULL)
end_define

begin_define
define|#
directive|define
name|SSL_RSA
value|(SSL_kRSA|SSL_aRSA)
end_define

begin_define
define|#
directive|define
name|SSL_DH
value|(SSL_kDHr|SSL_kDHd|SSL_kEDH)
end_define

begin_define
define|#
directive|define
name|SSL_FZA
value|(SSL_aFZA|SSL_kFZA|SSL_eFZA)
end_define

begin_define
define|#
directive|define
name|SSL_ENC_MASK
value|0x0001Fc00L
end_define

begin_define
define|#
directive|define
name|SSL_DES
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|SSL_3DES
value|0x00000800L
end_define

begin_define
define|#
directive|define
name|SSL_RC4
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|SSL_RC2
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|SSL_IDEA
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|SSL_eFZA
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|SSL_eNULL
value|0x00010000L
end_define

begin_define
define|#
directive|define
name|SSL_MAC_MASK
value|0x00060000L
end_define

begin_define
define|#
directive|define
name|SSL_MD5
value|0x00020000L
end_define

begin_define
define|#
directive|define
name|SSL_SHA1
value|0x00040000L
end_define

begin_define
define|#
directive|define
name|SSL_SHA
value|(SSL_SHA1)
end_define

begin_define
define|#
directive|define
name|SSL_SSL_MASK
value|0x00180000L
end_define

begin_define
define|#
directive|define
name|SSL_SSLV2
value|0x00080000L
end_define

begin_define
define|#
directive|define
name|SSL_SSLV3
value|0x00100000L
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

begin_comment
comment|/* we have used 001fffff - 11 bits left to go */
end_comment

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
name|SSL_STRONG_MASK
value|0x0000007cL
end_define

begin_define
define|#
directive|define
name|SSL_EXP40
value|0x00000004L
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
value|0x00000008L
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
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|SSL_MEDIUM
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|SSL_HIGH
value|0x00000040L
end_define

begin_comment
comment|/* we have used 0000007f - 25 bits left to go */
end_comment

begin_comment
comment|/*  * Macros to check the export status and cipher strength for export ciphers.  * Even though the macros for EXPORT and EXPORT40/56 have similar names,  * their meaning is different:  * *_EXPORT macros check the 'exportable' status.  * *_EXPORT40/56 macros are used to check whether a certain cipher strength  *          is given.  * Since the SSL_IS_EXPORT* and SSL_EXPORT* macros depend on the correct  * algorithm structure element to be passed (algorithms, algo_strength) and no  * typechecking can be done as they are all of type unsigned long, their  * direct usage is discouraged.  * Use the SSL_C_* macros instead.  */
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
value|(SSL_IS_EXPORT40(s) ? 5 : \ 				 ((a)&SSL_ENC_MASK) == SSL_DES ? 8 : 7)
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
value|SSL_EXPORT_KEYLENGTH((c)->algorithms, \ 				(c)->algo_strength)
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

begin_define
define|#
directive|define
name|SSL_ALL
value|0xffffffffL
end_define

begin_define
define|#
directive|define
name|SSL_ALL_CIPHERS
value|(SSL_MKEY_MASK|SSL_AUTH_MASK|SSL_ENC_MASK|\ 				SSL_MAC_MASK)
end_define

begin_define
define|#
directive|define
name|SSL_ALL_STRENGTHS
value|(SSL_EXP_MASK|SSL_STRONG_MASK)
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
name|SSL_PKEY_NUM
value|5
end_define

begin_comment
comment|/* SSL_kRSA<- RSA_ENC | (RSA_TMP& RSA_SIGN) |  *<- (EXPORT& (RSA_ENC | RSA_TMP)& RSA_SIGN)  * SSL_kDH<- DH_ENC& (RSA_ENC | RSA_SIGN | DSA_SIGN)  * SSL_kEDH<- RSA_ENC | RSA_SIGN | DSA_SIGN  * SSL_aRSA<- RSA_ENC | RSA_SIGN  * SSL_aDSS<- DSA_SIGN  */
end_comment

begin_comment
comment|/* #define CERT_INVALID		0 #define CERT_PUBLIC_KEY		1 #define CERT_PRIVATE_KEY	2 */
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
block|}
name|CERT_PKEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cert_st
block|{
comment|/* Current active set */
name|CERT_PKEY
modifier|*
name|key
decl_stmt|;
comment|/* ALWAYS points to an element of the pkeys array 			 * Probably it would make more sense to store 			 * an index, not a pointer. */
comment|/* The following masks are for the key and auth 	 * algorithms that are supported by the certs below */
name|int
name|valid
decl_stmt|;
name|unsigned
name|long
name|mask
decl_stmt|;
name|unsigned
name|long
name|export_mask
decl_stmt|;
ifndef|#
directive|ifndef
name|NO_RSA
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
name|NO_DH
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
name|CERT_PKEY
name|pkeys
index|[
name|SSL_PKEY_NUM
index|]
decl_stmt|;
name|int
name|references
decl_stmt|;
comment|/*>1 only if SSL_copy_session_id is used */
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
comment|/* points to an element of peer_pkeys (never NULL!) */
name|CERT_PKEY
name|peer_pkeys
index|[
name|SSL_PKEY_NUM
index|]
decl_stmt|;
comment|/* Obviously we don't have the private keys of these, 	 * so maybe we shouldn't even use the CERT_PKEY type here. */
ifndef|#
directive|ifndef
name|NO_RSA
name|RSA
modifier|*
name|peer_rsa_tmp
decl_stmt|;
comment|/* not used for SSL 2 */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NO_DH
name|DH
modifier|*
name|peer_dh_tmp
decl_stmt|;
comment|/* not used for SSL 2 */
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
comment|/*#define MAC_DEBUG	*/
end_comment

begin_comment
comment|/*#define ERR_DEBUG	*/
end_comment

begin_comment
comment|/*#define ABORT_DEBUG	*/
end_comment

begin_comment
comment|/*#define PKT_DEBUG 1   */
end_comment

begin_comment
comment|/*#define DES_DEBUG	*/
end_comment

begin_comment
comment|/*#define DES_OFB_DEBUG	*/
end_comment

begin_comment
comment|/*#define SSL_DEBUG	*/
end_comment

begin_comment
comment|/*#define RSA_DEBUG	*/
end_comment

begin_comment
comment|/*#define IDEA_DEBUG	*/
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

begin_define
define|#
directive|define
name|ssl_get_cipher_by_char
parameter_list|(
name|ssl
parameter_list|,
name|ptr
parameter_list|)
define|\
value|((ssl)->method->get_cipher_by_char(ptr))
end_define

begin_comment
comment|/* This is for the SSLv3/TLSv1.0 differences in crypto/hash stuff  * It is a bit of a mess of functions, but hell, think of it as  * an opaque structure :-) */
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
name|EVP_MD_CTX
modifier|*
parameter_list|,
name|EVP_MD_CTX
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
name|EVP_MD_CTX
modifier|*
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
block|}
name|SSL3_ENC_METHOD
typedef|;
end_typedef

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
comment|/* The identifier byte for this compression type */
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

begin_decl_stmt
name|OPENSSL_EXTERN
name|SSL3_ENC_METHOD
name|ssl3_undef_enc_method
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
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

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_undef
undef|#
directive|undef
name|SSL_COMP_get_compression_methods
end_undef

begin_define
define|#
directive|define
name|SSL_COMP_get_compression_methods
value|SSL_COMP_get_compress_methods
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|SSL_METHOD
modifier|*
name|sslv2_base_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SSL_METHOD
modifier|*
name|sslv23_base_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SSL_METHOD
modifier|*
name|sslv3_base_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|SSL_COMP
modifier|*
modifier|*
name|comp
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
name|ssl_undefined_function
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|X509
modifier|*
name|ssl_get_server_send_cert
parameter_list|(
name|SSL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVP_PKEY
modifier|*
name|ssl_get_sign_pkey
parameter_list|(
name|SSL
modifier|*
parameter_list|,
name|SSL_CIPHER
modifier|*
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
name|void
name|ssl2_generate_key_material
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
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
name|char
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
name|char
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
parameter_list|()
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
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl2_pending
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
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
name|void
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
name|EVP_MD_CTX
modifier|*
name|ctx1
parameter_list|,
name|EVP_MD_CTX
modifier|*
name|ctx2
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
name|EVP_MD_CTX
modifier|*
name|in
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
name|ssl3_mac
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
name|unsigned
name|long
name|ssl3_output_cert_chain
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|,
name|X509
modifier|*
name|x
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
name|have
argument_list|,
name|STACK_OF
argument_list|(
name|SSL_CIPHER
argument_list|)
operator|*
name|pref
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
name|char
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
name|char
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
parameter_list|()
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
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssl3_pending
parameter_list|(
name|SSL
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

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
name|char
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
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SSL_METHOD
modifier|*
name|tlsv1_base_method
parameter_list|(
name|void
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
name|EVP_MD_CTX
modifier|*
name|in1_ctx
parameter_list|,
name|EVP_MD_CTX
modifier|*
name|in2_ctx
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
name|EVP_MD_CTX
modifier|*
name|in
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

begin_expr_stmt
name|STACK_OF
argument_list|(
name|SSL_COMP
argument_list|)
operator|*
name|SSL_COMP_get_compression_methods
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

