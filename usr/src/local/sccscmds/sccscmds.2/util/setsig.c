begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_undef
undef|#
directive|undef
name|NSIG
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|PWB
end_ifdef

begin_define
define|#
directive|define
name|NSIG
value|16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NSIG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../hdr/macros.h"
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|setsig
literal|2.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	General-purpose signal setting routine. 	All non-ignored, non-caught signals are caught. 	If a signal other than hangup, interrupt, or quit is caught, 	a "user-oriented" message is printed on file descriptor 2 with 	a number for help(I). 	If hangup, interrupt or quit is caught, that signal	 	is set to ignore. 	Termination is like that of "fatal", 	via "clean_up(sig)" (sig is the signal number) 	and "exit(userexit(1))".   	If the file "dump.core" exists in the current directory 	the function commits 	suicide to produce a core dump 	(after calling clean_up, but before calling userexit). */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Mesg
index|[
name|NSIG
index|]
block|{
literal|0
operator|,
literal|0
operator|,
comment|/* Hangup */
literal|0
operator|,
comment|/* Interrupt */
literal|0
operator|,
comment|/* Quit */
ifdef|#
directive|ifdef
name|PWB
literal|"Illegal instruction"
operator|,
literal|"Trace/BPT trap"
operator|,
literal|"IOT trap"
operator|,
literal|"EMT trap"
operator|,
literal|"Floating exception"
operator|,
literal|"Killed"
operator|,
literal|"Bus error"
operator|,
literal|"Memory fault"
operator|,
literal|"Bad system call"
operator|,
literal|"Broken pipe"
operator|,
literal|"Alarm clock"
operator|,
literal|"Terminated"
endif|#
directive|endif
endif|PWB
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|setsig
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|setsig1
parameter_list|()
function_decl|;
specifier|register
name|int
name|j
decl_stmt|,
name|n
decl_stmt|;
for|for
control|(
name|j
operator|=
literal|1
init|;
name|j
operator|<
name|NSIG
condition|;
name|j
operator|++
control|)
if|if
condition|(
name|n
operator|=
name|signal
argument_list|(
name|j
argument_list|,
name|setsig1
argument_list|)
condition|)
name|signal
argument_list|(
name|j
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|char
name|preface
index|[]
literal|"SIGNAL: "
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|char
name|endmsg
index|[]
literal|" (ut12)\n"
expr_stmt|;
end_expr_stmt

begin_macro
name|setsig1
argument_list|(
argument|sig
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sig
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifndef|#
directive|ifndef
name|PWB
name|sig
operator|=
literal|2
expr_stmt|;
endif|#
directive|endif
endif|PWB
if|if
condition|(
name|Mesg
index|[
name|sig
index|]
condition|)
block|{
name|syswrite
argument_list|(
literal|2
argument_list|,
name|preface
argument_list|,
name|length
argument_list|(
name|preface
argument_list|)
argument_list|)
expr_stmt|;
name|syswrite
argument_list|(
literal|2
argument_list|,
name|Mesg
index|[
name|sig
index|]
argument_list|,
name|length
argument_list|(
name|Mesg
index|[
name|sig
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|syswrite
argument_list|(
literal|2
argument_list|,
name|endmsg
argument_list|,
name|length
argument_list|(
name|endmsg
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|signal
argument_list|(
name|sig
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|clean_up
argument_list|(
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
name|open
argument_list|(
literal|"dump.core"
argument_list|,
literal|0
argument_list|)
operator|>
literal|0
condition|)
block|{
name|signal
argument_list|(
name|SIGIOT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|exit
argument_list|(
name|userexit
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

