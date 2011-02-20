begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | grep noalias
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
modifier|*
name|__restrict
name|myptr1
parameter_list|,
name|int
modifier|*
name|myptr2
parameter_list|)
block|{
name|myptr1
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|myptr2
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

