begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'a: 2\*f(9)'
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'b: 2\*9\*g'
end_comment

begin_define
define|#
directive|define
name|f
parameter_list|(
name|a
parameter_list|)
value|a*g
end_define

begin_define
define|#
directive|define
name|g
value|f
end_define

begin_label
name|a
label|:
end_label

begin_macro
name|f
argument_list|(
literal|2
argument_list|)
end_macro

begin_expr_stmt
operator|(
literal|9
operator|)
undef|#
directive|undef
name|f
undef|#
directive|undef
name|g
define|#
directive|define
name|f
parameter_list|(
name|a
parameter_list|)
value|a*g
define|#
directive|define
name|g
parameter_list|(
name|a
parameter_list|)
value|f(a)
name|b
operator|:
name|f
argument_list|(
literal|2
argument_list|)
operator|(
literal|9
operator|)
end_expr_stmt

end_unit

