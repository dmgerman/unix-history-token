begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)r_atn2.c	1.1"  */
end_comment

begin_function
name|double
name|r_atn2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|float
modifier|*
name|x
decl_stmt|,
decl|*
name|y
decl_stmt|;
end_function

begin_block
block|{
name|double
name|atan2
parameter_list|()
function_decl|;
return|return
operator|(
name|atan2
argument_list|(
operator|*
name|x
argument_list|,
operator|*
name|y
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

