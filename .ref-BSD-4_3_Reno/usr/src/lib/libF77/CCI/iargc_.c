begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)iargc_.c	5.1 (Berkeley) 11/3/86  */
end_comment

begin_function
name|long
name|int
name|iargc_
parameter_list|()
block|{
specifier|extern
name|int
name|xargc
decl_stmt|;
return|return
operator|(
name|xargc
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

