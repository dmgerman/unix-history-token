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
literal|"@(#)except.c 1.6 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"panics.h"
end_include

begin_include
include|#
directive|include
file|"vars.h"
end_include

begin_comment
comment|/*  * Routine panic is called from the interpreter when a runtime panic occurs.  * Its argument is the internal number of the panic which occurred.  */
end_comment

begin_macro
name|panic
argument_list|(
argument|errnum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|errnum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTRAP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGBUS
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSYS
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|PFLUSH
argument_list|()
expr_stmt|;
name|fputs
argument_list|(
literal|"\n\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|errnum
condition|)
block|{
case|case
name|PINTR
case|:
case|case
name|PLIBERR
case|:
break|break;
case|case
name|PNUMOVFLO
case|:
name|fputs
argument_list|(
literal|"Overflow arithmetic operation\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
case|case
name|PHALT
case|:
if|if
condition|(
name|_nodump
operator|==
name|TRUE
condition|)
name|psexit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"Call to procedure halt\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|backtrace
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
comment|/* pfree(objprog); */
name|psexit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
name|PSTKOVFLO
case|:
name|fputs
argument_list|(
literal|"Run time stack overflow\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
case|case
name|PSYSTEM
case|:
name|fputs
argument_list|(
literal|"Panic: Computational error in interpreter\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
case|case
name|PSTKNEMP
case|:
name|fputs
argument_list|(
literal|"Panic: stack not empty between statements\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
case|case
name|PBADOP
case|:
name|fputs
argument_list|(
literal|"Panic: bad op code\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fputs
argument_list|(
literal|"Panic: unknown error\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|backtrace
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
comment|/* pfree(objprog); */
name|psexit
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_macro
name|liberr
argument_list|()
end_macro

begin_block
block|{
name|panic
argument_list|(
name|PLIBERR
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|intr
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intr
argument_list|)
expr_stmt|;
name|panic
argument_list|(
name|PINTR
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|memsize
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|memsize
argument_list|)
expr_stmt|;
name|panic
argument_list|(
name|PSTKOVFLO
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|syserr
argument_list|(
argument|signum
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signum
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|signal
argument_list|(
name|signum
argument_list|,
name|syserr
argument_list|)
expr_stmt|;
name|panic
argument_list|(
name|PSYSTEM
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|except
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|except
argument_list|)
expr_stmt|;
name|panic
argument_list|(
name|PNUMOVFLO
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

