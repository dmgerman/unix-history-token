begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: main.c,v 2.5 85/08/22 16:05:00 timo Exp $"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * B editor -- Main program (init/exit processing), error handling.  */
end_comment

begin_comment
comment|/*  * The B editor is a structured editor for a programming language  * for beginners and non-professional computer users.  * [L.G.L.T. Meertens: Draft Proposal for the B programming language,  * Mathematical Centre, Amsterdam, 1982, ISBN 90 6169 238 2.]  * Note that `B' is only a provisional name for the language.  * The editor uses a subset of the run-time system for the B  * interpreter, so that they may be linked together in a later stage.  * Also the sharing strategy of the B run-time routines makes a very  * elegant and powerful UNDO-mechanism possible.  */
end_comment

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_comment
comment|/* Contains definitions like string, etc. */
end_comment

begin_include
include|#
directive|include
file|"feat.h"
end_include

begin_include
include|#
directive|include
file|"bobj.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SAVEPOS
end_ifdef

begin_define
define|#
directive|define
name|SAVEPOSFILE
value|".Bed_pos"
end_define

begin_comment
comment|/* Last focus position database */
end_comment

begin_define
define|#
directive|define
name|MAXSAVE
value|50
end_define

begin_comment
comment|/* Maximum number of entries kept in SAVEPOSFILE */
end_comment

begin_endif
endif|#
directive|endif
endif|SAVEPOS
end_endif

begin_comment
comment|/* Command line flags */
end_comment

begin_decl_stmt
name|bool
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -d: debugging output wanted */
end_comment

begin_decl_stmt
name|bool
name|slowterminal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -s: the terminal is so slow that long messages are annoying */
end_comment

begin_decl_stmt
name|bool
name|hushbaby
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -h: no bells are to be heard */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENTED_OUT
end_ifdef

begin_comment
comment|/* Lower levels don't respond to this */
end_comment

begin_decl_stmt
name|bool
name|nostandout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -n: inhibit use of standout */
end_comment

begin_endif
endif|#
directive|endif
endif|COMMENTED_OUT
end_endif

begin_comment
comment|/*  * Main program -- call module initializations, do some work,   * call module shut-off code, exit.  */
end_comment

begin_function
name|Visible
name|Procedure
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|string
modifier|*
name|argv
decl_stmt|;
block|{
name|bool
name|initdone
init|=
name|No
decl_stmt|;
name|bool
name|status
init|=
name|Yes
decl_stmt|;
name|int
name|lineno
init|=
literal|0
decl_stmt|;
name|string
name|arg0
init|=
name|argv
index|[
literal|0
index|]
decl_stmt|;
name|string
name|cp
decl_stmt|;
name|string
name|filename
decl_stmt|;
specifier|extern
name|string
name|malloc
parameter_list|()
function_decl|;
name|cp
operator|=
name|rindex
argument_list|(
name|arg0
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|cp
condition|)
name|arg0
operator|=
name|cp
operator|+
literal|1
expr_stmt|;
comment|/* Process UNIX command line options */
for|for
control|(
init|;
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
condition|;
operator|--
name|argc
operator|,
operator|++
name|argv
control|)
block|{
switch|switch
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
condition|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
case|case
literal|'d'
case|:
name|dflag
operator|=
name|Yes
expr_stmt|;
break|break;
endif|#
directive|endif
endif|NDEBUG
case|case
literal|'h'
case|:
name|hushbaby
operator|=
name|Yes
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|COMMENTED_OUT
comment|/* Lower levels don't respond to this */
case|case
literal|'n'
case|:
name|nostandout
operator|=
name|Yes
expr_stmt|;
break|break;
endif|#
directive|endif
endif|COMMENTED_OUT
case|case
literal|'s'
case|:
name|slowterminal
operator|=
name|Yes
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** Usage: %s [-h] [-s] %s\n"
argument_list|,
name|arg0
argument_list|,
ifdef|#
directive|ifdef
name|FILEARGS
literal|"[ [+lineno] file ] ..."
argument_list|)
expr_stmt|;
else|#
directive|else
else|!FILEARGS
literal|""
block|)
empty_stmt|;
endif|#
directive|endif
endif|!FILEARGS
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Setbuf must be called before any output is produced! */
end_comment

