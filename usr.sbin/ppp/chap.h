begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CHAP_CHALLENGE
value|1
end_define

begin_define
define|#
directive|define
name|CHAP_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|CHAP_SUCCESS
value|3
end_define

begin_define
define|#
directive|define
name|CHAP_FAILURE
value|4
end_define

begin_struct
struct|struct
name|chap
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
struct|struct
block|{
name|pid_t
name|pid
decl_stmt|;
name|int
name|fd
decl_stmt|;
struct|struct
block|{
name|char
name|ptr
index|[
name|AUTHLEN
operator|*
literal|2
operator|+
literal|3
index|]
decl_stmt|;
comment|/* Allow for \r\n at the end (- NUL) */
name|int
name|len
decl_stmt|;
block|}
name|buf
struct|;
block|}
name|child
struct|;
name|struct
name|authinfo
name|auth
decl_stmt|;
struct|struct
block|{
name|u_char
name|local
index|[
name|CHAPCHALLENGELEN
operator|+
name|AUTHLEN
index|]
decl_stmt|;
comment|/* I invented this one */
name|u_char
name|peer
index|[
name|CHAPCHALLENGELEN
operator|+
name|AUTHLEN
index|]
decl_stmt|;
comment|/* Peer gave us this one */
block|}
name|challenge
struct|;
ifdef|#
directive|ifdef
name|HAVE_DES
name|unsigned
name|NTRespSent
range|:
literal|1
decl_stmt|;
comment|/* Our last response */
name|int
name|peertries
decl_stmt|;
name|u_char
name|authresponse
index|[
name|CHAPAUTHRESPONSELEN
index|]
decl_stmt|;
comment|/* CHAP 81 response */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2chap
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == CHAP_DESCRIPTOR ? (struct chap *)(d) : NULL)
end_define

begin_define
define|#
directive|define
name|auth2chap
parameter_list|(
name|a
parameter_list|)
define|\
value|((struct chap *)((char *)a - (int)&((struct chap *)0)->auth))
end_define

begin_function_decl
specifier|extern
name|void
name|chap_Init
parameter_list|(
name|struct
name|chap
modifier|*
parameter_list|,
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|chap_ReInit
parameter_list|(
name|struct
name|chap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|chap_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

