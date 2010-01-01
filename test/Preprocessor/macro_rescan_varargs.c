begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|LPAREN
value|(
end_define

begin_define
define|#
directive|define
name|RPAREN
value|)
end_define

begin_define
define|#
directive|define
name|F
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x + y
end_define

begin_define
define|#
directive|define
name|ELLIP_FUNC
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
end_define

begin_expr_stmt
literal|1
operator|:
name|ELLIP_FUNC
argument_list|(
name|F
argument_list|,
name|LPAREN
argument_list|,
literal|'a'
argument_list|,
literal|'b'
argument_list|,
name|RPAREN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 1st invocation */
end_comment

begin_expr_stmt
literal|2
operator|:
name|ELLIP_FUNC
argument_list|(
argument|F LPAREN
literal|'a'
argument_list|,
literal|'b'
argument|RPAREN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 2nd invocation */
end_comment

begin_comment
comment|// CHECK: 1: F, (, 'a', 'b', );
end_comment

begin_comment
comment|// CHECK: 2: 'a' + 'b';
end_comment

end_unit

