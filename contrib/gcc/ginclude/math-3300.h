begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************\ *								   * *<math-68881.h>		last modified: 18 May 1989.	   * *								   * *  Copyright (C) 1989 by Matthew Self.				   * *  You may freely distribute verbatim copies of this software	   * *  provided that this copyright notice is retained in all copies.  * *  You may distribute modifications to this software under the     * *  conditions above if you also clearly note such modifications    * *  with their author and date.			   	     	   * *								   * *  Note:  errno is not set to EDOM when domain errors occur for    * *  most of these functions.  Rather, it is assumed that the	   * *  68881's OPERR exception will be enabled and handled		   * *  appropriately by the	operating system.  Similarly, overflow	   * *  and underflow do not set errno to ERANGE.			   * *								   * *  Send bugs to Matthew Self (self@bayes.arc.nasa.gov).		   * *								   * \******************************************************************/
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_undef
undef|#
directive|undef
name|HUGE_VAL
end_undef

begin_define
define|#
directive|define
name|HUGE_VAL
define|\
value|({									\   double huge_val;							\ 									\   __asm ("fmove%.d %#0x7ff0000000000000,%0"
comment|/* Infinity */
value|\ 	 : "=f" (huge_val)						\ 	 :
comment|/* no inputs */
value|);						\   huge_val;								\ })
end_define

