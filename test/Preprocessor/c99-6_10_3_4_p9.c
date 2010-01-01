begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Example from C99 6.10.3.4p9
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|debug
parameter_list|(
modifier|...
parameter_list|)
value|fprintf(stderr, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|showlist
parameter_list|(
modifier|...
parameter_list|)
value|puts(#__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|report
parameter_list|(
name|test
parameter_list|,
modifier|...
parameter_list|)
value|((test)?puts(#test):\                            printf(__VA_ARGS__))
end_define

begin_expr_stmt
name|debug
argument_list|(
literal|"Flag"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: fprintf(stderr, "Flag");
end_comment

begin_expr_stmt
name|debug
argument_list|(
literal|"X = %d\n"
argument_list|,
name|x
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: fprintf(stderr, "X = %d\n", x);
end_comment

begin_macro
name|showlist
argument_list|(
argument|The first
argument_list|,
argument|second
argument_list|,
argument|and third items.
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: puts("The first, second, and third items.");
end_comment

begin_expr_stmt
name|report
argument_list|(
name|x
operator|>
name|y
argument_list|,
literal|"x is %d but y is %d"
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: ((x>y)?puts("x>y"): printf("x is %d but y is %d", x, y));
end_comment

end_unit

