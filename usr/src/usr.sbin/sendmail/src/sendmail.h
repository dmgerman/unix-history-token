begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)sendmail.h	5.15 (Berkeley) %G%  */
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
literal|"@(#)sendmail.h	5.15		%G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_else
else|#
directive|else
else|_DEFINE
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
endif|_DEFINE
end_endif

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
file|"conf.h"
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
file|<sys/syslog.h>
end_include

begin_endif
endif|#
directive|endif
endif|LOG
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DAEMON
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

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

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

begin_endif
endif|#
directive|endif
endif|DAEMON
end_endif

begin_define
define|#
directive|define
name|PSBUFSIZE
value|(MAXNAME + MAXATOM)
end_define

begin_comment
comment|/* size of prescan buffer */
end_comment

begin_comment
comment|/* **  Data structure for bit maps. ** **	Each bit in this map can be referenced by an ascii character. **	This is 128 possible bits, or 12 8-bit bytes. */
end_comment

begin_define
define|#
directive|define
name|BITMAPBYTES
value|16
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
value|(bit / (BYTEBITS * sizeof (int)))
end_define

begin_define
define|#
directive|define
name|_BITBIT
parameter_list|(
name|bit
parameter_list|)
value|(1<< (bit % (BYTEBITS * sizeof (int))))
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

begin_escape
end_escape

begin_comment
comment|/* **  Address structure. **	Addresses are stored internally in this structure. ** **	Each address is on two chains and in one tree. **		The q_next chain is used to link together addresses **		  for one mailer (and is rooted in a mailer). **		The q_chain chain is used to maintain a list of **		  addresses originating from one call to sendto, and **		  is used primarily for printing messages. **		The q_alias, q_sibling, and q_child tree maintains **		  a complete tree of the aliases.  q_alias points to **		  the parent -- obviously, there can be several, and **		  so this points to "one" of them.  Ditto for q_sibling. */
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
name|u_short
name|q_flags
decl_stmt|;
comment|/* status flags, see below */
name|short
name|q_uid
decl_stmt|;
comment|/* user-id of receiver (if known) */
name|short
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
name|char
modifier|*
name|q_fullname
decl_stmt|;
comment|/* full name of this person */
name|time_t
name|q_timeout
decl_stmt|;
comment|/* timeout for this address */
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
comment|/* parent in alias tree */
name|struct
name|address
modifier|*
name|q_sibling
decl_stmt|;
comment|/* sibling in alias tree */
name|struct
name|address
modifier|*
name|q_child
decl_stmt|;
comment|/* child in alias tree */
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
value|000001
end_define

begin_comment
comment|/* don't send to this address */
end_comment

begin_define
define|#
directive|define
name|QBADADDR
value|000002
end_define

begin_comment
comment|/* this address is verified bad */
end_comment

begin_define
define|#
directive|define
name|QGOODUID
value|000004
end_define

begin_comment
comment|/* the q_uid q_gid fields are good */
end_comment

begin_define
define|#
directive|define
name|QPRIMARY
value|000010
end_define

begin_comment
comment|/* set from argv */
end_comment

begin_define
define|#
directive|define
name|QQUEUEUP
value|000020
end_define

begin_comment
comment|/* queue for later transmission */
end_comment

begin_define
define|#
directive|define
name|QPSEUDO
value|000040
end_define

begin_comment
comment|/* only on the list for verification */
end_comment

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
name|BITMAP
name|m_flags
decl_stmt|;
comment|/* status flags, see below */
name|short
name|m_mno
decl_stmt|;
comment|/* mailer number internally */
name|char
modifier|*
modifier|*
name|m_argv
decl_stmt|;
comment|/* template argument vector */
name|short
name|m_s_rwset
decl_stmt|;
comment|/* rewriting set for sender addresses */
name|short
name|m_r_rwset
decl_stmt|;
comment|/* rewriting set for recipient addresses */
name|char
modifier|*
name|m_eol
decl_stmt|;
comment|/* end of line string */
name|long
name|m_maxsize
decl_stmt|;
comment|/* size limit on message to this mailer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mailer
name|MAILER
typedef|;
end_typedef

begin_comment
comment|/* bits for m_flags */
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
name|M_INTERNAL
value|'I'
end_define

