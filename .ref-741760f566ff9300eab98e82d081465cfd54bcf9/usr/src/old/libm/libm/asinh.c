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
literal|"@(#)asinh.c	1.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* ASINH(X)  * RETURN THE INVERSE HYPERBOLIC SINE OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 2/16/85;  * REVISED BY K.C. NG on 3/7/85, 3/24/85, 4/16/85.  *  * Required system supported functions :  *	copysign(x,y)  *	sqrt(x)  *  * Required kernel function:  *	log1p(x) 		...return log(1+x)  *  * Method :  *	Based on   *		asinh(x) = sign(x) * log [ |x| + sqrt(x*x+1) ]  *	we have  *	asinh(x) := x  if  1+x*x=1,  *		 := sign(x)*(log1p(x)+ln2))	 if sqrt(1+x*x)=x, else  *		 := sign(x)*log1p(|x| + |x|/(1/|x| + sqrt(1+(1/|x|)^2)) )    *  * Accuracy:  *	asinh(x) returns the exact inverse hyperbolic sine of x nearly rounded.  *	In a test run with 52,000 random arguments on a VAX, the maximum   *	observed error was 1.58 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/* VAX D format */
end_comment

begin_comment
comment|/* static double */
end_comment

begin_comment
comment|/* ln2hi  =  6.9314718055829871446E-1    , Hex  2^  0   *  .B17217F7D00000 */
end_comment

begin_comment
comment|/* ln2lo  =  1.6465949582897081279E-12   ; Hex  2^-39   *  .E7BCD5E4F1D9CC */
end_comment

begin_decl_stmt
specifier|static
name|long
name|ln2hix
index|[]
init|=
block|{
literal|0x72174031
block|,
literal|0x0000f7d0
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
literal|0xbcd52ce7
block|,
literal|0xd9cce4f1
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^-33   *  1.A39EF35793C76 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|asinh
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
name|sqrt
argument_list|()
decl_stmt|,
name|t
decl_stmt|,
name|s
decl_stmt|;
specifier|static
name|double
name|small
init|=
literal|1.0E
operator|-
literal|10
decl_stmt|,
comment|/* fl(1+small*small) == 1 */
name|big
init|=
literal|1.0E20
decl_stmt|,
comment|/* fl(1+big) == big */
name|one
init|=
literal|1.0
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
name|t
operator|=
name|copysign
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
operator|)
operator|>
name|small
condition|)
if|if
condition|(
name|t
operator|<
name|big
condition|)
block|{
name|s
operator|=
name|one
operator|/
name|t
expr_stmt|;
return|return
operator|(
name|copysign
argument_list|(
name|log1p
argument_list|(
name|t
operator|+
name|t
operator|/
operator|(
name|s
operator|+
name|sqrt
argument_list|(
name|one
operator|+
name|s
operator|*
name|s
argument_list|)
operator|)
argument_list|)
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
else|else
comment|/* if |x|> big */
block|{
name|s
operator|=
name|log1p
argument_list|(
name|t
argument_list|)
operator|+
name|ln2lo
expr_stmt|;
return|return
operator|(
name|copysign
argument_list|(
name|s
operator|+
name|ln2hi
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
else|else
comment|/* if |x|< small */
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

end_unit

