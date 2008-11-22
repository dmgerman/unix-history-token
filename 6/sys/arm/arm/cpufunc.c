begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpufunc.c,v 1.65 2003/11/05 12:53:15 scw Exp $	*/
end_comment

begin_comment
comment|/*-  * arm7tdmi support code Copyright (c) 2001 John Fremlin  * arm8 support code Copyright (c) 1997 ARM Limited  * arm8 support code Copyright (c) 1997 Causality Limited  * arm9 support code Copyright (C) 2001 ARM Ltd  * Copyright (c) 1997 Mark Brinicombe.  * Copyright (c) 1997 Causality Limited  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Causality Limited.  * 4. The name of Causality Limited may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY CAUSALITY LIMITED ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL CAUSALITY LIMITED BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * cpufuncs.c  *  * C functions for supporting CPU / MMU / TLB specific operations.  *  * Created      : 30/01/97  */
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/disassem.h>
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
file|<machine/cpuconf.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bootconfig.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_80200
end_ifdef

begin_include
include|#
directive|include
file|<arm/xscale/i80200/i80200reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80200/i80200var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_80321
end_ifdef

begin_include
include|#
directive|include
file|<arm/xscale/i80321/i80321reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/i80321var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_IXP425
end_ifdef

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
end_if

begin_include
include|#
directive|include
file|<arm/xscale/xscalereg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERFCTRS
argument_list|)
end_if

begin_decl_stmt
name|struct
name|arm_pmc_funcs
modifier|*
name|arm_pmc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRIMARY CACHE VARIABLES */
end_comment

begin_decl_stmt
name|int
name|arm_picache_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_picache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_picache_ways
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_pdcache_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and unified */
end_comment

begin_decl_stmt
name|int
name|arm_pdcache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_pdcache_ways
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_pcache_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_pcache_unified
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_dcache_align
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|arm_dcache_align_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 == use cpu_sleep(), 0 == don't */
end_comment

begin_decl_stmt
name|int
name|cpu_do_powersave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctrl
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM7TDMI
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|arm7tdmi_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|arm7tdmi_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|arm7tdmi_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|arm7tdmi_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|arm7tdmi_tlb_flushID
block|,
comment|/* tlb_flushI		*/
name|arm7tdmi_tlb_flushID_SE
block|,
comment|/* tlb_flushI_SE	*/
name|arm7tdmi_tlb_flushID
block|,
comment|/* tlb_flushD		*/
name|arm7tdmi_tlb_flushID_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|cpufunc_nullop
block|,
comment|/* icache_sync_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* icache_sync_range	*/
name|arm7tdmi_cache_flushID
block|,
comment|/* dcache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|arm7tdmi_cache_flushID
block|,
comment|/* dcache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|arm7tdmi_cache_flushID
block|,
comment|/* dcache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* dcache_wb_range	*/
name|arm7tdmi_cache_flushID
block|,
comment|/* idcache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|arm7tdmi_cache_flushID
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|cpufunc_nullop
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|late_abort_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|arm7tdmi_context_switch
block|,
comment|/* context_switch	*/
name|arm7tdmi_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM7TDMI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM8
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|arm8_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|arm8_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|arm8_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|arm8_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|arm8_tlb_flushID
block|,
comment|/* tlb_flushI		*/
name|arm8_tlb_flushID_SE
block|,
comment|/* tlb_flushI_SE	*/
name|arm8_tlb_flushID
block|,
comment|/* tlb_flushD		*/
name|arm8_tlb_flushID_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|cpufunc_nullop
block|,
comment|/* icache_sync_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* icache_sync_range	*/
name|arm8_cache_purgeID
block|,
comment|/* dcache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|arm8_cache_purgeID
block|,
comment|/* dcache_wbinv_range	*/
comment|/*XXX*/
operator|(
name|void
operator|*
operator|)
name|arm8_cache_purgeID
block|,
comment|/* dcache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|arm8_cache_cleanID
block|,
comment|/* dcache_wb_range	*/
name|arm8_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|arm8_cache_purgeID
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|cpufunc_nullop
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|arm8_context_switch
block|,
comment|/* context_switch	*/
name|arm8_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM8 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM9
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|arm9_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* Domain		*/
name|arm9_setttb
block|,
comment|/* Setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|arm9_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
operator|(
name|void
operator|*
operator|)
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|arm9_icache_sync_all
block|,
comment|/* icache_sync_all	*/
name|arm9_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|arm9_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|arm9_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
comment|/*XXX*/
name|arm9_dcache_wbinv_range
block|,
comment|/* dcache_inv_range	*/
name|arm9_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|arm9_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|arm9_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|arm9_context_switch
block|,
comment|/* context_switch	*/
name|arm9_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM9 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM10
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|arm10_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* Domain		*/
name|arm10_setttb
block|,
comment|/* Setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|arm10_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
name|arm10_tlb_flushI_SE
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|arm10_icache_sync_all
block|,
comment|/* icache_sync_all	*/
name|arm10_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|arm10_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|arm10_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
name|arm10_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|arm10_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|arm10_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|arm10_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|arm10_context_switch
block|,
comment|/* context_switch	*/
name|arm10_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM10 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SA110
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|sa110_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|sa1_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|sa1_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
operator|(
name|void
operator|*
operator|)
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|sa1_cache_syncI
block|,
comment|/* icache_sync_all	*/
name|sa1_cache_syncI_rng
block|,
comment|/* icache_sync_range	*/
name|sa1_cache_purgeD
block|,
comment|/* dcache_wbinv_all	*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_wbinv_range	*/
comment|/*XXX*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_inv_range	*/
name|sa1_cache_cleanD_rng
block|,
comment|/* dcache_wb_range	*/
name|sa1_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|sa1_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|sa110_context_switch
block|,
comment|/* context_switch	*/
name|sa110_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SA110 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_SA1100
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1110
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|sa11x0_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|sa1_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|sa1_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
operator|(
name|void
operator|*
operator|)
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|sa1_cache_syncI
block|,
comment|/* icache_sync_all	*/
name|sa1_cache_syncI_rng
block|,
comment|/* icache_sync_range	*/
name|sa1_cache_purgeD
block|,
comment|/* dcache_wbinv_all	*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_wbinv_range	*/
comment|/*XXX*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_inv_range	*/
name|sa1_cache_cleanD_rng
block|,
comment|/* dcache_wb_range	*/
name|sa1_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|sa1_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|sa11x0_drain_readbuf
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
name|sa11x0_cpu_sleep
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|sa11x0_context_switch
block|,
comment|/* context_switch	*/
name|sa11x0_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SA1100 || CPU_SA1110 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_IXP12X0
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|ixp12x0_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|cpufunc_nullop
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|sa1_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|sa1_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
operator|(
name|void
operator|*
operator|)
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|sa1_cache_syncI
block|,
comment|/* icache_sync_all	*/
name|sa1_cache_syncI_rng
block|,
comment|/* icache_sync_range	*/
name|sa1_cache_purgeD
block|,
comment|/* dcache_wbinv_all	*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_wbinv_range	*/
comment|/*XXX*/
name|sa1_cache_purgeD_rng
block|,
comment|/* dcache_inv_range	*/
name|sa1_cache_cleanD_rng
block|,
comment|/* dcache_wb_range	*/
name|sa1_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|sa1_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|ixp12x0_drain_readbuf
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|ixp12x0_context_switch
block|,
comment|/* context_switch	*/
name|ixp12x0_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_IXP12X0 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|xscale_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|xscale_cpwait
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|xscale_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* domain		*/
name|xscale_setttb
block|,
comment|/* setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* faultaddress		*/
comment|/* TLB functions */
name|armv4_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|xscale_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
operator|(
name|void
operator|*
operator|)
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|xscale_cache_syncI
block|,
comment|/* icache_sync_all	*/
name|xscale_cache_syncI_rng
block|,
comment|/* icache_sync_range	*/
name|xscale_cache_purgeD
block|,
comment|/* dcache_wbinv_all	*/
name|xscale_cache_purgeD_rng
block|,
comment|/* dcache_wbinv_range	*/
name|xscale_cache_flushD_rng
block|,
comment|/* dcache_inv_range	*/
name|xscale_cache_cleanD_rng
block|,
comment|/* dcache_wb_range	*/
name|xscale_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|xscale_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E	*/
name|xscale_cpu_sleep
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|xscale_context_switch
block|,
comment|/* context_switch	*/
name|xscale_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80200 || CPU_XSCALE_80321 || CPU_XSCALE_PXA2X0 || CPU_XSCALE_IXP425 */
end_comment

