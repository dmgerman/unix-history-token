begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2005 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FENV_H_
end_ifndef

begin_define
define|#
directive|define
name|_FENV_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
block|{
name|__uint32_t
name|__control
decl_stmt|;
name|__uint32_t
name|__status
decl_stmt|;
name|__uint32_t
name|__tag
decl_stmt|;
name|char
name|__other
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__x87
struct|;
name|__uint32_t
name|__mxcsr
decl_stmt|;
block|}
name|fenv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|fexcept_t
typedef|;
end_typedef

begin_comment
comment|/* Exception flags */
end_comment

begin_define
define|#
directive|define
name|FE_INVALID
value|0x01
end_define

begin_define
define|#
directive|define
name|FE_DENORMAL
value|0x02
end_define

begin_define
define|#
directive|define
name|FE_DIVBYZERO
value|0x04
end_define

begin_define
define|#
directive|define
name|FE_OVERFLOW
value|0x08
end_define

begin_define
define|#
directive|define
name|FE_UNDERFLOW
value|0x10
end_define

begin_define
define|#
directive|define
name|FE_INEXACT
value|0x20
end_define

begin_define
define|#
directive|define
name|FE_ALL_EXCEPT
value|(FE_DIVBYZERO | FE_DENORMAL | FE_INEXACT | \ 			 FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)
end_define

begin_comment
comment|/* Rounding modes */
end_comment

begin_define
define|#
directive|define
name|FE_TONEAREST
value|0x0000
end_define

begin_define
define|#
directive|define
name|FE_DOWNWARD
value|0x0400
end_define

begin_define
define|#
directive|define
name|FE_UPWARD
value|0x0800
end_define

begin_define
define|#
directive|define
name|FE_TOWARDZERO
value|0x0c00
end_define

begin_define
define|#
directive|define
name|_ROUND_MASK
value|(FE_TONEAREST | FE_DOWNWARD | \ 			 FE_UPWARD | FE_TOWARDZERO)
end_define

begin_comment
comment|/*  * As compared to the x87 control word, the SSE unit's control word  * has the rounding control bits offset by 3 and the exception mask  * bits offset by 7.  */
end_comment

begin_define
define|#
directive|define
name|_SSE_ROUND_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|_SSE_EMASK_SHIFT
value|7
end_define

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* Default floating-point environment */
specifier|extern
specifier|const
name|fenv_t
name|__fe_dfl_env
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FE_DFL_ENV
value|(&__fe_dfl_env)
end_define

begin_define
define|#
directive|define
name|__fldcw
parameter_list|(
name|__cw
parameter_list|)
value|__asm __volatile("fldcw %0" : : "m" (__cw))
end_define

begin_define
define|#
directive|define
name|__fldenv
parameter_list|(
name|__env
parameter_list|)
value|__asm __volatile("fldenv %0" : : "m" (__env))
end_define

begin_define
define|#
directive|define
name|__fldenvx
parameter_list|(
name|__env
parameter_list|)
value|__asm __volatile("fldenv %0" : : "m" (__env)  \ 				: "st", "st(1)", "st(2)", "st(3)", "st(4)",   \ 				"st(5)", "st(6)", "st(7)")
end_define

begin_define
define|#
directive|define
name|__fnclex
parameter_list|()
value|__asm __volatile("fnclex")
end_define

begin_define
define|#
directive|define
name|__fnstenv
parameter_list|(
name|__env
parameter_list|)
value|__asm __volatile("fnstenv %0" : "=m" (*(__env)))
end_define

begin_define
define|#
directive|define
name|__fnstcw
parameter_list|(
name|__cw
parameter_list|)
value|__asm __volatile("fnstcw %0" : "=m" (*(__cw)))
end_define

begin_define
define|#
directive|define
name|__fnstsw
parameter_list|(
name|__sw
parameter_list|)
value|__asm __volatile("fnstsw %0" : "=am" (*(__sw)))
end_define

begin_define
define|#
directive|define
name|__fwait
parameter_list|()
value|__asm __volatile("fwait")
end_define

begin_define
define|#
directive|define
name|__ldmxcsr
parameter_list|(
name|__csr
parameter_list|)
value|__asm __volatile("ldmxcsr %0" : : "m" (__csr))
end_define

begin_define
define|#
directive|define
name|__stmxcsr
parameter_list|(
name|__csr
parameter_list|)
value|__asm __volatile("stmxcsr %0" : "=m" (*(__csr)))
end_define

