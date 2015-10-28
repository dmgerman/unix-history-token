begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Konstantin Belousov<kib@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|lfence_works
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|get_lfence_usage
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|cpuid_supported
decl_stmt|,
name|p
index|[
literal|4
index|]
decl_stmt|;
if|if
condition|(
name|lfence_works
operator|==
operator|-
literal|1
condition|)
block|{
asm|__asm __volatile(
literal|"	pushfl\n"
literal|"	popl	%%eax\n"
literal|"	movl    %%eax,%%ecx\n"
literal|"	xorl    $0x200000,%%eax\n"
literal|"	pushl	%%eax\n"
literal|"	popfl\n"
literal|"	pushfl\n"
literal|"	popl    %%eax\n"
literal|"	xorl    %%eax,%%ecx\n"
literal|"	je	1f\n"
literal|"	movl	$1,%0\n"
literal|"	jmp	2f\n"
literal|"1:	movl	$0,%0\n"
literal|"2:\n"
operator|:
literal|"=r"
operator|(
name|cpuid_supported
operator|)
operator|:
operator|:
literal|"eax"
operator|,
literal|"ecx"
block|)
empty_stmt|;
if|if
condition|(
name|cpuid_supported
condition|)
block|{
asm|__asm __volatile(
literal|"	pushl	%%ebx\n"
literal|"	cpuid\n"
literal|"	movl	%%ebx,%1\n"
literal|"	popl	%%ebx\n"
operator|:
literal|"=a"
operator|(
name|p
index|[
literal|0
index|]
operator|)
operator|,
literal|"=r"
operator|(
name|p
index|[
literal|1
index|]
operator|)
operator|,
literal|"=c"
operator|(
name|p
index|[
literal|2
index|]
operator|)
operator|,
literal|"=d"
operator|(
name|p
index|[
literal|3
index|]
operator|)
operator|:
literal|"0"
operator|(
literal|0x1
operator|)
block|)
empty_stmt|;
name|lfence_works
operator|=
operator|(
name|p
index|[
literal|3
index|]
operator|&
name|CPUID_SSE2
operator|)
operator|!=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|else
name|lfence_works
operator|=
literal|0
expr_stmt|;
end_else

begin_expr_stmt
unit|} 	return
operator|(
name|lfence_works
operator|)
expr_stmt|;
end_expr_stmt

begin_function
unit|}  static
name|u_int
name|__vdso_gettc_low
parameter_list|(
specifier|const
name|struct
name|vdso_timehands
modifier|*
name|th
parameter_list|)
block|{
name|u_int
name|rv
decl_stmt|;
if|if
condition|(
name|get_lfence_usage
argument_list|()
operator|==
literal|1
condition|)
name|lfence
argument_list|()
expr_stmt|;
asm|__asm __volatile("rdtsc; shrd %%cl, %%edx, %0"
block|:
literal|"=a"
operator|(
name|rv
operator|)
operator|:
literal|"c"
operator|(
name|th
operator|->
name|th_x86_shift
operator|)
operator|:
literal|"edx"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|rv
operator|)
return|;
end_return

begin_function
unit|}  static
name|u_int
name|__vdso_rdtsc32
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|rv
decl_stmt|;
if|if
condition|(
name|get_lfence_usage
argument_list|()
operator|==
literal|1
condition|)
name|lfence
argument_list|()
expr_stmt|;
name|rv
operator|=
name|rdtsc32
argument_list|()
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|__vdso_gettc
end_pragma

begin_function
name|u_int
name|__vdso_gettc
parameter_list|(
specifier|const
name|struct
name|vdso_timehands
modifier|*
name|th
parameter_list|)
block|{
return|return
operator|(
name|th
operator|->
name|th_x86_shift
operator|>
literal|0
condition|?
name|__vdso_gettc_low
argument_list|(
name|th
argument_list|)
else|:
name|__vdso_rdtsc32
argument_list|()
operator|)
return|;
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

