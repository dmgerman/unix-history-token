begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* options.h - specify the conditionally-compiled features  * vix 28mar92 [moved out of the Makefile because they were getting too big]  *  * $Id: options.h,v 4.9.1.1 1993/05/02 23:17:40 vixie Rel $  */
end_comment

begin_comment
comment|/*  * ++Copyright++  * -  * Copyright (c)  Regents of the University of California.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/* Key:  *	ucb = U C Berkeley 4.8.3 release  *	vix = Paul Vixie of Digital  *	del = Don Lewis of Harris  *	mcsun = Piet Beertema of EUNet  *	asp = Andrew Partan of UUNet  *	pma = Paul Albitz of Hewlett Packard  *	bb = Bryan Beecher of UMich  */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* enable -d flag and SIGUSR[12] support (ucb) */
end_comment

begin_define
define|#
directive|define
name|STATS
end_define

begin_comment
comment|/* enable statistic gathering/reporting (ucb) */
end_comment

begin_comment
comment|/*#define ALLOW_T_UNSPEC /* enable the "unspec" RR type for old athena (ucb) */
end_comment

begin_comment
comment|/*#define ALLOW_UPDATES	/* enable on-the-fly dynamic updates (mike schwartz) */
end_comment

begin_define
define|#
directive|define
name|INVQ
value|1
end_define

begin_comment
comment|/* [01] enable inverse queries (nslookup) (ucb/vix) */
end_comment

begin_comment
comment|/*#define DSTORAGE	/* debug malloc overruns using storage.o (ucb/vix) */
end_comment

begin_comment
comment|/*#define DMALLOC	/* trace malloc orphans using dmalloc.o (vix) */
end_comment

begin_define
define|#
directive|define
name|CRED
end_define

begin_comment
comment|/* "credibility" hacks and pollution control (vix) */
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
comment|/*#define YPKLUDGE  	/* deal effectively with broken "ypserv -i" (mcsun) */
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
comment|/*#define LOCALDOM	/* permit "domain" directive in named.boot (ucb/vix) */
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

begin_comment
comment|/*#define SYSV		/* compile for SYSV (ucb) XXX */
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
comment|/*#define SENSIBLE_DOTS	/* if you want dotted serial#s to make numeric sense */
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
value|rt_alloc
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

end_unit

