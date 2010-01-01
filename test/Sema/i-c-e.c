begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -fsyntax-only -Xclang -verify -pedantic -fpascal-strings
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
name|int
name|a
parameter_list|()
block|{
name|int
name|p
decl_stmt|;
operator|*
operator|(
literal|1
condition|?
operator|&
name|p
else|:
operator|(
name|void
operator|*
operator|)
operator|(
literal|0
operator|&&
operator|(
name|a
argument_list|()
operator|,
literal|1
operator|)
operator|)
operator|)
operator|=
literal|10
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{incomplete type 'void' is not assignable}}
end_comment

begin_comment
comment|// rdar://6091492 - ?: with __builtin_constant_p as the operand is an i-c-e.
end_comment

begin_decl_stmt
name|int
name|expr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|w
index|[
name|__builtin_constant_p
argument_list|(
name|expr
argument_list|)
condition|?
name|expr
else|:
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __builtin_constant_p as the condition of ?: allows arbitrary foldable
end_comment

begin_comment
comment|// constants to be transmogrified into i-c-e's.
end_comment

begin_decl_stmt
name|char
name|b
index|[
name|__builtin_constant_p
argument_list|(
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|+
literal|2.0
argument_list|)
argument_list|)
condition|?
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|+
literal|2.0
argument_list|)
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|c
block|{
name|int
name|a
range|:
operator|(
comment|// expected-error {{expression is not an integer constant expression}}
name|__builtin_constant_p
argument_list|(
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|+
literal|2.0
argument_list|)
argument_list|)
condition|?
call|(
name|int
call|)
argument_list|(
literal|1.0
operator|+
name|expr
comment|// expected-note {{subexpression not valid in an integer constant expression}}
argument_list|)
else|:
operator|-
literal|1
operator|)
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|test1
parameter_list|(
name|int
name|n
parameter_list|,
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
operator|(
name|n
condition|?
name|p
else|:
operator|(
name|void
operator|*
operator|)
operator|(
literal|7
operator|-
literal|7
operator|)
operator|)
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|int
name|n
parameter_list|,
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
operator|(
name|n
condition|?
name|p
else|:
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|char
name|array
index|[
literal|1024
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
index|[
literal|'\xBb'
operator|==
operator|(
name|char
operator|)
literal|187
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR1992
end_comment

begin_function
name|void
name|func
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
sizeof|sizeof
argument_list|(
literal|"abc"
argument_list|)
case|:
break|break;
case|case
sizeof|sizeof
argument_list|(
literal|"loooong"
argument_list|)
case|:
name|func
argument_list|(
literal|4
argument_list|)
expr_stmt|;
case|case
sizeof|sizeof
argument_list|(
literal|"\ploooong"
argument_list|)
case|:
name|func
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// rdar://4213768
end_comment

begin_decl_stmt
name|int
name|expr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|y
index|[
name|__builtin_constant_p
argument_list|(
name|expr
argument_list|)
condition|?
operator|-
literal|1
else|:
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|z
index|[
name|__builtin_constant_p
argument_list|(
literal|4
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Comma tests
end_comment

begin_decl_stmt
name|int
name|comma1
index|[
literal|0
condition|?
literal|1
operator|,
literal|2
operator|:
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|comma2
index|[
literal|1
operator|||
operator|(
literal|1
operator|,
literal|2
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|comma3
index|[
operator|(
literal|1
operator|,
literal|2
operator|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{size of static array must be an integer constant expression}}
end_comment

begin_comment
comment|// Pointer + __builtin_constant_p
end_comment

begin_decl_stmt
name|char
name|pbcp
index|[
name|__builtin_constant_p
argument_list|(
literal|4
argument_list|)
condition|?
operator|(
name|intptr_t
operator|)
operator|&
name|expr
else|:
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable length array declaration not allowed at file scope}}
end_comment

begin_decl_stmt
name|int
name|illegaldiv1
index|[
literal|1
operator|||
literal|1
operator|/
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|illegaldiv2
index|[
literal|1
operator|/
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable length array declaration not allowed at file scope}}
end_comment

begin_decl_stmt
name|int
name|illegaldiv3
index|[
name|INT_MIN
operator|/
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{variable length array declaration not allowed at file scope}}
end_comment

begin_decl_stmt
name|int
name|chooseexpr
index|[
name|__builtin_choose_expr
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|expr
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|realop
index|[
operator|(
name|__real__
literal|4
operator|)
operator|==
literal|4
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|imagop
index|[
operator|(
name|__imag__
literal|4
operator|)
operator|==
literal|0
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

