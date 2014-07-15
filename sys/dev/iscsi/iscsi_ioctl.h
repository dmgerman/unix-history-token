begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCSI_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|ISCSI_IOCTL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISCSI_PATH
value|"/dev/iscsi"
end_define

begin_define
define|#
directive|define
name|ISCSI_MAX_DATA_SEGMENT_LENGTH
value|(128 * 1024)
end_define

begin_define
define|#
directive|define
name|ISCSI_NAME_LEN
value|224
end_define

begin_comment
comment|/* 223 bytes, by RFC 3720, + '\0' */
end_comment

begin_define
define|#
directive|define
name|ISCSI_ADDR_LEN
value|47
end_define

begin_comment
comment|/* INET6_ADDRSTRLEN + '\0' */
end_comment

begin_define
define|#
directive|define
name|ISCSI_ALIAS_LEN
value|256
end_define

begin_comment
comment|/* XXX: Where did it come from? */
end_comment

begin_define
define|#
directive|define
name|ISCSI_SECRET_LEN
value|17
end_define

begin_comment
comment|/* 16 + '\0' */
end_comment

begin_define
define|#
directive|define
name|ISCSI_REASON_LEN
value|64
end_define

begin_define
define|#
directive|define
name|ISCSI_DIGEST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ISCSI_DIGEST_CRC32C
value|1
end_define

begin_comment
comment|/*  * Session configuration, set when adding the session.  */
end_comment

