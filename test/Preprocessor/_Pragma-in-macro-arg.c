begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -Wconversion
end_comment

begin_comment
comment|// Don't crash (rdar://11168596)
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|desc
parameter_list|)
value|_Pragma("clang diagnostic push")  _Pragma("clang diagnostic ignored \"-Wparentheses\"") _Pragma("clang diagnostic pop")
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|desc
parameter_list|)
value|A(desc)
end_define

begin_macro
name|B
argument_list|(
argument|_Pragma(
literal|"clang diagnostic ignored \"-Wparentheses\""
argument|)
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EMPTY
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INACTIVE
parameter_list|(
name|x
parameter_list|)
value|EMPTY(x)
end_define

begin_define
define|#
directive|define
name|ID
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|ACTIVE
parameter_list|(
name|x
parameter_list|)
value|ID(x)
end_define

begin_comment
comment|// This should be ignored..
end_comment

begin_macro
name|INACTIVE
argument_list|(
argument|_Pragma(
literal|"clang diagnostic ignored \"-Wconversion\""
argument|)
argument_list|)
end_macro

begin_define
define|#
directive|define
name|IGNORE_CONV
value|_Pragma("clang diagnostic ignored \"-Wconversion\"") _Pragma("clang diagnostic ignored \"-Wconversion\"")
end_define

begin_comment
comment|// ..as should this.
end_comment

begin_macro
name|INACTIVE
argument_list|(
argument|IGNORE_CONV
argument_list|)
end_macro

begin_define
define|#
directive|define
name|IGNORE_POPPUSH
parameter_list|(
name|Pop
parameter_list|,
name|Push
parameter_list|,
name|W
parameter_list|,
name|D
parameter_list|)
value|Push W D Pop
end_define

begin_macro
name|IGNORE_POPPUSH
argument_list|(
argument|_Pragma(
literal|"clang diagnostic pop"
argument|)
argument_list|,
argument|_Pragma(
literal|"clang diagnostic push"
argument|)
argument_list|,
argument|_Pragma(
literal|"clang diagnostic ignored \"-Wconversion\""
argument|)
argument_list|,
argument|int q = (double)
literal|1.0
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|x1
init|=
operator|(
name|double
operator|)
literal|1.0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{implicit conversion}}
end_comment

begin_expr_stmt
name|ACTIVE
argument_list|(
name|_Pragma
argument_list|)
argument_list|(
literal|"clang diagnostic ignored \"-Wconversion\""
argument_list|)
end_expr_stmt

begin_comment
unit|)
comment|// expected-error {{_Pragma takes a parenthesized string literal}} \
end_comment

begin_expr_stmt
name|expected
operator|-
name|error
block|{
block|{
name|expected
name|identifier
name|or
literal|'('
block|}
block|}
name|expected
operator|-
name|error
block|{
block|{
name|expected
literal|')'
block|}
block|}
name|expected
operator|-
name|note
block|{
block|{
name|to
name|match
name|this
literal|'('
block|}
block|}
comment|// This should disable the warning.
name|ACTIVE
argument_list|(
argument|IGNORE_CONV
argument_list|)
name|int
name|x2
operator|=
operator|(
name|double
operator|)
literal|1.0
expr_stmt|;
end_expr_stmt

end_unit

