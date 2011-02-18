begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Chelsio Communications, Inc.  * All rights reserved.  * Written by: Navdeep Parhar<np@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_OFFLOAD_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_OFFLOAD_H__
end_define

begin_comment
comment|/*  * Max # of ATIDs.  The absolute HW max is 16K but we keep it lower.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ATIDS
value|8192U
end_define

begin_struct
struct|struct
name|serv_entry
block|{
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|aopen_entry
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|union
name|aopen_entry
modifier|*
name|next
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Holds the size, base address, free list start, etc of the TID, server TID,  * and active-open TID tables.  The tables themselves are allocated dynamically.  */
end_comment

begin_struct
struct|struct
name|tid_info
block|{
name|void
modifier|*
modifier|*
name|tid_tab
decl_stmt|;
name|unsigned
name|int
name|ntids
decl_stmt|;
name|struct
name|serv_entry
modifier|*
name|stid_tab
decl_stmt|;
name|unsigned
name|long
modifier|*
name|stid_bmap
decl_stmt|;
name|unsigned
name|int
name|nstids
decl_stmt|;
name|unsigned
name|int
name|stid_base
decl_stmt|;
name|union
name|aopen_entry
modifier|*
name|atid_tab
decl_stmt|;
name|unsigned
name|int
name|natids
decl_stmt|;
name|unsigned
name|int
name|nftids
decl_stmt|;
name|unsigned
name|int
name|ftid_base
decl_stmt|;
name|union
name|aopen_entry
modifier|*
name|afree
decl_stmt|;
name|unsigned
name|int
name|atids_in_use
decl_stmt|;
name|unsigned
name|int
name|stids_in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_range
block|{
name|unsigned
name|int
name|start
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_virt_res
block|{
comment|/* virtualized HW resources */
name|struct
name|t4_range
name|ddp
decl_stmt|;
name|struct
name|t4_range
name|iscsi
decl_stmt|;
name|struct
name|t4_range
name|stag
decl_stmt|;
name|struct
name|t4_range
name|rq
decl_stmt|;
name|struct
name|t4_range
name|pbl
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

