begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985 Regents of the University of California.  *   * Use and reproduction of this software are granted  in  accordance  with  * the terms and conditions specified in  the  Berkeley  Software  License  * Agreement (in particular, this entails acknowledgement of the programs'  * source, and inclusion of this notice) with the additional understanding  * that  all  recipients  should regard themselves as participants  in  an  * ongoing  research  project and hence should  feel  obligated  to report  * their  experiences (good or bad) with these elementary function  codes,  * using "sendbug 4bsd-bugs@BERKELEY", to the authors.  */
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
literal|"@(#)sinh.c	4.3 (Berkeley) 8/21/85; 1.3 (ucb.elefunt) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* SINH(X)  * RETURN THE HYPERBOLIC SINE OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/8/85;   * REVISED BY K.C. NG on 2/8/85, 3/7/85, 3/24/85, 4/16/85.  *  * Required system supported functions :  *	copysign(x,y)  *	scalb(x,N)  *  * Required kernel functions:  *	expm1(x)	...return exp(x)-1  *  * Method :  *	1. reduce x to non-negative by sinh(-x) = - sinh(x).  *	2.   *  *	                                      expm1(x) + expm1(x)/(expm1(x)+1)  *	    0<= x<= lnovfl     : sinh(x) := --------------------------------  *			       		                      2  *     lnovfl<= x<= lnovfl+ln2 : sinh(x) := expm1(x)/2 (avoid overflow)  * lnovfl+ln2<  x<  INF        :  overflow to INF  *	  *  * Special cases:  *	sinh(x) is x if x is +INF, -INF, or NaN.  *	only sinh(0)=0 is exact for finite argument.  *  * Accuracy:  *	sinh(x) returns the exact hyperbolic sine of x nearly rounded. In  *	a test run with 1,024,000 random arguments on a VAX, the maximum  *	observed error was 1.93 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/* static double */
end_comment

begin_comment
comment|/* mln2hi =  8.8029691931113054792E1     , Hex  2^  7   *  .B00F33C7E22BDB */
end_comment

begin_comment
comment|/* mln2lo = -4.9650192275318476525E-16   , Hex  2^-50   * -.8F1B60279E582A */
end_comment

begin_comment
comment|/* lnovfl =  8.8029691931113053016E1     ; Hex  2^  7   *  .B00F33C7E22BDA */
end_comment

begin_decl_stmt
specifier|static
name|long
name|mln2hix
index|[]
init|=
block|{
literal|0x0f3343b0
block|,
literal|0x2bdbc7e2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|mln2lox
index|[]
init|=
block|{
literal|0x1b60a70f
block|,
literal|0x582a279e
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|lnovflx
index|[]
init|=
block|{
literal|0x0f3343b0
block|,
literal|0x2bdac7e2
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mln2hi
value|(*(double*)mln2hix)
end_define

begin_define
define|#
directive|define
name|mln2lo
value|(*(double*)mln2lox)
end_define

begin_define
define|#
directive|define
name|lnovfl
value|(*(double*)lnovflx)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE double */
end_comment

begin_decl_stmt
specifier|static
name|double
name|mln2hi
init|=
literal|7.0978271289338397310E2
decl_stmt|,
comment|/*Hex  2^ 10   *  1.62E42FEFA39EF */
name|mln2lo
init|=
literal|2.3747039373786107478E
operator|-
literal|14
decl_stmt|,
comment|/*Hex  2^-45   *  1.ABC9E3B39803F */
name|lnovfl
init|=
literal|7.0978271289338397310E2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^  9   *  1.62E42FEFA39EF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_expr_stmt
specifier|static
name|max
operator|=
literal|126
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE double */
end_comment

begin_expr_stmt
specifier|static
name|max
operator|=
literal|1023
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|sinh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
specifier|static
name|double
name|one
init|=
literal|1.0
decl_stmt|,
name|half
init|=
literal|1.0
operator|/
literal|2.0
decl_stmt|;
name|double
name|expm1
argument_list|()
decl_stmt|,
name|t
decl_stmt|,
name|scalb
argument_list|()
decl_stmt|,
name|copysign
argument_list|()
decl_stmt|,
name|sign
decl_stmt|;
ifndef|#
directive|ifndef
name|VAX
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
name|sign
operator|=
name|copysign
argument_list|(
name|one
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
name|one
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
name|lnovfl
condition|)
block|{
name|t
operator|=
name|expm1
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|copysign
argument_list|(
operator|(
name|t
operator|+
name|t
operator|/
operator|(
name|one
operator|+
name|t
operator|)
operator|)
operator|*
name|half
argument_list|,
name|sign
argument_list|)
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|x
operator|<=
name|lnovfl
operator|+
literal|0.7
condition|)
comment|/* subtract x by ln(2^(max+1)) and return 2^max*exp(x)  	    		to avoid unnecessary overflow */
return|return
operator|(
name|copysign
argument_list|(
name|scalb
argument_list|(
name|one
operator|+
name|expm1
argument_list|(
operator|(
name|x
operator|-
name|mln2hi
operator|)
operator|-
name|mln2lo
argument_list|)
argument_list|,
name|max
argument_list|)
argument_list|,
name|sign
argument_list|)
operator|)
return|;
else|else
comment|/* sinh(+-INF) = +-INF, sinh(+-big no.) overflow to +-INF */
return|return
operator|(
name|expm1
argument_list|(
name|x
argument_list|)
operator|*
name|sign
operator|)
return|;
block|}
end_function

end_unit

