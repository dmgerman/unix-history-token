begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | grep 'bar foo (2)'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep 'm(ABCD)'
end_comment

begin_define
define|#
directive|define
name|foo
parameter_list|(
name|x
parameter_list|)
value|bar x
end_define

begin_macro
name|foo
argument_list|(
argument|foo
argument_list|)
end_macro

begin_expr_stmt
operator|(
literal|2
operator|)
define|#
directive|define
name|m
parameter_list|(
name|a
parameter_list|)
value|a(w)
define|#
directive|define
name|w
value|ABCD
name|m
argument_list|(
argument|m
argument_list|)
end_expr_stmt

begin_comment
comment|// m(ABCD)
end_comment

end_unit

