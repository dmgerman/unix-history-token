begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2007, 2008 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX4_ABI_USER_H
end_ifndef

begin_define
define|#
directive|define
name|MLX4_ABI_USER_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<infiniband/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Increment this value if any changes that break userspace ABI  * compatibility are made.  */
end_comment

begin_define
define|#
directive|define
name|MLX4_IB_UVERBS_NO_DEV_CAPS_ABI_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|MLX4_IB_UVERBS_ABI_VERSION
value|4
end_define

begin_comment
comment|/*  * Make sure that all structs defined in this file remain laid out so  * that they pack the same way on 32-bit and 64-bit architectures (to  * avoid incompatibility between 32-bit userspace and 64-bit kernels).  * In particular do not use pointer types -- pass pointers in __u64  * instead.  */
end_comment

begin_struct
struct|struct
name|mlx4_ib_alloc_ucontext_resp_v3
block|{
name|__u32
name|qp_tab_size
decl_stmt|;
name|__u16
name|bf_reg_size
decl_stmt|;
name|__u16
name|bf_regs_per_page
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_ib_alloc_ucontext_resp
block|{
name|__u32
name|dev_caps
decl_stmt|;
name|__u32
name|qp_tab_size
decl_stmt|;
name|__u16
name|bf_reg_size
decl_stmt|;
name|__u16
name|bf_regs_per_page
decl_stmt|;
name|__u32
name|cqe_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_ib_alloc_pd_resp
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
name|mlx4_ib_create_cq
block|{
name|__u64
name|buf_addr
decl_stmt|;
name|__u64
name|db_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_ib_create_cq_resp
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
name|mlx4_ib_resize_cq
block|{
name|__u64
name|buf_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_ib_create_srq
block|{
name|__u64
name|buf_addr
decl_stmt|;
name|__u64
name|db_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mlx4_ib_create_srq_resp
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
name|mlx4_ib_create_qp
block|{
name|__u64
name|buf_addr
decl_stmt|;
name|__u64
name|db_addr
decl_stmt|;
name|__u8
name|log_sq_bb_count
decl_stmt|;
name|__u8
name|log_sq_stride
decl_stmt|;
name|__u8
name|sq_no_prefetch
decl_stmt|;
name|__u8
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX4_ABI_USER_H */
end_comment

end_unit

