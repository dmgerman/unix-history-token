begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1995-1997 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sendmail.h	8.245 (Berkeley) 10/22/97  */
end_comment

begin_comment
comment|/* **  SENDMAIL.H -- Global definitions for sendmail. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_DEFINE
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|SmailSccsId
index|[]
init|=
literal|"@(#)sendmail.h	8.245		10/22/97"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  _DEFINE */
end_comment

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFINE */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EX_OK
end_ifdef

begin_undef
undef|#
directive|undef
name|EX_OK
end_undef

begin_comment
comment|/* for SVr4.2 SMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOG */
end_comment

begin_if
if|#
directive|if
name|NETINET
operator|||
name|NETUNIX
operator|||
name|NETISO
operator|||
name|NETNS
operator|||
name|NETX25
end_if

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NETUNIX
end_if

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NETINET
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NETISO
end_if

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NETNS
end_if

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NETX25
end_if

begin_include
include|#
directive|include
file|<netccitt/x25.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NAMED_BIND
end_if

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NOERROR
end_ifdef

begin_undef
undef|#
directive|undef
name|NOERROR
end_undef

begin_comment
comment|/* avoid<sys/streams.h> conflict */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Following are "sort of" configuration constants, but they should **  be pretty solid on most architectures today.  They have to be **  defined after<arpa/nameser.h> because some versions of that **  file also define them.  In all cases, we can't use sizeof because **  some systems (e.g., Crays) always treat everything as being at **  least 64 bits. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDRSZ
end_ifndef

begin_define
define|#
directive|define
name|INADDRSZ
value|4
end_define

begin_comment
comment|/* size of an IPv4 address in bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT16SZ
end_ifndef

begin_define
define|#
directive|define
name|INT16SZ
value|2
end_define

begin_comment
comment|/* size of a 16 bit integer in bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT32SZ
end_ifndef

begin_define
define|#
directive|define
name|INT32SZ
value|4
end_define

begin_comment
comment|/* size of a 32 bit integer in bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* forward references for prototypes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|envelope
name|ENVELOPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mailer
name|MAILER
typedef|;
end_typedef

begin_comment
comment|/* **  Data structure for bit maps. ** **	Each bit in this map can be referenced by an ascii character. **	This is 256 possible bits, or 32 8-bit bytes. */
end_comment

begin_define
define|#
directive|define
name|BITMAPBYTES
value|32
end_define

begin_comment
comment|/* number of bytes in a bit map */
end_comment

begin_define
define|#
directive|define
name|BYTEBITS
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_comment
comment|/* internal macros */
end_comment

begin_define
define|#
directive|define
name|_BITWORD
parameter_list|(
name|bit
parameter_list|)
value|((bit) / (BYTEBITS * sizeof (int)))
end_define

begin_define
define|#
directive|define
name|_BITBIT
parameter_list|(
name|bit
parameter_list|)
value|(1<< ((bit) % (BYTEBITS * sizeof (int))))
end_define

begin_typedef
typedef|typedef
name|int
name|BITMAP
index|[
name|BITMAPBYTES
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
typedef|;
end_typedef

begin_comment
comment|/* test bit number N */
end_comment

begin_define
define|#
directive|define
name|bitnset
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|((map)[_BITWORD(bit)]& _BITBIT(bit))
end_define

begin_comment
comment|/* set bit number N */
end_comment

begin_define
define|#
directive|define
name|setbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)] |= _BITBIT(bit)
end_define

begin_comment
comment|/* clear bit number N */
end_comment

begin_define
define|#
directive|define
name|clrbitn
parameter_list|(
name|bit
parameter_list|,
name|map
parameter_list|)
value|(map)[_BITWORD(bit)]&= ~_BITBIT(bit)
end_define

begin_comment
comment|/* clear an entire bit map */
end_comment

begin_define
define|#
directive|define
name|clrbitmap
parameter_list|(
name|map
parameter_list|)
value|bzero((char *) map, BITMAPBYTES)
end_define

begin_comment
comment|/* **  Utility macros */
end_comment

begin_comment
comment|/* return number of bytes left in a buffer */
end_comment

begin_define
define|#
directive|define
name|SPACELEFT
parameter_list|(
name|buf
parameter_list|,
name|ptr
parameter_list|)
value|(sizeof buf - ((ptr) - buf))
end_define

begin_escape
end_escape

begin_comment
comment|/* **  Address structure. **	Addresses are stored internally in this structure. */
end_comment

