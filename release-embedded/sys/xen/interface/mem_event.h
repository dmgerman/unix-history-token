begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * mem_event.h  *  * Memory event common structures.  *  * Copyright (c) 2009 by Citrix Systems, Inc. (Patrick Colp)  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_PUBLIC_MEM_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_PUBLIC_MEM_EVENT_H
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_include
include|#
directive|include
file|"io/ring.h"
end_include

begin_comment
comment|/* Memory event flags */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_FLAG_VCPU_PAUSED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MEM_EVENT_FLAG_DROP_PAGE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MEM_EVENT_FLAG_EVICT_FAIL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MEM_EVENT_FLAG_FOREIGN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MEM_EVENT_FLAG_DUMMY
value|(1<< 4)
end_define

begin_comment
comment|/* Reasons for the memory event request */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_UNKNOWN
value|0
end_define

begin_comment
comment|/* typical reason */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_VIOLATION
value|1
end_define

begin_comment
comment|/* access violation, GFN is address */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_CR0
value|2
end_define

begin_comment
comment|/* CR0 was hit: gfn is CR0 value */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_CR3
value|3
end_define

begin_comment
comment|/* CR3 was hit: gfn is CR3 value */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_CR4
value|4
end_define

begin_comment
comment|/* CR4 was hit: gfn is CR4 value */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_INT3
value|5
end_define

begin_comment
comment|/* int3 was hit: gla/gfn are RIP */
end_comment

begin_define
define|#
directive|define
name|MEM_EVENT_REASON_SINGLESTEP
value|6
end_define

begin_comment
comment|/* single step was invoked: gla/gfn are RIP */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mem_event_st
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|vcpu_id
decl_stmt|;
name|uint64_t
name|gfn
decl_stmt|;
name|uint64_t
name|offset
decl_stmt|;
name|uint64_t
name|gla
decl_stmt|;
comment|/* if gla_valid */
name|uint32_t
name|p2mt
decl_stmt|;
name|uint16_t
name|access_r
range|:
literal|1
decl_stmt|;
name|uint16_t
name|access_w
range|:
literal|1
decl_stmt|;
name|uint16_t
name|access_x
range|:
literal|1
decl_stmt|;
name|uint16_t
name|gla_valid
range|:
literal|1
decl_stmt|;
name|uint16_t
name|available
range|:
literal|12
decl_stmt|;
name|uint16_t
name|reason
decl_stmt|;
block|}
name|mem_event_request_t
operator|,
name|mem_event_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|mem_event
argument_list|,
name|mem_event_request_t
argument_list|,
name|mem_event_response_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

