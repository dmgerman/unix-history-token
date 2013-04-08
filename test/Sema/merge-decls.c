begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function_decl
name|void
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{conflicting types for 'foo'}}
end_comment

begin_function
name|int
name|funcdef
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|funcdef
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|funcdef2
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function
name|int
name|funcdef2
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error {{redefinition of 'funcdef2'}}
end_comment

begin_comment
comment|// PR2502
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|int
name|Vi2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float
name|Vf2
typedef|;
end_typedef

begin_decl_stmt
name|Vf2
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
name|Vi2
name|g0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'g0'}}
end_comment

begin_decl_stmt
specifier|_Complex
name|int
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_decl_stmt
specifier|_Complex
name|float
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{redefinition of 'g1'}}
end_comment

begin_comment
comment|// rdar://6096412
end_comment

begin_decl_stmt
specifier|extern
name|char
name|i6096412
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|i6096412
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo6096412
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|i6096412
argument_list|)
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|test1_IA
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|test1_A10
index|[
literal|10
index|]
typedef|;
end_typedef

begin_function_decl
specifier|static
name|test1_A10
modifier|*
name|test1_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test1_g
parameter_list|(
name|void
parameter_list|)
block|{
block|{
specifier|extern
name|test1_IA
modifier|*
name|test1_f
argument_list|(
name|void
argument_list|)
decl_stmt|;
block|}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|*
name|test1_f
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|test2_IA
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|test2_A10
index|[
literal|10
index|]
typedef|;
end_typedef

begin_function_decl
specifier|static
name|test2_A10
modifier|*
name|test2_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|test2_IA
modifier|*
name|test2_f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test2_g
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|*
name|test2_f
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|int
argument_list|(
operator|*
name|test3_f
argument_list|()
argument_list|)
index|[
literal|10
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
argument_list|(
operator|*
name|test3_f
argument_list|()
argument_list|)
index|[]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|test3_k
init|=
sizeof|sizeof
argument_list|(
operator|*
name|test3_f
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|test4_f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test4_f
parameter_list|(
name|a
parameter_list|)
name|char
name|a
decl_stmt|;
block|{
name|int
name|v
index|[
sizeof|sizeof
argument_list|(
name|a
argument_list|)
operator|==
literal|1
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|test5_f
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test5_f
argument_list|(
name|int
argument_list|(
operator|*
name|x
argument_list|)
index|[]
argument_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
operator|*
name|x
argument_list|)
return|;
comment|// expected-error {{invalid application of 'sizeof' to an incomplete type 'int []'}}
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|test6_f
argument_list|(
name|int
argument_list|(
operator|*
name|a
argument_list|)
index|[
literal|11
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|test6_f
argument_list|(
name|a
argument_list|)
name|int
argument_list|(
operator|*
name|a
argument_list|)
decl|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{}
end_block

begin_function
name|void
name|test6_g
parameter_list|()
block|{
name|int
name|arr
index|[
literal|10
index|]
decl_stmt|;
name|test6_f
argument_list|(
operator|&
name|arr
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types passing 'int (*)[10]' to parameter of type 'int (*)[11]}}
block|}
end_function

begin_decl_stmt
name|void
name|test7_f
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
index|[
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|test7_f
argument_list|(
name|int
argument_list|(
operator|*
argument_list|)
index|[]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{passing argument to parameter here}}
end_comment

begin_function
name|void
name|test7_g
parameter_list|()
block|{
name|int
name|x
index|[
literal|5
index|]
decl_stmt|;
name|test7_f
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer types passing 'int (*)[5]' to parameter of type 'int (*)[10]}}
block|}
end_function

end_unit

