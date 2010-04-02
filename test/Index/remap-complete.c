begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:6:2 -remap-file="%s;%S/Inputs/remap-complete-to.c" %s 2> %t.err | FileCheck %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DIAGS %s< %t.err
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_comment
comment|// CHECK: FunctionDecl:{ResultType int}{TypedText f0}{LeftParen (}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK-DIAGS: remap-complete.c:2:19
end_comment

end_unit

