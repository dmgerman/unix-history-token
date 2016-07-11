begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_REG_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * Hyper-V SynIC message format.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_MSG_DSIZE_MAX
value|240
end_define

begin_define
define|#
directive|define
name|VMBUS_MSG_SIZE
value|256
end_define

begin_struct
struct|struct
name|vmbus_message
block|{
name|uint32_t
name|msg_type
decl_stmt|;
comment|/* HYPERV_MSGTYPE_ */
name|uint8_t
name|msg_dsize
decl_stmt|;
comment|/* data size */
name|uint8_t
name|msg_flags
decl_stmt|;
comment|/* VMBUS_MSGFLAG_ */
name|uint16_t
name|msg_rsvd
decl_stmt|;
name|uint64_t
name|msg_id
decl_stmt|;
name|uint8_t
name|msg_data
index|[
name|VMBUS_MSG_DSIZE_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmbus_message
argument_list|)
operator|==
name|VMBUS_MSG_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VMBUS_MSGFLAG_PENDING
value|0x01
end_define

begin_comment
comment|/*  * Hyper-V SynIC event flags  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|VMBUS_EVTFLAGS_MAX
value|32
end_define

begin_define
define|#
directive|define
name|VMBUS_EVTFLAG_SHIFT
value|6
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VMBUS_EVTFLAGS_MAX
value|64
end_define

begin_define
define|#
directive|define
name|VMBUS_EVTFLAG_SHIFT
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VMBUS_EVTFLAG_LEN
value|(1<< VMBUS_EVTFLAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|VMBUS_EVTFLAG_MASK
value|(VMBUS_EVTFLAG_LEN - 1)
end_define

begin_define
define|#
directive|define
name|VMBUS_EVTFLAGS_SIZE
value|256
end_define

begin_struct
struct|struct
name|vmbus_evtflags
block|{
name|u_long
name|evt_flags
index|[
name|VMBUS_EVTFLAGS_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmbus_evtflags
argument_list|)
operator|==
name|VMBUS_EVTFLAGS_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Channel  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHAN_MAX_COMPAT
value|256
end_define

begin_define
define|#
directive|define
name|VMBUS_CHAN_MAX
value|(VMBUS_EVTFLAG_LEN * VMBUS_EVTFLAGS_MAX)
end_define

begin_comment
comment|/*  * Channel messages  * - Embedded in vmbus_message.msg_data, e.g. response.  * - Embedded in hypercall_postmsg_in.hc_data, e.g. request.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_INIT_CONTACT
value|14
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_VERSION_RESP
value|15
end_define

begin_comment
comment|/* RESP */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_hdr
block|{
name|uint32_t
name|chm_type
decl_stmt|;
comment|/* VMBUS_CHANMSG_TYPE_ */
name|uint32_t
name|chm_rsvd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_INIT_CONTACT */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_init_contact
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_ver
decl_stmt|;
name|uint32_t
name|chm_rsvd
decl_stmt|;
name|uint64_t
name|chm_evtflags
decl_stmt|;
name|uint64_t
name|chm_mnf1
decl_stmt|;
name|uint64_t
name|chm_mnf2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_VERSION_RESP */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_version_resp
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint8_t
name|chm_supp
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_REG_H_ */
end_comment

end_unit

