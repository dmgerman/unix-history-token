begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/aes/aes.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2002 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_AES_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_AES_LOCL_H
end_define

begin_include
include|#
directive|include
file|<openssl/e_os2.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_AES
end_ifdef

begin_error
error|#
directive|error
error|AES is disabled.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_M_IA64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_SYS_WINCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|)
value|(_lrotl(x, 8)& 0x00ff00ff | _lrotr(x, 8)& 0xff00ff00)
end_define

begin_define
define|#
directive|define
name|GETU32
parameter_list|(
name|p
parameter_list|)
value|SWAP(*((u32 *)(p)))
end_define

begin_define
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ *((u32 *)(ct)) = SWAP((st)); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GETU32
parameter_list|(
name|pt
parameter_list|)
value|(((u32)(pt)[0]<< 24) ^ ((u32)(pt)[1]<< 16) ^ ((u32)(pt)[2]<<  8) ^ ((u32)(pt)[3]))
end_define

begin_define
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ (ct)[0] = (u8)((st)>> 24); (ct)[1] = (u8)((st)>> 16); (ct)[2] = (u8)((st)>>  8); (ct)[3] = (u8)(st); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXKC
value|(256/32)
end_define

begin_define
define|#
directive|define
name|MAXKB
value|(256/8)
end_define

begin_define
define|#
directive|define
name|MAXNR
value|14
end_define

begin_comment
comment|/* This controls loop-unrolling in aes_core.c */
end_comment

begin_undef
undef|#
directive|undef
name|FULL_UNROLL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HEADER_AES_LOCL_H */
end_comment

end_unit

