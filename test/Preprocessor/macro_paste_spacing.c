begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep "^xy$"
end_comment

begin_define
define|#
directive|define
name|A
value|x ## y
end_define

begin_expr_stmt
name|blah
name|A
end_expr_stmt

end_unit

