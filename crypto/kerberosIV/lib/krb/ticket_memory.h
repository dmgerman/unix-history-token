begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* ticket_memory.h - Storage for tickets in memory  * Author: d93-jka@nada.kth.se - June 1996  */
end_comment

begin_comment
comment|/* $Id: ticket_memory.h,v 1.8 1999/12/02 16:58:44 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TICKET_MEMORY_H
end_ifndef

begin_define
define|#
directive|define
name|TICKET_MEMORY_H
end_define

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_define
define|#
directive|define
name|CRED_VEC_SZ
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_tktmem
block|{
name|char
name|tmname
index|[
literal|64
index|]
decl_stmt|;
name|char
name|pname
index|[
name|ANAME_SZ
index|]
decl_stmt|;
comment|/* Principal's name */
name|char
name|pinst
index|[
name|INST_SZ
index|]
decl_stmt|;
comment|/* Principal's instance */
name|int
name|last_cred_no
decl_stmt|;
name|CREDENTIALS
name|cred_vec
index|[
name|CRED_VEC_SZ
index|]
decl_stmt|;
name|time_t
name|kdc_diff
decl_stmt|;
block|}
name|tktmem
typedef|;
end_typedef

begin_function_decl
name|int
name|newTktMem
parameter_list|(
specifier|const
name|char
modifier|*
name|tf_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freeTktMem
parameter_list|(
specifier|const
name|char
modifier|*
name|tf_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tktmem
modifier|*
name|getTktMem
parameter_list|(
specifier|const
name|char
modifier|*
name|tf_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|firstCred
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nextCredIndex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|currCredIndex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nextFreeIndex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TICKET_MEMORY_H */
end_comment

end_unit