begin_comment
comment|/* SMTP to another sendmail site */
end_comment

begin_define
define|#
directive|define
name|M_LOCAL
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
name|M_FROMPATH
value|'p'
end_define

begin_comment
comment|/* use reverse-path in MAIL FROM: */
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
name|M_RESTR
value|'S'
end_define

begin_comment
comment|/* must be daemon to execute */
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
name|M_XDOT
value|'X'
end_define

begin_comment
comment|/* use hidden-dot algorithm */
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
value|00001
end_define

begin_comment
comment|/* this field terminates header */
end_comment

begin_define
define|#
directive|define
name|H_RCPT
value|00002
end_define

begin_comment
comment|/* contains recipient addresses */
end_comment

begin_define
define|#
directive|define
name|H_DEFAULT
value|00004
end_define

begin_comment
comment|/* if another value is found, drop this */
end_comment

begin_define
define|#
directive|define
name|H_RESENT
value|00010
end_define

begin_comment
comment|/* this address is a "Resent-..." address */
end_comment

begin_define
define|#
directive|define
name|H_CHECK
value|00020
end_define

begin_comment
comment|/* check h_mflags against m_flags */
end_comment

begin_define
define|#
directive|define
name|H_ACHECK
value|00040
end_define

begin_comment
comment|/* ditto, but always (not just default) */
end_comment

begin_define
define|#
directive|define
name|H_FORCE
value|00100
end_define

begin_comment
comment|/* force this field, even if default */
end_comment

begin_define
define|#
directive|define
name|H_TRACE
value|00200
end_define

begin_comment
comment|/* this field contains trace information */
end_comment

begin_define
define|#
directive|define
name|H_FROM
value|00400
end_define

begin_comment
comment|/* this is a from-type field */
end_comment

begin_define
define|#
directive|define
name|H_VALID
value|01000
end_define

begin_comment
comment|/* this field has a validated value */
end_comment

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
name|char
modifier|*
name|e_receiptto
decl_stmt|;
comment|/* return receipt address */
name|ADDRESS
name|e_from
decl_stmt|;
comment|/* the person it is from */
name|char
modifier|*
modifier|*
name|e_fromdomain
decl_stmt|;
comment|/* the domain part of the sender */
name|ADDRESS
modifier|*
name|e_returnto
decl_stmt|;
comment|/* place to return the message to */
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
name|int
name|e_nrcpts
decl_stmt|;
comment|/* number of recipients */
name|short
name|e_class
decl_stmt|;
comment|/* msg class (priority, junk, etc.) */
name|short
name|e_flags
decl_stmt|;
comment|/* flags, see below */
name|short
name|e_hopcount
decl_stmt|;
comment|/* number of times processed */
name|int
function_decl|(
modifier|*
name|e_puthdr
function_decl|)
parameter_list|()
function_decl|;
comment|/* function to put header of message */
name|int
function_decl|(
modifier|*
name|e_putbody
function_decl|)
parameter_list|()
function_decl|;
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
name|e_df
decl_stmt|;
comment|/* location of temp file */
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
name|e_qfp
decl_stmt|;
comment|/* queue control file */
name|char
modifier|*
name|e_message
decl_stmt|;
comment|/* error message */
name|char
modifier|*
name|e_macro
index|[
literal|128
index|]
decl_stmt|;
comment|/* macro definitions */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|envelope
name|ENVELOPE
typedef|;
end_typedef

begin_comment
comment|/* values for e_flags */
end_comment

begin_define
define|#
directive|define
name|EF_OLDSTYLE
value|000001
end_define

begin_comment
comment|/* use spaces (not commas) in hdrs */
end_comment

begin_define
define|#
directive|define
name|EF_INQUEUE
value|000002
end_define

begin_comment
comment|/* this message is fully queued */
end_comment

begin_define
define|#
directive|define
name|EF_TIMEOUT
value|000004
end_define

