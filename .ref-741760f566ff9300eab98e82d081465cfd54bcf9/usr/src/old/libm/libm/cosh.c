begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|From
name|Prof
operator|.
name|Kahan
name|at
name|UC
name|at
name|Berkeley
comment|/*   * Copyright (c) 1985 Regents of the University of California.  *   * Use and reproduction of this software are granted  in  accordance  with  * the terms and conditions specified in  the  Berkeley  Software  License  * Agreement (in particular, this entails acknowledgement of the programs'  * source, and inclusion of this notice) with the additional understanding  * that  all  recipients  should regard themselves as participants  in  an  * ongoing  research  project and hence should  feel  obligated  to report  * their  experiences (good or bad) with these elementary function  codes,  * using "sendbug 4bsd-bugs@BERKELEY", to the authors.  */
ifndef|#
directive|ifndef
name|lint
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)cosh.c	1.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* COSH(X)  * RETURN THE HYPERBOLIC COSINE OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/8/85;   * REVISED BY K.C. NG on 2/8/85, 2/23/85, 3/7/85, 3/29/85, 4/16/85.  *  * Required system supported functions :  *	copysign(x,y)  *	scalb(x,N)  *  * Required kernel function:  *	exp(x)   *	exp__E(x,c)	...return exp(x+c)-1-x for |x|<0.3465  *  * Method :  *	1. Replace x by |x|.   *	2.   *		                                        [ exp(x) - 1 ]^2   *	    0<= x<= 0.3465  :  cosh(x) := 1 + -------------------  *			       			           2*exp(x)  *  *		                                   exp(x) +  1/exp(x)  *	    0.3465<= x<= 22      :  cosh(x) := -------------------  *			       			           2  *	    22<= x<= lnovfl  :  cosh(x) := exp(x)/2   *	    lnovfl<= x<= lnovfl+log(2)  *				     :  cosh(x) := exp(x)/2 (avoid overflow)  *	    log(2)+lnovfl<  x<  INF:  overflow to INF  *  *	Note: .3465 is a number near one half of ln2.  *  * Special cases:  *	cosh(x) is x if x is +INF, -INF, or NaN.  *	only cosh(0)=1 is exact for finite x.  *  * Accuracy:  *	cosh(x) returns the exact hyperbolic cosine of x nearly rounded.  *	In a test run with 768,000 random arguments on a VAX, the maximum  *	observed error was 1.23 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/* double static  */
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
name|double
specifier|static
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
name|cosh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
specifier|static
name|double
name|half
init|=
literal|1.0
operator|/
literal|2.0
decl_stmt|,
name|one
init|=
literal|1.0
decl_stmt|,
name|small
init|=
literal|1.0E
operator|-
literal|18
decl_stmt|;
comment|/* fl(1+small)==1 */
name|double
name|scalb
argument_list|()
decl_stmt|,
name|copysign
argument_list|()
decl_stmt|,
name|exp
argument_list|()
decl_stmt|,
name|exp__E
argument_list|()
decl_stmt|,
name|t
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
if|if
condition|(
operator|(
name|x
operator|=
name|copysign
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
operator|)
operator|<=
literal|22
condition|)
if|if
condition|(
name|x
operator|<
literal|0.3465
condition|)
if|if
condition|(
name|x
operator|<
name|small
condition|)
return|return
operator|(
name|one
operator|+
name|x
operator|)
return|;
else|else
block|{
name|t
operator|=
name|x
operator|+
name|exp__E
argument_list|(
name|x
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|x
operator|=
name|t
operator|+
name|t
expr_stmt|;
return|return
operator|(
name|one
operator|+
name|t
operator|*
name|t
operator|/
operator|(
literal|2.0
operator|+
name|x
operator|)
operator|)
return|;
block|}
else|else
comment|/* for x lies in [0.3465,22] */
block|{
name|t
operator|=
name|exp
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|t
operator|+
name|one
operator|/
name|t
operator|)
operator|*
name|half
operator|)
return|;
block|}
if|if
condition|(
name|lnovfl
operator|<=
name|x
operator|&&
name|x
operator|<=
operator|(
name|lnovfl
operator|+
literal|0.7
operator|)
condition|)
comment|/* for x lies in [lnovfl, lnovfl+ln2], decrease x by ln(2^(max+1))           * and return 2^max*exp(x) to avoid unnecessary overflow           */
return|return
operator|(
name|scalb
argument_list|(
name|exp
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
operator|)
return|;
else|else
return|return
operator|(
name|exp
argument_list|(
name|x
argument_list|)
operator|*
name|half
operator|)
return|;
comment|/* for large x,  cosh(x)=exp(x)/2 */
block|}
end_function

end_unit

