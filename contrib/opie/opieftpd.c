begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* opieftpd.c: Main program for an FTP daemon.  %%% portions-copyright-cmetz-96 Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to these portions of the software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.  Portions of this software are Copyright 1995 by Randall Atkinson and Dan McDonald, All Rights Reserved. All Rights under this copyright are assigned to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and License Agreement applies to this software.  	History:  	Modified by cmetz for OPIE 2.4. Add id parameter to opielogwtmp. Use 		opiestrncpy(). Fix incorrect use of setproctitle(). 	Modified by cmetz for OPIE 2.32. Remove include of dirent.h here; it's 		done already (and conditionally) in opie_cfg.h. 	Modified by cmetz for OPIE 2.31. Merged in some 4.4BSD-Lite changes. 		Merged in a security fix to BSD-derived ftpds. 	Modified by cmetz for OPIE 2.3. Fixed the filename at the top. 		Moved LS_COMMAND here. 	Modified by cmetz for OPIE 2.2. Use FUNCTION definition et al.                 Removed useless strings (I don't think that removing the                 ucb copyright one is a problem -- please let me know if                 I'm wrong). Changed default CMASK to 077. Removed random                 comments. Use ANSI stdargs for reply/lreply if we can,                 added stdargs version of reply/lreply. Don't declare the                 tos variable unless IP_TOS defined. Include stdargs headers                 early. More headers ifdefed. Made everything static.                 Got rid of gethostname() call and use of hostname. Pared                 down status response for places where header files frequently                 cause trouble. Made logging of user logins (ala -l)                 non-optional. Moved reply()/lrepy(). Fixed some prototypes. 	Modified at NRL for OPIE 2.1. Added declaration of envp. Discard 	        result of opiechallenge (allows access control to work). 		Added patches for AIX. Symbol changes for autoconf.         Modified at NRL for OPIE 2.01. Changed password lookup handling                 to avoid problems with drain-bamaged shadow password packages.                 Properly handle internal state for anonymous FTP. Unlock                 user accounts properly if login fails because of /etc/shells.                 Make sure to close syslog by function to avoid problems with                 drain bamaged syslog implementations. 	Modified at NRL for OPIE 2.0. 	Originally from BSD Net/2.  	        There is some really, really ugly code in here.  $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1985, 1988, 1990 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_if
if|#
directive|if
name|HAVE_ANSISTDARG
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ANSISTDARG */
end_comment

begin_comment
comment|/*  * FTP server.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_PARAM_H */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* #include<sys/ioctl.h> */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_FCNTL_H */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_define
define|#
directive|define
name|FTP_NAMES
end_define

begin_include
include|#
directive|include
file|<arpa/ftp.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|HAVE_TIME_H
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TIME_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_PWD_H
end_if

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PWD_H */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_if
if|#
directive|if
name|HAVE_SHADOW_H
end_if

begin_include
include|#
directive|include
file|<shadow.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SHADOW_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_CRYPT_H
end_if

begin_include
include|#
directive|include
file|<crypt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CRYPT_H */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_UTSNAME_H
end_if

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYS_UTSNAME_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_include
include|#
directive|include
file|<sys/id.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IP_TOS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IPTOS_THROUGHPUT
end_ifndef

begin_undef
undef|#
directive|undef
name|IP_TOS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IPTOS_THROUGHPUT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPTOS_LOWDELAY
end_ifndef

begin_undef
undef|#
directive|undef
name|IP_TOS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IPTOS_LOWDELAY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IP_TOS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to home directory for glob */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ftpd_popen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftpd_pclose
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|restart_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sockaddr_in
name|ctrl_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sockaddr_in
name|data_source
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|data_dest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|his_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|sockaddr_in
name|pasv_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|errcatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|jmp_buf
name|urgcatch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logged_in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|timeout
init|=
literal|900
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timeout after 15 minutes of inactivity */
end_comment

begin_decl_stmt
name|int
name|maxtimeout
init|=
literal|7200
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't allow idle time to be set beyond 2 hours */
end_comment

begin_if
if|#
directive|if
name|DOANONYMOUS
end_if

begin_decl_stmt
specifier|static
name|int
name|guest
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOANONYMOUS */
end_comment

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|form
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|stru
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* avoid C keyword */
end_comment

begin_decl_stmt
specifier|static
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usedefault
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for data transfers */
end_comment

begin_decl_stmt
name|int
name|pdata
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for passive mode */
end_comment

begin_decl_stmt
specifier|static
name|int
name|transflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|off_t
name|file_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|off_t
name|byte_count
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|CMASK
argument_list|)
operator|||
name|CMASK
operator|==
literal|0
operator|)
end_if

begin_undef
undef|#
directive|undef
name|CMASK
end_undef

begin_define
define|#
directive|define
name|CMASK
value|077
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|defumask
init|=
name|CMASK
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default umask value */
end_comment

