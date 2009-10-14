begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* Regression test.  Just compile .c -> .ll to test */
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|pp
decl_stmt|;
name|unsigned
name|w_cnt
decl_stmt|;
name|w_cnt
operator|+=
operator|*
name|pp
expr_stmt|;
return|return
name|w_cnt
return|;
block|}
end_function

end_unit

