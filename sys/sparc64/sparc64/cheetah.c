begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * Copyright (c) 2005, 2008 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/systm.h>
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
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/dcr.h>
end_include

begin_include
include|#
directive|include
file|<machine/lsu.h>
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

begin_include
include|#
directive|include
file|<machine/ver.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_comment
comment|/* A FLUSH is required after changing LSU_IC (the address is ignored). */
end_comment

begin_define
define|#
directive|define
name|CHEETAH_FLUSH_LSU_IC
parameter_list|()
value|__asm __volatile("flush %%g0" : :)
end_define

begin_define
define|#
directive|define
name|CHEETAH_ICACHE_TAG_LOWER
value|0x30
end_define

begin_comment
comment|/*  * CPU-specific initialization  */
end_comment

begin_function
name|void
name|cheetah_init
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|s
decl_stmt|;
comment|/* 	 * Disable interrupts for safety, this shouldn't be actually 	 * necessary though. 	 */
name|s
operator|=
name|intr_disable
argument_list|()
expr_stmt|;
comment|/* 	 * Ensure DCR_IFPOE is disabled as long as we haven't implemented 	 * support for it (if ever) as most if not all firmware versions 	 * apparently turn it on.  Not making use of DCR_IFPOE should also 	 * avoid Cheetah erratum #109. 	 */
name|wr
argument_list|(
name|asr18
argument_list|,
name|rd
argument_list|(
name|asr18
argument_list|)
operator|&
operator|~
name|DCR_IFPOE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Ensure the TSB Extension Registers hold 0 as TSB_Base. */
name|stxa
argument_list|(
name|AA_DMMU_TSB_PEXT_REG
argument_list|,
name|ASI_DMMU
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
name|AA_IMMU_TSB_PEXT_REG
argument_list|,
name|ASI_IMMU
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|membar
argument_list|(
name|Sync
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
name|AA_DMMU_TSB_SEXT_REG
argument_list|,
name|ASI_DMMU
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* 	 * NB: the secondary context was removed from the iMMU. 	 */
name|membar
argument_list|(
name|Sync
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
name|AA_DMMU_TSB_NEXT_REG
argument_list|,
name|ASI_DMMU
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
name|AA_IMMU_TSB_NEXT_REG
argument_list|,
name|ASI_IMMU
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|membar
argument_list|(
name|Sync
argument_list|)
expr_stmt|;
name|intr_restore
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Enable level 1 caches.  */
end_comment

begin_function
name|void
name|cheetah_cache_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|u_long
name|lsu
decl_stmt|;
name|lsu
operator|=
name|ldxa
argument_list|(
literal|0
argument_list|,
name|ASI_LSU_CTL_REG
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_impl
operator|==
name|CPU_IMPL_ULTRASPARCIII
condition|)
block|{
comment|/* Disable P$ due to Cheetah erratum #18. */
name|lsu
operator|&=
operator|~
name|LSU_PE
expr_stmt|;
block|}
name|stxa
argument_list|(
literal|0
argument_list|,
name|ASI_LSU_CTL_REG
argument_list|,
name|lsu
operator||
name|LSU_IC
operator||
name|LSU_DC
argument_list|)
expr_stmt|;
name|CHEETAH_FLUSH_LSU_IC
argument_list|()
expr_stmt|;
block|}
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
block|{
name|u_long
name|addr
decl_stmt|,
name|lsu
decl_stmt|;
for|for
control|(
name|addr
operator|=
literal|0
init|;
name|addr
operator|<
name|PCPU_GET
argument_list|(
name|cache
operator|.
name|dc_size
argument_list|)
condition|;
name|addr
operator|+=
name|PCPU_GET
argument_list|(
name|cache
operator|.
name|dc_linesize
argument_list|)
control|)
name|stxa_sync
argument_list|(
name|addr
argument_list|,
name|ASI_DCACHE_TAG
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* The I$ must be disabled when flushing it so ensure it's off. */
name|lsu
operator|=
name|ldxa
argument_list|(
literal|0
argument_list|,
name|ASI_LSU_CTL_REG
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
literal|0
argument_list|,
name|ASI_LSU_CTL_REG
argument_list|,
name|lsu
operator|&
operator|~
operator|(
name|LSU_IC
operator|)
argument_list|)
expr_stmt|;
name|CHEETAH_FLUSH_LSU_IC
argument_list|()
expr_stmt|;
for|for
control|(
name|addr
operator|=
name|CHEETAH_ICACHE_TAG_LOWER
init|;
name|addr
operator|<
name|PCPU_GET
argument_list|(
name|cache
operator|.
name|ic_size
argument_list|)
operator|*
literal|2
condition|;
name|addr
operator|+=
name|PCPU_GET
argument_list|(
name|cache
operator|.
name|ic_linesize
argument_list|)
operator|*
literal|2
control|)
name|stxa_sync
argument_list|(
name|addr
argument_list|,
name|ASI_ICACHE_TAG
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|stxa
argument_list|(
literal|0
argument_list|,
name|ASI_LSU_CTL_REG
argument_list|,
name|lsu
argument_list|)
expr_stmt|;
name|CHEETAH_FLUSH_LSU_IC
argument_list|()
expr_stmt|;
block|}
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
literal|"%s: pa not page aligned"
operator|,
name|__func__
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
name|PCPU_GET
argument_list|(
name|cache
operator|.
name|dc_linesize
argument_list|)
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
block|{  }
end_function

begin_define
define|#
directive|define
name|cheetah_dmap_all
parameter_list|()
value|do {						\ 	stxa(TLB_DEMAP_ALL, ASI_DMMU_DEMAP, 0);				\ 	stxa(TLB_DEMAP_ALL, ASI_IMMU_DEMAP, 0);				\ 	flush(KERNBASE);						\ } while (0)
end_define

begin_comment
comment|/*  * Flush all non-locked mappings from the TLB.  */
end_comment

begin_function
name|void
name|cheetah_tlb_flush_nonlocked
parameter_list|(
name|void
parameter_list|)
block|{
name|cheetah_dmap_all
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Flush all user mappings from the TLB.  */
end_comment

begin_function
name|void
name|cheetah_tlb_flush_user
parameter_list|()
block|{
comment|/* 	 * Just use cheetah_dmap_all() and accept somes TLB misses 	 * rather than searching all 1040 D-TLB and 144 I-TLB slots 	 * for non-kernel mappings. 	 */
name|cheetah_dmap_all
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

