begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2002 Intel Corporation    All rights reserved.       Redistribution and use in source and binary forms of the Software, with or    without modification, are permitted provided that the following conditions    are met:        1. Redistributions of source code of the Software may retain the above        copyright notice, this list of conditions and the following disclaimer.        2. Redistributions in binary form of the Software may reproduce the above        copyright notice, this list of conditions and the following disclaimer        in the documentation and/or other materials provided with the        distribution.        3. Neither the name of the Intel Corporation nor the names of its        contributors shall be used to endorse or promote products derived from        this Software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* if_em_fxhw.h  * Structures, enums, and macros for the MAC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EM_MAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_EM_MAC_H_
end_define

begin_include
include|#
directive|include
file|<dev/em/if_em_osdep.h>
end_include

begin_comment
comment|/* Forward declarations of structures used by the shared code */
end_comment

begin_struct_decl
struct_decl|struct
name|em_shared_adapter
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|em_shared_stats
struct_decl|;
end_struct_decl

begin_comment
comment|/* Enumerated types specific to the e1000 hardware */
end_comment

begin_comment
comment|/* Media Access Controlers */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_82542_rev2_0
init|=
literal|0
block|,
name|em_82542_rev2_1
block|,
name|em_82543
block|,
name|em_82544
block|,
name|em_82540
block|,
name|em_num_macs
block|}
name|em_mac_type
typedef|;
end_typedef

begin_comment
comment|/* Media Types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_media_type_copper
init|=
literal|0
block|,
name|em_media_type_fiber
init|=
literal|1
block|,
name|em_num_media_types
block|}
name|em_media_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_10_half
init|=
literal|0
block|,
name|em_10_full
init|=
literal|1
block|,
name|em_100_half
init|=
literal|2
block|,
name|em_100_full
init|=
literal|3
block|}
name|em_speed_duplex_type
typedef|;
end_typedef

begin_comment
comment|/* Flow Control Settings */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_fc_none
init|=
literal|0
block|,
name|em_fc_rx_pause
init|=
literal|1
block|,
name|em_fc_tx_pause
init|=
literal|2
block|,
name|em_fc_full
init|=
literal|3
block|,
name|em_fc_default
init|=
literal|0xFF
block|}
name|em_fc_type
typedef|;
end_typedef

begin_comment
comment|/* PCI bus types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_bus_type_unknown
init|=
literal|0
block|,
name|em_bus_type_pci
block|,
name|em_bus_type_pcix
block|}
name|em_bus_type
typedef|;
end_typedef

begin_comment
comment|/* PCI bus speeds */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_bus_speed_unknown
init|=
literal|0
block|,
name|em_bus_speed_33
block|,
name|em_bus_speed_66
block|,
name|em_bus_speed_100
block|,
name|em_bus_speed_133
block|,
name|em_bus_speed_reserved
block|}
name|em_bus_speed
typedef|;
end_typedef

begin_comment
comment|/* PCI bus widths */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_bus_width_unknown
init|=
literal|0
block|,
name|em_bus_width_32
block|,
name|em_bus_width_64
block|}
name|em_bus_width
typedef|;
end_typedef

begin_comment
comment|/* Function prototypes */
end_comment

begin_comment
comment|/* Setup */
end_comment

begin_function_decl
name|void
name|em_adapter_stop
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_init_hw
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_init_rx_addrs
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Filters (multicast, vlan, receive) */
end_comment

begin_function_decl
name|void
name|em_mc_addr_list_update
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint8_t
modifier|*
name|mc_addr_list
parameter_list|,
name|uint32_t
name|mc_addr_count
parameter_list|,
name|uint32_t
name|pad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|em_hash_mc_addr
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint8_t
modifier|*
name|mc_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_mta_set
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|hash_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_rar_set
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint8_t
modifier|*
name|mc_addr
parameter_list|,
name|uint32_t
name|rar_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_write_vfta
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_clear_vfta
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Link layer setup functions */
end_comment

begin_function_decl
name|boolean_t
name|em_setup_fc_and_link
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_setup_pcs_link
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|dev_ctrl_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_config_fc_after_link_up
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_check_for_link
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_get_speed_and_duplex
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint16_t
modifier|*
name|speed
parameter_list|,
name|uint16_t
modifier|*
name|duplex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EEPROM Functions */
end_comment

begin_function_decl
name|uint16_t
name|em_read_eeprom
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint16_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_validate_eeprom_checksum
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_update_eeprom_checksum
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_write_eeprom
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Everything else */
end_comment

begin_function_decl
name|void
name|em_clear_hw_cntrs
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_read_part_num
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
modifier|*
name|part_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_led_on
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_led_off
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_get_bus_info
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|em_tbi_adjust_stats
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|struct
name|em_shared_stats
modifier|*
name|stats
parameter_list|,
name|uint32_t
name|frame_len
parameter_list|,
name|uint8_t
modifier|*
name|mac_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_write_pci_cfg
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PCI Device IDs */
end_comment

begin_define
define|#
directive|define
name|E1000_DEV_ID_82542
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82543GC_FIBER
value|0x1001
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82543GC_COPPER
value|0x1004
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82544EI_COPPER
value|0x1008
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82544EI_FIBER
value|0x1009
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82544GC_COPPER
value|0x100C
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82544GC_LOM
value|0x100D
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82540EM
value|0x100E
end_define

begin_define
define|#
directive|define
name|NUM_DEV_IDS
value|8
end_define

begin_define
define|#
directive|define
name|NODE_ADDRESS_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|ETH_LENGTH_OF_ADDRESS
value|6
end_define

begin_comment
comment|/* MAC decode size is 128K - This is the size of BAR0 */
end_comment

begin_define
define|#
directive|define
name|MAC_DECODE_SIZE
value|(128 * 1024)
end_define

begin_define
define|#
directive|define
name|E1000_82542_2_0_REV_ID
value|2
end_define

begin_define
define|#
directive|define
name|E1000_82542_2_1_REV_ID
value|3
end_define

begin_define
define|#
directive|define
name|SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|HALF_DUPLEX
value|1
end_define

begin_define
define|#
directive|define
name|FULL_DUPLEX
value|2
end_define

begin_comment
comment|/* The sizes (in bytes) of a ethernet packet */
end_comment

begin_define
define|#
directive|define
name|ENET_HEADER_SIZE
value|14
end_define

begin_define
define|#
directive|define
name|MAXIMUM_ETHERNET_PACKET_SIZE
value|1514
end_define

begin_comment
comment|/* Without FCS */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_ETHERNET_PACKET_SIZE
value|60
end_define

begin_comment
comment|/* Without FCS */
end_comment

begin_define
define|#
directive|define
name|CRC_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|MAX_JUMBO_FRAME_SIZE
value|0x3F00
end_define

begin_comment
comment|/* 802.1q VLAN Packet Sizes */
end_comment

begin_define
define|#
directive|define
name|VLAN_TAG_SIZE
value|4
end_define

begin_comment
comment|/* 802.3ac tag (not DMAed) */
end_comment

begin_comment
comment|/* Ethertype field values */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_IEEE_VLAN_TYPE
value|0x8100
end_define

begin_comment
comment|/* 802.3ac packet */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_IP_TYPE
value|0x0800
end_define

begin_comment
comment|/* IP packets */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_ARP_TYPE
value|0x0806
end_define

begin_comment
comment|/* Address Resolution Protocol (ARP) */
end_comment

begin_comment
comment|/* Packet Header defines */
end_comment

begin_define
define|#
directive|define
name|IP_PROTOCOL_TCP
value|6
end_define

begin_define
define|#
directive|define
name|IP_PROTOCOL_UDP
value|0x11
end_define

begin_comment
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error   */
end_comment

begin_define
define|#
directive|define
name|POLL_IMS_ENABLE_MASK
value|( \     E1000_IMS_RXDMT0 |         \     E1000_IMS_RXSEQ)
end_define

begin_comment
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXT0   = Receiver Timer Interrupt (ring 0)  *   o TXDW   = Transmit Descriptor Written Back  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error  *   o LSC    = Link Status Change  */
end_comment

begin_define
define|#
directive|define
name|IMS_ENABLE_MASK
value|( \     E1000_IMS_RXT0   |    \     E1000_IMS_TXDW   |    \     E1000_IMS_RXDMT0 |    \     E1000_IMS_RXSEQ  |    \     E1000_IMS_LSC)
end_define

begin_comment
comment|/* The number of high/low register pairs in the RAR. The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor. We  * reserve one of these spots for our directed address, allowing us room for  * E1000_RAR_ENTRIES - 1 multicast addresses.   */
end_comment

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES
value|16
end_define

begin_define
define|#
directive|define
name|MIN_NUMBER_OF_DESCRIPTORS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NUMBER_OF_DESCRIPTORS
value|0xFFF8
end_define

begin_comment
comment|/* Receive Descriptor */
end_comment

