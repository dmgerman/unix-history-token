begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from ns.h	4.33 (Berkeley) 8/23/90  *	$Id: ns_defs.h,v 8.38 1998/03/17 03:22:27 halley Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986  *    The Regents of the University of California.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Portions Copyright (c) 1996, 1997 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Global definitions for the name server.  */
end_comment

begin_comment
comment|/*  * Effort has been expended here to make all structure members 32 bits or  * larger land on 32-bit boundaries; smaller structure members have been  * deliberately shuffled and smaller integer sizes chosen where possible  * to make sure this happens.  This is all meant to avoid structure member  * padding which can cost a _lot_ of memory when you have hundreds of   * thousands of entries in your cache.  */
end_comment

begin_comment
comment|/*  * Timeout time should be around 1 minute or so.  Using the  * the current simplistic backoff strategy, the sequence  * retrys after 4, 8, and 16 seconds.  With 3 servers, this  * dies out in a little more than a minute.  * (sequence RETRYBASE, 2*RETRYBASE, 4*RETRYBASE... for MAXRETRY)  */
end_comment

begin_define
define|#
directive|define
name|MINROOTS
value|2
end_define

begin_comment
comment|/* min number of root hints */
end_comment

begin_define
define|#
directive|define
name|NSMAX
value|16
end_define

begin_comment
comment|/* max number of NS addrs to try ([0..255]) */
end_comment

begin_define
define|#
directive|define
name|RETRYBASE
value|4
end_define

begin_comment
comment|/* base time between retries */
end_comment

begin_define
define|#
directive|define
name|MAXCLASS
value|255
end_define

begin_comment
comment|/* XXX - may belong elsewhere */
end_comment

begin_define
define|#
directive|define
name|MAXRETRY
value|3
end_define

begin_comment
comment|/* max number of retries per addr */
end_comment

begin_define
define|#
directive|define
name|MAXCNAMES
value|8
end_define

begin_comment
comment|/* max # of CNAMES tried per addr */
end_comment

begin_define
define|#
directive|define
name|MAXQUERIES
value|20
end_define

begin_comment
comment|/* max # of queries to be made */
end_comment

begin_define
define|#
directive|define
name|MAXQSERIAL
value|4
end_define

begin_comment
comment|/* max # of outstanding QSERIAL's */
end_comment

begin_comment
comment|/* (prevent "recursive" loops) */
end_comment

begin_define
define|#
directive|define
name|INIT_REFRESH
value|600
end_define

begin_comment
comment|/* retry time for initial secondary */
end_comment

begin_comment
comment|/* contact (10 minutes) */
end_comment

begin_define
define|#
directive|define
name|MIN_REFRESH
value|2
end_define

begin_comment
comment|/* never refresh more frequently than once */
end_comment

begin_comment
comment|/* every MIN_REFRESH seconds */
end_comment

begin_define
define|#
directive|define
name|MIN_RETRY
value|1
end_define

begin_comment
comment|/* never retry more frequently than once */
end_comment

begin_comment
comment|/* every MIN_RETRY seconds */
end_comment

begin_define
define|#
directive|define
name|NADDRECS
value|20
end_define

begin_comment
comment|/* max addt'l rr's per resp */
end_comment

begin_define
define|#
directive|define
name|XFER_TIMER
value|120
end_define

begin_comment
comment|/* named-xfer's connect timeout */
end_comment

begin_define
define|#
directive|define
name|MAX_XFER_TIME
value|60*60*2
end_define

begin_comment
comment|/* default max seconds for an xfer */
end_comment

begin_define
define|#
directive|define
name|XFER_TIME_FUDGE
value|10
end_define

begin_comment
comment|/* MAX_XFER_TIME fudge */
end_comment

begin_define
define|#
directive|define
name|MAX_XFERS_RUNNING
value|20
end_define

begin_comment
comment|/* max value of transfers_in */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_XFERS_RUNNING
value|10
end_define

begin_comment
comment|/* default value of transfers_in */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_XFERS_PER_NS
value|2
end_define

begin_comment
comment|/* default # of xfers per peer nameserver */
end_comment

begin_define
define|#
directive|define
name|XFER_BUFSIZE
value|(16*1024)
end_define

begin_comment
comment|/* arbitrary but bigger than most MTU's */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|0.7
end_define

begin_comment
comment|/* How much to preserve of old response time */
end_comment

begin_define
define|#
directive|define
name|BETA
value|1.2
end_define

begin_comment
comment|/* How much to penalize response time on failure */
end_comment

begin_define
define|#
directive|define
name|GAMMA
value|0.98
end_define

begin_comment
comment|/* How much to decay unused response times */
end_comment

begin_comment
comment|/* What maintainance operations need to be performed sometime soon? */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_RELOAD
value|0x0001
end_define

begin_comment
comment|/* db_reload() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_MAINT
value|0x0002
end_define

begin_comment
comment|/* ns_maint() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_ENDXFER
value|0x0004
end_define

begin_comment
comment|/* endxfer() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_ZONELOAD
value|0x0008
end_define

begin_comment
comment|/* loadxfer() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_DUMP
value|0x0010
end_define

begin_comment
comment|/* doadump() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_STATSDUMP
value|0x0020
end_define

begin_comment
comment|/* ns_stats() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_EXIT
value|0x0040
end_define

begin_comment
comment|/* exit() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_QRYLOG
value|0x0080
end_define

begin_comment
comment|/* toggle_qrylog() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_DEBUG
value|0x0100
end_define

begin_comment
comment|/* use_desired_debug() needed. */
end_comment

