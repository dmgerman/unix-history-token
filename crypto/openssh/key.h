begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: key.h,v 1.18 2002/02/24 19:14:59 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KEY_H
end_ifndef

begin_define
define|#
directive|define
name|KEY_H
end_define

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|Key
name|Key
typedef|;
end_typedef

begin_enum
enum|enum
name|types
block|{
name|KEY_RSA1
block|,
name|KEY_RSA
block|,
name|KEY_DSA
block|,
name|KEY_UNSPEC
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fp_type
block|{
name|SSH_FP_SHA1
block|,
name|SSH_FP_MD5
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fp_rep
block|{
name|SSH_FP_HEX
block|,
name|SSH_FP_BUBBLEBABBLE
block|}
enum|;
end_enum

begin_comment
comment|/* key is stored in external hardware */
end_comment

begin_define
define|#
directive|define
name|KEY_FLAG_EXT
value|0x0001
end_define

begin_struct
struct|struct
name|Key
block|{
name|int
name|type
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|RSA
modifier|*
name|rsa
decl_stmt|;
name|DSA
modifier|*
name|dsa
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|Key
modifier|*
name|key_new
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_new_private
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|key_free
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_equal
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|key_fingerprint
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|enum
name|fp_type
parameter_list|,
name|enum
name|fp_rep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|key_type
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_write
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_read
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|key_size
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_generate
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_from_private
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_type_from_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|key_from_blob
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_to_blob
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|key_ssh_name
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_names_valid2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_sign
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|key_verify
parameter_list|(
name|Key
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

