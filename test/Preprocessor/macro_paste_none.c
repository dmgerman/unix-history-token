begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '!!'
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|B
parameter_list|,
name|C
parameter_list|)
value|B ## C
end_define

begin_expr_stmt
operator|!
name|A
argument_list|(,)
operator|!
end_expr_stmt

end_unit

