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

begin_function
name|void
name|bar
parameter_list|()
block|{
name|int
name|dragon
decl_stmt|;
name|dragon
operator|=
name|dragon
operator|+
literal|1
block|}
end_function

begin_comment
comment|// Test handling of FixIts that only remove text.
end_comment

begin_function_decl
name|int
name|baz
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|qux
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
operator|(
name|x
operator|==
name|baz
argument_list|()
operator|)
condition|)
return|return;
block|}
end_function

begin_comment
comment|// Test handling of macros.
end_comment

begin_function_decl
name|void
name|taz
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_function
name|void
name|testMacro
parameter_list|()
block|{
name|taz
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test handling of issues from #includes.
end_comment

begin_include
include|#
directive|include
file|"serialized-diags.h"
end_include

begin_comment
comment|// Test handling of warnings that have empty fixits.
end_comment

begin_function
name|void
name|rdar11040133
parameter_list|()
block|{
name|unsigned
name|x
decl_stmt|;
block|}
end_function

begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang -Wall -fsyntax-only %s --serialize-diagnostics %t.diag> /dev/null 2>&1 || true
end_comment

begin_comment
comment|// RUN: c-index-test -read-diagnostics %t.diag> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// This test case tests that we can handle multiple diagnostics which contain
end_comment

begin_comment
comment|// FIXITs at different levels (one at the note, another at the main diagnostic).
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.c:3:12: warning: variable 'voodoo' is uninitialized when used here [-Wuninitialized]
end_comment

begin_comment
comment|// CHECK: Range: {{.*[/\\]}}serialized-diags.c:3:12 {{.*[/\\]}}serialized-diags.c:3:18
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:2:13: note: initialize the variable 'voodoo' to silence this warning []
end_comment

begin_comment
comment|// CHECK: +-FIXIT: ({{.*[/\\]}}serialized-diags.c:2:13 - {{.*[/\\]}}serialized-diags.c:2:13): " = 0"
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.c:8:22: error: expected ';' after expression []
end_comment

begin_comment
comment|// CHECK: FIXIT: ({{.*[/\\]}}serialized-diags.c:8:22 - {{.*[/\\]}}serialized-diags.c:8:22): ";"
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.c:14:10: warning: equality comparison with extraneous parentheses [-Wparentheses-equality]
end_comment

begin_comment
comment|// CHECK: Range: {{.*[/\\]}}serialized-diags.c:14:8 {{.*[/\\]}}serialized-diags.c:14:18
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:14:10: note: remove extraneous parentheses around the comparison to silence this warning []
end_comment

begin_comment
comment|// CHECK: +-FIXIT: ({{.*[/\\]}}serialized-diags.c:14:7 - {{.*[/\\]}}serialized-diags.c:14:8): ""
end_comment

begin_comment
comment|// CHECK: +-FIXIT: ({{.*[/\\]}}serialized-diags.c:14:18 - {{.*[/\\]}}serialized-diags.c:14:19): ""
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:14:10: note: use '=' to turn this equality comparison into an assignment []
end_comment

begin_comment
comment|// CHECK: +-FIXIT: ({{.*[/\\]}}serialized-diags.c:14:10 - {{.*[/\\]}}serialized-diags.c:14:12): "="
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.c:22:13: error: too many arguments to function call, expected 2, have 3 []
end_comment

begin_comment
comment|// CHECK: Range: {{.*[/\\]}}serialized-diags.c:22:3 {{.*[/\\]}}serialized-diags.c:22:6
end_comment

begin_comment
comment|// CHECK: Range: {{.*[/\\]}}serialized-diags.c:22:13 {{.*[/\\]}}serialized-diags.c:22:18
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:20:15: note: expanded from macro 'false' []
end_comment

begin_comment
comment|// CHECK: +-Range: {{.*[/\\]}}serialized-diags.c:22:3 {{.*[/\\]}}serialized-diags.c:22:6
end_comment

begin_comment
comment|// CHECK: +-Range: {{.*[/\\]}}serialized-diags.c:20:15 {{.*[/\\]}}serialized-diags.c:20:16
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:19:1: note: 'taz' declared here []
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.h:5:7: warning: incompatible integer to pointer conversion initializing 'char *' with an expression of type 'int' [-Wint-conversion]
end_comment

begin_comment
comment|// CHECK: Range: {{.*[/\\]}}serialized-diags.h:5:16 {{.*[/\\]}}serialized-diags.h:5:17
end_comment

begin_comment
comment|// CHECK: +-{{.*[/\\]}}serialized-diags.c:26:10: note: in file included from {{.*[/\\]}}serialized-diags.c:26: []
end_comment

begin_comment
comment|// CHECK: Number FIXITs = 0
end_comment

begin_comment
comment|// CHECK: {{.*[/\\]}}serialized-diags.c:30:12: warning: unused variable 'x'
end_comment

begin_comment
comment|// CHECK: Number FIXITs = 0
end_comment

begin_comment
comment|// CHECK: Number of diagnostics: 6
end_comment

end_unit

