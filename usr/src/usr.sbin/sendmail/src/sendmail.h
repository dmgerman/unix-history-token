begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)sendmail.h	3.73		%G%"
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
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_comment
comment|/* **  Configuration constants. **	There shouldn't be much need to change these.... */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|256
end_define

begin_comment
comment|/* max line length */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|128
end_define

begin_comment
comment|/* max length of a name */
end_comment

begin_define
define|#
directive|define
name|MAXFIELD
value|2500
end_define

begin_comment
comment|/* max total length of a hdr field */
end_comment

begin_define
define|#
directive|define
name|MAXPV
value|40
end_define

begin_comment
comment|/* max # of parms to mailers */
end_comment

begin_define
define|#
directive|define
name|MAXHOP
value|30
end_define

begin_comment
comment|/* max value of HopCount */
end_comment

begin_define
define|#
directive|define
name|MAXATOM
value|30
end_define

begin_comment
comment|/* max atoms per address */
end_comment

begin_define
define|#
directive|define
name|MAXMAILERS
value|10
end_define

begin_comment
comment|/* maximum mailers known to system */
end_comment

begin_define
define|#
directive|define
name|SPACESUB
value|('.'|0200)
end_define

begin_comment
comment|/* substitution for<lwsp> */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Arpa_Info
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the message number for Arpanet info */
end_comment

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
name|q_host
decl_stmt|;
comment|/* host name */
name|struct
name|mailer
modifier|*
name|q_mailer
decl_stmt|;
comment|/* mailer to use */
name|short
name|q_rmailer
decl_stmt|;
comment|/* real mailer (before mapping) */
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
name|u_long
name|m_flags
decl_stmt|;
comment|/* status flags, see below */
name|short
name|m_badstat
decl_stmt|;
comment|/* the status code to use on unknown error */
name|short
name|m_mno
decl_stmt|;
comment|/* mailer number internally */
name|char
modifier|*
name|m_from
decl_stmt|;
comment|/* pattern for From: header */
name|char
modifier|*
modifier|*
name|m_argv
decl_stmt|;
comment|/* template argument vector */
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
name|M_FOPT
value|000000001L
end_define

begin_comment
comment|/* mailer takes picky -f flag */
end_comment

begin_define
define|#
directive|define
name|M_ROPT
value|000000002L
end_define

begin_comment
comment|/* mailer takes picky -r flag */
end_comment

begin_define
define|#
directive|define
name|M_QUIET
value|000000004L
end_define

begin_comment
comment|/* don't print error on bad status */
end_comment

begin_define
define|#
directive|define
name|M_RESTR
value|000000010L
end_define

begin_comment
comment|/* must be daemon to execute */
end_comment

begin_define
define|#
directive|define
name|M_NHDR
value|000000020L
end_define

begin_comment
comment|/* don't insert From line */
end_comment

begin_define
define|#
directive|define
name|M_LOCAL
value|000000040L
end_define

begin_comment
comment|/* delivery is to this host */
end_comment

begin_define
define|#
directive|define
name|M_STRIPQ
value|000000100L
end_define

begin_comment
comment|/* strip quote chars from user/host */
end_comment

begin_define
define|#
directive|define
name|M_MUSER
value|000000200L
end_define

begin_comment
comment|/* can handle multiple users at once */
end_comment

begin_define
define|#
directive|define
name|M_NEEDFROM
value|000000400L
end_define

begin_comment
comment|/* need arpa-style From: line */
end_comment

begin_define
define|#
directive|define
name|M_NEEDDATE
value|000001000L
end_define

begin_comment
comment|/* need arpa-style Date: line */
end_comment

begin_define
define|#
directive|define
name|M_MSGID
value|000002000L
end_define

begin_comment
comment|/* need Message-Id: field */
end_comment

begin_define
define|#
directive|define
name|M_RELRCPT
value|000004000L
end_define

begin_comment
comment|/* make recipient addresses relative */
end_comment

begin_define
define|#
directive|define
name|M_USR_UPPER
value|000010000L
end_define

begin_comment
comment|/* preserve user case distinction */
end_comment

begin_define
define|#
directive|define
name|M_HST_UPPER
value|000020000L
end_define

begin_comment
comment|/* preserve host case distinction */
end_comment

