begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | FileCheck --strict-whitespace --match-full-lines %s
end_comment

begin_comment
comment|// In the following tests, note that the output is sensitive to the
end_comment

begin_comment
comment|// whitespace *preceeding* the varargs argument, as well as to
end_comment

begin_comment
comment|// interior whitespace. AFAIK, this is the only case where whitespace
end_comment

begin_comment
comment|// preceeding an argument matters, and might be considered a bug in
end_comment

begin_comment
comment|// GCC. Nevertheless, since this feature is a GCC extension in the
end_comment

begin_comment
comment|// first place, we'll follow along.
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

begin_comment
comment|// CHECK:V);
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK:W,1, 2);
end_comment

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

begin_comment
comment|// CHECK:X, 1, 2);
end_comment

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

begin_comment
comment|// CHECK:Y,);
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|Y
argument_list|, )
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK:Z,);
end_comment

begin_expr_stmt
name|debug
argument_list|(
name|Z
argument_list|,)
expr_stmt|;
end_expr_stmt

end_unit

