begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -xc %s -S -o - | grep getelementptr
end_comment

begin_comment
comment|// This should be turned into a tasty getelementptr instruction, not a nasty
end_comment

begin_comment
comment|// series of casts and address arithmetic.
end_comment

begin_decl_stmt
name|char
name|Global
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|test1
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
operator|&
name|Global
index|[
name|i
index|]
return|;
block|}
end_function

end_unit

