begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/*  *	beep.c  *  *	Routines beep() and flash()  *  */
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

begin_comment
comment|/*  *	beep()  *  *	Sound the current terminal's audible bell if it has one.   If not,  *	flash the screen if possible.  *  */
end_comment

begin_function
name|int
name|beep
parameter_list|()
block|{
name|T
argument_list|(
operator|(
literal|"beep() called"
operator|)
argument_list|)
expr_stmt|;
comment|/* should make sure that we are not in altchar mode */
if|if
condition|(
name|bell
condition|)
return|return
operator|(
name|tputs
argument_list|(
name|bell
argument_list|,
literal|1
argument_list|,
name|_outc
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|flash_screen
condition|)
return|return
operator|(
name|tputs
argument_list|(
name|flash_screen
argument_list|,
literal|1
argument_list|,
name|_outc
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|ERR
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	flash()  *  *	Flash the current terminal's screen if possible.   If not,  *	sound the audible bell if one exists.  *  */
end_comment

begin_function
name|int
name|flash
parameter_list|()
block|{
name|T
argument_list|(
operator|(
literal|"flash() called"
operator|)
argument_list|)
expr_stmt|;
comment|/* should make sure that we are not in altchar mode */
if|if
condition|(
name|flash_screen
condition|)
return|return
operator|(
name|tputs
argument_list|(
name|flash_screen
argument_list|,
literal|1
argument_list|,
name|_outc
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|bell
condition|)
return|return
operator|(
name|tputs
argument_list|(
name|bell
argument_list|,
literal|1
argument_list|,
name|_outc
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|ERR
operator|)
return|;
block|}
end_function

end_unit

