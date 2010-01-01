begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:1:12 -remap-file="%s;%S/Inputs/remap-complete-to.c" %s | FileCheck %s
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_comment
comment|// CHECK: FunctionDecl:{ResultType void}{TypedText f0}{LeftParen (}{RightParen )}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

end_unit

