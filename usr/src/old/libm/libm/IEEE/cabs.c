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
literal|"@(#)cabs.c	1.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* HYPOT(X,Y)   * RETURN THE SQUARE ROOT OF X^2 + Y^2  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 11/28/84.  *  * Required kernel function :  *	cabs(x,y)  *  * Method :  *	hypot(x,y) = cabs(x,y) .  */
end_comment

begin_function
name|double
name|hypot
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|{
name|double
name|cabs
parameter_list|()
function_decl|;
return|return
operator|(
name|cabs
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* CABS(REAL,IMAG)  * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  REAL + i*IMAG  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 11/28/84;   * REVISED BY K.C. NG on 2/7/85, 2/22/85, 3/7/85, 3/30/85, 4/16/85.  *  * Required system supported functions :  *	copysign(x,y)  *	finite(x)  *	scalb(x,N)  *	sqrt(x)  *  * Method :  *	1. replace real by |real| and imag by |imag|, and swap real and  *	   imag if imag> real (hence real is never smaller than imag).  *	2. Let X=real and Y=imag, cabs(X,Y) is computed by:  *	   Case I, X/Y> 2  *		  *				       Y  *		cabs = X + -----------------------------  *			 		    2  *			    sqrt ( 1 + [X/Y]  )  +  X/Y  *  *	   Case II, X/Y<= 2   *				                   Y  *		cabs = X + --------------------------------------------------  *				          		     2   *				     			[X/Y]   -  2  *			   (sqrt(2)+1) + (X-Y)/Y + -----------------------------  *			 		    			  2  *			    			  sqrt ( 1 + [X/Y]  )  + sqrt(2)  *  *  *  * Special cases:  *	cabs(x,y) is INF if x or y is +INF or -INF; else  *	cabs(x,y) is NAN if x or y is NAN.  *  * Accuracy:  * 	cabs(x,y) returns the sqrt(x^2+y^2) with error less than 1 ulps (units  *	in the last place). See Kahan's "Interval Arithmetic Options in the  *	Proposed IEEE Floating Point Arithmetic Standard", Interval Mathematics  *      1980, Edited by Karl L.E. Nickel, pp 99-128. (A faster but less accurate  *	code follows in	comments.) In a test run with 500,000 random arguments  *	on a VAX, the maximum observed error was .959 ulps.  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
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
comment|/* r2p1hi =  2.4142135623730950345E0     , Hex  2^  2   *  .9A827999FCEF32 */
end_comment

begin_comment
comment|/* r2p1lo =  1.4349369327986523769E-17   , Hex  2^-55   *  .84597D89B3754B */
end_comment

begin_comment
comment|/* sqrt2  =  1.4142135623730950622E0     ; Hex  2^  1   *  .B504F333F9DE65 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|r2p1hix
index|[]
init|=
block|{
literal|0x8279411a
block|,
literal|0xef3299fc
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|r2p1lox
index|[]
init|=
block|{
literal|0x597d2484
block|,
literal|0x754b89b3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|sqrt2x
index|[]
init|=
block|{
literal|0x04f340b5
block|,
literal|0xde6533f9
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|r2p1hi
value|(*(double*)r2p1hix)
end_define

begin_define
define|#
directive|define
name|r2p1lo
value|(*(double*)r2p1lox)
end_define

begin_define
define|#
directive|define
name|sqrt2
value|(*(double*)sqrt2x)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IEEE double format */
end_comment

begin_decl_stmt
specifier|static
name|double
name|r2p1hi
init|=
literal|2.4142135623730949234E0
decl_stmt|,
comment|/*Hex  2^1     *  1.3504F333F9DE6 */
name|r2p1lo
init|=
literal|1.2537167179050217666E
operator|-
literal|16
decl_stmt|,
comment|/*Hex  2^-53   *  1.21165F626CDD5 */
name|sqrt2
init|=
literal|1.4142135623730951455E0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*Hex  2^  0   *  1.6A09E667F3BCD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
name|cabs
parameter_list|(
name|real
parameter_list|,
name|imag
parameter_list|)
name|double
name|real
decl_stmt|,
name|imag
decl_stmt|;
block|{
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
name|small
init|=
literal|1.0E
operator|-
literal|18
decl_stmt|;
comment|/* fl(1+small)==1 */
specifier|static
name|ibig
operator|=
literal|30
expr_stmt|;
comment|/* fl(1+2**(2*ibig))==1 */
name|double
name|copysign
argument_list|()
decl_stmt|,
name|scalb
argument_list|()
decl_stmt|,
name|logb
argument_list|()
decl_stmt|,
name|sqrt
argument_list|()
decl_stmt|,
name|t
decl_stmt|,
name|r
decl_stmt|;
name|int
name|finite
argument_list|()
decl_stmt|,
name|exp
decl_stmt|;
if|if
condition|(
name|finite
argument_list|(
name|real
argument_list|)
condition|)
if|if
condition|(
name|finite
argument_list|(
name|imag
argument_list|)
condition|)
block|{
name|real
operator|=
name|copysign
argument_list|(
name|real
argument_list|,
name|one
argument_list|)
expr_stmt|;
name|imag
operator|=
name|copysign
argument_list|(
name|imag
argument_list|,
name|one
argument_list|)
expr_stmt|;
if|if
condition|(
name|imag
operator|>
name|real
condition|)
block|{
name|t
operator|=
name|real
expr_stmt|;
name|real
operator|=
name|imag
expr_stmt|;
name|imag
operator|=
name|t
expr_stmt|;
block|}
if|if
condition|(
name|real
operator|==
name|zero
condition|)
return|return
operator|(
name|zero
operator|)
return|;
if|if
condition|(
name|imag
operator|==
name|zero
condition|)
return|return
operator|(
name|real
operator|)
return|;
name|exp
operator|=
name|logb
argument_list|(
name|real
argument_list|)
expr_stmt|;
if|if
condition|(
name|exp
operator|-
operator|(
name|int
operator|)
name|logb
argument_list|(
name|imag
argument_list|)
operator|>
name|ibig
condition|)
comment|/* raise inexact flag and return |real| */
block|{
name|one
operator|+
name|small
expr_stmt|;
return|return
operator|(
name|real
operator|)
return|;
block|}
comment|/* start computing sqrt(real^2 + imag^2) */
name|r
operator|=
name|real
operator|-
name|imag
expr_stmt|;
if|if
condition|(
name|r
operator|>
name|imag
condition|)
block|{
comment|/* real/imag> 2 */
name|r
operator|=
name|real
operator|/
name|imag
expr_stmt|;
name|r
operator|=
name|r
operator|+
name|sqrt
argument_list|(
name|one
operator|+
name|r
operator|*
name|r
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* 1<= real/imag<= 2 */
name|r
operator|/=
name|imag
expr_stmt|;
name|t
operator|=
name|r
operator|*
operator|(
name|r
operator|+
literal|2.0
operator|)
expr_stmt|;
name|r
operator|+=
name|t
operator|/
operator|(
name|sqrt2
operator|+
name|sqrt
argument_list|(
literal|2.0
operator|+
name|t
argument_list|)
operator|)
expr_stmt|;
name|r
operator|+=
name|r2p1lo
expr_stmt|;
name|r
operator|+=
name|r2p1hi
expr_stmt|;
block|}
name|r
operator|=
name|imag
operator|/
name|r
expr_stmt|;
return|return
operator|(
name|real
operator|+
name|r
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|imag
operator|==
name|imag
condition|)
comment|/* imag is +-INF */
return|return
operator|(
name|copysign
argument_list|(
name|imag
argument_list|,
name|one
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|imag
operator|)
return|;
comment|/* imag is NaN and x is finite */
elseif|else
if|if
condition|(
name|real
operator|==
name|real
condition|)
comment|/* real is +-INF */
return|return
operator|(
name|copysign
argument_list|(
name|real
argument_list|,
name|one
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|finite
argument_list|(
name|imag
argument_list|)
condition|)
return|return
operator|(
name|real
operator|)
return|;
comment|/* real is NaN, imag is finite */
elseif|else
if|if
condition|(
name|imag
operator|!=
name|imag
condition|)
return|return
operator|(
name|imag
operator|)
return|;
comment|/* real and imag is NaN */
else|else
return|return
operator|(
name|copysign
argument_list|(
name|imag
argument_list|,
name|one
argument_list|)
operator|)
return|;
comment|/* imag is INF */
block|}
end_function

begin_comment
comment|/* A faster but less accurate version of cabs(real,imag) */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|double cabs(real,imag) double real, imag; { 	static double zero=0, one=1; 		      small=1.0E-18;
comment|/* fl(1+small)==1 */
end_comment

begin_comment
unit|static ibig=30;
comment|/* fl(1+2**(2*ibig))==1 */
end_comment

begin_comment
unit|double copysign(),scalb(),logb(),sqrt(),temp; 	int finite(), exp;  	if(finite(real)) 	    if(finite(imag)) 	    {	 		real=copysign(real,one); 		imag=copysign(imag,one); 		if(imag> real)  		    { temp=real; real=imag; imag=temp; } 		if(real == zero) return(zero); 		if(imag == zero) return(real); 		exp= logb(real); 		real=scalb(real,-exp); 		if(exp-(int)logb(imag)> ibig )
comment|/* raise inexact flag and return |real| */
end_comment

begin_comment
unit|{ one+small; return(scalb(real,exp)); } 		else imag=scalb(imag,-exp); 		return(scalb(sqrt(real*real+imag*imag),exp)); 	    }  	    else if(imag==imag)
comment|/* imag is +-INF */
end_comment

begin_comment
unit|return(copysign(imag,one)); 	    else  		     return(imag);
comment|/* imag is NaN and x is finite */
end_comment

begin_comment
unit|else if(real==real)
comment|/* real is +-INF */
end_comment

begin_comment
unit|return (copysign(real,one)); 	else if(finite(imag)) 	         return(real);
comment|/* real is NaN, imag is finite */
end_comment

begin_comment
unit|else if(imag!=imag) return(imag);
comment|/* real and imag is NaN */
end_comment

begin_comment
unit|else return(copysign(imag,one));
comment|/* imag is INF */
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

