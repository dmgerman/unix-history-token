begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant - Layer2 packet interface definition  * Copyright (c) 2003-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This file defines an interface for layer 2 (link layer) packet sending and  * receiving. l2_packet_linux.c is one implementation for such a layer 2  * implementation using Linux packet sockets and l2_packet_pcap.c another one  * using libpcap and libdnet. When porting %wpa_supplicant to other operating  * systems, a new l2_packet implementation may need to be added.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|L2_PACKET_H
end_ifndef

begin_define
define|#
directive|define
name|L2_PACKET_H
end_define

begin_define
define|#
directive|define
name|MAC2STR
parameter_list|(
name|a
parameter_list|)
value|(a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
end_define

begin_define
define|#
directive|define
name|MACSTR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_EAPOL
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_EAPOL
value|0x888e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_RSN_PREAUTH
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_RSN_PREAUTH
value|0x88c7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * struct l2_packet_data - Internal l2_packet data structure  *  * This structure is used by the l2_packet implementation to store its private  * data. Other files use a pointer to this data when calling the l2_packet  * functions, but the contents of this structure should not be used directly  * outside l2_packet implementation.  */
end_comment

begin_struct_decl
struct_decl|struct
name|l2_packet_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|l2_ethhdr
block|{
name|u8
name|h_dest
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|h_source
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u16
name|h_proto
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/**  * l2_packet_init - Initialize l2_packet interface  * @ifname: Interface name  * @own_addr: Optional own MAC address if available from driver interface or  *	%NULL if not available  * @protocol: Ethernet protocol number in host byte order  * @rx_callback: Callback function that will be called for each received packet  * @rx_callback_ctx: Callback data (ctx) for calls to rx_callback()  * @l2_hdr: 1 = include layer 2 header, 0 = do not include header  * Returns: Pointer to internal data or %NULL on failure  *  * rx_callback function will be called with src_addr pointing to the source  * address (MAC address) of the the packet. If l2_hdr is set to 0, buf  * points to len bytes of the payload after the layer 2 header and similarly,  * TX buffers start with payload. This behavior can be changed by setting  * l2_hdr=1 to include the layer 2 header in the data buffer.  */
end_comment

begin_function_decl
name|struct
name|l2_packet_data
modifier|*
name|l2_packet_init
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
name|unsigned
name|short
name|protocol
parameter_list|,
name|void
function_decl|(
modifier|*
name|rx_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|src_addr
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
parameter_list|,
name|void
modifier|*
name|rx_callback_ctx
parameter_list|,
name|int
name|l2_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * l2_packet_deinit - Deinitialize l2_packet interface  * @l2: Pointer to internal l2_packet data from l2_packet_init()  */
end_comment

begin_function_decl
name|void
name|l2_packet_deinit
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * l2_packet_get_own_addr - Get own layer 2 address  * @l2: Pointer to internal l2_packet data from l2_packet_init()  * @addr: Buffer for the own address (6 bytes)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|l2_packet_get_own_addr
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * l2_packet_send - Send a packet  * @l2: Pointer to internal l2_packet data from l2_packet_init()  * @dst_addr: Destination address for the packet (only used if l2_hdr == 0)  * @proto: Protocol/ethertype for the packet in host byte order (only used if  * l2_hdr == 0)  * @buf: Packet contents to be sent; including layer 2 header if l2_hdr was  * set to 1 in l2_packet_init() call. Otherwise, only the payload of the packet  * is included.  * @len: Length of the buffer (including l2 header only if l2_hdr == 1)  * Returns:>=0 on success,<0 on failure  */
end_comment

begin_function_decl
name|int
name|l2_packet_send
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
specifier|const
name|u8
modifier|*
name|dst_addr
parameter_list|,
name|u16
name|proto
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * l2_packet_get_ip_addr - Get the current IP address from the interface  * @l2: Pointer to internal l2_packet data from l2_packet_init()  * @buf: Buffer for the IP address in text format  * @len: Maximum buffer length  * Returns: 0 on success, -1 on failure  *  * This function can be used to get the current IP address from the interface  * bound to the l2_packet. This is mainly for status information and the IP  * address will be stored as an ASCII string. This function is not essential  * for %wpa_supplicant operation, so full implementation is not required.  * l2_packet implementation will need to define the function, but it can return  * -1 if the IP address information is not available.  */
end_comment

begin_function_decl
name|int
name|l2_packet_get_ip_addr
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * l2_packet_notify_auth_start - Notify l2_packet about start of authentication  * @l2: Pointer to internal l2_packet data from l2_packet_init()  *  * This function is called when authentication is expected to start, e.g., when  * association has been completed, in order to prepare l2_packet implementation  * for EAPOL frames. This function is used mainly if the l2_packet code needs  * to do polling in which case it can increasing polling frequency. This can  * also be an empty function if the l2_packet implementation does not benefit  * from knowing about the starting authentication.  */
end_comment

begin_function_decl
name|void
name|l2_packet_notify_auth_start
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L2_PACKET_H */
end_comment

end_unit

