begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pppd.h - PPP daemon global declarations.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPPD_H__
end_ifndef

begin_define
define|#
directive|define
name|__PPPD_H__
end_define

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for MAXPATHLEN and BSD4_4, if defined */
end_comment

begin_define
define|#
directive|define
name|NUM_PPP
value|1
end_define

begin_comment
comment|/* One PPP interface supported (per process) */
end_comment

begin_comment
comment|/*  * Limits.  */
end_comment

begin_define
define|#
directive|define
name|MAXWORDLEN
value|1024
end_define

begin_comment
comment|/* max length of word in file (incl null) */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|1
end_define

begin_comment
comment|/* max # args to a command */
end_comment

begin_define
define|#
directive|define
name|MAXNAMELEN
value|256
end_define

begin_comment
comment|/* max length of hostname or name for auth */
end_comment

begin_define
define|#
directive|define
name|MAXSECRETLEN
value|256
end_define

begin_comment
comment|/* max length of password or secret */
end_comment

begin_comment
comment|/*  * Global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface unit number */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ifname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hostname */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|peername
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|outpacket_buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for outgoing packets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|phase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See values below */
end_comment

begin_comment
comment|/*  * Values for phase.  */
end_comment

begin_define
define|#
directive|define
name|PHASE_DEAD
value|0
end_define

begin_define
define|#
directive|define
name|PHASE_ESTABLISH
value|1
end_define

begin_define
define|#
directive|define
name|PHASE_AUTHENTICATE
value|2
end_define

begin_define
define|#
directive|define
name|PHASE_NETWORK
value|3
end_define

begin_define
define|#
directive|define
name|PHASE_TERMINATE
value|4
end_define

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_decl_stmt
name|void
name|quit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cleanup and exit */
end_comment

begin_decl_stmt
name|void
name|timeout
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look-alike of kernel's timeout() */
end_comment

begin_decl_stmt
name|void
name|untimeout
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look-alike of kernel's untimeout() */
end_comment

begin_decl_stmt
name|void
name|output
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a PPP packet */
end_comment

begin_decl_stmt
name|void
name|demuxprotrej
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Demultiplex a Protocol-Reject */
end_comment

begin_decl_stmt
name|int
name|check_passwd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check peer-supplied username/password */
end_comment

begin_decl_stmt
name|int
name|get_secret
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get "secret" for chap */
end_comment

begin_decl_stmt
name|u_long
name|GetMask
name|__P
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get netmask for address */
end_comment

begin_comment
comment|/*  * Inline versions of get/put char/short/long.  * Pointer is advanced; we assume that both arguments  * are lvalues and will already be in registers.  * cp MUST be u_char *.  */
end_comment

begin_define
define|#
directive|define
name|GETCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(c) = *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) (c); \ }
end_define

begin_define
define|#
directive|define
name|GETSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(s) = *(cp)++<< 8; \ 	(s) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) ((s)>> 8); \ 	*(cp)++ = (u_char) (s); \ }
end_define

begin_define
define|#
directive|define
name|GETLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(l) = *(cp)++<< 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) ((l)>> 24); \ 	*(cp)++ = (u_char) ((l)>> 16); \ 	*(cp)++ = (u_char) ((l)>> 8); \ 	*(cp)++ = (u_char) (l); \ }
end_define

begin_define
define|#
directive|define
name|INCPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) += (n))
end_define

begin_define
define|#
directive|define
name|DECPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) -= (n))
end_define

begin_comment
comment|/*  * System dependent definitions for user-level 4.3BSD UNIX implementation.  */
end_comment

begin_define
define|#
directive|define
name|DEMUXPROTREJ
parameter_list|(
name|u
parameter_list|,
name|p
parameter_list|)
value|demuxprotrej(u, p)
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|timeout((r), (f), (t))
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|untimeout((r), (f))
end_define

begin_define
define|#
directive|define
name|BCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|memcpy(d, s, l)
end_define

begin_define
define|#
directive|define
name|BZERO
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, 0, n)
end_define

begin_define
define|#
directive|define
name|EXIT
parameter_list|(
name|u
parameter_list|)
value|quit()
end_define

begin_define
define|#
directive|define
name|PRINTMSG
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|{ m[l] = '\0'; syslog(LOG_INFO, "Remote message: %s", m); }
end_define

begin_comment
comment|/*  * MAKEHEADER - Add Header fields to a packet.  */
end_comment

begin_define
define|#
directive|define
name|MAKEHEADER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|{ \     PUTCHAR(ALLSTATIONS, p); \     PUTCHAR(UI, p); \     PUTSHORT(t, p); }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGALL
end_ifdef

begin_define
define|#
directive|define
name|DEBUGMAIN
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGFSM
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGLCP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGPPP_IPCP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGPPP_PAP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGCHAP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_PPP
end_ifndef

begin_comment
comment|/* we use LOG_LOCAL2 for syslog by default */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUGMAIN
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGFSM
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGLCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGPPP_IPCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGPPP_PAP
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGPPP_CHAP
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_LOCAL2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_DAEMON
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
comment|/* LOG_PPP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGMAIN
end_ifdef

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGFSM
end_ifdef

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGLCP
end_ifdef

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGIPCP
end_ifdef

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGUPAP
end_ifdef

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGCHAP
end_ifdef

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun) || defined(SYSV) || defined(POSIX_SOURCE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b)? (a): (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b)? (a): (b))
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
comment|/* __PPP_H__ */
end_comment

end_unit

