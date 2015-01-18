begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -verify %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -pedantic -fixit -x c %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Werror -Wno-invalid-noreturn -x c %t
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
comment|// expected-error {{base of member reference is a function; perhaps you meant to call it with no arguments?}}
block|}
end_function

begin_expr_stmt
name|void
name|noreturn_1
argument_list|()
specifier|_Noreturn
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error {{must precede function declarator}}
end_comment

begin_function
name|void
name|noreturn_1
parameter_list|()
block|{
return|return;
comment|// expected-warning {{should not return}}
block|}
end_function

begin_expr_stmt
name|void
name|noreturn_2
argument_list|()
specifier|_Noreturn
block|{
comment|// expected-error {{must precede function declarator}}
return|return;
comment|// expected-warning {{should not return}}
block|}
end_expr_stmt

end_unit

