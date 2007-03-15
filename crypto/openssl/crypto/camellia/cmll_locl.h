begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/camellia/camellia_locl.h -*- mode:C; c-file-style: "eay" -*- */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright 2006 NTT (Nippon Telegraph and Telephone Corporation) .   * ALL RIGHTS RESERVED.  *  * Intellectual Property information for Camellia:  *     http://info.isl.ntt.co.jp/crypt/eng/info/chiteki.html  *  * News Release for Announcement of Camellia open source:  *     http://www.ntt.co.jp/news/news06e/0604/060413a.html  *  * The Camellia Code included herein is developed by  * NTT (Nippon Telegraph and Telephone Corporation), and is contributed  * to the OpenSSL project.  *  * The Camellia Code is licensed pursuant to the OpenSSL open source  * license provided below.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2006 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_CAMELLIA_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_CAMELLIA_LOCL_H
end_define

begin_include
include|#
directive|include
file|"openssl/e_os2.h"
end_include

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

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
end_typedef

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
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
operator|)
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|)
value|( _lrotl(x, 8)& 0x00ff00ff | _lrotr(x, 8)& 0xff00ff00 )
define|#
directive|define
name|GETU32
parameter_list|(
name|p
parameter_list|)
value|SWAP(*((u32 *)(p)))
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ *((u32 *)(ct)) = SWAP((st)); }
define|#
directive|define
name|CAMELLIA_SWAP4
parameter_list|(
name|x
parameter_list|)
value|(x = ( _lrotl(x, 8)& 0x00ff00ff | _lrotr(x, 8)& 0xff00ff00) )
else|#
directive|else
comment|/* not windows */
define|#
directive|define
name|GETU32
parameter_list|(
name|pt
parameter_list|)
value|(((u32)(pt)[0]<< 24) \ 	^ ((u32)(pt)[1]<< 16) \ 	^ ((u32)(pt)[2]<<  8) \ 	^ ((u32)(pt)[3]))
define|#
directive|define
name|PUTU32
parameter_list|(
name|ct
parameter_list|,
name|st
parameter_list|)
value|{ (ct)[0] = (u8)((st)>> 24); \ 	(ct)[1] = (u8)((st)>> 16); \ 	(ct)[2] = (u8)((st)>>  8); \ 	(ct)[3] = (u8)(st); }
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|)
operator|)
define|#
directive|define
name|CAMELLIA_SWAP4
parameter_list|(
name|x
parameter_list|)
define|\
value|do{\     asm("bswap %1" : "+r" (x));\   }while(0)
else|#
directive|else
define|#
directive|define
name|CAMELLIA_SWAP4
parameter_list|(
name|x
parameter_list|)
define|\
value|do{\      x = ((u32)x<< 16) + ((u32)x>> 16);\      x = (((u32)x& 0xff00ff)<< 8) + (((u32)x>> 8)& 0xff00ff);\    } while(0)
endif|#
directive|endif
endif|#
directive|endif
define|#
directive|define
name|COPY4WORD
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|do			 \ 		     {		 \ 		     (dst)[0]=(src)[0];		\ 		     (dst)[1]=(src)[1];		\ 		     (dst)[2]=(src)[2];		\ 		     (dst)[3]=(src)[3];		\ 		     }while(0)
define|#
directive|define
name|SWAP4WORD
parameter_list|(
name|word
parameter_list|)
define|\
value|do						\ 	   {					\ 	   CAMELLIA_SWAP4((word)[0]);			\ 	   CAMELLIA_SWAP4((word)[1]);			\ 	   CAMELLIA_SWAP4((word)[2]);			\ 	   CAMELLIA_SWAP4((word)[3]);			\ 	   }while(0)
define|#
directive|define
name|XOR4WORD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
comment|/* a = a ^ b */
define|\
value|do						\ 	{					\ 	(a)[0]^=(b)[0];				\ 	(a)[1]^=(b)[1];				\ 	(a)[2]^=(b)[2];				\ 	(a)[3]^=(b)[3];				\ 	}while(0)
define|#
directive|define
name|XOR4WORD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
comment|/* a = b ^ c */
define|\
value|do						\ 	{					\ 	(a)[0]=(b)[0]^(c)[0];			\ 	(a)[1]=(b)[1]^(c)[1];				\ 	(a)[2]=(b)[2]^(c)[2];				\ 	(a)[3]=(b)[3]^(c)[3];				\ 	}while(0)
name|void
name|camellia_setup128
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u32
modifier|*
name|subkey
parameter_list|)
function_decl|;
name|void
name|camellia_setup192
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u32
modifier|*
name|subkey
parameter_list|)
function_decl|;
name|void
name|camellia_setup256
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u32
modifier|*
name|subkey
parameter_list|)
function_decl|;
name|void
name|camellia_encrypt128
parameter_list|(
specifier|const
name|u32
modifier|*
name|subkey
parameter_list|,
name|u32
modifier|*
name|io
parameter_list|)
function_decl|;
name|void
name|camellia_decrypt128
parameter_list|(
specifier|const
name|u32
modifier|*
name|subkey
parameter_list|,
name|u32
modifier|*
name|io
parameter_list|)
function_decl|;
name|void
name|camellia_encrypt256
parameter_list|(
specifier|const
name|u32
modifier|*
name|subkey
parameter_list|,
name|u32
modifier|*
name|io
parameter_list|)
function_decl|;
name|void
name|camellia_decrypt256
parameter_list|(
specifier|const
name|u32
modifier|*
name|subkey
parameter_list|,
name|u32
modifier|*
name|io
parameter_list|)
function_decl|;
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
comment|/* #ifndef HEADER_CAMELLIA_LOCL_H */
end_comment

end_unit

