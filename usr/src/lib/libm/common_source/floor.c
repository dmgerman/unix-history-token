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
literal|"@(#)floor.c	5.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"mathimpl.h"
end_include

begin_macro
name|vc
argument_list|(
argument|L
argument_list|,
literal|4503599627370496.0E0
argument_list|,
literal|0000
argument_list|,
literal|5c00
argument_list|,
literal|0000
argument_list|,
literal|0000
argument_list|,
literal|55
argument_list|,
literal|1.0
argument_list|)
end_macro

begin_comment
comment|/* 2**55 */
end_comment

begin_macro
name|ic
argument_list|(
argument|L
argument_list|,
literal|4503599627370496.0E0
argument_list|,
literal|52
argument_list|,
literal|1.0
argument_list|)
end_macro

begin_comment
comment|/* 2**52 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vccast
end_ifdef

begin_define
define|#
directive|define
name|L
value|vccast(L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|double
name|ceil
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|floor
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * floor(x) := the largest integer no larger than x;  * ceil(x) := -floor(-x), for all real x.  *  * Note: Inexact will be signaled if x is not an integer, as is  *	customary for IEEE 754.  No other signal can be emitted.  */
end_comment

begin_function
name|double
name|floor
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|y
decl_stmt|;
if|if
condition|(
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
name|x
operator|!=
name|x
operator|||
comment|/* NaN */
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
name|x
operator|>=
name|L
condition|)
comment|/* already an even integer */
return|return
name|x
return|;
elseif|else
if|if
condition|(
name|x
operator|<
operator|(
name|double
operator|)
literal|0
condition|)
return|return
operator|-
name|ceil
argument_list|(
operator|-
name|x
argument_list|)
return|;
else|else
block|{
comment|/* now 0<= x< L */
name|y
operator|=
name|L
operator|+
name|x
expr_stmt|;
comment|/* destructive store must be forced */
name|y
operator|-=
name|L
expr_stmt|;
comment|/* an integer, and |x-y|< 1 */
return|return
name|x
operator|<
name|y
condition|?
name|y
operator|-
operator|(
name|double
operator|)
literal|1
else|:
name|y
return|;
block|}
block|}
end_function

begin_function
name|double
name|ceil
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|y
decl_stmt|;
if|if
condition|(
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
name|x
operator|!=
name|x
operator|||
comment|/* NaN */
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
name|x
operator|>=
name|L
condition|)
comment|/* already an even integer */
return|return
name|x
return|;
elseif|else
if|if
condition|(
name|x
operator|<
operator|(
name|double
operator|)
literal|0
condition|)
return|return
operator|-
name|floor
argument_list|(
operator|-
name|x
argument_list|)
return|;
else|else
block|{
comment|/* now 0<= x< L */
name|y
operator|=
name|L
operator|+
name|x
expr_stmt|;
comment|/* destructive store must be forced */
name|y
operator|-=
name|L
expr_stmt|;
comment|/* an integer, and |x-y|< 1 */
return|return
name|x
operator|>
name|y
condition|?
name|y
operator|+
operator|(
name|double
operator|)
literal|1
else|:
name|y
return|;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|national
end_ifndef

begin_comment
comment|/* rint() is in ./NATIONAL/support.s */
end_comment

begin_comment
comment|/*  * algorithm for rint(x) in pseudo-pascal form ...  *  * real rint(x): real x;  *	... delivers integer nearest x in direction of prevailing rounding  *	... mode  * const	L = (last consecutive integer)/2  * 	  = 2**55; for VAX D  * 	  = 2**52; for IEEE 754 Double  * real	s,t;  * begin  * 	if x != x then return x;		... NaN  * 	if |x|>= L then return x;		... already an integer  * 	s := copysign(L,x);  * 	t := x + s;				... = (x+s) rounded to integer  * 	return t - s  * end;  *  * Note: Inexact will be signaled if x is not an integer, as is  *	customary for IEEE 754.  No other signal can be emitted.  */
end_comment

begin_function
name|double
name|rint
parameter_list|(
name|x
parameter_list|)
name|double
name|x
decl_stmt|;
block|{
name|double
name|s
decl_stmt|,
name|t
decl_stmt|;
specifier|const
name|double
name|one
init|=
literal|1.0
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
comment|/* NaN */
return|return
operator|(
name|x
operator|)
return|;
endif|#
directive|endif
comment|/* !defined(vax)&&!defined(tahoe) */
if|if
condition|(
name|copysign
argument_list|(
name|x
argument_list|,
name|one
argument_list|)
operator|>=
name|L
condition|)
comment|/* already an integer */
return|return
operator|(
name|x
operator|)
return|;
name|s
operator|=
name|copysign
argument_list|(
name|L
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|t
operator|=
name|x
operator|+
name|s
expr_stmt|;
comment|/* x+s rounded to integer */
return|return
operator|(
name|t
operator|-
name|s
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not national */
end_comment

end_unit

