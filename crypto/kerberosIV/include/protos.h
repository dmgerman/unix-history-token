begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- C -*-  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the Kungliga Tekniska  *      Högskolan and its contributors.  *   * 4. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Add here functions that don't have a prototype on your system.  *  * $Id: protos.H,v 1.43 1997/05/28 01:09:36 assar Exp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_CRYPT_PROTO
end_ifdef

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
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
name|NEED_STRTOK_R_PROTO
end_ifdef

begin_function_decl
name|char
modifier|*
name|strtok_r
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|,
name|char
modifier|*
modifier|*
name|lasts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTARG_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTERR_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTIND_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_OPTOPT_DECLARATION
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|optopt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|SunOS
operator|==
literal|4
end_if

begin_comment
comment|/* To get type fd_set */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* To get struct sockaddr, struct in_addr and struct hostent */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/* To get struct stat */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* To get struct utimbuf */
end_comment

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_function_decl
name|int
name|utime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|utimbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftruncate
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchmod
parameter_list|(
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchown
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|owner
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsync
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setreuid
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flock
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tp
parameter_list|,
name|struct
name|timezone
modifier|*
name|tzp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lstat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ioctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpriority
parameter_list|(
name|int
name|which
parameter_list|,
name|int
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpriority
parameter_list|(
name|int
name|which
parameter_list|,
name|int
name|who
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initgroups
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|basegid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ulimit
parameter_list|(
name|int
name|cmd
parameter_list|,
name|long
name|newlimit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vhangup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsetmask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setitimer
parameter_list|(
name|int
name|which
parameter_list|,
name|struct
name|itimerval
modifier|*
name|value
parameter_list|,
name|struct
name|itimerval
modifier|*
name|ovalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|munmap
parameter_list|(
name|caddr_t
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|socket
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bind
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsockname
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|accept
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|connect
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|listen
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recv
parameter_list|(
name|int
name|s
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recvfrom
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendto
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shutdown
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpeername
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsockopt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send
parameter_list|(
name|int
name|s
parameter_list|,
specifier|const
name|void
modifier|*
name|msg
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|strbuf
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|getmsg
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|strbuf
modifier|*
name|ctlptr
parameter_list|,
name|struct
name|strbuf
modifier|*
name|dataptr
parameter_list|,
name|int
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|inet_ntoa
parameter_list|(
name|struct
name|in_addr
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|inet_addr
parameter_list|(
specifier|const
name|char
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_expand
parameter_list|(
specifier|const
name|u_char
modifier|*
name|msg
parameter_list|,
specifier|const
name|u_char
modifier|*
name|eomorig
parameter_list|,
specifier|const
name|u_char
modifier|*
name|comp_dn
parameter_list|,
name|char
modifier|*
name|exp_dn
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_search
parameter_list|(
specifier|const
name|char
modifier|*
name|dname
parameter_list|,
name|int
name|class
parameter_list|,
name|int
name|type
parameter_list|,
name|u_char
modifier|*
name|answer
parameter_list|,
name|int
name|anslen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yp_get_default_domain
parameter_list|(
name|char
modifier|*
modifier|*
name|outdomain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
specifier|const
name|char
modifier|*
name|machine
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
name|pathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|(
name|char
modifier|*
name|b
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strcasecmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swab
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srandom
parameter_list|(
name|int
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openlog
parameter_list|(
specifier|const
name|char
modifier|*
name|ident
parameter_list|,
name|int
name|logopt
parameter_list|,
name|int
name|facility
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syslog
parameter_list|(
name|int
name|priority
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ttyslot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getpass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setpwent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endpwent
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SunOS4 */
end_comment

begin_if
if|#
directive|if
name|SunOS
operator|==
literal|5
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strtok_r
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpriority
parameter_list|(
name|int
name|which
parameter_list|,
name|id_t
name|who
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpriority
parameter_list|(
name|int
name|which
parameter_list|,
name|id_t
name|who
parameter_list|,
name|int
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tp
parameter_list|,
name|void
modifier|*
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_comment
comment|/* OSF/1 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* To get type fd_set */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
unit|int select(int, fd_set *, fd_set *, fd_set *, struct timeval *); int fsync(int fildes); int gethostname(char *address, int address_len); int setreuid(int ruid, int euid); int ioctl(int d, unsigned long request, void * arg);
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|flock
parameter_list|(
name|int
name|fildes
parameter_list|,
name|int
name|operation
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|htons
parameter_list|(
name|unsigned
name|short
name|hostshort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|htonl
parameter_list|(
name|unsigned
name|int
name|hostint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|ntohs
parameter_list|(
name|unsigned
name|short
name|netshort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|ntohl
parameter_list|(
name|unsigned
name|int
name|netint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
name|template
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|short
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport
parameter_list|(
name|int
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSF/1 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|char
modifier|*
name|ptsname
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|spwd
modifier|*
name|getspuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_comment
comment|/* AIX */
end_comment

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timezone
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|Tp
parameter_list|,
name|void
modifier|*
name|Tzp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_comment
comment|/* HP-UX */
end_comment

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vhangup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ptsname
parameter_list|(
name|int
name|fildes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utmpname
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
specifier|const
name|char
modifier|*
name|machine
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_comp
parameter_list|(
name|char
modifier|*
name|exp_dn
parameter_list|,
name|char
modifier|*
name|comp_dn
parameter_list|,
name|int
name|length
parameter_list|,
name|char
modifier|*
modifier|*
name|dnptrs
parameter_list|,
name|char
modifier|*
modifier|*
name|lastdnptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_query
parameter_list|(
name|char
modifier|*
name|dname
parameter_list|,
name|int
name|class
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|answer
parameter_list|,
name|int
name|anslen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_expand
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|eomorig
parameter_list|,
name|char
modifier|*
name|comp_dn
parameter_list|,
name|char
modifier|*
name|exp_dn
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_search
parameter_list|(
name|char
modifier|*
name|dname
parameter_list|,
name|int
name|class
parameter_list|,
name|int
name|type
parameter_list|,
name|unsigned
name|char
modifier|*
name|answer
parameter_list|,
name|int
name|anslen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/* Visual C++ 4.0 (Windows95/NT) */
end_comment

begin_function_decl
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

end_unit

