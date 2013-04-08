begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify -std=c11 %s
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -Xclang -verify -std=c11 -fmodules %s
end_comment

begin_function_decl
name|noreturn
name|int
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error 1+{{}}
end_comment

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_include
include|#
directive|include
file|<stdnoreturn.h>
end_include

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|noreturn
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|noreturn
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<stdalign.h>
end_include

begin_assert
assert|_Static_assert
argument_list|(
name|__alignas_is_defined
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof_is_defined
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

begin_macro
name|alignas
argument_list|(
argument|alignof(int)
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_assert
assert|_Static_assert
argument_list|(
name|__alignof
argument_list|(
name|c
argument_list|)
operator|==
literal|4
argument_list|,
literal|""
argument_list|)
assert|;
end_assert

end_unit

