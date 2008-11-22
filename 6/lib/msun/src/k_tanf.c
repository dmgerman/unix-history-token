begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* k_tanf.c -- float version of k_tan.c  * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.  * Optimized by Bruce D. Evans.  */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright 2004 Sun Microsystems, Inc.  All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE_KERNEL_TANDF
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* |tan(x)/x - t(x)|< 2**-25.5 (~[-2e-08, 2e-08]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|T
index|[]
init|=
block|{
literal|0x15554d3418c99f
literal|.0p
operator|-
literal|54
block|,
comment|/* 0.333331395030791399758 */
literal|0x1112fd38999f72
literal|.0p
operator|-
literal|55
block|,
comment|/* 0.133392002712976742718 */
literal|0x1b54c91d865afe
literal|.0p
operator|-
literal|57
block|,
comment|/* 0.0533812378445670393523 */
literal|0x191df3908c33ce
literal|.0p
operator|-
literal|58
block|,
comment|/* 0.0245283181166547278873 */
literal|0x185dadfcecf44e
literal|.0p
operator|-
literal|61
block|,
comment|/* 0.00297435743359967304927 */
literal|0x1362b9bf971bcd
literal|.0p
operator|-
literal|59
block|,
comment|/* 0.00946564784943673166728 */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INLINE_KERNEL_TANDF
end_ifdef

begin_function
specifier|extern
specifier|inline
endif|#
directive|endif
name|float
name|__kernel_tandf
parameter_list|(
name|double
name|x
parameter_list|,
name|int
name|iy
parameter_list|)
block|{
name|double
name|z
decl_stmt|,
name|r
decl_stmt|,
name|w
decl_stmt|,
name|s
decl_stmt|,
name|t
decl_stmt|,
name|u
decl_stmt|;
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
comment|/* 	 * Split up the polynomial into small independent terms to give 	 * opportunities for parallel evaluation.  The chosen splitting is 	 * micro-optimized for Athlons (XP, X64).  It costs 2 multiplications 	 * relative to Horner's method on sequential machines. 	 * 	 * We add the small terms from lowest degree up for efficiency on 	 * non-sequential machines (the lowest degree terms tend to be ready 	 * earlier).  Apart from this, we don't care about order of 	 * operations, and don't need to to care since we have precision to 	 * spare.  However, the chosen splitting is good for accuracy too, 	 * and would give results as accurate as Horner's method if the 	 * small terms were added from highest degree down. 	 */
name|r
operator|=
name|T
index|[
literal|4
index|]
operator|+
name|z
operator|*
name|T
index|[
literal|5
index|]
expr_stmt|;
name|t
operator|=
name|T
index|[
literal|2
index|]
operator|+
name|z
operator|*
name|T
index|[
literal|3
index|]
expr_stmt|;
name|w
operator|=
name|z
operator|*
name|z
expr_stmt|;
name|s
operator|=
name|z
operator|*
name|x
expr_stmt|;
name|u
operator|=
name|T
index|[
literal|0
index|]
operator|+
name|z
operator|*
name|T
index|[
literal|1
index|]
expr_stmt|;
name|r
operator|=
operator|(
name|x
operator|+
name|s
operator|*
name|u
operator|)
operator|+
operator|(
name|s
operator|*
name|w
operator|)
operator|*
operator|(
name|t
operator|+
name|w
operator|*
name|r
operator|)
expr_stmt|;
if|if
condition|(
name|iy
operator|==
literal|1
condition|)
return|return
name|r
return|;
else|else
return|return
operator|-
literal|1.0
operator|/
name|r
return|;
block|}
end_function

end_unit

