begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -fixit -x c %t || true
end_comment

begin_comment
comment|// RUN: grep -v CHECK %t> %t2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Werror -x c %t
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t2 %t
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_comment
comment|// FIXME: FIX-IT should add #include<string.h>?
end_comment

begin_function_decl
name|int
name|strcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|s1
parameter_list|,
specifier|const
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|s
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
empty_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: _Complex double cd;
end_comment

begin_expr_stmt
specifier|_Complex
name|cd
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK: struct s s0 = { .y = 5 };
end_comment

begin_decl_stmt
name|struct
name|s
name|s0
init|=
block|{
name|y
operator|:
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int array0[5] = { [3] = 3 };
end_comment

begin_decl_stmt
name|int
name|array0
index|[
literal|5
index|]
init|=
block|{
index|[
literal|3
index|]
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
block|{ }
end_function

begin_decl_stmt
name|int
name|i0
init|=
block|{
literal|17
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test_cond
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|fooBar
parameter_list|)
block|{
comment|// CHECK: int x = y ? 1 : 4+fooBar;
name|int
name|x
init|=
name|y
condition|?
literal|1
literal|4
operator|+
name|foobar
decl_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: typedef int int_t;
end_comment

begin_typedef
typedef|typedef
typedef|typedef
name|int
name|int_t
typedef|;
end_typedef

begin_comment
comment|//<rdar://problem/7159693>
end_comment

begin_enum
enum|enum
name|Color
block|{
name|Red
comment|// expected-error{{missing ',' between enumerators}}
name|Green
init|=
literal|17
comment|// expected-error{{missing ',' between enumerators}}
name|Blue
block|, }
enum|;
end_enum

end_unit

