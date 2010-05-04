begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Checks folding of an unordered comparison
end_comment

begin_function
name|int
name|nan_ne_check
parameter_list|()
block|{
comment|// CHECK: store i32 1
return|return
operator|(
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
operator|!=
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
operator|)
condition|?
literal|1
else|:
literal|0
return|;
block|}
end_function

end_unit

