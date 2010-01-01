begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// __COUNTER__ support: rdar://4329310
end_comment

begin_comment
comment|// RUN: %clang -E %s> %t
end_comment

begin_define
define|#
directive|define
name|PASTE2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x##y
end_define

begin_define
define|#
directive|define
name|PASTE1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|PASTE2(x,y)
end_define

begin_define
define|#
directive|define
name|UNIQUE
parameter_list|(
name|x
parameter_list|)
value|PASTE1(x,__COUNTER__)
end_define

begin_comment
comment|// RUN: grep "A: 0" %t
end_comment

begin_label
name|A
label|:
end_label

begin_decl_stmt
name|__COUNTER__
comment|// RUN: grep "B: foo1" %t
name|B
range|:
name|UNIQUE
argument_list|(
name|foo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: grep "C: foo2" %t
end_comment

begin_label
name|C
label|:
end_label

begin_expr_stmt
name|UNIQUE
argument_list|(
name|foo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// RUN: grep "D: 3" %t
end_comment

begin_label
name|D
label|:
end_label

begin_macro
name|__COUNTER__
end_macro

end_unit

