begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * convert short ints to long.  * Needed for literals in -I2 compiles.  * used as follows:  *	integer*4 long  *	...  *	call ftell(long(11))  */
end_comment

begin_function
name|long
name|long_
parameter_list|(
name|i
parameter_list|)
name|short
modifier|*
name|i
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|long
operator|)
operator|*
name|i
operator|)
return|;
block|}
end_function

end_unit

