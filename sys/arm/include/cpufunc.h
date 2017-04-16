begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpufunc.h,v 1.29 2003/09/06 09:08:35 rearnsha Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Mark Brinicombe.  * Copyright (c) 1997 Causality Limited  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Causality Limited.  * 4. The name of Causality Limited may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY CAUSALITY LIMITED ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL CAUSALITY LIMITED BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * cpufunc.h  *  * Prototypes for cpu, mmu and tlb related functions.  *  * $FreeBSD$  */
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
file|<machine/armreg.h>
end_include

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm(".word      0xe7ffffff");
block|}
end_function

begin_struct
struct|struct
name|cpu_functions
block|{
comment|/* CPU functions */
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
name|void
function_decl|(
modifier|*
name|cf_cpwait
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* MMU functions */
name|u_int
function_decl|(
modifier|*
name|cf_control
function_decl|)
parameter_list|(
name|u_int
name|bic
parameter_list|,
name|u_int
name|eor
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_setttb
function_decl|)
parameter_list|(
name|u_int
name|ttb
parameter_list|)
function_decl|;
comment|/* TLB functions */
name|void
function_decl|(
modifier|*
name|cf_tlb_flushID
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_tlb_flushID_SE
function_decl|)
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_tlb_flushD
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_tlb_flushD_SE
function_decl|)
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
comment|/* 	 * Cache operations: 	 * 	 * We define the following primitives: 	 * 	 *	icache_sync_range	Synchronize I-cache range 	 * 	 *	dcache_wbinv_all	Write-back and Invalidate D-cache 	 *	dcache_wbinv_range	Write-back and Invalidate D-cache range 	 *	dcache_inv_range	Invalidate D-cache range 	 *	dcache_wb_range		Write-back D-cache range 	 * 	 *	idcache_wbinv_all	Write-back and Invalidate D-cache, 	 *				Invalidate I-cache 	 *	idcache_wbinv_range	Write-back and Invalidate D-cache, 	 *				Invalidate I-cache range 	 * 	 * Note that the ARM term for "write-back" is "clean".  We use 	 * the term "write-back" since it's a more common way to describe 	 * the operation. 	 * 	 * There are some rules that must be followed: 	 * 	 *	ID-cache Invalidate All: 	 *		Unlike other functions, this one must never write back. 	 *		It is used to intialize the MMU when it is in an unknown 	 *		state (such as when it may have lines tagged as valid 	 *		that belong to a previous set of mappings). 	 * 	 *	I-cache Sync range: 	 *		The goal is to synchronize the instruction stream, 	 *		so you may beed to write-back dirty D-cache blocks 	 *		first.  If a range is requested, and you can't 	 *		synchronize just a range, you have to hit the whole 	 *		thing. 	 * 	 *	D-cache Write-Back and Invalidate range: 	 *		If you can't WB-Inv a range, you must WB-Inv the 	 *		entire D-cache. 	 * 	 *	D-cache Invalidate: 	 *		If you can't Inv the D-cache, you must Write-Back 	 *		and Invalidate.  Code that uses this operation 	 *		MUST NOT assume that the D-cache will not be written 	 *		back to memory. 	 * 	 *	D-cache Write-Back: 	 *		If you can't Write-back without doing an Inv, 	 *		that's fine.  Then treat this as a WB-Inv. 	 *		Skipping the invalidate is merely an optimization. 	 * 	 *	All operations: 	 *		Valid virtual addresses must be passed to each 	 *		cache operation. 	 */
name|void
function_decl|(
modifier|*
name|cf_icache_sync_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_dcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_dcache_wbinv_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_dcache_inv_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_dcache_wb_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_idcache_inv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_idcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_idcache_wbinv_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|cf_l2cache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_l2cache_wbinv_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_l2cache_inv_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_l2cache_wb_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cf_l2cache_drain_writebuf
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Other functions */
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
name|void
function_decl|(
modifier|*
name|cf_drain_writebuf
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|cf_sleep
function_decl|)
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
comment|/* Soft functions */
name|void
function_decl|(
modifier|*
name|cf_context_switch
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|cf_setup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cpu_functions
name|cpufuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cputype
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_define
define|#
directive|define
name|cpu_cpwait
parameter_list|()
value|cpufuncs.cf_cpwait()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_control
parameter_list|(
name|c
parameter_list|,
name|e
parameter_list|)
value|cpufuncs.cf_control(c, e)
end_define

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_define
define|#
directive|define
name|cpu_setttb
parameter_list|(
name|t
parameter_list|)
value|cpufuncs.cf_setttb(t)
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID
parameter_list|()
value|cpufuncs.cf_tlb_flushID()
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID_SE
parameter_list|(
name|e
parameter_list|)
value|cpufuncs.cf_tlb_flushID_SE(e)
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushD
parameter_list|()
value|cpufuncs.cf_tlb_flushD()
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushD_SE
parameter_list|(
name|e
parameter_list|)
value|cpufuncs.cf_tlb_flushD_SE(e)
end_define

begin_define
define|#
directive|define
name|cpu_icache_sync_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_icache_sync_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_dcache_wbinv_all
parameter_list|()
value|cpufuncs.cf_dcache_wbinv_all()
end_define

begin_define
define|#
directive|define
name|cpu_dcache_wbinv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_dcache_wbinv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_dcache_inv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_dcache_inv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_dcache_wb_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_dcache_wb_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_idcache_inv_all
parameter_list|()
value|cpufuncs.cf_idcache_inv_all()
end_define

begin_define
define|#
directive|define
name|cpu_idcache_wbinv_all
parameter_list|()
value|cpufuncs.cf_idcache_wbinv_all()
end_define

begin_define
define|#
directive|define
name|cpu_idcache_wbinv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_idcache_wbinv_range((a), (s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_l2cache_wbinv_all
parameter_list|()
value|cpufuncs.cf_l2cache_wbinv_all()
end_define

begin_define
define|#
directive|define
name|cpu_l2cache_wb_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_l2cache_wb_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_l2cache_inv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_l2cache_inv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_l2cache_wbinv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|cpufuncs.cf_l2cache_wbinv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_l2cache_drain_writebuf
parameter_list|()
value|cpufuncs.cf_l2cache_drain_writebuf()
end_define

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_define
define|#
directive|define
name|cpu_drain_writebuf
parameter_list|()
value|cpufuncs.cf_drain_writebuf()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cpu_sleep
parameter_list|(
name|m
parameter_list|)
value|cpufuncs.cf_sleep(m)
end_define

begin_define
define|#
directive|define
name|cpu_setup
parameter_list|()
value|cpufuncs.cf_setup()
end_define

begin_function_decl
name|int
name|set_cpufuncs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARCHITECTURE_NOT_PRESENT
value|1
end_define

begin_comment
comment|/* known but not configured */
end_comment

begin_define
define|#
directive|define
name|ARCHITECTURE_NOT_SUPPORTED
value|2
end_define

begin_comment
comment|/* not known */
end_comment

begin_function_decl
name|void
name|cpufunc_nullop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_ident
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpufunc_control
parameter_list|(
name|u_int
name|clear
parameter_list|,
name|u_int
name|bic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_domains
parameter_list|(
name|u_int
name|domains
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_faultstatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_faultaddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_get_control
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cpu_pfr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_FA526
argument_list|)
end_if

begin_function_decl
name|void
name|fa526_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_setttb
parameter_list|(
name|u_int
name|ttb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_cpu_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_tlb_flushID_SE
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_icache_sync_range
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_dcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_dcache_inv_range
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_dcache_wb_range
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fa526_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
end_if

begin_function_decl
name|void
name|arm9_setttb
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_tlb_flushID_SE
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
end_if

begin_function_decl
name|void
name|arm9_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_dcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm9_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|arm9_dcache_sets_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|arm9_dcache_sets_inc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|arm9_dcache_index_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|arm9_dcache_index_inc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
end_if

begin_function_decl
name|void
name|arm10_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|sheeva_control_ext
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_cpu_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_setttb
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_l2cache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_l2cache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_l2cache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sheeva_l2cache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
end_if

begin_function_decl
name|void
name|armv6_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
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

begin_function_decl
name|void
name|armv7_setttb
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_tlb_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_tlb_flushID_SE
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_idcache_inv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_dcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_cpu_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv7_drain_writebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|armv7_auxctrl
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armadaxp_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cortexa_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_MV_PJ4B
argument_list|)
end_if

begin_function_decl
name|void
name|pj4b_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pj4bv7_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_function_decl
name|void
name|arm11_tlb_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11_tlb_flushID_SE
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11_tlb_flushD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11_tlb_flushD_SE
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11_drain_writebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv6_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv6_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv6_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv6_idcache_inv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_setttb
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_dcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm11x6_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* no ref. for errata */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
end_if

begin_function_decl
name|void
name|armv5_ec_setttb
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_dcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_idcache_wbinv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv5_ec_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_ARM9
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_ARM9E
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|CPU_FA526
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
name|CPU_XSCALE_81342
argument_list|)
end_if

begin_function_decl
name|void
name|armv4_tlb_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv4_tlb_flushD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv4_tlb_flushD_SE
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv4_drain_writebuf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|armv4_idcache_inv_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
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
name|CPU_XSCALE_81342
argument_list|)
end_if

begin_function_decl
name|void
name|xscale_cpwait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cpu_sleep
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|xscale_control
parameter_list|(
name|u_int
name|clear
parameter_list|,
name|u_int
name|bic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_setttb
parameter_list|(
name|u_int
name|ttb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_tlb_flushID_SE
parameter_list|(
name|u_int
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_flushI
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_flushD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_flushD_SE
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_cleanID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_cleanD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_cleanD_E
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_clean_minidata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeID_E
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeD_E
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_syncI
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_cleanID_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_cleanD_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeID_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_purgeD_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_syncI_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_cache_flushD_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscale_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_PXA2X0 || CPU_XSCALE_IXP425 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_XSCALE_81342
end_ifdef

begin_function_decl
name|void
name|xscalec3_l2cache_purge
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_purgeID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_purgeD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_cleanID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_cleanD
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_syncI
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_purgeID_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_purgeD_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_cleanID_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_cleanD_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_cache_syncI_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_l2cache_flush_rng
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_l2cache_clean_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_l2cache_purge_rng
parameter_list|(
name|vm_offset_t
name|start
parameter_list|,
name|vm_size_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_setttb
parameter_list|(
name|u_int
name|ttb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xscalec3_context_switch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_XSCALE_81342 */
end_comment

begin_comment
comment|/*  * Macros for manipulating CPU interrupts  */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_define
define|#
directive|define
name|__ARM_INTR_BITS
value|(PSR_I | PSR_F)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ARM_INTR_BITS
value|(PSR_I | PSR_F | PSR_A)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|uint32_t
name|__set_cpsr
parameter_list|(
name|uint32_t
name|bic
parameter_list|,
name|uint32_t
name|eor
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|,
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"mrs     %0, cpsr\n"
comment|/* Get the CPSR */
literal|"bic	 %1, %0, %2\n"
comment|/* Clear bits */
literal|"eor	 %1, %1, %3\n"
comment|/* XOR bits */
literal|"msr     cpsr_xc, %1\n"
comment|/* Set the CPSR */
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
literal|"r"
operator|(
name|bic
operator|)
operator|,
literal|"r"
operator|(
name|eor
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|ret
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|disable_interrupts
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|__set_cpsr
argument_list|(
name|mask
operator|&
name|__ARM_INTR_BITS
argument_list|,
name|mask
operator|&
name|__ARM_INTR_BITS
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|enable_interrupts
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|__set_cpsr
argument_list|(
name|mask
operator|&
name|__ARM_INTR_BITS
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|restore_interrupts
parameter_list|(
name|uint32_t
name|old_cpsr
parameter_list|)
block|{
return|return
operator|(
name|__set_cpsr
argument_list|(
name|__ARM_INTR_BITS
argument_list|,
name|old_cpsr
operator|&
name|__ARM_INTR_BITS
argument_list|)
operator|)
return|;
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
return|return
operator|(
name|disable_interrupts
argument_list|(
name|PSR_I
operator||
name|PSR_F
argument_list|)
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
name|s
parameter_list|)
block|{
name|restore_interrupts
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__ARM_INTR_BITS
end_undef

begin_comment
comment|/*  * Functions to manipulate cpu r13  * (in arm/arm32/setstack.S)  */
end_comment

begin_function_decl
name|void
name|set_stackptr
parameter_list|(
name|u_int
name|mode
parameter_list|,
name|u_int
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|get_stackptr
parameter_list|(
name|u_int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Miscellany  */
end_comment

begin_function_decl
name|int
name|get_pc_str_offset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CPU functions from locore.S  */
end_comment

begin_function_decl
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Cache info variables.  */
end_comment

begin_comment
comment|/* PRIMARY CACHE VARIABLES */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_picache_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_picache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_picache_ways
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_pdcache_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and unified */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_pdcache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_pdcache_ways
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_pcache_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_pcache_unified
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_dcache_align
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|arm_dcache_align_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|arm_cache_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|arm_cache_loc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|arm_cache_type
index|[
literal|14
index|]
decl_stmt|;
end_decl_stmt

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
comment|/* _MACHINE_CPUFUNC_H_ */
end_comment

begin_comment
comment|/* End of cpufunc.h */
end_comment

end_unit

