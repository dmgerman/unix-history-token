begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: fetch.h,v 1.6 1998/11/06 22:14:08 des Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FETCH_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_FETCH_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<fetch_err.h>
end_include

begin_define
define|#
directive|define
name|_LIBFETCH_VER
value|"libfetch/1.0"
end_define

begin_define
define|#
directive|define
name|URL_SCHEMELEN
value|16
end_define

begin_define
define|#
directive|define
name|URL_USERLEN
value|256
end_define

begin_define
define|#
directive|define
name|URL_PWDLEN
value|256
end_define

begin_struct
struct|struct
name|url
block|{
name|char
name|scheme
index|[
name|URL_SCHEMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|user
index|[
name|URL_USERLEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|pwd
index|[
name|URL_PWDLEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|host
index|[
name|MAXHOSTNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|port
decl_stmt|;
name|char
name|doc
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|url_stat
block|{
name|off_t
name|size
decl_stmt|;
name|time_t
name|atime
decl_stmt|;
name|time_t
name|mtime
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* FILE-specific functions */
end_comment

begin_function_decl
name|FILE
modifier|*
name|fetchGetFile
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchPutFile
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetchStatFile
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* HTTP-specific functions */
end_comment

begin_function_decl
name|char
modifier|*
name|fetchContentType
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchGetHTTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchPutHTTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetchStatHTTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FTP-specific functions */
end_comment

begin_function_decl
name|FILE
modifier|*
name|fetchGetFTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchPutFTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetchStatFTP
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic functions */
end_comment

begin_function_decl
name|struct
name|url
modifier|*
name|fetchParseURL
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchGetURL
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
name|FILE
modifier|*
name|fetchPutURL
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
name|fetchStatURL
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchGet
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fetchPut
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetchStat
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Last error code */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fetchLastErrCode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

