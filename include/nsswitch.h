begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nsswitch.h,v 1.6 1999/01/26 01:04:07 lukem Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Luke Mewburn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NSSWITCH_H
end_ifndef

begin_define
define|#
directive|define
name|_NSSWITCH_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NS_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NS_CONF
value|"/etc/nsswitch.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NS_CONTINUE
value|0
end_define

begin_define
define|#
directive|define
name|NS_RETURN
value|1
end_define

begin_define
define|#
directive|define
name|NS_SUCCESS
value|(1<<0)
end_define

begin_comment
comment|/* entry was found */
end_comment

begin_define
define|#
directive|define
name|NS_UNAVAIL
value|(1<<1)
end_define

begin_comment
comment|/* source not responding, or corrupt */
end_comment

begin_define
define|#
directive|define
name|NS_NOTFOUND
value|(1<<2)
end_define

begin_comment
comment|/* source responded 'no such entry' */
end_comment

begin_define
define|#
directive|define
name|NS_TRYAGAIN
value|(1<<3)
end_define

begin_comment
comment|/* source busy, may respond to retrys */
end_comment

begin_define
define|#
directive|define
name|NS_STATUSMASK
value|0x000000ff
end_define

begin_comment
comment|/* bitmask to get the status flags */
end_comment

begin_comment
comment|/*  * currently implemented sources  */
end_comment

begin_define
define|#
directive|define
name|NSSRC_FILES
value|"files"
end_define

begin_comment
comment|/* local files */
end_comment

begin_define
define|#
directive|define
name|NSSRC_DNS
value|"dns"
end_define

begin_comment
comment|/* DNS; IN for hosts, HS for others */
end_comment

begin_define
define|#
directive|define
name|NSSRC_NIS
value|"nis"
end_define

begin_comment
comment|/* YP/NIS */
end_comment

begin_define
define|#
directive|define
name|NSSRC_COMPAT
value|"compat"
end_define

begin_comment
comment|/* passwd,group in YP compat mode */
end_comment

begin_comment
comment|/*  * currently implemented databases  */
end_comment

begin_define
define|#
directive|define
name|NSDB_HOSTS
value|"hosts"
end_define

begin_define
define|#
directive|define
name|NSDB_GROUP
value|"group"
end_define

begin_define
define|#
directive|define
name|NSDB_GROUP_COMPAT
value|"group_compat"
end_define

begin_define
define|#
directive|define
name|NSDB_NETGROUP
value|"netgroup"
end_define

begin_define
define|#
directive|define
name|NSDB_NETWORKS
value|"networks"
end_define

begin_define
define|#
directive|define
name|NSDB_PASSWD
value|"passwd"
end_define

begin_define
define|#
directive|define
name|NSDB_PASSWD_COMPAT
value|"passwd_compat"
end_define

begin_define
define|#
directive|define
name|NSDB_SHELLS
value|"shells"
end_define

begin_comment
comment|/*  * suggested databases to implement  */
end_comment

begin_define
define|#
directive|define
name|NSDB_ALIASES
value|"aliases"
end_define

begin_define
define|#
directive|define
name|NSDB_AUTH
value|"auth"
end_define

begin_define
define|#
directive|define
name|NSDB_AUTOMOUNT
value|"automount"
end_define

begin_define
define|#
directive|define
name|NSDB_BOOTPARAMS
value|"bootparams"
end_define

begin_define
define|#
directive|define
name|NSDB_ETHERS
value|"ethers"
end_define

begin_define
define|#
directive|define
name|NSDB_EXPORTS
value|"exports"
end_define

begin_define
define|#
directive|define
name|NSDB_NETMASKS
value|"netmasks"
end_define

begin_define
define|#
directive|define
name|NSDB_PHONES
value|"phones"
end_define

begin_define
define|#
directive|define
name|NSDB_PRINTCAP
value|"printcap"
end_define

begin_define
define|#
directive|define
name|NSDB_PROTOCOLS
value|"protocols"
end_define

begin_define
define|#
directive|define
name|NSDB_REMOTE
value|"remote"
end_define

begin_define
define|#
directive|define
name|NSDB_RPC
value|"rpc"
end_define

begin_define
define|#
directive|define
name|NSDB_SENDMAILVARS
value|"sendmailvars"
end_define

begin_define
define|#
directive|define
name|NSDB_SERVICES
value|"services"
end_define

begin_define
define|#
directive|define
name|NSDB_TERMCAP
value|"termcap"
end_define

begin_define
define|#
directive|define
name|NSDB_TTYS
value|"ttys"
end_define

begin_comment
comment|/*  * ns_dtab - `nsswitch dispatch table'  * contains an entry for each source and the appropriate function to call  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|src
decl_stmt|;
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|retval
parameter_list|,
name|void
modifier|*
name|cb_data
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
name|void
modifier|*
name|cb_data
decl_stmt|;
block|}
name|ns_dtab
typedef|;
end_typedef

begin_comment
comment|/*  * macros to help build an ns_dtab[]  */
end_comment

begin_define
define|#
directive|define
name|NS_FILES_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
value|{ NSSRC_FILES,	F,	C },
end_define

begin_define
define|#
directive|define
name|NS_COMPAT_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
value|{ NSSRC_COMPAT,	F,	C },
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HESIOD
end_ifdef

begin_define
define|#
directive|define
name|NS_DNS_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
value|{ NSSRC_DNS,	F,	C },
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NS_DNS_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|YP
end_ifdef

begin_define
define|#
directive|define
name|NS_NIS_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
value|{ NSSRC_NIS,	F,	C },
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NS_NIS_CB
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ns_src - `nsswitch source'  * used by the nsparser routines to store a mapping between a source  * and its dispatch control flags for a given database.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
block|}
name|ns_src
typedef|;
end_typedef

begin_comment
comment|/*  * default sourcelist (if nsswitch.conf is missing, corrupt,  * or the requested database doesn't have an entry.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|ns_src
name|__nsdefaultsrc
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_NS_PRIVATE
end_ifdef

begin_comment
comment|/*  * private data structures for back-end nsswitch implementation  */
end_comment

begin_comment
comment|/*  * ns_dbt - `nsswitch database thang'  * for each database in /etc/nsswitch.conf there is a ns_dbt, with its  * name and a list of ns_src's containing the source information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of database */
name|ns_src
modifier|*
name|srclist
decl_stmt|;
comment|/* list of sources */
name|int
name|srclistsize
decl_stmt|;
comment|/* size of srclist */
block|}
name|ns_dbt
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NS_PRIVATE */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|nsdispatch
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|ns_dtab
index|[]
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
name|ns_src
index|[]
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_NS_PRIVATE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|_nsdbtaddsrc
parameter_list|(
name|ns_dbt
modifier|*
parameter_list|,
specifier|const
name|ns_src
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nsdbtdump
parameter_list|(
specifier|const
name|ns_dbt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|ns_dbt
modifier|*
name|_nsdbtget
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nsdbtput
parameter_list|(
specifier|const
name|ns_dbt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_nsyyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_nsyylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|_nsyylineno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NS_PRIVATE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NSSWITCH_H */
end_comment

end_unit

