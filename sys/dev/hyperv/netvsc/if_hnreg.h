begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_HNREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_HNREG_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/*  * NDIS protocol version numbers  */
end_comment

begin_define
define|#
directive|define
name|HN_NDIS_VERSION_6_1
value|0x00060001
end_define

begin_define
define|#
directive|define
name|HN_NDIS_VERSION_6_20
value|0x00060014
end_define

begin_define
define|#
directive|define
name|HN_NDIS_VERSION_6_30
value|0x0006001e
end_define

begin_define
define|#
directive|define
name|HN_NDIS_VERSION_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|HN_NDIS_VERSION_MINOR
parameter_list|(
name|ver
parameter_list|)
value|((ver)& 0xffff)
end_define

begin_comment
comment|/*  * NVS versions.  */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_VERSION_1
value|0x00002
end_define

begin_define
define|#
directive|define
name|HN_NVS_VERSION_2
value|0x30002
end_define

begin_define
define|#
directive|define
name|HN_NVS_VERSION_4
value|0x40000
end_define

begin_define
define|#
directive|define
name|HN_NVS_VERSION_5
value|0x50000
end_define

begin_define
define|#
directive|define
name|HN_NVS_RXBUF_SIG
value|0xcafe
end_define

begin_define
define|#
directive|define
name|HN_NVS_CHIM_SIG
value|0xface
end_define

begin_define
define|#
directive|define
name|HN_NVS_CHIM_IDX_INVALID
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|HN_NVS_RNDIS_MTYPE_DATA
value|0
end_define

begin_define
define|#
directive|define
name|HN_NVS_RNDIS_MTYPE_CTRL
value|1
end_define

begin_comment
comment|/*  * NVS message transacion status codes.  */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_STATUS_OK
value|1
end_define

begin_define
define|#
directive|define
name|HN_NVS_STATUS_FAILED
value|2
end_define

begin_comment
comment|/*  * NVS request/response message types.  */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_TYPE_INIT
value|1
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_INIT_RESP
value|2
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_NDIS_INIT
value|100
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_RXBUF_CONN
value|101
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_RXBUF_CONNRESP
value|102
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_RXBUF_DISCONN
value|103
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_CHIM_CONN
value|104
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_CHIM_CONNRESP
value|105
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_CHIM_DISCONN
value|106
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_RNDIS
value|107
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_RNDIS_ACK
value|108
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_NDIS_CONF
value|125
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_VFASSOC_NOTE
value|128
end_define

begin_comment
comment|/* notification */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_TYPE_SET_DATAPATH
value|129
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_SUBCH_REQ
value|133
end_define

begin_define
define|#
directive|define
name|HN_NVS_TYPE_SUBCH_RESP
value|133
end_define

begin_comment
comment|/* same as SUBCH_REQ */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_TYPE_TXTBL_NOTE
value|134
end_define

begin_comment
comment|/* notification */
end_comment

begin_comment
comment|/*  * Any size less than this one will _not_ work, e.g. hn_nvs_init  * only has 12B valid data, however, if only 12B data were sent,  * Hypervisor would never reply.  */
end_comment

begin_define
define|#
directive|define
name|HN_NVS_REQSIZE_MIN
value|32
end_define

begin_comment
comment|/* NVS message common header */
end_comment

