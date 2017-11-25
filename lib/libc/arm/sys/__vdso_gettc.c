begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2015 The FreeBSD Foundation  *  * This software was developed by Konstantin Belousov  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/elf.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/vdso.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/acle-compat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cp15_cntvct_get
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|reg
decl_stmt|;
asm|__asm __volatile("mrrc\tp15, 1, %Q0, %R0, c14" : "=r" (reg));
return|return
operator|(
name|reg
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|cp15_cntpct_get
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|reg
decl_stmt|;
asm|__asm __volatile("mrrc\tp15, 0, %Q0, %R0, c14" : "=r" (reg));
return|return
operator|(
name|reg
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|weak
name|__vdso_gettc
end_pragma

begin_function
name|int
name|__vdso_gettc
parameter_list|(
specifier|const
name|struct
name|vdso_timehands
modifier|*
name|th
parameter_list|,
name|u_int
modifier|*
name|tc
parameter_list|)
block|{
if|if
condition|(
name|th
operator|->
name|th_algo
operator|!=
name|VDSO_TH_ALGO_ARM_GENTIM
condition|)
return|return
operator|(
name|ENOSYS
operator|)
return|;
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
comment|/* 	 * Userspace gettimeofday() is only enabled on ARMv7 CPUs, but 	 * libc is compiled for ARMv6.  Due to clang issues, .arch 	 * armv7-a directive does not work. 	 */
asm|__asm __volatile(".word\t0xf57ff06f" : : : "memory");
comment|/* isb */
operator|*
name|tc
operator|=
name|th
operator|->
name|th_physical
operator|==
literal|0
condition|?
name|cp15_cntvct_get
argument_list|()
else|:
name|cp15_cntpct_get
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
operator|*
name|tc
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|ENOSYS
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|__vdso_gettimekeep
end_pragma

begin_function
name|int
name|__vdso_gettimekeep
parameter_list|(
name|struct
name|vdso_timekeep
modifier|*
modifier|*
name|tk
parameter_list|)
block|{
return|return
operator|(
name|_elf_aux_info
argument_list|(
name|AT_TIMEKEEP
argument_list|,
name|tk
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|tk
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

