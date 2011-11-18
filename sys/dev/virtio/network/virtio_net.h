begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_NET_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_NET_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* The feature bitmap for virtio net */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_CSUM
value|0x00001
end_define

begin_comment
comment|/* Host handles pkts w/ partial csum */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GUEST_CSUM
value|0x00002
end_define

begin_comment
comment|/* Guest handles pkts w/ partial csum*/
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_MAC
value|0x00020
end_define

begin_comment
comment|/* Host has given MAC address. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GSO
value|0x00040
end_define

begin_comment
comment|/* Host handles pkts w/ any GSO type */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GUEST_TSO4
value|0x00080
end_define

begin_comment
comment|/* Guest can handle TSOv4 in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GUEST_TSO6
value|0x00100
end_define

begin_comment
comment|/* Guest can handle TSOv6 in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GUEST_ECN
value|0x00200
end_define

begin_comment
comment|/* Guest can handle TSO[6] w/ ECN in.*/
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_GUEST_UFO
value|0x00400
end_define

begin_comment
comment|/* Guest can handle UFO in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_HOST_TSO4
value|0x00800
end_define

begin_comment
comment|/* Host can handle TSOv4 in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_HOST_TSO6
value|0x01000
end_define

begin_comment
comment|/* Host can handle TSOv6 in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_HOST_ECN
value|0x02000
end_define

begin_comment
comment|/* Host can handle TSO[6] w/ ECN in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_HOST_UFO
value|0x04000
end_define

begin_comment
comment|/* Host can handle UFO in. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_MRG_RXBUF
value|0x08000
end_define

begin_comment
comment|/* Host can merge receive buffers. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_STATUS
value|0x10000
end_define

begin_comment
comment|/* virtio_net_config.status available*/
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_CTRL_VQ
value|0x20000
end_define

begin_comment
comment|/* Control channel available */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_CTRL_RX
value|0x40000
end_define

begin_comment
comment|/* Control channel RX mode support */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_CTRL_VLAN
value|0x80000
end_define

begin_comment
comment|/* Control channel VLAN filtering */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_F_CTRL_RX_EXTRA
value|0x100000
end_define

begin_comment
comment|/* Extra RX mode control support */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_S_LINK_UP
value|1
end_define

begin_comment
comment|/* Link is up */
end_comment

begin_struct
struct|struct
name|virtio_net_config
block|{
comment|/* The config defining mac address (if VIRTIO_NET_F_MAC) */
name|uint8_t
name|mac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* See VIRTIO_NET_F_STATUS and VIRTIO_NET_S_* above */
name|uint16_t
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * This is the first element of the scatter-gather list.  If you don't  * specify GSO or CSUM features, you can simply ignore the header.  */
end_comment

begin_struct
struct|struct
name|virtio_net_hdr
block|{
define|#
directive|define
name|VIRTIO_NET_HDR_F_NEEDS_CSUM
value|1
comment|/* Use csum_start,csum_offset*/
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_NONE
value|0
comment|/* Not a GSO frame */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_TCPV4
value|1
comment|/* GSO frame, IPv4 TCP (TSO) */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_UDP
value|3
comment|/* GSO frame, IPv4 UDP (UFO) */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_TCPV6
value|4
comment|/* GSO frame, IPv6 TCP */
define|#
directive|define
name|VIRTIO_NET_HDR_GSO_ECN
value|0x80
comment|/* TCP has ECN set */
name|uint8_t
name|gso_type
decl_stmt|;
name|uint16_t
name|hdr_len
decl_stmt|;
comment|/* Ethernet + IP + tcp/udp hdrs */
name|uint16_t
name|gso_size
decl_stmt|;
comment|/* Bytes to append to hdr_len per frame */
name|uint16_t
name|csum_start
decl_stmt|;
comment|/* Position to start checksumming from */
name|uint16_t
name|csum_offset
decl_stmt|;
comment|/* Offset after that to place checksum */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the version of the header to use when the MRG_RXBUF  * feature has been negotiated.  */
end_comment

begin_struct
struct|struct
name|virtio_net_hdr_mrg_rxbuf
block|{
name|struct
name|virtio_net_hdr
name|hdr
decl_stmt|;
name|uint16_t
name|num_buffers
decl_stmt|;
comment|/* Number of merged rx buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control virtqueue data structures  *  * The control virtqueue expects a header in the first sg entry  * and an ack/status response in the last entry.  Data for the  * command goes in between.  */
end_comment

begin_struct
struct|struct
name|virtio_net_ctrl_hdr
block|{
name|uint8_t
name|class
decl_stmt|;
name|uint8_t
name|cmd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint8_t
name|virtio_net_ctrl_ack
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIRTIO_NET_OK
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_ERR
value|1
end_define

begin_comment
comment|/*  * Control the RX mode, ie. promiscuous, allmulti, etc...  * All commands require an "out" sg entry containing a 1 byte  * state value, zero = disable, non-zero = enable.  Commands  * 0 and 1 are supported with the VIRTIO_NET_F_CTRL_RX feature.  * Commands 2-5 are added with VIRTIO_NET_F_CTRL_RX_EXTRA.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_PROMISC
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_ALLMULTI
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_ALLUNI
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_NOMULTI
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_NOUNI
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_RX_NOBCAST
value|5
end_define

begin_comment
comment|/*  * Control the MAC filter table.  *  * The MAC filter table is managed by the hypervisor, the guest should  * assume the size is infinite.  Filtering should be considered  * non-perfect, ie. based on hypervisor resources, the guest may  * received packets from sources not specified in the filter list.  *  * In addition to the class/cmd header, the TABLE_SET command requires  * two out scatterlists.  Each contains a 4 byte count of entries followed  * by a concatenated byte stream of the ETH_ALEN MAC addresses.  The  * first sg list contains unicast addresses, the second is for multicast.  * This functionality is present if the VIRTIO_NET_F_CTRL_RX feature  * is available.  */
end_comment

begin_struct
struct|struct
name|virtio_net_ctrl_mac
block|{
name|uint32_t
name|entries
decl_stmt|;
name|uint8_t
name|macs
index|[]
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_MAC
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_MAC_TABLE_SET
value|0
end_define

begin_comment
comment|/*  * Control VLAN filtering  *  * The VLAN filter table is controlled via a simple ADD/DEL interface.  * VLAN IDs not added may be filtered by the hypervisor.  Del is the  * opposite of add.  Both commands expect an out entry containing a 2  * byte VLAN ID.  VLAN filtering is available with the  * VIRTIO_NET_F_CTRL_VLAN feature bit.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_VLAN
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_VLAN_ADD
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_NET_CTRL_VLAN_DEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_NET_H */
end_comment

end_unit

