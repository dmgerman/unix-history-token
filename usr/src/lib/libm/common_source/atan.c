begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  * All recipients should regard themselves as participants in an ongoing  * research project and hence should feel obligated to report their  * experiences (good or bad) with these elementary function codes, using  * the sendbug(8) program, to the authors.  */
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
literal|"@(#)atan.c	5.4 (Berkeley) %G%"
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
comment|/* ATAN(X)  * RETURNS ARC TANGENT OF X  * DOUBLE PRECISION (IEEE DOUBLE 53 bits, VAX D FORMAT 56 bits)  * CODED IN C BY K.C. NG, 4/16/85, REVISED ON 6/10/85.  *  * Required kernel function:  *	atan2(y,x)   *  * Method:                    *	atan(x) = atan2(x,1.0).   *  * Special case:  *	if x is NaN, return x itself.  *  * Accuracy:  * 1)  If atan2() uses machine PI, then  *   *	atan(x) returns (PI/pi) * (the exact arc tangent of x) nearly rounded;  *	and PI is the exact pi rounded to machine precision (see atan2 for  *      details):  *  *	in decimal:  *		pi = 3.141592653589793 23846264338327 .....   *    53 bits   PI = 3.141592653589793 115997963 ..... ,  *    56 bits   PI = 3.141592653589793 227020265 ..... ,    *  *	in hexadecimal:  *		pi = 3.243F6A8885A308D313198A2E....  *    53 bits   PI = 3.243F6A8885A30  =  2 * 1.921FB54442D18	error=.276ulps  *    56 bits   PI = 3.243F6A8885A308 =  4 * .C90FDAA22168C2    error=.206ulps  *	  *	In a test run with more than 200,000 random arguments on a VAX, the   *	maximum observed error in ulps (units in the last place) was  *	0.86 ulps.      (comparing against (PI/pi)*(exact atan(x))).  *  * 2)  If atan2() uses true pi, then  *  *	atan(x) returns the exact atan(x) with error below about 2 ulps.  *  *	In a test run with more than 1,024,000 random arguments on a VAX, the   *	maximum observed error in ulps (units in the last place) was  *	0.85 ulps.  */
end_comment

begin_function
name|double
name|atan
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|atan2
argument_list|()
decl_stmt|,
name|one
init|=
literal|1.0
decl_stmt|;
return|return
operator|(
name|atan2
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

