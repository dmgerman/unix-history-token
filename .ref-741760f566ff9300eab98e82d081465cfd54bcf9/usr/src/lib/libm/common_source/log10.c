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
literal|"@(#)log10.c	1.2 (Berkeley) 8/21/85; 1.2 (ucb.elefunt) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* LOG10(X)  * RETURN THE BASE 10 LOGARITHM OF x  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 1/20/85;   * REVISED BY K.C. NG on 1/23/85, 3/7/85, 4/16/85.  *   * Required kernel function:  *	log(x)  *  * Method :  *			     log(x)  *		log10(x) = ---------  or  [1/log(10)]*log(x)  *			    log(10)  *  *    Note:  *	  [log(10)]   rounded to 56 bits has error  .0895  ulps,  *	  [1/log(10)] rounded to 53 bits has error  .198   ulps;  *	  therefore, for better accuracy, in VAX D format, we divide   *	  log(x) by log(10), but in IEEE Double format, we multiply   *	  log(x) by [1/log(10)].  *  * Special cases:  *	log10(x) is NaN with signal if x< 0;   *	log10(+INF) is +INF with no signal; log10(0) is -INF with signal;  *	log10(NaN) is that NaN with no signal.  *  * Accuracy:  *	log10(X) returns the exact log10(x) nearly rounded. In a test run  *	with 1,536,000 random arguments on a VAX, the maximum observed  *	error was 1.74 ulps (units in the last place).  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
comment|/* ln10hi =  2.3025850929940456790E0     ; Hex   2^  2   *  .935D8DDDAAA8AC */
end_comment

begin_decl_stmt
specifier|static
name|long
name|ln10hix
index|[]
init|=
block|{
literal|0x5d8d4113
block|,
literal|0xa8acddaa
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ln10hi
value|(*(double*)ln10hix)
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
name|ivln10
init|=
literal|4.3429448190325181667E
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex   2^ -2   *  1.BCB7B1526E50E */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|log10
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|log
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|VAX
return|return
operator|(
name|log
argument_list|(
name|x
argument_list|)
operator|/
name|ln10hi
operator|)
return|;
else|#
directive|else
comment|/* IEEE double */
return|return
operator|(
name|ivln10
operator|*
name|log
argument_list|(
name|x
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

