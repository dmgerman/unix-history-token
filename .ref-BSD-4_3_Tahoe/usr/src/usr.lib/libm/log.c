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
literal|"@(#)log.c	5.3 (Berkeley) 6/30/88"
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
comment|/* LOG(X)  * RETURN THE LOGARITHM OF x   * DOUBLE PRECISION (VAX D FORMAT 56 bits or IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/19/85;  * REVISED BY K.C. NG on 2/7/85, 3/7/85, 3/24/85, 4/16/85.  *  * Required system supported functions:  *	scalb(x,n)  *	copysign(x,y)  *	logb(x)	  *	finite(x)  *  * Required kernel function:  *	log__L(z)   *  * Method :  *	1. Argument Reduction: find k and f such that   *			x = 2^k * (1+f),   *	   where  sqrt(2)/2< 1+f< sqrt(2) .  *  *	2. Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)  *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,  *	   log(1+f) is computed by  *  *	     		log(1+f) = 2s + s*log__L(s*s)  *	   where  *		log__L(z) = z*(L1 + z*(L2 + z*(... (L6 + z*L7)...)))  *  *	   See log__L() for the values of the coefficients.  *  *	3. Finally,  log(x) = k*ln2 + log(1+f).  (Here n*ln2 will be stored  *	   in two floating point number: n*ln2hi + n*ln2lo, n*ln2hi is exact  *	   since the last 20 bits of ln2hi is 0.)  *  * Special cases:  *	log(x) is NaN with signal if x< 0 (including -INF) ;   *	log(+INF) is +INF; log(0) is -INF with signal;  *	log(NaN) is that NaN with no signal.  *  * Accuracy:  *	log(x) returns the exact log(x) nearly rounded. In a test run with  *	1,536,000 random arguments on a VAX, the maximum observed error was  *	.826 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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

begin_comment
comment|/* VAX D format */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_0x
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|0x
comment|/**/
value|A
comment|/**/
value|B
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* vax */
end_comment

begin_define
define|#
directive|define
name|_0x
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|0x
comment|/**/
value|B
comment|/**/
value|A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_comment
comment|/* static double */
end_comment

begin_comment
comment|/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
end_comment

begin_comment
comment|/* ln2lo  =  1.6465949582897081279E-12   , Hex  2^-39   *  .E7BCD5E4F1D9CC */
end_comment

begin_comment
comment|/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|ln2hix
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|7217
argument_list|,
literal|4031
argument_list|)
block|,
name|_0x
argument_list|(
literal|0000
argument_list|,
argument|f7d0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|ln2lox
index|[]
init|=
block|{
name|_0x
argument_list|(
name|bcd5
argument_list|,
literal|2ce7
argument_list|)
block|,
name|_0x
argument_list|(
argument|d9cc
argument_list|,
argument|e4f1
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|sqrt2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|04f3
argument_list|,
literal|40b5
argument_list|)
block|,
name|_0x
argument_list|(
argument|de65
argument_list|,
literal|33f9
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ln2hi
value|(*(double*)ln2hix)
end_define

begin_define
define|#
directive|define
name|ln2lo
value|(*(double*)ln2lox)
end_define

begin_define
define|#
directive|define
name|sqrt2
value|(*(double*)sqrt2x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(vax)||defined(tahoe)	*/
end_comment

begin_decl_stmt
specifier|static
name|double
name|ln2hi
init|=
literal|6.9314718036912381649E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -1   *  1.62E42FEE00000 */
name|ln2lo
init|=
literal|1.9082149292705877000E
operator|-
literal|10
decl_stmt|,
comment|/*Hex  2^-33   *  1.A39EF35793C76 */
name|sqrt2
init|=
literal|1.4142135623730951455E0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^  0   *  1.6A09E667F3BCD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe)	*/
end_comment

begin_function
name|double
name|log
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
specifier|static
name|double
name|zero
init|=
literal|0.0
decl_stmt|,
name|negone
init|=
operator|-
literal|1.0
decl_stmt|,
name|half
init|=
literal|1.0
operator|/
literal|2.0
decl_stmt|;
name|double
name|logb
argument_list|()
decl_stmt|,
name|scalb
argument_list|()
decl_stmt|,
name|copysign
argument_list|()
decl_stmt|,
name|log__L
argument_list|()
decl_stmt|,
name|s
decl_stmt|,
name|z
decl_stmt|,
name|t
decl_stmt|;
name|int
name|k
decl_stmt|,
name|n
decl_stmt|,
name|finite
argument_list|()
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
if|if
condition|(
name|x
operator|!=
name|x
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* x is NaN */
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
if|if
condition|(
name|finite
argument_list|(
name|x
argument_list|)
condition|)
block|{
if|if
condition|(
name|x
operator|>
name|zero
condition|)
block|{
comment|/* argument reduction */
name|k
operator|=
name|logb
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
name|scalb
argument_list|(
name|x
argument_list|,
operator|-
name|k
argument_list|)
expr_stmt|;
if|if
condition|(
name|k
operator|==
operator|-
literal|1022
condition|)
comment|/* subnormal no. */
block|{
name|n
operator|=
name|logb
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|x
operator|=
name|scalb
argument_list|(
name|x
argument_list|,
operator|-
name|n
argument_list|)
expr_stmt|;
name|k
operator|+=
name|n
expr_stmt|;
block|}
if|if
condition|(
name|x
operator|>=
name|sqrt2
condition|)
block|{
name|k
operator|+=
literal|1
expr_stmt|;
name|x
operator|*=
name|half
expr_stmt|;
block|}
name|x
operator|+=
name|negone
expr_stmt|;
comment|/* compute log(1+x)  */
name|s
operator|=
name|x
operator|/
operator|(
literal|2
operator|+
name|x
operator|)
expr_stmt|;
name|t
operator|=
name|x
operator|*
name|x
operator|*
name|half
expr_stmt|;
name|z
operator|=
name|k
operator|*
name|ln2lo
operator|+
name|s
operator|*
operator|(
name|t
operator|+
name|log__L
argument_list|(
name|s
operator|*
name|s
argument_list|)
operator|)
expr_stmt|;
name|x
operator|+=
operator|(
name|z
operator|-
name|t
operator|)
expr_stmt|;
return|return
operator|(
name|k
operator|*
name|ln2hi
operator|+
name|x
operator|)
return|;
block|}
comment|/* end of if (x> zero) */
else|else
block|{
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
specifier|extern
name|double
name|infnan
parameter_list|()
function_decl|;
if|if
condition|(
name|x
operator|==
name|zero
condition|)
return|return
operator|(
name|infnan
argument_list|(
operator|-
name|ERANGE
argument_list|)
operator|)
return|;
comment|/* -INF */
else|else
return|return
operator|(
name|infnan
argument_list|(
name|EDOM
argument_list|)
operator|)
return|;
comment|/* NaN */
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
comment|/* zero argument, return -INF with signal */
if|if
condition|(
name|x
operator|==
name|zero
condition|)
return|return
operator|(
name|negone
operator|/
name|zero
operator|)
return|;
comment|/* negative argument, return NaN with signal */
else|else
return|return
operator|(
name|zero
operator|/
name|zero
operator|)
return|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
block|}
comment|/* end of if (finite(x)) */
comment|/* NOTREACHED if defined(vax)||defined(tahoe) */
comment|/* log(-INF) is NaN with signal */
elseif|else
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|zero
operator|/
name|zero
operator|)
return|;
comment|/* log(+INF) is +INF */
else|else
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

end_unit

