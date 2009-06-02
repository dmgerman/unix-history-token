begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -verify -fsyntax-only -Wvector-conversions
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|v2u
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|v2s
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|v1s
name|__attribute__
typedef|((
name|vector_size
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|v2f
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|v4ss
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|v2s
name|v1
decl_stmt|;
name|v2u
name|v2
decl_stmt|;
name|v1s
name|v3
decl_stmt|;
name|v2f
name|v4
decl_stmt|;
name|v4ss
name|v5
decl_stmt|;
name|v1
operator|=
name|v2
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2u', expected 'v2s'}}
name|v1
operator|=
name|v3
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v1s', expected 'v2s'}}
name|v1
operator|=
name|v4
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2f', expected 'v2s'}}
name|v1
operator|=
name|v5
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v4ss', expected 'v2s'}}
name|v2
operator|=
name|v1
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2s', expected 'v2u'}}
name|v2
operator|=
name|v3
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v1s', expected 'v2u'}}
name|v2
operator|=
name|v4
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2f', expected 'v2u'}}
name|v2
operator|=
name|v5
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v4ss', expected 'v2u'}}
name|v3
operator|=
name|v1
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v2s', expected 'v1s'}}
name|v3
operator|=
name|v2
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v2u', expected 'v1s'}}
name|v3
operator|=
name|v4
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v2f', expected 'v1s'}}
name|v3
operator|=
name|v5
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v4ss', expected 'v1s'}}
name|v4
operator|=
name|v1
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2s', expected 'v2f'}}
name|v4
operator|=
name|v2
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2u', expected 'v2f'}}
name|v4
operator|=
name|v3
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v1s', expected 'v2f'}}
name|v4
operator|=
name|v5
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v4ss', expected 'v2f'}}
name|v5
operator|=
name|v1
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2s', expected 'v4ss'}}
name|v5
operator|=
name|v2
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2u', expected 'v4ss'}}
name|v5
operator|=
name|v3
expr_stmt|;
comment|// expected-error {{incompatible type assigning 'v1s', expected 'v4ss'}}
name|v5
operator|=
name|v4
expr_stmt|;
comment|// expected-warning {{incompatible vector types assigning 'v2f', expected 'v4ss'}}
block|}
end_function

begin_comment
comment|// PR2263
end_comment

begin_decl_stmt
name|float
name|f2
argument_list|(
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|float
name|a
argument_list|,
name|int
name|b
argument_list|)
block|{
return|return
name|a
index|[
name|b
index|]
return|;
block|}
end_decl_stmt

end_unit

