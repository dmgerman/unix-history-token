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
literal|"@(#)exp__E.c	5.3 (Berkeley) 6/30/88"
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
comment|/* exp__E(x,c)  * ASSUMPTION: c<< x  SO THAT  fl(x+c)=x.  * (c is the correction term for x)  * exp__E RETURNS  *  *			 /  exp(x+c) - 1 - x ,  1E-19< |x|< .3465736  *       exp__E(x,c) = 	| 		       *			 \  0 ,  |x|< 1E-19.  *  * DOUBLE PRECISION (IEEE 53 bits, VAX D FORMAT 56 BITS)  * KERNEL FUNCTION OF EXP, EXPM1, POW FUNCTIONS  * CODED IN C BY K.C. NG, 1/31/85;  * REVISED BY K.C. NG on 3/16/85, 4/16/85.  *  * Required system supported function:  *	copysign(x,y)	  *  * Method:  *	1. Rational approximation. Let r=x+c.  *	   Based on  *                                   2 * sinh(r/2)       *                exp(r) - 1 =   ----------------------   ,  *                               cosh(r/2) - sinh(r/2)  *	   exp__E(r) is computed using  *                   x*x            (x/2)*W - ( Q - ( 2*P  + x*P ) )  *                   --- + (c + x*[---------------------------------- + c ])  *                    2                          1 - W  * 	   where  P := p1*x^2 + p2*x^4,  *	          Q := q1*x^2 + q2*x^4 (for 56 bits precision, add q3*x^6)  *	          W := x/2-(Q-x*P),  *  *	   (See the listing below for the values of p1,p2,q1,q2,q3. The poly-  *	    nomials P and Q may be regarded as the approximations to sinh  *	    and cosh :  *		sinh(r/2) =  r/2 + r * P  ,  cosh(r/2) =  1 + Q . )  *  *         The coefficients were obtained by a special Remez algorithm.  *  * Approximation error:  *  *   |	exp(x) - 1			   |        2**(-57),  (IEEE double)  *   | ------------  -  (exp__E(x,0)+x)/x  |<=   *   |	     x			           |	    2**(-69).  (VAX D)  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
comment|/* p1     =  1.5150724356786683059E-2    , Hex  2^ -6   *  .F83ABE67E1066A */
end_comment

begin_comment
comment|/* p2     =  6.3112487873718332688E-5    , Hex  2^-13   *  .845B4248CD0173 */
end_comment

begin_comment
comment|/* q1     =  1.1363478204690669916E-1    , Hex  2^ -3   *  .E8B95A44A2EC45 */
end_comment

begin_comment
comment|/* q2     =  1.2624568129896839182E-3    , Hex  2^ -9   *  .A5790572E4F5E7 */
end_comment

begin_comment
comment|/* q3     =  1.5021856115869022674E-6    ; Hex  2^-19   *  .C99EB4604AC395 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|p1x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|3abe
argument_list|,
literal|3d78
argument_list|)
block|,
name|_0x
argument_list|(
literal|066a
argument_list|,
literal|67e1
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
literal|5b42
argument_list|,
literal|3984
argument_list|)
block|,
name|_0x
argument_list|(
literal|0173
argument_list|,
literal|48cd
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|q1x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|b95a
argument_list|,
literal|3ee8
argument_list|)
block|,
name|_0x
argument_list|(
argument|ec45
argument_list|,
literal|44a2
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|q2x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|7905
argument_list|,
literal|3ba5
argument_list|)
block|,
name|_0x
argument_list|(
argument|f5e7
argument_list|,
literal|72e4
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|q3x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|9eb4
argument_list|,
literal|36c9
argument_list|)
block|,
name|_0x
argument_list|(
argument|c395
argument_list|,
literal|604a
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

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
name|q1
value|(*(double*)q1x)
end_define

begin_define
define|#
directive|define
name|q2
value|(*(double*)q2x)
end_define

begin_define
define|#
directive|define
name|q3
value|(*(double*)q3x)
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
literal|1.3887401997267371720E
operator|-
literal|2
decl_stmt|,
comment|/*Hex  2^ -7   *  1.C70FF8B3CC2CF */
name|p2
init|=
literal|3.3044019718331897649E
operator|-
literal|5
decl_stmt|,
comment|/*Hex  2^-15   *  1.15317DF4526C4 */
name|q1
init|=
literal|1.1110813732786649355E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -4   *  1.C719538248597 */
name|q2
init|=
literal|9.9176615021572857300E
operator|-
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^-10   *  1.03FC4CB8C98E8 */
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
name|exp__E
parameter_list|(
name|x
parameter_list|,
name|c
parameter_list|)
name|double
name|x
decl_stmt|,
name|c
decl_stmt|;
block|{
specifier|static
name|double
name|zero
init|=
literal|0.0
decl_stmt|,
name|one
init|=
literal|1.0
decl_stmt|,
name|half
init|=
literal|1.0
operator|/
literal|2.0
decl_stmt|,
name|small
init|=
literal|1.0E
operator|-
literal|19
decl_stmt|;
name|double
name|copysign
argument_list|()
decl_stmt|,
name|z
decl_stmt|,
name|p
decl_stmt|,
name|q
decl_stmt|,
name|xp
decl_stmt|,
name|xh
decl_stmt|,
name|w
decl_stmt|;
if|if
condition|(
name|copysign
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
operator|>
name|small
condition|)
block|{
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|p
operator|=
name|z
operator|*
operator|(
name|p1
operator|+
name|z
operator|*
name|p2
operator|)
expr_stmt|;
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
name|q
operator|=
name|z
operator|*
operator|(
name|q1
operator|+
name|z
operator|*
operator|(
name|q2
operator|+
name|z
operator|*
name|q3
operator|)
operator|)
expr_stmt|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
name|q
operator|=
name|z
operator|*
operator|(
name|q1
operator|+
name|z
operator|*
name|q2
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
name|xp
operator|=
name|x
operator|*
name|p
expr_stmt|;
name|xh
operator|=
name|x
operator|*
name|half
expr_stmt|;
name|w
operator|=
name|xh
operator|-
operator|(
name|q
operator|-
name|xp
operator|)
expr_stmt|;
name|p
operator|=
name|p
operator|+
name|p
expr_stmt|;
name|c
operator|+=
name|x
operator|*
operator|(
operator|(
name|xh
operator|*
name|w
operator|-
operator|(
name|q
operator|-
operator|(
name|p
operator|+
name|xp
operator|)
operator|)
operator|)
operator|/
operator|(
name|one
operator|-
name|w
operator|)
operator|+
name|c
operator|)
expr_stmt|;
return|return
operator|(
name|z
operator|*
name|half
operator|+
name|c
operator|)
return|;
block|}
comment|/* end of |x|> small */
else|else
block|{
if|if
condition|(
name|x
operator|!=
name|zero
condition|)
name|one
operator|+
name|small
expr_stmt|;
comment|/* raise the inexact flag */
return|return
operator|(
name|copysign
argument_list|(
name|zero
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
block|}
end_function

end_unit

