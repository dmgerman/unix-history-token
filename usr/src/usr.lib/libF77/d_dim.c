begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)d_dim.c	1.1"  */
end_comment

begin_function
name|double
name|d_dim
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|double
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
return|return
operator|(
operator|*
name|a
operator|>
operator|*
name|b
condition|?
operator|*
name|a
operator|-
operator|*
name|b
else|:
literal|0
operator|)
return|;
block|}
end_block

end_unit