begin_define
define|#
directive|define
name|M_FULLNAME
value|000040000L
end_define

begin_comment
comment|/* want Full-Name field */
end_comment

begin_define
define|#
directive|define
name|M_UGLYUUCP
value|000100000L
end_define

begin_comment
comment|/* this wants an ugly UUCP from line */
end_comment

begin_define
define|#
directive|define
name|M_EXPENSIVE
value|000200000L
end_define

begin_comment
comment|/* it costs to use this mailer.... */
end_comment

begin_define
define|#
directive|define
name|M_FULLSMTP
value|000400000L
end_define

begin_comment
comment|/* must run full SMTP, inc. limits */
end_comment

begin_define
define|#
directive|define
name|M_ARPAFMT
value|(M_NEEDDATE|M_NEEDFROM|M_MSGID)
end_define

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
name|u_long
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
name|u_short
name|hi_mflags
decl_stmt|;
comment|/* m_flags needed for this field */
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
name|H_USED
value|00010
end_define

begin_comment
comment|/* indicates that this has been output */
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
name|H_ADDR
value|00200
end_define

begin_comment
comment|/* this field contains addresses */
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
name|bool
name|e_queueup
decl_stmt|;
comment|/* queue this message */
name|bool
name|e_oldstyle
decl_stmt|;
comment|/* use spaces (not commas) in hdrs */
name|bool
name|e_retreceipt
decl_stmt|;
comment|/* give a return receipt */
name|bool
name|e_sendreceipt
decl_stmt|;
comment|/* actually send a receipt back */
name|char
modifier|*
name|e_origfrom
decl_stmt|;
comment|/* the From: line first read */
name|char
modifier|*
name|e_to
decl_stmt|;
comment|/* the target person */
name|ADDRESS
name|e_from
decl_stmt|;
comment|/* the person it is from */
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
name|short
name|e_class
decl_stmt|;
comment|/* msg class (priority, junk, etc.) */
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
name|char
modifier|*
name|e_df
decl_stmt|;
comment|/* location of temp file */
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
comment|/* **  Work queue. */
end_comment

