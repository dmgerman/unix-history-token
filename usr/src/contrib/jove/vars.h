begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_struct
struct|struct
name|variable
block|{
name|int
name|Type
decl_stmt|;
comment|/* in this case a variable */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* name is always second */
name|char
modifier|*
name|v_value
decl_stmt|;
name|int
name|v_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* variable types/flags */
end_comment

begin_define
define|#
directive|define
name|V_BASE10
value|01
end_define

begin_comment
comment|/* is integer in base 10 */
end_comment

begin_define
define|#
directive|define
name|V_BASE8
value|02
end_define

begin_comment
comment|/* is integer in base 8 */
end_comment

begin_define
define|#
directive|define
name|V_BOOL
value|04
end_define

begin_comment
comment|/* is a boolean */
end_comment

begin_define
define|#
directive|define
name|V_STRING
value|010
end_define

begin_comment
comment|/* is a string */
end_comment

begin_define
define|#
directive|define
name|V_CHAR
value|020
end_define

begin_comment
comment|/* is a character */
end_comment

begin_define
define|#
directive|define
name|V_FILENAME
value|040
end_define

begin_comment
comment|/* a file name (implies V_STRING) */
end_comment

begin_define
define|#
directive|define
name|V_TYPEMASK
value|077
end_define

begin_comment
comment|/* mask off the extra bits */
end_comment

begin_define
define|#
directive|define
name|V_MODELINE
value|0100
end_define

begin_comment
comment|/* update modeline */
end_comment

begin_define
define|#
directive|define
name|V_CLRSCREEN
value|0200
end_define

begin_comment
comment|/* clear and redraw screen */
end_comment

begin_define
define|#
directive|define
name|V_TTY_RESET
value|0400
end_define

begin_comment
comment|/* redo the tty modes */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|variable
name|variables
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TXT_TO_C
end_ifdef

begin_decl_stmt
name|int
comment|/* kludge, so setmaps will compile with variables */
else|#
directive|else
specifier|extern
name|int
endif|#
directive|endif
comment|/* TXT_TO_C */
else|#
directive|else
specifier|extern
name|int
endif|#
directive|endif
comment|/* MAC */
name|OKXonXoff
decl_stmt|,
comment|/* disable start/stop characters */
name|MetaKey
decl_stmt|,
comment|/* this terminal has a meta key */
name|VisBell
decl_stmt|,
comment|/* use visible bell (if possible) */
name|WrapScan
decl_stmt|,
comment|/* make searches wrap */
ifndef|#
directive|ifndef
name|MAC
name|phystab
decl_stmt|,
comment|/* terminal's tabstop settings */
endif|#
directive|endif
name|tabstop
decl_stmt|,
comment|/* expand tabs to this number of spaces */
ifdef|#
directive|ifdef
name|BACKUPFILES
name|BkupOnWrite
decl_stmt|,
comment|/* make backup files when writing */
endif|#
directive|endif
name|RMargin
decl_stmt|,
comment|/* right margin */
name|LMargin
decl_stmt|,
comment|/* left margin */
name|ScrollStep
decl_stmt|,
comment|/* how should we scroll */
ifndef|#
directive|ifndef
name|MAC
name|WtOnMk
decl_stmt|,
comment|/* write files on compile-it command */
endif|#
directive|endif
name|EndWNewline
decl_stmt|,
comment|/* end files with a blank line */
name|MarkThresh
decl_stmt|,
comment|/* moves greater than MarkThresh will SetMark */
name|PDelay
decl_stmt|,
comment|/* paren flash delay in tenths of a second */
name|CArgIndent
decl_stmt|,
comment|/* how to indent arguments to C functions */
name|CIndIncrmt
decl_stmt|,
comment|/* how much each indentation level pushes 				   over in C mode */
name|CreatMode
decl_stmt|,
comment|/* default mode for creat'ing files */
name|CaseIgnore
decl_stmt|,
comment|/* case ignore search */
ifdef|#
directive|ifdef
name|ABBREV
name|AutoCaseAbbrev
decl_stmt|,
comment|/* automatically do case on abbreviations */
endif|#
directive|endif
name|MarksShouldFloat
decl_stmt|,
comment|/* adjust marks on insertion/deletion */
name|UseRE
decl_stmt|,
comment|/* use regular expressions in search */
name|SyncFreq
decl_stmt|,
comment|/* how often to sync the file pointers */
name|BriteMode
decl_stmt|,
comment|/* make the mode line inverse? */
name|OkayBadChars
decl_stmt|,
comment|/* allow bad characters in files created 				   by JOVE */
name|UpdFreq
decl_stmt|,
comment|/* how often to update modeline */
name|UseBuffers
decl_stmt|,
comment|/* use buffers with Typeout() */
ifdef|#
directive|ifdef
name|BIFF
name|BiffChk
decl_stmt|,
comment|/* turn off/on biff with entering/exiting jove */
endif|#
directive|endif
name|MailInt
decl_stmt|,
comment|/* mail check interval */
ifdef|#
directive|ifdef
name|ID_CHAR
name|UseIC
decl_stmt|,
comment|/* whether or not to use i/d char 				   processesing */
endif|#
directive|endif
name|SExitChar
decl_stmt|,
comment|/* type this to stop i-search */
name|AbortChar
decl_stmt|,
comment|/* cancels command input */
name|IntChar
decl_stmt|,
comment|/* ttysets this to generate QUIT */
name|DoEVexpand
decl_stmt|,
comment|/* treat $foo as environment variable */
ifdef|#
directive|ifdef
name|F_COMPLETION
name|DispBadFs
decl_stmt|,
comment|/* display filenames with bad extensions? */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IBMPC
name|Fgcolor
decl_stmt|,
name|Bgcolor
decl_stmt|,
name|Mdcolor
decl_stmt|,
endif|#
directive|endif
comment|/* IBMPC */
name|ScrollAll
decl_stmt|,
comment|/* we current line scrolls, scroll whole window? */
ifndef|#
directive|ifndef
name|MAC
name|EWSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size to make the error window */
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Macmode
operator|,
comment|/* see mac.c */
name|Keyonly
operator|,
name|Bufchange
operator|,
name|Modechange
operator|,
name|Windchange
operator|,
name|EventCmd
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TXT_TO_C
end_ifdef

begin_comment
comment|/* kludge, for setmaps with variables */
end_comment

begin_decl_stmt
name|char
else|#
directive|else
specifier|extern
name|char
endif|#
directive|endif
comment|/* TXT_TO_C */
else|#
directive|else
specifier|extern
name|char
endif|#
directive|endif
comment|/* MAC */
ifndef|#
directive|ifndef
name|MAC
name|ErrFmtStr
index|[
literal|256
index|]
decl_stmt|,
comment|/* format string for parse errors */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|IPROCS
name|proc_prompt
index|[
literal|128
index|]
decl_stmt|,
comment|/* process prompt */
name|dbx_parse_fmt
index|[
literal|128
index|]
decl_stmt|,
comment|/* dbx-mode parse string */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|F_COMPLETION
name|BadExtensions
index|[
literal|128
index|]
decl_stmt|,
comment|/* extensions (e.g., ".o" to ignore) */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CMT_FMT
name|CmtFmt
index|[
literal|80
index|]
decl_stmt|,
endif|#
directive|endif
name|ModeFmt
index|[
literal|120
index|]
decl_stmt|,
comment|/* mode line format string */
ifdef|#
directive|ifdef
name|UNIX
name|Mailbox
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* mailbox name */
endif|#
directive|endif
comment|/* UNIX */
name|TmpFilePath
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* directory/device to store tmp files */
name|TagFile
index|[
name|FILESIZE
index|]
decl_stmt|,
comment|/* default tag file */
name|Shell
index|[
name|FILESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shell to use */
end_comment

end_unit

