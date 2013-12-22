begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-pc-linux-gnu -DTEST_32BIT_X86 -fsyntax-only \
end_comment

begin_comment
comment|// RUN:   -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -DTEST_64BIT_X86 -fsyntax-only \
end_comment

begin_comment
comment|// RUN:   -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-pc-linux-gnu -DTEST_64BIT_PPC64 -fsyntax-only \
end_comment

begin_comment
comment|// RUN:   -verify %s
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
comment|// expected-error{{'mode' attribute takes one argument}}
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
comment|// expected-error{{'mode' attribute takes one argument}}
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

begin_typedef
typedef|typedef
name|int
name|invalid_6
name|__attribute__
typedef|((
name|mode
typedef|(12)));
end_typedef

begin_comment
comment|// expected-error{{'mode' attribute requires an identifier}}
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|unwind_word
name|__attribute
typedef|((
name|mode
typedef|(
name|unwind_word
typedef|)));
end_typedef

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

begin_ifndef
ifndef|#
directive|ifndef
name|TEST_64BIT_PPC64
end_ifndef

begin_comment
comment|// Note, 'XC' mode is illegal for PPC64 machines.
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR6108: Correctly select 'long' built in type on 64-bit platforms for 64 bit
end_comment

begin_comment
comment|// modes. Also test other mode-based conversions.
end_comment

begin_typedef
typedef|typedef
name|int
name|i8_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__QI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ui8_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__QI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|i16_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ui16_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__HI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|i32_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ui32_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__SI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|i64_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ui64_mode_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)));
end_typedef

begin_function
name|void
name|f_i8_arg
parameter_list|(
name|i8_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_ui8_arg
parameter_list|(
name|ui8_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_i16_arg
parameter_list|(
name|i16_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_ui16_arg
parameter_list|(
name|ui16_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_i32_arg
parameter_list|(
name|i32_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_ui32_arg
parameter_list|(
name|ui32_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_i64_arg
parameter_list|(
name|i64_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f_ui64_arg
parameter_list|(
name|ui64_mode_t
modifier|*
name|x
parameter_list|)
block|{
operator|(
name|void
operator|)
name|x
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_char_to_i8
parameter_list|(
name|signed
name|char
modifier|*
name|y
parameter_list|)
block|{
name|f_i8_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_char_to_ui8
parameter_list|(
name|unsigned
name|char
modifier|*
name|y
parameter_list|)
block|{
name|f_ui8_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_short_to_i16
parameter_list|(
name|short
modifier|*
name|y
parameter_list|)
block|{
name|f_i16_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_short_to_ui16
parameter_list|(
name|unsigned
name|short
modifier|*
name|y
parameter_list|)
block|{
name|f_ui16_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_int_to_i32
parameter_list|(
name|int
modifier|*
name|y
parameter_list|)
block|{
name|f_i32_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_int_to_ui32
parameter_list|(
name|unsigned
name|int
modifier|*
name|y
parameter_list|)
block|{
name|f_ui32_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|TEST_32BIT_X86
end_if

begin_function
name|void
name|test_long_to_i64
parameter_list|(
name|long
name|long
modifier|*
name|y
parameter_list|)
block|{
name|f_i64_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_long_to_ui64
parameter_list|(
name|unsigned
name|long
name|long
modifier|*
name|y
parameter_list|)
block|{
name|f_ui64_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|TEST_64BIT_X86
end_elif

begin_function
name|void
name|test_long_to_i64
parameter_list|(
name|long
modifier|*
name|y
parameter_list|)
block|{
name|f_i64_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_long_to_ui64
parameter_list|(
name|unsigned
name|long
modifier|*
name|y
parameter_list|)
block|{
name|f_ui64_arg
argument_list|(
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|float
name|f128ibm
name|__attribute__
typedef|((
name|mode
typedef|(
name|TF
typedef|)));
end_typedef

begin_comment
comment|// expected-error{{unsupported machine mode 'TF'}}
end_comment

begin_elif
elif|#
directive|elif
name|TEST_64BIT_PPC64
end_elif

begin_typedef
typedef|typedef
name|float
name|f128ibm
name|__attribute__
typedef|((
name|mode
typedef|(
name|TF
typedef|)));
end_typedef

begin_typedef
typedef|typedef
specifier|_Complex
name|float
name|c128ibm
name|__attribute__
typedef|((
name|mode
typedef|(
name|TC
typedef|)));
end_typedef

begin_function_decl
name|void
name|f_ft128_arg
parameter_list|(
name|long
name|double
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f_ft128_complex_arg
parameter_list|(
specifier|_Complex
name|long
name|double
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_TFtype
parameter_list|(
name|f128ibm
modifier|*
name|a
parameter_list|)
block|{
name|f_ft128_arg
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_TCtype
parameter_list|(
name|c128ibm
modifier|*
name|a
parameter_list|)
block|{
name|f_ft128_complex_arg
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown test architecture.
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

