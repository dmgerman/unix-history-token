begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* options.h - specify the conditionally-compiled features  * vix 28mar92 [moved out of the Makefile because they were getting too big]  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++  * -  * Copyright (c)  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/* Key:  *	ucb = U C Berkeley 4.8.3 release  *	vix = Paul Vixie of Digital  *	del = Don Lewis of Harris  *	mcsun = Piet Beertema of EUNet  *	asp = Andrew Partan of UUNet  *	pma = Paul Albitz of Hewlett Packard  *	bb = Bryan Beecher of UMich  *	mpa = Mark Andrews of CSIRO - DMS  *	rossc = Ross Cartlidge of The Univeritsy of Sydney  *	mtr = Marshall Rose of TPC.INT  *      bg = Benoit Grange of INRIA  *      ckd = Christopher Davis of Kapor Enterprises  *      gns = Greg Shapiro of WPI  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* enable -d flag and SIGUSR[12] support (ucb) */
end_comment

begin_comment
comment|/*#define ALLOW_T_UNSPEC*/
end_comment

begin_comment
comment|/* enable the "unspec" RR type for old athena (ucb) */
end_comment

begin_define
define|#
directive|define
name|INVQ
end_define

begin_comment
comment|/* enable inverse queries (nslookup) (ucb/vix) */
end_comment

begin_comment
comment|/*#define DSTORAGE*/
end_comment

begin_comment
comment|/* debug malloc overruns using storage.o (ucb/vix) */
end_comment

begin_comment
comment|/*#define DMALLOC*/
end_comment

begin_comment
comment|/* trace malloc orphans using dmalloc.o (vix) */
end_comment

begin_define
define|#
directive|define
name|XFRNETS
end_define

begin_comment
comment|/* enable "xfrnets" command in named.boot (vix) */
end_comment

begin_define
define|#
directive|define
name|PID_FIX
end_define

begin_comment
comment|/* be careful about overwriting named.pid file (del) */
end_comment

begin_define
define|#
directive|define
name|FWD_LOOP
end_define

begin_comment
comment|/* try to break out of forwarding loops (del) */
end_comment

begin_define
define|#
directive|define
name|NO_GLUE
end_define

begin_comment
comment|/* don't accept or send out-of-zone glue (del) */
end_comment

begin_define
define|#
directive|define
name|BOGUSNS
end_define

begin_comment
comment|/* detect bogus nameservers (mcsun) */
end_comment

begin_define
define|#
directive|define
name|QRYLOG
end_define

begin_comment
comment|/* enable SIGWINCH for query logging (bb) */
end_comment

begin_comment
comment|/*#define YPKLUDGE*/
end_comment

begin_comment
comment|/* deal effectively with broken "ypserv -i" (mcsun) */
end_comment

begin_define
define|#
directive|define
name|TRACEROOT
end_define

begin_comment
comment|/* trace bogus root servers and ignore them (pma,bb) */
end_comment

begin_comment
comment|/*#define LOCALDOM*/
end_comment

begin_comment
comment|/* permit "domain" directive in named.boot (ucb) */
end_comment

begin_define
define|#
directive|define
name|FORCED_RELOAD
end_define

begin_comment
comment|/* refresh secondary zones on SIGHUP (pma) */
end_comment

begin_define
define|#
directive|define
name|SLAVE_FORWARD
end_define

begin_comment
comment|/* use sensible timeouts on slave forwarders (pma) */
end_comment

begin_define
define|#
directive|define
name|WANT_PIDFILE
end_define

begin_comment
comment|/* if you want the named.pid file (ucb/arc) */
end_comment

begin_define
define|#
directive|define
name|DOTTED_SERIAL
end_define

begin_comment
comment|/* if you want to be able to specify dotted serial#s */
end_comment

begin_comment
comment|/*#define SENSIBLE_DOTS*/
end_comment

begin_comment
comment|/* if you want dotted serial#s to make numeric sense */
end_comment

begin_define
define|#
directive|define
name|NCACHE
end_define

begin_comment
comment|/* negative caching (anant@isi.edu) */
end_comment

begin_comment
comment|/*#define VALIDATE*/
end_comment

begin_comment
comment|/* validation procedure (anant@isi.edu) (DO NOT USE!)*/
end_comment

begin_comment
comment|/*#define SHORT_FNAMES*/
end_comment

begin_comment
comment|/* file names used in named-xfer need to be short */
end_comment

begin_define
define|#
directive|define
name|RESOLVSORT
end_define

begin_comment
comment|/* allow sorting of addresses in gethostbyname (mpa) */
end_comment

