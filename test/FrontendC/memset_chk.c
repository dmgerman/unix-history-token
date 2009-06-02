begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -emit-llvm -O1 %s -o - | grep call | not grep memset_chk
end_comment

begin_comment
comment|// rdar://6728562
end_comment

begin_function
name|void
name|t
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|__builtin___memset_chk
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|,
literal|32
argument_list|,
name|__builtin_object_size
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

