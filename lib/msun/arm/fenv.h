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
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__fenv_static
end_ifndef

begin_define
define|#
directive|define
name|__fenv_static
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint32_t
name|fenv_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
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
value|0x0001
end_define

begin_define
define|#
directive|define
name|FE_DIVBYZERO
value|0x0002
end_define

begin_define
define|#
directive|define
name|FE_OVERFLOW
value|0x0004
end_define

begin_define
define|#
directive|define
name|FE_UNDERFLOW
value|0x0008
end_define

begin_define
define|#
directive|define
name|FE_INEXACT
value|0x0010
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_PCS_VFP
end_ifdef

begin_define
define|#
directive|define
name|FE_DENORMAL
value|0x0080
end_define

begin_define
define|#
directive|define
name|FE_ALL_EXCEPT
value|(FE_DIVBYZERO | FE_INEXACT | \ 			 FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW | FE_DENORMAL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FE_ALL_EXCEPT
value|(FE_DIVBYZERO | FE_INEXACT | \ 			 FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Rounding modes */
end_comment

begin_define
define|#
directive|define
name|VFP_FE_TONEAREST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|VFP_FE_UPWARD
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VFP_FE_DOWNWARD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VFP_FE_TOWARDZERO
value|0x00c00000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_PCS_VFP
end_ifdef

begin_define
define|#
directive|define
name|FE_TONEAREST
value|VFP_FE_TONEAREST
end_define

begin_define
define|#
directive|define
name|FE_UPWARD
value|VFP_FE_UPWARD
end_define

begin_define
define|#
directive|define
name|FE_DOWNWARD
value|VFP_FE_DOWNWARD
end_define

begin_define
define|#
directive|define
name|FE_TOWARDZERO
value|VFP_FE_TOWARDZERO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FE_TONEAREST
value|0x0000
end_define

begin_define
define|#
directive|define
name|FE_TOWARDZERO
value|0x0001
end_define

begin_define
define|#
directive|define
name|FE_UPWARD
value|0x0002
end_define

begin_define
define|#
directive|define
name|FE_DOWNWARD
value|0x0003
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ROUND_MASK
value|(FE_TONEAREST | FE_DOWNWARD | \ 			 FE_UPWARD | FE_TOWARDZERO)
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

begin_comment
comment|/* We need to be able to map status flag positions to mask flag positions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_PCS_VFP
end_ifndef

begin_define
define|#
directive|define
name|_FPUSW_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|_ENABLE_MASK
value|(FE_ALL_EXCEPT<< _FPUSW_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_PCS_VFP
end_ifndef

begin_function_decl
name|int
name|feclearexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|fetestexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fegetround
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fesetround
parameter_list|(
name|int
name|__round
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|fesetenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|fegetexcept
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_PCS_VFP */
end_comment

begin_define
define|#
directive|define
name|vmrs_fpscr
parameter_list|(
name|__r
parameter_list|)
value|__asm __volatile("vmrs %0, fpscr" : "=&r"(__r))
end_define

begin_define
define|#
directive|define
name|vmsr_fpscr
parameter_list|(
name|__r
parameter_list|)
value|__asm __volatile("vmsr fpscr, %0" : : "r"(__r))
end_define

begin_define
define|#
directive|define
name|_FPU_MASK_SHIFT
value|8
end_define

begin_function
name|__fenv_static
specifier|inline
name|int
name|feclearexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
block|{
name|fexcept_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
name|__fpsr
operator|&=
operator|~
name|__excepts
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__fpsr
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
name|__fenv_static
specifier|inline
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
name|fexcept_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
operator|*
name|__flagp
operator|=
name|__fpsr
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

begin_function
name|__fenv_static
specifier|inline
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
block|{
name|fexcept_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
name|__fpsr
operator|&=
operator|~
name|__excepts
expr_stmt|;
name|__fpsr
operator||=
operator|*
name|__flagp
operator|&
name|__excepts
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__fpsr
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
name|__fenv_static
specifier|inline
name|int
name|feraiseexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
block|{
name|fexcept_t
name|__ex
init|=
name|__excepts
decl_stmt|;
name|fesetexceptflag
argument_list|(
operator|&
name|__ex
argument_list|,
name|__excepts
argument_list|)
expr_stmt|;
comment|/* XXX */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|__fenv_static
specifier|inline
name|int
name|fetestexcept
parameter_list|(
name|int
name|__excepts
parameter_list|)
block|{
name|fexcept_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
return|return
operator|(
name|__fpsr
operator|&
name|__excepts
operator|)
return|;
block|}
end_function

begin_function
name|__fenv_static
specifier|inline
name|int
name|fegetround
parameter_list|(
name|void
parameter_list|)
block|{
name|fenv_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
return|return
operator|(
name|__fpsr
operator|&
name|_ROUND_MASK
operator|)
return|;
block|}
end_function

begin_function
name|__fenv_static
specifier|inline
name|int
name|fesetround
parameter_list|(
name|int
name|__round
parameter_list|)
block|{
name|fenv_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
name|__fpsr
operator|&=
operator|~
operator|(
name|_ROUND_MASK
operator|)
expr_stmt|;
name|__fpsr
operator||=
name|__round
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__fpsr
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
name|__fenv_static
specifier|inline
name|int
name|fegetenv
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
block|{
name|vmrs_fpscr
argument_list|(
operator|*
name|__envp
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
name|__fenv_static
specifier|inline
name|int
name|feholdexcept
parameter_list|(
name|fenv_t
modifier|*
name|__envp
parameter_list|)
block|{
name|fenv_t
name|__env
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__env
argument_list|)
expr_stmt|;
operator|*
name|__envp
operator|=
name|__env
expr_stmt|;
name|__env
operator|&=
operator|~
operator|(
name|FE_ALL_EXCEPT
operator|)
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__env
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
name|__fenv_static
specifier|inline
name|int
name|fesetenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
block|{
name|vmsr_fpscr
argument_list|(
operator|*
name|__envp
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
name|__fenv_static
specifier|inline
name|int
name|feupdateenv
parameter_list|(
specifier|const
name|fenv_t
modifier|*
name|__envp
parameter_list|)
block|{
name|fexcept_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
name|vmsr_fpscr
argument_list|(
operator|*
name|__envp
argument_list|)
expr_stmt|;
name|feraiseexcept
argument_list|(
name|__fpsr
operator|&
name|FE_ALL_EXCEPT
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/* We currently provide no external definitions of the functions below. */
end_comment

begin_function
name|__fenv_static
specifier|inline
name|int
name|feenableexcept
parameter_list|(
name|int
name|__mask
parameter_list|)
block|{
name|fenv_t
name|__old_fpsr
decl_stmt|,
name|__new_fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__old_fpsr
argument_list|)
expr_stmt|;
name|__new_fpsr
operator|=
name|__old_fpsr
operator||
operator|(
operator|(
name|__mask
operator|&
name|FE_ALL_EXCEPT
operator|)
operator|<<
name|_FPU_MASK_SHIFT
operator|)
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__new_fpsr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|__old_fpsr
operator|>>
name|_FPU_MASK_SHIFT
operator|)
operator|&
name|FE_ALL_EXCEPT
operator|)
return|;
block|}
end_function

begin_function
name|__fenv_static
specifier|inline
name|int
name|fedisableexcept
parameter_list|(
name|int
name|__mask
parameter_list|)
block|{
name|fenv_t
name|__old_fpsr
decl_stmt|,
name|__new_fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__old_fpsr
argument_list|)
expr_stmt|;
name|__new_fpsr
operator|=
name|__old_fpsr
operator|&
operator|~
operator|(
operator|(
name|__mask
operator|&
name|FE_ALL_EXCEPT
operator|)
operator|<<
name|_FPU_MASK_SHIFT
operator|)
expr_stmt|;
name|vmsr_fpscr
argument_list|(
name|__new_fpsr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|__old_fpsr
operator|>>
name|_FPU_MASK_SHIFT
operator|)
operator|&
name|FE_ALL_EXCEPT
operator|)
return|;
block|}
end_function

begin_function
name|__fenv_static
specifier|inline
name|int
name|fegetexcept
parameter_list|(
name|void
parameter_list|)
block|{
name|fenv_t
name|__fpsr
decl_stmt|;
name|vmrs_fpscr
argument_list|(
name|__fpsr
argument_list|)
expr_stmt|;
return|return
operator|(
name|__fpsr
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARM_PCS_VFP */
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

