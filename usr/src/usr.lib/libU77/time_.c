begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_time[] = "@(#)time_.c	1.1";  *  * return the current time as an integer  *  * calling sequence:  *	integer time  *	i = time()  * where:  *	i will receive the current GMT in seconds.  */
end_comment

begin_function_decl
name|long
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|time_
parameter_list|()
block|{
return|return
operator|(
name|time
argument_list|(
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

