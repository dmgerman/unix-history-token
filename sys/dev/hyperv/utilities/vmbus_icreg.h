begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_ICREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_ICREG_H_
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_NEGOTIATE
value|0
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_HEARTBEAT
value|1
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_KVP
value|2
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_SHUTDOWN
value|3
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_TIMESYNC
value|4
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TYPE_VSS
value|5
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_STATUS_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_STATUS_FAIL
value|0x80004005
end_define

begin_define
define|#
directive|define
name|VMBUS_IC_VERSION
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|((major) | (((uint32_t)(minor))<< 16))
end_define

begin_define
define|#
directive|define
name|VMBUS_ICVER_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|((ver)& 0xffff)
end_define

begin_define
define|#
directive|define
name|VMBUS_ICVER_MINOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|VMBUS_ICVER_SWAP
parameter_list|(
name|ver
parameter_list|)
define|\
value|((VMBUS_ICVER_MAJOR((ver))<< 16) | VMBUS_ICVER_MINOR((ver)))
end_define

begin_define
define|#
directive|define
name|VMBUS_ICVER_LE
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|(VMBUS_ICVER_SWAP((v1))<= VMBUS_ICVER_SWAP((v2)))
end_define

begin_define
define|#
directive|define
name|VMBUS_ICVER_GT
parameter_list|(
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|(VMBUS_ICVER_SWAP((v1))> VMBUS_ICVER_SWAP((v2)))
end_define

begin_struct
struct|struct
name|vmbus_pipe_hdr
block|{
name|uint32_t
name|ph_flags
decl_stmt|;
name|uint32_t
name|ph_msgsz
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_icmsg_hdr
block|{
name|struct
name|vmbus_pipe_hdr
name|ic_pipe
decl_stmt|;
name|uint32_t
name|ic_fwver
decl_stmt|;
comment|/* framework version */
name|uint16_t
name|ic_type
decl_stmt|;
name|uint32_t
name|ic_msgver
decl_stmt|;
comment|/* message version */
name|uint16_t
name|ic_dsize
decl_stmt|;
comment|/* data size */
name|uint32_t
name|ic_status
decl_stmt|;
comment|/* VMBUS_ICMSG_STATUS_ */
name|uint8_t
name|ic_xactid
decl_stmt|;
name|uint8_t
name|ic_flags
decl_stmt|;
comment|/* VMBUS_ICMSG_FLAG_ */
name|uint8_t
name|ic_rsvd
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_ICMSG_FLAG_XACT
value|0x0001
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_FLAG_REQ
value|0x0002
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_FLAG_RESP
value|0x0004
end_define

begin_comment
comment|/* VMBUS_ICMSG_TYPE_NEGOTIATE */
end_comment

begin_struct
struct|struct
name|vmbus_icmsg_negotiate
block|{
name|struct
name|vmbus_icmsg_hdr
name|ic_hdr
decl_stmt|;
name|uint16_t
name|ic_fwver_cnt
decl_stmt|;
name|uint16_t
name|ic_msgver_cnt
decl_stmt|;
name|uint32_t
name|ic_rsvd
decl_stmt|;
comment|/* 	 * This version array contains two set of supported 	 * versions: 	 * - The first set consists of #ic_fwver_cnt supported framework 	 *   versions. 	 * - The second set consists of #ic_msgver_cnt supported message 	 *   versions. 	 */
name|uint32_t
name|ic_ver
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_ICMSG_TYPE_HEARTBEAT */
end_comment

begin_struct
struct|struct
name|vmbus_icmsg_heartbeat
block|{
name|struct
name|vmbus_icmsg_hdr
name|ic_hdr
decl_stmt|;
name|uint64_t
name|ic_seq
decl_stmt|;
name|uint32_t
name|ic_rsvd
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_ICMSG_HEARTBEAT_SIZE_MIN
define|\
value|__offsetof(struct vmbus_icmsg_heartbeat, ic_rsvd[0])
end_define

begin_comment
comment|/* VMBUS_ICMSG_TYPE_SHUTDOWN */
end_comment

begin_struct
struct|struct
name|vmbus_icmsg_shutdown
block|{
name|struct
name|vmbus_icmsg_hdr
name|ic_hdr
decl_stmt|;
name|uint32_t
name|ic_code
decl_stmt|;
name|uint32_t
name|ic_timeo
decl_stmt|;
name|uint32_t
name|ic_haltflags
decl_stmt|;
name|uint8_t
name|ic_msg
index|[
literal|2048
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_ICMSG_SHUTDOWN_SIZE_MIN
define|\
value|__offsetof(struct vmbus_icmsg_shutdown, ic_msg[0])
end_define

begin_comment
comment|/* VMBUS_ICMSG_TYPE_TIMESYNC */
end_comment

begin_struct
struct|struct
name|vmbus_icmsg_timesync
block|{
name|struct
name|vmbus_icmsg_hdr
name|ic_hdr
decl_stmt|;
name|uint64_t
name|ic_hvtime
decl_stmt|;
name|uint64_t
name|ic_vmtime
decl_stmt|;
name|uint64_t
name|ic_rtt
decl_stmt|;
name|uint8_t
name|ic_tsflags
decl_stmt|;
comment|/* VMBUS_ICMSG_TS_FLAG_ */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TS_FLAG_SYNC
value|0x01
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TS_FLAG_SAMPLE
value|0x02
end_define

begin_comment
comment|/* XXX consolidate w/ hyperv */
end_comment

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TS_BASE
value|116444736000000000ULL
end_define

begin_define
define|#
directive|define
name|VMBUS_ICMSG_TS_FACTOR
value|100ULL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NANOSEC
end_ifndef

begin_define
define|#
directive|define
name|NANOSEC
value|1000000000ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_ICREG_H_ */
end_comment

end_unit