begin_comment
comment|/* this message is too old */
end_comment

begin_define
define|#
directive|define
name|EF_CLRQUEUE
value|000010
end_define

begin_comment
comment|/* disk copy is no longer needed */
end_comment

begin_define
define|#
directive|define
name|EF_SENDRECEIPT
value|000020
end_define

begin_comment
comment|/* send a return receipt */
end_comment

begin_define
define|#
directive|define
name|EF_FATALERRS
value|000040
end_define

begin_comment
comment|/* fatal errors occured */
end_comment

begin_define
define|#
directive|define
name|EF_KEEPQUEUE
value|000100
end_define

begin_comment
comment|/* keep queue files always */
end_comment

begin_define
define|#
directive|define
name|EF_RESPONSE
value|000200
end_define

begin_comment
comment|/* this is an error or return receipt */
end_comment

begin_define
define|#
directive|define
name|EF_RESENT
value|000400
end_define

begin_comment
comment|/* this message is being forwarded */
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
value|'\020'
end_define

begin_comment
comment|/* match zero or more tokens */
end_comment

begin_define
define|#
directive|define
name|MATCHANY
value|'\021'
end_define

begin_comment
comment|/* match one or more tokens */
end_comment

begin_define
define|#
directive|define
name|MATCHONE
value|'\022'
end_define

begin_comment
comment|/* match exactly one token */
end_comment

begin_define
define|#
directive|define
name|MATCHCLASS
value|'\023'
end_define

begin_comment
comment|/* match one token in a class */
end_comment

begin_define
define|#
directive|define
name|MATCHNCLASS
value|'\024'
end_define

begin_comment
comment|/* match anything not in class */
end_comment

begin_define
define|#
directive|define
name|MATCHREPL
value|'\025'
end_define

begin_comment
comment|/* replacement on RHS for above */
end_comment

begin_define
define|#
directive|define
name|MATCHLOOKUP
value|'\035'
end_define

begin_comment
comment|/* look up and replace a sequence */
end_comment

begin_define
define|#
directive|define
name|MATCHELOOKUP
value|'\036'
end_define

begin_comment
comment|/* end of the sequence */
end_comment

begin_comment
comment|/* right hand side items */
end_comment

begin_define
define|#
directive|define
name|CANONNET
value|'\026'
end_define

begin_comment
comment|/* canonical net, next token */
end_comment

begin_define
define|#
directive|define
name|CANONHOST
value|'\027'
end_define

begin_comment
comment|/* canonical host, next token */
end_comment

begin_define
define|#
directive|define
name|CANONUSER
value|'\030'
end_define

begin_comment
comment|/* canonical user, next N tokens */
end_comment

begin_define
define|#
directive|define
name|CALLSUBR
value|'\031'
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
value|'\032'
end_define

begin_comment
comment|/* conditional if-then */
end_comment

begin_define
define|#
directive|define
name|CONDELSE
value|'\033'
end_define

begin_comment
comment|/* conditional else */
end_comment

begin_define
define|#
directive|define
name|CONDFI
value|'\034'
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
value|'\035'
end_define

begin_comment
comment|/* hostname lookup begin */
end_comment

begin_define
define|#
directive|define
name|HOSTEND
value|'\036'
end_define

begin_comment
comment|/* hostname lookup end */
end_comment

begin_comment
comment|/* \001 is also reserved as the macro expansion character */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Information about hosts that we have looked up recently. ** **	This stuff is 4.2/3bsd specific. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DAEMON
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|HOSTINFO
value|struct hostinfo
end_define

begin_macro
name|HOSTINFO
end_macro

