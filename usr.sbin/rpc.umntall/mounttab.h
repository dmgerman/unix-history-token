begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Martin Blapp  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|STRSIZ
value|(RPCMNT_NAMELEN+RPCMNT_PATHLEN+100)
end_define

begin_define
define|#
directive|define
name|PATH_MOUNTTAB
value|"/var/db/mounttab"
end_define

begin_comment
comment|/* Structure for /var/db/mounttab */
end_comment

begin_struct
struct|struct
name|mtablist
block|{
name|time_t
name|mtab_time
decl_stmt|;
name|char
name|mtab_host
index|[
name|RPCMNT_NAMELEN
index|]
decl_stmt|;
name|char
name|mtab_dirp
index|[
name|RPCMNT_PATHLEN
index|]
decl_stmt|;
name|struct
name|mtablist
modifier|*
name|mtab_next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|add_mtab
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|badline
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_mtab
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_mtab
parameter_list|(
name|struct
name|mtablist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_mtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_mtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

