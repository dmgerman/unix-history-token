begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)dbesj1_.c	1.1"  */
end_comment

begin_function_decl
name|double
name|j1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|double
name|dbesj1_
parameter_list|(
name|x
parameter_list|)
name|double
modifier|*
name|x
decl_stmt|;
block|{
return|return
operator|(
name|j1
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

