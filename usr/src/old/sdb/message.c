begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)message.c 4.2 8/17/82"
decl_stmt|;
end_decl_stmt

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *  *	UNIX debugger  *  */
end_comment

begin_include
include|#
directive|include
file|"mac.h"
end_include

begin_include
include|#
directive|include
file|"mode.h"
end_include

begin_decl_stmt
name|MSG
name|BADMOD
init|=
literal|"bad modifier"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOBKPT
init|=
literal|"no breakpoint set"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOPCS
init|=
literal|"no process"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADTXT
init|=
literal|"text address not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADDAT
init|=
literal|"data address not found"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|EXBKPT
init|=
literal|"too many breakpoints"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADWAIT
init|=
literal|"wait error: process disappeared!"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ENDPCS
init|=
literal|"process terminated"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|NOFORK
init|=
literal|"try again"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|SZBKPT
init|=
literal|"bkpt: command too long"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|BADMAG
init|=
literal|"bad core magic number"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|signals
index|[]
init|=
block|{
literal|""
block|,
literal|"hangup"
block|,
literal|"interrupt"
block|,
literal|"quit"
block|,
literal|"illegal instruction"
block|,
literal|"trace/BPT"
block|,
literal|"IOT"
block|,
literal|"EMT"
block|,
literal|"floating exception"
block|,
literal|"killed"
block|,
literal|"bus error"
block|,
literal|"memory fault"
block|,
literal|"bad system call"
block|,
literal|"broken pipe"
block|,
literal|"alarm call"
block|,
literal|"terminated"
block|,
literal|"signal 16"
block|,
literal|"stop (signal)"
block|,
literal|"stop (tty)"
block|,
literal|"continue (signal)"
block|,
literal|"child termination"
block|,
literal|"stop (tty input)"
block|,
literal|"stop (tty output)"
block|,
literal|"input available (signal)"
block|,
literal|"cpu timelimit"
block|,
literal|"file sizelimit"
block|,
literal|"signal 26"
block|,
literal|"signal 27"
block|,
literal|"signal 28"
block|,
literal|"signal 29"
block|,
literal|"signal 30"
block|,
literal|"signal 31"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsig
init|=
sizeof|sizeof
argument_list|(
name|signals
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|signals
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

