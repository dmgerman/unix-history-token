begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)floor.c	4.2	9/11/85 */
end_comment

begin_comment
comment|/*  * floor and ceil-- greatest integer<= arg  * (resp least>=)  */
end_comment

begin_function_decl
name|double
name|modf
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|double
name|floor
parameter_list|(
name|d
parameter_list|)
name|double
name|d
decl_stmt|;
block|{
name|double
name|fract
decl_stmt|;
if|if
condition|(
name|d
operator|<
literal|0.0
condition|)
block|{
name|d
operator|=
operator|-
name|d
expr_stmt|;
name|fract
operator|=
name|modf
argument_list|(
name|d
argument_list|,
operator|&
name|d
argument_list|)
expr_stmt|;
if|if
condition|(
name|fract
operator|!=
literal|0.0
condition|)
name|d
operator|+=
literal|1
expr_stmt|;
name|d
operator|=
operator|-
name|d
expr_stmt|;
block|}
else|else
name|modf
argument_list|(
name|d
argument_list|,
operator|&
name|d
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|)
return|;
block|}
end_function

begin_function
name|double
name|ceil
parameter_list|(
name|d
parameter_list|)
name|double
name|d
decl_stmt|;
block|{
return|return
operator|(
operator|-
name|floor
argument_list|(
operator|-
name|d
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * algorithm for rint(x) in pseudo-pascal form ...  *  * real rint(x): real x;  *	... delivers integer nearest x in direction of prevailing rounding  *	... mode  * const	L = (last consecutive integer)/2  * 	  = 2**55; for VAX D  * 	  = 2**52; for IEEE 754 Double  * real	s,t;  * begin  * 	if x != x then return x;		... NaN  * 	if |x|>= L then return x;		... already an integer  * 	s := copysign(L,x);  * 	t := x + s;				... = (x+s) rounded to integer  * 	return t - s  * end;  *  * Note: Inexact will be signaled if x is not an integer, as is  *	customary for IEEE 754.  No other signal can be emitted.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX
end_ifdef

begin_decl_stmt
specifier|static
name|long
name|Lx
index|[]
init|=
block|{
literal|0x5c00
block|,
literal|0x0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2**55 */
end_comment

begin_define
define|#
directive|define
name|L
value|*(double *) Lx
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
name|L
init|=
literal|4503599627370496.0E0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2**52 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
decl_stmt|,
name|one
init|=
literal|1.0
decl_stmt|,
name|copysign
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|VAX
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

end_unit

