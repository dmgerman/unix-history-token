begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
end_comment

begin_decl_stmt
name|char
name|id_libF77
index|[]
init|=
literal|"@(#)main.c	2.10	11/3/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_decl_stmt
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|arge
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
modifier|*
name|arge
decl_stmt|;
block|{
name|int
name|sigdie
parameter_list|()
function_decl|;
name|long
name|int
argument_list|(
operator|*
name|sigf
argument_list|)
argument_list|()
decl_stmt|;
name|int
name|signum
decl_stmt|;
name|xargc
operator|=
name|argc
expr_stmt|;
name|xargv
operator|=
name|argv
expr_stmt|;
for|for
control|(
name|signum
operator|=
literal|1
init|;
name|signum
operator|<=
literal|16
condition|;
name|signum
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|sigf
operator|=
name|signal
argument_list|(
name|signum
argument_list|,
name|sigdie
argument_list|)
operator|)
operator|!=
name|SIG_DFL
condition|)
name|signal
argument_list|(
name|signum
argument_list|,
name|sigf
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|pdp11
name|ldfps
argument_list|(
literal|01200
argument_list|)
expr_stmt|;
comment|/* detect overflow as an exception */
endif|#
directive|endif
name|f_init
argument_list|()
expr_stmt|;
name|MAIN__
argument_list|()
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|action
block|{
name|char
modifier|*
name|mesg
decl_stmt|;
name|int
name|core
decl_stmt|;
block|}
name|sig_act
index|[
literal|16
index|]
init|=
block|{
block|{
literal|"Hangup"
block|,
literal|0
block|}
block|,
comment|/* SIGHUP  */
block|{
literal|"Interrupt!"
block|,
literal|0
block|}
block|,
comment|/* SIGINT  */
block|{
literal|"Quit!"
block|,
literal|1
block|}
block|,
comment|/* SIGQUIT */
ifdef|#
directive|ifdef
name|UCBVAX
block|{
literal|"Illegal "
block|,
literal|1
block|}
block|,
comment|/* SIGILL  */
else|#
directive|else
block|{
literal|"Illegal instruction"
block|,
literal|1
block|}
block|,
comment|/* SIGILL  */
endif|#
directive|endif
block|{
literal|"Trace Trap"
block|,
literal|1
block|}
block|,
comment|/* SIGTRAP */
block|{
literal|"IOT Trap"
block|,
literal|1
block|}
block|,
comment|/* SIGIOT  */
block|{
literal|"EMT Trap"
block|,
literal|1
block|}
block|,
comment|/* SIGEMT  */
ifdef|#
directive|ifdef
name|UCBVAX
block|{
literal|"Arithmetic Exception"
block|,
literal|1
block|}
block|,
comment|/* SIGFPE  */
else|#
directive|else
block|{
literal|"Floating Point Exception"
block|,
literal|1
block|}
block|,
comment|/* SIGFPE  */
endif|#
directive|endif
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* SIGKILL */
block|{
literal|"Bus error"
block|,
literal|1
block|}
block|,
comment|/* SIGBUS  */
block|{
literal|"Segmentation violation"
block|,
literal|1
block|}
block|,
comment|/* SIGSEGV */
block|{
literal|"Sys arg"
block|,
literal|1
block|}
block|,
comment|/* SIGSYS  */
block|{
literal|"Open pipe"
block|,
literal|0
block|}
block|,
comment|/* SIGPIPE */
block|{
literal|"Alarm"
block|,
literal|0
block|}
block|,
comment|/* SIGALRM */
block|{
literal|"Terminated"
block|,
literal|0
block|}
block|,
comment|/* SIGTERM */
block|{
literal|"Sig 16"
block|,
literal|0
block|}
block|,
comment|/* unassigned */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|UCBVAX
end_ifdef

begin_decl_stmt
name|struct
name|action
name|act_fpe
index|[]
init|=
block|{
block|{
literal|"Integer overflow"
block|,
literal|1
block|}
block|,
block|{
literal|"Integer divide by 0"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating point overflow"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating divide by zero"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating point underflow"
block|,
literal|1
block|}
block|,
block|{
literal|"Decimal overflow"
block|,
literal|1
block|}
block|,
block|{
literal|"Subscript range"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating point overflow"
block|,
literal|0
block|}
block|,
block|{
literal|"Floating divide by zero"
block|,
literal|0
block|}
block|,
block|{
literal|"Floating point underflow"
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|action
name|act_ill
index|[]
init|=
block|{
block|{
literal|"addr mode"
block|,
literal|1
block|}
block|,
block|{
literal|"instruction"
block|,
literal|1
block|}
block|,
block|{
literal|"operand"
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|sigdie
argument_list|(
argument|s
argument_list|,
argument|t
argument_list|,
argument|pc
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|pc
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
specifier|register
name|struct
name|action
modifier|*
name|act
init|=
operator|&
name|sig_act
index|[
name|s
operator|-
literal|1
index|]
decl_stmt|;
comment|/* print error message, then flush buffers */
if|if
condition|(
name|act
operator|->
name|mesg
condition|)
block|{
ifdef|#
directive|ifdef
name|UCBVAX
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|"*** %s"
argument_list|,
name|act
operator|->
name|mesg
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|SIGFPE
condition|)
block|{
if|if
condition|(
name|t
operator|>=
literal|1
operator|&&
name|t
operator|<=
literal|10
condition|)
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|": %s"
argument_list|,
name|act_fpe
index|[
name|t
operator|-
literal|1
index|]
operator|.
name|mesg
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|": Type=%d?"
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|s
operator|==
name|SIGILL
condition|)
block|{
if|if
condition|(
name|t
operator|==
literal|4
condition|)
name|t
operator|=
literal|2
expr_stmt|;
comment|/* 4.0bsd botch */
if|if
condition|(
name|t
operator|>=
literal|0
operator|&&
name|t
operator|<=
literal|2
condition|)
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|"%s"
argument_list|,
name|act_ill
index|[
name|t
index|]
operator|.
name|mesg
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|"compat mode: Code=%d"
argument_list|,
name|t
argument_list|)
expr_stmt|;
block|}
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|)
expr_stmt|;
else|#
directive|else
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|"*** %s\n"
argument_list|,
name|act
operator|->
name|mesg
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
if|if
condition|(
name|act
operator|->
name|core
condition|)
block|{
comment|/* now get a core */
ifdef|#
directive|ifdef
name|VAX
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
else|#
directive|else
name|signal
argument_list|(
name|SIGIOT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|abort
argument_list|()
expr_stmt|;
block|}
name|exit
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

