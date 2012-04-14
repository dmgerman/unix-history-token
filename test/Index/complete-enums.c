begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|deprecated
operator|)
argument_list|)
name|Color
block|{
name|Color_Red
operator|=
literal|17
operator|,
name|Color_Green
operator|,
name|Color_Blue
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|Greeby
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|(
name|enum
name|Color
name|color
parameter_list|)
block|{
switch|switch
condition|(
name|color
condition|)
block|{
case|case
name|Red
case|:
block|}
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:11:1 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: EnumConstantDecl:{ResultType enum Color}{TypedText Color_Red} (65) (deprecated)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:12:8 %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: EnumConstantDecl:{ResultType enum Color}{TypedText Color_Blue} (7) (deprecated)
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: EnumConstantDecl:{ResultType enum Color}{TypedText Color_Green} (7) (deprecated)
end_comment

begin_comment
comment|// CHECK-CC2-NEXT: EnumConstantDecl:{ResultType enum Color}{TypedText Color_Red} (7) (deprecated)
end_comment

end_unit

