begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)cabs.c	8.1 (Berkeley) 6/4/93"
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
comment|/* HYPOT(X,Y)  * RETURN THE SQUARE ROOT OF X^2 + Y^2  WHERE Z=X+iY  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 11/28/84;  * REVISED BY K.C. NG, 7/12/85.  *  * Required system supported functions :  *	copysign(x,y)  *	finite(x)  *	scalb(x,N)  *	sqrt(x)  *  * Method :  *	1. replace x by |x| and y by |y|, and swap x and  *	   y if y> x (hence x is never smaller than y).  *	2. Hypot(x,y) is computed by:  *	   Case I, x/y> 2  *  *				       y  *		hypot = x + -----------------------------  *			 		    2  *			    sqrt ( 1 + [x/y]  )  +  x/y  *  *	   Case II, x/y<= 2  *				                   y  *		hypot = x + --------------------------------------------------  *				          		     2  *				     			[x/y]   -  2  *			   (sqrt(2)+1) + (x-y)/y + -----------------------------  *			 		    			  2  *			    			  sqrt ( 1 + [x/y]  )  + sqrt(2)  *  *  *  * Special cases:  *	hypot(x,y) is INF if x or y is +INF or -INF; else  *	hypot(x,y) is NAN if x or y is NAN.  *  * Accuracy:  * 	hypot(x,y) returns the sqrt(x^2+y^2) with error less than 1 ulps (units  *	in the last place). See Kahan's "Interval Arithmetic Options in the  *	Proposed IEEE Floating Point Arithmetic Standard", Interval Mathematics  *      1980, Edited by Karl L.E. Nickel, pp 99-128. (A faster but less accurate  *	code follows in	comments.) In a test run with 500,000 random arguments  *	on a VAX, the maximum observed error was .959 ulps.  *  * Constants:  * The hexadecimal values are the intended ones for the following constants.  * The decimal values may be used, provided that the compiler will convert  * from decimal to binary accurately enough to produce the hexadecimal values  * shown.  */
end_comment

begin_include
include|#
directive|include
file|"mathimpl.h"
end_include

begin_macro
name|vc
argument_list|(
argument|r2p1hi
argument_list|,
literal|2.4142135623730950345E0
argument_list|,
literal|8279
argument_list|,
literal|411a
argument_list|,
argument|ef32
argument_list|,
literal|99fc
argument_list|,
literal|2
argument_list|,
literal|.9A827999FCEF32
argument_list|)
end_macro

begin_macro
name|vc
argument_list|(
argument|r2p1lo
argument_list|,
literal|1.4349369327986523769E
argument|-
literal|17
argument_list|,
literal|597d
argument_list|,
literal|2484
argument_list|,
literal|754b
argument_list|,
literal|89b3
argument_list|,
argument|-
literal|55
argument_list|,
literal|.84597D89B3754B
argument_list|)
end_macro

begin_macro
name|vc
argument_list|(
argument|sqrt2
argument_list|,
literal|1.4142135623730950622E0
argument_list|,
literal|04f3
argument_list|,
literal|40b5
argument_list|,
argument|de65
argument_list|,
literal|33f9
argument_list|,
literal|1
argument_list|,
argument|.B504F333F9DE65
argument_list|)
end_macro

begin_macro
name|ic
argument_list|(
argument|r2p1hi
argument_list|,
literal|2.4142135623730949234E0
argument_list|,
literal|1
argument_list|,
literal|1.3504F333F9DE6
argument_list|)
end_macro

begin_macro
name|ic
argument_list|(
argument|r2p1lo
argument_list|,
literal|1.2537167179050217666E
argument|-
literal|16
argument_list|,
argument|-
literal|53
argument_list|,
literal|1.21165F626CDD5
argument_list|)
end_macro

