begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|PATHSIZE
value|256
end_define

begin_decl_stmt
specifier|static
specifier|const
name|int
name|len
init|=
literal|1234
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|char
name|arr
index|[
end_function

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-macros -code-completion-at=%s:6:12 %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: COMPLETION: len
end_comment

begin_comment
comment|// CHECK: COMPLETION: PATHSIZE
end_comment

end_unit

