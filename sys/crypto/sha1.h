begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: sha1.h,v 1.5 2000/03/27 04:36:23 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * FIPS pub 180-1: Secure Hash Algorithm (SHA-1)  * based on: http://csrc.nist.gov/fips/fip180-1.txt  * implemented by Jun-ichiro itojun Itoh<itojun@itojun.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_SHA1_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_SHA1_H_
end_define

begin_struct
struct|struct
name|sha1_ctxt
block|{
union|union
block|{
name|u_int8_t
name|b8
index|[
literal|20
index|]
decl_stmt|;
name|u_int32_t
name|b32
index|[
literal|5
index|]
decl_stmt|;
block|}
name|h
union|;
union|union
block|{
name|u_int8_t
name|b8
index|[
literal|8
index|]
decl_stmt|;
name|u_int64_t
name|b64
index|[
literal|1
index|]
decl_stmt|;
block|}
name|c
union|;
union|union
block|{
name|u_int8_t
name|b8
index|[
literal|64
index|]
decl_stmt|;
name|u_int32_t
name|b32
index|[
literal|16
index|]
decl_stmt|;
block|}
name|m
union|;
name|u_int8_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|sha1_init
parameter_list|(
name|struct
name|sha1_ctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sha1_pad
parameter_list|(
name|struct
name|sha1_ctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sha1_loop
parameter_list|(
name|struct
name|sha1_ctxt
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sha1_result
parameter_list|(
name|struct
name|sha1_ctxt
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compatibilty with other SHA1 source codes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sha1_ctxt
name|SHA1_CTX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SHA1Init
parameter_list|(
name|x
parameter_list|)
value|sha1_init((x))
end_define

begin_define
define|#
directive|define
name|SHA1Update
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|sha1_loop((x), (y), (z))
end_define

begin_define
define|#
directive|define
name|SHA1Final
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|sha1_result((y), (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|SHA1_RESULTLEN
value|(160/8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_NETINET6_SHA1_H_*/
end_comment

end_unit

