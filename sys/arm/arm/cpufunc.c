begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpufunc.c,v 1.65 2003/11/05 12:53:15 scw Exp $	*/
end_comment

begin_comment
comment|/*-  * arm9 support code Copyright (C) 2001 ARM Ltd  * Copyright (c) 1997 Mark Brinicombe.  * Copyright (c) 1997 Causality Limited  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Causality Limited.  * 4. The name of Causality Limited may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY CAUSALITY LIMITED ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL CAUSALITY LIMITED BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * cpufuncs.c  *  * C functions for supporting CPU / MMU / TLB specific operations.  *  * Created      : 30/01/97  */
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
file|<vm/uma.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
end_if

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

begin_comment
comment|/*  * Some definitions in i81342reg.h clash with i80321reg.h.  * This only happens for the LINT kernel. As it happens,  * we don't need anything from i81342reg.h that we already  * got from somewhere else during a LINT compile.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|COMPILING_LINT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<arm/xscale/i8134x/i81342reg.h>
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

begin_decl_stmt
name|u_int
name|arm_cache_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|arm_cache_type
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|arm_cache_loc
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
name|arm9_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|arm9_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|armv4_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|arm9_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|arm9_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|armv5_ec_cpufuncs
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
name|armv5_ec_setttb
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
name|armv5_ec_icache_sync_all
block|,
comment|/* icache_sync_all	*/
name|armv5_ec_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|armv5_ec_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|armv5_ec_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
name|armv5_ec_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|armv5_ec_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|armv4_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|armv5_ec_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|armv5_ec_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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

