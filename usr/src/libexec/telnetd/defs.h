begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)defs.h	5.6 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Telnet server defines  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BSD
operator|>
literal|43
end_if

begin_define
define|#
directive|define
name|USE_TERMIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|NEWINIT
end_define

begin_define
define|#
directive|define
name|SYSV_TERMIO
end_define

begin_define
define|#
directive|define
name|NO_GETTYTAB
end_define

begin_define
define|#
directive|define
name|signal
value|sigset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TERMIO
end_ifdef

begin_define
define|#
directive|define
name|USE_TERMIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CRAY
end_ifndef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_DAEMON
end_ifndef

begin_define
define|#
directive|define
name|LOG_DAEMON
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_ODELAY
end_ifndef

begin_define
define|#
directive|define
name|LOG_ODELAY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USE_TERMIO
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termios.h>
end_include

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
name|CRAY
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY1
end_ifdef

begin_include
include|#
directive|include
file|<sys/pty.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FD_ZERO
end_ifndef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FD_ZERO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY1 */
end_comment

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRAY */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TCSIG
argument_list|)
operator|||
name|defined
argument_list|(
name|TIOCPKT_IOCTL
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINEMODE
end_define

begin_define
define|#
directive|define
name|KLUDGELINEMODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_fd_set
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|int
name|fds_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0] |= (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]&= ~(1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[0]& (1<<(n)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|((p)->fds_bits[0] = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FD_SET */
end_comment

begin_define
define|#
directive|define
name|OPT_NO
value|0
end_define

begin_comment
comment|/* won't do this option */
end_comment

begin_define
define|#
directive|define
name|OPT_YES
value|1
end_define

begin_comment
comment|/* will do this option */
end_comment

begin_define
define|#
directive|define
name|OPT_YES_BUT_ALWAYS_LOOK
value|2
end_define

begin_define
define|#
directive|define
name|OPT_NO_BUT_ALWAYS_LOOK
value|3
end_define

begin_comment
comment|/*  * I/O data buffers defines  */
end_comment

begin_define
define|#
directive|define
name|NETSLOP
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_undef
undef|#
directive|undef
name|BUFSIZ
end_undef

begin_define
define|#
directive|define
name|BUFSIZ
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NIACCUM
parameter_list|(
name|c
parameter_list|)
value|{   *netip++ = c; \ 			    ncc++; \ 			}
end_define

begin_comment
comment|/* clock manipulations */
end_comment

begin_define
define|#
directive|define
name|settimer
parameter_list|(
name|x
parameter_list|)
value|(clocks.x = ++clocks.system)
end_define

begin_define
define|#
directive|define
name|sequenceIs
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(clocks.x< clocks.y)
end_define

begin_comment
comment|/*  * Linemode support states, in decreasing order of importance  */
end_comment

begin_define
define|#
directive|define
name|REAL_LINEMODE
value|0x02
end_define

begin_define
define|#
directive|define
name|KLUDGE_LINEMODE
value|0x01
end_define

begin_define
define|#
directive|define
name|NO_LINEMODE
value|0x00
end_define

begin_comment
comment|/*  * Structures of information for each special character function.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|flag
decl_stmt|;
comment|/* the flags for this function */
name|cc_t
name|val
decl_stmt|;
comment|/* the value of the special character */
block|}
name|slcent
operator|,
typedef|*
name|Slcent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|slcent
name|defset
decl_stmt|;
comment|/* the default settings */
name|slcent
name|current
decl_stmt|;
comment|/* the current settings */
name|cc_t
modifier|*
name|sptr
decl_stmt|;
comment|/* a pointer to the char in */
comment|/* system data structures */
block|}
name|slcfun
operator|,
typedef|*
name|Slcfun
typedef|;
end_typedef

end_unit

