begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | grep 'V);'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep 'W, 1, 2);'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep 'X, 1, 2);'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep 'Y, );'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E | grep 'Z, );'
end_comment

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|format
parameter_list|,
modifier|...
parameter_list|)
value|format, ## __VA_ARGS__)
end_define

begin_expr_stmt
name|debug
argument_list|(
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|W
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|X
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|Y
argument_list|, )
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|debug
argument_list|(
name|Z
argument_list|,)
expr_stmt|;
end_expr_stmt

end_unit

