begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)int.c 4.1 10/10/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * px - interpreter for Berkeley Pascal  * Version 2.0 Winter 1979  *  * Original version for the PDP 11/70 authored by:  * Bill Joy, Charles Haley, Ken Thompson  *  * Rewritten for VAX 11/780 by Kirk McKusick  */
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"objfmt.h"
end_include

begin_function
name|main
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|)
name|long
name|ac
decl_stmt|;
name|char
modifier|*
modifier|*
name|av
decl_stmt|;
block|{
extern|extern	 intr(
block|)
function|;
end_function

begin_extern
extern|extern	 memsize(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern	 except(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern	 syserr(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|long
name|createtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pxhdr
name|pxhd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|long
name|bytesread
decl_stmt|,
name|block
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|objprog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|FILE
modifier|*
name|prog
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pipe
value|3
end_define

begin_define
define|#
directive|define
name|pipesize
value|4096
end_define

begin_comment
comment|/*  * Initialize everything  */
end_comment

begin_expr_stmt
name|argc
operator|=
name|ac
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|argv
operator|=
name|av
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stcnt
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|stlim
operator|=
literal|500000
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llimit
operator|=
literal|0x7fffffff
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* set to unlimited */
end_comment

begin_expr_stmt
name|nodump
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_escape
end_escape

begin_comment
comment|/*  * Determine how PX was invoked, and how to process the program   */
end_comment

begin_if
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
operator|==
literal|'o'
condition|)
block|{
name|file
operator|=
operator|&
name|argv
index|[
literal|0
index|]
index|[
literal|2
index|]
expr_stmt|;
name|mode
operator|=
name|PIX
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|argc
operator|<=
literal|1
condition|)
block|{
name|file
operator|=
literal|"obj"
expr_stmt|;
name|mode
operator|=
name|PX
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
name|file
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|mode
operator|=
name|PX
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
operator|==
literal|0
condition|)
block|{
name|file
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|mode
operator|=
name|PIPE
expr_stmt|;
name|argc
operator|-=
literal|1
expr_stmt|;
name|argv
index|[
literal|1
index|]
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|argv
operator|=
operator|&
name|argv
index|[
literal|1
index|]
expr_stmt|;
block|}
else|else
block|{
name|fputs
argument_list|(
literal|"Improper specification of object file to PX\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_escape
end_escape

begin_comment
comment|/*  * Process program header information  */
end_comment

begin_if
if|if
condition|(
name|mode
operator|==
name|PIPE
condition|)
name|read
argument_list|(
name|pipe
argument_list|,
operator|&
name|pxhd
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pxhdr
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|prog
operator|=
name|fopen
argument_list|(
name|file
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|prog
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|fseek
argument_list|(
name|prog
argument_list|,
name|HEADER_BYTES
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|pxhdr
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fread
argument_list|(
operator|&
name|pxhd
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pxhdr
argument_list|)
argument_list|,
literal|1
argument_list|,
name|prog
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|pxhd
operator|.
name|maketime
operator|<
name|createtime
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s is obsolete and must be recompiled\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|pxhd
operator|.
name|magicnum
operator|!=
literal|0403
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s is not a Pascal program\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_escape
end_escape

begin_comment
comment|/*  * Load program into memory  */
end_comment

begin_expr_stmt
name|objprog
operator|=
name|malloc
argument_list|(
name|pxhd
operator|.
name|objsize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|mode
operator|==
name|PIPE
condition|)
block|{
name|bytesread
operator|=
literal|0
expr_stmt|;
do|do
block|{
name|block
operator|=
name|read
argument_list|(
name|pipe
argument_list|,
name|objprog
operator|+
name|bytesread
argument_list|,
name|pipesize
argument_list|)
expr_stmt|;
name|bytesread
operator|+=
name|block
expr_stmt|;
block|}
do|while
condition|(
name|block
condition|)
do|;
block|}
else|else
block|{
name|bytesread
operator|=
name|fread
argument_list|(
name|objprog
argument_list|,
literal|1
argument_list|,
name|pxhd
operator|.
name|objsize
argument_list|,
name|prog
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|prog
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|PIX
condition|)
name|unlink
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|bytesread
operator|!=
name|pxhd
operator|.
name|objsize
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Read error occurred while loading %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|mode
operator|==
name|PIX
condition|)
name|fputs
argument_list|(
literal|"Execution begins...\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/*  * set interpreter to catch expected signals and begin interpretation  */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|syserr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGBUS
argument_list|,
name|syserr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGSYS
argument_list|,
name|syserr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intr
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|memsize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|except
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|profile
end_ifdef

begin_expr_stmt
name|interpret
argument_list|(
name|objprog
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|interpret
argument_list|(
name|objprog
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * reset signals, deallocate memory, and exit normally  */
end_comment

begin_expr_stmt
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pflush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pfree(objprog); */
end_comment

begin_expr_stmt
name|psexit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