begin_block
block|{
name|char
modifier|*
name|ho_name
decl_stmt|;
comment|/* name of this host */
name|struct
name|in_addr
name|ho_inaddr
decl_stmt|;
comment|/* internet address */
name|short
name|ho_flags
decl_stmt|;
comment|/* flag bits, see below */
name|short
name|ho_errno
decl_stmt|;
comment|/* error number on last connection */
name|short
name|ho_exitstat
decl_stmt|;
comment|/* exit status from last connection */
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
name|HOF_VALID
value|00001
end_define

begin_comment
comment|/* this entry is valid */
end_comment

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

begin_endif
endif|#
directive|endif
endif|DAEMON
end_endif

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
name|char
name|s_type
decl_stmt|;
comment|/* general type (see below) */
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
ifdef|#
directive|ifdef
name|HOSTINFO
name|HOSTINFO
name|sv_host
decl_stmt|;
comment|/* host information */
endif|#
directive|endif
endif|HOSTINFO
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
name|ST_HOST
value|5
end_define

begin_comment
comment|/* host information */
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
name|s_host
value|s_value.sv_host
end_define

begin_function_decl
specifier|extern
name|STAB
modifier|*
name|stab
parameter_list|()
function_decl|;
end_function_decl

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
name|int
function_decl|(
modifier|*
name|ev_func
function_decl|)
parameter_list|()
function_decl|;
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

begin_escape
end_escape

begin_comment
comment|/* **  Operation, send, and error modes ** **	The operation mode describes the basic operation of sendmail. **	This can be set from the command line, and is "send mail" by **	default. ** **	The send mode tells how to send mail.  It can be set in the **	configuration file.  It's setting determines how quickly the **	mail will be delivered versus the load on your system.  If the **	-v (verbose) flag is given, it will be forced to SM_DELIVER **	mode. ** **	The error mode tells how to return errors. */
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
name|MD_ARPAFTP
value|'a'
end_define

begin_comment
comment|/* old-style arpanet protocols */
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
name|MD_DAEMON
value|'d'
end_define

begin_comment
comment|/* run as a daemon */
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

begin_decl_stmt
name|EXTERN
name|char
name|SendMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send mode, see below */
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
name|SM_QUICKD
value|'j'
end_define

begin_comment
comment|/* deliver w/o queueing */
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

begin_decl_stmt
name|EXTERN
name|char
name|ErrorMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error mode, see below */
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
comment|/* offset used to issure that the error messages for name server error  * codes are unique.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ERRNO
value|100
end_define

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
name|NoAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, don't do any aliasing */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|ForceMail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, mail even if already got a copy */
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
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if blow-by-blow desired */
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
name|NoReturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't return letter to sender */
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
name|QueueRun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* currently running message from the queue */
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
name|UseNameServer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use internet domain name server */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|SafeAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minutes to wait until @:@ in alias file */
end_comment

begin_decl_stmt
name|EXTERN
name|time_t
name|TimeOut
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time until timeout */
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
name|int
name|RealUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when Daemon, real uid of caller */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|RealGid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when Daemon, real gid of caller */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|DefUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default uid to run as */
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
name|int
name|DefGid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default gid to run as */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OldUmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* umask when sendmail starts up */
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
name|AliasLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of aliasing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MotherPid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* proc id of parent process */
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
name|time_t
name|ReadTimeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timeout on reads */
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
name|AliasFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of alias file */
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
name|struct
name|sockaddr_in
name|RealHostAddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of host we are talking to */
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
specifier|extern
name|char
modifier|*
name|ConfFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of configuration file [conf.c] */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FreezeFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of frozen memory image [conf.c] */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Arpa_Info
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the reply code for Arpanet info [conf.c] */
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
name|WkClassFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* multiplier for message class -> priority */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|WkRecipFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* multiplier for # of recipients -> priority */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|WkTimeFact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* priority offset each time this job is run */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|CheckPointLimit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deliveries before checkpointing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Nmx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of MX RRs */
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
name|char
modifier|*
name|MxHosts
index|[
name|MAXMXHOSTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for MX RRs */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|TrustedUsers
index|[
name|MAXTRUST
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of trusted users */
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

begin_escape
end_escape

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

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

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

begin_function_decl
specifier|extern
name|ADDRESS
modifier|*
name|parseaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|sameaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|dfopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|EVENT
modifier|*
name|setevent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sfgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|queuename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|curtime
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* **  HACK to fix bug in C compiler on CCI */
end_comment

begin_undef
undef|#
directive|undef
name|isascii
end_undef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~0177) == 0)
end_define

end_unit

