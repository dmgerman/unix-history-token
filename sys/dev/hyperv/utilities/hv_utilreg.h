begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HV_UTILREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_HV_UTILREG_H_
end_define

begin_define
define|#
directive|define
name|HV_S_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HV_E_FAIL
value|0x80004005
end_define

begin_define
define|#
directive|define
name|HV_ERROR_NOT_SUPPORTED
value|0x80070032
end_define

begin_define
define|#
directive|define
name|HV_ERROR_MACHINE_LOCKED
value|0x800704F7
end_define

begin_comment
comment|/*  * Common defines for Hyper-V ICs  */
end_comment

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_NEGOTIATE
value|0
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_HEARTBEAT
value|1
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_KVPEXCHANGE
value|2
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_SHUTDOWN
value|3
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_TIMESYNC
value|4
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_VSS
value|5
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_TRANSACTION
value|1
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_REQUEST
value|2
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_RESPONSE
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_pipe_hdr
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|msgsize
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_pipe_hdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_ic_version
block|{
name|uint16_t
name|major
decl_stmt|;
name|uint16_t
name|minor
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_ic_version
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_icmsg_hdr
block|{
name|hv_vmbus_ic_version
name|icverframe
decl_stmt|;
name|uint16_t
name|icmsgtype
decl_stmt|;
name|hv_vmbus_ic_version
name|icvermsg
decl_stmt|;
name|uint16_t
name|icmsgsize
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|uint8_t
name|ictransaction_id
decl_stmt|;
name|uint8_t
name|icflags
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_icmsg_hdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_icmsg_negotiate
block|{
name|uint16_t
name|icframe_vercnt
decl_stmt|;
name|uint16_t
name|icmsg_vercnt
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|hv_vmbus_ic_version
name|icversion_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* any size array */
block|}
name|__packed
name|hv_vmbus_icmsg_negotiate
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_shutdown_msg_data
block|{
name|uint32_t
name|reason_code
decl_stmt|;
name|uint32_t
name|timeout_seconds
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint8_t
name|display_message
index|[
literal|2048
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_shutdown_msg_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_heartbeat_msg_data
block|{
name|uint64_t
name|seq_num
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_heartbeat_msg_data
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HV_UTILREG_H_ */
end_comment

end_unit

