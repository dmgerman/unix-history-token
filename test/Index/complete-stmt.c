begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_typedef
typedef|typedef
name|int
name|Integer
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
condition|)
block|{   }
block|}
end_function

begin_comment
comment|// RUN: env CINDEXTEST_CODE_COMPLETE_PATTERNS=1 c-index-test -code-completion-at=%s:7:4 %s | FileCheck -check-prefix=CHECK-IF-ELSE %s
end_comment

begin_comment
comment|// CHECK-IF-ELSE: NotImplemented:{TypedText else}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)
end_comment

begin_comment
comment|// CHECK-IF-ELSE: NotImplemented:{TypedText else}{HorizontalSpace  }{Text if}{HorizontalSpace  }{LeftParen (}{Placeholder expression}{RightParen )}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:4 %s | FileCheck -check-prefix=CHECK-IF-ELSE-SIMPLE %s
end_comment

begin_comment
comment|// CHECK-IF-ELSE-SIMPLE: NotImplemented:{TypedText else} (40)
end_comment

begin_comment
comment|// CHECK-IF-ELSE-SIMPLE: NotImplemented:{TypedText else}{HorizontalSpace  }{Text if}{HorizontalSpace  }{LeftParen (}{Placeholder expression}{RightParen )} (40)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:6:1 %s | FileCheck -check-prefix=CHECK-STMT %s
end_comment

begin_comment
comment|// CHECK-STMT: NotImplemented:{TypedText char} (50)
end_comment

begin_comment
comment|// CHECK-STMT: NotImplemented:{TypedText const} (50)
end_comment

begin_comment
comment|// CHECK-STMT: NotImplemented:{TypedText double} (50)
end_comment

begin_comment
comment|// CHECK-STMT: NotImplemented:{TypedText enum} (50)
end_comment

begin_comment
comment|// CHECK-STMT: FunctionDecl:{ResultType void}{TypedText f}{LeftParen (}{Placeholder int x}{RightParen )} (50)
end_comment

begin_comment
comment|// CHECK-STMT: TypedefDecl:{TypedText Integer} (50)
end_comment

begin_comment
comment|// CHECK-STMT: ParmDecl:{ResultType int}{TypedText x} (34)
end_comment

end_unit

