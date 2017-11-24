begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DEF_RDMAVT_INCCQ_H
end_ifndef

begin_define
define|#
directive|define
name|DEF_RDMAVT_INCCQ_H
end_define

begin_comment
comment|/*  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2016 Intel Corporation.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * BSD LICENSE  *  * Copyright(c) 2015 Intel Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  - Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  - Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  - Neither the name of Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<linux/kthread.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_user_verbs.h>
end_include

begin_comment
comment|/*  * Define an ib_cq_notify value that is not valid so we know when CQ  * notifications are armed.  */
end_comment

begin_define
define|#
directive|define
name|RVT_CQ_NONE
value|(IB_CQ_NEXT_COMP + 1)
end_define

begin_comment
comment|/*  * This structure is used to contain the head pointer, tail pointer,  * and completion queue entries as a single memory allocation so  * it can be mmap'ed into user space.  */
end_comment

begin_struct
struct|struct
name|rvt_cq_wc
block|{
name|u32
name|head
decl_stmt|;
comment|/* index of next entry to fill */
name|u32
name|tail
decl_stmt|;
comment|/* index of next ib_poll_cq() entry */
union|union
block|{
comment|/* these are actually size ibcq.cqe + 1 */
name|struct
name|ib_uverbs_wc
name|uqueue
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|ib_wc
name|kqueue
index|[
literal|0
index|]
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The completion queue structure.  */
end_comment

begin_struct
struct|struct
name|rvt_cq
block|{
name|struct
name|ib_cq
name|ibcq
decl_stmt|;
name|struct
name|kthread_work
name|comptask
decl_stmt|;
name|spinlock_t
name|lock
decl_stmt|;
comment|/* protect changes in this struct */
name|u8
name|notify
decl_stmt|;
name|u8
name|triggered
decl_stmt|;
name|struct
name|rvt_dev_info
modifier|*
name|rdi
decl_stmt|;
name|struct
name|rvt_cq_wc
modifier|*
name|queue
decl_stmt|;
name|struct
name|rvt_mmap_info
modifier|*
name|ip
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|struct
name|rvt_cq
modifier|*
name|ibcq_to_rvtcq
parameter_list|(
name|struct
name|ib_cq
modifier|*
name|ibcq
parameter_list|)
block|{
return|return
name|container_of
argument_list|(
name|ibcq
argument_list|,
expr|struct
name|rvt_cq
argument_list|,
name|ibcq
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|void
name|rvt_cq_enter
parameter_list|(
name|struct
name|rvt_cq
modifier|*
name|cq
parameter_list|,
name|struct
name|ib_wc
modifier|*
name|entry
parameter_list|,
name|bool
name|solicited
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEF_RDMAVT_INCCQH */
end_comment

end_unit

