begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

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
comment|// RUN: c-index-test -code-completion-at=%s:7:4 %s | FileCheck -check-prefix=CHECK-IF-ELSE %s
end_comment

begin_comment
comment|// CHECK-IF-ELSE: NotImplemented:{TypedText else}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)
end_comment

begin_comment
comment|// CHECK-IF-ELSE: NotImplemented:{TypedText else}{HorizontalSpace  }{Text if}{HorizontalSpace  }{LeftParen (}{Placeholder expression}{RightParen )}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)
end_comment

end_unit

