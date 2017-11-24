begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DEF_RDMAVT_INCMR_H
end_ifndef

begin_define
define|#
directive|define
name|DEF_RDMAVT_INCMR_H
end_define

begin_comment
comment|/*  * Copyright(c) 2016 Intel Corporation.  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * BSD LICENSE  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  - Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  - Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  - Neither the name of Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * For Memory Regions. This stuff should probably be moved into rdmavt/mr.h once  * drivers no longer need access to the MR directly.  */
end_comment

begin_comment
comment|/*  * A segment is a linear region of low physical memory.  * Used by the verbs layer.  */
end_comment

begin_struct
struct|struct
name|rvt_seg
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
name|size_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The number of rvt_segs that fit in a page. */
end_comment

begin_define
define|#
directive|define
name|RVT_SEGSZ
value|(PAGE_SIZE / sizeof(struct rvt_seg))
end_define

begin_struct
struct|struct
name|rvt_segarray
block|{
name|struct
name|rvt_seg
name|segs
index|[
name|RVT_SEGSZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_mregion
block|{
name|struct
name|ib_pd
modifier|*
name|pd
decl_stmt|;
comment|/* shares refcnt of ibmr.pd */
name|u64
name|user_base
decl_stmt|;
comment|/* User's address for this region */
name|u64
name|iova
decl_stmt|;
comment|/* IB start address of this region */
name|size_t
name|length
decl_stmt|;
name|u32
name|lkey
decl_stmt|;
name|u32
name|offset
decl_stmt|;
comment|/* offset (bytes) to start of region */
name|int
name|access_flags
decl_stmt|;
name|u32
name|max_segs
decl_stmt|;
comment|/* number of rvt_segs in all the arrays */
name|u32
name|mapsz
decl_stmt|;
comment|/* size of the map array */
name|u8
name|page_shift
decl_stmt|;
comment|/* 0 - non unform/non powerof2 sizes */
name|u8
name|lkey_published
decl_stmt|;
comment|/* in global table */
name|atomic_t
name|lkey_invalid
decl_stmt|;
comment|/* true if current lkey is invalid */
name|struct
name|completion
name|comp
decl_stmt|;
comment|/* complete when refcount goes to zero */
name|atomic_t
name|refcount
decl_stmt|;
name|struct
name|rvt_segarray
modifier|*
name|map
index|[
literal|0
index|]
decl_stmt|;
comment|/* the segments */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RVT_MAX_LKEY_TABLE_BITS
value|23
end_define

begin_struct
struct|struct
name|rvt_lkey_table
block|{
name|spinlock_t
name|lock
decl_stmt|;
comment|/* protect changes in this struct */
name|u32
name|next
decl_stmt|;
comment|/* next unused index (speeds search) */
name|u32
name|gen
decl_stmt|;
comment|/* generation count */
name|u32
name|max
decl_stmt|;
comment|/* size of the table */
name|struct
name|rvt_mregion
name|__rcu
modifier|*
modifier|*
name|table
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These keep track of the copy progress within a memory region.  * Used by the verbs layer.  */
end_comment

begin_struct
struct|struct
name|rvt_sge
block|{
name|struct
name|rvt_mregion
modifier|*
name|mr
decl_stmt|;
name|void
modifier|*
name|vaddr
decl_stmt|;
comment|/* kernel virtual address of segment */
name|u32
name|sge_length
decl_stmt|;
comment|/* length of the SGE */
name|u32
name|length
decl_stmt|;
comment|/* remaining length of the segment */
name|u16
name|m
decl_stmt|;
comment|/* current index: mr->map[m] */
name|u16
name|n
decl_stmt|;
comment|/* current index: mr->map[m]->segs[n] */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rvt_sge_state
block|{
name|struct
name|rvt_sge
modifier|*
name|sg_list
decl_stmt|;
comment|/* next SGE to be used if any */
name|struct
name|rvt_sge
name|sge
decl_stmt|;
comment|/* progress state for the current SGE */
name|u32
name|total_len
decl_stmt|;
name|u8
name|num_sge
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|rvt_put_mr
parameter_list|(
name|struct
name|rvt_mregion
modifier|*
name|mr
parameter_list|)
block|{
if|if
condition|(
name|unlikely
argument_list|(
name|atomic_dec_and_test
argument_list|(
operator|&
name|mr
operator|->
name|refcount
argument_list|)
argument_list|)
condition|)
name|complete
argument_list|(
operator|&
name|mr
operator|->
name|comp
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rvt_get_mr
parameter_list|(
name|struct
name|rvt_mregion
modifier|*
name|mr
parameter_list|)
block|{
name|atomic_inc
argument_list|(
operator|&
name|mr
operator|->
name|refcount
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rvt_put_ss
parameter_list|(
name|struct
name|rvt_sge_state
modifier|*
name|ss
parameter_list|)
block|{
while|while
condition|(
name|ss
operator|->
name|num_sge
condition|)
block|{
name|rvt_put_mr
argument_list|(
name|ss
operator|->
name|sge
operator|.
name|mr
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|ss
operator|->
name|num_sge
condition|)
name|ss
operator|->
name|sge
operator|=
operator|*
name|ss
operator|->
name|sg_list
operator|++
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEF_RDMAVT_INCMRH */
end_comment

end_unit