begin_decl_stmt
name|char
name|tmpline
index|[
literal|7
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|remotehost
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Timeout intervals for retrying connections  * to hosts that don't accept PORT cmds.  This  * is a kludge, but given the problems with TCP...  */
end_comment

begin_define
define|#
directive|define
name|SWAITMAX
value|90
end_define

begin_comment
comment|/* wait at most 90 seconds */
end_comment

begin_define
define|#
directive|define
name|SWAITINT
value|5
end_define

begin_comment
comment|/* interval between retries */
end_comment

begin_decl_stmt
specifier|static
name|int
name|swaitmax
init|=
name|SWAITMAX
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|swaitint
init|=
name|SWAITINT
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DOTITLE
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|Argv
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to argument vector */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|LastArgv
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of argv */
end_comment

begin_decl_stmt
specifier|static
name|char
name|proctitle
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial part of title */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOTITLE */
end_comment

begin_decl_stmt
specifier|static
name|int
name|af_pwok
init|=
literal|0
decl_stmt|,
name|pwok
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|opie
name|opiestate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOIDRET
name|perror_reply
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOIDRET
name|dologout
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getline
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOIDRET
name|upper
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|VOIDRET
name|lostconn
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|VOIDRET
name|myoob
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|getdatasock
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|dataconn
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|off_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|checkuser
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|VOIDRET
name|end_login
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|VOIDRET
name|send_data
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|FILE
operator|*
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|receive_data
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|gunique
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sgetsave
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opielogwtmp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fclose
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ANSISTDARG
end_ifdef

begin_decl_stmt
name|VOIDRET
name|reply
name|FUNCTION
argument_list|(
operator|(
name|stdarg
name|is
name|ANSI
name|only
operator|)
argument_list|,
name|int
name|n
name|AND
name|char
operator|*
name|fmt
name|AND
operator|...
argument_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d %s\r\n"
argument_list|,
name|n
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"<--- %d %s"
argument_list|,
name|n
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_ANSISTDARG */
end_comment

begin_decl_stmt
name|VOIDRET
name|reply
name|FUNCTION
argument_list|(
operator|(
name|n
operator|,
name|fmt
operator|,
name|p0
operator|,
name|p1
operator|,
name|p2
operator|,
name|p3
operator|,
name|p4
operator|,
name|p5
operator|)
argument_list|,
name|int
name|n
name|AND
name|char
operator|*
name|fmt
name|AND
name|int
name|p0
name|AND
name|int
name|p1
name|AND
name|int
name|p2
name|AND
name|int
name|p3
name|AND
name|int
name|p4
name|AND
name|int
name|p5
argument_list|)
block|{
name|printf
argument_list|(
literal|"%d "
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|fmt
argument_list|,
name|p0
argument_list|,
name|p1
argument_list|,
name|p2
argument_list|,
name|p3
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
block|{
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"<--- %d "
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
name|fmt
argument_list|,
name|p0
argument_list|,
name|p1
argument_list|,
name|p2
argument_list|,
name|p3
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ANSISTDARG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ANSISTDARG
end_ifdef

begin_decl_stmt
name|VOIDRET
name|lreply
name|FUNCTION
argument_list|(
operator|(
name|stdarg
name|is
name|ANSI
name|only
operator|)
argument_list|,
name|int
name|n
name|AND
name|char
operator|*
name|fmt
name|AND
operator|...
argument_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|char
name|buffer
index|[
literal|1024
index|]
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|buffer
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d- %s\r\n"
argument_list|,
name|n
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"<--- %d- %s"
argument_list|,
name|n
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_ANSISTDARG */
end_comment

begin_decl_stmt
name|VOIDRET
name|lreply
name|FUNCTION
argument_list|(
operator|(
name|n
operator|,
name|fmt
operator|,
name|p0
operator|,
name|p1
operator|,
name|p2
operator|,
name|p3
operator|,
name|p4
operator|,
name|p5
operator|)
argument_list|,
name|int
name|n
name|AND
name|char
operator|*
name|fmt
name|AND
name|int
name|p0
name|AND
name|int
name|p1
name|AND
name|int
name|p2
name|AND
name|int
name|p3
name|AND
name|int
name|p4
name|AND
name|int
name|p5
argument_list|)
block|{
name|printf
argument_list|(
literal|"%d- "
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|fmt
argument_list|,
name|p0
argument_list|,
name|p1
argument_list|,
name|p2
argument_list|,
name|p3
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
block|{
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"<--- %d- "
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
name|fmt
argument_list|,
name|p0
argument_list|,
name|p1
argument_list|,
name|p2
argument_list|,
name|p3
argument_list|,
name|p4
argument_list|,
name|p5
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ANSISTDARG */
end_comment

begin_decl_stmt
name|VOIDRET
name|enable_signalling
name|FUNCTION_NOARGS
block|{
name|signal
argument_list|(
name|SIGPIPE
argument_list|,
name|lostconn
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGURG
argument_list|,
name|myoob
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"signal: %m"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|VOIDRET
name|disable_signalling
name|FUNCTION_NOARGS
block|{
name|signal
argument_list|(
name|SIGPIPE
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGURG
argument_list|,
name|SIG_IGN
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"signal: %m"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|VOIDRET
name|lostconn
name|FUNCTION
argument_list|(
operator|(
name|input
operator|)
argument_list|,
name|int
name|input
argument_list|)
block|{
if|if
condition|(
name|debug
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"lost connection"
argument_list|)
expr_stmt|;
name|dologout
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|ttyline
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Helper function for sgetpwnam().  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sgetsave
name|FUNCTION
argument_list|(
operator|(
name|s
operator|)
argument_list|,
name|char
operator|*
name|s
argument_list|)
block|{
name|char
modifier|*
name|new
init|=
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|new
operator|==
name|NULL
condition|)
block|{
name|perror_reply
argument_list|(
literal|421
argument_list|,
literal|"Local resource failure: malloc"
argument_list|)
expr_stmt|;
name|dologout
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
name|strcpy
argument_list|(
name|new
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|new
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/*  * Save the result of a getpwnam.  Used for USER command, since  * the data returned must not be clobbered by any other command  * (e.g., globbing).  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|passwd
modifier|*
name|sgetpwnam
name|FUNCTION
argument_list|(
operator|(
name|name
operator|)
argument_list|,
name|char
operator|*
name|name
argument_list|)
block|{
specifier|static
name|struct
name|passwd
name|save
decl_stmt|;
specifier|register
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
if|#
directive|if
name|HAVE_SHADOW
name|struct
name|spwd
modifier|*
name|spwd
decl_stmt|;
endif|#
directive|endif
comment|/* HAVE_SHADOW */
if|if
condition|(
operator|(
name|p
operator|=
name|getpwnam
argument_list|(
name|name
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|p
operator|)
return|;
if|#
directive|if
name|HAVE_SHADOW
if|if
condition|(
operator|(
name|spwd
operator|=
name|getspnam
argument_list|(
name|name
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|endspent
argument_list|()
expr_stmt|;
name|p
operator|->
name|pw_passwd
operator|=
name|spwd
operator|->
name|sp_pwdp
expr_stmt|;
endif|#
directive|endif
comment|/* HAVE_SHADOW */
name|endpwent
argument_list|()
expr_stmt|;
if|if
condition|(
name|save
operator|.
name|pw_name
condition|)
block|{
name|free
argument_list|(
name|save
operator|.
name|pw_name
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|save
operator|.
name|pw_passwd
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|save
operator|.
name|pw_gecos
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|save
operator|.
name|pw_dir
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|save
operator|.
name|pw_shell
argument_list|)
expr_stmt|;
block|}
name|save
operator|=
operator|*
name|p
expr_stmt|;
name|save
operator|.
name|pw_name
operator|=
name|sgetsave
argument_list|(
name|p
operator|->
name|pw_name
argument_list|)
expr_stmt|;
name|save
operator|.
name|pw_passwd
operator|=
name|sgetsave
argument_list|(
name|p
operator|->
name|pw_passwd
argument_list|)
expr_stmt|;
name|save
operator|.
name|pw_gecos
operator|=
name|sgetsave
argument_list|(
name|p
operator|->
name|pw_gecos
argument_list|)
expr_stmt|;
name|save
operator|.
name|pw_dir
operator|=
name|sgetsave
argument_list|(
name|p
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
name|save
operator|.
name|pw_shell
operator|=
name|sgetsave
argument_list|(
name|p
operator|->
name|pw_shell
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|save
operator|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|login_attempts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of failed login attempts */
end_comment

begin_decl_stmt
name|int
name|askpasswd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* had user command, ask for passwd */
end_comment

begin_comment
comment|/*  * USER command.  * Sets global passwd pointer pw if named account exists and is acceptable;  * sets askpasswd if a PASS command is expected.  If logged in previously,  * need to reset state.  If name is "ftp" or "anonymous", the name is not in  * _PATH_FTPUSERS, and ftp account exists, set guest and pw, then just return.  * If account doesn't exist, ask for passwd anyway.  Otherwise, check user  * requesting login privileges.  Disallow anyone who does not have a standard  * shell as returned by getusershell().  Disallow anyone mentioned in the file  * _PATH_FTPUSERS to allow people such as root and uucp to be avoided.  */
end_comment

begin_decl_stmt
name|int
name|user
name|FUNCTION
argument_list|(
operator|(
name|name
operator|)
argument_list|,
name|char
operator|*
name|name
argument_list|)
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
name|char
modifier|*
name|shell
decl_stmt|;
if|if
condition|(
name|logged_in
condition|)
block|{
if|#
directive|if
name|DOANONYMOUS
if|if
condition|(
name|guest
condition|)
block|{
name|reply
argument_list|(
literal|530
argument_list|,
literal|"Can't change user from guest login."
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
comment|/* DOANONMOUS */
name|end_login
argument_list|()
expr_stmt|;
block|}
name|askpasswd
operator|=
literal|1
expr_stmt|;
if|#
directive|if
name|DOANONYMOUS
name|guest
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"ftp"
argument_list|)
operator|||
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"anonymous"
argument_list|)
condition|)
if|if
condition|(
operator|!
name|checkuser
argument_list|(
literal|"ftp"
argument_list|)
operator|&&
operator|!
name|checkuser
argument_list|(
literal|"anonymous"
argument_list|)
condition|)
if|if
condition|(
operator|(
name|pw
operator|=
name|sgetpwnam
argument_list|(
literal|"ftp"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|guest
operator|=
literal|1
expr_stmt|;
name|askpasswd
operator|=
literal|1
expr_stmt|;
name|reply
argument_list|(
literal|331
argument_list|,
literal|"Guest login ok, send your e-mail address as your password."
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_INFO
argument_list|,
literal|"Anonymous FTP connection made from host %s."
argument_list|,
name|remotehost
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* DOANONYMOUS */
if|if
condition|(
name|pw
operator|=
name|sgetpwnam
argument_list|(
name|name
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|shell
operator|=
name|pw
operator|->
name|pw_shell
operator|)
operator|==
name|NULL
operator|||
operator|*
name|shell
operator|==
literal|0
condition|)
name|shell
operator|=
name|_PATH_BSHELL
expr_stmt|;
while|while
condition|(
operator|(
name|cp
operator|=
name|getusershell
argument_list|()
operator|)
operator|!=
name|NULL
condition|)
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|cp
argument_list|,
name|shell
argument_list|)
condition|)
break|break;
name|endusershell
argument_list|()
expr_stmt|;
if|if
condition|(
name|cp
operator|==
name|NULL
operator|||
name|checkuser
argument_list|(
name|name
argument_list|)
operator|||
operator|(
operator|(
name|pw
operator|->
name|pw_passwd
index|[
literal|0
index|]
operator|==
literal|'*'
operator|)
operator|||
operator|(
name|pw
operator|->
name|pw_passwd
index|[
literal|0
index|]
operator|==
literal|'#'
operator|)
operator|)
condition|)
block|{
if|#
directive|if
name|DEBUG
if|if
condition|(
operator|!
name|cp
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"Couldn't find %s in the list of valid shells."
argument_list|,
name|pw
operator|->
name|pw_shell
argument_list|)
expr_stmt|;
if|if
condition|(
name|checkuser
argument_list|(
name|name
argument_list|)
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"checkuser failed - user in /etc/ftpusers?"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|pw
operator|->
name|pw_passwd
index|[
literal|0
index|]
operator|==
literal|'*'
operator|)
operator|||
operator|(
name|pw
operator|->
name|pw_passwd
index|[
literal|0
index|]
operator|==
literal|'#'
operator|)
operator|)
condition|)
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"Login disabled: pw_passwd == %s"
argument_list|,
name|pw
operator|->
name|pw_passwd
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
name|pw
operator|=
operator|(
expr|struct
name|passwd
operator|*
operator|)
name|NULL
expr_stmt|;
name|askpasswd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
block|{
name|char
name|prompt
index|[
name|OPIE_CHALLENGE_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|opiechallenge
argument_list|(
operator|&
name|opiestate
argument_list|,
name|name
argument_list|,
name|prompt
argument_list|)
expr_stmt|;
if|if
condition|(
name|askpasswd
operator|==
operator|-
literal|1
condition|)
block|{
name|syslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"Invalid FTP user name %s attempted from %s."
argument_list|,
name|name
argument_list|,
name|remotehost
argument_list|)
expr_stmt|;
name|pwok
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|pwok
operator|=
name|af_pwok
operator|&&
name|opiealways
argument_list|(
name|pw
operator|->
name|pw_dir
argument_list|)
expr_stmt|;
if|#
directive|if
name|NEW_PROMPTS
name|reply
argument_list|(
literal|331
argument_list|,
literal|"Response to %s %s for %s."
argument_list|,
argument|prompt
argument_list|,
else|#
directive|else
comment|/* NEW_PROMPTS */
argument|reply(
literal|331
argument|,
literal|"OTP response %s %s for %s."
argument|, prompt,
endif|#
directive|endif
comment|/* NEW_PROMPTS */
argument|pwok ?
literal|"requested"
argument|:
literal|"required"
argument|, name);   }
comment|/* Delay before reading passwd after first failed attempt to slow down      passwd-guessing programs. */
argument|if (login_attempts)     sleep((unsigned) login_attempts);    return
literal|0
argument|; }
comment|/*  * Check if a user is in the file _PATH_FTPUSERS  */
argument|static int checkuser FUNCTION((name), char *name) {   register FILE *fd;   register char *p;   char line[BUFSIZ];    if ((fd = fopen(_PATH_FTPUSERS,
literal|"r"
argument|)) != NULL) {     while (fgets(line, sizeof(line), fd) != NULL)       if ((p = strchr(line,
literal|'\n'
argument|)) != NULL) { 	*p =
literal|'\0'
argument|; 	if (line[
literal|0
argument|] ==
literal|'#'
argument|) 	  continue; 	if (!strcmp(line, name)) {           fclose(fd); 	  return (
literal|1
argument|);         }       }     fclose(fd);   }   return (
literal|0
argument|); }
comment|/*  * Terminate login as previous user, if any, resetting state;  * used when USER command is given or login fails.  */
argument|static VOIDRET end_login FUNCTION_NOARGS {   disable_signalling();   if (seteuid((uid_t)
literal|0
argument|))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   if (logged_in)     opielogwtmp(ttyline,
literal|""
argument|,
literal|""
argument|,
literal|"ftp"
argument|);   pw = NULL;   logged_in =
literal|0
argument|;
if|#
directive|if
name|DOANONYMOUS
argument|guest =
literal|0
argument|;
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|enable_signalling(); }  VOIDRET pass FUNCTION((passwd), char *passwd) {   int legit = askpasswd +
literal|1
argument_list|,
argument|i;    if (logged_in || askpasswd ==
literal|0
argument|) {     reply(
literal|503
argument|,
literal|"Login with USER first."
argument|);     return;   }   askpasswd =
literal|0
argument|;
if|#
directive|if
name|DOANONYMOUS
argument|if (!guest) {
comment|/* "ftp" is only account allowed no password */
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|i = opieverify(&opiestate, passwd);     if (legit&& i&& pwok)        i = strcmp(crypt(passwd, pw->pw_passwd), pw->pw_passwd);     if (!legit || i) {       reply(
literal|530
argument|,
literal|"Login incorrect."
argument|);       pw = NULL;       if (login_attempts++>=
literal|5
argument|) { 	syslog(LOG_WARNING,
literal|"Repeated login failures for user %s from %s"
argument|, 	       pw->pw_name, remotehost); 	exit(
literal|0
argument|);       }       return;     }
if|#
directive|if
name|DOANONYMOUS
argument|} else     if ((passwd[
literal|0
argument|]<=
literal|' '
argument|) ||  checkuser(passwd)) {       reply(
literal|530
argument|,
literal|"No identity, no service."
argument|);       syslog(LOG_DEBUG,
literal|"Bogus address: %s"
argument|, passwd);       exit(
literal|0
argument|);     }
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|login_attempts =
literal|0
argument|;
comment|/* this time successful */
argument|if (setegid((gid_t) pw->pw_gid)<
literal|0
argument|) {     reply(
literal|550
argument|,
literal|"Can't set gid."
argument|);     syslog(LOG_DEBUG,
literal|"gid = %d, errno = %s(%d)"
argument|, pw->pw_gid, strerror(errno), errno);     return;   }   initgroups(pw->pw_name, pw->pw_gid);
comment|/* open wtmp before chroot */
argument|sprintf(ttyline,
literal|"ftp%d"
argument|, getpid());   opielogwtmp(ttyline, pw->pw_name, remotehost,
literal|"ftp"
argument|);   logged_in =
literal|1
argument|;
if|#
directive|if
name|DOANONYMOUS
argument|if (guest) {
comment|/* We MUST do a chdir() after the chroot. Otherwise the old current        directory will be accessible as "." outside the new root! */
argument|if (chroot(pw->pw_dir)<
literal|0
argument||| chdir(
literal|"/"
argument|)<
literal|0
argument|) {       reply(
literal|550
argument|,
literal|"Can't set guest privileges."
argument|);       goto bad;     }   } else
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|if (chdir(pw->pw_dir)<
literal|0
argument|) {       if (chdir(
literal|"/"
argument|)<
literal|0
argument|) { 	reply(
literal|530
argument|,
literal|"User %s: can't change directory to %s."
argument|, 	      pw->pw_name, pw->pw_dir); 	goto bad;       } else 	lreply(
literal|230
argument|,
literal|"No directory! Logging in with home=/"
argument|);     }
comment|/* This patch was contributed by an OPIE user. We don't know what it    does, exactly. It may or may not work. */
ifdef|#
directive|ifdef
name|_AIX
argument|{        priv_t priv;        priv.pv_priv[
literal|0
argument|] =
literal|0
argument|;        priv.pv_priv[
literal|1
argument|] =
literal|0
argument|;        setgroups(NULL, NULL);        if (setpriv(PRIV_SET|PRIV_INHERITED|PRIV_EFFECTIVE|PRIV_BEQUEATH,&priv, sizeof(priv_t))<
literal|0
argument||| 	   setgidx(ID_REAL|ID_EFFECTIVE, (gid_t)pw->pw_gid)<
literal|0
argument|||            setuidx(ID_REAL|ID_EFFECTIVE, (uid_t)pw->pw_uid)<
literal|0
argument|||            seteuid((uid_t)pw->pw_uid)<
literal|0
argument|) {                reply(
literal|550
argument|,
literal|"Can't set uid (_AIX3)."
argument|);                goto bad;        }     }
else|#
directive|else
comment|/* _AIX */
argument|if (seteuid((uid_t) pw->pw_uid)<
literal|0
argument|) {     reply(
literal|550
argument|,
literal|"Can't set uid."
argument|);     goto bad;   }
endif|#
directive|endif
comment|/* _AIX */
comment|/*   * Display a login message, if it exists.   * N.B. reply(230,) must follow the message.   */
argument|{   FILE *fd;    if ((fd = fopen(_PATH_FTPLOGINMESG,
literal|"r"
argument|)) != NULL) {     char *cp
argument_list|,
argument|line[
literal|128
argument|];      while (fgets(line, sizeof(line), fd) != NULL) {       if ((cp = strchr(line,
literal|'\n'
argument|)) != NULL)         *cp =
literal|'\0'
argument|;       lreply(
literal|230
argument|,
literal|"%s"
argument|, line);     }     (void) fflush(stdout);     (void) fclose(fd);   }   }
if|#
directive|if
name|DOANONYMOUS
argument|if (guest) {     reply(
literal|230
argument|,
literal|"Guest login ok, access restrictions apply."
argument|);
if|#
directive|if
name|DOTITLE
argument|setproctitle(
literal|"%s: anonymous/%.*s"
argument|, remotehost,             sizeof(proctitle) - sizeof(remotehost) - sizeof(
literal|": anonymous/"
argument|), 	    passwd);
endif|#
directive|endif
comment|/* DOTITLE */
argument|syslog(LOG_NOTICE,
literal|"ANONYMOUS FTP login from %s with ID %s"
argument|,             remotehost, passwd);   } else
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|{     reply(
literal|230
argument|,
literal|"User %s logged in."
argument|, pw->pw_name);
if|#
directive|if
name|DOTITLE
argument|setproctitle(
literal|"%s: %s"
argument|, remotehost, pw->pw_name);
endif|#
directive|endif
comment|/* DOTITLE */
argument|syslog(LOG_INFO,
literal|"FTP login from %s with user name %s"
argument|, remotehost, pw->pw_name);   }   home = pw->pw_dir;
comment|/* home dir for globbing */
argument|umask(defumask);   return;  bad:
comment|/* Forget all about it... */
argument|end_login(); }  VOIDRET retrieve FUNCTION((cmd, name), char *cmd AND char *name) {   FILE *fin
argument_list|,
argument|*dout;   struct stat st;   int (*closefunc) ();    if (cmd ==
literal|0
argument|) {     fin = fopen(name,
literal|"r"
argument|)
argument_list|,
argument|closefunc = fclose;     st.st_size =
literal|0
argument|;   } else {     char line[BUFSIZ];      snprintf(line, sizeof(line), cmd, name);     name = line;     fin = ftpd_popen(line,
literal|"r"
argument|)
argument_list|,
argument|closefunc = ftpd_pclose;     st.st_size = -
literal|1
argument|;
if|#
directive|if
name|HAVE_ST_BLKSIZE
argument|st.st_blksize = BUFSIZ;
endif|#
directive|endif
comment|/* HAVE_ST_BLKSIZE */
argument|}   if (fin == NULL) {     if (errno !=
literal|0
argument|)       perror_reply(
literal|550
argument|, name);     return;   }   if (cmd ==
literal|0
argument|&&       (fstat(fileno(fin),&st)<
literal|0
argument||| (st.st_mode& S_IFMT) != S_IFREG)) {     reply(
literal|550
argument|,
literal|"%s: not a plain file."
argument|, name);     goto done;   }   if (restart_point) {     if (type == TYPE_A) {       register int i
argument_list|,
argument|n
argument_list|,
argument|c;        n = restart_point;       i =
literal|0
argument|;       while (i++< n) { 	if ((c = getc(fin)) == EOF) { 	  perror_reply(
literal|550
argument|, name); 	  goto done; 	} 	if (c ==
literal|'\n'
argument|) 	  i++;       }     } else       if (lseek(fileno(fin), restart_point, SEEK_SET
comment|/* L_SET */
argument|)<
literal|0
argument|) { 	perror_reply(
literal|550
argument|, name); 	goto done;       }   }   dout = dataconn(name, st.st_size,
literal|"w"
argument|);   if (dout == NULL)     goto done;
if|#
directive|if
name|HAVE_ST_BLKSIZE
argument|send_data(fin, dout, st.st_blksize);
else|#
directive|else
comment|/* HAVE_ST_BLKSIZE */
argument|send_data(fin, dout, BUFSIZ);
endif|#
directive|endif
comment|/* HAVE_ST_BLKSIZE */
argument|fclose(dout);   data = -
literal|1
argument|;   pdata = -
literal|1
argument|; done:   (*closefunc) (fin); }  VOIDRET store FUNCTION((name, mode, unique), char *name AND char *mode AND int unique) {   FILE *fout
argument_list|,
argument|*din;   struct stat st;   int (*closefunc) ();    if (unique&& stat(name,&st) ==
literal|0
argument|&&       (name = gunique(name)) == NULL)     return;    if (restart_point)     mode =
literal|"r+w"
argument|;   fout = fopen(name, mode);   closefunc = fclose;   if (fout == NULL) {     perror_reply(
literal|553
argument|, name);     return;   }   if (restart_point) {     if (type == TYPE_A) {       register int i
argument_list|,
argument|n
argument_list|,
argument|c;        n = restart_point;       i =
literal|0
argument|;       while (i++< n) { 	if ((c = getc(fout)) == EOF) { 	  perror_reply(
literal|550
argument|, name); 	  goto done; 	} 	if (c ==
literal|'\n'
argument|) 	  i++;       }
comment|/* We must do this seek to "current" position because we are changing          from reading to writing. */
argument|if (fseek(fout,
literal|0L
argument|, SEEK_CUR
comment|/* L_INCR */
argument|)<
literal|0
argument|) { 	perror_reply(
literal|550
argument|, name); 	goto done;       }     } else       if (lseek(fileno(fout), restart_point, SEEK_SET
comment|/* L_SET */
argument|)<
literal|0
argument|) { 	perror_reply(
literal|550
argument|, name); 	goto done;       }   }   din = dataconn(name, (off_t) -
literal|1
argument|,
literal|"r"
argument|);   if (din == NULL)     goto done;   if (receive_data(din, fout) ==
literal|0
argument|) {     if (unique)       reply(
literal|226
argument|,
literal|"Transfer complete (unique file name:%s)."
argument|, 	    name);     else       reply(
literal|226
argument|,
literal|"Transfer complete."
argument|);   }   fclose(din);   data = -
literal|1
argument|;   pdata = -
literal|1
argument|; done:   (*closefunc) (fout); }  static FILE *getdatasock FUNCTION((mode), char *mode) {   int s
argument_list|,
argument|on =
literal|1
argument_list|,
argument|tries;    if (data>=
literal|0
argument|)     return (fdopen(data, mode));   disable_signalling();   if (seteuid((uid_t)
literal|0
argument|))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   s = socket(AF_INET, SOCK_STREAM,
literal|0
argument|);   if (s<
literal|0
argument|)     goto bad;   if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, 		 (char *)&on, sizeof(on))<
literal|0
argument|)     goto bad;
comment|/* anchor socket to avoid multi-homing problems */
argument|data_source.sin_family = AF_INET;   data_source.sin_addr = ctrl_addr.sin_addr;   for (tries =
literal|1
argument|;; tries++) {     if (bind(s, (struct sockaddr *)& data_source, 	     sizeof(data_source))>=
literal|0
argument|)       break;     if (errno != EADDRINUSE || tries>
literal|10
argument|)       goto bad;     sleep(tries);   }   if (seteuid((uid_t) pw->pw_uid))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   enable_signalling();
ifdef|#
directive|ifdef
name|IP_TOS
argument|on = IPTOS_THROUGHPUT;   if (setsockopt(s, IPPROTO_IP, IP_TOS, (char *)&on, sizeof(int))<
literal|0
argument|)     syslog(LOG_WARNING,
literal|"setsockopt (IP_TOS): %m"
argument|);
endif|#
directive|endif
argument|return (fdopen(s, mode)); bad:   {   int t = errno;    if (seteuid((uid_t) pw->pw_uid))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   enable_signalling();   close(s);    errno = t;   }   return (NULL); }  static FILE *dataconn FUNCTION((name, size, mode), char *name AND off_t size AND char *mode) {   char sizebuf[
literal|32
argument|];   FILE *file;   int retry =
literal|0
argument|;
ifdef|#
directive|ifdef
name|IP_TOS
argument|int tos;
endif|#
directive|endif
comment|/* IP_TOS */
argument|file_size = size;   byte_count =
literal|0
argument|;   if (size != (off_t) -
literal|1
argument|)     snprintf(sizebuf, sizeof(sizebuf),
literal|" (%ld bytes)"
argument|, size);   else     strcpy(sizebuf,
literal|""
argument|);   if (pdata>=
literal|0
argument|) {     struct sockaddr_in from;     int s
argument_list|,
argument|fromlen = sizeof(from);      s = accept(pdata, (struct sockaddr *)& from,&fromlen);     if (s<
literal|0
argument|) {       reply(
literal|425
argument|,
literal|"Can't open data connection."
argument|);       close(pdata);       pdata = -
literal|1
argument|;       return (NULL);     }     close(pdata);     pdata = s;
ifdef|#
directive|ifdef
name|IP_TOS
argument|tos = IPTOS_LOWDELAY;     setsockopt(s, IPPROTO_IP, IP_TOS, (char *)&tos, 		      sizeof(int));
endif|#
directive|endif
argument|reply(
literal|150
argument|,
literal|"Opening %s mode data connection for %s%s."
argument|, 	  type == TYPE_A ?
literal|"ASCII"
argument|:
literal|"BINARY"
argument|, name, sizebuf);     return (fdopen(pdata, mode));   }   if (data>=
literal|0
argument|) {     reply(
literal|125
argument|,
literal|"Using existing data connection for %s%s."
argument|, 	  name, sizebuf);     usedefault =
literal|1
argument|;     return (fdopen(data, mode));   }   if (usedefault)     data_dest = his_addr;   usedefault =
literal|1
argument|;   file = getdatasock(mode);   if (file == NULL) {     reply(
literal|425
argument|,
literal|"Can't create data socket (%s,%d): %s."
argument|, 	  inet_ntoa(data_source.sin_addr), 	  ntohs(data_source.sin_port), strerror(errno));     return (NULL);   }   data = fileno(file);   while (connect(data, (struct sockaddr *)& data_dest, 		 sizeof(data_dest))<
literal|0
argument|) {     if (errno == EADDRINUSE&& retry< swaitmax) {       sleep((unsigned) swaitint);       retry += swaitint;       continue;     }     perror_reply(
literal|425
argument|,
literal|"Can't build data connection"
argument|);     fclose(file);     data = -
literal|1
argument|;     return (NULL);   }   reply(
literal|150
argument|,
literal|"Opening %s mode data connection for %s%s."
argument|, 	type == TYPE_A ?
literal|"ASCII"
argument|:
literal|"BINARY"
argument|, name, sizebuf);   return (file); }
comment|/*  * Tranfer the contents of "instr" to  * "outstr" peer using the appropriate  * encapsulation of the data subject  * to Mode, Structure, and Type.  *  * NB: Form isn't handled.  */
argument|static VOIDRET send_data FUNCTION((instr, outstr, blksize), FILE *instr AND FILE *outstr AND off_t blksize) {   register int c
argument_list|,
argument|cnt;   register char *buf;   int netfd
argument_list|,
argument|filefd;    transflag++;   if (setjmp(urgcatch)) {     transflag =
literal|0
argument|;     return;   }   switch (type) {    case TYPE_A:     while ((c = getc(instr)) != EOF) {       byte_count++;       if (c ==
literal|'\n'
argument|) { 	if (ferror(outstr)) 	  goto data_err; 	putc(
literal|'\r'
argument|, outstr);       }       putc(c, outstr);     }     fflush(outstr);     transflag =
literal|0
argument|;     if (ferror(instr))       goto file_err;     if (ferror(outstr))       goto data_err;     reply(
literal|226
argument|,
literal|"Transfer complete."
argument|);     return;    case TYPE_I:   case TYPE_L:     if ((buf = malloc((u_int) blksize)) == NULL) {       transflag =
literal|0
argument|;       perror_reply(
literal|451
argument|,
literal|"Local resource failure: malloc"
argument|);       return;     }     netfd = fileno(outstr);     filefd = fileno(instr);     while ((cnt = read(filefd, buf, (u_int) blksize))>
literal|0
argument|&& 	   write(netfd, buf, cnt) == cnt)       byte_count += cnt;     transflag =
literal|0
argument|;     free(buf);     if (cnt !=
literal|0
argument|) {       if (cnt<
literal|0
argument|) 	goto file_err;       goto data_err;     }     reply(
literal|226
argument|,
literal|"Transfer complete."
argument|);     return;   default:     transflag =
literal|0
argument|;     reply(
literal|550
argument|,
literal|"Unimplemented TYPE %d in send_data"
argument|, type);     return;   }  data_err:   transflag =
literal|0
argument|;   perror_reply(
literal|426
argument|,
literal|"Data connection"
argument|);   return;  file_err:   transflag =
literal|0
argument|;   perror_reply(
literal|551
argument|,
literal|"Error on input file"
argument|); }
comment|/*  * Transfer data from peer to  * "outstr" using the appropriate  * encapulation of the data subject  * to Mode, Structure, and Type.  *  * N.B.: Form isn't handled.  */
argument|static int receive_data FUNCTION((instr, outstr), FILE *instr AND FILE *outstr) {   register int c;   int cnt
argument_list|,
argument|bare_lfs =
literal|0
argument|;   char buf[BUFSIZ];    transflag++;   if (setjmp(urgcatch)) {     transflag =
literal|0
argument|;     return (-
literal|1
argument|);   }   switch (type) {    case TYPE_I:   case TYPE_L:     while ((cnt = read(fileno(instr), buf, sizeof buf))>
literal|0
argument|) {       if (write(fileno(outstr), buf, cnt) != cnt) 	goto file_err;       byte_count += cnt;     }     if (cnt<
literal|0
argument|)       goto data_err;     transflag =
literal|0
argument|;     return (
literal|0
argument|);    case TYPE_E:     reply(
literal|553
argument|,
literal|"TYPE E not implemented."
argument|);     transflag =
literal|0
argument|;     return (-
literal|1
argument|);    case TYPE_A:     while ((c = getc(instr)) != EOF) {       byte_count++;       if (c ==
literal|'\n'
argument|) 	bare_lfs++;       while (c ==
literal|'\r'
argument|) { 	if (ferror(outstr)) 	  goto data_err; 	if ((c = getc(instr)) !=
literal|'\n'
argument|) { 	  putc(
literal|'\r'
argument|, outstr); 	  if (c ==
literal|'\0'
argument||| c == EOF) 	    goto contin2; 	}       }       putc(c, outstr);   contin2:;     }     fflush(outstr);     if (ferror(instr))       goto data_err;     if (ferror(outstr))       goto file_err;     transflag =
literal|0
argument|;     if (bare_lfs) {       lreply(
literal|230
argument|,
literal|"WARNING! %d bare linefeeds received in ASCII mode"
argument|, bare_lfs);       printf(
literal|"   File may not have transferred correctly.\r\n"
argument|);     }     return (
literal|0
argument|);   default:     reply(
literal|550
argument|,
literal|"Unimplemented TYPE %d in receive_data"
argument|, type);     transflag =
literal|0
argument|;     return (-
literal|1
argument|);   }  data_err:   transflag =
literal|0
argument|;   perror_reply(
literal|426
argument|,
literal|"Data Connection"
argument|);   return (-
literal|1
argument|);  file_err:   transflag =
literal|0
argument|;   perror_reply(
literal|452
argument|,
literal|"Error writing file"
argument|);   return (-
literal|1
argument|); }  VOIDRET statfilecmd FUNCTION((filename), char *filename) {   char line[BUFSIZ];   FILE *fin;   int c;
if|#
directive|if
name|HAVE_LS_G_FLAG
argument|snprintf(line, sizeof(line),
literal|"%s %s"
argument|,
literal|"/bin/ls -lgA"
argument|, filename);
else|#
directive|else
comment|/* HAVE_LS_G_FLAG */
argument|snprintf(line, sizeof(line),
literal|"%s %s"
argument|,
literal|"/bin/ls -lA"
argument|, filename);
endif|#
directive|endif
comment|/* HAVE_LS_G_FLAG */
argument|fin = ftpd_popen(line,
literal|"r"
argument|);   lreply(
literal|211
argument|,
literal|"status of %s:"
argument|, filename);   while ((c = getc(fin)) != EOF) {     if (c ==
literal|'\n'
argument|) {       if (ferror(stdout)) { 	perror_reply(
literal|421
argument|,
literal|"control connection"
argument|); 	ftpd_pclose(fin); 	dologout(
literal|1
argument|);
comment|/* NOTREACHED */
argument|}       if (ferror(fin)) { 	perror_reply(
literal|551
argument|, filename); 	ftpd_pclose(fin); 	return;       }       putc(
literal|'\r'
argument|, stdout);     }     putc(c, stdout);   }   ftpd_pclose(fin);   reply(
literal|211
argument|,
literal|"End of Status"
argument|); }  VOIDRET statcmd FUNCTION_NOARGS {
comment|/* COMMENTED OUT STUFF BECAUSE THINGS BROKE ON SUNOS. */
argument|struct sockaddr_in *sin;   u_char *a
argument_list|,
argument|*p;    lreply(
literal|211
argument|,
literal|"FTP server status:"
argument|);   printf(
literal|"     \r\n"
argument|);   printf(
literal|"     Connected to %s"
argument|, remotehost);   if (!isdigit(remotehost[
literal|0
argument|]))     printf(
literal|" (%s)"
argument|, inet_ntoa(his_addr.sin_addr));   printf(
literal|"\r\n"
argument|);   if (logged_in) {
if|#
directive|if
name|DOANONYMOUS
argument|if (guest)       printf(
literal|"     Logged in anonymously\r\n"
argument|);     else
endif|#
directive|endif
comment|/* DOANONYMOUS */
argument|printf(
literal|"     Logged in as %s\r\n"
argument|, pw->pw_name);   } else     if (askpasswd)       printf(
literal|"     Waiting for password\r\n"
argument|);     else       printf(
literal|"     Waiting for user name\r\n"
argument|);   if (data != -
literal|1
argument|)     printf(
literal|"     Data connection open\r\n"
argument|);   else     if (pdata != -
literal|1
argument|) {       printf(
literal|"     in Passive mode"
argument|);       sin =&pasv_addr;       goto printaddr;     } else       if (usedefault ==
literal|0
argument|) { 	printf(
literal|"     PORT"
argument|); 	sin =&data_dest;     printaddr: 	a = (u_char *)& sin->sin_addr; 	p = (u_char *)& sin->sin_port;
define|#
directive|define
name|UC
parameter_list|(
name|b
parameter_list|)
value|(((int) b)& 0xff)
argument|printf(
literal|" (%d,%d,%d,%d,%d,%d)\r\n"
argument|, UC(a[
literal|0
argument|]), 	       UC(a[
literal|1
argument|]), UC(a[
literal|2
argument|]), UC(a[
literal|3
argument|]), UC(p[
literal|0
argument|]), UC(p[
literal|1
argument|]));
undef|#
directive|undef
name|UC
argument|} else 	printf(
literal|"     No data connection\r\n"
argument|);   reply(
literal|211
argument|,
literal|"End of status"
argument|); }  VOIDRET opiefatal FUNCTION((s), char *s) {   reply(
literal|451
argument|,
literal|"Error in server: %s\n"
argument|, s);   reply(
literal|221
argument|,
literal|"Closing connection due to server error."
argument|);   dologout(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}  static VOIDRET ack FUNCTION((s), char *s) {   reply(
literal|250
argument|,
literal|"%s command successful."
argument|, s); }  VOIDRET nack FUNCTION((s), char *s) {   reply(
literal|502
argument|,
literal|"%s command not implemented."
argument|, s); }  VOIDRET yyerror FUNCTION((s), char *s) {   char *cp;    if (cp = strchr(cbuf,
literal|'\n'
argument|))     *cp =
literal|'\0'
argument|;   reply(
literal|500
argument|,
literal|"'%s': command not understood."
argument|, cbuf); }  VOIDRET delete FUNCTION((name), char *name) {   struct stat st;    if (stat(name,&st)<
literal|0
argument|) {     perror_reply(
literal|550
argument|, name);     return;   }   if ((st.st_mode& S_IFMT) == S_IFDIR) {     if (rmdir(name)<
literal|0
argument|) {       perror_reply(
literal|550
argument|, name);       return;     }     goto done;   }   if (unlink(name)<
literal|0
argument|) {     perror_reply(
literal|550
argument|, name);     return;   } done:   ack(
literal|"DELE"
argument|); }  VOIDRET cwd FUNCTION((path), char *path) {   if (chdir(path)<
literal|0
argument|)     perror_reply(
literal|550
argument|, path);   else     ack(
literal|"CWD"
argument|); }  VOIDRET makedir FUNCTION((name), char *name) {   if (mkdir(name,
literal|0777
argument|)<
literal|0
argument|)     perror_reply(
literal|550
argument|, name);   else     reply(
literal|257
argument|,
literal|"MKD command successful."
argument|); }  VOIDRET removedir FUNCTION((name), char *name) {   if (rmdir(name)<
literal|0
argument|)     perror_reply(
literal|550
argument|, name);   else     ack(
literal|"RMD"
argument|); }  VOIDRET pwd FUNCTION_NOARGS {   char path[MAXPATHLEN +
literal|1
argument|];    if (getcwd(path, MAXPATHLEN) == (char *) NULL)     reply(
literal|550
argument|,
literal|"%s."
argument|, path);   else     reply(
literal|257
argument|,
literal|"\"%s\" is current directory."
argument|, path); }  char *renamefrom FUNCTION((name), char *name) {   struct stat st;    if (stat(name,&st)<
literal|0
argument|) {     perror_reply(
literal|550
argument|, name);     return ((char *)
literal|0
argument|);   }   reply(
literal|350
argument|,
literal|"File exists, ready for destination name"
argument|);   return (name); }  VOIDRET renamecmd FUNCTION((from, to), char *from AND char *to) {   if (rename(from, to)<
literal|0
argument|)     perror_reply(
literal|550
argument|,
literal|"rename"
argument|);   else     ack(
literal|"RNTO"
argument|); }  static VOIDRET dolog FUNCTION((sin), struct sockaddr_in *sin) {   struct hostent *hp = gethostbyaddr((char *)&sin->sin_addr, 				     sizeof(struct in_addr), AF_INET);   time_t t
argument_list|,
argument|time();    if (hp)     opiestrncpy(remotehost, hp->h_name, sizeof(remotehost));   else     opiestrncpy(remotehost, inet_ntoa(sin->sin_addr), sizeof(remotehost));
if|#
directive|if
name|DOTITLE
argument|setproctitle(
literal|"%s: connected"
argument|, remotehost);
endif|#
directive|endif
comment|/* DOTITLE */
argument|t = time((time_t *)
literal|0
argument|);   syslog(LOG_INFO,
literal|"connection from %s at %s"
argument|,     remotehost, ctime(&t)); }
comment|/*  * Record logout in wtmp file  * and exit with supplied status.  */
argument|VOIDRET dologout FUNCTION((status), int status) {   disable_signalling();   if (logged_in) {     if (seteuid((uid_t)
literal|0
argument|))       syslog(LOG_ERR,
literal|"Can't set euid"
argument|);     opielogwtmp(ttyline,
literal|""
argument|,
literal|""
argument|,
literal|"ftp"
argument|);   }
comment|/* beware of flushing buffers after a SIGPIPE */
argument|_exit(status); }  static VOIDRET myoob FUNCTION((input), int input) {   char *cp;
comment|/* only process if transfer occurring */
argument|if (!transflag)     return;   cp = tmpline;   if (getline(cp,
literal|7
argument|, stdin) == NULL) {     reply(
literal|221
argument|,
literal|"You could at least say goodbye."
argument|);     dologout(
literal|0
argument|);   }   upper(cp);   if (strcmp(cp,
literal|"ABOR\r\n"
argument|) ==
literal|0
argument|) {     tmpline[
literal|0
argument|] =
literal|'\0'
argument|;     reply(
literal|426
argument|,
literal|"Transfer aborted. Data connection closed."
argument|);     reply(
literal|226
argument|,
literal|"Abort successful"
argument|);     longjmp(urgcatch,
literal|1
argument|);   }   if (strcmp(cp,
literal|"STAT\r\n"
argument|) ==
literal|0
argument|) {     if (file_size != (off_t) -
literal|1
argument|)       reply(
literal|213
argument|,
literal|"Status: %lu of %lu bytes transferred"
argument|, 	    byte_count, file_size);     else       reply(
literal|213
argument|,
literal|"Status: %lu bytes transferred"
argument|, byte_count);   } }
comment|/*  * Note: a response of 425 is not mentioned as a possible response to  *      the PASV command in RFC959. However, it has been blessed as  *      a legitimate response by Jon Postel in a telephone conversation  *      with Rick Adams on 25 Jan 89.  */
argument|VOIDRET passive FUNCTION_NOARGS {   int len;   register char *p
argument_list|,
argument|*a;    pdata = socket(AF_INET, SOCK_STREAM,
literal|0
argument|);   if (pdata<
literal|0
argument|) {     perror_reply(
literal|425
argument|,
literal|"Can't open passive connection"
argument|);     return;   }   pasv_addr = ctrl_addr;   pasv_addr.sin_port =
literal|0
argument|;   if (seteuid((uid_t)
literal|0
argument|))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   if (bind(pdata, (struct sockaddr *)& pasv_addr, sizeof(pasv_addr))<
literal|0
argument|) {     seteuid((uid_t) pw->pw_uid);     goto pasv_error;   }   if (seteuid((uid_t) pw->pw_uid))     syslog(LOG_ERR,
literal|"Can't set euid"
argument|);   len = sizeof(pasv_addr);   if (getsockname(pdata, (struct sockaddr *)& pasv_addr,&len)<
literal|0
argument|)     goto pasv_error;   if (listen(pdata,
literal|1
argument|)<
literal|0
argument|)     goto pasv_error;   a = (char *)&pasv_addr.sin_addr;   p = (char *)&pasv_addr.sin_port;
define|#
directive|define
name|UC
parameter_list|(
name|b
parameter_list|)
value|(((int) b)& 0xff)
argument|reply(
literal|227
argument|,
literal|"Entering Passive Mode (%d,%d,%d,%d,%d,%d)"
argument|, UC(a[
literal|0
argument|]), 	UC(a[
literal|1
argument|]), UC(a[
literal|2
argument|]), UC(a[
literal|3
argument|]), UC(p[
literal|0
argument|]), UC(p[
literal|1
argument|]));   return;  pasv_error:   close(pdata);   pdata = -
literal|1
argument|;   perror_reply(
literal|425
argument|,
literal|"Can't open passive connection"
argument|);   return; }
comment|/*  * Generate unique name for file with basename "local".  * The file named "local" is already known to exist.  * Generates failure reply on error.  */
argument|static char *gunique FUNCTION((local), char *local) {   static char new[MAXPATHLEN+
literal|1
argument|];   struct stat st;   char *cp = strrchr(local,
literal|'/'
argument|);   int count =
literal|0
argument|;    if (cp)     *cp =
literal|'\0'
argument|;   if (stat(cp ? local :
literal|"."
argument|,&st)<
literal|0
argument|) {     perror_reply(
literal|553
argument|, cp ? local :
literal|"."
argument|);     return ((char *)
literal|0
argument|);   }   if (cp)     *cp =
literal|'/'
argument|;   strcpy(new, local);   cp = new + strlen(new);   *cp++ =
literal|'.'
argument|;   for (count =
literal|1
argument|; count<
literal|100
argument|; count++) {     snprintf(cp, sizeof(new) - (cp - new),
literal|"%d"
argument|, count);     if (stat(new,&st)<
literal|0
argument|)       return (new);   }   reply(
literal|452
argument|,
literal|"Unique file name cannot be created."
argument|);   return ((char *)
literal|0
argument|); }
comment|/*  * Format and send reply containing system error number.  */
argument|VOIDRET perror_reply FUNCTION((code, string), int code AND char *string) {   reply(code,
literal|"%s: %s."
argument|, string, strerror(errno)); }  static char *onefile[] = {
literal|""
argument_list|,
literal|0
argument|};  VOIDRET send_file_list FUNCTION((whichfiles), char *whichfiles) {   struct stat st;   DIR *dirp = NULL;   struct dirent *dir;   FILE *dout = NULL;   register char **dirlist
argument_list|,
argument|*dirname;   int simple =
literal|0
argument|;    if (strpbrk(whichfiles,
literal|"~{[*?"
argument|) != NULL) {     extern char **ftpglob()
argument_list|,
argument|*globerr;      globerr = NULL;     dirlist = ftpglob(whichfiles);     if (globerr != NULL) {       reply(
literal|550
argument|, globerr);       return;     } else       if (dirlist == NULL) { 	errno = ENOENT; 	perror_reply(
literal|550
argument|, whichfiles); 	return;       }   } else {     onefile[
literal|0
argument|] = whichfiles;     dirlist = onefile;     simple =
literal|1
argument|;   }    if (setjmp(urgcatch)) {     transflag =
literal|0
argument|;     return;   }   while (dirname = *dirlist++) {     if (stat(dirname,&st)<
literal|0
argument|) {
comment|/* If user typed "ls -l", etc, and the client used NLST, do what the          user meant. */
argument|if (dirname[
literal|0
argument|] ==
literal|'-'
argument|&& *dirlist == NULL&& 	  transflag ==
literal|0
argument|) { 	retrieve(
literal|"/bin/ls %s"
argument|, dirname); 	return;       }       perror_reply(
literal|550
argument|, whichfiles);       if (dout != NULL) { 	fclose(dout); 	transflag =
literal|0
argument|; 	data = -
literal|1
argument|; 	pdata = -
literal|1
argument|;       }       return;     }     if ((st.st_mode& S_IFMT) == S_IFREG) {       if (dout == NULL) { 	dout = dataconn(
literal|"file list"
argument|, (off_t) -
literal|1
argument|,
literal|"w"
argument|); 	if (dout == NULL) 	  return; 	transflag++;       }       fprintf(dout,
literal|"%s%s\n"
argument|, dirname, 	      type == TYPE_A ?
literal|"\r"
argument|:
literal|""
argument|);       byte_count += strlen(dirname) +
literal|1
argument|;       continue;     } else       if ((st.st_mode& S_IFMT) != S_IFDIR) 	continue;      if ((dirp = opendir(dirname)) == NULL)       continue;      while ((dir = readdir(dirp)) != NULL) {       char nbuf[MAXPATHLEN+
literal|1
argument|];        if (dir->d_name[
literal|0
argument|] ==
literal|'.'
argument|&& (strlen(dir->d_name) ==
literal|1
argument|)) 	continue;       if (dir->d_name[
literal|0
argument|] ==
literal|'.'
argument|&& dir->d_name[
literal|1
argument|] ==
literal|'.'
argument|&& 	  (strlen(dir->d_name) ==
literal|2
argument|)) 	continue;        snprintf(nbuf, sizeof(nbuf),
literal|"%s/%s"
argument|, dirname, dir->d_name);
comment|/* We have to do a stat to insure it's not a directory or special file. */
argument|if (simple || (stat(nbuf,&st) ==
literal|0
argument|&& 		     (st.st_mode& S_IFMT) == S_IFREG)) { 	if (dout == NULL) { 	  dout = dataconn(
literal|"file list"
argument|, (off_t) -
literal|1
argument|,
literal|"w"
argument|); 	  if (dout == NULL) 	    return; 	  transflag++; 	} 	if (nbuf[
literal|0
argument|] ==
literal|'.'
argument|&& nbuf[
literal|1
argument|] ==
literal|'/'
argument|) 	  fprintf(dout,
literal|"%s%s\n"
argument|,&nbuf[
literal|2
argument|], 		  type == TYPE_A ?
literal|"\r"
argument|:
literal|""
argument|); 	else 	  fprintf(dout,
literal|"%s%s\n"
argument|, nbuf, 		  type == TYPE_A ?
literal|"\r"
argument|:
literal|""
argument|); 	byte_count += strlen(nbuf) +
literal|1
argument|;       }     }     closedir(dirp);   }    if (dout == NULL)     reply(
literal|550
argument|,
literal|"No files found."
argument|);   else     if (ferror(dout) !=
literal|0
argument|)       perror_reply(
literal|550
argument|,
literal|"Data connection"
argument|);     else       reply(
literal|226
argument|,
literal|"Transfer complete."
argument|);    transflag =
literal|0
argument|;   if (dout != NULL)     fclose(dout);   data = -
literal|1
argument|;   pdata = -
literal|1
argument|; }
if|#
directive|if
name|DOTITLE
comment|/*  * clobber argv so ps will show what we're doing.  * (stolen from sendmail)  * warning, since this is usually started from inetd.conf, it  * often doesn't have much of an environment or arglist to overwrite.  */
argument|VOIDRET setproctitle FUNCTION((fmt, a, b, c), char *fmt AND int a AND int b AND int c) {   register char *p
argument_list|,
argument|*bp
argument_list|,
argument|ch;   register int i;   char buf[BUFSIZ];    snprintf(buf, sizeof(buf), fmt, a, b, c);
comment|/* make ps print our process name */
argument|p = Argv[
literal|0
argument|];   *p++ =
literal|'-'
argument|;    i = strlen(buf);   if (i> LastArgv - p -
literal|2
argument|) {     i = LastArgv - p -
literal|2
argument|;     buf[i] =
literal|'\0'
argument|;   }   bp = buf;   while (ch = *bp++)     if (ch !=
literal|'\n'
argument|&& ch !=
literal|'\r'
argument|)       *p++ = ch;   while (p< LastArgv)     *p++ =
literal|' '
argument|; }
endif|#
directive|endif
comment|/* DOTITLE */
argument|VOIDRET catchexit FUNCTION_NOARGS {   closelog(); }  int main FUNCTION((argc, argv, envp), int argc AND char *argv[] AND char *envp[]) {   int addrlen
argument_list|,
argument|on =
literal|1
argument|;   char *cp;
ifdef|#
directive|ifdef
name|IP_TOS
argument|int tos;
endif|#
directive|endif
comment|/* IP_TOS */
argument|{   int i;    for (i = sysconf(_SC_OPEN_MAX); i>
literal|2
argument|; i--)     close(i);   }
comment|/* LOG_NDELAY sets up the logging connection immediately, necessary for      anonymous ftp's that chroot and can't do it later. */
argument|openlog(
literal|"ftpd"
argument|, LOG_PID | LOG_NDELAY, LOG_DAEMON);   atexit(catchexit);   addrlen = sizeof(his_addr);   if (getpeername(
literal|0
argument|, (struct sockaddr *)& his_addr,&addrlen)<
literal|0
argument|) {     syslog(LOG_ERR,
literal|"getpeername (%s): %m"
argument|, argv[
literal|0
argument|]);     exit(
literal|1
argument|);   }   addrlen = sizeof(ctrl_addr);   if (getsockname(
literal|0
argument|, (struct sockaddr *)& ctrl_addr,&addrlen)<
literal|0
argument|) {     syslog(LOG_ERR,
literal|"getsockname (%s): %m"
argument|, argv[
literal|0
argument|]);     exit(
literal|1
argument|);   }
ifdef|#
directive|ifdef
name|IP_TOS
argument|tos = IPTOS_LOWDELAY;   if (setsockopt(
literal|0
argument|, IPPROTO_IP, IP_TOS, (char *)&tos, sizeof(int))<
literal|0
argument|)     syslog(LOG_WARNING,
literal|"setsockopt (IP_TOS): %m"
argument|);
endif|#
directive|endif
argument|data_source.sin_port = htons(ntohs(ctrl_addr.sin_port) -
literal|1
argument|);   debug =
literal|0
argument|;
if|#
directive|if
name|DOTITLE
comment|/* Save start and extent of argv for setproctitle. */
argument|Argv = argv;   while (*envp)     envp++;   LastArgv = envp[-
literal|1
argument|] + strlen(envp[-
literal|1
argument|]);
endif|#
directive|endif
comment|/* DOTITLE */
argument|argc--
argument_list|,
argument|argv++;   while (argc>
literal|0
argument|&& *argv[
literal|0
argument|] ==
literal|'-'
argument|) {     for (cp =&argv[
literal|0
argument|][
literal|1
argument|]; *cp; cp++)       switch (*cp) {        case
literal|'v'
argument|: 	debug =
literal|1
argument|; 	break;        case
literal|'d'
argument|: 	debug =
literal|1
argument|; 	break;        case
literal|'l'
argument|: 	break;        case
literal|'t'
argument|: 	timeout = atoi(++cp); 	if (maxtimeout< timeout) 	  maxtimeout = timeout; 	goto nextopt;        case
literal|'T'
argument|: 	maxtimeout = atoi(++cp); 	if (timeout> maxtimeout) 	  timeout = maxtimeout; 	goto nextopt;        case
literal|'u'
argument|: 	{ 	  int val =
literal|0
argument|;  	  while (*++cp&& *cp>=
literal|'0'
argument|&& *cp<=
literal|'9'
argument|) 	    val = val *
literal|8
argument|+ *cp -
literal|'0'
argument|; 	  if (*cp) 	    fprintf(stderr,
literal|"ftpd: Bad value for -u\n"
argument|); 	  else 	    defumask = val; 	  goto nextopt; 	}        default: 	fprintf(stderr,
literal|"ftpd: Unknown flag -%c ignored.\n"
argument|, 		*cp); 	break;       } nextopt:     argc--
argument_list|,
argument|argv++;   }   freopen(_PATH_DEVNULL,
literal|"w"
argument|, stderr);   signal(SIGCHLD, SIG_IGN);   enable_signalling();
comment|/* Try to handle urgent data inline */
ifdef|#
directive|ifdef
name|SO_OOBINLINE
argument|if (setsockopt(
literal|0
argument|, SOL_SOCKET, SO_OOBINLINE, (char *)&on, sizeof(on))<
literal|0
argument|)     syslog(LOG_ERR,
literal|"setsockopt: %m"
argument|);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|F_SETOWN
argument|if (fcntl(fileno(stdin), F_SETOWN, getpid()) == -
literal|1
argument|)     syslog(LOG_ERR,
literal|"fcntl F_SETOWN: %m"
argument|);
endif|#
directive|endif
argument|dolog(&his_addr);
comment|/* Set up default state */
argument|data = -
literal|1
argument|;   type = TYPE_A;   form = FORM_N;   stru = STRU_F;   mode = MODE_S;   tmpline[
literal|0
argument|] =
literal|'\0'
argument|;   af_pwok = opieaccessfile(remotehost);    {   FILE *fd;   char line[
literal|128
argument|];
comment|/* If logins are disabled, print out the message. */
argument|if ((fd = fopen(_PATH_NOLOGIN,
literal|"r"
argument|)) != NULL) {     while (fgets(line, sizeof(line), fd) != NULL) {       if ((cp = strchr(line,
literal|'\n'
argument|)) != NULL)         *cp =
literal|'\0'
argument|;       lreply(
literal|530
argument|,
literal|"%s"
argument|, line);     }     (void) fflush(stdout);     (void) fclose(fd);     reply(
literal|530
argument|,
literal|"System not available."
argument|);     exit(
literal|0
argument|);   }   if ((fd = fopen(_PATH_FTPWELCOME,
literal|"r"
argument|)) != NULL) {     while (fgets(line, sizeof(line), fd) != NULL) {       if ((cp = strchr(line,
literal|'\n'
argument|)) != NULL)         *cp =
literal|'\0'
argument|;       lreply(
literal|220
argument|,
literal|"%s"
argument|, line);     }     (void) fflush(stdout);     (void) fclose(fd);
comment|/* reply(220,) must follow */
argument|}   };    reply(
literal|220
argument|,
literal|"FTP server ready."
argument|);    setjmp(errcatch);   for (;;)     yyparse();
comment|/* NOTREACHED */
argument|return
literal|0
argument|; }
end_decl_stmt

end_unit

