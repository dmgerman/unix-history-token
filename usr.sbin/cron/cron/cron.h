begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 1988,1990,1993,1994 by Paul Vixie  * All rights reserved  *  * Distribute freely, except: don't remove my name from the source or  * documentation (don't take credit for my work), mark your changes (don't  * get me blamed for your possible bugs), don't alter or remove this  * notice.  May be sold if buildable source is provided to buyer.  No  * warrantee of any kind, express or implied, is included with this  * software; use at your own risk, responsibility for damages (if any) to  * anyone resulting from the use of this software rests entirely with the  * user.  *  * Send bug reports, bug fixes, enhancements, requests, flames, etc., and  * I'll try to keep a version up to date.  I can be reached as follows:  * Paul Vixie<paul@vix.com>          uunet!decwrl!vixie!paul  */
end_comment

begin_comment
comment|/* cron.h - header for vixie's cron  *  * $FreeBSD$  *  * vix 14nov88 [rest of log is in RCS]  * vix 14jan87 [0 or 7 can be sunday; thanks, mwm@berkeley]  * vix 30dec86 [written]  */
end_comment

begin_comment
comment|/* reorder these #include's at your peril */
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

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"externs.h"
end_include

begin_comment
comment|/* these are really immutable, and are 	 *   defined for symbolic convenience only 	 * TRUE, FALSE, and ERR must be distinct 	 * ERR must be< OK. 	 */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/* system calls return this on success */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_comment
comment|/*   or this on error */
end_comment

begin_define
define|#
directive|define
name|ERR
value|(-1)
end_define

begin_comment
comment|/* turn this on to get '-x' code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGGING
end_ifndef

begin_define
define|#
directive|define
name|DEBUGGING
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_PIPE
value|0
end_define

begin_comment
comment|/* which end of a pipe pair do you read? */
end_comment

begin_define
define|#
directive|define
name|WRITE_PIPE
value|1
end_define

begin_comment
comment|/*   or write to? */
end_comment

begin_define
define|#
directive|define
name|STDIN
value|0
end_define

begin_comment
comment|/* what is stdin's file descriptor? */
end_comment

begin_define
define|#
directive|define
name|STDOUT
value|1
end_define

begin_comment
comment|/*   stdout's? */
end_comment

begin_define
define|#
directive|define
name|STDERR
value|2
end_define

begin_comment
comment|/*   stderr's? */
end_comment

begin_define
define|#
directive|define
name|ERROR_EXIT
value|1
end_define

begin_comment
comment|/* exit() with this will scare the shell */
end_comment

begin_define
define|#
directive|define
name|OK_EXIT
value|0
end_define

begin_comment
comment|/* exit() with this is considered 'normal' */
end_comment

begin_define
define|#
directive|define
name|MAX_FNAME
value|100
end_define

begin_comment
comment|/* max length of internally generated fn */
end_comment

begin_define
define|#
directive|define
name|MAX_COMMAND
value|1000
end_define

begin_comment
comment|/* max length of internally generated cmd */
end_comment

begin_define
define|#
directive|define
name|MAX_ENVSTR
value|1000
end_define

begin_comment
comment|/* max length of envvar=value\0 strings */
end_comment

begin_define
define|#
directive|define
name|MAX_TEMPSTR
value|100
end_define

begin_comment
comment|/* obvious */
end_comment

begin_define
define|#
directive|define
name|ROOT_UID
value|0
end_define

begin_comment
comment|/* don't change this, it really must be root */
end_comment

begin_define
define|#
directive|define
name|ROOT_USER
value|"root"
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|SYS_NAME
value|"*system*"
end_define

begin_comment
comment|/* magic owner name for system crontab */
end_comment

begin_comment
comment|/* NOTE: these correspond to DebugFlagNames, 				 *	defined below. 				 */
end_comment

begin_define
define|#
directive|define
name|DEXT
value|0x0001
end_define

begin_comment
comment|/* extend flag for other debug masks */
end_comment

begin_define
define|#
directive|define
name|DSCH
value|0x0002
end_define

begin_comment
comment|/* scheduling debug mask */
end_comment

begin_define
define|#
directive|define
name|DPROC
value|0x0004
end_define

begin_comment
comment|/* process control debug mask */
end_comment

begin_define
define|#
directive|define
name|DPARS
value|0x0008
end_define

begin_comment
comment|/* parsing debug mask */
end_comment

begin_define
define|#
directive|define
name|DLOAD
value|0x0010
end_define

begin_comment
comment|/* database loading debug mask */
end_comment

begin_define
define|#
directive|define
name|DMISC
value|0x0020
end_define

begin_comment
comment|/* misc debug mask */
end_comment

begin_define
define|#
directive|define
name|DTEST
value|0x0040
end_define

begin_comment
comment|/* test mode: don't execute any commands */
end_comment

begin_define
define|#
directive|define
name|DBIT
value|0x0080
end_define

begin_comment
comment|/* bit twiddling shown (long) */
end_comment

begin_define
define|#
directive|define
name|CRON_TAB
parameter_list|(
name|u
parameter_list|)
value|"%s/%s", SPOOL_DIR, u
end_define

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_define
define|#
directive|define
name|PPC_NULL
value|((char **)NULL)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Skip_Blanks
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|while (c == '\t' || c == ' ') \ 				c = get_char(f);
end_define

begin_define
define|#
directive|define
name|Skip_Nonblanks
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|while (c!='\t'&& c!=' '&& c!='\n'&& c != EOF) \ 				c = get_char(f);
end_define

begin_define
define|#
directive|define
name|Skip_Line
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|do {c = get_char(f);} while (c != '\n'&& c != EOF);
end_define

begin_if
if|#
directive|if
name|DEBUGGING
end_if

begin_define
define|#
directive|define
name|Debug
parameter_list|(
name|mask
parameter_list|,
name|message
parameter_list|)
define|\
value|if ( (DebugFlags& (mask) ) == (mask) ) \ 				printf message;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUGGING */
end_comment

begin_define
define|#
directive|define
name|Debug
parameter_list|(
name|mask
parameter_list|,
name|message
parameter_list|)
define|\
value|;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUGGING */
end_comment

begin_define
define|#
directive|define
name|MkLower
parameter_list|(
name|ch
parameter_list|)
value|(isupper(ch) ? tolower(ch) : ch)
end_define

begin_define
define|#
directive|define
name|MkUpper
parameter_list|(
name|ch
parameter_list|)
value|(islower(ch) ? toupper(ch) : ch)
end_define

begin_define
define|#
directive|define
name|Set_LineNum
parameter_list|(
name|ln
parameter_list|)
value|{Debug(DPARS|DEXT,("linenum=%d\n",ln)); \ 			 LineNumber = ln; \ 			}
end_define

begin_define
define|#
directive|define
name|FIRST_SECOND
value|0
end_define

begin_define
define|#
directive|define
name|LAST_SECOND
value|59
end_define

begin_define
define|#
directive|define
name|SECOND_COUNT
value|(LAST_SECOND - FIRST_SECOND + 1)
end_define

begin_define
define|#
directive|define
name|FIRST_MINUTE
value|0
end_define

begin_define
define|#
directive|define
name|LAST_MINUTE
value|59
end_define

begin_define
define|#
directive|define
name|MINUTE_COUNT
value|(LAST_MINUTE - FIRST_MINUTE + 1)
end_define

begin_define
define|#
directive|define
name|FIRST_HOUR
value|0
end_define

begin_define
define|#
directive|define
name|LAST_HOUR
value|23
end_define

begin_define
define|#
directive|define
name|HOUR_COUNT
value|(LAST_HOUR - FIRST_HOUR + 1)
end_define

begin_define
define|#
directive|define
name|FIRST_DOM
value|1
end_define

begin_define
define|#
directive|define
name|LAST_DOM
value|31
end_define

begin_define
define|#
directive|define
name|DOM_COUNT
value|(LAST_DOM - FIRST_DOM + 1)
end_define

begin_define
define|#
directive|define
name|FIRST_MONTH
value|1
end_define

begin_define
define|#
directive|define
name|LAST_MONTH
value|12
end_define

begin_define
define|#
directive|define
name|MONTH_COUNT
value|(LAST_MONTH - FIRST_MONTH + 1)
end_define

begin_comment
comment|/* note on DOW: 0 and 7 are both Sunday, for compatibility reasons. */
end_comment

begin_define
define|#
directive|define
name|FIRST_DOW
value|0
end_define

begin_define
define|#
directive|define
name|LAST_DOW
value|7
end_define

begin_define
define|#
directive|define
name|DOW_COUNT
value|(LAST_DOW - FIRST_DOW + 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOGIN_CAP
end_ifdef

begin_comment
comment|/* see init.c */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_RC
value|"daemon"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* each user's crontab will be held as a list of 			 * the following structure. 			 * 			 * These are the cron commands. 			 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_entry
block|{
name|struct
name|_entry
modifier|*
name|next
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
ifdef|#
directive|ifdef
name|LOGIN_CAP
name|char
modifier|*
name|class
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
modifier|*
name|envp
decl_stmt|;
name|char
modifier|*
name|cmd
decl_stmt|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|second
parameter_list|,
name|SECOND_COUNT
parameter_list|)
function_decl|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|minute
parameter_list|,
name|MINUTE_COUNT
parameter_list|)
function_decl|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|hour
parameter_list|,
name|HOUR_COUNT
parameter_list|)
function_decl|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|dom
parameter_list|,
name|DOM_COUNT
parameter_list|)
function_decl|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|month
parameter_list|,
name|MONTH_COUNT
parameter_list|)
function_decl|;
name|bitstr_t
name|bit_decl
parameter_list|(
name|dow
parameter_list|,
name|DOW_COUNT
parameter_list|)
function_decl|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|DOM_STAR
value|0x01
define|#
directive|define
name|DOW_STAR
value|0x02
define|#
directive|define
name|WHEN_REBOOT
value|0x04
define|#
directive|define
name|RUN_AT
value|0x08
define|#
directive|define
name|NOT_UNTIL
value|0x10
define|#
directive|define
name|SEC_RES
value|0x20
name|time_t
name|lastrun
decl_stmt|;
block|}
name|entry
typedef|;
end_typedef

