begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  MONITOR.H -- globals for the interactive terminal monitor ** **	Version: **		@(#)monitor.h	7.1	2/5/81 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_comment
comment|/* various global names and strings */
end_comment

begin_decl_stmt
name|char
name|Qbname
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of query buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Fileset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unique string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Pathname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pathname of INGRES root */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
name|char
name|Nodayfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suppress dayfile/prompts */
end_comment

begin_comment
comment|/* 0 - print dayfile and prompts 				** 1 - suppress dayfile but not prompts 				** -1 - supress dayfile and prompts 				*/
end_comment

begin_decl_stmt
name|char
name|Userdflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same: user flag */
end_comment

begin_comment
comment|/*  the Nodayfile flag gets reset by include(); 				**  this is the flag that the user actually 				**  specified (and what s/he gets when in 				**  interactive mode.			*/
end_comment

begin_decl_stmt
name|char
name|Autoclear
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clear query buffer automatically if set */
end_comment

begin_decl_stmt
name|char
name|Notnull
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if the query is not null */
end_comment

begin_decl_stmt
name|char
name|Prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if a prompt is needed */
end_comment

begin_decl_stmt
name|char
name|Nautoclear
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, disables the autoclear option */
end_comment

begin_decl_stmt
name|char
name|Phase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if in processing phase */
end_comment

begin_comment
comment|/* query buffer stuff */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Qryiop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the query buffer */
end_comment

begin_decl_stmt
name|char
name|Newline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if last character was a newline */
end_comment

begin_comment
comment|/* other stuff */
end_comment

begin_decl_stmt
name|int
name|Xwaitpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid to wait on - zero means none */
end_comment

begin_decl_stmt
name|int
name|Error_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the error number of the last err */
end_comment

begin_comment
comment|/* \include support stuff */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file */
end_comment

begin_decl_stmt
name|int
name|Idepth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* include depth */
end_comment

begin_decl_stmt
name|char
name|Oneline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deliver EOF after one line input */
end_comment

begin_decl_stmt
name|bool
name|GiveEof
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if set, return EOF on next getch */
end_comment

begin_comment
comment|/* commands to monitor */
end_comment

begin_define
define|#
directive|define
name|C_APPEND
value|1
end_define

begin_define
define|#
directive|define
name|C_BRANCH
value|2
end_define

begin_define
define|#
directive|define
name|C_CHDIR
value|3
end_define

begin_define
define|#
directive|define
name|C_EDIT
value|4
end_define

begin_define
define|#
directive|define
name|C_GO
value|5
end_define

begin_define
define|#
directive|define
name|C_INCLUDE
value|6
end_define

begin_define
define|#
directive|define
name|C_MARK
value|7
end_define

begin_define
define|#
directive|define
name|C_LIST
value|8
end_define

begin_define
define|#
directive|define
name|C_PRINT
value|9
end_define

begin_define
define|#
directive|define
name|C_QUIT
value|10
end_define

begin_define
define|#
directive|define
name|C_RESET
value|11
end_define

begin_define
define|#
directive|define
name|C_TIME
value|12
end_define

begin_define
define|#
directive|define
name|C_EVAL
value|13
end_define

begin_define
define|#
directive|define
name|C_WRITE
value|14
end_define

begin_define
define|#
directive|define
name|C_SHELL
value|15
end_define

begin_define
define|#
directive|define
name|C_SYSTRACE
value|16
end_define

begin_define
define|#
directive|define
name|C_SYSRESET
value|17
end_define

begin_comment
comment|/* stuff for querytrap facility */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Trapfile
decl_stmt|;
end_decl_stmt

end_unit

