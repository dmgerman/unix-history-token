begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_struct
struct|struct
name|foo
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
specifier|static
name|struct
name|foo
name|t
init|=
operator|(
expr|struct
name|foo
operator|)
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|foo
name|t2
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|foo
name|t3
init|=
name|t2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-error {{initializer element is not a compile-time constant}}
end_comment

begin_decl_stmt
specifier|static
name|int
modifier|*
name|p
init|=
operator|(
name|int
index|[]
operator|)
block|{
literal|2
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|x
init|=
operator|(
name|int
operator|)
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
modifier|*
name|p2
init|=
operator|(
name|int
index|[]
operator|)
block|{
literal|2
block|,
name|x
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-error {{initializer element is not a compile-time constant}}
end_comment

begin_decl_stmt
specifier|static
name|long
modifier|*
name|p3
init|=
operator|(
name|long
index|[]
operator|)
block|{
literal|2
block|,
literal|"x"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-warning {{incompatible pointer to integer conversion initializing 'char [2]', expected 'long'}}
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|cache_t
typedef|;
end_typedef

begin_comment
comment|// -expected-warning{{use of empty struct extension}}
end_comment

begin_decl_stmt
specifier|static
name|cache_t
name|clo_I1_cache
init|=
operator|(
operator|(
name|cache_t
operator|)
block|{ }
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-warning{{use of GNU empty initializer extension}}
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Test
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
name|Test
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|Test
modifier|*
name|ll
init|=
operator|&
operator|(
name|Test
operator|)
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fooFunc
parameter_list|(
name|struct
name|foo
modifier|*
name|pfoo
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
modifier|*
name|l
init|=
operator|(
name|int
index|[]
operator|)
block|{
name|x
block|,
operator|*
name|p
block|,
operator|*
name|p2
block|}
decl_stmt|;
name|fooFunc
argument_list|(
operator|&
operator|(
expr|struct
name|foo
operator|)
block|{
literal|1
block|,
literal|2
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|Incomplete
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note{{forward declaration of 'struct Incomplete'}}
end_comment

begin_decl_stmt
name|struct
name|Incomplete
modifier|*
name|I1
init|=
operator|&
operator|(
expr|struct
name|Incomplete
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-error {{variable has incomplete type}}
end_comment

begin_function
name|void
name|IncompleteFunc
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
name|struct
name|Incomplete
modifier|*
name|I2
init|=
operator|(
expr|struct
name|foo
index|[
name|x
index|]
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
comment|// -expected-error {{variable-sized object may not be initialized}}
operator|(
name|void
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
expr_stmt|;
comment|// -expected-error {{variable has incomplete type}}
operator|(
name|void
argument_list|(
name|void
argument_list|)
operator|)
block|{
literal|0
block|}
expr_stmt|;
comment|// -expected-error{{illegal initializer type 'void (void)'}}
block|}
end_function

begin_comment
comment|// PR6080
end_comment

begin_expr_stmt
name|int
name|array
index|[
operator|(
sizeof|sizeof
argument_list|(
name|int
index|[
literal|3
index|]
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
operator|(
name|int
index|[]
operator|)
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|}
argument_list|)
operator|)
operator|?
literal|1
operator|:
operator|-
literal|1
index|]
expr_stmt|;
end_expr_stmt

end_unit

