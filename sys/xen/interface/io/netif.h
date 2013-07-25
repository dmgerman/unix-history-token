begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * netif.h  *   * Unified network-device I/O interface for Xen guest OSes.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2003-2004, Keir Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_NETIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_NETIF_H__
end_define

begin_include
include|#
directive|include
file|"ring.h"
end_include

begin_include
include|#
directive|include
file|"../grant_table.h"
end_include

begin_comment
comment|/*  * Notifications after enqueuing any type of message should be conditional on  * the appropriate req_event or rsp_event field in the shared ring.  * If the client sends notification for rx requests then it should specify  * feature 'feature-rx-notify' via xenbus. Otherwise the backend will assume  * that it cannot safely queue packets (as it may not be kicked to send them).  */
end_comment

begin_comment
comment|/*  * This is the 'wire' format for packets:  *  Request 1: netif_tx_request -- NETTXF_* (any flags)  * [Request 2: netif_tx_extra] (only if request 1 has NETTXF_extra_info)  * [Request 3: netif_tx_extra] (only if request 2 has XEN_NETIF_EXTRA_FLAG_MORE)  *  Request 4: netif_tx_request -- NETTXF_more_data  *  Request 5: netif_tx_request -- NETTXF_more_data  *  ...  *  Request N: netif_tx_request -- 0  */
end_comment

begin_comment
comment|/* Protocol checksum field is blank in the packet (hardware offload)? */
end_comment

begin_define
define|#
directive|define
name|_NETTXF_csum_blank
value|(0)
end_define

begin_define
define|#
directive|define
name|NETTXF_csum_blank
value|(1U<<_NETTXF_csum_blank)
end_define

begin_comment
comment|/* Packet data has been validated against protocol checksum. */
end_comment

begin_define
define|#
directive|define
name|_NETTXF_data_validated
value|(1)
end_define

begin_define
define|#
directive|define
name|NETTXF_data_validated
value|(1U<<_NETTXF_data_validated)
end_define

begin_comment
comment|/* Packet continues in the next request descriptor. */
end_comment

begin_define
define|#
directive|define
name|_NETTXF_more_data
value|(2)
end_define

begin_define
define|#
directive|define
name|NETTXF_more_data
value|(1U<<_NETTXF_more_data)
end_define

begin_comment
comment|/* Packet to be followed by extra descriptor(s). */
end_comment

begin_define
define|#
directive|define
name|_NETTXF_extra_info
value|(3)
end_define

begin_define
define|#
directive|define
name|NETTXF_extra_info
value|(1U<<_NETTXF_extra_info)
end_define

