begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)mclock_.c	5.1 (Berkeley) 11/3/86  */
end_comment

begin_function
name|long
name|int
name|mclock_
parameter_list|()
block|{
name|int
name|buf
index|[
literal|6
index|]
decl_stmt|;
name|times
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
index|[
literal|0
index|]
operator|+
name|buf
index|[
literal|2
index|]
operator|+
name|buf
index|[
literal|3
index|]
operator|)
return|;
block|}
end_function

end_unit