begin_function
name|__inline
specifier|static
specifier|const
name|double
name|sin
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fsin%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|cos
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fcos%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|tan
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("ftan%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|asin
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fasin%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|acos
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("facos%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|atan
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fatan%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|atan2
parameter_list|(
name|double
name|y
parameter_list|,
name|double
name|x
parameter_list|)
block|{
name|double
name|pi
decl_stmt|,
name|pi_over_2
decl_stmt|;
asm|__asm ("fmovecr%.x %#0,%0"
comment|/* extended precision pi */
block|:
literal|"=f"
operator|(
name|pi
operator|)
operator|:
comment|/* no inputs */
block|)
function|;
end_function

begin_asm
asm|__asm ("fscale%.b %#-1,%0"
end_asm

begin_comment
comment|/* no loss of accuracy */
end_comment

begin_expr_stmt
unit|:
literal|"=f"
operator|(
name|pi_over_2
operator|)
operator|:
literal|"0"
operator|(
name|pi
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|y
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|x
operator|>
name|y
condition|)
return|return
name|atan
argument_list|(
name|y
operator|/
name|x
argument_list|)
return|;
else|else
return|return
name|pi_over_2
operator|-
name|atan
argument_list|(
name|x
operator|/
name|y
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|x
operator|>
operator|-
name|y
condition|)
return|return
name|atan
argument_list|(
name|y
operator|/
name|x
argument_list|)
return|;
else|else
return|return
operator|-
name|pi_over_2
operator|-
name|atan
argument_list|(
name|x
operator|/
name|y
argument_list|)
return|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|y
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|-
name|x
operator|>
name|y
condition|)
return|return
name|pi
operator|+
name|atan
argument_list|(
name|y
operator|/
name|x
argument_list|)
return|;
else|else
return|return
name|pi_over_2
operator|-
name|atan
argument_list|(
name|x
operator|/
name|y
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
operator|-
name|x
operator|>
operator|-
name|y
condition|)
return|return
operator|-
name|pi
operator|+
name|atan
argument_list|(
name|y
operator|/
name|x
argument_list|)
return|;
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
return|return
operator|-
name|pi_over_2
operator|-
name|atan
argument_list|(
name|x
operator|/
name|y
argument_list|)
return|;
else|else
block|{
name|double
name|value
decl_stmt|;
name|errno
operator|=
name|EDOM
expr_stmt|;
asm|__asm ("fmove%.d %#0x7fffffffffffffff,%0"
comment|/* quiet NaN */
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
comment|/* no inputs */
block|)
empty_stmt|;
return|return
name|value
return|;
block|}
block|}
end_if

begin_function
unit|} }
name|__inline
specifier|static
specifier|const
name|double
name|sinh
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fsinh%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|cosh
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fcosh%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|tanh
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("ftanh%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|atanh
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fatanh%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|exp
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fetox%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|expm1
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fetoxm1%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|log
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("flogn%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|log1p
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("flognp1%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|log10
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("flog10%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|sqrt
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fsqrt%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|pow
parameter_list|(
specifier|const
name|double
name|x
parameter_list|,
specifier|const
name|double
name|y
parameter_list|)
block|{
if|if
condition|(
name|x
operator|>
literal|0
condition|)
return|return
name|exp
argument_list|(
name|y
operator|*
name|log
argument_list|(
name|x
argument_list|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|x
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|y
operator|>
literal|0
condition|)
return|return
literal|0.0
return|;
else|else
block|{
name|double
name|value
decl_stmt|;
name|errno
operator|=
name|EDOM
expr_stmt|;
asm|__asm ("fmove%.d %#0x7fffffffffffffff,%0"
comment|/* quiet NaN */
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
comment|/* no inputs */
block|)
empty_stmt|;
return|return
name|value
return|;
block|}
block|}
end_function

begin_else
else|else
block|{
name|double
name|temp
decl_stmt|;
asm|__asm ("fintrz%.x %1,%0"
block|:
literal|"=f"
operator|(
name|temp
operator|)
comment|/* integer-valued float */
operator|:
literal|"f"
operator|(
name|y
operator|)
block|)
empty_stmt|;
end_else

begin_if
if|if
condition|(
name|y
operator|==
name|temp
condition|)
block|{
name|int
name|i
init|=
operator|(
name|int
operator|)
name|y
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
comment|/* even */
return|return
name|exp
argument_list|(
name|y
operator|*
name|log
argument_list|(
name|x
argument_list|)
argument_list|)
return|;
else|else
return|return
operator|-
name|exp
argument_list|(
name|y
operator|*
name|log
argument_list|(
name|x
argument_list|)
argument_list|)
return|;
block|}
else|else
block|{
name|double
name|value
decl_stmt|;
name|errno
operator|=
name|EDOM
expr_stmt|;
asm|__asm ("fmove%.d %#0x7fffffffffffffff,%0"
comment|/* quiet NaN */
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
comment|/* no inputs */
block|)
empty_stmt|;
end_if

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}     } }  __inline
specifier|static
specifier|const
name|double
name|fabs
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fabs%.x %1,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|ceil
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|rounding_mode
decl_stmt|,
name|round_up
decl_stmt|;
name|double
name|value
decl_stmt|;
asm|__asm volatile ("fmove%.l %%fpcr,%0"
block|:
literal|"=dm"
operator|(
name|rounding_mode
operator|)
operator|:
comment|/* no inputs */
block|)
function|;
end_function

begin_expr_stmt
name|round_up
operator|=
name|rounding_mode
operator||
literal|0x30
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|round_up
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fint%.x %1,%0"
end_asm

begin_expr_stmt
unit|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|rounding_mode
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|floor
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|rounding_mode
decl_stmt|,
name|round_down
decl_stmt|;
name|double
name|value
decl_stmt|;
asm|__asm volatile ("fmove%.l %%fpcr,%0"
block|:
literal|"=dm"
operator|(
name|rounding_mode
operator|)
operator|:
comment|/* no inputs */
block|)
function|;
end_function

begin_expr_stmt
name|round_down
operator|=
operator|(
name|rounding_mode
operator|&
operator|~
literal|0x10
operator|)
operator||
literal|0x20
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|round_down
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fint%.x %1,%0"
end_asm

begin_expr_stmt
unit|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|rounding_mode
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|rint
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|int
name|rounding_mode
decl_stmt|,
name|round_nearest
decl_stmt|;
name|double
name|value
decl_stmt|;
asm|__asm volatile ("fmove%.l %%fpcr,%0"
block|:
literal|"=dm"
operator|(
name|rounding_mode
operator|)
operator|:
comment|/* no inputs */
block|)
function|;
end_function

begin_expr_stmt
name|round_nearest
operator|=
name|rounding_mode
operator|&
operator|~
literal|0x30
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|round_nearest
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fint%.x %1,%0"
end_asm

begin_expr_stmt
unit|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_asm
asm|__asm volatile ("fmove%.l %0,%%fpcr"
end_asm

begin_comment
unit|:
comment|/* no outputs */
end_comment

begin_expr_stmt
unit|:
literal|"dmi"
operator|(
name|rounding_mode
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|fmod
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fmod%.x %2,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"0"
operator|(
name|x
operator|)
operator|,
literal|"f"
operator|(
name|y
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|drem
parameter_list|(
name|double
name|x
parameter_list|,
name|double
name|y
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("frem%.x %2,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"0"
operator|(
name|x
operator|)
operator|,
literal|"f"
operator|(
name|y
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|scalb
parameter_list|(
name|double
name|x
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fscale%.l %2,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"0"
operator|(
name|x
operator|)
operator|,
literal|"dmi"
operator|(
name|n
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
name|double
name|logb
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|double
name|exponent
decl_stmt|;
asm|__asm ("fgetexp%.x %1,%0"
block|:
literal|"=f"
operator|(
name|exponent
operator|)
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_return
return|return
name|exponent
return|;
end_return

begin_function
unit|}  __inline
specifier|static
specifier|const
name|double
name|ldexp
parameter_list|(
name|double
name|x
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|double
name|value
decl_stmt|;
asm|__asm ("fscale%.l %2,%0"
block|:
literal|"=f"
operator|(
name|value
operator|)
operator|:
literal|"0"
operator|(
name|x
operator|)
operator|,
literal|"dmi"
operator|(
name|n
operator|)
block|)
function|;
end_function

begin_return
return|return
name|value
return|;
end_return

begin_function
unit|}  __inline
specifier|static
name|double
name|frexp
parameter_list|(
name|double
name|x
parameter_list|,
name|int
modifier|*
name|exp
parameter_list|)
block|{
name|double
name|float_exponent
decl_stmt|;
name|int
name|int_exponent
decl_stmt|;
name|double
name|mantissa
decl_stmt|;
asm|__asm ("fgetexp%.x %1,%0"
block|:
literal|"=f"
operator|(
name|float_exponent
operator|)
comment|/* integer-valued float */
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|int_exponent
operator|=
operator|(
name|int
operator|)
name|float_exponent
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm ("fgetman%.x %1,%0"
end_asm

begin_expr_stmt
unit|:
literal|"=f"
operator|(
name|mantissa
operator|)
comment|/* 1.0<= mantissa< 2.0 */
operator|:
literal|"f"
operator|(
name|x
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|mantissa
operator|!=
literal|0
condition|)
block|{
asm|__asm ("fscale%.b %#-1,%0"
block|:
literal|"=f"
operator|(
name|mantissa
operator|)
comment|/* mantissa /= 2.0 */
operator|:
literal|"0"
operator|(
name|mantissa
operator|)
block|)
empty_stmt|;
end_if

begin_expr_stmt
name|int_exponent
operator|+=
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}   *
name|exp
operator|=
name|int_exponent
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|mantissa
return|;
end_return

begin_function
unit|}  __inline
specifier|static
name|double
name|modf
parameter_list|(
name|double
name|x
parameter_list|,
name|double
modifier|*
name|ip
parameter_list|)
block|{
name|double
name|temp
decl_stmt|;
asm|__asm ("fintrz%.x %1,%0"
block|:
literal|"=f"
operator|(
name|temp
operator|)
comment|/* integer-valued float */
operator|:
literal|"f"
operator|(
name|x
operator|)
block|)
function|;
end_function

begin_expr_stmt
operator|*
name|ip
operator|=
name|temp
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|x
operator|-
name|temp
return|;
end_return

unit|}
end_unit

