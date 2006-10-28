begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2005, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* if_em_hw.h  * Structures, enums, and macros for the MAC  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EM_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_EM_HW_H_
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
name|em_hw
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|em_hw_stats
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
name|em_undefined
init|=
literal|0
block|,
name|em_82542_rev2_0
block|,
name|em_82542_rev2_1
block|,
name|em_82543
block|,
name|em_82544
block|,
name|em_82540
block|,
name|em_82545
block|,
name|em_82545_rev_3
block|,
name|em_82546
block|,
name|em_82546_rev_3
block|,
name|em_82541
block|,
name|em_82541_rev_2
block|,
name|em_82547
block|,
name|em_82547_rev_2
block|,
name|em_82571
block|,
name|em_82572
block|,
name|em_82573
block|,
name|em_80003es2lan
block|,
name|em_ich8lan
block|,
name|em_num_macs
block|}
name|em_mac_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_eeprom_uninitialized
init|=
literal|0
block|,
name|em_eeprom_spi
block|,
name|em_eeprom_microwire
block|,
name|em_eeprom_flash
block|,
name|em_eeprom_ich8
block|,
name|em_eeprom_none
block|,
comment|/* No NVM support */
name|em_num_eeprom_types
block|}
name|em_eeprom_type
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
name|em_media_type_internal_serdes
init|=
literal|2
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

begin_struct
struct|struct
name|em_shadow_ram
block|{
name|uint16_t
name|eeprom_word
decl_stmt|;
name|boolean_t
name|modified
decl_stmt|;
block|}
struct|;
end_struct

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
block|,
name|em_bus_type_pci_express
block|,
name|em_bus_type_reserved
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
name|em_bus_speed_120
block|,
name|em_bus_speed_133
block|,
name|em_bus_speed_2500
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
comment|/* These PCIe values should literally match the possible return values      * from config space */
name|em_bus_width_pciex_1
init|=
literal|1
block|,
name|em_bus_width_pciex_2
init|=
literal|2
block|,
name|em_bus_width_pciex_4
init|=
literal|4
block|,
name|em_bus_width_32
block|,
name|em_bus_width_64
block|,
name|em_bus_width_reserved
block|}
name|em_bus_width
typedef|;
end_typedef

begin_comment
comment|/* PHY status info structure and supporting enums */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_cable_length_50
init|=
literal|0
block|,
name|em_cable_length_50_80
block|,
name|em_cable_length_80_110
block|,
name|em_cable_length_110_140
block|,
name|em_cable_length_140
block|,
name|em_cable_length_undefined
init|=
literal|0xFF
block|}
name|em_cable_length
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_gg_cable_length_60
init|=
literal|0
block|,
name|em_gg_cable_length_60_115
init|=
literal|1
block|,
name|em_gg_cable_length_115_150
init|=
literal|2
block|,
name|em_gg_cable_length_150
init|=
literal|4
block|}
name|em_gg_cable_length
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_igp_cable_length_10
init|=
literal|10
block|,
name|em_igp_cable_length_20
init|=
literal|20
block|,
name|em_igp_cable_length_30
init|=
literal|30
block|,
name|em_igp_cable_length_40
init|=
literal|40
block|,
name|em_igp_cable_length_50
init|=
literal|50
block|,
name|em_igp_cable_length_60
init|=
literal|60
block|,
name|em_igp_cable_length_70
init|=
literal|70
block|,
name|em_igp_cable_length_80
init|=
literal|80
block|,
name|em_igp_cable_length_90
init|=
literal|90
block|,
name|em_igp_cable_length_100
init|=
literal|100
block|,
name|em_igp_cable_length_110
init|=
literal|110
block|,
name|em_igp_cable_length_115
init|=
literal|115
block|,
name|em_igp_cable_length_120
init|=
literal|120
block|,
name|em_igp_cable_length_130
init|=
literal|130
block|,
name|em_igp_cable_length_140
init|=
literal|140
block|,
name|em_igp_cable_length_150
init|=
literal|150
block|,
name|em_igp_cable_length_160
init|=
literal|160
block|,
name|em_igp_cable_length_170
init|=
literal|170
block|,
name|em_igp_cable_length_180
init|=
literal|180
block|}
name|em_igp_cable_length
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_10bt_ext_dist_enable_normal
init|=
literal|0
block|,
name|em_10bt_ext_dist_enable_lower
block|,
name|em_10bt_ext_dist_enable_undefined
init|=
literal|0xFF
block|}
name|em_10bt_ext_dist_enable
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_rev_polarity_normal
init|=
literal|0
block|,
name|em_rev_polarity_reversed
block|,
name|em_rev_polarity_undefined
init|=
literal|0xFF
block|}
name|em_rev_polarity
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_downshift_normal
init|=
literal|0
block|,
name|em_downshift_activated
block|,
name|em_downshift_undefined
init|=
literal|0xFF
block|}
name|em_downshift
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_smart_speed_default
init|=
literal|0
block|,
name|em_smart_speed_on
block|,
name|em_smart_speed_off
block|}
name|em_smart_speed
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_polarity_reversal_enabled
init|=
literal|0
block|,
name|em_polarity_reversal_disabled
block|,
name|em_polarity_reversal_undefined
init|=
literal|0xFF
block|}
name|em_polarity_reversal
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_auto_x_mode_manual_mdi
init|=
literal|0
block|,
name|em_auto_x_mode_manual_mdix
block|,
name|em_auto_x_mode_auto1
block|,
name|em_auto_x_mode_auto2
block|,
name|em_auto_x_mode_undefined
init|=
literal|0xFF
block|}
name|em_auto_x_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_1000t_rx_status_not_ok
init|=
literal|0
block|,
name|em_1000t_rx_status_ok
block|,
name|em_1000t_rx_status_undefined
init|=
literal|0xFF
block|}
name|em_1000t_rx_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_phy_m88
init|=
literal|0
block|,
name|em_phy_igp
block|,
name|em_phy_igp_2
block|,
name|em_phy_gg82563
block|,
name|em_phy_igp_3
block|,
name|em_phy_ife
block|,
name|em_phy_undefined
init|=
literal|0xFF
block|}
name|em_phy_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_ms_hw_default
init|=
literal|0
block|,
name|em_ms_force_master
block|,
name|em_ms_force_slave
block|,
name|em_ms_auto
block|}
name|em_ms_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_ffe_config_enabled
init|=
literal|0
block|,
name|em_ffe_config_active
block|,
name|em_ffe_config_blocked
block|}
name|em_ffe_config
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_dsp_config_disabled
init|=
literal|0
block|,
name|em_dsp_config_enabled
block|,
name|em_dsp_config_activated
block|,
name|em_dsp_config_undefined
init|=
literal|0xFF
block|}
name|em_dsp_config
typedef|;
end_typedef

