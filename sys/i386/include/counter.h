begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Konstantin Belousov<kib@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHINE_COUNTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__MACHINE_COUNTER_H__
end_define

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_define
define|#
directive|define
name|counter_enter
parameter_list|()
value|do {				\ 	if ((cpu_feature& CPUID_CX8) == 0)		\ 		critical_enter();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|counter_exit
parameter_list|()
value|do {				\ 	if ((cpu_feature& CPUID_CX8) == 0)		\ 		critical_exit();			\ } while (0)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|counter_64_inc_8b
parameter_list|(
name|uint64_t
modifier|*
name|p
parameter_list|,
name|int64_t
name|inc
parameter_list|)
block|{
asm|__asm __volatile(
literal|"movl	%%fs:(%%esi),%%eax\n\t"
literal|"movl	%%fs:4(%%esi),%%edx\n"
literal|"1:\n\t"
literal|"movl	%%eax,%%ebx\n\t"
literal|"movl	%%edx,%%ecx\n\t"
literal|"addl	(%%edi),%%ebx\n\t"
literal|"adcl	4(%%edi),%%ecx\n\t"
literal|"cmpxchg8b %%fs:(%%esi)\n\t"
literal|"jnz	1b"
operator|:
operator|:
literal|"S"
operator|(
name|p
operator|)
operator|,
literal|"D"
operator|(
operator|&
name|inc
operator|)
operator|:
literal|"memory"
operator|,
literal|"cc"
operator|,
literal|"eax"
operator|,
literal|"edx"
operator|,
literal|"ebx"
operator|,
literal|"ecx"
block|)
function|;
end_function

begin_define
unit|}
define|#
directive|define
name|counter_u64_add_protected
parameter_list|(
name|c
parameter_list|,
name|inc
parameter_list|)
value|do {	\ 	if ((cpu_feature& CPUID_CX8) == 0) {		\ 		CRITICAL_ASSERT(curthread);		\ 		*(uint64_t *)zpcpu_get(c) += (inc);	\ 	} else						\ 		counter_64_inc_8b((c), (inc));		\ } while (0)
end_define

begin_function
unit|static
specifier|inline
name|void
name|counter_u64_add
parameter_list|(
name|counter_u64_t
name|c
parameter_list|,
name|int64_t
name|inc
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CX8
operator|)
operator|==
literal|0
condition|)
block|{
name|critical_enter
argument_list|()
expr_stmt|;
operator|*
operator|(
name|uint64_t
operator|*
operator|)
name|zpcpu_get
argument_list|(
name|c
argument_list|)
operator|+=
name|inc
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|counter_64_inc_8b
argument_list|(
name|c
argument_list|,
name|inc
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __MACHINE_COUNTER_H__ */
end_comment

end_unit

