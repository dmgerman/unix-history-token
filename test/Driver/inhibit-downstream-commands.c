begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -no-integrated-as %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: unknown type name 'invalid'
end_comment

begin_comment
comment|// CHECK-NOT: clang: error: assembler command failed
end_comment

begin_comment
comment|// CHECK-NOT: clang: error: linker command failed
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_expr_stmt
name|invalid
name|C
name|code
operator|!
end_expr_stmt

end_unit

