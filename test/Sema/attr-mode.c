begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|i16_1
name|__attribute
typedef|((
name|mode
typedef|(
name|HI
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|i16_1_test
index|[
sizeof|sizeof
argument_list|(
name|i16_1
argument_list|)
operator|==
literal|2
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|i16_2
name|__attribute
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|i16_2_test
index|[
sizeof|sizeof
argument_list|(
name|i16_1
argument_list|)
operator|==
literal|2
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|float
name|f64
name|__attribute
typedef|((
name|mode
typedef|(
name|DF
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|f64_test
index|[
sizeof|sizeof
argument_list|(
name|f64
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|invalid_1
name|__attribute
typedef|((
name|mode
typedef|));
end_typedef

begin_comment
comment|// expected-error{{attribute requires unquoted parameter}}
end_comment

begin_typedef
typedef|typedef
name|int
name|invalid_2
name|__attribute
typedef|((
name|mode
typedef|()));
end_typedef

begin_comment
comment|// expected-error{{attribute requires unquoted parameter}}
end_comment

begin_typedef
typedef|typedef
name|int
name|invalid_3
name|__attribute
typedef|((
name|mode
typedef|(
name|II
typedef|)));
end_typedef

begin_comment
comment|// expected-error{{unknown machine mode}}
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
block|}
name|invalid_4
name|__attribute
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_comment
comment|// expected-error{{mode attribute only supported for integer and floating-point types}}
end_comment

begin_typedef
typedef|typedef
name|float
name|invalid_5
name|__attribute
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_comment
comment|// expected-error{{type of machine mode does not match type of base type}}
end_comment

begin_decl_stmt
name|int
modifier|*
modifier|*
name|__attribute
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
modifier|*
name|i32
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{mode attribute}}
end_comment

begin_typedef
typedef|typedef
specifier|_Complex
name|double
name|c32
name|__attribute
typedef|((
name|mode
typedef|(
name|SC
typedef|)));
end_typedef

begin_decl_stmt
name|int
name|c32_test
index|[
sizeof|sizeof
argument_list|(
name|c32
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|c64
name|__attribute
typedef|((
name|mode
typedef|(
name|DC
typedef|)));
end_typedef

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|c80
name|__attribute
typedef|((
name|mode
typedef|(
name|XC
typedef|)));
end_typedef

end_unit

