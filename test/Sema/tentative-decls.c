begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_comment
comment|// PR3310
end_comment

begin_decl_stmt
name|struct
name|a
name|x1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 2{{forward declaration of 'struct a'}}
end_comment

begin_decl_stmt
specifier|static
name|struct
name|a
name|x2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{tentative definition of variable with internal linkage has incomplete non-array type 'struct a'}}
end_comment

begin_decl_stmt
name|struct
name|a
name|x3
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{array has incomplete element type 'struct a'}}
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|a
name|x2_okay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|a
name|x3_okay
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b
name|x4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{tentative definition has type 'struct b' that is never completed}} \
end_comment

begin_comment
comment|// expected-note{{forward declaration of 'struct b'}}
end_comment

begin_decl_stmt
specifier|const
name|int
name|a
index|[
literal|1
index|]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|b
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|b
index|[
literal|1
index|]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|c
index|[]
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{'extern' variable has an initializer}}
end_comment

begin_decl_stmt
specifier|const
name|int
name|c
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|i1
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'i1'}}
end_comment

begin_decl_stmt
name|int
name|i1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|i5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{static declaration of 'i5' follows non-static declaration}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|i2
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note 1 {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|i2
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{non-static declaration of 'i2' follows static declaration}}
end_comment

begin_decl_stmt
specifier|static
name|int
name|i3
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__private_extern__
name|int
name|pExtern
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pExtern
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i4
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|pToArray
argument_list|)
index|[]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|pToArray
argument_list|)
index|[
literal|8
index|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|redef
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|redef
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|redef
index|[
literal|11
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition of 'redef'}}
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
specifier|extern
name|int
name|i6
decl_stmt|;
comment|// expected-note {{previous definition is here}}
specifier|static
name|int
name|i6
decl_stmt|;
comment|// expected-error{{static declaration of 'i6' follows non-static declaration}}
block|}
end_function

begin_function
name|void
name|func2
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|double
modifier|*
name|p
decl_stmt|;
specifier|extern
name|double
modifier|*
name|p
decl_stmt|;
block|}
end_function

begin_comment
comment|//<rdar://problem/6808352>
end_comment

begin_decl_stmt
specifier|static
name|int
name|a0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|b0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|a0
index|[]
init|=
block|{
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|b0
init|=
literal|5
decl_stmt|;
end_decl_stmt

end_unit

