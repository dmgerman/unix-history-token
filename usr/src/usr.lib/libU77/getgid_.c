begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_getgid[] = "@(#)getgid_.c	1.1";  *  * get group id  *  * calling sequence:  *	integer getgid, gid  *	gid = getgid()  * where:  *	gid will be the real group id  */
end_comment

begin_function
name|long
name|getgid_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|getgid
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

