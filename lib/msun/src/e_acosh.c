begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)e_acosh.c 5.1 93/09/24 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ieee754_acosh(x)  * Method :  *	Based on  *		acosh(x) = log [ x + sqrt(x*x-1) ]  *	we have  *		acosh(x) := log(x)+ln2,	if x is large; else  *		acosh(x) := log(2x-1/(sqrt(x*x-1)+x)) if x>2; else  *		acosh(x) := log1p(t+sqrt(2.0*t+t*t)); where t=x-1.  *  * Special cases:  *	acosh(x) is NaN with signal if x<1.  *	acosh(NaN) is NaN without signal.  */
end_comment

begin_include
include|#
directive|include
file|"math.h"
end_include

begin_include
include|#
directive|include
file|"math_private.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|double
else|#
directive|else
specifier|static
name|double
endif|#
directive|endif
name|one
init|=
literal|1.0
decl_stmt|,
name|ln2
init|=
literal|6.93147180559945286227e-01
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x3FE62E42, 0xFEFA39EF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|double
name|__ieee754_acosh
parameter_list|(
name|double
name|x
parameter_list|)
else|#
directive|else
function|double __ieee754_acosh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
endif|#
directive|endif
block|{
name|double
name|t
decl_stmt|;
name|int32_t
name|hx
decl_stmt|;
name|u_int32_t
name|lx
decl_stmt|;
name|EXTRACT_WORDS
argument_list|(
name|hx
argument_list|,
name|lx
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|hx
operator|<
literal|0x3ff00000
condition|)
block|{
comment|/* x< 1 */
return|return
operator|(
name|x
operator|-
name|x
operator|)
operator|/
operator|(
name|x
operator|-
name|x
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|hx
operator|>=
literal|0x41b00000
condition|)
block|{
comment|/* x> 2**28 */
if|if
condition|(
name|hx
operator|>=
literal|0x7ff00000
condition|)
block|{
comment|/* x is inf of NaN */
return|return
name|x
operator|+
name|x
return|;
block|}
else|else
return|return
name|__ieee754_log
argument_list|(
name|x
argument_list|)
operator|+
name|ln2
return|;
comment|/* acosh(huge)=log(2x) */
block|}
elseif|else
if|if
condition|(
operator|(
operator|(
name|hx
operator|-
literal|0x3ff00000
operator|)
operator||
name|lx
operator|)
operator|==
literal|0
condition|)
block|{
return|return
literal|0.0
return|;
comment|/* acosh(1) = 0 */
block|}
elseif|else
if|if
condition|(
name|hx
operator|>
literal|0x40000000
condition|)
block|{
comment|/* 2**28> x> 2 */
name|t
operator|=
name|x
operator|*
name|x
expr_stmt|;
return|return
name|__ieee754_log
argument_list|(
literal|2.0
operator|*
name|x
operator|-
name|one
operator|/
operator|(
name|x
operator|+
name|__ieee754_sqrt
argument_list|(
name|t
operator|-
name|one
argument_list|)
operator|)
argument_list|)
return|;
block|}
else|else
block|{
comment|/* 1<x<2 */
name|t
operator|=
name|x
operator|-
name|one
expr_stmt|;
return|return
name|log1p
argument_list|(
name|t
operator|+
name|__ieee754_sqrt
argument_list|(
literal|2.0
operator|*
name|t
operator|+
name|t
operator|*
name|t
argument_list|)
argument_list|)
return|;
block|}
block|}
end_function

end_unit

