begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 The DragonFly Project.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Simon 'corecode' Schubert<corecode@fs.ei.tum.de> and  * Matthias Schmidt<matthias@dragonflybsd.org>.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_H
end_ifndef

begin_define
define|#
directive|define
name|DMA_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_define
define|#
directive|define
name|VERSION
value|"DragonFly Mail Agent " DMA_VERSION
end_define

begin_define
define|#
directive|define
name|BUF_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|ERRMSG_SIZE
value|200
end_define

begin_define
define|#
directive|define
name|USERNAME_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|MIN_RETRY
value|300
end_define

begin_comment
comment|/* 5 minutes */
end_comment

begin_define
define|#
directive|define
name|MAX_RETRY
value|(3*60*60)
end_define

begin_comment
comment|/* retry at least every 3 hours */
end_comment

begin_define
define|#
directive|define
name|MAX_TIMEOUT
value|(5*24*60*60)
end_define

begin_comment
comment|/* give up after 5 days */
end_comment

begin_define
define|#
directive|define
name|SLEEP_TIMEOUT
value|30
end_define

begin_comment
comment|/* check for queue flush every 30 seconds */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATH_MAX
end_ifndef

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_comment
comment|/* Max path len */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SMTP_PORT
value|25
end_define

begin_comment
comment|/* Default SMTP port */
end_comment

begin_define
define|#
directive|define
name|CON_TIMEOUT
value|(5*60)
end_define

begin_comment
comment|/* Connection timeout per RFC5321 */
end_comment

begin_define
define|#
directive|define
name|STARTTLS
value|0x002
end_define

begin_comment
comment|/* StartTLS support */
end_comment

begin_define
define|#
directive|define
name|SECURETRANS
value|0x004
end_define

begin_comment
comment|/* SSL/TLS in general */
end_comment

begin_define
define|#
directive|define
name|NOSSL
value|0x008
end_define

begin_comment
comment|/* Do not use SSL */
end_comment

begin_define
define|#
directive|define
name|DEFER
value|0x010
end_define

begin_comment
comment|/* Defer mails */
end_comment

begin_define
define|#
directive|define
name|INSECURE
value|0x020
end_define

begin_comment
comment|/* Allow plain login w/o encryption */
end_comment

begin_define
define|#
directive|define
name|FULLBOUNCE
value|0x040
end_define

begin_comment
comment|/* Bounce the full message */
end_comment

begin_define
define|#
directive|define
name|TLS_OPP
value|0x080
end_define

begin_comment
comment|/* Opportunistic STARTTLS */
end_comment

begin_define
define|#
directive|define
name|NULLCLIENT
value|0x100
end_define

begin_comment
comment|/* Nullclient support */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONF_PATH
end_ifndef

begin_error
error|#
directive|error
error|Please define CONF_PATH
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBEXEC_PATH
end_ifndef

begin_error
error|#
directive|error
error|Please define LIBEXEC_PATH
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPOOL_FLUSHFILE
value|"flush"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_ROOT_USER
end_ifndef

begin_define
define|#
directive|define
name|DMA_ROOT_USER
value|"mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_GROUP
end_ifndef

begin_define
define|#
directive|define
name|DMA_GROUP
value|"mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MBOX_STRICT
end_ifndef

