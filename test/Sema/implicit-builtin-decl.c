begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
modifier|*
name|ptr
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|*
literal|10
argument_list|)
decl_stmt|;
comment|// expected-warning{{implicitly declaring C library function 'malloc' with type}} \
comment|// expected-note{{please include the header<stdlib.h> or explicitly provide a declaration for 'malloc'}} \
comment|// expected-note{{'malloc' is a builtin with type 'void *}}
block|}
end_function

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|(
name|__SIZE_TYPE__
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// redeclaration okay
end_comment

begin_function_decl
name|int
modifier|*
name|calloc
parameter_list|(
name|__SIZE_TYPE__
parameter_list|,
name|__SIZE_TYPE__
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{incompatible redeclaration of library function 'calloc'}} \
end_comment

begin_comment
comment|// expected-note{{'calloc' is a builtin with type 'void *}}
end_comment

begin_function
name|void
name|g
parameter_list|(
name|int
name|malloc
parameter_list|)
block|{
comment|// okay: these aren't functions
name|int
name|calloc
init|=
literal|1
decl_stmt|;
block|}
end_function

begin_function
name|void
name|h
parameter_list|()
block|{
name|int
name|malloc
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-warning{{incompatible redeclaration of library function 'malloc'}}
name|int
name|strcpy
argument_list|(
name|int
argument_list|)
decl_stmt|;
comment|// expected-warning{{incompatible redeclaration of library function 'strcpy'}} \
comment|// expected-note{{'strcpy' is a builtin with type 'char *(char *, char const *)'}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|fprintf
argument_list|(
literal|0
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-error{{implicit declaration of 'fprintf' requires inclusion of the header<stdio.h>}} \
name|expected
operator|-
name|warning
block|{
block|{
name|implicit
name|declaration
name|of
name|function
literal|'fprintf'
name|is
name|invalid
name|in
name|C99
block|}
block|}
block|}
end_function

begin_comment
comment|// PR2892
end_comment

begin_function_decl
name|void
name|__builtin_object_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{conflicting types}} \
end_comment

begin_comment
comment|// expected-note{{'__builtin_object_size' is a builtin with type}}
end_comment

begin_decl_stmt
name|int
name|a
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f0
parameter_list|()
block|{
return|return
name|__builtin_object_size
argument_list|(
operator|&
name|a
argument_list|)
return|;
comment|// expected-error {{too few arguments to function}}
block|}
end_function

begin_function
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|int
name|size
parameter_list|)
block|{
comment|// expected-warning{{incompatible redeclaration of library function 'realloc'}} \
comment|// expected-note{{'realloc' is a builtin with type 'void *(void *,}}
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|// PR3855
end_comment

begin_function_decl
name|void
name|snprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{incompatible redeclaration of library function 'snprintf'}} \
end_comment

begin_comment
comment|// expected-note{{'snprintf' is a builtin}}
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|snprintf
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|snprintf
parameter_list|()
block|{ }
end_function

end_unit

