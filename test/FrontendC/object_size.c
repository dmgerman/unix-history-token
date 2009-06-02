begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -emit-llvm -O1 %s -o - | grep ret | grep {\\-1} | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -emit-llvm -O1 %s -o - | grep ret | grep {0}  | count 1
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -emit-llvm -O1 %s -o - | grep ret | grep {8}  | count 1
end_comment

begin_function
name|unsigned
name|t1
parameter_list|(
name|void
modifier|*
name|d
parameter_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|d
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|t2
parameter_list|(
name|void
modifier|*
name|d
parameter_list|)
block|{
return|return
name|__builtin_object_size
argument_list|(
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|char
name|buf
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|t3
parameter_list|()
block|{
return|return
name|__builtin_object_size
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

