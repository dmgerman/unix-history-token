begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Example from C99 6.10.3.4p5
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|x
value|3
end_define

begin_define
define|#
directive|define
name|f
parameter_list|(
name|a
parameter_list|)
value|f(x * (a))
end_define

begin_undef
undef|#
directive|undef
name|x
end_undef

begin_define
define|#
directive|define
name|x
value|2
end_define

begin_define
define|#
directive|define
name|g
value|f
end_define

begin_define
define|#
directive|define
name|z
value|z[0]
end_define

begin_define
define|#
directive|define
name|h
value|g(~
end_define

begin_define
define|#
directive|define
name|m
parameter_list|(
name|a
parameter_list|)
value|a(w)
end_define

begin_define
define|#
directive|define
name|w
value|0,1
end_define

begin_define
define|#
directive|define
name|t
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|p
parameter_list|()
value|int
end_define

begin_define
define|#
directive|define
name|q
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|r
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|str
parameter_list|(
name|x
parameter_list|)
value|# x
end_define

begin_expr_stmt
name|f
argument_list|(
name|y
operator|+
literal|1
argument_list|)
operator|+
name|f
argument_list|(
name|f
argument_list|(
name|z
argument_list|)
argument_list|)
operator|%
name|t
argument_list|(
name|t
argument_list|(
name|g
argument_list|)
argument_list|(
literal|0
argument_list|)
operator|+
name|t
argument_list|)
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|g
argument_list|(
name|x
operator|+
operator|(
literal|3
operator|,
literal|4
operator|)
operator|-
name|w
argument_list|)
operator||
name|h
literal|5
end_expr_stmt

begin_expr_stmt
unit|)
operator|&
name|m
argument_list|(
name|f
argument_list|)
operator|^
name|m
argument_list|(
name|m
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|p
argument_list|()
end_macro

begin_expr_stmt
name|i
index|[
name|q
argument_list|()
index|]
operator|=
block|{
name|q
argument_list|(
literal|1
argument_list|)
block|,
name|r
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
block|,
name|r
argument_list|(
literal|4
argument_list|,)
block|,
name|r
argument_list|(,
literal|5
argument_list|)
block|,
name|r
argument_list|(
argument_list|,)
block|}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|c
index|[
literal|2
index|]
index|[
literal|6
index|]
init|=
block|{
name|str
argument_list|(
name|hello
argument_list|)
block|,
name|str
argument_list|()
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: f(2 * (y+1)) + f(2 * (f(2 * (z[0])))) % f(2 * (0)) + t(1);
end_comment

begin_comment
comment|// CHECK: f(2 * (2 +(3,4)-0,1)) | f(2 * (~ 5))& f(2 * (0,1))^m(0,1);
end_comment

begin_comment
comment|// CHECK: int i[] = { 1, 23, 4, 5, };
end_comment

begin_comment
comment|// CHECK: char c[2][6] = { "hello", "" };
end_comment

end_unit

