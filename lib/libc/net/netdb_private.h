begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 The FreeBSD Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETDB_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETDB_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* XXX: for BUFSIZ */
end_comment

begin_define
define|#
directive|define
name|SERVENT_MAXALIASES
value|35
end_define

begin_struct
struct|struct
name|servent_data
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
modifier|*
name|aliases
index|[
name|SERVENT_MAXALIASES
index|]
decl_stmt|;
name|int
name|stayopen
decl_stmt|;
name|char
name|line
index|[
name|BUFSIZ
operator|+
literal|1
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|YP
name|int
name|stepping_yp
decl_stmt|;
name|char
modifier|*
name|getservbyname_yp
decl_stmt|;
name|char
modifier|*
name|getservbyproto_yp
decl_stmt|;
name|int
name|getservbyport_yp
decl_stmt|;
name|char
modifier|*
name|yp_domain
decl_stmt|;
name|char
modifier|*
name|key
decl_stmt|;
name|int
name|keylen
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|servdata
block|{
name|struct
name|servent
name|serv
decl_stmt|;
name|struct
name|servent_data
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|endservent_r
value|__endservent_r
end_define

begin_define
define|#
directive|define
name|getservbyname_r
value|__getservbyname_r
end_define

begin_define
define|#
directive|define
name|getservbyport_r
value|__getservbyport_r
end_define

begin_define
define|#
directive|define
name|getservent_r
value|__getservent_r
end_define

begin_define
define|#
directive|define
name|setservent_r
value|__setservent_r
end_define

begin_function_decl
name|struct
name|servdata
modifier|*
name|__servdata_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endservent_r
parameter_list|(
name|struct
name|servent_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getservbyname_r
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|servent
modifier|*
parameter_list|,
name|struct
name|servent_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getservbyport_r
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|servent
modifier|*
parameter_list|,
name|struct
name|servent_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getservent_r
parameter_list|(
name|struct
name|servent
modifier|*
parameter_list|,
name|struct
name|servent_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setservent_r
parameter_list|(
name|int
parameter_list|,
name|struct
name|servent_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETDB_PRIVATE_H_ */
end_comment

end_unit

