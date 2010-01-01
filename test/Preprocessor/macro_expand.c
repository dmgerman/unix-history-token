begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^A: Y$'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^B: f()$'
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^C: for()$'
end_comment

begin_define
define|#
directive|define
name|X
parameter_list|()
value|Y
end_define

begin_define
define|#
directive|define
name|Y
parameter_list|()
value|X
end_define

begin_label
name|A
label|:
end_label

begin_macro
name|X
argument_list|()
end_macro

begin_expr_stmt
operator|(
operator|)
operator|(
operator|)
comment|// PR3927
define|#
directive|define
name|f
parameter_list|(
name|x
parameter_list|)
value|h(x
define|#
directive|define
name|for
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
value|x()
name|B
operator|:
name|f
argument_list|(
name|f
argument_list|)
end_expr_stmt

begin_label
unit|)
name|C
label|:
end_label

begin_for
for|for
control|(for
control|)
end_for

begin_comment
unit|)
comment|// rdar://6880648
end_comment

begin_define
define|#
directive|define
name|f
parameter_list|(
name|x
parameter_list|,
name|y
modifier|...
parameter_list|)
value|y
end_define

begin_macro
name|f
argument_list|()
end_macro

end_unit