begin_macro
name|ic
argument_list|(
argument|sqrt2
argument_list|,
literal|1.4142135623730951455E0
argument_list|,
literal|0
argument_list|,
literal|1.6A09E667F3BCD
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|vccast
end_ifdef

begin_define
define|#
directive|define
name|r2p1hi
value|vccast(r2p1hi)
end_define

begin_define
define|#
directive|define
name|r2p1lo
value|vccast(r2p1lo)
end_define

begin_define
define|#
directive|define
name|sqrt2
value|vccast(sqrt2)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
specifier|static
specifier|const
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
specifier|const
name|ibig
operator|=
literal|30
expr_stmt|;
comment|/* fl(1+2**(2*ibig))==1 */
name|double
name|t
decl_stmt|,
name|r
decl_stmt|;
name|int
name|exp
decl_stmt|;
if|if
condition|(
name|finite
argument_list|(
name|x
argument_list|)
condition|)
if|if
condition|(
name|finite
argument_list|(
name|y
argument_list|)
condition|)
block|{
name|x
operator|=
name|copysign
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
expr_stmt|;
name|y
operator|=
name|copysign
argument_list|(
name|y
argument_list|,
name|one
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|x
condition|)
block|{
name|t
operator|=
name|x
expr_stmt|;
name|x
operator|=
name|y
expr_stmt|;
name|y
operator|=
name|t
expr_stmt|;
block|}
if|if
condition|(
name|x
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
name|y
operator|==
name|zero
condition|)
return|return
operator|(
name|x
operator|)
return|;
name|exp
operator|=
name|logb
argument_list|(
name|x
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
name|y
argument_list|)
operator|>
name|ibig
condition|)
comment|/* raise inexact flag and return |x| */
block|{
name|one
operator|+
name|small
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
comment|/* start computing sqrt(x^2 + y^2) */
name|r
operator|=
name|x
operator|-
name|y
expr_stmt|;
if|if
condition|(
name|r
operator|>
name|y
condition|)
block|{
comment|/* x/y> 2 */
name|r
operator|=
name|x
operator|/
name|y
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
comment|/* 1<= x/y<= 2 */
name|r
operator|/=
name|y
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
name|y
operator|/
name|r
expr_stmt|;
return|return
operator|(
name|x
operator|+
name|r
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|==
name|y
condition|)
comment|/* y is +-INF */
return|return
operator|(
name|copysign
argument_list|(
name|y
argument_list|,
name|one
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|y
operator|)
return|;
comment|/* y is NaN and x is finite */
elseif|else
if|if
condition|(
name|x
operator|==
name|x
condition|)
comment|/* x is +-INF */
return|return
operator|(
name|copysign
argument_list|(
name|x
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
name|y
argument_list|)
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* x is NaN, y is finite */
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
elseif|else
if|if
condition|(
name|y
operator|!=
name|y
condition|)
return|return
operator|(
name|y
operator|)
return|;
comment|/* x and y is NaN */
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
else|else
return|return
operator|(
name|copysign
argument_list|(
name|y
argument_list|,
name|one
argument_list|)
operator|)
return|;
comment|/* y is INF */
block|}
end_function

begin_comment
comment|/* CABS(Z)  * RETURN THE ABSOLUTE VALUE OF THE COMPLEX NUMBER  Z = X + iY  * DOUBLE PRECISION (VAX D format 56 bits, IEEE DOUBLE 53 BITS)  * CODED IN C BY K.C. NG, 11/28/84.  * REVISED BY K.C. NG, 7/12/85.  *  * Required kernel function :  *	hypot(x,y)  *  * Method :  *	cabs(z) = hypot(x,y) .  */
end_comment

begin_struct
struct|struct
name|complex
block|{
name|double
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|double
name|cabs
parameter_list|(
name|z
parameter_list|)
name|struct
name|complex
name|z
decl_stmt|;
block|{
return|return
name|hypot
argument_list|(
name|z
operator|.
name|x
argument_list|,
name|z
operator|.
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|z_abs
parameter_list|(
name|z
parameter_list|)
name|struct
name|complex
modifier|*
name|z
decl_stmt|;
block|{
return|return
name|hypot
argument_list|(
name|z
operator|->
name|x
argument_list|,
name|z
operator|->
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* A faster but less accurate version of cabs(x,y) */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|double hypot(x,y) double x, y; { 	static const double zero=0, one=1; 		      small=1.0E-18;
comment|/* fl(1+small)==1 */
end_comment

begin_comment
unit|static const ibig=30;
comment|/* fl(1+2**(2*ibig))==1 */
end_comment

begin_comment
unit|double temp; 	int exp;  	if(finite(x)) 	    if(finite(y)) 	    { 		x=copysign(x,one); 		y=copysign(y,one); 		if(y> x) 		    { temp=x; x=y; y=temp; } 		if(x == zero) return(zero); 		if(y == zero) return(x); 		exp= logb(x); 		x=scalb(x,-exp); 		if(exp-(int)logb(y)> ibig )
comment|/* raise inexact flag and return |x| */
end_comment

begin_comment
unit|{ one+small; return(scalb(x,exp)); } 		else y=scalb(y,-exp); 		return(scalb(sqrt(x*x+y*y),exp)); 	    }  	    else if(y==y)
comment|/* y is +-INF */
end_comment

begin_comment
unit|return(copysign(y,one)); 	    else 		     return(y);
comment|/* y is NaN and x is finite */
end_comment

begin_comment
unit|else if(x==x)
comment|/* x is +-INF */
end_comment

begin_comment
unit|return (copysign(x,one)); 	else if(finite(y)) 	         return(x);
comment|/* x is NaN, y is finite */
end_comment

begin_comment
unit|else if(y!=y) return(y);
comment|/* x and y is NaN */
end_comment

begin_comment
unit|else return(copysign(y,one));
comment|/* y is INF */
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

