begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-unknown-linux-gnu %s
end_comment

begin_comment
comment|// Correct cases.
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|byte
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|SI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|DI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|SF
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|DF
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t6
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|XF
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t7
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|v8qi
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)))
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|v8qi
name|__attribute__
typedef|((
name|mode
typedef|(
name|V8QI
typedef|)));
end_typedef

begin_comment
comment|// expected-warning@-1{{specifying vector types with the 'mode' attribute is deprecated; use the 'vector_size' attribute instead}}
end_comment

begin_typedef
typedef|typedef
name|float
name|v4sf
name|__attribute__
typedef|((
name|mode
typedef|(
name|V4SF
typedef|)));
end_typedef

begin_comment
comment|// expected-warning@-1{{specifying vector types with the 'mode' attribute is deprecated; use the 'vector_size' attribute instead}}
end_comment

begin_typedef
typedef|typedef
name|float
name|v4sf
name|__attribute__
typedef|((
name|mode
typedef|(
name|SF
typedef|)))
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_comment
comment|// Incorrect cases.
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QC
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t8
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{unsupported machine mode 'QC'}}
end_comment

begin_comment
comment|// expected-error@-2{{type of machine mode does not match type of base type}}
end_comment

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|__attribute__
typedef|((
name|mode
typedef|(
name|HC
typedef|)))
name|__attribute__
typedef|((
name|vector_size
typedef|(256)))
name|vec_t9
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{unsupported machine mode 'HC'}}
end_comment

begin_comment
comment|// expected-error@-2{{invalid vector element type '_Complex float'}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|SC
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t10
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{type of machine mode does not match type of base type}}
end_comment

begin_comment
comment|// expected-error@-2{{type of machine mode does not support base vector types}}
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|DC
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t11
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{type of machine mode does not match type of base type}}
end_comment

begin_comment
comment|// expected-error@-2{{type of machine mode does not support base vector types}}
end_comment

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|__attribute__
typedef|((
name|mode
typedef|(
name|XC
typedef|)))
name|__attribute__
typedef|((
name|vector_size
typedef|(256)))
name|vec_t12
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{invalid vector element type '_Complex float'}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V3QI
argument_list|)
operator|)
argument_list|)
name|v3qi
typedef|;
end_typedef

begin_comment
comment|// expected-error@-1{{unknown machine mode 'V3QI'}}
end_comment

end_unit

