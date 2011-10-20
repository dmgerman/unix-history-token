begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/Inputs/chain-decls1.h -include %S/Inputs/chain-decls2.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t1 %S/Inputs/chain-decls1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t2 %S/Inputs/chain-decls2.h -include-pch %t1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t2 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-print -include-pch %t2 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: void f();
end_comment

begin_comment
comment|// CHECK: void g();
end_comment

begin_function
name|int
name|h
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
name|g
argument_list|()
expr_stmt|;
name|struct
name|one
name|x
decl_stmt|;
name|one
argument_list|()
expr_stmt|;
name|struct
name|two
name|y
decl_stmt|;
name|two
argument_list|()
expr_stmt|;
name|struct
name|three
name|z
decl_stmt|;
name|many
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|struct
name|many
name|m
decl_stmt|;
name|noret
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

