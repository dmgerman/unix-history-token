begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: dh.h,v 1.7 2001/06/26 17:27:23 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Niels Provos.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DH_H
end_ifndef

begin_define
define|#
directive|define
name|DH_H
end_define

begin_struct
struct|struct
name|dhgroup
block|{
name|int
name|size
decl_stmt|;
name|BIGNUM
modifier|*
name|g
decl_stmt|;
name|BIGNUM
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|DH
modifier|*
name|choose_dh
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group_asc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group
parameter_list|(
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DH
modifier|*
name|dh_new_group1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dh_gen_key
parameter_list|(
name|DH
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dh_pub_is_valid
parameter_list|(
name|DH
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dh_estimate
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DH_GRP_MIN
value|1024
end_define

begin_define
define|#
directive|define
name|DH_GRP_MAX
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

