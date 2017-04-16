begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc-apple-darwin8 -target-feature +altivec -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc64-unknown-linux-gnu -target-feature +altivec -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple=powerpc64le-unknown-linux-gnu -target-feature +altivec -fsyntax-only -verify %s
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
name|char
name|vv_bc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|bool
name|short
name|vv_bs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|bool
name|int
name|vv_bi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|__bool
name|char
name|vv___bc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|__bool
name|short
name|vv___bs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__vector
name|__bool
name|int
name|vv___bi
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
name|char
name|v_bc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|short
name|v_bs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|bool
name|int
name|v_bi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|__bool
name|char
name|v___bc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|__bool
name|short
name|v___bs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|__bool
name|int
name|v___bi
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
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|long
name|double
name|v_ld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|v_b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|v___b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}}
end_comment

begin_comment
comment|// These should have errors.
end_comment

begin_decl_stmt
name|__vector
name|double
name|vv_d1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'double' with '__vector' requires VSX support to be enabled (available on POWER7 or later)}}
end_comment

begin_decl_stmt
name|vector
name|double
name|v_d2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'double' with '__vector' requires VSX support to be enabled (available on POWER7 or later)}}
end_comment

begin_decl_stmt
name|__vector
name|bool
name|long
name|long
name|v_bll1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'long long' with '__vector bool' requires VSX support (available on POWER7 or later) or extended Altivec support (available on POWER8 or later) to be enabled}}
end_comment

begin_decl_stmt
name|__vector
name|__bool
name|long
name|long
name|v_bll2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'long long' with '__vector bool' requires VSX support (available on POWER7 or later) or extended Altivec support (available on POWER8 or later) to be enabled}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|long
name|long
name|v_bll3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'long long' with '__vector bool' requires VSX support (available on POWER7 or later) or extended Altivec support (available on POWER8 or later) to be enabled}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|long
name|long
name|v_bll4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{use of 'long long' with '__vector bool' requires VSX support (available on POWER7 or later) or extended Altivec support (available on POWER8 or later) to be enabled}}
end_comment

begin_decl_stmt
name|__vector
name|long
name|double
name|vv_ld3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|long
name|double
name|v_ld4
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long double' with '__vector'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|float
name|v_bf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'float' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|double
name|v_bd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|pixel
name|v_bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use '__pixel' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|signed
name|char
name|v_bsc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'signed' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|unsigned
name|int
name|v_bsc2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'unsigned' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|bool
name|long
name|v_bl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|float
name|v___bf
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'float' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|double
name|v___bd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'double' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|pixel
name|v___bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use '__pixel' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|signed
name|char
name|v___bsc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'signed' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|unsigned
name|int
name|v___bsc2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'unsigned' with '__vector bool'}}
end_comment

begin_decl_stmt
name|vector
name|__bool
name|long
name|v___bl
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{cannot use 'long' with '__vector bool'}}
end_comment

begin_comment
comment|// vector long is deprecated, but vector long long is not.
end_comment

begin_decl_stmt
name|vector
name|long
name|long
name|v_ll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|signed
name|long
name|long
name|v_sll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|unsigned
name|long
name|long
name|v_ull
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|char
name|i8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|i16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|i32
typedef|;
end_typedef

begin_struct
struct|struct
name|S
block|{
comment|// i8, i16, i32 here are field names, not type names.
name|vector
name|bool
name|i8
decl_stmt|;
comment|// expected-error {{requires a specifier or qualifier}}
name|vector
name|pixel
name|i16
decl_stmt|;
name|vector
name|long
name|i32
decl_stmt|;
comment|// expected-warning {{deprecated}}
block|}
struct|;
end_struct

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
comment|// expected-error {{assigning to '__attribute__((__vector_size__(2 * sizeof(unsigned int)))) unsigned int' (vector of 2 'unsigned int' values) from incompatible type '__attribute__((__vector_size__(4 * sizeof(unsigned int)))) unsigned int' (vector of 4 'unsigned int' values)}}
name|av
operator|=
name|gv8
expr_stmt|;
comment|// expected-error {{assigning to '__vector unsigned int' (vector of 4 'unsigned int' values) from incompatible type '__attribute__((__vector_size__(2 * sizeof(unsigned int)))) unsigned int' (vector of 2 'unsigned int' values)}}
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
name|int
name|res_i
decl_stmt|;
comment|// bug 7553 - Problem with '==' and vectors
name|res_i
operator|=
operator|(
name|vv_sc
operator|==
name|vv_sc
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_uc
operator|!=
name|vv_uc
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_s
operator|>
name|vv_s
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_us
operator|>=
name|vv_us
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_i
operator|<
name|vv_i
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_ui
operator|<=
name|vv_ui
operator|)
expr_stmt|;
name|res_i
operator|=
operator|(
name|vv_f
operator|<=
name|vv_f
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// bug 6895 - Vectorl literal casting confusion.
end_comment

begin_decl_stmt
name|vector
name|char
name|v1
init|=
call|(
name|vector
name|char
call|)
argument_list|(
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|char
name|v2
init|=
call|(
name|vector
name|char
call|)
argument_list|(
call|(
name|vector
name|float
call|)
argument_list|(
literal|1.0f
argument_list|,
literal|2.0f
argument_list|,
literal|3.0f
argument_list|,
literal|4.0f
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|char
name|v3
init|=
call|(
name|vector
name|char
call|)
argument_list|(
call|(
name|vector
name|int
call|)
argument_list|(
literal|'a'
argument_list|,
literal|'b'
argument_list|,
literal|'c'
argument_list|,
literal|'d'
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|int
name|v4
init|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|float
name|v5
init|=
call|(
name|vector
name|float
call|)
argument_list|(
literal|1.0f
argument_list|,
literal|2.0f
argument_list|,
literal|3.0f
argument_list|,
literal|4.0f
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector
name|char
name|v6
init|=
call|(
name|vector
name|char
call|)
argument_list|(
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
operator|+
literal|2
argument_list|,
operator|-
literal|2
argument_list|,
call|(
name|int
call|)
argument_list|(
literal|2.0
operator|*
literal|3
argument_list|)
argument_list|,
operator|-
operator|(
literal|5
operator|-
literal|3
operator|)
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

