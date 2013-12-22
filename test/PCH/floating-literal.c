begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x ast -ast-print %t | FileCheck %s
end_comment

begin_comment
comment|// Make sure the semantics of FloatingLiterals are stored correctly in
end_comment

begin_comment
comment|// the AST. Previously, the ASTWriter didn't store anything and the
end_comment

begin_comment
comment|// reader assumed PPC 128-bit float semantics, which is incorrect for
end_comment

begin_comment
comment|// targets with 128-bit IEEE long doubles.
end_comment

begin_decl_stmt
name|long
name|double
name|foo
init|=
literal|1.0E4000L
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: long double foo = 1.00000000000000000000000000000000004E+4000L;
end_comment

begin_comment
comment|// Just as well check the others are still sane while we're here...
end_comment

begin_decl_stmt
name|double
name|bar
init|=
literal|1.0E300
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: double bar = 1.0000000000000001E+300;
end_comment

begin_decl_stmt
name|float
name|wibble
init|=
literal|1.0E40
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: float wibble = 1.0E+40;
end_comment

end_unit

