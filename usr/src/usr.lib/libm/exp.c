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
literal|"@(#)exp.c	5.3 (Berkeley) 6/30/88"
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
comment|/* EXP(X)  * RETURN THE EXPONENTIAL OF X  * DOUBLE PRECISION (IEEE 53 bits, VAX D FORMAT 56 BITS)  * CODED IN C BY K.C. NG, 1/19/85;   * REVISED BY K.C. NG on 2/6/85, 2/15/85, 3/7/85, 3/24/85, 4/16/85, 6/14/86.  *  * Required system supported functions:  *	scalb(x,n)	  *	copysign(x,y)	  *	finite(x)  *  * Method:  *	1. Argument Reduction: given the input x, find r and integer k such   *	   that  *	                   x = k*ln2 + r,  |r|<= 0.5*ln2 .    *	   r will be represented as r := z+c for better accuracy.  *  *	2. Compute exp(r) by   *  *		exp(r) = 1 + r + r*R1/(2-R1),  *	   where  *		R1 = x - x^2*(p1+x^2*(p2+x^2*(p3+x^2*(p4+p5*x^2)))).  *  *	3. exp(x) = 2^k * exp(r) .  *  * Special cases:  *	exp(INF) is INF, exp(NaN) is NaN;  *	exp(-INF)=  0;  *	for finite argument, only exp(0)=1 is exact.  *  * Accuracy:  *	exp(x) returns the exponential of x nearly rounded. In a test run  *	with 1,156,000 random arguments on a VAX, the maximum observed  *	error was 0.869 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
comment|/* lnhuge =  9.4961163736712506989E1     , Hex  2^  7   *  .BDEC1DA73E9010 */
end_comment

begin_comment
comment|/* lntiny = -9.5654310917272452386E1     , Hex  2^  7   * -.BF4F01D72E33AF */
end_comment

begin_comment
comment|/* invln2 =  1.4426950408889634148E0     ; Hex  2^  1   *  .B8AA3B295C17F1 */
end_comment

begin_comment
comment|/* p1     =  1.6666666666666602251E-1    , Hex  2^-2    *  .AAAAAAAAAAA9F1 */
end_comment

begin_comment
comment|/* p2     = -2.7777777777015591216E-3    , Hex  2^-8    * -.B60B60B5F5EC94 */
end_comment

begin_comment
comment|/* p3     =  6.6137563214379341918E-5    , Hex  2^-13   *  .8AB355792EF15F */
end_comment

begin_comment
comment|/* p4     = -1.6533902205465250480E-6    , Hex  2^-19   * -.DDEA0E2E935F84 */
end_comment

