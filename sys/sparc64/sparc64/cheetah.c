begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_pmap.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/cache.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_comment
comment|/*  * Enable level 1 caches.  */
end_comment

begin_function
name|void
name|cheetah_cache_enable
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Flush all lines from the level 1 caches.  */
end_comment

begin_function
name|void
name|cheetah_cache_flush
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Flush a physical page from the data cache.  */
end_comment

begin_function
name|void
name|cheetah_dcache_page_inval
parameter_list|(
name|vm_paddr_t
name|spa
parameter_list|)
block|{
name|vm_paddr_t
name|pa
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|KASSERT
argument_list|(
operator|(
name|spa
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"dcache_page_inval: pa not page aligned"
operator|)
argument_list|)
expr_stmt|;
name|cookie
operator|=
name|ipi_dcache_page_inval
argument_list|(
name|tl_ipi_cheetah_dcache_page_inval
argument_list|,
name|spa
argument_list|)
expr_stmt|;
for|for
control|(
name|pa
operator|=
name|spa
init|;
name|pa
operator|<
name|spa
operator|+
name|PAGE_SIZE
condition|;
name|pa
operator|+=
name|cache
operator|.
name|dc_linesize
control|)
name|stxa_sync
argument_list|(
name|pa
argument_list|,
name|ASI_DCACHE_INVALIDATE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ipi_wait
argument_list|(
name|cookie
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Flush a physical page from the intsruction cache.  Instruction cache  * consistency is maintained by hardware.  */
end_comment

begin_function
name|void
name|cheetah_icache_page_inval
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|cheetah_tlb_flush_user
parameter_list|(
name|void
parameter_list|)
block|{
name|panic
argument_list|(
literal|"cheetah_tlb_flush_user"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

