begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is Copyright (c) 1986 by Rick Adams.  *  * Permission is hereby granted to copy, reproduce, redistribute or  * otherwise use this software as long as: there is no monetary  * profit gained specifically from the use or reproduction or this  * software, it is not sold, rented, traded or otherwise marketed, and  * this copyright notice is included prominently in any copy  * made.  *  * The author make no claims as to the fitness or correctness of  * this software for any use whatsoever, and it is provided as is.   * Any use of this software is at the user's own risk.  *  * inews - insert, receive, and transmit news articles.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)inews.c	2.82	10/15/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_include
include|#
directive|include
file|"iparams.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LOCKF
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|F_RDLCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|F_SETLK
argument_list|)
end_if

begin_decl_stmt
name|struct
name|flock
name|news_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* F_RDLCK&& F_SETLK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCKF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BSD4_2 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCKF
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BSD4_2 */
end_comment

begin_comment
comment|/* local defines for inews */
end_comment

begin_define
define|#
directive|define
name|OPTION
value|0
end_define

begin_comment
comment|/* pick up an option string */
end_comment

begin_define
define|#
directive|define
name|STRING
value|1
end_define

begin_comment
comment|/* pick up a string of arguments */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN
value|0001
end_define

begin_comment
comment|/* possible modes for news program */
end_comment

begin_define
define|#
directive|define
name|UNPROC
value|0002
end_define

begin_comment
comment|/* Unprocessed input */
end_comment

begin_define
define|#
directive|define
name|PROC
value|0004
end_define

begin_comment
comment|/* Processed input */
end_comment

begin_define
define|#
directive|define
name|CONTROL
value|0010
end_define

begin_comment
comment|/* Control Message */
end_comment

begin_define
define|#
directive|define
name|CREATENG
value|0020
end_define

begin_comment
comment|/* Create a new newsgroup */
end_comment

begin_define
define|#
directive|define
name|DONT_SPOOL
value|0
end_define

begin_define
define|#
directive|define
name|DO_SPOOL
value|1
end_define

begin_define
define|#
directive|define
name|EXPIRE_RUNNING
value|2
end_define

