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

begin_define
define|#
directive|define
name|nil
value|0
end_define

begin_function
name|void
name|f
parameter_list|()
block|{  }
end_function

begin_function_decl
name|void
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f2
parameter_list|()
block|{
name|int
modifier|*
name|ip
init|=
name|nil
decl_stmt|;
name|ip
operator|=
name|nil
expr_stmt|;
name|g
argument_list|(
name|nil
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:7:1 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:7:1 %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: macro definition:{TypedText FOO}{LeftParen (}{Placeholder Arg1}{Comma , }{Placeholder Arg2}{RightParen )}
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:13:13 %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:14:8 %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:14:8 %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: macro definition:{TypedText nil} (32)
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:15:5 %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_CACHING=1 c-index-test -code-completion-at=%s:15:5 %s | FileCheck -check-prefix=CHECK-CC3 %s
end_comment

begin_comment
comment|// CHECK-CC3: macro definition:{TypedText nil} (65)
end_comment

end_unit

