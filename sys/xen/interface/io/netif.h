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
comment|/*  * Older implementation of Xen network frontend / backend has an  * implicit dependency on the MAX_SKB_FRAGS as the maximum number of  * ring slots a skb can use. Netfront / netback may not work as  * expected when frontend and backend have different MAX_SKB_FRAGS.  *  * A better approach is to add mechanism for netfront / netback to  * negotiate this value. However we cannot fix all possible  * frontends, so we need to define a value which states the minimum  * slots backend must support.  *  * The minimum value derives from older Linux kernel's MAX_SKB_FRAGS  * (18), which is proved to work with most frontends. Any new backend  * which doesn't negotiate with frontend should expect frontend to  * send a valid packet using slots up to this value.  */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_NR_SLOTS_MIN
value|18
end_define

begin_comment
comment|/*  * Notifications after enqueuing any type of message should be conditional on  * the appropriate req_event or rsp_event field in the shared ring.  * If the client sends notification for rx requests then it should specify  * feature 'feature-rx-notify' via xenbus. Otherwise the backend will assume  * that it cannot safely queue packets (as it may not be kicked to send them).  */
end_comment

begin_comment
comment|/*  * "feature-split-event-channels" is introduced to separate guest TX  * and RX notification. Backend either doesn't support this feature or  * advertises it via xenstore as 0 (disabled) or 1 (enabled).  *  * To make use of this feature, frontend should allocate two event  * channels for TX and RX, advertise them to backend as  * "event-channel-tx" and "event-channel-rx" respectively. If frontend  * doesn't want to use this feature, it just writes "event-channel"  * node as before.  */
end_comment

begin_comment
comment|/*  * Multiple transmit and receive queues:  * If supported, the backend will write the key "multi-queue-max-queues" to  * the directory for that vif, and set its value to the maximum supported  * number of queues.  * Frontends that are aware of this feature and wish to use it can write the  * key "multi-queue-num-queues", set to the number they wish to use, which  * must be greater than zero, and no more than the value reported by the backend  * in "multi-queue-max-queues".  *  * Queues replicate the shared rings and event channels.  * "feature-split-event-channels" may optionally be used when using  * multiple queues, but is not mandatory.  *  * Each queue consists of one shared ring pair, i.e. there must be the same  * number of tx and rx rings.  *  * For frontends requesting just one queue, the usual event-channel and  * ring-ref keys are written as before, simplifying the backend processing  * to avoid distinguishing between a frontend that doesn't understand the  * multi-queue feature, and one that does, but requested only one queue.  *  * Frontends requesting two or more queues must not write the toplevel  * event-channel (or event-channel-{tx,rx}) and {tx,rx}-ring-ref keys,  * instead writing those keys under sub-keys having the name "queue-N" where  * N is the integer ID of the queue for which those keys belong. Queues  * are indexed from zero. For example, a frontend with two queues and split  * event channels must write the following set of queue-related keys:  *  * /local/domain/1/device/vif/0/multi-queue-num-queues = "2"  * /local/domain/1/device/vif/0/queue-0 = ""  * /local/domain/1/device/vif/0/queue-0/tx-ring-ref = "<ring-ref-tx0>"  * /local/domain/1/device/vif/0/queue-0/rx-ring-ref = "<ring-ref-rx0>"  * /local/domain/1/device/vif/0/queue-0/event-channel-tx = "<evtchn-tx0>"  * /local/domain/1/device/vif/0/queue-0/event-channel-rx = "<evtchn-rx0>"  * /local/domain/1/device/vif/0/queue-1 = ""  * /local/domain/1/device/vif/0/queue-1/tx-ring-ref = "<ring-ref-tx1>"  * /local/domain/1/device/vif/0/queue-1/rx-ring-ref = "<ring-ref-rx1"  * /local/domain/1/device/vif/0/queue-1/event-channel-tx = "<evtchn-tx1>"  * /local/domain/1/device/vif/0/queue-1/event-channel-rx = "<evtchn-rx1>"  *  * If there is any inconsistency in the XenStore data, the backend may  * choose not to connect any queues, instead treating the request as an  * error. This includes scenarios where more (or fewer) queues were  * requested than the frontend provided details for.  *  * Mapping of packets to queues is considered to be a function of the  * transmitting system (backend or frontend) and is not negotiated  * between the two. Guests are free to transmit packets on any queue  * they choose, provided it has been set up correctly. Guests must be  * prepared to receive packets on any queue they have requested be set up.  */
end_comment

begin_comment
comment|/*  * "feature-no-csum-offload" should be used to turn IPv4 TCP/UDP checksum  * offload off or on. If it is missing then the feature is assumed to be on.  * "feature-ipv6-csum-offload" should be used to turn IPv6 TCP/UDP checksum  * offload on or off. If it is missing then the feature is assumed to be off.  */
end_comment

begin_comment
comment|/*  * "feature-gso-tcpv4" and "feature-gso-tcpv6" advertise the capability to  * handle large TCP packets (in IPv4 or IPv6 form respectively). Neither  * frontends nor backends are assumed to be capable unless the flags are  * present.  */
end_comment

