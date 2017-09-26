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
operator|||
name|defined
argument_list|(
name|__ARM_EABI__
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
comment|/*  * Get expsign and mantissa as 16 bit and 64 bit ints from an 80 bit long  * double.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_LDBL80_WORDS
parameter_list|(
name|ix0
parameter_list|,
name|ix1
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   union IEEEl2bits ew_u;					\   ew_u.e = (d);							\   (ix0) = ew_u.xbits.expsign;					\   (ix1) = ew_u.xbits.man;					\ } while (0)
end_define

begin_comment
comment|/*  * Get expsign and mantissa as one 16 bit and two 64 bit ints from a 128 bit  * long double.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_LDBL128_WORDS
parameter_list|(
name|ix0
parameter_list|,
name|ix1
parameter_list|,
name|ix2
parameter_list|,
name|d
parameter_list|)
define|\
value|do {								\   union IEEEl2bits ew_u;					\   ew_u.e = (d);							\   (ix0) = ew_u.xbits.expsign;					\   (ix1) = ew_u.xbits.manh;					\   (ix2) = ew_u.xbits.manl;					\ } while (0)
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
comment|/*  * Set an 80 bit long double from a 16 bit int expsign and a 64 bit int  * mantissa.  */
end_comment

begin_define
define|#
directive|define
name|INSERT_LDBL80_WORDS
parameter_list|(
name|d
parameter_list|,
name|ix0
parameter_list|,
name|ix1
parameter_list|)
define|\
value|do {								\   union IEEEl2bits iw_u;					\   iw_u.xbits.expsign = (ix0);					\   iw_u.xbits.man = (ix1);					\   (d) = iw_u.e;							\ } while (0)
end_define

begin_comment
comment|/*  * Set a 128 bit long double from a 16 bit int expsign and two 64 bit ints  * comprising the mantissa.  */
end_comment

begin_define
define|#
directive|define
name|INSERT_LDBL128_WORDS
parameter_list|(
name|d
parameter_list|,
name|ix0
parameter_list|,
name|ix1
parameter_list|,
name|ix2
parameter_list|)
define|\
value|do {								\   union IEEEl2bits iw_u;					\   iw_u.xbits.expsign = (ix0);					\   iw_u.xbits.manh = (ix1);					\   iw_u.xbits.manl = (ix2);					\   (d) = iw_u.e;							\ } while (0)
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

begin_define
define|#
directive|define
name|ENTERV
parameter_list|()
define|\
value|fp_prec_t __oprec;			\ 						\ 	if ((__oprec = fpgetprec()) != FP_PE)	\ 		fpsetprec(FP_PE)
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|do {				\ 	if (__oprec != FP_PE)			\ 		fpsetprec(__oprec);		\ 	return;			\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTERI
parameter_list|()
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

begin_define
define|#
directive|define
name|ENTERV
parameter_list|()
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|return
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
comment|/*  * 2sum gives the same result as 2sumF without requiring |a|>= |b| or  * a == 0, but is slower.  */
end_comment

begin_define
define|#
directive|define
name|_2sum
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {	\ 	__typeof(a) __s, __w;	\ 				\ 	__w = (a) + (b);	\ 	__s = __w - (a);	\ 	(b) = ((a) - (__w - __s)) + ((b) - __s); \ 	(a) = __w;		\ } while (0)
end_define

begin_comment
comment|/*  * 2sumF algorithm.  *  * "Normalize" the terms in the infinite-precision expression a + b for  * the sum of 2 floating point values so that b is as small as possible  * relative to 'a'.  (The resulting 'a' is the value of the expression in  * the same precision as 'a' and the resulting b is the rounding error.)  * |a| must be>= |b| or 0, b's type must be no larger than 'a's type, and  * exponent overflow or underflow must not occur.  This uses a Theorem of  * Dekker (1971).  See Knuth (1981) 4.2.2 Theorem C.  The name "TwoSum"  * is apparently due to Skewchuk (1997).  *  * For this to always work, assignment of a + b to 'a' must not retain any  * extra precision in a + b.  This is required by C standards but broken  * in many compilers.  The brokenness cannot be worked around using  * STRICT_ASSIGN() like we do elsewhere, since the efficiency of this  * algorithm would be destroyed by non-null strict assignments.  (The  * compilers are correct to be broken -- the efficiency of all floating  * point code calculations would be destroyed similarly if they forced the  * conversions.)  *  * Fortunately, a case that works well can usually be arranged by building  * any extra precision into the type of 'a' -- 'a' should have type float_t,  * double_t or long double.  b's type should be no larger than 'a's type.  * Callers should use these types with scopes as large as possible, to  * reduce their own extra-precision and efficiciency problems.  In  * particular, they shouldn't convert back and forth just to call here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|_2sumF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {				\ 	__typeof(a) __w;				\ 	volatile __typeof(a) __ia, __ib, __r, __vw;	\ 							\ 	__ia = (a);					\ 	__ib = (b);					\ 	assert(__ia == 0 || fabsl(__ia)>= fabsl(__ib));	\ 							\ 	__w = (a) + (b);				\ 	(b) = ((a) - __w) + (b);			\ 	(a) = __w;					\ 							\
comment|/* The next 2 assertions are weak if (a) is already long double. */
value|\ 	assert((long double)__ia + __ib == (long double)(a) + (b));	\ 	__vw = __ia + __ib;				\ 	__r = __ia - __vw;				\ 	__r += __ib;					\ 	assert(__vw == (a)&& __r == (b));		\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG */
end_comment

begin_define
define|#
directive|define
name|_2sumF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|do {	\ 	__typeof(a) __w;	\ 				\ 	__w = (a) + (b);	\ 	(b) = ((a) - __w) + (b); \ 	(a) = __w;		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*  * Set x += c, where x is represented in extra precision as a + b.  * x must be sufficiently normalized and sufficiently larger than c,  * and the result is then sufficiently normalized.  *  * The details of ordering are that |a| must be>= |c| (so that (a, c)  * can be normalized without extra work to swap 'a' with c).  The details of  * the normalization are that b must be small relative to the normalized 'a'.  * Normalization of (a, c) makes the normalized c tiny relative to the  * normalized a, so b remains small relative to 'a' in the result.  However,  * b need not ever be tiny relative to 'a'.  For example, b might be about  * 2**20 times smaller than 'a' to give about 20 extra bits of precision.  * That is usually enough, and adding c (which by normalization is about  * 2**53 times smaller than a) cannot change b significantly.  However,  * cancellation of 'a' with c in normalization of (a, c) may reduce 'a'  * significantly relative to b.  The caller must ensure that significant  * cancellation doesn't occur, either by having c of the same sign as 'a',  * or by having |c| a few percent smaller than |a|.  Pre-normalization of  * (a, b) may help.  *  * This is is a variant of an algorithm of Kahan (see Knuth (1981) 4.2.2  * exercise 19).  We gain considerable efficiency by requiring the terms to  * be sufficiently normalized and sufficiently increasing.  */
end_comment

begin_define
define|#
directive|define
name|_3sumF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|do {	\ 	__typeof(a) __tmp;	\ 				\ 	__tmp = (c);		\ 	_2sumF(__tmp, (a));	\ 	(b) += (a);		\ 	(a) = __tmp;		\ } while (0)
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
comment|/*  * Inline functions that can be used to construct complex values.  *  * The C99 standard intends x+I*y to be used for this, but x+I*y is  * currently unusable in general since gcc introduces many overflow,  * underflow, sign and efficiency bugs by rewriting I*y as  * (0.0+I)*(y+0.0*I) and laboriously computing the full complex product.  * In particular, I*Inf is corrupted to NaN+I*Inf, and I*-0 is corrupted  * to -0.0+I*0.0.  *  * The C11 standard introduced the macros CMPLX(), CMPLXF() and CMPLXL()  * to construct complex values.  Compilers that conform to the C99  * standard require the following functions to avoid the above issues.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMPLXF
end_ifndef

begin_function
specifier|static
name|__inline
name|float
name|complex
name|CMPLXF
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CMPLX
end_ifndef

begin_function
specifier|static
name|__inline
name|double
name|complex
name|CMPLX
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CMPLXL
end_ifndef

begin_function
specifier|static
name|__inline
name|long
name|double
name|complex
name|CMPLXL
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

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

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

begin_define
define|#
directive|define
name|breakpoint
parameter_list|()
value|asm("int $3")
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|breakpoint
parameter_list|()
value|raise(SIGTRAP)
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
comment|/* Write a pari script to test things externally. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOPRINT
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DOPRINT_SWIZZLE
end_ifndef

begin_define
define|#
directive|define
name|DOPRINT_SWIZZLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOPRINT_LD80
end_ifdef

begin_define
define|#
directive|define
name|DOPRINT_START
parameter_list|(
name|xp
parameter_list|)
value|do {						\ 	uint64_t __lx;							\ 	uint16_t __hx;							\ 									\
comment|/* Hack to give more-problematic args. */
value|\ 	EXTRACT_LDBL80_WORDS(__hx, __lx, *xp);				\ 	__lx ^= DOPRINT_SWIZZLE;					\ 	INSERT_LDBL80_WORDS(*xp, __hx, __lx);				\ 	printf("x = %.21Lg; ", (long double)*xp);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END1
parameter_list|(
name|v
parameter_list|)
define|\
value|printf("y = %.21Lg; z = 0; show(x, y, z);\n", (long double)(v))
end_define

begin_define
define|#
directive|define
name|DOPRINT_END2
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
define|\
value|printf("y = %.21Lg; z = %.21Lg; show(x, y, z);\n",		\ 	    (long double)(hi), (long double)(lo))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DOPRINT_D64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DOPRINT_START
parameter_list|(
name|xp
parameter_list|)
value|do {						\ 	uint32_t __hx, __lx;						\ 									\ 	EXTRACT_WORDS(__hx, __lx, *xp);					\ 	__lx ^= DOPRINT_SWIZZLE;					\ 	INSERT_WORDS(*xp, __hx, __lx);					\ 	printf("x = %.21Lg; ", (long double)*xp);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END1
parameter_list|(
name|v
parameter_list|)
define|\
value|printf("y = %.21Lg; z = 0; show(x, y, z);\n", (long double)(v))
end_define

begin_define
define|#
directive|define
name|DOPRINT_END2
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
define|\
value|printf("y = %.21Lg; z = %.21Lg; show(x, y, z);\n",		\ 	    (long double)(hi), (long double)(lo))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DOPRINT_F32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DOPRINT_START
parameter_list|(
name|xp
parameter_list|)
value|do {						\ 	uint32_t __hx;							\ 									\ 	GET_FLOAT_WORD(__hx, *xp);					\ 	__hx ^= DOPRINT_SWIZZLE;					\ 	SET_FLOAT_WORD(*xp, __hx);					\ 	printf("x = %.21Lg; ", (long double)*xp);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END1
parameter_list|(
name|v
parameter_list|)
define|\
value|printf("y = %.21Lg; z = 0; show(x, y, z);\n", (long double)(v))
end_define

begin_define
define|#
directive|define
name|DOPRINT_END2
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
define|\
value|printf("y = %.21Lg; z = %.21Lg; show(x, y, z);\n",		\ 	    (long double)(hi), (long double)(lo))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DOPRINT_LD80&& !DOPRINT_D64 (LD128 only) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOPRINT_SWIZZLE_HIGH
end_ifndef

begin_define
define|#
directive|define
name|DOPRINT_SWIZZLE_HIGH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DOPRINT_START
parameter_list|(
name|xp
parameter_list|)
value|do {						\ 	uint64_t __lx, __llx;						\ 	uint16_t __hx;							\ 									\ 	EXTRACT_LDBL128_WORDS(__hx, __lx, __llx, *xp);			\ 	__llx ^= DOPRINT_SWIZZLE;					\ 	__lx ^= DOPRINT_SWIZZLE_HIGH;					\ 	INSERT_LDBL128_WORDS(*xp, __hx, __lx, __llx);			\ 	printf("x = %.36Lg; ", (long double)*xp);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END1
parameter_list|(
name|v
parameter_list|)
define|\
value|printf("y = %.36Lg; z = 0; show(x, y, z);\n", (long double)(v))
end_define

begin_define
define|#
directive|define
name|DOPRINT_END2
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
define|\
value|printf("y = %.36Lg; z = %.36Lg; show(x, y, z);\n",		\ 	    (long double)(hi), (long double)(lo))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOPRINT_LD80 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DOPRINT */
end_comment

begin_define
define|#
directive|define
name|DOPRINT_START
parameter_list|(
name|xp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END1
parameter_list|(
name|v
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DOPRINT_END2
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOPRINT */
end_comment

begin_define
define|#
directive|define
name|RETURNP
parameter_list|(
name|x
parameter_list|)
value|do {			\ 	DOPRINT_END1(x);		\ 	RETURNF(x);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNPI
parameter_list|(
name|x
parameter_list|)
value|do {		\ 	DOPRINT_END1(x);		\ 	RETURNI(x);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURN2P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {		\ 	DOPRINT_END2((x), (y));		\ 	RETURNF((x) + (y));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURN2PI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {		\ 	DOPRINT_END2((x), (y));		\ 	RETURNI((x) + (y));		\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STRUCT_RETURN
end_ifdef

begin_define
define|#
directive|define
name|RETURNSP
parameter_list|(
name|rp
parameter_list|)
value|do {		\ 	if (!(rp)->lo_set)		\ 		RETURNP((rp)->hi);	\ 	RETURN2P((rp)->hi, (rp)->lo);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNSPI
parameter_list|(
name|rp
parameter_list|)
value|do {		\ 	if (!(rp)->lo_set)		\ 		RETURNPI((rp)->hi);	\ 	RETURN2PI((rp)->hi, (rp)->lo);	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUM2P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|({			\ 	const __typeof (x) __x = (x);	\ 	const __typeof (y) __y = (y);	\ 					\ 	DOPRINT_END2(__x, __y);		\ 	__x + __y;			\ })
end_define

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