begin_struct
struct|struct
name|iscsi_session_conf
block|{
name|char
name|isc_initiator
index|[
name|ISCSI_NAME_LEN
index|]
decl_stmt|;
name|char
name|isc_initiator_addr
index|[
name|ISCSI_ADDR_LEN
index|]
decl_stmt|;
name|char
name|isc_initiator_alias
index|[
name|ISCSI_ALIAS_LEN
index|]
decl_stmt|;
name|char
name|isc_target
index|[
name|ISCSI_NAME_LEN
index|]
decl_stmt|;
name|char
name|isc_target_addr
index|[
name|ISCSI_ADDR_LEN
index|]
decl_stmt|;
name|char
name|isc_user
index|[
name|ISCSI_NAME_LEN
index|]
decl_stmt|;
name|char
name|isc_secret
index|[
name|ISCSI_SECRET_LEN
index|]
decl_stmt|;
name|char
name|isc_mutual_user
index|[
name|ISCSI_NAME_LEN
index|]
decl_stmt|;
name|char
name|isc_mutual_secret
index|[
name|ISCSI_SECRET_LEN
index|]
decl_stmt|;
name|int
name|isc_discovery
decl_stmt|;
name|int
name|isc_header_digest
decl_stmt|;
name|int
name|isc_data_digest
decl_stmt|;
name|int
name|isc_iser
decl_stmt|;
name|int
name|isc_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Session state, negotiated by iscsid(8) and queried by iscsictl(8).  */
end_comment

begin_struct
struct|struct
name|iscsi_session_state
block|{
name|struct
name|iscsi_session_conf
name|iss_conf
decl_stmt|;
name|unsigned
name|int
name|iss_id
decl_stmt|;
name|char
name|iss_target_alias
index|[
name|ISCSI_ALIAS_LEN
index|]
decl_stmt|;
name|int
name|iss_header_digest
decl_stmt|;
name|int
name|iss_data_digest
decl_stmt|;
name|int
name|iss_max_data_segment_length
decl_stmt|;
name|int
name|iss_immediate_data
decl_stmt|;
name|int
name|iss_connected
decl_stmt|;
name|char
name|iss_reason
index|[
name|ISCSI_REASON_LEN
index|]
decl_stmt|;
name|int
name|iss_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * For use with iscsid(8).  */
end_comment

begin_struct
struct|struct
name|iscsi_daemon_request
block|{
name|unsigned
name|int
name|idr_session_id
decl_stmt|;
name|struct
name|iscsi_session_conf
name|idr_conf
decl_stmt|;
name|uint8_t
name|idr_isid
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|idr_tsih
decl_stmt|;
name|uint16_t
name|idr_spare_cid
decl_stmt|;
name|int
name|idr_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_daemon_handoff
block|{
name|unsigned
name|int
name|idh_session_id
decl_stmt|;
name|int
name|idh_socket
decl_stmt|;
name|char
name|idh_target_alias
index|[
name|ISCSI_ALIAS_LEN
index|]
decl_stmt|;
name|uint8_t
name|idh_spare_isid
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|idh_tsih
decl_stmt|;
name|uint16_t
name|idh_spare_cid
decl_stmt|;
name|uint32_t
name|idh_statsn
decl_stmt|;
name|int
name|idh_header_digest
decl_stmt|;
name|int
name|idh_data_digest
decl_stmt|;
name|int
name|idh_initial_r2t
decl_stmt|;
name|int
name|idh_immediate_data
decl_stmt|;
name|size_t
name|idh_max_data_segment_length
decl_stmt|;
name|size_t
name|idh_max_burst_length
decl_stmt|;
name|size_t
name|idh_first_burst_length
decl_stmt|;
name|int
name|idh_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_daemon_fail
block|{
name|unsigned
name|int
name|idf_session_id
decl_stmt|;
name|char
name|idf_reason
index|[
name|ISCSI_REASON_LEN
index|]
decl_stmt|;
name|int
name|idf_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCSIDWAIT
value|_IOR('I', 0x01, struct iscsi_daemon_request)
end_define

begin_define
define|#
directive|define
name|ISCSIDHANDOFF
value|_IOW('I', 0x02, struct iscsi_daemon_handoff)
end_define

begin_define
define|#
directive|define
name|ISCSIDFAIL
value|_IOW('I', 0x03, struct iscsi_daemon_fail)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ICL_KERNEL_PROXY
end_ifdef

begin_comment
comment|/*  * When ICL_KERNEL_PROXY is not defined, the iscsid(8) is responsible  * for creating the socket, connecting, and performing Login Phase using  * the socket in the usual userspace way, and then passing the socket  * file descriptor to the kernel part using ISCSIDHANDOFF.  *  * When ICL_KERNEL_PROXY is defined, the iscsid(8) creates the session  * using ISCSICONNECT, performs Login Phase using ISCSISEND/ISCSIRECEIVE  * instead of read(2)/write(2), and then calls ISCSIDHANDOFF with  * idh_socket set to 0.  *  * The purpose of ICL_KERNEL_PROXY is to workaround the fact that,  * at this time, it's not possible to do iWARP (RDMA) in userspace.  */
end_comment

begin_struct
struct|struct
name|iscsi_daemon_connect
block|{
name|int
name|idc_session_id
decl_stmt|;
name|int
name|idc_iser
decl_stmt|;
name|int
name|idc_domain
decl_stmt|;
name|int
name|idc_socktype
decl_stmt|;
name|int
name|idc_protocol
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|idc_from_addr
decl_stmt|;
name|socklen_t
name|idc_from_addrlen
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|idc_to_addr
decl_stmt|;
name|socklen_t
name|idc_to_addrlen
decl_stmt|;
name|int
name|idc_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_daemon_send
block|{
name|int
name|ids_session_id
decl_stmt|;
name|void
modifier|*
name|ids_bhs
decl_stmt|;
name|size_t
name|ids_spare
decl_stmt|;
name|void
modifier|*
name|ids_spare2
decl_stmt|;
name|size_t
name|ids_data_segment_len
decl_stmt|;
name|void
modifier|*
name|ids_data_segment
decl_stmt|;
name|int
name|ids_spare3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_daemon_receive
block|{
name|int
name|idr_session_id
decl_stmt|;
name|void
modifier|*
name|idr_bhs
decl_stmt|;
name|size_t
name|idr_spare
decl_stmt|;
name|void
modifier|*
name|idr_spare2
decl_stmt|;
name|size_t
name|idr_data_segment_len
decl_stmt|;
name|void
modifier|*
name|idr_data_segment
decl_stmt|;
name|int
name|idr_spare3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCSIDCONNECT
value|_IOWR('I', 0x04, struct iscsi_daemon_connect)
end_define

begin_define
define|#
directive|define
name|ISCSIDSEND
value|_IOWR('I', 0x05, struct iscsi_daemon_send)
end_define

begin_define
define|#
directive|define
name|ISCSIDRECEIVE
value|_IOWR('I', 0x06, struct iscsi_daemon_receive)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ICL_KERNEL_PROXY */
end_comment

begin_comment
comment|/*  * For use with iscsictl(8).  */
end_comment

begin_struct
struct|struct
name|iscsi_session_add
block|{
name|struct
name|iscsi_session_conf
name|isa_conf
decl_stmt|;
name|int
name|isa_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_session_remove
block|{
name|unsigned
name|int
name|isr_session_id
decl_stmt|;
name|struct
name|iscsi_session_conf
name|isr_conf
decl_stmt|;
name|int
name|isr_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_session_list
block|{
name|unsigned
name|int
name|isl_nentries
decl_stmt|;
name|struct
name|iscsi_session_state
modifier|*
name|isl_pstates
decl_stmt|;
name|int
name|isl_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCSISADD
value|_IOW('I', 0x11, struct iscsi_session_add)
end_define

begin_define
define|#
directive|define
name|ISCSISREMOVE
value|_IOW('I', 0x12, struct iscsi_session_remove)
end_define

begin_define
define|#
directive|define
name|ISCSISLIST
value|_IOWR('I', 0x13, struct iscsi_session_list)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ISCSI_IOCTL_H */
end_comment

end_unit

