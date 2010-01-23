begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_function_decl
name|void
name|f0
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|f0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|g0
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|f1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// RUN: %clang_cc1 -std=c89 -fsyntax-only -code-completion-at=%s:6:6 %s -o - | FileCheck -check-prefix=CC1 %s
comment|// CHECK-CC1: f0(<#float x#>, float y)
comment|// RUN: %clang_cc1 -std=c89 -fsyntax-only -code-completion-at=%s:6:9 %s -o - | FileCheck -check-prefix=CC2 %s
comment|// CHECK-CC2: f0(float x,<#float y#>)
comment|// RUN: %clang_cc1 -std=c89 -fsyntax-only -code-completion-at=%s:8:6 %s -o - | FileCheck -check-prefix=CC3 %s
comment|// CHECK-CC3: f1()
block|}
end_function

end_unit