begin_comment
comment|/* p5     =  4.1381367970572387085E-8    , Hex  2^-24   *  .B1BB4B95F52683 */
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
name|lnhugex
index|[]
init|=
block|{
name|_0x
argument_list|(
name|ec1d
argument_list|,
literal|43bd
argument_list|)
block|,
name|_0x
argument_list|(
literal|9010
argument_list|,
argument|a73e
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|lntinyx
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|4f01
argument_list|,
name|c3bf
argument_list|)
block|,
name|_0x
argument_list|(
literal|33af
argument_list|,
argument|d72e
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|invln2x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|aa3b
argument_list|,
literal|40b8
argument_list|)
block|,
name|_0x
argument_list|(
literal|17f1
argument_list|,
literal|295c
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|p1x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|aaaa
argument_list|,
literal|3f2a
argument_list|)
block|,
name|_0x
argument_list|(
argument|a9f1
argument_list|,
argument|aaaa
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|p2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0b60
argument_list|,
name|bc36
argument_list|)
block|,
name|_0x
argument_list|(
argument|ec94
argument_list|,
argument|b5f5
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|p3x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|b355
argument_list|,
literal|398a
argument_list|)
block|,
name|_0x
argument_list|(
argument|f15f
argument_list|,
literal|792e
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|p4x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|ea0e
argument_list|,
name|b6dd
argument_list|)
block|,
name|_0x
argument_list|(
literal|5f84
argument_list|,
literal|2e93
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|p5x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|bb4b
argument_list|,
literal|3431
argument_list|)
block|,
name|_0x
argument_list|(
literal|2683
argument_list|,
literal|95f5
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
name|lnhuge
value|(*(double*)lnhugex)
end_define

begin_define
define|#
directive|define
name|lntiny
value|(*(double*)lntinyx)
end_define

begin_define
define|#
directive|define
name|invln2
value|(*(double*)invln2x)
end_define

begin_define
define|#
directive|define
name|p1
value|(*(double*)p1x)
end_define

begin_define
define|#
directive|define
name|p2
value|(*(double*)p2x)
end_define

begin_define
define|#
directive|define
name|p3
value|(*(double*)p3x)
end_define

begin_define
define|#
directive|define
name|p4
value|(*(double*)p4x)
end_define

begin_define
define|#
directive|define
name|p5
value|(*(double*)p5x)
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
name|p1
init|=
literal|1.6666666666666601904E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^-3    *  1.555555555553E */
name|p2
init|=
operator|-
literal|2.7777777777015593384E
operator|-
literal|3
decl_stmt|,
comment|/*Hex  2^-9    * -1.6C16C16BEBD93 */
name|p3
init|=
literal|6.6137563214379343612E
operator|-
literal|5
decl_stmt|,
comment|/*Hex  2^-14   *  1.1566AAF25DE2C */
name|p4
init|=
operator|-
literal|1.6533902205465251539E
operator|-
literal|6
decl_stmt|,
comment|/*Hex  2^-20   * -1.BBD41C5D26BF1 */
name|p5
init|=
literal|4.1381367970572384604E
operator|-
literal|8
decl_stmt|,
comment|/*Hex  2^-25   *  1.6376972BEA4D0 */
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
name|lnhuge
init|=
literal|7.1602103751842355450E2
decl_stmt|,
comment|/*Hex  2^  9   *  1.6602B15B7ECF2 */
name|lntiny
init|=
operator|-
literal|7.5137154372698068983E2
decl_stmt|,
comment|/*Hex  2^  9   * -1.77AF8EBEAE354 */
name|invln2
init|=
literal|1.4426950408889633870E0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^  0   *  1.71547652B82FE */
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
name|exp
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|scalb
argument_list|()
decl_stmt|,
name|copysign
argument_list|()
decl_stmt|,
name|z
decl_stmt|,
name|hi
decl_stmt|,
name|lo
decl_stmt|,
name|c
decl_stmt|;
name|int
name|k
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
name|x
operator|<=
name|lnhuge
condition|)
block|{
if|if
condition|(
name|x
operator|>=
name|lntiny
condition|)
block|{
comment|/* argument reduction : x --> x - k*ln2 */
name|k
operator|=
name|invln2
operator|*
name|x
operator|+
name|copysign
argument_list|(
literal|0.5
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* k=NINT(x/ln2) */
comment|/* express x-k*ln2 as hi-lo and let x=hi-lo rounded */
name|hi
operator|=
name|x
operator|-
name|k
operator|*
name|ln2hi
expr_stmt|;
name|x
operator|=
name|hi
operator|-
operator|(
name|lo
operator|=
name|k
operator|*
name|ln2lo
operator|)
expr_stmt|;
comment|/* return 2^k*[1+x+x*c/(2+c)]  */
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|c
operator|=
name|x
operator|-
name|z
operator|*
operator|(
name|p1
operator|+
name|z
operator|*
operator|(
name|p2
operator|+
name|z
operator|*
operator|(
name|p3
operator|+
name|z
operator|*
operator|(
name|p4
operator|+
name|z
operator|*
name|p5
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
return|return
name|scalb
argument_list|(
literal|1.0
operator|+
operator|(
name|hi
operator|-
operator|(
name|lo
operator|-
operator|(
name|x
operator|*
name|c
operator|)
operator|/
operator|(
literal|2.0
operator|-
name|c
operator|)
operator|)
operator|)
argument_list|,
name|k
argument_list|)
return|;
block|}
comment|/* end of x> lntiny */
elseif|else
comment|/* exp(-big#) underflows to zero */
if|if
condition|(
name|finite
argument_list|(
name|x
argument_list|)
condition|)
return|return
operator|(
name|scalb
argument_list|(
literal|1.0
argument_list|,
operator|-
literal|5000
argument_list|)
operator|)
return|;
comment|/* exp(-INF) is zero */
else|else
return|return
operator|(
literal|0.0
operator|)
return|;
block|}
comment|/* end of x< lnhuge */
else|else
comment|/* exp(INF) is INF, exp(+big#) overflows to INF */
return|return
operator|(
name|finite
argument_list|(
name|x
argument_list|)
condition|?
name|scalb
argument_list|(
literal|1.0
argument_list|,
literal|5000
argument_list|)
else|:
name|x
operator|)
return|;
block|}
end_function

end_unit

