begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// RUN: %clang -Wall -fsyntax-only %s --serialize-diagnostics %t
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm -f  %t
end_comment

begin_comment
comment|// NOTE: it is important that this test case contains no issues.  It tests
end_comment

begin_comment
comment|// that serialize diagnostics work in the absence of any issues.
end_comment

begin_comment
comment|// CHECK: Number of diagnostics: 0
end_comment

end_unit

