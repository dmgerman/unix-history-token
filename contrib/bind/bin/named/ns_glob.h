begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from ns.h	4.33 (Berkeley) 8/23/90  *	$Id: ns_glob.h,v 8.56 2000/12/02 18:39:25 vixie Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996-2000 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Global variables for the name server.  */
end_comment

begin_comment
comment|/* original argv[] from main() */
end_comment

begin_decl_stmt
name|DECL
name|char
modifier|*
modifier|*
name|saved_argv
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|DECL
name|int
name|debug
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|desired_debug
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* global event context */
end_comment

begin_decl_stmt
name|DECL
name|evContext
name|ev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global resolver context. */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|__res_state
name|res
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of open streams */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|qstream
modifier|*
name|streamq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* often set to the current time */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|timeval
name|tt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of allocated queries */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|qinfo
modifier|*
name|nsqhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* datagram socket for sysquery() and ns_forw(). */
end_comment

begin_decl_stmt
name|DECL
name|int
name|ds
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event ID for reads of "ds". */
end_comment

begin_decl_stmt
name|DECL
name|evFileID
name|ds_evID
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|QRYLOG
end_ifdef

begin_comment
comment|/* is query logging turned on? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|qrylog
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*QRYLOG*/
end_comment

begin_comment
comment|/* port to which we send queries */
end_comment

begin_decl_stmt
name|DECL
name|u_int16_t
name|ns_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Source addr of our internal resolver. */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|sockaddr_in
name|source_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* INITs to<INADDR_ANY, 0>. */
end_comment

begin_comment
comment|/* Used by ns_stats */
end_comment

begin_decl_stmt
name|DECL
name|time_t
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|time_t
name|resettime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next query to retry */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|qinfo
modifier|*
name|retryqp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration file name */
end_comment

begin_decl_stmt
name|DECL
name|char
modifier|*
name|conffile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration file mtime */
end_comment

begin_decl_stmt
name|DECL
name|time_t
name|confmtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default debug output file */
end_comment

begin_decl_stmt
name|DECL
name|char
modifier|*
name|debugfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zone information */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|zoneinfo
modifier|*
name|zones
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of zones allocated */
end_comment

begin_decl_stmt
name|DECL
name|int
name|nzones
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free list of unused zones[] elements. */
end_comment

begin_decl_stmt
name|DECL
name|LIST
argument_list|(
expr|struct
name|zoneinfo
argument_list|)
name|freezones
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of zones that have a reload pending. */
end_comment

begin_decl_stmt
name|DECL
name|LIST
argument_list|(
expr|struct
name|zoneinfo
argument_list|)
name|reloadingzones
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we need a priming */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needs_prime_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is cache being primed */
end_comment

begin_decl_stmt
name|DECL
name|int
name|priming
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptrs to dnames in msg for dn_comp */
end_comment

begin_decl_stmt
name|DECL
name|u_char
modifier|*
name|dnptrs
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end pointer for dnptrs */
end_comment

