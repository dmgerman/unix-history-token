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
literal|"@(#)log__L.c	1.2 (Berkeley) 8/21/85; 1.2 (ucb.elefunt) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* log__L(Z)  *		LOG(1+X) - 2S			       X  * RETURN      ---------------  WHERE Z = S*S,  S = ------- , 0<= Z<= .0294...  *		      S				     2 + X  *		       * DOUBLE PRECISION (VAX D FORMAT 56 bits or IEEE DOUBLE 53 BITS)  * KERNEL FUNCTION FOR LOG; TO BE USED IN LOG1P, LOG, AND POW FUNCTIONS  * CODED IN C BY K.C. NG, 1/19/85;   * REVISED BY K.C. Ng, 2/3/85, 4/16/85.  *  * Method :  *	1. Polynomial approximation: let s = x/(2+x).   *	   Based on log(1+x) = log(1+s) - log(1-s)  *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,  *  *	   (log(1+x) - 2s)/s is computed by  *  *	       z*(L1 + z*(L2 + z*(... (L7 + z*L8)...)))  *  *	   where z=s*s. (See the listing below for Lk's values.) The   *	   coefficients are obtained by a special Remez algorithm.   *  * Accuracy:  *	Assuming no rounding error, the maximum magnitude of the approximation   *	error (absolute) is 2**(-58.49) for IEEE double, and 2**(-63.63)  *	for VAX D format.  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_comment
comment|/* VAX D format (56 bits) */
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
literal|0xaaaa402a
block|,
literal|0xaac5aaaa
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
literal|0xcccc3fcc
block|,
literal|0x2684cccc
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
literal|0x49243f92
block|,
literal|0x578292f8
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
literal|0x8e383f63
block|,
literal|0xaf2c39b7
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
literal|0x2eb43f3a
block|,
literal|0x655ecc39
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
literal|0x85513f1d
block|,
literal|0x781de8c5
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
literal|0x95b33f08
block|,
literal|0xcd92907f
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
literal|0x00003f00
block|,
literal|0x00000000
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
comment|/* IEEE double */
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
ifdef|#
directive|ifdef
name|VAX
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
comment|/* IEEE double */
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
block|}
end_function

end_unit

