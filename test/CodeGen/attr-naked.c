begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.7.0 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(naked
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Basic functionality check
end_comment

begin_comment
comment|// (Note that naked needs to imply noinline to work properly.)
end_comment

begin_comment
comment|// CHECK: define void @t1() [[NAKED_OPTNONE:#[0-9]+]] {
end_comment

begin_function
name|void
name|t1
parameter_list|()
block|{ }
end_function

begin_comment
comment|// Make sure this doesn't explode in the verifier.
end_comment

begin_comment
comment|// (It doesn't really make sense, but it isn't invalid.)
end_comment

begin_comment
comment|// CHECK: define void @t2() [[NAKED:#[0-9]+]] {
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(naked, always_inline)
argument_list|)
end_macro

begin_function
name|void
name|t2
parameter_list|()
block|{ }
end_function

begin_comment
comment|// Make sure not to generate prolog or epilog for naked functions.
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|void
name|t3
parameter_list|(
name|int
name|x
parameter_list|)
block|{
comment|// CHECK: define void @t3(i32)
comment|// CHECK-NOT: alloca
comment|// CHECK-NOT: store
comment|// CHECK: unreachable
block|}
end_function

begin_comment
comment|// CHECK: attributes [[NAKED_OPTNONE]] = { naked noinline nounwind optnone{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NAKED]] = { naked noinline nounwind{{.*}} }
end_comment

end_unit

