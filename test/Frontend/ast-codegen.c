begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -emit-ast -o %t.ast %s&&
end_comment

begin_comment
comment|// RUN: clang -emit-llvm -S -o - %t.ast | FileCheck %s
end_comment

begin_comment
comment|// CHECK: module asm "foo"
end_comment

begin_asm
asm|__asm__("foo");
end_asm

begin_comment
comment|// CHECK: @g0 = common global i32 0, align 4
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: define i32 @f0()
end_comment

begin_function
name|int
name|f0
parameter_list|()
block|{ }
end_function

end_unit

