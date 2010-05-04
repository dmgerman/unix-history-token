begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc-apple-darwin8 -faltivec -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|__vector
name|char
name|vv_c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|signed
name|char
name|vv_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|unsigned
name|char
name|vv_uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|short
name|vv_s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|signed
name|short
name|vv_ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|unsigned
name|short
name|vv_us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|short
name|int
name|vv_si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|signed
name|short
name|int
name|vv_ssi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|unsigned
name|short
name|int
name|vv_usi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|int
name|vv_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|signed
name|int
name|vv_sint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|unsigned
name|int
name|vv_ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|float
name|vv_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|bool
name|vv_b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|__pixel
name|vv_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|pixel
name|vv__p
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__vector
name|int
name|vf__r
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vf__a
parameter_list|(
name|__vector
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vf__a2
parameter_list|(
name|int
name|b
parameter_list|,
name|__vector
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vector
name|char
name|v_c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|char
name|v_sc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|char
name|v_uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|short
name|v_s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|v_ss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|short
name|v_us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|short
name|int
name|v_si
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|short
name|int
name|v_ssi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|short
name|int
name|v_usi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|int
name|v_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|int
name|v_sint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|int
name|v_ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|v_f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|v_b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|__pixel
name|v_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|pixel
name|v__p
decl_stmt|;
end_decl_stmt

begin_function_decl
name|vector
name|int
name|f__r
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f_a
parameter_list|(
name|vector
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|f_a2
parameter_list|(
name|int
name|b
parameter_list|,
name|vector
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vector
name|int
name|v
init|=
call|(
name|vector
name|int
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// These should have warnings.
end_comment

begin_decl_stmt
name|__vector
name|long
name|vv_l
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|signed
name|long
name|vv_sl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|unsigned
name|long
name|vv_ul
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|long
name|int
name|vv_li
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|signed
name|long
name|int
name|vv_sli
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|unsigned
name|long
name|int
name|vv_uli
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|long
name|v_l
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|signed
name|long
name|v_sl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|unsigned
name|long
name|v_ul
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|long
name|int
name|v_li
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|signed
name|long
name|int
name|v_sli
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|vector
name|unsigned
name|long
name|int
name|v_uli
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}}
end_comment

begin_decl_stmt
name|__vector
name|long
name|double
name|vv_ld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}} expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|long
name|double
name|v_ld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}} expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_comment
comment|// These should have errors.
end_comment

begin_decl_stmt
name|__vector
name|double
name|vv_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|__vector
name|double
name|vv_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|double
name|v_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|double
name|v_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|__vector
name|long
name|double
name|vv_ld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}} expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|long
name|double
name|v_ld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{Use of 'long' with '__vector' is deprecated}} expected-error {{cannot use 'double' with '__vector'}}
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|__vector
name|unsigned
name|int
name|v
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|__vector
name|int
name|v__cast
init|=
operator|(
name|__vector
name|int
operator|)
name|v
decl_stmt|;
name|__vector
name|int
name|v_cast
init|=
operator|(
name|vector
name|int
operator|)
name|v
decl_stmt|;
name|__vector
name|char
name|vb_cast
init|=
operator|(
name|vector
name|char
operator|)
name|v
decl_stmt|;
comment|// Check some casting between gcc and altivec vectors.
define|#
directive|define
name|gccvector
value|__attribute__((vector_size(16)))
name|gccvector
name|unsigned
name|int
name|gccv
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|gccvector
name|unsigned
name|int
name|gccv1
init|=
name|gccv
decl_stmt|;
name|gccvector
name|int
name|gccv2
init|=
operator|(
name|gccvector
name|int
operator|)
name|gccv
decl_stmt|;
name|gccvector
name|unsigned
name|int
name|gccv3
init|=
name|v
decl_stmt|;
name|__vector
name|unsigned
name|int
name|av
init|=
name|gccv
decl_stmt|;
name|__vector
name|int
name|avi
init|=
operator|(
name|__vector
name|int
operator|)
name|gccv
decl_stmt|;
name|gccvector
name|unsigned
name|int
name|gv
init|=
name|v
decl_stmt|;
name|gccvector
name|int
name|gvi
init|=
operator|(
name|gccvector
name|int
operator|)
name|v
decl_stmt|;
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|unsigned
name|int
name|gv8
decl_stmt|;
name|gv8
operator|=
name|gccv
expr_stmt|;
comment|// expected-error {{assigning to '__attribute__((__vector_size__(2 * sizeof(unsigned int)))) unsigned int' from incompatible type '__attribute__((__vector_size__(4 * sizeof(unsigned int)))) unsigned int'}}
name|av
operator|=
name|gv8
expr_stmt|;
comment|// expected-error {{assigning to '__vector unsigned int' from incompatible type '__attribute__((__vector_size__(2 * sizeof(unsigned int)))) unsigned int'}}
name|v
operator|=
name|gccv
expr_stmt|;
name|__vector
name|unsigned
name|int
name|tv
init|=
name|gccv
decl_stmt|;
name|gccv
operator|=
name|v
expr_stmt|;
name|gccvector
name|unsigned
name|int
name|tgv
init|=
name|v
decl_stmt|;
block|}
end_function

end_unit

