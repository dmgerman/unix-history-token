begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  SENDMAIL.H -- Global definitions for sendmail. ** **	@(#)sendmail.h	3.26	%G% */
end_comment

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_comment
comment|/* **  Manifest constants. */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|256
end_define

begin_comment
comment|/* maximum line length */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|128
end_define

begin_comment
comment|/* maximum length of a name */
end_comment

begin_define
define|#
directive|define
name|MAXFIELD
value|2500
end_define

begin_comment
comment|/* maximum total length of a header field */
end_comment

begin_define
define|#
directive|define
name|MAXPV
value|40
end_define

begin_comment
comment|/* maximum # of parms to mailers */
end_comment

begin_define
define|#
directive|define
name|MAXHOP
value|30
end_define

begin_comment
comment|/* maximum value of HopCount */
end_comment

begin_define
define|#
directive|define
name|MAXATOM
value|15
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
name|ALIASFILE
value|"/usr/lib/aliases"
end_define

begin_comment
comment|/* location of alias file */
end_comment

begin_define
define|#
directive|define
name|CONFFILE
value|"/usr/lib/sendmail.cf"
end_define

begin_comment
comment|/* configuration file */
end_comment

begin_comment
comment|/* values for ArpaMode -- these are ordered!! */
end_comment

begin_define
define|#
directive|define
name|ARPA_NONE
value|0
end_define

begin_comment
comment|/* not in arpanet mode */
end_comment

begin_define
define|#
directive|define
name|ARPA_OLD
value|1
end_define

begin_comment
comment|/* in old arpanet mode */
end_comment

begin_define
define|#
directive|define
name|ARPA_MAIL
value|2
end_define

begin_comment
comment|/* in regular arpanet mail */
end_comment

begin_define
define|#
directive|define
name|ARPA_FILE
value|3
end_define

begin_comment
comment|/* reading over data connection */
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
name|q_host
decl_stmt|;
comment|/* host name */
name|short
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
name|char
modifier|*
name|q_home
decl_stmt|;
comment|/* home dir (local mailer only) */
name|struct
name|address
modifier|*
name|q_next
decl_stmt|;
comment|/* chain */
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

begin_comment
comment|/* **  Mailer definition structure. **	Every mailer known to the system is declared in this **	structure.  It defines the pathname of the mailer, some **	flags associated with it, and the argument vector to **	pass to it.  The flags are defined in conf.c ** **	The host map is a list of lists of strings.  Within each **	list, any host is mapped to the last host in the list. **	This allows multiple names, as well as doing clever **	mail grouping in point-to-point networks.  Note: this **	is only used internally, so the apparent host is still **	kept around. ** **	The argument vector is expanded before actual use.  Every- **	thing is passed through except for things starting with "$". **	"$x" defines some interpolation, as described in conf.c **	"$x" where x is unknown expands to "x", so use "$$" to get "$". */
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
name|ADDRESS
modifier|*
name|m_sendq
decl_stmt|;
comment|/* list of addresses to send to */
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

begin_define
define|#
directive|define
name|M_FOPT
value|000001
end_define

begin_comment
comment|/* mailer takes picky -f flag */
end_comment

begin_define
define|#
directive|define
name|M_ROPT
value|000002
end_define

begin_comment
comment|/* mailer takes picky -r flag */
end_comment

begin_define
define|#
directive|define
name|M_QUIET
value|000004
end_define

begin_comment
comment|/* don't print error on bad status */
end_comment

begin_define
define|#
directive|define
name|M_RESTR
value|000010
end_define

begin_comment
comment|/* must be daemon to execute */
end_comment

begin_define
define|#
directive|define
name|M_NHDR
value|000020
end_define

begin_comment
comment|/* don't insert From line */
end_comment

begin_define
define|#
directive|define
name|M_NOHOST
value|000040
end_define

begin_comment
comment|/* ignore host in comparisons */
end_comment

begin_define
define|#
directive|define
name|M_STRIPQ
value|000100
end_define

begin_comment
comment|/* strip quote characters from user/host */
end_comment

begin_define
define|#
directive|define
name|M_MUSER
value|000200
end_define

begin_comment
comment|/* mailer can handle multiple users at once */
end_comment

begin_define
define|#
directive|define
name|M_NEEDFROM
value|000400
end_define

begin_comment
comment|/* need arpa-style From: line */
end_comment

begin_define
define|#
directive|define
name|M_NEEDDATE
value|001000
end_define

begin_comment
comment|/* need arpa-style Date: line */
end_comment

begin_define
define|#
directive|define
name|M_MSGID
value|002000
end_define

begin_comment
comment|/* need Message-Id: field */
end_comment

begin_define
define|#
directive|define
name|M_FINAL
value|004000
end_define

begin_comment
comment|/* mailing will effect final delivery */
end_comment

begin_define
define|#
directive|define
name|M_USR_UPPER
value|010000
end_define

begin_comment
comment|/* preserve user case distinction */
end_comment

begin_define
define|#
directive|define
name|M_HST_UPPER
value|020000
end_define

begin_comment
comment|/* preserve host case distinction */
end_comment

begin_define
define|#
directive|define
name|M_FULLNAME
value|040000
end_define

begin_comment
comment|/* want Full-Name field */
end_comment

begin_define
define|#
directive|define
name|M_ARPAFMT
value|(M_NEEDDATE|M_NEEDFROM|M_NEEDDATE)
end_define

begin_decl_stmt
specifier|extern
name|MAILER
modifier|*
name|Mailer
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special mailer numbers */
end_comment

begin_define
define|#
directive|define
name|M_LOCAL
value|0
end_define

begin_comment
comment|/* local mailer */
end_comment

begin_define
define|#
directive|define
name|M_PROG
value|1
end_define

begin_comment
comment|/* program mailer */
end_comment

begin_comment
comment|/* mailers from 2 on are arbitrary */
end_comment

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

begin_decl_stmt
specifier|extern
name|HDR
modifier|*
name|Header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of header list */
end_comment

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
name|H_DELETE
value|00002
end_define

begin_comment
comment|/* don't send this field */
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
name|s_addr
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

begin_comment
comment|/* **  Global variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ArpaMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARPANET handling mode */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|FromFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, "From" person is explicit */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|MailBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail back response on error */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|BerkNet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called from BerkNet */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|WriteBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write back response on error */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|NoAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, don't do any aliasing */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|ForceMail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, mail even if already got a copy */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|MeToo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send to the sender also */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|IgnrDot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't let dot end messages */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|SaveFrom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save leading "From" lines */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if blow-by-blow desired */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if errors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ExitStat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit status code */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|InFileName
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Transcript
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the transcript file name */
end_comment

begin_decl_stmt
specifier|extern
name|ADDRESS
name|From
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the person it is from */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|To
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the target person */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|HopCount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hop count */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|CurTime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of this message */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|FromLine
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a UNIX-style From line for this message */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|AliasLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of aliasing */
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
name|char
modifier|*
name|expand
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

end_unit

