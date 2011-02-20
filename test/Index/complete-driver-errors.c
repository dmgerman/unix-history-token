begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
modifier|*
name|blah
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_macro
name|int
end_macro

begin_comment
comment|// CHECK-RESULTS: NotImplemented:{TypedText const} (40)
end_comment

begin_comment
comment|// CHECK-RESULTS: NotImplemented:{TypedText restrict} (40)
end_comment

begin_comment
comment|// CHECK-RESULTS: NotImplemented:{TypedText volatile} (40)
end_comment

begin_comment
comment|// CHECK-DIAGS: error: invalid value '' in '-std='
end_comment

begin_comment
comment|// CHECK-DIAGS: complete-driver-errors.c:1:6:{1:13-1:14}: warning: incompatible integer to pointer conversion initializing 'int *' with an expression of type 'int'
end_comment

begin_comment
comment|// Test driver errors with code completion
end_comment

begin_comment
comment|// RUN: c-index-test -code-completion-at=%s:4:1 -std= %s 2> %t | FileCheck -check-prefix=CHECK-RESULTS %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DIAGS %s< %t
end_comment

begin_comment
comment|// Test driver errors with parsing
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all -std= %s 2> %t | FileCheck -check-prefix=CHECK-LOAD %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DIAGS %s< %t
end_comment

begin_comment
comment|// CHECK-LOAD: complete-driver-errors.c:1:6: VarDecl=blah:1:6
end_comment

begin_comment
comment|// Test driver errors with code completion and precompiled preamble
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -code-completion-at=%s:4:1 -std= %s 2> %t | FileCheck -check-prefix=CHECK-RESULTS %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DIAGS %s< %t
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source all -std= %s 2> %t | FileCheck -check-prefix=CHECK-LOAD %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-DIAGS %s< %t
end_comment

end_unit

