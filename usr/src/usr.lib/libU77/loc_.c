begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_loc[] = "@(#)loc_.c	1.1";  *  * Return the address of the argument.  *  * calling sequence:  *	iloc = loc (arg)  * where:  *	iloc will receive the address of arg  */
end_comment

begin_function
name|long
name|loc_
parameter_list|(
name|arg
parameter_list|)
name|long
modifier|*
name|arg
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|arg
operator|)
return|;
block|}
end_function

end_unit

