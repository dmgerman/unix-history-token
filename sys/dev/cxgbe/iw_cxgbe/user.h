begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009-2013 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__C4IW_USER_H__
end_ifndef

begin_define
define|#
directive|define
name|__C4IW_USER_H__
end_define

begin_define
define|#
directive|define
name|C4IW_UVERBS_ABI_VERSION
value|2
end_define

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  * In particular do not use pointer types -- pass pointers in __u64  * instead.  */
end_comment

begin_struct
struct|struct
name|c4iw_create_cq_resp
block|{
name|__u64
name|key
decl_stmt|;
name|__u64
name|gts_key
decl_stmt|;
name|__u64
name|memsize
decl_stmt|;
name|__u32
name|cqid
decl_stmt|;
name|__u32
name|size
decl_stmt|;
name|__u32
name|qid_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|c4iw_create_qp_resp
block|{
name|__u64
name|ma_sync_key
decl_stmt|;
name|__u64
name|sq_key
decl_stmt|;
name|__u64
name|rq_key
decl_stmt|;
name|__u64
name|sq_db_gts_key
decl_stmt|;
name|__u64
name|rq_db_gts_key
decl_stmt|;
name|__u64
name|sq_memsize
decl_stmt|;
name|__u64
name|rq_memsize
decl_stmt|;
name|__u32
name|sqid
decl_stmt|;
name|__u32
name|rqid
decl_stmt|;
name|__u32
name|sq_size
decl_stmt|;
name|__u32
name|rq_size
decl_stmt|;
name|__u32
name|qid_mask
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

