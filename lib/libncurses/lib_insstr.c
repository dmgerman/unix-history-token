begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/* **	lib_insstr.c ** **	The routine winsnstr(). ** */
end_comment

begin_include
include|#
directive|include
file|"curses.priv.h"
end_include

begin_function
name|int
name|winsnstr
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|T
argument_list|(
operator|(
literal|"winsstr(%x,'%x',%d) called"
operator|,
name|win
operator|,
name|str
operator|,
name|n
operator|)
argument_list|)
expr_stmt|;
return|return
name|OK
return|;
block|}
end_function

end_unit