begin_define
define|#
directive|define
name|MBOX_STRICT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|stritem
block|{
name|SLIST_ENTRY
argument_list|(
argument|stritem
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|strlist
argument_list|,
name|stritem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|alias
block|{
name|LIST_ENTRY
argument_list|(
argument|alias
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|alias
decl_stmt|;
name|struct
name|strlist
name|dests
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|aliases
argument_list|,
name|alias
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|qitem
block|{
name|LIST_ENTRY
argument_list|(
argument|qitem
argument_list|)
name|next
expr_stmt|;
specifier|const
name|char
modifier|*
name|sender
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
name|char
modifier|*
name|queuefn
decl_stmt|;
name|char
modifier|*
name|mailfn
decl_stmt|;
name|char
modifier|*
name|queueid
decl_stmt|;
name|FILE
modifier|*
name|queuef
decl_stmt|;
name|FILE
modifier|*
name|mailf
decl_stmt|;
name|int
name|remote
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|queueh
argument_list|,
name|qitem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|queue
block|{
name|struct
name|queueh
name|queue
decl_stmt|;
name|char
modifier|*
name|id
decl_stmt|;
name|FILE
modifier|*
name|mailf
decl_stmt|;
name|char
modifier|*
name|tmpf
decl_stmt|;
specifier|const
name|char
modifier|*
name|sender
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config
block|{
specifier|const
name|char
modifier|*
name|smarthost
decl_stmt|;
name|int
name|port
decl_stmt|;
specifier|const
name|char
modifier|*
name|aliases
decl_stmt|;
specifier|const
name|char
modifier|*
name|spooldir
decl_stmt|;
specifier|const
name|char
modifier|*
name|authpath
decl_stmt|;
specifier|const
name|char
modifier|*
name|certfile
decl_stmt|;
name|int
name|features
decl_stmt|;
specifier|const
name|char
modifier|*
name|mailname
decl_stmt|;
specifier|const
name|char
modifier|*
name|masquerade_host
decl_stmt|;
specifier|const
name|char
modifier|*
name|masquerade_user
decl_stmt|;
comment|/* XXX does not belong into config */
name|SSL
modifier|*
name|ssl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|authuser
block|{
name|SLIST_ENTRY
argument_list|(
argument|authuser
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|login
decl_stmt|;
name|char
modifier|*
name|password
decl_stmt|;
name|char
modifier|*
name|host
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|authusers
argument_list|,
name|authuser
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mx_hostentry
block|{
name|char
name|host
index|[
name|MAXDNAME
index|]
decl_stmt|;
name|char
name|addr
index|[
name|INET6_ADDRSTRLEN
index|]
decl_stmt|;
name|int
name|pref
decl_stmt|;
name|struct
name|addrinfo
name|ai
decl_stmt|;
name|struct
name|sockaddr_storage
name|sa
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|aliases
name|aliases
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|config
name|config
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|strlist
name|tmpfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|authusers
name|authusers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|username
index|[
name|USERNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uid_t
name|useruid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|logident_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|neterr
index|[
name|ERRMSG_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|errmsg
index|[
name|ERRMSG_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* aliases_parse.y */
end_comment

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|yyin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* conf.c */
end_comment

begin_function_decl
name|void
name|trim_line
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_conf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_authfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* crypto.c */
end_comment

begin_function_decl
name|void
name|hmac_md5
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smtp_auth_md5
parameter_list|(
name|int
parameter_list|,
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
name|smtp_init_crypto
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dns.c */
end_comment

begin_function_decl
name|int
name|dns_get_mx_list
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mx_hostentry
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* net.c */
end_comment

begin_function_decl
name|char
modifier|*
name|ssl_errstr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_remote
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|send_remote_command
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nonnull__
parameter_list|(
function_decl|2
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|__format__
argument_list|(
name|__printf__
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|deliver_remote
parameter_list|(
name|struct
name|qitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* base64.c */
end_comment

begin_function_decl
name|int
name|base64_encode
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|base64_decode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dma.c */
end_comment

begin_define
define|#
directive|define
name|EXPAND_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|EXPAND_WILDCARD
value|2
end_define

begin_function_decl
name|int
name|add_recp
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_queue
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* spool.c */
end_comment

begin_function_decl
name|int
name|newspoolf
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linkspool
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|load_queue
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delqueue
parameter_list|(
name|struct
name|qitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acquirespool
parameter_list|(
name|struct
name|qitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dropspool
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|,
name|struct
name|qitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flushqueue_since
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flushqueue_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* local.c */
end_comment

begin_function_decl
name|int
name|deliver_local
parameter_list|(
name|struct
name|qitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mail.c */
end_comment

begin_function_decl
name|void
name|bounce
parameter_list|(
name|struct
name|qitem
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readmail
parameter_list|(
name|struct
name|queue
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* util.c */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|hostname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setlogident
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|errlog
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|errlogx
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|set_username
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deltmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_timeout
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_locked
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rfc822date
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strprefixcmp
parameter_list|(
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
name|void
name|init_random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

