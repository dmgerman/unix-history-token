begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pedantic -fixit %s -o - | %clang_cc1 -pedantic -Werror -x c -
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
end_comment

begin_struct_decl
struct_decl|struct
name|s
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note{{previous use is here}}
end_comment

begin_decl_stmt
name|union
name|s
modifier|*
name|s1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{use of 's' with tag type that does not match previous declaration}}
end_comment

begin_struct
struct|struct
name|Point
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|Point
modifier|*
name|get_origin
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_point
parameter_list|()
block|{
operator|(
name|void
operator|)
name|get_origin
operator|->
name|x
expr_stmt|;
block|}
end_function

end_unit

