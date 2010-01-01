begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -pedantic -verify -triple=x86_64-apple-darwin9
end_comment

begin_comment
comment|// rdar://6097662
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
name|T
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|restrict
name|T
name|x
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
modifier|*
name|S
index|[
literal|2
index|]
typedef|;
end_typedef

begin_decl_stmt
specifier|restrict
name|S
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{restrict requires a pointer or reference ('S' (aka 'int *[2]') is invalid)}}
end_comment

begin_comment
comment|// int128_t is available.
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|__int128_t
name|s
decl_stmt|;
name|__uint128_t
name|t
decl_stmt|;
block|}
end_function

begin_comment
comment|// but not a keyword
end_comment

begin_function
name|int
name|b
parameter_list|()
block|{
name|int
name|__int128_t
decl_stmt|;
name|int
name|__uint128_t
decl_stmt|;
block|}
end_function

begin_comment
comment|// Array type merging should convert array size to whatever matches the target
end_comment

begin_comment
comment|// pointer size.
end_comment

begin_comment
comment|// rdar://6880874
end_comment

begin_decl_stmt
specifier|extern
name|int
name|i
index|[
literal|1LL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
index|[
operator|(
name|short
operator|)
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|e
block|{
name|e_1
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|int
name|j
index|[
sizeof|sizeof
argument_list|(
expr|enum
name|e
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition}}
end_comment

begin_decl_stmt
name|int
name|j
index|[
literal|42
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'j' with a different type}}
end_comment

begin_comment
comment|// rdar://6880104
end_comment

begin_decl_stmt
name|_Decimal32
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{GNU decimal type extension not supported}}
end_comment

begin_comment
comment|// rdar://6880951
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|,
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|v
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{invalid vector type}}
end_comment

end_unit