begin_struct
struct|struct
name|em_rx_desc
block|{
name|uint64_t
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's data buffer */
name|uint16_t
name|length
decl_stmt|;
comment|/* Length of data DMAed into data buffer */
name|uint16_t
name|csum
decl_stmt|;
comment|/* Packet checksum */
name|uint8_t
name|status
decl_stmt|;
comment|/* Descriptor status */
name|uint8_t
name|errors
decl_stmt|;
comment|/* Descriptor Errors */
name|uint16_t
name|special
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Receive Decriptor bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_DD
value|0x01
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_EOP
value|0x02
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_IXSM
value|0x04
end_define

begin_comment
comment|/* Ignore checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_VP
value|0x08
end_define

begin_comment
comment|/* IEEE VLAN Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_TCPCS
value|0x20
end_define

begin_comment
comment|/* TCP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_IPCS
value|0x40
end_define

begin_comment
comment|/* IP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_PIF
value|0x80
end_define

begin_comment
comment|/* passed in-exact filter */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_CE
value|0x01
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_SE
value|0x02
end_define

begin_comment
comment|/* Symbol Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_SEQ
value|0x04
end_define

begin_comment
comment|/* Sequence Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_CXE
value|0x10
end_define

begin_comment
comment|/* Carrier Extension Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_TCPE
value|0x20
end_define

begin_comment
comment|/* TCP/UDP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_IPE
value|0x40
end_define

begin_comment
comment|/* IP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_RXE
value|0x80
end_define

begin_comment
comment|/* Rx Data Error */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_VLAN_MASK
value|0x0FFF
end_define

begin_comment
comment|/* VLAN ID is in lower 12 bits */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_PRI_MASK
value|0xE000
end_define

begin_comment
comment|/* Priority is in upper 3 bits */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_PRI_SHIFT
value|0x000D
end_define

begin_comment
comment|/* Priority is in upper 3 of 16 */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_CFI_MASK
value|0x1000
end_define

begin_comment
comment|/* CFI is bit 12 */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_SPC_CFI_SHIFT
value|0x000C
end_define

begin_comment
comment|/* CFI is bit 12 */
end_comment

begin_comment
comment|/* mask to determine if packets should be dropped due to frame errors */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_ERR_FRAME_ERR_MASK
value|( \     E1000_RXD_ERR_CE  |                \     E1000_RXD_ERR_SE  |                \     E1000_RXD_ERR_SEQ |                \     E1000_RXD_ERR_CXE |                \     E1000_RXD_ERR_RXE)
end_define

begin_comment
comment|/* Transmit Descriptor */
end_comment

begin_struct
struct|struct
name|em_tx_desc
block|{
name|uint64_t
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's data buffer */
union|union
block|{
name|uint32_t
name|data
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|length
decl_stmt|;
comment|/* Data buffer length */
name|uint8_t
name|cso
decl_stmt|;
comment|/* Checksum offset */
name|uint8_t
name|cmd
decl_stmt|;
comment|/* Descriptor control */
block|}
name|flags
struct|;
block|}
name|lower
union|;
union|union
block|{
name|uint32_t
name|data
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|status
decl_stmt|;
comment|/* Descriptor status */
name|uint8_t
name|css
decl_stmt|;
comment|/* Checksum start */
name|uint16_t
name|special
decl_stmt|;
block|}
name|fields
struct|;
block|}
name|upper
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Transmit Descriptor bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_D
value|0x00100000
end_define

begin_comment
comment|/* Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_DTYP_C
value|0x00000000
end_define

begin_comment
comment|/* Context Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_IXSM
value|0x01
end_define

begin_comment
comment|/* Insert IP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_POPTS_TXSM
value|0x02
end_define

begin_comment
comment|/* Insert TCP/UDP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IC
value|0x04000000
end_define

begin_comment
comment|/* Insert Checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_RPS
value|0x10000000
end_define

begin_comment
comment|/* Report Packet Sent */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Descriptor extension (0 = legacy) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* Add VLAN tag */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IDE
value|0x80000000
end_define

begin_comment
comment|/* Enable Tidv register */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_DD
value|0x00000001
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_EC
value|0x00000002
end_define

begin_comment
comment|/* Excess Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_LC
value|0x00000004
end_define

begin_comment
comment|/* Late Collisions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TU
value|0x00000008
end_define

begin_comment
comment|/* Transmit underrun */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TCP
value|0x01000000
end_define

begin_comment
comment|/* TCP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_IP
value|0x02000000
end_define

begin_comment
comment|/* IP packet */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_CMD_TSE
value|0x04000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TXD_STAT_TC
value|0x00000004
end_define

begin_comment
comment|/* Tx Underrun */
end_comment

begin_comment
comment|/* Offload Context Descriptor */
end_comment

begin_struct
struct|struct
name|em_context_desc
block|{
union|union
block|{
name|uint32_t
name|ip_config
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|ipcss
decl_stmt|;
comment|/* IP checksum start */
name|uint8_t
name|ipcso
decl_stmt|;
comment|/* IP checksum offset */
name|uint16_t
name|ipcse
decl_stmt|;
comment|/* IP checksum end */
block|}
name|ip_fields
struct|;
block|}
name|lower_setup
union|;
union|union
block|{
name|uint32_t
name|tcp_config
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|tucss
decl_stmt|;
comment|/* TCP checksum start */
name|uint8_t
name|tucso
decl_stmt|;
comment|/* TCP checksum offset */
name|uint16_t
name|tucse
decl_stmt|;
comment|/* TCP checksum end */
block|}
name|tcp_fields
struct|;
block|}
name|upper_setup
union|;
name|uint32_t
name|cmd_and_length
decl_stmt|;
comment|/* */
union|union
block|{
name|uint32_t
name|data
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|status
decl_stmt|;
comment|/* Descriptor status */
name|uint8_t
name|hdr_len
decl_stmt|;
comment|/* Header length */
name|uint16_t
name|mss
decl_stmt|;
comment|/* Maximum segment size */
block|}
name|fields
struct|;
block|}
name|tcp_seg_setup
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Offload data descriptor */
end_comment

begin_struct
struct|struct
name|em_data_desc
block|{
name|uint64_t
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's buffer address */
union|union
block|{
name|uint32_t
name|data
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|length
decl_stmt|;
comment|/* Data buffer length */
name|uint8_t
name|typ_len_ext
decl_stmt|;
comment|/* */
name|uint8_t
name|cmd
decl_stmt|;
comment|/* */
block|}
name|flags
struct|;
block|}
name|lower
union|;
union|union
block|{
name|uint32_t
name|data
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|status
decl_stmt|;
comment|/* Descriptor status */
name|uint8_t
name|popts
decl_stmt|;
comment|/* Packet Options */
name|uint16_t
name|special
decl_stmt|;
comment|/* */
block|}
name|fields
struct|;
block|}
name|upper
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Filters */
end_comment

begin_define
define|#
directive|define
name|E1000_NUM_UNICAST
value|16
end_define

begin_comment
comment|/* Unicast filter entries */
end_comment

begin_define
define|#
directive|define
name|E1000_MC_TBL_SIZE
value|128
end_define

begin_comment
comment|/* Multicast Filter Table (4096 bits) */
end_comment

begin_define
define|#
directive|define
name|E1000_VLAN_FILTER_TBL_SIZE
value|128
end_define

begin_comment
comment|/* VLAN Filter Table (4096 bits) */
end_comment

begin_comment
comment|/* Receive Address Register */
end_comment

begin_struct
struct|struct
name|em_rar
block|{
specifier|volatile
name|uint32_t
name|low
decl_stmt|;
comment|/* receive address low */
specifier|volatile
name|uint32_t
name|high
decl_stmt|;
comment|/* receive address high */
block|}
struct|;
end_struct

begin_comment
comment|/* The number of entries in the Multicast Table Array (MTA). */
end_comment

begin_define
define|#
directive|define
name|E1000_NUM_MTA_REGISTERS
value|128
end_define

begin_comment
comment|/* IPv4 Address Table Entry */
end_comment