begin_comment
comment|/*  * Global constants also used by locore.s  */
end_comment

begin_decl_stmt
name|struct
name|cpu_functions
name|cpufuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|cputype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|cpu_reset_needs_v4_MMU_disable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag used in locore.s */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM7TDMI
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM8
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
end_if

begin_function_decl
specifier|static
name|void
name|get_cachetype_cp15
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Additional cache information local to this file.  Log2 of some of the    above numbers.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|arm_dcache_l2_nsets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|arm_dcache_l2_assoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|arm_dcache_l2_linesize
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|get_cachetype_cp15
parameter_list|()
block|{
name|u_int
name|ctype
decl_stmt|,
name|isize
decl_stmt|,
name|dsize
decl_stmt|;
name|u_int
name|multiplier
decl_stmt|;
asm|__asm __volatile("mrc p15, 0, %0, c0, c0, 1"
block|:
literal|"=r"
operator|(
name|ctype
operator|)
block|)
function|;
end_function

begin_comment
comment|/* 	 * ...and thus spake the ARM ARM: 	 * 	 * If an<opcode2> value corresponding to an unimplemented or 	 * reserved ID register is encountered, the System Control 	 * processor returns the value of the main ID register. 	 */
end_comment

begin_if
if|if
condition|(
name|ctype
operator|==
name|cpufunc_id
argument_list|()
condition|)
goto|goto
name|out
goto|;
end_if

begin_if
if|if
condition|(
operator|(
name|ctype
operator|&
name|CPU_CT_S
operator|)
operator|==
literal|0
condition|)
name|arm_pcache_unified
operator|=
literal|1
expr_stmt|;
end_if

begin_comment
comment|/* 	 * If you want to know how this code works, go read the ARM ARM. 	 */
end_comment

begin_expr_stmt
name|arm_pcache_type
operator|=
name|CPU_CT_CTYPE
argument_list|(
name|ctype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|arm_pcache_unified
operator|==
literal|0
condition|)
block|{
name|isize
operator|=
name|CPU_CT_ISIZE
argument_list|(
name|ctype
argument_list|)
expr_stmt|;
name|multiplier
operator|=
operator|(
name|isize
operator|&
name|CPU_CT_xSIZE_M
operator|)
condition|?
literal|3
else|:
literal|2
expr_stmt|;
name|arm_picache_line_size
operator|=
literal|1U
operator|<<
operator|(
name|CPU_CT_xSIZE_LEN
argument_list|(
name|isize
argument_list|)
operator|+
literal|3
operator|)
expr_stmt|;
if|if
condition|(
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|isize
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|isize
operator|&
name|CPU_CT_xSIZE_M
condition|)
name|arm_picache_line_size
operator|=
literal|0
expr_stmt|;
comment|/* not present */
else|else
name|arm_picache_ways
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|arm_picache_ways
operator|=
name|multiplier
operator|<<
operator|(
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|isize
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
block|}
name|arm_picache_size
operator|=
name|multiplier
operator|<<
operator|(
name|CPU_CT_xSIZE_SIZE
argument_list|(
name|isize
argument_list|)
operator|+
literal|8
operator|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|dsize
operator|=
name|CPU_CT_DSIZE
argument_list|(
name|ctype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|multiplier
operator|=
operator|(
name|dsize
operator|&
name|CPU_CT_xSIZE_M
operator|)
condition|?
literal|3
else|:
literal|2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_pdcache_line_size
operator|=
literal|1U
operator|<<
operator|(
name|CPU_CT_xSIZE_LEN
argument_list|(
name|dsize
argument_list|)
operator|+
literal|3
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|dsize
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|dsize
operator|&
name|CPU_CT_xSIZE_M
condition|)
name|arm_pdcache_line_size
operator|=
literal|0
expr_stmt|;
comment|/* not present */
else|else
name|arm_pdcache_ways
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|arm_pdcache_ways
operator|=
name|multiplier
operator|<<
operator|(
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|dsize
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|arm_pdcache_size
operator|=
name|multiplier
operator|<<
operator|(
name|CPU_CT_xSIZE_SIZE
argument_list|(
name|dsize
argument_list|)
operator|+
literal|8
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_align
operator|=
name|arm_pdcache_line_size
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_l2_assoc
operator|=
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|dsize
argument_list|)
operator|+
name|multiplier
operator|-
literal|2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_l2_linesize
operator|=
name|CPU_CT_xSIZE_LEN
argument_list|(
name|dsize
argument_list|)
operator|+
literal|3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_l2_nsets
operator|=
literal|6
operator|+
name|CPU_CT_xSIZE_SIZE
argument_list|(
name|dsize
argument_list|)
operator|-
name|CPU_CT_xSIZE_ASSOC
argument_list|(
name|dsize
argument_list|)
operator|-
name|CPU_CT_xSIZE_LEN
argument_list|(
name|dsize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|out
label|:
end_label

begin_expr_stmt
name|arm_dcache_align_mask
operator|=
name|arm_dcache_align
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM7TDMI || ARM8 || ARM9 || XSCALE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_SA110
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1100
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1110
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_IXP12X0
argument_list|)
end_if

begin_comment
comment|/* Cache information for CPUs without cache type registers. */
end_comment

begin_macro
unit|struct
name|cachetab
end_macro

begin_block
block|{
name|u_int32_t
name|ct_cpuid
decl_stmt|;
name|int
name|ct_pcache_type
decl_stmt|;
name|int
name|ct_pcache_unified
decl_stmt|;
name|int
name|ct_pdcache_size
decl_stmt|;
name|int
name|ct_pdcache_line_size
decl_stmt|;
name|int
name|ct_pdcache_ways
decl_stmt|;
name|int
name|ct_picache_size
decl_stmt|;
name|int
name|ct_picache_line_size
decl_stmt|;
name|int
name|ct_picache_ways
decl_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|cachetab
name|cachetab
index|[]
init|=
block|{
comment|/* cpuid,           cache type,       u,  dsiz, ls, wy,  isiz, ls, wy */
comment|/* XXX is this type right for SA-1? */
block|{
name|CPU_ID_SA110
block|,
name|CPU_CT_CTYPE_WB1
block|,
literal|0
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|}
block|,
block|{
name|CPU_ID_SA1100
block|,
name|CPU_CT_CTYPE_WB1
block|,
literal|0
block|,
literal|8192
block|,
literal|32
block|,
literal|32
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|}
block|,
block|{
name|CPU_ID_SA1110
block|,
name|CPU_CT_CTYPE_WB1
block|,
literal|0
block|,
literal|8192
block|,
literal|32
block|,
literal|32
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|}
block|,
block|{
name|CPU_ID_IXP1200
block|,
name|CPU_CT_CTYPE_WB1
block|,
literal|0
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|,
literal|16384
block|,
literal|32
block|,
literal|32
block|}
block|,
comment|/* XXX */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|get_cachetype_table
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|get_cachetype_table
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|u_int32_t
name|cpuid
init|=
name|cpufunc_id
argument_list|()
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_cpuid
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_cpuid
operator|==
operator|(
name|cpuid
operator|&
name|CPU_ID_CPU_MASK
operator|)
condition|)
block|{
name|arm_pcache_type
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_pcache_type
expr_stmt|;
name|arm_pcache_unified
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_pcache_unified
expr_stmt|;
name|arm_pdcache_size
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_pdcache_size
expr_stmt|;
name|arm_pdcache_line_size
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_pdcache_line_size
expr_stmt|;
name|arm_pdcache_ways
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_pdcache_ways
expr_stmt|;
name|arm_picache_size
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_picache_size
expr_stmt|;
name|arm_picache_line_size
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_picache_line_size
expr_stmt|;
name|arm_picache_ways
operator|=
name|cachetab
index|[
name|i
index|]
operator|.
name|ct_picache_ways
expr_stmt|;
block|}
block|}
name|arm_dcache_align
operator|=
name|arm_pdcache_line_size
expr_stmt|;
name|arm_dcache_align_mask
operator|=
name|arm_dcache_align
operator|-
literal|1
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA110 || SA1100 || SA1111 || IXP12X0 */
end_comment

begin_comment
comment|/*  * Cannot panic here as we may not have a console yet ...  */
end_comment

begin_function
name|int
name|set_cpufuncs
parameter_list|()
block|{
name|cputype
operator|=
name|cpufunc_id
argument_list|()
expr_stmt|;
name|cputype
operator|&=
name|CPU_ID_CPU_MASK
expr_stmt|;
comment|/* 	 * NOTE: cpu_do_powersave defaults to off.  If we encounter a 	 * CPU type where we want to use it by default, then we set it. 	 */
ifdef|#
directive|ifdef
name|CPU_ARM7TDMI
if|if
condition|(
operator|(
name|cputype
operator|&
name|CPU_ID_IMPLEMENTOR_MASK
operator|)
operator|==
name|CPU_ID_ARM_LTD
operator|&&
name|CPU_ID_IS7
argument_list|(
name|cputype
argument_list|)
operator|&&
operator|(
name|cputype
operator|&
name|CPU_ID_7ARCH_MASK
operator|)
operator|==
name|CPU_ID_7ARCH_V4T
condition|)
block|{
name|cpufuncs
operator|=
name|arm7tdmi_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|0
expr_stmt|;
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CPU_ARM8
if|if
condition|(
operator|(
name|cputype
operator|&
name|CPU_ID_IMPLEMENTOR_MASK
operator|)
operator|==
name|CPU_ID_ARM_LTD
operator|&&
operator|(
name|cputype
operator|&
literal|0x0000f000
operator|)
operator|==
literal|0x00008000
condition|)
block|{
name|cpufuncs
operator|=
name|arm8_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|0
expr_stmt|;
comment|/* XXX correct? */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_arm8
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM8 */
ifdef|#
directive|ifdef
name|CPU_ARM9
if|if
condition|(
operator|(
operator|(
name|cputype
operator|&
name|CPU_ID_IMPLEMENTOR_MASK
operator|)
operator|==
name|CPU_ID_ARM_LTD
operator|||
operator|(
name|cputype
operator|&
name|CPU_ID_IMPLEMENTOR_MASK
operator|)
operator|==
name|CPU_ID_TI
operator|)
operator|&&
operator|(
name|cputype
operator|&
literal|0x0000f000
operator|)
operator|==
literal|0x00009000
condition|)
block|{
name|cpufuncs
operator|=
name|arm9_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* V4 or higher */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|arm9_dcache_sets_inc
operator|=
literal|1U
operator|<<
name|arm_dcache_l2_linesize
expr_stmt|;
name|arm9_dcache_sets_max
operator|=
operator|(
literal|1U
operator|<<
operator|(
name|arm_dcache_l2_linesize
operator|+
name|arm_dcache_l2_nsets
operator|)
operator|)
operator|-
name|arm9_dcache_sets_inc
expr_stmt|;
name|arm9_dcache_index_inc
operator|=
literal|1U
operator|<<
operator|(
literal|32
operator|-
name|arm_dcache_l2_assoc
operator|)
expr_stmt|;
name|arm9_dcache_index_max
operator|=
literal|0U
operator|-
name|arm9_dcache_index_inc
expr_stmt|;
ifdef|#
directive|ifdef
name|ARM9_CACHE_WRITE_THROUGH
name|pmap_pte_init_arm9
argument_list|()
expr_stmt|;
else|#
directive|else
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM9 */
ifdef|#
directive|ifdef
name|CPU_ARM10
if|if
condition|(
comment|/* cputype == CPU_ID_ARM1020T || */
name|cputype
operator|==
name|CPU_ID_ARM1020E
condition|)
block|{
comment|/* 		 * Select write-through cacheing (this isn't really an 		 * option on ARM1020T). 		 */
name|cpufuncs
operator|=
name|arm10_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* V4 or higher */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|arm10_dcache_sets_inc
operator|=
literal|1U
operator|<<
name|arm_dcache_l2_linesize
expr_stmt|;
name|arm10_dcache_sets_max
operator|=
operator|(
literal|1U
operator|<<
operator|(
name|arm_dcache_l2_linesize
operator|+
name|arm_dcache_l2_nsets
operator|)
operator|)
operator|-
name|arm10_dcache_sets_inc
expr_stmt|;
name|arm10_dcache_index_inc
operator|=
literal|1U
operator|<<
operator|(
literal|32
operator|-
name|arm_dcache_l2_assoc
operator|)
expr_stmt|;
name|arm10_dcache_index_max
operator|=
literal|0U
operator|-
name|arm10_dcache_index_inc
expr_stmt|;
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM10 */
ifdef|#
directive|ifdef
name|CPU_SA110
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_SA110
condition|)
block|{
name|cpufuncs
operator|=
name|sa110_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* SA needs it */
name|get_cachetype_table
argument_list|()
expr_stmt|;
name|pmap_pte_init_sa1
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_SA110 */
ifdef|#
directive|ifdef
name|CPU_SA1100
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_SA1100
condition|)
block|{
name|cpufuncs
operator|=
name|sa11x0_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* SA needs it	*/
name|get_cachetype_table
argument_list|()
expr_stmt|;
name|pmap_pte_init_sa1
argument_list|()
expr_stmt|;
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_SA1100 */
ifdef|#
directive|ifdef
name|CPU_SA1110
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_SA1110
condition|)
block|{
name|cpufuncs
operator|=
name|sa11x0_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* SA needs it	*/
name|get_cachetype_table
argument_list|()
expr_stmt|;
name|pmap_pte_init_sa1
argument_list|()
expr_stmt|;
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_SA1110 */
ifdef|#
directive|ifdef
name|CPU_IXP12X0
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_IXP1200
condition|)
block|{
name|cpufuncs
operator|=
name|ixp12x0_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
name|get_cachetype_table
argument_list|()
expr_stmt|;
name|pmap_pte_init_sa1
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/* CPU_IXP12X0 */
ifdef|#
directive|ifdef
name|CPU_XSCALE_80200
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_80200
condition|)
block|{
name|int
name|rev
init|=
name|cpufunc_id
argument_list|()
operator|&
name|CPU_ID_REVISION_MASK
decl_stmt|;
name|i80200_icu_init
argument_list|()
expr_stmt|;
comment|/* 		 * Reset the Performance Monitoring Unit to a 		 * pristine state: 		 *	- CCNT, PMN0, PMN1 reset to 0 		 *	- overflow indications cleared 		 *	- all counters disabled 		 */
asm|__asm __volatile("mcr p14, 0, %0, c0, c0, 0"
block|: 			:
literal|"r"
operator|(
name|PMNC_P
operator||
name|PMNC_C
operator||
name|PMNC_PMN0_IF
operator||
name|PMNC_PMN1_IF
operator||
name|PMNC_CC_IF
operator|)
block|)
empty_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|XSCALE_CCLKCFG
argument_list|)
comment|/* 		 * Crank CCLKCFG to maximum legal value. 		 */
asm|__asm __volatile ("mcr p14, 0, %0, c6, c0, 0"
block|: 			:
literal|"r"
operator|(
name|XSCALE_CCLKCFG
operator|)
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 		 * XXX Disable ECC in the Bus Controller Unit; we 		 * don't really support it, yet.  Clear any pending 		 * error indications. 		 */
end_comment

begin_asm
asm|__asm __volatile("mcr p13, 0, %0, c0, c1, 0"
end_asm

begin_expr_stmt
unit|: 			:
literal|"r"
operator|(
name|BCUCTL_E0
operator||
name|BCUCTL_E1
operator||
name|BCUCTL_EV
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERFCTRS
argument_list|)
end_if

begin_expr_stmt
name|xscale_pmu_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 		 * i80200 errata: Step-A0 and A1 have a bug where 		 * D$ dirty bits are not cleared on "invalidate by 		 * address". 		 * 		 * Workaround: Clean cache line before invalidating. 		 */
end_comment

begin_if
if|if
condition|(
name|rev
operator|==
literal|0
operator|||
name|rev
operator|==
literal|1
condition|)
name|cpufuncs
operator|.
name|cf_dcache_inv_range
operator|=
name|xscale_cache_purgeD_rng
expr_stmt|;
end_if

begin_expr_stmt
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XScale needs it */
end_comment

begin_expr_stmt
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pmap_pte_init_xscale
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80200 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_80321
end_ifdef

begin_expr_stmt
unit|if
operator|(
name|cputype
operator|==
name|CPU_ID_80321_400
operator|||
name|cputype
operator|==
name|CPU_ID_80321_600
operator|||
name|cputype
operator|==
name|CPU_ID_80321_400_B0
operator|||
name|cputype
operator|==
name|CPU_ID_80321_600_B0
operator|)
block|{
comment|/* 		 * Reset the Performance Monitoring Unit to a 		 * pristine state: 		 *	- CCNT, PMN0, PMN1 reset to 0 		 *	- overflow indications cleared 		 *	- all counters disabled 		 */
asm|__asm __volatile("mcr p14, 0, %0, c0, c0, 0"
operator|:
operator|:
literal|"r"
operator|(
name|PMNC_P
operator||
name|PMNC_C
operator||
name|PMNC_PMN0_IF
operator||
name|PMNC_PMN1_IF
operator||
name|PMNC_CC_IF
operator|)
block|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERFCTRS
argument_list|)
end_if

begin_expr_stmt
name|xscale_pmu_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XScale needs it */
end_comment

begin_expr_stmt
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pmap_pte_init_xscale
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80321 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_PXA2X0
end_ifdef

begin_comment
comment|/* ignore core revision to test PXA2xx CPUs */
end_comment

begin_expr_stmt
unit|if
operator|(
operator|(
name|cputype
operator|&
operator|~
name|CPU_ID_XSCALE_COREREV_MASK
operator|)
operator|==
name|CPU_ID_PXA250
operator|||
operator|(
name|cputype
operator|&
operator|~
name|CPU_ID_XSCALE_COREREV_MASK
operator|)
operator|==
name|CPU_ID_PXA210
operator|)
block|{
name|cpufuncs
operator|=
name|xscale_cpufuncs
block|;
if|#
directive|if
name|defined
argument_list|(
name|PERFCTRS
argument_list|)
name|xscale_pmu_init
argument_list|()
block|;
endif|#
directive|endif
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
block|;
comment|/* XScale needs it */
name|get_cachetype_cp15
argument_list|()
block|;
name|pmap_pte_init_xscale
argument_list|()
block|;
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
block|;
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_PXA2X0 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_IXP425
end_ifdef

begin_if
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_IXP425_533
operator|||
name|cputype
operator|==
name|CPU_ID_IXP425_400
operator|||
name|cputype
operator|==
name|CPU_ID_IXP425_266
condition|)
block|{
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|PERFCTRS
argument_list|)
name|xscale_pmu_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* XScale needs it */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_xscale
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_IXP425 */
end_comment

begin_comment
comment|/* 	 * Bzzzz. And the answer was ... 	 */
end_comment

begin_expr_stmt
name|panic
argument_list|(
literal|"No support for this CPU type (%08x) in kernel"
argument_list|,
name|cputype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|ARCHITECTURE_NOT_PRESENT
operator|)
return|;
end_return

begin_comment
unit|}
comment|/*  * Fixup routines for data and prefetch aborts.  *  * Several compile time symbols are used  *  * DEBUG_FAULT_CORRECTION - Print debugging information during the  * correction of registers after a fault.  * ARM6_LATE_ABORT - ARM6 supports both early and late aborts  * when defined should use late aborts  */
end_comment

begin_comment
comment|/*  * Null abort fixup routine.  * For use when no fixup is required.  */
end_comment

begin_macro
unit|int
name|cpufunc_null_fixup
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ABORT_FIXUP_OK
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM7TDMI
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_FAULT_CORRECTION
end_ifdef

begin_define
define|#
directive|define
name|DFC_PRINTF
parameter_list|(
name|x
parameter_list|)
value|printf x
end_define

begin_define
define|#
directive|define
name|DFC_DISASSEMBLE
parameter_list|(
name|x
parameter_list|)
value|disassemble(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DFC_PRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|DFC_DISASSEMBLE
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * "Early" data abort fixup.  *  * For ARM2, ARM2as, ARM3 and ARM6 (in early-abort mode).  Also used  * indirectly by ARM6 (in late-abort mode) and ARM7[TDMI].  *  * In early aborts, we may have to fix up LDM, STM, LDC and STC.  */
end_comment

begin_function
name|int
name|early_abort_fixup
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|trapframe_t
modifier|*
name|frame
init|=
name|arg
decl_stmt|;
name|u_int
name|fault_pc
decl_stmt|;
name|u_int
name|fault_instruction
decl_stmt|;
name|int
name|saved_lr
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
block|{
comment|/* Ok an abort in SVC mode */
comment|/* 		 * Copy the SVC r14 into the usr r14 - The usr r14 is garbage 		 * as the fault happened in svc mode but we need it in the 		 * usr slot so we can treat the registers as an array of ints 		 * during fixing. 		 * NOTE: This PC is in the position but writeback is not 		 * allowed on r15. 		 * Doing it like this is more efficient than trapping this 		 * case in all possible locations in the following fixup code. 		 */
name|saved_lr
operator|=
name|frame
operator|->
name|tf_usr_lr
expr_stmt|;
name|frame
operator|->
name|tf_usr_lr
operator|=
name|frame
operator|->
name|tf_svc_lr
expr_stmt|;
comment|/* 		 * Note the trapframe does not have the SVC r13 so a fault 		 * from an instruction with writeback to r13 in SVC mode is 		 * not allowed. This should not happen as the kstack is 		 * always valid. 		 */
block|}
comment|/* Get fault address and status from the CPU */
name|fault_pc
operator|=
name|frame
operator|->
name|tf_pc
expr_stmt|;
name|fault_instruction
operator|=
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|int
operator|*
operator|)
name|fault_pc
operator|)
expr_stmt|;
comment|/* Decode the fault instruction and fix the registers as needed */
if|if
condition|(
operator|(
name|fault_instruction
operator|&
literal|0x0e000000
operator|)
operator|==
literal|0x08000000
condition|)
block|{
name|int
name|base
decl_stmt|;
name|int
name|loop
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
modifier|*
name|registers
init|=
operator|&
name|frame
operator|->
name|tf_r0
decl_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"LDM/STM\n"
operator|)
argument_list|)
expr_stmt|;
name|DFC_DISASSEMBLE
argument_list|(
name|fault_pc
argument_list|)
expr_stmt|;
if|if
condition|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|21
operator|)
condition|)
block|{
name|DFC_PRINTF
argument_list|(
operator|(
literal|"This instruction must be corrected\n"
operator|)
argument_list|)
expr_stmt|;
name|base
operator|=
operator|(
name|fault_instruction
operator|>>
literal|16
operator|)
operator|&
literal|0x0f
expr_stmt|;
if|if
condition|(
name|base
operator|==
literal|15
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
comment|/* Count registers transferred */
name|count
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|loop
operator|=
literal|0
init|;
name|loop
operator|<
literal|16
condition|;
operator|++
name|loop
control|)
block|{
if|if
condition|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
name|loop
operator|)
condition|)
operator|++
name|count
expr_stmt|;
block|}
name|DFC_PRINTF
argument_list|(
operator|(
literal|"%d registers used\n"
operator|,
name|count
operator|)
argument_list|)
expr_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"Corrected r%d by %d bytes "
operator|,
name|base
operator|,
name|count
operator|*
literal|4
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|23
operator|)
condition|)
block|{
name|DFC_PRINTF
argument_list|(
operator|(
literal|"down\n"
operator|)
argument_list|)
expr_stmt|;
name|registers
index|[
name|base
index|]
operator|-=
name|count
operator|*
literal|4
expr_stmt|;
block|}
else|else
block|{
name|DFC_PRINTF
argument_list|(
operator|(
literal|"up\n"
operator|)
argument_list|)
expr_stmt|;
name|registers
index|[
name|base
index|]
operator|+=
name|count
operator|*
literal|4
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|fault_instruction
operator|&
literal|0x0e000000
operator|)
operator|==
literal|0x0c000000
condition|)
block|{
name|int
name|base
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
modifier|*
name|registers
init|=
operator|&
name|frame
operator|->
name|tf_r0
decl_stmt|;
comment|/* REGISTER CORRECTION IS REQUIRED FOR THESE INSTRUCTIONS */
name|DFC_DISASSEMBLE
argument_list|(
name|fault_pc
argument_list|)
expr_stmt|;
comment|/* Only need to fix registers if write back is turned on */
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|21
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|base
operator|=
operator|(
name|fault_instruction
operator|>>
literal|16
operator|)
operator|&
literal|0x0f
expr_stmt|;
if|if
condition|(
name|base
operator|==
literal|13
operator|&&
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
if|if
condition|(
name|base
operator|==
literal|15
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
name|offset
operator|=
operator|(
name|fault_instruction
operator|&
literal|0xff
operator|)
operator|<<
literal|2
expr_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"r%d=%08x\n"
operator|,
name|base
operator|,
name|registers
index|[
name|base
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|)
operator|!=
literal|0
condition|)
name|offset
operator|=
operator|-
name|offset
expr_stmt|;
name|registers
index|[
name|base
index|]
operator|+=
name|offset
expr_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"r%d=%08x\n"
operator|,
name|base
operator|,
name|registers
index|[
name|base
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|fault_instruction
operator|&
literal|0x0e000000
operator|)
operator|==
literal|0x0c000000
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
if|if
condition|(
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
block|{
comment|/* Ok an abort in SVC mode */
comment|/* 		 * Copy the SVC r14 into the usr r14 - The usr r14 is garbage 		 * as the fault happened in svc mode but we need it in the 		 * usr slot so we can treat the registers as an array of ints 		 * during fixing. 		 * NOTE: This PC is in the position but writeback is not 		 * allowed on r15. 		 * Doing it like this is more efficient than trapping this 		 * case in all possible locations in the prior fixup code. 		 */
name|frame
operator|->
name|tf_svc_lr
operator|=
name|frame
operator|->
name|tf_usr_lr
expr_stmt|;
name|frame
operator|->
name|tf_usr_lr
operator|=
name|saved_lr
expr_stmt|;
comment|/* 		 * Note the trapframe does not have the SVC r13 so a fault 		 * from an instruction with writeback to r13 in SVC mode is 		 * not allowed. This should not happen as the kstack is 		 * always valid. 		 */
block|}
return|return
operator|(
name|ABORT_FIXUP_OK
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM2/250/3/6/7 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM7TDMI
argument_list|)
end_if

begin_comment
comment|/*  * "Late" (base updated) data abort fixup  *  * For ARM6 (in late-abort mode) and ARM7.  *  * In this model, all data-transfer instructions need fixing up.  We defer  * LDM, STM, LDC and STC fixup to the early-abort handler.  */
end_comment

begin_function
name|int
name|late_abort_fixup
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|trapframe_t
modifier|*
name|frame
init|=
name|arg
decl_stmt|;
name|u_int
name|fault_pc
decl_stmt|;
name|u_int
name|fault_instruction
decl_stmt|;
name|int
name|saved_lr
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
block|{
comment|/* Ok an abort in SVC mode */
comment|/* 		 * Copy the SVC r14 into the usr r14 - The usr r14 is garbage 		 * as the fault happened in svc mode but we need it in the 		 * usr slot so we can treat the registers as an array of ints 		 * during fixing. 		 * NOTE: This PC is in the position but writeback is not 		 * allowed on r15. 		 * Doing it like this is more efficient than trapping this 		 * case in all possible locations in the following fixup code. 		 */
name|saved_lr
operator|=
name|frame
operator|->
name|tf_usr_lr
expr_stmt|;
name|frame
operator|->
name|tf_usr_lr
operator|=
name|frame
operator|->
name|tf_svc_lr
expr_stmt|;
comment|/* 		 * Note the trapframe does not have the SVC r13 so a fault 		 * from an instruction with writeback to r13 in SVC mode is 		 * not allowed. This should not happen as the kstack is 		 * always valid. 		 */
block|}
comment|/* Get fault address and status from the CPU */
name|fault_pc
operator|=
name|frame
operator|->
name|tf_pc
expr_stmt|;
name|fault_instruction
operator|=
operator|*
operator|(
operator|(
specifier|volatile
name|unsigned
name|int
operator|*
operator|)
name|fault_pc
operator|)
expr_stmt|;
comment|/* Decode the fault instruction and fix the registers as needed */
comment|/* Was is a swap instruction ? */
if|if
condition|(
operator|(
name|fault_instruction
operator|&
literal|0x0fb00ff0
operator|)
operator|==
literal|0x01000090
condition|)
block|{
name|DFC_DISASSEMBLE
argument_list|(
name|fault_pc
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|fault_instruction
operator|&
literal|0x0c000000
operator|)
operator|==
literal|0x04000000
condition|)
block|{
comment|/* Was is a ldr/str instruction */
comment|/* This is for late abort only */
name|int
name|base
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
modifier|*
name|registers
init|=
operator|&
name|frame
operator|->
name|tf_r0
decl_stmt|;
name|DFC_DISASSEMBLE
argument_list|(
name|fault_pc
argument_list|)
expr_stmt|;
comment|/* This is for late abort only */
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|24
operator|)
operator|)
operator|==
literal|0
operator|||
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|21
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* postindexed ldr/str with no writeback */
name|base
operator|=
operator|(
name|fault_instruction
operator|>>
literal|16
operator|)
operator|&
literal|0x0f
expr_stmt|;
if|if
condition|(
name|base
operator|==
literal|13
operator|&&
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
if|if
condition|(
name|base
operator|==
literal|15
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"late abt fix: r%d=%08x : "
operator|,
name|base
operator|,
name|registers
index|[
name|base
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|25
operator|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Immediate offset - easy */
name|offset
operator|=
name|fault_instruction
operator|&
literal|0xfff
expr_stmt|;
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|)
condition|)
name|offset
operator|=
operator|-
name|offset
expr_stmt|;
name|registers
index|[
name|base
index|]
operator|+=
name|offset
expr_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"imm=%08x "
operator|,
name|offset
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* offset is a shifted register */
name|int
name|shift
decl_stmt|;
name|offset
operator|=
name|fault_instruction
operator|&
literal|0x0f
expr_stmt|;
if|if
condition|(
name|offset
operator|==
name|base
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
comment|/* 				 * Register offset - hard we have to 				 * cope with shifts ! 				 */
name|offset
operator|=
name|registers
index|[
name|offset
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|4
operator|)
operator|)
operator|==
literal|0
condition|)
comment|/* shift with amount */
name|shift
operator|=
operator|(
name|fault_instruction
operator|>>
literal|7
operator|)
operator|&
literal|0x1f
expr_stmt|;
else|else
block|{
comment|/* shift with register */
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|7
operator|)
operator|)
operator|!=
literal|0
condition|)
comment|/* undefined for now so bail out */
return|return
name|ABORT_FIXUP_FAILED
return|;
name|shift
operator|=
operator|(
operator|(
name|fault_instruction
operator|>>
literal|8
operator|)
operator|&
literal|0xf
operator|)
expr_stmt|;
if|if
condition|(
name|base
operator|==
name|shift
condition|)
return|return
name|ABORT_FIXUP_FAILED
return|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"shift reg=%d "
operator|,
name|shift
operator|)
argument_list|)
expr_stmt|;
name|shift
operator|=
name|registers
index|[
name|shift
index|]
expr_stmt|;
block|}
name|DFC_PRINTF
argument_list|(
operator|(
literal|"shift=%08x "
operator|,
name|shift
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
operator|(
operator|(
name|fault_instruction
operator|>>
literal|5
operator|)
operator|&
literal|0x3
operator|)
condition|)
block|{
case|case
literal|0
case|:
comment|/* Logical left */
name|offset
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|u_int
operator|)
name|offset
operator|)
operator|<<
name|shift
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
comment|/* Logical Right */
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
name|shift
operator|=
literal|32
expr_stmt|;
name|offset
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|u_int
operator|)
name|offset
operator|)
operator|>>
name|shift
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
comment|/* Arithmetic Right */
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
name|shift
operator|=
literal|32
expr_stmt|;
name|offset
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|int
operator|)
name|offset
operator|)
operator|>>
name|shift
argument_list|)
expr_stmt|;
break|break;
case|case
literal|3
case|:
comment|/* Rotate right (rol or rxx) */
return|return
name|ABORT_FIXUP_FAILED
return|;
break|break;
block|}
name|DFC_PRINTF
argument_list|(
operator|(
literal|"abt: fixed LDR/STR with "
literal|"register offset\n"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fault_instruction
operator|&
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|)
condition|)
name|offset
operator|=
operator|-
name|offset
expr_stmt|;
name|DFC_PRINTF
argument_list|(
operator|(
literal|"offset=%08x "
operator|,
name|offset
operator|)
argument_list|)
expr_stmt|;
name|registers
index|[
name|base
index|]
operator|+=
name|offset
expr_stmt|;
block|}
name|DFC_PRINTF
argument_list|(
operator|(
literal|"r%d=%08x\n"
operator|,
name|base
operator|,
name|registers
index|[
name|base
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|frame
operator|->
name|tf_spsr
operator|&
name|PSR_MODE
operator|)
operator|==
name|PSR_SVC32_MODE
condition|)
block|{
comment|/* Ok an abort in SVC mode */
comment|/* 		 * Copy the SVC r14 into the usr r14 - The usr r14 is garbage 		 * as the fault happened in svc mode but we need it in the 		 * usr slot so we can treat the registers as an array of ints 		 * during fixing. 		 * NOTE: This PC is in the position but writeback is not 		 * allowed on r15. 		 * Doing it like this is more efficient than trapping this 		 * case in all possible locations in the prior fixup code. 		 */
name|frame
operator|->
name|tf_svc_lr
operator|=
name|frame
operator|->
name|tf_usr_lr
expr_stmt|;
name|frame
operator|->
name|tf_usr_lr
operator|=
name|saved_lr
expr_stmt|;
comment|/* 		 * Note the trapframe does not have the SVC r13 so a fault 		 * from an instruction with writeback to r13 in SVC mode is 		 * not allowed. This should not happen as the kstack is 		 * always valid. 		 */
block|}
comment|/* 	 * Now let the early-abort fixup routine have a go, in case it 	 * was an LDM, STM, LDC or STC that faulted. 	 */
return|return
name|early_abort_fixup
argument_list|(
name|arg
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM7TDMI */
end_comment

begin_comment
comment|/*  * CPU Setup code  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM7TDMI
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM8
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_SA110
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1100
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1110
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
end_if

begin_define
define|#
directive|define
name|IGN
value|0
end_define

begin_define
define|#
directive|define
name|OR
value|1
end_define

begin_define
define|#
directive|define
name|BIC
value|2
end_define

begin_struct
struct|struct
name|cpu_option
block|{
name|char
modifier|*
name|co_name
decl_stmt|;
name|int
name|co_falseop
decl_stmt|;
name|int
name|co_trueop
decl_stmt|;
name|int
name|co_value
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|u_int
name|parse_cpu_options
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|cpu_option
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|u_int
name|parse_cpu_options
parameter_list|(
name|args
parameter_list|,
name|optlist
parameter_list|,
name|cpuctrl
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|struct
name|cpu_option
modifier|*
name|optlist
decl_stmt|;
name|u_int
name|cpuctrl
decl_stmt|;
block|{
name|int
name|integer
decl_stmt|;
if|if
condition|(
name|args
operator|==
name|NULL
condition|)
return|return
operator|(
name|cpuctrl
operator|)
return|;
while|while
condition|(
name|optlist
operator|->
name|co_name
condition|)
block|{
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
name|optlist
operator|->
name|co_name
argument_list|,
name|BOOTOPT_TYPE_BOOLEAN
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
if|if
condition|(
name|integer
condition|)
block|{
if|if
condition|(
name|optlist
operator|->
name|co_trueop
operator|==
name|OR
condition|)
name|cpuctrl
operator||=
name|optlist
operator|->
name|co_value
expr_stmt|;
elseif|else
if|if
condition|(
name|optlist
operator|->
name|co_trueop
operator|==
name|BIC
condition|)
name|cpuctrl
operator|&=
operator|~
name|optlist
operator|->
name|co_value
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|optlist
operator|->
name|co_falseop
operator|==
name|OR
condition|)
name|cpuctrl
operator||=
name|optlist
operator|->
name|co_value
expr_stmt|;
elseif|else
if|if
condition|(
name|optlist
operator|->
name|co_falseop
operator|==
name|BIC
condition|)
name|cpuctrl
operator|&=
operator|~
name|optlist
operator|->
name|co_value
expr_stmt|;
block|}
block|}
operator|++
name|optlist
expr_stmt|;
block|}
return|return
operator|(
name|cpuctrl
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM7TDMI || CPU_ARM8 || CPU_SA110 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM7TDMI
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM8
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_option
name|arm678_options
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"nocache"
block|,
name|IGN
block|,
name|BIC
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"nowritebuf"
block|,
name|IGN
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM6 || CPU_ARM7 || CPU_ARM7TDMI || CPU_ARM8 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM7TDMI
end_ifdef

begin_decl_stmt
name|struct
name|cpu_option
name|arm7tdmi_options
index|[]
init|=
block|{
block|{
literal|"arm7.cache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"arm7.nocache"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"arm7.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"arm7.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"fpaclk2"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_CPCLK
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"arm700.fpaclk"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_CPCLK
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|arm7tdmi_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IDC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
expr_stmt|;
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm678_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm7tdmi_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM7TDMI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM8
end_ifdef

begin_decl_stmt
name|struct
name|cpu_option
name|arm8_options
index|[]
init|=
block|{
block|{
literal|"arm8.cache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"arm8.nocache"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_IDC_ENABLE
block|}
block|,
block|{
literal|"arm8.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"arm8.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"cpu.branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
block|{
literal|"arm8.branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|arm8_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|integer
decl_stmt|;
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|int
name|clocktest
decl_stmt|;
name|int
name|setclock
init|=
literal|0
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IDC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IDC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm678_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm8_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
comment|/* Get clock configuration */
name|clocktest
operator|=
name|arm8_clock_config
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|&
literal|0x0f
expr_stmt|;
comment|/* Special ARM8 clock and test configuration */
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
literal|"arm8.clock.reset"
argument_list|,
name|BOOTOPT_TYPE_BOOLEAN
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
name|clocktest
operator|=
literal|0
expr_stmt|;
name|setclock
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
literal|"arm8.clock.dynamic"
argument_list|,
name|BOOTOPT_TYPE_BOOLEAN
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
if|if
condition|(
name|integer
condition|)
name|clocktest
operator||=
literal|0x01
expr_stmt|;
else|else
name|clocktest
operator|&=
operator|~
operator|(
literal|0x01
operator|)
expr_stmt|;
name|setclock
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
literal|"arm8.clock.sync"
argument_list|,
name|BOOTOPT_TYPE_BOOLEAN
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
if|if
condition|(
name|integer
condition|)
name|clocktest
operator||=
literal|0x02
expr_stmt|;
else|else
name|clocktest
operator|&=
operator|~
operator|(
literal|0x02
operator|)
expr_stmt|;
name|setclock
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
literal|"arm8.clock.fast"
argument_list|,
name|BOOTOPT_TYPE_BININT
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
name|clocktest
operator|=
operator|(
name|clocktest
operator|&
operator|~
literal|0xc0
operator|)
operator||
operator|(
name|integer
operator|&
literal|3
operator|)
operator|<<
literal|2
expr_stmt|;
name|setclock
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|get_bootconf_option
argument_list|(
name|args
argument_list|,
literal|"arm8.test"
argument_list|,
name|BOOTOPT_TYPE_BININT
argument_list|,
operator|&
name|integer
argument_list|)
condition|)
block|{
name|clocktest
operator||=
operator|(
name|integer
operator|&
literal|7
operator|)
operator|<<
literal|5
expr_stmt|;
name|setclock
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/* Set the clock/test register */
if|if
condition|(
name|setclock
condition|)
name|arm8_clock_config
argument_list|(
literal|0x7f
argument_list|,
name|clocktest
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM8 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM9
end_ifdef

begin_decl_stmt
name|struct
name|cpu_option
name|arm9_options
index|[]
init|=
block|{
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"arm9.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"arm9.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"arm9.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"arm9.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|arm9_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_ROUNDROBIN
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_VECRELOC
operator||
name|CPU_CONTROL_ROUNDROBIN
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm9_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|vector_page
operator|==
name|ARM_VECTORS_HIGH
condition|)
name|cpuctrl
operator||=
name|CPU_CONTROL_VECRELOC
expr_stmt|;
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|cpu_control
argument_list|(
name|cpuctrlmask
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM9 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_ARM10
end_ifdef

begin_decl_stmt
name|struct
name|cpu_option
name|arm10_options
index|[]
init|=
block|{
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"arm10.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"arm10.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"arm10.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"arm10.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|arm10_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
operator||
name|CPU_CONTROL_ROUNDROBIN
operator||
name|CPU_CONTROL_CPCLK
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm10_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Now really make sure they are clean.  */
asm|asm
specifier|volatile
asm|("mcr\tp15, 0, r0, c7, c7, 0" : : );
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/* And again. */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM10 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SA110
end_ifdef

begin_decl_stmt
name|struct
name|cpu_option
name|sa110_options
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"nocache"
block|,
name|IGN
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"nowritebuf"
block|,
name|IGN
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"sa110.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"sa110.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"sa110.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"sa110.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|sa110_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
operator||
name|CPU_CONTROL_CPCLK
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|sa110_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
comment|/*	cpu_control(cpuctrlmask, cpuctrl);*/
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/*  	 * enable clockswitching, note that this doesn't read or write to r0, 	 * r0 is just to make it valid asm 	 */
asm|__asm ("mcr 15, 0, r0, c15, c1, 2");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SA110 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_SA1100
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_SA1110
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_option
name|sa11x0_options
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"nocache"
block|,
name|IGN
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"nowritebuf"
block|,
name|IGN
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"sa11x0.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"sa11x0.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"sa11x0.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"sa11x0.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|sa11x0_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
operator||
name|CPU_CONTROL_CPCLK
operator||
name|CPU_CONTROL_VECRELOC
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|sa11x0_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|vector_page
operator|==
name|ARM_VECTORS_HIGH
condition|)
name|cpuctrl
operator||=
name|CPU_CONTROL_VECRELOC
expr_stmt|;
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SA1100 || CPU_SA1110 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_IXP12X0
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_option
name|ixp12x0_options
index|[]
init|=
block|{
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"ixp12x0.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"ixp12x0.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"ixp12x0.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
literal|"cpu.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"cpu.nowritebuf"
block|,
name|OR
block|,
name|BIC
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
literal|"ixp12x0.writebuf"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_WBUF_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ixp12x0_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_VECRELOC
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|ixp12x0_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|vector_page
operator|==
name|ARM_VECTORS_HIGH
condition|)
name|cpuctrl
operator||=
name|CPU_CONTROL_VECRELOC
expr_stmt|;
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
comment|/* cpu_control(0xffffffff, cpuctrl); */
name|cpu_control
argument_list|(
name|cpuctrlmask
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_IXP12X0 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80200
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_PXA2X0
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_IXP425
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_option
name|xscale_options
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|COMPAT_12
block|{
literal|"branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
block|{
literal|"nocache"
block|,
name|IGN
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
endif|#
directive|endif
comment|/* COMPAT_12 */
block|{
literal|"cpu.branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
block|{
literal|"cpu.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"cpu.nocache"
block|,
name|OR
block|,
name|BIC
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"xscale.branchpredict"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_BPRD_ENABLE
block|}
block|,
block|{
literal|"xscale.cache"
block|,
name|BIC
block|,
name|OR
block|,
operator|(
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator|)
block|}
block|,
block|{
literal|"xscale.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"xscale.dcache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_DC_ENABLE
block|}
block|,
block|{
name|NULL
block|,
name|IGN
block|,
name|IGN
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|xscale_setup
parameter_list|(
name|args
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
block|{
name|uint32_t
name|auxctl
decl_stmt|;
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
comment|/* 	 * The XScale Write Buffer is always enabled.  Our option 	 * is to enable/disable coalescing.  Note that bits 6:3 	 * must always be enabled. 	 */
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
expr_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_ROM_ENABLE
operator||
name|CPU_CONTROL_BEND_ENABLE
operator||
name|CPU_CONTROL_AFLT_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
operator||
name|CPU_CONTROL_CPCLK
operator||
name|CPU_CONTROL_VECRELOC
expr_stmt|;
ifndef|#
directive|ifndef
name|ARM32_DISABLE_ALIGNMENT_FAULTS
name|cpuctrl
operator||=
name|CPU_CONTROL_AFLT_ENABLE
expr_stmt|;
endif|#
directive|endif
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|xscale_options
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|vector_page
operator|==
name|ARM_VECTORS_HIGH
condition|)
name|cpuctrl
operator||=
name|CPU_CONTROL_VECRELOC
expr_stmt|;
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* 	 * Set the control register.  Note that bits 6:3 must always 	 * be set to 1. 	 */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
comment|/*	cpu_control(cpuctrlmask, cpuctrl);*/
name|cpu_control
argument_list|(
literal|0xffffffff
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/* Make sure write coalescing is turned on */
asm|__asm __volatile("mrc p15, 0, %0, c1, c0, 1"
block|:
literal|"=r"
operator|(
name|auxctl
operator|)
block|)
function|;
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|XSCALE_NO_COALESCE_WRITES
end_ifdef

begin_expr_stmt
name|auxctl
operator||=
name|XSCALE_AUXCTL_K
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|auxctl
operator|&=
operator|~
name|XSCALE_AUXCTL_K
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|__asm __volatile("mcr p15, 0, %0, c1, c0, 1"
end_asm

begin_expr_stmt
unit|: :
literal|"r"
operator|(
name|auxctl
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80200 || CPU_XSCALE_80321 || CPU_XSCALE_PXA2X0 || CPU_XSCALE_IXP425 */
end_comment

end_unit

