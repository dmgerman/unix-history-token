begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -E -x c-header %s> %t
end_comment

begin_comment
comment|// RUN: grep 'B B' %t
end_comment

begin_define
define|#
directive|define
name|A
value|B
end_define

begin_expr_stmt
name|A
name|A
end_expr_stmt

end_unit

