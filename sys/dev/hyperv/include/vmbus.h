begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * GPA stuffs.  */
end_comment

begin_struct
struct|struct
name|vmbus_gpa_range
block|{
name|uint32_t
name|gpa_len
decl_stmt|;
name|uint32_t
name|gpa_ofs
decl_stmt|;
name|uint64_t
name|gpa_page
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* This is actually vmbus_gpa_range.gpa_page[1] */
end_comment

begin_struct
struct|struct
name|vmbus_gpa
block|{
name|uint32_t
name|gpa_len
decl_stmt|;
name|uint32_t
name|gpa_ofs
decl_stmt|;
name|uint64_t
name|gpa_page
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_TYPE_INBAND
value|0x0006
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_TYPE_RXBUF
value|0x0007
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_TYPE_GPA
value|0x0009
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_TYPE_COMP
value|0x000b
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_FLAG_RC
value|0x0001
end_define

begin_comment
comment|/* report completion */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHAN_SGLIST_MAX
value|32
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_PRPLIST_MAX
value|32
end_define

begin_struct_decl
struct_decl|struct
name|hv_vmbus_channel
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|vmbus_chan_send
parameter_list|(
name|struct
name|hv_vmbus_channel
modifier|*
name|chan
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
name|uint64_t
name|xactid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_send_sglist
parameter_list|(
name|struct
name|hv_vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|vmbus_gpa
name|sg
index|[]
parameter_list|,
name|int
name|sglen
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
name|uint64_t
name|xactid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_send_prplist
parameter_list|(
name|struct
name|hv_vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|vmbus_gpa_range
modifier|*
name|prp
parameter_list|,
name|int
name|prp_cnt
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
name|uint64_t
name|xactid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_H_ */
end_comment

end_unit

