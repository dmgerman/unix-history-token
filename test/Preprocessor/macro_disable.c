begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s | grep 'a: 2 + M_0(3)(4)(5);'
end_comment

begin_comment
comment|// RUN: clang-cc -E %s | grep 'b: 4 + 4 + 3 + 2 + 1 + M_0(3)(2)(1);'
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

end_unit

