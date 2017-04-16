begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|Outer
parameter_list|(
name|action
parameter_list|)
value|action
end_define

begin_function
name|void
name|completeParam
parameter_list|(
name|int
name|param
parameter_list|)
block|{
empty_stmt|;
name|Outer
argument_list|(
name|__extension__
argument_list|(
block|{
name|_Pragma
argument_list|(
literal|"clang diagnostic push"
argument_list|)
block|}
argument_list|)
argument_list|)
expr_stmt|;
name|param
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:7:1 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: param : [#int#]param
end_comment

begin_function
name|void
name|completeParamPragmaError
parameter_list|(
name|int
name|param
parameter_list|)
block|{
name|Outer
argument_list|(
name|__extension__
argument_list|(
block|{
name|_Pragma
argument_list|(
literal|2
argument_list|)
block|}
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{_Pragma takes a parenthesized string literal}}
name|param
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -code-completion-at=%s:16:1 %s | FileCheck %s
end_comment

end_unit