begin_struct
struct|struct
name|work
block|{
name|char
modifier|*
name|w_name
decl_stmt|;
comment|/* name of control file */
name|long
name|w_pri
decl_stmt|;
comment|/* priority of message, see below */
name|struct
name|work
modifier|*
name|w_next
decl_stmt|;
comment|/* next in queue */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|work
name|WORK
typedef|;
end_typedef

begin_decl_stmt
name|EXTERN
name|WORK
modifier|*
name|WorkQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of things to be done */
end_comment

begin_comment
comment|/* **  Message priorities. **	Priorities> 0 should be preemptive. ** **	CurEnv->e_msgpriority is the number of bytes in the message adjusted **	by the message priority and the amount of time the message **	has been sitting around.  Each priority point is worth **	WKPRIFACT bytes of message, and each time we reprocess a **	message the size gets reduced by WKTIMEFACT. ** **	The "class" is this number, unadjusted by the age or size of **	this message.  Classes with negative representations will have **	error messages thrown away if they are not local. */
end_comment

begin_define
define|#
directive|define
name|PRI_ALERT
value|50
end_define

begin_define
define|#
directive|define
name|PRI_QUICK
value|30
end_define

begin_define
define|#
directive|define
name|PRI_FIRSTCL
value|10
end_define

begin_define
define|#
directive|define
name|PRI_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|PRI_SECONDCL
value|-10
end_define

begin_define
define|#
directive|define
name|PRI_THIRDCL
value|-40
end_define

begin_define
define|#
directive|define
name|PRI_JUNK
value|-100
end_define

begin_define
define|#
directive|define
name|WKPRIFACT
value|1800
end_define

begin_comment
comment|/* bytes each pri point is worth */
end_comment

begin_define
define|#
directive|define
name|WKTIMEFACT
value|400
end_define

begin_comment
comment|/* bytes each time unit is worth */
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
specifier|extern
name|struct
name|rewrite
modifier|*
name|RewriteRules
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MATCHANY
value|'\020'
end_define

begin_comment
comment|/* match one or more tokens */
end_comment

begin_define
define|#
directive|define
name|MATCHONE
value|'\021'
end_define

begin_comment
comment|/* match exactly one token */
end_comment

begin_define
define|#
directive|define
name|MATCHCLASS
value|'\022'
end_define

begin_comment
comment|/* match one token in a class */
end_comment

begin_define
define|#
directive|define
name|MATCHREPL
value|'\023'
end_define

begin_comment
comment|/* replacement on RHS for above */
end_comment

begin_define
define|#
directive|define
name|CANONNET
value|'\025'
end_define

begin_comment
comment|/* canonical net, next token */
end_comment

begin_define
define|#
directive|define
name|CANONHOST
value|'\026'
end_define

begin_comment
comment|/* canonical host, next token */
end_comment

begin_define
define|#
directive|define
name|CANONUSER
value|'\027'
end_define

begin_comment
comment|/* canonical user, next N tokens */
end_comment

begin_define
define|#
directive|define
name|CONDIF
value|'\030'
end_define

begin_comment
comment|/* conditional if-then */
end_comment

begin_define
define|#
directive|define
name|CONDELSE
value|'\031'
end_define

begin_comment
comment|/* conditional else */
end_comment

begin_define
define|#
directive|define
name|CONDFI
value|'\032'
end_define

begin_comment
comment|/* conditional fi */
end_comment

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
name|long
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
comment|/* **  Statistics structure. */
end_comment

begin_struct
struct|struct
name|statistics
block|{
name|time_t
name|stat_itime
decl_stmt|;
comment|/* file initialization time */
name|short
name|stat_size
decl_stmt|;
comment|/* size of this structure */
name|long
name|stat_nf
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # msgs from each mailer */
name|long
name|stat_bf
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* kbytes from each mailer */
name|long
name|stat_nt
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* # msgs to each mailer */
name|long
name|stat_bt
index|[
name|MAXMAILERS
index|]
decl_stmt|;
comment|/* kbytes to each mailer */
block|}
struct|;
end_struct

begin_decl_stmt
name|EXTERN
name|struct
name|statistics
name|Stat
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|kbytes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for _bf, _bt */
end_comment

begin_escape
end_escape

begin_comment
comment|/* **  Operation modes **	The default operation mode can be safely changed (except **	that the default cannot be MD_DAEMON). */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|Mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operation mode, see below */
end_comment

begin_define
define|#
directive|define
name|MD_DELIVER
value|'a'
end_define

begin_comment
comment|/* collect and deliver */
end_comment

begin_define
define|#
directive|define
name|MD_FORK
value|'f'
end_define

begin_comment
comment|/* verify& fork before delivery */
end_comment

begin_define
define|#
directive|define
name|MD_QUEUE
value|'q'
end_define

begin_comment
comment|/* collect& queue, don't deliver */
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
name|MD_DEFAULT
value|MD_DELIVER
end_define

begin_comment
comment|/* default operation mode */
end_comment

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
name|MailBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail back response on error */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|BerkNet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called from BerkNet */
end_comment

begin_decl_stmt
name|EXTERN
name|bool
name|WriteBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write back response on error */
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
name|DontSend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mark recipients as QDONTSEND */
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
name|Smtp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* using SMTP over connection */
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
name|ArpaMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if running arpanet protocol */
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
name|FatalErrors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if fatal errors during processing */
end_comment

begin_decl_stmt
specifier|extern
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
name|FILE
modifier|*
name|TempFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail temp file */
end_comment

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|Xscript
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail transcript file */
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
specifier|extern
name|int
name|DefUid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default uid to run as */
end_comment

begin_decl_stmt
specifier|extern
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
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging level */
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
name|HopCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hop count */
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
name|HostName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of this host for SMTP messages */
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Transcript
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the transcript file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|XcriptFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* template for Transcript */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AliasFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of alias file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ConfFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of configuration file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|StatFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of statistics summary */
end_comment

begin_decl_stmt
specifier|extern
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
name|time_t
name|CurTime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of this message */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_define
define|#
directive|define
name|setstat
parameter_list|(
name|s
parameter_list|)
value|{ if (ExitStat == EX_OK) ExitStat = s; }
end_define

begin_comment
comment|/* useful functions */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|newstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ADDRESS
modifier|*
name|parse
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

end_unit

