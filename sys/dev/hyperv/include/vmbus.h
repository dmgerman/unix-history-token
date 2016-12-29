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

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * VMBUS version is 32 bit, upper 16 bit for major_number and lower  * 16 bit for minor_number.  *  * 0.13  --  Windows Server 2008  * 1.1   --  Windows 7  * 2.4   --  Windows 8  * 3.0   --  Windows 8.1  */
end_comment

begin_define
define|#
directive|define
name|VMBUS_VERSION_WS2008
value|((0<< 16) | (13))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN7
value|((1<< 16) | (1))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN8
value|((2<< 16) | (4))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_WIN8_1
value|((3<< 16) | (0))
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|(((uint32_t)(ver))>> 16)
end_define

begin_define
define|#
directive|define
name|VMBUS_VERSION_MINOR
parameter_list|(
name|ver
parameter_list|)
value|(((uint32_t)(ver))& 0xffff)
end_define

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
name|VMBUS_CHANPKT_SIZE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_GETLEN
parameter_list|(
name|pktlen
parameter_list|)
define|\
value|(((int)(pktlen))<< VMBUS_CHANPKT_SIZE_SHIFT)
end_define

begin_struct
struct|struct
name|vmbus_chanpkt_hdr
block|{
name|uint16_t
name|cph_type
decl_stmt|;
comment|/* VMBUS_CHANPKT_TYPE_ */
name|uint16_t
name|cph_hlen
decl_stmt|;
comment|/* header len, in 8 bytes */
name|uint16_t
name|cph_tlen
decl_stmt|;
comment|/* total len, in 8 bytes */
name|uint16_t
name|cph_flags
decl_stmt|;
comment|/* VMBUS_CHANPKT_FLAG_ */
name|uint64_t
name|cph_xactid
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
name|VMBUS_CHANPKT_FLAG_NONE
value|0
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
name|VMBUS_CHANPKT_CONST_DATA
parameter_list|(
name|pkt
parameter_list|)
define|\
value|(const void *)((const uint8_t *)(pkt) +	\ 	VMBUS_CHANPKT_GETLEN((pkt)->cph_hlen))
end_define

begin_comment
comment|/* Include padding */
end_comment

begin_define
define|#
directive|define
name|VMBUS_CHANPKT_DATALEN
parameter_list|(
name|pkt
parameter_list|)
define|\
value|(VMBUS_CHANPKT_GETLEN((pkt)->cph_tlen) -\ 	 VMBUS_CHANPKT_GETLEN((pkt)->cph_hlen))
end_define

begin_struct
struct|struct
name|vmbus_rxbuf_desc
block|{
name|uint32_t
name|rb_len
decl_stmt|;
name|uint32_t
name|rb_ofs
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_chanpkt_rxbuf
block|{
name|struct
name|vmbus_chanpkt_hdr
name|cp_hdr
decl_stmt|;
name|uint16_t
name|cp_rxbuf_id
decl_stmt|;
name|uint16_t
name|cp_rsvd
decl_stmt|;
name|uint32_t
name|cp_rxbuf_cnt
decl_stmt|;
name|struct
name|vmbus_rxbuf_desc
name|cp_rxbuf
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|vmbus_chan_br
block|{
name|void
modifier|*
name|cbr
decl_stmt|;
name|bus_addr_t
name|cbr_paddr
decl_stmt|;
name|int
name|cbr_txsz
decl_stmt|;
name|int
name|cbr_rxsz
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|vmbus_channel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_xact
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_xact_ctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hyperv_guid
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|task
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vmbus_chan_callback_t
function_decl|)
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|vmbus_channel
operator|*
name|vmbus_get_channel
argument_list|(
argument|device_t dev
argument_list|)
block|{
return|return
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/*  * vmbus_chan_open_br()  *  * Return values:  * 0			Succeeded.  * EISCONN		Failed, and the memory passed through 'br' is still  *			connected.  Callers must _not_ free the the memory  *			passed through 'br', if this error happens.  * other values		Failed.  The memory passed through 'br' is no longer  *			connected.  Callers are free to do anything with the  *			memory passed through 'br'.  *  *  *  * vmbus_chan_close_direct()  *  * NOTE:  * Callers of this function _must_ make sure to close all sub-channels before  * closing the primary channel.  *  * Return values:  * 0			Succeeded.  * EISCONN		Failed, and the memory associated with the bufring  *			is still connected.  Callers must _not_ free the the  *			memory associated with the bufring, if this error  *			happens.  * other values		Failed.  The memory associated with the bufring is  *			no longer connected.  Callers are free to do anything  *			with the memory associated with the bufring.  */
end_comment

begin_function_decl
name|int
name|vmbus_chan_open
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|int
name|txbr_size
parameter_list|,
name|int
name|rxbr_size
parameter_list|,
specifier|const
name|void
modifier|*
name|udata
parameter_list|,
name|int
name|udlen
parameter_list|,
name|vmbus_chan_callback_t
name|cb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_open_br
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
specifier|const
name|struct
name|vmbus_chan_br
modifier|*
name|cbr
parameter_list|,
specifier|const
name|void
modifier|*
name|udata
parameter_list|,
name|int
name|udlen
parameter_list|,
name|vmbus_chan_callback_t
name|cb
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_close
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_close_direct
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_intr_drain
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_run_task
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_set_orphan
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|vmbus_xact_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_unset_orphan
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|vmbus_chan_xact_wait
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|,
name|bool
name|can_sleep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_gpadl_connect
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|bus_addr_t
name|paddr
parameter_list|,
name|int
name|size
parameter_list|,
name|uint32_t
modifier|*
name|gpadl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_gpadl_disconnect
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|uint32_t
name|gpadl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_cpu_set
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_cpu_rr
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_chan_set_readbatch
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vmbus_channel
modifier|*
modifier|*
name|vmbus_subchan_get
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|pri_chan
parameter_list|,
name|int
name|subchan_cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_subchan_rel
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
modifier|*
name|subchan
parameter_list|,
name|int
name|subchan_cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_subchan_drain
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|pri_chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_recv
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
modifier|*
name|dlen
parameter_list|,
name|uint64_t
modifier|*
name|xactid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_recv_pkt
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|,
name|struct
name|vmbus_chanpkt_hdr
modifier|*
name|pkt
parameter_list|,
name|int
modifier|*
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_send
parameter_list|(
name|struct
name|vmbus_channel
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
name|vmbus_channel
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
name|vmbus_channel
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

begin_function_decl
name|uint32_t
name|vmbus_chan_id
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|vmbus_chan_subidx
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vmbus_chan_is_primary
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vmbus_chan_is_revoked
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|hyperv_guid
modifier|*
name|vmbus_chan_guid_inst
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_chan_prplist_nelem
parameter_list|(
name|int
name|br_size
parameter_list|,
name|int
name|prpcnt_max
parameter_list|,
name|int
name|dlen_max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vmbus_chan_rx_empty
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|vmbus_chan_tx_empty
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|taskqueue
modifier|*
name|vmbus_chan_mgmt_tq
parameter_list|(
specifier|const
name|struct
name|vmbus_channel
modifier|*
name|chan
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

