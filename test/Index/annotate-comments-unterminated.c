begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-ERR %s
end_comment

begin_comment
comment|// CHECK: annotate-comments-unterminated.c:9:5: VarDecl=x:{{.*}} RawComment=[/** Aaa. */]{{.*}} BriefComment=[Aaa.]
end_comment

begin_comment
comment|// CHECK: annotate-comments-unterminated.c:11:5: VarDecl=y:{{.*}} RawComment=[/**< Bbb. */]{{.*}} BriefComment=[Bbb.]
end_comment

begin_comment
comment|// CHECK-ERR: error: unterminated
end_comment

begin_comment
comment|/** Aaa. */
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**< Bbb. */
end_comment

begin_comment
comment|/**< Ccc.  * Ddd.
end_comment

end_unit

