begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)cmdtab.c	4.4 (Berkeley) 7/25/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * lpc -- command tables  */
end_comment

begin_include
include|#
directive|include
file|"lpc.h"
end_include

begin_decl_stmt
name|int
name|abort
argument_list|()
decl_stmt|,
name|clean
argument_list|()
decl_stmt|,
name|enable
argument_list|()
decl_stmt|,
name|disable
argument_list|()
decl_stmt|,
name|help
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|quit
argument_list|()
decl_stmt|,
name|restart
argument_list|()
decl_stmt|,
name|start
argument_list|()
decl_stmt|,
name|status
argument_list|()
decl_stmt|,
name|stop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|topq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|aborthelp
index|[]
init|=
literal|"terminate a spooling daemon immediately and disable printing"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cleanhelp
index|[]
init|=
literal|"remove cruft files from a queue"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|enablehelp
index|[]
init|=
literal|"turn a spooling queue on"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|disablehelp
index|[]
init|=
literal|"turn a spooling queue off"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|helphelp
index|[]
init|=
literal|"get help on commands"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|quithelp
index|[]
init|=
literal|"exit lpc"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|restarthelp
index|[]
init|=
literal|"restart a spooling daemon that has died"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|starthelp
index|[]
init|=
literal|"enable printing and start a spooling daemon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|statushelp
index|[]
init|=
literal|"show status of daemon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|stophelp
index|[]
init|=
literal|"stop a spooling daemon after current job completes and disable printing"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|topqhelp
index|[]
init|=
literal|"put job at top of printer queue"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cmd
name|cmdtab
index|[]
init|=
block|{
block|{
literal|"abort"
block|,
name|aborthelp
block|,
name|abort
block|,
literal|1
block|}
block|,
block|{
literal|"clean"
block|,
name|cleanhelp
block|,
name|clean
block|,
literal|1
block|}
block|,
block|{
literal|"enable"
block|,
name|enablehelp
block|,
name|enable
block|,
literal|1
block|}
block|,
block|{
literal|"exit"
block|,
name|quithelp
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"disable"
block|,
name|disablehelp
block|,
name|disable
block|,
literal|1
block|}
block|,
block|{
literal|"help"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|"quit"
block|,
name|quithelp
block|,
name|quit
block|,
literal|0
block|}
block|,
block|{
literal|"restart"
block|,
name|restarthelp
block|,
name|restart
block|,
literal|0
block|}
block|,
block|{
literal|"start"
block|,
name|starthelp
block|,
name|start
block|,
literal|1
block|}
block|,
block|{
literal|"status"
block|,
name|statushelp
block|,
name|status
block|,
literal|0
block|}
block|,
block|{
literal|"stop"
block|,
name|stophelp
block|,
name|stop
block|,
literal|1
block|}
block|,
block|{
literal|"topq"
block|,
name|topqhelp
block|,
name|topq
block|,
literal|1
block|}
block|,
block|{
literal|"?"
block|,
name|helphelp
block|,
name|help
block|,
literal|0
block|}
block|,
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|NCMDS
init|=
sizeof|sizeof
argument_list|(
name|cmdtab
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cmdtab
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

