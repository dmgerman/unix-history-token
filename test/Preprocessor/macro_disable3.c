begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// Check for C99 6.10.3.4p2.
end_comment

begin_define
define|#
directive|define
name|f
parameter_list|(
name|a
parameter_list|)
value|f(x * (a))
end_define

begin_define
define|#
directive|define
name|x
value|2
end_define

begin_define
define|#
directive|define
name|z
value|z[0]
end_define

begin_expr_stmt
name|f
argument_list|(
name|f
argument_list|(
name|z
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: f(2 * (f(2 * (z[0]))));
end_comment

end_unit

