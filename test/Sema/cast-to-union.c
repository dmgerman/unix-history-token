begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_union
union|union
name|u
block|{
name|int
name|i
decl_stmt|;
block|}
union|;
end_union

begin_function_decl
name|void
name|f
parameter_list|(
name|union
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|f
argument_list|(
operator|(
expr|union
name|u
operator|)
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{C99 forbids casts to union type}}
name|f
argument_list|(
operator|(
expr|union
name|u
operator|)
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-error {{cast to union type from type 'int *' not present in union}}
block|}
end_function

begin_decl_stmt
name|union
name|u
name|w
init|=
operator|(
expr|union
name|u
operator|)
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{C99 forbids casts to union type}}
end_comment

begin_decl_stmt
name|union
name|u
name|ww
init|=
operator|(
expr|union
name|u
operator|)
literal|1.0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{cast to union type from type 'double' not present in union}}
end_comment

begin_decl_stmt
name|union
name|u
name|x
init|=
literal|7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{incompatible type initializing 'int', expected 'union u'}}
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|u
name|zz
init|=
operator|(
expr|union
name|u
operator|)
name|i
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{initializer element is not a compile-time constant}}  expected-warning {{C99 forbids casts to union type}}
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s
name|y
init|=
block|{
literal|1
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s
name|z
init|=
operator|(
expr|struct
name|s
operator|)
block|{
literal|1
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

end_unit

