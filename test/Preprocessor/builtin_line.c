begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | grep "^  4"
end_comment

begin_define
define|#
directive|define
name|FOO
value|__LINE__
end_define

begin_expr_stmt
name|FOO
comment|// PR3579 - This should expand to the __LINE__ of the ')' not of the X.
comment|// RUN: clang-cc %s -E | grep "^A 13"
define|#
directive|define
name|X
parameter_list|()
value|__LINE__
name|A
name|X
argument_list|(  )
end_expr_stmt

end_unit

