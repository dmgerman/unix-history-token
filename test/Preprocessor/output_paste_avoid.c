begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s -o - | FileCheck -strict-whitespace %s
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
comment|// This should print as ".. ." to avoid turning into ...
end_comment

begin_comment
comment|// CHECK: A: .. .
end_comment

begin_define
define|#
directive|define
name|X
value|0 .. 1
end_define

begin_label
name|B
label|:
end_label

begin_decl_stmt
name|X
comment|// CHECK: B: 0 .. 1
define|#
directive|define
name|DOT
value|.
name|C
range|:
operator|..
name|DOT
comment|// CHECK: C: .. .
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
comment|// CHECK: D: + + - - + + = = =
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
comment|// Should expand to L "str" not L"str"
comment|// CHECK: E: L "str"
comment|// Should avoid producing>>=.
define|#
directive|define
name|equal
value|=
name|F
operator|:
operator|>>
name|equal
end_decl_stmt

begin_comment
comment|// CHECK: F:>> =
end_comment

end_unit

