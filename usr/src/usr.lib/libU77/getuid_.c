begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_getuid[] = "@(#)getuid_.c	1.1";  *  * get user id  *  * calling sequence:  *	integer getuid, uid  *	uid = getuid()  * where:  *	uid will be the real user id  */
end_comment

begin_function
name|long
name|getuid_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|getuid
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

