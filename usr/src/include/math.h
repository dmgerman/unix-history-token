begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  * All recipients should regard themselves as participants in an ongoing  * research project and hence should feel obligated to report their  * experiences (good or bad) with these elementary function codes, using  * the sendbug(8) program, to the authors.  *  *	@(#)math.h	5.4 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MATH_H_
end_ifndef

begin_define
define|#
directive|define
name|_MATH_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|HUGE_VAL
value|1.701411733192644270e38
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VAL
value|1e500
end_define

begin_comment
comment|/* positive infinity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HUGE
value|HUGE_VAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|double
name|acos
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|asin
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|atan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|atan2
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
name|double
name|ceil
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|cos
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|cosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|exp
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|fabs
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|floor
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|fmod
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
name|double
name|frexp
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
name|double
name|ldexp
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log10
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|modf
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
name|double
name|pow
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
name|double
name|sin
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|sinh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|sqrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|tan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|tanh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_decl_stmt
name|double
name|acosh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|asinh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|atanh
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|cabs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* we can't describe cabs()'s argument properly */
end_comment

begin_decl_stmt
name|double
name|cbrt
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|copysign
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
name|double
name|drem
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
name|double
name|erf
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|erfc
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|expm1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|finite
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|hypot
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_decl_stmt
name|double
name|infnan
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|isnan
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|double
name|j0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|j1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|jn
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
name|double
name|lgamma
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log1p
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|logb
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|rint
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|scalb
name|__P
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|y0
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|y1
name|__P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|yn
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

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MATH_H_ */
end_comment

end_unit

