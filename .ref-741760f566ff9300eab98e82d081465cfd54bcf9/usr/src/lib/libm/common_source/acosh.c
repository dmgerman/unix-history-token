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
literal|"@(#)acosh.c	1.2 (Berkeley) 8/21/85; 1.2 (ucb.elefunt) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* ACOSH(X)  * RETURN THE INVERSE HYPERBOLIC COSINE OF X  * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 2/16/85;  * REVISED BY K.C. NG on 3/6/85, 3/24/85, 4/16/85, 8/17/85.  *  * Required system supported functions :  *	sqrt(x)  *  * Required kernel function:  *	log1p(x) 		...return log(1+x)  *  * Method :  *	Based on   *		acosh(x) = log [ x + sqrt(x*x-1) ]  *	we have  *		acosh(x) := log1p(x)+ln2,	if (x> 1.0E20); else		  *		acosh(x) := log1p( sqrt(x-1) * (sqrt(x-1) + sqrt(x+1)) ) .  *	These formulae avoid the over/underflow complication.  *  * Special cases:  *	acosh(x) is NaN with signal if x<1.  *	acosh(NaN) is NaN without signal.  *  * Accuracy:  *	acosh(x) returns the exact inverse hyperbolic cosine of x nearly   *	rounded. In a test run with 512,000 random arguments on a VAX, the  *	maximum observed error was 3.30 ulps (units of the last place) at  *	x=1.0070493753568216 .  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
name|acosh
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|log1p
argument_list|()
decl_stmt|,
name|sqrt
argument_list|()
decl_stmt|,
name|t
decl_stmt|,
name|big
init|=
literal|1.E20
decl_stmt|;
comment|/* big+1==big */
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
comment|/* return log1p(x) + log(2) if x is large */
if|if
condition|(
name|x
operator|>
name|big
condition|)
block|{
name|t
operator|=
name|log1p
argument_list|(
name|x
argument_list|)
operator|+
name|ln2lo
expr_stmt|;
return|return
operator|(
name|t
operator|+
name|ln2hi
operator|)
return|;
block|}
name|t
operator|=
name|sqrt
argument_list|(
name|x
operator|-
literal|1.0
argument_list|)
expr_stmt|;
return|return
operator|(
name|log1p
argument_list|(
name|t
operator|*
operator|(
name|t
operator|+
name|sqrt
argument_list|(
name|x
operator|+
literal|1.0
argument_list|)
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

