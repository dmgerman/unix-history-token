begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^3 ;$'
end_comment

begin_comment
comment|/* Right paren scanning, hard case.  Should expand to 3. */
end_comment

begin_define
define|#
directive|define
name|i
parameter_list|(
name|x
parameter_list|)
value|3
end_define

begin_define
define|#
directive|define
name|a
value|i(yz
end_define

begin_define
define|#
directive|define
name|b
value|)
end_define

begin_expr_stmt
name|a
name|b
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

