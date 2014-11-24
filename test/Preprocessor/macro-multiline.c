begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: printf -- "-DX=A\nTHIS_SHOULD_NOT_EXIST_IN_THE_OUTPUT" | xargs -0 %clang -E %s | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// Per GCC -D semantics, \n and anything that follows is ignored.
end_comment

begin_comment
comment|// CHECK: {{^START A END$}}
end_comment

begin_expr_stmt
name|START
name|X
name|END
end_expr_stmt

end_unit

