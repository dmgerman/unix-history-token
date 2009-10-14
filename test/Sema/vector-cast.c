begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only %s -verify -Wvector-conversions
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|t1
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|t2
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|t3
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|t1
name|v1
decl_stmt|;
name|t2
name|v2
decl_stmt|;
name|t3
name|v3
decl_stmt|;
name|v2
operator|=
operator|(
name|t2
operator|)
name|v1
expr_stmt|;
comment|// -expected-error {{invalid conversion between vector type \
literal|'t2'
name|and
literal|'t1'
name|of
name|different
name|size
block|}
end_function

begin_expr_stmt
unit|}   v1
operator|=
operator|(
name|t1
operator|)
name|v2
expr_stmt|;
end_expr_stmt

begin_comment
comment|// -expected-error {{invalid conversion between vector type \
end_comment

begin_expr_stmt
literal|'t1'
name|and
literal|'t2'
name|of
name|different
name|size
end_expr_stmt

begin_expr_stmt
unit|}}
name|v3
operator|=
operator|(
name|t3
operator|)
name|v2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|v1
operator|=
call|(
name|t1
call|)
argument_list|(
name|char
operator|*
argument_list|)
literal|10
expr_stmt|;
end_expr_stmt

begin_comment
comment|// -expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
name|and
name|scalar
name|type
literal|'char *'
end_expr_stmt

begin_expr_stmt
unit|}}
name|v1
operator|=
operator|(
name|t1
operator|)
operator|(
name|long
name|long
operator|)
literal|10
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|v1
operator|=
call|(
name|t1
call|)
argument_list|(
name|short
argument_list|)
literal|10
expr_stmt|;
end_expr_stmt

begin_comment
comment|// -expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
name|and
name|integer
name|type
literal|'short'
name|of
name|different
name|size
end_expr_stmt

begin_decl_stmt
unit|}}
name|long
name|long
name|r1
init|=
operator|(
name|long
name|long
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|r2
init|=
operator|(
name|short
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-error {{invalid conversion between vector \
end_comment

begin_expr_stmt
name|type
literal|'t1'
name|and
name|integer
name|type
literal|'short'
name|of
name|different
name|size
end_expr_stmt

begin_decl_stmt
unit|}}
name|char
modifier|*
name|r3
init|=
operator|(
name|char
operator|*
operator|)
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// -expected-error {{invalid conversion between vector\
end_comment

begin_expr_stmt
name|type
literal|'t1'
name|and
name|scalar
name|type
literal|'char *'
end_expr_stmt

begin_macro
unit|}} }   void
name|f2
argument_list|(
argument|t2 X
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f3
parameter_list|(
name|t3
name|Y
parameter_list|)
block|{
name|f2
argument_list|(
name|Y
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible vector types passing 't3', expected 't2'}}
block|}
end_function

end_unit

