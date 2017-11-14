begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|"cache.h"
end_include

begin_function
specifier|static
name|unsigned
name|int
name|get_dcache_line_size
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|ctr
decl_stmt|;
name|unsigned
name|int
name|dcl_size
decl_stmt|;
comment|/* Accessible from all security levels */
name|ctr
operator|=
name|READ_SPECIALREG
argument_list|(
name|ctr_el0
argument_list|)
expr_stmt|;
comment|/* 	 * Relevant field [19:16] is LOG2 	 * of the number of words in DCache line 	 */
name|dcl_size
operator|=
name|CTR_DLINE_SIZE
argument_list|(
name|ctr
argument_list|)
expr_stmt|;
comment|/* Size of word shifted by cache line size */
return|return
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|<<
name|dcl_size
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cpu_flush_dcache
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|uint64_t
name|cl_size
decl_stmt|;
name|vm_offset_t
name|addr
decl_stmt|,
name|end
decl_stmt|;
name|cl_size
operator|=
name|get_dcache_line_size
argument_list|()
expr_stmt|;
comment|/* Calculate end address to clean */
name|end
operator|=
operator|(
name|vm_offset_t
operator|)
name|ptr
operator|+
operator|(
name|vm_offset_t
operator|)
name|len
expr_stmt|;
comment|/* Align start address to cache line */
name|addr
operator|=
operator|(
name|vm_offset_t
operator|)
name|ptr
expr_stmt|;
name|addr
operator|=
name|rounddown2
argument_list|(
name|addr
argument_list|,
name|cl_size
argument_list|)
expr_stmt|;
for|for
control|(
init|;
name|addr
operator|<
name|end
condition|;
name|addr
operator|+=
name|cl_size
control|)
asm|__asm __volatile("dc	civac, %0" : : "r" (addr) : "memory");
comment|/* Full system DSB */
asm|__asm __volatile("dsb	sy" : : : "memory");
block|}
end_function

begin_function
name|void
name|cpu_inval_icache
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
comment|/* NULL ptr or 0 len means all */
if|if
condition|(
name|ptr
operator|==
name|NULL
operator|||
name|len
operator|==
literal|0
condition|)
block|{
asm|__asm __volatile(
literal|"ic		ialluis	\n"
literal|"dsb	ish	\n"
operator|:
operator|:
operator|:
literal|"memory"
block|)
empty_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* TODO: Other cache ranges if necessary */
end_comment

unit|}
end_unit

