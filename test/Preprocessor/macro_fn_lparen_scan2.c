begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'FUNC (3 +1);'
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|FUNC
parameter_list|(
name|a
parameter_list|)
value|(a+1)
end_define

begin_macro
name|F
argument_list|(
argument|FUNC
argument_list|)
end_macro

begin_expr_stmt
name|FUNC
argument_list|(
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* final token sequence is FUNC(3+1) */
end_comment

end_unit

