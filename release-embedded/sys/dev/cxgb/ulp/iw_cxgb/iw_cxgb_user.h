begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007, 2008 Chelsio, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IWCH_USER_H__
end_ifndef

begin_define
define|#
directive|define
name|__IWCH_USER_H__
end_define

begin_define
define|#
directive|define
name|IWCH_UVERBS_ABI_VERSION
value|1
end_define

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  * In particular do not use pointer types -- pass pointers in uint64_t  * instead.  */
end_comment

begin_struct
struct|struct
name|iwch_create_cq_req
block|{
name|uint64_t
name|user_rptr_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwch_create_cq_resp_v0
block|{
name|__u64
name|key
decl_stmt|;
name|__u32
name|cqid
decl_stmt|;
name|__u32
name|size_log2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwch_create_cq_resp
block|{
name|uint64_t
name|key
decl_stmt|;
name|uint32_t
name|cqid
decl_stmt|;
name|uint32_t
name|size_log2
decl_stmt|;
name|__u32
name|memsize
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwch_create_qp_resp
block|{
name|uint64_t
name|key
decl_stmt|;
name|uint64_t
name|db_key
decl_stmt|;
name|uint32_t
name|qpid
decl_stmt|;
name|uint32_t
name|size_log2
decl_stmt|;
name|uint32_t
name|sq_size_log2
decl_stmt|;
name|uint32_t
name|rq_size_log2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwch_reg_user_mr_resp
block|{
name|uint32_t
name|pbl_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

