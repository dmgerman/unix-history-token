begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  * enter standout mode  */
end_comment

begin_function
name|char
modifier|*
name|wstandout
parameter_list|(
name|win
parameter_list|)
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|SO
condition|)
return|return
name|FALSE
return|;
name|win
operator|->
name|_flags
operator||=
name|_STANDOUT
expr_stmt|;
return|return
name|SO
return|;
block|}
end_function

begin_comment
comment|/*  * exit standout mode  */
end_comment

begin_function
name|char
modifier|*
name|wstandend
parameter_list|(
name|win
parameter_list|)
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|SO
condition|)
return|return
name|FALSE
return|;
name|win
operator|->
name|_flags
operator|&=
operator|~
name|_STANDOUT
expr_stmt|;
return|return
name|SE
return|;
block|}
end_function

end_unit

