begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
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
name|descriptor
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
value|(struct chap *)((char *)a - (int)&((struct chap *)0)->auth)
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

