begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)derfc_.c	1.1"  */
end_comment

begin_function
name|double
name|derfc_
parameter_list|(
name|x
parameter_list|)
name|double
modifier|*
name|x
decl_stmt|;
block|{
name|double
name|erfc
parameter_list|()
function_decl|;
return|return
operator|(
name|erfc
argument_list|(
operator|*
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

