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

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

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
comment|/* CPU register mangling inlines */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mtmsr
parameter_list|(
name|register_t
name|value
parameter_list|)
block|{
asm|__asm __volatile ("mtmsr %0" :: "r"(value));
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|mfmsr
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|value
decl_stmt|;
asm|__asm __volatile ("mfmsr %0" : "=r"(value));
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mtdec
parameter_list|(
name|register_t
name|value
parameter_list|)
block|{
asm|__asm __volatile ("mtdec %0" :: "r"(value));
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|mfdec
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|value
decl_stmt|;
asm|__asm __volatile ("mfdec %0" : "=r"(value));
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|isync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("isync");
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|intr_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|msr
decl_stmt|;
name|msr
operator|=
name|mfmsr
argument_list|()
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
operator|&
operator|~
operator|(
name|PSL_EE
operator||
name|PSL_RI
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|msr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|intr_restore
parameter_list|(
name|register_t
name|msr
parameter_list|)
block|{
name|mtmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|restore_intr
parameter_list|(
name|unsigned
name|int
name|msr
parameter_list|)
block|{
name|mtmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
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
asm|__asm __volatile("eieio; sync" : : : "memory");
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|pcpu
operator|*
name|powerpc_get_pcpup
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|pcpu
operator|*
name|ret
block|;
asm|__asm ("mfsprg %0, 0" : "=r"(ret));
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|cpu_critical_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_critical_fork_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_thread_link
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

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

