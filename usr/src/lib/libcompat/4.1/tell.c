begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)tell.c	4.1 (Berkeley) %G% */
end_comment

begin_comment
comment|/*  * return offset in file.  */
end_comment

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|tell
parameter_list|(
name|f
parameter_list|)
block|{
return|return
operator|(
name|lseek
argument_list|(
name|f
argument_list|,
literal|0L
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