begin_decl_stmt
name|struct
name|cpu_functions
name|sheeva_cpufuncs
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
name|sheeva_setttb
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
name|armv5_ec_icache_sync_all
block|,
comment|/* icache_sync_all	*/
name|armv5_ec_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|armv5_ec_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|sheeva_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
name|sheeva_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|sheeva_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|armv4_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|armv5_ec_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|sheeva_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_all	*/
name|sheeva_l2cache_wbinv_all
block|,
comment|/* l2cache_wbinv_all    */
name|sheeva_l2cache_wbinv_range
block|,
comment|/* l2cache_wbinv_range  */
name|sheeva_l2cache_inv_range
block|,
comment|/* l2cache_inv_range    */
name|sheeva_l2cache_wb_range
block|,
comment|/* l2cache_wb_range     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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
name|sheeva_cpu_sleep
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
comment|/* CPU_ARM9E || CPU_ARM10 */
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
name|armv4_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|arm10_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|arm10_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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
name|CPU_MV_PJ4B
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|pj4bv7_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id			*/
name|armv7_drain_writebuf
block|,
comment|/* cpwait		*/
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control		*/
name|cpufunc_domains
block|,
comment|/* Domain		*/
name|armv7_setttb
block|,
comment|/* Setttb		*/
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus		*/
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress		*/
comment|/* TLB functions */
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushID		*/
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushI		*/
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushI_SE	*/
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushD		*/
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|armv7_idcache_wbinv_all
block|,
comment|/* icache_sync_all	*/
name|armv7_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|armv7_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|armv7_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
name|armv7_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|armv7_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|armv7_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|armv7_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|armv7_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf	*/
name|armv7_drain_writebuf
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
name|armv7_context_switch
block|,
comment|/* context_switch	*/
name|pj4bv7_setup
comment|/* cpu setup		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_MV_PJ4B */
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
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
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
name|xscale_cache_flushID
block|,
comment|/* idcache_inv_all	*/
name|xscale_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|xscale_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all 	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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
comment|/* CPU_XSCALE_80200 || CPU_XSCALE_80321 || CPU_XSCALE_PXA2X0 || CPU_XSCALE_IXP425    CPU_XSCALE_80219 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_81342
end_ifdef

begin_decl_stmt
name|struct
name|cpu_functions
name|xscalec3_cpufuncs
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
name|xscalec3_setttb
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
name|xscalec3_cache_syncI
block|,
comment|/* icache_sync_all	*/
name|xscalec3_cache_syncI_rng
block|,
comment|/* icache_sync_range	*/
name|xscalec3_cache_purgeD
block|,
comment|/* dcache_wbinv_all	*/
name|xscalec3_cache_purgeD_rng
block|,
comment|/* dcache_wbinv_range	*/
name|xscale_cache_flushD_rng
block|,
comment|/* dcache_inv_range	*/
name|xscalec3_cache_cleanD_rng
block|,
comment|/* dcache_wb_range	*/
name|xscale_cache_flushID
block|,
comment|/* idcache_inv_all	*/
name|xscalec3_cache_purgeID
block|,
comment|/* idcache_wbinv_all	*/
name|xscalec3_cache_purgeID_rng
block|,
comment|/* idcache_wbinv_range	*/
name|xscalec3_l2cache_purge
block|,
comment|/* l2cache_wbinv_all	*/
name|xscalec3_l2cache_purge_rng
block|,
comment|/* l2cache_wbinv_range	*/
name|xscalec3_l2cache_flush_rng
block|,
comment|/* l2cache_inv_range	*/
name|xscalec3_l2cache_clean_rng
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
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
name|xscalec3_context_switch
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
comment|/* CPU_XSCALE_81342 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA626TE
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|fa526_cpufuncs
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
name|fa526_setttb
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
name|fa526_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE	*/
name|armv4_tlb_flushI
block|,
comment|/* tlb_flushI		*/
name|fa526_tlb_flushI_SE
block|,
comment|/* tlb_flushI_SE	*/
name|armv4_tlb_flushD
block|,
comment|/* tlb_flushD		*/
name|armv4_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE	*/
comment|/* Cache operations */
name|fa526_icache_sync_all
block|,
comment|/* icache_sync_all	*/
name|fa526_icache_sync_range
block|,
comment|/* icache_sync_range	*/
name|fa526_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all	*/
name|fa526_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range	*/
name|fa526_dcache_inv_range
block|,
comment|/* dcache_inv_range	*/
name|fa526_dcache_wb_range
block|,
comment|/* dcache_wb_range	*/
name|armv4_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|fa526_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all	*/
name|fa526_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range	*/
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range	*/
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
comment|/* Other functions */
name|fa526_flush_prefetchbuf
block|,
comment|/* flush_prefetchbuf	*/
name|armv4_drain_writebuf
block|,
comment|/* drain_writebuf	*/
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C	*/
name|fa526_flush_brnchtgt_E
block|,
comment|/* flush_brnchtgt_E	*/
name|fa526_cpu_sleep
block|,
comment|/* sleep		*/
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup	*/
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup	*/
name|fa526_context_switch
block|,
comment|/* context_switch	*/
name|fa526_setup
comment|/* cpu setup 		*/
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_FA526 || CPU_FA626TE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|arm1136_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id                   */
name|cpufunc_nullop
block|,
comment|/* cpwait               */
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control              */
name|cpufunc_domains
block|,
comment|/* Domain               */
name|arm11x6_setttb
block|,
comment|/* Setttb               */
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus          */
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress         */
comment|/* TLB functions */
name|arm11_tlb_flushID
block|,
comment|/* tlb_flushID          */
name|arm11_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE       */
name|arm11_tlb_flushI
block|,
comment|/* tlb_flushI           */
name|arm11_tlb_flushI_SE
block|,
comment|/* tlb_flushI_SE        */
name|arm11_tlb_flushD
block|,
comment|/* tlb_flushD           */
name|arm11_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE        */
comment|/* Cache operations */
name|arm11x6_icache_sync_all
block|,
comment|/* icache_sync_all      */
name|arm11x6_icache_sync_range
block|,
comment|/* icache_sync_range    */
name|arm11x6_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all     */
name|armv6_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range   */
name|armv6_dcache_inv_range
block|,
comment|/* dcache_inv_range     */
name|armv6_dcache_wb_range
block|,
comment|/* dcache_wb_range      */
name|armv6_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|arm11x6_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all    */
name|arm11x6_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
comment|/* Other functions */
name|arm11x6_flush_prefetchbuf
block|,
comment|/* flush_prefetchbuf    */
name|arm11_drain_writebuf
block|,
comment|/* drain_writebuf       */
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E     */
name|arm11_sleep
block|,
comment|/* sleep                */
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup        */
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup    */
name|arm11_context_switch
block|,
comment|/* context_switch       */
name|arm11x6_setup
comment|/* cpu setup            */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM1136 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|arm1176_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id                   */
name|cpufunc_nullop
block|,
comment|/* cpwait               */
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control              */
name|cpufunc_domains
block|,
comment|/* Domain               */
name|arm11x6_setttb
block|,
comment|/* Setttb               */
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus          */
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress         */
comment|/* TLB functions */
name|arm11_tlb_flushID
block|,
comment|/* tlb_flushID          */
name|arm11_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE       */
name|arm11_tlb_flushI
block|,
comment|/* tlb_flushI           */
name|arm11_tlb_flushI_SE
block|,
comment|/* tlb_flushI_SE        */
name|arm11_tlb_flushD
block|,
comment|/* tlb_flushD           */
name|arm11_tlb_flushD_SE
block|,
comment|/* tlb_flushD_SE        */
comment|/* Cache operations */
name|arm11x6_icache_sync_all
block|,
comment|/* icache_sync_all      */
name|arm11x6_icache_sync_range
block|,
comment|/* icache_sync_range    */
name|arm11x6_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all     */
name|armv6_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range   */
name|armv6_dcache_inv_range
block|,
comment|/* dcache_inv_range     */
name|armv6_dcache_wb_range
block|,
comment|/* dcache_wb_range      */
name|armv6_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|arm11x6_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all    */
name|arm11x6_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
comment|/* Other functions */
name|arm11x6_flush_prefetchbuf
block|,
comment|/* flush_prefetchbuf    */
name|arm11_drain_writebuf
block|,
comment|/* drain_writebuf       */
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E     */
name|arm11x6_sleep
block|,
comment|/* sleep                */
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup        */
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup    */
name|arm11_context_switch
block|,
comment|/* context_switch       */
name|arm11x6_setup
comment|/* cpu setup            */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*CPU_ARM1176 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_functions
name|cortexa_cpufuncs
init|=
block|{
comment|/* CPU functions */
name|cpufunc_id
block|,
comment|/* id                   */
name|cpufunc_nullop
block|,
comment|/* cpwait               */
comment|/* MMU functions */
name|cpufunc_control
block|,
comment|/* control              */
name|cpufunc_domains
block|,
comment|/* Domain               */
name|armv7_setttb
block|,
comment|/* Setttb               */
name|cpufunc_faultstatus
block|,
comment|/* Faultstatus          */
name|cpufunc_faultaddress
block|,
comment|/* Faultaddress         */
comment|/*  	 * TLB functions.  ARMv7 does all TLB ops based on a unified TLB model 	 * whether the hardware implements separate I+D or not, so we use the 	 * same 'ID' functions for all 3 variations. 	 */
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushID          */
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushID_SE       */
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushI           */
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushI_SE        */
name|armv7_tlb_flushID
block|,
comment|/* tlb_flushD           */
name|armv7_tlb_flushID_SE
block|,
comment|/* tlb_flushD_SE        */
comment|/* Cache operations */
name|armv7_icache_sync_all
block|,
comment|/* icache_sync_all      */
name|armv7_icache_sync_range
block|,
comment|/* icache_sync_range    */
name|armv7_dcache_wbinv_all
block|,
comment|/* dcache_wbinv_all     */
name|armv7_dcache_wbinv_range
block|,
comment|/* dcache_wbinv_range   */
name|armv7_dcache_inv_range
block|,
comment|/* dcache_inv_range     */
name|armv7_dcache_wb_range
block|,
comment|/* dcache_wb_range      */
name|armv7_idcache_inv_all
block|,
comment|/* idcache_inv_all	*/
name|armv7_idcache_wbinv_all
block|,
comment|/* idcache_wbinv_all    */
name|armv7_idcache_wbinv_range
block|,
comment|/* idcache_wbinv_range  */
comment|/*  	 * Note: For CPUs using the PL310 the L2 ops are filled in when the 	 * L2 cache controller is actually enabled. 	 */
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_all    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wbinv_range  */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_inv_range    */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_wb_range     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* l2cache_drain_writebuf */
comment|/* Other functions */
name|cpufunc_nullop
block|,
comment|/* flush_prefetchbuf    */
name|armv7_drain_writebuf
block|,
comment|/* drain_writebuf       */
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_C     */
operator|(
name|void
operator|*
operator|)
name|cpufunc_nullop
block|,
comment|/* flush_brnchtgt_E     */
name|armv7_sleep
block|,
comment|/* sleep                */
comment|/* Soft functions */
name|cpufunc_null_fixup
block|,
comment|/* dataabt_fixup        */
name|cpufunc_null_fixup
block|,
comment|/* prefetchabt_fixup    */
name|armv7_context_switch
block|,
comment|/* context_switch       */
name|cortexa_setup
comment|/* cpu setup            */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_CORTEXA */
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
name|CPU_ARM9
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
operator|||
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
operator|||
expr|\
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA626TE
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
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
decl_stmt|,
name|cpuid
decl_stmt|;
name|u_int
name|clevel
decl_stmt|,
name|csize
decl_stmt|,
name|i
decl_stmt|,
name|sel
decl_stmt|;
name|u_int
name|multiplier
decl_stmt|;
name|u_char
name|type
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

begin_expr_stmt
name|cpuid
operator|=
name|cpufunc_id
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 	 * ...and thus spake the ARM ARM: 	 * 	 * If an<opcode2> value corresponding to an unimplemented or 	 * reserved ID register is encountered, the System Control 	 * processor returns the value of the main ID register. 	 */
end_comment

begin_if
if|if
condition|(
name|ctype
operator|==
name|cpuid
condition|)
goto|goto
name|out
goto|;
end_if

begin_if
if|if
condition|(
name|CPU_CT_FORMAT
argument_list|(
name|ctype
argument_list|)
operator|==
name|CPU_CT_ARMV7
condition|)
block|{
asm|__asm __volatile("mrc p15, 1, %0, c0, c0, 1"
block|:
literal|"=r"
operator|(
name|clevel
operator|)
block|)
empty_stmt|;
end_if

begin_expr_stmt
name|arm_cache_level
operator|=
name|clevel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_cache_loc
operator|=
name|CPU_CLIDR_LOC
argument_list|(
name|arm_cache_level
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|i
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|(
name|type
operator|=
operator|(
name|clevel
operator|&
literal|0x7
operator|)
operator|)
operator|&&
name|i
operator|<
literal|7
condition|)
block|{
if|if
condition|(
name|type
operator|==
name|CACHE_DCACHE
operator|||
name|type
operator|==
name|CACHE_UNI_CACHE
operator|||
name|type
operator|==
name|CACHE_SEP_CACHE
condition|)
block|{
name|sel
operator|=
name|i
operator|<<
literal|1
expr_stmt|;
asm|__asm __volatile("mcr p15, 2, %0, c0, c0, 0"
block|: :
literal|"r"
operator|(
name|sel
operator|)
block|)
empty_stmt|;
asm|__asm __volatile("mrc p15, 1, %0, c0, c0, 0"
block|:
literal|"=r"
operator|(
name|csize
operator|)
block|)
empty_stmt|;
end_while

begin_expr_stmt
name|arm_cache_type
index|[
name|sel
index|]
operator|=
name|csize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_align
operator|=
literal|1
operator|<<
operator|(
name|CPUV7_CT_xSIZE_LEN
argument_list|(
name|csize
argument_list|)
operator|+
literal|4
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|arm_dcache_align_mask
operator|=
name|arm_dcache_align
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 			if
operator|(
name|type
operator|==
name|CACHE_ICACHE
operator|||
name|type
operator|==
name|CACHE_SEP_CACHE
operator|)
block|{
name|sel
operator|=
operator|(
name|i
operator|<<
literal|1
operator|)
operator||
literal|1
block|;
asm|__asm __volatile("mcr p15, 2, %0, c0, c0, 0"
operator|:
operator|:
literal|"r"
operator|(
name|sel
operator|)
block|)
expr_stmt|;
end_expr_stmt

begin_asm
asm|__asm __volatile("mrc p15, 1, %0, c0, c0, 0"
end_asm

begin_expr_stmt
unit|:
literal|"=r"
operator|(
name|csize
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|arm_cache_type
index|[
name|sel
index|]
operator|=
name|csize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} 			i
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|clevel
operator|>>=
literal|3
expr_stmt|;
end_expr_stmt

begin_else
unit|} 	}
else|else
block|{
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
comment|/* 		 * If you want to know how this code works, go read the ARM ARM. 		 */
name|arm_pcache_type
operator|=
name|CPU_CT_CTYPE
argument_list|(
name|ctype
argument_list|)
expr_stmt|;
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
name|dsize
operator|=
name|CPU_CT_DSIZE
argument_list|(
name|ctype
argument_list|)
expr_stmt|;
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
name|arm_dcache_align
operator|=
name|arm_pdcache_line_size
expr_stmt|;
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
name|arm_dcache_l2_linesize
operator|=
name|CPU_CT_xSIZE_LEN
argument_list|(
name|dsize
argument_list|)
operator|+
literal|3
expr_stmt|;
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
name|out
label|:
name|arm_dcache_align_mask
operator|=
name|arm_dcache_align
operator|-
literal|1
expr_stmt|;
block|}
end_else

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM9 || XSCALE */
end_comment

begin_comment
comment|/*  * Cannot panic here as we may not have a console yet ...  */
end_comment

begin_macro
unit|int
name|set_cpufuncs
argument_list|()
end_macro

begin_block
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
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM9 */
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_MV88FR131
operator|||
name|cputype
operator|==
name|CPU_ID_MV88FR571_VD
operator|||
name|cputype
operator|==
name|CPU_ID_MV88FR571_41
condition|)
block|{
name|uint32_t
name|sheeva_ctrl
decl_stmt|;
name|sheeva_ctrl
operator|=
operator|(
name|MV_DC_STREAM_ENABLE
operator||
name|MV_BTB_DISABLE
operator||
name|MV_L2_ENABLE
operator|)
expr_stmt|;
comment|/* 		 * Workaround for Marvell MV78100 CPU: Cache prefetch 		 * mechanism may affect the cache coherency validity, 		 * so it needs to be disabled. 		 * 		 * Refer to errata document MV-S501058-00C.pdf (p. 3.1 		 * L2 Prefetching Mechanism) for details. 		 */
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_MV88FR571_VD
operator|||
name|cputype
operator|==
name|CPU_ID_MV88FR571_41
condition|)
name|sheeva_ctrl
operator||=
name|MV_L2_PREFETCH_DISABLE
expr_stmt|;
name|sheeva_control_ext
argument_list|(
literal|0xffffffff
operator|&
operator|~
name|MV_WA_ENABLE
argument_list|,
name|sheeva_ctrl
argument_list|)
expr_stmt|;
name|cpufuncs
operator|=
name|sheeva_cpufuncs
expr_stmt|;
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
goto|goto
name|out
goto|;
block|}
elseif|else
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_ARM926EJS
operator|||
name|cputype
operator|==
name|CPU_ID_ARM1026EJS
condition|)
block|{
name|cpufuncs
operator|=
name|armv5_ec_cpufuncs
expr_stmt|;
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM9E || CPU_ARM10 */
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
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM10 */
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_ARM1136JS
operator|||
name|cputype
operator|==
name|CPU_ID_ARM1136JSR1
operator|||
name|cputype
operator|==
name|CPU_ID_ARM1176JZS
condition|)
block|{
ifdef|#
directive|ifdef
name|CPU_ARM1136
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_ARM1136JS
operator|||
name|cputype
operator|==
name|CPU_ID_ARM1136JSR1
condition|)
name|cpufuncs
operator|=
name|arm1136_cpufuncs
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CPU_ARM1176
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_ARM1176JZS
condition|)
name|cpufuncs
operator|=
name|arm1176_cpufuncs
expr_stmt|;
endif|#
directive|endif
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* V4 or higher */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_mmu_v6
argument_list|()
expr_stmt|;
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_ARM1136 || CPU_ARM1176 */
if|#
directive|if
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_CORTEXA5
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA7
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA8R1
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA8R2
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA8R3
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA9R1
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA9R2
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA9R3
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA15R0
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA15R1
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA15R2
operator|||
name|cputype
operator|==
name|CPU_ID_CORTEXA15R3
operator|||
name|cputype
operator|==
name|CPU_ID_KRAIT
condition|)
block|{
name|cpufuncs
operator|=
name|cortexa_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* V4 or higher */
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_mmu_v6
argument_list|()
expr_stmt|;
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
expr_stmt|;
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_CORTEXA */
if|#
directive|if
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_MV88SV581X_V7
operator|||
name|cputype
operator|==
name|CPU_ID_MV88SV584X_V7
operator|||
name|cputype
operator|==
name|CPU_ID_ARM_88SV581X_V7
condition|)
block|{
name|cpufuncs
operator|=
name|pj4bv7_cpufuncs
expr_stmt|;
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_mmu_v6
argument_list|()
expr_stmt|;
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_MV_PJ4B */
if|#
directive|if
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA626TE
argument_list|)
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_FA526
operator|||
name|cputype
operator|==
name|CPU_ID_FA626TE
condition|)
block|{
name|cpufuncs
operator|=
name|fa526_cpufuncs
expr_stmt|;
name|cpu_reset_needs_v4_MMU_disable
operator|=
literal|1
expr_stmt|;
comment|/* SA needs it	*/
name|get_cachetype_cp15
argument_list|()
expr_stmt|;
name|pmap_pte_init_generic
argument_list|()
expr_stmt|;
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
expr_stmt|;
goto|goto
name|out
goto|;
block|}
endif|#
directive|endif
comment|/* CPU_FA526 || CPU_FA626TE */
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
empty_stmt|;
endif|#
directive|endif
comment|/* 		 * XXX Disable ECC in the Bus Controller Unit; we 		 * don't really support it, yet.  Clear any pending 		 * error indications. 		 */
asm|__asm __volatile("mcr p13, 0, %0, c0, c1, 0"
block|: 			:
literal|"r"
operator|(
name|BCUCTL_E0
operator||
name|BCUCTL_E1
operator||
name|BCUCTL_EV
operator|)
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
end_expr_stmt

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

begin_goto
goto|goto
name|out
goto|;
end_goto

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80200 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80321
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
end_if

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
operator|||
name|cputype
operator|==
name|CPU_ID_80219_400
operator|||
name|cputype
operator|==
name|CPU_ID_80219_600
operator|)
block|{
name|cpufuncs
operator|=
name|xscale_cpufuncs
block|;
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
goto|goto
name|out
goto|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_80321 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
end_if

begin_if
if|if
condition|(
name|cputype
operator|==
name|CPU_ID_81342
condition|)
block|{
name|cpufuncs
operator|=
name|xscalec3_cpufuncs
expr_stmt|;
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
goto|goto
name|out
goto|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_81342 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_PXA2X0
end_ifdef

begin_comment
comment|/* ignore core revision to test PXA2xx CPUs */
end_comment

begin_if
if|if
condition|(
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
name|CPU_ID_PXA27X
operator|||
operator|(
name|cputype
operator|&
operator|~
name|CPU_ID_XSCALE_COREREV_MASK
operator|)
operator|==
name|CPU_ID_PXA210
condition|)
block|{
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
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
comment|/* Use powersave on this CPU. */
name|cpu_do_powersave
operator|=
literal|1
expr_stmt|;
goto|goto
name|out
goto|;
block|}
end_if

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
operator|||
name|cputype
operator|==
name|CPU_ID_IXP435
condition|)
block|{
name|cpufuncs
operator|=
name|xscale_cpufuncs
expr_stmt|;
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
goto|goto
name|out
goto|;
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

begin_label
name|out
label|:
end_label

begin_expr_stmt
name|uma_set_align
argument_list|(
name|arm_dcache_align_mask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
literal|0
operator|)
return|;
end_return

begin_comment
unit|}
comment|/*  * Fixup routines for data and prefetch aborts.  *  * Several compile time symbols are used  *  * DEBUG_FAULT_CORRECTION - Print debugging information during the  * correction of registers after a fault.  */
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

begin_comment
comment|/*  * CPU Setup code  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM9E
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
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA626TE
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
comment|/* CPU_ARM9 || XSCALE*/
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM10
argument_list|)
end_if

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
asm|__asm __volatile ("mcr\tp15, 0, r0, c7, c7, 0" : : );
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
comment|/* CPU_ARM9E || CPU_ARM10 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
name|cpu_scc_setup_ccnt
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* This is how you give userland access to the CCNT and PMCn  * registers.  * BEWARE! This gives write access also, which may not be what  * you want!  */
ifdef|#
directive|ifdef
name|_PMC_USER_READ_WRITE_
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
comment|/* Use the Secure User and Non-secure Access Validation Control Register 	 * to allow userland access 	 */
asm|__asm volatile ("mcr	p15, 0, %0, c15, c9, 0\n\t"
block|: 			:
literal|"r"
operator|(
literal|0x00000001
operator|)
block|)
function|;
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Set PMUSERENR[0] to allow userland access */
end_comment

