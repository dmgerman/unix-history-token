begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Topspin Communications.  All rights reserved.  * Copyright (c) 2005, 2006 Cisco Systems.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MTHCA_USER_H
end_ifndef

begin_define
define|#
directive|define
name|MTHCA_USER_H
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/*  * Increment this value if any changes that break userspace ABI  * compatibility are made.  */
end_comment

begin_define
define|#
directive|define
name|MTHCA_UVERBS_ABI_VERSION
value|1
end_define

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  * In particular do not use pointer types -- pass pointers in __u64  * instead.  */
end_comment

begin_struct
struct|struct
name|mthca_alloc_ucontext_resp
block|{
name|__u32
name|qp_tab_size
decl_stmt|;
name|__u32
name|uarc_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_alloc_pd_resp
block|{
name|__u32
name|pdn
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_reg_mr
block|{
comment|/*  * Mark the memory region with a DMA attribute that causes  * in-flight DMA to be flushed when the region is written to:  */
define|#
directive|define
name|MTHCA_MR_DMASYNC
value|0x1
name|__u32
name|mr_attrs
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_create_cq
block|{
name|__u32
name|lkey
decl_stmt|;
name|__u32
name|pdn
decl_stmt|;
name|__u64
name|arm_db_page
decl_stmt|;
name|__u64
name|set_db_page
decl_stmt|;
name|__u32
name|arm_db_index
decl_stmt|;
name|__u32
name|set_db_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_create_cq_resp
block|{
name|__u32
name|cqn
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_resize_cq
block|{
name|__u32
name|lkey
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_create_srq
block|{
name|__u32
name|lkey
decl_stmt|;
name|__u32
name|db_index
decl_stmt|;
name|__u64
name|db_page
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_create_srq_resp
block|{
name|__u32
name|srqn
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mthca_create_qp
block|{
name|__u32
name|lkey
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
name|__u64
name|sq_db_page
decl_stmt|;
name|__u64
name|rq_db_page
decl_stmt|;
name|__u32
name|sq_db_index
decl_stmt|;
name|__u32
name|rq_db_index
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTHCA_USER_H */
end_comment

end_unit

