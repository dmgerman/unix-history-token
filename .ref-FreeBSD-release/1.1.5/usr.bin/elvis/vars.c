begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vars.c */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This file contains variables which weren't happy anyplace else */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_comment
comment|/*------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* used to remember whether the file has been modified */
end_comment

begin_decl_stmt
name|struct
name|_viflags
name|viflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to access the tmp file */
end_comment

begin_decl_stmt
name|long
name|lnum
index|[
name|MAXBLKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|nlines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tmpfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tmpnum
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CRUNCH
end_ifndef

begin_decl_stmt
name|int
name|wset
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* used to keep track of the current file& alternate file */
end_comment

begin_decl_stmt
name|long
name|origtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|origname
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prevorig
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|prevline
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to track various places in the text */
end_comment

begin_decl_stmt
name|MARK
name|mark
index|[
name|NMARKS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* marks 'a through 'z, plus mark '' */
end_comment

begin_decl_stmt
name|MARK
name|cursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the cursor position within the file */
end_comment

begin_comment
comment|/* which mode of the editor we're in */
end_comment

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vi mode? ex mode? quitting? */
end_comment

begin_comment
comment|/* used to manage the args list */
end_comment

begin_decl_stmt
name|char
name|args
index|[
name|BLKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of filenames to edit */
end_comment

begin_decl_stmt
name|int
name|argno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index of current file in args list */
end_comment

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of filenames in args[] */
end_comment

begin_comment
comment|/* dummy var, never explicitly referenced */
end_comment

begin_decl_stmt
name|int
name|bavar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used only in BeforeAfter macros */
end_comment

begin_comment
comment|/* used to detect changes that invalidate cached text/blocks */
end_comment

begin_decl_stmt
name|long
name|changes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* incremented when file is changed */
end_comment

begin_decl_stmt
name|int
name|significant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: was a *REAL* change made? */
end_comment

begin_decl_stmt
name|int
name|exitcode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* status code */
end_comment

begin_comment
comment|/* used to support the pfetch() macro */
end_comment

begin_decl_stmt
name|int
name|plen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of the line */
end_comment

begin_decl_stmt
name|long
name|pline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number that len refers to */
end_comment

begin_decl_stmt
name|long
name|pchgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "changes" level that len refers to */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ptext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text of previous line, if valid */
end_comment

begin_comment
comment|/* misc temporary storage - mostly for strings */
end_comment

begin_decl_stmt
name|BLK
name|tmpblk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a block used to accumulate changes */
end_comment

begin_comment
comment|/* screen oriented stuff */
end_comment

begin_decl_stmt
name|long
name|topline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file line number of top line */
end_comment

begin_decl_stmt
name|int
name|leftcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column number of left col */
end_comment

begin_decl_stmt
name|int
name|physcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical column number that cursor is on */
end_comment

begin_decl_stmt
name|int
name|physrow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical row number that cursor is on */
end_comment

begin_comment
comment|/* used to help minimize that "[Hit a key to continue]" message */
end_comment

begin_decl_stmt
name|int
name|exwrote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean: was the last ex command wordy? */
end_comment

begin_comment
comment|/* This variable affects the behaviour of certain functions -- most importantly  * the input function.  */
end_comment

begin_decl_stmt
name|int
name|doingdot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: are we doing the "." command? */
end_comment

begin_comment
comment|/* This variable affects the behaviour of the ":s" command, and it is also  * used to detect& prohibit nesting of ":g" commands  */
end_comment

begin_decl_stmt
name|int
name|doingglobal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: are doing a ":g" command? */
end_comment

begin_comment
comment|/* This variable is zeroed before a command executes, and later ORed with the  * command's flags after the command has been executed.  It is used to force  * certain flags to be TRUE for *some* invocations of a particular command.  * For example, "/regexp/+offset" forces the LNMD flag, and sometimes a "p"  * or "P" command will force FRNT.  */
end_comment

begin_decl_stmt
name|int
name|force_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are used for reporting multi-line changes to the user */
end_comment

begin_decl_stmt
name|long
name|rptlines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of lines affected by a command */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rptlabel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* description of how lines were affected */
end_comment

begin_comment
comment|/* These store info that pertains to the shift-U command */
end_comment

begin_decl_stmt
name|long
name|U_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line# of the undoable line, or 0l for none */
end_comment

begin_decl_stmt
name|char
name|U_text
index|[
name|BLKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contents of the undoable line */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VISIBLE
end_ifndef

begin_comment
comment|/* These are used to implement the 'v' and 'V' commands */
end_comment

begin_decl_stmt
name|MARK
name|V_from
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* starting point for v or V */
end_comment

begin_decl_stmt
name|int
name|V_linemd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean: doing line-mode version? (V, not v) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bigger stack req'ed for TOS and TURBOC */
end_comment

begin_if
if|#
directive|if
name|TOS
end_if

begin_decl_stmt
name|long
name|_stksize
init|=
literal|16384
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TURBOC
end_if

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|_stklen
init|=
literal|16384U
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

