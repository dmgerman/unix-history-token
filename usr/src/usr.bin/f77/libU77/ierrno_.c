begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_ierrno[] = "@(#)ierrno_.c	1.1";  *  * return the current value of the system error register  *  * calling sequence:  *	ier = ierrno()  * where:  *	ier will receive the current value of errno  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|ierrno_
parameter_list|()
block|{
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
block|}
end_function

end_unit

