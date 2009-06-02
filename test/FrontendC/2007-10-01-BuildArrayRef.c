begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %llvmgcc -S %s -o /dev/null |& grep "error: assignment of read-only location"
end_comment

begin_comment
comment|// PR 1603
end_comment

begin_function
name|int
name|func
parameter_list|()
block|{
specifier|const
name|int
modifier|*
name|arr
decl_stmt|;
name|arr
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

