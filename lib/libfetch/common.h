begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMMON_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_COMMON_H_INCLUDED
end_define

begin_define
define|#
directive|define
name|FTP_DEFAULT_PORT
value|21
end_define

begin_define
define|#
directive|define
name|HTTP_DEFAULT_PORT
value|80
end_define

begin_define
define|#
directive|define
name|FTP_DEFAULT_PROXY_PORT
value|21
end_define

begin_define
define|#
directive|define
name|HTTP_DEFAULT_PROXY_PORT
value|3128
end_define

begin_comment
comment|/* Structure used for error message lists */
end_comment

begin_struct
struct|struct
name|fetcherr
block|{
specifier|const
name|int
name|num
decl_stmt|,
name|cat
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|_fetch_seterr
parameter_list|(
name|struct
name|fetcherr
modifier|*
name|p
parameter_list|,
name|int
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_fetch_syserr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_fetch_info
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_default_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_default_proxy_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_connect
parameter_list|(
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|af
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_getln
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_putln
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_fetch_add_entry
parameter_list|(
name|struct
name|url_ent
modifier|*
modifier|*
name|p
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|int
modifier|*
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|url_stat
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_ftp_seterr
parameter_list|(
name|n
parameter_list|)
value|_fetch_seterr(_ftp_errlist, n)
end_define

begin_define
define|#
directive|define
name|_http_seterr
parameter_list|(
name|n
parameter_list|)
value|_fetch_seterr(_http_errlist, n)
end_define

begin_define
define|#
directive|define
name|_netdb_seterr
parameter_list|(
name|n
parameter_list|)
value|_fetch_seterr(_netdb_errlist, n)
end_define

begin_define
define|#
directive|define
name|_url_seterr
parameter_list|(
name|n
parameter_list|)
value|_fetch_seterr(_url_errlist, n)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|x
parameter_list|)
value|do x; while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * I don't really like exporting _http_request() from http.c, but ftp.c  * occasionally needs to use an HTTP proxy, and this saves me from adding  * a lot of special-case code to http.c to handle those cases.  *  * Note that _http_request() frees purl, which is way ugly but saves us a  * whole lot of trouble.  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|_http_request
parameter_list|(
name|struct
name|url
modifier|*
name|URL
parameter_list|,
specifier|const
name|char
modifier|*
name|op
parameter_list|,
name|struct
name|url_stat
modifier|*
name|us
parameter_list|,
name|struct
name|url
modifier|*
name|purl
parameter_list|,
specifier|const
name|char
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check whether a particular flag is set  */
end_comment

begin_define
define|#
directive|define
name|CHECK_FLAG
parameter_list|(
name|x
parameter_list|)
value|(flags&& strchr(flags, (x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