begin_define
define|#
directive|define
name|MAIN_NEED_NOTIFY
value|0x0200
end_define

begin_comment
comment|/* do_notify_after_load() needed */
end_comment

begin_comment
comment|/* What global options are set? */
end_comment

begin_define
define|#
directive|define
name|OPTION_NORECURSE
value|0x0001
end_define

begin_comment
comment|/* Don't recurse even if asked. */
end_comment

begin_define
define|#
directive|define
name|OPTION_NOFETCHGLUE
value|0x0002
end_define

begin_comment
comment|/* Don't fetch missing glue. */
end_comment

begin_define
define|#
directive|define
name|OPTION_FORWARD_ONLY
value|0x0004
end_define

begin_comment
comment|/* Don't use NS RR's, just forward. */
end_comment

begin_define
define|#
directive|define
name|OPTION_FAKE_IQUERY
value|0x0008
end_define

begin_comment
comment|/* Fake up bogus response to IQUERY. */
end_comment

begin_define
define|#
directive|define
name|OPTION_NONOTIFY
value|0x0010
end_define

begin_comment
comment|/* Turn off notify */
end_comment

begin_define
define|#
directive|define
name|OPTION_NONAUTH_NXDOMAIN
value|0x0020
end_define

begin_comment
comment|/* Generate non-auth NXDOMAINs? */
end_comment

begin_define
define|#
directive|define
name|OPTION_MULTIPLE_CNAMES
value|0x0040
end_define

begin_comment
comment|/* Allow a name to have multiple 					 * CNAME RRs */
end_comment

begin_define
define|#
directive|define
name|OPTION_HOSTSTATS
value|0x0080
end_define

begin_comment
comment|/* Maintain per-host statistics? */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEALLOC_ON_EXIT
value|0x0100
end_define

begin_comment
comment|/* Deallocate everything on exit? */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_OPTION_FLAGS
value|(OPTION_HOSTSTATS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_define
define|#
directive|define
name|SOAINCRINTVL
value|300
end_define

begin_comment
comment|/* default value for the time after which 			  * the zone serial number must be incremented 			  * after a successful update has occurred */
end_comment

begin_define
define|#
directive|define
name|DUMPINTVL
value|3600
end_define

begin_comment
comment|/* default interval at which to dump changed zones 			  * randomized, not exact */
end_comment

begin_define
define|#
directive|define
name|DEFERUPDCNT
value|100
end_define

begin_comment
comment|/* default number of updates that can happen 				 * before the zone serial number will be 				 * incremented */
end_comment

begin_define
define|#
directive|define
name|UPDATE_TIMER
value|XFER_TIMER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND_UPDATE */
end_comment

begin_define
define|#
directive|define
name|USE_MINIMUM
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MAXIMUM_TTL
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|CLEAN_TIMER
value|0x01
end_define

begin_define
define|#
directive|define
name|INTERFACE_TIMER
value|0x02
end_define

begin_define
define|#
directive|define
name|STATS_TIMER
value|0x04
end_define

begin_comment
comment|/* IP address accessor, network byte order. */
end_comment

begin_define
define|#
directive|define
name|ina_ulong
parameter_list|(
name|ina
parameter_list|)
value|(ina.s_addr)
end_define

begin_comment
comment|/* IP address accessor, host byte order, read only. */
end_comment

begin_define
define|#
directive|define
name|ina_hlong
parameter_list|(
name|ina
parameter_list|)
value|ntohl(ina.s_addr)
end_define

begin_comment
comment|/* IP address equality. */
end_comment

begin_comment
comment|/* XXX: assumes that network byte order won't affect equality. */
end_comment

begin_define
define|#
directive|define
name|ina_equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ina_ulong(a) == ina_ulong(b))
end_define

begin_comment
comment|/* IP address equality with a mask. */
end_comment

begin_define
define|#
directive|define
name|ina_onnet
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|((ina_ulong(h)& ina_ulong(m)) == ina_ulong(n))
end_define

begin_comment
comment|/* Sequence space arithmetic. */
end_comment

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int32_t)((a)-(b))> 0)
end_define

begin_define
define|#
directive|define
name|NS_OPTION_P
parameter_list|(
name|option
parameter_list|)
value|((server_options == NULL) ? \ 		(panic(panic_msg_no_options, NULL), 0) : \ 		((server_options->flags& option) != 0))
end_define

