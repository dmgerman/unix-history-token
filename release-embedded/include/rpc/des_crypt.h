begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)des_crypt.h	2.1 88/08/11 4.0 RPCSRC;	from 1.4 88/02/08 (C) 1986 SMI  * $FreeBSD$  *  * des_crypt.h, des library routine interface  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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

begin_define
define|#
directive|define
name|DES_MAXDATA
value|8192
end_define

begin_comment
comment|/* max bytes encrypted in one call */
end_comment

begin_define
define|#
directive|define
name|DES_DIRMASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DES_ENCRYPT
value|(0*DES_DIRMASK)
end_define

begin_comment
comment|/* Encrypt */
end_comment

begin_define
define|#
directive|define
name|DES_DECRYPT
value|(1*DES_DIRMASK)
end_define

begin_comment
comment|/* Decrypt */
end_comment

begin_define
define|#
directive|define
name|DES_DEVMASK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DES_HW
value|(0*DES_DEVMASK)
end_define

begin_comment
comment|/* Use hardware device */
end_comment

begin_define
define|#
directive|define
name|DES_SW
value|(1*DES_DEVMASK)
end_define

begin_comment
comment|/* Use software device */
end_comment

begin_define
define|#
directive|define
name|DESERR_NONE
value|0
end_define

begin_comment
comment|/* succeeded */
end_comment

begin_define
define|#
directive|define
name|DESERR_NOHWDEVICE
value|1
end_define

begin_comment
comment|/* succeeded, but hw device not available */
end_comment

begin_define
define|#
directive|define
name|DESERR_HWERROR
value|2
end_define

begin_comment
comment|/* failed, hardware/driver error */
end_comment

begin_define
define|#
directive|define
name|DESERR_BADPARAM
value|3
end_define

begin_comment
comment|/* failed, bad parameter to call */
end_comment

begin_define
define|#
directive|define
name|DES_FAILED
parameter_list|(
name|err
parameter_list|)
define|\
value|((err)> DESERR_NOHWDEVICE)
end_define

begin_comment
comment|/*  * cbc_crypt()  * ecb_crypt()  *  * Encrypt (or decrypt) len bytes of a buffer buf.  * The length must be a multiple of eight.  * The key should have odd parity in the low bit of each byte.  * ivec is the input vector, and is updated to the new one (cbc only).  * The mode is created by oring together the appropriate parameters.  * DESERR_NOHWDEVICE is returned if DES_HW was specified but  * there was no hardware to do it on (the data will still be  * encrypted though, in software).  */
end_comment

begin_comment
comment|/*  * Cipher Block Chaining mode  */
end_comment

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_function_decl
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
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DES_DES_CRYPT_H */
end_comment

end_unit

