begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_error
error|#
directive|error
error|foo
end_error

begin_error
error|#
directive|error
error|bar
end_error

begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang -ferror-limit=1 -fsyntax-only %s --serialize-diagnostics %t> /dev/null 2>&1 || true
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// This test case tests that we can handle both fatal errors and errors without categories.
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags-no-category.c:1:2: error: foo []
end_comment

begin_comment
comment|// CHECK: Number of diagnostics: 2
end_comment

end_unit

