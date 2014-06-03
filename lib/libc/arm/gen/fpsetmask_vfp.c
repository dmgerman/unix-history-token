begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__weak_alias
end_ifdef

begin_macro
name|__weak_alias
argument_list|(
argument|fpsetmask
argument_list|,
argument|_fpsetmask
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FP_X_MASK
value|(FP_X_INV | FP_X_DZ | FP_X_OFL | FP_X_UFL | FP_X_IMP)
end_define

begin_function
name|fp_except_t
name|fpsetmask
parameter_list|(
name|fp_except_t
name|mask
parameter_list|)
block|{
name|fp_except
name|old
decl_stmt|,
name|new
decl_stmt|;
asm|__asm __volatile("vmrs %0, fpscr" : "=&r"(old));
name|mask
operator|=
operator|(
name|mask
operator|&
name|FP_X_MASK
operator|)
operator|<<
literal|8
expr_stmt|;
name|new
operator|=
operator|(
name|old
operator|&
operator|~
operator|(
name|FP_X_MASK
operator|<<
literal|8
operator|)
operator|)
operator||
name|mask
expr_stmt|;
asm|__asm __volatile("vmsr fpscr, %0" : : "r"(new));
return|return
operator|(
operator|(
name|old
operator|>>
literal|8
operator|)
operator|&
name|FP_X_MASK
operator|)
return|;
block|}
end_function

end_unit

