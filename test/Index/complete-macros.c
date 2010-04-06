begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Note: the run lines follow their respective tests, since line/column
end_comment

begin_comment
comment|// matter in this test.
end_comment

begin_define
define|#
directive|define
name|FOO
parameter_list|(
name|Arg1
parameter_list|,
name|Arg2
parameter_list|)
value|foobar
end_define

begin_function
name|void
name|f
parameter_list|()
block|{  }
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:1 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: macro definition:{TypedText FOO}{LeftParen (}{Placeholder Arg1}{Comma , }{Placeholder Arg2}{RightParen )}
end_comment

end_unit

