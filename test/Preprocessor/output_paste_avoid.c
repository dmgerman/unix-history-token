begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E %s -o %t&&
end_comment

begin_comment
comment|// This should print as ".. ." to avoid turning into ...
end_comment

begin_comment
comment|// RUN: grep -F 'A: . . .' %t&&
end_comment

begin_define
define|#
directive|define
name|y
parameter_list|(
name|a
parameter_list|)
value|..a
end_define

begin_label
name|A
label|:
end_label

begin_macro
name|y
argument_list|(
argument|.
argument_list|)
end_macro

begin_comment
comment|// RUN: grep -F 'C: .. .' %t&&
end_comment

begin_define
define|#
directive|define
name|DOT
value|.
end_define

begin_label
name|C
label|:
end_label

begin_expr_stmt
operator|..
name|DOT
comment|// RUN: grep -F 'D: + + - - + + = = =' %t&&
define|#
directive|define
name|PLUS
value|+
define|#
directive|define
name|EMPTY
define|#
directive|define
name|f
parameter_list|(
name|x
parameter_list|)
value|=x=
name|D
operator|:
operator|+
name|PLUS
operator|-
name|EMPTY
operator|-
name|PLUS
operator|+
name|f
argument_list|(
argument|=
argument_list|)
comment|// RUN: grep -F 'E: L "str"' %t
comment|// Should expand to L "str" not L"str"
define|#
directive|define
name|test
parameter_list|(
name|x
parameter_list|)
value|L#x
name|E
operator|:
name|test
argument_list|(
argument|str
argument_list|)
end_expr_stmt

end_unit