begin_struct
struct|struct
name|hn_nvs_hdr
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|hn_nvs_init
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_INIT */
name|uint32_t
name|nvs_ver_min
decl_stmt|;
name|uint32_t
name|nvs_ver_max
decl_stmt|;
name|uint8_t
name|nvs_rsvd
index|[
literal|20
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
name|hn_nvs_init
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_init_resp
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_INIT_RESP */
name|uint32_t
name|nvs_ver
decl_stmt|;
comment|/* deprecated */
name|uint32_t
name|nvs_rsvd
decl_stmt|;
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* No reponse */
end_comment

begin_struct
struct|struct
name|hn_nvs_ndis_conf
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_NDIS_CONF */
name|uint32_t
name|nvs_mtu
decl_stmt|;
name|uint32_t
name|nvs_rsvd
decl_stmt|;
name|uint64_t
name|nvs_caps
decl_stmt|;
comment|/* HN_NVS_NDIS_CONF_ */
name|uint8_t
name|nvs_rsvd1
index|[
literal|12
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
name|hn_nvs_ndis_conf
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HN_NVS_NDIS_CONF_SRIOV
value|0x0004
end_define

begin_define
define|#
directive|define
name|HN_NVS_NDIS_CONF_VLAN
value|0x0008
end_define

begin_comment
comment|/* No response */
end_comment

begin_struct
struct|struct
name|hn_nvs_ndis_init
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_NDIS_INIT */
name|uint32_t
name|nvs_ndis_major
decl_stmt|;
comment|/* NDIS_VERSION_MAJOR_ */
name|uint32_t
name|nvs_ndis_minor
decl_stmt|;
comment|/* NDIS_VERSION_MINOR_ */
name|uint8_t
name|nvs_rsvd
index|[
literal|20
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
name|hn_nvs_ndis_init
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HN_NVS_DATAPATH_SYNTH
value|0
end_define

begin_define
define|#
directive|define
name|HN_NVS_DATAPATH_VF
value|1
end_define

begin_comment
comment|/* No response */
end_comment

begin_struct
struct|struct
name|hn_nvs_datapath
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_SET_DATAPATH */
name|uint32_t
name|nvs_active_path
decl_stmt|;
comment|/* HN_NVS_DATAPATH_* */
name|uint32_t
name|nvs_rsvd
index|[
literal|6
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
name|hn_nvs_datapath
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_rxbuf_conn
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_RXBUF_CONN */
name|uint32_t
name|nvs_gpadl
decl_stmt|;
comment|/* RXBUF vmbus GPADL */
name|uint16_t
name|nvs_sig
decl_stmt|;
comment|/* HN_NVS_RXBUF_SIG */
name|uint8_t
name|nvs_rsvd
index|[
literal|22
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
name|hn_nvs_rxbuf_conn
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_rxbuf_sect
block|{
name|uint32_t
name|nvs_start
decl_stmt|;
name|uint32_t
name|nvs_slotsz
decl_stmt|;
name|uint32_t
name|nvs_slotcnt
decl_stmt|;
name|uint32_t
name|nvs_end
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|hn_nvs_rxbuf_connresp
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_RXBUF_CONNRESP */
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
name|uint32_t
name|nvs_nsect
decl_stmt|;
comment|/* # of elem in nvs_sect */
name|struct
name|hn_nvs_rxbuf_sect
name|nvs_sect
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* No response */
end_comment

begin_struct
struct|struct
name|hn_nvs_rxbuf_disconn
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_RXBUF_DISCONN */
name|uint16_t
name|nvs_sig
decl_stmt|;
comment|/* HN_NVS_RXBUF_SIG */
name|uint8_t
name|nvs_rsvd
index|[
literal|26
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
name|hn_nvs_rxbuf_disconn
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_chim_conn
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_CHIM_CONN */
name|uint32_t
name|nvs_gpadl
decl_stmt|;
comment|/* chimney buf vmbus GPADL */
name|uint16_t
name|nvs_sig
decl_stmt|;
comment|/* NDIS_NVS_CHIM_SIG */
name|uint8_t
name|nvs_rsvd
index|[
literal|22
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
name|hn_nvs_chim_conn
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_chim_connresp
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_CHIM_CONNRESP */
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
name|uint32_t
name|nvs_sectsz
decl_stmt|;
comment|/* section size */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* No response */
end_comment

begin_struct
struct|struct
name|hn_nvs_chim_disconn
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_CHIM_DISCONN */
name|uint16_t
name|nvs_sig
decl_stmt|;
comment|/* HN_NVS_CHIM_SIG */
name|uint8_t
name|nvs_rsvd
index|[
literal|26
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
name|hn_nvs_chim_disconn
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HN_NVS_SUBCH_OP_ALLOC
value|1
end_define

begin_struct
struct|struct
name|hn_nvs_subch_req
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_SUBCH_REQ */
name|uint32_t
name|nvs_op
decl_stmt|;
comment|/* HN_NVS_SUBCH_OP_ */
name|uint32_t
name|nvs_nsubch
decl_stmt|;
name|uint8_t
name|nvs_rsvd
index|[
literal|20
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
name|hn_nvs_subch_req
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_subch_resp
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_SUBCH_RESP */
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
name|uint32_t
name|nvs_nsubch
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|hn_nvs_rndis
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_RNDIS */
name|uint32_t
name|nvs_rndis_mtype
decl_stmt|;
comment|/* HN_NVS_RNDIS_MTYPE_ */
comment|/* 	 * Chimney sending buffer index and size. 	 * 	 * NOTE: 	 * If nvs_chim_idx is set to HN_NVS_CHIM_IDX_INVALID 	 * and nvs_chim_sz is set to 0, then chimney sending 	 * buffer is _not_ used by this RNDIS message. 	 */
name|uint32_t
name|nvs_chim_idx
decl_stmt|;
name|uint32_t
name|nvs_chim_sz
decl_stmt|;
name|uint8_t
name|nvs_rsvd
index|[
literal|16
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
name|hn_nvs_rndis
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hn_nvs_rndis_ack
block|{
name|uint32_t
name|nvs_type
decl_stmt|;
comment|/* HN_NVS_TYPE_RNDIS_ACK */
name|uint32_t
name|nvs_status
decl_stmt|;
comment|/* HN_NVS_STATUS_ */
name|uint8_t
name|nvs_rsvd
index|[
literal|24
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
name|hn_nvs_rndis_ack
argument_list|)
operator|>=
name|HN_NVS_REQSIZE_MIN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * RNDIS extension  */
end_comment

begin_comment
comment|/* Per-packet hash info */
end_comment

begin_define
define|#
directive|define
name|HN_NDIS_HASH_INFO_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|HN_NDIS_PKTINFO_TYPE_HASHINF
value|NDIS_PKTINFO_TYPE_ORIG_NBLIST
end_define

begin_comment
comment|/* NDIS_HASH_ */
end_comment

begin_comment
comment|/* Per-packet hash value */
end_comment

begin_define
define|#
directive|define
name|HN_NDIS_HASH_VALUE_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|HN_NDIS_PKTINFO_TYPE_HASHVAL
value|NDIS_PKTINFO_TYPE_PKT_CANCELID
end_define

begin_comment
comment|/* Per-packet-info size */
end_comment

begin_define
define|#
directive|define
name|HN_RNDIS_PKTINFO_SIZE
parameter_list|(
name|dlen
parameter_list|)
define|\
value|__offsetof(struct rndis_pktinfo, rm_data[dlen])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_HNREG_H_ */
end_comment

end_unit

