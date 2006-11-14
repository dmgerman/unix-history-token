begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEMSTAT_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEMSTAT_INTERNAL_H_
end_define

begin_comment
comment|/*  * memstat maintains its own internal notion of statistics on each memory  * type, common across UMA and kernel malloc.  Some fields are straight from  * the allocator statistics, others are derived when extracted from the  * kernel.  A struct memory_type will describe each type supported by an  * allocator.  memory_type structures can be chained into lists.  */
end_comment

begin_struct
struct|struct
name|memory_type
block|{
comment|/* 	 * Static properties of type. 	 */
name|int
name|mt_allocator
decl_stmt|;
comment|/* malloc(9), uma(9), etc. */
name|char
name|mt_name
index|[
name|MEMTYPE_MAXNAME
index|]
decl_stmt|;
comment|/* name of memory type. */
comment|/* 	 * (Relatively) static zone settings, that don't uniquely identify 	 * the zone, but also don't change much. 	 */
name|uint64_t
name|mt_countlimit
decl_stmt|;
comment|/* 0, or maximum allocations. */
name|uint64_t
name|mt_byteslimit
decl_stmt|;
comment|/* 0, or maximum bytes. */
name|uint64_t
name|mt_sizemask
decl_stmt|;
comment|/* malloc: allocated size bitmask. */
name|uint64_t
name|mt_size
decl_stmt|;
comment|/* uma: size of objects. */
comment|/* 	 * Zone or type information that includes all caches and any central 	 * zone state.  Depending on the allocator, this may be synthesized 	 * from several sources, or directly measured. 	 */
name|uint64_t
name|mt_memalloced
decl_stmt|;
comment|/* Bytes allocated over life time. */
name|uint64_t
name|mt_memfreed
decl_stmt|;
comment|/* Bytes freed over life time. */
name|uint64_t
name|mt_numallocs
decl_stmt|;
comment|/* Allocations over life time. */
name|uint64_t
name|mt_numfrees
decl_stmt|;
comment|/* Frees over life time. */
name|uint64_t
name|mt_bytes
decl_stmt|;
comment|/* Bytes currently allocated. */
name|uint64_t
name|mt_count
decl_stmt|;
comment|/* Number of current allocations. */
name|uint64_t
name|mt_free
decl_stmt|;
comment|/* Number of cached free items. */
name|uint64_t
name|mt_failures
decl_stmt|;
comment|/* Number of allocation failures. */
comment|/* 	 * Caller-owned memory. 	 */
name|void
modifier|*
name|mt_caller_pointer
index|[
name|MEMSTAT_MAXCALLER
index|]
decl_stmt|;
comment|/* Pointers. */
name|uint64_t
name|mt_caller_uint64
index|[
name|MEMSTAT_MAXCALLER
index|]
decl_stmt|;
comment|/* Integers. */
comment|/* 	 * For allocators making use of per-CPU caches, we also provide raw 	 * statistics from the central allocator and each per-CPU cache, 	 * which (combined) sometimes make up the above general statistics. 	 * 	 * First, central zone/type state, all numbers excluding any items 	 * cached in per-CPU caches. 	 * 	 * XXXRW: Might be desirable to separately expose allocation stats 	 * from zone, which should (combined with per-cpu) add up to the 	 * global stats above. 	 */
name|uint64_t
name|mt_zonefree
decl_stmt|;
comment|/* Free items in zone. */
name|uint64_t
name|mt_kegfree
decl_stmt|;
comment|/* Free items in keg. */
comment|/* 	 * Per-CPU measurements fall into two categories: per-CPU allocation, 	 * and per-CPU cache state. 	 */
struct|struct
block|{
name|uint64_t
name|mtp_memalloced
decl_stmt|;
comment|/* Per-CPU mt_memalloced. */
name|uint64_t
name|mtp_memfreed
decl_stmt|;
comment|/* Per-CPU mt_memfreed. */
name|uint64_t
name|mtp_numallocs
decl_stmt|;
comment|/* Per-CPU mt_numallocs. */
name|uint64_t
name|mtp_numfrees
decl_stmt|;
comment|/* Per-CPU mt_numfrees. */
name|uint64_t
name|mtp_sizemask
decl_stmt|;
comment|/* Per-CPU mt_sizemask. */
name|void
modifier|*
name|mtp_caller_pointer
index|[
name|MEMSTAT_MAXCALLER
index|]
decl_stmt|;
name|uint64_t
name|mtp_caller_uint64
index|[
name|MEMSTAT_MAXCALLER
index|]
decl_stmt|;
block|}
name|mt_percpu_alloc
index|[
name|MEMSTAT_MAXCPU
index|]
struct|;
struct|struct
block|{
name|uint64_t
name|mtp_free
decl_stmt|;
comment|/* Per-CPU cache free items. */
block|}
name|mt_percpu_cache
index|[
name|MEMSTAT_MAXCPU
index|]
struct|;
name|LIST_ENTRY
argument_list|(
argument|memory_type
argument_list|)
name|mt_list
expr_stmt|;
comment|/* List of types. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of struct memory_type_list is in memstat.h.  */
end_comment

begin_struct
struct|struct
name|memory_type_list
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|memory_type
argument_list|)
name|mtl_list
expr_stmt|;
name|int
name|mtl_error
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|_memstat_mtl_empty
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|memory_type
modifier|*
name|_memstat_mt_allocate
parameter_list|(
name|struct
name|memory_type_list
modifier|*
name|list
parameter_list|,
name|int
name|allocator
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_memstat_mt_reset_stats
parameter_list|(
name|struct
name|memory_type
modifier|*
name|mtp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MEMSTAT_INTERNAL_H_ */
end_comment

end_unit

