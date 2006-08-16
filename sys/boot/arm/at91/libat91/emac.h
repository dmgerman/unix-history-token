begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: emac.h  *  * Definition of routine to set the MAC address.  *  * Revision information:  *  * 28AUG2004	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EMAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_EMAC_H_
end_define

begin_function_decl
specifier|extern
name|void
name|EMAC_SetMACAddress
parameter_list|(
name|unsigned
name|char
name|addr
index|[
literal|6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SetServerIPAddress
parameter_list|(
name|unsigned
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SetLocalIPAddress
parameter_list|(
name|unsigned
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|EMAC_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|TFTP_Download
parameter_list|(
name|unsigned
name|address
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAX_RX_PACKETS
value|8
end_define

begin_define
define|#
directive|define
name|RX_PACKET_SIZE
value|1536
end_define

begin_define
define|#
directive|define
name|RX_BUFFER_START
value|0x21000000
end_define

begin_define
define|#
directive|define
name|RX_DATA_START
value|(RX_BUFFER_START + (8 * MAX_RX_PACKETS))
end_define

begin_define
define|#
directive|define
name|ARP_REQUEST
value|0x0001
end_define

begin_define
define|#
directive|define
name|ARP_REPLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|PROTOCOL_ARP
value|0x0806
end_define

begin_define
define|#
directive|define
name|PROTOCOL_IP
value|0x0800
end_define

begin_define
define|#
directive|define
name|PROTOCOL_UDP
value|0x11
end_define

begin_define
define|#
directive|define
name|SWAP16
parameter_list|(
name|x
parameter_list|)
value|((((x)& 0xff)<< 8) | ((x)>> 8))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|address
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
block|}
name|receive_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|dest_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|src_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|frame_type
decl_stmt|;
name|unsigned
name|short
name|hard_type
decl_stmt|;
name|unsigned
name|short
name|prot_type
decl_stmt|;
name|unsigned
name|char
name|hard_size
decl_stmt|;
name|unsigned
name|char
name|prot_size
decl_stmt|;
name|unsigned
name|short
name|operation
decl_stmt|;
name|unsigned
name|char
name|sender_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|sender_ip
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|target_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|target_ip
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|arp_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|ip_v_hl
decl_stmt|;
name|unsigned
name|char
name|ip_tos
decl_stmt|;
name|unsigned
name|short
name|ip_len
decl_stmt|;
name|unsigned
name|short
name|ip_id
decl_stmt|;
name|unsigned
name|short
name|ip_off
decl_stmt|;
name|unsigned
name|char
name|ip_ttl
decl_stmt|;
name|unsigned
name|char
name|ip_p
decl_stmt|;
name|unsigned
name|short
name|ip_sum
decl_stmt|;
name|unsigned
name|char
name|ip_src
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|ip_dst
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|ip_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|dest_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|char
name|src_mac
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|proto_mac
decl_stmt|;
name|unsigned
name|short
name|packet_length
decl_stmt|;
name|ip_header_t
name|iphdr
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|transmit_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|src_port
decl_stmt|;
name|unsigned
name|short
name|dst_port
decl_stmt|;
name|unsigned
name|short
name|udp_len
decl_stmt|;
name|unsigned
name|short
name|udp_cksum
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|udp_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|unsigned
name|short
name|block_num
decl_stmt|;
name|unsigned
name|char
name|data
index|[
literal|512
index|]
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|__packed__
typedef|))
name|tftp_header_t
typedef|;
end_typedef

begin_comment
comment|// Preswap bytes
end_comment

begin_define
define|#
directive|define
name|TFTP_RRQ_OPCODE
value|0x0100
end_define

begin_define
define|#
directive|define
name|TFTP_WRQ_OPCODE
value|0x0200
end_define

begin_define
define|#
directive|define
name|TFTP_DATA_OPCODE
value|0x0300
end_define

begin_define
define|#
directive|define
name|TFTP_ACK_OPCODE
value|0x0400
end_define

begin_define
define|#
directive|define
name|TFTP_ERROR_OPCODE
value|0x0500
end_define

begin_comment
comment|/* MII registers definition */
end_comment

begin_define
define|#
directive|define
name|MII_STS_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|MII_STS_LINK_STAT
value|0x04
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BOOT_KB9202
end_ifdef

begin_define
define|#
directive|define
name|MII_STS2_REG
value|0x11
end_define

begin_define
define|#
directive|define
name|MII_STS2_LINK
value|0x400
end_define

begin_define
define|#
directive|define
name|MII_STS2_100TX
value|0x4000
end_define

begin_define
define|#
directive|define
name|MII_STS2_FDX
value|0x200
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MII_SPEC_STS_REG
value|0x11
end_define

begin_define
define|#
directive|define
name|MII_SSTS_100FDX
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_SSTS_100HDX
value|0x4000
end_define

begin_define
define|#
directive|define
name|MII_SSTS_10FDX
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_SSTS_10HDX
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|localMACAddr
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|localMAClow
decl_stmt|,
name|localMAChigh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|localMACSet
decl_stmt|,
name|serverMACSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|receive_descriptor_t
modifier|*
name|p_rxBD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|lastSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|localIPSet
decl_stmt|,
name|serverIPSet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|serverPort
decl_stmt|,
name|localPort
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EMAC_H_ */
end_comment

end_unit

