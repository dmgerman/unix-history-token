begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/* **	lib_clear.c ** **	The routine wclear(). ** */
end_comment

begin_include
include|#
directive|include
file|"curses.priv.h"
end_include

begin_function
name|int
name|wclear
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|)
block|{
name|T
argument_list|(
operator|(
literal|"wclear(%x) called"
operator|,
name|win
operator|)
argument_list|)
expr_stmt|;
name|werase
argument_list|(
name|win
argument_list|)
expr_stmt|;
name|win
operator|->
name|_clear
operator|=
name|TRUE
expr_stmt|;
return|return
name|OK
return|;
block|}
end_function

end_unit