begin_struct
struct|struct
name|em_ipv4_at_entry
block|{
specifier|volatile
name|uint32_t
name|ipv4_addr
decl_stmt|;
comment|/* IP Address (RW) */
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Four wakeup IP addresses are supported */
end_comment

begin_define
define|#
directive|define
name|E1000_WAKEUP_IP_ADDRESS_COUNT_MAX
value|4
end_define

begin_define
define|#
directive|define
name|E1000_IP4AT_SIZE
value|E1000_WAKEUP_IP_ADDRESS_COUNT_MAX
end_define

begin_define
define|#
directive|define
name|E1000_IP6AT_SIZE
value|1
end_define

begin_comment
comment|/* IPv6 Address Table Entry */
end_comment

begin_struct
struct|struct
name|em_ipv6_at_entry
block|{
specifier|volatile
name|uint8_t
name|ipv6_addr
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flexible Filter Length Table Entry */
end_comment

begin_struct
struct|struct
name|em_fflt_entry
block|{
specifier|volatile
name|uint32_t
name|length
decl_stmt|;
comment|/* Flexible Filter Length (RW) */
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flexible Filter Mask Table Entry */
end_comment

begin_struct
struct|struct
name|em_ffmt_entry
block|{
specifier|volatile
name|uint32_t
name|mask
decl_stmt|;
comment|/* Flexible Filter Mask (RW) */
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flexible Filter Value Table Entry */
end_comment

begin_struct
struct|struct
name|em_ffvt_entry
block|{
specifier|volatile
name|uint32_t
name|value
decl_stmt|;
comment|/* Flexible Filter Value (RW) */
specifier|volatile
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Four Flexible Filters are supported */
end_comment

begin_define
define|#
directive|define
name|E1000_FLEXIBLE_FILTER_COUNT_MAX
value|4
end_define

begin_comment
comment|/* Each Flexible Filter is at most 128 (0x80) bytes in length */
end_comment

begin_define
define|#
directive|define
name|E1000_FLEXIBLE_FILTER_SIZE_MAX
value|128
end_define

begin_define
define|#
directive|define
name|E1000_FFLT_SIZE
value|E1000_FLEXIBLE_FILTER_COUNT_MAX
end_define

begin_define
define|#
directive|define
name|E1000_FFMT_SIZE
value|E1000_FLEXIBLE_FILTER_SIZE_MAX
end_define

begin_define
define|#
directive|define
name|E1000_FFVT_SIZE
value|E1000_FLEXIBLE_FILTER_SIZE_MAX
end_define

begin_comment
comment|/* Register Set. (82543, 82544)  *  * Registers are defined to be 32 bits and  should be accessed as 32 bit values.  * These registers are physically located on the NIC, but are mapped into the   * host memory address space.  *  * RW - register is both readable and writable  * RO - register is read only  * WO - register is write only  * R/clr - register is read only and is cleared when read  * A - register array  */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL
value|0x00000
end_define

begin_comment
comment|/* Device Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS
value|0x00008
end_define

begin_comment
comment|/* Device Status - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD
value|0x00010
end_define

begin_comment
comment|/* EEPROM/Flash Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD
value|0x00014
end_define

begin_comment
comment|/* EEPROM Read - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT
value|0x00018
end_define

begin_comment
comment|/* Extended Device Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MDIC
value|0x00020
end_define

begin_comment
comment|/* MDI Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCAL
value|0x00028
end_define

begin_comment
comment|/* Flow Control Address Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCAH
value|0x0002C
end_define

begin_comment
comment|/* Flow Control Address High -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCT
value|0x00030
end_define

begin_comment
comment|/* Flow Control Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VET
value|0x00038
end_define

begin_comment
comment|/* VLAN Ether Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR
value|0x000C0
end_define

begin_comment
comment|/* Interrupt Cause Read - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ITR
value|0x000C4
end_define

begin_comment
comment|/* Interrupt Throttling Rate - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS
value|0x000C8
end_define

begin_comment
comment|/* Interrupt Cause Set - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS
value|0x000D0
end_define

begin_comment
comment|/* Interrupt Mask Set - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC
value|0x000D8
end_define

begin_comment
comment|/* Interrupt Mask Clear - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL
value|0x00100
end_define

begin_comment
comment|/* RX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCTTV
value|0x00170
end_define

begin_comment
comment|/* Flow Control Transmit Timer Value - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW
value|0x00178
end_define

begin_comment
comment|/* TX Configuration Word - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW
value|0x00180
end_define

begin_comment
comment|/* RX Configuration Word - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL
value|0x00400
end_define

begin_comment
comment|/* TX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIPG
value|0x00410
end_define

begin_comment
comment|/* TX Inter-packet gap -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TBT
value|0x00448
end_define

begin_comment
comment|/* TX Burst Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LEDCTL
value|0x00E00
end_define

begin_comment
comment|/* LED Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA
value|0x01000
end_define

begin_comment
comment|/* Packet Buffer Allocation - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL
value|0x02160
end_define

begin_comment
comment|/* Flow Control Receive Threshold Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH
value|0x02168
end_define

begin_comment
comment|/* Flow Control Receive Threshold High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAL
value|0x02800
end_define

begin_comment
comment|/* RX Descriptor Base Address Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAH
value|0x02804
end_define

begin_comment
comment|/* RX Descriptor Base Address High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDLEN
value|0x02808
end_define

begin_comment
comment|/* RX Descriptor Length - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDH
value|0x02810
end_define

begin_comment
comment|/* RX Descriptor Head - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT
value|0x02818
end_define

begin_comment
comment|/* RX Descriptor Tail - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDTR
value|0x02820
end_define

begin_comment
comment|/* RX Delay Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL
value|0x02828
end_define

begin_comment
comment|/* RX Descriptor Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RADV
value|0x0282C
end_define

begin_comment
comment|/* RX Interrupt Absolute Delay Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RSRPD
value|0x02C00
end_define

begin_comment
comment|/* RX Small Packet Detect - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDMAC
value|0x03000
end_define

begin_comment
comment|/* TX DMA Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDBAL
value|0x03800
end_define

begin_comment
comment|/* TX Descriptor Base Address Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDBAH
value|0x03804
end_define

begin_comment
comment|/* TX Descriptor Base Address High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDLEN
value|0x03808
end_define

begin_comment
comment|/* TX Descriptor Length - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDH
value|0x03810
end_define

begin_comment
comment|/* TX Descriptor Head - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDT
value|0x03818
end_define

begin_comment
comment|/* TX Descripotr Tail - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIDV
value|0x03820
end_define

begin_comment
comment|/* TX Interrupt Delay Value - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL
value|0x03828
end_define

begin_comment
comment|/* TX Descriptor Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TADV
value|0x0382C
end_define

begin_comment
comment|/* TX Interrupt Absolute Delay Val - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TSPMT
value|0x03830
end_define

begin_comment
comment|/* TCP Segmentation PAD& Min Threshold - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CRCERRS
value|0x04000
end_define

begin_comment
comment|/* CRC Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ALGNERRC
value|0x04004
end_define

begin_comment
comment|/* Alignment Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SYMERRS
value|0x04008
end_define

begin_comment
comment|/* Symbol Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RXERRC
value|0x0400C
end_define

begin_comment
comment|/* Receive Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPC
value|0x04010
end_define

begin_comment
comment|/* Missed Packet Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SCC
value|0x04014
end_define

begin_comment
comment|/* Single Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ECOL
value|0x04018
end_define

begin_comment
comment|/* Excessive Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MCC
value|0x0401C
end_define

begin_comment
comment|/* Multiple Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_LATECOL
value|0x04020
end_define

begin_comment
comment|/* Late Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_COLC
value|0x04028
end_define

begin_comment
comment|/* Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_DC
value|0x04030
end_define

begin_comment
comment|/* Defer Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TNCRS
value|0x04034
end_define

begin_comment
comment|/* TX-No CRS - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SEC
value|0x04038
end_define

begin_comment
comment|/* Sequence Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_CEXTERR
value|0x0403C
end_define

begin_comment
comment|/* Carrier Extension Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RLEC
value|0x04040
end_define

begin_comment
comment|/* Receive Length Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XONRXC
value|0x04048
end_define

begin_comment
comment|/* XON RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XONTXC
value|0x0404C
end_define

begin_comment
comment|/* XON TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFRXC
value|0x04050
end_define

begin_comment
comment|/* XOFF RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFTXC
value|0x04054
end_define

begin_comment
comment|/* XOFF TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRUC
value|0x04058
end_define

begin_comment
comment|/* Flow Control RX Unsupported Count- R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC64
value|0x0405C
end_define

begin_comment
comment|/* Packets RX (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC127
value|0x04060
end_define

begin_comment
comment|/* Packets RX (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC255
value|0x04064
end_define

begin_comment
comment|/* Packets RX (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC511
value|0x04068
end_define

begin_comment
comment|/* Packets RX (255-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1023
value|0x0406C
end_define

begin_comment
comment|/* Packets RX (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1522
value|0x04070
end_define

begin_comment
comment|/* Packets RX (1024-1522 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPRC
value|0x04074
end_define

begin_comment
comment|/* Good Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPRC
value|0x04078
end_define

begin_comment
comment|/* Broadcast Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPRC
value|0x0407C
end_define

begin_comment
comment|/* Multicast Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPTC
value|0x04080
end_define

begin_comment
comment|/* Good Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCL
value|0x04088
end_define

begin_comment
comment|/* Good Octets RX Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCH
value|0x0408C
end_define

begin_comment
comment|/* Good Octets RX Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCL
value|0x04090
end_define

begin_comment
comment|/* Good Octets TX Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCH
value|0x04094
end_define

begin_comment
comment|/* Good Octets TX Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RNBC
value|0x040A0
end_define

begin_comment
comment|/* RX No Buffers Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RUC
value|0x040A4
end_define

begin_comment
comment|/* RX Undersize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RFC
value|0x040A8
end_define

begin_comment
comment|/* RX Fragment Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ROC
value|0x040AC
end_define

begin_comment
comment|/* RX Oversize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RJC
value|0x040B0
end_define

begin_comment
comment|/* RX Jabber Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPRC
value|0x040B4
end_define

begin_comment
comment|/* Management Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPDC
value|0x040B8
end_define

begin_comment
comment|/* Management Packets Dropped Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPTC
value|0x040BC
end_define

begin_comment
comment|/* Management Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORL
value|0x040C0
end_define

begin_comment
comment|/* Total Octets RX Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORH
value|0x040C4
end_define

begin_comment
comment|/* Total Octets RX High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTL
value|0x040C8
end_define

begin_comment
comment|/* Total Octets TX Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTH
value|0x040CC
end_define

begin_comment
comment|/* Total Octets TX High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPR
value|0x040D0
end_define

begin_comment
comment|/* Total Packets RX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPT
value|0x040D4
end_define

begin_comment
comment|/* Total Packets TX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC64
value|0x040D8
end_define

begin_comment
comment|/* Packets TX (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC127
value|0x040DC
end_define

begin_comment
comment|/* Packets TX (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC255
value|0x040E0
end_define

begin_comment
comment|/* Packets TX (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC511
value|0x040E4
end_define

begin_comment
comment|/* Packets TX (256-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1023
value|0x040E8
end_define

begin_comment
comment|/* Packets TX (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1522
value|0x040EC
end_define

begin_comment
comment|/* Packets TX (1024-1522 Bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPTC
value|0x040F0
end_define

begin_comment
comment|/* Multicast Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPTC
value|0x040F4
end_define

begin_comment
comment|/* Broadcast Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTC
value|0x040F8
end_define

begin_comment
comment|/* TCP Segmentation Context TX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTFC
value|0x040FC
end_define

begin_comment
comment|/* TCP Segmentation Context TX Fail - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM
value|0x05000
end_define

begin_comment
comment|/* RX Checksum Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MTA
value|0x05200
end_define

begin_comment
comment|/* Multicast Table Array - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RA
value|0x05400
end_define

begin_comment
comment|/* Receive Address - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_VFTA
value|0x05600
end_define

begin_comment
comment|/* VLAN Filter Table Array - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC
value|0x05800
end_define

begin_comment
comment|/* Wakeup Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC
value|0x05808
end_define

begin_comment
comment|/* Wakeup Filter Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS
value|0x05810
end_define

begin_comment
comment|/* Wakeup Status - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC
value|0x05820
end_define

begin_comment
comment|/* Management Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPAV
value|0x05838
end_define

begin_comment
comment|/* IP Address Valid - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IP4AT
value|0x05840
end_define

begin_comment
comment|/* IPv4 Address Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_IP6AT
value|0x05880
end_define

begin_comment
comment|/* IPv6 Address Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPL
value|0x05900
end_define

begin_comment
comment|/* Wakeup Packet Length - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPM
value|0x05A00
end_define

begin_comment
comment|/* Wakeup Packet Memory - RO A */
end_comment

begin_define
define|#
directive|define
name|E1000_FFLT
value|0x05F00
end_define

begin_comment
comment|/* Flexible Filter Length Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_FFMT
value|0x09000
end_define

begin_comment
comment|/* Flexible Filter Mask Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_FFVT
value|0x09800
end_define

begin_comment
comment|/* Flexible Filter Value Table - RW Array */
end_comment

begin_comment
comment|/* Register Set (82542)  *  * Some of the 82542 registers are located at different offsets than they are  * in more current versions of the 8254x. Despite the difference in location,  * the registers function in the same manner.  */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_CTRL
value|E1000_CTRL
end_define

begin_define
define|#
directive|define
name|E1000_82542_STATUS
value|E1000_STATUS
end_define

begin_define
define|#
directive|define
name|E1000_82542_EECD
value|E1000_EECD
end_define

begin_define
define|#
directive|define
name|E1000_82542_EERD
value|E1000_EERD
end_define

begin_define
define|#
directive|define
name|E1000_82542_CTRL_EXT
value|E1000_CTRL_EXT
end_define

begin_define
define|#
directive|define
name|E1000_82542_MDIC
value|E1000_MDIC
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCAL
value|E1000_FCAL
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCAH
value|E1000_FCAH
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCT
value|E1000_FCT
end_define

begin_define
define|#
directive|define
name|E1000_82542_VET
value|E1000_VET
end_define

begin_define
define|#
directive|define
name|E1000_82542_RA
value|0x00040
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICR
value|E1000_ICR
end_define

begin_define
define|#
directive|define
name|E1000_82542_ITR
value|E1000_ITR
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICS
value|E1000_ICS
end_define

begin_define
define|#
directive|define
name|E1000_82542_IMS
value|E1000_IMS
end_define

begin_define
define|#
directive|define
name|E1000_82542_IMC
value|E1000_IMC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RCTL
value|E1000_RCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDTR
value|0x00108
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAL
value|0x00110
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAH
value|0x00114
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDLEN
value|0x00118
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDH
value|0x00120
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDT
value|0x00128
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCRTH
value|0x00160
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCRTL
value|0x00168
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCTTV
value|E1000_FCTTV
end_define

begin_define
define|#
directive|define
name|E1000_82542_TXCW
value|E1000_TXCW
end_define

begin_define
define|#
directive|define
name|E1000_82542_RXCW
value|E1000_RXCW
end_define

begin_define
define|#
directive|define
name|E1000_82542_MTA
value|0x00200
end_define

begin_define
define|#
directive|define
name|E1000_82542_TCTL
value|E1000_TCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_TIPG
value|E1000_TIPG
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDBAL
value|0x00420
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDBAH
value|0x00424
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDLEN
value|0x00428
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDH
value|0x00430
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDT
value|0x00438
end_define

begin_define
define|#
directive|define
name|E1000_82542_TIDV
value|0x00440
end_define

begin_define
define|#
directive|define
name|E1000_82542_TBT
value|E1000_TBT
end_define

begin_define
define|#
directive|define
name|E1000_82542_VFTA
value|0x00600
end_define

begin_define
define|#
directive|define
name|E1000_82542_LEDCTL
value|E1000_LEDCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_PBA
value|E1000_PBA
end_define

begin_define
define|#
directive|define
name|E1000_82542_RXDCTL
value|E1000_RXDCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_RADV
value|E1000_RADV
end_define

begin_define
define|#
directive|define
name|E1000_82542_RSRPD
value|E1000_RSRPD
end_define

begin_define
define|#
directive|define
name|E1000_82542_TXDMAC
value|E1000_TXDMAC
end_define

begin_define
define|#
directive|define
name|E1000_82542_TXDCTL
value|E1000_TXDCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_TADV
value|E1000_TADV
end_define

begin_define
define|#
directive|define
name|E1000_82542_TSPMT
value|E1000_TSPMT
end_define

begin_define
define|#
directive|define
name|E1000_82542_CRCERRS
value|E1000_CRCERRS
end_define

begin_define
define|#
directive|define
name|E1000_82542_ALGNERRC
value|E1000_ALGNERRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_SYMERRS
value|E1000_SYMERRS
end_define

begin_define
define|#
directive|define
name|E1000_82542_RXERRC
value|E1000_RXERRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MPC
value|E1000_MPC
end_define

begin_define
define|#
directive|define
name|E1000_82542_SCC
value|E1000_SCC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ECOL
value|E1000_ECOL
end_define

begin_define
define|#
directive|define
name|E1000_82542_MCC
value|E1000_MCC
end_define

begin_define
define|#
directive|define
name|E1000_82542_LATECOL
value|E1000_LATECOL
end_define

begin_define
define|#
directive|define
name|E1000_82542_COLC
value|E1000_COLC
end_define

begin_define
define|#
directive|define
name|E1000_82542_DC
value|E1000_DC
end_define

begin_define
define|#
directive|define
name|E1000_82542_TNCRS
value|E1000_TNCRS
end_define

begin_define
define|#
directive|define
name|E1000_82542_SEC
value|E1000_SEC
end_define

begin_define
define|#
directive|define
name|E1000_82542_CEXTERR
value|E1000_CEXTERR
end_define

begin_define
define|#
directive|define
name|E1000_82542_RLEC
value|E1000_RLEC
end_define

begin_define
define|#
directive|define
name|E1000_82542_XONRXC
value|E1000_XONRXC
end_define

begin_define
define|#
directive|define
name|E1000_82542_XONTXC
value|E1000_XONTXC
end_define

begin_define
define|#
directive|define
name|E1000_82542_XOFFRXC
value|E1000_XOFFRXC
end_define

begin_define
define|#
directive|define
name|E1000_82542_XOFFTXC
value|E1000_XOFFTXC
end_define

begin_define
define|#
directive|define
name|E1000_82542_FCRUC
value|E1000_FCRUC
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC64
value|E1000_PRC64
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC127
value|E1000_PRC127
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC255
value|E1000_PRC255
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC511
value|E1000_PRC511
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC1023
value|E1000_PRC1023
end_define

begin_define
define|#
directive|define
name|E1000_82542_PRC1522
value|E1000_PRC1522
end_define

begin_define
define|#
directive|define
name|E1000_82542_GPRC
value|E1000_GPRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_BPRC
value|E1000_BPRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MPRC
value|E1000_MPRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_GPTC
value|E1000_GPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_GORCL
value|E1000_GORCL
end_define

begin_define
define|#
directive|define
name|E1000_82542_GORCH
value|E1000_GORCH
end_define

begin_define
define|#
directive|define
name|E1000_82542_GOTCL
value|E1000_GOTCL
end_define

begin_define
define|#
directive|define
name|E1000_82542_GOTCH
value|E1000_GOTCH
end_define

begin_define
define|#
directive|define
name|E1000_82542_RNBC
value|E1000_RNBC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RUC
value|E1000_RUC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RFC
value|E1000_RFC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ROC
value|E1000_ROC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RJC
value|E1000_RJC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MGTPRC
value|E1000_MGTPRC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MGTPDC
value|E1000_MGTPDC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MGTPTC
value|E1000_MGTPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_TORL
value|E1000_TORL
end_define

begin_define
define|#
directive|define
name|E1000_82542_TORH
value|E1000_TORH
end_define

begin_define
define|#
directive|define
name|E1000_82542_TOTL
value|E1000_TOTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_TOTH
value|E1000_TOTH
end_define

begin_define
define|#
directive|define
name|E1000_82542_TPR
value|E1000_TPR
end_define

begin_define
define|#
directive|define
name|E1000_82542_TPT
value|E1000_TPT
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC64
value|E1000_PTC64
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC127
value|E1000_PTC127
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC255
value|E1000_PTC255
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC511
value|E1000_PTC511
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC1023
value|E1000_PTC1023
end_define

begin_define
define|#
directive|define
name|E1000_82542_PTC1522
value|E1000_PTC1522
end_define

begin_define
define|#
directive|define
name|E1000_82542_MPTC
value|E1000_MPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_BPTC
value|E1000_BPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_TSCTC
value|E1000_TSCTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_TSCTFC
value|E1000_TSCTFC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RXCSUM
value|E1000_RXCSUM
end_define

begin_define
define|#
directive|define
name|E1000_82542_WUC
value|E1000_WUC
end_define

begin_define
define|#
directive|define
name|E1000_82542_WUFC
value|E1000_WUFC
end_define

begin_define
define|#
directive|define
name|E1000_82542_WUS
value|E1000_WUS
end_define

begin_define
define|#
directive|define
name|E1000_82542_MANC
value|E1000_MANC
end_define

begin_define
define|#
directive|define
name|E1000_82542_IPAV
value|E1000_IPAV
end_define

begin_define
define|#
directive|define
name|E1000_82542_IP4AT
value|E1000_IP4AT
end_define

begin_define
define|#
directive|define
name|E1000_82542_IP6AT
value|E1000_IP6AT
end_define

begin_define
define|#
directive|define
name|E1000_82542_WUPL
value|E1000_WUPL
end_define

begin_define
define|#
directive|define
name|E1000_82542_WUPM
value|E1000_WUPM
end_define

begin_define
define|#
directive|define
name|E1000_82542_FFLT
value|E1000_FFLT
end_define

begin_define
define|#
directive|define
name|E1000_82542_FFMT
value|E1000_FFMT
end_define

begin_define
define|#
directive|define
name|E1000_82542_FFVT
value|E1000_FFVT
end_define

begin_comment
comment|/* Statistics counters collected by the MAC */
end_comment

begin_struct
struct|struct
name|em_shared_stats
block|{
name|uint64_t
name|crcerrs
decl_stmt|;
name|uint64_t
name|algnerrc
decl_stmt|;
name|uint64_t
name|symerrs
decl_stmt|;
name|uint64_t
name|rxerrc
decl_stmt|;
name|uint64_t
name|mpc
decl_stmt|;
name|uint64_t
name|scc
decl_stmt|;
name|uint64_t
name|ecol
decl_stmt|;
name|uint64_t
name|mcc
decl_stmt|;
name|uint64_t
name|latecol
decl_stmt|;
name|uint64_t
name|colc
decl_stmt|;
name|uint64_t
name|dc
decl_stmt|;
name|uint64_t
name|tncrs
decl_stmt|;
name|uint64_t
name|sec
decl_stmt|;
name|uint64_t
name|cexterr
decl_stmt|;
name|uint64_t
name|rlec
decl_stmt|;
name|uint64_t
name|xonrxc
decl_stmt|;
name|uint64_t
name|xontxc
decl_stmt|;
name|uint64_t
name|xoffrxc
decl_stmt|;
name|uint64_t
name|xofftxc
decl_stmt|;
name|uint64_t
name|fcruc
decl_stmt|;
name|uint64_t
name|prc64
decl_stmt|;
name|uint64_t
name|prc127
decl_stmt|;
name|uint64_t
name|prc255
decl_stmt|;
name|uint64_t
name|prc511
decl_stmt|;
name|uint64_t
name|prc1023
decl_stmt|;
name|uint64_t
name|prc1522
decl_stmt|;
name|uint64_t
name|gprc
decl_stmt|;
name|uint64_t
name|bprc
decl_stmt|;
name|uint64_t
name|mprc
decl_stmt|;
name|uint64_t
name|gptc
decl_stmt|;
name|uint64_t
name|gorcl
decl_stmt|;
name|uint64_t
name|gorch
decl_stmt|;
name|uint64_t
name|gotcl
decl_stmt|;
name|uint64_t
name|gotch
decl_stmt|;
name|uint64_t
name|rnbc
decl_stmt|;
name|uint64_t
name|ruc
decl_stmt|;
name|uint64_t
name|rfc
decl_stmt|;
name|uint64_t
name|roc
decl_stmt|;
name|uint64_t
name|rjc
decl_stmt|;
name|uint64_t
name|mgprc
decl_stmt|;
name|uint64_t
name|mgpdc
decl_stmt|;
name|uint64_t
name|mgptc
decl_stmt|;
name|uint64_t
name|torl
decl_stmt|;
name|uint64_t
name|torh
decl_stmt|;
name|uint64_t
name|totl
decl_stmt|;
name|uint64_t
name|toth
decl_stmt|;
name|uint64_t
name|tpr
decl_stmt|;
name|uint64_t
name|tpt
decl_stmt|;
name|uint64_t
name|ptc64
decl_stmt|;
name|uint64_t
name|ptc127
decl_stmt|;
name|uint64_t
name|ptc255
decl_stmt|;
name|uint64_t
name|ptc511
decl_stmt|;
name|uint64_t
name|ptc1023
decl_stmt|;
name|uint64_t
name|ptc1522
decl_stmt|;
name|uint64_t
name|mptc
decl_stmt|;
name|uint64_t
name|bptc
decl_stmt|;
name|uint64_t
name|tsctc
decl_stmt|;
name|uint64_t
name|tsctfc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure containing variables used by the shared code (em_mac.c and   * em_phy.c)  */
end_comment

begin_struct
struct|struct
name|em_shared_adapter
block|{
name|uint8_t
modifier|*
name|hw_addr
decl_stmt|;
name|em_mac_type
name|mac_type
decl_stmt|;
name|em_media_type
name|media_type
decl_stmt|;
name|void
modifier|*
name|back
decl_stmt|;
name|em_fc_type
name|fc
decl_stmt|;
name|em_bus_speed
name|bus_speed
decl_stmt|;
name|em_bus_width
name|bus_width
decl_stmt|;
name|em_bus_type
name|bus_type
decl_stmt|;
name|uint32_t
name|phy_id
decl_stmt|;
name|uint32_t
name|phy_addr
decl_stmt|;
name|uint32_t
name|original_fc
decl_stmt|;
name|uint32_t
name|txcw_reg
decl_stmt|;
name|uint32_t
name|autoneg_failed
decl_stmt|;
name|uint32_t
name|max_frame_size
decl_stmt|;
name|uint32_t
name|min_frame_size
decl_stmt|;
name|uint32_t
name|mc_filter_type
decl_stmt|;
name|uint32_t
name|num_mc_addrs
decl_stmt|;
name|uint16_t
name|autoneg_advertised
decl_stmt|;
name|uint16_t
name|pci_cmd_word
decl_stmt|;
name|uint16_t
name|fc_high_water
decl_stmt|;
name|uint16_t
name|fc_low_water
decl_stmt|;
name|uint16_t
name|fc_pause_time
decl_stmt|;
name|uint16_t
name|device_id
decl_stmt|;
name|uint16_t
name|vendor_id
decl_stmt|;
name|uint16_t
name|subsystem_id
decl_stmt|;
name|uint16_t
name|subsystem_vendor_id
decl_stmt|;
name|uint8_t
name|revision_id
decl_stmt|;
name|boolean_t
name|disable_polarity_correction
decl_stmt|;
name|boolean_t
name|get_link_status
decl_stmt|;
name|boolean_t
name|tbi_compatibility_en
decl_stmt|;
name|boolean_t
name|tbi_compatibility_on
decl_stmt|;
name|boolean_t
name|adapter_stopped
decl_stmt|;
name|boolean_t
name|fc_send_xon
decl_stmt|;
name|boolean_t
name|report_tx_early
decl_stmt|;
name|boolean_t
name|low_profile
decl_stmt|;
name|uint8_t
name|autoneg
decl_stmt|;
name|uint8_t
name|mdix
decl_stmt|;
name|uint8_t
name|forced_speed_duplex
decl_stmt|;
name|uint8_t
name|wait_autoneg_complete
decl_stmt|;
name|uint8_t
name|dma_fairness
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|NODE_ADDRESS_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E1000_EEPROM_SWDPIN0
value|0x0001
end_define

begin_comment
comment|/* SWDPIN 0 EEPROM Value */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_LED_LOGIC
value|0x0020
end_define

begin_comment
comment|/* Led Logic Word */
end_comment

begin_comment
comment|/* Register Bit Masks */
end_comment

begin_comment
comment|/* Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FD
value|0x00000001
end_define

begin_comment
comment|/* Full duplex.0=half; 1=full */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_BEM
value|0x00000002
end_define

begin_comment
comment|/* Endian Mode.0=little,1=big */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PRIOR
value|0x00000004
end_define

begin_comment
comment|/* Priority on PCI. 0=rx,1=fair */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_LRST
value|0x00000008
end_define

begin_comment
comment|/* Link reset. 0=normal,1=reset */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_TME
value|0x00000010
end_define

begin_comment
comment|/* Test mode. 0=normal,1=test */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SLE
value|0x00000020
end_define

begin_comment
comment|/* Serial Link on 0=dis,1=en */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_ASDE
value|0x00000020
end_define

begin_comment
comment|/* Auto-speed detect enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SLU
value|0x00000040
end_define

begin_comment
comment|/* Set link up (Force Link) */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_ILOS
value|0x00000080
end_define

begin_comment
comment|/* Invert Loss-Of Signal */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_SEL
value|0x00000300
end_define

begin_comment
comment|/* Speed Select Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_10
value|0x00000000
end_define

begin_comment
comment|/* Force 10Mb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_100
value|0x00000100
end_define

begin_comment
comment|/* Force 100Mb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SPD_1000
value|0x00000200
end_define

begin_comment
comment|/* Force 1Gb */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_BEM32
value|0x00000400
end_define

begin_comment
comment|/* Big Endian 32 mode */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FRCSPD
value|0x00000800
end_define

begin_comment
comment|/* Force Speed */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FRCDPX
value|0x00001000
end_define

begin_comment
comment|/* Force Duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN0
value|0x00040000
end_define

begin_comment
comment|/* SWDPIN 0 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN1
value|0x00080000
end_define

begin_comment
comment|/* SWDPIN 1 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN2
value|0x00100000
end_define

begin_comment
comment|/* SWDPIN 2 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIN3
value|0x00200000
end_define

begin_comment
comment|/* SWDPIN 3 value */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO0
value|0x00400000
end_define

begin_comment
comment|/* SWDPIN 0 Input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO1
value|0x00800000
end_define

begin_comment
comment|/* SWDPIN 1 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO2
value|0x01000000
end_define

begin_comment
comment|/* SWDPIN 2 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_SWDPIO3
value|0x02000000
end_define

begin_comment
comment|/* SWDPIN 3 input or output */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RST
value|0x04000000
end_define

begin_comment
comment|/* Global reset */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RFCE
value|0x08000000
end_define

begin_comment
comment|/* Receive Flow Control enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_TFCE
value|0x10000000
end_define

begin_comment
comment|/* Transmit flow control enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_RTE
value|0x20000000
end_define

begin_comment
comment|/* Routing tag enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_VME
value|0x40000000
end_define

begin_comment
comment|/* IEEE VLAN mode enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RST
value|0x80000000
end_define

begin_comment
comment|/* PHY Reset */
end_comment

begin_comment
comment|/* Device Status */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FD
value|0x00000001
end_define

begin_comment
comment|/* Full duplex.0=half,1=full */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_LU
value|0x00000002
end_define

begin_comment
comment|/* Link up.0=no,1=link */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_MASK
value|0x0000000C
end_define

begin_comment
comment|/* PCI Function Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_0
value|0x00000000
end_define

begin_comment
comment|/* Function 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUNC_1
value|0x00000004
end_define

begin_comment
comment|/* Function 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_TXOFF
value|0x00000010
end_define

begin_comment
comment|/* transmission paused */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_TBIMODE
value|0x00000020
end_define

begin_comment
comment|/* TBI mode */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_10
value|0x00000000
end_define

begin_comment
comment|/* Speed 10Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_100
value|0x00000040
end_define

begin_comment
comment|/* Speed 100Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SPEED_1000
value|0x00000080
end_define

begin_comment
comment|/* Speed 1000Mb/s */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_ASDV
value|0x00000300
end_define

begin_comment
comment|/* Auto speed detect value */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_MTXCKOK
value|0x00000400
end_define

begin_comment
comment|/* MTX clock running OK */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCI66
value|0x00000800
end_define

begin_comment
comment|/* In 66Mhz slot */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BUS64
value|0x00001000
end_define

begin_comment
comment|/* In 64 bit slot */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_MODE
value|0x00002000
end_define

begin_comment
comment|/* PCI-X mode */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED
value|0x0000C000
end_define

begin_comment
comment|/* PCI-X bus speed */
end_comment

begin_comment
comment|/* Constants used to intrepret the masked PCI-X bus speed. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_66
value|0x00000000
end_define

begin_comment
comment|/* PCI-X bus speed  50-66 MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_100
value|0x00004000
end_define

begin_comment
comment|/* PCI-X bus speed  66-100 MHz */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_PCIX_SPEED_133
value|0x00008000
end_define

begin_comment
comment|/* PCI-X bus speed 100-133 MHz */
end_comment

begin_comment
comment|/* EEPROM/Flash Control */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SK
value|0x00000001
end_define

begin_comment
comment|/* EEPROM Clock */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_CS
value|0x00000002
end_define

begin_comment
comment|/* EEPROM Chip Select */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_DI
value|0x00000004
end_define

begin_comment
comment|/* EEPROM Data In */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_DO
value|0x00000008
end_define

begin_comment
comment|/* EEPROM Data Out */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|E1000_EECD_FWE_DIS
value|0x00000010
end_define

begin_comment
comment|/* Disable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_EN
value|0x00000020
end_define

begin_comment
comment|/* Enable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FWE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|E1000_EECD_SIZE
value|0x00000200
end_define

begin_comment
comment|/* EEPROM Size (0=64 word 1=256 word) */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_REQ
value|0x00000040
end_define

begin_comment
comment|/* EEPROM Access Request */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_GNT
value|0x00000080
end_define

begin_comment
comment|/* EEPROM Access Grant */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_PRES
value|0x00000100
end_define

begin_comment
comment|/* EEPROM Present */
end_comment

begin_comment
comment|/* EEPROM Read */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD_START
value|0x00000001
end_define

begin_comment
comment|/* Start Read */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD_DONE
value|0x00000010
end_define

begin_comment
comment|/* Read Done */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_EERD_ADDR_MASK
value|0x0000FF00
end_define

begin_comment
comment|/* Read Address */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_EERD_DATA_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* Read Data */
end_comment

begin_comment
comment|/* Extended Device Control */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI0_EN
value|0x00000001
end_define

begin_comment
comment|/* Maps SDP4 to GPI0 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI1_EN
value|0x00000002
end_define

begin_comment
comment|/* Maps SDP5 to GPI1 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PHYINT_EN
value|E1000_CTRL_EXT_GPI1_EN
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI2_EN
value|0x00000004
end_define

begin_comment
comment|/* Maps SDP6 to GPI2 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GPI3_EN
value|0x00000008
end_define

begin_comment
comment|/* Maps SDP7 to GPI3 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP4_DATA
value|0x00000010
end_define

begin_comment
comment|/* Value of SW Defineable Pin 4 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP5_DATA
value|0x00000020
end_define

begin_comment
comment|/* Value of SW Defineable Pin 5 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_PHY_INT
value|E1000_CTRL_EXT_SDP5_DATA
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP6_DATA
value|0x00000040
end_define

begin_comment
comment|/* Value of SW Defineable Pin 6 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP7_DATA
value|0x00000080
end_define

begin_comment
comment|/* Value of SW Defineable Pin 7 */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP4_DIR
value|0x00000100
end_define

begin_comment
comment|/* Direction of SDP4 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP5_DIR
value|0x00000200
end_define

begin_comment
comment|/* Direction of SDP5 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP6_DIR
value|0x00000400
end_define

begin_comment
comment|/* Direction of SDP6 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SDP7_DIR
value|0x00000800
end_define

begin_comment
comment|/* Direction of SDP7 0=in 1=out */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_ASDCHK
value|0x00001000
end_define

begin_comment
comment|/* Initiate an ASD sequence */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_EE_RST
value|0x00002000
end_define

begin_comment
comment|/* Reinitialize from EEPROM */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IPS
value|0x00004000
end_define

begin_comment
comment|/* Invert Power State */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_SPD_BYPS
value|0x00008000
end_define

begin_comment
comment|/* Speed Select Bypass */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_MASK
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_GMII
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_TBI
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_256
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_320
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_384
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_WR_WMARK_448
value|0x03000000
end_define

begin_comment
comment|/* MDI Control */
end_comment

begin_define
define|#
directive|define
name|E1000_MDIC_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_REG_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_REG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_PHY_MASK
value|0x03E00000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_PHY_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_OP_WRITE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_OP_READ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_READY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_INT_EN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_MDIC_ERROR
value|0x40000000
end_define

begin_comment
comment|/* LED Control */
end_comment

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_MODE_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_IVRT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED0_BLINK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_MODE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_MODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_IVRT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED1_BLINK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_MODE_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_IVRT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED2_BLINK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_MODE_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_MODE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_IVRT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_LED3_BLINK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_10_1000
value|0x0
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_100_1000
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_UP
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_ACTIVITY
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_ACTIVITY
value|0x4
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_10
value|0x5
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_100
value|0x6
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LINK_1000
value|0x7
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_PCIX_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_FULL_DUPLEX
value|0x9
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_COLLISION
value|0xA
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_BUS_SPEED
value|0xB
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_BUS_SIZE
value|0xC
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_PAUSED
value|0xD
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LED_ON
value|0xE
end_define

begin_define
define|#
directive|define
name|E1000_LEDCTL_MODE_LED_OFF
value|0xF
end_define

begin_comment
comment|/* Receive Address */
end_comment

begin_define
define|#
directive|define
name|E1000_RAH_AV
value|0x80000000
end_define

begin_comment
comment|/* Receive descriptor valid */
end_comment

begin_comment
comment|/* Interrupt Cause Read */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXDW
value|0x00000001
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXQE
value|0x00000002
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_LSC
value|0x00000004
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXSEQ
value|0x00000008
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXDMT0
value|0x00000010
end_define

begin_comment
comment|/* rx desc min. threshold (0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXO
value|0x00000040
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXT0
value|0x00000080
end_define

begin_comment
comment|/* rx timer intr (ring 0) */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_MDAC
value|0x00000200
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXCFG
value|0x00000400
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN0
value|0x00000800
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN1
value|0x00001000
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN2
value|0x00002000
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_GPI_EN3
value|0x00004000
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_LOW
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_ICR_SRPD
value|0x00010000
end_define

begin_comment
comment|/* Interrupt Cause Set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXDW
value|E1000_ICR_TXDW
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXQE
value|E1000_ICR_TXQE
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_LSC
value|E1000_ICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* rx timer intr */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_MDAC
value|E1000_ICR_MDAC
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXCFG
value|E1000_ICR_RXCFG
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN0
value|E1000_ICR_GPI_EN0
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN1
value|E1000_ICR_GPI_EN1
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN2
value|E1000_ICR_GPI_EN2
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_GPI_EN3
value|E1000_ICR_GPI_EN3
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_LOW
value|E1000_ICR_TXD_LOW
end_define

begin_define
define|#
directive|define
name|E1000_ICS_SRPD
value|E1000_ICR_SRPD
end_define

begin_comment
comment|/* Interrupt Mask Set */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXDW
value|E1000_ICR_TXDW
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXQE
value|E1000_ICR_TXQE
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_LSC
value|E1000_ICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* rx timer intr */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_MDAC
value|E1000_ICR_MDAC
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXCFG
value|E1000_ICR_RXCFG
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN0
value|E1000_ICR_GPI_EN0
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN1
value|E1000_ICR_GPI_EN1
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN2
value|E1000_ICR_GPI_EN2
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_GPI_EN3
value|E1000_ICR_GPI_EN3
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_LOW
value|E1000_ICR_TXD_LOW
end_define

begin_define
define|#
directive|define
name|E1000_IMS_SRPD
value|E1000_ICR_SRPD
end_define

begin_comment
comment|/* Interrupt Mask Clear */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_TXDW
value|E1000_ICR_TXDW
end_define

begin_comment
comment|/* Transmit desc written back */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_TXQE
value|E1000_ICR_TXQE
end_define

begin_comment
comment|/* Transmit Queue empty */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_LSC
value|E1000_ICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXSEQ
value|E1000_ICR_RXSEQ
end_define

begin_comment
comment|/* rx sequence error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXDMT0
value|E1000_ICR_RXDMT0
end_define

begin_comment
comment|/* rx desc min. threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXO
value|E1000_ICR_RXO
end_define

begin_comment
comment|/* rx overrun */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXT0
value|E1000_ICR_RXT0
end_define

begin_comment
comment|/* rx timer intr */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_MDAC
value|E1000_ICR_MDAC
end_define

begin_comment
comment|/* MDIO access complete */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXCFG
value|E1000_ICR_RXCFG
end_define

begin_comment
comment|/* RX /c/ ordered set */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_GPI_EN0
value|E1000_ICR_GPI_EN0
end_define

begin_comment
comment|/* GP Int 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_GPI_EN1
value|E1000_ICR_GPI_EN1
end_define

begin_comment
comment|/* GP Int 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_GPI_EN2
value|E1000_ICR_GPI_EN2
end_define

begin_comment
comment|/* GP Int 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_GPI_EN3
value|E1000_ICR_GPI_EN3
end_define

begin_comment
comment|/* GP Int 3 */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_TXD_LOW
value|E1000_ICR_TXD_LOW
end_define

begin_define
define|#
directive|define
name|E1000_IMC_SRPD
value|E1000_ICR_SRPD
end_define

begin_comment
comment|/* Receive Control */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RST
value|0x00000001
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_EN
value|0x00000002
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SBP
value|0x00000004
end_define

begin_comment
comment|/* store bad packet */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_UPE
value|0x00000008
end_define

begin_comment
comment|/* unicast promiscuous enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MPE
value|0x00000010
end_define

begin_comment
comment|/* multicast promiscuous enab */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LPE
value|0x00000020
end_define

begin_comment
comment|/* long packet enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_NO
value|0x00000000
end_define

begin_comment
comment|/* no loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_MAC
value|0x00000040
end_define

begin_comment
comment|/* MAC loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_SLP
value|0x00000080
end_define

begin_comment
comment|/* serial link loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_LBM_TCVR
value|0x000000C0
end_define

begin_comment
comment|/* tcvr loopback mode */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_HALF
value|0x00000000
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_QUAT
value|0x00000100
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_RDMTS_EIGTH
value|0x00000200
end_define

begin_comment
comment|/* rx desc min threshold size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_SHIFT
value|12
end_define

begin_comment
comment|/* multicast offset shift */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_0
value|0x00000000
end_define

begin_comment
comment|/* multicast offset 11:0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_1
value|0x00001000
end_define

begin_comment
comment|/* multicast offset 12:1 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_2
value|0x00002000
end_define

begin_comment
comment|/* multicast offset 13:2 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MO_3
value|0x00003000
end_define

begin_comment
comment|/* multicast offset 15:4 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_MDR
value|0x00004000
end_define

begin_comment
comment|/* multicast desc ring 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_BAM
value|0x00008000
end_define

begin_comment
comment|/* broadcast enable */
end_comment

begin_comment
comment|/* these buffer sizes are valid if E1000_RCTL_BSEX is 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_2048
value|0x00000000
end_define

begin_comment
comment|/* rx buffer size 2048 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_1024
value|0x00010000
end_define

begin_comment
comment|/* rx buffer size 1024 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_512
value|0x00020000
end_define

begin_comment
comment|/* rx buffer size 512 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_256
value|0x00030000
end_define

begin_comment
comment|/* rx buffer size 256 */
end_comment

begin_comment
comment|/* these buffer sizes are valid if E1000_RCTL_BSEX is 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_16384
value|0x00010000
end_define

begin_comment
comment|/* rx buffer size 16384 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_8192
value|0x00020000
end_define

begin_comment
comment|/* rx buffer size 8192 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_SZ_4096
value|0x00030000
end_define

begin_comment
comment|/* rx buffer size 4096 */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_VFE
value|0x00040000
end_define

begin_comment
comment|/* vlan filter enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_CFIEN
value|0x00080000
end_define

begin_comment
comment|/* canonical form enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_CFI
value|0x00100000
end_define

begin_comment
comment|/* canonical form indicator */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_DPF
value|0x00400000
end_define

begin_comment
comment|/* discard pause frames */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_PMCF
value|0x00800000
end_define

begin_comment
comment|/* pass MAC control frames */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_BSEX
value|0x02000000
end_define

begin_comment
comment|/* Buffer size extension */
end_comment

begin_comment
comment|/* Receive Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT_DELAY
value|0x0000ffff
end_define

begin_comment
comment|/* Delay timer (1=1024us) */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT_FPDB
value|0x80000000
end_define

begin_comment
comment|/* Flush descriptor block */
end_comment

begin_define
define|#
directive|define
name|E1000_RDLEN_LEN
value|0x0007ff80
end_define

begin_comment
comment|/* descriptor length */
end_comment

begin_define
define|#
directive|define
name|E1000_RDH_RDH
value|0x0000ffff
end_define

begin_comment
comment|/* receive descriptor head */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT_RDT
value|0x0000ffff
end_define

begin_comment
comment|/* receive descriptor tail */
end_comment

begin_comment
comment|/* Flow Control */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH_RTH
value|0x0000FFF8
end_define

begin_comment
comment|/* Mask Bits[15:3] for RTH */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH_XFCE
value|0x80000000
end_define

begin_comment
comment|/* External Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL_RTL
value|0x0000FFF8
end_define

begin_comment
comment|/* Mask Bits[15:3] for RTL */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL_XONE
value|0x80000000
end_define

begin_comment
comment|/* Enable XON frame transmission */
end_comment

begin_comment
comment|/* Receive Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_PTHRESH
value|0x0000003F
end_define

begin_comment
comment|/* RXDCTL Prefetch Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_HTHRESH
value|0x00003F00
end_define

begin_comment
comment|/* RXDCTL Host Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_WTHRESH
value|0x003F0000
end_define

begin_comment
comment|/* RXDCTL Writeback Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_GRAN
value|0x01000000
end_define

begin_comment
comment|/* RXDCTL Granularity */
end_comment

begin_comment
comment|/* Transmit Descriptor Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_PTHRESH
value|0x000000FF
end_define

begin_comment
comment|/* TXDCTL Prefetch Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_HTHRESH
value|0x0000FF00
end_define

begin_comment
comment|/* TXDCTL Host Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_WTHRESH
value|0x00FF0000
end_define

begin_comment
comment|/* TXDCTL Writeback Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_GRAN
value|0x01000000
end_define

begin_comment
comment|/* TXDCTL Granularity */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_LWTHRESH
value|0xFE000000
end_define

begin_comment
comment|/* TXDCTL Low Threshold */
end_comment

begin_comment
comment|/* Transmit Configuration Word */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_FD
value|0x00000020
end_define

begin_comment
comment|/* TXCW full duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_HD
value|0x00000040
end_define

begin_comment
comment|/* TXCW half duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_PAUSE
value|0x00000080
end_define

begin_comment
comment|/* TXCW sym pause request */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_ASM_DIR
value|0x00000100
end_define

begin_comment
comment|/* TXCW astm pause direction */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_PAUSE_MASK
value|0x00000180
end_define

begin_comment
comment|/* TXCW pause request mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_RF
value|0x00003000
end_define

begin_comment
comment|/* TXCW remote fault */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_NP
value|0x00008000
end_define

begin_comment
comment|/* TXCW next page */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_CW
value|0x0000ffff
end_define

begin_comment
comment|/* TxConfigWord mask */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_TXC
value|0x40000000
end_define

begin_comment
comment|/* Transmit Config control */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW_ANE
value|0x80000000
end_define

begin_comment
comment|/* Auto-neg enable */
end_comment

begin_comment
comment|/* Receive Configuration Word */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_CW
value|0x0000ffff
end_define

begin_comment
comment|/* RxConfigWord mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_NC
value|0x04000000
end_define

begin_comment
comment|/* Receive config no carrier */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_IV
value|0x08000000
end_define

begin_comment
comment|/* Receive config invalid */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_CC
value|0x10000000
end_define

begin_comment
comment|/* Receive config change */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_C
value|0x20000000
end_define

begin_comment
comment|/* Receive config */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_SYNCH
value|0x40000000
end_define

begin_comment
comment|/* Receive config synch */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW_ANC
value|0x80000000
end_define

begin_comment
comment|/* Auto-neg complete */
end_comment

begin_comment
comment|/* Transmit Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_RST
value|0x00000001
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EN
value|0x00000002
end_define

begin_comment
comment|/* enable tx */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_BCE
value|0x00000004
end_define

begin_comment
comment|/* busy check enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_PSP
value|0x00000008
end_define

begin_comment
comment|/* pad short packets */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_CT
value|0x00000ff0
end_define

begin_comment
comment|/* collision threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_COLD
value|0x003ff000
end_define

begin_comment
comment|/* collision distance */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_SWXOFF
value|0x00400000
end_define

begin_comment
comment|/* SW Xoff transmission */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_PBE
value|0x00800000
end_define

begin_comment
comment|/* Packet Burst Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_RTLC
value|0x01000000
end_define

begin_comment
comment|/* Re-transmit on late collision */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_NRTU
value|0x02000000
end_define

begin_comment
comment|/* No Re-transmit on underrun */
end_comment

begin_comment
comment|/* Receive Checksum Control */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_PCSS_MASK
value|0x000000FF
end_define

begin_comment
comment|/* Packet Checksum Start */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPOFL
value|0x00000100
end_define

begin_comment
comment|/* IPv4 checksum offload */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_TUOFL
value|0x00000200
end_define

begin_comment
comment|/* TCP / UDP checksum offload */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPV6OFL
value|0x00000400
end_define

begin_comment
comment|/* IPv6 checksum offload */
end_comment

begin_comment
comment|/* Definitions for power management and wakeup registers */
end_comment

begin_comment
comment|/* Wake Up Control */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_APME
value|0x00000001
end_define

begin_comment
comment|/* APM Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_PME_EN
value|0x00000002
end_define

begin_comment
comment|/* PME Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_PME_STATUS
value|0x00000004
end_define

begin_comment
comment|/* PME Status */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC_APMPME
value|0x00000008
end_define

begin_comment
comment|/* Assert PME on APM Wakeup */
end_comment

begin_comment
comment|/* Wake Up Filter Control */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_LNKC
value|0x00000001
end_define

begin_comment
comment|/* Link Status Change Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_MAG
value|0x00000002
end_define

begin_comment
comment|/* Magic Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed Exact Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_MC
value|0x00000008
end_define

begin_comment
comment|/* Directed Multicast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_BC
value|0x00000010
end_define

begin_comment
comment|/* Broadcast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_ARP
value|0x00000020
end_define

begin_comment
comment|/* ARP Request Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_IPV4
value|0x00000040
end_define

begin_comment
comment|/* Directed IPv4 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_IPV6
value|0x00000080
end_define

begin_comment
comment|/* Directed IPv6 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX0
value|0x00010000
end_define

begin_comment
comment|/* Flexible Filter 0 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX1
value|0x00020000
end_define

begin_comment
comment|/* Flexible Filter 1 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX2
value|0x00040000
end_define

begin_comment
comment|/* Flexible Filter 2 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX3
value|0x00080000
end_define

begin_comment
comment|/* Flexible Filter 3 Enable */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_ALL_FILTERS
value|0x000F00FF
end_define

begin_comment
comment|/* Mask for all wakeup filters */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX_OFFSET
value|16
end_define

begin_comment
comment|/* Offset to the Flexible Filters bits */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC_FLX_FILTERS
value|0x000F0000
end_define

begin_comment
comment|/* Mask for the 4 flexible filters */
end_comment

begin_comment
comment|/* Wake Up Status */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_LNKC
value|0x00000001
end_define

begin_comment
comment|/* Link Status Changed */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_MAG
value|0x00000002
end_define

begin_comment
comment|/* Magic Packet Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed Exact Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_MC
value|0x00000008
end_define

begin_comment
comment|/* Directed Multicast Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_BC
value|0x00000010
end_define

begin_comment
comment|/* Broadcast Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_ARP
value|0x00000020
end_define

begin_comment
comment|/* ARP Request Packet Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_IPV4
value|0x00000040
end_define

begin_comment
comment|/* Directed IPv4 Packet Wakeup Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_IPV6
value|0x00000080
end_define

begin_comment
comment|/* Directed IPv6 Packet Wakeup Received */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_FLX0
value|0x00010000
end_define

begin_comment
comment|/* Flexible Filter 0 Match */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_FLX1
value|0x00020000
end_define

begin_comment
comment|/* Flexible Filter 1 Match */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_FLX2
value|0x00040000
end_define

begin_comment
comment|/* Flexible Filter 2 Match */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_FLX3
value|0x00080000
end_define

begin_comment
comment|/* Flexible Filter 3 Match */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS_FLX_FILTERS
value|0x000F0000
end_define

begin_comment
comment|/* Mask for the 4 flexible filters */
end_comment

begin_comment
comment|/* Management Control */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMBUS_EN
value|0x00000001
end_define

begin_comment
comment|/* SMBus Enabled - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ASF_EN
value|0x00000002
end_define

begin_comment
comment|/* ASF Enabled - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_R_ON_FORCE
value|0x00000004
end_define

begin_comment
comment|/* Reset on Force TCO - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_RMCP_EN
value|0x00000100
end_define

begin_comment
comment|/* Enable RCMP 026Fh Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_0298_EN
value|0x00000200
end_define

begin_comment
comment|/* Enable RCMP 0298h Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_IPV4_EN
value|0x00000400
end_define

begin_comment
comment|/* Enable IPv4 */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_IPV6_EN
value|0x00000800
end_define

begin_comment
comment|/* Enable IPv6 */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SNAP_EN
value|0x00001000
end_define

begin_comment
comment|/* Accept LLC/SNAP */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ARP_EN
value|0x00002000
end_define

begin_comment
comment|/* Enable ARP Request Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_NEIGHBOR_EN
value|0x00004000
end_define

begin_comment
comment|/* Enable Neighbor Discovery                                               * Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_TCO_RESET
value|0x00010000
end_define

begin_comment
comment|/* TCO Reset Occurred */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_RCV_TCO_EN
value|0x00020000
end_define

begin_comment
comment|/* Receive TCO Packets Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_REPORT_STATUS
value|0x00040000
end_define

begin_comment
comment|/* Status Reporting Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_REQ
value|0x01000000
end_define

begin_comment
comment|/* SMBus Request */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_GNT
value|0x02000000
end_define

begin_comment
comment|/* SMBus Grant */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_IN
value|0x04000000
end_define

begin_comment
comment|/* SMBus Clock In */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_IN
value|0x08000000
end_define

begin_comment
comment|/* SMBus Data In */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_OUT
value|0x10000000
end_define

begin_comment
comment|/* SMBus Data Out */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_OUT
value|0x20000000
end_define

begin_comment
comment|/* SMBus Clock Out */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_DATA_OUT_SHIFT
value|28
end_define

begin_comment
comment|/* SMBus Data Out Shift */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_SMB_CLK_OUT_SHIFT
value|29
end_define

begin_comment
comment|/* SMBus Clock Out Shift */
end_comment

begin_comment
comment|/* Wake Up Packet Length */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPL_LENGTH_MASK
value|0x0FFF
end_define

begin_comment
comment|/* Only the lower 12 bits are valid */
end_comment

begin_define
define|#
directive|define
name|E1000_MDALIGN
value|4096
end_define

begin_comment
comment|/* EEPROM Commands */
end_comment

begin_define
define|#
directive|define
name|EEPROM_READ_OPCODE
value|0x6
end_define

begin_comment
comment|/* EERPOM read opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRITE_OPCODE
value|0x5
end_define

begin_comment
comment|/* EERPOM write opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE_OPCODE
value|0x7
end_define

begin_comment
comment|/* EERPOM erase opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWEN_OPCODE
value|0x13
end_define

begin_comment
comment|/* EERPOM erase/write enable */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWDS_OPCODE
value|0x10
end_define

begin_comment
comment|/* EERPOM erast/write disable */
end_comment

begin_comment
comment|/* EEPROM Word Offsets */
end_comment

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL1_REG
value|0x000A
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL2_REG
value|0x000F
end_define

begin_define
define|#
directive|define
name|EEPROM_FLASH_VERSION
value|0x0032
end_define

begin_define
define|#
directive|define
name|EEPROM_CHECKSUM_REG
value|0x003F
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x0a of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WORD0A_ILOS
value|0x0010
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0A_SWDPIO
value|0x01E0
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0A_LRST
value|0x0200
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0A_FD
value|0x0400
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0A_66MHZ
value|0x0800
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x0f of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WORD0F_PAUSE_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0F_PAUSE
value|0x1000
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0F_ASM_DIR
value|0x2000
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0F_ANE
value|0x0800
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD0F_SWPDIO_EXT
value|0x00F0
end_define

begin_comment
comment|/* For checksumming, the sum of all words in the EEPROM should equal 0xBABA. */
end_comment

begin_define
define|#
directive|define
name|EEPROM_SUM
value|0xBABA
end_define

begin_comment
comment|/* EEPROM Map defines (WORD OFFSETS)*/
end_comment

begin_define
define|#
directive|define
name|EEPROM_NODE_ADDRESS_BYTE_0
value|0
end_define

begin_define
define|#
directive|define
name|EEPROM_PBA_BYTE_1
value|8
end_define

begin_comment
comment|/* EEPROM Map Sizes (Byte Counts) */
end_comment

begin_define
define|#
directive|define
name|PBA_SIZE
value|4
end_define

begin_comment
comment|/* Collision related configuration parameters */
end_comment

begin_define
define|#
directive|define
name|E1000_COLLISION_THRESHOLD
value|16
end_define

begin_define
define|#
directive|define
name|E1000_CT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|E1000_FDX_COLLISION_DISTANCE
value|64
end_define

begin_define
define|#
directive|define
name|E1000_HDX_COLLISION_DISTANCE
value|64
end_define

begin_define
define|#
directive|define
name|E1000_GB_HDX_COLLISION_DISTANCE
value|512
end_define

begin_define
define|#
directive|define
name|E1000_COLD_SHIFT
value|12
end_define

begin_comment
comment|/* The number of Transmit and Receive Descriptors must be a multiple of 8 */
end_comment

begin_define
define|#
directive|define
name|REQ_TX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_define
define|#
directive|define
name|REQ_RX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_comment
comment|/* Default values for the transmit IPG register */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGT
value|10
end_define

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGT_FIBER
value|9
end_define

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGT_COPPER
value|8
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGT_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR1_MASK
value|0x000FFC00
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR2_MASK
value|0x3FF00000
end_define

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGR1
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGR1
value|8
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR1_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|DEFAULT_82542_TIPG_IPGR2
value|10
end_define

begin_define
define|#
directive|define
name|DEFAULT_82543_TIPG_IPGR2
value|6
end_define

begin_define
define|#
directive|define
name|E1000_TIPG_IPGR2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|E1000_TXDMAC_DPP
value|0x00000001
end_define

begin_comment
comment|/* PBA constants */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_16K
value|0x0010
end_define

begin_comment
comment|/* 16KB, default TX allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_24K
value|0x0018
end_define

begin_define
define|#
directive|define
name|E1000_PBA_40K
value|0x0028
end_define

begin_define
define|#
directive|define
name|E1000_PBA_48K
value|0x0030
end_define

begin_comment
comment|/* 48KB, default RX allocation */
end_comment

begin_comment
comment|/* Flow Control Constants */
end_comment

begin_define
define|#
directive|define
name|FLOW_CONTROL_ADDRESS_LOW
value|0x00C28001
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_ADDRESS_HIGH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FLOW_CONTROL_TYPE
value|0x8808
end_define

begin_comment
comment|/* The historical defaults for the flow control values are given below. */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_HI_THRESH
value|(0x8000)
end_define

begin_comment
comment|/* 32KB */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_LO_THRESH
value|(0x4000)
end_define

begin_comment
comment|/* 16KB */
end_comment

begin_define
define|#
directive|define
name|FC_DEFAULT_TX_TIMER
value|(0x100)
end_define

begin_comment
comment|/* ~130 us */
end_comment

begin_comment
comment|/* The number of bits that we need to shift right to move the "pause"  * bits from the EEPROM (bits 13:12) to the "pause" (bits 8:7) field  * in the TXCW register   */
end_comment

begin_define
define|#
directive|define
name|PAUSE_SHIFT
value|5
end_define

begin_comment
comment|/* The number of bits that we need to shift left to move the "SWDPIO"  * bits from the EEPROM (bits 8:5) to the "SWDPIO" (bits 25:22) field  * in the CTRL register   */
end_comment

begin_define
define|#
directive|define
name|SWDPIO_SHIFT
value|17
end_define

begin_comment
comment|/* The number of bits that we need to shift left to move the "SWDPIO_EXT"  * bits from the EEPROM word F (bits 7:4) to the bits 11:8 of The  * Extended CTRL register.  * in the CTRL register   */
end_comment

begin_define
define|#
directive|define
name|SWDPIO__EXT_SHIFT
value|4
end_define

begin_comment
comment|/* The number of bits that we need to shift left to move the "ILOS"  * bit from the EEPROM (bit 4) to the "ILOS" (bit 7) field  * in the CTRL register   */
end_comment

begin_define
define|#
directive|define
name|ILOS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RECEIVE_BUFFER_ALIGN_SIZE
value|(256)
end_define

begin_comment
comment|/* The number of milliseconds we wait for auto-negotiation to complete */
end_comment

begin_define
define|#
directive|define
name|LINK_UP_TIMEOUT
value|500
end_define

begin_define
define|#
directive|define
name|E1000_TX_BUFFER_SIZE
value|((uint32_t)1514)
end_define

begin_comment
comment|/* The carrier extension symbol, as received by the NIC. */
end_comment

begin_define
define|#
directive|define
name|CARRIER_EXTENSION
value|0x0F
end_define

begin_comment
comment|/* TBI_ACCEPT macro definition:  *  * This macro requires:  *      adapter = a pointer to struct em_shared_adapter   *      status = the 8 bit status field of the RX descriptor with EOP set  *      error = the 8 bit error field of the RX descriptor with EOP set  *      length = the sum of all the length fields of the RX descriptors that  *               make up the current frame  *      last_byte = the last byte of the frame DMAed by the hardware  *      max_frame_length = the maximum frame length we want to accept.  *      min_frame_length = the minimum frame length we want to accept.  *  * This macro is a conditional that should be used in the interrupt   * handler's Rx processing routine when RxErrors have been detected.  *  * Typical use:  *  ...  *  if (TBI_ACCEPT) {  *      accept_frame = TRUE;  *      em_tbi_adjust_stats(adapter, MacAddress);  *      frame_length--;  *  } else {  *      accept_frame = FALSE;  *  }  *  ...  */
end_comment

begin_define
define|#
directive|define
name|TBI_ACCEPT
parameter_list|(
name|adapter
parameter_list|,
name|status
parameter_list|,
name|errors
parameter_list|,
name|length
parameter_list|,
name|last_byte
parameter_list|)
define|\
value|((adapter)->tbi_compatibility_on&& \      (((errors)& E1000_RXD_ERR_FRAME_ERR_MASK) == E1000_RXD_ERR_CE)&& \      ((last_byte) == CARRIER_EXTENSION)&& \      (((status)& E1000_RXD_STAT_VP) ? \           (((length)> ((adapter)->min_frame_size - VLAN_TAG_SIZE))&& \            ((length)<= ((adapter)->max_frame_size + 1))) : \           (((length)> (adapter)->min_frame_size)&& \            ((length)<= ((adapter)->max_frame_size + VLAN_TAG_SIZE + 1)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_MAC_H_ */
end_comment

end_unit

