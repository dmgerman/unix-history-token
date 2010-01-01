begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pedantic -fixit %s -o - | grep -v 'CHECK'> %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Werror -x c -
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t %s
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
name|f2
parameter_list|(
specifier|const
name|char
modifier|*
name|my_string
parameter_list|)
block|{
comment|// FIXME: terminal output isn't so good when "my_string" is shorter
comment|// CHECK: return strcmp(my_string , "foo") == 0;
return|return
name|my_string
operator|==
literal|"foo"
return|;
block|}
end_function

end_unit