begin_struct
struct|struct
name|em_phy_info
block|{
name|em_cable_length
name|cable_length
decl_stmt|;
name|em_10bt_ext_dist_enable
name|extended_10bt_distance
decl_stmt|;
name|em_rev_polarity
name|cable_polarity
decl_stmt|;
name|em_downshift
name|downshift
decl_stmt|;
name|em_polarity_reversal
name|polarity_correction
decl_stmt|;
name|em_auto_x_mode
name|mdix_mode
decl_stmt|;
name|em_1000t_rx_status
name|local_rx
decl_stmt|;
name|em_1000t_rx_status
name|remote_rx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_phy_stats
block|{
name|uint32_t
name|idle_errors
decl_stmt|;
name|uint32_t
name|receive_errors
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_eeprom_info
block|{
name|em_eeprom_type
name|type
decl_stmt|;
name|uint16_t
name|word_size
decl_stmt|;
name|uint16_t
name|opcode_bits
decl_stmt|;
name|uint16_t
name|address_bits
decl_stmt|;
name|uint16_t
name|delay_usec
decl_stmt|;
name|uint16_t
name|page_size
decl_stmt|;
name|boolean_t
name|use_eerd
decl_stmt|;
name|boolean_t
name|use_eewr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flex ASF Information */
end_comment

begin_define
define|#
directive|define
name|E1000_HOST_IF_MAX_SIZE
value|2048
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_byte_align
init|=
literal|0
block|,
name|em_word_align
init|=
literal|1
block|,
name|em_dword_align
init|=
literal|2
block|}
name|em_align_type
typedef|;
end_typedef

begin_comment
comment|/* Error Codes */
end_comment

begin_define
define|#
directive|define
name|E1000_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|E1000_ERR_EEPROM
value|1
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PHY
value|2
end_define

begin_define
define|#
directive|define
name|E1000_ERR_CONFIG
value|3
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PARAM
value|4
end_define

begin_define
define|#
directive|define
name|E1000_ERR_MAC_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|E1000_ERR_PHY_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|E1000_ERR_RESET
value|9
end_define

begin_define
define|#
directive|define
name|E1000_ERR_MASTER_REQUESTS_PENDING
value|10
end_define

begin_define
define|#
directive|define
name|E1000_ERR_HOST_INTERFACE_COMMAND
value|11
end_define

begin_define
define|#
directive|define
name|E1000_BLK_PHY_RESET
value|12
end_define

begin_define
define|#
directive|define
name|E1000_ERR_SWFW_SYNC
value|13
end_define

begin_define
define|#
directive|define
name|E1000_BYTE_SWAP_WORD
parameter_list|(
name|_value
parameter_list|)
value|((((_value)& 0x00ff)<< 8) | \                                      (((_value)& 0xff00)>> 8))
end_define

begin_comment
comment|/* Function prototypes */
end_comment

begin_comment
comment|/* Initialization */
end_comment

begin_function_decl
name|int32_t
name|em_reset_hw
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_init_hw
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_set_mac_type
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_set_media_type
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Link Configuration */
end_comment

begin_function_decl
name|int32_t
name|em_setup_link
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_phy_setup_autoneg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_config_collision_dist
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_check_for_link
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_get_speed_and_duplex
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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

begin_function_decl
name|int32_t
name|em_force_mac_fc
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PHY */
end_comment

begin_function_decl
name|int32_t
name|em_read_phy_reg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint16_t
modifier|*
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_write_phy_reg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_phy_hw_reset
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_phy_reset
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_phy_get_info
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|em_phy_info
modifier|*
name|phy_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_validate_mdi_setting
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_phy_powerdown_workaround
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EEPROM Functions */
end_comment

begin_function_decl
name|int32_t
name|em_init_eeprom_params
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MNG HOST IF functions */
end_comment

begin_function_decl
name|uint32_t
name|em_enable_mng_pass_thru
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_TX_PAYLOAD_CMD
value|64
end_define

begin_define
define|#
directive|define
name|E1000_HI_MAX_MNG_DATA_LENGTH
value|0x6F8
end_define

begin_comment
comment|/* Host Interface data length */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COMMAND_TIMEOUT
value|10
end_define

begin_comment
comment|/* Time in ms to process MNG command */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_OFFSET
value|0x6F0
end_define

begin_comment
comment|/* Cookie offset */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_LENGTH
value|0x10
end_define

begin_comment
comment|/* Cookie length */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_IAMT_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_MNG_ICH_IAMT_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_IAMT_SIGNATURE
value|0x544D4149
end_define

begin_comment
comment|/* Intel(R) Active Management Technology signature */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_STATUS_PARSING_SUPPORT
value|0x1
end_define

begin_comment
comment|/* DHCP parsing enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_STATUS_VLAN_SUPPORT
value|0x2
end_define

begin_comment
comment|/* DHCP parsing enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_SHIFT
value|0x5
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_BIT_SHIFT_MASK
value|0x1F
end_define

begin_struct
struct|struct
name|em_host_mng_command_header
block|{
name|uint8_t
name|command_id
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint16_t
name|command_length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_host_mng_command_info
block|{
name|struct
name|em_host_mng_command_header
name|command_header
decl_stmt|;
comment|/* Command Head/Command Result Head has 4 bytes */
name|uint8_t
name|command_data
index|[
name|E1000_HI_MAX_MNG_DATA_LENGTH
index|]
decl_stmt|;
comment|/* Command data can length 0..0x658*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_host_mng_dhcp_cookie
block|{
name|uint32_t
name|signature
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|vlan_id
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int32_t
name|em_read_part_num
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
modifier|*
name|part_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_mng_write_dhcp_info
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint8_t
modifier|*
name|buffer
parameter_list|,
name|uint16_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_check_mng_mode
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_enable_tx_pkt_filtering
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_read_eeprom
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
name|words
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_validate_eeprom_checksum
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_update_eeprom_checksum
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_write_eeprom
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
name|words
parameter_list|,
name|uint16_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_read_mac_addr
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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
name|em_hw
modifier|*
name|hw
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
parameter_list|,
name|uint32_t
name|rar_used_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|em_hash_mc_addr
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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
name|em_hw
modifier|*
name|hw
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
name|em_hw
modifier|*
name|hw
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
name|em_hw
modifier|*
name|hw
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LED functions */
end_comment

begin_function_decl
name|int32_t
name|em_setup_led
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_cleanup_led
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_led_on
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_led_off
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_blink_led_start
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Adaptive IFS Functions */
end_comment

begin_comment
comment|/* Everything else */
end_comment

begin_function_decl
name|void
name|em_clear_hw_cntrs
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_reset_adaptive
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_update_adaptive
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_tbi_adjust_stats
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|em_hw_stats
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
name|em_get_bus_info
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_pci_set_mwi
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_pci_clear_mwi
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_read_pci_cfg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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

begin_function_decl
name|void
name|em_write_pci_cfg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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

begin_function_decl
name|int32_t
name|em_read_pcie_cap_reg
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
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
comment|/* Port I/O is only supported on 82544 and newer */
end_comment

begin_function_decl
name|uint32_t
name|em_io_read
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|unsigned
name|long
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_io_write
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|,
name|unsigned
name|long
name|port
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_disable_pciex_master
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|em_check_phy_reset_block
parameter_list|(
name|struct
name|em_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|E1000_READ_REG_IO
end_ifndef

begin_define
define|#
directive|define
name|E1000_READ_REG_IO
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|)
define|\
value|em_read_reg_io((a), E1000_##reg)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_IO
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|em_write_reg_io((a), E1000_##reg, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|E1000_DEV_ID_82540EM_LOM
value|0x1015
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82540EP_LOM
value|0x1016
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82540EP
value|0x1017
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82540EP_LP
value|0x101E
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82545EM_COPPER
value|0x100F
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82545EM_FIBER
value|0x1011
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82545GM_COPPER
value|0x1026
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82545GM_FIBER
value|0x1027
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82545GM_SERDES
value|0x1028
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546EB_COPPER
value|0x1010
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546EB_FIBER
value|0x1012
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546EB_QUAD_COPPER
value|0x101D
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541EI
value|0x1013
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541EI_MOBILE
value|0x1018
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541ER_LOM
value|0x1014
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541ER
value|0x1078
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82547GI
value|0x1075
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541GI
value|0x1076
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541GI_MOBILE
value|0x1077
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82541GI_LF
value|0x107C
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_COPPER
value|0x1079
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_FIBER
value|0x107A
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_SERDES
value|0x107B
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_PCIE
value|0x108A
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_QUAD_COPPER
value|0x1099
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82547EI
value|0x1019
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82547EI_MOBILE
value|0x101A
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82571EB_COPPER
value|0x105E
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82571EB_FIBER
value|0x105F
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82571EB_SERDES
value|0x1060
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82571EB_QUAD_COPPER
value|0x10A4
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82571EB_QUAD_COPPER_LOWPROFILE
value|0x10BC
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82572EI_COPPER
value|0x107D
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82572EI_FIBER
value|0x107E
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82572EI_SERDES
value|0x107F
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82572EI
value|0x10B9
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82573E
value|0x108B
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82573E_IAMT
value|0x108C
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82573L
value|0x109A
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_82546GB_QUAD_COPPER_KSP3
value|0x10B5
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_80003ES2LAN_COPPER_DPT
value|0x1096
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_80003ES2LAN_SERDES_DPT
value|0x1098
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_80003ES2LAN_COPPER_SPT
value|0x10BA
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_80003ES2LAN_SERDES_SPT
value|0x10BB
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IGP_M_AMT
value|0x1049
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IGP_AMT
value|0x104A
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IGP_C
value|0x104B
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IFE
value|0x104C
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IFE_GT
value|0x10C4
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IFE_G
value|0x10C5
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_ICH8_IGP_M
value|0x104D
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
name|E1000_REVISION_0
value|0
end_define

begin_define
define|#
directive|define
name|E1000_REVISION_1
value|1
end_define

begin_define
define|#
directive|define
name|E1000_REVISION_2
value|2
end_define

begin_define
define|#
directive|define
name|E1000_REVISION_3
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
name|MAXIMUM_ETHERNET_FRAME_SIZE
value|1518
end_define

begin_comment
comment|/* With FCS */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_ETHERNET_FRAME_SIZE
value|64
end_define

begin_comment
comment|/* With FCS */
end_comment

begin_define
define|#
directive|define
name|ETHERNET_FCS_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|MAXIMUM_ETHERNET_PACKET_SIZE
define|\
value|(MAXIMUM_ETHERNET_FRAME_SIZE - ETHERNET_FCS_SIZE)
end_define

begin_define
define|#
directive|define
name|MINIMUM_ETHERNET_PACKET_SIZE
define|\
value|(MINIMUM_ETHERNET_FRAME_SIZE - ETHERNET_FCS_SIZE)
end_define

begin_define
define|#
directive|define
name|CRC_LENGTH
value|ETHERNET_FCS_SIZE
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
comment|/* This defines the bits that are set in the Interrupt Mask  * Set/Read Register.  Each bit is documented below:  *   o RXDMT0 = Receive Descriptor Minimum Threshold hit (ring 0)  *   o RXSEQ  = Receive Sequence Error  */
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
comment|/* Additional interrupts need to be handled for em_ich8lan:     DSW = The FW changed the status of the DISSW bit in FWSM     PHYINT = The LAN connected device generates an interrupt     EPRST = Manageability reset event */
end_comment

begin_define
define|#
directive|define
name|IMS_ICH8LAN_ENABLE_MASK
value|(\     E1000_IMS_DSW   | \     E1000_IMS_PHYINT | \     E1000_IMS_EPRST)
end_define

begin_comment
comment|/* Number of high/low register pairs in the RAR. The RAR (Receive Address  * Registers) holds the directed and multicast addresses that we monitor. We  * reserve one of these spots for our directed address, allowing us room for  * E1000_RAR_ENTRIES - 1 multicast addresses.  */
end_comment

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES
value|15
end_define

begin_define
define|#
directive|define
name|E1000_RAR_ENTRIES_ICH8LAN
value|6
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
comment|/* Receive Descriptor - Extended */
end_comment

begin_union
union|union
name|em_rx_desc_extended
block|{
struct|struct
block|{
name|uint64_t
name|buffer_addr
decl_stmt|;
name|uint64_t
name|reserved
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
name|uint32_t
name|mrq
decl_stmt|;
comment|/* Multiple Rx Queues */
union|union
block|{
name|uint32_t
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|uint16_t
name|ip_id
decl_stmt|;
comment|/* IP id */
name|uint16_t
name|csum
decl_stmt|;
comment|/* Packet Checksum */
block|}
name|csum_ip
struct|;
block|}
name|hi_dword
union|;
block|}
name|lower
struct|;
struct|struct
block|{
name|uint32_t
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
comment|/* VLAN tag */
block|}
name|upper
struct|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|MAX_PS_BUFFERS
value|4
end_define

begin_comment
comment|/* Receive Descriptor - Packet Split */
end_comment

begin_union
union|union
name|em_rx_desc_packet_split
block|{
struct|struct
block|{
comment|/* one buffer for protocol header(s), three data buffers */
name|uint64_t
name|buffer_addr
index|[
name|MAX_PS_BUFFERS
index|]
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
name|uint32_t
name|mrq
decl_stmt|;
comment|/* Multiple Rx Queues */
union|union
block|{
name|uint32_t
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|uint16_t
name|ip_id
decl_stmt|;
comment|/* IP id */
name|uint16_t
name|csum
decl_stmt|;
comment|/* Packet Checksum */
block|}
name|csum_ip
struct|;
block|}
name|hi_dword
union|;
block|}
name|lower
struct|;
struct|struct
block|{
name|uint32_t
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|uint16_t
name|length0
decl_stmt|;
comment|/* length of buffer 0 */
name|uint16_t
name|vlan
decl_stmt|;
comment|/* VLAN tag */
block|}
name|middle
struct|;
struct|struct
block|{
name|uint16_t
name|header_status
decl_stmt|;
name|uint16_t
name|length
index|[
literal|3
index|]
decl_stmt|;
comment|/* length of buffers 1-3 */
block|}
name|upper
struct|;
name|uint64_t
name|reserved
decl_stmt|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

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
name|E1000_RXD_STAT_UDPCS
value|0x10
end_define

begin_comment
comment|/* UDP xsum caculated */
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
name|E1000_RXD_STAT_IPIDV
value|0x200
end_define

begin_comment
comment|/* IP identification valid */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_UDPV
value|0x400
end_define

begin_comment
comment|/* Valid UDP checksum */
end_comment

begin_define
define|#
directive|define
name|E1000_RXD_STAT_ACK
value|0x8000
end_define

begin_comment
comment|/* ACK Packet indication */
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
value|13
end_define

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
value|12
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_CE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_SE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_SEQ
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_CXE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_TCPE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_IPE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_STATERR_RXE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDPS_HDRSTAT_HDRSP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_RXDPS_HDRSTAT_HDRLEN_MASK
value|0x000003FF
end_define

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
comment|/* Same mask, but for extended and packet split descriptors */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDEXT_ERR_FRAME_ERR_MASK
value|( \     E1000_RXDEXT_STATERR_CE  |            \     E1000_RXDEXT_STATERR_SE  |            \     E1000_RXDEXT_STATERR_SEQ |            \     E1000_RXDEXT_STATERR_CXE |            \     E1000_RXDEXT_STATERR_RXE)
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

begin_define
define|#
directive|define
name|E1000_NUM_UNICAST_ICH8LAN
value|7
end_define

begin_define
define|#
directive|define
name|E1000_MC_TBL_SIZE_ICH8LAN
value|32
end_define

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
comment|/* Number of entries in the Multicast Table Array (MTA). */
end_comment

begin_define
define|#
directive|define
name|E1000_NUM_MTA_REGISTERS
value|128
end_define

begin_define
define|#
directive|define
name|E1000_NUM_MTA_REGISTERS_ICH8LAN
value|32
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
name|E1000_IP4AT_SIZE_ICH8LAN
value|3
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

begin_define
define|#
directive|define
name|E1000_DISABLE_SERDES_LOOPBACK
value|0x0400
end_define

begin_comment
comment|/* Register Set. (82543, 82544)  *  * Registers are defined to be 32 bits and  should be accessed as 32 bit values.  * These registers are physically located on the NIC, but are mapped into the  * host memory address space.  *  * RW - register is both readable and writable  * RO - register is read only  * WO - register is write only  * R/clr - register is read only and is cleared when read  * A - register array  */
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
name|E1000_CTRL_DUP
value|0x00004
end_define

begin_comment
comment|/* Device Control Duplicate (Shadow) - RW */
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
name|E1000_FLA
value|0x0001C
end_define

begin_comment
comment|/* Flash Access - RW */
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
name|E1000_SCTL
value|0x00024
end_define

begin_comment
comment|/* SerDes Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FEXTNVM
value|0x00028
end_define

begin_comment
comment|/* Future Extended NVM register */
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
name|E1000_IAM
value|0x000E0
end_define

begin_comment
comment|/* Interrupt Acknowledge Auto Mask */
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
name|E1000_RDTR1
value|0x02820
end_define

begin_comment
comment|/* RX Delay Timer (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAL1
value|0x02900
end_define

begin_comment
comment|/* RX Descriptor Base Address Low (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAH1
value|0x02904
end_define

begin_comment
comment|/* RX Descriptor Base Address High (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDLEN1
value|0x02908
end_define

begin_comment
comment|/* RX Descriptor Length (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDH1
value|0x02910
end_define

begin_comment
comment|/* RX Descriptor Head (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT1
value|0x02918
end_define

begin_comment
comment|/* RX Descriptor Tail (1) - RW */
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
name|E1000_TCTL_EXT
value|0x00404
end_define

begin_comment
comment|/* Extended TX Control - RW */
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
name|E1000_AIT
value|0x00458
end_define

begin_comment
comment|/* Adaptive Interframe Spacing Throttle - RW */
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
name|E1000_EXTCNF_CTRL
value|0x00F00
end_define

begin_comment
comment|/* Extended Configuration Control */
end_comment

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE
value|0x00F08
end_define

begin_comment
comment|/* Extended Configuration Size */
end_comment

begin_define
define|#
directive|define
name|E1000_PHY_CTRL
value|0x00F10
end_define

begin_comment
comment|/* PHY Control Register in CSR */
end_comment

begin_define
define|#
directive|define
name|FEXTNVM_SW_CONFIG
value|0x0001
end_define

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
name|E1000_PBS
value|0x01008
end_define

begin_comment
comment|/* Packet Buffer Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EEMNGCTL
value|0x01010
end_define

begin_comment
comment|/* MNG EEprom Control */
end_comment

begin_define
define|#
directive|define
name|E1000_FLASH_UPDATES
value|1000
end_define

begin_define
define|#
directive|define
name|E1000_EEARBC
value|0x01024
end_define

begin_comment
comment|/* EEPROM Auto Read Bus Control */
end_comment

begin_define
define|#
directive|define
name|E1000_FLASHT
value|0x01028
end_define

begin_comment
comment|/* FLASH Timer Register */
end_comment

begin_define
define|#
directive|define
name|E1000_EEWR
value|0x0102C
end_define

begin_comment
comment|/* EEPROM Write Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWCTL
value|0x01030
end_define

begin_comment
comment|/* FLASH control register */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWDATA
value|0x01034
end_define

begin_comment
comment|/* FLASH data register */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWCNT
value|0x01038
end_define

begin_comment
comment|/* FLASH Access Counter */
end_comment

begin_define
define|#
directive|define
name|E1000_FLOP
value|0x0103C
end_define

begin_comment
comment|/* FLASH Opcode Register */
end_comment

begin_define
define|#
directive|define
name|E1000_ERT
value|0x02008
end_define

begin_comment
comment|/* Early Rx Threshold - RW */
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
name|E1000_PSRCTL
value|0x02170
end_define

begin_comment
comment|/* Packet Split Receive Control - RW */
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
name|E1000_RDBAL0
value|E1000_RDBAL
end_define

begin_comment
comment|/* RX Desc Base Address Low (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAH0
value|E1000_RDBAH
end_define

begin_comment
comment|/* RX Desc Base Address High (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDLEN0
value|E1000_RDLEN
end_define

begin_comment
comment|/* RX Desc Length (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDH0
value|E1000_RDH
end_define

begin_comment
comment|/* RX Desc Head (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDT0
value|E1000_RDT
end_define

begin_comment
comment|/* RX Desc Tail (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDTR0
value|E1000_RDTR
end_define

begin_comment
comment|/* RX Delay Timer (0) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL
value|0x02828
end_define

begin_comment
comment|/* RX Descriptor Control queue 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL1
value|0x02928
end_define

begin_comment
comment|/* RX Descriptor Control queue 1 - RW */
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
name|E1000_RAID
value|0x02C08
end_define

begin_comment
comment|/* Receive Ack Interrupt Delay - RW */
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
name|E1000_KABGTXD
value|0x03004
end_define

begin_comment
comment|/* AFE Band Gap Transmit Ref Data */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFH
value|0x03410
end_define

begin_comment
comment|/* TX Data FIFO Head - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFT
value|0x03418
end_define

begin_comment
comment|/* TX Data FIFO Tail - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFHS
value|0x03420
end_define

begin_comment
comment|/* TX Data FIFO Head Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFTS
value|0x03428
end_define

begin_comment
comment|/* TX Data FIFO Tail Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFPC
value|0x03430
end_define

begin_comment
comment|/* TX Data FIFO Packet Count - RW */
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
name|E1000_TARC0
value|0x03840
end_define

begin_comment
comment|/* TX Arbitration Count (0) */
end_comment

begin_define
define|#
directive|define
name|E1000_TDBAL1
value|0x03900
end_define

begin_comment
comment|/* TX Desc Base Address Low (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDBAH1
value|0x03904
end_define

begin_comment
comment|/* TX Desc Base Address High (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDLEN1
value|0x03908
end_define

begin_comment
comment|/* TX Desc Length (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDH1
value|0x03910
end_define

begin_comment
comment|/* TX Desc Head (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDT1
value|0x03918
end_define

begin_comment
comment|/* TX Desc Tail (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL1
value|0x03928
end_define

begin_comment
comment|/* TX Descriptor Control (1) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TARC1
value|0x03940
end_define

begin_comment
comment|/* TX Arbitration Count (1) */
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
name|E1000_IAC
value|0x04100
end_define

begin_comment
comment|/* Interrupt Assertion Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXPTC
value|0x04104
end_define

begin_comment
comment|/* Interrupt Cause Rx Packet Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXATC
value|0x04108
end_define

begin_comment
comment|/* Interrupt Cause Rx Absolute Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXPTC
value|0x0410C
end_define

begin_comment
comment|/* Interrupt Cause Tx Packet Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXATC
value|0x04110
end_define

begin_comment
comment|/* Interrupt Cause Tx Absolute Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXQEC
value|0x04118
end_define

begin_comment
comment|/* Interrupt Cause Tx Queue Empty Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXQMTC
value|0x0411C
end_define

begin_comment
comment|/* Interrupt Cause Tx Queue Minimum Threshold Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXDMTC
value|0x04120
end_define

begin_comment
comment|/* Interrupt Cause Rx Descriptor Minimum Threshold Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXOC
value|0x04124
end_define

begin_comment
comment|/* Interrupt Cause Receiver Overrun Count */
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
name|E1000_RFCTL
value|0x05008
end_define

begin_comment
comment|/* Receive Filter Control*/
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
name|E1000_HOST_IF
value|0x08800
end_define

begin_comment
comment|/* Host Interface */
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

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA
value|0x00034
end_define

begin_comment
comment|/* MAC-PHY interface - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MDPHYA
value|0x0003C
end_define

begin_comment
comment|/* PHY address - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC2H
value|0x05860
end_define

begin_comment
comment|/* Managment Control To Host - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_SW_FW_SYNC
value|0x05B5C
end_define

begin_comment
comment|/* Software-Firmware Synchronization - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_GCR
value|0x05B00
end_define

begin_comment
comment|/* PCI-Ex Control */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_1
value|0x05B10
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #1 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_2
value|0x05B14
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #2 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_3
value|0x05B18
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #3 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_4
value|0x05B1C
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #4 */
end_comment

begin_define
define|#
directive|define
name|E1000_FACTPS
value|0x05B30
end_define

begin_comment
comment|/* Function Active and Power State to MNG */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM
value|0x05B50
end_define

begin_comment
comment|/* SW Semaphore */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM
value|0x05B54
end_define

begin_comment
comment|/* FW Semaphore */
end_comment

begin_define
define|#
directive|define
name|E1000_FFLT_DBG
value|0x05F04
end_define

begin_comment
comment|/* Debug Register */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR
value|0x08F00
end_define

begin_comment
comment|/* Host Inteface Control */
end_comment

begin_comment
comment|/* RSS registers */
end_comment

begin_define
define|#
directive|define
name|E1000_CPUVEC
value|0x02C10
end_define

begin_comment
comment|/* CPU Vector Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MRQC
value|0x05818
end_define

begin_comment
comment|/* Multiple Receive Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RETA
value|0x05C00
end_define

begin_comment
comment|/* Redirection Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSRK
value|0x05C80
end_define

begin_comment
comment|/* RSS Random Key - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSIM
value|0x05864
end_define

begin_comment
comment|/* RSS Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSIR
value|0x05868
end_define

begin_comment
comment|/* RSS Interrupt Request */
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
name|E1000_82542_CTRL_DUP
value|E1000_CTRL_DUP
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
name|E1000_82542_FLA
value|E1000_FLA
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
name|E1000_82542_SCTL
value|E1000_SCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_FEXTNVM
value|E1000_FEXTNVM
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
name|E1000_82542_RDTR0
value|E1000_82542_RDTR
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAL0
value|E1000_82542_RDBAL
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAH0
value|E1000_82542_RDBAH
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDLEN0
value|E1000_82542_RDLEN
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDH0
value|E1000_82542_RDH
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDT0
value|E1000_82542_RDT
end_define

begin_define
define|#
directive|define
name|E1000_82542_SRRCTL
parameter_list|(
name|_n
parameter_list|)
value|(0x280C + ((_n)<< 8))
end_define

begin_comment
comment|/* Split and Replication                                                        * RX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_DCA_RXCTRL
parameter_list|(
name|_n
parameter_list|)
value|(0x02814 + ((_n)<< 8))
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAH3
value|0x02B04
end_define

begin_comment
comment|/* RX Desc Base High Queue 3 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDBAL3
value|0x02B00
end_define

begin_comment
comment|/* RX Desc Low Queue 3 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDLEN3
value|0x02B08
end_define

begin_comment
comment|/* RX Desc Length Queue 3 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDH3
value|0x02B10
end_define

begin_comment
comment|/* RX Desc Head Queue 3 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDT3
value|0x02B18
end_define

begin_comment
comment|/* RX Desc Tail Queue 3 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDBAL2
value|0x02A00
end_define

begin_comment
comment|/* RX Desc Base Low Queue 2 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDBAH2
value|0x02A04
end_define

begin_comment
comment|/* RX Desc Base High Queue 2 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDLEN2
value|0x02A08
end_define

begin_comment
comment|/* RX Desc Length Queue 2 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDH2
value|0x02A10
end_define

begin_comment
comment|/* RX Desc Head Queue 2 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDT2
value|0x02A18
end_define

begin_comment
comment|/* RX Desc Tail Queue 2 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_82542_RDTR1
value|0x00130
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAL1
value|0x00138
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDBAH1
value|0x0013C
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDLEN1
value|0x00140
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDH1
value|0x00148
end_define

begin_define
define|#
directive|define
name|E1000_82542_RDT1
value|0x00150
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
name|E1000_82542_TCTL_EXT
value|E1000_TCTL_EXT
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
name|E1000_82542_AIT
value|E1000_AIT
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
name|E1000_82542_PBS
value|E1000_PBS
end_define

begin_define
define|#
directive|define
name|E1000_82542_EEMNGCTL
value|E1000_EEMNGCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_EEARBC
value|E1000_EEARBC
end_define

begin_define
define|#
directive|define
name|E1000_82542_FLASHT
value|E1000_FLASHT
end_define

begin_define
define|#
directive|define
name|E1000_82542_EEWR
value|E1000_EEWR
end_define

begin_define
define|#
directive|define
name|E1000_82542_FLSWCTL
value|E1000_FLSWCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_FLSWDATA
value|E1000_FLSWDATA
end_define

begin_define
define|#
directive|define
name|E1000_82542_FLSWCNT
value|E1000_FLSWCNT
end_define

begin_define
define|#
directive|define
name|E1000_82542_FLOP
value|E1000_FLOP
end_define

begin_define
define|#
directive|define
name|E1000_82542_EXTCNF_CTRL
value|E1000_EXTCNF_CTRL
end_define

begin_define
define|#
directive|define
name|E1000_82542_EXTCNF_SIZE
value|E1000_EXTCNF_SIZE
end_define

begin_define
define|#
directive|define
name|E1000_82542_PHY_CTRL
value|E1000_PHY_CTRL
end_define

begin_define
define|#
directive|define
name|E1000_82542_ERT
value|E1000_ERT
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
name|E1000_82542_RXDCTL1
value|E1000_RXDCTL1
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
name|E1000_82542_KABGTXD
value|E1000_KABGTXD
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDFHS
value|E1000_TDFHS
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDFTS
value|E1000_TDFTS
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDFPC
value|E1000_TDFPC
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
name|E1000_82542_TDFH
value|0x08010
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDFT
value|0x08018
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

begin_define
define|#
directive|define
name|E1000_82542_HOST_IF
value|E1000_HOST_IF
end_define

begin_define
define|#
directive|define
name|E1000_82542_IAM
value|E1000_IAM
end_define

begin_define
define|#
directive|define
name|E1000_82542_EEMNGCTL
value|E1000_EEMNGCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_PSRCTL
value|E1000_PSRCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_RAID
value|E1000_RAID
end_define

begin_define
define|#
directive|define
name|E1000_82542_TARC0
value|E1000_TARC0
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDBAL1
value|E1000_TDBAL1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDBAH1
value|E1000_TDBAH1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDLEN1
value|E1000_TDLEN1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDH1
value|E1000_TDH1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TDT1
value|E1000_TDT1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TXDCTL1
value|E1000_TXDCTL1
end_define

begin_define
define|#
directive|define
name|E1000_82542_TARC1
value|E1000_TARC1
end_define

begin_define
define|#
directive|define
name|E1000_82542_RFCTL
value|E1000_RFCTL
end_define

begin_define
define|#
directive|define
name|E1000_82542_GCR
value|E1000_GCR
end_define

begin_define
define|#
directive|define
name|E1000_82542_GSCL_1
value|E1000_GSCL_1
end_define

begin_define
define|#
directive|define
name|E1000_82542_GSCL_2
value|E1000_GSCL_2
end_define

begin_define
define|#
directive|define
name|E1000_82542_GSCL_3
value|E1000_GSCL_3
end_define

begin_define
define|#
directive|define
name|E1000_82542_GSCL_4
value|E1000_GSCL_4
end_define

begin_define
define|#
directive|define
name|E1000_82542_FACTPS
value|E1000_FACTPS
end_define

begin_define
define|#
directive|define
name|E1000_82542_SWSM
value|E1000_SWSM
end_define

begin_define
define|#
directive|define
name|E1000_82542_FWSM
value|E1000_FWSM
end_define

begin_define
define|#
directive|define
name|E1000_82542_FFLT_DBG
value|E1000_FFLT_DBG
end_define

begin_define
define|#
directive|define
name|E1000_82542_IAC
value|E1000_IAC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICRXPTC
value|E1000_ICRXPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICRXATC
value|E1000_ICRXATC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICTXPTC
value|E1000_ICTXPTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICTXATC
value|E1000_ICTXATC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICTXQEC
value|E1000_ICTXQEC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICTXQMTC
value|E1000_ICTXQMTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICRXDMTC
value|E1000_ICRXDMTC
end_define

begin_define
define|#
directive|define
name|E1000_82542_ICRXOC
value|E1000_ICRXOC
end_define

begin_define
define|#
directive|define
name|E1000_82542_HICR
value|E1000_HICR
end_define

begin_define
define|#
directive|define
name|E1000_82542_CPUVEC
value|E1000_CPUVEC
end_define

begin_define
define|#
directive|define
name|E1000_82542_MRQC
value|E1000_MRQC
end_define

begin_define
define|#
directive|define
name|E1000_82542_RETA
value|E1000_RETA
end_define

begin_define
define|#
directive|define
name|E1000_82542_RSSRK
value|E1000_RSSRK
end_define

begin_define
define|#
directive|define
name|E1000_82542_RSSIM
value|E1000_RSSIM
end_define

begin_define
define|#
directive|define
name|E1000_82542_RSSIR
value|E1000_RSSIR
end_define

begin_define
define|#
directive|define
name|E1000_82542_KUMCTRLSTA
value|E1000_KUMCTRLSTA
end_define

begin_define
define|#
directive|define
name|E1000_82542_SW_FW_SYNC
value|E1000_SW_FW_SYNC
end_define

begin_comment
comment|/* Statistics counters collected by the MAC */
end_comment

begin_struct
struct|struct
name|em_hw_stats
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
name|uint64_t
name|iac
decl_stmt|;
name|uint64_t
name|icrxptc
decl_stmt|;
name|uint64_t
name|icrxatc
decl_stmt|;
name|uint64_t
name|ictxptc
decl_stmt|;
name|uint64_t
name|ictxatc
decl_stmt|;
name|uint64_t
name|ictxqec
decl_stmt|;
name|uint64_t
name|ictxqmtc
decl_stmt|;
name|uint64_t
name|icrxdmtc
decl_stmt|;
name|uint64_t
name|icrxoc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure containing variables used by the shared code (em_hw.c) */
end_comment

begin_struct
struct|struct
name|em_hw
block|{
name|uint8_t
modifier|*
name|hw_addr
decl_stmt|;
name|uint8_t
modifier|*
name|flash_address
decl_stmt|;
name|em_mac_type
name|mac_type
decl_stmt|;
name|em_phy_type
name|phy_type
decl_stmt|;
name|uint32_t
name|phy_init_script
decl_stmt|;
name|em_media_type
name|media_type
decl_stmt|;
name|void
modifier|*
name|back
decl_stmt|;
name|struct
name|em_shadow_ram
modifier|*
name|eeprom_shadow_ram
decl_stmt|;
name|uint32_t
name|flash_bank_size
decl_stmt|;
name|uint32_t
name|flash_base_addr
decl_stmt|;
name|uint32_t
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
name|struct
name|em_eeprom_info
name|eeprom
decl_stmt|;
name|em_ms_type
name|master_slave
decl_stmt|;
name|em_ms_type
name|original_master_slave
decl_stmt|;
name|em_ffe_config
name|ffe_config_state
decl_stmt|;
name|uint32_t
name|asf_firmware_present
decl_stmt|;
name|uint32_t
name|eeprom_semaphore_present
decl_stmt|;
name|uint32_t
name|swfw_sync_present
decl_stmt|;
name|uint32_t
name|swfwhw_semaphore_present
decl_stmt|;
name|unsigned
name|long
name|io_base
decl_stmt|;
name|uint32_t
name|phy_id
decl_stmt|;
name|uint32_t
name|phy_revision
decl_stmt|;
name|uint32_t
name|phy_addr
decl_stmt|;
name|uint32_t
name|original_fc
decl_stmt|;
name|uint32_t
name|txcw
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
name|uint32_t
name|collision_delta
decl_stmt|;
name|uint32_t
name|tx_packet_delta
decl_stmt|;
name|uint32_t
name|ledctl_default
decl_stmt|;
name|uint32_t
name|ledctl_mode1
decl_stmt|;
name|uint32_t
name|ledctl_mode2
decl_stmt|;
name|boolean_t
name|tx_pkt_filtering
decl_stmt|;
name|struct
name|em_host_mng_dhcp_cookie
name|mng_cookie
decl_stmt|;
name|uint16_t
name|phy_spd_default
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
name|current_ifs_val
decl_stmt|;
name|uint16_t
name|ifs_min_val
decl_stmt|;
name|uint16_t
name|ifs_max_val
decl_stmt|;
name|uint16_t
name|ifs_step_size
decl_stmt|;
name|uint16_t
name|ifs_ratio
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
name|uint8_t
name|perm_mac_addr
index|[
name|NODE_ADDRESS_SIZE
index|]
decl_stmt|;
name|boolean_t
name|disable_polarity_correction
decl_stmt|;
name|boolean_t
name|speed_downgraded
decl_stmt|;
name|em_smart_speed
name|smart_speed
decl_stmt|;
name|em_dsp_config
name|dsp_config_state
decl_stmt|;
name|boolean_t
name|get_link_status
decl_stmt|;
name|boolean_t
name|serdes_link_down
decl_stmt|;
name|boolean_t
name|tbi_compatibility_en
decl_stmt|;
name|boolean_t
name|tbi_compatibility_on
decl_stmt|;
name|boolean_t
name|laa_is_present
decl_stmt|;
name|boolean_t
name|phy_reset_disable
decl_stmt|;
name|boolean_t
name|initialize_hw_bits_disable
decl_stmt|;
name|boolean_t
name|fc_send_xon
decl_stmt|;
name|boolean_t
name|fc_strict_ieee
decl_stmt|;
name|boolean_t
name|report_tx_early
decl_stmt|;
name|boolean_t
name|adaptive_ifs
decl_stmt|;
name|boolean_t
name|ifs_params_forced
decl_stmt|;
name|boolean_t
name|in_ifs_mode
decl_stmt|;
name|boolean_t
name|mng_reg_access_disabled
decl_stmt|;
name|boolean_t
name|leave_av_bit_off
decl_stmt|;
name|boolean_t
name|kmrn_lock_loss_workaround_disabled
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

begin_define
define|#
directive|define
name|E1000_EEPROM_RW_REG_DATA
value|16
end_define

begin_comment
comment|/* Offset to data in EEPROM read/write registers */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_RW_REG_DONE
value|2
end_define

begin_comment
comment|/* Offset to READ/WRITE done bit */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_RW_REG_START
value|1
end_define

begin_comment
comment|/* First bit for telling part to start operation */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_RW_ADDR_SHIFT
value|2
end_define

begin_comment
comment|/* Shift to the address bits */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_POLL_WRITE
value|1
end_define

begin_comment
comment|/* Flag for polling for write complete */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_POLL_READ
value|0
end_define

begin_comment
comment|/* Flag for polling for read complete */
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
name|E1000_CTRL_GIO_MASTER_DISABLE
value|0x00000004
end_define

begin_comment
comment|/*Blocks new Master requests */
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
name|E1000_CTRL_D_UD_EN
value|0x00002000
end_define

begin_comment
comment|/* Dock/Undock enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_D_UD_POLARITY
value|0x00004000
end_define

begin_comment
comment|/* Defined polarity of Dock/Undock indication in SDP[0] */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_FORCE_PHY_RESET
value|0x00008000
end_define

begin_comment
comment|/* Reset both PHY ports, through PHYRST_N pin */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_EN
value|0x00010000
end_define

begin_comment
comment|/* enable link status from external LINK_0 and LINK_1 pins */
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

begin_define
define|#
directive|define
name|E1000_CTRL_SW2FW_INT
value|0x02000000
end_define

begin_comment
comment|/* Initiate an interrupt to manageability engine */
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
name|E1000_STATUS_FUNC_SHIFT
value|2
end_define

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
name|E1000_STATUS_LAN_INIT_DONE
value|0x00000200
end_define

begin_comment
comment|/* Lan Init Completion                                                    by EEPROM/Flash */
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
name|E1000_STATUS_DOCK_CI
value|0x00000800
end_define

begin_comment
comment|/* Change in Dock/Undock state. Clear on write '0'. */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_GIO_MASTER_ENABLE
value|0x00080000
end_define

begin_comment
comment|/* Status of Master requests. */
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

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_0
value|0x00100000
end_define

begin_comment
comment|/* BMC USB redirect disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_1
value|0x00200000
end_define

begin_comment
comment|/* BMC SRAM disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_SKU_2
value|0x00400000
end_define

begin_comment
comment|/* BMC SDRAM disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_CRYPTO
value|0x00800000
end_define

begin_comment
comment|/* BMC crypto disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_BMC_LITE
value|0x01000000
end_define

begin_comment
comment|/* BMC external code execution disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_RGMII_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* RGMII disabled */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_FUSE_8
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_FUSE_9
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_STATUS_SERDES0_DIS
value|0x10000000
end_define

begin_comment
comment|/* SERDES disabled on port 0 */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS_SERDES1_DIS
value|0x20000000
end_define

begin_comment
comment|/* SERDES disabled on port 1 */
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
name|E1000_EECD_ADDR_BITS
value|0x00000400
end_define

begin_comment
comment|/* EEPROM Addressing bits based on type                                          * (0-small, 1-large) */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_TYPE
value|0x00002000
end_define

begin_comment
comment|/* EEPROM Type (1-SPI, 0-Microwire) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|E1000_EEPROM_GRANT_ATTEMPTS
end_ifndef

begin_define
define|#
directive|define
name|E1000_EEPROM_GRANT_ATTEMPTS
value|1000
end_define

begin_comment
comment|/* EEPROM # attempts to gain grant */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|E1000_EECD_AUTO_RD
value|0x00000200
end_define

begin_comment
comment|/* EEPROM Auto Read done */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SIZE_EX_MASK
value|0x00007800
end_define

begin_comment
comment|/* EEprom Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SIZE_EX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|E1000_EECD_NVADDS
value|0x00018000
end_define

begin_comment
comment|/* NVM Address Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SELSHAD
value|0x00020000
end_define

begin_comment
comment|/* Select Shadow RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_INITSRAM
value|0x00040000
end_define

begin_comment
comment|/* Initialize Shadow RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_FLUPD
value|0x00080000
end_define

begin_comment
comment|/* Update FLASH */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_AUPDEN
value|0x00100000
end_define

begin_comment
comment|/* Enable Autonomous FLASH update */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SHADV
value|0x00200000
end_define

begin_comment
comment|/* Shadow RAM Data Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SEC1VAL
value|0x00400000
end_define

begin_comment
comment|/* Sector One Valid */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD_SECVAL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|E1000_STM_OPCODE
value|0xDB00
end_define

begin_define
define|#
directive|define
name|E1000_HICR_FW_RESET
value|0xC0
end_define

begin_define
define|#
directive|define
name|E1000_SHADOW_RAM_WORDS
value|2048
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_WORD
value|0x13
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_MASK
value|0xC0
end_define

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
comment|/* SPI EEPROM Status Register */
end_comment

begin_define
define|#
directive|define
name|EEPROM_STATUS_RDY_SPI
value|0x01
end_define

begin_define
define|#
directive|define
name|EEPROM_STATUS_WEN_SPI
value|0x02
end_define

begin_define
define|#
directive|define
name|EEPROM_STATUS_BP0_SPI
value|0x04
end_define

begin_define
define|#
directive|define
name|EEPROM_STATUS_BP1_SPI
value|0x08
end_define

begin_define
define|#
directive|define
name|EEPROM_STATUS_WPEN_SPI
value|0x80
end_define

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
name|E1000_CTRL_EXT_RO_DIS
value|0x00020000
end_define

begin_comment
comment|/* Relaxed Ordering disable */
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
name|E1000_CTRL_EXT_LINK_MODE_KMRN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_SERDES
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_LINK_MODE_SGMII
value|0x00800000
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

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_DRV_LOAD
value|0x10000000
end_define

begin_comment
comment|/* Driver loaded bit for FW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_IAME
value|0x08000000
end_define

begin_comment
comment|/* Interrupt acknowledge Auto-mask */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_INT_TIMER_CLR
value|0x20000000
end_define

begin_comment
comment|/* Clear Interrupt timers after IMS clear */
end_comment

begin_define
define|#
directive|define
name|E1000_CRTL_EXT_PB_PAREN
value|0x01000000
end_define

begin_comment
comment|/* packet buffer parity error detection enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_DF_PAREN
value|0x02000000
end_define

begin_comment
comment|/* descriptor FIFO parity error detection enable */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT_GHOST_PAREN
value|0x40000000
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

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_REN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_FIFO_CTRL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_CTRL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_INB_CTRL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_DIAG
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_TIMEOUTS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_INB_PARAM
value|0x00000009
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_HD_CTRL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_M2P_SERDES
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_M2P_MODES
value|0x0000001F
end_define

begin_comment
comment|/* FIFO Control */
end_comment

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_FIFO_CTRL_RX_BYPASS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_FIFO_CTRL_TX_BYPASS
value|0x00000800
end_define

begin_comment
comment|/* In-Band Control */
end_comment

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_INB_CTRL_LINK_STATUS_TX_TIMEOUT_DEFAULT
value|0x00000500
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_INB_CTRL_DIS_PADDING
value|0x00000010
end_define

begin_comment
comment|/* Half-Duplex Control */
end_comment

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_HD_CTRL_10_100_DEFAULT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_HD_CTRL_1000_DEFAULT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_OFFSET_K0S_CTRL
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_DIAG_FELPBK
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_DIAG_NELPBK
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_K0S_100_EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_K0S_GBE_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_KUMCTRLSTA_K0S_ENTRY_LATENCY_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|E1000_KABGTXD_BGSQLBIAS
value|0x00050000
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_SPD_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_D0A_LPLU
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_NOND0A_LPLU
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_NOND0A_GBE_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_GBE_DISABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_PHY_CTRL_B2B_EN
value|0x00000080
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
name|E1000_LEDCTL_LED0_BLINK_RATE
value|0x0000020
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
name|E1000_LEDCTL_LED1_BLINK_RATE
value|0x0002000
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
name|E1000_LEDCTL_LED2_BLINK_RATE
value|0x00200000
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
name|E1000_LEDCTL_LED3_BLINK_RATE
value|0x20000000
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

begin_define
define|#
directive|define
name|E1000_ICR_ACK
value|0x00020000
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_MNG
value|0x00040000
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_DOCK
value|0x00080000
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_INT_ASSERTED
value|0x80000000
end_define

begin_comment
comment|/* If this bit asserted, the driver should claim the interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXD_FIFO_PAR0
value|0x00100000
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_FIFO_PAR0
value|0x00200000
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_HOST_ARB_PAR
value|0x00400000
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_PB_PAR
value|0x00800000
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_RXD_FIFO_PAR1
value|0x01000000
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_TXD_FIFO_PAR1
value|0x02000000
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_ALL_PARITY
value|0x03F00000
end_define

begin_comment
comment|/* all parity error bits */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_DSW
value|0x00000020
end_define

begin_comment
comment|/* FW changed the status of DISSW bit in the FWSM */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_PHYINT
value|0x00001000
end_define

begin_comment
comment|/* LAN connected device generates an interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_EPRST
value|0x00100000
end_define

begin_comment
comment|/* ME handware reset occurs */
end_comment

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

begin_define
define|#
directive|define
name|E1000_ICS_ACK
value|E1000_ICR_ACK
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_MNG
value|E1000_ICR_MNG
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_DOCK
value|E1000_ICR_DOCK
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXD_FIFO_PAR0
value|E1000_ICR_RXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_FIFO_PAR0
value|E1000_ICR_TXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_HOST_ARB_PAR
value|E1000_ICR_HOST_ARB_PAR
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_PB_PAR
value|E1000_ICR_PB_PAR
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_RXD_FIFO_PAR1
value|E1000_ICR_RXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_TXD_FIFO_PAR1
value|E1000_ICR_TXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_DSW
value|E1000_ICR_DSW
end_define

begin_define
define|#
directive|define
name|E1000_ICS_PHYINT
value|E1000_ICR_PHYINT
end_define

begin_define
define|#
directive|define
name|E1000_ICS_EPRST
value|E1000_ICR_EPRST
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

begin_define
define|#
directive|define
name|E1000_IMS_ACK
value|E1000_ICR_ACK
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_MNG
value|E1000_ICR_MNG
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DOCK
value|E1000_ICR_DOCK
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXD_FIFO_PAR0
value|E1000_ICR_RXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_FIFO_PAR0
value|E1000_ICR_TXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_HOST_ARB_PAR
value|E1000_ICR_HOST_ARB_PAR
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_PB_PAR
value|E1000_ICR_PB_PAR
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_RXD_FIFO_PAR1
value|E1000_ICR_RXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_TXD_FIFO_PAR1
value|E1000_ICR_TXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_DSW
value|E1000_ICR_DSW
end_define

begin_define
define|#
directive|define
name|E1000_IMS_PHYINT
value|E1000_ICR_PHYINT
end_define

begin_define
define|#
directive|define
name|E1000_IMS_EPRST
value|E1000_ICR_EPRST
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

begin_define
define|#
directive|define
name|E1000_IMC_ACK
value|E1000_ICR_ACK
end_define

begin_comment
comment|/* Receive Ack frame */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_MNG
value|E1000_ICR_MNG
end_define

begin_comment
comment|/* Manageability event */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_DOCK
value|E1000_ICR_DOCK
end_define

begin_comment
comment|/* Dock/Undock */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXD_FIFO_PAR0
value|E1000_ICR_RXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_TXD_FIFO_PAR0
value|E1000_ICR_TXD_FIFO_PAR0
end_define

begin_comment
comment|/* queue 0 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_HOST_ARB_PAR
value|E1000_ICR_HOST_ARB_PAR
end_define

begin_comment
comment|/* host arb read buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_PB_PAR
value|E1000_ICR_PB_PAR
end_define

begin_comment
comment|/* packet buffer parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_RXD_FIFO_PAR1
value|E1000_ICR_RXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Rx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_TXD_FIFO_PAR1
value|E1000_ICR_TXD_FIFO_PAR1
end_define

begin_comment
comment|/* queue 1 Tx descriptor FIFO parity error */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_DSW
value|E1000_ICR_DSW
end_define

begin_define
define|#
directive|define
name|E1000_IMC_PHYINT
value|E1000_ICR_PHYINT
end_define

begin_define
define|#
directive|define
name|E1000_IMC_EPRST
value|E1000_ICR_EPRST
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
name|E1000_RCTL_DTYP_MASK
value|0x00000C00
end_define

begin_comment
comment|/* Descriptor type mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_DTYP_PS
value|0x00000400
end_define

begin_comment
comment|/* Packet Split descriptor */
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

begin_define
define|#
directive|define
name|E1000_RCTL_SECRC
value|0x04000000
end_define

begin_comment
comment|/* Strip Ethernet CRC */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_FLXBUF_MASK
value|0x78000000
end_define

begin_comment
comment|/* Flexible buffer size */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL_FLXBUF_SHIFT
value|27
end_define

begin_comment
comment|/* Flexible buffer shift */
end_comment

begin_comment
comment|/* Use byte values for the following shift parameters  * Usage:  *     psrctl |= (((ROUNDUP(value0, 128)>> E1000_PSRCTL_BSIZE0_SHIFT)&  *                  E1000_PSRCTL_BSIZE0_MASK) |  *                ((ROUNDUP(value1, 1024)>> E1000_PSRCTL_BSIZE1_SHIFT)&  *                  E1000_PSRCTL_BSIZE1_MASK) |  *                ((ROUNDUP(value2, 1024)<< E1000_PSRCTL_BSIZE2_SHIFT)&  *                  E1000_PSRCTL_BSIZE2_MASK) |  *                ((ROUNDUP(value3, 1024)<< E1000_PSRCTL_BSIZE3_SHIFT) |;  *                  E1000_PSRCTL_BSIZE3_MASK))  * where value0 = [128..16256],  default=256  *       value1 = [1024..64512], default=4096  *       value2 = [0..64512],    default=4096  *       value3 = [0..64512],    default=0  */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE0_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE1_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE2_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE3_MASK
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE0_SHIFT
value|7
end_define

begin_comment
comment|/* Shift _right_ 7 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE1_SHIFT
value|2
end_define

begin_comment
comment|/* Shift _right_ 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE2_SHIFT
value|6
end_define

begin_comment
comment|/* Shift _left_ 6 */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL_BSIZE3_SHIFT
value|14
end_define

begin_comment
comment|/* Shift _left_ 14 */
end_comment

begin_comment
comment|/* SW_W_SYNC definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_SWFW_EEP_SM
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY0_SM
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_PHY1_SM
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_SWFW_MAC_CSR_SM
value|0x0008
end_define

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
comment|/* Flow Control Settings */
end_comment

begin_define
define|#
directive|define
name|E1000_FC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|E1000_FC_RX_PAUSE
value|1
end_define

begin_define
define|#
directive|define
name|E1000_FC_TX_PAUSE
value|2
end_define

begin_define
define|#
directive|define
name|E1000_FC_FULL
value|3
end_define

begin_define
define|#
directive|define
name|E1000_FC_DEFAULT
value|0xFF
end_define

begin_comment
comment|/* Header split receive */
end_comment

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DWC_MASK
value|0x0000003E
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ISCSI_DWC_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFSW_DIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFSR_DIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFS_VER_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NFS_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_DIS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_XSUM_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ACK_DIS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_ACKD_DIS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPFRSP_DIS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_EXTEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_IPV6_EX_DIS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_RFCTL_NEW_IPV6_EXT_DIS
value|0x00020000
end_define

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

begin_define
define|#
directive|define
name|E1000_TXDCTL_FULL_TX_DESC_WB
value|0x01010000
end_define

begin_comment
comment|/* GRAN=1, WTHRESH=1 */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_COUNT_DESC
value|0x00400000
end_define

begin_comment
comment|/* Enable the counting of desc.                                               still to be processed. */
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

begin_define
define|#
directive|define
name|E1000_TCTL_MULR
value|0x10000000
end_define

begin_comment
comment|/* Multiple request support */
end_comment

begin_comment
comment|/* Extended Transmit Control */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EXT_BST_MASK
value|0x000003FF
end_define

begin_comment
comment|/* Backoff Slot Time */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EXT_GCEX_MASK
value|0x000FFC00
end_define

begin_comment
comment|/* Gigabit Carry Extend Padding */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_80003ES2LAN_TCTL_EXT_GCEX
value|0x00010000
end_define

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

begin_define
define|#
directive|define
name|E1000_RXCSUM_IPPCSE
value|0x00001000
end_define

begin_comment
comment|/* IP payload checksum enable */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM_PCSD
value|0x00002000
end_define

begin_comment
comment|/* packet checksum disabled */
end_comment

begin_comment
comment|/* Multiple Receive Queue Control */
end_comment

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_RSS_2Q
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_ENABLE_RSS_INT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV4_TCP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_TCP_EX
value|0x00040000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_EX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_MRQC_RSS_FIELD_IPV6_TCP
value|0x00200000
end_define

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

begin_define
define|#
directive|define
name|E1000_WUC_SPM
value|0x80000000
end_define

begin_comment
comment|/* Enable SPM */
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
name|E1000_WUFC_IGNORE_TCO
value|0x00008000
end_define

begin_comment
comment|/* Ignore WakeOn TCO packets */
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
comment|/* Enable Neighbor Discovery                                              * Filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_ARP_RES_EN
value|0x00008000
end_define

begin_comment
comment|/* Enable ARP response Filtering */
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
name|E1000_MANC_RCV_ALL
value|0x00080000
end_define

begin_comment
comment|/* Receive All Enabled */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_BLK_PHY_RST_ON_IDE
value|0x00040000
end_define

begin_comment
comment|/* Block phy resets */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MAC_ADDR_FILTER
value|0x00100000
end_define

begin_comment
comment|/* Enable MAC address                                                     * filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_MNG2HOST
value|0x00200000
end_define

begin_comment
comment|/* Enable MNG packets to host                                              * memory */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_IP_ADDR_FILTER
value|0x00400000
end_define

begin_comment
comment|/* Enable IP address                                                     * filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_EN_XSUM_FILTER
value|0x00800000
end_define

begin_comment
comment|/* Enable checksum filtering */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC_BR_EN
value|0x01000000
end_define

begin_comment
comment|/* Enable broadcast filtering */
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
comment|/* SW Semaphore Register */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_SMBI
value|0x00000001
end_define

begin_comment
comment|/* Driver Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_SWESMBI
value|0x00000002
end_define

begin_comment
comment|/* FW Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_WMNG
value|0x00000004
end_define

begin_comment
comment|/* Wake MNG Clock */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM_DRV_LOAD
value|0x00000008
end_define

begin_comment
comment|/* Driver Loaded Bit */
end_comment

begin_comment
comment|/* FW Semaphore Register */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_MODE_MASK
value|0x0000000E
end_define

begin_comment
comment|/* FW mode */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_MODE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_FW_VALID
value|0x00008000
end_define

begin_comment
comment|/* FW established a valid mode */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_RSPCIPHY
value|0x00000040
end_define

begin_comment
comment|/* Reset PHY on PCI reset */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_DISSW
value|0x10000000
end_define

begin_comment
comment|/* FW disable SW Write Access */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_SKUSEL_MASK
value|0x60000000
end_define

begin_comment
comment|/* LAN SKU select */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_SKUEL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_SKUSEL_EMB
value|0x0
end_define

begin_comment
comment|/* Embedded SKU */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_SKUSEL_CONS
value|0x1
end_define

begin_comment
comment|/* Consumer SKU */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_SKUSEL_PERF_100
value|0x2
end_define

begin_comment
comment|/* Perf& Corp 10/100 SKU */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM_SKUSEL_PERF_GBE
value|0x3
end_define

begin_comment
comment|/* Perf& Copr GbE SKU */
end_comment

begin_comment
comment|/* FFLT Debug Register */
end_comment

begin_define
define|#
directive|define
name|E1000_FFLT_DBG_INVC
value|0x00100000
end_define

begin_comment
comment|/* Invalid /C/ code handling */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_mng_mode_none
init|=
literal|0
block|,
name|em_mng_mode_asf
block|,
name|em_mng_mode_pt
block|,
name|em_mng_mode_ipmi
block|,
name|em_mng_mode_host_interface_only
block|}
name|em_mng_mode
typedef|;
end_typedef

begin_comment
comment|/* Host Inteface Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_EN
value|0x00000001
end_define

begin_comment
comment|/* Enable Bit - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_C
value|0x00000002
end_define

begin_comment
comment|/* Driver sets this bit when done                                              * to put command in RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_SV
value|0x00000004
end_define

begin_comment
comment|/* Status Validity */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_FWR
value|0x00000080
end_define

begin_comment
comment|/* FW reset. Set by the Host */
end_comment

begin_comment
comment|/* Host Interface Command Interface - Address range 0x8800-0x8EFF */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_MAX_DATA_LENGTH
value|252
end_define

begin_comment
comment|/* Host Interface data length */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_MAX_BLOCK_BYTE_LENGTH
value|1792
end_define

begin_comment
comment|/* Number of bytes in range */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_MAX_BLOCK_DWORD_LENGTH
value|448
end_define

begin_comment
comment|/* Number of dwords in range */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_COMMAND_TIMEOUT
value|500
end_define

begin_comment
comment|/* Time in ms to process HI command */
end_comment

begin_struct
struct|struct
name|em_host_command_header
block|{
name|uint8_t
name|command_id
decl_stmt|;
name|uint8_t
name|command_length
decl_stmt|;
name|uint8_t
name|command_options
decl_stmt|;
comment|/* I/F bits for command, status for return */
name|uint8_t
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_host_command_info
block|{
name|struct
name|em_host_command_header
name|command_header
decl_stmt|;
comment|/* Command Head/Command Result Head has 4 bytes */
name|uint8_t
name|command_data
index|[
name|E1000_HI_MAX_DATA_LENGTH
index|]
decl_stmt|;
comment|/* Command data can length 0..252 */
block|}
struct|;
end_struct

begin_comment
comment|/* Host SMB register #0 */
end_comment

begin_define
define|#
directive|define
name|E1000_HSMC0R_CLKIN
value|0x00000001
end_define

begin_comment
comment|/* SMB Clock in */
end_comment

begin_define
define|#
directive|define
name|E1000_HSMC0R_DATAIN
value|0x00000002
end_define

begin_comment
comment|/* SMB Data in */
end_comment

begin_define
define|#
directive|define
name|E1000_HSMC0R_DATAOUT
value|0x00000004
end_define

begin_comment
comment|/* SMB Data out */
end_comment

begin_define
define|#
directive|define
name|E1000_HSMC0R_CLKOUT
value|0x00000008
end_define

begin_comment
comment|/* SMB Clock out */
end_comment

begin_comment
comment|/* Host SMB register #1 */
end_comment

begin_define
define|#
directive|define
name|E1000_HSMC1R_CLKIN
value|E1000_HSMC0R_CLKIN
end_define

begin_define
define|#
directive|define
name|E1000_HSMC1R_DATAIN
value|E1000_HSMC0R_DATAIN
end_define

begin_define
define|#
directive|define
name|E1000_HSMC1R_DATAOUT
value|E1000_HSMC0R_DATAOUT
end_define

begin_define
define|#
directive|define
name|E1000_HSMC1R_CLKOUT
value|E1000_HSMC0R_CLKOUT
end_define

begin_comment
comment|/* FW Status Register */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSTS_FWS_MASK
value|0x000000FF
end_define

begin_comment
comment|/* FW Status */
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
comment|/* PCI-Ex registers*/
end_comment

begin_comment
comment|/* PCI-Ex Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_GCR_RXD_NO_SNOOP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_GCR_RXDSCW_NO_SNOOP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_GCR_RXDSCR_NO_SNOOP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXD_NO_SNOOP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXDSCW_NO_SNOOP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|E1000_GCR_TXDSCR_NO_SNOOP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCI_EX_NO_SNOOP_ALL
value|(E1000_GCR_RXD_NO_SNOOP         | \                              E1000_GCR_RXDSCW_NO_SNOOP      | \                              E1000_GCR_RXDSCR_NO_SNOOP      | \                              E1000_GCR_TXD_NO_SNOOP         | \                              E1000_GCR_TXDSCW_NO_SNOOP      | \                              E1000_GCR_TXDSCR_NO_SNOOP)
end_define

begin_define
define|#
directive|define
name|PCI_EX_82566_SNOOP_ALL
value|PCI_EX_NO_SNOOP_ALL
end_define

begin_define
define|#
directive|define
name|E1000_GCR_L1_ACT_WITHOUT_L0S_RX
value|0x08000000
end_define

begin_comment
comment|/* Function Active and Power State to MNG */
end_comment

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC0_POWER_STATE_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_LAN0_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC0_AUX_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC1_POWER_STATE_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC1_POWER_STATE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_LAN1_VALID
value|0x00000100
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC1_AUX_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC2_POWER_STATE_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC2_POWER_STATE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_IDE_ENABLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC2_AUX_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC3_POWER_STATE_MASK
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC3_POWER_STATE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_SP_ENABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC3_AUX_EN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC4_POWER_STATE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC4_POWER_STATE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_IPMI_ENABLE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_FUNC4_AUX_EN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_MNGCG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_LAN_FUNC_SEL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_FACTPS_PM_STATE_CHANGED
value|0x80000000
end_define

begin_comment
comment|/* PCI-Ex Config Space */
end_comment

begin_define
define|#
directive|define
name|PCI_EX_LINK_STATUS
value|0x12
end_define

begin_define
define|#
directive|define
name|PCI_EX_LINK_WIDTH_MASK
value|0x3F0
end_define

begin_define
define|#
directive|define
name|PCI_EX_LINK_WIDTH_SHIFT
value|4
end_define

begin_comment
comment|/* EEPROM Commands - Microwire */
end_comment

begin_define
define|#
directive|define
name|EEPROM_READ_OPCODE_MICROWIRE
value|0x6
end_define

begin_comment
comment|/* EEPROM read opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRITE_OPCODE_MICROWIRE
value|0x5
end_define

begin_comment
comment|/* EEPROM write opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE_OPCODE_MICROWIRE
value|0x7
end_define

begin_comment
comment|/* EEPROM erase opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWEN_OPCODE_MICROWIRE
value|0x13
end_define

begin_comment
comment|/* EEPROM erase/write enable */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWDS_OPCODE_MICROWIRE
value|0x10
end_define

begin_comment
comment|/* EEPROM erast/write disable */
end_comment

begin_comment
comment|/* EEPROM Commands - SPI */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MAX_RETRY_SPI
value|5000
end_define

begin_comment
comment|/* Max wait of 5ms, for RDY signal */
end_comment

begin_define
define|#
directive|define
name|EEPROM_READ_OPCODE_SPI
value|0x03
end_define

begin_comment
comment|/* EEPROM read opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRITE_OPCODE_SPI
value|0x02
end_define

begin_comment
comment|/* EEPROM write opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_A8_OPCODE_SPI
value|0x08
end_define

begin_comment
comment|/* opcode bit-3 = address bit-8 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WREN_OPCODE_SPI
value|0x06
end_define

begin_comment
comment|/* EEPROM set Write Enable latch */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRDI_OPCODE_SPI
value|0x04
end_define

begin_comment
comment|/* EEPROM reset Write Enable latch */
end_comment

begin_define
define|#
directive|define
name|EEPROM_RDSR_OPCODE_SPI
value|0x05
end_define

begin_comment
comment|/* EEPROM read Status register */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRSR_OPCODE_SPI
value|0x01
end_define

begin_comment
comment|/* EEPROM write Status register */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE4K_OPCODE_SPI
value|0x20
end_define

begin_comment
comment|/* EEPROM ERASE 4KB */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE64K_OPCODE_SPI
value|0xD8
end_define

begin_comment
comment|/* EEPROM ERASE 64KB */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE256_OPCODE_SPI
value|0xDB
end_define

begin_comment
comment|/* EEPROM ERASE 256B */
end_comment

begin_comment
comment|/* EEPROM Size definitions */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WORD_SIZE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|EEPROM_SIZE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|EEPROM_SIZE_MASK
value|0x1C00
end_define

begin_comment
comment|/* EEPROM Word Offsets */
end_comment

begin_define
define|#
directive|define
name|EEPROM_COMPAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|EEPROM_ID_LED_SETTINGS
value|0x0004
end_define

begin_define
define|#
directive|define
name|EEPROM_VERSION
value|0x0005
end_define

begin_define
define|#
directive|define
name|EEPROM_SERDES_AMPLITUDE
value|0x0006
end_define

begin_comment
comment|/* For SERDES output amplitude adjustment. */
end_comment

begin_define
define|#
directive|define
name|EEPROM_PHY_CLASS_WORD
value|0x0007
end_define

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
name|EEPROM_SWDEF_PINS_CTRL_PORT_1
value|0x0010
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL3_PORT_B
value|0x0014
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_3GIO_3
value|0x001A
end_define

begin_define
define|#
directive|define
name|EEPROM_SWDEF_PINS_CTRL_PORT_0
value|0x0020
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL3_PORT_A
value|0x0024
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG
value|0x0012
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

begin_define
define|#
directive|define
name|E1000_EEPROM_CFG_DONE
value|0x00040000
end_define

begin_comment
comment|/* MNG config cycle done */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_CFG_DONE_PORT_1
value|0x00080000
end_define

begin_comment
comment|/* ...for second port */
end_comment

begin_comment
comment|/* Word definitions for ID LED Settings */
end_comment

begin_define
define|#
directive|define
name|ID_LED_RESERVED_0000
value|0x0000
end_define

begin_define
define|#
directive|define
name|ID_LED_RESERVED_FFFF
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|ID_LED_RESERVED_82573
value|0xF746
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_82573
value|0x1811
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT
value|((ID_LED_OFF1_ON2<< 12) | \                               (ID_LED_OFF1_OFF2<< 8) | \                               (ID_LED_DEF1_DEF2<< 4) | \                               (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_ICH8LAN
value|((ID_LED_DEF1_DEF2<< 12) | \                                  (ID_LED_DEF1_OFF2<<  8) | \                                  (ID_LED_DEF1_ON2<<  4) | \                                  (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_DEF2
value|0x1
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_ON2
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_LED_DEF1_OFF2
value|0x3
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_DEF2
value|0x4
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_ON2
value|0x5
end_define

begin_define
define|#
directive|define
name|ID_LED_ON1_OFF2
value|0x6
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_DEF2
value|0x7
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_ON2
value|0x8
end_define

begin_define
define|#
directive|define
name|ID_LED_OFF1_OFF2
value|0x9
end_define

begin_define
define|#
directive|define
name|IGP_ACTIVITY_LED_MASK
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|IGP_ACTIVITY_LED_ENABLE
value|0x0300
end_define

begin_define
define|#
directive|define
name|IGP_LED3_MODE
value|0x07000000
end_define

begin_comment
comment|/* Mask bits for SERDES amplitude adjustment in Word 6 of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_SERDES_AMPLITUDE_MASK
value|0x000F
end_define

begin_comment
comment|/* Mask bit for PHY class in Word 7 of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_PHY_CLASS_A
value|0x8000
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

begin_define
define|#
directive|define
name|EEPROM_WORD0F_LPLU
value|0x0001
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x10/0x20 of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WORD1020_GIGA_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|EEPROM_WORD1020_GIGA_DISABLE_NON_D0A
value|0x0008
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x1a of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WORD1A_ASPM_MASK
value|0x000C
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

begin_define
define|#
directive|define
name|EEPROM_RESERVED_WORD
value|0xFFFF
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
value|15
end_define

begin_define
define|#
directive|define
name|E1000_CT_SHIFT
value|4
end_define

begin_comment
comment|/* Collision distance is a 0-based value that applies to  * half-duplex-capable hardware only. */
end_comment

begin_define
define|#
directive|define
name|E1000_COLLISION_DISTANCE
value|63
end_define

begin_define
define|#
directive|define
name|E1000_COLLISION_DISTANCE_82542
value|64
end_define

begin_define
define|#
directive|define
name|E1000_FDX_COLLISION_DISTANCE
value|E1000_COLLISION_DISTANCE
end_define

begin_define
define|#
directive|define
name|E1000_HDX_COLLISION_DISTANCE
value|E1000_COLLISION_DISTANCE
end_define

begin_define
define|#
directive|define
name|E1000_COLD_SHIFT
value|12
end_define

begin_comment
comment|/* Number of Transmit and Receive Descriptors must be a multiple of 8 */
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
name|DEFAULT_80003ES2LAN_TIPG_IPGR2
value|7
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
name|DEFAULT_80003ES2LAN_TIPG_IPGT_10_100
value|0x00000009
end_define

begin_define
define|#
directive|define
name|DEFAULT_80003ES2LAN_TIPG_IPGT_1000
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_TXDMAC_DPP
value|0x00000001
end_define

begin_comment
comment|/* Adaptive IFS defines */
end_comment

begin_define
define|#
directive|define
name|TX_THRESHOLD_START
value|8
end_define

begin_define
define|#
directive|define
name|TX_THRESHOLD_INCREMENT
value|10
end_define

begin_define
define|#
directive|define
name|TX_THRESHOLD_DECREMENT
value|1
end_define

begin_define
define|#
directive|define
name|TX_THRESHOLD_STOP
value|190
end_define

begin_define
define|#
directive|define
name|TX_THRESHOLD_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|TX_THRESHOLD_TIMER_MS
value|10000
end_define

begin_define
define|#
directive|define
name|MIN_NUM_XMITS
value|1000
end_define

begin_define
define|#
directive|define
name|IFS_MAX
value|80
end_define

begin_define
define|#
directive|define
name|IFS_STEP
value|10
end_define

begin_define
define|#
directive|define
name|IFS_MIN
value|40
end_define

begin_define
define|#
directive|define
name|IFS_RATIO
value|4
end_define

begin_comment
comment|/* Extended Configuration Control and Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_PCIE_WRITE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_PHY_WRITE_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_D_UD_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_D_UD_LATENCY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_D_UD_OWNER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_MDIO_SW_OWNERSHIP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_MDIO_HW_OWNERSHIP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_EXT_CNF_POINTER
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE_EXT_PHY_LENGTH
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE_EXT_DOCK_LENGTH
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE_EXT_PCIE_LENGTH
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_LCD_WRITE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL_SWFLAG
value|0x00000020
end_define

begin_comment
comment|/* PBA constants */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_8K
value|0x0008
end_define

begin_comment
comment|/* 8KB, default Rx allocation */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_12K
value|0x000C
end_define

begin_comment
comment|/* 12KB, default Rx allocation */
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
name|E1000_PBA_22K
value|0x0016
end_define

begin_define
define|#
directive|define
name|E1000_PBA_24K
value|0x0018
end_define

begin_define
define|#
directive|define
name|E1000_PBA_30K
value|0x001E
end_define

begin_define
define|#
directive|define
name|E1000_PBA_32K
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_PBA_34K
value|0x0022
end_define

begin_define
define|#
directive|define
name|E1000_PBA_38K
value|0x0026
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

begin_define
define|#
directive|define
name|E1000_PBS_16K
value|E1000_PBA_16K
end_define

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
comment|/* PCIX Config space */
end_comment

begin_define
define|#
directive|define
name|PCIX_COMMAND_REGISTER
value|0xE6
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_REGISTER_LO
value|0xE8
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_REGISTER_HI
value|0xEA
end_define

begin_define
define|#
directive|define
name|PCIX_COMMAND_MMRBC_MASK
value|0x000C
end_define

begin_define
define|#
directive|define
name|PCIX_COMMAND_MMRBC_SHIFT
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_SHIFT
value|0x5
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_4K
value|0x3
end_define

begin_define
define|#
directive|define
name|PCIX_STATUS_HI_MMRBC_2K
value|0x2
end_define

begin_comment
comment|/* Number of bits required to shift right the "pause" bits from the  * EEPROM (bits 13:12) to the "pause" (bits 8:7) field in the TXCW register.  */
end_comment

begin_define
define|#
directive|define
name|PAUSE_SHIFT
value|5
end_define

begin_comment
comment|/* Number of bits required to shift left the "SWDPIO" bits from the  * EEPROM (bits 8:5) to the "SWDPIO" (bits 25:22) field in the CTRL register.  */
end_comment

begin_define
define|#
directive|define
name|SWDPIO_SHIFT
value|17
end_define

begin_comment
comment|/* Number of bits required to shift left the "SWDPIO_EXT" bits from the  * EEPROM word F (bits 7:4) to the bits 11:8 of The Extended CTRL register.  */
end_comment

begin_define
define|#
directive|define
name|SWDPIO__EXT_SHIFT
value|4
end_define

begin_comment
comment|/* Number of bits required to shift left the "ILOS" bit from the EEPROM  * (bit 4) to the "ILOS" (bit 7) field in the CTRL register.  */
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
comment|/* Number of milliseconds we wait for auto-negotiation to complete */
end_comment

begin_define
define|#
directive|define
name|LINK_UP_TIMEOUT
value|500
end_define

begin_comment
comment|/* Number of 100 microseconds we wait for PCI Express master disable */
end_comment

begin_define
define|#
directive|define
name|MASTER_DISABLE_TIMEOUT
value|800
end_define

begin_comment
comment|/* Number of milliseconds we wait for Eeprom auto read bit done after MAC reset */
end_comment

begin_define
define|#
directive|define
name|AUTO_READ_DONE_TIMEOUT
value|10
end_define

begin_comment
comment|/* Number of milliseconds we wait for PHY configuration done after MAC reset */
end_comment

begin_define
define|#
directive|define
name|PHY_CFG_TIMEOUT
value|100
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
comment|/* TBI_ACCEPT macro definition:  *  * This macro requires:  *      adapter = a pointer to struct em_hw  *      status = the 8 bit status field of the RX descriptor with EOP set  *      error = the 8 bit error field of the RX descriptor with EOP set  *      length = the sum of all the length fields of the RX descriptors that  *               make up the current frame  *      last_byte = the last byte of the frame DMAed by the hardware  *      max_frame_length = the maximum frame length we want to accept.  *      min_frame_length = the minimum frame length we want to accept.  *  * This macro is a conditional that should be used in the interrupt  * handler's Rx processing routine when RxErrors have been detected.  *  * Typical use:  *  ...  *  if (TBI_ACCEPT) {  *      accept_frame = TRUE;  *      em_tbi_adjust_stats(adapter, MacAddress);  *      frame_length--;  *  } else {  *      accept_frame = FALSE;  *  }  *  ...  */
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

begin_comment
comment|/* Structures, enums, and macros for the PHY */
end_comment

begin_comment
comment|/* Bit definitions for the Management Data IO (MDIO) and Management Data  * Clock (MDC) pins in the Device Control Register.  */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR
value|E1000_CTRL_SWDPIO0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET
value|E1000_CTRL_SWDPIN0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO_DIR
value|E1000_CTRL_SWDPIO2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO
value|E1000_CTRL_SWDPIN2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC_DIR
value|E1000_CTRL_SWDPIO3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC
value|E1000_CTRL_SWDPIN3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR4
value|E1000_CTRL_EXT_SDP4_DIR
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET4
value|E1000_CTRL_EXT_SDP4_DATA
end_define

begin_comment
comment|/* PHY 1000 MII Register/Bit Definitions */
end_comment

begin_comment
comment|/* PHY Registers defined by IEEE */
end_comment

begin_define
define|#
directive|define
name|PHY_CTRL
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_STATUS
value|0x01
end_define

begin_comment
comment|/* Status Regiser */
end_comment

begin_define
define|#
directive|define
name|PHY_ID1
value|0x02
end_define

begin_comment
comment|/* Phy Id Reg (word 1) */
end_comment

begin_define
define|#
directive|define
name|PHY_ID2
value|0x03
end_define

begin_comment
comment|/* Phy Id Reg (word 2) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_ADV
value|0x04
end_define

begin_comment
comment|/* Autoneg Advertisement */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_ABILITY
value|0x05
end_define

begin_comment
comment|/* Link Partner Ability (Base Page) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_EXP
value|0x06
end_define

begin_comment
comment|/* Autoneg Expansion Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_NEXT_PAGE_TX
value|0x07
end_define

begin_comment
comment|/* Next Page TX */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_NEXT_PAGE
value|0x08
end_define

begin_comment
comment|/* Link Partner Next Page */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_CTRL
value|0x09
end_define

begin_comment
comment|/* 1000Base-T Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_STATUS
value|0x0A
end_define

begin_comment
comment|/* 1000Base-T Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_EXT_STATUS
value|0x0F
end_define

begin_comment
comment|/* Extended Status Reg */
end_comment

begin_define
define|#
directive|define
name|MAX_PHY_REG_ADDRESS
value|0x1F
end_define

begin_comment
comment|/* 5 bit address bus (0-0x1F) */
end_comment

begin_define
define|#
directive|define
name|MAX_PHY_MULTI_PAGE_REG
value|0xF
end_define

begin_comment
comment|/* Registers equal on all pages */
end_comment

begin_comment
comment|/* M88E1000 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_CTRL
value|0x10
end_define

begin_comment
comment|/* PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_STATUS
value|0x11
end_define

begin_comment
comment|/* PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_ENABLE
value|0x12
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_STATUS
value|0x13
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EXT_PHY_SPEC_CTRL
value|0x14
end_define

begin_comment
comment|/* Extended PHY Specific Control */
end_comment

begin_define
define|#
directive|define
name|M88E1000_RX_ERR_CNTR
value|0x15
end_define

begin_comment
comment|/* Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_EXT_CTRL
value|0x1A
end_define

begin_comment
comment|/* PHY extend control register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_PAGE_SELECT
value|0x1D
end_define

begin_comment
comment|/* Reg 29 for page number setting */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_GEN_CONTROL
value|0x1E
end_define

begin_comment
comment|/* Its meaning depends on reg 29 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_VCO_REG_BIT8
value|0x100
end_define

begin_comment
comment|/* Bits 8& 11 are adjusted for */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_VCO_REG_BIT11
value|0x800
end_define

begin_comment
comment|/* improved BER performance */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_IEEE_REGS_PAGE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_IEEE_RESTART_AUTONEG
value|0x3300
end_define

begin_define
define|#
directive|define
name|IGP01E1000_IEEE_FORCE_GIGA
value|0x0140
end_define

begin_comment
comment|/* IGP01E1000 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_CONFIG
value|0x10
end_define

begin_comment
comment|/* PHY Specific Port Config Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_STATUS
value|0x11
end_define

begin_comment
comment|/* PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_CTRL
value|0x12
end_define

begin_comment
comment|/* PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_LINK_HEALTH
value|0x13
end_define

begin_comment
comment|/* PHY Link Health Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_FIFO
value|0x14
end_define

begin_comment
comment|/* GMII FIFO Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_CHANNEL_QUALITY
value|0x15
end_define

begin_comment
comment|/* PHY Channel Quality Register */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PHY_POWER_MGMT
value|0x19
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PAGE_SELECT
value|0x1F
end_define

begin_comment
comment|/* PHY Page Select Core Register */
end_comment

begin_comment
comment|/* IGP01E1000 AGC Registers - stores the cable length values*/
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_A
value|0x1172
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_B
value|0x1272
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_C
value|0x1472
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_D
value|0x1872
end_define

begin_comment
comment|/* IGP02E1000 AGC Registers for cable length values */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_A
value|0x11B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_B
value|0x12B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_C
value|0x14B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_D
value|0x18B1
end_define

begin_comment
comment|/* IGP01E1000 DSP Reset Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_RESET
value|0x1F33
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_SET
value|0x1F71
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE
value|0x1F35
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_CHANNEL_NUM
value|4
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_CHANNEL_NUM
value|4
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_A
value|0x1171
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_B
value|0x1271
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_C
value|0x1471
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_D
value|0x1871
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_EDAC_MU_INDEX
value|0xC000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_EDAC_SIGN_EXT_9_BITS
value|0x8000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_ANALOG_TX_STATE
value|0x2890
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_ANALOG_CLASS_A
value|0x2000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_FORCE_ANALOG_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE_CM_CP
value|0x0069
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE_DEFAULT
value|0x002A
end_define

begin_comment
comment|/* IGP01E1000 PCS Initialization register - stores the polarity status when  * speed = 1000 Mbps. */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PCS_INIT_REG
value|0x00B4
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PCS_CTRL_REG
value|0x00B5
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_REGS_PAGE
value|0x20C0
end_define

begin_comment
comment|/* Bits...  * 15-5: page  * 4-0: register offset  */
end_comment

begin_define
define|#
directive|define
name|GG82563_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|GG82563_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((page)<< GG82563_PAGE_SHIFT) | ((reg)& MAX_PHY_REG_ADDRESS))
end_define

begin_define
define|#
directive|define
name|GG82563_MIN_ALT_REG
value|30
end_define

begin_comment
comment|/* GG82563 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_CTRL
define|\
value|GG82563_REG(0, 16)
end_define

begin_comment
comment|/* PHY Specific Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_STATUS
define|\
value|GG82563_REG(0, 17)
end_define

begin_comment
comment|/* PHY Specific Status */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_INT_ENABLE
define|\
value|GG82563_REG(0, 18)
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_STATUS_2
define|\
value|GG82563_REG(0, 19)
end_define

begin_comment
comment|/* PHY Specific Status 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_RX_ERR_CNTR
define|\
value|GG82563_REG(0, 21)
end_define

begin_comment
comment|/* Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT
define|\
value|GG82563_REG(0, 22)
end_define

begin_comment
comment|/* Page Select */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_SPEC_CTRL_2
define|\
value|GG82563_REG(0, 26)
end_define

begin_comment
comment|/* PHY Specific Control 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PAGE_SELECT_ALT
define|\
value|GG82563_REG(0, 29)
end_define

begin_comment
comment|/* Alternate Page Select */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_TEST_CLK_CTRL
define|\
value|GG82563_REG(0, 30)
end_define

begin_comment
comment|/* Test Clock Control (use reg. 29 to select) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_MAC_SPEC_CTRL
define|\
value|GG82563_REG(2, 21)
end_define

begin_comment
comment|/* MAC Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_MAC_SPEC_CTRL_2
define|\
value|GG82563_REG(2, 26)
end_define

begin_comment
comment|/* MAC Specific Control 2 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_DSP_DISTANCE
define|\
value|GG82563_REG(5, 26)
end_define

begin_comment
comment|/* DSP Distance */
end_comment

begin_comment
comment|/* Page 193 - Port Control Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_MODE_CTRL
define|\
value|GG82563_REG(193, 16)
end_define

begin_comment
comment|/* Kumeran Mode Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PORT_RESET
define|\
value|GG82563_REG(193, 17)
end_define

begin_comment
comment|/* Port Reset */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_REVISION_ID
define|\
value|GG82563_REG(193, 18)
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_DEVICE_ID
define|\
value|GG82563_REG(193, 19)
end_define

begin_comment
comment|/* Device ID */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_PWR_MGMT_CTRL
define|\
value|GG82563_REG(193, 20)
end_define

begin_comment
comment|/* Power Management Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_RATE_ADAPT_CTRL
define|\
value|GG82563_REG(193, 25)
end_define

begin_comment
comment|/* Rate Adaptation Control */
end_comment

begin_comment
comment|/* Page 194 - KMRN Registers */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_FIFO_CTRL_STAT
define|\
value|GG82563_REG(194, 16)
end_define

begin_comment
comment|/* FIFO's Control/Status */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_CTRL
define|\
value|GG82563_REG(194, 17)
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_INBAND_CTRL
define|\
value|GG82563_REG(194, 18)
end_define

begin_comment
comment|/* Inband Control */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_DIAGNOSTIC
define|\
value|GG82563_REG(194, 19)
end_define

begin_comment
comment|/* Diagnostic */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ACK_TIMEOUTS
define|\
value|GG82563_REG(194, 20)
end_define

begin_comment
comment|/* Acknowledge Timeouts */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ADV_ABILITY
define|\
value|GG82563_REG(194, 21)
end_define

begin_comment
comment|/* Advertised Ability */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_LINK_PARTNER_ADV_ABILITY
define|\
value|GG82563_REG(194, 23)
end_define

begin_comment
comment|/* Link Partner Advertised Ability */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_ADV_NEXT_PAGE
define|\
value|GG82563_REG(194, 24)
end_define

begin_comment
comment|/* Advertised Next Page */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_LINK_PARTNER_ADV_NEXT_PAGE
define|\
value|GG82563_REG(194, 25)
end_define

begin_comment
comment|/* Link Partner Advertised Next page */
end_comment

begin_define
define|#
directive|define
name|GG82563_PHY_KMRN_MISC
define|\
value|GG82563_REG(194, 26)
end_define

begin_comment
comment|/* Misc. */
end_comment

begin_comment
comment|/* PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_MSB
value|0x0040
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_COLL_TEST_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_FULL_DUPLEX
value|0x0100
end_define

begin_comment
comment|/* FDX =1, half duplex =0 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESTART_AUTO_NEG
value|0x0200
end_define

begin_comment
comment|/* Restart auto negotiation */
end_comment

begin_define
define|#
directive|define
name|MII_CR_ISOLATE
value|0x0400
end_define

begin_comment
comment|/* Isolate PHY from MII */
end_comment

begin_define
define|#
directive|define
name|MII_CR_POWER_DOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|MII_CR_AUTO_NEG_EN
value|0x1000
end_define

begin_comment
comment|/* Auto Neg Enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_LSB
value|0x2000
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 0 = normal, 1 = loopback */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESET
value|0x8000
end_define

begin_comment
comment|/* 0 = normal, 1 = PHY reset */
end_comment

begin_comment
comment|/* PHY Status Register */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_CAPS
value|0x0001
end_define

begin_comment
comment|/* Extended register capabilities */
end_comment

begin_define
define|#
directive|define
name|MII_SR_JABBER_DETECT
value|0x0002
end_define

begin_comment
comment|/* Jabber Detected */
end_comment

begin_define
define|#
directive|define
name|MII_SR_LINK_STATUS
value|0x0004
end_define

begin_comment
comment|/* Link Status 1 = link */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_CAPS
value|0x0008
end_define

begin_comment
comment|/* Auto Neg Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_REMOTE_FAULT
value|0x0010
end_define

begin_comment
comment|/* Remote Fault Detect */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_COMPLETE
value|0x0020
end_define

begin_comment
comment|/* Auto Neg Complete */
end_comment

begin_define
define|#
directive|define
name|MII_SR_PREAMBLE_SUPPRESS
value|0x0040
end_define

begin_comment
comment|/* Preamble may be suppressed */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_STATUS
value|0x0100
end_define

begin_comment
comment|/* Ext. status info in Reg 0x0F */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_HD_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T2 Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_FD_CAPS
value|0x0400
end_define

begin_comment
comment|/* 100T2 Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_HD_CAPS
value|0x0800
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_FD_CAPS
value|0x1000
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_HD_CAPS
value|0x2000
end_define

begin_comment
comment|/* 100X  Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_FD_CAPS
value|0x4000
end_define

begin_comment
comment|/* 100X  Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T4_CAPS
value|0x8000
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_comment
comment|/* Autoneg Advertisement Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_SELECTOR_FIELD
value|0x0001
end_define

begin_comment
comment|/* indicates IEEE 802.3 CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* Remote Fault detected */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Link Partner Ability Register (Base Page) */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_SELECTOR_FIELD
value|0x0000
end_define

begin_comment
comment|/* LP protocol selector field */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* LP is 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* LP Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* LP Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* LP has detected Remote Fault */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_comment
comment|/* LP has rx'd link code word */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Autoneg Expansion Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NWAY_CAPS
value|0x0001
end_define

begin_comment
comment|/* LP has Auto Neg Capability */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAGE_RXD
value|0x0002
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_NEXT_PAGE_CAPS
value|0x0004
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NEXT_PAGE_CAPS
value|0x0008
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAR_DETECT_FAULT
value|0x0010
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_comment
comment|/* Next Page TX Register */
end_comment

begin_define
define|#
directive|define
name|NPTX_MSG_CODE_FIELD
value|0x0001
end_define

begin_comment
comment|/* NP msg code or unformatted data */
end_comment

begin_define
define|#
directive|define
name|NPTX_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggles between exchanges                                     * of different NP                                     */
end_comment

begin_define
define|#
directive|define
name|NPTX_ACKNOWLDGE2
value|0x1000
end_define

begin_comment
comment|/* 1 = will comply with msg                                     * 0 = cannot comply with msg                                     */
end_comment

begin_define
define|#
directive|define
name|NPTX_MSG_PAGE
value|0x2000
end_define

begin_comment
comment|/* formatted(1)/unformatted(0) pg */
end_comment

begin_define
define|#
directive|define
name|NPTX_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* 1 = addition NP will follow                                     * 0 = sending last NP                                     */
end_comment

begin_comment
comment|/* Link Partner Next Page Register */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_MSG_CODE_FIELD
value|0x0001
end_define

begin_comment
comment|/* NP msg code or unformatted data */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggles between exchanges                                        * of different NP                                        */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE2
value|0x1000
end_define

begin_comment
comment|/* 1 = will comply with msg                                        * 0 = cannot comply with msg                                        */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_MSG_PAGE
value|0x2000
end_define

begin_comment
comment|/* formatted(1)/unformatted(0) pg */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE
value|0x4000
end_define

begin_comment
comment|/* 1 = ACK / 0 = NO ACK */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* 1 = addition NP will follow                                         * 0 = sending last NP                                         */
end_comment

begin_comment
comment|/* 1000BASE-T Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_ASYM_PAUSE
value|0x0080
end_define

begin_comment
comment|/* Advertise asymmetric pause bit */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_HD_CAPS
value|0x0100
end_define

begin_comment
comment|/* Advertise 1000T HD capability */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_FD_CAPS
value|0x0200
end_define

begin_comment
comment|/* Advertise 1000T FD capability  */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_REPEATER_DTE
value|0x0400
end_define

begin_comment
comment|/* 1=Repeater/switch device port */
end_comment

begin_comment
comment|/* 0=DTE device */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_VALUE
value|0x0800
end_define

begin_comment
comment|/* 1=Configure PHY as Master */
end_comment

begin_comment
comment|/* 0=Configure PHY as Slave */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_ENABLE
value|0x1000
end_define

begin_comment
comment|/* 1=Master/Slave manual config value */
end_comment

begin_comment
comment|/* 0=Automatic Master/Slave config */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_NORMAL
value|0x0000
end_define

begin_comment
comment|/* Normal Operation */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_1
value|0x2000
end_define

begin_comment
comment|/* Transmit Waveform test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_2
value|0x4000
end_define

begin_comment
comment|/* Master Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_3
value|0x6000
end_define

begin_comment
comment|/* Slave Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_4
value|0x8000
end_define

begin_comment
comment|/* Transmitter Distortion test */
end_comment

begin_comment
comment|/* 1000BASE-T Status Register */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_IDLE_ERROR_CNT
value|0x00FF
end_define

begin_comment
comment|/* Num idle errors since last read */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_comment
comment|/* LP asymmetric pause direction bit */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_HD_CAPS
value|0x0400
end_define

begin_comment
comment|/* LP is 1000T HD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_FD_CAPS
value|0x0800
end_define

begin_comment
comment|/* LP is 1000T FD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS
value|0x2000
end_define

begin_comment
comment|/* Local receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_RES
value|0x4000
end_define

begin_comment
comment|/* 1=Local TX is Master, 0=Slave */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_FAULT
value|0x8000
end_define

begin_comment
comment|/* Master/Slave config fault */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|SR_1000T_PHY_EXCESSIVE_IDLE_ERR_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|FFE_IDLE_ERR_COUNT_TIMEOUT_20
value|20
end_define

begin_define
define|#
directive|define
name|FFE_IDLE_ERR_COUNT_TIMEOUT_100
value|100
end_define

begin_comment
comment|/* Extended Status Register */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_HD_CAPS
value|0x1000
end_define

begin_comment
comment|/* 1000T HD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_FD_CAPS
value|0x2000
end_define

begin_comment
comment|/* 1000T FD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_HD_CAPS
value|0x4000
end_define

begin_comment
comment|/* 1000X HD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_FD_CAPS
value|0x8000
end_define

begin_comment
comment|/* 1000X FD capable */
end_comment

begin_define
define|#
directive|define
name|PHY_TX_POLARITY_MASK
value|0x0100
end_define

begin_comment
comment|/* register 10h bit 8 (polarity bit) */
end_comment

begin_define
define|#
directive|define
name|PHY_TX_NORMAL_POLARITY
value|0
end_define

begin_comment
comment|/* register 10h bit 8 (normal polarity) */
end_comment

begin_define
define|#
directive|define
name|AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_comment
comment|/* register 11h bit 4 */
end_comment

begin_comment
comment|/* (0=enable, 1=disable) */
end_comment

begin_comment
comment|/* M88E1000 PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_JABBER_DISABLE
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber Function disabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reversal enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SQE_TEST
value|0x0004
end_define

begin_comment
comment|/* 1=SQE Test enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_CLK125_DISABLE
value|0x0010
end_define

begin_comment
comment|/* 1=CLK125 low,                                                 * 0=CLK125 toggling                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_comment
comment|/* MDI Crossover Mode bits 6:5 */
end_comment

begin_comment
comment|/* Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_comment
comment|/* Manual MDIX configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_1000T
value|0x0040
end_define

begin_comment
comment|/* 1000BASE-T: Auto crossover,                                                 *  100BASE-TX/10BASE-T:                                                 *  MDI Mode                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE
value|0x0060
end_define

begin_comment
comment|/* Auto crossover enabled                                                 * all speeds.                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_10BT_EXT_DIST_ENABLE
value|0x0080
end_define

begin_comment
comment|/* 1=Enable Extended 10BASE-T distance                                          * (Lower 10BASE-T RX Threshold)                                          * 0=Normal 10BASE-T RX Threshold */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_comment
comment|/* 1=5-Bit interface in 100BASE-TX                                          * 0=MII interface in 100BASE-TX */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_comment
comment|/* 1=Scrambler disable */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_comment
comment|/* 1=Force link good */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_comment
comment|/* 1=Assert CRS on Transmit */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_POLARITY_REVERSAL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_10BT_EXT_DIST_ENABLE_SHIFT
value|7
end_define

begin_comment
comment|/* M88E1000 PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_REV_POLARITY
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity reversed */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_DOWNSHIFT
value|0x0020
end_define

begin_comment
comment|/* 1=Downshifted */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_MDIX
value|0x0040
end_define

begin_comment
comment|/* 1=MDIX; 0=MDI */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH
value|0x0380
end_define

begin_comment
comment|/* 0=<50M;1=50-80M;2=80-110M;                                             * 3=110-140M;4=>140M */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_LINK
value|0x0400
end_define

begin_comment
comment|/* 1=Link up, 0=Link down */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_comment
comment|/* 1=Speed& Duplex resolved */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_PAGE_RCVD
value|0x1000
end_define

begin_comment
comment|/* 1=Page received */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_DPLX
value|0x2000
end_define

begin_comment
comment|/* 1=Duplex 0=Half Duplex */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPEED
value|0xC000
end_define

begin_comment
comment|/* Speed, bits 14:15 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_10MBS
value|0x0000
end_define

begin_comment
comment|/* 00=10Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_100MBS
value|0x4000
end_define

begin_comment
comment|/* 01=100Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_1000MBS
value|0x8000
end_define

begin_comment
comment|/* 10=1000Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_REV_POLARITY_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|M88E1000_PSSR_DOWNSHIFT_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|M88E1000_PSSR_MDIX_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH_SHIFT
value|7
end_define

begin_comment
comment|/* M88E1000 Extended PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_FIBER_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 1=Fiber loopback */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_DOWN_NO_IDLE
value|0x8000
end_define

begin_comment
comment|/* 1=Lost lock detect enabled.                                               * Will assert lost lock and bring                                               * link down if idle not seen                                               * within 1ms in 1000BASE-T                                               */
end_comment

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the master */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_MASK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_1X
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_2X
value|0x0400
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_3X
value|0x0800
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_MASTER_DOWNSHIFT_4X
value|0x0C00
end_define

begin_comment
comment|/* Number of times we will attempt to autonegotiate before downshifting if we  * are the slave */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_DIS
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_1X
value|0x0100
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_2X
value|0x0200
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_SLAVE_DOWNSHIFT_3X
value|0x0300
end_define

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_2_5
value|0x0060
end_define

begin_comment
comment|/* 2.5 MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_25
value|0x0070
end_define

begin_comment
comment|/* 25  MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_0
value|0x0000
end_define

begin_comment
comment|/* NO  TX_CLK */
end_comment

begin_comment
comment|/* M88EC018 Rev 2 specific DownShift settings */
end_comment

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_MASK
value|0x0E00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_1X
value|0x0000
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_2X
value|0x0200
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_3X
value|0x0400
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_4X
value|0x0600
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_5X
value|0x0800
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_6X
value|0x0A00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_7X
value|0x0C00
end_define

begin_define
define|#
directive|define
name|M88EC018_EPSCR_DOWNSHIFT_COUNTER_8X
value|0x0E00
end_define

begin_comment
comment|/* IGP01E1000 Specific Port Config Register - R/W */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_AUTO_MDIX_PAR_DETECT
value|0x0010
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_PRE_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_SMART_SPEED
value|0x0080
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_DISABLE_TPLOOPBACK
value|0x0100
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_DISABLE_JABBER
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_DISABLE_TRANSMIT
value|0x2000
end_define

begin_comment
comment|/* IGP01E1000 Specific Port Status Register - R/O */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_AUTONEG_FAILED
value|0x0001
end_define

begin_comment
comment|/* RO LH SC */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_POLARITY_REVERSED
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_CABLE_LENGTH
value|0x007C
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_FULL_DUPLEX
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_LINK_UP
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_MDIX
value|0x0800
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_MASK
value|0xC000
end_define

begin_comment
comment|/* speed bits mask */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_10MBPS
value|0x4000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_100MBPS
value|0x8000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_1000MBPS
value|0xC000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_CABLE_LENGTH_SHIFT
value|0x0002
end_define

begin_comment
comment|/* shift right 2 */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_MDIX_SHIFT
value|0x000B
end_define

begin_comment
comment|/* shift right 11 */
end_comment

begin_comment
comment|/* IGP01E1000 Specific Port Control Register - R/W */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_TP_LOOPBACK
value|0x0010
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_CORRECT_NC_SCMBLR
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_TEN_CRS_SELECT
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_FLIP_CHIP
value|0x0800
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_AUTO_MDIX
value|0x1000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_FORCE_MDI_MDIX
value|0x2000
end_define

begin_comment
comment|/* 0-MDI, 1-MDIX */
end_comment

begin_comment
comment|/* IGP01E1000 Specific Port Link Health Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_SS_DOWNGRADE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_GIG_SCRAMBLER_ERROR
value|0x4000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_MASTER_FAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_MASTER_RESOLUTION
value|0x1000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_GIG_REM_RCVR_NOK
value|0x0800
end_define

begin_comment
comment|/* LH */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_IDLE_ERROR_CNT_OFLOW
value|0x0400
end_define

begin_comment
comment|/* LH */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_DATA_ERR_1
value|0x0200
end_define

begin_comment
comment|/* LH */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_DATA_ERR_0
value|0x0100
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_AUTONEG_FAULT
value|0x0040
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_AUTONEG_ACTIVE
value|0x0010
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_VALID_CHANNEL_D
value|0x0008
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_VALID_CHANNEL_C
value|0x0004
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_VALID_CHANNEL_B
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_VALID_CHANNEL_A
value|0x0001
end_define

begin_comment
comment|/* IGP01E1000 Channel Quality Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_D
value|0x000F
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_C
value|0x00F0
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_B
value|0x0F00
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_A
value|0xF000
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PM_SPD
value|0x0001
end_define

begin_comment
comment|/* Smart Power Down */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PM_D3_LPLU
value|0x0004
end_define

begin_comment
comment|/* Enable LPLU in non-D0a modes */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PM_D0_LPLU
value|0x0002
end_define

begin_comment
comment|/* Enable LPLU in D0a mode */
end_comment

begin_comment
comment|/* IGP01E1000 DSP reset macros */
end_comment

begin_define
define|#
directive|define
name|DSP_RESET_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|DSP_RESET_DISABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_MAX_DSP_RESETS
value|10
end_define

begin_comment
comment|/* IGP01E1000& IGP02E1000 AGC Registers */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_AGC_LENGTH_SHIFT
value|7
end_define

begin_comment
comment|/* Coarse - 13:11, Fine - 10:7 */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_AGC_LENGTH_SHIFT
value|9
end_define

begin_comment
comment|/* Coarse - 15:13, Fine - 12:9 */
end_comment

begin_comment
comment|/* IGP02E1000 AGC Register Length 9-bit mask */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_AGC_LENGTH_MASK
value|0x7F
end_define

begin_comment
comment|/* 7 bits (3 Coarse + 4 Fine) --> 128 optional values */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_AGC_LENGTH_TABLE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|IGP02E1000_AGC_LENGTH_TABLE_SIZE
value|113
end_define

begin_comment
comment|/* The precision error of the cable length is +/- 10 meters */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_AGC_RANGE
value|10
end_define

begin_define
define|#
directive|define
name|IGP02E1000_AGC_RANGE
value|15
end_define

begin_comment
comment|/* IGP01E1000 PCS Initialization register */
end_comment

begin_comment
comment|/* bits 3:6 in the PCS registers stores the channels polarity */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_POLARITY_MASK
value|0x0078
end_define

begin_comment
comment|/* IGP01E1000 GMII FIFO Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_FLEX_SPD
value|0x10
end_define

begin_comment
comment|/* Enable flexible speed                                                      * on Link-Up */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_SPD
value|0x20
end_define

begin_comment
comment|/* Enable SPD */
end_comment

begin_comment
comment|/* IGP01E1000 Analog Register */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_SPARE_FUSE_STATUS
value|0x20D1
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_STATUS
value|0x20D0
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_CONTROL
value|0x20DC
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_BYPASS
value|0x20DE
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_POLY_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_MASK
value|0x0F80
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_SPARE_FUSE_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_ENABLE_SW_CONTROL
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_THRESH
value|0x0040
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_10
value|0x0010
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_1
value|0x0080
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_10
value|0x0500
end_define

begin_comment
comment|/* GG82563 PHY Specific Status Register (Page 0, Register 16 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_DISABLE_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Disable Jabber */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_POLARITY_REVERSAL_DISABLE
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reversal Disabled */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_POWER_DOWN
value|0x0004
end_define

begin_comment
comment|/* 1=Power Down */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_COPPER_TRANSMITER_DISABLE
value|0x0008
end_define

begin_comment
comment|/* 1=Transmitter Disabled */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_MDI
value|0x0000
end_define

begin_comment
comment|/* 00=Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_MDIX
value|0x0020
end_define

begin_comment
comment|/* 01=Manual MDIX configuration */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_AUTO
value|0x0060
end_define

begin_comment
comment|/* 11=Automatic crossover */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_ENALBE_EXTENDED_DISTANCE
value|0x0080
end_define

begin_comment
comment|/* 1=Enable Extended Distance */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_ENERGY_DETECT_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|GG82563_PSCR_ENERGY_DETECT_OFF
value|0x0000
end_define

begin_comment
comment|/* 00,01=Off */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_ENERGY_DETECT_RX
value|0x0200
end_define

begin_comment
comment|/* 10=Sense on Rx only (Energy Detect) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_ENERGY_DETECT_RX_TM
value|0x0300
end_define

begin_comment
comment|/* 11=Sense and Tx NLP */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_comment
comment|/* 1=Force Link Good */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_DOWNSHIFT_ENABLE
value|0x0800
end_define

begin_comment
comment|/* 1=Enable Downshift */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_DOWNSHIFT_COUNTER_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|GG82563_PSCR_DOWNSHIFT_COUNTER_SHIFT
value|12
end_define

begin_comment
comment|/* PHY Specific Status Register (Page 0, Register 17) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_POLARITY
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reversed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_LINK
value|0x0008
end_define

begin_comment
comment|/* 1=Link is Up */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_ENERGY_DETECT
value|0x0010
end_define

begin_comment
comment|/* 1=Sleep, 0=Active */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_DOWNSHIFT
value|0x0020
end_define

begin_comment
comment|/* 1=Downshift */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_CROSSOVER_STATUS
value|0x0040
end_define

begin_comment
comment|/* 1=MDIX, 0=MDI */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_RX_PAUSE_ENABLED
value|0x0100
end_define

begin_comment
comment|/* 1=Receive Pause Enabled */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_TX_PAUSE_ENABLED
value|0x0200
end_define

begin_comment
comment|/* 1=Transmit Pause Enabled */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_LINK_UP
value|0x0400
end_define

begin_comment
comment|/* 1=Link Up */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_SPEED_DUPLEX_RESOLVED
value|0x0800
end_define

begin_comment
comment|/* 1=Resolved */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_PAGE_RECEIVED
value|0x1000
end_define

begin_comment
comment|/* 1=Page Received */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_DUPLEX
value|0x2000
end_define

begin_comment
comment|/* 1-Full-Duplex */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_SPEED_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|GG82563_PSSR_SPEED_10MBPS
value|0x0000
end_define

begin_comment
comment|/* 00=10Mbps */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_SPEED_100MBPS
value|0x4000
end_define

begin_comment
comment|/* 01=100Mbps */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR_SPEED_1000MBPS
value|0x8000
end_define

begin_comment
comment|/* 10=1000Mbps */
end_comment

begin_comment
comment|/* PHY Specific Status Register 2 (Page 0, Register 19) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_POLARITY_CHANGED
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_ENERGY_DETECT_CHANGED
value|0x0010
end_define

begin_comment
comment|/* 1=Energy Detect Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_DOWNSHIFT_INTERRUPT
value|0x0020
end_define

begin_comment
comment|/* 1=Downshift Detected */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_MDI_CROSSOVER_CHANGE
value|0x0040
end_define

begin_comment
comment|/* 1=Crossover Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_FALSE_CARRIER
value|0x0100
end_define

begin_comment
comment|/* 1=False Carrier */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_SYMBOL_ERROR
value|0x0200
end_define

begin_comment
comment|/* 1=Symbol Error */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_LINK_STATUS_CHANGED
value|0x0400
end_define

begin_comment
comment|/* 1=Link Status Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_AUTO_NEG_COMPLETED
value|0x0800
end_define

begin_comment
comment|/* 1=Auto-Neg Completed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_PAGE_RECEIVED
value|0x1000
end_define

begin_comment
comment|/* 1=Page Received */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_DUPLEX_CHANGED
value|0x2000
end_define

begin_comment
comment|/* 1=Duplex Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_SPEED_CHANGED
value|0x4000
end_define

begin_comment
comment|/* 1=Speed Changed */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSSR2_AUTO_NEG_ERROR
value|0x8000
end_define

begin_comment
comment|/* 1=Auto-Neg Error */
end_comment

begin_comment
comment|/* PHY Specific Control Register 2 (Page 0, Register 26) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_10BT_POLARITY_FORCE
value|0x0002
end_define

begin_comment
comment|/* 1=Force Negative Polarity */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_1000MB_TEST_SELECT_MASK
value|0x000C
end_define

begin_define
define|#
directive|define
name|GG82563_PSCR2_1000MB_TEST_SELECT_NORMAL
value|0x0000
end_define

begin_comment
comment|/* 00,01=Normal Operation */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_1000MB_TEST_SELECT_112NS
value|0x0008
end_define

begin_comment
comment|/* 10=Select 112ns Sequence */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_1000MB_TEST_SELECT_16NS
value|0x000C
end_define

begin_comment
comment|/* 11=Select 16ns Sequence */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_REVERSE_AUTO_NEG
value|0x2000
end_define

begin_comment
comment|/* 1=Reverse Auto-Negotiation */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_1000BT_DISABLE
value|0x4000
end_define

begin_comment
comment|/* 1=Disable 1000BASE-T */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_TRANSMITER_TYPE_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|GG82563_PSCR2_TRANSMITTER_TYPE_CLASS_B
value|0x0000
end_define

begin_comment
comment|/* 0=Class B */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR2_TRANSMITTER_TYPE_CLASS_A
value|0x8000
end_define

begin_comment
comment|/* 1=Class A */
end_comment

begin_comment
comment|/* MAC Specific Control Register (Page 2, Register 21) */
end_comment

begin_comment
comment|/* Tx clock speed for Link Down and 1000BASE-T for the following speeds */
end_comment

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_10MBPS_2_5MHZ
value|0x0004
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_100MBPS_25MHZ
value|0x0005
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_1000MBPS_2_5MHZ
value|0x0006
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_1000MBPS_25MHZ
value|0x0007
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_ASSERT_CRS_ON_TX
value|0x0010
end_define

begin_comment
comment|/* 1=Assert */
end_comment

begin_comment
comment|/* DSP Distance Register (Page 5, Register 26) */
end_comment

begin_define
define|#
directive|define
name|GG82563_DSPD_CABLE_LENGTH
value|0x0007
end_define

begin_comment
comment|/* 0 =<50M;                                                           1 = 50-80M;                                                           2 = 80-110M;                                                           3 = 110-140M;                                                           4 =>140M */
end_comment

begin_comment
comment|/* Kumeran Mode Control Register (Page 193, Register 16) */
end_comment

begin_define
define|#
directive|define
name|GG82563_KMCR_PHY_LEDS_EN
value|0x0020
end_define

begin_comment
comment|/* 1=PHY LEDs, 0=Kumeran Inband LEDs */
end_comment

begin_define
define|#
directive|define
name|GG82563_KMCR_FORCE_LINK_UP
value|0x0040
end_define

begin_comment
comment|/* 1=Force Link Up */
end_comment

begin_define
define|#
directive|define
name|GG82563_KMCR_SUPPRESS_SGMII_EPD_EXT
value|0x0080
end_define

begin_define
define|#
directive|define
name|GG82563_KMCR_MDIO_BUS_SPEED_SELECT_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|GG82563_KMCR_MDIO_BUS_SPEED_SELECT
value|0x0400
end_define

begin_comment
comment|/* 1=6.25MHz, 0=0.8MHz */
end_comment

begin_define
define|#
directive|define
name|GG82563_KMCR_PASS_FALSE_CARRIER
value|0x0800
end_define

begin_comment
comment|/* Power Management Control Register (Page 193, Register 20) */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_ENABLE_ELECTRICAL_IDLE
value|0x0001
end_define

begin_comment
comment|/* 1=Enalbe SERDES Electrical Idle */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_DISABLE_PORT
value|0x0002
end_define

begin_comment
comment|/* 1=Disable Port */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_DISABLE_SERDES
value|0x0004
end_define

begin_comment
comment|/* 1=Disable SERDES */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_REVERSE_AUTO_NEG
value|0x0008
end_define

begin_comment
comment|/* 1=Enable Reverse Auto-Negotiation */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_DISABLE_1000_NON_D0
value|0x0010
end_define

begin_comment
comment|/* 1=Disable 1000Mbps Auto-Neg in non D0 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_DISABLE_1000
value|0x0020
end_define

begin_comment
comment|/* 1=Disable 1000Mbps Auto-Neg Always */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_REVERSE_AUTO_NEG_D0A
value|0x0040
end_define

begin_comment
comment|/* 1=Enable D0a Reverse Auto-Negotiation */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_FORCE_POWER_STATE
value|0x0080
end_define

begin_comment
comment|/* 1=Force Power State */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_PROGRAMMED_POWER_STATE_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|GG82563_PMCR_PROGRAMMED_POWER_STATE_DR
value|0x0000
end_define

begin_comment
comment|/* 00=Dr */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_PROGRAMMED_POWER_STATE_D0U
value|0x0100
end_define

begin_comment
comment|/* 01=D0u */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_PROGRAMMED_POWER_STATE_D0A
value|0x0200
end_define

begin_comment
comment|/* 10=D0a */
end_comment

begin_define
define|#
directive|define
name|GG82563_PMCR_PROGRAMMED_POWER_STATE_D3
value|0x0300
end_define

begin_comment
comment|/* 11=D3 */
end_comment

begin_comment
comment|/* In-Band Control Register (Page 194, Register 18) */
end_comment

begin_define
define|#
directive|define
name|GG82563_ICR_DIS_PADDING
value|0x0010
end_define

begin_comment
comment|/* Disable Padding Use */
end_comment

begin_comment
comment|/* Bit definitions for valid PHY IDs. */
end_comment

begin_comment
comment|/* I = Integrated  * E = External  */
end_comment

begin_define
define|#
directive|define
name|M88_VENDOR
value|0x0141
end_define

begin_define
define|#
directive|define
name|M88E1000_E_PHY_ID
value|0x01410C50
end_define

begin_define
define|#
directive|define
name|M88E1000_I_PHY_ID
value|0x01410C30
end_define

begin_define
define|#
directive|define
name|M88E1011_I_PHY_ID
value|0x01410C20
end_define

begin_define
define|#
directive|define
name|IGP01E1000_I_PHY_ID
value|0x02A80380
end_define

begin_define
define|#
directive|define
name|M88E1000_12_PHY_ID
value|M88E1000_E_PHY_ID
end_define

begin_define
define|#
directive|define
name|M88E1000_14_PHY_ID
value|M88E1000_E_PHY_ID
end_define

begin_define
define|#
directive|define
name|M88E1011_I_REV_4
value|0x04
end_define

begin_define
define|#
directive|define
name|M88E1111_I_PHY_ID
value|0x01410CC0
end_define

begin_define
define|#
directive|define
name|L1LXT971A_PHY_ID
value|0x001378E0
end_define

begin_define
define|#
directive|define
name|GG82563_E_PHY_ID
value|0x01410CA0
end_define

begin_comment
comment|/* Bits...  * 15-5: page  * 4-0: register offset  */
end_comment

begin_define
define|#
directive|define
name|PHY_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PHY_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((page)<< PHY_PAGE_SHIFT) | ((reg)& MAX_PHY_REG_ADDRESS))
end_define

begin_define
define|#
directive|define
name|IGP3_PHY_PORT_CTRL
define|\
value|PHY_REG(769, 17)
end_define

begin_comment
comment|/* Port General Configuration */
end_comment

begin_define
define|#
directive|define
name|IGP3_PHY_RATE_ADAPT_CTRL
define|\
value|PHY_REG(769, 25)
end_define

begin_comment
comment|/* Rate Adapter Control Register */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_FIFO_CTRL_STATS
define|\
value|PHY_REG(770, 16)
end_define

begin_comment
comment|/* KMRN FIFO's control/status register */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_POWER_MNG_CTRL
define|\
value|PHY_REG(770, 17)
end_define

begin_comment
comment|/* KMRN Power Management Control Register */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_INBAND_CTRL
define|\
value|PHY_REG(770, 18)
end_define

begin_comment
comment|/* KMRN Inband Control Register */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG
define|\
value|PHY_REG(770, 19)
end_define

begin_comment
comment|/* KMRN Diagnostic register */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG_PCS_LOCK_LOSS
value|0x0002
end_define

begin_comment
comment|/* RX PCS is not synced */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_ACK_TIMEOUT
define|\
value|PHY_REG(770, 20)
end_define

begin_comment
comment|/* KMRN Acknowledge Timeouts register */
end_comment

begin_define
define|#
directive|define
name|IGP3_VR_CTRL
define|\
value|PHY_REG(776, 18)
end_define

begin_comment
comment|/* Voltage regulator control register */
end_comment

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_MODE_SHUT
value|0x0200
end_define

begin_comment
comment|/* Enter powerdown, shutdown VRs */
end_comment

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_MODE_MASK
value|0x0300
end_define

begin_comment
comment|/* Shutdown VR Mask */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAPABILITY
define|\
value|PHY_REG(776, 19)
end_define

begin_comment
comment|/* IGP3 Capability Register */
end_comment

begin_comment
comment|/* Capabilities for SKU Control  */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_INITIATE_TEAM
value|0x0001
end_define

begin_comment
comment|/* Able to initiate a team */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_WFM
value|0x0002
end_define

begin_comment
comment|/* Support WoL and PXE */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_ASF
value|0x0004
end_define

begin_comment
comment|/* Support ASF */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_LPLU
value|0x0008
end_define

begin_comment
comment|/* Support Low Power Link Up */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_DC_AUTO_SPEED
value|0x0010
end_define

begin_comment
comment|/* Support AC/DC Auto Link Speed */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_SPD
value|0x0020
end_define

begin_comment
comment|/* Support Smart Power Down */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_MULT_QUEUE
value|0x0040
end_define

begin_comment
comment|/* Support 2 tx& 2 rx queues */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_RSS
value|0x0080
end_define

begin_comment
comment|/* Support RSS */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_8021PQ
value|0x0100
end_define

begin_comment
comment|/* Support 802.1Q& 802.1p */
end_comment

begin_define
define|#
directive|define
name|IGP3_CAP_AMT_CB
value|0x0200
end_define

begin_comment
comment|/* Support active manageability and circuit breaker */
end_comment

begin_define
define|#
directive|define
name|IGP3_PPC_JORDAN_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|IGP3_PPC_JORDAN_GIGA_SPEED
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_PMC_EE_IDLE_LINK_DIS
value|0x0001
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_PMC_K0S_ENTRY_LATENCY_MASK
value|0x001E
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_PMC_K0S_MODE1_EN_GIGA
value|0x0020
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_PMC_K0S_MODE1_EN_100
value|0x0040
end_define

begin_define
define|#
directive|define
name|IGP3E1000_PHY_MISC_CTRL
value|0x1B
end_define

begin_comment
comment|/* Misc. Ctrl register */
end_comment

begin_define
define|#
directive|define
name|IGP3_PHY_MISC_DUPLEX_MANUAL_SET
value|0x1000
end_define

begin_comment
comment|/* Duplex Manual Set */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_EXT_CTRL
value|PHY_REG(770, 18)
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_EC_DIS_INBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|IGP03E1000_E_PHY_ID
value|0x02A80390
end_define

begin_define
define|#
directive|define
name|IFE_E_PHY_ID
value|0x02A80330
end_define

begin_comment
comment|/* 10/100 PHY */
end_comment

begin_define
define|#
directive|define
name|IFE_PLUS_E_PHY_ID
value|0x02A80320
end_define

begin_define
define|#
directive|define
name|IFE_C_E_PHY_ID
value|0x02A80310
end_define

begin_define
define|#
directive|define
name|IFE_PHY_EXTENDED_STATUS_CONTROL
value|0x10
end_define

begin_comment
comment|/* 100BaseTx Extended Status, Control and Address */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_SPECIAL_CONTROL
value|0x11
end_define

begin_comment
comment|/* 100BaseTx PHY special control register */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_RCV_FALSE_CARRIER
value|0x13
end_define

begin_comment
comment|/* 100BaseTx Receive False Carrier Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_RCV_DISCONNECT
value|0x14
end_define

begin_comment
comment|/* 100BaseTx Receive Disconnet Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_RCV_ERROT_FRAME
value|0x15
end_define

begin_comment
comment|/* 100BaseTx Receive Error Frame Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_RCV_SYMBOL_ERR
value|0x16
end_define

begin_comment
comment|/* Receive Symbol Error Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_PREM_EOF_ERR
value|0x17
end_define

begin_comment
comment|/* 100BaseTx Receive Premature End Of Frame Error Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_RCV_EOF_ERR
value|0x18
end_define

begin_comment
comment|/* 10BaseT Receive End Of Frame Error Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_TX_JABBER_DETECT
value|0x19
end_define

begin_comment
comment|/* 10BaseT Transmit Jabber Detect Counter */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_EQUALIZER
value|0x1A
end_define

begin_comment
comment|/* PHY Equalizer Control and Status */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_SPECIAL_CONTROL_LED
value|0x1B
end_define

begin_comment
comment|/* PHY special control and LED configuration */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_MDIX_CONTROL
value|0x1C
end_define

begin_comment
comment|/* MDI/MDI-X Control register */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_HWI_CONTROL
value|0x1D
end_define

begin_comment
comment|/* Hardware Integrity Control (HWI) */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_REDUCED_POWER_DOWN_DISABLE
value|0x2000
end_define

begin_comment
comment|/* Defaut 1 = Disable auto reduced power down */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_100BTX_POWER_DOWN
value|0x0400
end_define

begin_comment
comment|/* Indicates the power state of 100BASE-TX */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_10BTX_POWER_DOWN
value|0x0200
end_define

begin_comment
comment|/* Indicates the power state of 10BASE-T */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_POLARITY_REVERSED
value|0x0100
end_define

begin_comment
comment|/* Indicates 10BASE-T polarity */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_PHY_ADDR_MASK
value|0x007C
end_define

begin_comment
comment|/* Bit 6:2 for sampled PHY address */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_SPEED
value|0x0002
end_define

begin_comment
comment|/* Auto-negotiation speed result 1=100Mbs, 0=10Mbs */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_DUPLEX
value|0x0001
end_define

begin_comment
comment|/* Auto-negotiation duplex result 1=Full, 0=Half */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_POLARITY_REVERSED_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IFE_PSC_DISABLE_DYNAMIC_POWER_DOWN
value|0x0100
end_define

begin_comment
comment|/* 1 = Dyanmic Power Down disabled */
end_comment

begin_define
define|#
directive|define
name|IFE_PSC_FORCE_POLARITY
value|0x0020
end_define

begin_comment
comment|/* 1=Reversed Polarity, 0=Normal */
end_comment

begin_define
define|#
directive|define
name|IFE_PSC_AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_comment
comment|/* 1=Auto Polarity Disabled, 0=Enabled */
end_comment

begin_define
define|#
directive|define
name|IFE_PSC_JABBER_FUNC_DISABLE
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber Disabled, 0=Normal Jabber Operation */
end_comment

begin_define
define|#
directive|define
name|IFE_PSC_FORCE_POLARITY_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IFE_PSC_AUTO_POLARITY_DISABLE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IFE_PMC_AUTO_MDIX
value|0x0080
end_define

begin_comment
comment|/* 1=enable MDI/MDI-X feature, default 0=disabled */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_FORCE_MDIX
value|0x0040
end_define

begin_comment
comment|/* 1=force MDIX-X, 0=force MDI */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_MDIX_STATUS
value|0x0020
end_define

begin_comment
comment|/* 1=MDI-X, 0=MDI */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_AUTO_MDIX_COMPLETE
value|0x0010
end_define

begin_comment
comment|/* Resolution algorthm is completed */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_MDIX_MODE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IFE_PHC_MDIX_RESET_ALL_MASK
value|0x0000
end_define

begin_comment
comment|/* Disable auto MDI-X */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_HWI_ENABLE
value|0x8000
end_define

begin_comment
comment|/* Enable the HWI feature */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_ABILITY_CHECK
value|0x4000
end_define

begin_comment
comment|/* 1= Test Passed, 0=failed */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_TEST_EXEC
value|0x2000
end_define

begin_comment
comment|/* PHY launch test pulses on the wire */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_HIGHZ
value|0x0200
end_define

begin_comment
comment|/* 1 = Open Circuit */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_LOWZ
value|0x0400
end_define

begin_comment
comment|/* 1 = Short Circuit */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_LOW_HIGH_Z_MASK
value|0x0600
end_define

begin_comment
comment|/* Mask for indication type of problem on the line */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_DISTANCE_MASK
value|0x01FF
end_define

begin_comment
comment|/* Mask for distance to the cable problem, in 80cm granularity */
end_comment

begin_define
define|#
directive|define
name|IFE_PHC_RESET_ALL_MASK
value|0x0000
end_define

begin_comment
comment|/* Disable HWI */
end_comment

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_MODE
value|0x0020
end_define

begin_comment
comment|/* LED Probe mode */
end_comment

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_LEDS_OFF
value|0x0006
end_define

begin_comment
comment|/* Force LEDs 0 and 2 off */
end_comment

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_LEDS_ON
value|0x0007
end_define

begin_comment
comment|/* Force LEDs 0 and 2 on */
end_comment

begin_define
define|#
directive|define
name|ICH_FLASH_COMMAND_TIMEOUT
value|5000
end_define

begin_comment
comment|/* 5000 uSecs - adjusted */
end_comment

begin_define
define|#
directive|define
name|ICH_FLASH_ERASE_TIMEOUT
value|3000000
end_define

begin_comment
comment|/* Up to 3 seconds - worst case */
end_comment

begin_define
define|#
directive|define
name|ICH_FLASH_CYCLE_REPEAT_COUNT
value|10
end_define

begin_comment
comment|/* 10 cycles */
end_comment

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_256
value|256
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_4K
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_64K
value|65536
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_READ
value|0x0
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_RESERVED
value|0x1
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_ERASE
value|0x3
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_GFPREG
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFSTS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFCTL
value|0x0006
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FADDR
value|0x0008
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FDATA0
value|0x0010
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FRACC
value|0x0050
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FREG0
value|0x0054
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FREG1
value|0x0058
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FREG2
value|0x005C
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FREG3
value|0x0060
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FPR0
value|0x0074
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FPR1
value|0x0078
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SSFSTS
value|0x0090
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SSFCTL
value|0x0092
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_PREOP
value|0x0094
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_OPTYPE
value|0x0096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_OPMENU
value|0x0098
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_REG_MAPSIZE
value|0x00A0
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SECTOR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_GFPREG_BASE_MASK
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_LINEAR_ADDR_MASK
value|0x00FFFFFF
end_define

begin_comment
comment|/* ICH8 GbE Flash Hardware Sequencing Flash Status Register bit breakdown */
end_comment

begin_comment
comment|/* Offset 04h HSFSTS */
end_comment

begin_union
union|union
name|ich8_hws_flash_status
block|{
struct|struct
name|ich8_hsfsts
block|{
name|uint16_t
name|flcdone
range|:
literal|1
decl_stmt|;
comment|/* bit 0 Flash Cycle Done */
name|uint16_t
name|flcerr
range|:
literal|1
decl_stmt|;
comment|/* bit 1 Flash Cycle Error */
name|uint16_t
name|dael
range|:
literal|1
decl_stmt|;
comment|/* bit 2 Direct Access error Log */
name|uint16_t
name|berasesz
range|:
literal|2
decl_stmt|;
comment|/* bit 4:3 Block/Sector Erase Size */
name|uint16_t
name|flcinprog
range|:
literal|1
decl_stmt|;
comment|/* bit 5 flash SPI cycle in Progress */
name|uint16_t
name|reserved1
range|:
literal|2
decl_stmt|;
comment|/* bit 13:6 Reserved */
name|uint16_t
name|reserved2
range|:
literal|6
decl_stmt|;
comment|/* bit 13:6 Reserved */
name|uint16_t
name|fldesvalid
range|:
literal|1
decl_stmt|;
comment|/* bit 14 Flash Descriptor Valid */
name|uint16_t
name|flockdn
range|:
literal|1
decl_stmt|;
comment|/* bit 15 Flash Configuration Lock-Down */
block|}
name|hsf_status
struct|;
name|uint16_t
name|regval
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* ICH8 GbE Flash Hardware Sequencing Flash control Register bit breakdown */
end_comment

begin_comment
comment|/* Offset 06h FLCTL */
end_comment

begin_union
union|union
name|ich8_hws_flash_ctrl
block|{
struct|struct
name|ich8_hsflctl
block|{
name|uint16_t
name|flcgo
range|:
literal|1
decl_stmt|;
comment|/* 0 Flash Cycle Go */
name|uint16_t
name|flcycle
range|:
literal|2
decl_stmt|;
comment|/* 2:1 Flash Cycle */
name|uint16_t
name|reserved
range|:
literal|5
decl_stmt|;
comment|/* 7:3 Reserved  */
name|uint16_t
name|fldbcount
range|:
literal|2
decl_stmt|;
comment|/* 9:8 Flash Data Byte Count */
name|uint16_t
name|flockdn
range|:
literal|6
decl_stmt|;
comment|/* 15:10 Reserved */
block|}
name|hsf_ctrl
struct|;
name|uint16_t
name|regval
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* ICH8 Flash Region Access Permissions */
end_comment

begin_union
union|union
name|ich8_hws_flash_regacc
block|{
struct|struct
name|ich8_flracc
block|{
name|uint32_t
name|grra
range|:
literal|8
decl_stmt|;
comment|/* 0:7 GbE region Read Access */
name|uint32_t
name|grwa
range|:
literal|8
decl_stmt|;
comment|/* 8:15 GbE region Write Access */
name|uint32_t
name|gmrag
range|:
literal|8
decl_stmt|;
comment|/* 23:16 GbE Master Read Access Grant  */
name|uint32_t
name|gmwag
range|:
literal|8
decl_stmt|;
comment|/* 31:24 GbE Master Write Access Grant */
block|}
name|hsf_flregacc
struct|;
name|uint16_t
name|regval
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Miscellaneous PHY bit definitions. */
end_comment

begin_define
define|#
directive|define
name|PHY_PREAMBLE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|PHY_SOF
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_OP_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_OP_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_PREAMBLE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_PHY_ADDRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_AUTO_NEG_TIME
value|45
end_define

begin_comment
comment|/* 4.5 Seconds */
end_comment

begin_define
define|#
directive|define
name|PHY_FORCE_TIME
value|20
end_define

begin_comment
comment|/* 2.0 Seconds */
end_comment

begin_define
define|#
directive|define
name|PHY_REVISION_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|DEVICE_SPEED_MASK
value|0x00000300
end_define

begin_comment
comment|/* Device Ctrl Reg Speed Mask */
end_comment

begin_define
define|#
directive|define
name|REG4_SPEED_MASK
value|0x01E0
end_define

begin_define
define|#
directive|define
name|REG9_SPEED_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_HALF
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_HALF
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_FULL
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000_HALF
value|0x0010
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000_FULL
value|0x0020
end_define

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_SPEED_DEFAULT
value|0x002F
end_define

begin_comment
comment|/* Everything but 1000-Half */
end_comment

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_10_100_ALL
value|0x000F
end_define

begin_comment
comment|/* All 10/100 speeds*/
end_comment

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_10_ALL
value|0x0003
end_define

begin_comment
comment|/* 10Mbps Full& Half speeds*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_HW_H_ */
end_comment

end_unit

