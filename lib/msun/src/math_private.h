begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_comment
comment|/*  * from: @(#)fdlibm.h 5.1 93/09/24  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MATH_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MATH_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* The original fdlibm code used statements like: 	n0 = ((*(int*)&one)>>29)^1;		* index of high word * 	ix0 = *(n0+(int*)&x);			* high word of x * 	ix1 = *((1-n0)+(int*)&x);		* low word of x *    to dig two 32 bit words out of the 64 bit IEEE floating point    value.  That is non-ANSI, and, moreover, the gcc instruction    scheduler gets it wrong.  We instead use the following macros.    Unlike the original code, we determine the endianness at compile    time, not at run time; I don't see much benefit to selecting    endianness at run time.  */
end_comment

begin_comment
comment|/* A union which permits us to convert between a double and two 32 bit    ints.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_typedef
typedef|typedef
union|union
block|{
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|msw
decl_stmt|;
name|u_int32_t
name|lsw
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_double_shape_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_typedef
typedef|typedef
union|union
block|{
name|double
name|value
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|lsw
decl_stmt|;
name|u_int32_t
name|msw
decl_stmt|;
block|}
name|parts
struct|;
block|}
name|ieee_double_shape_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get two 32 bit ints from a double.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_WORDS
parameter_list|(
name|ix0
parameter_list|,
name|ix1
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type ew_u;					\   ew_u.value = (d);						\   (ix0) = ew_u.parts.msw;					\   (ix1) = ew_u.parts.lsw;					\ } while (0)
end_define

begin_comment
comment|/* Get the more significant 32 bit int from a double.  */
end_comment

begin_define
define|#
directive|define
name|GET_HIGH_WORD
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type gh_u;					\   gh_u.value = (d);						\   (i) = gh_u.parts.msw;						\ } while (0)
end_define

begin_comment
comment|/* Get the less significant 32 bit int from a double.  */
end_comment

begin_define
define|#
directive|define
name|GET_LOW_WORD
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type gl_u;					\   gl_u.value = (d);						\   (i) = gl_u.parts.lsw;						\ } while (0)
end_define

begin_comment
comment|/* Set a double from two 32 bit ints.  */
end_comment

begin_define
define|#
directive|define
name|INSERT_WORDS
parameter_list|(
name|d
parameter_list|,
name|ix0
parameter_list|,
name|ix1
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type iw_u;					\   iw_u.parts.msw = (ix0);					\   iw_u.parts.lsw = (ix1);					\   (d) = iw_u.value;						\ } while (0)
end_define

begin_comment
comment|/* Set the more significant 32 bits of a double from an int.  */
end_comment

begin_define
define|#
directive|define
name|SET_HIGH_WORD
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type sh_u;					\   sh_u.value = (d);						\   sh_u.parts.msw = (v);						\   (d) = sh_u.value;						\ } while (0)
end_define

begin_comment
comment|/* Set the less significant 32 bits of a double from an int.  */
end_comment

begin_define
define|#
directive|define
name|SET_LOW_WORD
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type sl_u;					\   sl_u.value = (d);						\   sl_u.parts.lsw = (v);						\   (d) = sl_u.value;						\ } while (0)
end_define

begin_comment
comment|/* A union which permits us to convert between a float and a 32 bit    int.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|value
decl_stmt|;
comment|/* FIXME: Assumes 32 bit int.  */
name|unsigned
name|int
name|word
decl_stmt|;
block|}
name|ieee_float_shape_type
typedef|;
end_typedef

begin_comment
comment|/* Get a 32 bit int from a float.  */
end_comment

begin_define
define|#
directive|define
name|GET_FLOAT_WORD
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_float_shape_type gf_u;					\   gf_u.value = (d);						\   (i) = gf_u.word;						\ } while (0)
end_define

begin_comment
comment|/* Set a float from a 32 bit int.  */
end_comment

begin_define
define|#
directive|define
name|SET_FLOAT_WORD
parameter_list|(
name|d
parameter_list|,
name|i
parameter_list|)
define|\
value|do {								\   ieee_float_shape_type sf_u;					\   sf_u.word = (i);						\   (d) = sf_u.value;						\ } while (0)
end_define

begin_comment
comment|/* ieee style elementary functions */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_sqrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_acos
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_acosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_log
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_atanh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_asin
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_atan2
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_exp
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_cosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_fmod
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_pow
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_lgamma_r
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_gamma_r
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_lgamma
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_gamma
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_log10
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_sinh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_hypot
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_j0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_j1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_y0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_y1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_jn
name|__P
argument_list|(
operator|(
name|int
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_yn
name|__P
argument_list|(
operator|(
name|int
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_remainder
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__ieee754_rem_pio2
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__ieee754_scalb
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fdlibm kernel function */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|__kernel_standard
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__kernel_sin
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__kernel_cos
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|__kernel_tan
name|__P
argument_list|(
operator|(
name|double
operator|,
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__kernel_rem_pio2
name|__P
argument_list|(
operator|(
name|double
operator|*
operator|,
name|double
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ieee style elementary float functions */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_sqrtf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_acosf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_acoshf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_logf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_atanhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_asinf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_atan2f
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_expf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_coshf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_fmodf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_powf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_lgammaf_r
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_gammaf_r
name|__P
argument_list|(
operator|(
name|float
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_lgammaf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_gammaf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_log10f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_sinhf
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_hypotf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_j0f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_j1f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_y0f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_y1f
name|__P
argument_list|(
operator|(
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_jnf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_ynf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_remainderf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__ieee754_rem_pio2f
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__ieee754_scalbf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* float versions of fdlibm kernel functions */
end_comment

begin_decl_stmt
specifier|extern
name|float
name|__kernel_sinf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__kernel_cosf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|__kernel_tanf
name|__P
argument_list|(
operator|(
name|float
operator|,
name|float
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__kernel_rem_pio2f
name|__P
argument_list|(
operator|(
name|float
operator|*
operator|,
name|float
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|__generic___ieee754_acos
value|__ieee754_acos
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_asin
value|__ieee754_asin
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_atan2
value|__ieee754_atan2
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_exp
value|__ieee754_exp
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_fmod
value|__ieee754_fmod
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_log
value|__ieee754_log
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_log10
value|__ieee754_log10
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_remainder
value|__ieee754_remainder
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_scalb
value|__ieee754_scalb
end_define

begin_define
define|#
directive|define
name|__generic___ieee754_sqrt
value|__ieee754_sqrt
end_define

begin_define
define|#
directive|define
name|__generic_atan
value|atan
end_define

begin_define
define|#
directive|define
name|__generic_ceil
value|ceil
end_define

begin_define
define|#
directive|define
name|__generic_copysign
value|copysign
end_define

begin_define
define|#
directive|define
name|__generic_cos
value|cos
end_define

begin_define
define|#
directive|define
name|__generic_finite
value|finite
end_define

begin_define
define|#
directive|define
name|__generic_floor
value|floor
end_define

begin_define
define|#
directive|define
name|__generic_ilogb
value|ilogb
end_define

begin_define
define|#
directive|define
name|__generic_log1p
value|log1p
end_define

begin_define
define|#
directive|define
name|__generic_logb
value|logb
end_define

begin_define
define|#
directive|define
name|__generic_rint
value|rint
end_define

begin_define
define|#
directive|define
name|__generic_scalbn
value|scalbn
end_define

begin_define
define|#
directive|define
name|__generic_significand
value|significand
end_define

begin_define
define|#
directive|define
name|__generic_sin
value|sin
end_define

begin_define
define|#
directive|define
name|__generic_tan
value|tan
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MATH_PRIVATE_H_ */
end_comment

end_unit

