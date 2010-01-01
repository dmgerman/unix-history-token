begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Example from C99 6.10.3.4p6
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|str
parameter_list|(
name|s
parameter_list|)
value|# s
end_define

begin_define
define|#
directive|define
name|xstr
parameter_list|(
name|s
parameter_list|)
value|str(s)
end_define

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|printf("x" # s "= %d, x" # t "= s" \
end_define

begin_expr_stmt
name|x
operator|#
operator|#
name|s
operator|,
name|x
operator|#
operator|#
name|t
end_expr_stmt

begin_define
unit|)
define|#
directive|define
name|INCFILE
parameter_list|(
name|n
parameter_list|)
value|vers ## n
end_define

begin_define
define|#
directive|define
name|glue
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_define
define|#
directive|define
name|xglue
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|glue(a, b)
end_define

begin_define
define|#
directive|define
name|HIGHLOW
value|"hello"
end_define

begin_define
define|#
directive|define
name|LOW
value|LOW ", world"
end_define

begin_expr_stmt
name|debug
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|fputs
argument_list|(
name|str
argument_list|(
argument|strncmp(
literal|"abc\0d"
literal|"abc"
argument|,
literal|'\4'
argument|)
comment|// this goes away
argument|==
literal|0
argument_list|)
name|str
argument_list|(:
argument|@
operator|\
name|n
argument_list|)
argument_list|,
name|s
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|include
name|xstr
argument_list|(
name|INCFILE
argument_list|(
literal|2
argument_list|)
operator|.
name|h
argument_list|)
name|glue
argument_list|(
name|HIGH
argument_list|,
name|LOW
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|xglue
argument_list|(
argument|HIGH
argument_list|,
argument|LOW
argument_list|)
end_macro

begin_comment
comment|// CHECK: printf("x" "1" "= %d, x" "2" "= s" x1, x2);
end_comment

begin_comment
comment|// CHECK: fputs("strncmp(\"abc\\0d\" \"abc\", '\\4') == 0" ": @\n", s);
end_comment

begin_comment
comment|// CHECK: include "vers2.h"
end_comment

begin_comment
comment|// CHECK: "hello";
end_comment

begin_comment
comment|// CHECK: "hello" ", world"
end_comment

end_unit

