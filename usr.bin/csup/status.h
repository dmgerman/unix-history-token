begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STATUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_STATUS_H_
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_struct_decl
struct_decl|struct
name|coll
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|status
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|SR_DIRDOWN
value|0
end_define

begin_define
define|#
directive|define
name|SR_CHECKOUTLIVE
value|1
end_define

begin_define
define|#
directive|define
name|SR_CHECKOUTDEAD
value|2
end_define

begin_define
define|#
directive|define
name|SR_FILELIVE
value|3
end_define

begin_define
define|#
directive|define
name|SR_FILEDEAD
value|4
end_define

begin_define
define|#
directive|define
name|SR_DIRUP
value|5
end_define

begin_struct
struct|struct
name|statusrec
block|{
name|int
name|sr_type
decl_stmt|;
name|char
modifier|*
name|sr_file
decl_stmt|;
name|char
modifier|*
name|sr_tag
decl_stmt|;
name|char
modifier|*
name|sr_date
decl_stmt|;
name|char
modifier|*
name|sr_revnum
decl_stmt|;
name|char
modifier|*
name|sr_revdate
decl_stmt|;
comment|/* 	 * "clientrttr" contains the attributes of the client's file if there 	 * is one. "serverattr" contains the attributes of the corresponding 	 * file on the server.  In CVS mode, these are identical.  But in 	 * checkout mode, "clientattr" represents the checked-out file while 	 * "serverattr" represents the corresponding RCS file on the server. 	 */
name|struct
name|fattr
modifier|*
name|sr_serverattr
decl_stmt|;
name|struct
name|fattr
modifier|*
name|sr_clientattr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|status
modifier|*
name|status_open
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|,
name|time_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|status_get
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|statusrec
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|status_put
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|,
name|struct
name|statusrec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|status_eof
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|status_errmsg
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|status_delete
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|status_close
parameter_list|(
name|struct
name|status
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STATUS_H_ */
end_comment

end_unit

