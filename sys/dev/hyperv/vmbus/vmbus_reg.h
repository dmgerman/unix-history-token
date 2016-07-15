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

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv.h>
end_include

begin_comment
comment|/* XXX for hyperv_guid */
end_comment

begin_include
include|#
directive|include
file|<dev/hyperv/include/vmbus.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/vmbus/hyperv_reg.h>
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
comment|/*  * Hyper-V Monitor Notification Facility  */
end_comment

begin_struct
struct|struct
name|vmbus_mon_trig
block|{
name|uint32_t
name|mt_pending
decl_stmt|;
name|uint32_t
name|mt_armed
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_MONTRIGS_MAX
value|4
end_define

begin_define
define|#
directive|define
name|VMBUS_MONTRIG_LEN
value|32
end_define

begin_struct
struct|struct
name|vmbus_mnf
block|{
name|uint32_t
name|mnf_state
decl_stmt|;
name|uint32_t
name|mnf_rsvd1
decl_stmt|;
name|struct
name|vmbus_mon_trig
name|mnf_trigs
index|[
name|VMBUS_MONTRIGS_MAX
index|]
decl_stmt|;
name|uint8_t
name|mnf_rsvd2
index|[
literal|536
index|]
decl_stmt|;
name|uint16_t
name|mnf_lat
index|[
name|VMBUS_MONTRIGS_MAX
index|]
index|[
name|VMBUS_MONTRIG_LEN
index|]
decl_stmt|;
name|uint8_t
name|mnf_rsvd3
index|[
literal|256
index|]
decl_stmt|;
name|struct
name|hyperv_mon_param
name|mnf_param
index|[
name|VMBUS_MONTRIGS_MAX
index|]
index|[
name|VMBUS_MONTRIG_LEN
index|]
decl_stmt|;
name|uint8_t
name|mnf_rsvd4
index|[
literal|1984
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
name|vmbus_mnf
argument_list|)
operator|==
name|PAGE_SIZE
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
comment|/*  * Channel packets  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_SIZE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_SIZE_ALIGN
value|(1<< VMBUS_CHANPKT_SIZE_SHIFT)
end_define

begin_struct
struct|struct
name|vmbus_chanpkt_hdr
block|{
name|uint16_t
name|cph_type
decl_stmt|;
name|uint16_t
name|cph_data_ofs
decl_stmt|;
comment|/* in 8 bytes */
name|uint16_t
name|cph_len
decl_stmt|;
comment|/* in 8 bytes */
name|uint16_t
name|cph_flags
decl_stmt|;
name|uint64_t
name|cph_xactid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_chanpkt
block|{
name|struct
name|vmbus_chanpkt_hdr
name|cp_hdr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_chanpkt_sglist
block|{
name|struct
name|vmbus_chanpkt_hdr
name|cp_hdr
decl_stmt|;
name|uint32_t
name|cp_rsvd
decl_stmt|;
name|uint32_t
name|cp_gpa_cnt
decl_stmt|;
name|struct
name|vmbus_gpa
name|cp_gpa
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_chanpkt_prplist
block|{
name|struct
name|vmbus_chanpkt_hdr
name|cp_hdr
decl_stmt|;
name|uint32_t
name|cp_rsvd
decl_stmt|;
name|uint32_t
name|cp_range_cnt
decl_stmt|;
name|struct
name|vmbus_gpa_range
name|cp_range
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Channel messages  * - Embedded in vmbus_message.msg_data, e.g. response and notification.  * - Embedded in hypercall_postmsg_in.hc_data, e.g. request.  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHOFFER
value|1
end_define

begin_comment
comment|/* NOTE */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHRESCIND
value|2
end_define

begin_comment
comment|/* NOTE */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHREQUEST
value|3
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHOFFER_DONE
value|4
end_define

begin_comment
comment|/* NOTE */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHOPEN
value|5
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHOPEN_RESP
value|6
end_define

begin_comment
comment|/* RESP */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHCLOSE
value|7
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_GPADL_CONN
value|8
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_GPADL_SUBCONN
value|9
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_GPADL_CONNRESP
value|10
end_define

begin_comment
comment|/* RESP */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_GPADL_DISCONN
value|11
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_GPADL_DISCONNRESP
value|12
end_define

begin_comment
comment|/* RESP */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CHFREE
value|13
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CONNECT
value|14
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_CONNECT_RESP
value|15
end_define

begin_comment
comment|/* RESP */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_DISCONNECT
value|16
end_define

begin_comment
comment|/* REQ */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_TYPE_MAX
value|22
end_define

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
comment|/* VMBUS_CHANMSG_TYPE_CONNECT */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_connect
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
comment|/* VMBUS_CHANMSG_TYPE_CONNECT_RESP */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_connect_resp
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint8_t
name|chm_done
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHREQUEST */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chrequest
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_DISCONNECT */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_disconnect
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHOPEN */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chopen
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint32_t
name|chm_openid
decl_stmt|;
name|uint32_t
name|chm_gpadl
decl_stmt|;
name|uint32_t
name|chm_vcpuid
decl_stmt|;
name|uint32_t
name|chm_rxbr_pgofs
decl_stmt|;
define|#
directive|define
name|VMBUS_CHANMSG_CHOPEN_UDATA_SIZE
value|120
name|uint8_t
name|chm_udata
index|[
name|VMBUS_CHANMSG_CHOPEN_UDATA_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHOPEN_RESP */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chopen_resp
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint32_t
name|chm_openid
decl_stmt|;
name|uint32_t
name|chm_status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_GPADL_CONN */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_gpadl_conn
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint32_t
name|chm_gpadl
decl_stmt|;
name|uint16_t
name|chm_range_len
decl_stmt|;
name|uint16_t
name|chm_range_cnt
decl_stmt|;
name|struct
name|vmbus_gpa_range
name|chm_range
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_GPADL_CONN_PGMAX
value|26
end_define

begin_expr_stmt
name|CTASSERT
argument_list|(
name|__offsetof
argument_list|(
expr|struct
name|vmbus_chanmsg_gpadl_conn
argument_list|,
name|chm_range
operator|.
name|gpa_page
index|[
name|VMBUS_CHANMSG_GPADL_CONN_PGMAX
index|]
argument_list|)
operator|<=
name|HYPERCALL_POSTMSGIN_DSIZE_MAX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_GPADL_SUBCONN */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_gpadl_subconn
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_msgno
decl_stmt|;
name|uint32_t
name|chm_gpadl
decl_stmt|;
name|uint64_t
name|chm_gpa_page
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VMBUS_CHANMSG_GPADL_SUBCONN_PGMAX
value|28
end_define

begin_expr_stmt
name|CTASSERT
argument_list|(
name|__offsetof
argument_list|(
expr|struct
name|vmbus_chanmsg_gpadl_subconn
argument_list|,
name|chm_gpa_page
index|[
name|VMBUS_CHANMSG_GPADL_SUBCONN_PGMAX
index|]
argument_list|)
operator|<=
name|HYPERCALL_POSTMSGIN_DSIZE_MAX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_GPADL_CONNRESP */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_gpadl_connresp
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint32_t
name|chm_gpadl
decl_stmt|;
name|uint32_t
name|chm_status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHCLOSE */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chclose
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_GPADL_DISCONN */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_gpadl_disconn
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint32_t
name|chm_gpadl
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHFREE */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chfree
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHRESCIND */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_chrescind
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* VMBUS_CHANMSG_TYPE_CHOFFER */
end_comment

begin_struct
struct|struct
name|vmbus_chanmsg_choffer
block|{
name|struct
name|vmbus_chanmsg_hdr
name|chm_hdr
decl_stmt|;
name|struct
name|hyperv_guid
name|chm_chtype
decl_stmt|;
name|struct
name|hyperv_guid
name|chm_chinst
decl_stmt|;
name|uint64_t
name|chm_chlat
decl_stmt|;
comment|/* unit: 100ns */
name|uint32_t
name|chm_chrev
decl_stmt|;
name|uint32_t
name|chm_svrctx_sz
decl_stmt|;
name|uint16_t
name|chm_chflags
decl_stmt|;
name|uint16_t
name|chm_mmio_sz
decl_stmt|;
comment|/* unit: MB */
name|uint8_t
name|chm_udata
index|[
literal|120
index|]
decl_stmt|;
name|uint16_t
name|chm_subidx
decl_stmt|;
name|uint16_t
name|chm_rsvd
decl_stmt|;
name|uint32_t
name|chm_chanid
decl_stmt|;
name|uint8_t
name|chm_montrig
decl_stmt|;
name|uint8_t
name|chm_flags1
decl_stmt|;
comment|/* VMBUS_CHOFFER_FLAG1_ */
name|uint16_t
name|chm_flags2
decl_stmt|;
name|uint32_t
name|chm_connid
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
name|vmbus_chanmsg_choffer
argument_list|)
operator|<=
name|VMBUS_MSG_DSIZE_MAX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VMBUS_CHOFFER_FLAG1_HASMNF
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_REG_H_ */
end_comment

end_unit