begin_expr_stmt
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|BUFSIZ
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FILEARGS
end_ifdef

begin_for
for|for
control|(
init|;
name|status
operator|&&
name|argc
operator|>
literal|1
condition|;
operator|--
name|argc
operator|,
operator|++
name|argv
control|)
block|{
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'+'
condition|)
block|{
comment|/* +lineno option */
name|lineno
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|filename
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|initdone
condition|)
block|{
name|initall
argument_list|()
expr_stmt|;
name|initdone
operator|=
name|Yes
expr_stmt|;
block|}
name|status
operator|=
name|demo
argument_list|(
name|filename
argument_list|,
name|lineno
argument_list|)
expr_stmt|;
name|lineno
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_for

begin_endif
endif|#
directive|endif
endif|FILEARGS
end_endif

begin_if
if|if
condition|(
operator|!
name|initdone
condition|)
block|{
ifdef|#
directive|ifdef
name|BTOP
name|initall
argument_list|()
expr_stmt|;
name|mainloop
argument_list|()
expr_stmt|;
else|#
directive|else
else|BTOP
ifndef|#
directive|ifndef
name|FILEARGS
name|Deliberate
name|error
operator|.
name|You
name|should
name|define
name|at
name|least
name|one
name|of
name|BTOP
name|and
name|FILEARGS
decl_stmt|;
endif|#
directive|endif
endif|!FILEARGS
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** No file edited\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|BTOP
block|}
end_if

begin_expr_stmt
name|endall
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|objstats
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|status
condition|)
name|objcheck
argument_list|()
expr_stmt|;
else|else
name|objdump
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
operator|!
name|status
return|;
end_return

begin_comment
unit|}
comment|/*  * Module initializations -- for each module xxxx that needs dynamic  * initialization, call a routine named initxxxx.  * The order is determined by the inter-module dependencies.  * Also note that all terminal- and screen-related initializations are called  * indirectly by initterm().  */
end_comment

begin_function
unit|Hidden
name|Procedure
name|initall
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|NDEBUG
if|if
condition|(
name|dflag
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** initall();\n\r"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|NDEBUG
name|initfile
argument_list|()
expr_stmt|;
name|initkeys
argument_list|()
expr_stmt|;
name|initgram
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|USERSUGG
name|initsugg
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|USERSUGG
name|initunix
argument_list|()
expr_stmt|;
name|initterm
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Module shut-off code -- for each module xxxx that needs dynamic  * shut-off code (what is the inverse of `initialization'?),  * call a routine named endxxxx.  * Endall is also called (from module "unix") when a signal or interrupt  * causes termination.  */
end_comment

begin_function
name|Visible
name|Procedure
name|endall
parameter_list|()
block|{
if|if
condition|(
name|dflag
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** endall();\n\r"
argument_list|)
expr_stmt|;
name|endterm
argument_list|()
expr_stmt|;
name|enddemo
argument_list|()
expr_stmt|;
name|endunix
argument_list|()
expr_stmt|;
name|enderro
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|USERSUGG
name|endsugg
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|USERSUGG
block|}
end_function

begin_comment
comment|/*  * System error -- abort the editor with a short error message.  * Should only be called for catastrophic, unrecoverable errors  * or those that `cannot happen'.  */
end_comment

begin_comment
comment|/* VARARGS 1 */
end_comment

begin_function
name|Visible
name|Procedure
name|syserr
parameter_list|(
name|fmt
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|,
name|a7
parameter_list|,
name|a8
parameter_list|,
name|a9
parameter_list|,
name|a10
parameter_list|)
name|string
name|fmt
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BTOP
name|termchild
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|BTOP
name|endall
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** System error: "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|,
name|a9
argument_list|,
name|a10
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** Core dump for B guru: "
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
else|#
directive|else
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/*  * Assertion error.  * Call syserr with information about where something was wrong.  * (Sorry, WHAT was wrong must be dug out of the core dump.)  */
end_comment

begin_function
name|Visible
name|Procedure
name|asserr
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|)
name|string
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|{
name|syserr
argument_list|(
literal|"Assertion failed: file %s, line %d"
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