begin_struct
struct|struct
name|netif_tx_request
block|{
name|grant_ref_t
name|gref
decl_stmt|;
comment|/* Reference to buffer page */
name|uint16_t
name|offset
decl_stmt|;
comment|/* Offset within buffer page */
name|uint16_t
name|flags
decl_stmt|;
comment|/* NETTXF_* */
name|uint16_t
name|id
decl_stmt|;
comment|/* Echoed in response message. */
name|uint16_t
name|size
decl_stmt|;
comment|/* For the first request in a packet, the packet  			      size in bytes.  For subsequent requests, the  			      size of that request's associated data in bytes*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netif_tx_request
name|netif_tx_request_t
typedef|;
end_typedef

begin_comment
comment|/* Types of netif_extra_info descriptors. */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_TYPE_NONE
value|(0)
end_define

begin_comment
comment|/* Never used - invalid */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_TYPE_GSO
value|(1)
end_define

begin_comment
comment|/* u.gso */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_TYPE_MCAST_ADD
value|(2)
end_define

begin_comment
comment|/* u.mcast */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_TYPE_MCAST_DEL
value|(3)
end_define

begin_comment
comment|/* u.mcast */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_TYPE_MAX
value|(4)
end_define

begin_comment
comment|/* netif_extra_info flags. */
end_comment

begin_define
define|#
directive|define
name|_XEN_NETIF_EXTRA_FLAG_MORE
value|(0)
end_define

begin_define
define|#
directive|define
name|XEN_NETIF_EXTRA_FLAG_MORE
value|(1U<<_XEN_NETIF_EXTRA_FLAG_MORE)
end_define

begin_comment
comment|/* GSO types - only TCPv4 currently supported. */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_GSO_TYPE_TCPV4
value|(1)
end_define

begin_comment
comment|/*  * This structure needs to fit within both netif_tx_request and  * netif_rx_response for compatibility.  */
end_comment

begin_struct
struct|struct
name|netif_extra_info
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* XEN_NETIF_EXTRA_TYPE_* */
name|uint8_t
name|flags
decl_stmt|;
comment|/* XEN_NETIF_EXTRA_FLAG_* */
union|union
block|{
comment|/*          * XEN_NETIF_EXTRA_TYPE_GSO:          */
struct|struct
block|{
comment|/*              * Maximum payload size of each segment. For example, for TCP this              * is just the path MSS.              */
name|uint16_t
name|size
decl_stmt|;
comment|/*              * GSO type. This determines the protocol of the packet and any              * extra features required to segment the packet properly.              */
name|uint8_t
name|type
decl_stmt|;
comment|/* XEN_NETIF_GSO_TYPE_* */
comment|/* Future expansion. */
name|uint8_t
name|pad
decl_stmt|;
comment|/*              * GSO features. This specifies any extra GSO features required              * to process this packet, such as ECN support for TCPv4.              */
name|uint16_t
name|features
decl_stmt|;
comment|/* XEN_NETIF_GSO_FEAT_* */
block|}
name|gso
struct|;
comment|/*          * XEN_NETIF_EXTRA_TYPE_MCAST_{ADD,DEL}:          * Backend advertises availability via 'feature-multicast-control'          * xenbus node containing value '1'.          * Frontend requests this feature by advertising          * 'request-multicast-control' xenbus node containing value '1'.          * If multicast control is requested then multicast flooding is          * disabled and the frontend must explicitly register its interest          * in multicast groups using dummy transmit requests containing          * MCAST_{ADD,DEL} extra-info fragments.          */
struct|struct
block|{
name|uint8_t
name|addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* Address to add/remove. */
block|}
name|mcast
struct|;
name|uint16_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netif_extra_info
name|netif_extra_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|netif_tx_response
block|{
name|uint16_t
name|id
decl_stmt|;
name|int16_t
name|status
decl_stmt|;
comment|/* NETIF_RSP_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netif_tx_response
name|netif_tx_response_t
typedef|;
end_typedef

begin_struct
struct|struct
name|netif_rx_request
block|{
name|uint16_t
name|id
decl_stmt|;
comment|/* Echoed in response message.        */
name|grant_ref_t
name|gref
decl_stmt|;
comment|/* Reference to incoming granted frame */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netif_rx_request
name|netif_rx_request_t
typedef|;
end_typedef

begin_comment
comment|/* Packet data has been validated against protocol checksum. */
end_comment

begin_define
define|#
directive|define
name|_NETRXF_data_validated
value|(0)
end_define

begin_define
define|#
directive|define
name|NETRXF_data_validated
value|(1U<<_NETRXF_data_validated)
end_define

begin_comment
comment|/* Protocol checksum field is blank in the packet (hardware offload)? */
end_comment

begin_define
define|#
directive|define
name|_NETRXF_csum_blank
value|(1)
end_define

begin_define
define|#
directive|define
name|NETRXF_csum_blank
value|(1U<<_NETRXF_csum_blank)
end_define

begin_comment
comment|/* Packet continues in the next request descriptor. */
end_comment

begin_define
define|#
directive|define
name|_NETRXF_more_data
value|(2)
end_define

begin_define
define|#
directive|define
name|NETRXF_more_data
value|(1U<<_NETRXF_more_data)
end_define

begin_comment
comment|/* Packet to be followed by extra descriptor(s). */
end_comment

begin_define
define|#
directive|define
name|_NETRXF_extra_info
value|(3)
end_define

begin_define
define|#
directive|define
name|NETRXF_extra_info
value|(1U<<_NETRXF_extra_info)
end_define

begin_comment
comment|/* GSO Prefix descriptor. */
end_comment

begin_define
define|#
directive|define
name|_NETRXF_gso_prefix
value|(4)
end_define

begin_define
define|#
directive|define
name|NETRXF_gso_prefix
value|(1U<<_NETRXF_gso_prefix)
end_define

begin_struct
struct|struct
name|netif_rx_response
block|{
name|uint16_t
name|id
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
comment|/* Offset in page of start of received packet  */
name|uint16_t
name|flags
decl_stmt|;
comment|/* NETRXF_* */
name|int16_t
name|status
decl_stmt|;
comment|/* -ve: NETIF_RSP_* ; +ve: Rx'ed response size. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netif_rx_response
name|netif_rx_response_t
typedef|;
end_typedef

begin_comment
comment|/*  * Generate netif ring structures and types.  */
end_comment

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|netif_tx
argument_list|,
expr|struct
name|netif_tx_request
argument_list|,
expr|struct
name|netif_tx_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|netif_rx
argument_list|,
expr|struct
name|netif_rx_request
argument_list|,
expr|struct
name|netif_rx_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NETIF_RSP_DROPPED
value|-2
end_define

begin_define
define|#
directive|define
name|NETIF_RSP_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|NETIF_RSP_OKAY
value|0
end_define

begin_comment
comment|/* No response: used for auxiliary requests (e.g., netif_tx_extra). */
end_comment

begin_define
define|#
directive|define
name|NETIF_RSP_NULL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

