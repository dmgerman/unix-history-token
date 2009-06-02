begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm-bc -o - %s
end_comment

begin_comment
comment|// PR3869
end_comment

begin_function
name|int
name|a
parameter_list|(
name|long
name|long
name|b
parameter_list|)
block|{
goto|goto *
name|b
goto|;
block|}
end_function

end_unit

