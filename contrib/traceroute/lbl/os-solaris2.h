begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: os-solaris2.h,v 1.16 96/07/05 22:11:23 leres Locked $ (LBL)  */
end_comment

begin_comment
comment|/* Signal routines are this type */
end_comment

begin_define
define|#
directive|define
name|SIGRET
value|void
end_define

begin_comment
comment|/* Signal routines use "return SIGRETVAL;" */
end_comment

begin_define
define|#
directive|define
name|SIGRETVAL
end_define

begin_comment
comment|/* The wait() status variable is this type */
end_comment

begin_define
define|#
directive|define
name|WAITSTATUS
value|int
end_define

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|((int)(((unsigned)(x)>>8)&0377))
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|((int)((x)&0377))
end_define

begin_comment
comment|/* Prototypes missing in SunOS 5 */
end_comment

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_expand
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dn_skipname
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
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
name|getdtablesize
parameter_list|(
name|void
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
name|int
name|getpagesize
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
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iruserok
parameter_list|(
name|u_int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|utmp
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|login
parameter_list|(
name|struct
name|utmp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|logout
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|res_query
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_STDIO_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETLINEBUF
argument_list|)
end_if

begin_function_decl
name|int
name|setlinebuf
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
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
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
name|unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|utimes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Solaris signal compat */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sigmask
end_ifndef

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|m
parameter_list|)
value|(1<< ((m)-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|signal
end_ifndef

begin_define
define|#
directive|define
name|signal
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|sigset(s, f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Solaris random compat */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|srandom
end_ifndef

begin_define
define|#
directive|define
name|srandom
parameter_list|(
name|seed
parameter_list|)
value|srand48((long)seed)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|random
end_ifndef

begin_define
define|#
directive|define
name|random
parameter_list|()
value|lrand48()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CBREAK
end_ifndef

begin_define
define|#
directive|define
name|CBREAK
value|O_CBREAK
end_define

begin_define
define|#
directive|define
name|CRMOD
value|O_CRMOD
end_define

begin_define
define|#
directive|define
name|RAW
value|O_RAW
end_define

begin_define
define|#
directive|define
name|TBDELAY
value|O_TBDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIOCPKT_DATA
end_ifndef

begin_define
define|#
directive|define
name|TIOCPKT_DATA
value|0x00
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHREAD
value|0x01
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_FLUSHWRITE
value|0x02
end_define

begin_comment
comment|/* flush packet */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_STOP
value|0x04
end_define

begin_comment
comment|/* stop output */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_START
value|0x08
end_define

begin_comment
comment|/* start output */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_NOSTOP
value|0x10
end_define

begin_comment
comment|/* no more ^S, ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_DOSTOP
value|0x20
end_define

begin_comment
comment|/* now do ^S ^Q */
end_comment

begin_define
define|#
directive|define
name|TIOCPKT_IOCTL
value|0x40
end_define

begin_comment
comment|/* state change of pty driver */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISTXT
end_ifndef

begin_define
define|#
directive|define
name|S_ISTXT
value|S_ISVTX
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

