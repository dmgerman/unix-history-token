begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)pathnames.h	5.4 (Berkeley) 6/1/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * ++Copyright++ 1989  * -  * Copyright (c) 1989  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_XFER
end_ifdef

begin_define
define|#
directive|define
name|_PATH_XFER_PREDEFINED
end_define

begin_comment
comment|/* probably from Makefile */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_SYSTYPE_SVR4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__SYSTYPE_SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PATH_BOOT
value|"/usr/etc/named.d/named.boot"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_BOOT
value|"/etc/named.boot"
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
name|BSD
argument_list|)
operator|&&
name|BSD
operator|>=
literal|198810
end_if

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFER
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/usr/libexec/named-xfer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_DEBUG
value|"/var/tmp/named.run"
end_define

begin_define
define|#
directive|define
name|_PATH_DUMPFILE
value|"/var/tmp/named_dump.db"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PIDFILE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/var/run/named.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_STATS
value|"/var/tmp/named.stats"
end_define

begin_define
define|#
directive|define
name|_PATH_XFERTRACE
value|"/var/tmp/xfer.trace"
end_define

begin_define
define|#
directive|define
name|_PATH_XFERDDT
value|"/var/tmp/xfer.ddt"
end_define

begin_define
define|#
directive|define
name|_PATH_TMPXFER
value|"/var/tmp/xfer.ddt.XXXXXX"
end_define

begin_define
define|#
directive|define
name|_PATH_TMPDIR
value|"/var/tmp"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFER
end_ifndef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/etc/named-xfer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_DEBUG
value|"/usr/tmp/named.run"
end_define

begin_define
define|#
directive|define
name|_PATH_DUMPFILE
value|"/usr/tmp/named_dump.db"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PIDFILE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/etc/named.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_STATS
value|"/usr/tmp/named.stats"
end_define

begin_define
define|#
directive|define
name|_PATH_XFERTRACE
value|"/usr/tmp/xfer.trace"
end_define

begin_define
define|#
directive|define
name|_PATH_XFERDDT
value|"/usr/tmp/xfer.ddt"
end_define

begin_define
define|#
directive|define
name|_PATH_TMPXFER
value|"/usr/tmp/xfer.ddt.XXXXXX"
end_define

begin_define
define|#
directive|define
name|_PATH_TMPDIR
value|"/usr/tmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_XFER_PREDEFINED
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__ultrix
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_PATH_XFER
end_undef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/usr/etc/named-xfer"
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
name|__osf__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_PATH_XFER
end_undef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/usr/sbin/named-xfer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_undef
undef|#
directive|undef
name|_PATH_XFER
end_undef

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/usr/etc/in.named-xfer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|_PATH_XFER_PREDEFINED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_PATH_XFER_PREDEFINED*/
end_comment

end_unit

