begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)encrypt.h	8.1 (Berkeley) 6/4/93  *  *	@(#)encrypt.h	5.2 (Berkeley) 3/22/91  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1990 by the Massachusetts Institute of Technology  *  * Export of this software from the United States of America is assumed  * to require a specific license from the United States Government.  * It is the responsibility of any person or organization contemplating  * export to obtain such a license before exporting.  *  * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and  * distribute this software and its documentation for any purpose and  * without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright notice and  * this permission notice appear in supporting documentation, and that  * the name of M.I.T. not be used in advertising or publicity pertaining  * to distribution of the software without specific, written prior  * permission.  M.I.T. makes no representations about the suitability of  * this software for any purpose.  It is provided "as is" without express  * or implied warranty.  */
end_comment

begin_comment
comment|/* $Id: encrypt.h,v 1.7 2001/08/22 20:30:22 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ENCRYPT__
end_ifndef

begin_define
define|#
directive|define
name|__ENCRYPT__
end_define

begin_define
define|#
directive|define
name|DIR_DECRYPT
value|1
end_define

begin_define
define|#
directive|define
name|DIR_ENCRYPT
value|2
end_define

begin_define
define|#
directive|define
name|VALIDKEY
parameter_list|(
name|key
parameter_list|)
value|( key[0] | key[1] | key[2] | key[3] | \ 			  key[4] | key[5] | key[6] | key[7])
end_define

begin_define
define|#
directive|define
name|SAMEKEY
parameter_list|(
name|k1
parameter_list|,
name|k2
parameter_list|)
value|(!memcmp(k1, k2, sizeof(des_cblock)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|type
decl_stmt|;
name|int
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|Session_Key
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
name|void
function_decl|(
modifier|*
name|output
function_decl|)
parameter_list|(
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
name|input
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is
function_decl|)
parameter_list|(
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
name|reply
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|session
function_decl|)
parameter_list|(
name|Session_Key
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|keyid
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|printsub
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
name|Encryptions
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SK_DES
value|1
end_define

begin_comment
comment|/* Matched Kerberos v5 KEYTYPE_DES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OPENSSL
end_ifdef

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_define
define|#
directive|define
name|des_new_random_key
value|des_random_key
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"enc-proto.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|encrypt_debug_mode
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|decrypt_input
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|encrypt_output
function_decl|)
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

