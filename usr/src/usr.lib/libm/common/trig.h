begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * All recipients should regard themselves as participants in an ongoing  * research project and hence should feel obligated to report their  * experiences (good or bad) with these elementary function codes, using  * the sendbug(8) program, to the authors.  *  *	@(#)trig.h	5.3 (Berkeley) 6/30/88  */
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
comment|/*thresh =  2.6117239648121182150E-1    , Hex  2^ -1   *  .85B8636B026EA0 */
end_comment

begin_comment
comment|/*PIo4   =  7.8539816339744830676E-1    , Hex  2^  0   *  .C90FDAA22168C2 */
end_comment

begin_comment
comment|/*PIo2   =  1.5707963267948966135E0     , Hex  2^  1   *  .C90FDAA22168C2 */
end_comment

begin_comment
comment|/*PI3o4  =  2.3561944901923449203E0     , Hex  2^  2   *  .96CBE3F9990E92 */
end_comment

begin_comment
comment|/*PI     =  3.1415926535897932270E0     , Hex  2^  2   *  .C90FDAA22168C2 */
end_comment

begin_comment
comment|/*PI2    =  6.2831853071795864540E0     ; Hex  2^  3   *  .C90FDAA22168C2 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|threshx
index|[]
init|=
block|{
name|_0x
argument_list|(
name|b863
argument_list|,
literal|3f85
argument_list|)
block|,
name|_0x
argument_list|(
literal|6ea0
argument_list|,
literal|6b02
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|PIo4x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0fda
argument_list|,
literal|4049
argument_list|)
block|,
name|_0x
argument_list|(
literal|68c2
argument_list|,
argument|a221
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|PIo2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0fda
argument_list|,
literal|40c9
argument_list|)
block|,
name|_0x
argument_list|(
literal|68c2
argument_list|,
argument|a221
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|PI3o4x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|cbe3
argument_list|,
literal|4116
argument_list|)
block|,
name|_0x
argument_list|(
literal|0e92
argument_list|,
argument|f999
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|PIx
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0fda
argument_list|,
literal|4149
argument_list|)
block|,
name|_0x
argument_list|(
literal|68c2
argument_list|,
argument|a221
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|PI2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0fda
argument_list|,
literal|41c9
argument_list|)
block|,
name|_0x
argument_list|(
literal|68c2
argument_list|,
argument|a221
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|thresh
value|(*(double*)threshx)
end_define

begin_define
define|#
directive|define
name|PIo4
value|(*(double*)PIo4x)
end_define

begin_define
define|#
directive|define
name|PIo2
value|(*(double*)PIo2x)
end_define

begin_define
define|#
directive|define
name|PI3o4
value|(*(double*)PI3o4x)
end_define

begin_define
define|#
directive|define
name|PI
value|(*(double*)PIx)
end_define

begin_define
define|#
directive|define
name|PI2
value|(*(double*)PI2x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_decl_stmt
specifier|static
name|double
name|thresh
init|=
literal|2.6117239648121182150E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -2   *  1.0B70C6D604DD4 */
name|PIo4
init|=
literal|7.8539816339744827900E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -1   *  1.921FB54442D18 */
name|PIo2
init|=
literal|1.5707963267948965580E0
decl_stmt|,
comment|/*Hex  2^  0   *  1.921FB54442D18 */
name|PI3o4
init|=
literal|2.3561944901923448370E0
decl_stmt|,
comment|/*Hex  2^  1   *  1.2D97C7F3321D2 */
name|PI
init|=
literal|3.1415926535897931160E0
decl_stmt|,
comment|/*Hex  2^  1   *  1.921FB54442D18 */
name|PI2
init|=
literal|6.2831853071795862320E0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^  2   *  1.921FB54442D18 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|national
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|fmaxx
index|[]
init|=
block|{
literal|0xffffffff
block|,
literal|0x7fefffff
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fmax
value|(*(double*)fmaxx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* national */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_decl_stmt
specifier|static
name|double
name|zero
init|=
literal|0
decl_stmt|,
name|one
init|=
literal|1
decl_stmt|,
name|negone
init|=
operator|-
literal|1
decl_stmt|,
name|half
init|=
literal|1.0
operator|/
literal|2.0
decl_stmt|,
name|small
init|=
literal|1E
operator|-
literal|10
decl_stmt|,
comment|/* 1+small**2 == 1; better values for small: 			 *		small	= 1.5E-9 for VAX D 			 *			= 1.2E-8 for IEEE Double 			 *			= 2.8E-10 for IEEE Extended 			 */
name|big
init|=
literal|1E20
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* big := 1/(small**2) */
end_comment

begin_comment
comment|/* sin__S(x*x) ... re-implemented as a macro  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * STATIC KERNEL FUNCTION OF SIN(X), COS(X), AND TAN(X)   * CODED IN C BY K.C. NG, 1/21/85;   * REVISED BY K.C. NG on 8/13/85.  *  *	    sin(x*k) - x  * RETURN  --------------- on [-PI/4,PI/4] , where k=pi/PI, PI is the rounded  *	            x	  * value of pi in machine precision:  *  *	Decimal:  *		pi = 3.141592653589793 23846264338327 .....   *    53 bits   PI = 3.141592653589793 115997963 ..... ,  *    56 bits   PI = 3.141592653589793 227020265 ..... ,    *  *	Hexadecimal:  *		pi = 3.243F6A8885A308D313198A2E....  *    53 bits   PI = 3.243F6A8885A30  =  2 * 1.921FB54442D18  *    56 bits   PI = 3.243F6A8885A308 =  4 * .C90FDAA22168C2      *  * Method:  *	1. Let z=x*x. Create a polynomial approximation to   *	    (sin(k*x)-x)/x  =  z*(S0 + S1*z^1 + ... + S5*z^5).  *	Then  *      sin__S(x*x) = z*(S0 + S1*z^1 + ... + S5*z^5)  *  *	The coefficient S's are obtained by a special Remez algorithm.  *  * Accuracy:  *	In the absence of rounding error, the approximation has absolute error   *	less than 2**(-61.11) for VAX D FORMAT, 2**(-57.45) for IEEE DOUBLE.   *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  *  */
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
comment|/*S0     = -1.6666666666666646660E-1    , Hex  2^ -2   * -.AAAAAAAAAAAA71 */
end_comment

begin_comment
comment|/*S1     =  8.3333333333297230413E-3    , Hex  2^ -6   *  .8888888888477F */
end_comment

begin_comment
comment|/*S2     = -1.9841269838362403710E-4    , Hex  2^-12   * -.D00D00CF8A1057 */
end_comment

begin_comment
comment|/*S3     =  2.7557318019967078930E-6    , Hex  2^-18   *  .B8EF1CA326BEDC */
end_comment

begin_comment
comment|/*S4     = -2.5051841873876551398E-8    , Hex  2^-25   * -.D73195374CE1D3 */
end_comment

begin_comment
comment|/*S5     =  1.6028995389845827653E-10   , Hex  2^-32   *  .B03D9C6D26CCCC */
end_comment

begin_comment
comment|/*S6     = -6.2723499671769283121E-13   ; Hex  2^-40   * -.B08D0B7561EA82 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|S0x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|aaaa
argument_list|,
name|bf2a
argument_list|)
block|,
name|_0x
argument_list|(
argument|aa71
argument_list|,
argument|aaaa
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S1x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|8888
argument_list|,
literal|3d08
argument_list|)
block|,
name|_0x
argument_list|(
literal|477f
argument_list|,
literal|8888
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0d00
argument_list|,
name|ba50
argument_list|)
block|,
name|_0x
argument_list|(
literal|1057
argument_list|,
argument|cf8a
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S3x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|ef1c
argument_list|,
literal|3738
argument_list|)
block|,
name|_0x
argument_list|(
argument|bedc
argument_list|,
argument|a326
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S4x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|3195
argument_list|,
name|b3d7
argument_list|)
block|,
name|_0x
argument_list|(
argument|e1d3
argument_list|,
literal|374c
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S5x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|3d9c
argument_list|,
literal|3030
argument_list|)
block|,
name|_0x
argument_list|(
argument|cccc
argument_list|,
literal|6d26
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|S6x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|8d0b
argument_list|,
name|ac30
argument_list|)
block|,
name|_0x
argument_list|(
argument|ea82
argument_list|,
literal|7561
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|S0
value|(*(double*)S0x)
end_define

begin_define
define|#
directive|define
name|S1
value|(*(double*)S1x)
end_define

begin_define
define|#
directive|define
name|S2
value|(*(double*)S2x)
end_define

begin_define
define|#
directive|define
name|S3
value|(*(double*)S3x)
end_define

begin_define
define|#
directive|define
name|S4
value|(*(double*)S4x)
end_define

begin_define
define|#
directive|define
name|S5
value|(*(double*)S5x)
end_define

begin_define
define|#
directive|define
name|S6
value|(*(double*)S6x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE double  */
end_comment

begin_decl_stmt
specifier|static
name|double
name|S0
init|=
operator|-
literal|1.6666666666666463126E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -3   * -1.555555555550C */
name|S1
init|=
literal|8.3333333332992771264E
operator|-
literal|3
decl_stmt|,
comment|/*Hex  2^ -7   *  1.111111110C461 */
name|S2
init|=
operator|-
literal|1.9841269816180999116E
operator|-
literal|4
decl_stmt|,
comment|/*Hex  2^-13   * -1.A01A019746345 */
name|S3
init|=
literal|2.7557309793219876880E
operator|-
literal|6
decl_stmt|,
comment|/*Hex  2^-19   *  1.71DE3209CDCD9 */
name|S4
init|=
operator|-
literal|2.5050225177523807003E
operator|-
literal|8
decl_stmt|,
comment|/*Hex  2^-26   * -1.AE5C0E319A4EF */
name|S5
init|=
literal|1.5868926979889205164E
operator|-
literal|10
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^-33   *  1.5CF61DF672B13 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|sin__S
parameter_list|(
name|z
parameter_list|)
value|(z*(S0+z*(S1+z*(S2+z*(S3+z*(S4+z*(S5+z*S6)))))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_define
define|#
directive|define
name|sin__S
parameter_list|(
name|z
parameter_list|)
value|(z*(S0+z*(S1+z*(S2+z*(S3+z*(S4+z*S5))))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_comment
comment|/* cos__C(x*x) ... re-implemented as a macro  * DOUBLE PRECISION (VAX D FORMAT 56 BITS, IEEE DOUBLE 53 BITS)  * STATIC KERNEL FUNCTION OF SIN(X), COS(X), AND TAN(X)   * CODED IN C BY K.C. NG, 1/21/85;   * REVISED BY K.C. NG on 8/13/85.  *  *	   		    x*x	  * RETURN   cos(k*x) - 1 + ----- on [-PI/4,PI/4],  where k = pi/PI,  *	  		     2	  * PI is the rounded value of pi in machine precision :  *  *	Decimal:  *		pi = 3.141592653589793 23846264338327 .....   *    53 bits   PI = 3.141592653589793 115997963 ..... ,  *    56 bits   PI = 3.141592653589793 227020265 ..... ,    *  *	Hexadecimal:  *		pi = 3.243F6A8885A308D313198A2E....  *    53 bits   PI = 3.243F6A8885A30  =  2 * 1.921FB54442D18  *    56 bits   PI = 3.243F6A8885A308 =  4 * .C90FDAA22168C2      *  *  * Method:  *	1. Let z=x*x. Create a polynomial approximation to   *	    cos(k*x)-1+z/2  =  z*z*(C0 + C1*z^1 + ... + C5*z^5)  *	then  *      cos__C(z) =  z*z*(C0 + C1*z^1 + ... + C5*z^5)  *  *	The coefficient C's are obtained by a special Remez algorithm.  *  * Accuracy:  *	In the absence of rounding error, the approximation has absolute error   *	less than 2**(-64) for VAX D FORMAT, 2**(-58.3) for IEEE DOUBLE.   *	  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  *  */
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
comment|/*C0     =  4.1666666666666504759E-2    , Hex  2^ -4   *  .AAAAAAAAAAA9F0 */
end_comment

begin_comment
comment|/*C1     = -1.3888888888865302059E-3    , Hex  2^ -9   * -.B60B60B60A0CCA */
end_comment

begin_comment
comment|/*C2     =  2.4801587285601038265E-5    , Hex  2^-15   *  .D00D00CDCD098F */
end_comment

begin_comment
comment|/*C3     = -2.7557313470902390219E-7    , Hex  2^-21   * -.93F27BB593E805 */
end_comment

begin_comment
comment|/*C4     =  2.0875623401082232009E-9    , Hex  2^-28   *  .8F74C8FA1E3FF0 */
end_comment

begin_comment
comment|/*C5     = -1.1355178117642986178E-11   ; Hex  2^-36   * -.C7C32D0A5C5A63 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|C0x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|aaaa
argument_list|,
literal|3e2a
argument_list|)
block|,
name|_0x
argument_list|(
argument|a9f0
argument_list|,
argument|aaaa
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|C1x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0b60
argument_list|,
name|bbb6
argument_list|)
block|,
name|_0x
argument_list|(
literal|0cca
argument_list|,
argument|b60a
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|C2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0d00
argument_list|,
literal|38d0
argument_list|)
block|,
name|_0x
argument_list|(
literal|098f
argument_list|,
argument|cdcd
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|C3x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|f27b
argument_list|,
name|b593
argument_list|)
block|,
name|_0x
argument_list|(
argument|e805
argument_list|,
argument|b593
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|C4x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|74c8
argument_list|,
literal|320f
argument_list|)
block|,
name|_0x
argument_list|(
literal|3ff0
argument_list|,
argument|fa1e
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|C5x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|c32d
argument_list|,
name|ae47
argument_list|)
block|,
name|_0x
argument_list|(
literal|5a63
argument_list|,
literal|0a5c
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|C0
value|(*(double*)C0x)
end_define

begin_define
define|#
directive|define
name|C1
value|(*(double*)C1x)
end_define

begin_define
define|#
directive|define
name|C2
value|(*(double*)C2x)
end_define

begin_define
define|#
directive|define
name|C3
value|(*(double*)C3x)
end_define

begin_define
define|#
directive|define
name|C4
value|(*(double*)C4x)
end_define

begin_define
define|#
directive|define
name|C5
value|(*(double*)C5x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_decl_stmt
specifier|static
name|double
name|C0
init|=
literal|4.1666666666666504759E
operator|-
literal|2
decl_stmt|,
comment|/*Hex  2^ -5   *  1.555555555553E */
name|C1
init|=
operator|-
literal|1.3888888888865301516E
operator|-
literal|3
decl_stmt|,
comment|/*Hex  2^-10   * -1.6C16C16C14199 */
name|C2
init|=
literal|2.4801587269650015769E
operator|-
literal|5
decl_stmt|,
comment|/*Hex  2^-16   *  1.A01A01971CAEB */
name|C3
init|=
operator|-
literal|2.7557304623183959811E
operator|-
literal|7
decl_stmt|,
comment|/*Hex  2^-22   * -1.27E4F1314AD1A */
name|C4
init|=
literal|2.0873958177697780076E
operator|-
literal|9
decl_stmt|,
comment|/*Hex  2^-29   *  1.1EE3B60DDDC8C */
name|C5
init|=
operator|-
literal|1.1250289076471311557E
operator|-
literal|11
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^-37   * -1.8BD5986B2A52E */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(vax)||defined(tahoe) */
end_comment

begin_define
define|#
directive|define
name|cos__C
parameter_list|(
name|z
parameter_list|)
value|(z*z*(C0+z*(C1+z*(C2+z*(C3+z*(C4+z*C5))))))
end_define

begin_function_decl
specifier|extern
name|int
name|finite
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|double
name|copysign
argument_list|()
decl_stmt|,
name|drem
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

