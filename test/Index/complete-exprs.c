begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|j
parameter_list|,
name|int
name|k
parameter_list|,
name|int
name|l
parameter_list|)
block|{
return|return
name|i
operator||
name|j
operator||
name|k
operator|&
name|l
return|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:9 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: FunctionDecl:{ResultType int}{TypedText f}{LeftParen (}{Placeholder int}{RightParen )}
end_comment

begin_comment
comment|// CHECK-CC1: NotImplemented:{TypedText sizeof}{LeftParen (}{Placeholder expression-or-type}{RightParen )}
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:14 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:18 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:22 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

end_unit

