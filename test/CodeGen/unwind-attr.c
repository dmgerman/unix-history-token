begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -fexceptions -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck -check-prefix CHECK-NOEXC %s
end_comment

begin_function_decl
name|int
name|opaque
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:       define [[INT:i.*]] @test0() [[TF:#[0-9]+]] {
end_comment

begin_comment
comment|// CHECK-NOEXC: define [[INT:i.*]] @test0() [[NUW:#[0-9]+]] {
end_comment

begin_function
name|int
name|test0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|opaque
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/8087431>: locally infer nounwind at -O0
end_comment

begin_comment
comment|// CHECK:       define [[INT:i.*]] @test1() [[NUW:#[0-9]+]] {
end_comment

begin_comment
comment|// CHECK-NOEXC: define [[INT:i.*]] @test1() [[NUW]] {
end_comment

begin_function
name|int
name|test1
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
comment|//<rdar://problem/8283071>: not for weak functions
end_comment

begin_comment
comment|// CHECK:       define weak [[INT:i.*]] @test2() [[TF]] {
end_comment

begin_comment
comment|// CHECK-NOEXC: define weak [[INT:i.*]] @test2() [[NUW]] {
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function
name|int
name|test2
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
comment|// CHECK: attributes [[TF]] = { noinline optnone "{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK-NOEXC: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

end_unit

