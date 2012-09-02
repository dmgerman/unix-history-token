begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)des_crypt.h	2.1 88/08/11 4.0 RPCSRC;	from 1.4 88/02/08 (C) 1986 SMI  * $FreeBSD$  *  * des_crypt.h, des library routine interface  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * des_crypt.h, des library routine interface  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DES_DES_CRYPT_H
end_ifndef

begin_define
define|#
directive|define
name|_DES_DES_CRYPT_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|DES_MAXDATA
value|8192
comment|/* max bytes encrypted in one call */
define|#
directive|define
name|DES_DIRMASK
value|(1<< 0)
define|#
directive|define
name|DES_ENCRYPT
value|(0*DES_DIRMASK)
comment|/* Encrypt */
define|#
directive|define
name|DES_DECRYPT
value|(1*DES_DIRMASK)
comment|/* Decrypt */
define|#
directive|define
name|DES_DEVMASK
value|(1<< 1)
define|#
directive|define
name|DES_HW
value|(0*DES_DEVMASK)
comment|/* Use hardware device */
define|#
directive|define
name|DES_SW
value|(1*DES_DEVMASK)
comment|/* Use software device */
define|#
directive|define
name|DESERR_NONE
value|0
comment|/* succeeded */
define|#
directive|define
name|DESERR_NOHWDEVICE
value|1
comment|/* succeeded, but hw device not available */
define|#
directive|define
name|DESERR_HWERROR
value|2
comment|/* failed, hardware/driver error */
define|#
directive|define
name|DESERR_BADPARAM
value|3
comment|/* failed, bad parameter to call */
define|#
directive|define
name|DES_FAILED
parameter_list|(
name|err
parameter_list|)
define|\
value|((err)> DESERR_NOHWDEVICE)
comment|/*  * cbc_crypt()  * ecb_crypt()  *  * Encrypt (or decrypt) len bytes of a buffer buf.  * The length must be a multiple of eight.  * The key should have odd parity in the low bit of each byte.  * ivec is the input vector, and is updated to the new one (cbc only).  * The mode is created by oring together the appropriate parameters.  * DESERR_NOHWDEVICE is returned if DES_HW was specified but  * there was no hardware to do it on (the data will still be  * encrypted though, in software).  */
comment|/*  * Cipher Block Chaining mode  */
name|__BEGIN_DECLS
name|int
name|cbc_crypt
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|__END_DECLS
comment|/*  * Electronic Code Book mode  */
name|__BEGIN_DECLS
name|int
name|ecb_crypt
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|__END_DECLS
comment|/*   * Set des parity for a key.  * DES parity is odd and in the low bit of each byte  */
name|__BEGIN_DECLS
name|void
name|des_setparity
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|__END_DECLS
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DES_DES_CRYPT_H */
end_comment

end_unit

