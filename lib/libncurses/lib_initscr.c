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
if|if
condition|(
name|newterm
argument_list|(
name|getenv
argument_list|(
literal|"TERM"
argument_list|)
argument_list|,
name|stdout
argument_list|,
name|stdin
argument_list|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
else|else
block|{
name|def_shell_mode
argument_list|()
expr_stmt|;
name|def_prog_mode
argument_list|()
expr_stmt|;
return|return
operator|(
name|stdscr
operator|)
return|;
block|}
block|}
end_function

end_unit

