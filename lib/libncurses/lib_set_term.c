begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/* **	lib_set_term.c ** **	The routine set_term(). ** */
end_comment

begin_include
include|#
directive|include
file|"curses.priv.h"
end_include

begin_include
include|#
directive|include
file|<nterm.h>
end_include

begin_function
name|struct
name|screen
modifier|*
name|set_term
parameter_list|(
name|screen
parameter_list|)
name|struct
name|screen
modifier|*
name|screen
decl_stmt|;
block|{
name|struct
name|screen
modifier|*
name|oldSP
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE
if|if
condition|(
name|_tracing
condition|)
name|_tracef
argument_list|(
literal|"set_term(%o) called"
argument_list|,
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|oldSP
operator|=
name|SP
expr_stmt|;
name|SP
operator|=
name|screen
expr_stmt|;
name|cur_term
operator|=
name|SP
operator|->
name|_term
expr_stmt|;
name|curscr
operator|=
name|SP
operator|->
name|_curscr
expr_stmt|;
name|newscr
operator|=
name|SP
operator|->
name|_newscr
expr_stmt|;
return|return
operator|(
name|oldSP
operator|)
return|;
block|}
end_function

end_unit