begin_decl_stmt
name|DECL
name|u_char
modifier|*
modifier|*
name|dnptrs_end
name|INIT
argument_list|(
name|dnptrs
operator|+
sizeof|sizeof
name|dnptrs
operator|/
sizeof|sizeof
argument_list|(
name|u_char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data about all forwarders */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|fwddata
modifier|*
modifier|*
name|fwddata
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many forwarders are there in fwddata? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|fwddata_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of names in addinfo */
end_comment

begin_decl_stmt
name|DECL
name|int
name|addcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of cache file */
end_comment

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|cache_file
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|LogSignature
name|INIT
argument_list|(
literal|";BIND LOG V8\n"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|DumpSignature
name|INIT
argument_list|(
literal|";BIND DUMP V8\n"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|DumpSuffix
name|INIT
argument_list|(
literal|".dumptmp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|DECL
specifier|const
name|char
name|sendtoStr
index|[]
name|INIT
argument_list|(
literal|"sendto"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
name|tcpsendStr
index|[]
name|INIT
argument_list|(
literal|"tcp_send"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in version.c, can't use DECL/INIT */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Version
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ShortVersion
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If getnum() has an error, here will be the result. */
end_comment

begin_decl_stmt
name|DECL
name|int
name|getnum_error
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|context
block|{
name|domain_ctx
block|,
name|owner_ctx
block|,
name|mailname_ctx
block|,
name|hostname_ctx
block|}
enum|;
end_enum

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|context_strings
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
init|=
block|{
literal|"domain"
block|,
literal|"owner"
block|,
literal|"mail"
block|,
literal|"host"
block|,
name|NULL
block|}
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|transport_strings
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
init|=
block|{
literal|"primary"
block|,
literal|"secondary"
block|,
literal|"response"
block|,
name|NULL
block|}
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
modifier|*
name|severity_strings
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
init|=
block|{
literal|"ignore"
block|,
literal|"warn"
block|,
literal|"fail"
block|,
literal|"not_set"
block|,
name|NULL
block|}
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|struct
name|in_addr
name|inaddr_any
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Inits to 0.0.0.0 */
end_comment

begin_function_decl
name|DECL
name|options
name|server_options
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|server_info
name|nameserver_info
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|key_info_list
name|secretkey_info
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|ip_match_list
name|bogus_nameservers
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|DECL
name|log_context
name|log_ctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|log_ctx_valid
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DECL
name|log_channel
name|syslog_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|log_channel
name|debug_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|log_channel
name|stderr_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|log_channel
name|eventlib_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|log_channel
name|packet_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|log_channel
name|null_channel
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|ip_match_list
name|local_addresses
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|ip_match_list
name|local_networks
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* are we running in no-fork mode? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|foreground
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECL
specifier|const
expr|struct
name|ns_sym
name|logging_constants
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
operator|=
block|{
block|{
name|log_info
block|,
literal|"info"
block|}
block|,
block|{
name|log_notice
block|,
literal|"notice"
block|}
block|,
block|{
name|log_warning
block|,
literal|"warning"
block|}
block|,
block|{
name|log_error
block|,
literal|"error"
block|}
block|,
block|{
name|log_critical
block|,
literal|"critical"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
endif|#
directive|endif
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECL
specifier|const
expr|struct
name|ns_sym
name|syslog_constants
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
operator|=
block|{
block|{
name|LOG_KERN
block|,
literal|"kern"
block|}
block|,
block|{
name|LOG_USER
block|,
literal|"user"
block|}
block|,
block|{
name|LOG_MAIL
block|,
literal|"mail"
block|}
block|,
block|{
name|LOG_DAEMON
block|,
literal|"daemon"
block|}
block|,
block|{
name|LOG_AUTH
block|,
literal|"auth"
block|}
block|,
block|{
name|LOG_SYSLOG
block|,
literal|"syslog"
block|}
block|,
block|{
name|LOG_LPR
block|,
literal|"lpr"
block|}
block|,
ifdef|#
directive|ifdef
name|LOG_NEWS
block|{
name|LOG_NEWS
block|,
literal|"news"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOG_UUCP
block|{
name|LOG_UUCP
block|,
literal|"uucp"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOG_CRON
block|{
name|LOG_CRON
block|,
literal|"cron"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOG_AUTHPRIV
block|{
name|LOG_AUTHPRIV
block|,
literal|"authpriv"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOG_FTP
block|{
name|LOG_FTP
block|,
literal|"ftp"
block|}
block|,
endif|#
directive|endif
block|{
name|LOG_LOCAL0
block|,
literal|"local0"
block|}
block|,
block|{
name|LOG_LOCAL1
block|,
literal|"local1"
block|}
block|,
block|{
name|LOG_LOCAL2
block|,
literal|"local2"
block|}
block|,
block|{
name|LOG_LOCAL3
block|,
literal|"local3"
block|}
block|,
block|{
name|LOG_LOCAL4
block|,
literal|"local4"
block|}
block|,
block|{
name|LOG_LOCAL5
block|,
literal|"local5"
block|}
block|,
block|{
name|LOG_LOCAL6
block|,
literal|"local6"
block|}
block|,
block|{
name|LOG_LOCAL7
block|,
literal|"local7"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
endif|#
directive|endif
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECL
specifier|const
expr|struct
name|ns_sym
name|category_constants
index|[]
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
operator|=
block|{
block|{
name|ns_log_default
block|,
literal|"default"
block|}
block|,
block|{
name|ns_log_config
block|,
literal|"config"
block|}
block|,
block|{
name|ns_log_parser
block|,
literal|"parser"
block|}
block|,
block|{
name|ns_log_queries
block|,
literal|"queries"
block|}
block|,
block|{
name|ns_log_lame_servers
block|,
literal|"lame-servers"
block|}
block|,
block|{
name|ns_log_statistics
block|,
literal|"statistics"
block|}
block|,
block|{
name|ns_log_panic
block|,
literal|"panic"
block|}
block|,
block|{
name|ns_log_update
block|,
literal|"update"
block|}
block|,
block|{
name|ns_log_ncache
block|,
literal|"ncache"
block|}
block|,
block|{
name|ns_log_xfer_in
block|,
literal|"xfer-in"
block|}
block|,
block|{
name|ns_log_xfer_out
block|,
literal|"xfer-out"
block|}
block|,
block|{
name|ns_log_db
block|,
literal|"db"
block|}
block|,
block|{
name|ns_log_eventlib
block|,
literal|"eventlib"
block|}
block|,
block|{
name|ns_log_packet
block|,
literal|"packet"
block|}
block|,
ifdef|#
directive|ifdef
name|BIND_NOTIFY
block|{
name|ns_log_notify
block|,
literal|"notify"
block|}
block|,
endif|#
directive|endif
block|{
name|ns_log_cname
block|,
literal|"cname"
block|}
block|,
block|{
name|ns_log_security
block|,
literal|"security"
block|}
block|,
block|{
name|ns_log_os
block|,
literal|"os"
block|}
block|,
block|{
name|ns_log_insist
block|,
literal|"insist"
block|}
block|,
block|{
name|ns_log_maint
block|,
literal|"maintenance"
block|}
block|,
block|{
name|ns_log_load
block|,
literal|"load"
block|}
block|,
block|{
name|ns_log_resp_checks
block|,
literal|"response-checks"
block|}
block|,
block|{
name|ns_log_control
block|,
literal|"control"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
endif|#
directive|endif
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
name|panic_msg_no_options
index|[]
name|INIT
argument_list|(
literal|"no server_options in NS_OPTION_P"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
name|panic_msg_insist_failed
index|[]
name|INIT
argument_list|(
literal|"%s:%d: insist '%s' failed: %s"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
specifier|const
name|char
name|panic_msg_bad_which
index|[]
name|INIT
argument_list|(
literal|"%s:%d: INCRSTATS(%s): bad \"which\""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|u_long
name|globalStats
index|[
name|nssLast
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|evTimerID
name|clean_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|evTimerID
name|interface_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|evTimerID
name|stats_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|evTimerID
name|heartbeat_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|active_timers
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|uid_t
name|user_id
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DECL
name|char
modifier|*
name|user_name
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|DECL
name|gid_t
name|group_id
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DECL
name|char
modifier|*
name|group_name
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DECL
name|char
modifier|*
name|chroot_dir
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|DECL
name|int
name|loading
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|xfers_running
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|xfers_deferred
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|int
name|qserials_running
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

