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
comment|// CHECK: define void @t1() nounwind noinline naked {
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
comment|// CHECK: define void @t2() nounwind noinline naked {
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

end_unit

