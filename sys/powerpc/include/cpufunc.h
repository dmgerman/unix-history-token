begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUFUNC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bogus interrupt manipulation  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|disable_intr
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|msr
decl_stmt|;
name|msr
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"mfmsr %0\n\t"
literal|"rlwinm %0, %0, 0, 17, 15\n\t"
literal|"mtmsr %0"
operator|:
literal|"+r"
operator|(
name|msr
operator|)
block|)
function|;
end_function

begin_return
return|return;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|enable_intr
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|msr
decl_stmt|;
name|msr
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"mfmsr %0\n\t"
literal|"ori %0, %0, 0x8000\n\t"
literal|"mtmsr %0"
operator|:
literal|"+r"
operator|(
name|msr
operator|)
block|)
function|;
end_function

begin_return
return|return;
end_return

begin_function
unit|}  static
name|__inline
name|u_int
name|save_intr
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|msr
decl_stmt|;
asm|__asm __volatile("mfmsr %0" : "=r" (msr));
return|return
name|msr
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|critical_t
name|critical_enter
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|critical_t
operator|)
name|save_intr
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|restore_intr
parameter_list|(
name|u_int
name|msr
parameter_list|)
block|{
asm|__asm __volatile("mtmsr %0" : : "r" (msr));
return|return;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|critical_exit
parameter_list|(
name|critical_t
name|msr
parameter_list|)
block|{
return|return
operator|(
name|restore_intr
argument_list|(
operator|(
name|u_int
operator|)
name|msr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|powerpc_mb
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("eieio;" : : : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|powerpc_get_globalp
parameter_list|(
name|void
parameter_list|)
block|{
name|void
modifier|*
name|ret
decl_stmt|;
asm|__asm __volatile("mfsprg %0, 0" : "=r" (ret));
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

