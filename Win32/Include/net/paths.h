begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)paths.h	5.15 (Berkeley) 5/29/91  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATHS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PATHS_H_
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|__PATH_ETC_INET
value|"/usr/etc/inet"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PATH_ETC_INET
value|"/etc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default search path. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/local/bin:/usr/bin:/bin:."
end_define

begin_define
define|#
directive|define
name|_PATH_DEFPATH_ROOT
value|"/sbin:/bin:/usr/sbin:/usr/bin"
end_define

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|_PATH_CONSOLE
value|"/dev/console"
end_define

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/bin/csh"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVDB
value|"/var/run/dev.db"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|_PATH_DRUM
value|"/dev/drum"
end_define

begin_define
define|#
directive|define
name|_PATH_HEQUIV
value|__PATH_ETC_INET"/hosts.equiv"
end_define

begin_define
define|#
directive|define
name|_PATH_KMEM
value|"/dev/kmem"
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/spool/mail"
end_define

begin_define
define|#
directive|define
name|_PATH_MAN
value|"/usr/man"
end_define

begin_define
define|#
directive|define
name|_PATH_MEM
value|"/dev/mem"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/bin/login"
end_define

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/etc/nologin"
end_define

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_define
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
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
name|_PATH_UNIX
value|"/vmlinux"
end_define

begin_define
define|#
directive|define
name|_PATH_VI
value|"/usr/bin/vi"
end_define

begin_comment
comment|/* Provide trailing slash, since mostly used for building pathnames. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARRUN
value|"/var/run/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARTMP
value|"/var/tmp/"
end_define

begin_define
define|#
directive|define
name|_PATH_KLOG
value|"/proc/kmsg"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGCONF
value|__PATH_ETC_INET"/syslog.conf"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|_PATH_LOGPID
value|__PATH_ETC_INET"/syslog.pid"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_LOGPID
value|"/var/run/syslog.pid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_LOG
value|"/dev/log"
end_define

begin_define
define|#
directive|define
name|_PATH_CONSOLE
value|"/dev/console"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/var/adm/utmp"
end_define

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/var/adm/wtmp"
end_define

begin_define
define|#
directive|define
name|_PATH_LASTLOG
value|"/var/adm/lastlog"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/var/run/utmp"
end_define

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/var/log/wtmp"
end_define

begin_define
define|#
directive|define
name|_PATH_LASTLOG
value|"/var/log/lastlog"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_LOCALE
value|"/usr/lib/locale"
end_define

begin_define
define|#
directive|define
name|_PATH_RWHODIR
value|"/var/spool/rwho"
end_define

begin_if
if|#
directive|if
name|_MIT_POSIX_THREADS
end_if

begin_comment
comment|/* For the MIT pthreads */
end_comment

begin_define
define|#
directive|define
name|_PATH_PTY
value|"/dev/"
end_define

begin_define
define|#
directive|define
name|_PATH_TZDIR
value|"/usr/lib/zoneinfo"
end_define

begin_define
define|#
directive|define
name|_PATH_TZFILE
value|"/usr/lib/zoneinfo/localtime"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATHS_H_ */
end_comment

end_unit

