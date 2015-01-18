begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the driver correctly combines its own diagnostics with CC1's in the
end_comment

begin_comment
comment|// serialized diagnostics. To test this, we need to trigger diagnostics from
end_comment

begin_comment
comment|// both processes, so we compile code that has a warning (with an associated
end_comment

begin_comment
comment|// note) and then force the driver to crash. We compile stdin so that the crash
end_comment

begin_comment
comment|// doesn't litter the user's system with preprocessed output.
end_comment

begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang -Wx-unknown-warning -Wall -fsyntax-only --serialize-diagnostics %t.diag %s
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t.diag 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: warning: unknown warning option '-Wx-unknown-warning' [-Wunknown-warning-option] []
end_comment

begin_comment
comment|// CHECK: warning: variable 'voodoo' is uninitialized when used here [-Wuninitialized]
end_comment

begin_comment
comment|// CHECK: note: initialize the variable 'voodoo' to silence this warning []
end_comment

begin_comment
comment|// CHECK: Number of diagnostics: 2
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|voodoo
decl_stmt|;
name|voodoo
operator|=
name|voodoo
operator|+
literal|1
expr_stmt|;
block|}
end_function

end_unit

