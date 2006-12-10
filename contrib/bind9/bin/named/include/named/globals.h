begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: globals.h,v 1.59.68.7 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_GLOBALS_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_GLOBALS_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_include
include|#
directive|include
file|<dns/zone.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NS_MAIN
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|v
parameter_list|)
value|= (v)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|v
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|EXTERN
name|isc_mem_t
modifier|*
name|ns_g_mctx
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|ns_g_cpus
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTERN
name|isc_taskmgr_t
modifier|*
name|ns_g_taskmgr
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|dns_dispatchmgr_t
modifier|*
name|ns_g_dispatchmgr
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_entropy_t
modifier|*
name|ns_g_entropy
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_entropy_t
modifier|*
name|ns_g_fallbackentropy
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXXRTH  We're going to want multiple timer managers eventually.  One  *         for really short timers, another for client timers, and one  *         for zone timers.  */
end_comment

begin_function_decl
name|EXTERN
name|isc_timermgr_t
modifier|*
name|ns_g_timermgr
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_socketmgr_t
modifier|*
name|ns_g_socketmgr
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|cfg_parser_t
modifier|*
name|ns_g_parser
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_version
name|INIT
parameter_list|(
name|VERSION
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|in_port_t
name|ns_g_port
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|in_port_t
name|lwresd_g_listenport
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTERN
name|ns_server_t
modifier|*
name|ns_g_server
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|ns_g_lwresdonly
name|INIT
parameter_list|(
name|ISC_FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Logging.  */
end_comment

begin_function_decl
name|EXTERN
name|isc_log_t
modifier|*
name|ns_g_lctx
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_logcategory_t
modifier|*
name|ns_g_categories
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_logmodule_t
modifier|*
name|ns_g_modules
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|ns_g_debuglevel
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Current configuration information.  */
end_comment

begin_function_decl
name|EXTERN
name|cfg_obj_t
modifier|*
name|ns_g_config
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
specifier|const
name|cfg_obj_t
modifier|*
name|ns_g_defaults
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_conffile
name|INIT
argument_list|(
name|NS_SYSCONFDIR
literal|"/named.conf"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_keyfile
name|INIT
argument_list|(
name|NS_SYSCONFDIR
literal|"/rndc.key"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|lwresd_g_conffile
name|INIT
argument_list|(
name|NS_SYSCONFDIR
literal|"/lwresd.conf"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|lwresd_g_resolvconffile
name|INIT
argument_list|(
literal|"/etc"
literal|"/resolv.conf"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|ns_g_conffileset
name|INIT
parameter_list|(
name|ISC_FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|lwresd_g_useresolvconf
name|INIT
parameter_list|(
name|ISC_FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|isc_uint16_t
name|ns_g_udpsize
name|INIT
argument_list|(
literal|4096
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initial resource limits.  */
end_comment

begin_decl_stmt
name|EXTERN
name|isc_resourcevalue_t
name|ns_g_initstacksize
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|isc_resourcevalue_t
name|ns_g_initdatasize
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|isc_resourcevalue_t
name|ns_g_initcoresize
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|isc_resourcevalue_t
name|ns_g_initopenfiles
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Misc.  */
end_comment

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|ns_g_coreok
name|INIT
parameter_list|(
name|ISC_TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_chrootdir
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|ns_g_foreground
name|INIT
parameter_list|(
name|ISC_FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXTERN
name|isc_boolean_t
name|ns_g_logstderr
name|INIT
parameter_list|(
name|ISC_FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_defaultpidfile
name|INIT
argument_list|(
name|NS_LOCALSTATEDIR
literal|"/run/named.pid"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
specifier|const
name|char
modifier|*
name|lwresd_g_defaultpidfile
name|INIT
argument_list|(
name|NS_LOCALSTATEDIR
literal|"/run/lwresd.pid"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXTERN
specifier|const
name|char
modifier|*
name|ns_g_username
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXTERN
name|int
name|ns_g_listen
name|INIT
argument_list|(
literal|3
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_GLOBALS_H */
end_comment

end_unit

