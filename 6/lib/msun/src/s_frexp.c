begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)s_frexp.c 5.1 93/09/24 */
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
comment|/*  * for non-zero x  *	x = frexp(arg,&exp);  * return a double fp quantity x such that 0.5<= |x|<1.0  * and the corresponding binary exponent "exp". That is  *	arg = x*2^exp.  * If arg is inf, 0.0, or NaN, then frexp(arg,&exp) returns arg  * with *exp=0.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

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

begin_decl_stmt
specifier|static
specifier|const
name|double
name|two54
init|=
literal|1.80143985094819840000e+16
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0x43500000, 0x00000000 */
end_comment

begin_function
name|double
name|frexp
parameter_list|(
name|double
name|x
parameter_list|,
name|int
modifier|*
name|eptr
parameter_list|)
block|{
name|int32_t
name|hx
decl_stmt|,
name|ix
decl_stmt|,
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
name|ix
operator|=
literal|0x7fffffff
operator|&
name|hx
expr_stmt|;
operator|*
name|eptr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ix
operator|>=
literal|0x7ff00000
operator|||
operator|(
operator|(
name|ix
operator||
name|lx
operator|)
operator|==
literal|0
operator|)
condition|)
return|return
name|x
return|;
comment|/* 0,inf,nan */
if|if
condition|(
name|ix
operator|<
literal|0x00100000
condition|)
block|{
comment|/* subnormal */
name|x
operator|*=
name|two54
expr_stmt|;
name|GET_HIGH_WORD
argument_list|(
name|hx
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|ix
operator|=
name|hx
operator|&
literal|0x7fffffff
expr_stmt|;
operator|*
name|eptr
operator|=
operator|-
literal|54
expr_stmt|;
block|}
operator|*
name|eptr
operator|+=
operator|(
name|ix
operator|>>
literal|20
operator|)
operator|-
literal|1022
expr_stmt|;
name|hx
operator|=
operator|(
name|hx
operator|&
literal|0x800fffff
operator|)
operator||
literal|0x3fe00000
expr_stmt|;
name|SET_HIGH_WORD
argument_list|(
name|x
argument_list|,
name|hx
argument_list|)
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_if
if|#
directive|if
operator|(
name|LDBL_MANT_DIG
operator|==
literal|53
operator|)
end_if

begin_expr_stmt
name|__weak_reference
argument_list|(
name|frexp
argument_list|,
name|frexpl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

