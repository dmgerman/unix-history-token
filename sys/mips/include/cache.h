begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cache.h,v 1.6 2003/02/17 11:35:01 simonb Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CACHE_H_
end_define

begin_comment
comment|/*  * Cache operations.  *  * We define the following primitives:  *  * --- Instruction cache synchronization (mandatory):  *  *	icache_sync_all		Synchronize I-cache  *  *	icache_sync_range	Synchronize I-cache range  *  *	icache_sync_range_index	(index ops)  *  * --- Primary data cache (mandatory):  *  *	pdcache_wbinv_all	Write-back Invalidate primary D-cache  *  *	pdcache_wbinv_range	Write-back Invalidate primary D-cache range  *  *	pdcache_wbinv_range_index (index ops)  *  *	pdcache_inv_range	Invalidate primary D-cache range  *  *	pdcache_wb_range	Write-back primary D-cache range  *  * --- Secondary data cache (optional):  *  *	sdcache_wbinv_all	Write-back Invalidate secondary D-cache  *  *	sdcache_wbinv_range	Write-back Invalidate secondary D-cache range  *  *	sdcache_wbinv_range_index (index ops)  *  *	sdcache_inv_range	Invalidate secondary D-cache range  *  *	sdcache_wb_range	Write-back secondary D-cache range  *  * There are some rules that must be followed:  *  *	I-cache Synch (all or range):  *		The goal is to synchronize the instruction stream,  *		so you may need to write-back dirty data cache  *		blocks first.  If a range is requested, and you  *		can't synchronize just a range, you have to hit  *		the whole thing.  *  *	D-cache Write-back Invalidate range:  *		If you can't WB-Inv a range, you must WB-Inv the  *		entire D-cache.  *  *	D-cache Invalidate:  *		If you can't Inv the D-cache without doing a  *		Write-back, YOU MUST PANIC.  This is to catch  *		errors in calling code.  Callers must be aware  *		of this scenario, and must handle it appropriately  *		(consider the bus_dma(9) operations).  *  *	D-cache Write-back:  *		If you can't Write-back without doing an invalidate,  *		that's fine.  Then treat this as a WB-Inv.  Skipping  *		the invalidate is merely an optimization.  *  *	All operations:  *		Valid virtual addresses must be passed to the  *		cache operation.  *  * Finally, these primitives are grouped together in reasonable  * ways.  For all operations described here, first the primary  * cache is frobbed, then the secondary cache frobbed, if the  * operation for the secondary cache exists.  *  *	mips_icache_sync_all	Synchronize I-cache  *  *	mips_icache_sync_range	Synchronize I-cache range  *  *	mips_icache_sync_range_index (index ops)  *  *	mips_dcache_wbinv_all	Write-back Invalidate D-cache  *  *	mips_dcache_wbinv_range	Write-back Invalidate D-cache range  *  *	mips_dcache_wbinv_range_index (index ops)  *  *	mips_dcache_inv_range	Invalidate D-cache range  *  *	mips_dcache_wb_range	Write-back D-cache range  */
end_comment

begin_struct
struct|struct
name|mips_cache_ops
block|{
name|void
function_decl|(
modifier|*
name|mco_icache_sync_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mco_icache_sync_range
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
name|mco_icache_sync_range_index
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
name|mco_pdcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mco_pdcache_wbinv_range
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
name|mco_pdcache_wbinv_range_index
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
name|mco_pdcache_inv_range
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
name|mco_pdcache_wb_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
comment|/* These are called only by the (mipsNN) icache functions. */
name|void
function_decl|(
modifier|*
name|mco_intern_pdcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mco_intern_pdcache_wbinv_range_index
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
name|mco_intern_pdcache_wb_range
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
name|mco_sdcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mco_sdcache_wbinv_range
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
name|mco_sdcache_wbinv_range_index
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
name|mco_sdcache_inv_range
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
name|mco_sdcache_wb_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
comment|/* These are called only by the (mipsNN) icache functions. */
name|void
function_decl|(
modifier|*
name|mco_intern_sdcache_wbinv_all
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mco_intern_sdcache_wbinv_range_index
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
name|mco_intern_sdcache_wb_range
function_decl|)
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|mips_cache_ops
name|mips_cache_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PRIMARY CACHE VARIABLES */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_picache_linesize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mips_pdcache_linesize
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__mco_noargs
parameter_list|(
name|prefix
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\ 	(*mips_cache_ops.mco_ ## prefix ## p ## x )();			\ 	if (*mips_cache_ops.mco_ ## prefix ## s ## x )			\ 		(*mips_cache_ops.mco_ ## prefix ## s ## x )();		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|__mco_2args
parameter_list|(
name|prefix
parameter_list|,
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|do {									\ 	(*mips_cache_ops.mco_ ## prefix ## p ## x )((a), (b));		\ 	if (*mips_cache_ops.mco_ ## prefix ## s ## x )			\ 		(*mips_cache_ops.mco_ ## prefix ## s ## x )((a), (b));	\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|mips_icache_sync_all
parameter_list|()
define|\
value|(*mips_cache_ops.mco_icache_sync_all)()
end_define

begin_define
define|#
directive|define
name|mips_icache_sync_range
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|(*mips_cache_ops.mco_icache_sync_range)((v), (s))
end_define

begin_define
define|#
directive|define
name|mips_icache_sync_range_index
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|(*mips_cache_ops.mco_icache_sync_range_index)((v), (s))
end_define

begin_define
define|#
directive|define
name|mips_dcache_wbinv_all
parameter_list|()
define|\
value|__mco_noargs(, dcache_wbinv_all)
end_define

begin_define
define|#
directive|define
name|mips_dcache_wbinv_range
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(, dcache_wbinv_range, (v), (s))
end_define

begin_define
define|#
directive|define
name|mips_dcache_wbinv_range_index
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(, dcache_wbinv_range_index, (v), (s))
end_define

begin_define
define|#
directive|define
name|mips_dcache_inv_range
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(, dcache_inv_range, (v), (s))
end_define

begin_define
define|#
directive|define
name|mips_dcache_wb_range
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(, dcache_wb_range, (v), (s))
end_define

begin_comment
comment|/*  * Private D-cache functions only called from (currently only the  * mipsNN) I-cache functions.  */
end_comment

begin_define
define|#
directive|define
name|mips_intern_dcache_wbinv_all
parameter_list|()
define|\
value|__mco_noargs(intern_, dcache_wbinv_all)
end_define

begin_define
define|#
directive|define
name|mips_intern_dcache_wbinv_range_index
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(intern_, dcache_wbinv_range_index, (v), (s))
end_define

begin_define
define|#
directive|define
name|mips_intern_dcache_wb_range
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|__mco_2args(intern_, dcache_wb_range, (v), (s))
end_define

begin_comment
comment|/* forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|mips_cpuinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|mips_config_cache
parameter_list|(
name|struct
name|mips_cpuinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips_dcache_compute_align
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<machine/cache_mipsNN.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CACHE_H_ */
end_comment

end_unit

