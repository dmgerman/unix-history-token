begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | FileCheck -strict-whitespace %s
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

begin_define
define|#
directive|define
name|A
value|A B C
end_define

begin_define
define|#
directive|define
name|B
value|B C A
end_define

begin_define
define|#
directive|define
name|C
value|C A B
end_define

begin_function
name|A
comment|// CHECK: A B C A B A C A B C A
comment|// PR1820
define|#
directive|define
name|i
parameter_list|(
name|x
parameter_list|)
value|h(x
define|#
directive|define
name|h
parameter_list|(
name|x
parameter_list|)
value|x(void)
specifier|extern
name|int
name|i
parameter_list|(
name|i
parameter_list|)
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: int i(void)
end_comment

begin_define
define|#
directive|define
name|M_0
parameter_list|(
name|x
parameter_list|)
value|M_ ## x
end_define

begin_define
define|#
directive|define
name|M_1
parameter_list|(
name|x
parameter_list|)
value|x + M_0(0)
end_define

begin_define
define|#
directive|define
name|M_2
parameter_list|(
name|x
parameter_list|)
value|x + M_1(1)
end_define

begin_define
define|#
directive|define
name|M_3
parameter_list|(
name|x
parameter_list|)
value|x + M_2(2)
end_define

begin_define
define|#
directive|define
name|M_4
parameter_list|(
name|x
parameter_list|)
value|x + M_3(3)
end_define

begin_define
define|#
directive|define
name|M_5
parameter_list|(
name|x
parameter_list|)
value|x + M_4(4)
end_define

begin_label
name|a
label|:
end_label

begin_expr_stmt
name|M_0
argument_list|(
literal|1
argument_list|)
argument_list|(
literal|2
argument_list|)
argument_list|(
literal|3
argument_list|)
argument_list|(
literal|4
argument_list|)
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|b
label|:
end_label

begin_expr_stmt
name|M_0
argument_list|(
literal|5
argument_list|)
argument_list|(
literal|4
argument_list|)
argument_list|(
literal|3
argument_list|)
argument_list|(
literal|2
argument_list|)
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: a: 2 + M_0(3)(4)(5);
end_comment

begin_comment
comment|// CHECK: b: 4 + 4 + 3 + 2 + 1 + M_0(3)(2)(1);
end_comment

begin_define
define|#
directive|define
name|n
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|l
value|m
end_define

begin_define
define|#
directive|define
name|m
value|l a
end_define

begin_label
name|c
label|:
end_label

begin_macro
name|n
argument_list|(
argument|m
argument_list|)
end_macro

begin_macro
name|X
end_macro

begin_comment
comment|// CHECK: c: m a X
end_comment

end_unit

