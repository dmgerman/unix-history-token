begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	from ns.h	4.33 (Berkeley) 8/23/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++ 1986  * -  * Copyright (c) 1986  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  * Global variables for the name server.  */
end_comment

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

begin_function_decl
name|DECL
name|FILE
modifier|*
name|ddt
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* list of open streams */
end_comment

begin_function_decl
name|DECL
name|struct
name|qstream
modifier|*
name|streamq
name|INIT
parameter_list|(
name|QSTREAM_NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* list of datagram interfaces */
end_comment

begin_function_decl
name|DECL
name|struct
name|qdatagram
modifier|*
name|datagramq
name|INIT
parameter_list|(
name|QDATAGRAM_NULL
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|DECL
name|struct
name|qinfo
modifier|*
name|nsqhead
name|INIT
parameter_list|(
name|QINFO_NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* list of forwarding hosts */
end_comment

begin_function_decl
name|DECL
name|struct
name|fwdinfo
modifier|*
name|fwdtab
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* datagram socket */
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
comment|/* listening TCP socket */
end_comment

begin_decl_stmt
name|DECL
name|int
name|vs
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* received SIGHUP, need to reload db */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needreload
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to call ns_maint()*/
end_comment

begin_decl_stmt
name|DECL
name|int
name|needmaint
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how often does ns_maint() need to be called, in seconds? */
end_comment

begin_comment
comment|/* (beware: this is also the upper bound on named_xfer real time) */
end_comment

begin_decl_stmt
name|DECL
name|int
name|maint_interval
name|INIT
argument_list|(
literal|15
operator|*
literal|60
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CLEANCACHE
end_ifdef

begin_comment
comment|/* What's the minimum interval between cache cleanings? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|cache_interval
name|INIT
argument_list|(
literal|60
operator|*
literal|60
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XSTATS
end_ifdef

begin_comment
comment|/* What's the minimum interval between stats output? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|stats_interval
name|INIT
argument_list|(
literal|60
operator|*
literal|60
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* need to reload secondary zone(s) */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needzoneload
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to dump database */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needToDoadump
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to checkpoint cache */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needToChkpt
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to dump statistics */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needStatsDump
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_UPDATES
end_ifdef

begin_comment
comment|/* need to exit (may need to doadump 	 * first, if database has changed since 	 * it was last dumped/booted). Gets 	 * set by shutdown signal handler 	 *  (onintr) 	 */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needToExit
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
comment|/* ALLOW_UPDATES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XSTATS
end_ifdef

begin_comment
comment|/* need to exit 	 * set by shutdown signal handler 	 *  (onintr) 	 */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needToExit
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
comment|/* XSTATS */
end_comment

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
comment|/*QRYLOG*/
end_comment

begin_comment
comment|/* is this a root server that should therefore not recurse? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|NoRecurse
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We keep a list of favored networks headed by nettab.  * There are three (possibly empty) parts to this list, in this order:  *	1. directly attached (sub)nets.  *	2. logical networks for directly attached subnetted networks.  *	3. networks from the sort list.  * The value (*elocal) points at the first entry in the second part of the  * list, if any, while (*enettab) points at the first entry in the sort list.  */
end_comment

begin_function_decl
name|DECL
name|struct
name|netinfo
modifier|*
name|nettab
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|DECL
name|struct
name|netinfo
modifier|*
modifier|*
name|elocal
name|INIT
argument_list|(
operator|&
name|nettab
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DECL
name|struct
name|netinfo
modifier|*
modifier|*
name|enettab
name|INIT
argument_list|(
operator|&
name|nettab
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XFRNETS
end_ifdef

begin_comment
comment|/* list of nets we're willing to zone transfer to */
end_comment

begin_function_decl
name|DECL
name|struct
name|netinfo
modifier|*
name|xfrnets
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BOGUSNS
end_ifdef

begin_comment
comment|/* list of bogus nameservers */
end_comment

begin_function_decl
name|DECL
name|struct
name|netinfo
modifier|*
name|boglist
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* loopback net */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|netinfo
name|netloop
decl_stmt|;
end_decl_stmt

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
comment|/* Source addr of last packet */
end_comment

begin_decl_stmt
name|DECL
name|struct
name|sockaddr_in
name|from_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Source addr size of last packet */
end_comment

begin_decl_stmt
name|DECL
name|int
name|from_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used by ns_stats */
end_comment

begin_decl_stmt
name|DECL
name|time_t
name|boottime
decl_stmt|,
name|resettime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next query to retry */
end_comment

begin_function_decl
name|DECL
name|struct
name|qinfo
modifier|*
name|retryqp
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* default boot file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BOOTFILE
end_ifdef

begin_function_decl
name|DECL
name|char
modifier|*
name|bootfile
name|INIT
parameter_list|(
name|BOOTFILE
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DECL
name|char
modifier|*
name|bootfile
name|INIT
parameter_list|(
name|_PATH_BOOT
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default debug output file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGFILE
end_ifdef

begin_function_decl
name|DECL
name|char
modifier|*
name|debugfile
name|INIT
parameter_list|(
name|DEBUGFILE
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DECL
name|char
modifier|*
name|debugfile
name|INIT
parameter_list|(
name|_PATH_DEBUG
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_PIDFILE
end_ifdef

begin_comment
comment|/* file to store current named PID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PIDFILE
end_ifdef

begin_function_decl
name|DECL
name|char
modifier|*
name|PidFile
name|INIT
parameter_list|(
name|PIDFILE
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DECL
name|char
modifier|*
name|PidFile
name|INIT
parameter_list|(
name|_PATH_PIDFILE
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*WANT_PIDFILE*/
end_comment

begin_comment
comment|/* zone information */
end_comment

begin_function_decl
name|DECL
name|struct
name|zoneinfo
modifier|*
name|zones
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* number of zones in use */
end_comment

begin_decl_stmt
name|DECL
name|int
name|nzones
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true on slave server */
end_comment

begin_decl_stmt
name|DECL
name|int
name|forward_only
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we need a priming */
end_comment

begin_decl_stmt
name|DECL
name|int
name|needs_prime_cache
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is cache being primed */
end_comment

begin_decl_stmt
name|DECL
name|int
name|priming
name|INIT
argument_list|(
literal|0
argument_list|)
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
name|char
modifier|*
name|cache_file
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOCALDOM
end_ifdef

begin_comment
comment|/* our local domain (deprecated in favor of resolv.conf) */
end_comment

begin_decl_stmt
name|DECL
name|char
modifier|*
name|localdomain
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SLAVE_FORWARD
end_ifdef

begin_comment
comment|/* retry time when a slave */
end_comment

begin_decl_stmt
name|DECL
name|int
name|slave_retry
name|INIT
argument_list|(
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STATSFILE
end_ifdef

begin_function_decl
name|DECL
specifier|const
name|char
modifier|*
name|statsfile
name|INIT
parameter_list|(
name|STATSFILE
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DECL
specifier|const
name|char
modifier|*
name|statsfile
name|INIT
parameter_list|(
name|_PATH_STATS
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* max value of xfers_running */
end_comment

begin_function_decl
name|DECL
name|int
name|max_xfers_running
name|INIT
parameter_list|(
name|MAX_XFERS_RUNNING
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* max number of transfers to any given name server */
end_comment

begin_function_decl
name|DECL
name|int
name|max_xfers_per_ns
name|INIT
parameter_list|(
name|MAX_XFERS_PER_NS
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|INVQ
end_ifndef

begin_comment
comment|/* should IQUERY be answered bogusly rather than with NOTIMPL? */
end_comment

begin_decl_stmt
name|DECL
name|int
name|fake_iquery
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

end_unit

