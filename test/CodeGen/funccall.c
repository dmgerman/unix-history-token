begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|int
name|q
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|t
init|=
name|q
decl_stmt|;
name|q
operator|=
name|t
operator|+
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|q
operator|=
literal|0
expr_stmt|;
name|foo
argument_list|()
expr_stmt|;
name|q
operator|=
name|q
operator|-
literal|1
expr_stmt|;
return|return
name|q
return|;
block|}
end_function

begin_comment
comment|// This is the source that corresponds to funccall.ll
end_comment

begin_comment
comment|// RUN: echo foo
end_comment

end_unit

