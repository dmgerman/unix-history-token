begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * All recipients should regard themselves as participants in an ongoing  * research project and hence should feel obligated to report their  * experiences (good or bad) with these elementary function codes, using  * the sendbug(8) program, to the authors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)atanh.c	5.3 (Berkeley) 6/30/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* ATANH(X)  * RETURN THE HYPERBOLIC ARC TANGENT OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/8/85;   * REVISED BY K.C. NG on 2/7/85, 3/7/85, 8/18/85.  *  * Required kernel function:  *	log1p(x) 	...return log(1+x)  *  * Method :  *	Return   *                          1              2x                          x  *		atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)  *                          2             1 - x                      1 - x  *  * Special cases:  *	atanh(x) is NaN if |x|> 1 with signal;  *	atanh(NaN) is that NaN with no signal;  *	atanh(+-1) is +-INF with signal.  *  * Accuracy:  *	atanh(x) returns the exact hyperbolic arc tangent of x nearly rounded.  *	In a test run with 512,000 random arguments on a VAX, the maximum  *	observed error was 1.87 ulps (units in the last place) at  *	x= -3.8962076028810414000e-03.  */
end_comment

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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_function
name|double
name|atanh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|copysign
argument_list|()
decl_stmt|,
name|log1p
argument_list|()
decl_stmt|,
name|z
decl_stmt|;
name|z
operator|=
name|copysign
argument_list|(
literal|0.5
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
name|copysign
argument_list|(
name|x
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
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
if|if
condition|(
name|x
operator|==
literal|1.0
condition|)
block|{
specifier|extern
name|double
name|infnan
parameter_list|()
function_decl|;
return|return
operator|(
name|copysign
argument_list|(
literal|1.0
argument_list|,
name|z
argument_list|)
operator|*
name|infnan
argument_list|(
name|ERANGE
argument_list|)
operator|)
return|;
comment|/* sign(x)*INF */
block|}
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
name|x
operator|=
name|x
operator|/
operator|(
literal|1.0
operator|-
name|x
operator|)
expr_stmt|;
return|return
operator|(
name|z
operator|*
name|log1p
argument_list|(
name|x
operator|+
name|x
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

