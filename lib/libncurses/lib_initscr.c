begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/* **	lib_initscr.c ** **	The routine initscr(). ** */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"curses.priv.h"
end_include

begin_function
name|WINDOW
modifier|*
name|initscr
parameter_list|()
block|{
specifier|static
name|bool
name|initialized
init|=
name|FALSE
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE
name|_init_trace
argument_list|()
expr_stmt|;
name|T
argument_list|(
operator|(
literal|"initscr() called"
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Portable applications must not call initscr() more than once */
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
operator|(
name|name
operator|=
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
operator|)
operator|==
literal|0
condition|)
name|name
operator|=
literal|"unknown"
expr_stmt|;
if|if
condition|(
name|newterm
argument_list|(
name|name
argument_list|,
name|stdout
argument_list|,
name|stdin
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error opening terminal: %s.\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* def_shell_mode - done in newterm */
name|def_prog_mode
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|stdscr
operator|)
return|;
block|}
end_function

end_unit

