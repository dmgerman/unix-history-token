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
literal|"@(#)atanh.c	1.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* ATANH(X)  * RETURN THE HYPERBOLIC ARC TANGENT OF X  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/8/85;   * REVISED BY K.C. NG on 2/7/85, 3/7/85.  *  * Required kernel function:  *	L(x) 	...return log(1+x)  *  * Method :  *	Return   *                         log(1+x) - log(1-x)   L(x) - L(-x)  *		atanh(x) = ------------------- = ------------ .  *                                  2                 2  *  * Special cases:  *	atanh(x) is NAN if |x|> 1 with signal;  *	atanh(NAN) is that NAN with no signal;  *	atanh(+-1) is +-INF with signal.  *  * Accuracy:  *	atanh(x) returns the exact hyperbolic arc tangent of x nearly rounded.  *	In a test run with 200,000 random arguments on a VAX, the maximum  *	observed error was 1.45 ulps (units in the last place).  */
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
name|L
parameter_list|()
function_decl|;
return|return
operator|(
operator|(
name|L
argument_list|(
name|x
argument_list|)
operator|-
name|L
argument_list|(
operator|-
name|x
argument_list|)
operator|)
operator|/
literal|2.0
operator|)
return|;
block|}
end_function

end_unit