begin_comment
comment|/* the crontab database will be a list of the 			 * following structure, one element per user 			 * plus one for the system. 			 * 			 * These are the crontabs. 			 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_user
block|{
name|struct
name|_user
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* links */
name|char
modifier|*
name|name
decl_stmt|;
name|time_t
name|mtime
decl_stmt|;
comment|/* last modtime of crontab */
name|entry
modifier|*
name|crontab
decl_stmt|;
comment|/* this person's crontab */
block|}
name|user
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_cron_db
block|{
name|user
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
comment|/* links */
name|time_t
name|mtime
decl_stmt|;
comment|/* last modtime on spooldir */
block|}
name|cron_db
typedef|;
end_typedef

begin_decl_stmt
name|void
name|set_cron_uid
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|set_cron_cwd
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|load_database
argument_list|(
name|cron_db
operator|*
argument_list|)
decl_stmt|,
name|open_logfile
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|sigpipe_func
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|job_add
argument_list|(
name|entry
operator|*
argument_list|,
name|user
operator|*
argument_list|)
decl_stmt|,
name|do_command
argument_list|(
name|entry
operator|*
argument_list|,
name|user
operator|*
argument_list|)
decl_stmt|,
name|link_user
argument_list|(
name|cron_db
operator|*
argument_list|,
name|user
operator|*
argument_list|)
decl_stmt|,
name|unlink_user
argument_list|(
name|cron_db
operator|*
argument_list|,
name|user
operator|*
argument_list|)
decl_stmt|,
name|free_user
argument_list|(
name|user
operator|*
argument_list|)
decl_stmt|,
name|env_free
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
name|unget_char
argument_list|(
name|int
argument_list|,
name|FILE
operator|*
argument_list|)
decl_stmt|,
name|free_entry
argument_list|(
name|entry
operator|*
argument_list|)
decl_stmt|,
name|skip_comments
argument_list|(
name|FILE
operator|*
argument_list|)
decl_stmt|,
name|log_it
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|log_close
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|job_runqueue
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|set_debug_flags
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|get_char
argument_list|(
name|FILE
operator|*
argument_list|)
decl_stmt|,
name|get_string
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|FILE
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
name|swap_uids
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|swap_uids_back
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|load_env
argument_list|(
name|char
operator|*
argument_list|,
name|FILE
operator|*
argument_list|)
decl_stmt|,
name|cron_pclose
argument_list|(
name|FILE
operator|*
argument_list|)
decl_stmt|,
name|strcmp_until
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|int
argument_list|)
decl_stmt|,
name|allowed
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|,
name|strdtb
argument_list|(
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|env_get
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
modifier|*
name|arpadate
argument_list|(
name|time_t
operator|*
argument_list|)
decl_stmt|,
modifier|*
name|mkprints
argument_list|(
name|unsigned
name|char
operator|*
argument_list|,
name|unsigned
name|int
argument_list|)
decl_stmt|,
modifier|*
name|first_word
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
modifier|*
modifier|*
name|env_init
argument_list|(
name|void
argument_list|)
decl_stmt|,
modifier|*
modifier|*
name|env_copy
argument_list|(
name|char
operator|*
operator|*
argument_list|)
decl_stmt|,
modifier|*
modifier|*
name|env_set
argument_list|(
name|char
operator|*
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|user
modifier|*
name|load_user
argument_list|(
name|int
argument_list|,
expr|struct
name|passwd
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|,
modifier|*
name|find_user
argument_list|(
name|cron_db
operator|*
argument_list|,
name|char
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|entry
modifier|*
name|load_entry
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
parameter_list|,
name|struct
name|passwd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|cron_popen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in the C tradition, we only create 				 * variables for the main program, just 				 * extern them elsewhere. 				 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN_PROGRAM
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|copyright
index|[]
init|=
block|{
literal|"@(#) Copyright 1988,1989,1990,1993,1994 by Paul Vixie"
block|,
literal|"@(#) All rights reserved"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|MonthNames
index|[]
init|=
block|{
literal|"Jan"
block|,
literal|"Feb"
block|,
literal|"Mar"
block|,
literal|"Apr"
block|,
literal|"May"
block|,
literal|"Jun"
block|,
literal|"Jul"
block|,
literal|"Aug"
block|,
literal|"Sep"
block|,
literal|"Oct"
block|,
literal|"Nov"
block|,
literal|"Dec"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DowNames
index|[]
init|=
block|{
literal|"Sun"
block|,
literal|"Mon"
block|,
literal|"Tue"
block|,
literal|"Wed"
block|,
literal|"Thu"
block|,
literal|"Fri"
block|,
literal|"Sat"
block|,
literal|"Sun"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ProgramName
decl_stmt|,
modifier|*
name|defmailto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|LineNumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|Jitter
decl_stmt|,
name|RootJitter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|TargetTime
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUGGING
end_if

begin_decl_stmt
name|int
name|DebugFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|DebugFlagNames
index|[]
init|=
block|{
comment|/* sync with #defines */
literal|"ext"
block|,
literal|"sch"
block|,
literal|"proc"
block|,
literal|"pars"
block|,
literal|"load"
block|,
literal|"misc"
block|,
literal|"test"
block|,
literal|"bit"
block|,
name|NULL
comment|/* NULL must be last element */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUGGING */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*MAIN_PROGRAM*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|copyright
index|[]
decl_stmt|,
modifier|*
name|MonthNames
index|[]
decl_stmt|,
modifier|*
name|DowNames
index|[]
decl_stmt|,
modifier|*
name|ProgramName
decl_stmt|,
modifier|*
name|defmailto
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LineNumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|Jitter
decl_stmt|,
name|RootJitter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|TargetTime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pidfh
modifier|*
name|pfh
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|DEBUGGING
end_if

begin_decl_stmt
specifier|extern
name|int
name|DebugFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DebugFlagNames
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUGGING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MAIN_PROGRAM*/
end_comment

end_unit