begin_comment
comment|/*  * "feature-multicast-control" advertises the capability to filter ethernet  * multicast packets in the backend. To enable use of this capability the  * frontend must set "request-multicast-control" before moving into the  * connected state.  *  * If "request-multicast-control" is set then the backend transmit side should  * no longer flood multicast packets to the frontend, it should instead drop any  * multicast packet that does not match in a filter list. The list is  * amended by the frontend by sending dummy transmit requests containing  * XEN_NETIF_EXTRA_TYPE_MCAST_{ADD,DEL} extra-info fragments as specified below.  * Once enabled by the frontend, the feature cannot be disabled except by  * closing and re-connecting to the backend.  */
end_comment

begin_comment
comment|/*  * This is the 'wire' format for packets:  *  Request 1: netif_tx_request_t -- NETTXF_* (any flags)  * [Request 2: netif_extra_info_t] (only if request 1 has NETTXF_extra_info)  * [Request 3: netif_extra_info_t] (only if request 2 has XEN_NETIF_EXTRA_MORE)  *  Request 4: netif_tx_request_t -- NETTXF_more_data  *  Request 5: netif_tx_request_t -- NETTXF_more_data  *  ...  *  Request N: netif_tx_request_t -- 0  */
end_comment

begin_comment
comment|/*  * Guest transmit  * ==============  *  * Ring slot size is 12 octets, however not all request/response  * structs use the full size.  *  * tx request data (netif_tx_request_t)  * ------------------------------------  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | grant ref             | offset    | flags     |  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | id        | size      |  * +-----+-----+-----+-----+  *  * grant ref: Reference to buffer page.  * offset: Offset within buffer page.  * flags: NETTXF_*.  * id: request identifier, echoed in response.  * size: packet size in bytes.  *  * tx response (netif_tx_response_t)  * ---------------------------------  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | id        | status    | unused                |  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | unused                |  * +-----+-----+-----+-----+  *  * id: reflects id in transmit request  * status: NETIF_RSP_*  *  * Guest receive  * =============  *  * Ring slot size is 8 octets.  *  * rx request (netif_rx_request_t)  * -------------------------------  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | id        | pad       | gref                  |  * +-----+-----+-----+-----+-----+-----+-----+-----+  *  * id: request identifier, echoed in response.  * gref: reference to incoming granted frame.  *  * rx response (netif_rx_response_t)  * ---------------------------------  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | id        | offset    | flags     | status    |  * +-----+-----+-----+-----+-----+-----+-----+-----+  *  * id: reflects id in receive request  * offset: offset in page of start of received packet  * flags: NETRXF_*  * status: -ve: NETIF_RSP_*; +ve: Rx'ed pkt size.  *  * Extra Info  * ==========  *  * Can be present if initial request has NET{T,R}XF_extra_info, or  * previous extra request has XEN_NETIF_EXTRA_MORE.  *  * The struct therefore needs to fit into either a tx or rx slot and  * is therefore limited to 8 octets.  *  * extra info (netif_extra_info_t)  * -------------------------------  *  * General format:  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * |type |flags| type specfic data                 |  * +-----+-----+-----+-----+-----+-----+-----+-----+  * | padding for tx        |  * +-----+-----+-----+-----+  *  * type: XEN_NETIF_EXTRA_TYPE_*  * flags: XEN_NETIF_EXTRA_FLAG_*  * padding for tx: present only in the tx case due to 8 octet limit  *     from rx case. Not shown in type specific entries below.  *  * XEN_NETIF_EXTRA_TYPE_GSO:  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * |type |flags| size      |type | pad | features  |  * +-----+-----+-----+-----+-----+-----+-----+-----+  *  * type: Must be XEN_NETIF_EXTRA_TYPE_GSO  * flags: XEN_NETIF_EXTRA_FLAG_*  * size: Maximum payload size of each segment.  * type: XEN_NETIF_GSO_TYPE_*  * features: EN_NETIF_GSO_FEAT_*  *  * XEN_NETIF_EXTRA_TYPE_MCAST_{ADD,DEL}:  *  *    0     1     2     3     4     5     6     7  octet  * +-----+-----+-----+-----+-----+-----+-----+-----+  * |type |flags| addr                              |  * +-----+-----+-----+-----+-----+-----+-----+-----+  *  * type: Must be XEN_NETIF_EXTRA_TYPE_MCAST_{ADD,DEL}  * flags: XEN_NETIF_EXTRA_FLAG_*  * addr: address to add/remove  */
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

begin_define
define|#
directive|define
name|XEN_NETIF_MAX_TX_SIZE
value|0xFFFF
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
comment|/* Packet size in bytes.       */
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
comment|/* netif_extra_info_t flags. */
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
comment|/* GSO types */
end_comment

begin_define
define|#
directive|define
name|XEN_NETIF_GSO_TYPE_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|XEN_NETIF_GSO_TYPE_TCPV4
value|(1)
end_define

begin_define
define|#
directive|define
name|XEN_NETIF_GSO_TYPE_TCPV6
value|(2)
end_define

begin_comment
comment|/*  * This structure needs to fit within both netif_tx_request_t and  * netif_rx_response_t for compatibility.  */
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
comment|/*          * XEN_NETIF_EXTRA_TYPE_MCAST_{ADD,DEL}:          */
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
name|uint16_t
name|pad
decl_stmt|;
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
comment|/* -ve: NETIF_RSP_* ; +ve: Rx'ed pkt size. */
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
comment|/* No response: used for auxiliary requests (e.g., netif_extra_info_t). */
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
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

