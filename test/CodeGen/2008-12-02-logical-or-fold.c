begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | grep "store i32 1"
end_comment

begin_comment
comment|// PR3150
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
return|return
literal|1
operator|||
literal|1
return|;
block|}
end_function

end_unit

