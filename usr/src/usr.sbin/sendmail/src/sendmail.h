begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  DELIVERMAIL.H -- Global definitions for delivermail. ** **	Most of these are actually allocated in globals.c ** **	History: **		12/26/79 -- written. */
end_comment

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

begin_comment
comment|/* **  Mailer definition structure. **	Every mailer known to the system is declared in this **	structure.  It defines the pathname of the mailer, some **	flags associated with it, and the argument vector to **	pass to it. ** **	The flags are as follows: **		M_FOPT -- if set, the mailer has a picky "-f" **			option.  In this mode, the mailer will only **			accept the "-f" option if the sender is **			actually "root", "network", and possibly **			(but not necessarily) if the -f argument **			matches the real sender.  The effect is **			that if the "-f" option is given to **			delivermail then it will be passed through **			(as arguments 1& 2) to the mailer. **		M_ROPT -- identical to M_FOPT, except uses -r instead. **			UGH! **		M_QUIET -- if set, don't print a message if the mailer **			returns bad status. **		M_RESTR -- if set, this mailer is restricted to use **			by "daemon"; otherwise, we do a **			setuid(getuid()) before calling the mailer. **		M_HDR -- if set, the mailer wants us to insert a **			UNIX "From" line before outputting. **		M_NOHOST -- if set, this mailer doesn't care about **			the host part (e.g., the local mailer). **		M_STRIPQ -- if set, strip quote (`"') characters **			out of parameters as you transliterate them **			into the argument vector.  For example, the **			local mailer is called directly, so these **			should be stripped, but the program-mailer **			(i.e., csh) should leave them in. ** **	The argument vector is expanded before actual use.  Every- **	thing is passed through except for things starting with "$". **	"$x" defines some interpolation, as defined by x: **		$f	The "from" person. **		$h	The host being sent to. **		$u	The user being sent to. **		$c	The current hop count. **	"$x" where x is unknown expands to "x", so use "$$" to get "$". */
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
value|0001
end_define

begin_comment
comment|/* mailer takes picky -f flag */
end_comment

begin_define
define|#
directive|define
name|M_ROPT
value|0002
end_define

begin_comment
comment|/* mailer takes picky -r flag */
end_comment

begin_define
define|#
directive|define
name|M_QUIET
value|0004
end_define

begin_comment
comment|/* don't print error on bad status */
end_comment

begin_define
define|#
directive|define
name|M_RESTR
value|0010
end_define

begin_comment
comment|/* must be daemon to execute */
end_comment

begin_define
define|#
directive|define
name|M_HDR
value|0020
end_define

begin_comment
comment|/* insert From line */
end_comment

begin_define
define|#
directive|define
name|M_NOHOST
value|0040
end_define

begin_comment
comment|/* ignore host in comparisons */
end_comment

begin_define
define|#
directive|define
name|M_STRIPQ
value|0100
end_define

begin_comment
comment|/* strip quote characters from user/host */
end_comment

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
name|addrq
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
name|addrq
name|SendQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of people to send to */
end_comment

begin_decl_stmt
specifier|extern
name|addrq
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
comment|/* **  Global variables. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ArpaFmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, message is in arpanet fmt */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|FromFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, "From" person is explicit */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, debugging info */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MailBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mail back response on error */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|BerkNet
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called from BerkNet */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|WriteBack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* write back response on error */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|NoAlias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, don't do any aliasing */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ForceMail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, mail even if already got a copy */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|MeToo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send to the sender also */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Error
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
name|addrq
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
name|flagset
parameter_list|(
name|bits
parameter_list|,
name|word
parameter_list|)
value|((bits)& (word))
end_define

begin_define
define|#
directive|define
name|setstat
parameter_list|(
name|s
parameter_list|)
value|{ if (ExitStat == EX_OK) ExitStat = s; }
end_define

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_define
define|#
directive|define
name|BADMAIL
value|YES
end_define

begin_comment
comment|/* mail doesn't know about new returncodes */
end_comment

end_unit

