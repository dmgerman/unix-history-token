begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
end_comment

begin_decl_stmt
name|char
name|id_libF77
index|[]
init|=
literal|"@(#)main.c	2.17	%G%"
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
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

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
name|MAIN_
argument_list|()
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
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
block|{
literal|"Illegal "
block|,
literal|1
block|}
block|,
comment|/* SIGILL  */
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
block|{
literal|"Arithmetic Exception"
block|,
literal|1
block|}
block|,
comment|/* SIGFPE  */
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
literal|"Floating point overflow trap"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating divide by zero trap"
block|,
literal|1
block|}
block|,
block|{
literal|"Floating point underflow trap"
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

begin_if
if|#
directive|if
name|vax
end_if

begin_macro
name|sigdie
argument_list|(
argument|s
argument_list|,
argument|t
argument_list|,
argument|sc
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
name|struct
name|sigcontext
modifier|*
name|sc
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|pdp11
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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
name|s
operator|==
name|SIGHUP
operator|||
name|s
operator|==
name|SIGINT
operator|||
name|s
operator|==
name|SIGQUIT
condition|)
name|signal
argument_list|(
name|s
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* don't allow it again */
else|else
name|signal
argument_list|(
name|s
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
comment|/* shouldn't happen again, but ... */
if|if
condition|(
name|act
operator|->
name|mesg
condition|)
block|{
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
block|}
name|f77_abort
argument_list|(
name|s
argument_list|,
name|act
operator|->
name|core
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|extern
name|int
name|_dbsubc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dbsubc is non-zero if -lg was specified to ld */
end_comment

begin_macro
name|f77_abort
argument_list|(
argument|err_val
argument_list|,
argument|act_core
argument_list|)
end_macro

begin_block
block|{
name|char
name|first_char
decl_stmt|,
modifier|*
name|env_var
decl_stmt|;
name|int
name|core_dump
decl_stmt|;
name|env_var
operator|=
name|getenv
argument_list|(
literal|"f77_dump_flag"
argument_list|)
expr_stmt|;
name|first_char
operator|=
operator|(
name|env_var
operator|==
name|NULL
operator|)
condition|?
literal|0
else|:
operator|*
name|env_var
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* don't block */
comment|/* see if we want a core dump: 		first line checks for signals like hangup - don't dump then. 		second line checks if -lg specified to ld (e.g. by saying 			-g to f77) and checks the f77_dump_flag var. */
name|core_dump
operator|=
operator|(
operator|(
name|nargs
argument_list|()
operator|!=
literal|2
operator|)
operator|||
name|act_core
operator|)
operator|&&
operator|(
operator|(
name|_dbsubc
operator|&&
operator|(
name|first_char
operator|!=
literal|'n'
operator|)
operator|)
operator|||
name|first_char
operator|==
literal|'y'
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|core_dump
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
literal|"*** Execution terminated\n"
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
if|if
condition|(
name|nargs
argument_list|()
condition|)
name|errno
operator|=
name|err_val
expr_stmt|;
else|else
name|errno
operator|=
operator|-
literal|2
expr_stmt|;
comment|/* prior value will be meaningless, 				so set it to undefined value */
if|if
condition|(
name|core_dump
condition|)
name|abort
argument_list|()
expr_stmt|;
else|else
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