begin_struct
struct|struct
name|address
block|{
name|char
modifier|*
name|q_paddr
decl_stmt|;
comment|/* the printname for the address */
name|char
modifier|*
name|q_user
decl_stmt|;
comment|/* user name */
name|char
modifier|*
name|q_ruser
decl_stmt|;
comment|/* real user name, or NULL if q_user */
name|char
modifier|*
name|q_host
decl_stmt|;
comment|/* host name */
name|struct
name|mailer
modifier|*
name|q_mailer
decl_stmt|;
comment|/* mailer to use */
name|u_long
name|q_flags
decl_stmt|;
comment|/* status flags, see below */
name|uid_t
name|q_uid
decl_stmt|;
comment|/* user-id of receiver (if known) */
name|gid_t
name|q_gid
decl_stmt|;
comment|/* group-id of receiver (if known) */
name|char
modifier|*
name|q_home
decl_stmt|;
comment|/* home dir (local mailer only) */
name|char
modifier|*
name|q_fullname
decl_stmt|;
comment|/* full name if known */
name|struct
name|address
modifier|*
name|q_next
decl_stmt|;
comment|/* chain */
name|struct
name|address
modifier|*
name|q_alias
decl_stmt|;
comment|/* address this results from */
name|char
modifier|*
name|q_owner
decl_stmt|;
comment|/* owner of q_alias */
name|struct
name|address
modifier|*
name|q_tchain
decl_stmt|;
comment|/* temporary use chain */
name|char
modifier|*
name|q_orcpt
decl_stmt|;
comment|/* ORCPT parameter from RCPT TO: line */
name|char
modifier|*
name|q_status
decl_stmt|;
comment|/* status code for DSNs */
name|char
modifier|*
name|q_rstatus
decl_stmt|;
comment|/* remote status message for DSNs */
name|time_t
name|q_statdate
decl_stmt|;
comment|/* date of status messages */
name|char
modifier|*
name|q_statmta
decl_stmt|;
comment|/* MTA generating q_rstatus */
name|short
name|q_specificity
decl_stmt|;
comment|/* how "specific" this address is */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|address
name|ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QDONTSEND
value|0x00000001
end_define

begin_comment
comment|/* don't send to this address */
end_comment

begin_define
define|#
directive|define
name|QBADADDR
value|0x00000002
end_define

begin_comment
comment|/* this address is verified bad */
end_comment

begin_define
define|#
directive|define
name|QGOODUID
value|0x00000004
end_define

begin_comment
comment|/* the q_uid q_gid fields are good */
end_comment

begin_define
define|#
directive|define
name|QPRIMARY
value|0x00000008
end_define

begin_comment
comment|/* set from RCPT or argv */
end_comment

begin_define
define|#
directive|define
name|QQUEUEUP
value|0x00000010
end_define

begin_comment
comment|/* queue for later transmission */
end_comment

begin_define
define|#
directive|define
name|QSENT
value|0x00000020
end_define

begin_comment
comment|/* has been successfully delivered */
end_comment

begin_define
define|#
directive|define
name|QNOTREMOTE
value|0x00000040
end_define

begin_comment
comment|/* address not for remote forwarding */
end_comment

begin_define
define|#
directive|define
name|QSELFREF
value|0x00000080
end_define

begin_comment
comment|/* this address references itself */
end_comment

begin_define
define|#
directive|define
name|QVERIFIED
value|0x00000100
end_define

begin_comment
comment|/* verified, but not expanded */
end_comment

begin_define
define|#
directive|define
name|QBOGUSSHELL
value|0x00000400
end_define

begin_comment
comment|/* user has no valid shell listed */
end_comment

begin_define
define|#
directive|define
name|QUNSAFEADDR
value|0x00000800
end_define

begin_comment
comment|/* address aquired via unsafe path */
end_comment

begin_define
define|#
directive|define
name|QPINGONSUCCESS
value|0x00001000
end_define

begin_comment
comment|/* give return on successful delivery */
end_comment

begin_define
define|#
directive|define
name|QPINGONFAILURE
value|0x00002000
end_define

begin_comment
comment|/* give return on failure */
end_comment

begin_define
define|#
directive|define
name|QPINGONDELAY
value|0x00004000
end_define

begin_comment
comment|/* give return on message delay */
end_comment

begin_define
define|#
directive|define
name|QHASNOTIFY
value|0x00008000
end_define

begin_comment
comment|/* propogate notify parameter */
end_comment

begin_define
define|#
directive|define
name|QRELAYED
value|0x00010000
end_define

begin_comment
comment|/* DSN: relayed to non-DSN aware sys */
end_comment

begin_define
define|#
directive|define
name|QEXPANDED
value|0x00020000
end_define

begin_comment
comment|/* DSN: undergone list expansion */
end_comment

begin_define
define|#
directive|define
name|QDELIVERED
value|0x00040000
end_define

begin_comment
comment|/* DSN: successful final delivery */
end_comment

begin_define
define|#
directive|define
name|QDELAYED
value|0x00080000
end_define

begin_comment
comment|/* DSN: message delayed */
end_comment

begin_define
define|#
directive|define
name|QTHISPASS
value|0x40000000
end_define

begin_comment
comment|/* temp: address set this pass */
end_comment

begin_define
define|#
directive|define
name|QRCPTOK
value|0x80000000
end_define

begin_comment
comment|/* recipient() processed address */
end_comment

begin_define
define|#
directive|define
name|Q_PINGFLAGS
value|(QPINGONSUCCESS|QPINGONFAILURE|QPINGONDELAY)
end_define

begin_define
define|#
directive|define
name|NULLADDR
value|((ADDRESS *) NULL)
end_define

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|ADDRESS
modifier|*
name|parseaddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ADDRESS
modifier|*
name|buildaddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ADDRESS
modifier|*
name|recipient
name|__P
argument_list|(
operator|(
name|ADDRESS
operator|*
operator|,
name|ADDRESS
operator|*
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|prescan
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
index|[]
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rewrite
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|remotename
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MAILER
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ADDRESS
modifier|*
name|getctladdr
name|__P
argument_list|(
operator|(
name|ADDRESS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sameaddr
name|__P
argument_list|(
operator|(
name|ADDRESS
operator|*
operator|,
name|ADDRESS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|emptyaddr
name|__P
argument_list|(
operator|(
name|ADDRESS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printaddr
name|__P
argument_list|(
operator|(
name|ADDRESS
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cataddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sendtolist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|ADDRESS
operator|*
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Mailer definition structure. **	Every mailer known to the system is declared in this **	structure.  It defines the pathname of the mailer, some **	flags associated with it, and the argument vector to **	pass to it.  The flags are defined in conf.c ** **	The argument vector is expanded before actual use.  All **	words except the first are passed through the macro **	processor. */
end_comment

begin_struct
struct|struct
name|mailer
block|{
name|char
modifier|*
name|m_name
decl_stmt|;
comment|/* symbolic name of this mailer */
name|char
modifier|*
name|m_mailer
decl_stmt|;
comment|/* pathname of the mailer to use */
name|char
modifier|*
name|m_mtatype
decl_stmt|;
comment|/* type of this MTA */
name|char
modifier|*
name|m_addrtype
decl_stmt|;
comment|/* type for addresses */
name|char
modifier|*
name|m_diagtype
decl_stmt|;
comment|/* type for diagnostics */
name|BITMAP
name|m_flags
decl_stmt|;
comment|/* status flags, see below */
name|short
name|m_mno
decl_stmt|;
comment|/* mailer number internally */
name|short
name|m_nice
decl_stmt|;
comment|/* niceness to run at (mostly for prog) */
name|char
modifier|*
modifier|*
name|m_argv
decl_stmt|;
comment|/* template argument vector */
name|short
name|m_sh_rwset
decl_stmt|;
comment|/* rewrite set: sender header addresses */
name|short
name|m_se_rwset
decl_stmt|;
comment|/* rewrite set: sender envelope addresses */
name|short
name|m_rh_rwset
decl_stmt|;
comment|/* rewrite set: recipient header addresses */
name|short
name|m_re_rwset
decl_stmt|;
comment|/* rewrite set: recipient envelope addresses */
name|char
modifier|*
name|m_eol
decl_stmt|;
comment|/* end of line string */
name|long
name|m_maxsize
decl_stmt|;
comment|/* size limit on message to this mailer */
name|int
name|m_linelimit
decl_stmt|;
comment|/* max # characters per line */
name|char
modifier|*
name|m_execdir
decl_stmt|;
comment|/* directory to chdir to before execv */
name|uid_t
name|m_uid
decl_stmt|;
comment|/* UID to run as */
name|gid_t
name|m_gid
decl_stmt|;
comment|/* GID to run as */
name|char
modifier|*
name|m_defcharset
decl_stmt|;
comment|/* default character set */
block|}
struct|;
end_struct

begin_comment
comment|/* bits for m_flags */
end_comment

begin_define
define|#
directive|define
name|M_ESMTP
value|'a'
end_define

begin_comment
comment|/* run Extended SMTP protocol */
end_comment

begin_define
define|#
directive|define
name|M_ALIASABLE
value|'A'
end_define

begin_comment
comment|/* user can be LHS of an alias */
end_comment

begin_define
define|#
directive|define
name|M_BLANKEND
value|'b'
end_define

begin_comment
comment|/* ensure blank line at end of message */
end_comment

begin_define
define|#
directive|define
name|M_NOCOMMENT
value|'c'
end_define

begin_comment
comment|/* don't include comment part of address */
end_comment

begin_define
define|#
directive|define
name|M_CANONICAL
value|'C'
end_define

begin_comment
comment|/* make addresses canonical "u@dom" */
end_comment

begin_define
define|#
directive|define
name|M_NOBRACKET
value|'d'
end_define

begin_comment
comment|/* never angle bracket envelope route-addrs */
end_comment

begin_comment
comment|/*	'D'	   CF: include Date: */
end_comment

begin_define
define|#
directive|define
name|M_EXPENSIVE
value|'e'
end_define

begin_comment
comment|/* it costs to use this mailer.... */
end_comment

begin_define
define|#
directive|define
name|M_ESCFROM
value|'E'
end_define

begin_comment
comment|/* escape From lines to>From */
end_comment

begin_define
define|#
directive|define
name|M_FOPT
value|'f'
end_define

begin_comment
comment|/* mailer takes picky -f flag */
end_comment

begin_comment
comment|/*	'F'	   CF: include From: or Resent-From: */
end_comment

begin_define
define|#
directive|define
name|M_NO_NULL_FROM
value|'g'
end_define

begin_comment
comment|/* sender of errors should be $g */
end_comment

begin_define
define|#
directive|define
name|M_HST_UPPER
value|'h'
end_define

begin_comment
comment|/* preserve host case distinction */
end_comment

begin_define
define|#
directive|define
name|M_PREHEAD
value|'H'
end_define

begin_comment
comment|/* MAIL11V3: preview headers */
end_comment

begin_define
define|#
directive|define
name|M_UDBENVELOPE
value|'i'
end_define

begin_comment
comment|/* do udbsender rewriting on envelope */
end_comment

begin_define
define|#
directive|define
name|M_INTERNAL
value|'I'
end_define

begin_comment
comment|/* SMTP to another sendmail site */
end_comment

begin_define
define|#
directive|define
name|M_UDBRECIPIENT
value|'j'
end_define

begin_comment
comment|/* do udbsender rewriting on recipient lines */
end_comment

begin_define
define|#
directive|define
name|M_NOLOOPCHECK
value|'k'
end_define

begin_comment
comment|/* don't check for loops in HELO command */
end_comment

begin_define
define|#
directive|define
name|M_CHUNKING
value|'K'
end_define

begin_comment
comment|/* CHUNKING: reserved for future use */
end_comment

begin_define
define|#
directive|define
name|M_LOCALMAILER
value|'l'
end_define

begin_comment
comment|/* delivery is to this host */
end_comment

begin_define
define|#
directive|define
name|M_LIMITS
value|'L'
end_define

begin_comment
comment|/* must enforce SMTP line limits */
end_comment

begin_define
define|#
directive|define
name|M_MUSER
value|'m'
end_define

begin_comment
comment|/* can handle multiple users at once */
end_comment

begin_comment
comment|/*	'M'	   CF: include Message-Id: */
end_comment

begin_define
define|#
directive|define
name|M_NHDR
value|'n'
end_define

begin_comment
comment|/* don't insert From line */
end_comment

begin_define
define|#
directive|define
name|M_MANYSTATUS
value|'N'
end_define

begin_comment
comment|/* MAIL11V3: DATA returns multi-status */
end_comment

begin_define
define|#
directive|define
name|M_RUNASRCPT
value|'o'
end_define

begin_comment
comment|/* always run mailer as recipient */
end_comment

begin_define
define|#
directive|define
name|M_FROMPATH
value|'p'
end_define

begin_comment
comment|/* use reverse-path in MAIL FROM: */
end_comment

begin_comment
comment|/*	'P'	   CF: include Return-Path: */
end_comment

begin_define
define|#
directive|define
name|M_VRFY250
value|'q'
end_define

begin_comment
comment|/* VRFY command returns 250 instead of 252 */
end_comment

begin_define
define|#
directive|define
name|M_ROPT
value|'r'
end_define

begin_comment
comment|/* mailer takes picky -r flag */
end_comment

begin_define
define|#
directive|define
name|M_SECURE_PORT
value|'R'
end_define

begin_comment
comment|/* try to send on a reserved TCP port */
end_comment

begin_define
define|#
directive|define
name|M_STRIPQ
value|'s'
end_define

begin_comment
comment|/* strip quote chars from user/host */
end_comment

begin_define
define|#
directive|define
name|M_SPECIFIC_UID
value|'S'
end_define

begin_comment
comment|/* run as specific uid/gid */
end_comment

begin_define
define|#
directive|define
name|M_USR_UPPER
value|'u'
end_define

begin_comment
comment|/* preserve user case distinction */
end_comment

begin_define
define|#
directive|define
name|M_UGLYUUCP
value|'U'
end_define

begin_comment
comment|/* this wants an ugly UUCP from line */
end_comment

begin_define
define|#
directive|define
name|M_CONTENT_LEN
value|'v'
end_define

begin_comment
comment|/* add Content-Length: header (SVr4) */
end_comment

begin_comment
comment|/*	'V'	   UIUC: !-relativize all addresses */
end_comment

begin_define
define|#
directive|define
name|M_HASPWENT
value|'w'
end_define

begin_comment
comment|/* check for /etc/passwd entry */
end_comment

begin_comment
comment|/*	'x'	   CF: include Full-Name: */
end_comment

begin_define
define|#
directive|define
name|M_XDOT
value|'X'
end_define

begin_comment
comment|/* use hidden-dot algorithm */
end_comment

begin_define
define|#
directive|define
name|M_LMTP
value|'z'
end_define

begin_comment
comment|/* run Local Mail Transport Protocol */
end_comment

begin_define
define|#
directive|define
name|M_NOMX
value|'0'
end_define

begin_comment
comment|/* turn off MX lookups */
end_comment

begin_define
define|#
directive|define
name|M_NONULLS
value|'1'
end_define

begin_comment
comment|/* don't send null bytes */
end_comment

begin_define
define|#
directive|define
name|M_EBCDIC
value|'3'
end_define

begin_comment
comment|/* extend Q-P encoding for EBCDIC */
end_comment

begin_define
define|#
directive|define
name|M_TRYRULESET5
value|'5'
end_define

begin_comment
comment|/* use ruleset 5 after local aliasing */
end_comment

begin_define
define|#
directive|define
name|M_7BITHDRS
value|'6'
end_define

begin_comment
comment|/* strip headers to 7 bits even in 8 bit path */
end_comment

begin_define
define|#
directive|define
name|M_7BITS
value|'7'
end_define

begin_comment
comment|/* use 7-bit path */
end_comment

begin_define
define|#
directive|define
name|M_8BITS
value|'8'
end_define

begin_comment
comment|/* force "just send 8" behaviour */
end_comment

begin_define
define|#
directive|define
name|M_MAKE8BIT
value|'9'
end_define

begin_comment
comment|/* convert 7 -> 8 bit if appropriate */
end_comment

begin_define
define|#
directive|define
name|M_CHECKINCLUDE
value|':'
end_define

begin_comment
comment|/* check for :include: files */
end_comment

begin_define
define|#
directive|define
name|M_CHECKPROG
value|'|'
end_define

begin_comment
comment|/* check for |program addresses */
end_comment

begin_define
define|#
directive|define
name|M_CHECKFILE
value|'/'
end_define

begin_comment
comment|/* check for /file addresses */
end_comment

begin_define
define|#
directive|define
name|M_CHECKUDB
value|'@'
end_define

begin_comment
comment|/* user can be user database key */
end_comment

begin_define
define|#
directive|define
name|M_CHECKHDIR
value|'~'
end_define

begin_comment
comment|/* SGI: check for valid home directory */
end_comment

begin_decl_stmt
name|EXTERN
name|MAILER
modifier|*
name|Mailer
index|[
name|MAXMAILERS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|MAILER
modifier|*
name|LocalMailer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to local mailer */
end_comment

begin_decl_stmt
name|EXTERN
name|MAILER
modifier|*
name|ProgMailer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to program mailer */
end_comment

begin_decl_stmt
name|EXTERN
name|MAILER
modifier|*
name|FileMailer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to *file* mailer */
end_comment

begin_decl_stmt
name|EXTERN
name|MAILER
modifier|*
name|InclMailer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to *include* mailer */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Information about currently open connections to mailers, or to **  hosts that we have looked up recently. */
end_comment

begin_define
define|#
directive|define
name|MCI
value|struct mailer_con_info
end_define

begin_macro
name|MCI
end_macro

begin_block
block|{
name|short
name|mci_flags
decl_stmt|;
comment|/* flag bits, see below */
name|short
name|mci_errno
decl_stmt|;
comment|/* error number on last connection */
name|short
name|mci_herrno
decl_stmt|;
comment|/* h_errno from last DNS lookup */
name|short
name|mci_exitstat
decl_stmt|;
comment|/* exit status from last connection */
name|short
name|mci_state
decl_stmt|;
comment|/* SMTP state */
name|long
name|mci_maxsize
decl_stmt|;
comment|/* max size this server will accept */
name|FILE
modifier|*
name|mci_in
decl_stmt|;
comment|/* input side of connection */
name|FILE
modifier|*
name|mci_out
decl_stmt|;
comment|/* output side of connection */
name|pid_t
name|mci_pid
decl_stmt|;
comment|/* process id of subordinate proc */
name|char
modifier|*
name|mci_phase
decl_stmt|;
comment|/* SMTP phase string */
name|struct
name|mailer
modifier|*
name|mci_mailer
decl_stmt|;
comment|/* ptr to the mailer for this conn */
name|char
modifier|*
name|mci_host
decl_stmt|;
comment|/* host name */
name|char
modifier|*
name|mci_status
decl_stmt|;
comment|/* DSN status to be copied to addrs */
name|char
modifier|*
name|mci_rstatus
decl_stmt|;
comment|/* SMTP status to be copied to addrs */
name|time_t
name|mci_lastuse
decl_stmt|;
comment|/* last usage time */
name|FILE
modifier|*
name|mci_statfile
decl_stmt|;
comment|/* long term status file */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* flag bits */
end_comment

begin_define
define|#
directive|define
name|MCIF_VALID
value|0x0001
end_define

begin_comment
comment|/* this entry is valid */
end_comment

begin_define
define|#
directive|define
name|MCIF_TEMP
value|0x0002
end_define

begin_comment
comment|/* don't cache this connection */
end_comment

begin_define
define|#
directive|define
name|MCIF_CACHED
value|0x0004
end_define

begin_comment
comment|/* currently in open cache */
end_comment

begin_define
define|#
directive|define
name|MCIF_ESMTP
value|0x0008
end_define

begin_comment
comment|/* this host speaks ESMTP */
end_comment

begin_define
define|#
directive|define
name|MCIF_EXPN
value|0x0010
end_define

begin_comment
comment|/* EXPN command supported */
end_comment

begin_define
define|#
directive|define
name|MCIF_SIZE
value|0x0020
end_define

begin_comment
comment|/* SIZE option supported */
end_comment

begin_define
define|#
directive|define
name|MCIF_8BITMIME
value|0x0040
end_define

begin_comment
comment|/* BODY=8BITMIME supported */
end_comment

begin_define
define|#
directive|define
name|MCIF_7BIT
value|0x0080
end_define

begin_comment
comment|/* strip this message to 7 bits */
end_comment

begin_define
define|#
directive|define
name|MCIF_MULTSTAT
value|0x0100
end_define

begin_comment
comment|/* MAIL11V3: handles MULT status */
end_comment

begin_define
define|#
directive|define
name|MCIF_INHEADER
value|0x0200
end_define

begin_comment
comment|/* currently outputing header */
end_comment

begin_define
define|#
directive|define
name|MCIF_CVT8TO7
value|0x0400
end_define

begin_comment
comment|/* convert from 8 to 7 bits */
end_comment

begin_define
define|#
directive|define
name|MCIF_DSN
value|0x0800
end_define

begin_comment
comment|/* DSN extension supported */
end_comment

begin_define
define|#
directive|define
name|MCIF_8BITOK
value|0x1000
end_define

begin_comment
comment|/* OK to send 8 bit characters */
end_comment

begin_define
define|#
directive|define
name|MCIF_CVT7TO8
value|0x2000
end_define

begin_comment
comment|/* convert from 7 to 8 bits */
end_comment

begin_define
define|#
directive|define
name|MCIF_INMIME
value|0x4000
end_define

begin_comment
comment|/* currently reading MIME header */
end_comment

begin_comment
comment|/* states */
end_comment

begin_define
define|#
directive|define
name|MCIS_CLOSED
value|0
end_define

begin_comment
comment|/* no traffic on this connection */
end_comment

begin_define
define|#
directive|define
name|MCIS_OPENING
value|1
end_define

begin_comment
comment|/* sending initial protocol */
end_comment

begin_define
define|#
directive|define
name|MCIS_OPEN
value|2
end_define

begin_comment
comment|/* open, initial protocol sent */
end_comment

begin_define
define|#
directive|define
name|MCIS_ACTIVE
value|3
end_define

begin_comment
comment|/* message being sent */
end_comment

begin_define
define|#
directive|define
name|MCIS_QUITING
value|4
end_define

begin_comment
comment|/* running quit protocol */
end_comment

begin_define
define|#
directive|define
name|MCIS_SSD
value|5
end_define

begin_comment
comment|/* service shutting down */
end_comment

begin_define
define|#
directive|define
name|MCIS_ERROR
value|6
end_define

begin_comment
comment|/* I/O error on connection */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|MCI
modifier|*
name|mci_get
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MAILER
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_cache
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_flush
name|__P
argument_list|(
operator|(
name|bool
operator|,
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_dump
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_dump_all
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MCI
modifier|*
modifier|*
name|mci_scan
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mci_traverse_persistent
name|__P
argument_list|(
operator|(
name|int
argument_list|()
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
name|mci_print_persistent
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
name|mci_purge_persistent
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
name|mci_lock_host
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_unlock_host
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mci_lock_host_statfile
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_store_persistent
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mci_read_persistent
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Header structure. **	This structure is used internally to store header items. */
end_comment

begin_struct
struct|struct
name|header
block|{
name|char
modifier|*
name|h_field
decl_stmt|;
comment|/* the name of the field */
name|char
modifier|*
name|h_value
decl_stmt|;
comment|/* the value of that field */
name|struct
name|header
modifier|*
name|h_link
decl_stmt|;
comment|/* the next header */
name|u_short
name|h_flags
decl_stmt|;
comment|/* status bits, see below */
name|BITMAP
name|h_mflags
decl_stmt|;
comment|/* m_flags bits needed */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|header
name|HDR
typedef|;
end_typedef

begin_comment
comment|/* **  Header information structure. **	Defined in conf.c, this struct declares the header fields **	that have some magic meaning. */
end_comment

begin_struct
struct|struct
name|hdrinfo
block|{
name|char
modifier|*
name|hi_field
decl_stmt|;
comment|/* the name of the field */
name|u_short
name|hi_flags
decl_stmt|;
comment|/* status bits, see below */
name|char
modifier|*
name|hi_ruleset
decl_stmt|;
comment|/* validity check ruleset */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hdrinfo
name|HdrInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bits for h_flags and hi_flags */
end_comment

begin_define
define|#
directive|define
name|H_EOH
value|0x0001
end_define

begin_comment
comment|/* this field terminates header */
end_comment

begin_define
define|#
directive|define
name|H_RCPT
value|0x0002
end_define

begin_comment
comment|/* contains recipient addresses */
end_comment

begin_define
define|#
directive|define
name|H_DEFAULT
value|0x0004
end_define

begin_comment
comment|/* if another value is found, drop this */
end_comment

begin_define
define|#
directive|define
name|H_RESENT
value|0x0008
end_define

begin_comment
comment|/* this address is a "Resent-..." address */
end_comment

begin_define
define|#
directive|define
name|H_CHECK
value|0x0010
end_define

begin_comment
comment|/* check h_mflags against m_flags */
end_comment

begin_define
define|#
directive|define
name|H_ACHECK
value|0x0020
end_define

begin_comment
comment|/* ditto, but always (not just default) */
end_comment

begin_define
define|#
directive|define
name|H_FORCE
value|0x0040
end_define

begin_comment
comment|/* force this field, even if default */
end_comment

begin_define
define|#
directive|define
name|H_TRACE
value|0x0080
end_define

begin_comment
comment|/* this field contains trace information */
end_comment

begin_define
define|#
directive|define
name|H_FROM
value|0x0100
end_define

begin_comment
comment|/* this is a from-type field */
end_comment

begin_define
define|#
directive|define
name|H_VALID
value|0x0200
end_define

begin_comment
comment|/* this field has a validated value */
end_comment

begin_define
define|#
directive|define
name|H_RECEIPTTO
value|0x0400
end_define

begin_comment
comment|/* this field has return receipt info */
end_comment

begin_define
define|#
directive|define
name|H_ERRORSTO
value|0x0800
end_define

begin_comment
comment|/* this field has error address info */
end_comment

begin_define
define|#
directive|define
name|H_CTE
value|0x1000
end_define

begin_comment
comment|/* this field is a content-transfer-encoding */
end_comment

begin_define
define|#
directive|define
name|H_CTYPE
value|0x2000
end_define

begin_comment
comment|/* this is a content-type field */
end_comment

begin_define
define|#
directive|define
name|H_BCC
value|0x4000
end_define

begin_comment
comment|/* Bcc: header: strip value or delete */
end_comment

begin_define
define|#
directive|define
name|H_ENCODABLE
value|0x8000
end_define

begin_comment
comment|/* field can be RFC 1522 encoded */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|addheader
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|HDR
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hvalue
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|HDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|commaize
name|__P
argument_list|(
operator|(
name|HDR
operator|*
operator|,
name|char
operator|*
operator|,
name|bool
operator|,
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|put_vanilla_header
name|__P
argument_list|(
operator|(
name|HDR
operator|*
operator|,
name|char
operator|*
operator|,
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|eatheader
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|chompheader
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|,
name|HDR
operator|*
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Envelope structure. **	This structure defines the message itself.  There is usually **	only one of these -- for the message that we originally read **	and which is our primary interest -- but other envelopes can **	be generated during processing.  For example, error messages **	will have their own envelope. */
end_comment

begin_struct
struct|struct
name|envelope
block|{
name|HDR
modifier|*
name|e_header
decl_stmt|;
comment|/* head of header list */
name|long
name|e_msgpriority
decl_stmt|;
comment|/* adjusted priority of this message */
name|time_t
name|e_ctime
decl_stmt|;
comment|/* time message appeared in the queue */
name|char
modifier|*
name|e_to
decl_stmt|;
comment|/* the target person */
name|ADDRESS
name|e_from
decl_stmt|;
comment|/* the person it is from */
name|char
modifier|*
name|e_sender
decl_stmt|;
comment|/* e_from.q_paddr w comments stripped */
name|char
modifier|*
modifier|*
name|e_fromdomain
decl_stmt|;
comment|/* the domain part of the sender */
name|ADDRESS
modifier|*
name|e_sendqueue
decl_stmt|;
comment|/* list of message recipients */
name|ADDRESS
modifier|*
name|e_errorqueue
decl_stmt|;
comment|/* the queue for error responses */
name|long
name|e_msgsize
decl_stmt|;
comment|/* size of the message in bytes */
name|long
name|e_flags
decl_stmt|;
comment|/* flags, see below */
name|int
name|e_nrcpts
decl_stmt|;
comment|/* number of recipients */
name|short
name|e_class
decl_stmt|;
comment|/* msg class (priority, junk, etc.) */
name|short
name|e_hopcount
decl_stmt|;
comment|/* number of times processed */
name|short
name|e_nsent
decl_stmt|;
comment|/* number of sends since checkpoint */
name|short
name|e_sendmode
decl_stmt|;
comment|/* message send mode */
name|short
name|e_errormode
decl_stmt|;
comment|/* error return mode */
name|short
name|e_timeoutclass
decl_stmt|;
comment|/* message timeout class */
name|void
argument_list|(
argument|*e_puthdr
argument_list|)
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|HDR
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* function to put header of message */
name|void
argument_list|(
argument|*e_putbody
argument_list|)
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* function to put body of message */
name|struct
name|envelope
modifier|*
name|e_parent
decl_stmt|;
comment|/* the message this one encloses */
name|struct
name|envelope
modifier|*
name|e_sibling
decl_stmt|;
comment|/* the next envelope of interest */
name|char
modifier|*
name|e_bodytype
decl_stmt|;
comment|/* type of message body */
name|FILE
modifier|*
name|e_dfp
decl_stmt|;
comment|/* temporary file */
name|char
modifier|*
name|e_id
decl_stmt|;
comment|/* code for this entry in queue */
name|FILE
modifier|*
name|e_xfp
decl_stmt|;
comment|/* transcript file */
name|FILE
modifier|*
name|e_lockfp
decl_stmt|;
comment|/* the lock file for this message */
name|char
modifier|*
name|e_message
decl_stmt|;
comment|/* error message */
name|char
modifier|*
name|e_statmsg
decl_stmt|;
comment|/* stat msg (changes per delivery) */
name|char
modifier|*
name|e_msgboundary
decl_stmt|;
comment|/* MIME-style message part boundary */
name|char
modifier|*
name|e_origrcpt
decl_stmt|;
comment|/* original recipient (one only) */
name|char
modifier|*
name|e_envid
decl_stmt|;
comment|/* envelope id from MAIL FROM: line */
name|char
modifier|*
name|e_status
decl_stmt|;
comment|/* DSN status for this message */
name|time_t
name|e_dtime
decl_stmt|;
comment|/* time of last delivery attempt */
name|int
name|e_ntries
decl_stmt|;
comment|/* number of delivery attempts */
name|dev_t
name|e_dfdev
decl_stmt|;
comment|/* df file's device, for crash recov */
name|ino_t
name|e_dfino
decl_stmt|;
comment|/* df file's ino, for crash recovery */
name|char
modifier|*
name|e_macro
index|[
literal|256
index|]
decl_stmt|;
comment|/* macro definitions */
block|}
struct|;
end_struct

begin_comment
comment|/* values for e_flags */
end_comment

begin_define
define|#
directive|define
name|EF_OLDSTYLE
value|0x0000001
end_define

begin_comment
comment|/* use spaces (not commas) in hdrs */
end_comment

begin_define
define|#
directive|define
name|EF_INQUEUE
value|0x0000002
end_define

begin_comment
comment|/* this message is fully queued */
end_comment

begin_define
define|#
directive|define
name|EF_NO_BODY_RETN
value|0x0000004
end_define

begin_comment
comment|/* omit message body on error */
end_comment

begin_define
define|#
directive|define
name|EF_CLRQUEUE
value|0x0000008
end_define

begin_comment
comment|/* disk copy is no longer needed */
end_comment

begin_define
define|#
directive|define
name|EF_SENDRECEIPT
value|0x0000010
end_define

begin_comment
comment|/* send a return receipt */
end_comment

begin_define
define|#
directive|define
name|EF_FATALERRS
value|0x0000020
end_define

begin_comment
comment|/* fatal errors occured */
end_comment

begin_define
define|#
directive|define
name|EF_DELETE_BCC
value|0x0000040
end_define

begin_comment
comment|/* delete Bcc: headers entirely */
end_comment

begin_define
define|#
directive|define
name|EF_RESPONSE
value|0x0000080
end_define

begin_comment
comment|/* this is an error or return receipt */
end_comment

begin_define
define|#
directive|define
name|EF_RESENT
value|0x0000100
end_define

begin_comment
comment|/* this message is being forwarded */
end_comment

begin_define
define|#
directive|define
name|EF_VRFYONLY
value|0x0000200
end_define

begin_comment
comment|/* verify only (don't expand aliases) */
end_comment

begin_define
define|#
directive|define
name|EF_WARNING
value|0x0000400
end_define

begin_comment
comment|/* warning message has been sent */
end_comment

begin_define
define|#
directive|define
name|EF_QUEUERUN
value|0x0000800
end_define

begin_comment
comment|/* this envelope is from queue */
end_comment

begin_define
define|#
directive|define
name|EF_GLOBALERRS
value|0x0001000
end_define

begin_comment
comment|/* treat errors as global */
end_comment

begin_define
define|#
directive|define
name|EF_PM_NOTIFY
value|0x0002000
end_define

begin_comment
comment|/* send return mail to postmaster */
end_comment

begin_define
define|#
directive|define
name|EF_METOO
value|0x0004000
end_define

begin_comment
comment|/* send to me too */
end_comment

begin_define
define|#
directive|define
name|EF_LOGSENDER
value|0x0008000
end_define

begin_comment
comment|/* need to log the sender */
end_comment

begin_define
define|#
directive|define
name|EF_NORECEIPT
value|0x0010000
end_define

begin_comment
comment|/* suppress all return-receipts */
end_comment

begin_define
define|#
directive|define
name|EF_HAS8BIT
value|0x0020000
end_define

begin_comment
comment|/* at least one 8-bit char in body */
end_comment

begin_define
define|#
directive|define
name|EF_NL_NOT_EOL
value|0x0040000
end_define

begin_comment
comment|/* don't accept raw NL as EOLine */
end_comment

begin_define
define|#
directive|define
name|EF_CRLF_NOT_EOL
value|0x0080000
end_define

begin_comment
comment|/* don't accept CR-LF as EOLine */
end_comment

begin_define
define|#
directive|define
name|EF_RET_PARAM
value|0x0100000
end_define

begin_comment
comment|/* RCPT command had RET argument */
end_comment

begin_define
define|#
directive|define
name|EF_HAS_DF
value|0x0200000
end_define

begin_comment
comment|/* set when df file is instantiated */
end_comment

begin_define
define|#
directive|define
name|EF_IS_MIME
value|0x0400000
end_define

begin_comment
comment|/* really is a MIME message */
end_comment

begin_define
define|#
directive|define
name|EF_DONT_MIME
value|0x0800000
end_define

begin_comment
comment|/* never MIME this message */
end_comment

begin_decl_stmt
name|EXTERN
name|ENVELOPE
modifier|*
name|CurEnv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* envelope currently being processed */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|ENVELOPE
modifier|*
name|newenvelope
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dropenvelope
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearenvelope
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|putheader
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|HDR
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|putbody
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Message priority classes. ** **	The message class is read directly from the Priority: header **	field in the message. ** **	CurEnv->e_msgpriority is the number of bytes in the message plus **	the creation time (so that jobs ``tend'' to be ordered correctly), **	adjusted by the message class, the number of recipients, and the **	amount of time the message has been sitting around.  This number **	is used to order the queue.  Higher values mean LOWER priority. ** **	Each priority class point is worth WkClassFact priority points; **	each recipient is worth WkRecipFact priority points.  Each time **	we reprocess a message the priority is adjusted by WkTimeFact. **	WkTimeFact should normally decrease the priority so that jobs **	that have historically failed will be run later; thanks go to **	Jay Lepreau at Utah for pointing out the error in my thinking. ** **	The "class" is this number, unadjusted by the age or size of **	this message.  Classes with negative representations will have **	error messages thrown away if they are not local. */
end_comment

begin_struct
struct|struct
name|priority
block|{
name|char
modifier|*
name|pri_name
decl_stmt|;
comment|/* external name of priority */
name|int
name|pri_val
decl_stmt|;
comment|/* internal value for same */
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|priority
name|Priorities
index|[
name|MAXPRIORITIES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|NumPriorities
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into Priorities */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Rewrite rules. */
end_comment

begin_struct
struct|struct
name|rewrite
block|{
name|char
modifier|*
modifier|*
name|r_lhs
decl_stmt|;
comment|/* pattern match */
name|char
modifier|*
modifier|*
name|r_rhs
decl_stmt|;
comment|/* substitution value */
name|struct
name|rewrite
modifier|*
name|r_next
decl_stmt|;
comment|/* next in chain */
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|rewrite
modifier|*
name|RewriteRules
index|[
name|MAXRWSETS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Special characters in rewriting rules. **	These are used internally only. **	The COND* rules are actually used in macros rather than in **		rewriting rules, but are given here because they **		cannot conflict. */
end_comment

begin_comment
comment|/* left hand side items */
end_comment

begin_define
define|#
directive|define
name|MATCHZANY
value|((u_char)0220)
end_define

begin_comment
comment|/* match zero or more tokens */
end_comment

begin_define
define|#
directive|define
name|MATCHANY
value|((u_char)0221)
end_define

begin_comment
comment|/* match one or more tokens */
end_comment

begin_define
define|#
directive|define
name|MATCHONE
value|((u_char)0222)
end_define

begin_comment
comment|/* match exactly one token */
end_comment

begin_define
define|#
directive|define
name|MATCHCLASS
value|((u_char)0223)
end_define

begin_comment
comment|/* match one token in a class */
end_comment

begin_define
define|#
directive|define
name|MATCHNCLASS
value|((u_char)0224)
end_define

begin_comment
comment|/* match anything not in class */
end_comment

begin_define
define|#
directive|define
name|MATCHREPL
value|((u_char)0225)
end_define

begin_comment
comment|/* replacement on RHS for above */
end_comment

begin_comment
comment|/* right hand side items */
end_comment

begin_define
define|#
directive|define
name|CANONNET
value|((u_char)0226)
end_define

begin_comment
comment|/* canonical net, next token */
end_comment

begin_define
define|#
directive|define
name|CANONHOST
value|((u_char)0227)
end_define

begin_comment
comment|/* canonical host, next token */
end_comment

begin_define
define|#
directive|define
name|CANONUSER
value|((u_char)0230)
end_define

begin_comment
comment|/* canonical user, next N tokens */
end_comment

begin_define
define|#
directive|define
name|CALLSUBR
value|((u_char)0231)
end_define

begin_comment
comment|/* call another rewriting set */
end_comment

begin_comment
comment|/* conditionals in macros */
end_comment

begin_define
define|#
directive|define
name|CONDIF
value|((u_char)0232)
end_define

begin_comment
comment|/* conditional if-then */
end_comment

begin_define
define|#
directive|define
name|CONDELSE
value|((u_char)0233)
end_define

begin_comment
comment|/* conditional else */
end_comment

begin_define
define|#
directive|define
name|CONDFI
value|((u_char)0234)
end_define

begin_comment
comment|/* conditional fi */
end_comment

begin_comment
comment|/* bracket characters for host name lookup */
end_comment

begin_define
define|#
directive|define
name|HOSTBEGIN
value|((u_char)0235)
end_define

begin_comment
comment|/* hostname lookup begin */
end_comment

begin_define
define|#
directive|define
name|HOSTEND
value|((u_char)0236)
end_define

begin_comment
comment|/* hostname lookup end */
end_comment

begin_comment
comment|/* bracket characters for generalized lookup */
end_comment

begin_define
define|#
directive|define
name|LOOKUPBEGIN
value|((u_char)0205)
end_define

begin_comment
comment|/* generalized lookup begin */
end_comment

begin_define
define|#
directive|define
name|LOOKUPEND
value|((u_char)0206)
end_define

begin_comment
comment|/* generalized lookup end */
end_comment

begin_comment
comment|/* macro substitution character */
end_comment

begin_define
define|#
directive|define
name|MACROEXPAND
value|((u_char)0201)
end_define

begin_comment
comment|/* macro expansion */
end_comment

begin_define
define|#
directive|define
name|MACRODEXPAND
value|((u_char)0202)
end_define

begin_comment
comment|/* deferred macro expansion */
end_comment

begin_comment
comment|/* to make the code clearer */
end_comment

begin_define
define|#
directive|define
name|MATCHZERO
value|CANONHOST
end_define

begin_comment
comment|/* external<==> internal mapping table */
end_comment

begin_struct
struct|struct
name|metamac
block|{
name|char
name|metaname
decl_stmt|;
comment|/* external code (after $) */
name|u_char
name|metaval
decl_stmt|;
comment|/* internal code (as above) */
block|}
struct|;
end_struct

begin_comment
comment|/* values for macros with external names only */
end_comment

begin_define
define|#
directive|define
name|MID_OPMODE
value|0202
end_define

begin_comment
comment|/* operation mode */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|define
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|macvalue
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|macname
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|macid
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Name canonification short circuit. ** **	If the name server for a host is down, the process of trying to **	canonify the name can hang.  This is similar to (but alas, not **	identical to) looking up the name for delivery.  This stab type **	caches the result of the name server lookup so we don't hang **	multiple times. */
end_comment

begin_define
define|#
directive|define
name|NAMECANON
value|struct _namecanon
end_define

begin_macro
name|NAMECANON
end_macro

begin_block
block|{
name|short
name|nc_errno
decl_stmt|;
comment|/* cached errno */
name|short
name|nc_herrno
decl_stmt|;
comment|/* cached h_errno */
name|short
name|nc_stat
decl_stmt|;
comment|/* cached exit status code */
name|short
name|nc_flags
decl_stmt|;
comment|/* flag bits */
name|char
modifier|*
name|nc_cname
decl_stmt|;
comment|/* the canonical name */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* values for nc_flags */
end_comment

begin_define
define|#
directive|define
name|NCF_VALID
value|0x0001
end_define

begin_comment
comment|/* entry valid */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Mapping functions ** **	These allow arbitrary mappings in the config file.  The idea **	(albeit not the implementation) comes from IDA sendmail. */
end_comment

begin_define
define|#
directive|define
name|MAPCLASS
value|struct _mapclass
end_define

begin_define
define|#
directive|define
name|MAP
value|struct _map
end_define

begin_define
define|#
directive|define
name|MAXMAPACTIONS
value|3
end_define

begin_comment
comment|/* size of map_actions array */
end_comment

begin_comment
comment|/* **  An actual map. */
end_comment

begin_macro
name|MAP
end_macro

begin_block
block|{
name|MAPCLASS
modifier|*
name|map_class
decl_stmt|;
comment|/* the class of this map */
name|char
modifier|*
name|map_mname
decl_stmt|;
comment|/* name of this map */
name|long
name|map_mflags
decl_stmt|;
comment|/* flags, see below */
name|char
modifier|*
name|map_file
decl_stmt|;
comment|/* the (nominal) filename */
name|ARBPTR_T
name|map_db1
decl_stmt|;
comment|/* the open database ptr */
name|ARBPTR_T
name|map_db2
decl_stmt|;
comment|/* an "extra" database pointer */
name|char
modifier|*
name|map_keycolnm
decl_stmt|;
comment|/* key column name */
name|char
modifier|*
name|map_valcolnm
decl_stmt|;
comment|/* value column name */
name|u_char
name|map_keycolno
decl_stmt|;
comment|/* key column number */
name|u_char
name|map_valcolno
decl_stmt|;
comment|/* value column number */
name|char
name|map_coldelim
decl_stmt|;
comment|/* column delimiter */
name|char
modifier|*
name|map_app
decl_stmt|;
comment|/* to append to successful matches */
name|char
modifier|*
name|map_domain
decl_stmt|;
comment|/* the (nominal) NIS domain */
name|char
modifier|*
name|map_rebuild
decl_stmt|;
comment|/* program to run to do auto-rebuild */
name|time_t
name|map_mtime
decl_stmt|;
comment|/* last database modification time */
name|int
name|map_lockfd
decl_stmt|;
comment|/* auxiliary lock file descriptor */
name|short
name|map_specificity
decl_stmt|;
comment|/* specificity of aliases */
name|MAP
modifier|*
name|map_stack
index|[
name|MAXMAPSTACK
index|]
decl_stmt|;
comment|/* list for stacked maps */
name|short
name|map_return
index|[
name|MAXMAPACTIONS
index|]
decl_stmt|;
comment|/* return bitmaps for stacked maps */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* bit values for map_mflags */
end_comment

begin_define
define|#
directive|define
name|MF_VALID
value|0x00000001
end_define

begin_comment
comment|/* this entry is valid */
end_comment

begin_define
define|#
directive|define
name|MF_INCLNULL
value|0x00000002
end_define

begin_comment
comment|/* include null byte in key */
end_comment

begin_define
define|#
directive|define
name|MF_OPTIONAL
value|0x00000004
end_define

begin_comment
comment|/* don't complain if map not found */
end_comment

begin_define
define|#
directive|define
name|MF_NOFOLDCASE
value|0x00000008
end_define

begin_comment
comment|/* don't fold case in keys */
end_comment

begin_define
define|#
directive|define
name|MF_MATCHONLY
value|0x00000010
end_define

begin_comment
comment|/* don't use the map value */
end_comment

begin_define
define|#
directive|define
name|MF_OPEN
value|0x00000020
end_define

begin_comment
comment|/* this entry is open */
end_comment

begin_define
define|#
directive|define
name|MF_WRITABLE
value|0x00000040
end_define

begin_comment
comment|/* open for writing */
end_comment

begin_define
define|#
directive|define
name|MF_ALIAS
value|0x00000080
end_define

begin_comment
comment|/* this is an alias file */
end_comment

begin_define
define|#
directive|define
name|MF_TRY0NULL
value|0x00000100
end_define

begin_comment
comment|/* try with no null byte */
end_comment

begin_define
define|#
directive|define
name|MF_TRY1NULL
value|0x00000200
end_define

begin_comment
comment|/* try with the null byte */
end_comment

begin_define
define|#
directive|define
name|MF_LOCKED
value|0x00000400
end_define

begin_comment
comment|/* this map is currently locked */
end_comment

begin_define
define|#
directive|define
name|MF_ALIASWAIT
value|0x00000800
end_define

begin_comment
comment|/* alias map in aliaswait state */
end_comment

begin_define
define|#
directive|define
name|MF_IMPL_HASH
value|0x00001000
end_define

begin_comment
comment|/* implicit: underlying hash database */
end_comment

begin_define
define|#
directive|define
name|MF_IMPL_NDBM
value|0x00002000
end_define

begin_comment
comment|/* implicit: underlying NDBM database */
end_comment

begin_define
define|#
directive|define
name|MF_UNSAFEDB
value|0x00004000
end_define

begin_comment
comment|/* this map is world writable */
end_comment

begin_define
define|#
directive|define
name|MF_APPEND
value|0x00008000
end_define

begin_comment
comment|/* append new entry on rebuiled */
end_comment

begin_define
define|#
directive|define
name|MF_KEEPQUOTES
value|0x00010000
end_define

begin_comment
comment|/* don't dequote key before lookup */
end_comment

begin_define
define|#
directive|define
name|MF_NODEFER
value|0x00020000
end_define

begin_comment
comment|/* don't defer if map lookup fails */
end_comment

begin_comment
comment|/* indices for map_actions */
end_comment

begin_define
define|#
directive|define
name|MA_NOTFOUND
value|0
end_define

begin_comment
comment|/* member map returned "not found" */
end_comment

begin_define
define|#
directive|define
name|MA_UNAVAIL
value|1
end_define

begin_comment
comment|/* member map is not available */
end_comment

begin_define
define|#
directive|define
name|MA_TRYAGAIN
value|2
end_define

begin_comment
comment|/* member map returns temp failure */
end_comment

begin_comment
comment|/* **  The class of a map -- essentially the functions to call */
end_comment

begin_macro
name|MAPCLASS
end_macro

begin_block
block|{
name|char
modifier|*
name|map_cname
decl_stmt|;
comment|/* name of this map class */
name|char
modifier|*
name|map_ext
decl_stmt|;
comment|/* extension for database file */
name|short
name|map_cflags
decl_stmt|;
comment|/* flag bits, see below */
name|bool
argument_list|(
argument|*map_parse
argument_list|)
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* argument parsing function */
name|char
operator|*
operator|(
operator|*
name|map_lookup
operator|)
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* lookup function */
name|void
argument_list|(
argument|*map_store
argument_list|)
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* store function */
name|bool
argument_list|(
argument|*map_open
argument_list|)
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* open function */
name|void
argument_list|(
argument|*map_close
argument_list|)
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* close function */
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* bit values for map_cflags */
end_comment

begin_define
define|#
directive|define
name|MCF_ALIASOK
value|0x0001
end_define

begin_comment
comment|/* can be used for aliases */
end_comment

begin_define
define|#
directive|define
name|MCF_ALIASONLY
value|0x0002
end_define

begin_comment
comment|/* usable only for aliases */
end_comment

begin_define
define|#
directive|define
name|MCF_REBUILDABLE
value|0x0004
end_define

begin_comment
comment|/* can rebuild alias files */
end_comment

begin_define
define|#
directive|define
name|MCF_OPTFILE
value|0x0008
end_define

begin_comment
comment|/* file name is optional */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|map_rewrite
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MAP
modifier|*
name|makemapentry
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
specifier|extern
name|void
name|initmaps
name|__P
argument_list|(
operator|(
name|bool
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Symbol table definitions */
end_comment

begin_struct
struct|struct
name|symtab
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* name to be entered */
name|short
name|s_type
decl_stmt|;
comment|/* general type (see below) */
name|short
name|s_len
decl_stmt|;
comment|/* length of this entry */
name|struct
name|symtab
modifier|*
name|s_next
decl_stmt|;
comment|/* pointer to next in chain */
union|union
block|{
name|BITMAP
name|sv_class
decl_stmt|;
comment|/* bit-map of word classes */
name|ADDRESS
modifier|*
name|sv_addr
decl_stmt|;
comment|/* pointer to address header */
name|MAILER
modifier|*
name|sv_mailer
decl_stmt|;
comment|/* pointer to mailer */
name|char
modifier|*
name|sv_alias
decl_stmt|;
comment|/* alias */
name|MAPCLASS
name|sv_mapclass
decl_stmt|;
comment|/* mapping function class */
name|MAP
name|sv_map
decl_stmt|;
comment|/* mapping function */
name|char
modifier|*
name|sv_hostsig
decl_stmt|;
comment|/* host signature */
name|MCI
name|sv_mci
decl_stmt|;
comment|/* mailer connection info */
name|NAMECANON
name|sv_namecanon
decl_stmt|;
comment|/* canonical name cache */
name|int
name|sv_macro
decl_stmt|;
comment|/* macro name => id mapping */
name|int
name|sv_ruleset
decl_stmt|;
comment|/* ruleset index */
name|struct
name|hdrinfo
name|sv_header
decl_stmt|;
comment|/* header metainfo */
name|char
modifier|*
name|sv_service
index|[
name|MAXMAPSTACK
index|]
decl_stmt|;
comment|/* service switch */
block|}
name|s_value
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|symtab
name|STAB
typedef|;
end_typedef

begin_comment
comment|/* symbol types */
end_comment

begin_define
define|#
directive|define
name|ST_UNDEF
value|0
end_define

begin_comment
comment|/* undefined type */
end_comment

begin_define
define|#
directive|define
name|ST_CLASS
value|1
end_define

begin_comment
comment|/* class map */
end_comment

begin_define
define|#
directive|define
name|ST_ADDRESS
value|2
end_define

begin_comment
comment|/* an address in parsed format */
end_comment

begin_define
define|#
directive|define
name|ST_MAILER
value|3
end_define

begin_comment
comment|/* a mailer header */
end_comment

begin_define
define|#
directive|define
name|ST_ALIAS
value|4
end_define

begin_comment
comment|/* an alias */
end_comment

begin_define
define|#
directive|define
name|ST_MAPCLASS
value|5
end_define

begin_comment
comment|/* mapping function class */
end_comment

begin_define
define|#
directive|define
name|ST_MAP
value|6
end_define

begin_comment
comment|/* mapping function */
end_comment

begin_define
define|#
directive|define
name|ST_HOSTSIG
value|7
end_define

begin_comment
comment|/* host signature */
end_comment

begin_define
define|#
directive|define
name|ST_NAMECANON
value|8
end_define

begin_comment
comment|/* cached canonical name */
end_comment

begin_define
define|#
directive|define
name|ST_MACRO
value|9
end_define

begin_comment
comment|/* macro name to id mapping */
end_comment

begin_define
define|#
directive|define
name|ST_RULESET
value|10
end_define

begin_comment
comment|/* ruleset index */
end_comment

begin_define
define|#
directive|define
name|ST_SERVICE
value|11
end_define

begin_comment
comment|/* service switch entry */
end_comment

begin_define
define|#
directive|define
name|ST_HEADER
value|12
end_define

begin_comment
comment|/* special header flags */
end_comment

begin_define
define|#
directive|define
name|ST_MCI
value|16
end_define

begin_comment
comment|/* mailer connection info (offset) */
end_comment

begin_define
define|#
directive|define
name|s_class
value|s_value.sv_class
end_define

begin_define
define|#
directive|define
name|s_address
value|s_value.sv_addr
end_define

begin_define
define|#
directive|define
name|s_mailer
value|s_value.sv_mailer
end_define

begin_define
define|#
directive|define
name|s_alias
value|s_value.sv_alias
end_define

begin_define
define|#
directive|define
name|s_mci
value|s_value.sv_mci
end_define

begin_define
define|#
directive|define
name|s_mapclass
value|s_value.sv_mapclass
end_define

begin_define
define|#
directive|define
name|s_hostsig
value|s_value.sv_hostsig
end_define

begin_define
define|#
directive|define
name|s_map
value|s_value.sv_map
end_define

begin_define
define|#
directive|define
name|s_namecanon
value|s_value.sv_namecanon
end_define

begin_define
define|#
directive|define
name|s_macro
value|s_value.sv_macro
end_define

begin_define
define|#
directive|define
name|s_ruleset
value|s_value.sv_ruleset
end_define

begin_define
define|#
directive|define
name|s_service
value|s_value.sv_service
end_define

begin_define
define|#
directive|define
name|s_header
value|s_value.sv_header
end_define

begin_decl_stmt
specifier|extern
name|STAB
modifier|*
name|stab
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stabapply
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|STAB
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* opcodes to stab */
end_comment

begin_define
define|#
directive|define
name|ST_FIND
value|0
end_define

begin_comment
comment|/* find entry */
end_comment

begin_define
define|#
directive|define
name|ST_ENTER
value|1
end_define

begin_comment
comment|/* enter if not there */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  STRUCT EVENT -- event queue. ** **	Maintained in sorted order. ** **	We store the pid of the process that set this event to insure **	that when we fork we will not take events intended for the parent. */
end_comment

begin_struct
struct|struct
name|event
block|{
name|time_t
name|ev_time
decl_stmt|;
comment|/* time of the function call */
name|void
argument_list|(
argument|*ev_func
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* function to call */
name|int
name|ev_arg
decl_stmt|;
comment|/* argument to ev_func */
name|int
name|ev_pid
decl_stmt|;
comment|/* pid that set this event */
name|struct
name|event
modifier|*
name|ev_link
decl_stmt|;
comment|/* link to next item */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|event
name|EVENT
typedef|;
end_typedef

begin_decl_stmt
name|EXTERN
name|EVENT
modifier|*
name|EventQueue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of event queue */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|EVENT
modifier|*
name|setevent
name|__P
argument_list|(
operator|(
name|time_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clrevent
name|__P
argument_list|(
operator|(
name|EVENT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* **  Operation, send, error, and MIME modes ** **	The operation mode describes the basic operation of sendmail. **	This can be set from the command line, and is "send mail" by **	default. ** **	The send mode tells how to send mail.  It can be set in the **	configuration file.  It's setting determines how quickly the **	mail will be delivered versus the load on your system.  If the **	-v (verbose) flag is given, it will be forced to SM_DELIVER **	mode. ** **	The error mode tells how to return errors. */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|OpMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operation mode, see below */
end_comment

begin_define
define|#
directive|define
name|MD_DELIVER
value|'m'
end_define

begin_comment
comment|/* be a mail sender */
end_comment

begin_define
define|#
directive|define
name|MD_SMTP
value|'s'
end_define

begin_comment
comment|/* run SMTP on standard input */
end_comment

begin_define
define|#
directive|define
name|MD_ARPAFTP
value|'a'
end_define

begin_comment
comment|/* obsolete ARPANET mode (Grey Book) */
end_comment

begin_define
define|#
directive|define
name|MD_DAEMON
value|'d'
end_define

begin_comment
comment|/* run as a daemon */
end_comment

begin_define
define|#
directive|define
name|MD_FGDAEMON
value|'D'
end_define

begin_comment
comment|/* run daemon in foreground */
end_comment

begin_define
define|#
directive|define
name|MD_VERIFY
value|'v'
end_define

begin_comment
comment|/* verify: don't collect or deliver */
end_comment

begin_define
define|#
directive|define
name|MD_TEST
value|'t'
end_define

begin_comment
comment|/* test mode: resolve addrs only */
end_comment

begin_define
define|#
directive|define
name|MD_INITALIAS
value|'i'
end_define

begin_comment
comment|/* initialize alias database */
end_comment

begin_define
define|#
directive|define
name|MD_PRINT
value|'p'
end_define

begin_comment
comment|/* print the queue */
end_comment

begin_define
define|#
directive|define
name|MD_FREEZE
value|'z'
end_define

begin_comment
comment|/* freeze the configuration file */
end_comment

begin_define
define|#
directive|define
name|MD_HOSTSTAT
value|'h'
end_define

begin_comment
comment|/* print persistent host stat info */
end_comment

begin_define
define|#
directive|define
name|MD_PURGESTAT
value|'H'
end_define

begin_comment
comment|/* purge persistent host stat info */
end_comment

begin_comment
comment|/* values for e_sendmode -- send modes */
end_comment

begin_define
define|#
directive|define
name|SM_DELIVER
value|'i'
end_define

begin_comment
comment|/* interactive delivery */
end_comment

begin_define
define|#
directive|define
name|SM_FORK
value|'b'
end_define

begin_comment
comment|/* deliver in background */
end_comment

begin_define
define|#
directive|define
name|SM_QUEUE
value|'q'
end_define

begin_comment
comment|/* queue, don't deliver */
end_comment

begin_define
define|#
directive|define
name|SM_DEFER
value|'d'
end_define

begin_comment
comment|/* defer map lookups as well as queue */
end_comment

begin_define
define|#
directive|define
name|SM_VERIFY
value|'v'
end_define

begin_comment
comment|/* verify only (used internally) */
end_comment

begin_comment
comment|/* used only as a parameter to sendall */
end_comment

begin_define
define|#
directive|define
name|SM_DEFAULT
value|'\0'
end_define

begin_comment
comment|/* unspecified, use SendMode */
end_comment

begin_comment
comment|/* values for e_errormode -- error handling modes */
end_comment

begin_define
define|#
directive|define
name|EM_PRINT
value|'p'
end_define

begin_comment
comment|/* print errors */
end_comment

begin_define
define|#
directive|define
name|EM_MAIL
value|'m'
end_define

begin_comment
comment|/* mail back errors */
end_comment

begin_define
define|#
directive|define
name|EM_WRITE
value|'w'
end_define

begin_comment
comment|/* write back errors */
end_comment

begin_define
define|#
directive|define
name|EM_BERKNET
value|'e'
end_define

begin_comment
comment|/* special berknet processing */
end_comment

begin_define
define|#
directive|define
name|EM_QUIET
value|'q'
end_define

begin_comment
comment|/* don't print messages (stat only) */
end_comment

begin_comment
comment|/* MIME processing mode */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MimeMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bit values for MimeMode */
end_comment

begin_define
define|#
directive|define
name|MM_CVTMIME
value|0x0001
end_define

begin_comment
comment|/* convert 8 to 7 bit MIME */
end_comment

begin_define
define|#
directive|define
name|MM_PASS8BIT
value|0x0002
end_define

begin_comment
comment|/* just send 8 bit data blind */
end_comment

begin_define
define|#
directive|define
name|MM_MIME8BIT
value|0x0004
end_define

begin_comment
comment|/* convert 8-bit data to MIME */
end_comment

begin_comment
comment|/* queue sorting order algorithm */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|QueueSortOrder
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|QS_BYPRIORITY
value|0
end_define

begin_comment
comment|/* sort by message priority */
end_comment

begin_define
define|#
directive|define
name|QS_BYHOST
value|1
end_define

begin_comment
comment|/* sort by first host name */
end_comment

begin_define
define|#
directive|define
name|QS_BYTIME
value|2
end_define

begin_comment
comment|/* sort by submission time */
end_comment

begin_comment
comment|/* how to handle messages without any recipient addresses */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|NoRecipientAction
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NRA_NO_ACTION
value|0
end_define

begin_comment
comment|/* just leave it as is */
end_comment

begin_define
define|#
directive|define
name|NRA_ADD_TO
value|1
end_define

begin_comment
comment|/* add To: header */
end_comment

begin_define
define|#
directive|define
name|NRA_ADD_APPARENTLY_TO
value|2
end_define

begin_comment
comment|/* add Apparently-To: header */
end_comment

begin_define
define|#
directive|define
name|NRA_ADD_BCC
value|3
end_define

begin_comment
comment|/* add empty Bcc: header */
end_comment

begin_define
define|#
directive|define
name|NRA_ADD_TO_UNDISCLOSED
value|4
end_define

begin_comment
comment|/* add To: undisclosed:; header */
end_comment

begin_comment
comment|/* flags to putxline */
end_comment

begin_define
define|#
directive|define
name|PXLF_NOTHINGSPECIAL
value|0
end_define

begin_comment
comment|/* no special mapping */
end_comment

begin_define
define|#
directive|define
name|PXLF_MAPFROM
value|0x0001
end_define

begin_comment
comment|/* map From_ to>From_ */
end_comment

begin_define
define|#
directive|define
name|PXLF_STRIP8BIT
value|0x0002
end_define

begin_comment
comment|/* strip 8th bit */
end_comment

begin_define
define|#
directive|define
name|PXLF_HEADER
value|0x0004
end_define

begin_comment
comment|/* map newlines in headers */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Additional definitions */
end_comment

begin_comment
comment|/* **  Privacy flags **	These are bit values for the PrivacyFlags word. */
end_comment

begin_define
define|#
directive|define
name|PRIV_PUBLIC
value|0
end_define

begin_comment
comment|/* what have I got to hide? */
end_comment

begin_define
define|#
directive|define
name|PRIV_NEEDMAILHELO
value|0x0001
end_define

begin_comment
comment|/* insist on HELO for MAIL, at least */
end_comment

begin_define
define|#
directive|define
name|PRIV_NEEDEXPNHELO
value|0x0002
end_define

begin_comment
comment|/* insist on HELO for EXPN */
end_comment

begin_define
define|#
directive|define
name|PRIV_NEEDVRFYHELO
value|0x0004
end_define

begin_comment
comment|/* insist on HELO for VRFY */
end_comment

begin_define
define|#
directive|define
name|PRIV_NOEXPN
value|0x0008
end_define

begin_comment
comment|/* disallow EXPN command entirely */
end_comment

begin_define
define|#
directive|define
name|PRIV_NOVRFY
value|0x0010
end_define

begin_comment
comment|/* disallow VRFY command entirely */
end_comment

begin_define
define|#
directive|define
name|PRIV_AUTHWARNINGS
value|0x0020
end_define

begin_comment
comment|/* flag possible authorization probs */
end_comment

begin_define
define|#
directive|define
name|PRIV_NORECEIPTS
value|0x0040
end_define

begin_comment
comment|/* disallow return receipts */
end_comment

begin_define
define|#
directive|define
name|PRIV_NOETRN
value|0x0080
end_define

begin_comment
comment|/* disallow ETRN command entirely */
end_comment

begin_define
define|#
directive|define
name|PRIV_RESTRICTMAILQ
value|0x1000
end_define

begin_comment
comment|/* restrict mailq command */
end_comment

begin_define
define|#
directive|define
name|PRIV_RESTRICTQRUN
value|0x2000
end_define

begin_comment
comment|/* restrict queue run */
end_comment

begin_define
define|#
directive|define
name|PRIV_GOAWAY
value|0x0fff
end_define

begin_comment
comment|/* don't give no info, anyway, anyhow */
end_comment

begin_comment
comment|/* struct defining such things */
end_comment

begin_struct
struct|struct
name|prival
block|{
name|char
modifier|*
name|pv_name
decl_stmt|;
comment|/* name of privacy flag */
name|int
name|pv_flag
decl_stmt|;
comment|/* numeric level */
block|}
struct|;
end_struct

begin_comment
comment|/* **  Flags passed to remotename, parseaddr, allocaddr, and buildaddr. */
end_comment

begin_define
define|#
directive|define
name|RF_SENDERADDR
value|0x001
end_define

begin_comment
comment|/* this is a sender address */
end_comment

begin_define
define|#
directive|define
name|RF_HEADERADDR
value|0x002
end_define

begin_comment
comment|/* this is a header address */
end_comment

begin_define
define|#
directive|define
name|RF_CANONICAL
value|0x004
end_define

begin_comment
comment|/* strip comment information */
end_comment

begin_define
define|#
directive|define
name|RF_ADDDOMAIN
value|0x008
end_define

begin_comment
comment|/* OK to do domain extension */
end_comment

begin_define
define|#
directive|define
name|RF_COPYPARSE
value|0x010
end_define

begin_comment
comment|/* copy parsed user& host */
end_comment

begin_define
define|#
directive|define
name|RF_COPYPADDR
value|0x020
end_define

begin_comment
comment|/* copy print address */
end_comment

begin_define
define|#
directive|define
name|RF_COPYALL
value|(RF_COPYPARSE|RF_COPYPADDR)
end_define

begin_define
define|#
directive|define
name|RF_COPYNONE
value|0
end_define

begin_comment
comment|/* **  Flags passed to safefile/safedirpath. */
end_comment

begin_define
define|#
directive|define
name|SFF_ANYFILE
value|0
end_define

begin_comment
comment|/* no special restrictions */
end_comment

begin_define
define|#
directive|define
name|SFF_MUSTOWN
value|0x0001
end_define

begin_comment
comment|/* user must own this file */
end_comment

begin_define
define|#
directive|define
name|SFF_NOSLINK
value|0x0002
end_define

begin_comment
comment|/* file cannot be a symbolic link */
end_comment

begin_define
define|#
directive|define
name|SFF_ROOTOK
value|0x0004
end_define

begin_comment
comment|/* ok for root to own this file */
end_comment

begin_define
define|#
directive|define
name|SFF_RUNASREALUID
value|0x0008
end_define

begin_comment
comment|/* if no ctladdr, run as real uid */
end_comment

begin_define
define|#
directive|define
name|SFF_NOPATHCHECK
value|0x0010
end_define

begin_comment
comment|/* don't bother checking dir path */
end_comment

begin_define
define|#
directive|define
name|SFF_SETUIDOK
value|0x0020
end_define

begin_comment
comment|/* setuid files are ok */
end_comment

begin_define
define|#
directive|define
name|SFF_CREAT
value|0x0040
end_define

begin_comment
comment|/* ok to create file if necessary */
end_comment

begin_define
define|#
directive|define
name|SFF_REGONLY
value|0x0080
end_define

begin_comment
comment|/* regular files only */
end_comment

begin_define
define|#
directive|define
name|SFF_SAFEDIRPATH
value|0x0100
end_define

begin_comment
comment|/* no writable directories allowed */
end_comment

begin_define
define|#
directive|define
name|SFF_NOHLINK
value|0x0200
end_define

begin_comment
comment|/* file cannot have hard links */
end_comment

begin_define
define|#
directive|define
name|SFF_NOWLINK
value|0x0400
end_define

begin_comment
comment|/* links only in non-writable dirs */
end_comment

begin_define
define|#
directive|define
name|SFF_NOWFILES
value|0x0800
end_define

begin_comment
comment|/* disallow world writable files */
end_comment

begin_comment
comment|/* flags that are actually specific to safeopen/safefopen/dfopen */
end_comment

begin_define
define|#
directive|define
name|SFF_OPENASROOT
value|0x1000
end_define

begin_comment
comment|/* open as root instead of real user */
end_comment

begin_define
define|#
directive|define
name|SFF_NOLOCK
value|0x2000
end_define

begin_comment
comment|/* don't lock the file */
end_comment

begin_comment
comment|/* pseudo-flags */
end_comment

begin_define
define|#
directive|define
name|SFF_NOLINK
value|(SFF_NOHLINK|SFF_NOSLINK)
end_define

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safefile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|UID_T
operator|,
name|GID_T
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|safedirpath
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|UID_T
operator|,
name|GID_T
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|safeopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|safefopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dfopen
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|filechanged
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|stat
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Flags passed to mime8to7. */
end_comment

begin_define
define|#
directive|define
name|M87F_OUTER
value|0
end_define

begin_comment
comment|/* outer context */
end_comment

begin_define
define|#
directive|define
name|M87F_NO8BIT
value|0x0001
end_define

begin_comment
comment|/* can't have 8-bit in this section */
end_comment

begin_define
define|#
directive|define
name|M87F_DIGEST
value|0x0002
end_define

begin_comment
comment|/* processing multipart/digest */
end_comment

begin_comment
comment|/* **  Flags passed to returntosender. */
end_comment

begin_define
define|#
directive|define
name|RTSF_NO_BODY
value|0
end_define

begin_comment
comment|/* send headers only */
end_comment

begin_define
define|#
directive|define
name|RTSF_SEND_BODY
value|0x0001
end_define

begin_comment
comment|/* include body of message in return */
end_comment

begin_define
define|#
directive|define
name|RTSF_PM_BOUNCE
value|0x0002
end_define

begin_comment
comment|/* this is a postmaster bounce */
end_comment

begin_comment
comment|/* **  Regular UNIX sockaddrs are too small to handle ISO addresses, so **  we are forced to declare a supertype here. */
end_comment

begin_if
if|#
directive|if
name|NETINET
operator|||
name|NETUNIX
operator|||
name|NETISO
operator|||
name|NETNS
operator|||
name|NETX25
end_if

begin_union
union|union
name|bigsockaddr
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
comment|/* general version */
if|#
directive|if
name|NETUNIX
name|struct
name|sockaddr_un
name|sunix
decl_stmt|;
comment|/* UNIX family */
endif|#
directive|endif
if|#
directive|if
name|NETINET
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
comment|/* INET family */
endif|#
directive|endif
if|#
directive|if
name|NETISO
name|struct
name|sockaddr_iso
name|siso
decl_stmt|;
comment|/* ISO family */
endif|#
directive|endif
if|#
directive|if
name|NETNS
name|struct
name|sockaddr_ns
name|sns
decl_stmt|;
comment|/* XNS family */
endif|#
directive|endif
if|#
directive|if
name|NETX25
name|struct
name|sockaddr_x25
name|sx25
decl_stmt|;
comment|/* X.25 family */
endif|#
directive|endif
block|}
union|;
end_union

begin_define
define|#
directive|define
name|SOCKADDR
value|union bigsockaddr
end_define

begin_decl_stmt
name|EXTERN
name|SOCKADDR
name|RealHostAddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of host we are talking to */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostnamebyanyaddr
name|__P
argument_list|(
operator|(
name|SOCKADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|anynet_ntoa
name|__P
argument_list|(
operator|(
name|SOCKADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DAEMON
end_if

begin_decl_stmt
specifier|extern
name|bool
name|validate_connection
name|__P
argument_list|(
operator|(
name|SOCKADDR
operator|*
operator|,
name|char
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **  Vendor codes ** **	Vendors can customize sendmail to add special behaviour, **	generally for back compatibility.  Ideally, this should **	be set up in the .cf file using the "V" command.  However, **	it's quite reasonable for some vendors to want the default **	be their old version; this can be set using **		-DVENDOR_DEFAULT=VENDOR_xxx **	in the Makefile. ** **	Vendors should apply to sendmail@CS.Berkeley.EDU for **	unique vendor codes. */
end_comment

begin_define
define|#
directive|define
name|VENDOR_BERKELEY
value|1
end_define

begin_comment
comment|/* Berkeley-native configuration file */
end_comment

begin_define
define|#
directive|define
name|VENDOR_SUN
value|2
end_define

begin_comment
comment|/* Sun-native configuration file */
end_comment

begin_define
define|#
directive|define
name|VENDOR_HP
value|3
end_define

begin_comment
comment|/* Hewlett-Packard specific config syntax */
end_comment

begin_define
define|#
directive|define
name|VENDOR_IBM
value|4
end_define

begin_comment
comment|/* IBM specific config syntax */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|VendorCode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vendor-specific operation enhancements */
end_comment

begin_comment
comment|/* prototypes for vendor-specific hook routines */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|vendor_set_uid
name|__P
argument_list|(
operator|(
name|UID_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vendor_daemon_setup
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Terminal escape codes. ** **	To make debugging output clearer. */
end_comment

begin_struct
struct|struct
name|termescape
block|{
name|char
modifier|*
name|te_rv_on
decl_stmt|;
comment|/* turn reverse-video on */
name|char
modifier|*
name|te_rv_off
decl_stmt|;
comment|/* turn reverse-video off */
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|termescape
name|TermEscape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Error return from inet_addr(3), in case not defined in /usr/include. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_NONE
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* **  Global variables. */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|FromFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, "From" person is explicit */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|MeToo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send to the sender also */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|IgnrDot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't let dot end messages */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SaveFrom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save leading "From" lines */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|GrabTo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, get recipients from msg */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SuprErrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we are suppressing errors */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|HoldErrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only output errors to transcript */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|NoConnect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't connect to non-local mailers */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SuperSafe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* be extra careful, even if expensive */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|ForkQueueRuns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fork for each job when running the queue */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|AutoRebuild
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auto-rebuild the alias database as needed */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|CheckAliases
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parse addresses during newaliases */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|NoAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress aliasing */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|UseNameServer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using DNS -- interpret h_errno& MX RRs */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|UseHesiod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using Hesiod -- interpret Hesiod errors */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SevenBitInput
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force 7-bit data on input */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|HasEightBits
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* has at least one eight bit input byte */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|ConfigFileRead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration file has been read */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|SafeAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interval to wait until @:@ in alias file */
end_comment

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|InChannel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input connection */
end_comment

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|OutChannel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output connection */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|RealUserName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real user name of caller */
end_comment

begin_decl_stmt
name|EXTERN
name|uid_t
name|RealUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real uid of caller */
end_comment

begin_decl_stmt
name|EXTERN
name|gid_t
name|RealGid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real gid of caller */
end_comment

begin_decl_stmt
name|EXTERN
name|uid_t
name|DefUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default uid to run as */
end_comment

begin_decl_stmt
name|EXTERN
name|gid_t
name|DefGid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default gid to run as */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|DefUser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default user to run as (from DefUid) */
end_comment

begin_decl_stmt
name|EXTERN
name|MODE_T
name|OldUmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* umask when sendmail starts up */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if blow-by-blow desired */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if errors (local to single pass) */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ExitStat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit status code */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|LineNumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in current input */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|LogLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* level of logging to perform */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|FileMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode on files */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|QueueLA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* load average starting forced queueing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|RefuseLA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* load average refusing connections are */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|CurrentLA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current load average */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|QueueFactor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* slope of queue function */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|QueueIntvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* intervals between running the queue */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|HelpFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of SMTP help file */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ErrMsgFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file to prepend to all error messages */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|StatFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of statistics summary */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|QueueDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of queue directory */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|FileName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name to print on error messages */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|SmtpPhase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current phase in SMTP processing */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|MyHostName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of this host for SMTP messages */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|RealHostName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of host we are talking to */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|CurHostName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current host we are dealing with */
end_comment

begin_decl_stmt
name|EXTERN
name|jmp_buf
name|TopFrame
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* branch-to-top-of-loop-on-error frame */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|QuickAbort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  .... but only if we want a quick abort */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|OnlyOneError
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  .... or only want to give one SMTP reply */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|LogUsrErrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* syslog user errors (e.g., SMTP RCPT cmd) */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SendMIMEErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send error messages in MIME format */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|MatchGecos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* look for user names in gecos field */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|UseErrorsTo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use Errors-To: header (back compat) */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|TryNullMXList
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if we are the best MX, try host directly */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|InChild
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if running in an SMTP subprocess */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DisConnected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* running with OutChannel redirected to xf */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|ColonOkInAddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* single colon legal in address */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|HasWildcardMX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't use MX records when canonifying */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|SpaceSub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* substitution for<lwsp> */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|PrivacyFlags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* privacy flags */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ConfFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of configuration file [conf.c] */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|PidFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of proc id file [conf.c] */
end_comment

begin_decl_stmt
specifier|extern
name|ADDRESS
name|NullAddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a null (template) address [main.c] */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|WkClassFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* multiplier for message class -> priority */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|WkRecipFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* multiplier for # of recipients -> priority */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|WkTimeFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* priority offset each time this job is run */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|UdbSpec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user database source spec */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxHopCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # of hops until bounce */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ConfigLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* config file level */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|TimeZoneSpec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* override time zone specification */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ForwardPath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to search for .forward files */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|MinBlocksFree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min # of blocks free on queue fs */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|FallBackMX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fall back MX host */
end_comment

begin_decl_stmt
name|EXTERN
name|long
name|MaxMessageSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* advertised max size we will accept */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|MinQueueAge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min delivery interval */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|DialDelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delay between dial-on-demand tries */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|SafeFileEnv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* chroot location for file delivery */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|HostsFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to /etc/hosts file */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|HostStatDir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of host status information */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxQueueRun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of jobs in one queue run */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxChildren
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of daemonic children */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|CurChildren
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current number of daemonic children */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|SmtpGreeting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SMTP greeting message (old $e macro) */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|UnixFromLine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UNIX From_ line (old $l macro) */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|OperatorChars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operators (old $o macro) */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DontInitGroups
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* avoid initgroups() because of NIS cost */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|DefaultNotify
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default DSN notification flags */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|AllowBogusHELO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow syntax errors on HELO command */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|UserSubmission
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial (user) mail submission */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|RunAsUserName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user to become for bulk of run */
end_comment

begin_decl_stmt
name|EXTERN
name|uid_t
name|RunAsUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UID to become for bulk of run */
end_comment

begin_decl_stmt
name|EXTERN
name|gid_t
name|RunAsGid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GID to become for bulk of run */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxRcptPerMsg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max recipients per SMTP message */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DoQueueRun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-interrupt time queue run needed */
end_comment

begin_if
if|#
directive|if
name|_FFR_DSN_RRT_OPTION
end_if

begin_decl_stmt
name|EXTERN
name|bool
name|RrtImpliesDsn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* turn Return-Receipt-To: into DSN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|DeadLetterDrop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path to dead letter office */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DontProbeInterfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't probe interfaces for names */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|ChownAlwaysSafe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* treat chown(2) as safe */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|IgnoreHostStatus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore long term host status files */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SingleThreadDelivery
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* single thread hosts on delivery */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|UnsafeGroupWrites
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* group-writable files are unsafe */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|SingleLineFromHeader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force From: header to be one line */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DontLockReadFiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't read lock support files */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|ConnRateThrottle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* throttle for SMTP connection rate */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxAliasRecursion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum depth of alias recursion */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxMacroRecursion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum depth of macro recursion */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxRuleRecursion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum depth of ruleset recursion */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|MustQuoteChars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quote these characters in phrases */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ServiceSwitchFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backup service switch */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|DefaultCharSet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default character set for MIME */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|PostMasterCopy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address to get errs cc's */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|CheckpointInterval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue file checkpoint interval */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DontPruneRoutes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't prune source routes */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|DontExpandCnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do not $[...$] expand CNAMEs */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxMciCache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum entries in MCI cache */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|ServiceCacheTime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time service switch was cached */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|ServiceCacheMaxAge
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* refresh interval for cache */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|MciCacheTimeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum idle time on connections */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|MciInfoTimeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how long 'til we retry down hosts */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|QueueLimitRecipient
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit queue runs to this recipient */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|QueueLimitSender
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit queue runs to this sender */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|QueueLimitId
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* limit queue runs to this id */
end_comment

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|TrafficLogFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file in which to log all traffic */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|DoubleBounceAddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where to send double bounces */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|FatalWritableDirs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no writable dirs in map paths */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
modifier|*
name|ExternalEnviron
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input environment */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|UserEnviron
index|[
name|MAXUSERENVIRON
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved user environment */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Timeouts ** **	Indicated values are the MINIMUM per RFC 1123 section 5.3.2. */
end_comment

begin_macro
name|EXTERN
end_macro

begin_struct
struct|struct
block|{
comment|/* RFC 1123-specified timeouts [minimum value] */
name|time_t
name|to_initial
decl_stmt|;
comment|/* initial greeting timeout [5m] */
name|time_t
name|to_mail
decl_stmt|;
comment|/* MAIL command [5m] */
name|time_t
name|to_rcpt
decl_stmt|;
comment|/* RCPT command [5m] */
name|time_t
name|to_datainit
decl_stmt|;
comment|/* DATA initiation [2m] */
name|time_t
name|to_datablock
decl_stmt|;
comment|/* DATA block [3m] */
name|time_t
name|to_datafinal
decl_stmt|;
comment|/* DATA completion [10m] */
name|time_t
name|to_nextcommand
decl_stmt|;
comment|/* next command [5m] */
comment|/* following timeouts are not mentioned in RFC 1123 */
name|time_t
name|to_iconnect
decl_stmt|;
comment|/* initial connection timeout (first try) */
name|time_t
name|to_connect
decl_stmt|;
comment|/* initial connection timeout (later tries) */
name|time_t
name|to_rset
decl_stmt|;
comment|/* RSET command */
name|time_t
name|to_helo
decl_stmt|;
comment|/* HELO command */
name|time_t
name|to_quit
decl_stmt|;
comment|/* QUIT command */
name|time_t
name|to_miscshort
decl_stmt|;
comment|/* misc short commands (NOOP, VERB, etc) */
name|time_t
name|to_ident
decl_stmt|;
comment|/* IDENT protocol requests */
name|time_t
name|to_fileopen
decl_stmt|;
comment|/* opening :include: and .forward files */
comment|/* following are per message */
name|time_t
name|to_q_return
index|[
name|MAXTOCLASS
index|]
decl_stmt|;
comment|/* queue return timeouts */
name|time_t
name|to_q_warning
index|[
name|MAXTOCLASS
index|]
decl_stmt|;
comment|/* queue warning timeouts */
block|}
name|TimeOuts
struct|;
end_struct

begin_comment
comment|/* timeout classes for return and warning timeouts */
end_comment

begin_define
define|#
directive|define
name|TOC_NORMAL
value|0
end_define

begin_comment
comment|/* normal delivery */
end_comment

begin_define
define|#
directive|define
name|TOC_URGENT
value|1
end_define

begin_comment
comment|/* urgent delivery */
end_comment

begin_define
define|#
directive|define
name|TOC_NONURGENT
value|2
end_define

begin_comment
comment|/* non-urgent delivery */
end_comment

begin_comment
comment|/* **  Trace information */
end_comment

begin_comment
comment|/* trace vector and macros for debugging flags */
end_comment

begin_decl_stmt
name|EXTERN
name|u_char
name|tTdvect
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tTd
parameter_list|(
name|flag
parameter_list|,
name|level
parameter_list|)
value|(tTdvect[flag]>= level)
end_define

begin_define
define|#
directive|define
name|tTdlevel
parameter_list|(
name|flag
parameter_list|)
value|(tTdvect[flag])
end_define

begin_escape
end_escape

begin_comment
comment|/* **  Miscellaneous information. */
end_comment

begin_comment
comment|/* **  The "no queue id" queue id for sm_syslog */
end_comment

begin_define
define|#
directive|define
name|NOQID
value|"*~*"
end_define

begin_comment
comment|/* **  Some in-line functions */
end_comment

begin_comment
comment|/* set exit status */
end_comment

begin_define
define|#
directive|define
name|setstat
parameter_list|(
name|s
parameter_list|)
value|{ \ 				if (ExitStat == EX_OK || ExitStat == EX_TEMPFAIL) \ 					ExitStat = s; \ 			}
end_define

begin_comment
comment|/* make a copy of a string */
end_comment

begin_define
define|#
directive|define
name|newstr
parameter_list|(
name|s
parameter_list|)
value|strcpy(xalloc(strlen(s) + 1), s)
end_define

begin_define
define|#
directive|define
name|STRUCTCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|d = s
end_define

begin_comment
comment|/* **  Declarations of useful functions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sfgets
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
operator|,
name|time_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|queuename
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|curtime
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|transienterror
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fgetfolded
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
specifier|extern
name|char
modifier|*
name|username
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pintvl
name|__P
argument_list|(
operator|(
name|time_t
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|shouldqueue
name|__P
argument_list|(
operator|(
name|long
operator|,
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|lockfile
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
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|hostsignature
name|__P
argument_list|(
operator|(
name|MAILER
operator|*
operator|,
name|char
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|openxscript
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|closexscript
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|shortenstring
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|usershellok
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
name|char
modifier|*
name|defcharset
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|wordinclass
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|denlstring
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|makelower
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
specifier|extern
name|void
name|rebuildaliases
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readaliases
name|__P
argument_list|(
operator|(
name|MAP
operator|*
operator|,
name|FILE
operator|*
operator|,
name|bool
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|finis
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setsender
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ENVELOPE
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xputs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|logsender
name|__P
argument_list|(
operator|(
name|ENVELOPE
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
name|void
name|smtprset
name|__P
argument_list|(
operator|(
name|MAILER
operator|*
operator|,
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|smtpquit
name|__P
argument_list|(
operator|(
name|MAILER
operator|*
operator|,
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setuserenv
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getextenv
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|disconnect
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|putxline
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
name|MCI
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dumpfd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|bool
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|makemailer
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
specifier|extern
name|void
name|putfromline
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setoption
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|bool
operator|,
name|bool
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setclass
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
specifier|extern
name|void
name|inittimeouts
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
specifier|extern
name|void
name|logdelivery
name|__P
argument_list|(
operator|(
name|MAILER
operator|*
operator|,
name|MCI
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|time_t
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|giveresponse
name|__P
argument_list|(
operator|(
name|int
operator|,
name|MAILER
operator|*
operator|,
name|MCI
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|time_t
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|buildfname
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
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mci_setstat
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|int
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
specifier|extern
name|char
modifier|*
name|smtptodsn
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rscheck
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
name|ENVELOPE
operator|*
name|e
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mime7to8
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|HDR
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mime8to7
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|HDR
operator|*
operator|,
name|ENVELOPE
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xfclose
name|__P
argument_list|(
operator|(
name|FILE
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
specifier|extern
name|int
name|switch_map_find
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
index|[]
operator|,
name|short
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shorten_hostname
name|__P
argument_list|(
operator|(
name|char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|waitfor
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|proc_list_add
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|proc_list_drop
name|__P
argument_list|(
operator|(
name|pid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|proc_list_clear
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|buffer_errors
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flush_errors
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|putline
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|MCI
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|xtextok
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
specifier|extern
name|char
modifier|*
name|xtextify
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
name|char
modifier|*
name|xuntextify
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
specifier|extern
name|void
name|cleanstrcpy
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getmxrr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|bool
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strtorwset
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printav
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|printopenfds
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|endmailer
name|__P
argument_list|(
operator|(
name|MCI
operator|*
operator|,
name|ENVELOPE
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fixcrlf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dofork
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initsys
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|collect
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|bool
operator|,
name|HDR
operator|*
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|stripquotes
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
specifier|extern
name|int
name|include
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|,
name|ADDRESS
operator|*
operator|,
name|ADDRESS
operator|*
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unlockqueue
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xunlink
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
specifier|extern
name|bool
name|runqueue
name|__P
argument_list|(
operator|(
name|bool
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getla
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sendall
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|queueup
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|checkfds
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
specifier|extern
name|int
name|returntosender
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|markstats
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|ADDRESS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|poststats
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
specifier|extern
name|char
modifier|*
name|arpadate
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
specifier|extern
name|int
name|mailfile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|ADDRESS
operator|*
operator|,
name|int
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|loseqfile
name|__P
argument_list|(
operator|(
name|ENVELOPE
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
name|prog_open
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|getcanonname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|path_is_dir
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pid_t
name|dowork
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|,
name|bool
operator|,
name|ENVELOPE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|drop_privileges
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fill_fd
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
specifier|extern
specifier|const
name|char
modifier|*
name|errstring
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sigfunc_t
name|setsignal
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sigfunc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|blocksignal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|releasesignal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hostent
modifier|*
name|sm_gethostbyname
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
specifier|extern
name|struct
name|hostent
modifier|*
name|sm_gethostbyaddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|sm_getpwnam
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
specifier|extern
name|struct
name|passwd
modifier|*
name|sm_getpwuid
name|__P
argument_list|(
operator|(
name|UID_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
modifier|*
name|finduser
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XDEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|checkfdopen
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
specifier|extern
name|void
name|checkfd012
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ellipsis is a different case though */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|auth_warning
parameter_list|(
name|ENVELOPE
modifier|*
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
specifier|extern
name|void
name|syserr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usrerr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|message
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nmessage
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sm_syslog
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|auth_warning
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|syserr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usrerr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nmessage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setproctitle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sm_syslog
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HASSNPRINTF
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
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
specifier|extern
name|int
name|vsnprintf
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
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|snprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vsnprintf
parameter_list|()
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

end_unit

