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

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__VFP_FP__
argument_list|)
end_if

begin_define
define|#
directive|define
name|IEEE_WORD_ORDER
value|BYTE_ORDER
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IEEE_WORD_ORDER
value|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __arm__ */
end_comment

begin_define
define|#
directive|define
name|IEEE_WORD_ORDER
value|BYTE_ORDER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IEEE_WORD_ORDER
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
struct|struct
block|{
name|u_int64_t
name|w
decl_stmt|;
block|}
name|xparts
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
name|IEEE_WORD_ORDER
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
struct|struct
block|{
name|u_int64_t
name|w
decl_stmt|;
block|}
name|xparts
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
comment|/* Get a 64-bit int from a double. */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_WORD64
parameter_list|(
name|ix
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type ew_u;					\   ew_u.value = (d);						\   (ix) = ew_u.xparts.w;						\ } while (0)
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
comment|/* Set a double from a 64-bit int. */
end_comment

begin_define
define|#
directive|define
name|INSERT_WORD64
parameter_list|(
name|d
parameter_list|,
name|ix
parameter_list|)
define|\
value|do {								\   ieee_double_shape_type iw_u;					\   iw_u.xparts.w = (ix);						\   (d) = iw_u.value;						\ } while (0)
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
comment|/* Get expsign as a 16 bit int from a long double.  */
end_comment

begin_define
define|#
directive|define
name|GET_LDBL_EXPSIGN
parameter_list|(
name|i
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   union IEEEl2bits ge_u;					\   ge_u.e = (d);							\   (i) = ge_u.xbits.expsign;					\ } while (0)
end_define

begin_comment
comment|/* Set expsign of a long double from a 16 bit int.  */
end_comment

