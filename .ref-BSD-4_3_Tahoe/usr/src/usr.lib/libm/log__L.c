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
literal|"@(#)log__L.c	5.3 (Berkeley) 6/30/88"
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
comment|/* log__L(Z)  *		LOG(1+X) - 2S			       X  * RETURN      ---------------  WHERE Z = S*S,  S = ------- , 0<= Z<= .0294...  *		      S				     2 + X  *		       * DOUBLE PRECISION (VAX D FORMAT 56 bits or IEEE DOUBLE 53 BITS)  * KERNEL FUNCTION FOR LOG; TO BE USED IN LOG1P, LOG, AND POW FUNCTIONS  * CODED IN C BY K.C. NG, 1/19/85;   * REVISED BY K.C. Ng, 2/3/85, 4/16/85.  *  * Method :  *	1. Polynomial approximation: let s = x/(2+x).   *	   Based on log(1+x) = log(1+s) - log(1-s)  *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,  *  *	   (log(1+x) - 2s)/s is computed by  *  *	       z*(L1 + z*(L2 + z*(... (L7 + z*L8)...)))  *  *	   where z=s*s. (See the listing below for Lk's values.) The   *	   coefficients are obtained by a special Remez algorithm.   *  * Accuracy:  *	Assuming no rounding error, the maximum magnitude of the approximation   *	error (absolute) is 2**(-58.49) for IEEE double, and 2**(-63.63)  *	for VAX D format.  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
comment|/* VAX D format (56 bits) */
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
comment|/* L1     =  6.6666666666666703212E-1    , Hex  2^  0   *  .AAAAAAAAAAAAC5 */
end_comment

begin_comment
comment|/* L2     =  3.9999999999970461961E-1    , Hex  2^ -1   *  .CCCCCCCCCC2684 */
end_comment

begin_comment
comment|/* L3     =  2.8571428579395698188E-1    , Hex  2^ -1   *  .92492492F85782 */
end_comment

begin_comment
comment|/* L4     =  2.2222221233634724402E-1    , Hex  2^ -2   *  .E38E3839B7AF2C */
end_comment

begin_comment
comment|/* L5     =  1.8181879517064680057E-1    , Hex  2^ -2   *  .BA2EB4CC39655E */
end_comment

begin_comment
comment|/* L6     =  1.5382888777946145467E-1    , Hex  2^ -2   *  .9D8551E8C5781D */
end_comment

begin_comment
comment|/* L7     =  1.3338356561139403517E-1    , Hex  2^ -2   *  .8895B3907FCD92 */
end_comment

begin_comment
comment|/* L8     =  1.2500000000000000000E-1    , Hex  2^ -2   *  .80000000000000 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|L1x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|aaaa
argument_list|,
literal|402a
argument_list|)
block|,
name|_0x
argument_list|(
argument|aac5
argument_list|,
argument|aaaa
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L2x
index|[]
init|=
block|{
name|_0x
argument_list|(
name|cccc
argument_list|,
literal|3fcc
argument_list|)
block|,
name|_0x
argument_list|(
literal|2684
argument_list|,
argument|cccc
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L3x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|4924
argument_list|,
literal|3f92
argument_list|)
block|,
name|_0x
argument_list|(
literal|5782
argument_list|,
literal|92f8
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L4x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|8e38
argument_list|,
literal|3f63
argument_list|)
block|,
name|_0x
argument_list|(
argument|af2c
argument_list|,
literal|39b7
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L5x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|2eb4
argument_list|,
literal|3f3a
argument_list|)
block|,
name|_0x
argument_list|(
literal|655e
argument_list|,
argument|cc39
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L6x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|8551
argument_list|,
literal|3f1d
argument_list|)
block|,
name|_0x
argument_list|(
literal|781d
argument_list|,
argument|e8c5
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L7x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|95b3
argument_list|,
literal|3f08
argument_list|)
block|,
name|_0x
argument_list|(
argument|cd92
argument_list|,
literal|907f
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|L8x
index|[]
init|=
block|{
name|_0x
argument_list|(
literal|0000
argument_list|,
literal|3f00
argument_list|)
block|,
name|_0x
argument_list|(
literal|0000
argument_list|,
literal|0000
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|L1
value|(*(double*)L1x)
end_define

begin_define
define|#
directive|define
name|L2
value|(*(double*)L2x)
end_define

begin_define
define|#
directive|define
name|L3
value|(*(double*)L3x)
end_define

begin_define
define|#
directive|define
name|L4
value|(*(double*)L4x)
end_define

begin_define
define|#
directive|define
name|L5
value|(*(double*)L5x)
end_define

begin_define
define|#
directive|define
name|L6
value|(*(double*)L6x)
end_define

begin_define
define|#
directive|define
name|L7
value|(*(double*)L7x)
end_define

begin_define
define|#
directive|define
name|L8
value|(*(double*)L8x)
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
name|L1
init|=
literal|6.6666666666667340202E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -1   *  1.5555555555592 */
name|L2
init|=
literal|3.9999999999416702146E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -2   *  1.999999997FF24 */
name|L3
init|=
literal|2.8571428742008753154E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -2   *  1.24924941E07B4 */
name|L4
init|=
literal|2.2222198607186277597E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -3   *  1.C71C52150BEA6 */
name|L5
init|=
literal|1.8183562745289935658E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -3   *  1.74663CC94342F */
name|L6
init|=
literal|1.5314087275331442206E
operator|-
literal|1
decl_stmt|,
comment|/*Hex  2^ -3   *  1.39A1EC014045B */
name|L7
init|=
literal|1.4795612545334174692E
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^ -3   *  1.2F039F0085122 */
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
name|log__L
parameter_list|(
name|z
parameter_list|)
name|double
name|z
decl_stmt|;
block|{
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
return|return
operator|(
name|z
operator|*
operator|(
name|L1
operator|+
name|z
operator|*
operator|(
name|L2
operator|+
name|z
operator|*
operator|(
name|L3
operator|+
name|z
operator|*
operator|(
name|L4
operator|+
name|z
operator|*
operator|(
name|L5
operator|+
name|z
operator|*
operator|(
name|L6
operator|+
name|z
operator|*
operator|(
name|L7
operator|+
name|z
operator|*
name|L8
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
else|#
directive|else
comment|/* defined(vax)||defined(tahoe) */
return|return
operator|(
name|z
operator|*
operator|(
name|L1
operator|+
name|z
operator|*
operator|(
name|L2
operator|+
name|z
operator|*
operator|(
name|L3
operator|+
name|z
operator|*
operator|(
name|L4
operator|+
name|z
operator|*
operator|(
name|L5
operator|+
name|z
operator|*
operator|(
name|L6
operator|+
name|z
operator|*
name|L7
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
operator|)
return|;
endif|#
directive|endif
comment|/* defined(vax)||defined(tahoe) */
block|}
end_function

end_unit