begin_function
specifier|static
name|__inline
name|int
name|feclearexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
block|{
name|fenv_t
name|__env
decl_stmt|;
if|if
condition|(
name|__excepts
operator|==
name|FE_ALL_EXCEPT
condition|)
block|{
name|__fnclex
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|__fnstenv
argument_list|(
operator|&
name|__env
operator|.
name|__x87
argument_list|)
expr_stmt|;
name|__env
operator|.
name|__x87
operator|.
name|__status
operator|&=
operator|~
name|__excepts
expr_stmt|;
name|__fldenv
argument_list|(
name|__env
operator|.
name|__x87
argument_list|)
expr_stmt|;
block|}
name|__stmxcsr
argument_list|(
operator|&
name|__env
operator|.
name|__mxcsr
argument_list|)
expr_stmt|;
name|__env
operator|.
name|__mxcsr
operator|&=
operator|~
name|__excepts
expr_stmt|;
name|__ldmxcsr
argument_list|(
name|__env
operator|.
name|__mxcsr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fegetexceptflag
parameter_list|(
name|fexcept_t
modifier|*
name|__flagp
parameter_list|,
name|int
name|__excepts
parameter_list|)
block|{
name|int
name|__mxcsr
decl_stmt|,
name|__status
decl_stmt|;
name|__stmxcsr
argument_list|(
operator|&
name|__mxcsr
argument_list|)
expr_stmt|;
name|__fnstsw
argument_list|(
operator|&
name|__status
argument_list|)
expr_stmt|;
operator|*
name|__flagp
operator|=
operator|(
name|__mxcsr
operator||
name|__status
operator|)
operator|&
name|__excepts
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|fesetexceptflag
parameter_list|(
specifier|const
name|fexcept_t
modifier|*
name|__flagp
parameter_list|,
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feraiseexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|fetestexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
block|{
name|int
name|__mxcsr
decl_stmt|,
name|__status
decl_stmt|;
name|__stmxcsr
argument_list|(
operator|&
name|__mxcsr
argument_list|)
expr_stmt|;
name|__fnstsw
argument_list|(
operator|&
name|__status
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|__status
operator||
name|__mxcsr
operator|)
operator|&
name|__excepts
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fegetround
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|__control
decl_stmt|;
comment|/* 	 * We assume that the x87 and the SSE unit agree on the 	 * rounding mode.  Reading the control word on the x87 turns 	 * out to be about 5 times faster than reading it on the SSE 	 * unit on an Opteron 244. 	 */
name|__fnstcw
argument_list|(
operator|&
name|__control
argument_list|)
expr_stmt|;
return|return
operator|(
name|__control
operator|&
name|_ROUND_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|fesetround
parameter_list|(
name|int
name|__round
parameter_list|)
block|{
name|int
name|__mxcsr
decl_stmt|,
name|__control
decl_stmt|;
if|if
condition|(
name|__round
operator|&
operator|~
name|_ROUND_MASK
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|__fnstcw
argument_list|(
operator|&
name|__control
argument_list|)
expr_stmt|;
name|__control
operator|&=
operator|~
name|_ROUND_MASK
expr_stmt|;
name|__control
operator||=
name|__round
expr_stmt|;
name|__fldcw
argument_list|(
name|__control
argument_list|)
expr_stmt|;
name|__stmxcsr
argument_list|(
operator|&
name|__mxcsr
argument_list|)
expr_stmt|;
name|__mxcsr
operator|&=
operator|~
operator|(
name|_ROUND_MASK
operator|<<
name|_SSE_ROUND_SHIFT
operator|)
expr_stmt|;
name|__mxcsr
operator||=
name|__round
operator|<<
name|_SSE_ROUND_SHIFT
expr_stmt|;
name|__ldmxcsr
argument_list|(
name|__mxcsr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|fegetenv
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feholdexcept
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|fesetenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
block|{
comment|/* 	 * XXX Using fldenvx() instead of fldenv() tells the compiler that this 	 * instruction clobbers the i387 register stack.  This happens because 	 * we restore the tag word from the saved environment.  Normally, this 	 * would happen anyway and we wouldn't care, because the ABI allows 	 * function calls to clobber the i387 regs.  However, fesetenv() is 	 * inlined, so we need to be more careful. 	 */
name|__fldenvx
argument_list|(
name|__envp
operator|->
name|__x87
argument_list|)
expr_stmt|;
name|__ldmxcsr
argument_list|(
name|__envp
operator|->
name|__mxcsr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|feupdateenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|feenableexcept
parameter_list|(
name|int
name|__mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fedisableexcept
parameter_list|(
name|int
name|__mask
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|int
name|fegetexcept
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|__control
decl_stmt|;
comment|/* 	 * We assume that the masks for the x87 and the SSE unit are 	 * the same. 	 */
name|__fnstcw
argument_list|(
operator|&
name|__control
argument_list|)
expr_stmt|;
return|return
operator|(
operator|~
name|__control
operator|&
name|FE_ALL_EXCEPT
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FENV_H_ */
end_comment

end_unit

