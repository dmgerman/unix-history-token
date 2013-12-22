begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386 -emit-llvm -O2 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f0()
end_comment

begin_comment
comment|// CHECK:  ret i32 1
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
specifier|static
name|_Bool
name|f0_0
parameter_list|(
name|void
modifier|*
name|a0
parameter_list|)
block|{
return|return
operator|(
name|_Bool
operator|)
name|a0
return|;
block|}
end_function

begin_function
name|int
name|f0
parameter_list|()
block|{
return|return
name|f0_0
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x2
argument_list|)
return|;
block|}
end_function

begin_function
name|_Bool
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_Bool
operator|)
operator|(
block|{
name|void
argument_list|(
operator|*
name|x
argument_list|)
argument_list|()
block|;
name|x
operator|=
literal|0
block|; }
operator|)
return|;
block|}
end_function

end_unit

