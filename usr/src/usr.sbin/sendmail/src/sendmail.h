begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  POSTBOX.H -- Global definitions for postbox. ** **	Most of these are actually allocated in globals.c ** **	@(#)sendmail.h	3.3	%G% */
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
value|15
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
name|ALIASFILE
value|"/usr/lib/aliases"
end_define

begin_comment
comment|/* location of alias file */
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
name|m_mailer
decl_stmt|;
comment|/* pathname of the mailer to use */
name|short
name|m_flags
decl_stmt|;
comment|/* status flags, see below */
name|short
name|m_badstat
decl_stmt|;
comment|/* the status code to use on unknown error */
name|char
modifier|*
modifier|*
name|m_local
decl_stmt|;
comment|/* list of local names for this host */
name|char
modifier|*
name|m_from
decl_stmt|;
comment|/* pattern for From: header */
name|char
modifier|*
modifier|*
modifier|*
name|m_hmap
decl_stmt|;
comment|/* host map */
name|char
modifier|*
name|m_argv
index|[
name|MAXPV
index|]
decl_stmt|;
comment|/* template argument vector */
block|}
struct|;
end_struct

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
name|M_HDR
value|000020
end_define

begin_comment
comment|/* insert From line */
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
name|M_FHDR
value|000200
end_define

begin_comment
comment|/* force good From line */
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
name|M_COMMAS
value|004000
end_define

begin_comment
comment|/* need comma-seperated address lists */
end_comment

begin_define
define|#
directive|define
name|M_ARPAFMT
value|(M_NEEDDATE|M_NEEDFROM|M_MSGID|M_COMMAS)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mailer
name|Mailer
index|[]
decl_stmt|;
end_decl_stmt

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
name|struct
name|mailer
modifier|*
name|q_mailer
decl_stmt|;
comment|/* mailer to use */
name|int
name|q_rmailer
decl_stmt|;
comment|/* real mailer (before mapping) */
name|struct
name|address
modifier|*
name|q_next
decl_stmt|;
comment|/* chain */
name|struct
name|address
modifier|*
name|q_prev
decl_stmt|;
comment|/* back pointer */
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

begin_comment
comment|/* some other primitives */
end_comment

begin_define
define|#
directive|define
name|nxtinq
parameter_list|(
name|q
parameter_list|)
value|((q)->q_next)
end_define

begin_define
define|#
directive|define
name|clearq
parameter_list|(
name|q
parameter_list|)
value|(q)->q_next = (q)->q_prev = NULL
end_define

begin_decl_stmt
specifier|extern
name|ADDRESS
name|SendQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of people to send to */
end_comment

begin_decl_stmt
specifier|extern
name|ADDRESS
name|AliasQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of people that are aliases */
end_comment

begin_comment
comment|/* **  Parse structure. **	This table drives the parser which determines the network **	to send the mail to. */
end_comment

begin_struct
struct|struct
name|parsetab
block|{
name|char
name|p_char
decl_stmt|;
comment|/* trigger character */
name|char
name|p_mailer
decl_stmt|;
comment|/* the index of the mailer to call */
name|short
name|p_flags
decl_stmt|;
comment|/* see below */
name|char
modifier|*
name|p_arg
decl_stmt|;
comment|/* extra info needed for some flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|P_MAP
value|0001
end_define

begin_comment
comment|/* map p_char -> p_arg[0] */
end_comment

begin_define
define|#
directive|define
name|P_HLAST
value|0002
end_define

begin_comment
comment|/* host is last,& right associative */
end_comment

begin_define
define|#
directive|define
name|P_ONE
value|0004
end_define

begin_comment
comment|/* can only be one p_char in addr */
end_comment

begin_define
define|#
directive|define
name|P_MOVE
value|0010
end_define

begin_comment
comment|/* send untouched to host p_arg */
end_comment

begin_define
define|#
directive|define
name|P_USR_UPPER
value|0020
end_define

begin_comment
comment|/* don't map UPPER->lower in user names */
end_comment

begin_define
define|#
directive|define
name|P_HST_UPPER
value|0040
end_define

begin_comment
comment|/* don't map UPPER->lower in host names */
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
name|short
name|h_flags
decl_stmt|;
comment|/* status bits, see below */
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
name|short
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
name|H_CONCAT
value|00001
end_define

begin_comment
comment|/* comma-concat multiple fields */
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

begin_comment
comment|/* **  Global variables. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|ArpaFmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, message is in arpanet fmt */
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
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, debugging info */
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
name|UseMsgId
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* put msg-id's in all msgs [conf.c] */
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
name|char
modifier|*
name|MsgId
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the message id for this message */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Date
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* origination date (UNIX format) */
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

end_unit