begin_define
define|#
directive|define
name|NS_INCRSTAT
parameter_list|(
name|addr
parameter_list|,
name|which
parameter_list|)
define|\
value|do { \ 		if ((int)which>= (int)nssLast) \ 			ns_panic(ns_log_insist, 1, panic_msg_bad_which, \ 				 __FILE__, __LINE__, #which); \ 		else { \ 			if (NS_OPTION_P(OPTION_HOSTSTATS)) { \ 				struct nameser *ns = \ 					nameserFind(addr, NS_F_INSERT); \ 				if (ns != NULL) \ 					ns->stats[(int)which]++; \ 			} \ 			globalStats[(int)which]++; \ 		} \ 	} while (0)
end_define

begin_enum
enum|enum
name|severity
block|{
name|ignore
block|,
name|warn
block|,
name|fail
block|,
name|not_set
block|}
enum|;
end_enum

begin_enum
enum|enum
name|znotify
block|{
name|znotify_use_default
init|=
literal|0
block|,
name|znotify_yes
block|,
name|znotify_no
block|}
enum|;
end_enum

begin_enum
enum|enum
name|axfr_format
block|{
name|axfr_use_default
init|=
literal|0
block|,
name|axfr_one_answer
block|,
name|axfr_many_answers
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ip_match_direct
block|{
name|struct
name|in_addr
name|address
decl_stmt|;
name|struct
name|in_addr
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ip_match_indirect
block|{
name|struct
name|ip_match_list
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|ip_match_pattern
block|,
name|ip_match_indirect
block|,
name|ip_match_localhost
block|,
name|ip_match_localnets
block|}
name|ip_match_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ip_match_element
block|{
name|ip_match_type
name|type
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
union|union
block|{
name|struct
name|ip_match_direct
name|direct
decl_stmt|;
name|struct
name|ip_match_indirect
name|indirect
decl_stmt|;
block|}
name|u
union|;
name|struct
name|ip_match_element
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|ip_match_element
typedef|;
end_typedef

begin_comment
comment|/* Flags for ip_match_element */
end_comment

begin_define
define|#
directive|define
name|IP_MATCH_NEGATE
value|0x01
end_define

begin_comment
comment|/* match means deny access */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ip_match_list
block|{
name|ip_match_element
name|first
decl_stmt|;
name|ip_match_element
name|last
decl_stmt|;
block|}
typedef|*
name|ip_match_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ztimer_info
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|class
decl_stmt|;
name|int
name|type
decl_stmt|;
block|}
typedef|*
name|ztimer_info
typedef|;
end_typedef

begin_comment
comment|/* these fields are ordered to maintain word-alignment;  * be careful about changing them.  */
end_comment

begin_struct
struct|struct
name|zoneinfo
block|{
name|char
modifier|*
name|z_origin
decl_stmt|;
comment|/* root domain name of zone */
name|time_t
name|z_time
decl_stmt|;
comment|/* time for next refresh */
name|time_t
name|z_lastupdate
decl_stmt|;
comment|/* time of last soa serial increment */
name|u_int32_t
name|z_refresh
decl_stmt|;
comment|/* refresh interval */
name|u_int32_t
name|z_retry
decl_stmt|;
comment|/* refresh retry interval */
name|u_int32_t
name|z_expire
decl_stmt|;
comment|/* expiration time for cached info */
name|u_int32_t
name|z_minimum
decl_stmt|;
comment|/* minimum TTL value */
name|u_int32_t
name|z_serial
decl_stmt|;
comment|/* changes if zone modified */
name|char
modifier|*
name|z_source
decl_stmt|;
comment|/* source location of data */
name|time_t
name|z_ftime
decl_stmt|;
comment|/* modification time of source file */
name|struct
name|in_addr
name|z_axfr_src
decl_stmt|;
comment|/* bind() the axfr socket to this */
name|struct
name|in_addr
name|z_xaddr
decl_stmt|;
comment|/* override server for next xfer */
name|struct
name|in_addr
name|z_addr
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* list of master servers for zone */
name|u_char
name|z_addrcnt
decl_stmt|;
comment|/* number of entries in z_addr[] */
name|u_char
name|z_type
decl_stmt|;
comment|/* type of zone; see below */
name|u_int16_t
name|z_flags
decl_stmt|;
comment|/* state bits; see below */
name|pid_t
name|z_xferpid
decl_stmt|;
comment|/* xfer child pid */
name|int
name|z_class
decl_stmt|;
comment|/* class of zone */
name|int
name|z_numxfrs
decl_stmt|;
comment|/* Ref count of concurrent xfrs. */
name|enum
name|severity
name|z_checknames
decl_stmt|;
comment|/* How to handle non-RFC-compliant names */
ifdef|#
directive|ifdef
name|BIND_UPDATE
name|time_t
name|z_dumptime
decl_stmt|;
comment|/* randomized time for next zone dump 					 * if Z_NEED_DUMP is set */
name|u_int32_t
name|z_dumpintvl
decl_stmt|;
comment|/* time interval between zone dumps */
name|time_t
name|z_soaincrintvl
decl_stmt|;
comment|/* interval for updating soa serial */
name|time_t
name|z_soaincrtime
decl_stmt|;
comment|/* time for soa increment */
name|u_int32_t
name|z_deferupdcnt
decl_stmt|;
comment|/* max number of updates before SOA 					 * serial number incremented */
name|u_int32_t
name|z_updatecnt
decl_stmt|;
comment|/* number of update requests processed 					 * since the last SOA serial update */
name|char
modifier|*
name|z_updatelog
decl_stmt|;
comment|/* log file for updates */
endif|#
directive|endif
name|ip_match_list
name|z_update_acl
decl_stmt|;
comment|/* list of who can issue dynamic 					   updates */
name|ip_match_list
name|z_query_acl
decl_stmt|;
comment|/* sites we'll answer questions for */
name|ip_match_list
name|z_transfer_acl
decl_stmt|;
comment|/* sites that may get a zone transfer 					   from us */
name|long
name|z_max_transfer_time_in
decl_stmt|;
comment|/* max num seconds for AXFR */
name|enum
name|znotify
name|z_notify
decl_stmt|;
comment|/* Notify mode */
name|struct
name|in_addr
name|z_also_notify
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* More nameservers to notify */
name|int
name|z_notify_count
decl_stmt|;
name|evTimerID
name|z_timer
decl_stmt|;
comment|/* maintenance timer */
name|ztimer_info
name|z_timerinfo
decl_stmt|;
comment|/* UAP associated with timer */
name|time_t
name|z_nextmaint
decl_stmt|;
comment|/* time of next maintenance */
block|}
struct|;
end_struct

begin_comment
comment|/* zone types (z_type) */
end_comment

begin_enum
enum|enum
name|zonetype
block|{
name|z_nil
block|,
name|z_master
block|,
name|z_slave
block|,
name|z_hint
block|,
name|z_stub
block|,
name|z_any
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|Z_NIL
value|z_nil
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_MASTER
value|z_master
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_PRIMARY
value|z_master
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_SLAVE
value|z_slave
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_SECONDARY
value|z_slave
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_HINT
value|z_hint
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_CACHE
value|z_hint
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_STUB
value|z_stub
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|Z_ANY
value|z_any
end_define

begin_comment
comment|/* XXX*2 */
end_comment

begin_comment
comment|/* zone state bits (16 bits) */
end_comment

begin_define
define|#
directive|define
name|Z_AUTH
value|0x0001
end_define

begin_comment
comment|/* zone is authoritative */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_XFER
value|0x0002
end_define

begin_comment
comment|/* waiting to do xfer */
end_comment

begin_define
define|#
directive|define
name|Z_XFER_RUNNING
value|0x0004
end_define

begin_comment
comment|/* asynch. xfer is running */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_RELOAD
value|0x0008
end_define

begin_comment
comment|/* waiting to do reload */
end_comment

begin_define
define|#
directive|define
name|Z_SYSLOGGED
value|0x0010
end_define

begin_comment
comment|/* have logged timeout */
end_comment

begin_define
define|#
directive|define
name|Z_QSERIAL
value|0x0020
end_define

begin_comment
comment|/* sysquery()'ing for serial number */
end_comment

begin_define
define|#
directive|define
name|Z_FOUND
value|0x0040
end_define

begin_comment
comment|/* found in boot file when reloading */
end_comment

begin_define
define|#
directive|define
name|Z_INCLUDE
value|0x0080
end_define

begin_comment
comment|/* set if include used in file */
end_comment

begin_define
define|#
directive|define
name|Z_DB_BAD
value|0x0100
end_define

begin_comment
comment|/* errors when loading file */
end_comment

begin_define
define|#
directive|define
name|Z_TMP_FILE
value|0x0200
end_define

begin_comment
comment|/* backup file for xfer is temporary */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_define
define|#
directive|define
name|Z_DYNAMIC
value|0x0400
end_define

begin_comment
comment|/* allow dynamic updates */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_DUMP
value|0x0800
end_define

begin_comment
comment|/* zone has changed, needs a dump */
end_comment

begin_define
define|#
directive|define
name|Z_NEED_SOAUPDATE
value|0x1000
end_define

begin_comment
comment|/* soa serial number needs increment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND_UPDATE */
end_comment

begin_define
define|#
directive|define
name|Z_XFER_ABORTED
value|0x2000
end_define

begin_comment
comment|/* zone transfer has been aborted */
end_comment

begin_define
define|#
directive|define
name|Z_XFER_GONE
value|0x4000
end_define

begin_comment
comment|/* zone transfer process is gone */
end_comment

begin_define
define|#
directive|define
name|Z_TIMER_SET
value|0x8000
end_define

begin_comment
comment|/* z_timer contains a valid id */
end_comment

begin_comment
comment|/* named_xfer exit codes */
end_comment

begin_define
define|#
directive|define
name|XFER_UPTODATE
value|0
end_define

begin_comment
comment|/* zone is up-to-date */
end_comment

begin_define
define|#
directive|define
name|XFER_SUCCESS
value|1
end_define

begin_comment
comment|/* performed transfer successfully */
end_comment

begin_define
define|#
directive|define
name|XFER_TIMEOUT
value|2
end_define

begin_comment
comment|/* no server reachable/xfer timeout */
end_comment

begin_define
define|#
directive|define
name|XFER_FAIL
value|3
end_define

begin_comment
comment|/* other failure, has been logged */
end_comment

begin_comment
comment|/* XXX - "struct qserv" is deprecated in favor of "struct nameser" */
end_comment

begin_struct
struct|struct
name|qserv
block|{
name|struct
name|sockaddr_in
name|ns_addr
decl_stmt|;
comment|/* address of NS */
name|struct
name|databuf
modifier|*
name|ns
decl_stmt|;
comment|/* databuf for NS record */
name|struct
name|databuf
modifier|*
name|nsdata
decl_stmt|;
comment|/* databuf for server address */
name|struct
name|timeval
name|stime
decl_stmt|;
comment|/* time first query started */
name|int
name|nretry
decl_stmt|;
comment|/* # of times addr retried */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for recording info on forwarded or generated queries.  */
end_comment

begin_struct
struct|struct
name|qinfo
block|{
name|u_int16_t
name|q_id
decl_stmt|;
comment|/* id of query */
name|u_int16_t
name|q_nsid
decl_stmt|;
comment|/* id of forwarded query */
name|struct
name|sockaddr_in
name|q_from
decl_stmt|;
comment|/* requestor's address */
name|u_char
modifier|*
name|q_msg
decl_stmt|,
comment|/* the message */
modifier|*
name|q_cmsg
decl_stmt|;
comment|/* the cname message */
name|int16_t
name|q_msglen
decl_stmt|,
comment|/* len of message */
name|q_msgsize
decl_stmt|,
comment|/* allocated size of message */
name|q_cmsglen
decl_stmt|,
comment|/* len of cname message */
name|q_cmsgsize
decl_stmt|;
comment|/* allocated size of cname message */
name|int16_t
name|q_dfd
decl_stmt|;
comment|/* UDP file descriptor */
name|struct
name|fwdinfo
modifier|*
name|q_fwd
decl_stmt|;
comment|/* last	forwarder used */
name|time_t
name|q_time
decl_stmt|;
comment|/* time to retry */
name|time_t
name|q_expire
decl_stmt|;
comment|/* time to expire */
name|struct
name|qinfo
modifier|*
name|q_next
decl_stmt|;
comment|/* rexmit list (sorted by time) */
name|struct
name|qinfo
modifier|*
name|q_link
decl_stmt|;
comment|/* storage list (random order) */
name|struct
name|databuf
modifier|*
name|q_usedns
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* databuf for NS that we've tried */
name|struct
name|qserv
name|q_addr
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* addresses of NS's */
ifdef|#
directive|ifdef
name|notyet
name|struct
name|nameser
modifier|*
name|q_ns
index|[
name|NSMAX
index|]
decl_stmt|;
comment|/* name servers */
endif|#
directive|endif
name|u_char
name|q_naddr
decl_stmt|;
comment|/* number of addr's in q_addr */
name|u_char
name|q_curaddr
decl_stmt|;
comment|/* last addr sent to */
name|u_char
name|q_nusedns
decl_stmt|;
comment|/* number of elements in q_usedns[] */
name|u_int8_t
name|q_flags
decl_stmt|;
comment|/* see below */
name|int16_t
name|q_cname
decl_stmt|;
comment|/* # of cnames found */
name|int16_t
name|q_nqueries
decl_stmt|;
comment|/* # of queries required */
name|struct
name|qstream
modifier|*
name|q_stream
decl_stmt|;
comment|/* TCP stream, null if UDP */
name|struct
name|zoneinfo
modifier|*
name|q_zquery
decl_stmt|;
comment|/* Zone query is about (Q_ZSERIAL) */
name|char
modifier|*
name|q_domain
decl_stmt|;
comment|/* domain of most enclosing zone cut */
name|char
modifier|*
name|q_name
decl_stmt|;
comment|/* domain of query */
name|u_int16_t
name|q_class
decl_stmt|;
comment|/* class of query */
name|u_int16_t
name|q_type
decl_stmt|;
comment|/* type of query */
ifdef|#
directive|ifdef
name|BIND_NOTIFY
name|int
name|q_notifyzone
decl_stmt|;
comment|/* zone which needs a sysnotify() 					 * when the reply to this comes in. 					 */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* q_flags bits (8 bits) */
end_comment

begin_define
define|#
directive|define
name|Q_SYSTEM
value|0x01
end_define

begin_comment
comment|/* is a system query */
end_comment

begin_define
define|#
directive|define
name|Q_PRIMING
value|0x02
end_define

begin_comment
comment|/* generated during priming phase */
end_comment

begin_define
define|#
directive|define
name|Q_ZSERIAL
value|0x04
end_define

begin_comment
comment|/* getting zone serial for xfer test */
end_comment

begin_define
define|#
directive|define
name|Q_USEVC
value|0x08
end_define

begin_comment
comment|/* forward using tcp not udp */
end_comment

begin_define
define|#
directive|define
name|Q_NEXTADDR
parameter_list|(
name|qp
parameter_list|,
name|n
parameter_list|)
define|\
value|(((qp)->q_fwd == (struct fwdinfo *)0) ? \&(qp)->q_addr[n].ns_addr :&(qp)->q_fwd->fwdaddr)
end_define

begin_define
define|#
directive|define
name|RETRY_TIMEOUT
value|45
end_define

begin_comment
comment|/*  * Return codes from ns_forw:  */
end_comment

begin_define
define|#
directive|define
name|FW_OK
value|0
end_define

begin_define
define|#
directive|define
name|FW_DUP
value|1
end_define

begin_define
define|#
directive|define
name|FW_NOSERVER
value|2
end_define

begin_define
define|#
directive|define
name|FW_SERVFAIL
value|3
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sq_closure
function_decl|)
parameter_list|(
name|struct
name|qstream
modifier|*
name|qs
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_struct
struct|struct
name|fdlist
block|{
name|int
name|fd
decl_stmt|;
name|struct
name|fdlist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_interface
block|{
name|int
name|dfd
decl_stmt|,
comment|/* Datagram file descriptor */
name|sfd
decl_stmt|;
comment|/* Stream file descriptor. */
name|time_t
name|gen
decl_stmt|;
comment|/* Generation number. */
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* Interface address. */
name|u_int16_t
name|port
decl_stmt|;
comment|/* Interface port. */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* Valid bits for evXXXXID. */
name|evFileID
name|evID_d
decl_stmt|;
comment|/* Datagram read-event. */
name|evConnID
name|evID_s
decl_stmt|;
comment|/* Stream listen-event. */
name|LINK
argument_list|(
argument|struct _interface
argument_list|)
name|link
expr_stmt|;
block|}
name|interface
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INTERFACE_FILE_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|INTERFACE_CONN_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|INTERFACE_FORWARDING
value|0x04
end_define

begin_struct
struct|struct
name|qstream
block|{
name|int
name|s_rfd
decl_stmt|;
comment|/* stream file descriptor */
name|int
name|s_size
decl_stmt|;
comment|/* expected amount of data to rcv */
name|int
name|s_bufsize
decl_stmt|;
comment|/* amount of data received in s_buf */
name|u_char
modifier|*
name|s_buf
decl_stmt|;
comment|/* buffer of received data */
name|u_char
modifier|*
name|s_wbuf
decl_stmt|;
comment|/* send buffer */
name|u_char
modifier|*
name|s_wbuf_send
decl_stmt|;
comment|/* next sendable byte of send buffer */
name|u_char
modifier|*
name|s_wbuf_free
decl_stmt|;
comment|/* next free byte of send buffer */
name|u_char
modifier|*
name|s_wbuf_end
decl_stmt|;
comment|/* byte after end of send buffer */
name|sq_closure
name|s_wbuf_closure
decl_stmt|;
comment|/* callback for writable descriptor */
name|struct
name|qstream
modifier|*
name|s_next
decl_stmt|;
comment|/* next stream */
name|struct
name|sockaddr_in
name|s_from
decl_stmt|;
comment|/* address query came from */
name|interface
modifier|*
name|s_ifp
decl_stmt|;
comment|/* interface query came from */
name|time_t
name|s_time
decl_stmt|;
comment|/* time stamp of last transaction */
name|int
name|s_refcnt
decl_stmt|;
comment|/* number of outstanding queries */
name|u_char
name|s_temp
index|[
name|HFIXEDSZ
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|BIND_UPDATE
name|int
name|s_opcode
decl_stmt|;
comment|/* type of request */
name|int
name|s_linkcnt
decl_stmt|;
comment|/* number of client connections using 					 * this connection to forward updates 					 * to the primary */
name|struct
name|fdlist
modifier|*
name|s_fds
decl_stmt|;
comment|/* linked list of connections to the 					 * primaries that have been used by 					 * the server to forward this client's 					 * update requests */
endif|#
directive|endif
name|evStreamID
name|evID_r
decl_stmt|;
comment|/* read event. */
name|evFileID
name|evID_w
decl_stmt|;
comment|/* writable event handle. */
name|evConnID
name|evID_c
decl_stmt|;
comment|/* connect event handle */
name|u_int
name|flags
decl_stmt|;
comment|/* see below */
struct|struct
name|qstream_xfr
block|{
enum|enum
block|{
name|s_x_base
block|,
name|s_x_firstsoa
block|,
name|s_x_zone
block|,
name|s_x_lastsoa
block|,
name|s_x_done
block|}
name|state
enum|;
comment|/* state of transfer. */
name|u_char
modifier|*
name|msg
decl_stmt|,
comment|/* current assembly message. */
modifier|*
name|cp
decl_stmt|,
comment|/* where are we in msg? */
modifier|*
name|eom
decl_stmt|,
comment|/* end of msg. */
modifier|*
name|ptrs
index|[
literal|128
index|]
decl_stmt|;
comment|/* ptrs for dn_comp(). */
name|int
name|class
decl_stmt|,
comment|/* class of an XFR. */
name|id
decl_stmt|,
comment|/* id of an XFR. */
name|opcode
decl_stmt|;
comment|/* opcode of an XFR. */
name|u_int
name|zone
decl_stmt|;
comment|/* zone being XFR'd. */
name|struct
name|namebuf
modifier|*
name|top
decl_stmt|;
comment|/* top np of an XFR. */
struct|struct
name|qs_x_lev
block|{
comment|/* decompose the recursion. */
enum|enum
block|{
name|sxl_ns
block|,
name|sxl_all
block|,
name|sxl_sub
block|}
name|state
enum|;
comment|/* what's this level doing? */
name|int
name|flags
decl_stmt|;
comment|/* see below (SXL_*). */
name|char
name|dname
index|[
name|MAXDNAME
index|]
decl_stmt|;
name|struct
name|namebuf
modifier|*
name|np
decl_stmt|,
comment|/* this node. */
modifier|*
name|nnp
decl_stmt|,
comment|/* next node to process. */
modifier|*
modifier|*
name|npp
decl_stmt|,
comment|/* subs. */
modifier|*
modifier|*
name|npe
decl_stmt|;
comment|/* end of subs. */
name|struct
name|databuf
modifier|*
name|dp
decl_stmt|;
comment|/* current rr. */
name|struct
name|qs_x_lev
modifier|*
name|next
decl_stmt|;
comment|/* link. */
block|}
modifier|*
name|lev
struct|;
comment|/* LIFO. */
name|enum
name|axfr_format
name|transfer_format
decl_stmt|;
block|}
name|xfr
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SXL_GLUING
value|0x01
end_define

begin_define
define|#
directive|define
name|SXL_ZONECUT
value|0x02
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|STREAM_MALLOC
value|0x01
end_define

begin_define
define|#
directive|define
name|STREAM_WRITE_EV
value|0x02
end_define

begin_define
define|#
directive|define
name|STREAM_READ_EV
value|0x04
end_define

begin_define
define|#
directive|define
name|STREAM_CONNECT_EV
value|0x08
end_define

begin_define
define|#
directive|define
name|STREAM_DONE_CLOSE
value|0x10
end_define

begin_define
define|#
directive|define
name|STREAM_AXFR
value|0x20
end_define

begin_define
define|#
directive|define
name|ALLOW_NETS
value|0x0001
end_define

begin_define
define|#
directive|define
name|ALLOW_HOSTS
value|0x0002
end_define

begin_define
define|#
directive|define
name|ALLOW_ALL
value|(ALLOW_NETS | ALLOW_HOSTS)
end_define

begin_struct
struct|struct
name|fwdinfo
block|{
name|struct
name|fwdinfo
modifier|*
name|next
decl_stmt|;
name|struct
name|sockaddr_in
name|fwdaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|nameserStats
block|{
name|nssRcvdR
block|,
comment|/* sent us an answer */
name|nssRcvdNXD
block|,
comment|/* sent us a negative response */
name|nssRcvdFwdR
block|,
comment|/* sent us a response we had to fwd */
name|nssRcvdDupR
block|,
comment|/* sent us an extra answer */
name|nssRcvdFail
block|,
comment|/* sent us a SERVFAIL */
name|nssRcvdFErr
block|,
comment|/* sent us a FORMERR */
name|nssRcvdErr
block|,
comment|/* sent us some other error */
name|nssRcvdAXFR
block|,
comment|/* sent us an AXFR */
name|nssRcvdLDel
block|,
comment|/* sent us a lame delegation */
name|nssRcvdOpts
block|,
comment|/* sent us some IP options */
name|nssSentSysQ
block|,
comment|/* sent them a sysquery */
name|nssSentAns
block|,
comment|/* sent them an answer */
name|nssSentFwdQ
block|,
comment|/* fwdd a query to them */
name|nssSentDupQ
block|,
comment|/* sent them a retry */
name|nssSendtoErr
block|,
comment|/* error in sendto */
name|nssRcvdQ
block|,
comment|/* sent us a query */
name|nssRcvdIQ
block|,
comment|/* sent us an inverse query */
name|nssRcvdFwdQ
block|,
comment|/* sent us a query we had to fwd */
name|nssRcvdDupQ
block|,
comment|/* sent us a retry */
name|nssRcvdTCP
block|,
comment|/* sent us a query using TCP */
name|nssSentFwdR
block|,
comment|/* fwdd a response to them */
name|nssSentFail
block|,
comment|/* sent them a SERVFAIL */
name|nssSentFErr
block|,
comment|/* sent them a FORMERR */
name|nssSentNaAns
block|,
comment|/* sent them a non autoritative answer */
name|nssSentNXD
block|,
comment|/* sent them a negative response */
name|nssLast
block|}
enum|;
end_enum

begin_struct
struct|struct
name|nameser
block|{
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* key */
name|u_long
name|stats
index|[
name|nssLast
index|]
decl_stmt|;
comment|/* statistics */
ifdef|#
directive|ifdef
name|notyet
name|u_int32_t
name|rtt
decl_stmt|;
comment|/* round trip time */
comment|/* XXX - need to add more stuff from "struct qserv", and use our rtt */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* see below */
endif|#
directive|endif
name|u_int8_t
name|xfers
decl_stmt|;
comment|/* #/xfers running right now */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|transport
block|{
name|primary_trans
block|,
name|secondary_trans
block|,
name|response_trans
block|,
name|num_trans
block|}
enum|;
end_enum

begin_comment
comment|/* types used by the parser or config routines */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|zone_config
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|zone_config
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|listen_info
block|{
name|u_short
name|port
decl_stmt|;
name|ip_match_list
name|list
decl_stmt|;
name|struct
name|listen_info
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|listen_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|listen_info_list
block|{
name|listen_info
name|first
decl_stmt|;
name|listen_info
name|last
decl_stmt|;
block|}
typedef|*
name|listen_info_list
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|RLIMIT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|RLIMIT_TYPE
value|u_long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|RLIMIT_TYPE
name|rlimit_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|options
block|{
name|u_int
name|flags
decl_stmt|;
name|char
modifier|*
name|directory
decl_stmt|;
name|char
modifier|*
name|dump_filename
decl_stmt|;
name|char
modifier|*
name|pid_filename
decl_stmt|;
name|char
modifier|*
name|stats_filename
decl_stmt|;
name|char
modifier|*
name|memstats_filename
decl_stmt|;
name|char
modifier|*
name|named_xfer
decl_stmt|;
name|int
name|transfers_in
decl_stmt|;
name|int
name|transfers_per_ns
decl_stmt|;
name|int
name|transfers_out
decl_stmt|;
name|enum
name|axfr_format
name|transfer_format
decl_stmt|;
name|long
name|max_transfer_time_in
decl_stmt|;
name|struct
name|sockaddr_in
name|query_source
decl_stmt|;
name|ip_match_list
name|query_acl
decl_stmt|;
name|ip_match_list
name|transfer_acl
decl_stmt|;
name|ip_match_list
name|topology
decl_stmt|;
name|enum
name|severity
name|check_names
index|[
name|num_trans
index|]
decl_stmt|;
name|u_long
name|data_size
decl_stmt|;
name|u_long
name|stack_size
decl_stmt|;
name|u_long
name|core_size
decl_stmt|;
name|u_long
name|files
decl_stmt|;
name|listen_info_list
name|listen_list
decl_stmt|;
name|struct
name|fwdinfo
modifier|*
name|fwdtab
decl_stmt|;
comment|/* XXX need to add forward option */
name|int
name|clean_interval
decl_stmt|;
name|int
name|interface_interval
decl_stmt|;
name|int
name|stats_interval
decl_stmt|;
block|}
typedef|*
name|options
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|key_info
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|algorithm
decl_stmt|;
name|char
modifier|*
name|secret
decl_stmt|;
comment|/* XXX should be u_char? */
block|}
typedef|*
name|key_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|key_list_element
block|{
name|key_info
name|info
decl_stmt|;
name|struct
name|key_list_element
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|key_list_element
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|key_info_list
block|{
name|key_list_element
name|first
decl_stmt|;
name|key_list_element
name|last
decl_stmt|;
block|}
typedef|*
name|key_info_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|topology_config
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|topology_config
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNKNOWN_TOPOLOGY_DISTANCE
value|9998
end_define

begin_define
define|#
directive|define
name|MAX_TOPOLOGY_DISTANCE
value|9999
end_define

begin_typedef
typedef|typedef
struct|struct
name|topology_distance
block|{
name|ip_match_list
name|patterns
decl_stmt|;
name|struct
name|topology_distance
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|topology_distance
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|topology_context
block|{
name|topology_distance
name|first
decl_stmt|;
name|topology_distance
name|last
decl_stmt|;
block|}
typedef|*
name|topology_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acl_table_entry
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|ip_match_list
name|list
decl_stmt|;
name|struct
name|acl_table_entry
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|acl_table_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|server_config
block|{
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
name|server_config
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SERVER_INFO_BOGUS
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|server_info
block|{
name|struct
name|in_addr
name|address
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|int
name|transfers
decl_stmt|;
name|enum
name|axfr_format
name|transfer_format
decl_stmt|;
name|key_info_list
name|key_list
decl_stmt|;
comment|/* could move statistics to here, too */
name|struct
name|server_info
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|server_info
typedef|;
end_typedef

begin_comment
comment|/*  * enum<--> name translation  */
end_comment

begin_struct
struct|struct
name|ns_sym
block|{
name|int
name|number
decl_stmt|;
comment|/* Identifying number, like ns_log_default */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Its symbolic name, like "default" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Logging options  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ns_logging_categories
block|{
name|ns_log_default
init|=
literal|0
block|,
name|ns_log_config
block|,
name|ns_log_parser
block|,
name|ns_log_queries
block|,
name|ns_log_lame_servers
block|,
name|ns_log_statistics
block|,
name|ns_log_panic
block|,
name|ns_log_update
block|,
name|ns_log_ncache
block|,
name|ns_log_xfer_in
block|,
name|ns_log_xfer_out
block|,
name|ns_log_db
block|,
name|ns_log_eventlib
block|,
name|ns_log_packet
block|,
name|ns_log_notify
block|,
name|ns_log_cname
block|,
name|ns_log_security
block|,
name|ns_log_os
block|,
name|ns_log_insist
block|,
name|ns_log_maint
block|,
name|ns_log_load
block|,
name|ns_log_resp_checks
block|,
name|ns_log_max_category
block|}
name|ns_logging_categories
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|log_config
block|{
name|log_context
name|log_ctx
decl_stmt|;
name|log_channel
name|eventlib_channel
decl_stmt|;
name|log_channel
name|packet_channel
decl_stmt|;
name|int
name|default_debug_active
decl_stmt|;
block|}
typedef|*
name|log_config
typedef|;
end_typedef

begin_struct
struct|struct
name|map
block|{
name|char
modifier|*
name|token
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NOERROR_NODATA
value|6
end_define

begin_comment
comment|/* only used internally by the server, used for 				 * -ve $ing non-existence of records. 6 is not  				 * a code used as yet anyway. anant@isi.edu 				 */
end_comment

begin_define
define|#
directive|define
name|NTTL
value|600
end_define

begin_comment
comment|/* ttl for negative data: 10 minutes? */
end_comment

begin_define
define|#
directive|define
name|VQEXPIRY
value|900
end_define

begin_comment
comment|/* a VQ entry expires in 15*60 = 900 seconds */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_UPDATE
end_ifdef

begin_enum
enum|enum
name|req_action
block|{
name|Finish
block|,
name|Refuse
block|,
name|Return
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BIND_NOTIFY
end_ifdef

begin_typedef
typedef|typedef
enum|enum
block|{
name|notify_info_waitfor
block|,
name|notify_info_delay
block|,
name|notify_info_error
block|,
name|notify_info_done
block|}
name|notify_info_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|notify_info
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|class
decl_stmt|;
name|notify_info_state
name|state
decl_stmt|;
name|evWaitID
name|wait_id
decl_stmt|;
name|evTimerID
name|timer_id
decl_stmt|;
name|LINK
argument_list|(
argument|struct notify_info
argument_list|)
name|link
expr_stmt|;
block|}
typedef|*
name|notify_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|LIST
argument_list|(
argument|struct notify_info
argument_list|)
name|notify_info_list
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND_NOTIFY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INIT
end_ifdef

begin_expr_stmt
name|error
literal|"INIT already defined, check system include files"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DECL
name|error
literal|"DECL already defined, check system include files"
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
end_ifdef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_define
define|#
directive|define
name|DECL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DECL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

