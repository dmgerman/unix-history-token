begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep '! ,'
end_comment

begin_define
define|#
directive|define
name|XX
end_define

begin_expr_stmt
operator|!
name|XX
operator|,
end_expr_stmt

end_unit

