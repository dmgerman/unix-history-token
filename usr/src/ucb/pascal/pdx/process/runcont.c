begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)runcont.c	5.2 (Berkeley) 4/7/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Execution management.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"machine.h"
end_include

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"process.rep"
end_include

begin_define
define|#
directive|define
name|MAXNARGS
value|100
end_define

begin_comment
comment|/* maximum number of arguments to RUN */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|String
typedef|;
end_typedef

begin_decl_stmt
name|LOCAL
name|BOOLEAN
name|just_started
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|String
name|argv
index|[
name|MAXNARGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|String
name|infile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|String
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|PROCESS
name|pbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PROCESS
modifier|*
name|process
init|=
operator|&
name|pbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is a px-related kludge to deal with the possibility  * of object code magically coming from a tmp file.  */
end_comment

begin_decl_stmt
name|LOCAL
name|String
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LOCAL
name|String
name|realname
decl_stmt|;
end_decl_stmt

begin_macro
name|setargs
argument_list|(
argument|m
argument_list|,
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|m
decl_stmt|,
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|mode
operator|=
name|m
expr_stmt|;
name|realname
operator|=
name|r
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Initialize the argument list.  */
end_comment

begin_macro
name|arginit
argument_list|()
end_macro

begin_block
block|{
name|infile
operator|=
name|NIL
expr_stmt|;
name|outfile
operator|=
name|NIL
expr_stmt|;
name|argv
index|[
literal|0
index|]
operator|=
name|mode
expr_stmt|;
name|argv
index|[
literal|1
index|]
operator|=
name|objname
expr_stmt|;
if|if
condition|(
name|option
argument_list|(
literal|'t'
argument_list|)
operator|&&
name|realname
operator|==
name|NIL
condition|)
block|{
name|argc
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|argv
index|[
literal|2
index|]
operator|=
name|realname
expr_stmt|;
name|argc
operator|=
literal|3
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Add an argument to the list for the debuggee.  */
end_comment

begin_macro
name|newarg
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|String
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|argc
operator|>=
name|MAXNARGS
condition|)
block|{
name|error
argument_list|(
literal|"too many arguments to run"
argument_list|)
expr_stmt|;
block|}
name|argv
index|[
name|argc
operator|++
index|]
operator|=
name|arg
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Set the standard input for the debuggee.  */
end_comment

begin_macro
name|inarg
argument_list|(
argument|filename
argument_list|)
end_macro

begin_decl_stmt
name|String
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|infile
operator|!=
name|NIL
condition|)
block|{
name|error
argument_list|(
literal|"multiple input redirects"
argument_list|)
expr_stmt|;
block|}
name|infile
operator|=
name|filename
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Set the standard output for the debuggee.  * Probably should check to avoid overwriting an existing file.  */
end_comment

begin_macro
name|outarg
argument_list|(
argument|filename
argument_list|)
end_macro

begin_decl_stmt
name|String
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|outfile
operator|!=
name|NIL
condition|)
block|{
name|error
argument_list|(
literal|"multiple output redirect"
argument_list|)
expr_stmt|;
block|}
name|outfile
operator|=
name|filename
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Initial start of the process.  The idea is to get it to the point  * where the object code has been loaded but execution has not begun.  */
end_comment

begin_macro
name|initstart
argument_list|()
end_macro

begin_block
block|{
name|arginit
argument_list|()
expr_stmt|;
name|argv
index|[
name|argc
index|]
operator|=
name|NIL
expr_stmt|;
name|initcache
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|start
argument_list|(
name|argv
argument_list|,
name|infile
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|process
operator|->
name|status
operator|!=
name|STOPPED
condition|)
block|{
name|panic
argument_list|(
literal|"could not start program"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Run starts debuggee executing.  */
end_comment

begin_macro
name|run
argument_list|()
end_macro

begin_block
block|{
name|fixbps
argument_list|()
expr_stmt|;
name|curline
operator|=
literal|0
expr_stmt|;
name|argv
index|[
name|argc
index|]
operator|=
name|NIL
expr_stmt|;
name|start
argument_list|(
name|argv
argument_list|,
name|infile
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|process
operator|->
name|status
operator|==
name|STOPPED
condition|)
block|{
name|just_started
operator|=
name|TRUE
expr_stmt|;
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|cont
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|option
argument_list|(
literal|'r'
argument_list|)
condition|)
block|{
name|panic
argument_list|(
literal|"could not start program"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Continue execution wherever we left off.  *  * Note that this routine never returns.  Eventually bpact() will fail  * and we'll call printstatus or step will call it.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|INTFUNC
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|LOCAL
name|INTFUNC
modifier|*
name|dbintr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LOCAL
name|intr
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fails
value|== FALSE
end_define

begin_macro
name|cont
argument_list|()
end_macro

begin_block
block|{
name|dbintr
operator|=
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intr
argument_list|)
expr_stmt|;
if|if
condition|(
name|just_started
condition|)
block|{
name|just_started
operator|=
name|FALSE
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|isstopped
condition|)
block|{
name|error
argument_list|(
literal|"can't continue execution"
argument_list|)
expr_stmt|;
block|}
name|isstopped
operator|=
name|FALSE
expr_stmt|;
name|step
argument_list|()
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|single_stepping
condition|)
block|{
name|printnews
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|setallbps
argument_list|()
expr_stmt|;
name|resume
argument_list|()
expr_stmt|;
name|unsetallbps
argument_list|()
expr_stmt|;
if|if
condition|(
name|bpact
argument_list|()
name|fails
condition|)
block|{
name|printstatus
argument_list|()
expr_stmt|;
block|}
block|}
name|step
argument_list|()
expr_stmt|;
block|}
comment|/* NOTREACHED */
block|}
end_block

begin_comment
comment|/*  * This routine is called if we get an interrupt while "running" px  * but actually in the debugger.  Could happen, for example, while  * processing breakpoints.  *  * We basically just want to keep going; the assumption is  * that when the process resumes it will get the interrupt  * which will then be handled.  */
end_comment

begin_function
name|LOCAL
name|intr
parameter_list|()
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intr
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|fixintr
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|dbintr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

