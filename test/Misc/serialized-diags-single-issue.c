begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|// RUN: %clang -Wall -fsyntax-only %s --serialize-diagnostics %t
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// NOTE: it is important that this test case only contain a single issue.  This test case checks
end_comment

begin_comment
comment|// if we can handle serialized diagnostics that contain only one diagnostic.
end_comment

begin_comment
comment|// CHECK: {{.*}}serialized-diags-single-issue.c:3:12: warning: variable 'voodoo' is uninitialized when used here [-Wuninitialized] [Semantic Issue]
end_comment

begin_comment
comment|// CHECK: Range: {{.*}}serialized-diags-single-issue.c:3:12 {{.*}}serialized-diags-single-issue.c:3:18
end_comment

begin_comment
comment|// CHECK: +-{{.*}}serialized-diags-single-issue.c:2:13: note: initialize the variable 'voodoo' to silence this warning []
end_comment

begin_comment
comment|// CHECK: +-Range: {{.*}}serialized-diags-single-issue.c:2:13 {{.*}}serialized-diags-single-issue.c:2:13
end_comment

begin_comment
comment|// CHECK: +-FIXIT: ({{.*}}serialized-diags-single-issue.c:2:13 - {{.*}}serialized-diags-single-issue.c:2:13): " = 0"
end_comment

begin_comment
comment|// Test that we handle serializing diagnostics for multiple source files
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wall -fsyntax-only %s %s -serialize-diagnostic-file %t
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t 2>&1 | FileCheck -check-prefix=CHECK-MULT %s
end_comment

begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// CHECK-MULT: {{.*}}serialized-diags-single-issue.c:3:12: warning: variable 'voodoo' is uninitialized when used here [-Wuninitialized]
end_comment

begin_comment
comment|// CHECK-MULT: Range: {{.*}}serialized-diags-single-issue.c:3:12 {{.*}}serialized-diags-single-issue.c:3:18
end_comment

begin_comment
comment|// CHECK-MULT: +-{{.*}}serialized-diags-single-issue.c:2:13: note: initialize the variable 'voodoo' to silence this warning []
end_comment

begin_comment
comment|// CHECK-MULT: +-Range: {{.*}}serialized-diags-single-issue.c:2:13 {{.*}}serialized-diags-single-issue.c:2:13
end_comment

begin_comment
comment|// CHECK-MULT: +-FIXIT: ({{.*}}serialized-diags-single-issue.c:2:13 - {{.*}}serialized-diags-single-issue.c:2:13): " = 0"
end_comment

begin_comment
comment|// CHECK-MULT: {{.*}}serialized-diags-single-issue.c:3:12: warning: variable 'voodoo' is uninitialized when used here [-Wuninitialized]
end_comment

begin_comment
comment|// CHECK-MULT: Range: {{.*}}serialized-diags-single-issue.c:3:12 {{.*}}serialized-diags-single-issue.c:3:18
end_comment

begin_comment
comment|// CHECK-MULT: +-{{.*}}serialized-diags-single-issue.c:2:13: note: initialize the variable 'voodoo' to silence this warning []
end_comment

begin_comment
comment|// CHECK-MULT: +-Range: {{.*}}serialized-diags-single-issue.c:2:13 {{.*}}serialized-diags-single-issue.c:2:13
end_comment

begin_comment
comment|// CHECK-MULT: +-FIXIT: ({{.*}}serialized-diags-single-issue.c:2:13 - {{.*}}serialized-diags-single-issue.c:2:13): " = 0"
end_comment

begin_comment
comment|// CHECK-MULT: Number of diagnostics: 2
end_comment

end_unit