begin_define
define|#
directive|define
name|STUBS
end_define

begin_comment
comment|/* allow transfers of NS only for a zone (mpa) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGFAC
end_ifndef

begin_define
define|#
directive|define
name|LOGFAC
value|LOG_DAEMON
end_define

begin_comment
comment|/* what syslog facility should named use? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SECURE_ZONES
end_define

begin_comment
comment|/* if you want to inhibit world access to zones (gns)*/
end_comment

begin_define
define|#
directive|define
name|ROUND_ROBIN
end_define

begin_comment
comment|/* rotate databuf list after each access (mtr) */
end_comment

begin_define
define|#
directive|define
name|ADDAUTH
end_define

begin_comment
comment|/* return NS and glue w/ authorative answers (mpa) */
end_comment

begin_comment
comment|/*#define RFC1535*/
end_comment

begin_comment
comment|/* use RFC 1535 default for "search" list (vix) */
end_comment

begin_define
define|#
directive|define
name|GEN_AXFR
end_define

begin_comment
comment|/* distinct zones within each class */
end_comment

begin_define
define|#
directive|define
name|DATUMREFCNT
end_define

begin_comment
comment|/* use reference counts on datums (mpa) */
end_comment

begin_define
define|#
directive|define
name|LAME_DELEGATION
end_define

begin_comment
comment|/* lame delegations (original-del,reworked-bb&del)*/
end_comment

begin_define
define|#
directive|define
name|LAME_LOGGING
value|LOG_WARNING
end_define

begin_comment
comment|/* log lame delegations, set log level */
end_comment

begin_define
define|#
directive|define
name|GETSER_LOGGING
value|LOG_INFO
end_define

begin_comment
comment|/* log errors/timeouts getting serial number */
end_comment

begin_comment
comment|/*#define RETURNSOA*/
end_comment

begin_comment
comment|/* good code that the world isn't ready for yet */
end_comment

begin_define
define|#
directive|define
name|CLEANCACHE
end_define

begin_comment
comment|/* useful and necessary in the face of NCACHE */
end_comment

begin_define
define|#
directive|define
name|PURGE_ZONE
end_define

begin_comment
comment|/* remove all traces of a zone when reloading (mpa) */
end_comment

begin_define
define|#
directive|define
name|STATS
end_define

begin_comment
comment|/* keep nameserver statistics; uses more memory */
end_comment

begin_define
define|#
directive|define
name|RENICE
end_define

begin_comment
comment|/* named-xfer should run at normal priority */
end_comment

begin_define
define|#
directive|define
name|XSTATS
end_define

begin_comment
comment|/* extended statistics, syslogged periodically (bg) */
end_comment

begin_comment
comment|/*#define BIND_NOTIFY*/
end_comment

begin_comment
comment|/* experimental - do not enable in customer products */
end_comment

begin_comment
comment|/*#define LOC_RR*/
end_comment

begin_comment
comment|/* support for (draft) LOC record parsing (ckd) */
end_comment

begin_comment
comment|/*--------------------------------------------*  * no user-servicable parts beyond this point *  *--------------------------------------------*/
end_comment

begin_comment
comment|/* if DSTORAGE is defined, we need to disable DMALLOC and remap  * malloc and free to storage.o's exported names.  storage.o also  * includes a calloc and a realloc, but once we drag in its malloc  * and free we'll get the others automatically and so will never  * pull in those routines from libc.a.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DSTORAGE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DMALLOC
end_ifdef

begin_undef
undef|#
directive|undef
name|DMALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DMALLOC*/
end_comment

begin_define
define|#
directive|define
name|malloc
value|rt_malloc
end_define

begin_define
define|#
directive|define
name|free
value|rt_free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DSTORAGE*/
end_comment

begin_comment
comment|/* if DMALLOC is defined, grab the header file which will remap  * all the malloc-style names to those exported by dmalloc.o.  note  * that DMALLOC also changes the function signatures of several  * functions in private named source modules, and that this file  * (options.h) must be included before any other private *.h files  * since those *.h files have some conditional remapping to do.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DMALLOC
end_ifdef

begin_include
include|#
directive|include
file|"dmalloc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* systems with killall(1M) don't need this  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_PIDFILE
end_ifdef

begin_undef
undef|#
directive|undef
name|WANT_PIDFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LAME_LOGGING
end_ifdef

begin_define
define|#
directive|define
name|LAME_DELEGATION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XSTATS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STATS
argument_list|)
end_if

begin_define
define|#
directive|define
name|STATS
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

