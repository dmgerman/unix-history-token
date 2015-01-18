begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -fsyntax-only -verify  %s
end_comment

begin_comment
comment|// rdar://18716393
end_comment

begin_decl_stmt
specifier|extern
name|int
name|a
index|[]
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|b
index|[]
init|=
block|{
literal|8
block|,
literal|13
block|,
literal|21
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|x
index|[
literal|10
index|]
decl_stmt|;
block|}
name|c
struct|;
end_struct

begin_decl_stmt
specifier|const
name|char
name|str
index|[]
init|=
literal|"text"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ignore
parameter_list|()
block|{
if|if
condition|(
operator|!
name|a
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
if|if
condition|(
operator|!
name|b
condition|)
block|{}
comment|// expected-warning {{address of array 'b' will always evaluate to 'true'}}
if|if
condition|(
name|b
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{comparison of array 'b' equal to a null pointer is always false}}
if|if
condition|(
operator|!
name|c
operator|.
name|x
condition|)
block|{}
comment|// expected-warning {{address of array 'c.x' will always evaluate to 'true'}}
if|if
condition|(
name|c
operator|.
name|x
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{comparison of array 'c.x' equal to a null pointer is always false}}
if|if
condition|(
operator|!
name|str
condition|)
block|{}
comment|// expected-warning {{address of array 'str' will always evaluate to 'true'}}
if|if
condition|(
literal|0
operator|==
name|str
condition|)
block|{}
comment|// expected-warning {{comparison of array 'str' equal to a null pointer is always false}}
block|}
end_function

begin_decl_stmt
name|int
name|array
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|test1
parameter_list|()
block|{
if|if
condition|(
operator|!
name|array
condition|)
block|{
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
return|return
name|array
index|[
literal|0
index|]
return|;
block|}
elseif|else
if|if
condition|(
name|array
operator|!=
literal|0
condition|)
block|{
comment|// expected-warning {{comparison of array 'array' not equal to a null pointer is always true}}
return|return
name|array
index|[
literal|1
index|]
return|;
block|}
if|if
condition|(
name|array
operator|==
literal|0
condition|)
comment|// expected-warning {{comparison of array 'array' equal to a null pointer is always false}}
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NULL
value|(void*)0
end_define

begin_function
name|int
name|test2
parameter_list|(
name|int
modifier|*
name|pointer
parameter_list|,
name|char
name|ch
parameter_list|,
name|void
modifier|*
name|pv
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|&
name|pointer
condition|)
block|{
comment|// expected-warning {{address of 'pointer' will always evaluate to 'true'}}
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|&
name|pointer
condition|)
block|{
comment|// expected-warning {{address of 'pointer' will always evaluate to 'true'}}
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|&
name|pointer
operator|==
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of address of 'pointer' equal to a null pointer is always false}}
if|if
condition|(
operator|&
name|pointer
operator|!=
name|NULL
condition|)
block|{}
comment|// expected-warning {{comparison of address of 'pointer' not equal to a null pointer is always true}}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
if|if
condition|(
name|array
condition|)
block|{ }
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
operator|!=
literal|0
condition|)
block|{}
comment|// expected-warning {{comparison of array 'array' not equal to a null pointer is always true}}
if|if
condition|(
operator|!
name|array
condition|)
block|{ }
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning {{comparison of array 'array' equal to a null pointer is always false}}
if|if
condition|(
name|array
index|[
literal|0
index|]
operator|&&
name|array
condition|)
block|{}
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
index|[
literal|0
index|]
operator|||
name|array
condition|)
block|{}
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
index|[
literal|0
index|]
operator|&&
operator|!
name|array
condition|)
block|{}
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
index|[
literal|0
index|]
operator|||
operator|!
name|array
condition|)
block|{}
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
if|if
condition|(
name|array
operator|&&
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
name|array
index|[
literal|0
index|]
condition|)
block|{}
if|if
condition|(
operator|!
name|array
operator|||
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
name|array
index|[
literal|0
index|]
condition|)
block|{}
if|if
condition|(
name|array
operator|||
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
operator|(
operator|!
name|array
operator|&&
name|array
index|[
literal|0
index|]
operator|)
condition|)
block|{}
comment|// expected-warning {{address of array 'array' will always evaluate to 'true'}}
block|}
end_function

begin_comment
comment|// rdar://19256338
end_comment

begin_define
define|#
directive|define
name|SAVE_READ
parameter_list|(
name|PTR
parameter_list|)
value|if( (PTR)&& (&result) ) *result=*PTR;
end_define

begin_function
name|void
name|_HTTPClientErrorHandler
parameter_list|(
name|int
name|me
parameter_list|)
block|{
name|int
modifier|*
name|result
decl_stmt|;
name|SAVE_READ
argument_list|(
operator|&
name|me
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

