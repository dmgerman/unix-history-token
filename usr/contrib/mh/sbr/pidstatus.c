begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pidstatus.c - report child's status */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sigs
index|[]
init|=
block|{
name|NULL
block|,
literal|"Hangup"
block|,
literal|"Interrupt"
block|,
literal|"Quit"
block|,
literal|"Illegal instruction"
block|,
literal|"Trace/BPT trap"
block|,
literal|"IOT trap"
block|,
literal|"EMT trap"
block|,
literal|"Floating exception"
block|,
literal|"Killed"
block|,
literal|"Bus error"
block|,
literal|"Segmentation fault"
block|,
literal|"Bad system call"
block|,
literal|"Broken pipe"
block|,
literal|"Alarm clock"
block|,
literal|"Terminated"
block|,
ifdef|#
directive|ifdef
name|SIGURG
literal|"Urgent I/O condition"
block|,
else|#
directive|else
name|NULL
block|,
endif|#
directive|endif
literal|"Stopped (signal)"
block|,
literal|"Stopped"
block|,
literal|"Continued"
block|,
literal|"Child exited"
block|,
literal|"Stopped (tty input)"
block|,
literal|"Stopped (tty output)"
block|,
literal|"Tty input interrupt"
block|,
literal|"Cputime limit exceeded"
block|,
literal|"Filesize limit exceeded"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_siglist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BSD42
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_function
name|int
name|pidstatus
parameter_list|(
name|status
parameter_list|,
name|fp
parameter_list|,
name|cp
parameter_list|)
specifier|register
name|int
name|status
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
block|{
name|int
name|signum
decl_stmt|;
if|if
condition|(
operator|(
name|status
operator|&
literal|0xff00
operator|)
operator|==
literal|0xff00
condition|)
return|return
name|status
return|;
switch|switch
condition|(
name|signum
operator|=
name|status
operator|&
literal|0x007f
condition|)
block|{
case|case
name|OK
case|:
if|if
condition|(
name|signum
operator|=
operator|(
operator|(
name|status
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator|)
condition|)
block|{
if|if
condition|(
name|cp
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s: "
argument_list|,
name|cp
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"Exit %d\n"
argument_list|,
name|signum
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SIGINT
case|:
break|break;
default|default:
if|if
condition|(
name|cp
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s: "
argument_list|,
name|cp
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|BSD42
if|if
condition|(
name|signum
operator|>=
sizeof|sizeof
name|sigs
operator|||
name|sigs
index|[
name|signum
index|]
operator|==
name|NULL
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"Signal %d"
argument_list|,
name|signum
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s"
argument_list|,
name|sigs
index|[
name|signum
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
else|BSD42
if|if
condition|(
name|signum
operator|>=
name|NSIG
condition|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"Signal %d"
argument_list|,
name|signum
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s"
argument_list|,
name|sys_siglist
index|[
name|signum
index|]
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|BSD42
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s\n"
argument_list|,
name|status
operator|&
literal|0x80
condition|?
literal|" (core dumped)"
else|:
literal|""
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|status
return|;
block|}
end_function

end_unit

