begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Andrew Moore, Talke Studio  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#) floatingpoint.h	1.0 (Berkeley) 9/23/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FLOATINGPOINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FLOATINGPOINT_H_
end_define

begin_comment
comment|/*  * IEEE floating point structure and function definitions  */
end_comment

begin_comment
comment|/*-  * XXX the following undocumented pollution is exported:  *	fpsetsticky().  *	FP*FLD, FP*OFF and FP*REG from<machine/ieeefp.h>  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ieeefp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__fldenv
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fldenv %0" : : "m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnstenv
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstenv %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnstcw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstcw %0" : "=m" (*(addr)))
end_define

begin_define
define|#
directive|define
name|__fnstsw
parameter_list|(
name|addr
parameter_list|)
value|__asm __volatile("fnstsw %0" : "=m" (*(addr)))
end_define

begin_comment
comment|/*  * return the contents of a FP register  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__fpgetreg
parameter_list|(
name|int
name|_reg
parameter_list|)
block|{
name|unsigned
name|short
name|_mem
decl_stmt|;
comment|/*- 	 * This is more efficient than it looks.  The switch gets optimized 	 * away if _reg is constant. 	 * 	 * The default case only supports _reg == 0.  We could handle more 	 * registers (e.g., tags) using fnstenv, but the interface doesn't 	 * support more. 	 */
switch|switch
condition|(
name|_reg
condition|)
block|{
default|default:
name|__fnstcw
argument_list|(
operator|&
name|_mem
argument_list|)
expr_stmt|;
break|break;
case|case
name|FP_STKY_REG
case|:
name|__fnstsw
argument_list|(
operator|&
name|_mem
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|_mem
return|;
block|}
end_function

begin_comment
comment|/*  * set a FP mode; return previous mode  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__fpsetreg
parameter_list|(
name|int
name|_m
parameter_list|,
name|int
name|_reg
parameter_list|,
name|int
name|_fld
parameter_list|,
name|int
name|_off
parameter_list|)
block|{
name|unsigned
name|_env
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|_p
decl_stmt|;
comment|/* 	 * _reg == 0 could be handled better using fnstcw/fldcw. 	 */
name|__fnstenv
argument_list|(
name|_env
argument_list|)
expr_stmt|;
name|_p
operator|=
operator|(
name|_env
index|[
name|_reg
index|]
operator|&
name|_fld
operator|)
operator|>>
name|_off
expr_stmt|;
name|_env
index|[
name|_reg
index|]
operator|=
operator|(
name|_env
index|[
name|_reg
index|]
operator|&
operator|~
name|_fld
operator|)
operator||
operator|(
name|_m
operator|<<
name|_off
operator|&
name|_fld
operator|)
expr_stmt|;
name|__fldenv
argument_list|(
name|_env
argument_list|)
expr_stmt|;
return|return
name|_p
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/*  * SysV/386 FP control interface  */
end_comment

begin_define
define|#
directive|define
name|fpgetround
parameter_list|()
value|((fp_rnd_t) ((__fpgetreg(FP_RND_REG)& FP_RND_FLD)>> FP_RND_OFF))
end_define

begin_define
define|#
directive|define
name|fpsetround
parameter_list|(
name|m
parameter_list|)
value|((fp_rnd_t) __fpsetreg((m), FP_RND_REG, FP_RND_FLD, FP_RND_OFF))
end_define

begin_define
define|#
directive|define
name|fpgetprec
parameter_list|()
value|((fp_prec_t) ((__fpgetreg(FP_PRC_REG)& FP_PRC_FLD)>> FP_PRC_OFF))
end_define

begin_define
define|#
directive|define
name|fpsetprec
parameter_list|(
name|m
parameter_list|)
value|((fp_prec_t) __fpsetreg((m), FP_PRC_REG, FP_PRC_FLD, FP_PRC_OFF))
end_define

begin_define
define|#
directive|define
name|fpgetmask
parameter_list|()
value|((fp_except_t) ((~__fpgetreg(FP_MSKS_REG)& FP_MSKS_FLD)>> FP_MSKS_OFF))
end_define

begin_define
define|#
directive|define
name|fpsetmask
parameter_list|(
name|m
parameter_list|)
value|((fp_except_t) (__fpsetreg(~(m), FP_MSKS_REG, FP_MSKS_FLD, FP_MSKS_OFF)))
end_define

begin_define
define|#
directive|define
name|fpgetsticky
parameter_list|()
value|((fp_except_t) ((__fpgetreg(FP_STKY_REG)& FP_STKY_FLD)>> FP_STKY_OFF))
end_define

begin_define
define|#
directive|define
name|fpresetsticky
parameter_list|(
name|m
parameter_list|)
value|((fp_except_t) __fpsetreg(0, FP_STKY_REG, (m), FP_STKY_OFF))
end_define

begin_define
define|#
directive|define
name|fpsetsticky
parameter_list|(
name|m
parameter_list|)
value|fpresetsticky(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FLOATINGPOINT_H_ */
end_comment

end_unit

