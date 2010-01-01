begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '1: aaab 2'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '2: 2 baaa'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '3: 2 xx'
end_comment

begin_define
define|#
directive|define
name|a
parameter_list|(
name|n
parameter_list|)
value|aaa ## n
end_define

begin_define
define|#
directive|define
name|b
value|2
end_define

begin_expr_stmt
literal|1
operator|:
name|a
argument_list|(
argument|b b
argument_list|)
comment|// aaab 2    2 gets expanded, not b.
undef|#
directive|undef
name|a
undef|#
directive|undef
name|b
define|#
directive|define
name|a
parameter_list|(
name|n
parameter_list|)
value|n ## aaa
define|#
directive|define
name|b
value|2
literal|2
operator|:
name|a
argument_list|(
argument|b b
argument_list|)
comment|// 2 baaa    2 gets expanded, not b.
define|#
directive|define
name|baaa
value|xx
literal|3
operator|:
name|a
argument_list|(
argument|b b
argument_list|)
end_expr_stmt

begin_comment
comment|// 2 xx
end_comment

end_unit