begin_define
define|#
directive|define
name|SET_LDBL_EXPSIGN
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
define|\
value|do {								\   union IEEEl2bits se_u;					\   se_u.e = (d);							\   se_u.xbits.expsign = (v);					\   (d) = se_u.e;							\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/* Long double constants are broken on i386. */
end_comment

begin_define
define|#
directive|define
name|LD80C
parameter_list|(
name|m
parameter_list|,
name|ex
parameter_list|,
name|v
parameter_list|)
value|{						\ 	.xbits.man = __CONCAT(m, ULL),					\ 	.xbits.expsign = (0x3fff + (ex)) | ((v)< 0 ? 0x8000 : 0),	\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The above works on non-i386 too, but we use this to check v. */
end_comment

begin_define
define|#
directive|define
name|LD80C
parameter_list|(
name|m
parameter_list|,
name|ex
parameter_list|,
name|v
parameter_list|)
value|{ .e = (v), }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLT_EVAL_METHOD
end_ifdef

begin_comment
comment|/*  * Attempt to get strict C99 semantics for assignment with non-C99 compilers.  */
end_comment

begin_if
if|#
directive|if
name|FLT_EVAL_METHOD
operator|==
literal|0
operator|||
name|__GNUC__
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|STRICT_ASSIGN
parameter_list|(
name|type
parameter_list|,
name|lval
parameter_list|,
name|rval
parameter_list|)
value|((lval) = (rval))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRICT_ASSIGN
parameter_list|(
name|type
parameter_list|,
name|lval
parameter_list|,
name|rval
parameter_list|)
value|do {	\ 	volatile type __lval;			\ 						\ 	if (sizeof(type)>= sizeof(long double))	\ 		(lval) = (rval);		\ 	else {					\ 		__lval = (rval);		\ 		(lval) = __lval;		\ 	}					\ } while (0)
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
comment|/* FLT_EVAL_METHOD */
end_comment

begin_comment
comment|/* Support switching the mode to FP_PE if necessary. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_FPSETPREC
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENTERI
parameter_list|()
define|\
value|long double __retval;			\ 	fp_prec_t __oprec;			\ 						\ 	if ((__oprec = fpgetprec()) != FP_PE)	\ 		fpsetprec(FP_PE)
end_define

begin_define
define|#
directive|define
name|RETURNI
parameter_list|(
name|x
parameter_list|)
value|do {				\ 	__retval = (x);				\ 	if (__oprec != FP_PE)			\ 		fpsetprec(__oprec);		\ 	RETURNF(__retval);			\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTERI
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RETURNI
parameter_list|(
name|x
parameter_list|)
value|RETURNF(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default return statement if hack*_t() is not used. */
end_comment

begin_define
define|#
directive|define
name|RETURNF
parameter_list|(
name|v
parameter_list|)
value|return (v)
end_define

begin_comment
comment|/*  * Common routine to process the arguments to nan(), nanf(), and nanl().  */
end_comment

begin_function_decl
name|void
name|_scan_nan
parameter_list|(
name|uint32_t
modifier|*
name|__words
parameter_list|,
name|int
name|__num_words
parameter_list|,
specifier|const
name|char
modifier|*
name|__s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_COMPLEX_H
end_ifdef

begin_comment
comment|/*  * C99 specifies that complex numbers have the same representation as  * an array of two elements, where the first element is the real part  * and the second element is the imaginary part.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|complex
name|f
decl_stmt|;
name|float
name|a
index|[
literal|2
index|]
decl_stmt|;
block|}
name|float_complex
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|double
name|complex
name|f
decl_stmt|;
name|double
name|a
index|[
literal|2
index|]
decl_stmt|;
block|}
name|double_complex
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|long
name|double
name|complex
name|f
decl_stmt|;
name|long
name|double
name|a
index|[
literal|2
index|]
decl_stmt|;
block|}
name|long_double_complex
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REALPART
parameter_list|(
name|z
parameter_list|)
value|((z).a[0])
end_define

begin_define
define|#
directive|define
name|IMAGPART
parameter_list|(
name|z
parameter_list|)
value|((z).a[1])
end_define

begin_comment
comment|/*  * Inline functions that can be used to construct complex values.  *  * The C99 standard intends x+I*y to be used for this, but x+I*y is  * currently unusable in general since gcc introduces many overflow,  * underflow, sign and efficiency bugs by rewriting I*y as  * (0.0+I)*(y+0.0*I) and laboriously computing the full complex product.  * In particular, I*Inf is corrupted to NaN+I*Inf, and I*-0 is corrupted  * to -0.0+I*0.0.  */
end_comment

begin_function
specifier|static
name|__inline
name|float
name|complex
name|cpackf
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
name|float_complex
name|z
decl_stmt|;
name|REALPART
argument_list|(
name|z
argument_list|)
operator|=
name|x
expr_stmt|;
name|IMAGPART
argument_list|(
name|z
argument_list|)
operator|=
name|y
expr_stmt|;
return|return
operator|(
name|z
operator|.
name|f
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|double
name|complex
name|cpack
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
name|double_complex
name|z
decl_stmt|;
name|REALPART
argument_list|(
name|z
argument_list|)
operator|=
name|x
expr_stmt|;
name|IMAGPART
argument_list|(
name|z
argument_list|)
operator|=
name|y
expr_stmt|;
return|return
operator|(
name|z
operator|.
name|f
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|long
name|double
name|complex
name|cpackl
parameter_list|(
name|long
name|double
name|x
parameter_list|,
name|long
name|double
name|y
parameter_list|)
block|{
name|long_double_complex
name|z
decl_stmt|;
name|REALPART
argument_list|(
name|z
argument_list|)
operator|=
name|x
expr_stmt|;
name|IMAGPART
argument_list|(
name|z
argument_list|)
operator|=
name|y
expr_stmt|;
return|return
operator|(
name|z
operator|.
name|f
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPLEX_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
end_ifdef

begin_comment
comment|/* Asm versions of some functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_function
specifier|static
name|__inline
name|int
name|irint
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
asm|asm("cvtsd2si %1,%0" : "=r" (n) : "x" (x));
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_EFFICIENT_IRINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function
specifier|static
name|__inline
name|int
name|irint
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
asm|asm("fistl %0" : "=m" (n) : "t" (x));
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_EFFICIENT_IRINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|int
name|irintl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
asm|asm("fistl %0" : "=m" (n) : "t" (x));
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_EFFICIENT_IRINTL
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
comment|/* __GNUCLIKE_ASM */
end_comment

begin_comment
comment|/*  * ieee style elementary functions  *  * We rename functions here to improve other sources' diffability  * against fdlibm.  */
end_comment

begin_define
define|#
directive|define
name|__ieee754_sqrt
value|sqrt
end_define

begin_define
define|#
directive|define
name|__ieee754_acos
value|acos
end_define

begin_define
define|#
directive|define
name|__ieee754_acosh
value|acosh
end_define

begin_define
define|#
directive|define
name|__ieee754_log
value|log
end_define

begin_define
define|#
directive|define
name|__ieee754_log2
value|log2
end_define

begin_define
define|#
directive|define
name|__ieee754_atanh
value|atanh
end_define

begin_define
define|#
directive|define
name|__ieee754_asin
value|asin
end_define

begin_define
define|#
directive|define
name|__ieee754_atan2
value|atan2
end_define

begin_define
define|#
directive|define
name|__ieee754_exp
value|exp
end_define

begin_define
define|#
directive|define
name|__ieee754_cosh
value|cosh
end_define

begin_define
define|#
directive|define
name|__ieee754_fmod
value|fmod
end_define

begin_define
define|#
directive|define
name|__ieee754_pow
value|pow
end_define

begin_define
define|#
directive|define
name|__ieee754_lgamma
value|lgamma
end_define

begin_define
define|#
directive|define
name|__ieee754_gamma
value|gamma
end_define

begin_define
define|#
directive|define
name|__ieee754_lgamma_r
value|lgamma_r
end_define

begin_define
define|#
directive|define
name|__ieee754_gamma_r
value|gamma_r
end_define

begin_define
define|#
directive|define
name|__ieee754_log10
value|log10
end_define

begin_define
define|#
directive|define
name|__ieee754_sinh
value|sinh
end_define

begin_define
define|#
directive|define
name|__ieee754_hypot
value|hypot
end_define

begin_define
define|#
directive|define
name|__ieee754_j0
value|j0
end_define

begin_define
define|#
directive|define
name|__ieee754_j1
value|j1
end_define

begin_define
define|#
directive|define
name|__ieee754_y0
value|y0
end_define

begin_define
define|#
directive|define
name|__ieee754_y1
value|y1
end_define

begin_define
define|#
directive|define
name|__ieee754_jn
value|jn
end_define

begin_define
define|#
directive|define
name|__ieee754_yn
value|yn
end_define

begin_define
define|#
directive|define
name|__ieee754_remainder
value|remainder
end_define

begin_define
define|#
directive|define
name|__ieee754_scalb
value|scalb
end_define

begin_define
define|#
directive|define
name|__ieee754_sqrtf
value|sqrtf
end_define

begin_define
define|#
directive|define
name|__ieee754_acosf
value|acosf
end_define

begin_define
define|#
directive|define
name|__ieee754_acoshf
value|acoshf
end_define

begin_define
define|#
directive|define
name|__ieee754_logf
value|logf
end_define

begin_define
define|#
directive|define
name|__ieee754_atanhf
value|atanhf
end_define

begin_define
define|#
directive|define
name|__ieee754_asinf
value|asinf
end_define

begin_define
define|#
directive|define
name|__ieee754_atan2f
value|atan2f
end_define

begin_define
define|#
directive|define
name|__ieee754_expf
value|expf
end_define

begin_define
define|#
directive|define
name|__ieee754_coshf
value|coshf
end_define

begin_define
define|#
directive|define
name|__ieee754_fmodf
value|fmodf
end_define

begin_define
define|#
directive|define
name|__ieee754_powf
value|powf
end_define

begin_define
define|#
directive|define
name|__ieee754_lgammaf
value|lgammaf
end_define

begin_define
define|#
directive|define
name|__ieee754_gammaf
value|gammaf
end_define

begin_define
define|#
directive|define
name|__ieee754_lgammaf_r
value|lgammaf_r
end_define

begin_define
define|#
directive|define
name|__ieee754_gammaf_r
value|gammaf_r
end_define

begin_define
define|#
directive|define
name|__ieee754_log10f
value|log10f
end_define

begin_define
define|#
directive|define
name|__ieee754_log2f
value|log2f
end_define

begin_define
define|#
directive|define
name|__ieee754_sinhf
value|sinhf
end_define

begin_define
define|#
directive|define
name|__ieee754_hypotf
value|hypotf
end_define

begin_define
define|#
directive|define
name|__ieee754_j0f
value|j0f
end_define

begin_define
define|#
directive|define
name|__ieee754_j1f
value|j1f
end_define

begin_define
define|#
directive|define
name|__ieee754_y0f
value|y0f
end_define

begin_define
define|#
directive|define
name|__ieee754_y1f
value|y1f
end_define

begin_define
define|#
directive|define
name|__ieee754_jnf
value|jnf
end_define

begin_define
define|#
directive|define
name|__ieee754_ynf
value|ynf
end_define

begin_define
define|#
directive|define
name|__ieee754_remainderf
value|remainderf
end_define

begin_define
define|#
directive|define
name|__ieee754_scalbf
value|scalbf
end_define

begin_comment
comment|/* fdlibm kernel function */
end_comment

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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* double precision kernel functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_REM_PIO2
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

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
name|double
name|__ldexp_exp
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_COMPLEX_H
end_ifdef

begin_function_decl
name|double
name|complex
name|__ldexp_cexp
parameter_list|(
name|double
name|complex
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* float precision kernel functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_REM_PIO2F
end_ifndef

begin_function_decl
name|int
name|__ieee754_rem_pio2f
parameter_list|(
name|float
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_SINDF
end_ifndef

begin_function_decl
name|float
name|__kernel_sindf
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_COSDF
end_ifndef

begin_function_decl
name|float
name|__kernel_cosdf
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_TANDF
end_ifndef

begin_function_decl
name|float
name|__kernel_tandf
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|float
name|__ldexp_expf
parameter_list|(
name|float
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_COMPLEX_H
end_ifdef

begin_function_decl
name|float
name|complex
name|__ldexp_cexpf
parameter_list|(
name|float
name|complex
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* long double precision kernel functions */
end_comment

begin_function_decl
name|long
name|double
name|__kernel_sinl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|__kernel_cosl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|__kernel_tanl
parameter_list|(
name|long
name|double
parameter_list|,
name|long
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MATH_PRIVATE_H_ */
end_comment

end_unit

