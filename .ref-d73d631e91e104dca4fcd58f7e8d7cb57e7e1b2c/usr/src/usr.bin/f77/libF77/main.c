begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)main.c	5.5	%G%  */
end_comment

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
name|void
name|sigdie
parameter_list|()
function_decl|;
name|sig_t
name|sigf
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

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/* The following arrays are defined& used assuming that signal codes are     1 to 5 for SIGFPE, and 0 to 3 for SIGILL.     Actually ILL_ALIGN_FAULT=14, and is mapped to 3. */
end_comment

begin_define
define|#
directive|define
name|N_ACT_ILL
value|4
end_define

begin_comment
comment|/* number of entries in act_ill[] */
end_comment

begin_define
define|#
directive|define
name|N_ACT_FPE
value|5
end_define

begin_comment
comment|/* number of entries in act_fpe[] */
end_comment

begin_define
define|#
directive|define
name|ILL_ALIGN_FAULT
value|14
end_define

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
literal|"Floating divide by zero"
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
literal|"Floating point underflow"
block|,
literal|1
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|vax || pdp11
end_else

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

begin_endif
endif|#
directive|endif
endif|vax || pdp11
end_endif

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
block|,
ifdef|#
directive|ifdef
name|tahoe
block|{
literal|"alignment"
block|,
literal|1
block|}
block|,
endif|#
directive|endif
endif|tahoe
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|)
end_if

begin_function
name|void
name|sigdie
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|,
name|sc
parameter_list|)
name|int
name|s
decl_stmt|;
name|int
name|t
decl_stmt|;
name|struct
name|sigcontext
modifier|*
name|sc
decl_stmt|;
else|#
directive|else
else|pdp11
function|void sigdie
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|,
name|pc
parameter_list|)
name|int
name|s
decl_stmt|;
name|int
name|t
decl_stmt|;
name|long
name|pc
decl_stmt|;
endif|#
directive|endif
endif|pdp11
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
ifndef|#
directive|ifndef
name|tahoe
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
else|#
directive|else
else|tahoe
if|if
condition|(
operator|(
name|t
operator|-
literal|1
operator|)
operator|>=
literal|0
operator|&&
name|t
operator|<
name|N_ACT_FPE
condition|)
endif|#
directive|endif
endif|tahoe
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
ifndef|#
directive|ifndef
name|tahoe
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
else|#
directive|else
else|tahoe
if|if
condition|(
name|t
operator|==
name|ILL_ALIGN_FAULT
condition|)
comment|/* ILL_ALIGN_FAULT maps to last 			t = N_ACT_ILL-1;   	   entry in act_ill[] */
if|if
condition|(
name|t
operator|>=
literal|0
operator|&&
name|t
operator|<
name|N_ACT_ILL
condition|)
endif|#
directive|endif
endif|tahoe
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
end_function

end_unit

