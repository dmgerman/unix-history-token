begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pathnames.h	5.4 (Berkeley) 6/1/90  */
end_comment

begin_define
define|#
directive|define
name|_PATH_BOOT
value|"/etc/named.boot"
end_define

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

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/usr/libexec/named-xfer"
end_define

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

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/var/run/named.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_STATS
value|"/var/tmp/named.stats"
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

begin_define
define|#
directive|define
name|_PATH_XFER
value|"/etc/named-xfer"
end_define

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

begin_define
define|#
directive|define
name|_PATH_PIDFILE
value|"/etc/named.pid"
end_define

begin_define
define|#
directive|define
name|_PATH_STATS
value|"/usr/tmp/named.stats"
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

end_unit

