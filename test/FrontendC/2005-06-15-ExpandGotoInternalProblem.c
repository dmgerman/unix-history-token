begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -std=c99 %s -S -o - | \
end_comment

begin_comment
comment|// RUN:    opt -std-compile-opts -disable-output
end_comment

begin_comment
comment|// PR580
end_comment

begin_decl_stmt
name|int
name|X
decl_stmt|,
name|Y
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
block|{
break|break;
name|i
operator|=
operator|(
name|X
operator|||
name|Y
operator|)
expr_stmt|;
block|}
block|}
end_function

end_unit

