begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)e_log.c 1.3 95/01/18 */
end_comment

begin_comment
comment|/*  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunSoft, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice   * is preserved.  * ====================================================  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * k_log1p(f):  * Return log(1+f) - f for 1+f in ~[sqrt(2)/2, sqrt(2)].  *  * The following describes the overall strategy for computing  * logarithms in base e.  The argument reduction and adding the final  * term of the polynomial are done by the caller for increased accuracy  * when different bases are used.  *  * Method :                    *   1. Argument Reduction: find k and f such that   *			x = 2^k * (1+f),   *	   where  sqrt(2)/2< 1+f< sqrt(2) .  *  *   2. Approximation of log(1+f).  *	Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)  *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,  *	     	 = 2s + s*R  *      We use a special Reme algorithm on [0,0.1716] to generate   * 	a polynomial of degree 14 to approximate R The maximum error   *	of this polynomial approximation is bounded by 2**-58.45. In  *	other words,  *		        2      4      6      8      10      12      14  *	    R(z) ~ Lg1*s +Lg2*s +Lg3*s +Lg4*s +Lg5*s  +Lg6*s  +Lg7*s  *  	(the values of Lg1 to Lg7 are listed in the program)  *	and  *	    |      2          14          |     -58.45  *	    | Lg1*s +...+Lg7*s    -  R(z) |<= 2   *	    |                             |  *	Note that 2s = f - s*f = f - hfsq + s*hfsq, where hfsq = f*f/2.  *	In order to guarantee error in log below 1ulp, we compute log  *	by  *		log(1+f) = f - s*(f - R)	(if f is not too large)  *		log(1+f) = f - (hfsq - s*(hfsq+R)).	(better accuracy)  *	  *	3. Finally,  log(x) = k*ln2 + log(1+f).    *			    = k*ln2_hi+(f-(hfsq-(s*(hfsq+R)+k*ln2_lo)))  *	   Here ln2 is split into two floating point number:   *			ln2_hi + ln2_lo,  *	   where n*ln2_hi is always exact for |n|< 2000.  *  * Special cases:  *	log(x) is NaN with signal if x< 0 (including -INF) ;   *	log(+INF) is +INF; log(0) is -INF with signal;  *	log(NaN) is that NaN with no signal.  *  * Accuracy:  *	according to an error analysis, the error is always less than  *	1 ulp (unit in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following   * constants. The decimal values may be used, provided that the   * compiler will convert from decimal to binary accurately enough   * to produce the hexadecimal values shown.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|Lg1
init|=
literal|6.666666666666735130e-01
decl_stmt|,
comment|/* 3FE55555 55555593 */
name|Lg2
init|=
literal|3.999999999940941908e-01
decl_stmt|,
comment|/* 3FD99999 9997FA04 */
name|Lg3
init|=
literal|2.857142874366239149e-01
decl_stmt|,
comment|/* 3FD24924 94229359 */
name|Lg4
init|=
literal|2.222219843214978396e-01
decl_stmt|,
comment|/* 3FCC71C5 1D8E78AF */
name|Lg5
init|=
literal|1.818357216161805012e-01
decl_stmt|,
comment|/* 3FC74664 96CB03DE */
name|Lg6
init|=
literal|1.531383769920937332e-01
decl_stmt|,
comment|/* 3FC39A09 D078C69F */
name|Lg7
init|=
literal|1.479819860511658591e-01
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3FC2F112 DF3E5244 */
end_comment

begin_comment
comment|/*  * We always inline k_log1p(), since doing so produces a  * substantial performance improvement (~40% on amd64).  */
end_comment

begin_function
specifier|static
specifier|inline
name|double
name|k_log1p
parameter_list|(
name|double
name|f
parameter_list|)
block|{
name|double
name|hfsq
decl_stmt|,
name|s
decl_stmt|,
name|z
decl_stmt|,
name|R
decl_stmt|,
name|w
decl_stmt|,
name|t1
decl_stmt|,
name|t2
decl_stmt|;
name|s
operator|=
name|f
operator|/
operator|(
literal|2.0
operator|+
name|f
operator|)
expr_stmt|;
name|z
operator|=
name|s
operator|*
name|s
expr_stmt|;
name|w
operator|=
name|z
operator|*
name|z
expr_stmt|;
name|t1
operator|=
name|w
operator|*
operator|(
name|Lg2
operator|+
name|w
operator|*
operator|(
name|Lg4
operator|+
name|w
operator|*
name|Lg6
operator|)
operator|)
expr_stmt|;
name|t2
operator|=
name|z
operator|*
operator|(
name|Lg1
operator|+
name|w
operator|*
operator|(
name|Lg3
operator|+
name|w
operator|*
operator|(
name|Lg5
operator|+
name|w
operator|*
name|Lg7
operator|)
operator|)
operator|)
expr_stmt|;
name|R
operator|=
name|t2
operator|+
name|t1
expr_stmt|;
name|hfsq
operator|=
literal|0.5
operator|*
name|f
operator|*
name|f
expr_stmt|;
return|return
name|s
operator|*
operator|(
name|hfsq
operator|+
name|R
operator|)
return|;
block|}
end_function

end_unit

