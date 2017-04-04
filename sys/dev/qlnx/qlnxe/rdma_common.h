begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RDMA_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__RDMA_COMMON__
end_define

begin_comment
comment|/************************/
end_comment

begin_comment
comment|/* RDMA FW CONSTANTS */
end_comment

begin_comment
comment|/************************/
end_comment

begin_define
define|#
directive|define
name|RDMA_RESERVED_LKEY
value|(0)
end_define

begin_comment
comment|//Reserved lkey
end_comment

begin_define
define|#
directive|define
name|RDMA_RING_PAGE_SIZE
value|(0x1000)
end_define

begin_comment
comment|//4KB pages
end_comment

begin_define
define|#
directive|define
name|RDMA_MAX_SGE_PER_SQ_WQE
value|(4)
end_define

begin_comment
comment|//max number of SGEs in a single request
end_comment

begin_define
define|#
directive|define
name|RDMA_MAX_SGE_PER_RQ_WQE
value|(4)
end_define

begin_comment
comment|//max number of SGEs in a single request
end_comment

begin_define
define|#
directive|define
name|RDMA_MAX_DATA_SIZE_IN_WQE
value|(0x80000000)
end_define

begin_comment
comment|//max size of data in single request
end_comment

begin_define
define|#
directive|define
name|RDMA_REQ_RD_ATOMIC_ELM_SIZE
value|(0x50)
end_define

begin_define
define|#
directive|define
name|RDMA_RESP_RD_ATOMIC_ELM_SIZE
value|(0x20)
end_define

begin_define
define|#
directive|define
name|RDMA_MAX_CQS
value|(64*1024)
end_define

begin_define
define|#
directive|define
name|RDMA_MAX_TIDS
value|(128*1024-1)
end_define

begin_define
define|#
directive|define
name|RDMA_MAX_PDS
value|(64*1024)
end_define

begin_define
define|#
directive|define
name|RDMA_NUM_STATISTIC_COUNTERS
value|MAX_NUM_VPORTS
end_define

begin_define
define|#
directive|define
name|RDMA_NUM_STATISTIC_COUNTERS_K2
value|MAX_NUM_VPORTS_K2
end_define

begin_define
define|#
directive|define
name|RDMA_NUM_STATISTIC_COUNTERS_BB
value|MAX_NUM_VPORTS_BB
end_define

begin_define
define|#
directive|define
name|RDMA_TASK_TYPE
value|(PROTOCOLID_ROCE)
end_define

begin_struct
struct|struct
name|rdma_srq_id
block|{
name|__le16
name|srq_idx
comment|/* SRQ index */
decl_stmt|;
name|__le16
name|opaque_fid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdma_srq_producers
block|{
name|__le32
name|sge_prod
comment|/* Current produced sge in SRQ */
decl_stmt|;
name|__le32
name|wqe_prod
comment|/* Current produced WQE to SRQ */
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RDMA_COMMON__ */
end_comment

end_unit

