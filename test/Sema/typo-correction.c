begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains typo correction tests which hit different code paths in C
end_comment

begin_comment
comment|// than in C++ and may exhibit different behavior as a result.
end_comment

begin_macro
name|__typeof__
argument_list|(
argument|struct F*
argument_list|)
end_macro

begin_expr_stmt
name|var
index|[
name|invalid
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error-re {{use of undeclared identifier 'invalid'{{$}}}}
end_comment

begin_function
name|void
name|PR21656
parameter_list|()
block|{
name|float
name|x
decl_stmt|;
name|x
operator|=
operator|(
name|float
operator|)
name|arst
expr_stmt|;
comment|// expected-error-re {{use of undeclared identifier 'arst'{{$}}}}
block|}
end_function

begin_expr_stmt
name|a
operator|=
name|b
condition|?
else|:
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}} \
end_comment

begin_comment
comment|// expected-error {{use of undeclared identifier 'b'}}
end_comment

begin_struct
struct|struct
name|ContainerStuct
block|{
enum|enum
block|{
name|SOME_ENUM
block|}
enum|;
comment|// expected-note {{'SOME_ENUM' declared here}}
block|}
struct|;
end_struct

begin_function
name|void
name|func
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|SOME_ENUM_
case|:
comment|// expected-error {{use of undeclared identifier 'SOME_ENUM_'; did you mean 'SOME_ENUM'}}
empty_stmt|;
block|}
block|}
end_function

end_unit

