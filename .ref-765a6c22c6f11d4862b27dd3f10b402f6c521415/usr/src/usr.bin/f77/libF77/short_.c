begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	"@(#)short_.c	1.1"  */
end_comment

begin_comment
comment|/*  * convert long ints to short.  *  * used as follows:  *	integer*2 short  *	...  *	call mysub(short(ivar))  * where:  *	mysub expects to receive an integer*2 arg and ivar is integer*4  */
end_comment

begin_function
name|short
name|short_
parameter_list|(
name|i
parameter_list|)
name|long
modifier|*
name|i
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|short
operator|)
operator|*
name|i
operator|)
return|;
block|}
end_function

end_unit

