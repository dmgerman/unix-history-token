begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTXDB_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTXDB_H_
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_define
define|#
directive|define
name|_PATH_UTX_ACTIVE
value|"/var/run/utx.active"
end_define

begin_define
define|#
directive|define
name|_PATH_UTX_LASTLOGIN
value|"/var/log/utx.lastlogin"
end_define

begin_define
define|#
directive|define
name|_PATH_UTX_LOG
value|"/var/log/utx.log"
end_define

begin_comment
comment|/*  * Entries in struct futx are ordered by how often they are used.  In  * utx.log only entries will be written until the last non-zero byte,  * which means we want to put the hostname at the end. Most primitive  * records only store a ut_type and ut_tv, which means we want to store  * those at the front.  */
end_comment

begin_struct_decl
struct_decl|struct
name|utmpx
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|futx
block|{
name|uint8_t
name|fu_type
decl_stmt|;
name|uint64_t
name|fu_tv
decl_stmt|;
name|char
name|fu_id
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|fu_pid
decl_stmt|;
name|char
name|fu_user
index|[
literal|32
index|]
decl_stmt|;
name|char
name|fu_line
index|[
literal|16
index|]
decl_stmt|;
name|char
name|fu_host
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|void
name|utx_to_futx
parameter_list|(
specifier|const
name|struct
name|utmpx
modifier|*
parameter_list|,
name|struct
name|futx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|futx_to_utx
parameter_list|(
specifier|const
name|struct
name|futx
modifier|*
parameter_list|,
name|struct
name|utmpx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UTXDB_H_ */
end_comment

end_unit