begin_asm
asm|__asm volatile ("mcr	p15, 0, %0, c9, c14, 0\n\t"
end_asm

begin_expr_stmt
unit|: 			:
literal|"r"
operator|(
literal|0x00000001
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_comment
comment|/* Set PMCR[2,0] to enable counters and reset CCNT */
end_comment

begin_asm
asm|__asm volatile ("mcr	p15, 0, %0, c15, c12, 0\n\t"
end_asm

begin_expr_stmt
unit|: 			:
literal|"r"
operator|(
literal|0x00000005
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Set up the PMCCNTR register as a cyclecounter: 	 * Set PMINTENCLR to 0xFFFFFFFF to block interrupts 	 * Set PMCR[2,0] to enable counters and reset CCNT 	 * Set PMCNTENSET to 0x80000000 to enable CCNT */
end_comment

begin_asm
asm|__asm volatile ("mcr	p15, 0, %0, c9, c14, 2\n\t"
end_asm

begin_expr_stmt
literal|"mcr	p15, 0, %1, c9, c12, 0\n\t"
literal|"mcr	p15, 0, %2, c9, c12, 1\n\t"
operator|:
operator|:
literal|"r"
operator|(
literal|0xFFFFFFFF
operator|)
operator|,
literal|"r"
operator|(
literal|0x00000005
operator|)
operator|,
literal|"r"
operator|(
literal|0x80000000
operator|)
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1136
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_decl_stmt
unit|struct
name|cpu_option
name|arm11_options
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
literal|"arm11.cache"
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
literal|"arm11.icache"
block|,
name|BIC
block|,
name|OR
block|,
name|CPU_CONTROL_IC_ENABLE
block|}
block|,
block|{
literal|"arm11.dcache"
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
name|arm11x6_setup
parameter_list|(
name|char
modifier|*
name|args
parameter_list|)
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrl_wax
decl_stmt|;
name|uint32_t
name|auxctrl
decl_stmt|,
name|auxctrl_wax
decl_stmt|;
name|uint32_t
name|tmp
decl_stmt|,
name|tmp2
decl_stmt|;
name|uint32_t
name|sbz
init|=
literal|0
decl_stmt|;
name|uint32_t
name|cpuid
decl_stmt|;
name|cpuid
operator|=
name|cpufunc_id
argument_list|()
expr_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_WBUF_ENABLE
operator||
name|CPU_CONTROL_32BP_ENABLE
operator||
name|CPU_CONTROL_32BD_ENABLE
operator||
name|CPU_CONTROL_LABT_ENABLE
operator||
name|CPU_CONTROL_SYST_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
expr_stmt|;
comment|/* 	 * "write as existing" bits 	 * inverse of this is mask 	 */
name|cpuctrl_wax
operator|=
operator|(
literal|3
operator|<<
literal|30
operator|)
operator||
comment|/* SBZ */
operator|(
literal|1
operator|<<
literal|29
operator|)
operator||
comment|/* FA */
operator|(
literal|1
operator|<<
literal|28
operator|)
operator||
comment|/* TR */
operator|(
literal|3
operator|<<
literal|26
operator|)
operator||
comment|/* SBZ */
operator|(
literal|3
operator|<<
literal|19
operator|)
operator||
comment|/* SBZ */
operator|(
literal|1
operator|<<
literal|17
operator|)
expr_stmt|;
comment|/* SBZ */
name|cpuctrl
operator||=
name|CPU_CONTROL_BPRD_ENABLE
expr_stmt|;
name|cpuctrl
operator||=
name|CPU_CONTROL_V6_EXTPAGE
expr_stmt|;
name|cpuctrl
operator|=
name|parse_cpu_options
argument_list|(
name|args
argument_list|,
name|arm11_options
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
name|auxctrl
operator|=
literal|0
expr_stmt|;
name|auxctrl_wax
operator|=
operator|~
literal|0
expr_stmt|;
comment|/* 	 * This options enables the workaround for the 364296 ARM1136 	 * r0pX errata (possible cache data corruption with 	 * hit-under-miss enabled). It sets the undocumented bit 31 in 	 * the auxiliary control register and the FI bit in the control 	 * register, thus disabling hit-under-miss without putting the 	 * processor into full low interrupt latency mode. ARM11MPCore 	 * is not affected. 	 */
if|if
condition|(
operator|(
name|cpuid
operator|&
name|CPU_ID_CPU_MASK
operator|)
operator|==
name|CPU_ID_ARM1136JS
condition|)
block|{
comment|/* ARM1136JSr0pX */
name|cpuctrl
operator||=
name|CPU_CONTROL_FI_ENABLE
expr_stmt|;
name|auxctrl
operator|=
name|ARM1136_AUXCTL_PFI
expr_stmt|;
name|auxctrl_wax
operator|=
operator|~
name|ARM1136_AUXCTL_PFI
expr_stmt|;
block|}
comment|/* 	 * Enable an errata workaround 	 */
if|if
condition|(
operator|(
name|cpuid
operator|&
name|CPU_ID_CPU_MASK
operator|)
operator|==
name|CPU_ID_ARM1176JZS
condition|)
block|{
comment|/* ARM1176JZSr0 */
name|auxctrl
operator|=
name|ARM1176_AUXCTL_PHD
expr_stmt|;
name|auxctrl_wax
operator|=
operator|~
name|ARM1176_AUXCTL_PHD
expr_stmt|;
block|}
comment|/* Clear out the cache */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
comment|/* Now really make sure they are clean.  */
asm|__asm volatile ("mcr\tp15, 0, %0, c7, c7, 0" : : "r"(sbz));
comment|/* Allow detection code to find the VFP if it's fitted.  */
asm|__asm volatile ("mcr\tp15, 0, %0, c1, c0, 2" : : "r" (0x0fffffff));
comment|/* Set the control register */
name|ctrl
operator|=
name|cpuctrl
expr_stmt|;
name|cpu_control
argument_list|(
operator|~
name|cpuctrl_wax
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
asm|__asm volatile ("mrc	p15, 0, %0, c1, c0, 1\n\t"
literal|"and	%1, %0, %2\n\t"
literal|"orr	%1, %1, %3\n\t"
literal|"teq	%0, %1\n\t"
literal|"mcrne	p15, 0, %1, c1, c0, 1\n\t"
operator|:
literal|"=r"
operator|(
name|tmp
operator|)
operator|,
literal|"=r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|auxctrl_wax
operator|)
operator|,
literal|"r"
operator|(
name|auxctrl
operator|)
block|)
function|;
end_function

begin_comment
comment|/* And again. */
end_comment

begin_expr_stmt
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|cpu_scc_setup_ccnt
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_ARM1136 || CPU_ARM1176 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_MV_PJ4B
end_ifdef

begin_macro
unit|void
name|pj4bv7_setup
argument_list|(
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|cpuctrl
decl_stmt|;
name|pj4b_config
argument_list|()
expr_stmt|;
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
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
operator||=
name|CPU_CONTROL_DC_ENABLE
expr_stmt|;
name|cpuctrl
operator||=
operator|(
literal|0xf
operator|<<
literal|3
operator|)
expr_stmt|;
name|cpuctrl
operator||=
name|CPU_CONTROL_BPRD_ENABLE
expr_stmt|;
name|cpuctrl
operator||=
name|CPU_CONTROL_IC_ENABLE
expr_stmt|;
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
name|cpuctrl
operator||=
operator|(
literal|0x5
operator|<<
literal|16
operator|)
operator||
operator|(
literal|1
operator|<
literal|22
operator|)
expr_stmt|;
name|cpuctrl
operator||=
name|CPU_CONTROL_V6_EXTPAGE
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
literal|0xFFFFFFFF
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/* And again. */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
name|cpu_scc_setup_ccnt
argument_list|()
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_MV_PJ4B */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_CORTEXA
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_KRAIT
argument_list|)
end_if

begin_function
name|void
name|cortexa_setup
parameter_list|(
name|char
modifier|*
name|args
parameter_list|)
block|{
name|int
name|cpuctrl
decl_stmt|,
name|cpuctrlmask
decl_stmt|;
name|cpuctrlmask
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
comment|/* MMU enable         [0] */
name|CPU_CONTROL_AFLT_ENABLE
operator||
comment|/* Alignment fault    [1] */
name|CPU_CONTROL_DC_ENABLE
operator||
comment|/* DCache enable      [2] */
name|CPU_CONTROL_BPRD_ENABLE
operator||
comment|/* Branch prediction [11] */
name|CPU_CONTROL_IC_ENABLE
operator||
comment|/* ICache enable     [12] */
name|CPU_CONTROL_VECRELOC
expr_stmt|;
comment|/* Vector relocation [13] */
name|cpuctrl
operator|=
name|CPU_CONTROL_MMU_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
operator||
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_BPRD_ENABLE
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
comment|/* Switch to big endian */
ifdef|#
directive|ifdef
name|__ARMEB__
name|cpuctrl
operator||=
name|CPU_CONTROL_BEND_ENABLE
expr_stmt|;
endif|#
directive|endif
comment|/* Check if the vector page is at the high address (0xffff0000) */
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
name|cpuctrlmask
argument_list|,
name|cpuctrl
argument_list|)
expr_stmt|;
comment|/* And again. */
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
name|armv7_auxctrl
argument_list|(
operator|(
literal|1
operator|<<
literal|6
operator|)
operator||
operator|(
literal|1
operator|<<
literal|0
operator|)
argument_list|,
operator|(
literal|1
operator|<<
literal|6
operator|)
operator||
operator|(
literal|1
operator|<<
literal|0
operator|)
argument_list|)
expr_stmt|;
comment|/* Enable SMP + TLB broadcasting  */
endif|#
directive|endif
name|cpu_scc_setup_ccnt
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_CORTEXA */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_FA626TE
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cpu_option
name|fa526_options
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

begin_function
name|void
name|fa526_setup
parameter_list|(
name|char
modifier|*
name|args
parameter_list|)
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
name|fa526_options
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
comment|/* CPU_FA526 || CPU_FA626TE */
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
operator|||
expr|\
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_XSCALE_81342
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
operator||
expr|\
name|CPU_CONTROL_L2_ENABLE
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
ifdef|#
directive|ifdef
name|CPU_XSCALE_CORE3
name|cpuctrl
operator||=
name|CPU_CONTROL_L2_ENABLE
expr_stmt|;
endif|#
directive|endif
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

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_CORE3
end_ifdef

begin_expr_stmt
name|auxctl
operator||=
name|XSCALE_AUXCTL_LLR
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|auxctl
operator||=
name|XSCALE_AUXCTL_MD_MASK
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
comment|/* CPU_XSCALE_80200 || CPU_XSCALE_80321 || CPU_XSCALE_PXA2X0 || CPU_XSCALE_IXP425 	   CPU_XSCALE_80219 */
end_comment

end_unit

