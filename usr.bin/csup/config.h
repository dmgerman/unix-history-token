begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2006, Maxime Henrion<mux@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"fattr.h"
end_include

begin_include
include|#
directive|include
file|"queue.h"
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_comment
comment|/*  * Collection options.  */
end_comment

begin_define
define|#
directive|define
name|CO_BACKUP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CO_DELETE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CO_KEEP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CO_OLD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CO_UNLINKBUSY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CO_NOUPDATE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CO_COMPRESS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CO_USERELSUFFIX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CO_EXACTRCS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CO_CHECKRCS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CO_SKIP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CO_CHECKOUTMODE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CO_NORSYNC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CO_KEEPBADFILES
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CO_EXECUTE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CO_SETOWNER
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CO_SETMODE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CO_SETFLAGS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CO_NORCS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CO_STRICTCHECKRCS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CO_TRUSTSTATUSFILE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CO_DODELETESONLY
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CO_DETAILALLRCSFILES
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CO_MASK
value|0x007fffff
end_define

begin_comment
comment|/* Options that the server is allowed to set. */
end_comment

begin_define
define|#
directive|define
name|CO_SERVMAYSET
value|(CO_SKIP | CO_NORSYNC | CO_NORCS)
end_define

begin_comment
comment|/* Options that the server is allowed to clear. */
end_comment

begin_define
define|#
directive|define
name|CO_SERVMAYCLEAR
value|CO_CHECKRCS
end_define

begin_struct
struct|struct
name|coll
block|{
name|char
modifier|*
name|co_name
decl_stmt|;
name|char
modifier|*
name|co_host
decl_stmt|;
name|char
modifier|*
name|co_base
decl_stmt|;
name|char
modifier|*
name|co_date
decl_stmt|;
name|char
modifier|*
name|co_prefix
decl_stmt|;
name|size_t
name|co_prefixlen
decl_stmt|;
name|char
modifier|*
name|co_release
decl_stmt|;
name|char
modifier|*
name|co_tag
decl_stmt|;
name|char
modifier|*
name|co_cvsroot
decl_stmt|;
name|int
name|co_attrignore
decl_stmt|;
name|struct
name|pattlist
modifier|*
name|co_accepts
decl_stmt|;
name|struct
name|pattlist
modifier|*
name|co_refusals
decl_stmt|;
name|struct
name|globtree
modifier|*
name|co_dirfilter
decl_stmt|;
name|struct
name|globtree
modifier|*
name|co_filefilter
decl_stmt|;
name|struct
name|globtree
modifier|*
name|co_norsync
decl_stmt|;
specifier|const
name|char
modifier|*
name|co_colldir
decl_stmt|;
name|char
modifier|*
name|co_listsuffix
decl_stmt|;
name|time_t
name|co_scantime
decl_stmt|;
comment|/* Set by the detailer thread. */
name|int
name|co_options
decl_stmt|;
name|mode_t
name|co_umask
decl_stmt|;
name|struct
name|keyword
modifier|*
name|co_keyword
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|coll
argument_list|)
name|co_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|coll
argument_list|)
name|colls
expr_stmt|;
name|struct
name|fixups
modifier|*
name|fixups
decl_stmt|;
name|char
modifier|*
name|host
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|laddr
decl_stmt|;
name|socklen_t
name|laddrlen
decl_stmt|;
name|int
name|deletelim
decl_stmt|;
name|int
name|socket
decl_stmt|;
name|struct
name|chan
modifier|*
name|chan0
decl_stmt|;
name|struct
name|chan
modifier|*
name|chan1
decl_stmt|;
name|struct
name|stream
modifier|*
name|server
decl_stmt|;
name|fattr_support_t
name|fasupport
decl_stmt|;
name|int
name|reqauth
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|config
modifier|*
name|config_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|coll
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|config_checkcolls
parameter_list|(
name|struct
name|config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_free
parameter_list|(
name|struct
name|config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|coll
modifier|*
name|coll_new
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|coll_override
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|,
name|struct
name|coll
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|coll_statuspath
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|coll_statussuffix
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|coll_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|coll_free
parameter_list|(
name|struct
name|coll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|coll_setdef
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|coll_setopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CONFIG_H_ */
end_comment

end_unit

