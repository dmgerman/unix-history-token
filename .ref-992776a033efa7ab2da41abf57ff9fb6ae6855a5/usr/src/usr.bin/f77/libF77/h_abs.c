begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)h_abs.c	1.1"  */
end_comment

begin_function
name|short
name|h_abs
parameter_list|(
name|x
parameter_list|)
name|short
modifier|*
name|x
decl_stmt|;
block|{
if|if
condition|(
operator|*
name|x
operator|>=
literal|0
condition|)
return|return
operator|(
operator|*
name|x
operator|)
return|;
return|return
operator|(
operator|-
operator|*
name|x
operator|)
return|;
block|}
end_function

end_unit

