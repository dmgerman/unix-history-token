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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * The original fdlibm code used statements like:  *	n0 = ((*(int*)&one)>>29)^1;		* index of high word *  *	ix0 = *(n0+(int*)&x);			* high word of x *  *	ix1 = *((1-n0)+(int*)&x);		* low word of x *  * to dig two 32 bit words out of the 64 bit IEEE floating point  * value.  That is non-ANSI, and, moreover, the gcc instruction  * scheduler gets it wrong.  We instead use the following macros.  * Unlike the original code, we determine the endianness at compile  * time, not at run time; I don't see much benefit to selecting  * endianness at run time.  */
end_comment

begin_comment
comment|/*  * A union which permits us to convert between a double and two 32 bit  * ints.  */
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
comment|/*  * A union which permits us to convert between a float and a 32 bit  * int.  */
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

begin_function_decl
name|double
name|__ieee754_sqrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_acos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_acosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_log
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_atanh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_asin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_atan2
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_exp
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_cosh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_fmod
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_lgamma_r
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_gamma_r
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_lgamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_gamma
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_log10
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_sinh
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_hypot
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_j0
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_j1
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_y0
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_y1
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_jn
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_yn
parameter_list|(
name|int
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_remainder
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__ieee754_rem_pio2
parameter_list|(
name|double
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__ieee754_scalb
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fdlibm kernel function */
end_comment

begin_function_decl
name|double
name|__kernel_standard
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__kernel_sin
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__kernel_cos
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__kernel_tan
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__kernel_rem_pio2
parameter_list|(
name|double
modifier|*
parameter_list|,
name|double
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ieee style elementary float functions */
end_comment

begin_function_decl
name|float
name|__ieee754_sqrtf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_acosf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_acoshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_logf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_atanhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_asinf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_atan2f
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_expf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_coshf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_fmodf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_powf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_lgammaf_r
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_gammaf_r
parameter_list|(
name|float
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_lgammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_gammaf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_log10f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_sinhf
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_hypotf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_j0f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_j1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_y0f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_y1f
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_jnf
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_ynf
parameter_list|(
name|int
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_remainderf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__ieee754_rem_pio2f
parameter_list|(
name|float
parameter_list|,
name|float
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__ieee754_scalbf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* float versions of fdlibm kernel functions */
end_comment

begin_function_decl
name|float
name|__kernel_sinf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__kernel_cosf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__kernel_tanf
parameter_list|(
name|float
parameter_list|,
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__kernel_rem_pio2f
parameter_list|(
name|float
modifier|*
parameter_list|,
name|float
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_if

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
comment|/* !_MATH_PRIVATE_H_ */
end_comment

end_unit