begin_decl_stmt
name|int
name|spool_news
init|=
name|DONT_SPOOL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|histline
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|forgedname
index|[
name|NAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A user specified -f option. */
end_comment

begin_comment
comment|/* Fake sys line in case they forget their own system */
end_comment

begin_decl_stmt
name|struct
name|srec
name|dummy_srec
init|=
block|{
literal|"MEMEME"
block|,
literal|""
block|,
literal|"all"
block|,
literal|""
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Progname
init|=
literal|"inews"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by xerror to identify failing program */
end_comment

begin_struct
struct|struct
block|{
comment|/* options table. */
name|char
name|optlet
decl_stmt|;
comment|/* option character. */
name|char
name|filchar
decl_stmt|;
comment|/* if to pickup string, fill character. */
name|int
name|flag
decl_stmt|;
comment|/* TRUE if have seen this opt. */
name|int
name|oldmode
decl_stmt|;
comment|/* OR of legal input modes. */
name|int
name|newmode
decl_stmt|;
comment|/* output mode. */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* string buffer */
block|}
modifier|*
name|optpt
struct|,
name|options
index|[]
init|=
block|{
comment|/* optlet	filchar		flag	oldmode	newmode		buf	*/
literal|'t'
block|,
literal|' '
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|title
block|,
literal|'n'
block|,
name|NGDELIM
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|nbuf
block|,
literal|'d'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|distribution
block|,
literal|'e'
block|,
literal|' '
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|expdate
block|,
literal|'p'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNKNOWN
operator||
name|PROC
block|,
name|PROC
block|,
name|filename
block|,
literal|'f'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|forgedname
block|,
literal|'F'
block|,
literal|' '
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|followid
block|,
literal|'c'
block|,
literal|' '
block|,
name|FALSE
block|,
name|UNKNOWN
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|ctlmsg
block|,
literal|'C'
block|,
literal|' '
block|,
name|FALSE
block|,
name|UNKNOWN
block|,
name|CREATENG
block|,
name|header
operator|.
name|ctlmsg
block|,
define|#
directive|define
name|hflag
value|options[9].flag
literal|'h'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|filename
block|,
define|#
directive|define
name|oflag
value|options[10].flag
literal|'o'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|organization
block|,
define|#
directive|define
name|Mflag
value|options[11].flag
literal|'M'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|filename
block|,
literal|'a'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|approved
block|,
literal|'U'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|PROC
block|,
name|PROC
block|,
name|filename
block|,
define|#
directive|define
name|Sflag
value|options[14].flag
literal|'S'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNKNOWN
operator||
name|PROC
block|,
name|UNPROC
block|,
name|filename
block|,
literal|'x'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|not_here
block|,
literal|'r'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNPROC
block|,
name|UNKNOWN
block|,
name|header
operator|.
name|replyto
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|(
name|char
operator|*
operator|)
name|NULL
block|}
struct|;
end_struct

begin_function_decl
name|FILE
modifier|*
name|mailhdr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeb
name|Now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Authors:  *		Matt Glickman	glickman@ucbarpa.Berkeley.ARPA  *		Mark Horton	mark@cbosgd.UUCP  *		Stephen Daniels	swd@mcnc.UUCP  *		Tom Truscott	trt@duke.UUCP  *		Rick Adams	rick@seismo.CSS.GOV  *	IHCC version adapted by:  *		Larry Marek	larry@ihuxf.UUCP  */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|state
decl_stmt|;
comment|/* which type of argument to pick up	*/
name|int
name|tlen
decl_stmt|,
name|len
decl_stmt|;
comment|/* temps for string processing routine	*/
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
comment|/* pointer to rest of buffer		*/
name|int
name|filchar
decl_stmt|;
comment|/* fill character (state = STRING)	*/
name|char
modifier|*
name|user
init|=
name|NULL
decl_stmt|,
modifier|*
name|home
init|=
name|NULL
decl_stmt|;
comment|/* environment temps	*/
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
comment|/* struct for pw lookup			*/
name|struct
name|group
modifier|*
name|gp
decl_stmt|;
comment|/* struct for group lookup		*/
specifier|register
name|int
name|i
decl_stmt|;
name|FILE
modifier|*
name|mfd
decl_stmt|;
comment|/* mail file file-descriptor		*/
comment|/* uuxqt doesn't close all its files */
for|for
control|(
name|i
operator|=
literal|3
init|;
operator|!
name|close
argument_list|(
name|i
argument_list|)
condition|;
name|i
operator|++
control|)
empty_stmt|;
comment|/* set up defaults and initialize. */
name|mode
operator|=
name|UNKNOWN
expr_stmt|;
name|infp
operator|=
name|stdin
expr_stmt|;
name|pathinit
argument_list|()
expr_stmt|;
name|savmask
operator|=
name|umask
argument_list|(
name|N_UMASK
argument_list|)
expr_stmt|;
comment|/* set up mask */
name|ptr
operator|=
name|rindex
argument_list|(
operator|*
name|argv
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ptr
condition|)
name|ptr
operator|=
operator|*
name|argv
operator|-
literal|1
expr_stmt|;
name|actfp
operator|=
name|xfopen
argument_list|(
name|ACTIVE
argument_list|,
literal|"r+"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LOCKF
if|#
directive|if
name|defined
argument_list|(
name|F_RDLCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|F_SETLK
argument_list|)
name|news_lock
operator|.
name|l_type
operator|=
name|F_RDLCK
expr_stmt|;
if|if
condition|(
name|fcntl
argument_list|(
name|fileno
argument_list|(
name|actfp
argument_list|)
argument_list|,
name|F_SETLK
argument_list|,
operator|&
name|news_lock
argument_list|)
operator|<
literal|0
condition|)
block|{
else|#
directive|else
comment|/* !F_RDLCK */
if|if
condition|(
name|lockf
argument_list|(
name|fileno
argument_list|(
name|actfp
argument_list|)
argument_list|,
name|F_TLOCK
argument_list|,
literal|0L
argument_list|)
operator|<
literal|0
condition|)
block|{
endif|#
directive|endif
comment|/* !F_RDLCK */
if|if
condition|(
name|errno
operator|!=
name|EAGAIN
operator|&&
name|errno
operator|!=
name|EACCES
condition|)
else|#
directive|else
comment|/* !LOCKF */
ifdef|#
directive|ifdef
name|BSD4_2
if|if
condition|(
name|flock
argument_list|(
name|fileno
argument_list|(
name|actfp
argument_list|)
argument_list|,
name|LOCK_SH
operator||
name|LOCK_NB
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EWOULDBLOCK
condition|)
else|#
directive|else
comment|/* !BSD4_2 */
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s.lock"
argument_list|,
name|ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|LINK
argument_list|(
name|ACTIVE
argument_list|,
name|bfr
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EEXIST
condition|)
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* !BSD4_2 */
name|xerror
argument_list|(
literal|"Can't lock %s: %s"
argument_list|,
name|ACTIVE
argument_list|,
name|errmsg
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|spool_news
operator|=
name|EXPIRE_RUNNING
expr_stmt|;
block|}
else|else
block|{
ifdef|#
directive|ifdef
name|SPOOLNEWS
if|if
condition|(
name|argc
operator|>
literal|1
operator|&&
operator|!
name|strcmp
argument_list|(
operator|*
operator|(
name|argv
operator|+
literal|1
operator|)
argument_list|,
literal|"-S"
argument_list|)
condition|)
block|{
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
name|Sflag
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|spool_news
operator|=
name|DO_SPOOL
expr_stmt|;
endif|#
directive|endif
comment|/* SPOOLNEWS */
block|}
if|if
condition|(
name|spool_news
operator|!=
name|EXPIRE_RUNNING
condition|)
block|{
comment|/* only unlock if we locked */
ifdef|#
directive|ifdef
name|LOCKF
operator|(
name|void
operator|)
name|lockf
argument_list|(
name|fileno
argument_list|(
name|actfp
argument_list|)
argument_list|,
name|F_ULOCK
argument_list|,
literal|0L
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !LOCKF */
ifdef|#
directive|ifdef
name|BSD4_2
operator|(
name|void
operator|)
name|flock
argument_list|(
name|fileno
argument_list|(
name|actfp
argument_list|)
argument_list|,
name|LOCK_UN
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !BSD4_2 */
operator|(
name|void
operator|)
name|UNLINK
argument_list|(
name|bfr
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* !BSD4_2 */
block|}
else|else
block|{
comment|/* expire is running */
if|if
condition|(
name|argc
operator|>
literal|1
operator|&&
operator|!
name|strcmp
argument_list|(
operator|*
operator|(
name|argv
operator|+
literal|1
operator|)
argument_list|,
literal|"-S"
argument_list|)
condition|)
name|exit
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|/* inform rnews -U by exit status */
block|}
if|if
condition|(
name|argc
operator|>
literal|1
operator|&&
operator|!
name|strcmp
argument_list|(
operator|*
operator|(
name|argv
operator|+
literal|1
operator|)
argument_list|,
literal|"-U"
argument_list|)
condition|)
block|{
comment|/* can't unspool while things are locked */
if|if
condition|(
name|spool_news
operator|==
name|EXPIRE_RUNNING
condition|)
name|xxit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|dounspool
argument_list|()
expr_stmt|;
comment|/* NOT REACHED */
block|}
if|if
condition|(
operator|!
name|STRNCMP
argument_list|(
name|ptr
operator|+
literal|1
argument_list|,
literal|"rnews"
argument_list|,
literal|5
argument_list|)
condition|)
block|{
name|mode
operator|=
name|PROC
expr_stmt|;
if|if
condition|(
name|spool_news
operator|!=
name|DONT_SPOOL
condition|)
block|{
name|dospool
argument_list|(
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
comment|/* NOT REACHED */
block|}
ifdef|#
directive|ifdef
name|NICENESS
if|if
condition|(
name|nice
argument_list|(
literal|0
argument_list|)
operator|<
name|NICENESS
condition|)
operator|(
name|void
operator|)
name|nice
argument_list|(
name|NICENESS
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NICENESS */
block|}
else|else
block|{
comment|/* it's not rnews, so it must be inews */
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
goto|goto
name|usage
goto|;
ifndef|#
directive|ifndef
name|SPOOLINEWS
if|if
condition|(
name|spool_news
operator|==
name|DO_SPOOL
condition|)
name|spool_news
operator|=
name|DONT_SPOOL
expr_stmt|;
endif|#
directive|endif
comment|/* SPOOLINEWS */
block|}
name|state
operator|=
name|OPTION
expr_stmt|;
name|header
operator|.
name|title
index|[
literal|0
index|]
operator|=
name|header
operator|.
name|nbuf
index|[
literal|0
index|]
operator|=
name|filename
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* check for existence of special files */
ifdef|#
directive|ifdef
name|DBM
name|chkfile
argument_list|(
name|ARTFILE
argument_list|)
expr_stmt|;
else|#
directive|else
name|chkdir
argument_list|(
name|ARTFILE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DBM */
name|chkfile
argument_list|(
name|ACTIVE
argument_list|)
expr_stmt|;
name|SigTrap
operator|=
name|FALSE
expr_stmt|;
comment|/* true if a signal has been caught */
if|if
condition|(
name|mode
operator|!=
name|PROC
condition|)
block|{
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|onsig
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|onsig
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Catch "filesize exceeded" signals on 4.2BSD systems 	 * - the history files may exceed this limit. 	 */
ifdef|#
directive|ifdef
name|SIGXFSZ
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGXFSZ
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SIGXFSZ */
name|uid
operator|=
name|getuid
argument_list|()
expr_stmt|;
name|gid
operator|=
name|getgid
argument_list|()
expr_stmt|;
name|duid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
name|dgid
operator|=
name|getegid
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|ftime
argument_list|(
operator|&
name|Now
argument_list|)
expr_stmt|;
if|if
condition|(
name|uid
operator|==
literal|0
operator|&&
name|duid
operator|==
literal|0
condition|)
block|{
comment|/* 		 * Must go through with this kludge since 		 * some systems do not honor the setuid bit 		 * when root invokes a setuid program. 		 */
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|NEWSUSR
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot get NEWSU pw entry"
argument_list|)
expr_stmt|;
name|duid
operator|=
name|pw
operator|->
name|pw_uid
expr_stmt|;
if|if
condition|(
operator|(
name|gp
operator|=
name|getgrnam
argument_list|(
name|NEWSGRP
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Cannot get NEWSG gr entry"
argument_list|)
expr_stmt|;
name|dgid
operator|=
name|gp
operator|->
name|gr_gid
expr_stmt|;
operator|(
name|void
operator|)
name|setgid
argument_list|(
name|dgid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|setuid
argument_list|(
name|duid
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|DOGETUSER
comment|/* 	 * Force the use of 'getuser()' to prevent forgery of articles 	 * by just changing $LOGNAME 	 */
if|if
condition|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stderr
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|user
operator|=
name|getenv
argument_list|(
literal|"USER"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|user
operator|=
name|getenv
argument_list|(
literal|"LOGNAME"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|home
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|home
operator|=
name|getenv
argument_list|(
literal|"LOGDIR"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* !DOGETUSER */
if|if
condition|(
name|user
operator|==
name|NULL
operator|||
name|home
operator|==
name|NULL
condition|)
name|getuser
argument_list|()
expr_stmt|;
else|else
block|{
if|if
condition|(
name|STRCMP
argument_list|(
name|username
argument_list|,
literal|"Unknown"
argument_list|)
operator|==
literal|0
operator|||
name|username
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|username
operator|=
name|AllocCpy
argument_list|(
name|user
argument_list|)
expr_stmt|;
block|}
name|userhome
operator|=
name|AllocCpy
argument_list|(
name|home
argument_list|)
expr_stmt|;
block|}
name|getuser
argument_list|()
expr_stmt|;
comment|/* loop once per arg. */
operator|++
name|argv
expr_stmt|;
comment|/* skip first arg, which is prog name. */
while|while
condition|(
operator|--
name|argc
condition|)
block|{
if|if
condition|(
name|state
operator|==
name|OPTION
condition|)
block|{
if|if
condition|(
operator|*
operator|*
name|argv
operator|!=
literal|'-'
condition|)
block|{
name|xerror
argument_list|(
literal|"Bad option string \"%s\""
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|*
operator|++
operator|*
name|argv
operator|!=
literal|'\0'
condition|)
block|{
for|for
control|(
name|optpt
operator|=
name|options
init|;
name|optpt
operator|->
name|optlet
operator|!=
literal|'\0'
condition|;
operator|++
name|optpt
control|)
block|{
if|if
condition|(
name|optpt
operator|->
name|optlet
operator|==
operator|*
operator|*
name|argv
condition|)
goto|goto
name|found
goto|;
block|}
comment|/* unknown option letter */
name|usage
label|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: inews -t title"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" [ -n newsgroups ]"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" [ -e expiration date ]\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t[ -f sender]\n\n"
argument_list|)
expr_stmt|;
name|xxit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|found
label|:
empty_stmt|;
if|if
condition|(
name|optpt
operator|->
name|flag
operator|==
name|TRUE
operator|||
operator|(
name|mode
operator|!=
name|UNKNOWN
operator|&&
operator|(
name|mode
operator|&
name|optpt
operator|->
name|oldmode
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
name|xerror
argument_list|(
literal|"Bad %c option"
argument_list|,
operator|*
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|==
name|UNKNOWN
condition|)
name|mode
operator|=
name|optpt
operator|->
name|newmode
expr_stmt|;
name|filchar
operator|=
name|optpt
operator|->
name|filchar
expr_stmt|;
name|optpt
operator|->
name|flag
operator|=
name|TRUE
expr_stmt|;
name|state
operator|=
name|STRING
expr_stmt|;
name|ptr
operator|=
name|optpt
operator|->
name|buf
expr_stmt|;
name|len
operator|=
name|BUFLEN
expr_stmt|;
block|}
name|argv
operator|++
expr_stmt|;
comment|/* done with this option arg. */
block|}
else|else
block|{
comment|/* 		 * Pick up a piece of a string and put it into 		 * the appropriate buffer. 		 */
if|if
condition|(
operator|*
operator|*
name|argv
operator|==
literal|'-'
condition|)
block|{
name|state
operator|=
name|OPTION
expr_stmt|;
name|argc
operator|++
expr_stmt|;
comment|/* uncount this arg. */
continue|continue;
block|}
if|if
condition|(
operator|(
name|tlen
operator|=
name|strlen
argument_list|(
operator|*
name|argv
argument_list|)
operator|)
operator|>=
name|len
condition|)
name|xerror
argument_list|(
literal|"Argument string too long"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|ptr
argument_list|,
operator|*
name|argv
operator|++
argument_list|)
expr_stmt|;
name|ptr
operator|+=
name|tlen
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|ptr
operator|-
literal|1
operator|)
operator|!=
name|filchar
condition|)
operator|*
name|ptr
operator|++
operator|=
name|filchar
expr_stmt|;
name|len
operator|-=
name|tlen
operator|+
literal|1
expr_stmt|;
operator|*
name|ptr
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
comment|/* 	 * ALL of the command line has now been processed. (!) 	 */
if|if
condition|(
operator|*
name|filename
condition|)
block|{
name|infp
operator|=
name|freopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
if|if
condition|(
name|infp
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"freopen(%s): %s"
argument_list|,
name|filename
argument_list|,
name|errmsg
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|infp
operator|=
name|stdin
expr_stmt|;
name|tty
operator|=
name|isatty
argument_list|(
name|fileno
argument_list|(
name|infp
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|CREATENG
condition|)
name|createng
argument_list|()
expr_stmt|;
if|if
condition|(
name|header
operator|.
name|ctlmsg
index|[
literal|0
index|]
operator|!=
literal|'\0'
operator|&&
name|header
operator|.
name|title
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|header
operator|.
name|title
argument_list|,
name|header
operator|.
name|ctlmsg
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|header
operator|.
name|nbuf
condition|)
block|{
name|lcase
argument_list|(
name|header
operator|.
name|nbuf
argument_list|)
expr_stmt|;
name|ptr
operator|=
name|index
argument_list|(
name|header
operator|.
name|nbuf
argument_list|,
literal|'\0'
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
index|[
operator|-
literal|1
index|]
operator|==
name|NGDELIM
condition|)
operator|*
operator|--
name|ptr
operator|=
literal|'\0'
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|nstrip
argument_list|(
name|header
operator|.
name|title
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|nstrip
argument_list|(
name|header
operator|.
name|expdate
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|nstrip
argument_list|(
name|header
operator|.
name|followid
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|!=
name|PROC
condition|)
block|{
if|if
condition|(
name|hflag
condition|)
block|{
name|header
operator|.
name|path
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
operator|(
name|void
operator|)
name|hread
argument_list|(
operator|&
name|header
argument_list|,
name|infp
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
comment|/* there are certain fields we won't let him specify. */
if|if
condition|(
name|header
operator|.
name|from
index|[
literal|0
index|]
condition|)
block|{
operator|(
name|void
operator|)
name|fixfrom
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
if|if
condition|(
name|Sflag
operator|&&
operator|!
name|Mflag
operator|&&
operator|!
name|header
operator|.
name|approved
index|[
literal|0
index|]
operator|&
operator|!
name|header
operator|.
name|sender
index|[
literal|0
index|]
condition|)
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|strcpy
argument_list|(
name|bfr
argument_list|,
name|header
operator|.
name|from
argument_list|)
expr_stmt|;
name|p
operator|=
name|strpbrk
argument_list|(
name|bfr
argument_list|,
literal|"@ !"
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
condition|)
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|bfr
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|uid
operator|=
name|pw
operator|->
name|pw_uid
expr_stmt|;
name|gid
operator|=
name|pw
operator|->
name|pw_gid
expr_stmt|;
name|username
operator|=
name|AllocCpy
argument_list|(
name|bfr
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|forgedname
argument_list|,
name|header
operator|.
name|from
argument_list|)
expr_stmt|;
name|header
operator|.
name|from
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|header
operator|.
name|approved
index|[
literal|0
index|]
condition|)
name|Mflag
operator|=
name|FALSE
expr_stmt|;
name|header
operator|.
name|sender
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|header
operator|.
name|subdate
index|[
literal|0
index|]
operator|&&
name|cgtdate
argument_list|(
name|header
operator|.
name|subdate
argument_list|)
operator|<
literal|0
condition|)
name|header
operator|.
name|subdate
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
name|header
operator|.
name|ident
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|getident
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
if|if
condition|(
name|forgedname
index|[
literal|0
index|]
condition|)
block|{
specifier|register
name|char
modifier|*
name|p1
decl_stmt|;
if|if
condition|(
name|Mflag
condition|)
name|sprintf
argument_list|(
name|header
operator|.
name|path
argument_list|,
literal|"%s!%s"
argument_list|,
name|PATHSYSNAME
argument_list|,
name|username
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|header
operator|.
name|path
index|[
literal|0
index|]
condition|)
block|{
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|header
operator|.
name|path
argument_list|,
name|forgedname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p1
operator|=
name|strpbrk
argument_list|(
name|header
operator|.
name|path
argument_list|,
literal|" (<"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
operator|*
name|p1
operator|=
literal|'\0'
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|Mflag
operator|&&
operator|!
name|strpbrk
argument_list|(
name|forgedname
argument_list|,
literal|"@ (<"
argument_list|)
condition|)
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|header
operator|.
name|from
argument_list|,
literal|"%s@%s"
argument_list|,
name|forgedname
argument_list|,
name|FROMSYSNAME
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|header
operator|.
name|from
argument_list|,
name|forgedname
argument_list|,
name|BUFLEN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|header
operator|.
name|sender
argument_list|,
literal|"%s@%s"
argument_list|,
name|username
argument_list|,
name|FROMSYSNAME
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|gensender
argument_list|(
operator|&
name|header
argument_list|,
name|username
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|MYORG
if|if
condition|(
name|header
operator|.
name|organization
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|&&
operator|!
name|Mflag
operator|&&
name|header
operator|.
name|sender
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|strncpy
argument_list|(
name|header
operator|.
name|organization
argument_list|,
name|MYORG
argument_list|,
name|BUFLEN
argument_list|)
expr_stmt|;
if|if
condition|(
name|STRNCMP
argument_list|(
name|header
operator|.
name|organization
argument_list|,
literal|"Frobozz"
argument_list|,
literal|7
argument_list|)
operator|==
literal|0
condition|)
name|header
operator|.
name|organization
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|ptr
operator|=
name|getenv
argument_list|(
literal|"ORGANIZATION"
argument_list|)
condition|)
name|strncpy
argument_list|(
name|header
operator|.
name|organization
argument_list|,
name|ptr
argument_list|,
name|BUFLEN
argument_list|)
expr_stmt|;
comment|/* 			 * Note that the organization can also be turned off by 			 * setting it to the null string, either in MYORG or 			 * $ORGANIZATION in the environment. 			 */
if|if
condition|(
name|header
operator|.
name|organization
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
block|{
name|mfd
operator|=
name|fopen
argument_list|(
name|header
operator|.
name|organization
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfd
condition|)
block|{
operator|(
name|void
operator|)
name|fgets
argument_list|(
name|header
operator|.
name|organization
argument_list|,
sizeof|sizeof
name|header
operator|.
name|organization
argument_list|,
name|mfd
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|mfd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|logerr
argument_list|(
literal|"Couldn't open %s"
argument_list|,
name|header
operator|.
name|organization
argument_list|)
expr_stmt|;
name|header
operator|.
name|organization
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
name|ptr
operator|=
name|index
argument_list|(
name|header
operator|.
name|organization
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
condition|)
operator|*
name|ptr
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|/* MYORG */
block|}
comment|/* Authorize newsgroups. */
if|if
condition|(
name|mode
operator|==
name|PROC
condition|)
block|{
name|checkbatch
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|header
operator|.
name|ident
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|hread
argument_list|(
operator|&
name|header
argument_list|,
name|infp
argument_list|,
name|TRUE
argument_list|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"%s: Inbound news is garbled"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|input
argument_list|(
name|bfr
index|[
literal|0
index|]
operator|!=
literal|'\n'
argument_list|)
expr_stmt|;
block|}
comment|/* always check history */
if|if
condition|(
name|history
argument_list|(
operator|&
name|header
argument_list|)
condition|)
block|{
name|log
argument_list|(
literal|"Duplicate article %s rejected. Path: %s"
argument_list|,
name|header
operator|.
name|ident
argument_list|,
name|header
operator|.
name|path
argument_list|)
expr_stmt|;
name|xxit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/* Easy way to make control messages, since all.all.ctl is unblessed */
if|if
condition|(
name|mode
operator|!=
name|PROC
operator|&&
name|PREFIX
argument_list|(
name|header
operator|.
name|title
argument_list|,
literal|"cmsg "
argument_list|)
operator|&&
name|header
operator|.
name|ctlmsg
index|[
literal|0
index|]
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|header
operator|.
name|ctlmsg
argument_list|,
operator|&
name|header
operator|.
name|title
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
name|is_ctl
operator|=
name|mode
operator|!=
name|CREATENG
operator|&&
operator|(
name|ngmatch
argument_list|(
name|header
operator|.
name|nbuf
argument_list|,
literal|"all.all.ctl,"
argument_list|)
operator|||
name|header
operator|.
name|ctlmsg
index|[
literal|0
index|]
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"is_ctl set to %d\n"
argument_list|,
name|is_ctl
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|mode
operator|!=
name|CREATENG
condition|)
block|{
if|if
condition|(
operator|!
operator|*
name|header
operator|.
name|title
condition|)
name|error
argument_list|(
literal|"No title, ng %s from %s"
argument_list|,
name|header
operator|.
name|nbuf
argument_list|,
name|header
operator|.
name|from
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|header
operator|.
name|nbuf
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|header
operator|.
name|nbuf
argument_list|,
name|DFLTNG
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|<=
name|UNPROC
condition|)
block|{
ifdef|#
directive|ifdef
name|FASCIST
if|if
condition|(
name|uid
operator|&&
name|uid
operator|!=
name|ROOTID
operator|&&
name|fascist
argument_list|(
name|username
argument_list|,
name|header
operator|.
name|nbuf
argument_list|)
condition|)
name|xerror
argument_list|(
literal|"User %s is not authorized to post to newsgroup %s"
argument_list|,
name|username
argument_list|,
name|header
operator|.
name|nbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* FASCIST */
name|ctlcheck
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|mode
operator|==
name|CREATENG
condition|)
name|createng
argument_list|()
expr_stmt|;
comment|/* Determine input. */
if|if
condition|(
name|mode
operator|!=
name|PROC
condition|)
name|input
argument_list|(
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
name|header
operator|.
name|intnumlines
operator|==
literal|0
operator|&&
operator|!
name|is_ctl
condition|)
name|error
argument_list|(
literal|"%s rejected: no text lines"
argument_list|,
name|header
operator|.
name|ident
argument_list|)
expr_stmt|;
name|dates
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
comment|/* Do the actual insertion. */
name|insert
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
block|}
comment|/* check for existence of file */
specifier|static
name|chkfile
argument_list|(
argument|f
argument_list|)
name|char
operator|*
name|f
expr_stmt|;
block|{
name|FILE
modifier|*
name|mfd
decl_stmt|;
comment|/* mail file file-descriptor		*/
name|char
name|cbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* command buffer			*/
if|if
condition|(
name|rwaccess
argument_list|(
name|f
argument_list|)
condition|)
return|return;
comment|/* everything is ok */
name|mfd
operator|=
name|mailhdr
argument_list|(
operator|(
expr|struct
name|hbuf
operator|*
operator|)
name|NULL
argument_list|,
name|exists
argument_list|(
name|f
argument_list|)
condition|?
literal|"Unwritable files!"
else|:
literal|"Missing files!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfd
operator|==
name|NULL
condition|)
return|return;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|mfd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s\n\nThere was a problem with %s!!\n"
argument_list|,
name|LOCALSYSNAME
argument_list|,
name|f
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|cbuf
argument_list|,
literal|"touch %s;chmod 666 %s"
argument_list|,
name|f
argument_list|,
name|f
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|system
argument_list|(
name|cbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|rwaccess
argument_list|(
name|f
argument_list|)
condition|)
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"The problem has been taken care of.\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"Corrective action failed - check suid bits.\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|mclose
argument_list|(
name|mfd
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|DBM
comment|/* check for existence of directory */
specifier|static
name|chkdir
argument_list|(
argument|d
argument_list|)
name|char
operator|*
name|d
expr_stmt|;
block|{
name|FILE
modifier|*
name|mfd
decl_stmt|;
comment|/* mail file file-descriptor		*/
name|char
name|dir
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* holds directory name			*/
name|sprintf
argument_list|(
name|dir
argument_list|,
literal|"%s.d"
argument_list|,
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|eaccess
argument_list|(
name|dir
argument_list|,
literal|07
argument_list|)
operator|==
literal|0
condition|)
return|return;
comment|/* everything is ok */
name|mfd
operator|=
name|mailhdr
argument_list|(
operator|(
expr|struct
name|hbuf
operator|*
operator|)
name|NULL
argument_list|,
name|exists
argument_list|(
name|dir
argument_list|)
condition|?
literal|"Unwritable directories"
else|:
literal|"Missing directories"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfd
operator|==
name|NULL
condition|)
return|return;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|mfd
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s\n\nThere was a problem with %s!\n"
argument_list|,
name|LOCALSYSNAME
argument_list|,
name|dir
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|mkdir
argument_list|(
name|dir
argument_list|,
literal|0775
argument_list|)
expr_stmt|;
if|if
condition|(
name|eaccess
argument_list|(
name|dir
argument_list|,
literal|07
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"The problem has been taken care of.\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"Corrective action failed - check suid bits.\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|mclose
argument_list|(
name|mfd
argument_list|)
expr_stmt|;
block|}
comment|/*  * This version of access checks against effective uid and effective gid  */
name|eaccess
argument_list|(
name|name
argument_list|,
name|mode
argument_list|)
specifier|register
name|char
operator|*
name|name
expr_stmt|;
specifier|register
name|int
name|mode
decl_stmt|;
block|{
name|struct
name|stat
name|statb
decl_stmt|;
name|int
name|euserid
init|=
name|geteuid
argument_list|()
decl_stmt|;
name|int
name|egroupid
init|=
name|getegid
argument_list|()
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|statb
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|euserid
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|statb
operator|.
name|st_mode
operator|&
name|S_IFMT
operator|)
operator|!=
name|S_IFREG
operator|||
name|mode
operator|!=
literal|1
condition|)
return|return
literal|0
return|;
comment|/* root needs execute permission for someone */
name|mode
operator|=
operator|(
name|S_IEXEC
operator||
operator|(
name|S_IEXEC
operator|>>
literal|3
operator|)
operator||
operator|(
name|S_IEXEC
operator|>>
literal|6
operator|)
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|euserid
operator|==
name|statb
operator|.
name|st_uid
condition|)
name|mode
operator|<<=
literal|6
expr_stmt|;
elseif|else
if|if
condition|(
name|egroupid
operator|==
name|statb
operator|.
name|st_gid
condition|)
name|mode
operator|<<=
literal|3
expr_stmt|;
ifdef|#
directive|ifdef
name|BSD4_2
comment|/* in BSD4_2 you can be in several groups */
else|else
block|{
name|int
name|groups
index|[
name|NGROUPS
index|]
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
name|n
operator|=
name|getgroups
argument_list|(
name|NGROUPS
argument_list|,
name|groups
argument_list|)
expr_stmt|;
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|groups
index|[
name|n
index|]
operator|==
name|statb
operator|.
name|st_gid
condition|)
block|{
name|mode
operator|<<=
literal|3
expr_stmt|;
break|break;
block|}
block|}
block|}
endif|#
directive|endif
comment|/* BSD4_2 */
if|if
condition|(
name|statb
operator|.
name|st_mode
operator|&
name|mode
condition|)
return|return
literal|0
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
comment|/* DBM */
name|dospool
argument_list|(
argument|batchcmd
argument_list|,
argument|dolhwrite
argument_list|)
name|char
modifier|*
name|batchcmd
decl_stmt|;
name|int
name|dolhwrite
decl_stmt|;
block|{
specifier|register
name|int
name|c
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|sp
decl_stmt|;
specifier|register
name|struct
name|tm
modifier|*
name|tp
decl_stmt|;
name|time_t
name|t
decl_stmt|;
name|char
name|buf
index|[
name|BUFLEN
index|]
decl_stmt|,
name|sfile
index|[
name|BUFLEN
index|]
decl_stmt|;
specifier|extern
name|struct
name|tm
modifier|*
name|gmtime
parameter_list|()
function_decl|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|sfile
argument_list|,
literal|"%s/.spXXXXXX"
argument_list|,
name|SPOOL
argument_list|)
expr_stmt|;
name|sp
operator|=
name|xfopen
argument_list|(
name|mktemp
argument_list|(
name|sfile
argument_list|)
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|batchcmd
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|not_here
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|sp
argument_list|,
literal|"%s -x %s\n"
argument_list|,
name|batchcmd
argument_list|,
name|not_here
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|sp
argument_list|,
literal|"%s\n"
argument_list|,
name|batchcmd
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|not_here
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|sp
argument_list|,
literal|"#! inews -x %s -p\n"
argument_list|,
name|not_here
argument_list|)
expr_stmt|;
if|if
condition|(
name|dolhwrite
condition|)
name|lhwrite
argument_list|(
operator|&
name|header
argument_list|,
name|sp
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|infp
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
name|putc
argument_list|(
name|c
argument_list|,
name|sp
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|sp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|tp
operator|=
name|gmtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
comment|/* This file name "has to" be unique  (right?) */
ifdef|#
directive|ifdef
name|USG
operator|(
name|void
operator|)
name|sprintf
argument_list|(
argument|buf
argument_list|,
literal|"%s/.rnews/%2.2d%2.2d%2.2d%2.2d%2.2d%x"
argument_list|,
else|#
directive|else
ifdef|#
directive|ifdef
name|VMS
comment|/* Eunice doesn't like dots in directory names */
argument|(void) sprintf(buf,
literal|"%s/+rnews/%02d%02d%02d%02d%02d%x"
argument|,
else|#
directive|else
comment|/* V7 */
argument|(void) sprintf(buf,
literal|"%s/.rnews/%02d%02d%02d%02d%02d%x"
argument|,
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* VMS */
argument|SPOOL, 		tp->tm_year, tp->tm_mon+
literal|1
argument|, tp->tm_mday, 		tp->tm_hour, tp->tm_min, getpid());
ifdef|#
directive|ifdef
name|IHCC
argument|log(
literal|"Spooling %s into %s"
argument|, header.ident, (rindex(buf,
literal|'/'
argument|) +
literal|1
argument|));
endif|#
directive|endif
comment|/* IHCC */
argument|if (LINK(sfile, buf)<
literal|0
argument|) { 		char dbuf[BUFLEN];
ifdef|#
directive|ifdef
name|VMS
argument|sprintf(dbuf,
literal|"%s/+rnews"
argument|, SPOOL);
else|#
directive|else
comment|/* !VMS */
argument|sprintf(dbuf,
literal|"%s/.rnews"
argument|, SPOOL);
endif|#
directive|endif
comment|/* !VMS */
argument|if (mkdir(dbuf,
literal|0777
argument|&~N_UMASK)<
literal|0
argument|) 			xerror(
literal|"Cannot mkdir %s: %s"
argument|, dbuf, errmsg(errno)); 		if (LINK(sfile, buf)<
literal|0
argument|)  			xerror(
literal|"Cannot link(%s,%s): %s"
argument|, sfile, buf, 				errmsg(errno)); 	} 	(void) UNLINK(sfile); 	xxit(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}
comment|/*  *	Create a newsgroup  */
argument|createng() { 	register char *cp;
comment|/* 	 * Only certain users are allowed to create newsgroups 	 */
argument|if (uid != ROOTID&& uid != duid&& uid) { 		logerr(
literal|"Please contact one of the local netnews people"
argument|); 		xerror(
literal|"to create group \"%s\" for you"
argument|, header.ctlmsg); 	} 	if (header.distribution[
literal|0
argument|] ==
literal|'\0'
argument|)
ifdef|#
directive|ifdef
name|ORGDISTRIB
argument|strcpy(header.distribution, ORGDISTRIB);
else|#
directive|else
comment|/* !ORGDISTRIB */
argument|strcpy(header.distribution,
literal|"local"
argument|);
endif|#
directive|endif
comment|/* !ORGDISTRIB */
argument|(void) strcpy(header.nbuf, header.ctlmsg); 	if ((cp=index(header.nbuf,
literal|' '
argument|)) != NULL) 		*cp =
literal|'\0'
argument|;  	if (header.approved[
literal|0
argument|] ==
literal|'\0'
argument|) 		(void) sprintf(header.approved,
literal|"%s@%s"
argument|, 				username, FROMSYSNAME); 	(void) sprintf(bfr,
literal|"%s/inews -n %s.ctl -c newgroup %s -d %s -a \"%s\""
argument|, 		LIB, header.nbuf, header.ctlmsg, header.distribution, 		header.approved); 	if (tty) { 		printf(
literal|"Please type in a paragraph describing the new newsgroup.\n"
argument|); 		printf(
literal|"End with control D as usual.\n"
argument|); 	} 	printf(
literal|"%s\n"
argument|, bfr); 	(void) fflush(stdout); 	(void) system(bfr); 	exit(
literal|0
argument|);
comment|/*NOTREACHED*/
argument|}  char firstbufname[BUFLEN];
comment|/*  *	Link ARTICLE into dir for ngname and update active file.  */
argument|long localize(ngname) char	*ngname; { 	char afline[BUFLEN]; 	long ngsize; 	long fpos; 	int e; 	char *cp;  	lock(); 	(void) rewind(actfp); clearerr(actfp);  	for(;;) { 		fpos = ftell(actfp); 		if (fgets(afline, sizeof afline, actfp) == NULL) { 			unlock(); 			logerr(
literal|"Can't find \"%s\" in active file"
argument|, ngname); 			return FALSE;
comment|/* No such newsgroup locally */
argument|} 		if (PREFIX(afline, ngname)) { 			(void) sscanf(afline,
literal|"%s %ld"
argument|, bfr,&ngsize); 			if (STRCMP(bfr, ngname) ==
literal|0
argument|) { 				if (ngsize<
literal|0
argument||| ngsize>
literal|99998
argument|) { 					logerr(
literal|"found bad ngsize %ld ng %s, setting to 1"
argument|, ngsize, bfr); 					ngsize =
literal|1
argument|; 				} 				break; 			} 		} 	} 	for (;;) { 		cp = dirname(ngname);  		(void) sprintf(bfr,
literal|"%s/%ld"
argument|, cp, ngsize+
literal|1
argument|);
ifdef|#
directive|ifdef
name|VMS
comment|/* 		 * The effect of this code is to store the article in the first 		 * newsgroup's directory and to put symbolic links elsewhere. 		 * If this is the first group, firstbufname is not yet filled 		 * in. It should be portable to other link-less systems. 		 * epimass!jbuck 		 */
argument|if (firstbufname[
literal|0
argument|]) { 			if (vmslink(firstbufname, bfr) ==
literal|0
argument|) 				break; 		} else if (rename(ARTICLE, bfr) ==
literal|0
argument|) 			break;
else|#
directive|else
comment|/* !VMS */
argument|if (link(ARTICLE, bfr) ==
literal|0
argument|) 			break;
endif|#
directive|endif
comment|/* !VMS */
argument|if (!exists(cp)) 			mknewsg(cp, ngname);
ifdef|#
directive|ifdef
name|VMS
argument|if (firstbufname[
literal|0
argument|]) { 			if (vmslink(firstbufname, bfr) ==
literal|0
argument|) 				break; 		} else if (rename(ARTICLE, bfr) ==
literal|0
argument|)  			break;
else|#
directive|else
comment|/* !VMS */
argument|if (link(ARTICLE, bfr) ==
literal|0
argument|) 			break;
endif|#
directive|endif
comment|/* !VMS */
argument|e = errno;
comment|/* keep log from clobbering it */
argument|log(
literal|"Cannot install article as %s: %s"
argument|, bfr, errmsg(errno)); 		if (e != EEXIST) { 			logerr(
literal|"Link into %s failed (%s); check dir permissions."
argument|, 			    bfr, errmsg(e)); 			unlock(); 			return FALSE; 		} 		ngsize++; 	}
comment|/* 	 * This works around a bug in the 4.1bsd stdio 	 * on fseeks to non even offsets in r+w files 	 */
argument|if (fpos&
literal|1
argument|) 		(void) rewind(actfp);  	(void) fseek(actfp, fpos,
literal|0
argument|);
comment|/* 	 * Has to be same size as old because of %05d. 	 * This will overflow with 99999 articles. 	 */
argument|fprintf(actfp,
literal|"%s %05ld"
argument|, ngname, ngsize+
literal|1
argument|);
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|MG1
argument_list|)
comment|/* 	 * U G L Y   K L U D G E 	 * This utter piece of tripe is the only way I know of to get 	 * around the fact that ATT BROKE standard IO in System 5.2. 	 * Basically, you can't open a file for "r+" and then try and 	 * write to it. This works on all "real" USGUnix systems, It will 	 * probably break on some obscure look alike that doesnt use the 	 * real ATT stdio.h 	 * Don't blame me, blame ATT. stdio should have already done the 	 * following line for us, but it doesn't 	 * also broken in WCW MG-1 42nix 2.0 	 */
argument|actfp->_flag |= _IOWRT;
endif|#
directive|endif
comment|/* USG */
argument|(void) fflush(actfp); 	if (ferror(actfp)) 		xerror(
literal|"Active file write failed"
argument|); 	unlock(); 	if (firstbufname[
literal|0
argument|] ==
literal|'\0'
argument|) 		(void) strcpy(firstbufname, bfr); 	(void) sprintf(bfr,
literal|"%s/%ld "
argument|, ngname, ngsize+
literal|1
argument|); 	addhist(bfr); 	return ngsize+
literal|1
argument|; }
comment|/*  *	Localize for each newsgroup and broadcast.  */
argument|insert() { 	register char *ptr; 	register FILE *tfp; 	register int c; 	struct srec srec;
comment|/* struct for sys file lookup	*/
argument|struct tm *tm, *gmtime(); 	int is_invalid = FALSE; 	int exitcode =
literal|0
argument|; 	long now;
ifdef|#
directive|ifdef
name|DOXREFS
argument|register char *nextref = header.xref;
endif|#
directive|endif
comment|/* DOXREFS */
comment|/* Clean up Newsgroups: line */
argument|if (!is_ctl&& mode != CREATENG) 		is_invalid = ngfcheck(mode == PROC);  	(void) time(&now); 	tm = gmtime(&now); 	if (header.expdate[
literal|0
argument|]) 		addhist(
literal|" "
argument|);
ifdef|#
directive|ifdef
name|USG
argument|sprintf(bfr,
literal|"%2.2d/%2.2d/%d %2.2d:%2.2d\t"
argument|,
else|#
directive|else
comment|/* !USG */
argument|sprintf(bfr,
literal|"%02d/%02d/%d %02d:%02d\t"
argument|,
endif|#
directive|endif
comment|/* !USG */
argument|tm->tm_mon+
literal|1
argument|, tm->tm_mday, tm->tm_year,tm->tm_hour, tm->tm_min); 	addhist(bfr); 	log(
literal|"%s %s ng %s subj '%s' from %s"
argument|, spool_news != DONT_SPOOL 		?
literal|"queued"
argument|: (mode==PROC ?
literal|"received"
argument|:
literal|"posted"
argument|), 		header.ident, header.nbuf, header.title, header.from);
comment|/* Write article to temp file. */
argument|tfp = xfopen(mktemp(ARTICLE),
literal|"w"
argument|);  	if (is_invalid) { 		logerr(
literal|"No valid newsgroups found, moved to junk"
argument|); 		if (localize(
literal|"junk"
argument|)) 			savehist(histline); 		exitcode =
literal|1
argument|; 		goto writeout; 	}
ifdef|#
directive|ifdef
name|ZAPNOTES
argument|if (STRNCMP(header.title,
literal|"Re: Orphaned Response"
argument|,
literal|21
argument|) ==
literal|0
argument|) { 		logerr(
literal|"Orphaned Response, moved to junk"
argument|); 		if (localize(
literal|"junk"
argument|)) 			savehist(histline); 		exitcode =
literal|1
argument|; 		goto writeout; 	}
endif|#
directive|endif
comment|/* ZAPNOTES */
argument|if (time((time_t *)
literal|0
argument|)> (cgtdate(header.subdate) + HISTEXP) ){ 		logerr(
literal|"Article too old, moved to junk"
argument|); 		if (localize(
literal|"junk"
argument|)) 			savehist(histline); 		exitcode =
literal|1
argument|; 		goto writeout; 	}  	if (is_mod[
literal|0
argument|] !=
literal|'\0'
comment|/* one of the groups is moderated */
argument|&& header.approved[
literal|0
argument|] ==
literal|'\0'
argument|) {
comment|/* and unapproved */
argument|struct hbuf mhdr; 		FILE *mfd, *mhopen(); 		register char *p; 		char modadd[BUFLEN], *replyname();
ifdef|#
directive|ifdef
name|DONTFOWARD
argument|if(mode == PROC) { 			logerr(
literal|"Unapproved article in moderated group %s"
argument|, 				is_mod); 			if (localize(
literal|"junk"
argument|)) 				savehist(histline); 			goto writeout; 		}
endif|#
directive|endif
comment|/* DONTFORWARD */
argument|fprintf(stderr,
literal|"%s is moderated and may not be posted to"
argument|, 			is_mod); 		fprintf(stderr,
literal|" directly.\nYour article is being mailed to"
argument|); 		fprintf(stderr,
literal|" the moderator who will post it for you.\n"
argument|);
comment|/* Let's find a path to the backbone */
argument|sprintf(bfr,
literal|"%s/mailpaths"
argument|, LIB); 		mfd = xfopen(bfr,
literal|"r"
argument|); 		do { 			if (fscanf(mfd,
literal|"%s %s"
argument|, bfr, modadd) !=
literal|2
argument|) 				xerror(
literal|"Can't find backbone in %s/mailpaths"
argument|, 					LIB); 		} while (STRCMP(bfr,
literal|"backbone"
argument|) !=
literal|0
argument|&& !ngmatch(is_mod, bfr)); 		(void) fclose(mfd);
comment|/* fake a header for mailhdr */
argument|mhdr.from[
literal|0
argument|] =
literal|'\0'
argument|; 		mhdr.replyto[
literal|0
argument|] =
literal|'\0'
argument|; 		p = is_mod; 		while (*++p) 			if (*p ==
literal|'.'
argument|) 				*p =
literal|'-'
argument|; 		sprintf(mhdr.path, modadd, is_mod); 		mfd = mhopen(&mhdr); 		if (mfd == NULL) 			xerror(
literal|"Can't send mail to %s"
argument|, mhdr.path); 		fprintf(mfd,
literal|"To: %s\n"
argument|, replyname(&mhdr)); 		lhwrite(&header, mfd); 		putc(
literal|'\n'
argument|, mfd); 		while ((c = getc(infp)) != EOF) 			putc(c, mfd); 		mclose(mfd); 		log(
literal|"Article mailed to %s"
argument|, mhdr.path); 		xxit(
literal|0
argument|); 	}  	if (mode != PROC&& spool_news != DONT_SPOOL)  { 		if (spool_news != EXPIRE_RUNNING&& ngmatch(header.nbuf,
literal|"to.all.ctl"
argument|)) 				spool_news = DONT_SPOOL; 		if (spool_news != DONT_SPOOL) { 			fprintf(stderr,
literal|"Your article has been spooled for later processing.\n"
argument|); 			dospool(
literal|"#! inews -S -h"
argument|, TRUE);
comment|/* NOT REACHED */
argument|} 	}  	if (is_ctl) { 		exitcode = control(&header); 		if (localize(
literal|"control"
argument|)&& exitcode !=
literal|0
argument|) 			savehist(histline); 	} else { 		if (s_find(&srec, LOCALPATHSYSNAME) == FALSE) { 			logerr(
literal|"Cannot find my name '%s' in %s"
argument|, 				LOCALPATHSYSNAME, SUBFILE); 			srec = dummy_srec; 		}
ifdef|#
directive|ifdef
name|DOXREFS
argument|(void) strncpy(nextref, PATHSYSNAME, BUFLEN);
endif|#
directive|endif
comment|/* DOXREFS */
argument|for (ptr = nbuf; *ptr;) { 			if (ngmatch(ptr,srec.s_nbuf) || index(ptr,
literal|'.'
argument|) == NULL){
ifdef|#
directive|ifdef
name|DOXREFS
argument|while (*nextref++) 					; 				(void) sprintf(--nextref,
literal|" %s:%ld"
argument|, ptr, localize(ptr));
else|#
directive|else
comment|/* !DOXREFS */
argument|(void) localize(ptr);
endif|#
directive|endif
comment|/* !DOXREFS */
argument|} 			while (*ptr++) 				; 		} 		if (firstbufname[
literal|0
argument|] ==
literal|'\0'
argument|) { 			logerr(
literal|"Newsgroups in active, but not sys"
argument|); 			(void) localize(
literal|"junk"
argument|); 		} 	}
ifdef|#
directive|ifdef
name|DOXREFS
argument|if (index(header.nbuf, NGDELIM) == NULL) 		header.xref[
literal|0
argument|] =
literal|'\0'
argument|;
endif|#
directive|endif
comment|/* DOXREFS */
argument|writeout:
comment|/* Part 1 of kludge to get around article truncation problem */
argument|if ( (c=getc(infp)) != EOF) { 		ungetc(c, infp); 		if (c ==
literal|' '
argument||| c ==
literal|'\t'
argument|) { 			header.intnumlines++; 			(void) sprintf(header.numlines,
literal|"%d"
argument|, 				header.intnumlines); 		} 	}
comment|/* End of part 1 */
argument|if (header.expdate[
literal|0
argument|] !=
literal|'\0'
argument|&& mode != PROC) {
comment|/* Make sure it's fully qualified */
argument|long t = cgtdate(header.expdate); 		strcpy(header.expdate, arpadate(&t)); 	}  	lhwrite(&header, tfp); 	if ((c = getc(infp)) != EOF) {
comment|/* Part 2 of kludge to get around article truncation problem */
argument|if (c ==
literal|' '
argument||| c ==
literal|'\t'
argument|) 			putc(
literal|'\n'
argument|, tfp);
comment|/* End of part 2 */
argument|ungetc(c, infp); 		while (fgets(bfr, BUFLEN, infp) != NULL) 			fputs(bfr, tfp); 		if (bfr[strlen(bfr)-
literal|1
argument|] !=
literal|'\n'
argument|) 			putc(
literal|'\n'
argument|,tfp); 	} 	if (ferror(tfp)) 		xerror(
literal|"Write failed for temp file"
argument|); 	(void) fclose(tfp); 	(void) fclose(infp); 	if(exitcode ==
literal|0
argument|) {
comment|/* article has passed all the checks, so work in background */
argument|if (mode != PROC) { 			int pid; 			if ((pid=fork())<
literal|0
argument|) 				xerror(
literal|"Can't fork"
argument|); 			else if (pid>
literal|0
argument|) 				_exit(
literal|0
argument|); 		}
ifdef|#
directive|ifdef
name|SIGTTOU
argument|(void) signal(SIGTTOU, SIG_IGN);
endif|#
directive|endif
comment|/* SIGTTOU */
argument|savehist(histline); 		if (header.supersedes[
literal|0
argument|] !=
literal|'\0'
argument|) { 			char *av[
literal|2
argument|];  			av[
literal|0
argument|] =
literal|"cancel"
argument|; 			av[
literal|1
argument|] = header.supersedes; 			c_cancel(
literal|2
argument|, av); 		} 		broadcast(mode==PROC); 	} 	xxit((mode == PROC&& filename[
literal|0
argument|] ==
literal|'\0'
argument|) ?
literal|0
argument|: 		(exitcode<
literal|0
argument|?
literal|0
argument|: exitcode)); }  input(usegunk) { 	register char *cp; 	register int c; 	register int empty = TRUE; 	FILE *tmpfp; 	int consec_newlines =
literal|0
argument|; 	int linecount =
literal|0
argument|; 	int linserted =
literal|0
argument|;  	tmpfp = xfopen(mktemp(INFILE),
literal|"w"
argument|); 	for ( ; ; ) { 		if (SigTrap) 			break; 		if (usegunk) 			usegunk = FALSE; 		else if (fgets(bfr, BUFLEN, infp) != bfr) 			break;  		if (mode == PROC) {
comment|/* zap trailing empty lines */
ifdef|#
directive|ifdef
name|ZAPNOTES
argument|if (empty&& bfr[
literal|0
argument|] ==
literal|'#'
argument|&& bfr[
literal|2
argument|] ==
literal|':'
argument|&& header.nf_id[
literal|0
argument|] ==
literal|'\0'
argument|&& header.nf_from[
literal|0
argument|] ==
literal|'\0'
argument|) { 				(void) strcpy(header.nf_id, bfr); 				(void) nstrip(header.nf_id); 				(void) fgets(bfr, BUFLEN, infp); 				(void) strcpy(header.nf_from, bfr); 				(void) nstrip(header.nf_from); 				(void) fgets(bfr, BUFLEN, infp);  				if (header.numlines[
literal|0
argument|]) { 					header.intnumlines -=
literal|2
argument|; 					(void) sprintf(header.numlines,
literal|"%d"
argument|, header.intnumlines); 				}
comment|/* Strip trailing " - (nf)" */
argument|if ((cp = rindex(header.title,
literal|'-'
argument|)) != NULL&& !strcmp(--cp,
literal|" - (nf)"
argument|)) 					*cp =
literal|'\0'
argument|; 				log(
literal|"Stripped notes header on %s"
argument|, header.ident); 				continue; 			}
endif|#
directive|endif
comment|/* ZAPNOTES */
argument|if (bfr[
literal|0
argument|] ==
literal|'\n'
argument|||
comment|/* Bandage for older versions of inews */
argument|bfr[
literal|1
argument|] ==
literal|'\n'
argument|&& !isascii(bfr[
literal|0
argument|])) {  				consec_newlines++;
comment|/* count it, in case */
argument|continue;
comment|/* but don't write it*/
argument|}
comment|/* foo! a non-empty line. write out all saved lines. */
argument|while (consec_newlines>
literal|0
argument|) { 				putc(
literal|'\n'
argument|, tmpfp); 				consec_newlines--; 				linecount++; 			}  		} 		if (mode != PROC&& tty&& STRCMP(bfr,
literal|".\n"
argument|) ==
literal|0
argument|) 			break; 		for (cp = bfr; c = toascii(*cp); cp++) { 			if (isprint(c) || isspace(c) || c ==
literal|'\b'
argument|) 				putc(c, tmpfp); 			if (c ==
literal|'\n'
argument|) 				linecount++; 		} 		if (bfr[
literal|0
argument|] ==
literal|'>'
argument|) 			linserted++; 		if (bfr[
literal|0
argument|] ==
literal|'<'
argument|)
comment|/* kludge to allow diff's to be posted */
argument|linserted--; 		empty = FALSE; 	} 	if (*filename) 		(void) fclose(infp); 	if (mode != PROC&& 		linecount> LNCNT&& linserted> (linecount-linserted)) 		error(
literal|"Article rejected: %s included more text than new text"
argument|, 			username);  	if (mode != PROC&& !is_ctl&& header.sender[
literal|0
argument|] ==
literal|'\0'
argument|&& !Sflag) { 		int siglines =
literal|0
argument|; 		char sbuf[BUFLEN]; 		(void) sprintf(bfr,
literal|"%s/%s"
argument|, userhome,
literal|".signature"
argument|); 		if (access(bfr,
literal|4
argument|) ==
literal|0
argument|) { 			if ((infp = fopen(bfr,
literal|"r"
argument|)) == NULL) { 				(void) fprintf(stderr,
literal|"inews: \"%s\" left off (must be readable by \"inews\" owner)\n"
argument|, bfr); 				goto finish; 			}  			while (fgets(sbuf, sizeof sbuf, infp) != NULL) 				if (++siglines>
literal|4
argument|) 					break; 			if (siglines>
literal|4
argument|) 				fprintf(stderr,
literal|".signature not included (> 4 lines)\n"
argument|); 			else { 				rewind(infp); 				fprintf(tmpfp,
literal|"-- \n"
argument|);
comment|/* To separate */
argument|linecount++; 				while ((c = getc(infp)) != EOF) { 					putc(c, tmpfp); 					if (c ==
literal|'\n'
argument|) 						linecount++; 				} 			} 			(void) fclose(infp); 		} 	}  finish: 	if (ferror(tmpfp)) 		xerror(
literal|"write failed to temp file"
argument|); 	(void) fclose(tmpfp); 	if (SigTrap) { 		if (tty) 			fprintf(stderr,
literal|"Interrupt\n"
argument|); 		if (tty&& !empty) 			fwait(fsubr(newssave, (char *) NULL, (char *) NULL)); 		if (!tty) 			log(
literal|"Blown away by an interrupt %d"
argument|, SigTrap); 		xxit(
literal|1
argument|); 	} 	if (tty) 		fprintf(stderr,
literal|"EOT\n"
argument|); 	fflush(stdout); 	infp = fopen(INFILE,
literal|"r"
argument|); 	if (header.numlines[
literal|0
argument|]) {
comment|/* 		 * Check line count if there's already one attached to 		 * the article.  Could make this a fatal error - 		 * throwing it away if it got chopped, in hopes that 		 * another copy will come in later with a correct 		 * line count.  But that seems a bit much for now. 		 */
argument|if (linecount != header.intnumlines) { 			if (linecount ==
literal|0
argument|) 				error(
literal|"%s rejected. linecount expected %d, got 0"
argument|, header.ident, header.intnumlines); 			if (linecount> header.intnumlines || 			    linecount+consec_newlines< header.intnumlines) 				log(
literal|"linecount expected %d, got %d"
argument|, header.intnumlines, linecount+consec_newlines); 		}
comment|/* adjust count for blank lines we stripped off */
argument|if (consec_newlines) { 			header.intnumlines -= consec_newlines; 			if (header.intnumlines<
literal|0
argument|) 				header.intnumlines =
literal|0
argument|;
comment|/* paranoia */
argument|(void) sprintf(header.numlines,
literal|"%d"
argument|, header.intnumlines); 		}  	} else {
comment|/* Attach a line count to the article. */
argument|header.intnumlines = linecount; 		(void) sprintf(header.numlines,
literal|"%d"
argument|, linecount); 	} }
comment|/*  * Make the directory for a new newsgroup.  ngname should be the  * full pathname of the directory.  Do the other stuff too.  * The various games with setuid and chown are to try to make sure  * the directory is owned by NEWSUSR and NEWSGRP, which is tough to  * do if you aren't root.  This will work on a UCB system (which allows  * setuid(geteuid()) or a USG system (which allows you to give away files  * you own with chown), otherwise you have to change your kernel to allow  * one of these things or run with your dirs 777 so that it doesn't matter  * who owns them.  */
argument|mknewsg(fulldir, ngname) char	*fulldir; char	*ngname; {
ifdef|#
directive|ifdef
name|USG
argument|register char *p; 	char parent[
literal|200
argument|]; 	char sysbuf[
literal|200
argument|]; 	struct stat sbuf;
endif|#
directive|endif
comment|/* USG */
argument|if (ngname == NULL || !isalpha(ngname[
literal|0
argument|])) 		xerror(
literal|"Tried to make illegal newsgroup %s"
argument|, ngname);
ifdef|#
directive|ifdef
name|USG
comment|/* 	 * If the parent is 755 the setuid(getuid) 	 * will fail, and since mkdir is suid, and our real uid is random, 	 * the mkdir will fail.  So we have to temporarily chmod it to 777. 	 */
argument|(void) strcpy(parent, fulldir); 	while (p = rindex(parent,
literal|'/'
argument|)) { 		*p =
literal|'\0'
argument|; 		if (stat(parent,&sbuf) ==
literal|0
argument|) { 			(void) chmod(parent,
literal|0777
argument|); 			break; 		} 	}
endif|#
directive|endif
comment|/* USG */
comment|/* Create the directory */
argument|mkparents(fulldir); 	if (mkdir(fulldir,
literal|0777
argument|)<
literal|0
argument|) 		xerror(
literal|"Cannot mkdir %s: %s"
argument|, fulldir, errmsg(errno));
ifdef|#
directive|ifdef
name|USG
comment|/* 	 * Give away the directories we just created which were assigned 	 * our real uid. 	 */
argument|(void) setuid(uid); 	(void) chown(fulldir, duid, dgid);  	(void) strcpy(sysbuf, fulldir); 	while (p = rindex(sysbuf,
literal|'/'
argument|)) { 		*p =
literal|'\0'
argument|;
comment|/* stop when get to last known good parent */
argument|if (strcmp(sysbuf, parent) ==
literal|0
argument|) 			break; 		(void) chown(sysbuf, duid, dgid); 	} 	(void) setuid(duid); 	(void) chmod(parent, (int)sbuf.st_mode);
comment|/* put it back */
endif|#
directive|endif
comment|/* USG */
argument|log(
literal|"make newsgroup %s in dir %s"
argument|, ngname, fulldir); }
comment|/*  * If any parent directories of this dir don't exist, create them.  */
argument|mkparents(dname) char *dname; { 	char buf[
literal|200
argument|]; 	register char *p;  	(void) strcpy(buf, dname); 	p = rindex(buf,
literal|'/'
argument|); 	if (p) 		*p =
literal|'\0'
argument|; 	if (exists(buf)) 		return; 	mkparents(buf); 	if (mkdir(buf,
literal|0777
argument|)<
literal|0
argument|) 		xerror(
literal|"Can not mkdir %s: %s"
argument|, buf, errmsg(errno)); }  dounspool() { 	register DIR	*dirp; 	register struct direct *dir; 	register int foundsome; 	int pid, status, ret; 	char spbuf[BUFLEN];
ifdef|#
directive|ifdef
name|LOCKF
argument|FILE* LockFd;
endif|#
directive|endif
comment|/* LOCKF */
ifdef|#
directive|ifdef
name|VMS
argument|sprintf(spbuf,
literal|"%s/+rnews"
argument|, SPOOL);
else|#
directive|else
comment|/* !VMS */
argument|sprintf(spbuf,
literal|"%s/.rnews"
argument|, SPOOL);
endif|#
directive|endif
comment|/* !VMS */
argument|if (chdir(spbuf)<
literal|0
argument|) 		xerror(
literal|"chdir(%s):%s"
argument|, spbuf, errmsg(errno));  	dirp = opendir(
literal|"."
argument|); 	if (dirp == NULL)
comment|/* Boy are things screwed up */
argument|xerror(
literal|"opendir can't open .:%s"
argument|, errmsg(errno));
ifdef|#
directive|ifdef
name|LOCKF
argument|LockFd = xfopen(SEQFILE,
literal|"r+w"
argument|); 	if (lockf(fileno(LockFd), F_TLOCK,
literal|0L
argument|)<
literal|0
argument|) { 		if (errno != EAGAIN&& errno != EACCES)
else|#
directive|else
comment|/* !LOCKF */
ifdef|#
directive|ifdef
name|BSD4_2
argument|if (flock(dirp->dd_fd, LOCK_EX|LOCK_NB)<
literal|0
argument|) { 		if (errno != EWOULDBLOCK)
else|#
directive|else
comment|/* V7 */
argument|strcat(spbuf,
literal|".lock"
argument|); 	sprintf(bfr,
literal|"%s.tmp"
argument|, spbuf); 	(void) close(creat(bfr,
literal|0666
argument|)); 	ret = LINK(bfr, spbuf); 	status = errno; 	(void) UNLINK(bfr); 	errno = status; 	if (ret<
literal|0
argument|) { 		if (errno != EEXIST)
endif|#
directive|endif
comment|/* V7 */
endif|#
directive|endif
comment|/* !LOCKF */
argument|xerror(
literal|"Can't lock %s: %s"
argument|, spbuf, errmsg(errno)); 		xxit(
literal|3
argument|);
comment|/* another rnews -U is running */
argument|}  	do { 		foundsome =
literal|0
argument|;  		while ((dir=readdir(dirp)) != NULL) { 			if (dir->d_name[
literal|0
argument|] ==
literal|'.'
argument|) 				continue;
ifdef|#
directive|ifdef
name|IHCC
argument|log(
literal|"Unspooling from %s"
argument|, dir->d_name);
endif|#
directive|endif
comment|/* IHCC */
argument|if ((pid=vfork()) == -
literal|1
argument|) 				xerror(
literal|"Can't fork: %s"
argument|, errmsg(errno)); 			if (pid ==
literal|0
argument|) {
ifdef|#
directive|ifdef
name|LOGDIR
argument|char bufr[BUFSIZ]; 				sprintf(bufr,
literal|"%s/%s"
argument|, logdir(HOME), RNEWS); 				execl(bufr,
literal|"rnews"
argument|,
literal|"-S"
argument|,
literal|"-p"
argument|, dir->d_name, 					(char *) NULL);
else|#
directive|else
comment|/* !LOGDIR */
argument|execl(RNEWS,
literal|"rnews"
argument|,
literal|"-S"
argument|,
literal|"-p"
argument|, dir->d_name, 					(char *) NULL);
endif|#
directive|endif
comment|/* !LOGDIR */
argument|_exit(
literal|1
argument|); 			} 			 			while ((ret=wait(&status)) != pid&& ret != -
literal|1
argument|)
comment|/* continue */
argument|;  			if (((status>>
literal|8
argument|)&
literal|0177
argument|) ==
literal|42
argument|) {
comment|/* expire has started up, shutdown rnews -U */
argument|break; 			}  			if (status !=
literal|0
argument|) { 				sprintf(bfr,
literal|"../%s"
argument|, dir->d_name); 				(void) LINK(dir->d_name, bfr); 				logerr(
literal|"rnews failed, status %ld. Batch saved in %s/%s"
argument|, 					(long)status, SPOOL, dir->d_name); 			} 			(void) unlink(dir->d_name); 			foundsome++; 		} 		rewinddir(dirp); 	} while (foundsome);
comment|/* keep rereading the directory until it's empty */
ifndef|#
directive|ifndef
name|LOCKF
ifndef|#
directive|ifndef
name|BSD4_2
argument|(void) UNLINK(spbuf);
endif|#
directive|endif
endif|#
directive|endif
argument|xxit(
literal|0
argument|); }
end_function

end_unit

