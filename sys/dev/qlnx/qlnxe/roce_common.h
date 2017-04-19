begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ROCE_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__ROCE_COMMON__
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common rdma target for both eCore and protocol rdma driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"rdma_common.h"
end_include

begin_comment
comment|/************************/
end_comment

begin_comment
comment|/* ROCE FW CONSTANTS */
end_comment

begin_comment
comment|/************************/
end_comment

begin_define
define|#
directive|define
name|ROCE_REQ_MAX_INLINE_DATA_SIZE
value|(256)
end_define

begin_comment
comment|//max size of inline data in single request
end_comment

begin_define
define|#
directive|define
name|ROCE_REQ_MAX_SINGLE_SQ_WQE_SIZE
value|(288)
end_define

begin_comment
comment|//Maximum size of single SQ WQE (rdma wqe and inline data)
end_comment

begin_define
define|#
directive|define
name|ROCE_MAX_QPS
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|ROCE_DCQCN_NP_MAX_QPS
value|(64)
end_define

begin_comment
comment|/* notification point max QPs*/
end_comment

begin_define
define|#
directive|define
name|ROCE_DCQCN_RP_MAX_QPS
value|(64)
end_define

begin_comment
comment|/* reaction point max QPs*/
end_comment

begin_comment
comment|/*  * Affiliated asynchronous events / errors enumeration  */
end_comment

begin_enum
enum|enum
name|roce_async_events_type
block|{
name|ROCE_ASYNC_EVENT_NONE
init|=
literal|0
block|,
name|ROCE_ASYNC_EVENT_COMM_EST
init|=
literal|1
block|,
name|ROCE_ASYNC_EVENT_SQ_DRAINED
block|,
name|ROCE_ASYNC_EVENT_SRQ_LIMIT
block|,
name|ROCE_ASYNC_EVENT_LAST_WQE_REACHED
block|,
name|ROCE_ASYNC_EVENT_CQ_ERR
block|,
name|ROCE_ASYNC_EVENT_LOCAL_INVALID_REQUEST_ERR
block|,
name|ROCE_ASYNC_EVENT_LOCAL_CATASTROPHIC_ERR
block|,
name|ROCE_ASYNC_EVENT_LOCAL_ACCESS_ERR
block|,
name|ROCE_ASYNC_EVENT_QP_CATASTROPHIC_ERR
block|,
name|ROCE_ASYNC_EVENT_CQ_OVERFLOW_ERR
block|,
name|ROCE_ASYNC_EVENT_SRQ_EMPTY
block|,
name|ROCE_ASYNC_EVENT_DESTROY_QP_DONE
block|,
name|MAX_ROCE_ASYNC_EVENTS_TYPE
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ROCE_COMMON__ */
end_comment

end_unit

