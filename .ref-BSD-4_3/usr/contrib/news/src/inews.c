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
literal|"@(#)inews.c	2.61	3/19/86"
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

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
name|CANCEL
value|0010
end_define

begin_comment
comment|/* Cancel an article */
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

begin_decl_stmt
specifier|extern
name|char
name|histline
index|[]
decl_stmt|;
end_decl_stmt

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
literal|'\0'
block|,
name|FALSE
block|,
name|UNKNOWN
block|,
name|CANCEL
block|,
name|filename
block|,
literal|'C'
block|,
literal|'\0'
block|,
name|FALSE
block|,
name|UNKNOWN
block|,
name|CREATENG
block|,
name|header
operator|.
name|nbuf
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

begin_function_decl
name|char
modifier|*
name|genversion
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Authors:  *		Matt Glickman	glickman@ucbarpa.Berkeley.ARPA  *		Mark Horton	mark@cbosgd.UUCP  *		Stephen Daniels	swd@mcnc.UUCP  *		Tom Truscott	trt@duke.UUCP  *	IHCC version adapted by:  *		Larry Marek	larry@ihuxf.UUCP  */
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
name|char
name|cbuf
index|[
name|BUFLEN
index|]
decl_stmt|;
comment|/* command buffer			*/
comment|/* uuxqt doesn't close all it's files */
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
name|pathinit
argument_list|()
expr_stmt|;
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
if|if
condition|(
operator|!
name|strncmp
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
ifdef|#
directive|ifdef
name|NICENESS
name|nice
argument_list|(
name|NICENESS
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NICENESS */
block|}
elseif|else
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
goto|goto
name|usage
goto|;
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
if|if
condition|(
operator|!
name|rwaccess
argument_list|(
name|ARTFILE
argument_list|)
condition|)
block|{
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
name|ARTFILE
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
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|HIDDENNET
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s.%s\n\nThere was a problem with %s!!\n"
argument_list|,
name|LOCALSYSNAME
argument_list|,
name|FULLSYSNAME
argument_list|,
name|ARTFILE
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HIDDENNET */
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s\n\nThere was a problem with %s!!\n"
argument_list|,
name|FULLSYSNAME
argument_list|,
name|ARTFILE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HIDDENNET */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|cbuf
argument_list|,
literal|"touch %s;chmod 666 %s"
argument_list|,
name|ARTFILE
argument_list|,
name|ARTFILE
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
name|ARTFILE
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
block|}
if|if
condition|(
operator|!
name|rwaccess
argument_list|(
name|ACTIVE
argument_list|)
condition|)
block|{
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
name|ACTIVE
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
operator|!=
name|NULL
condition|)
block|{
ifdef|#
directive|ifdef
name|HIDDENNET
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s.%s\n\nThere was a problem with %s!!\n"
argument_list|,
name|LOCALSYSNAME
argument_list|,
name|FULLSYSNAME
argument_list|,
name|ARTFILE
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* !HIDDENNET */
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"System: %s\n\nThere was a problem with %s!!\n"
argument_list|,
name|FULLSYSNAME
argument_list|,
name|ACTIVE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HIDDENNET */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|cbuf
argument_list|,
literal|"touch %s;chmod 666 %s"
argument_list|,
name|ACTIVE
argument_list|,
name|ACTIVE
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
name|ACTIVE
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
block|}
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
name|savmask
operator|=
name|umask
argument_list|(
name|N_UMASK
argument_list|)
expr_stmt|;
comment|/* set up mask */
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
name|IHCC
comment|/* 	 * We force the use of 'getuser()' to prevent forgery of articles 	 * by just changing $LOGNAME 	 */
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
name|username
operator|==
name|NULL
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
name|tty
operator|=
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|)
expr_stmt|;
comment|/* This code is really intended to be replaced by the control message. */
if|if
condition|(
name|mode
operator|==
name|CANCEL
condition|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|xfopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|hread
argument_list|(
operator|&
name|header
argument_list|,
name|f
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|p
operator|=
name|index
argument_list|(
name|header
operator|.
name|path
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
operator|*
name|p
operator|=
literal|0
expr_stmt|;
name|p
operator|=
name|header
operator|.
name|path
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|username
argument_list|,
name|p
argument_list|,
name|strlen
argument_list|(
name|username
argument_list|)
argument_list|)
operator|&&
name|uid
operator|!=
name|ROOTID
operator|&&
name|uid
operator|!=
name|geteuid
argument_list|()
operator|&&
name|uid
condition|)
name|xerror
argument_list|(
literal|"Not contributor"
argument_list|)
expr_stmt|;
name|cancel
argument_list|()
expr_stmt|;
name|xxit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
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
name|getident
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
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
name|stdin
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
name|from
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|header
operator|.
name|subdate
index|[
literal|0
index|]
operator|=
literal|'\0'
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
name|strncmp
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
name|header
operator|.
name|organization
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|logerr
argument_list|(
literal|"Couldn't open %s"
argument_list|,
name|header
operator|.
name|organization
argument_list|)
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
name|FULLSYSNAME
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
literal|"@ (<"
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
literal|"%s@%s%s"
argument_list|,
name|forgedname
argument_list|,
name|FULLSYSNAME
argument_list|,
name|MYDOMAIN
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
literal|"%s@%s%s"
argument_list|,
name|username
argument_list|,
name|FULLSYSNAME
argument_list|,
name|MYDOMAIN
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
block|}
comment|/* Authorize newsgroups. */
if|if
condition|(
name|mode
operator|==
name|PROC
condition|)
block|{
ifdef|#
directive|ifdef
name|BATCH
name|checkbatch
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* BATCH */
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
name|stdin
argument_list|,
name|TRUE
argument_list|)
operator|==
name|NULL
condition|)
name|xerror
argument_list|(
literal|"Inbound news is garbled"
argument_list|)
expr_stmt|;
name|input
argument_list|()
expr_stmt|;
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
block|}
comment|/* Easy way to make control messages, since all.all.ctl is unblessed */
if|if
condition|(
name|mode
operator|!=
name|PROC
operator|&&
name|prefix
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
comment|/* Must end in comma (NGDELIM) */
define|#
directive|define
name|MODGROUPS
value|"mod.all,all.mod,all.announce,"
if|if
condition|(
name|ngmatch
argument_list|(
name|header
operator|.
name|nbuf
argument_list|,
name|MODGROUPS
argument_list|)
operator|&&
operator|!
name|header
operator|.
name|approved
index|[
literal|0
index|]
condition|)
block|{
name|mfd
operator|=
name|mailhdr
argument_list|(
operator|&
name|header
argument_list|,
literal|"Moderated newsgroup"
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfd
condition|)
block|{
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"This newsgroup is moderated, and cannot be posted to directly.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|mfd
argument_list|,
literal|"Please mail your article to the moderator for posting.\n"
argument_list|)
expr_stmt|;
name|hwrite
argument_list|(
operator|&
name|header
argument_list|,
name|mfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|infp
condition|)
while|while
condition|(
operator|(
name|i
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
name|i
argument_list|,
name|mfd
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
name|xerror
argument_list|(
literal|"Unapproved moderated newsgroup."
argument_list|)
expr_stmt|;
block|}
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
name|xerror
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
name|user
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
name|user
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
argument_list|()
expr_stmt|;
comment|/* Do the actual insertion. */
name|insert
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	Create a newsgroup  */
end_comment

begin_macro
name|createng
argument_list|()
end_macro

begin_block
block|{
comment|/* 	 * Only certain users are allowed to create newsgroups 	 */
if|if
condition|(
name|uid
operator|!=
name|ROOTID
operator|&&
name|uid
operator|!=
name|geteuid
argument_list|()
operator|&&
name|uid
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Please contact one of the local netnews people\n\tto create this group for you"
argument_list|)
expr_stmt|;
name|xxit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s/inews -n %s.ctl -t cmsg newgroup %s -d local"
argument_list|,
name|LIB
argument_list|,
name|header
operator|.
name|nbuf
argument_list|,
name|header
operator|.
name|nbuf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Please type in a paragraph describing the new newsgroup.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"End with control D as usual.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|system
argument_list|(
name|bfr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_block

begin_decl_stmt
name|char
name|firstbufname
index|[
name|BUFLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Link ARTICLE into dir for ngname and update active file.  */
end_comment

begin_function
name|long
name|localize
parameter_list|(
name|ngname
parameter_list|)
name|char
modifier|*
name|ngname
decl_stmt|;
block|{
name|char
name|afline
index|[
name|BUFLEN
index|]
decl_stmt|;
name|long
name|ngsize
decl_stmt|;
name|long
name|fpos
decl_stmt|;
name|int
name|e
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|lock
argument_list|()
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
for|for
control|(
init|;
condition|;
control|)
block|{
name|fpos
operator|=
name|ftell
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
if|if
condition|(
name|fgets
argument_list|(
name|afline
argument_list|,
sizeof|sizeof
name|afline
argument_list|,
name|actfp
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|unlock
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
name|logerr
argument_list|(
literal|"Can't fine \"%s\" in active file"
argument_list|,
name|ngname
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
comment|/* No such newsgroup locally */
block|}
if|if
condition|(
name|prefix
argument_list|(
name|afline
argument_list|,
name|ngname
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|sscanf
argument_list|(
name|afline
argument_list|,
literal|"%s %ld"
argument_list|,
name|bfr
argument_list|,
operator|&
name|ngsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|bfr
argument_list|,
name|ngname
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|ngsize
operator|<
literal|0
operator|||
name|ngsize
operator|>
literal|99998
condition|)
block|{
name|logerr
argument_list|(
literal|"found bad ngsize %ld ng %s, setting to 1"
argument_list|,
name|ngsize
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
name|ngsize
operator|=
literal|1
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
name|cp
operator|=
name|dirname
argument_list|(
name|ngname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|exists
argument_list|(
name|cp
argument_list|)
condition|)
name|mknewsg
argument_list|(
name|cp
argument_list|,
name|ngname
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s/%ld"
argument_list|,
name|cp
argument_list|,
name|ngsize
operator|+
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
if|if
condition|(
name|vmslink
argument_list|(
name|ARTICLE
argument_list|,
name|bfr
argument_list|)
operator|==
literal|0
condition|)
break|break;
else|#
directive|else
comment|/* !VMS */
if|if
condition|(
name|link
argument_list|(
name|ARTICLE
argument_list|,
name|bfr
argument_list|)
operator|==
literal|0
condition|)
break|break;
endif|#
directive|endif
comment|/* !VMS */
name|e
operator|=
name|errno
expr_stmt|;
comment|/* keep log from clobbering it */
name|log
argument_list|(
literal|"Cannot install article as %s: %s"
argument_list|,
name|bfr
argument_list|,
name|errmsg
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|!=
name|EEXIST
condition|)
block|{
name|logerr
argument_list|(
literal|"Link into %s failed (%s); check dir permissions."
argument_list|,
name|bfr
argument_list|,
name|errmsg
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
name|unlock
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
name|ngsize
operator|++
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
name|vmstounix
argument_list|(
name|ACTIVE
argument_list|)
expr_stmt|;
name|actfp
operator|=
name|fopen
argument_list|(
name|ACTIVE
argument_list|,
literal|"r+"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
comment|/* 	 * This works around a bug in the 4.1bsd stdio 	 * on fseeks to non even offsets in r+w files 	 */
if|if
condition|(
name|fpos
operator|&
literal|1
condition|)
operator|(
name|void
operator|)
name|rewind
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fseek
argument_list|(
name|actfp
argument_list|,
name|fpos
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Has to be same size as old because of %05d. 	 * This will overflow with 99999 articles. 	 */
name|fprintf
argument_list|(
name|actfp
argument_list|,
literal|"%s %05ld"
argument_list|,
name|ngname
argument_list|,
name|ngsize
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|actfp
argument_list|)
condition|)
name|xerror
argument_list|(
literal|"Active file write failed"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|actfp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|unixtovms
argument_list|(
name|ACTIVE
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* VMS */
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|firstbufname
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
name|firstbufname
argument_list|,
name|bfr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|bfr
argument_list|,
literal|"%s/%ld "
argument_list|,
name|ngname
argument_list|,
name|ngsize
operator|+
literal|1
argument_list|)
expr_stmt|;
name|addhist
argument_list|(
name|bfr
argument_list|)
expr_stmt|;
return|return
name|ngsize
operator|+
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  *	Localize for each newsgroup and broadcast.  */
end_comment

begin_macro
name|insert
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|tfp
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|struct
name|srec
name|srec
decl_stmt|;
comment|/* struct for sys file lookup	*/
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|int
name|is_invalid
init|=
name|FALSE
decl_stmt|;
name|int
name|exitcode
init|=
literal|0
decl_stmt|;
name|long
name|now
decl_stmt|;
ifdef|#
directive|ifdef
name|DOXREFS
specifier|register
name|char
modifier|*
name|nextref
init|=
name|header
operator|.
name|xref
decl_stmt|;
endif|#
directive|endif
comment|/* DOXREFS */
comment|/* Fill up the rest of header. */
if|if
condition|(
name|mode
operator|!=
name|PROC
condition|)
block|{
name|history
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
block|}
name|dates
argument_list|(
operator|&
name|header
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
if|if
condition|(
name|header
operator|.
name|expdate
index|[
literal|0
index|]
condition|)
name|addhist
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|sprintf
argument_list|(
argument|bfr
argument_list|,
literal|"%2.2d/%2.2d/%d %2.2d:%2.2d\t"
argument_list|,
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
argument|, 		mode==PROC ?
literal|"received"
argument|:
literal|"posted"
argument|, 		header.ident, header.nbuf, header.title, header.from);
comment|/* Clean up Newsgroups: line */
argument|if (!is_ctl&& mode != CREATENG) 		is_invalid = ngfcheck(mode == PROC);
comment|/* Write article to temp file. */
argument|tfp = xfopen(mktemp(ARTICLE),
literal|"w"
argument|);  	if (is_invalid) { 		logerr(
literal|"No valid newsgroups found, moved to junk"
argument|); 		if (localize(
literal|"junk"
argument|)) 			savehist(histline); 		exitcode =
literal|1
argument|; 		goto writeout; 	}  	if (time((time_t *)
literal|0
argument|)> (cgtdate(header.subdate) + HISTEXP) ){ 		logerr(
literal|"Article too old, moved to junk"
argument|); 		if (localize(
literal|"junk"
argument|)) 			savehist(histline); 		exitcode =
literal|1
argument|; 		goto writeout; 	}  	if (is_ctl) { 		exitcode = control(&header); 		if (localize(
literal|"control"
argument|)&& exitcode !=
literal|0
argument|) 			savehist(histline); 	} else { 		if (s_find(&srec, FULLSYSNAME) == FALSE) { 			logerr(
literal|"Cannot find my name '%s' in %s"
argument|, FULLSYSNAME, SUBFILE); 			srec = dummy_srec; 		}
ifdef|#
directive|ifdef
name|DOXREFS
argument|(void) strncpy(nextref, FULLSYSNAME, BUFLEN);
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
argument|lhwrite(&header, tfp); 	if ((c = getc(infp)) != EOF) {
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
argument|); 	(void) fclose(tfp); 	(void) fclose(infp);  	if(exitcode ==
literal|0
argument|) { 		int pid;
comment|/* article has passed all the checks, so work in background */
argument|if (mode != PROC) 			if ((pid=fork())<
literal|0
argument|) 				xerror(
literal|"Can't fork"
argument|); 			else if (pid>
literal|0
argument|) 				exit(
literal|0
argument|);
ifdef|#
directive|ifdef
name|SIGTTOU
argument|signal(SIGTTOU, SIG_IGN);
endif|#
directive|endif
comment|/* SIGTTOU */
argument|savehist(histline); 		broadcast(); 	} 	xxit(mode == PROC ?
literal|0
argument|: exitcode); }  input() { 	register char *cp; 	register int c; 	register int empty = TRUE; 	FILE *tmpfp; 	int consec_newlines =
literal|0
argument|; 	int linecount =
literal|0
argument|; 	int linserted =
literal|0
argument|;  	tmpfp = xfopen(mktemp(INFILE),
literal|"w"
argument|); 	if (*filename) { 		tty = FALSE; 		infp = xfopen(filename,
literal|"r"
argument|); 	} else { 		infp = stdin; 	} 	while (!SigTrap&& fgets(bfr, BUFLEN, stdin) != NULL) {  		if (mode == PROC) {
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
argument|) { 				(void) strcpy(header.nf_id, bfr); 				(void) nstrip(header.nf_id); 				(void) fgets(bfr, BUFLEN, stdin); 				(void) strcpy(header.nf_from, bfr); 				(void) nstrip(header.nf_from); 				(void) fgets(bfr, BUFLEN, stdin);  				if (header.numlines[
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
argument|, tmpfp); 				consec_newlines--; 				linecount++; 			}  		} 		if (mode != PROC&& tty&& strcmp(bfr,
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
argument|) 			linserted++; 		empty = FALSE; 	} 	if (*filename) 		(void) fclose(infp); 	if (mode != PROC&& linserted> (linecount-linserted)) 		xerror(
literal|"Article rejected: More included text than new text"
argument|);  	if (mode != PROC&& !is_ctl&& header.sender[
literal|0
argument|] ==
literal|'\0'
argument|) { 		int siglines =
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
argument|) 				xerror(
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
argument|(void) chmod(parent, (int)sbuf.st_mode);
comment|/* put it back */
comment|/* 	 * Give away the directories we just created which were assigned 	 * our real uid. 	 */
argument|(void) setuid(uid); 	(void) chown(fulldir, duid, dgid); 	(void) strcpy(sysbuf, fulldir); 	while (p = rindex(sysbuf,
literal|'/'
argument|)) { 		*p =
literal|'\0'
argument|;
comment|/* stop when get to last known good parent */
argument|if (strcmp(sysbuf, parent) ==
literal|0
argument|) 			break; 		(void) chown(sysbuf, duid, dgid); 	} 	(void) setuid(duid);
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
argument|, buf, errmsg(errno)); }  cancel() { 	register FILE *fp;  	log(
literal|"cancel article %s"
argument|, filename); 	fp = fopen(filename,
literal|"r"
argument|); 	if (fp == NULL) { 		log(
literal|"article %s not found"
argument|, filename); 		return; 	} 	if (hread(&header, fp, TRUE) == NULL) 		xerror(
literal|"Article is garbled."
argument|); 	(void) fclose(fp); 	(void) unlink(filename); }
end_block

end_unit

