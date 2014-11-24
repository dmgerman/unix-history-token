begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|// CHECK: define void @f1(i32 signext %x) [[NUW:#[0-9]+]]
end_comment

begin_function
name|void
name|f2
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|// CHECK: define void @f2(i32 zeroext %x) [[NUW]]
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i32 @f3() [[NUW]]
end_comment

begin_function
name|unsigned
name|int
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define zeroext i32 @f4() [[NUW]]
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

end_unit

