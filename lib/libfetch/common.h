begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998-2014 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_SSL
end_ifdef

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_include
include|#
directive|include
file|<openssl/x509.h>
end_include

begin_include
include|#
directive|include
file|<openssl/pem.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Connection */
end_comment

begin_typedef
typedef|typedef
name|struct
name|fetchconn
name|conn_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fetchconn
block|{
name|int
name|sd
decl_stmt|;
comment|/* socket descriptor */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer */
name|size_t
name|bufsize
decl_stmt|;
comment|/* buffer size */
name|size_t
name|buflen
decl_stmt|;
comment|/* length of buffer contents */
name|int
name|err
decl_stmt|;
comment|/* last protocol reply code */
ifdef|#
directive|ifdef
name|WITH_SSL
name|SSL
modifier|*
name|ssl
decl_stmt|;
comment|/* SSL handle */
name|SSL_CTX
modifier|*
name|ssl_ctx
decl_stmt|;
comment|/* SSL context */
name|X509
modifier|*
name|ssl_cert
decl_stmt|;
comment|/* server certificate */
specifier|const
name|SSL_METHOD
modifier|*
name|ssl_meth
decl_stmt|;
comment|/* SSL method */
endif|#
directive|endif
name|int
name|ref
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

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
decl_stmt|;
specifier|const
name|int
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

begin_comment
comment|/* for fetch_writev */
end_comment

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|fetch_seterr
parameter_list|(
name|struct
name|fetcherr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetch_syserr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fetch_info
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_default_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_default_proxy_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_bind
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|conn_t
modifier|*
name|fetch_connect
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|conn_t
modifier|*
name|fetch_reopen
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|conn_t
modifier|*
name|fetch_ref
parameter_list|(
name|conn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_SSL
end_ifdef

begin_function_decl
name|int
name|fetch_ssl_cb_verify_crt
parameter_list|(
name|int
parameter_list|,
name|X509_STORE_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|fetch_ssl
parameter_list|(
name|conn_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|url
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|fetch_read
parameter_list|(
name|conn_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_getln
parameter_list|(
name|conn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|fetch_write
parameter_list|(
name|conn_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|fetch_writev
parameter_list|(
name|conn_t
modifier|*
parameter_list|,
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_putln
parameter_list|(
name|conn_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_close
parameter_list|(
name|conn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_add_entry
parameter_list|(
name|struct
name|url_ent
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_netrc_auth
parameter_list|(
name|struct
name|url
modifier|*
name|url
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fetch_no_proxy_match
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ftp_seterr
parameter_list|(
name|n
parameter_list|)
value|fetch_seterr(ftp_errlist, n)
end_define

begin_define
define|#
directive|define
name|http_seterr
parameter_list|(
name|n
parameter_list|)
value|fetch_seterr(http_errlist, n)
end_define

begin_define
define|#
directive|define
name|netdb_seterr
parameter_list|(
name|n
parameter_list|)
value|fetch_seterr(netdb_errlist, n)
end_define

begin_define
define|#
directive|define
name|url_seterr
parameter_list|(
name|n
parameter_list|)
value|fetch_seterr(url_errlist, n)
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
value|do { if (fetchDebug) { x; } } while (0)
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
comment|/*  * I don't really like exporting http_request() and ftp_request(),  * but the HTTP and FTP code occasionally needs to cross-call  * eachother, and this saves me from adding a lot of special-case code  * to handle those cases.  *  * Note that _*_request() free purl, which is way ugly but saves us a  * whole lot of trouble.  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|http_request
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|http_request_body
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|ftp_request
parameter_list|(
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|url_stat
modifier|*
parameter_list|,
name|struct
name|url
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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

