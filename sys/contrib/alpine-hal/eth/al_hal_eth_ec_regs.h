begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_eth_ec_regs.h  *  * @brief Ethernet controller registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_EC_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_EC_REG_H
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* * Unit Registers */
struct|struct
name|al_ec_gen
block|{
comment|/* [0x0] Ethernet controller Version */
name|uint32_t
name|version
decl_stmt|;
comment|/* [0x4] Enable modules operation. */
name|uint32_t
name|en
decl_stmt|;
comment|/* [0x8] Enable FIFO operation on the EC side. */
name|uint32_t
name|fifo_en
decl_stmt|;
comment|/* [0xc] General L2 configuration for the Ethernet controlle ... */
name|uint32_t
name|l2
decl_stmt|;
comment|/* [0x10] Configure protocol index values */
name|uint32_t
name|cfg_i
decl_stmt|;
comment|/* [0x14] Configure protocol index values (extended protocols ... */
name|uint32_t
name|cfg_i_ext
decl_stmt|;
comment|/* [0x18] Enable modules operation (extended operations). */
name|uint32_t
name|en_ext
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_mac
block|{
comment|/* [0x0] General configuration of the MAC side of the Ethern ... */
name|uint32_t
name|gen
decl_stmt|;
comment|/* [0x4] Minimum packet size  */
name|uint32_t
name|min_pkt
decl_stmt|;
comment|/* [0x8] Maximum packet size  */
name|uint32_t
name|max_pkt
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rxf
block|{
comment|/* [0x0] Rx FIFO input controller configuration 1 */
name|uint32_t
name|cfg_1
decl_stmt|;
comment|/* [0x4] Rx FIFO input controller configuration 2 */
name|uint32_t
name|cfg_2
decl_stmt|;
comment|/* [0x8] Threshold to start reading packet from the Rx FIFO */
name|uint32_t
name|rd_fifo
decl_stmt|;
comment|/* [0xc] Threshold to stop writing packet to the Rx FIFO */
name|uint32_t
name|wr_fifo
decl_stmt|;
comment|/* [0x10] Threshold to stop writing packet to the loopback FI ... */
name|uint32_t
name|lb_fifo
decl_stmt|;
comment|/* [0x14] Rx FIFO input controller loopback FIFO configuratio ... */
name|uint32_t
name|cfg_lb
decl_stmt|;
comment|/* [0x18] Configuration for dropping packet at the FIFO outpu ... */
name|uint32_t
name|out_drop
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|25
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_epe
block|{
comment|/* [0x0] Ethernet parsing engine configuration 1 */
name|uint32_t
name|parse_cfg
decl_stmt|;
comment|/* [0x4] Protocol index action table address */
name|uint32_t
name|act_table_addr
decl_stmt|;
comment|/* [0x8] Protocol index action table data */
name|uint32_t
name|act_table_data_1
decl_stmt|;
comment|/* [0xc] Protocol index action table data */
name|uint32_t
name|act_table_data_2
decl_stmt|;
comment|/* [0x10] Protocol index action table data */
name|uint32_t
name|act_table_data_3
decl_stmt|;
comment|/* [0x14] Protocol index action table data */
name|uint32_t
name|act_table_data_4
decl_stmt|;
comment|/* [0x18] Protocol index action table data */
name|uint32_t
name|act_table_data_5
decl_stmt|;
comment|/* [0x1c] Protocol index action table data */
name|uint32_t
name|act_table_data_6
decl_stmt|;
comment|/* [0x20] Input result vector, default values for parser inpu ... */
name|uint32_t
name|res_def
decl_stmt|;
comment|/* [0x24] Result input vector selection */
name|uint32_t
name|res_in
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_epe_res
block|{
comment|/* [0x0] Parser result vector pointer */
name|uint32_t
name|p1
decl_stmt|;
comment|/* [0x4] Parser result vector pointer */
name|uint32_t
name|p2
decl_stmt|;
comment|/* [0x8] Parser result vector pointer */
name|uint32_t
name|p3
decl_stmt|;
comment|/* [0xc] Parser result vector pointer */
name|uint32_t
name|p4
decl_stmt|;
comment|/* [0x10] Parser result vector pointer */
name|uint32_t
name|p5
decl_stmt|;
comment|/* [0x14] Parser result vector pointer */
name|uint32_t
name|p6
decl_stmt|;
comment|/* [0x18] Parser result vector pointer */
name|uint32_t
name|p7
decl_stmt|;
comment|/* [0x1c] Parser result vector pointer */
name|uint32_t
name|p8
decl_stmt|;
comment|/* [0x20] Parser result vector pointer */
name|uint32_t
name|p9
decl_stmt|;
comment|/* [0x24] Parser result vector pointer */
name|uint32_t
name|p10
decl_stmt|;
comment|/* [0x28] Parser result vector pointer */
name|uint32_t
name|p11
decl_stmt|;
comment|/* [0x2c] Parser result vector pointer */
name|uint32_t
name|p12
decl_stmt|;
comment|/* [0x30] Parser result vector pointer */
name|uint32_t
name|p13
decl_stmt|;
comment|/* [0x34] Parser result vector pointer */
name|uint32_t
name|p14
decl_stmt|;
comment|/* [0x38] Parser result vector pointer */
name|uint32_t
name|p15
decl_stmt|;
comment|/* [0x3c] Parser result vector pointer */
name|uint32_t
name|p16
decl_stmt|;
comment|/* [0x40] Parser result vector pointer */
name|uint32_t
name|p17
decl_stmt|;
comment|/* [0x44] Parser result vector pointer */
name|uint32_t
name|p18
decl_stmt|;
comment|/* [0x48] Parser result vector pointer */
name|uint32_t
name|p19
decl_stmt|;
comment|/* [0x4c] Parser result vector pointer */
name|uint32_t
name|p20
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_epe_h
block|{
comment|/* [0x0] Header length, support for header length table for  ... */
name|uint32_t
name|hdr_len
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_epe_p
block|{
comment|/* [0x0] Data  for comparison */
name|uint32_t
name|comp_data
decl_stmt|;
comment|/* [0x4] Mask for comparison */
name|uint32_t
name|comp_mask
decl_stmt|;
comment|/* [0x8] Compare control */
name|uint32_t
name|comp_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_epe_a
block|{
comment|/* [0x0] Protocol index action register */
name|uint32_t
name|prot_act
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw
block|{
comment|/* [0x0] Tuple (4/2) Hash configuration */
name|uint32_t
name|thash_cfg_1
decl_stmt|;
comment|/* [0x4] Tuple (4/2) Hash configuration */
name|uint32_t
name|thash_cfg_2
decl_stmt|;
comment|/* [0x8] MAC Hash configuration */
name|uint32_t
name|mhash_cfg_1
decl_stmt|;
comment|/* [0xc] MAC Hash configuration */
name|uint32_t
name|mhash_cfg_2
decl_stmt|;
comment|/* [0x10] MAC Hash configuration */
name|uint32_t
name|hdr_split
decl_stmt|;
comment|/* [0x14] Masking the errors described in  register rxf_drop  ... */
name|uint32_t
name|meta_err
decl_stmt|;
comment|/* [0x18] Configuration for generating the MetaData for the R ... */
name|uint32_t
name|meta
decl_stmt|;
comment|/* [0x1c] Configuration for generating the MetaData for the R ... */
name|uint32_t
name|filter
decl_stmt|;
comment|/* [0x20] 4 tupple hash table address */
name|uint32_t
name|thash_table_addr
decl_stmt|;
comment|/* [0x24] 4 tupple hash table data */
name|uint32_t
name|thash_table_data
decl_stmt|;
comment|/* [0x28] MAC hash table address */
name|uint32_t
name|mhash_table_addr
decl_stmt|;
comment|/* [0x2c] MAC hash table data */
name|uint32_t
name|mhash_table_data
decl_stmt|;
comment|/* [0x30] VLAN table address */
name|uint32_t
name|vid_table_addr
decl_stmt|;
comment|/* [0x34] VLAN table data */
name|uint32_t
name|vid_table_data
decl_stmt|;
comment|/* [0x38] VLAN p-bits table address */
name|uint32_t
name|pbits_table_addr
decl_stmt|;
comment|/* [0x3c] VLAN p-bits table data */
name|uint32_t
name|pbits_table_data
decl_stmt|;
comment|/* [0x40] DSCP table address */
name|uint32_t
name|dscp_table_addr
decl_stmt|;
comment|/* [0x44] DSCP table data */
name|uint32_t
name|dscp_table_data
decl_stmt|;
comment|/* [0x48] TC table address */
name|uint32_t
name|tc_table_addr
decl_stmt|;
comment|/* [0x4c] TC table data */
name|uint32_t
name|tc_table_data
decl_stmt|;
comment|/* [0x50] Control table address */
name|uint32_t
name|ctrl_table_addr
decl_stmt|;
comment|/* [0x54] Control table data */
name|uint32_t
name|ctrl_table_data
decl_stmt|;
comment|/* [0x58] Forwarding output configuration */
name|uint32_t
name|out_cfg
decl_stmt|;
comment|/* [0x5c] Flow steering mechanism, Table address */
name|uint32_t
name|fsm_table_addr
decl_stmt|;
comment|/* [0x60] Flow steering mechanism, Table data */
name|uint32_t
name|fsm_table_data
decl_stmt|;
comment|/* [0x64] Selection of data to be used in packet forwarding0  ... */
name|uint32_t
name|ctrl_sel
decl_stmt|;
comment|/* [0x68] Default VLAN data, used for untagged packets */
name|uint32_t
name|default_vlan
decl_stmt|;
comment|/* [0x6c] Default HASH output values */
name|uint32_t
name|default_hash
decl_stmt|;
comment|/* [0x70] Default override values, if a packet was filtered b ... */
name|uint32_t
name|default_or
decl_stmt|;
comment|/* [0x74] Latched information when a drop condition occurred */
name|uint32_t
name|drop_latch
decl_stmt|;
comment|/* [0x78] Check sum calculation configuration */
name|uint32_t
name|checksum
decl_stmt|;
comment|/* [0x7c] LRO offload engine configuration register */
name|uint32_t
name|lro_cfg_1
decl_stmt|;
comment|/* [0x80] LRO offload engine Check rules configurations for I ... */
name|uint32_t
name|lro_check_ipv4
decl_stmt|;
comment|/* [0x84] LRO offload engine IPv4 values configuration */
name|uint32_t
name|lro_ipv4
decl_stmt|;
comment|/* [0x88] LRO offload engine Check rules configurations for I ... */
name|uint32_t
name|lro_check_ipv6
decl_stmt|;
comment|/* [0x8c] LRO offload engine IPv6 values configuration */
name|uint32_t
name|lro_ipv6
decl_stmt|;
comment|/* [0x90] LRO offload engine Check rules configurations for T ... */
name|uint32_t
name|lro_check_tcp
decl_stmt|;
comment|/* [0x94] LRO offload engine IPv6 values configuration */
name|uint32_t
name|lro_tcp
decl_stmt|;
comment|/* [0x98] LRO offload engine Check rules configurations for U ... */
name|uint32_t
name|lro_check_udp
decl_stmt|;
comment|/* [0x9c] LRO offload engine Check rules configurations for U ... */
name|uint32_t
name|lro_check_l2
decl_stmt|;
comment|/* [0xa0] LRO offload engine Check rules configurations for U ... */
name|uint32_t
name|lro_check_gen
decl_stmt|;
comment|/* [0xa4] Rules for storing packet information into the cache ... */
name|uint32_t
name|lro_store
decl_stmt|;
comment|/* [0xa8] VLAN table default */
name|uint32_t
name|vid_table_def
decl_stmt|;
comment|/* [0xac] Control table default */
name|uint32_t
name|ctrl_table_def
decl_stmt|;
comment|/* [0xb0] Additional configuration 0 */
name|uint32_t
name|cfg_a_0
decl_stmt|;
comment|/* [0xb4] Tuple (4/2) Hash configuration (extended for RoCE a ... */
name|uint32_t
name|thash_cfg_3
decl_stmt|;
comment|/* [0xb8] Tuple (4/2) Hash configuration , mask for the input ... */
name|uint32_t
name|thash_mask_outer_ipv6
decl_stmt|;
comment|/* [0xbc] Tuple (4/2) Hash configuration , mask for the input ... */
name|uint32_t
name|thash_mask_outer
decl_stmt|;
comment|/* [0xc0] Tuple (4/2) Hash configuration , mask for the input ... */
name|uint32_t
name|thash_mask_inner_ipv6
decl_stmt|;
comment|/* [0xc4] Tuple (4/2) Hash configuration , mask for the input ... */
name|uint32_t
name|thash_mask_inner
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw_udma
block|{
comment|/* [0x0] Per UDMA default configuration */
name|uint32_t
name|def_cfg
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw_hash
block|{
comment|/* [0x0] key configuration (320 bits) */
name|uint32_t
name|key
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw_priority
block|{
comment|/* [0x0] Priority to queue mapping configuration */
name|uint32_t
name|queue
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw_default
block|{
comment|/* [0x0] Default forwarding configuration options */
name|uint32_t
name|opt_1
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_fwd_mac
block|{
comment|/* [0x0] MAC address data [31:0] */
name|uint32_t
name|data_l
decl_stmt|;
comment|/* [0x4] MAC address data [15:0] */
name|uint32_t
name|data_h
decl_stmt|;
comment|/* [0x8] MAC address mask [31:0] */
name|uint32_t
name|mask_l
decl_stmt|;
comment|/* [0xc] MAC address mask [15:0] */
name|uint32_t
name|mask_h
decl_stmt|;
comment|/* [0x10] MAC compare control */
name|uint32_t
name|ctrl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_msw
block|{
comment|/* [0x0] Configuration for unicast packets */
name|uint32_t
name|uc
decl_stmt|;
comment|/* [0x4] Configuration for multicast packets */
name|uint32_t
name|mc
decl_stmt|;
comment|/* [0x8] Configuration for broadcast packets */
name|uint32_t
name|bc
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tso
block|{
comment|/* [0x0] Input configuration */
name|uint32_t
name|in_cfg
decl_stmt|;
comment|/* [0x4] MetaData default cache table address */
name|uint32_t
name|cache_table_addr
decl_stmt|;
comment|/* [0x8] MetaData default cache table data */
name|uint32_t
name|cache_table_data_1
decl_stmt|;
comment|/* [0xc] MetaData default cache table data */
name|uint32_t
name|cache_table_data_2
decl_stmt|;
comment|/* [0x10] MetaData default cache table data */
name|uint32_t
name|cache_table_data_3
decl_stmt|;
comment|/* [0x14] MetaData default cache table data */
name|uint32_t
name|cache_table_data_4
decl_stmt|;
comment|/* [0x18] TCP control bit operation for first segment */
name|uint32_t
name|ctrl_first
decl_stmt|;
comment|/* [0x1c] TCP control bit operation for middle segments  */
name|uint32_t
name|ctrl_middle
decl_stmt|;
comment|/* [0x20] TCP control bit operation for last segment */
name|uint32_t
name|ctrl_last
decl_stmt|;
comment|/* [0x24] Additional TSO configurations */
name|uint32_t
name|cfg_add_0
decl_stmt|;
comment|/* [0x28] TSO configuration for tunnelled packets */
name|uint32_t
name|cfg_tunnel
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tso_sel
block|{
comment|/* [0x0] MSS value */
name|uint32_t
name|mss
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tpe
block|{
comment|/* [0x0] Parsing configuration */
name|uint32_t
name|parse
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tpm_udma
block|{
comment|/* [0x0] Default VLAN data */
name|uint32_t
name|vlan_data
decl_stmt|;
comment|/* [0x4] UDMA MAC SA information for spoofing */
name|uint32_t
name|mac_sa_1
decl_stmt|;
comment|/* [0x8] UDMA MAC SA information for spoofing */
name|uint32_t
name|mac_sa_2
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tpm_sel
block|{
comment|/* [0x0] Ethertype values for VLAN modification */
name|uint32_t
name|etype
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tfw
block|{
comment|/* [0x0] Tx FIFO Wr configuration */
name|uint32_t
name|tx_wr_fifo
decl_stmt|;
comment|/* [0x4] VLAN table address */
name|uint32_t
name|tx_vid_table_addr
decl_stmt|;
comment|/* [0x8] VLAN table data */
name|uint32_t
name|tx_vid_table_data
decl_stmt|;
comment|/* [0xc] Tx FIFO Rd configuration */
name|uint32_t
name|tx_rd_fifo
decl_stmt|;
comment|/* [0x10] Tx FIFO Rd configuration, checksum insertion */
name|uint32_t
name|tx_checksum
decl_stmt|;
comment|/* [0x14] Tx forwarding general configuration register */
name|uint32_t
name|tx_gen
decl_stmt|;
comment|/* [0x18] Tx spoofing configuration */
name|uint32_t
name|tx_spf
decl_stmt|;
comment|/* [0x1c] TX data FIFO status */
name|uint32_t
name|data_fifo
decl_stmt|;
comment|/* [0x20] Tx control FIFO status */
name|uint32_t
name|ctrl_fifo
decl_stmt|;
comment|/* [0x24] Tx header FIFO status */
name|uint32_t
name|hdr_fifo
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tfw_udma
block|{
comment|/* [0x0] Default GMDA output bitmap for unicast packet */
name|uint32_t
name|uc_udma
decl_stmt|;
comment|/* [0x4] Default GMDA output bitmap for multicast packet */
name|uint32_t
name|mc_udma
decl_stmt|;
comment|/* [0x8] Default GMDA output bitmap for broadcast packet */
name|uint32_t
name|bc_udma
decl_stmt|;
comment|/* [0xc] Tx spoofing configuration */
name|uint32_t
name|spf_cmd
decl_stmt|;
comment|/* [0x10] Forwarding decision control */
name|uint32_t
name|fwd_dec
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tmi
block|{
comment|/* [0x0] Forward packets back to the Rx data path for local  ... */
name|uint32_t
name|tx_cfg
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_efc
block|{
comment|/* [0x0] Mask of pause_on  [7:0] for the Ethernet controller ... */
name|uint32_t
name|ec_pause
decl_stmt|;
comment|/* [0x4] Mask of Ethernet controller Almost Full indication  ... */
name|uint32_t
name|ec_xoff
decl_stmt|;
comment|/* [0x8] Mask for generating XON indication pulse */
name|uint32_t
name|xon
decl_stmt|;
comment|/* [0xc] Mask for generating GPIO output XOFF indication fro ... */
name|uint32_t
name|gpio
decl_stmt|;
comment|/* [0x10] Rx FIFO threshold for generating the Almost Full in ... */
name|uint32_t
name|rx_fifo_af
decl_stmt|;
comment|/* [0x14] Rx FIFO threshold for generating the Almost Full in ... */
name|uint32_t
name|rx_fifo_hyst
decl_stmt|;
comment|/* [0x18] Rx FIFO threshold for generating the Almost Full in ... */
name|uint32_t
name|stat
decl_stmt|;
comment|/* [0x1c] XOFF timer for the 1G MACSets the interval (in SB_C ... */
name|uint32_t
name|xoff_timer_1g
decl_stmt|;
comment|/* [0x20] PFC force flow control generation */
name|uint32_t
name|ec_pfc
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_fc_udma
block|{
comment|/* [0x0] Mask of "pause_on"  [0] for all queues */
name|uint32_t
name|q_pause_0
decl_stmt|;
comment|/* [0x4] Mask of "pause_on"  [1] for all queues */
name|uint32_t
name|q_pause_1
decl_stmt|;
comment|/* [0x8] Mask of "pause_on"  [2] for all queues */
name|uint32_t
name|q_pause_2
decl_stmt|;
comment|/* [0xc] Mask of "pause_on"  [3] for all queues */
name|uint32_t
name|q_pause_3
decl_stmt|;
comment|/* [0x10] Mask of "pause_on"  [4] for all queues */
name|uint32_t
name|q_pause_4
decl_stmt|;
comment|/* [0x14] Mask of "pause_on"  [5] for all queues */
name|uint32_t
name|q_pause_5
decl_stmt|;
comment|/* [0x18] Mask of "pause_on"  [6] for all queues */
name|uint32_t
name|q_pause_6
decl_stmt|;
comment|/* [0x1c] Mask of "pause_on"  [7] for all queues */
name|uint32_t
name|q_pause_7
decl_stmt|;
comment|/* [0x20] Mask of external GPIO input pause [0] for all queue ... */
name|uint32_t
name|q_gpio_0
decl_stmt|;
comment|/* [0x24] Mask of external GPIO input pause [1] for all queue ... */
name|uint32_t
name|q_gpio_1
decl_stmt|;
comment|/* [0x28] Mask of external GPIO input pause [2] for all queue ... */
name|uint32_t
name|q_gpio_2
decl_stmt|;
comment|/* [0x2c] Mask of external GPIO input pause [3] for all queue ... */
name|uint32_t
name|q_gpio_3
decl_stmt|;
comment|/* [0x30] Mask of external GPIO input [4] for all queues */
name|uint32_t
name|q_gpio_4
decl_stmt|;
comment|/* [0x34] Mask of external GPIO input [5] for all queues */
name|uint32_t
name|q_gpio_5
decl_stmt|;
comment|/* [0x38] Mask of external GPIO input [6] for all queues */
name|uint32_t
name|q_gpio_6
decl_stmt|;
comment|/* [0x3c] Mask of external GPIO input [7] for all queues */
name|uint32_t
name|q_gpio_7
decl_stmt|;
comment|/* [0x40] Mask of "pause_on"  [7:0] for the UDMA stream inter ... */
name|uint32_t
name|s_pause
decl_stmt|;
comment|/* [0x44] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_0
decl_stmt|;
comment|/* [0x48] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_1
decl_stmt|;
comment|/* [0x4c] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_2
decl_stmt|;
comment|/* [0x50] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_3
decl_stmt|;
comment|/* [0x54] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_4
decl_stmt|;
comment|/* [0x58] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_5
decl_stmt|;
comment|/* [0x5c] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_6
decl_stmt|;
comment|/* [0x60] Mask of Rx Almost Full indication for generating XO ... */
name|uint32_t
name|q_xoff_7
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tpg_rpa_res
block|{
comment|/* [0x0] NOT used */
name|uint32_t
name|not_used
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|63
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_eee
block|{
comment|/* [0x0] EEE configuration */
name|uint32_t
name|cfg_e
decl_stmt|;
comment|/* [0x4] Number of clocks to get into EEE mode. */
name|uint32_t
name|pre_cnt
decl_stmt|;
comment|/* [0x8] Number of clocks to stop MAC EEE mode after getting ... */
name|uint32_t
name|post_cnt
decl_stmt|;
comment|/* [0xc] Number of clocks to stop the Tx MAC interface after ... */
name|uint32_t
name|stop_cnt
decl_stmt|;
comment|/* [0x10] EEE status */
name|uint32_t
name|stat_eee
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|59
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_stat
block|{
comment|/* [0x0] Rx Frequency adjust FIFO input  packets */
name|uint32_t
name|faf_in_rx_pkt
decl_stmt|;
comment|/* [0x4] Rx Frequency adjust FIFO input short error packets */
name|uint32_t
name|faf_in_rx_short
decl_stmt|;
comment|/* [0x8] Rx Frequency adjust FIFO input  long error packets */
name|uint32_t
name|faf_in_rx_long
decl_stmt|;
comment|/* [0xc] Rx Frequency adjust FIFO output  packets */
name|uint32_t
name|faf_out_rx_pkt
decl_stmt|;
comment|/* [0x10] Rx Frequency adjust FIFO output short error packets ... */
name|uint32_t
name|faf_out_rx_short
decl_stmt|;
comment|/* [0x14] Rx Frequency adjust FIFO output long error packets */
name|uint32_t
name|faf_out_rx_long
decl_stmt|;
comment|/* [0x18] Rx Frequency adjust FIFO output  drop packets */
name|uint32_t
name|faf_out_drop
decl_stmt|;
comment|/* [0x1c] Number of packets written into the Rx FIFO (without ... */
name|uint32_t
name|rxf_in_rx_pkt
decl_stmt|;
comment|/* [0x20] Number of error packets written into the Rx FIFO (w ... */
name|uint32_t
name|rxf_in_fifo_err
decl_stmt|;
comment|/* [0x24] Number of packets written into the loopback FIFO (w ... */
name|uint32_t
name|lbf_in_rx_pkt
decl_stmt|;
comment|/* [0x28] Number of error packets written into the loopback F ... */
name|uint32_t
name|lbf_in_fifo_err
decl_stmt|;
comment|/* [0x2c] Number of packets read from Rx FIFO 1 */
name|uint32_t
name|rxf_out_rx_1_pkt
decl_stmt|;
comment|/* [0x30] Number of packets read from Rx FIFO 2 (loopback FIF ... */
name|uint32_t
name|rxf_out_rx_2_pkt
decl_stmt|;
comment|/* [0x34] Rx FIFO output drop packets from FIFO 1 */
name|uint32_t
name|rxf_out_drop_1_pkt
decl_stmt|;
comment|/* [0x38] Rx FIFO output drop packets from FIFO 2 (loopback) */
name|uint32_t
name|rxf_out_drop_2_pkt
decl_stmt|;
comment|/* [0x3c] Rx Parser 1, input packet counter */
name|uint32_t
name|rpe_1_in_rx_pkt
decl_stmt|;
comment|/* [0x40] Rx Parser 1, output packet counter */
name|uint32_t
name|rpe_1_out_rx_pkt
decl_stmt|;
comment|/* [0x44] Rx Parser 2, input packet counter */
name|uint32_t
name|rpe_2_in_rx_pkt
decl_stmt|;
comment|/* [0x48] Rx Parser 2, output packet counter */
name|uint32_t
name|rpe_2_out_rx_pkt
decl_stmt|;
comment|/* [0x4c] Rx Parser 3 (MACsec), input packet counter */
name|uint32_t
name|rpe_3_in_rx_pkt
decl_stmt|;
comment|/* [0x50] Rx Parser 3 (MACsec), output packet counter */
name|uint32_t
name|rpe_3_out_rx_pkt
decl_stmt|;
comment|/* [0x54] Tx parser, input packet counter */
name|uint32_t
name|tpe_in_tx_pkt
decl_stmt|;
comment|/* [0x58] Tx parser, output packet counter */
name|uint32_t
name|tpe_out_tx_pkt
decl_stmt|;
comment|/* [0x5c] Tx packet modification, input packet counter */
name|uint32_t
name|tpm_tx_pkt
decl_stmt|;
comment|/* [0x60] Tx forwarding input packet counter */
name|uint32_t
name|tfw_in_tx_pkt
decl_stmt|;
comment|/* [0x64] Tx forwarding input packet counter */
name|uint32_t
name|tfw_out_tx_pkt
decl_stmt|;
comment|/* [0x68] Rx forwarding input packet counter */
name|uint32_t
name|rfw_in_rx_pkt
decl_stmt|;
comment|/* [0x6c] Rx Forwarding, packet with VLAN command drop indica ... */
name|uint32_t
name|rfw_in_vlan_drop
decl_stmt|;
comment|/* [0x70] Rx Forwarding, packets with parse drop indication */
name|uint32_t
name|rfw_in_parse_drop
decl_stmt|;
comment|/* [0x74] Rx Forwarding, multicast packets */
name|uint32_t
name|rfw_in_mc
decl_stmt|;
comment|/* [0x78] Rx Forwarding, broadcast packets */
name|uint32_t
name|rfw_in_bc
decl_stmt|;
comment|/* [0x7c] Rx Forwarding, tagged packets */
name|uint32_t
name|rfw_in_vlan_exist
decl_stmt|;
comment|/* [0x80] Rx Forwarding, untagged packets */
name|uint32_t
name|rfw_in_vlan_nexist
decl_stmt|;
comment|/* [0x84] Rx Forwarding, packets with MAC address drop indica ... */
name|uint32_t
name|rfw_in_mac_drop
decl_stmt|;
comment|/* [0x88] Rx Forwarding, packets with undetected MAC address */
name|uint32_t
name|rfw_in_mac_ndet_drop
decl_stmt|;
comment|/* [0x8c] Rx Forwarding, packets with drop indication from th ... */
name|uint32_t
name|rfw_in_ctrl_drop
decl_stmt|;
comment|/* [0x90] Rx Forwarding, packets with L3_protocol_index drop  ... */
name|uint32_t
name|rfw_in_prot_i_drop
decl_stmt|;
comment|/* [0x94] EEE, number of times the system went into EEE state ... */
name|uint32_t
name|eee_in
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|90
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_stat_udma
block|{
comment|/* [0x0] Rx forwarding output packet counter */
name|uint32_t
name|rfw_out_rx_pkt
decl_stmt|;
comment|/* [0x4] Rx forwarding output drop packet counter */
name|uint32_t
name|rfw_out_drop
decl_stmt|;
comment|/* [0x8] Multi-stream write, number of Rx packets */
name|uint32_t
name|msw_in_rx_pkt
decl_stmt|;
comment|/* [0xc] Multi-stream write, number of dropped packets at SO ... */
name|uint32_t
name|msw_drop_q_full
decl_stmt|;
comment|/* [0x10] Multi-stream write, number of dropped packets at SO ... */
name|uint32_t
name|msw_drop_sop
decl_stmt|;
comment|/* [0x14] Multi-stream write, number of dropped packets at EO ... */
name|uint32_t
name|msw_drop_eop
decl_stmt|;
comment|/* [0x18] Multi-stream write, number of packets written to th ... */
name|uint32_t
name|msw_wr_eop
decl_stmt|;
comment|/* [0x1c] Multi-stream write, number of packets read from the ... */
name|uint32_t
name|msw_out_rx_pkt
decl_stmt|;
comment|/* [0x20] Number of transmitted packets without TSO enabled */
name|uint32_t
name|tso_no_tso_pkt
decl_stmt|;
comment|/* [0x24] Number of transmitted packets with TSO enabled */
name|uint32_t
name|tso_tso_pkt
decl_stmt|;
comment|/* [0x28] Number of TSO segments that were generated */
name|uint32_t
name|tso_seg_pkt
decl_stmt|;
comment|/* [0x2c] Number of TSO segments that required padding */
name|uint32_t
name|tso_pad_pkt
decl_stmt|;
comment|/* [0x30] Tx Packet modification, MAC SA spoof error  */
name|uint32_t
name|tpm_tx_spoof
decl_stmt|;
comment|/* [0x34] Tx MAC interface, input packet counter */
name|uint32_t
name|tmi_in_tx_pkt
decl_stmt|;
comment|/* [0x38] Tx MAC interface, number of packets forwarded to th ... */
name|uint32_t
name|tmi_out_to_mac
decl_stmt|;
comment|/* [0x3c] Tx MAC interface, number of packets forwarded to th ... */
name|uint32_t
name|tmi_out_to_rx
decl_stmt|;
comment|/* [0x40] Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q0_bytes
decl_stmt|;
comment|/* [0x44] Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q1_bytes
decl_stmt|;
comment|/* [0x48] Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q2_bytes
decl_stmt|;
comment|/* [0x4c] Tx MAC interface, number of transmitted bytes */
name|uint32_t
name|tx_q3_bytes
decl_stmt|;
comment|/* [0x50] Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q0_pkts
decl_stmt|;
comment|/* [0x54] Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q1_pkts
decl_stmt|;
comment|/* [0x58] Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q2_pkts
decl_stmt|;
comment|/* [0x5c] Tx MAC interface, number of transmitted packets */
name|uint32_t
name|tx_q3_pkts
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|40
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_msp
block|{
comment|/* [0x0] Ethernet parsing engine configuration 1 */
name|uint32_t
name|p_parse_cfg
decl_stmt|;
comment|/* [0x4] Protocol index action table address */
name|uint32_t
name|p_act_table_addr
decl_stmt|;
comment|/* [0x8] Protocol index action table data */
name|uint32_t
name|p_act_table_data_1
decl_stmt|;
comment|/* [0xc] Protocol index action table data */
name|uint32_t
name|p_act_table_data_2
decl_stmt|;
comment|/* [0x10] Protocol index action table data */
name|uint32_t
name|p_act_table_data_3
decl_stmt|;
comment|/* [0x14] Protocol index action table data */
name|uint32_t
name|p_act_table_data_4
decl_stmt|;
comment|/* [0x18] Protocol index action table data */
name|uint32_t
name|p_act_table_data_5
decl_stmt|;
comment|/* [0x1c] Protocol index action table data */
name|uint32_t
name|p_act_table_data_6
decl_stmt|;
comment|/* [0x20] Input result vector, default values for parser inpu ... */
name|uint32_t
name|p_res_def
decl_stmt|;
comment|/* [0x24] Result input vector selection */
name|uint32_t
name|p_res_in
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_msp_p
block|{
comment|/* [0x0] Header length, support for header length table for  ... */
name|uint32_t
name|h_hdr_len
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_msp_c
block|{
comment|/* [0x0] Data  for comparison */
name|uint32_t
name|p_comp_data
decl_stmt|;
comment|/* [0x4] Mask for comparison */
name|uint32_t
name|p_comp_mask
decl_stmt|;
comment|/* [0x8] Compare control */
name|uint32_t
name|p_comp_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_wol
block|{
comment|/* [0x0] WoL enable configuration,Packet forwarding and inte ... */
name|uint32_t
name|wol_en
decl_stmt|;
comment|/* [0x4] Password for magic_password packet detection - bits ... */
name|uint32_t
name|magic_pswd_l
decl_stmt|;
comment|/* [0x8] Password for magic+password packet detection -  47: ... */
name|uint32_t
name|magic_pswd_h
decl_stmt|;
comment|/* [0xc] Configured L3 Destination IP address for WoL IPv6 p ... */
name|uint32_t
name|ipv6_dip_word0
decl_stmt|;
comment|/* [0x10] Configured L3 Destination IP address for WoL IPv6 p ... */
name|uint32_t
name|ipv6_dip_word1
decl_stmt|;
comment|/* [0x14] Configured L3 Destination IP address for WoL IPv6 p ... */
name|uint32_t
name|ipv6_dip_word2
decl_stmt|;
comment|/* [0x18] Configured L3 Destination IP address for WoL IPv6 p ... */
name|uint32_t
name|ipv6_dip_word3
decl_stmt|;
comment|/* [0x1c] Configured L3 Destination IP address for WoL IPv4 p ... */
name|uint32_t
name|ipv4_dip
decl_stmt|;
comment|/* [0x20] Configured EtherType for WoL EtherType_da/EtherType ... */
name|uint32_t
name|ethertype
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_pth
block|{
comment|/* [0x0] System time counter (Time of Day) */
name|uint32_t
name|system_time_seconds
decl_stmt|;
comment|/* [0x4] System time subseconds in a second (MSBs) */
name|uint32_t
name|system_time_subseconds_msb
decl_stmt|;
comment|/* [0x8] System time subseconds in a second (LSBs) */
name|uint32_t
name|system_time_subseconds_lsb
decl_stmt|;
comment|/* [0xc] Clock period in femtoseconds (MSB) */
name|uint32_t
name|clock_period_msb
decl_stmt|;
comment|/* [0x10] Clock period in femtoseconds (LSB) */
name|uint32_t
name|clock_period_lsb
decl_stmt|;
comment|/* [0x14] Control register for internal updates to the system ... */
name|uint32_t
name|int_update_ctrl
decl_stmt|;
comment|/* [0x18] Value to update system_time_seconds with */
name|uint32_t
name|int_update_seconds
decl_stmt|;
comment|/* [0x1c] Value to update system_time_subseconds_msb with */
name|uint32_t
name|int_update_subseconds_msb
decl_stmt|;
comment|/* [0x20] Value to update system_time_subseconds_lsb with */
name|uint32_t
name|int_update_subseconds_lsb
decl_stmt|;
comment|/* [0x24] Control register for external updates to the system ... */
name|uint32_t
name|ext_update_ctrl
decl_stmt|;
comment|/* [0x28] Value to update system_time_seconds with */
name|uint32_t
name|ext_update_seconds
decl_stmt|;
comment|/* [0x2c] Value to update system_time_subseconds_msb with */
name|uint32_t
name|ext_update_subseconds_msb
decl_stmt|;
comment|/* [0x30] Value to update system_time_subseconds_lsb with */
name|uint32_t
name|ext_update_subseconds_lsb
decl_stmt|;
comment|/* [0x34] This value represents the APB transaction delay fro ... */
name|uint32_t
name|read_compensation_subseconds_msb
decl_stmt|;
comment|/* [0x38] This value represents the APB transaction delay fro ... */
name|uint32_t
name|read_compensation_subseconds_lsb
decl_stmt|;
comment|/* [0x3c] This value is used for two purposes:1 */
name|uint32_t
name|int_write_compensation_subseconds_msb
decl_stmt|;
comment|/* [0x40] This value is used for two purposes:1 */
name|uint32_t
name|int_write_compensation_subseconds_lsb
decl_stmt|;
comment|/* [0x44] This value represents the number of cycles it for a ... */
name|uint32_t
name|ext_write_compensation_subseconds_msb
decl_stmt|;
comment|/* [0x48] This value represents the number of cycles it for a ... */
name|uint32_t
name|ext_write_compensation_subseconds_lsb
decl_stmt|;
comment|/* [0x4c] Value to be added to system_time before transferrin ... */
name|uint32_t
name|sync_compensation_subseconds_msb
decl_stmt|;
comment|/* [0x50] Value to be added to system_time before transferrin ... */
name|uint32_t
name|sync_compensation_subseconds_lsb
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_pth_egress
block|{
comment|/* [0x0] Control register for egress trigger #k */
name|uint32_t
name|trigger_ctrl
decl_stmt|;
comment|/* [0x4] threshold for next egress trigger (#k) - secondsWri ... */
name|uint32_t
name|trigger_seconds
decl_stmt|;
comment|/* [0x8] Threshold for next egress trigger (#k) - subseconds ... */
name|uint32_t
name|trigger_subseconds_msb
decl_stmt|;
comment|/* [0xc] threshold for next egress trigger (#k) - subseconds ... */
name|uint32_t
name|trigger_subseconds_lsb
decl_stmt|;
comment|/* [0x10] External output pulse width (subseconds_msb)(Atomic ... */
name|uint32_t
name|pulse_width_subseconds_msb
decl_stmt|;
comment|/* [0x14] External output pulse width (subseconds_lsb)(Atomic ... */
name|uint32_t
name|pulse_width_subseconds_lsb
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_pth_db
block|{
comment|/* [0x0] timestamp[k], in resolution of 2^18 femtosec =~ 0 */
name|uint32_t
name|ts
decl_stmt|;
comment|/* [0x4] Timestamp entry is valid */
name|uint32_t
name|qual
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_gen_v3
block|{
comment|/* [0x0] Bypass enable */
name|uint32_t
name|bypass
decl_stmt|;
comment|/* [0x4] Rx Completion descriptor */
name|uint32_t
name|rx_comp_desc
decl_stmt|;
comment|/* [0x8] general configuration */
name|uint32_t
name|conf
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_tfw_v3
block|{
comment|/* [0x0] Generic protocol detect Cam compare table address */
name|uint32_t
name|tx_gpd_cam_addr
decl_stmt|;
comment|/* [0x4] Tx Generic protocol detect Cam compare data_1 (low) ... */
name|uint32_t
name|tx_gpd_cam_data_1
decl_stmt|;
comment|/* [0x8] Tx Generic protocol detect Cam compare data_2 (high ... */
name|uint32_t
name|tx_gpd_cam_data_2
decl_stmt|;
comment|/* [0xc] Tx Generic protocol detect Cam compare mask_1 (low) ... */
name|uint32_t
name|tx_gpd_cam_mask_1
decl_stmt|;
comment|/* [0x10] Tx Generic protocol detect Cam compare mask_1 (high ... */
name|uint32_t
name|tx_gpd_cam_mask_2
decl_stmt|;
comment|/* [0x14] Tx Generic protocol detect Cam compare control */
name|uint32_t
name|tx_gpd_cam_ctrl
decl_stmt|;
comment|/* [0x18] Tx Generic crc parameters legacy */
name|uint32_t
name|tx_gcp_legacy
decl_stmt|;
comment|/* [0x1c] Tx Generic crc prameters table address */
name|uint32_t
name|tx_gcp_table_addr
decl_stmt|;
comment|/* [0x20] Tx Generic crc prameters table general */
name|uint32_t
name|tx_gcp_table_gen
decl_stmt|;
comment|/* [0x24] Tx Generic crc parametrs tabel mask word 1 */
name|uint32_t
name|tx_gcp_table_mask_1
decl_stmt|;
comment|/* [0x28] Tx Generic crc parametrs tabel mask word 2 */
name|uint32_t
name|tx_gcp_table_mask_2
decl_stmt|;
comment|/* [0x2c] Tx Generic crc parametrs tabel mask word 3 */
name|uint32_t
name|tx_gcp_table_mask_3
decl_stmt|;
comment|/* [0x30] Tx Generic crc parametrs tabel mask word 4 */
name|uint32_t
name|tx_gcp_table_mask_4
decl_stmt|;
comment|/* [0x34] Tx Generic crc parametrs tabel mask word 5 */
name|uint32_t
name|tx_gcp_table_mask_5
decl_stmt|;
comment|/* [0x38] Tx Generic crc parametrs tabel mask word 6 */
name|uint32_t
name|tx_gcp_table_mask_6
decl_stmt|;
comment|/* [0x3c] Tx Generic crc parametrs tabel crc init */
name|uint32_t
name|tx_gcp_table_crc_init
decl_stmt|;
comment|/* [0x40] Tx Generic crc parametrs tabel result configuration ... */
name|uint32_t
name|tx_gcp_table_res
decl_stmt|;
comment|/* [0x44] Tx Generic crc parameters table alu opcode */
name|uint32_t
name|tx_gcp_table_alu_opcode
decl_stmt|;
comment|/* [0x48] Tx Generic crc parameters table alu opsel */
name|uint32_t
name|tx_gcp_table_alu_opsel
decl_stmt|;
comment|/* [0x4c] Tx Generic crc parameters table alu constant value */
name|uint32_t
name|tx_gcp_table_alu_val
decl_stmt|;
comment|/* [0x50] Tx CRC/Checksum replace */
name|uint32_t
name|crc_csum_replace
decl_stmt|;
comment|/* [0x54] CRC/Checksum replace table address */
name|uint32_t
name|crc_csum_replace_table_addr
decl_stmt|;
comment|/* [0x58] CRC/Checksum replace table */
name|uint32_t
name|crc_csum_replace_table
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_rfw_v3
block|{
comment|/* [0x0] Rx Generic protocol detect Cam compare table addres ... */
name|uint32_t
name|rx_gpd_cam_addr
decl_stmt|;
comment|/* [0x4] Rx Generic protocol detect Cam compare data_1 (low) ... */
name|uint32_t
name|rx_gpd_cam_data_1
decl_stmt|;
comment|/* [0x8] Rx Generic protocol detect Cam compare data_2 (high ... */
name|uint32_t
name|rx_gpd_cam_data_2
decl_stmt|;
comment|/* [0xc] Rx Generic protocol detect Cam compare mask_1 (low) ... */
name|uint32_t
name|rx_gpd_cam_mask_1
decl_stmt|;
comment|/* [0x10] Rx Generic protocol detect Cam compare mask_1 (high ... */
name|uint32_t
name|rx_gpd_cam_mask_2
decl_stmt|;
comment|/* [0x14] Rx Generic protocol detect Cam compare control */
name|uint32_t
name|rx_gpd_cam_ctrl
decl_stmt|;
comment|/* [0x18] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p1
decl_stmt|;
comment|/* [0x1c] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p2
decl_stmt|;
comment|/* [0x20] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p3
decl_stmt|;
comment|/* [0x24] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p4
decl_stmt|;
comment|/* [0x28] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p5
decl_stmt|;
comment|/* [0x2c] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p6
decl_stmt|;
comment|/* [0x30] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p7
decl_stmt|;
comment|/* [0x34] Generic protocol detect Parser result vector pointe ... */
name|uint32_t
name|gpd_p8
decl_stmt|;
comment|/* [0x38] Rx Generic crc parameters legacy */
name|uint32_t
name|rx_gcp_legacy
decl_stmt|;
comment|/* [0x3c] Rx Generic crc prameters table address */
name|uint32_t
name|rx_gcp_table_addr
decl_stmt|;
comment|/* [0x40] Rx Generic crc prameters table general */
name|uint32_t
name|rx_gcp_table_gen
decl_stmt|;
comment|/* [0x44] Rx Generic crc parametrs tabel mask word 1 */
name|uint32_t
name|rx_gcp_table_mask_1
decl_stmt|;
comment|/* [0x48] Rx Generic crc parametrs tabel mask word 2 */
name|uint32_t
name|rx_gcp_table_mask_2
decl_stmt|;
comment|/* [0x4c] Rx Generic crc parametrs tabel mask word 3 */
name|uint32_t
name|rx_gcp_table_mask_3
decl_stmt|;
comment|/* [0x50] Rx Generic crc parametrs tabel mask word 4 */
name|uint32_t
name|rx_gcp_table_mask_4
decl_stmt|;
comment|/* [0x54] Rx Generic crc parametrs tabel mask word 5 */
name|uint32_t
name|rx_gcp_table_mask_5
decl_stmt|;
comment|/* [0x58] Rx Generic crc parametrs tabel mask word 6 */
name|uint32_t
name|rx_gcp_table_mask_6
decl_stmt|;
comment|/* [0x5c] Rx Generic crc parametrs tabel crc init */
name|uint32_t
name|rx_gcp_table_crc_init
decl_stmt|;
comment|/* [0x60] Rx Generic crc parametrs tabel result configuration ... */
name|uint32_t
name|rx_gcp_table_res
decl_stmt|;
comment|/* [0x64] Rx Generic crc  parameters table alu opcode */
name|uint32_t
name|rx_gcp_table_alu_opcode
decl_stmt|;
comment|/* [0x68] Rx Generic crc  parameters table alu opsel */
name|uint32_t
name|rx_gcp_table_alu_opsel
decl_stmt|;
comment|/* [0x6c] Rx Generic crc  parameters table alu constant value ... */
name|uint32_t
name|rx_gcp_table_alu_val
decl_stmt|;
comment|/* [0x70] Generic crc engin parameters alu Parser result vect ... */
name|uint32_t
name|rx_gcp_alu_p1
decl_stmt|;
comment|/* [0x74] Generic crc engine parameters alu Parser result vec ... */
name|uint32_t
name|rx_gcp_alu_p2
decl_stmt|;
comment|/* [0x78] Header split control table address */
name|uint32_t
name|hs_ctrl_table_addr
decl_stmt|;
comment|/* [0x7c] Header split control table */
name|uint32_t
name|hs_ctrl_table
decl_stmt|;
comment|/* [0x80] Header split control alu opcode */
name|uint32_t
name|hs_ctrl_table_alu_opcode
decl_stmt|;
comment|/* [0x84] Header split control alu opsel */
name|uint32_t
name|hs_ctrl_table_alu_opsel
decl_stmt|;
comment|/* [0x88] Header split control alu constant value */
name|uint32_t
name|hs_ctrl_table_alu_val
decl_stmt|;
comment|/* [0x8c] Header split control configuration */
name|uint32_t
name|hs_ctrl_cfg
decl_stmt|;
comment|/* [0x90] Header split control alu Parser result vector point ... */
name|uint32_t
name|hs_ctrl_alu_p1
decl_stmt|;
comment|/* [0x94] Header split control alu Parser result vector point ... */
name|uint32_t
name|hs_ctrl_alu_p2
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|26
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_crypto
block|{
comment|/* [0x0] Tx inline crypto configuration */
name|uint32_t
name|tx_config
decl_stmt|;
comment|/* [0x4] Rx inline crypto configuration */
name|uint32_t
name|rx_config
decl_stmt|;
comment|/* [0x8] reserved FFU */
name|uint32_t
name|tx_override
decl_stmt|;
comment|/* [0xc] reserved FFU */
name|uint32_t
name|rx_override
decl_stmt|;
comment|/* [0x10] inline XTS alpha [31:0] */
name|uint32_t
name|xts_alpha_1
decl_stmt|;
comment|/* [0x14] inline XTS alpha [63:32] */
name|uint32_t
name|xts_alpha_2
decl_stmt|;
comment|/* [0x18] inline XTS alpha [95:64] */
name|uint32_t
name|xts_alpha_3
decl_stmt|;
comment|/* [0x1c] inline XTS alpha [127:96] */
name|uint32_t
name|xts_alpha_4
decl_stmt|;
comment|/* [0x20] inline XTS sector ID increment [31:0] */
name|uint32_t
name|xts_sector_id_1
decl_stmt|;
comment|/* [0x24] inline XTS sector ID increment [63:32] */
name|uint32_t
name|xts_sector_id_2
decl_stmt|;
comment|/* [0x28] inline XTS sector ID increment [95:64] */
name|uint32_t
name|xts_sector_id_3
decl_stmt|;
comment|/* [0x2c] inline XTS sector ID increment [127:96] */
name|uint32_t
name|xts_sector_id_4
decl_stmt|;
comment|/* [0x30] IV formation configuration */
name|uint32_t
name|tx_enc_iv_construction
decl_stmt|;
comment|/* [0x34] IV formation configuration */
name|uint32_t
name|rx_enc_iv_construction
decl_stmt|;
comment|/* [0x38] IV formation configuration */
name|uint32_t
name|rx_enc_iv_map
decl_stmt|;
comment|/* 	[0x3c] effectively shorten shift-registers used for 	eop-pkt-trim, in order to improve performance. 	Each value must be built of consecutive 1's (bypassed regs), 	and then consecutive 0's (non-bypassed regs) 	*/
name|uint32_t
name|tx_pkt_trim_len
decl_stmt|;
comment|/* 	[0x40] effectively shorten shift-registers used for 	eop-pkt-trim, in order to improve performance. 	Each value must be built of consecutive 1's (bypassed regs), 	and then consecutive 0's (non-bypassed regs) 	*/
name|uint32_t
name|rx_pkt_trim_len
decl_stmt|;
comment|/* [0x44] reserved FFU */
name|uint32_t
name|tx_reserved
decl_stmt|;
comment|/* [0x48] reserved FFU */
name|uint32_t
name|rx_reserved
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_crypto_perf_cntr
block|{
comment|/* [0x0]  */
name|uint32_t
name|total_tx_pkts
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|total_rx_pkts
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|total_tx_secured_pkts
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|total_rx_secured_pkts
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|total_tx_secured_pkts_cipher_mode
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|total_tx_secured_pkts_cipher_mode_cmpr
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|total_rx_secured_pkts_cipher_mode
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|total_rx_secured_pkts_cipher_mode_cmpr
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|total_tx_secured_bytes_low
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|total_tx_secured_bytes_high
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|total_rx_secured_bytes_low
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|total_rx_secured_bytes_high
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|total_tx_sign_calcs
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|total_rx_sign_calcs
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|total_tx_sign_errs
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|total_rx_sign_errs
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_crypto_tx_tid
block|{
comment|/* [0x0] tid_default_entry */
name|uint32_t
name|def_val
decl_stmt|;
block|}
struct|;
struct|struct
name|al_ec_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|al_ec_gen
name|gen
decl_stmt|;
comment|/* [0x80] */
name|struct
name|al_ec_mac
name|mac
decl_stmt|;
comment|/* [0xc0] */
name|struct
name|al_ec_rxf
name|rxf
decl_stmt|;
comment|/* [0x100] */
name|struct
name|al_ec_epe
name|epe
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x180] */
name|struct
name|al_ec_epe_res
name|epe_res
decl_stmt|;
comment|/* [0x200] */
name|struct
name|al_ec_epe_h
name|epe_h
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x280] */
name|struct
name|al_ec_epe_p
name|epe_p
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x300] */
name|struct
name|al_ec_epe_a
name|epe_a
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x680] */
name|struct
name|al_ec_rfw
name|rfw
decl_stmt|;
comment|/* [0x700] */
name|struct
name|al_ec_rfw_udma
name|rfw_udma
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x7f0] */
name|struct
name|al_ec_rfw_hash
name|rfw_hash
index|[
literal|10
index|]
decl_stmt|;
comment|/* [0x800] */
name|struct
name|al_ec_rfw_priority
name|rfw_priority
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x828] */
name|struct
name|al_ec_rfw_default
name|rfw_default
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x848] */
name|struct
name|al_ec_fwd_mac
name|fwd_mac
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x868] */
name|struct
name|al_ec_msw
name|msw
decl_stmt|;
comment|/* [0xae8] */
name|struct
name|al_ec_tso
name|tso
decl_stmt|;
comment|/* [0xb00] */
name|struct
name|al_ec_tso_sel
name|tso_sel
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0xb60] */
name|struct
name|al_ec_tpe
name|tpe
decl_stmt|;
comment|/* [0xb80] */
name|struct
name|al_ec_tpm_udma
name|tpm_udma
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xbc0] */
name|struct
name|al_ec_tpm_sel
name|tpm_sel
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xbf0] */
name|struct
name|al_ec_tfw
name|tfw
decl_stmt|;
comment|/* [0xc00] */
name|struct
name|al_ec_tfw_udma
name|tfw_udma
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xc60] */
name|struct
name|al_ec_tmi
name|tmi
decl_stmt|;
comment|/* [0xcc0] */
name|struct
name|al_ec_efc
name|efc
decl_stmt|;
comment|/* [0xcd0] */
name|struct
name|al_ec_fc_udma
name|fc_udma
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xd00] */
name|struct
name|al_ec_tpg_rpa_res
name|tpg_rpa_res
decl_stmt|;
comment|/* [0xf00] */
name|struct
name|al_ec_eee
name|eee
decl_stmt|;
comment|/* [0x1000] */
name|struct
name|al_ec_stat
name|stat
decl_stmt|;
comment|/* [0x1100] */
name|struct
name|al_ec_stat_udma
name|stat_udma
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x1300] */
name|struct
name|al_ec_msp
name|msp
decl_stmt|;
comment|/* [0x1700] */
name|struct
name|al_ec_msp_p
name|msp_p
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x1740] */
name|struct
name|al_ec_msp_c
name|msp_c
index|[
literal|32
index|]
decl_stmt|;
comment|/* [0x17c0] */
name|uint32_t
name|rsrvd_1
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|al_ec_wol
name|wol
decl_stmt|;
comment|/* [0x1b80] */
name|uint32_t
name|rsrvd_2
index|[
literal|80
index|]
decl_stmt|;
name|struct
name|al_ec_pth
name|pth
decl_stmt|;
comment|/* [0x1d00] */
name|struct
name|al_ec_pth_egress
name|pth_egress
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x1d80] */
name|struct
name|al_ec_pth_db
name|pth_db
index|[
literal|16
index|]
decl_stmt|;
comment|/* [0x1e80] */
name|uint32_t
name|rsrvd_3
index|[
literal|416
index|]
decl_stmt|;
name|struct
name|al_ec_gen_v3
name|gen_v3
decl_stmt|;
comment|/* [0x2680] */
name|struct
name|al_ec_tfw_v3
name|tfw_v3
decl_stmt|;
comment|/* [0x26c0] */
name|struct
name|al_ec_rfw_v3
name|rfw_v3
decl_stmt|;
comment|/* [0x2740] */
name|struct
name|al_ec_crypto
name|crypto
decl_stmt|;
comment|/* [0x2840] */
name|struct
name|al_ec_crypto_perf_cntr
name|crypto_perf_cntr
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x28c0] */
name|uint32_t
name|rsrvd_4
index|[
literal|48
index|]
decl_stmt|;
name|struct
name|al_ec_crypto_tx_tid
name|crypto_tx_tid
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x2a00] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** version register ****/
comment|/* Revision number (Minor) */
define|#
directive|define
name|EC_GEN_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|EC_GEN_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/* Revision number (Major) */
define|#
directive|define
name|EC_GEN_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|EC_GEN_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/* Day of release */
define|#
directive|define
name|EC_GEN_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|EC_GEN_VERSION_DATE_DAY_SHIFT
value|16
comment|/* Month of release */
define|#
directive|define
name|EC_GEN_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|EC_GEN_VERSION_DATA_MONTH_SHIFT
value|21
comment|/* Year of release (starting from 2000) */
define|#
directive|define
name|EC_GEN_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|EC_GEN_VERSION_DATE_YEAR_SHIFT
value|25
comment|/* Reserved */
define|#
directive|define
name|EC_GEN_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|EC_GEN_VERSION_RESERVED_SHIFT
value|30
comment|/**** en register ****/
comment|/* Enable Frequency adjust FIFO input controller operation. */
define|#
directive|define
name|EC_GEN_EN_FAF_IN
value|(1<< 0)
comment|/* Enable Frequency adjust FIFO output controller operation. */
define|#
directive|define
name|EC_GEN_EN_FAF_OUT
value|(1<< 1)
comment|/* Enable Rx FIFO input controller 1 operation. */
define|#
directive|define
name|EC_GEN_EN_RXF_IN
value|(1<< 2)
comment|/* Enable Rx FIFO output controller  operation. */
define|#
directive|define
name|EC_GEN_EN_RXF_OUT
value|(1<< 3)
comment|/* Enable Rx forwarding input controller operation. */
define|#
directive|define
name|EC_GEN_EN_RFW_IN
value|(1<< 4)
comment|/* Enable Rx forwarding output controller operation. */
define|#
directive|define
name|EC_GEN_EN_RFW_OUT
value|(1<< 5)
comment|/* Enable Rx multi-stream write controller operation. */
define|#
directive|define
name|EC_GEN_EN_MSW_IN
value|(1<< 6)
comment|/* Enable Rx first parsing engine output operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_1_OUT
value|(1<< 7)
comment|/* Enable Rx first parsing engine input operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_1_IN
value|(1<< 8)
comment|/* Enable Rx second parsing engine output operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_2_OUT
value|(1<< 9)
comment|/* Enable Rx second parsing engine input operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_2_IN
value|(1<< 10)
comment|/* Enable Rx MACsec parsing engine output operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_3_OUT
value|(1<< 11)
comment|/* Enable Rx MACsec parsing engine input operation. */
define|#
directive|define
name|EC_GEN_EN_RPE_3_IN
value|(1<< 12)
comment|/* Enable Loopback FIFO input controller 1 operation. */
define|#
directive|define
name|EC_GEN_EN_LBF_IN
value|(1<< 13)
comment|/* Enable Rx packet analyzer operation. */
define|#
directive|define
name|EC_GEN_EN_RPA
value|(1<< 14)
define|#
directive|define
name|EC_GEN_EN_RESERVED_15
value|(1<< 15)
comment|/* Enable Tx stream interface operation. */
define|#
directive|define
name|EC_GEN_EN_TSO
value|(1<< 16)
comment|/* Enable Tx parser input controller operation. */
define|#
directive|define
name|EC_GEN_EN_TPE_IN
value|(1<< 17)
comment|/* Enable Tx parser output controller operation. */
define|#
directive|define
name|EC_GEN_EN_TPE_OUT
value|(1<< 18)
comment|/* Enable Tx packet modification operation. */
define|#
directive|define
name|EC_GEN_EN_TPM
value|(1<< 19)
comment|/* Enable Tx forwarding input controller operation. */
define|#
directive|define
name|EC_GEN_EN_TFW_IN
value|(1<< 20)
comment|/* Enable Tx forwarding output controller operation. */
define|#
directive|define
name|EC_GEN_EN_TFW_OUT
value|(1<< 21)
comment|/* Enable Tx MAC interface controller operation. */
define|#
directive|define
name|EC_GEN_EN_TMI
value|(1<< 22)
comment|/* Enable Tx packet generator operation. */
define|#
directive|define
name|EC_GEN_EN_TPG
value|(1<< 23)
define|#
directive|define
name|EC_GEN_EN_RESERVED_31_MASK
value|0xFF000000
define|#
directive|define
name|EC_GEN_EN_RESERVED_31_SHIFT
value|24
comment|/**** fifo_en register ****/
comment|/* Enable Frequency adjust FIFO operation (input). */
define|#
directive|define
name|EC_GEN_FIFO_EN_FAF_IN
value|(1<< 0)
comment|/* Enable Frequency adjust FIFO operation (output). */
define|#
directive|define
name|EC_GEN_FIFO_EN_FAF_OUT
value|(1<< 1)
comment|/* Enable Rx FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_RX_FIFO
value|(1<< 2)
comment|/* Enable Rx forwarding FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_RFW_FIFO
value|(1<< 3)
comment|/* Enable Rx multi-stream write FIFO operation */
define|#
directive|define
name|EC_GEN_FIFO_EN_MSW_FIFO
value|(1<< 4)
comment|/* Enable Rx first parser FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_RPE_1_FIFO
value|(1<< 5)
comment|/* Enable Rx second parser FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_RPE_2_FIFO
value|(1<< 6)
comment|/* Enable Rx MACsec parser FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_RPE_3_FIFO
value|(1<< 7)
comment|/* Enable Loopback FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_LB_FIFO
value|(1<< 8)
define|#
directive|define
name|EC_GEN_FIFO_EN_RESERVED_15_9_MASK
value|0x0000FE00
define|#
directive|define
name|EC_GEN_FIFO_EN_RESERVED_15_9_SHIFT
value|9
comment|/* Enable Tx parser FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_TPE_FIFO
value|(1<< 16)
comment|/* Enable Tx forwarding FIFO operation. */
define|#
directive|define
name|EC_GEN_FIFO_EN_TFW_FIFO
value|(1<< 17)
define|#
directive|define
name|EC_GEN_FIFO_EN_RESERVED_31_18_MASK
value|0xFFFC0000
define|#
directive|define
name|EC_GEN_FIFO_EN_RESERVED_31_18_SHIFT
value|18
comment|/**** l2 register ****/
comment|/* Size of a 802.3 Ethernet header (DA+SA) */
define|#
directive|define
name|EC_GEN_L2_SIZE_802_3_MASK
value|0x0000003F
define|#
directive|define
name|EC_GEN_L2_SIZE_802_3_SHIFT
value|0
comment|/* Size of a 802.3 + MACsec 8 byte header */
define|#
directive|define
name|EC_GEN_L2_SIZE_802_3_MS_8_MASK
value|0x00003F00
define|#
directive|define
name|EC_GEN_L2_SIZE_802_3_MS_8_SHIFT
value|8
comment|/* Offset of the L2 header from the beginning of the packet. */
define|#
directive|define
name|EC_GEN_L2_OFFSET_MASK
value|0x7F000000
define|#
directive|define
name|EC_GEN_L2_OFFSET_SHIFT
value|24
comment|/**** cfg_i register ****/
comment|/* IPv4 protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_IPV4_INDEX_MASK
value|0x0000001F
define|#
directive|define
name|EC_GEN_CFG_I_IPV4_INDEX_SHIFT
value|0
comment|/* IPv6 protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_IPV6_INDEX_MASK
value|0x000003E0
define|#
directive|define
name|EC_GEN_CFG_I_IPV6_INDEX_SHIFT
value|5
comment|/* TCP protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_TCP_INDEX_MASK
value|0x00007C00
define|#
directive|define
name|EC_GEN_CFG_I_TCP_INDEX_SHIFT
value|10
comment|/* UDP protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_UDP_INDEX_MASK
value|0x000F8000
define|#
directive|define
name|EC_GEN_CFG_I_UDP_INDEX_SHIFT
value|15
comment|/* MACsec with 8 bytes SecTAG */
define|#
directive|define
name|EC_GEN_CFG_I_MACSEC_8_INDEX_MASK
value|0x01F00000
define|#
directive|define
name|EC_GEN_CFG_I_MACSEC_8_INDEX_SHIFT
value|20
comment|/* MACsec with 16 bytes SecTAG */
define|#
directive|define
name|EC_GEN_CFG_I_MACSEC_16_INDEX_MASK
value|0x3E000000
define|#
directive|define
name|EC_GEN_CFG_I_MACSEC_16_INDEX_SHIFT
value|25
comment|/**** cfg_i_ext register ****/
comment|/* FcoE protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_EXT_FCOE_INDEX_MASK
value|0x0000001F
define|#
directive|define
name|EC_GEN_CFG_I_EXT_FCOE_INDEX_SHIFT
value|0
comment|/* RoCE protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L3_1_MASK
value|0x000003E0
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L3_1_SHIFT
value|5
comment|/* RoCE protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L3_2_MASK
value|0x00007C00
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L3_2_SHIFT
value|10
comment|/* RoCE protocol index */
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L4_MASK
value|0x000F8000
define|#
directive|define
name|EC_GEN_CFG_I_EXT_ROCE_INDEX_L4_SHIFT
value|15
comment|/**** en_ext register ****/
comment|/* Enable Usage of Ethernet port memories for testing */
define|#
directive|define
name|EC_GEN_EN_EXT_MEM_FOR_TEST_MASK
value|0x0000000F
define|#
directive|define
name|EC_GEN_EN_EXT_MEM_FOR_TEST_SHIFT
value|0
define|#
directive|define
name|EC_GEN_EN_EXT_MEM_FOR_TEST_VAL_EN
define|\
value|(0xa<< EC_GEN_EN_EXT_MEM_FOR_TEST_SHIFT)
define|#
directive|define
name|EC_GEN_EN_EXT_MEM_FOR_TEST_VAL_DIS
define|\
value|(0x0<< EC_GEN_EN_EXT_MEM_FOR_TEST_SHIFT)
comment|/* Enable MAC loop back (Rx --> Tx, after MAC layer) for 802 */
define|#
directive|define
name|EC_GEN_EN_EXT_MAC_LB
value|(1<< 4)
comment|/* CRC forward value for the MAC Tx when working in loopback mod ... */
define|#
directive|define
name|EC_GEN_EN_EXT_MAC_LB_CRC_FWD
value|(1<< 5)
comment|/* Ready signal configuration when in loopback mode:00 - Ready f ... */
define|#
directive|define
name|EC_GEN_EN_EXT_MAC_LB_READY_CFG_MASK
value|0x000000C0
define|#
directive|define
name|EC_GEN_EN_EXT_MAC_LB_READY_CFG_SHIFT
value|6
comment|/* Bypass the PTH completion update. */
define|#
directive|define
name|EC_GEN_EN_EXT_PTH_COMPLETION_BYPASS
value|(1<< 16)
comment|/* Selection between the 1G and 10G MAC: 0 - 1G 1 - 10G */
define|#
directive|define
name|EC_GEN_EN_EXT_PTH_1_10_SEL
value|(1<< 17)
comment|/* avoid timestamping every pkt in 1G */
define|#
directive|define
name|EC_GEN_EN_EXT_PTH_CFG_1G_TIMESTAMP_OPT
value|(1<< 18)
comment|/* Selection between descriptor caching options (WORD selection) ... */
define|#
directive|define
name|EC_GEN_EN_EXT_CACHE_WORD_SPLIT
value|(1<< 20)
comment|/**** gen register ****/
comment|/* Enable swap of input byte order */
define|#
directive|define
name|EC_MAC_GEN_SWAP_IN_BYTE
value|(1<< 0)
comment|/**** min_pkt register ****/
comment|/* Minimum packet size  */
define|#
directive|define
name|EC_MAC_MIN_PKT_SIZE_MASK
value|0x000FFFFF
define|#
directive|define
name|EC_MAC_MIN_PKT_SIZE_SHIFT
value|0
comment|/**** max_pkt register ****/
comment|/* Maximum packet size  */
define|#
directive|define
name|EC_MAC_MAX_PKT_SIZE_MASK
value|0x000FFFFF
define|#
directive|define
name|EC_MAC_MAX_PKT_SIZE_SHIFT
value|0
comment|/**** cfg_1 register ****/
comment|/* Drop packet at the ingress0 - Packets are not dropped at the  ... */
define|#
directive|define
name|EC_RXF_CFG_1_DROP_AT_INGRESS
value|(1<< 0)
comment|/* Accept packet criteria at start of packet indication */
define|#
directive|define
name|EC_RXF_CFG_1_SOP_ACCEPT
value|(1<< 1)
comment|/* Select the arbiter between Rx packets and Tx packets (packets ... */
define|#
directive|define
name|EC_RXF_CFG_1_ARB_SEL
value|(1<< 2)
comment|/* Arbiter priority when strict priority is selected in arb_sel0 ... */
define|#
directive|define
name|EC_RXF_CFG_1_ARB_P
value|(1<< 3)
comment|/* Force loopback operation */
define|#
directive|define
name|EC_RXF_CFG_1_FORCE_LB
value|(1<< 4)
comment|/* Forwarding selection between Rx path and/or packet analyzer */
define|#
directive|define
name|EC_RXF_CFG_1_FWD_SEL_MASK
value|0x00000300
define|#
directive|define
name|EC_RXF_CFG_1_FWD_SEL_SHIFT
value|8
comment|/**** cfg_2 register ****/
comment|/* FIFO USED threshold for accepting new packets, low threshold  ... */
define|#
directive|define
name|EC_RXF_CFG_2_FIFO_USED_TH_L_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RXF_CFG_2_FIFO_USED_TH_L_SHIFT
value|0
comment|/* FIFO USED threshold for accepting new packets, high threshold ... */
define|#
directive|define
name|EC_RXF_CFG_2_FIFO_USED_TH_H_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RXF_CFG_2_FIFO_USED_TH_H_SHIFT
value|16
comment|/**** rd_fifo register ****/
comment|/* Minimum number of entries in the data FIFO to start reading p ... */
define|#
directive|define
name|EC_RXF_RD_FIFO_TH_DATA_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RXF_RD_FIFO_TH_DATA_SHIFT
value|0
comment|/* Enable cut through operation */
define|#
directive|define
name|EC_RXF_RD_FIFO_EN_CUT_TH
value|(1<< 16)
comment|/**** wr_fifo register ****/
define|#
directive|define
name|EC_RXF_WR_FIFO_TH_DATA_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RXF_WR_FIFO_TH_DATA_SHIFT
value|0
define|#
directive|define
name|EC_RXF_WR_FIFO_TH_INFO_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RXF_WR_FIFO_TH_INFO_SHIFT
value|16
comment|/**** lb_fifo register ****/
define|#
directive|define
name|EC_RXF_LB_FIFO_TH_DATA_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RXF_LB_FIFO_TH_DATA_SHIFT
value|0
define|#
directive|define
name|EC_RXF_LB_FIFO_TH_INFO_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RXF_LB_FIFO_TH_INFO_SHIFT
value|16
comment|/**** cfg_lb register ****/
comment|/* FIFO USED threshold for accepting new packets */
define|#
directive|define
name|EC_RXF_CFG_LB_FIFO_USED_TH_INT_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RXF_CFG_LB_FIFO_USED_TH_INT_SHIFT
value|0
comment|/* FIFO USED threshold for generating ready for the Tx path */
define|#
directive|define
name|EC_RXF_CFG_LB_FIFO_USED_TH_EXT_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RXF_CFG_LB_FIFO_USED_TH_EXT_SHIFT
value|16
comment|/**** out_drop register ****/
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_ERR
value|(1<< 0)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_COL
value|(1<< 1)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_DEC
value|(1<< 2)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_LEN
value|(1<< 3)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_PHY
value|(1<< 4)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_FIFO
value|(1<< 5)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_FCS
value|(1<< 6)
define|#
directive|define
name|EC_RXF_OUT_DROP_MAC_ETYPE
value|(1<< 7)
define|#
directive|define
name|EC_RXF_OUT_DROP_EC_LEN
value|(1<< 8)
define|#
directive|define
name|EC_RXF_OUT_DROP_EC_FIFO
value|(1<< 9)
comment|/**** parse_cfg register ****/
comment|/* MAX number of beats for packet parsing */
define|#
directive|define
name|EC_EPE_PARSE_CFG_MAX_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|EC_EPE_PARSE_CFG_MAX_BEATS_SHIFT
value|0
comment|/* MAX number of parsing iterations for packet parsing */
define|#
directive|define
name|EC_EPE_PARSE_CFG_MAX_ITER_MASK
value|0x0000FF00
define|#
directive|define
name|EC_EPE_PARSE_CFG_MAX_ITER_SHIFT
value|8
comment|/**** act_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_EPE_ACT_TABLE_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_EPE_ACT_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** act_table_data_1 register ****/
comment|/* Table data[5:0] - Offset to next protocol [bytes][6] - Next p ... */
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_1_VAL_MASK
value|0x03FFFFFF
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_1_VAL_SHIFT
value|0
comment|/**** act_table_data_2 register ****/
comment|/* Table Data [8:0] - Offset to data in the packet [bits][17:9]  ... */
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_2_VAL_MASK
value|0x1FFFFFFF
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_2_VAL_SHIFT
value|0
comment|/**** act_table_data_3 register ****/
comment|/* Table Data  [8:0] - Offset to data in the packet [bits] [17:9 ... */
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_3_VAL_MASK
value|0x1FFFFFFF
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_3_VAL_SHIFT
value|0
comment|/**** act_table_data_4 register ****/
comment|/* Table data[7:0] - Offset to header length location in the pac ... */
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_4_VAL_MASK
value|0x0FFFFFFF
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_4_VAL_SHIFT
value|0
comment|/**** act_table_data_6 register ****/
comment|/* Table data[0] - WR header length[10:1] - Write header length  ... */
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_6_VAL_MASK
value|0x007FFFFF
define|#
directive|define
name|EC_EPE_ACT_TABLE_DATA_6_VAL_SHIFT
value|0
comment|/**** res_in register ****/
comment|/* Selector for input parse_en0 - Input vector1 - Default value  ... */
define|#
directive|define
name|EC_EPE_RES_IN_SEL_PARSE_EN
value|(1<< 0)
comment|/* Selector for input protocol_index 0 - Input vector 1 - Defaul ... */
define|#
directive|define
name|EC_EPE_RES_IN_SEL_PROT_INDEX
value|(1<< 1)
comment|/* Selector for input hdr_offset 0 - Input vector 1 - Default va ... */
define|#
directive|define
name|EC_EPE_RES_IN_SEL_HDR_OFFSET
value|(1<< 2)
comment|/**** p1 register ****/
comment|/* Location of the input protocol index in the parser result vec ... */
define|#
directive|define
name|EC_EPE_RES_P1_IN_PROT_INDEX_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P1_IN_PROT_INDEX_SHIFT
value|0
comment|/**** p2 register ****/
comment|/* Location of the input offset in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P2_IN_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P2_IN_OFFSET_SHIFT
value|0
comment|/**** p3 register ****/
comment|/* Location of the input parse enable in the parser result vecto ... */
define|#
directive|define
name|EC_EPE_RES_P3_IN_PARSE_EN_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P3_IN_PARSE_EN_SHIFT
value|0
comment|/**** p4 register ****/
comment|/* Location of the control bits in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P4_CTRL_BITS_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P4_CTRL_BITS_SHIFT
value|0
comment|/**** p5 register ****/
comment|/* Location of the MAC DA in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P5_DA_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P5_DA_SHIFT
value|0
comment|/**** p6 register ****/
comment|/* Location of the MAC SA in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P6_SA_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P6_SA_SHIFT
value|0
comment|/**** p7 register ****/
comment|/* Location of the first VLAN in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P7_VLAN_1_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P7_VLAN_1_SHIFT
value|0
comment|/**** p8 register ****/
comment|/* Location of the second VLAN in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P8_VLAN_2_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P8_VLAN_2_SHIFT
value|0
comment|/**** p9 register ****/
comment|/* Location of the L3 protocol index in the parser result vector ... */
define|#
directive|define
name|EC_EPE_RES_P9_L3_PROT_INDEX_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P9_L3_PROT_INDEX_SHIFT
value|0
comment|/**** p10 register ****/
comment|/* Location of the L3 offset in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P10_L3_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P10_L3_OFFSET_SHIFT
value|0
comment|/**** p11 register ****/
comment|/* Location of the L3 SIP in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P11_L3_SIP_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P11_L3_SIP_SHIFT
value|0
comment|/**** p12 register ****/
comment|/* Location of the L3 DIP in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P12_L3_DIP_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P12_L3_DIP_SHIFT
value|0
comment|/**** p13 register ****/
comment|/* Location of the L3 priority in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P13_L3_PRIORITY_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P13_L3_PRIORITY_SHIFT
value|0
comment|/**** p14 register ****/
comment|/* Location of the L3 header length in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P14_L3_HDR_LEN_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P14_L3_HDR_LEN_SHIFT
value|0
comment|/**** p15 register ****/
comment|/* Location of the L4 protocol index in the parser result vector ... */
define|#
directive|define
name|EC_EPE_RES_P15_L4_PROT_INDEX_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P15_L4_PROT_INDEX_SHIFT
value|0
comment|/**** p16 register ****/
comment|/* Location of the L4 source port in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P16_L4_SRC_PORT_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P16_L4_SRC_PORT_SHIFT
value|0
comment|/**** p17 register ****/
comment|/* Location of the L4 destination port in the parser result vect ... */
define|#
directive|define
name|EC_EPE_RES_P17_L4_DST_PORT_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P17_L4_DST_PORT_SHIFT
value|0
comment|/**** p18 register ****/
comment|/* Location of the L4 offset in the parser result vector */
define|#
directive|define
name|EC_EPE_RES_P18_L4_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P18_L4_OFFSET_SHIFT
value|0
comment|/**** p19 register ****/
comment|/* Location of the Ether type in the parser result vector when w ... */
define|#
directive|define
name|EC_EPE_RES_P19_WOL_ETYPE_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P19_WOL_ETYPE_SHIFT
value|0
comment|/**** p20 register ****/
comment|/* Location of the RoCE QP number field in the parser result vec ... */
define|#
directive|define
name|EC_EPE_RES_P20_ROCE_QPN_MASK
value|0x000003FF
define|#
directive|define
name|EC_EPE_RES_P20_ROCE_QPN_SHIFT
value|0
comment|/**** hdr_len register ****/
comment|/* Value for selecting table 1 */
define|#
directive|define
name|EC_EPE_H_HDR_LEN_TABLE_1_MASK
value|0x000000FF
define|#
directive|define
name|EC_EPE_H_HDR_LEN_TABLE_1_SHIFT
value|0
comment|/* Value for selecting table 2 */
define|#
directive|define
name|EC_EPE_H_HDR_LEN_TABLE_2_MASK
value|0x00FF0000
define|#
directive|define
name|EC_EPE_H_HDR_LEN_TABLE_2_SHIFT
value|16
comment|/**** comp_data register ****/
comment|/* Data 1 for comparison */
define|#
directive|define
name|EC_EPE_P_COMP_DATA_DATA_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_EPE_P_COMP_DATA_DATA_1_SHIFT
value|0
comment|/* Data 2 for comparison [18:16] - Stage [24:19] - Branch ID */
define|#
directive|define
name|EC_EPE_P_COMP_DATA_DATA_2_MASK
value|0x01FF0000
define|#
directive|define
name|EC_EPE_P_COMP_DATA_DATA_2_SHIFT
value|16
comment|/**** comp_mask register ****/
comment|/* Data 1 for comparison */
define|#
directive|define
name|EC_EPE_P_COMP_MASK_DATA_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_EPE_P_COMP_MASK_DATA_1_SHIFT
value|0
comment|/* Data 2 for comparison [18:16] - Stage [24:19] - Branch ID */
define|#
directive|define
name|EC_EPE_P_COMP_MASK_DATA_2_MASK
value|0x01FF0000
define|#
directive|define
name|EC_EPE_P_COMP_MASK_DATA_2_SHIFT
value|16
comment|/**** comp_ctrl register ****/
comment|/* Output result value */
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_RES_MASK
value|0x0000001F
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_RES_SHIFT
value|0
comment|/* Compare command for the data_1 field00 - Compare01 -<=10 -> ... */
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_CMD_1_MASK
value|0x00030000
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_CMD_1_SHIFT
value|16
comment|/* Compare command for the data_2 field 00 - Compare 01 -<= 10  ... */
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_CMD_2_MASK
value|0x000C0000
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_CMD_2_SHIFT
value|18
comment|/* Entry is valid */
define|#
directive|define
name|EC_EPE_P_COMP_CTRL_VALID
value|(1<< 31)
comment|/**** prot_act register ****/
comment|/* Drop indication for the selected protocol index */
define|#
directive|define
name|EC_EPE_A_PROT_ACT_DROP
value|(1<< 0)
comment|/* Mapping value Used when mapping the entire protocol index ran ... */
define|#
directive|define
name|EC_EPE_A_PROT_ACT_MAP_MASK
value|0x00000F00
define|#
directive|define
name|EC_EPE_A_PROT_ACT_MAP_SHIFT
value|8
comment|/**** thash_cfg_1 register ****/
comment|/* Hash function output selection:000 - [7:0]001 - [15:8]010 - [ ... */
define|#
directive|define
name|EC_RFW_THASH_CFG_1_OUT_SEL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_THASH_CFG_1_OUT_SEL_SHIFT
value|0
comment|/* Selects between hash functions00 - toeplitz01 - CRC-3210 - 0x ... */
define|#
directive|define
name|EC_RFW_THASH_CFG_1_FUNC_SEL_MASK
value|0x00000300
define|#
directive|define
name|EC_RFW_THASH_CFG_1_FUNC_SEL_SHIFT
value|8
comment|/* Enable SIP/DIP swap if SIP<DIP */
define|#
directive|define
name|EC_RFW_THASH_CFG_1_ENABLE_IP_SWAP
value|(1<< 16)
comment|/* Enable PORT swap if SPORT<DPORT */
define|#
directive|define
name|EC_RFW_THASH_CFG_1_ENABLE_PORT_SWAP
value|(1<< 17)
comment|/**** mhash_cfg_1 register ****/
comment|/* Hash function output selection:000 - [7:0]001 - [15:8]010 - [ ... */
define|#
directive|define
name|EC_RFW_MHASH_CFG_1_OUT_SEL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_MHASH_CFG_1_OUT_SEL_SHIFT
value|0
comment|/* Selects the input to the MAC hash function0 - DA1 - DA + SA ... */
define|#
directive|define
name|EC_RFW_MHASH_CFG_1_INPUT_SEL
value|(1<< 4)
comment|/* Selects between hash functions00 - toeplitz01 - CRC-3210 - 0x ... */
define|#
directive|define
name|EC_RFW_MHASH_CFG_1_FUNC_SEL_MASK
value|0x00000300
define|#
directive|define
name|EC_RFW_MHASH_CFG_1_FUNC_SEL_SHIFT
value|8
comment|/**** hdr_split register ****/
comment|/* Default header length for header split */
define|#
directive|define
name|EC_RFW_HDR_SPLIT_DEF_LEN_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_HDR_SPLIT_DEF_LEN_SHIFT
value|0
comment|/* Enable header split operation */
define|#
directive|define
name|EC_RFW_HDR_SPLIT_EN
value|(1<< 16)
comment|/**** meta_err register ****/
comment|/* Mask for error 1 in the Rx descriptor */
define|#
directive|define
name|EC_RFW_META_ERR_MASK_1_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_META_ERR_MASK_1_SHIFT
value|0
comment|/* Mask for error 2 in the Rx descriptor */
define|#
directive|define
name|EC_RFW_META_ERR_MASK_2_MASK
value|0x03FF0000
define|#
directive|define
name|EC_RFW_META_ERR_MASK_2_SHIFT
value|16
comment|/**** meta register ****/
comment|/* Selection of the L3 offset source: 1 - Inner packet 0 - Outer ... */
define|#
directive|define
name|EC_RFW_META_L3_LEN_SEL
value|(1<< 0)
comment|/* Selection of the L3 offset source:1 - Inner packet0 - Outer p ... */
define|#
directive|define
name|EC_RFW_META_L3_OFFSET_SEL
value|(1<< 1)
comment|/* Selection of the l3 protocol index source: 1 - Inner packet 0 ... */
define|#
directive|define
name|EC_RFW_META_L3_PROT_SEL
value|(1<< 2)
comment|/* Selection of the l4 protocol index source:  1 - Inner packet  ... */
define|#
directive|define
name|EC_RFW_META_L4_PROT_SEL
value|(1<< 3)
comment|/* Selects how to calculate the L3 header length when L3 is IpPv ... */
define|#
directive|define
name|EC_RFW_META_L3_LEN_CALC
value|(1<< 4)
comment|/* Selection of the IPv4 fragment indication source:  1 - Inner  ... */
define|#
directive|define
name|EC_RFW_META_FRAG_SEL
value|(1<< 5)
comment|/* Selection of the L4 offset source:1 - Inner packet0 - Outer p ... */
define|#
directive|define
name|EC_RFW_META_L4_OFFSET_SEL
value|(1<< 6)
comment|/**** filter register ****/
comment|/* Filter undetected MAC DA */
define|#
directive|define
name|EC_RFW_FILTER_UNDET_MAC
value|(1<< 0)
comment|/* Filter specific MAC DA based on MAC table output. */
define|#
directive|define
name|EC_RFW_FILTER_DET_MAC
value|(1<< 1)
comment|/* Filter all tagged. */
define|#
directive|define
name|EC_RFW_FILTER_TAGGED
value|(1<< 2)
comment|/* Filter all untagged. */
define|#
directive|define
name|EC_RFW_FILTER_UNTAGGED
value|(1<< 3)
comment|/* Filter all broadcast. */
define|#
directive|define
name|EC_RFW_FILTER_BC
value|(1<< 4)
comment|/* Filter all multicast. */
define|#
directive|define
name|EC_RFW_FILTER_MC
value|(1<< 5)
comment|/* Filter based on parsing output (used to drop selected protoco ... */
define|#
directive|define
name|EC_RFW_FILTER_PARSE
value|(1<< 6)
comment|/* Filter packet based on VLAN table output. */
define|#
directive|define
name|EC_RFW_FILTER_VLAN_VID
value|(1<< 7)
comment|/* Filter packet based on control table output. */
define|#
directive|define
name|EC_RFW_FILTER_CTRL_TABLE
value|(1<< 8)
comment|/* Filter packet based on protocol index action register. */
define|#
directive|define
name|EC_RFW_FILTER_PROT_INDEX
value|(1<< 9)
comment|/* Filter packet based on WoL decision */
define|#
directive|define
name|EC_RFW_FILTER_WOL
value|(1<< 10)
comment|/* Override filter decision and forward to default UDMA/queue;dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_UNDET_MAC
value|(1<< 16)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_DET_MAC
value|(1<< 17)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_TAGGED
value|(1<< 18)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_UNTAGGED
value|(1<< 19)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_BC
value|(1<< 20)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_MC
value|(1<< 21)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_PARSE
value|(1<< 22)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_VLAN_VID
value|(1<< 23)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_CTRL_TABLE
value|(1<< 24)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_PROT_INDEX
value|(1<< 25)
comment|/* Override filter decision and forward to default UDMA/queue;Dr ... */
define|#
directive|define
name|EC_RFW_FILTER_OR_WOL
value|(1<< 26)
comment|/**** thash_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_THASH_TABLE_ADDR_VAL_MASK
value|0x000000FF
define|#
directive|define
name|EC_RFW_THASH_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** thash_table_data register ****/
comment|/* Table data (valid only after configuring the table address re ... */
define|#
directive|define
name|EC_RFW_THASH_TABLE_DATA_VAL_MASK
value|0x00003FFF
define|#
directive|define
name|EC_RFW_THASH_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** mhash_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_MHASH_TABLE_ADDR_VAL_MASK
value|0x000000FF
define|#
directive|define
name|EC_RFW_MHASH_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** mhash_table_data register ****/
comment|/* Table data (valid only after configuring the table address re ... */
define|#
directive|define
name|EC_RFW_MHASH_TABLE_DATA_VAL_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_MHASH_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** vid_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_VID_TABLE_ADDR_VAL_MASK
value|0x00000FFF
define|#
directive|define
name|EC_RFW_VID_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** vid_table_data register ****/
comment|/* Table data (valid only after configuring the table address re ... */
define|#
directive|define
name|EC_RFW_VID_TABLE_DATA_VAL_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_VID_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** pbits_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_PBITS_TABLE_ADDR_VAL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_PBITS_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** pbits_table_data register ****/
comment|/* VLAN P-bits to internal priority mapping */
define|#
directive|define
name|EC_RFW_PBITS_TABLE_DATA_VAL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_PBITS_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** dscp_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_DSCP_TABLE_ADDR_VAL_MASK
value|0x000000FF
define|#
directive|define
name|EC_RFW_DSCP_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** dscp_table_data register ****/
comment|/* IPv4 DSCP to internal priority mapping */
define|#
directive|define
name|EC_RFW_DSCP_TABLE_DATA_VAL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_DSCP_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** tc_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_RFW_TC_TABLE_ADDR_VAL_MASK
value|0x000000FF
define|#
directive|define
name|EC_RFW_TC_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** tc_table_data register ****/
comment|/* IPv6 TC to internal priority mapping */
define|#
directive|define
name|EC_RFW_TC_TABLE_DATA_VAL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_TC_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** ctrl_table_addr register ****/
comment|/* Address for accessing the table[0] - VLAN table control out[1 ... */
define|#
directive|define
name|EC_RFW_CTRL_TABLE_ADDR_VAL_MASK
value|0x000007FF
define|#
directive|define
name|EC_RFW_CTRL_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** ctrl_table_data register ****/
comment|/* Control table output for selecting the forwarding MUXs[3:0] - ... */
define|#
directive|define
name|EC_RFW_CTRL_TABLE_DATA_VAL_MASK
value|0x000FFFFF
define|#
directive|define
name|EC_RFW_CTRL_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** out_cfg register ****/
comment|/* Number of MetaData at the end of the packet1 - One MetaData b ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_META_CNT_MASK
value|0x00000003
define|#
directive|define
name|EC_RFW_OUT_CFG_META_CNT_SHIFT
value|0
comment|/* Enable packet drop */
define|#
directive|define
name|EC_RFW_OUT_CFG_DROP_EN
value|(1<< 2)
comment|/* Swap output byte order */
define|#
directive|define
name|EC_RFW_OUT_CFG_SWAP_OUT_BYTE
value|(1<< 3)
comment|/* Enable the insertion of the MACsec decoding result into the M ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_EN_MACSEC_DEC
value|(1<< 4)
comment|/* Sample time of the time stamp:0 - SOP (for 10G MAC)1 - EOP (f ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_TIMESTAMP_SAMPLE
value|(1<< 5)
comment|/* Determines which queue to write into the packet header0 - Ori ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_QUEUE_OR_SEL
value|(1<< 6)
comment|/* Determines the logic of the drop indication:0 - Sample the dr ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_DROP_LOGIC_SEL
value|(1<< 7)
comment|/* Determines the logic of the drop indication:0 - Sample the dr ... */
define|#
directive|define
name|EC_RFW_OUT_CFG_PKT_TYPE_DEF
value|(1<< 8)
comment|/**** fsm_table_addr register ****/
comment|/* Address for accessing the table :[2:0] - Outer header control ... */
define|#
directive|define
name|EC_RFW_FSM_TABLE_ADDR_VAL_MASK
value|0x0000007F
define|#
directive|define
name|EC_RFW_FSM_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** fsm_table_data register ****/
comment|/* Flow steering mechanism output selectors:[1:0] - Input select ... */
define|#
directive|define
name|EC_RFW_FSM_TABLE_DATA_VAL_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_FSM_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** ctrl_sel register ****/
comment|/* Packet type (UC/MC/BC) for the control table */
define|#
directive|define
name|EC_RFW_CTRL_SEL_PKT_TYPE
value|(1<< 0)
comment|/* L3 protocol index for the control table */
define|#
directive|define
name|EC_RFW_CTRL_SEL_L3_PROTOCOL
value|(1<< 1)
comment|/* Selects the content and structure of the control table addres ... */
define|#
directive|define
name|EC_RFW_CTRL_SEL_ADDR_MASK
value|0x0000000C
define|#
directive|define
name|EC_RFW_CTRL_SEL_ADDR_SHIFT
value|2
comment|/**** default_vlan register ****/
comment|/* Default VLAN data, used for untagged packets */
define|#
directive|define
name|EC_RFW_DEFAULT_VLAN_DATA_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_DEFAULT_VLAN_DATA_SHIFT
value|0
comment|/**** default_hash register ****/
comment|/* Default UDMA */
define|#
directive|define
name|EC_RFW_DEFAULT_HASH_UDMA_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_DEFAULT_HASH_UDMA_SHIFT
value|0
comment|/* Default queue */
define|#
directive|define
name|EC_RFW_DEFAULT_HASH_QUEUE_MASK
value|0x00030000
define|#
directive|define
name|EC_RFW_DEFAULT_HASH_QUEUE_SHIFT
value|16
comment|/**** default_or register ****/
comment|/* Default UDMA */
define|#
directive|define
name|EC_RFW_DEFAULT_OR_UDMA_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_DEFAULT_OR_UDMA_SHIFT
value|0
comment|/* Default queue */
define|#
directive|define
name|EC_RFW_DEFAULT_OR_QUEUE_MASK
value|0x00030000
define|#
directive|define
name|EC_RFW_DEFAULT_OR_QUEUE_SHIFT
value|16
comment|/**** checksum register ****/
comment|/* Check that the length in the UDP header matches the length in ... */
define|#
directive|define
name|EC_RFW_CHECKSUM_UDP_LEN
value|(1<< 0)
comment|/* Select the header that will be used for the checksum when a t ... */
define|#
directive|define
name|EC_RFW_CHECKSUM_HDR_SEL
value|(1<< 1)
comment|/* Enable L4 checksum when L3 fragmentation is detected */
define|#
directive|define
name|EC_RFW_CHECKSUM_L4_FRAG_EN
value|(1<< 2)
comment|/* L3 Checksum result selection for the Metadata descriptor0 - O ... */
define|#
directive|define
name|EC_RFW_CHECKSUM_L3_CKS_SEL
value|(1<< 4)
comment|/* L4 Checksum result selection for the Metadata descriptor0 - O ... */
define|#
directive|define
name|EC_RFW_CHECKSUM_L4_CKS_SEL
value|(1<< 5)
comment|/**** lro_cfg_1 register ****/
comment|/* Select the header that will be used for the LRO offload engin ... */
define|#
directive|define
name|EC_RFW_LRO_CFG_1_HDR_SEL
value|(1<< 0)
comment|/* Select the L2 header that will be used for the LRO offload en ... */
define|#
directive|define
name|EC_RFW_LRO_CFG_1_HDR_L2_SEL
value|(1<< 1)
comment|/**** lro_check_ipv4 register ****/
comment|/* Check version field. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_VER
value|(1<< 0)
comment|/* Check IHL field == 5. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_IHL_0
value|(1<< 1)
comment|/* Check IHL field>= 5. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_IHL_1
value|(1<< 2)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_IHL_2
value|(1<< 3)
comment|/* Compare DSCP to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_DSCP
value|(1<< 4)
comment|/* Check that Total length>= lro_ipv4_tlen_val. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_TLEN
value|(1<< 5)
comment|/* Compare to previous packet value +1. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_ID
value|(1<< 6)
comment|/* Compare to lro_ipv4_flags_val with lro_ipv4_flags_mask_0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_FLAGS_0
value|(1<< 7)
comment|/* Compare to previous packet flags with lro_ipv4_flags_mask_1. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_FLAGS_1
value|(1<< 8)
comment|/* Verify that the fragment offset field is 0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_FRAG
value|(1<< 9)
comment|/* Verify that the TTL value>0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_TTL_0
value|(1<< 10)
comment|/* Compare TTL value to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_TTL_1
value|(1<< 11)
comment|/* Compare to previous packet protocol field. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_PROT_0
value|(1<< 12)
comment|/* Verify that the protocol is TCP or UDP. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_PROT_1
value|(1<< 13)
comment|/* Verify that the check sum is correct. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_CHECKSUM
value|(1<< 14)
comment|/* Compare SIP to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_SIP
value|(1<< 15)
comment|/* Compare DIP to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV4_DIP
value|(1<< 16)
comment|/**** lro_ipv4 register ****/
comment|/* Total length minimum value */
define|#
directive|define
name|EC_RFW_LRO_IPV4_TLEN_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_LRO_IPV4_TLEN_VAL_SHIFT
value|0
comment|/* Flags value  */
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_VAL_MASK
value|0x00070000
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_VAL_SHIFT
value|16
comment|/* Flags mask */
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_MASK_0_MASK
value|0x00380000
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_MASK_0_SHIFT
value|19
comment|/* Flags mask */
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_MASK_1_MASK
value|0x01C00000
define|#
directive|define
name|EC_RFW_LRO_IPV4_FLAGS_MASK_1_SHIFT
value|22
comment|/* Version value */
define|#
directive|define
name|EC_RFW_LRO_IPV4_VER_MASK
value|0xF0000000
define|#
directive|define
name|EC_RFW_LRO_IPV4_VER_SHIFT
value|28
comment|/**** lro_check_ipv6 register ****/
comment|/* Check version field */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_VER
value|(1<< 0)
comment|/* Compare TC to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_TC
value|(1<< 1)
comment|/* Compare flow label field to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_FLOW
value|(1<< 2)
comment|/* Check that Total length>= lro_ipv6_pen_val. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_PLEN
value|(1<< 3)
comment|/* Compare to previous packet next header field. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_NEXT_0
value|(1<< 4)
comment|/* Verify that the next header is TCP or UDP. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_NEXT_1
value|(1<< 5)
comment|/* Verify that hop limit is>0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_HOP_0
value|(1<< 6)
comment|/* Compare hop limit to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_HOP_1
value|(1<< 7)
comment|/* Compare SIP to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_SIP
value|(1<< 8)
comment|/* Compare DIP to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_IPV6_DIP
value|(1<< 9)
comment|/**** lro_ipv6 register ****/
comment|/* Payload length minimum value */
define|#
directive|define
name|EC_RFW_LRO_IPV6_PLEN_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_LRO_IPV6_PLEN_VAL_SHIFT
value|0
comment|/* Version value */
define|#
directive|define
name|EC_RFW_LRO_IPV6_VER_MASK
value|0x0F000000
define|#
directive|define
name|EC_RFW_LRO_IPV6_VER_SHIFT
value|24
comment|/**** lro_check_tcp register ****/
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_SRC_PORT
value|(1<< 0)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_DST_PORT
value|(1<< 1)
comment|/* If (SYN == 1), don't check  */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_SN
value|(1<< 2)
comment|/* Check data offset field == 5. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_OFFSET_0
value|(1<< 3)
comment|/* Check data offset field>= 5. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_OFFSET_1
value|(1<< 4)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_OFFSET_2
value|(1<< 5)
comment|/* Compare reserved field to lro_tcp_res. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_RES
value|(1<< 6)
comment|/* Compare to lro_tcp_ecn_val and lro_tcp_ecn_mask_0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_ECN_0
value|(1<< 7)
comment|/* Compare to previous packet ECN field with lro_tcp_ecn_mask_1 */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_ECN_1
value|(1<< 8)
comment|/* Compare to lro_tcp_ctrl_val and lro_tcp_ctrl_mask_0. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_CTRL_0
value|(1<< 9)
comment|/* Compare to previous packet ECN field with lro_tcp_ctrl_mask_1 */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_CTRL_1
value|(1<< 10)
comment|/* Verify that check sum is correct. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_TCP_CHECKSUM
value|(1<< 11)
comment|/**** lro_tcp register ****/
comment|/* Reserved field default value */
define|#
directive|define
name|EC_RFW_LRO_TCP_RES_MASK
value|0x00000007
define|#
directive|define
name|EC_RFW_LRO_TCP_RES_SHIFT
value|0
comment|/* ECN field value */
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_VAL_MASK
value|0x00000038
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_VAL_SHIFT
value|3
comment|/* ECN field mask */
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_MASK_0_MASK
value|0x000001C0
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_MASK_0_SHIFT
value|6
comment|/* ECN field mask */
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_MASK_1_MASK
value|0x00000E00
define|#
directive|define
name|EC_RFW_LRO_TCP_ECN_MASK_1_SHIFT
value|9
comment|/* Control field value */
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_VAL_MASK
value|0x0003F000
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_VAL_SHIFT
value|12
comment|/* Control field mask */
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_MASK_0_MASK
value|0x00FC0000
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_MASK_0_SHIFT
value|18
comment|/* Control field mask */
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_MASK_1_MASK
value|0x3F000000
define|#
directive|define
name|EC_RFW_LRO_TCP_CTRL_MASK_1_SHIFT
value|24
comment|/**** lro_check_udp register ****/
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_UDP_SRC_PORT
value|(1<< 0)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_UDP_DST_PORT
value|(1<< 1)
comment|/* Verify that check sum is correct. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_UDP_CHECKSUM
value|(1<< 2)
comment|/**** lro_check_l2 register ****/
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_MAC_DA
value|(1<< 0)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_MAC_SA
value|(1<< 1)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_1_EXIST
value|(1<< 2)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_1_VID
value|(1<< 3)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_1_CFI
value|(1<< 4)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_1_PBITS
value|(1<< 5)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_2_EXIST
value|(1<< 6)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_2_VID
value|(1<< 7)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_2_CFI
value|(1<< 8)
comment|/* Compare to previous packet. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_VLAN_2_PBITS
value|(1<< 9)
comment|/* Verify that the FCS is correct. */
define|#
directive|define
name|EC_RFW_LRO_CHECK_L2_FCS
value|(1<< 10)
comment|/**** lro_check_gen register ****/
comment|/* Compare to previous packet */
define|#
directive|define
name|EC_RFW_LRO_CHECK_GEN_UDMA
value|(1<< 0)
comment|/* Compare to previous packet */
define|#
directive|define
name|EC_RFW_LRO_CHECK_GEN_QUEUE
value|(1<< 1)
comment|/**** lro_store register ****/
comment|/* Store packet information if protocol match. */
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV4
value|(1<< 0)
comment|/* Store packet information if protocol match. */
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV6
value|(1<< 1)
comment|/* Store packet information if protocol match. */
define|#
directive|define
name|EC_RFW_LRO_STORE_TCP
value|(1<< 2)
comment|/* Store packet information if protocol match. */
define|#
directive|define
name|EC_RFW_LRO_STORE_UDP
value|(1<< 3)
comment|/* Store packet if IPv4 flags match the register value with mask */
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV4_FLAGS_VAL_MASK
value|0x00000070
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV4_FLAGS_VAL_SHIFT
value|4
comment|/* Mask for IPv4 flags */
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV4_FLAGS_MASK_MASK
value|0x00000380
define|#
directive|define
name|EC_RFW_LRO_STORE_IPV4_FLAGS_MASK_SHIFT
value|7
comment|/* Store packet if TCP control and ECN match the register value  ... */
define|#
directive|define
name|EC_RFW_LRO_STORE_TCP_CTRL_VAL_MASK
value|0x0007FC00
define|#
directive|define
name|EC_RFW_LRO_STORE_TCP_CTRL_VAL_SHIFT
value|10
comment|/* Mask for TCP control */
define|#
directive|define
name|EC_RFW_LRO_STORE_TCP_CTRL_MASK_MASK
value|0x0FF80000
define|#
directive|define
name|EC_RFW_LRO_STORE_TCP_CTRL_MASK_SHIFT
value|19
comment|/**** vid_table_def register ****/
comment|/* Table default data (valid only after configuring the table ad ... */
define|#
directive|define
name|EC_RFW_VID_TABLE_DEF_VAL_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_VID_TABLE_DEF_VAL_SHIFT
value|0
comment|/* Default data selection 0 - Default value 1 - Table data out */
define|#
directive|define
name|EC_RFW_VID_TABLE_DEF_SEL
value|(1<< 6)
comment|/**** ctrl_table_def register ****/
comment|/* Control table output for selecting the forwarding MUXs [3:0]  ... */
define|#
directive|define
name|EC_RFW_CTRL_TABLE_DEF_VAL_MASK
value|0x000FFFFF
define|#
directive|define
name|EC_RFW_CTRL_TABLE_DEF_VAL_SHIFT
value|0
comment|/* Default data selection 0 - Default value 1 - Table data out ... */
define|#
directive|define
name|EC_RFW_CTRL_TABLE_DEF_SEL
value|(1<< 20)
comment|/**** cfg_a_0 register ****/
comment|/* Selection of the L3 checksum result in the Metadata00 - L3 ch ... */
define|#
directive|define
name|EC_RFW_CFG_A_0_META_L3_CHK_RES_SEL_MASK
value|0x00000003
define|#
directive|define
name|EC_RFW_CFG_A_0_META_L3_CHK_RES_SEL_SHIFT
value|0
comment|/* Selection of the L4 checksum result in the Metadata0 - L4 che ... */
define|#
directive|define
name|EC_RFW_CFG_A_0_META_L4_CHK_RES_SEL
value|(1<< 2)
comment|/* Selection of the LRO_context_value result in the Metadata0 -  ... */
define|#
directive|define
name|EC_RFW_CFG_A_0_LRO_CONTEXT_SEL
value|(1<< 4)
comment|/**** thash_cfg_3 register ****/
comment|/* Enable Hash value for RoCE packets in outer packet. */
define|#
directive|define
name|EC_RFW_THASH_CFG_3_ENABLE_OUTER_ROCE
value|(1<< 0)
comment|/* Enable Hash value for RoCE packets in inner packet. */
define|#
directive|define
name|EC_RFW_THASH_CFG_3_ENABLE_INNER_ROCE
value|(1<< 1)
comment|/* Enable Hash value for FcoE packets in outer packet. */
define|#
directive|define
name|EC_RFW_THASH_CFG_3_ENABLE_OUTER_FCOE
value|(1<< 2)
comment|/* Enable Hash value for FcoE packets in inner packet. */
define|#
directive|define
name|EC_RFW_THASH_CFG_3_ENABLE_INNER_FCOE
value|(1<< 3)
comment|/**** thash_mask_outer_ipv6 register ****/
comment|/* IPv6 source IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV6_SRC_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV6_SRC_SHIFT
value|0
comment|/* IPv6 destination IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV6_DST_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV6_DST_SHIFT
value|16
comment|/**** thash_mask_outer register ****/
comment|/* IPv4 source IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV4_SRC_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV4_SRC_SHIFT
value|0
comment|/* IPv4 destination IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV4_DST_MASK
value|0x000000F0
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_IPV4_DST_SHIFT
value|4
comment|/* TCP source port */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_TCP_SRC_PORT_MASK
value|0x00000300
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_TCP_SRC_PORT_SHIFT
value|8
comment|/* TCP destination port */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_TCP_DST_PORT_MASK
value|0x00000C00
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_TCP_DST_PORT_SHIFT
value|10
comment|/* UDP source port */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_UDP_SRC_PORT_MASK
value|0x00003000
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_UDP_SRC_PORT_SHIFT
value|12
comment|/* UDP destination port */
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_UDP_DST_PORT_MASK
value|0x0000C000
define|#
directive|define
name|EC_RFW_THASH_MASK_OUTER_UDP_DST_PORT_SHIFT
value|14
comment|/**** thash_mask_inner_ipv6 register ****/
comment|/* IPv6 source IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV6_SRC_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV6_SRC_SHIFT
value|0
comment|/* IPv6 destination IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV6_DST_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV6_DST_SHIFT
value|16
comment|/**** thash_mask_inner register ****/
comment|/* IPv4 source IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV4_SRC_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV4_SRC_SHIFT
value|0
comment|/* IPv4 destination IP address */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV4_DST_MASK
value|0x000000F0
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_IPV4_DST_SHIFT
value|4
comment|/* TCP source port */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_TCP_SRC_PORT_MASK
value|0x00000300
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_TCP_SRC_PORT_SHIFT
value|8
comment|/* TCP destination port */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_TCP_DST_PORT_MASK
value|0x00000C00
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_TCP_DST_PORT_SHIFT
value|10
comment|/* UDP source port */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_UDP_SRC_PORT_MASK
value|0x00003000
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_UDP_SRC_PORT_SHIFT
value|12
comment|/* UDP destination port */
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_UDP_DST_PORT_MASK
value|0x0000C000
define|#
directive|define
name|EC_RFW_THASH_MASK_INNER_UDP_DST_PORT_SHIFT
value|14
comment|/**** def_cfg register ****/
comment|/* Number of padding bytes to add at the beginning of each Ether ... */
define|#
directive|define
name|EC_RFW_UDMA_DEF_CFG_RX_PAD_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_UDMA_DEF_CFG_RX_PAD_SHIFT
value|0
comment|/**** queue register ****/
comment|/* Mapping between priority and queue number */
define|#
directive|define
name|EC_RFW_PRIORITY_QUEUE_MAP_MASK
value|0x00000003
define|#
directive|define
name|EC_RFW_PRIORITY_QUEUE_MAP_SHIFT
value|0
comment|/**** opt_1 register ****/
comment|/* Default UDMA for forwarding  */
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_UDMA_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_UDMA_SHIFT
value|0
comment|/* Default priority for forwarding */
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_PRIORITY_MASK
value|0x00000700
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_PRIORITY_SHIFT
value|8
comment|/* Default queue for forwarding */
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_QUEUE_MASK
value|0x00030000
define|#
directive|define
name|EC_RFW_DEFAULT_OPT_1_QUEUE_SHIFT
value|16
comment|/**** data_h register ****/
comment|/* MAC address data  */
define|#
directive|define
name|EC_FWD_MAC_DATA_H_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_FWD_MAC_DATA_H_VAL_SHIFT
value|0
comment|/**** mask_h register ****/
comment|/* MAC address mask  */
define|#
directive|define
name|EC_FWD_MAC_MASK_H_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_FWD_MAC_MASK_H_VAL_SHIFT
value|0
comment|/**** ctrl register ****/
comment|/* Control value for Rx forwarding engine[0] - Drop indication[2 ... */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_MASK
value|0x000001FF
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_SHIFT
value|0
comment|/* Drop indication */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_DROP
value|(1<< 0)
comment|/* control table command input */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_CTRL_CMD_MASK
value|0x00000006
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_CTRL_CMD_SHIFT
value|1
comment|/* UDMA selection */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_UDMA_MASK
value|0x000000078
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_UDMA_SHIFT
value|3
comment|/* queue number */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_QID_MASK
value|0x00000180
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VAL_QID_SHIFT
value|7
comment|/* Entry is valid for Rx forwarding engine. */
define|#
directive|define
name|EC_FWD_MAC_CTRL_RX_VALID
value|(1<< 15)
comment|/* Control value for Tx forwarding engine */
define|#
directive|define
name|EC_FWD_MAC_CTRL_TX_VAL_MASK
value|0x001F0000
define|#
directive|define
name|EC_FWD_MAC_CTRL_TX_VAL_SHIFT
value|16
comment|/* Entry is valid for Tx forwarding engine. */
define|#
directive|define
name|EC_FWD_MAC_CTRL_TX_VALID
value|(1<< 31)
comment|/**** uc register ****/
comment|/* timer max value for waiting for a stream to be ready to accep ... */
define|#
directive|define
name|EC_MSW_UC_TIMER_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_MSW_UC_TIMER_SHIFT
value|0
comment|/* Drop packet if target queue in the UDMA is full */
define|#
directive|define
name|EC_MSW_UC_Q_FULL_DROP_MASK
value|0x000F0000
define|#
directive|define
name|EC_MSW_UC_Q_FULL_DROP_SHIFT
value|16
comment|/* Drop packet if timer expires. */
define|#
directive|define
name|EC_MSW_UC_TIMER_DROP_MASK
value|0x0F000000
define|#
directive|define
name|EC_MSW_UC_TIMER_DROP_SHIFT
value|24
comment|/**** mc register ****/
comment|/* Timer max value for waiting for a stream to be ready to accep ... */
define|#
directive|define
name|EC_MSW_MC_TIMER_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_MSW_MC_TIMER_SHIFT
value|0
comment|/* Drop packet if target queue in UDMA is full. */
define|#
directive|define
name|EC_MSW_MC_Q_FULL_DROP_MASK
value|0x000F0000
define|#
directive|define
name|EC_MSW_MC_Q_FULL_DROP_SHIFT
value|16
comment|/* Drop packet if timer expires. */
define|#
directive|define
name|EC_MSW_MC_TIMER_DROP_MASK
value|0x0F000000
define|#
directive|define
name|EC_MSW_MC_TIMER_DROP_SHIFT
value|24
comment|/**** bc register ****/
comment|/* Timer max value for waiting for a stream to be ready to accep ... */
define|#
directive|define
name|EC_MSW_BC_TIMER_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_MSW_BC_TIMER_SHIFT
value|0
comment|/* Drop packet if target queue in UDMA is full. */
define|#
directive|define
name|EC_MSW_BC_Q_FULL_DROP_MASK
value|0x000F0000
define|#
directive|define
name|EC_MSW_BC_Q_FULL_DROP_SHIFT
value|16
comment|/* Drop packet if timer expires. */
define|#
directive|define
name|EC_MSW_BC_TIMER_DROP_MASK
value|0x0F000000
define|#
directive|define
name|EC_MSW_BC_TIMER_DROP_SHIFT
value|24
comment|/**** in_cfg register ****/
comment|/* Swap input bytes order */
define|#
directive|define
name|EC_TSO_IN_CFG_SWAP_BYTES
value|(1<< 0)
comment|/* Selects strict priority or round robin scheduling between GDM ... */
define|#
directive|define
name|EC_TSO_IN_CFG_SEL_SP_RR
value|(1<< 1)
comment|/* Selects scheduler numbering direction */
define|#
directive|define
name|EC_TSO_IN_CFG_SEL_SCH_DIR
value|(1<< 2)
comment|/* Minimum L2 packet size (not including FCS) */
define|#
directive|define
name|EC_TSO_IN_CFG_L2_MIN_SIZE_MASK
value|0x00007F00
define|#
directive|define
name|EC_TSO_IN_CFG_L2_MIN_SIZE_SHIFT
value|8
comment|/* Swap input bytes order */
define|#
directive|define
name|EC_TSO_IN_CFG_SP_INIT_VAL_MASK
value|0x000F0000
define|#
directive|define
name|EC_TSO_IN_CFG_SP_INIT_VAL_SHIFT
value|16
comment|/**** cache_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_TSO_CACHE_TABLE_ADDR_VAL_MASK
value|0x0000000F
define|#
directive|define
name|EC_TSO_CACHE_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** ctrl_first register ****/
comment|/* Data to be written into the control BIS. */
define|#
directive|define
name|EC_TSO_CTRL_FIRST_DATA_MASK
value|0x000001FF
define|#
directive|define
name|EC_TSO_CTRL_FIRST_DATA_SHIFT
value|0
comment|/* Mask for control bits */
define|#
directive|define
name|EC_TSO_CTRL_FIRST_MASK_MASK
value|0x01FF0000
define|#
directive|define
name|EC_TSO_CTRL_FIRST_MASK_SHIFT
value|16
comment|/**** ctrl_middle register ****/
comment|/* Data to be written into the control BIS. */
define|#
directive|define
name|EC_TSO_CTRL_MIDDLE_DATA_MASK
value|0x000001FF
define|#
directive|define
name|EC_TSO_CTRL_MIDDLE_DATA_SHIFT
value|0
comment|/* Mask for the control bits */
define|#
directive|define
name|EC_TSO_CTRL_MIDDLE_MASK_MASK
value|0x01FF0000
define|#
directive|define
name|EC_TSO_CTRL_MIDDLE_MASK_SHIFT
value|16
comment|/**** ctrl_last register ****/
comment|/* Data to be written into the control BIS. */
define|#
directive|define
name|EC_TSO_CTRL_LAST_DATA_MASK
value|0x000001FF
define|#
directive|define
name|EC_TSO_CTRL_LAST_DATA_SHIFT
value|0
comment|/* Mask for the control bits */
define|#
directive|define
name|EC_TSO_CTRL_LAST_MASK_MASK
value|0x01FF0000
define|#
directive|define
name|EC_TSO_CTRL_LAST_MASK_SHIFT
value|16
comment|/**** cfg_add_0 register ****/
comment|/* MSS selection option:0 - MSS value is selected using MSS_sel  ... */
define|#
directive|define
name|EC_TSO_CFG_ADD_0_MSS_SEL
value|(1<< 0)
comment|/**** cfg_tunnel register ****/
comment|/* Enable TSO with tunnelling */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_TUNNEL_TSO
value|(1<< 0)
comment|/* Enable outer UDP checksum update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_UDP_CHKSUM
value|(1<< 8)
comment|/* Enable outer UDP length update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_UDP_LEN
value|(1<< 9)
comment|/* Enable outer Ip6  length update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_IPV6_PLEN
value|(1<< 10)
comment|/* Enable outer IPv4 checksum update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_IPV4_CHKSUM
value|(1<< 11)
comment|/* Enable outer IPv4 Identification update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_IPV4_IDEN
value|(1<< 12)
comment|/* Enable outer IPv4 length update */
define|#
directive|define
name|EC_TSO_CFG_TUNNEL_EN_IPV4_TLEN
value|(1<< 13)
comment|/**** mss register ****/
comment|/* MSS value */
define|#
directive|define
name|EC_TSO_SEL_MSS_VAL_MASK
value|0x000FFFFF
define|#
directive|define
name|EC_TSO_SEL_MSS_VAL_SHIFT
value|0
comment|/**** parse register ****/
comment|/* Max number of bus beats for parsing */
define|#
directive|define
name|EC_TPE_PARSE_MAX_BEATS_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TPE_PARSE_MAX_BEATS_SHIFT
value|0
comment|/**** vlan_data register ****/
comment|/* UDMA default VLAN 1 data */
define|#
directive|define
name|EC_TPM_UDMA_VLAN_DATA_DEF_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TPM_UDMA_VLAN_DATA_DEF_1_SHIFT
value|0
comment|/* UDMA default VLAN 2 data */
define|#
directive|define
name|EC_TPM_UDMA_VLAN_DATA_DEF_2_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_TPM_UDMA_VLAN_DATA_DEF_2_SHIFT
value|16
comment|/**** mac_sa_2 register ****/
comment|/* MAC source address data [47:32] */
define|#
directive|define
name|EC_TPM_UDMA_MAC_SA_2_H_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TPM_UDMA_MAC_SA_2_H_VAL_SHIFT
value|0
comment|/* Drop indication for MAC SA spoofing0 â Don't drop */
define|#
directive|define
name|EC_TPM_UDMA_MAC_SA_2_DROP
value|(1<< 16)
comment|/* Replace indication for MAC SA spoofing 0 - Don't replace */
define|#
directive|define
name|EC_TPM_UDMA_MAC_SA_2_REPLACE
value|(1<< 17)
comment|/**** etype register ****/
comment|/* Ether type value  */
define|#
directive|define
name|EC_TPM_SEL_ETYPE_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TPM_SEL_ETYPE_VAL_SHIFT
value|0
comment|/**** tx_wr_fifo register ****/
comment|/* Max data beats that can be used in the Tx FIFO */
define|#
directive|define
name|EC_TFW_TX_WR_FIFO_DATA_TH_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TFW_TX_WR_FIFO_DATA_TH_SHIFT
value|0
comment|/* Max packets that can be stored in the Tx FIFO */
define|#
directive|define
name|EC_TFW_TX_WR_FIFO_INFO_TH_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_TFW_TX_WR_FIFO_INFO_TH_SHIFT
value|16
comment|/**** tx_vid_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_TFW_TX_VID_TABLE_ADDR_VAL_MASK
value|0x00000FFF
define|#
directive|define
name|EC_TFW_TX_VID_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** tx_vid_table_data register ****/
comment|/* Table data (valid only after configuring the table address re ... */
define|#
directive|define
name|EC_TFW_TX_VID_TABLE_DATA_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_TX_VID_TABLE_DATA_VAL_SHIFT
value|0
comment|/**** tx_rd_fifo register ****/
comment|/* Read data threshold when cut through mode is enabled. */
define|#
directive|define
name|EC_TFW_TX_RD_FIFO_READ_TH_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TFW_TX_RD_FIFO_READ_TH_SHIFT
value|0
comment|/* Enable cut through operation of the Tx FIFO. */
define|#
directive|define
name|EC_TFW_TX_RD_FIFO_EN_CUT_THROUGH
value|(1<< 16)
comment|/**** tx_checksum register ****/
comment|/* Enable L3 checksum insertion. */
define|#
directive|define
name|EC_TFW_TX_CHECKSUM_L3_EN
value|(1<< 0)
comment|/* Enable L4 checksum insertion. */
define|#
directive|define
name|EC_TFW_TX_CHECKSUM_L4_EN
value|(1<< 1)
comment|/* Enable L4 checksum when L3 fragmentation is detected. */
define|#
directive|define
name|EC_TFW_TX_CHECKSUM_L4_FRAG_EN
value|(1<< 2)
comment|/**** tx_gen register ****/
comment|/* Force forward of all Tx packets to MAC. */
define|#
directive|define
name|EC_TFW_TX_GEN_FWD_ALL_TO_MAC
value|(1<< 0)
comment|/* Select the Packet generator as the source of Tx packets0 - Tx ... */
define|#
directive|define
name|EC_TFW_TX_GEN_SELECT_PKT_GEN
value|(1<< 1)
comment|/**** tx_spf register ****/
comment|/* Select the VID for spoofing check:[0] - Packet VID[1] - Forwa ... */
define|#
directive|define
name|EC_TFW_TX_SPF_VID_SEL
value|(1<< 0)
comment|/**** data_fifo register ****/
comment|/* FIFO used value (number of entries) */
define|#
directive|define
name|EC_TFW_DATA_FIFO_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TFW_DATA_FIFO_USED_SHIFT
value|0
comment|/* FIFO FULL status */
define|#
directive|define
name|EC_TFW_DATA_FIFO_FULL
value|(1<< 16)
comment|/* FIFO EMPTY status */
define|#
directive|define
name|EC_TFW_DATA_FIFO_EMPTY
value|(1<< 17)
comment|/**** ctrl_fifo register ****/
comment|/* FIFO used value (number of entries) */
define|#
directive|define
name|EC_TFW_CTRL_FIFO_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TFW_CTRL_FIFO_USED_SHIFT
value|0
comment|/* FIFO FULL status */
define|#
directive|define
name|EC_TFW_CTRL_FIFO_FULL
value|(1<< 16)
comment|/* FIFO EMPTY status */
define|#
directive|define
name|EC_TFW_CTRL_FIFO_EMPTY
value|(1<< 17)
comment|/**** hdr_fifo register ****/
comment|/* FIFO used value (number of entries) */
define|#
directive|define
name|EC_TFW_HDR_FIFO_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_TFW_HDR_FIFO_USED_SHIFT
value|0
comment|/* FIFO FULL status */
define|#
directive|define
name|EC_TFW_HDR_FIFO_FULL
value|(1<< 16)
comment|/* FIFO EMPTY status */
define|#
directive|define
name|EC_TFW_HDR_FIFO_EMPTY
value|(1<< 17)
comment|/**** uc_udma register ****/
comment|/* Default UDMA bitmap (MSB represents physical port) */
define|#
directive|define
name|EC_TFW_UDMA_UC_UDMA_DEF_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_UDMA_UC_UDMA_DEF_SHIFT
value|0
comment|/**** mc_udma register ****/
comment|/* Default UDMA bitmap (MSB represents physical port.) */
define|#
directive|define
name|EC_TFW_UDMA_MC_UDMA_DEF_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_UDMA_MC_UDMA_DEF_SHIFT
value|0
comment|/**** bc_udma register ****/
comment|/* Default UDMA bitmap (MSB represents physical port.) */
define|#
directive|define
name|EC_TFW_UDMA_BC_UDMA_DEF_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_UDMA_BC_UDMA_DEF_SHIFT
value|0
comment|/**** spf_cmd register ****/
comment|/* Command for the VLAN spoofing00 â Ignore  mismatch */
define|#
directive|define
name|EC_TFW_UDMA_SPF_CMD_VID_MASK
value|0x00000003
define|#
directive|define
name|EC_TFW_UDMA_SPF_CMD_VID_SHIFT
value|0
comment|/* Command for VLAN spoofing 00 - Ignore  mismatch */
define|#
directive|define
name|EC_TFW_UDMA_SPF_CMD_MAC_MASK
value|0x0000000C
define|#
directive|define
name|EC_TFW_UDMA_SPF_CMD_MAC_SHIFT
value|2
comment|/**** fwd_dec register ****/
comment|/* Forwarding decision control:[0] â Enable internal switch */
define|#
directive|define
name|EC_TFW_UDMA_FWD_DEC_CTRL_MASK
value|0x000003FF
define|#
directive|define
name|EC_TFW_UDMA_FWD_DEC_CTRL_SHIFT
value|0
comment|/**** tx_cfg register ****/
comment|/* Swap output byte order */
define|#
directive|define
name|EC_TMI_TX_CFG_SWAP_BYTES
value|(1<< 0)
comment|/* Enable forwarding to the Rx data path. */
define|#
directive|define
name|EC_TMI_TX_CFG_EN_FWD_TO_RX
value|(1<< 1)
comment|/* Force forwarding all packets to the MAC. */
define|#
directive|define
name|EC_TMI_TX_CFG_FORCE_FWD_MAC
value|(1<< 2)
comment|/* Force forwarding all packets to the MAC. */
define|#
directive|define
name|EC_TMI_TX_CFG_FORCE_FWD_RX
value|(1<< 3)
comment|/* Force loop back operation */
define|#
directive|define
name|EC_TMI_TX_CFG_FORCE_LB
value|(1<< 4)
comment|/**** ec_pause register ****/
comment|/* Mask of pause_on [7:0] */
define|#
directive|define
name|EC_EFC_EC_PAUSE_MASK_MAC_MASK
value|0x000000FF
define|#
directive|define
name|EC_EFC_EC_PAUSE_MASK_MAC_SHIFT
value|0
comment|/* Mask of GPIO input [7:0] */
define|#
directive|define
name|EC_EFC_EC_PAUSE_MASK_GPIO_MASK
value|0x0000FF00
define|#
directive|define
name|EC_EFC_EC_PAUSE_MASK_GPIO_SHIFT
value|8
comment|/**** ec_xoff register ****/
comment|/* Mask 1 for XOFF [7:0] Mask 1 for Almost Full indication, */
define|#
directive|define
name|EC_EFC_EC_XOFF_MASK_1_MASK
value|0x000000FF
define|#
directive|define
name|EC_EFC_EC_XOFF_MASK_1_SHIFT
value|0
comment|/* Mask 2 for XOFF [7:0] Mask 2 for sampled Almost Full indicati ... */
define|#
directive|define
name|EC_EFC_EC_XOFF_MASK_2_MASK
value|0x0000FF00
define|#
directive|define
name|EC_EFC_EC_XOFF_MASK_2_SHIFT
value|8
comment|/**** xon register ****/
comment|/* Mask 1 for generating XON pulse, masking XOFF [0] */
define|#
directive|define
name|EC_EFC_XON_MASK_1
value|(1<< 0)
comment|/* Mask 2 for generating XON pulse, masking Almost Full indicati ... */
define|#
directive|define
name|EC_EFC_XON_MASK_2
value|(1<< 1)
comment|/**** gpio register ****/
comment|/* Mask for generating GPIO output XOFF indication from XOFF[0] */
define|#
directive|define
name|EC_EFC_GPIO_MASK_1
value|(1<< 0)
comment|/**** rx_fifo_af register ****/
comment|/* Threshold */
define|#
directive|define
name|EC_EFC_RX_FIFO_AF_TH_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_EFC_RX_FIFO_AF_TH_SHIFT
value|0
comment|/**** rx_fifo_hyst register ****/
comment|/* Threshold low */
define|#
directive|define
name|EC_EFC_RX_FIFO_HYST_TH_LOW_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_EFC_RX_FIFO_HYST_TH_LOW_SHIFT
value|0
comment|/* Threshold high */
define|#
directive|define
name|EC_EFC_RX_FIFO_HYST_TH_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_EFC_RX_FIFO_HYST_TH_HIGH_SHIFT
value|16
comment|/**** stat register ****/
comment|/* 10G MAC PFC mode, input from the 10 MAC */
define|#
directive|define
name|EC_EFC_STAT_PFC_MODE
value|(1<< 0)
comment|/**** ec_pfc register ****/
comment|/* Force PFC flow control */
define|#
directive|define
name|EC_EFC_EC_PFC_FORCE_MASK
value|0x000000FF
define|#
directive|define
name|EC_EFC_EC_PFC_FORCE_SHIFT
value|0
comment|/**** q_pause_0 register ****/
comment|/* [i] â Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_0_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_0_MASK_SHIFT
value|0
comment|/**** q_pause_1 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_1_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_1_MASK_SHIFT
value|0
comment|/**** q_pause_2 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_2_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_2_MASK_SHIFT
value|0
comment|/**** q_pause_3 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_3_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_3_MASK_SHIFT
value|0
comment|/**** q_pause_4 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_4_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_4_MASK_SHIFT
value|0
comment|/**** q_pause_5 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_5_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_5_MASK_SHIFT
value|0
comment|/**** q_pause_6 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_6_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_6_MASK_SHIFT
value|0
comment|/**** q_pause_7 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_7_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_PAUSE_7_MASK_SHIFT
value|0
comment|/**** q_gpio_0 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_0_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_0_MASK_SHIFT
value|0
comment|/**** q_gpio_1 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_1_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_1_MASK_SHIFT
value|0
comment|/**** q_gpio_2 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_2_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_2_MASK_SHIFT
value|0
comment|/**** q_gpio_3 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_3_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_3_MASK_SHIFT
value|0
comment|/**** q_gpio_4 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_4_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_4_MASK_SHIFT
value|0
comment|/**** q_gpio_5 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_5_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_5_MASK_SHIFT
value|0
comment|/**** q_gpio_6 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_6_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_6_MASK_SHIFT
value|0
comment|/**** q_gpio_7 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_7_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_GPIO_7_MASK_SHIFT
value|0
comment|/**** s_pause register ****/
comment|/* Mask of pause_on [7:0] */
define|#
directive|define
name|EC_FC_UDMA_S_PAUSE_MASK_MAC_MASK
value|0x000000FF
define|#
directive|define
name|EC_FC_UDMA_S_PAUSE_MASK_MAC_SHIFT
value|0
comment|/* Mask of GPIO input  [7:0] */
define|#
directive|define
name|EC_FC_UDMA_S_PAUSE_MASK_GPIO_MASK
value|0x0000FF00
define|#
directive|define
name|EC_FC_UDMA_S_PAUSE_MASK_GPIO_SHIFT
value|8
comment|/**** q_xoff_0 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_0_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_0_MASK_SHIFT
value|0
comment|/**** q_xoff_1 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_1_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_1_MASK_SHIFT
value|0
comment|/**** q_xoff_2 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_2_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_2_MASK_SHIFT
value|0
comment|/**** q_xoff_3 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_3_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_3_MASK_SHIFT
value|0
comment|/**** q_xoff_4 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_4_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_4_MASK_SHIFT
value|0
comment|/**** q_xoff_5 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_5_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_5_MASK_SHIFT
value|0
comment|/**** q_xoff_6 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_6_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_6_MASK_SHIFT
value|0
comment|/**** q_xoff_7 register ****/
comment|/* [i] - Mask for Q[i] */
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_7_MASK_MASK
value|0x0000000F
define|#
directive|define
name|EC_FC_UDMA_Q_XOFF_7_MASK_SHIFT
value|0
comment|/**** cfg_e register ****/
comment|/* Use MAC Tx FIFO empty status for EEE control. */
define|#
directive|define
name|EC_EEE_CFG_E_USE_MAC_TX_FIFO
value|(1<< 0)
comment|/* Use MAC Rx FIFO empty status for EEE control. */
define|#
directive|define
name|EC_EEE_CFG_E_USE_MAC_RX_FIFO
value|(1<< 1)
comment|/* Use Ethernet controller Tx FIFO empty status for EEE control */
define|#
directive|define
name|EC_EEE_CFG_E_USE_EC_TX_FIFO
value|(1<< 2)
comment|/* Use Ethernet controller Rx FIFO empty status for EEE control */
define|#
directive|define
name|EC_EEE_CFG_E_USE_EC_RX_FIFO
value|(1<< 3)
comment|/* Enable Low power signalling. */
define|#
directive|define
name|EC_EEE_CFG_E_ENABLE
value|(1<< 4)
comment|/* Mask output to MAC.  */
define|#
directive|define
name|EC_EEE_CFG_E_MASK_MAC_EEE
value|(1<< 8)
comment|/* Mask output to stop MAC interface. */
define|#
directive|define
name|EC_EEE_CFG_E_MASK_EC_TMI_STOP
value|(1<< 9)
comment|/**** stat_eee register ****/
comment|/* EEE state */
define|#
directive|define
name|EC_EEE_STAT_EEE_STATE_MASK
value|0x0000000F
define|#
directive|define
name|EC_EEE_STAT_EEE_STATE_SHIFT
value|0
comment|/* EEE detected */
define|#
directive|define
name|EC_EEE_STAT_EEE_DET
value|(1<< 4)
comment|/**** p_parse_cfg register ****/
comment|/* MAX number of beats for packet parsing */
define|#
directive|define
name|EC_MSP_P_PARSE_CFG_MAX_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|EC_MSP_P_PARSE_CFG_MAX_BEATS_SHIFT
value|0
comment|/* MAX number of parsing iterations for packet parsing */
define|#
directive|define
name|EC_MSP_P_PARSE_CFG_MAX_ITER_MASK
value|0x0000FF00
define|#
directive|define
name|EC_MSP_P_PARSE_CFG_MAX_ITER_SHIFT
value|8
comment|/**** p_act_table_addr register ****/
comment|/* Address for accessing the table */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** p_act_table_data_1 register ****/
comment|/* Table data[5:0] - Offset to next protocol [bytes] [6] - Next  ... */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_1_VAL_MASK
value|0x03FFFFFF
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_1_VAL_SHIFT
value|0
comment|/**** p_act_table_data_2 register ****/
comment|/* Table data  [8:0] - Offset to data in the packet [bits][17:9] ... */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_2_VAL_MASK
value|0x1FFFFFFF
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_2_VAL_SHIFT
value|0
comment|/**** p_act_table_data_3 register ****/
comment|/* Table data   [8:0] - Offset to data in the packet [bits]  [17 ... */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_3_VAL_MASK
value|0x1FFFFFFF
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_3_VAL_SHIFT
value|0
comment|/**** p_act_table_data_4 register ****/
comment|/* Table data [7:0] - Offset to the header length location in th ... */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_4_VAL_MASK
value|0x0FFFFFFF
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_4_VAL_SHIFT
value|0
comment|/**** p_act_table_data_6 register ****/
comment|/* Table data [0] - Wr header length [10:1] - Write header lengt ... */
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_6_VAL_MASK
value|0x007FFFFF
define|#
directive|define
name|EC_MSP_P_ACT_TABLE_DATA_6_VAL_SHIFT
value|0
comment|/**** p_res_in register ****/
comment|/* Selector for input parse_en 0 - Input vector 1 - Default valu ... */
define|#
directive|define
name|EC_MSP_P_RES_IN_SEL_PARSE_EN
value|(1<< 0)
comment|/* Selector for input protocol_index  0 - Input vector  1 - Defa ... */
define|#
directive|define
name|EC_MSP_P_RES_IN_SEL_PROT_INDEX
value|(1<< 1)
comment|/* Selector for input hdr_offset  0 - Input vector 1 - Default v ... */
define|#
directive|define
name|EC_MSP_P_RES_IN_SEL_HDR_OFFSET
value|(1<< 2)
comment|/**** h_hdr_len register ****/
comment|/* Value for selecting table 1 */
define|#
directive|define
name|EC_MSP_P_H_HDR_LEN_TABLE_1_MASK
value|0x000000FF
define|#
directive|define
name|EC_MSP_P_H_HDR_LEN_TABLE_1_SHIFT
value|0
comment|/* Value for selecting table 2 */
define|#
directive|define
name|EC_MSP_P_H_HDR_LEN_TABLE_2_MASK
value|0x00FF0000
define|#
directive|define
name|EC_MSP_P_H_HDR_LEN_TABLE_2_SHIFT
value|16
comment|/**** p_comp_data register ****/
comment|/* Data 1 for comparison */
define|#
directive|define
name|EC_MSP_C_P_COMP_DATA_DATA_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_MSP_C_P_COMP_DATA_DATA_1_SHIFT
value|0
comment|/* Data 2 for comparison [18:16] - Stage [24:19] - Branch ID */
define|#
directive|define
name|EC_MSP_C_P_COMP_DATA_DATA_2_MASK
value|0x01FF0000
define|#
directive|define
name|EC_MSP_C_P_COMP_DATA_DATA_2_SHIFT
value|16
comment|/**** p_comp_mask register ****/
comment|/* Data 1 for comparison */
define|#
directive|define
name|EC_MSP_C_P_COMP_MASK_DATA_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_MSP_C_P_COMP_MASK_DATA_1_SHIFT
value|0
comment|/* Data 2 for comparison [18:16] - Stage [24:19] - Branch ID */
define|#
directive|define
name|EC_MSP_C_P_COMP_MASK_DATA_2_MASK
value|0x01FF0000
define|#
directive|define
name|EC_MSP_C_P_COMP_MASK_DATA_2_SHIFT
value|16
comment|/**** p_comp_ctrl register ****/
comment|/* Output result value */
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_RES_MASK
value|0x0000001F
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_RES_SHIFT
value|0
comment|/* Compare command for the data_1 field 00 - Compare 01 -<= 10  ... */
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_CMD_1_MASK
value|0x00030000
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_CMD_1_SHIFT
value|16
comment|/* Compare command for the data_2 field 00 - Compare 01 -<= 10  ... */
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_CMD_2_MASK
value|0x000C0000
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_CMD_2_SHIFT
value|18
comment|/* Entry is valid */
define|#
directive|define
name|EC_MSP_C_P_COMP_CTRL_VALID
value|(1<< 31)
comment|/**** wol_en register ****/
comment|/* Interrupt enable WoL MAC DA Unicast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_UNICAST
value|(1<< 0)
comment|/* Interrupt enable WoL L2 Multicast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_MULTICAST
value|(1<< 1)
comment|/* Interrupt enable WoL L2 Broadcast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_BROADCAST
value|(1<< 2)
comment|/* Interrupt enable WoL IPv4 detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_IPV4
value|(1<< 3)
comment|/* Interrupt enable WoL IPv6 detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_IPV6
value|(1<< 4)
comment|/* Interrupt enable WoL EtherType+MAC DA detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_ETHERTYPE_DA
value|(1<< 5)
comment|/* Interrupt enable WoL EtherType+L2 Broadcast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_ETHERTYPE_BC
value|(1<< 6)
comment|/* Interrupt enable WoL parser detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_PARSER
value|(1<< 7)
comment|/* Interrupt enable WoL magic detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_MAGIC
value|(1<< 8)
comment|/* Interrupt enable WoL magic+password detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_INTRPT_EN_MAGIC_PSWD
value|(1<< 9)
comment|/* Forward enable WoL MAC DA Unicast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_UNICAST
value|(1<< 16)
comment|/* Forward enable WoL L2 Multicast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_MULTICAST
value|(1<< 17)
comment|/* Forward enable WoL L2 Broadcast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_BROADCAST
value|(1<< 18)
comment|/* Forward enable WoL IPv4 detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_IPV4
value|(1<< 19)
comment|/* Forward enable WoL IPv6 detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_IPV6
value|(1<< 20)
comment|/* Forward enable WoL EtherType+MAC DA detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_ETHERTYPE_DA
value|(1<< 21)
comment|/* Forward enable WoL EtherType+L2 Broadcast detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_ETHERTYPE_BC
value|(1<< 22)
comment|/* Forward enable WoL parser detected  packet */
define|#
directive|define
name|EC_WOL_WOL_EN_FWRD_EN_PARSER
value|(1<< 23)
comment|/**** magic_pswd_h register ****/
comment|/* Password for magic_password packet detection - bits 47:32 */
define|#
directive|define
name|EC_WOL_MAGIC_PSWD_H_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_WOL_MAGIC_PSWD_H_VAL_SHIFT
value|0
comment|/**** ethertype register ****/
comment|/* Configured EtherType 1 for WoL EtherType_da/EtherType_bc pack ... */
define|#
directive|define
name|EC_WOL_ETHERTYPE_VAL_1_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_WOL_ETHERTYPE_VAL_1_SHIFT
value|0
comment|/* Configured EtherType 2 for WoL EtherType_da/EtherType_bc pack ... */
define|#
directive|define
name|EC_WOL_ETHERTYPE_VAL_2_MASK
value|0xFFFF0000
define|#
directive|define
name|EC_WOL_ETHERTYPE_VAL_2_SHIFT
value|16
define|#
directive|define
name|EC_PTH_SYSTEM_TIME_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_SYSTEM_TIME_SUBSECONDS_LSB_VAL_SHIFT
value|14
define|#
directive|define
name|EC_PTH_CLOCK_PERIOD_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_CLOCK_PERIOD_LSB_VAL_SHIFT
value|14
comment|/**** int_update_ctrl register ****/
comment|/* This field chooses between two methods for SW to update the s ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_UPDATE_TRIG
value|(1<< 0)
comment|/* 3'b000 - Set system time according to the value in {int_updat ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_UPDATE_METHOD_MASK
value|0x0000000E
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_UPDATE_METHOD_SHIFT
value|1
comment|/* 1'b1 - Next update writes to system_time_subseconds1'b0 - Nex ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_SUBSECOND_MASK
value|(1<< 4)
comment|/* 1'b1 - Next update writes to system_time_seconds1'b0 - Next u ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_SECOND_MASK
value|(1<< 5)
comment|/* Enabling / disabling the internal ingress trigger (ingress_tr ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_INT_TRIG_EN
value|(1<< 16)
comment|/* Determines if internal ingress trigger (ingress_trigger #0) s ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_PULSE_LEVEL_N
value|(1<< 17)
comment|/* Internal ingress trigger polarity (ingress_trigger #0)1'b0 -  ... */
define|#
directive|define
name|EC_PTH_INT_UPDATE_CTRL_POLARITY
value|(1<< 18)
comment|/**** int_update_subseconds_lsb register ****/
define|#
directive|define
name|EC_PTH_INT_UPDATE_SUBSECONDS_LSB_RESERVED_13_0_MASK
value|0x00003FFF
define|#
directive|define
name|EC_PTH_INT_UPDATE_SUBSECONDS_LSB_RESERVED_13_0_SHIFT
value|0
define|#
directive|define
name|EC_PTH_INT_UPDATE_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_INT_UPDATE_SUBSECONDS_LSB_VAL_SHIFT
value|14
comment|/* 3'b000 - Set system time according to the value in {int_updat ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_UPDATE_METHOD_MASK
value|0x0000000E
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_UPDATE_METHOD_SHIFT
value|1
comment|/* 1'b1 - next update writes to system_time_subseconds1'b0 - nex ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_SUBSECOND_MASK
value|(1<< 4)
comment|/* 1'b1 - Next update writes to system_time_seconds1'b0 - Next u ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_SECOND_MASK
value|(1<< 5)
comment|/* Enabling / disabling the external ingress triggers (ingress_t ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_EXT_TRIG_EN_MASK
value|0x00001F00
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_EXT_TRIG_EN_SHIFT
value|8
comment|/* Determines if external ingress triggers (ingress_triggers #1- ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_PULSE_LEVEL_N_MASK
value|0x001F0000
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_PULSE_LEVEL_N_SHIFT
value|16
comment|/* bit-field configurations of external ingress trigger polarity ... */
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_POLARITY_MASK
value|0x1F000000
define|#
directive|define
name|EC_PTH_EXT_UPDATE_CTRL_POLARITY_SHIFT
value|24
comment|/**** ext_update_subseconds_lsb register ****/
define|#
directive|define
name|EC_PTH_EXT_UPDATE_SUBSECONDS_LSB_RESERVED_13_0_MASK
value|0x00003FFF
define|#
directive|define
name|EC_PTH_EXT_UPDATE_SUBSECONDS_LSB_RESERVED_13_0_SHIFT
value|0
define|#
directive|define
name|EC_PTH_EXT_UPDATE_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_EXT_UPDATE_SUBSECONDS_LSB_VAL_SHIFT
value|14
define|#
directive|define
name|EC_PTH_READ_COMPENSATION_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_READ_COMPENSATION_SUBSECONDS_LSB_VAL_SHIFT
value|14
define|#
directive|define
name|EC_PTH_INT_WRITE_COMPENSATION_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_INT_WRITE_COMPENSATION_SUBSECONDS_LSB_VAL_SHIFT
value|14
define|#
directive|define
name|EC_PTH_EXT_WRITE_COMPENSATION_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_EXT_WRITE_COMPENSATION_SUBSECONDS_LSB_VAL_SHIFT
value|14
define|#
directive|define
name|EC_PTH_SYNC_COMPENSATION_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_SYNC_COMPENSATION_SUBSECONDS_LSB_VAL_SHIFT
value|14
comment|/**** trigger_ctrl register ****/
comment|/* Enabling / disabling the egress trigger1'b1 - Enabled1'b0 - D ... */
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_EN
value|(1<< 0)
comment|/* Configuration that determines if the egress trigger is a peri ... */
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_PERIODIC
value|(1<< 1)
comment|/* Configuration of egress trigger polarity */
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_POLARITY
value|(1<< 2)
comment|/* If the pulse is marked as periodic (see periodic field), this ... */
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_PERIOD_SUBSEC_MASK
value|0x00FFFFF0
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_PERIOD_SUBSEC_SHIFT
value|4
comment|/* If the pulse is marked as periodic (see periodic field), this ... */
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_PERIOD_SEC_MASK
value|0xFF000000
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_CTRL_PERIOD_SEC_SHIFT
value|24
comment|/**** trigger_subseconds_lsb register ****/
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_SUBSECONDS_LSB_RESERVED_13_0_MASK
value|0x00003FFF
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_SUBSECONDS_LSB_RESERVED_13_0_SHIFT
value|0
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_EGRESS_TRIGGER_SUBSECONDS_LSB_VAL_SHIFT
value|14
comment|/**** pulse_width_subseconds_lsb register ****/
define|#
directive|define
name|EC_PTH_EGRESS_PULSE_WIDTH_SUBSECONDS_LSB_RESERVED_13_0_MASK
value|0x00003FFF
define|#
directive|define
name|EC_PTH_EGRESS_PULSE_WIDTH_SUBSECONDS_LSB_RESERVED_13_0_SHIFT
value|0
define|#
directive|define
name|EC_PTH_EGRESS_PULSE_WIDTH_SUBSECONDS_LSB_VAL_MASK
value|0xFFFFC000
define|#
directive|define
name|EC_PTH_EGRESS_PULSE_WIDTH_SUBSECONDS_LSB_VAL_SHIFT
value|14
comment|/**** qual register ****/
define|#
directive|define
name|EC_PTH_DB_QUAL_TS_VALID
value|(1<< 0)
define|#
directive|define
name|EC_PTH_DB_QUAL_RESERVED_31_1_MASK
value|0xFFFFFFFE
define|#
directive|define
name|EC_PTH_DB_QUAL_RESERVED_31_1_SHIFT
value|1
comment|/**** rx_comp_desc register ****/
comment|/* Selection for word0[13]:0- legacy SR-A01- per generic protoco ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W0_L3_CKS_RES_SEL
value|(1<< 0)
comment|/* Selection for word0[14]:0- legacy SR-A01- per generic protoco ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W0_L4_CKS_RES_SEL
value|(1<< 1)
comment|/* Selection for word3[29]:0-macsec decryption status[13] (legac ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W3_DEC_STAT_13_L4_CKS_RES_SEL
value|(1<< 8)
comment|/* Selection for word3[30]:0-macsec decryption status[14] (legac ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W3_DEC_STAT_14_L3_CKS_RES_SEL
value|(1<< 9)
comment|/* Selection for word3[31]:0-macsec decryption status[15] (legac ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W3_DEC_STAT_15_CRC_RES_SEL
value|(1<< 10)
comment|/* Selection for word 0 [6:5], source VLAN count0- source vlan c ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W0_SRC_VLAN_CNT
value|(1<< 12)
comment|/* Selection for word 0 [4:0], l3 protocol index0-  l3 protocol  ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W0_L3_PROT_INDEX
value|(1<< 13)
comment|/* Selection for word 1 [31:16], lP fragment checksum0-  IP frag ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W1_IP_FRAG_CHECKSUM
value|(1<< 14)
comment|/* Selection for word 2 [15:9], L3 offset0-  LL3 offset1- CRC re ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W2_L3_OFFSET
value|(1<< 15)
comment|/* Selection for word 2 [8:0], tunnel offset0-  tunnel offset1-  ... */
define|#
directive|define
name|EC_GEN_V3_RX_COMP_DESC_W2_TUNNEL_OFFSET
value|(1<< 16)
comment|/**** conf register ****/
comment|/* Valid signal configuration when in loopback mode:00 - valid f ... */
define|#
directive|define
name|EC_GEN_V3_CONF_MAC_LB_EC_OUT_S_VALID_CFG_MASK
value|0x00000003
define|#
directive|define
name|EC_GEN_V3_CONF_MAC_LB_EC_OUT_S_VALID_CFG_SHIFT
value|0
comment|/* Valid signal configuration when in loopback mode:00 â valid f ... */
define|#
directive|define
name|EC_GEN_V3_CONF_MAC_LB_EC_IN_S_VALID_CFG_MASK
value|0x0000000C
define|#
directive|define
name|EC_GEN_V3_CONF_MAC_LB_EC_IN_S_VALID_CFG_SHIFT
value|2
comment|/**** tx_gpd_cam_addr register ****/
comment|/* Cam compare table address */
define|#
directive|define
name|EC_TFW_V3_TX_GPD_CAM_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_V3_TX_GPD_CAM_ADDR_VAL_SHIFT
value|0
comment|/* cam entry is valid */
define|#
directive|define
name|EC_TFW_V3_TX_GPD_CAM_CTRL_VALID
value|(1<< 31)
comment|/**** tx_gcp_legacy register ****/
comment|/* 0-choose parameters from table1- choose legacy crce roce para ... */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_LEGACY_PARAM_SEL
value|(1<< 0)
comment|/**** tx_gcp_table_addr register ****/
comment|/* parametrs table address */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** tx_gcp_table_gen register ****/
comment|/* polynomial selcet 0-crc32(0x104C11DB7) 1-crc32c(0x11EDC6F41) */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_POLY_SEL
value|(1<< 0)
comment|/* Enable bit complement on crc result */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_CRC32_BIT_COMP
value|(1<< 1)
comment|/* Enable bit swap on crc result */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_CRC32_BIT_SWAP
value|(1<< 2)
comment|/* Enable byte swap on crc result */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_CRC32_BYTE_SWAP
value|(1<< 3)
comment|/* Enable bit swap on input data */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_DATA_BIT_SWAP
value|(1<< 4)
comment|/* Enable byte swap on input data */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_DATA_BYTE_SWAP
value|(1<< 5)
comment|/* Number of bytes in trailer which are not part of crc calculat ... */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_TRAIL_SIZE_MASK
value|0x000003C0
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_TRAIL_SIZE_SHIFT
value|6
comment|/* Number of bytes in header which are not part of crc calculati ... */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_HEAD_SIZE_MASK
value|0x00FF0000
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_HEAD_SIZE_SHIFT
value|16
comment|/* corrected offset calculation0- subtract head_size (roce)1- ad ... */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_HEAD_CALC
value|(1<< 24)
comment|/* 0-replace masked bits with 01-replace masked bits with 1 (roc ... */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_GEN_MASK_POLARITY
value|(1<< 25)
comment|/**** tx_gcp_table_res register ****/
comment|/* Not in use */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_RES_SEL_MASK
value|0x0000001F
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_RES_SEL_SHIFT
value|0
comment|/* Not in use */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_RES_EN
value|(1<< 5)
comment|/* Not in use */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_RES_DEF
value|(1<< 6)
comment|/**** tx_gcp_table_alu_opcode register ****/
comment|/* first opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_1_MASK
value|0x0000003F
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_1_SHIFT
value|0
comment|/* second opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_2_MASK
value|0x00000FC0
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_2_SHIFT
value|6
comment|/* third opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_3_MASK
value|0x0003F000
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPCODE_OPCODE_3_SHIFT
value|12
comment|/**** tx_gcp_table_alu_opsel register ****/
comment|/* frst opsel, input selection */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_1_MASK
value|0x0000000F
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_1_SHIFT
value|0
comment|/* second opsel, input selection */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_2_MASK
value|0x000000F0
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_2_SHIFT
value|4
comment|/* third opsel, input selction */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_3_MASK
value|0x00000F00
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_3_SHIFT
value|8
comment|/* fourth opsel, input selction */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_4_MASK
value|0x0000F000
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_OPSEL_OPSEL_4_SHIFT
value|12
comment|/**** tx_gcp_table_alu_val register ****/
comment|/* value for alu input */
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_VAL_VAL_MASK
value|0x000001FF
define|#
directive|define
name|EC_TFW_V3_TX_GCP_TABLE_ALU_VAL_VAL_SHIFT
value|0
comment|/**** crc_csum_replace register ****/
comment|/* 0- use table 1- legacy SR-A0 */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_L3_CSUM_LEGACY_SEL
value|(1<< 0)
comment|/* 0- use table 1- legacy SR-A0 */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_L4_CSUM_LEGACY_SEL
value|(1<< 1)
comment|/* 0- use table 1- legacy SR-A0 */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_CRC_LEGACY_SEL
value|(1<< 2)
comment|/**** crc_csum_replace_table_addr register ****/
comment|/* parametrs table address */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_TABLE_ADDR_VAL_MASK
value|0x0000007F
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** crc_csum_replace_table register ****/
comment|/* L3 Checksum replace enable */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_TABLE_L3_CSUM_EN
value|(1<< 0)
comment|/* L4 Checksum replace enable */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_TABLE_L4_CSUM_EN
value|(1<< 1)
comment|/* CRC replace enable */
define|#
directive|define
name|EC_TFW_V3_CRC_CSUM_REPLACE_TABLE_CRC_EN
value|(1<< 2)
comment|/**** rx_gpd_cam_addr register ****/
comment|/* Cam compare table address */
define|#
directive|define
name|EC_RFW_V3_RX_GPD_CAM_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_RFW_V3_RX_GPD_CAM_ADDR_VAL_SHIFT
value|0
comment|/* cam entry is valid */
define|#
directive|define
name|EC_RFW_V3_RX_GPD_CAM_CTRL_VALID
value|(1<< 31)
comment|/**** gpd_p1 register ****/
comment|/* Location in bytes of the gpd cam data1 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P1_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P1_OFFSET_SHIFT
value|0
comment|/**** gpd_p2 register ****/
comment|/* Location in bytes of the gpd cam data2 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P2_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P2_OFFSET_SHIFT
value|0
comment|/**** gpd_p3 register ****/
comment|/* Location in bytes of the gpd cam data3 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P3_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P3_OFFSET_SHIFT
value|0
comment|/**** gpd_p4 register ****/
comment|/* Location in bytes of the gpd cam data4 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P4_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P4_OFFSET_SHIFT
value|0
comment|/**** gpd_p5 register ****/
comment|/* Location in bytes of the gpd cam data5 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P5_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P5_OFFSET_SHIFT
value|0
comment|/**** gpd_p6 register ****/
comment|/* Location in bytes of the gpd cam data6 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P6_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P6_OFFSET_SHIFT
value|0
comment|/**** gpd_p7 register ****/
comment|/* Location in bytes of the gpd cam data7 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P7_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P7_OFFSET_SHIFT
value|0
comment|/**** gpd_p8 register ****/
comment|/* Location in bytes of the gpd cam data8 in the parser result v ... */
define|#
directive|define
name|EC_RFW_V3_GPD_P8_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_GPD_P8_OFFSET_SHIFT
value|0
comment|/**** rx_gcp_legacy register ****/
comment|/* 0-choose parameters from table1- choose legacy crce roce para ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_LEGACY_PARAM_SEL
value|(1<< 0)
comment|/**** rx_gcp_table_addr register ****/
comment|/* parametrs table address */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** rx_gcp_table_gen register ****/
comment|/* polynomial selcet 0-crc32(0x104C11DB7) 1-crc32c(0x11EDC6F41) */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_POLY_SEL
value|(1<< 0)
comment|/* Enable bit complement on crc result */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_CRC32_BIT_COMP
value|(1<< 1)
comment|/* Enable bit swap on crc result */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_CRC32_BIT_SWAP
value|(1<< 2)
comment|/* Enable byte swap on crc result */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_CRC32_BYTE_SWAP
value|(1<< 3)
comment|/* Enable bit swap on input data */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_DATA_BIT_SWAP
value|(1<< 4)
comment|/* Enable byte swap on input data */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_DATA_BYTE_SWAP
value|(1<< 5)
comment|/* Number of bytes in trailer which are not part of crc calculat ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_TRAIL_SIZE_MASK
value|0x000003C0
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_TRAIL_SIZE_SHIFT
value|6
comment|/* Number of bytes in header which are not part of crc calculati ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_HEAD_SIZE_MASK
value|0x00FF0000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_HEAD_SIZE_SHIFT
value|16
comment|/* corrected offset calculation0- subtract head_size (roce)1- ad ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_HEAD_CALC
value|(1<< 24)
comment|/* 0-replace masked bits with 01-replace masked bits with 1 (roc ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_GEN_MASK_POLARITY
value|(1<< 25)
comment|/**** rx_gcp_table_res register ****/
comment|/* Bit mask for crc/checksum result options for metadata W0[13][ ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_0_MASK
value|0x0000001F
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_0_SHIFT
value|0
comment|/* Bit mask for crc/checksum result options for metadata W0[14][ ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_1_MASK
value|0x000003E0
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_1_SHIFT
value|5
comment|/* Bit mask for crc/checksum result options for metadata W3[29][ ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_2_MASK
value|0x00007C00
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_2_SHIFT
value|10
comment|/* Bit mask for crc/checksum result options for metadata W3[30][ ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_3_MASK
value|0x000F8000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_3_SHIFT
value|15
comment|/* Bit mask for crc/checksum result options for metadata W3[31][ ... */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_4_MASK
value|0x01F00000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_SEL_4_SHIFT
value|20
comment|/* enable crc result check */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_EN
value|(1<< 25)
comment|/* default value for crc check for non-crc protocol */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_RES_DEF
value|(1<< 26)
comment|/**** rx_gcp_table_alu_opcode register ****/
comment|/* first opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_1_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_1_SHIFT
value|0
comment|/* second opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_2_MASK
value|0x00000FC0
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_2_SHIFT
value|6
comment|/* third opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_3_MASK
value|0x0003F000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPCODE_OPCODE_3_SHIFT
value|12
comment|/**** rx_gcp_table_alu_opsel register ****/
comment|/* frst opsel, input selection */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_1_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_1_SHIFT
value|0
comment|/* second opsel, input selection */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_2_MASK
value|0x000000F0
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_2_SHIFT
value|4
comment|/* third opsel, input selction */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_3_MASK
value|0x00000F00
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_3_SHIFT
value|8
comment|/* fourth opsel, input selction */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_4_MASK
value|0x0000F000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_OPSEL_OPSEL_4_SHIFT
value|12
comment|/**** rx_gcp_table_alu_val register ****/
comment|/* value for alu input */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_VAL_VAL_MASK
value|0x000001FF
define|#
directive|define
name|EC_RFW_V3_RX_GCP_TABLE_ALU_VAL_VAL_SHIFT
value|0
comment|/**** rx_gcp_alu_p1 register ****/
comment|/* Location in bytes of field 1 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P1_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P1_OFFSET_SHIFT
value|0
comment|/* Right shift for field 1 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P1_SHIFT_MASK
value|0x000F0000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P1_SHIFT_SHIFT
value|16
comment|/**** rx_gcp_alu_p2 register ****/
comment|/* Location in bytes of field 2 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P2_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P2_OFFSET_SHIFT
value|0
comment|/* Right shift for field 2 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P2_SHIFT_MASK
value|0x000F0000
define|#
directive|define
name|EC_RFW_V3_RX_GCP_ALU_P2_SHIFT_SHIFT
value|16
comment|/**** hs_ctrl_table_addr register ****/
comment|/* Header split control table address */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ADDR_VAL_MASK
value|0x000000FF
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ADDR_VAL_SHIFT
value|0
comment|/**** hs_ctrl_table register ****/
comment|/* Header split length select */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_SEL_MASK
value|0x00000003
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_SEL_SHIFT
value|0
comment|/* enable header split */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ENABLE
value|(1<< 2)
comment|/**** hs_ctrl_table_alu_opcode register ****/
comment|/* first opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_1_MASK
value|0x0000003F
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_1_SHIFT
value|0
comment|/* second opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_2_MASK
value|0x00000FC0
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_2_SHIFT
value|6
comment|/* third opcode e.g. (A op1 B) op3 (C op2 D) */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_3_MASK
value|0x0003F000
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPCODE_OPCODE_3_SHIFT
value|12
comment|/**** hs_ctrl_table_alu_opsel register ****/
comment|/* frst opsel, input selection */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_1_MASK
value|0x0000000F
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_1_SHIFT
value|0
comment|/* second opsel, input selection */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_2_MASK
value|0x000000F0
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_2_SHIFT
value|4
comment|/* third opsel, input selction */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_3_MASK
value|0x00000F00
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_3_SHIFT
value|8
comment|/* fourth opsel, input selction */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_4_MASK
value|0x0000F000
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_OPSEL_OPSEL_4_SHIFT
value|12
comment|/**** hs_ctrl_table_alu_val register ****/
comment|/* value for alu input */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_VAL_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_TABLE_ALU_VAL_VAL_SHIFT
value|0
comment|/**** hs_ctrl_cfg register ****/
comment|/* Header split enable static selction0 â legacy1 â header split ... */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_CFG_ENABLE_SEL
value|(1<< 0)
comment|/* Header split length static selction0 â legacy1 â header split ... */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_CFG_LENGTH_SEL
value|(1<< 1)
comment|/**** hs_ctrl_alu_p1 register ****/
comment|/* Location in bytes of field 1 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P1_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P1_OFFSET_SHIFT
value|0
comment|/* Right shift for field 1 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P1_SHIFT_MASK
value|0x000F0000
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P1_SHIFT_SHIFT
value|16
comment|/**** hs_ctrl_alu_p2 register ****/
comment|/* Location in bytes of field 2 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P2_OFFSET_MASK
value|0x000003FF
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P2_OFFSET_SHIFT
value|0
comment|/* Right shift for field 2 in the parser result vector */
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P2_SHIFT_MASK
value|0x000F0000
define|#
directive|define
name|EC_RFW_V3_HS_CTRL_ALU_P2_SHIFT_SHIFT
value|16
comment|/**** tx_config register ****/
comment|/* [0] pre increment word swap[1] pre increment byte swap[2] pre ... */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_TWEAK_ENDIANITY_SWAP_MASK
value|0x0000003F
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_TWEAK_ENDIANITY_SWAP_SHIFT
value|0
comment|/* [0] pre encryption word swap[1] pre encryption byte swap[2] p ... */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_DATA_ENDIANITY_SWAP_MASK
value|0x00003F00
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_DATA_ENDIANITY_SWAP_SHIFT
value|8
comment|/* direction flip, used in order to use same TID entry for both TX& RX traffic */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_CRYPTO_DIR_FLIP
value|(1<< 14)
comment|/* Enabling pipe line optimization */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_PIPE_CALC_EN
value|(1<< 16)
comment|/* enable performance counters */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_PERF_CNT_EN
value|(1<< 17)
comment|/* [0] pre aes word swap[1] pre aes byte swap[2] pre aes bit swa ... */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_AES_ENDIANITY_SWAP_MASK
value|0x03F00000
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_AES_ENDIANITY_SWAP_SHIFT
value|20
comment|/* [0] pre aes key word swap[1] pre aes key byte swap[2] pre aes ... */
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_AES_KEY_ENDIANITY_SWAP_MASK
value|0xFC000000
define|#
directive|define
name|EC_CRYPTO_TX_CONFIG_AES_KEY_ENDIANITY_SWAP_SHIFT
value|26
comment|/**** rx_config register ****/
comment|/* [0] pre increment word swap[1] pre increment byte swap[2] pre ... */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_TWEAK_ENDIANITY_SWAP_MASK
value|0x0000003F
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_TWEAK_ENDIANITY_SWAP_SHIFT
value|0
comment|/* [0] pre encryption word swap[1] pre encryption byte swap[2] p ... */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_DATA_ENDIANITY_SWAP_MASK
value|0x00003F00
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_DATA_ENDIANITY_SWAP_SHIFT
value|8
comment|/* direction flip, used in order to use same TID entry for both TX& RX traffic */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_CRYPTO_DIR_FLIP
value|(1<< 14)
comment|/* Enabling pipe line optimization */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_PIPE_CALC_EN
value|(1<< 16)
comment|/* enable performance counters */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_PERF_CNT_EN
value|(1<< 17)
comment|/* [0] pre aes word swap[1] pre aes byte swap[2] pre aes bit swa ... */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_AES_ENDIANITY_SWAP_MASK
value|0x03F00000
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_AES_ENDIANITY_SWAP_SHIFT
value|20
comment|/* [0] data aes key word swap[1] data aes key byte swap[2] data  ... */
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_AES_KEY_ENDIANITY_SWAP_MASK
value|0xFC000000
define|#
directive|define
name|EC_CRYPTO_RX_CONFIG_AES_KEY_ENDIANITY_SWAP_SHIFT
value|26
comment|/**** tx_override register ****/
comment|/* all transactions are encrypted */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ENCRYPT_ONLY
value|(1<< 0)
comment|/* all transactions are decrypted */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_DECRYPT_ONLY
value|(1<< 1)
comment|/* all pkts use IV */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ALWAYS_DRIVE_IV
value|(1<< 2)
comment|/* no pkt uses IV */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_NEVER_DRIVE_IV
value|(1<< 3)
comment|/* all pkts perform authentication calculation */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ALWAYS_PERFORM_SIGN
value|(1<< 4)
comment|/* no pkt performs authentication calculation */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_NEVER_PERFORM_SIGN
value|(1<< 5)
comment|/* all pkts perform encryption calculation */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ALWAYS_PERFORM_ENC
value|(1<< 6)
comment|/* no pkt performs encryption calculation */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_NEVER_PERFORM_ENC
value|(1<< 7)
comment|/* Enforce pkt trimming bit[0] relates to metadata_pkt_trim bit[1] relates to trailer_pkt_trime bit[2] relates to sign_trim bit[3] relates to aes_padding_trim */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ALWAYS_BYPASS_PKT_TRIM_MASK
value|0x00000F00
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_ALWAYS_BYPASS_PKT_TRIM_SHIFT
value|8
comment|/* Enforce no pkt trimming bit[0] relates to metadata_pkt_trim bit[1] relates to trailer_pkt_trime bit[2] relates to sign_trim bit[3] relates to aes_padding_trim */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_NEVER_BYPASS_PKT_TRIM_MASK
value|0x0000F000
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_NEVER_BYPASS_PKT_TRIM_SHIFT
value|12
comment|/* chicken bit to disable metadata handling optimization */
define|#
directive|define
name|EC_CRYPTO_TX_OVERRIDE_EXPLICIT_METADATA_STAGE
value|(1<< 16)
comment|/**** rx_override register ****/
comment|/* all transactions are encrypted */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ENCRYPT_ONLY
value|(1<< 0)
comment|/* all transactions are decrypted */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_DECRYPT_ONLY
value|(1<< 1)
comment|/* all pkts use IV */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ALWAYS_DRIVE_IV
value|(1<< 2)
comment|/* no pkt uses IV */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_NEVER_DRIVE_IV
value|(1<< 3)
comment|/* all pkts perform authentication calculation */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ALWAYS_PERFORM_SIGN
value|(1<< 4)
comment|/* no pkt performs authentication calculation */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_NEVER_PERFORM_SIGN
value|(1<< 5)
comment|/* all pkts perform encryption calculation */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ALWAYS_PERFORM_ENC
value|(1<< 6)
comment|/* no pkt performs encryption calculation */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_NEVER_PERFORM_ENC
value|(1<< 7)
comment|/* Enforce pkt trimming bit[0] relates to metadata_pkt_trim bit[1] relates to trailer_pkt_trime bit[2] relates to sign_trim bit[3] relates to aes_padding_trim */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ALWAYS_BYPASS_PKT_TRIM_MASK
value|0x00000F00
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_ALWAYS_BYPASS_PKT_TRIM_SHIFT
value|8
comment|/* Enforce no pkt trimming bit[0] relates to metadata_pkt_trim bit[1] relates to trailer_pkt_trime bit[2] relates to sign_trim bit[3] relates to aes_padding_trim */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_NEVER_BYPASS_PKT_TRIM_MASK
value|0x0000F000
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_NEVER_BYPASS_PKT_TRIM_SHIFT
value|12
comment|/* bit enable for writing to rx_cmpl metadata info */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_META_DATA_WRITE_EN_MASK
value|0x00070000
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_META_DATA_WRITE_EN_SHIFT
value|16
comment|/* chicken bit to disable metadata handling optimization */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_EXPLICIT_METADATA_STAGE
value|(1<< 19)
comment|/* crypto metadata offset in the rx cmpl_desc */
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_META_DATA_BASE_MASK
value|0x07F00000
define|#
directive|define
name|EC_CRYPTO_RX_OVERRIDE_META_DATA_BASE_SHIFT
value|20
comment|/**** tx_enc_iv_construction register ****/
comment|/* for each IV byte, select between src1& src2. Src1& src2 ... */
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MUX_SEL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MUX_SEL_SHIFT
value|0
comment|/* configure meaning of mux_sel=1'b0 (2'b00 â zeros, 2'b01 f...  */
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MAP_0_MASK
value|0x00030000
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MAP_0_SHIFT
value|16
comment|/* configure meaning of mux_sel=1'b1 (2'b00 â zeros, 2'b01 ...  */
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MAP_1_MASK
value|0x000C0000
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_MAP_1_SHIFT
value|18
comment|/* Per-byte mux select taken from Crypto table (otherwise ...  */
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_SEL_FROM_TABLE
value|(1<< 20)
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_ENDIANITY_SWAP_MASK
value|0x00E00000
define|#
directive|define
name|EC_CRYPTO_TX_ENC_IV_CONSTRUCTION_ENDIANITY_SWAP_SHIFT
value|21
comment|/**** rx_enc_iv_construction register ****/
comment|/* for each IV byte, select between src1& src2. Src1& src2 ...  */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MUX_SEL_MASK
value|0x0000FFFF
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MUX_SEL_SHIFT
value|0
comment|/* configure meaning of mux_sel=1'b0 (2'b00 â zeros, 2'b01 â ...  */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MAP_0_MASK
value|0x00030000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MAP_0_SHIFT
value|16
comment|/* configure meaning of mux_sel=1'b1 (2'b00 â zeros, 2'b01 â ...  */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MAP_1_MASK
value|0x000C0000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_MAP_1_SHIFT
value|18
comment|/* Per-byte mux select taken from Crypto table (otherwise from ...  */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_SEL_FROM_TABLE
value|(1<< 20)
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_ENDIANITY_SWAP_MASK
value|0x00E00000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_CONSTRUCTION_ENDIANITY_SWAP_SHIFT
value|21
comment|/**** rx_enc_iv_map register ****/
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_0_OFFSET_MASK
value|0x0000001F
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_0_OFFSET_SHIFT
value|0
comment|/* number of valid bytes in word, as generated by field extract ... */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_0_LENGTH_MASK
value|0x000000E0
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_0_LENGTH_SHIFT
value|5
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_1_OFFSET_MASK
value|0x00001F00
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_1_OFFSET_SHIFT
value|8
comment|/* number of valid bytes in word, as generated by field extract ... */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_1_LENGTH_MASK
value|0x0000E000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_1_LENGTH_SHIFT
value|13
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_2_OFFSET_MASK
value|0x001F0000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_2_OFFSET_SHIFT
value|16
comment|/* number of valid bytes in word, as generated by field extract ... */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_2_LENGTH_MASK
value|0x00E00000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_2_LENGTH_SHIFT
value|21
comment|/* [0] word swap en [1] byte swap en [2] bit swap en */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_3_OFFSET_MASK
value|0x1F000000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_3_OFFSET_SHIFT
value|24
comment|/* number of valid bytes in word, as generated by field extract ... */
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_3_LENGTH_MASK
value|0xE0000000
define|#
directive|define
name|EC_CRYPTO_RX_ENC_IV_MAP_FIELD_EXTRACT_3_LENGTH_SHIFT
value|29
comment|/**** tx_pkt_trim_len register ****/
comment|/* metadata shift-reg length */
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_META_MASK
value|0x00000007
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_META_SHIFT
value|0
comment|/* pkt trailer shift-reg length */
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_TRAIL_MASK
value|0x000000F0
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_TRAIL_SHIFT
value|4
comment|/* sign shift-reg length */
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_SIGN_MASK
value|0x00000300
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_SIGN_SHIFT
value|8
comment|/* crypto padding shift-reg length */
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_CRYPTO_PADDING_MASK
value|0x00003000
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_CRYPTO_PADDING_SHIFT
value|12
comment|/* hardware chooses shift-registers configurations automatically â no need for sw configuration */
define|#
directive|define
name|EC_CRYPTO_TX_PKT_TRIM_LEN_AUTO_MODE
value|(1<< 16)
comment|/**** rx_pkt_trim_len register ****/
comment|/* metadata shift-reg length */
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_META_MASK
value|0x00000007
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_META_SHIFT
value|0
comment|/* pkt trailer shift-reg length */
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_TRAIL_MASK
value|0x000000F0
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_TRAIL_SHIFT
value|4
comment|/* sign shift-reg length */
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_SIGN_MASK
value|0x00000300
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_SIGN_SHIFT
value|8
comment|/* crypto padding shift-reg length */
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_CRYPTO_PADDING_MASK
value|0x00003000
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_CRYPTO_PADDING_SHIFT
value|12
comment|/* hardware chooses shift-registers configurations automatically â no need for sw configuration */
define|#
directive|define
name|EC_CRYPTO_RX_PKT_TRIM_LEN_AUTO_MODE
value|(1<< 16)
comment|/**** total_tx_secured_pkts_cipher_mode_cmpr register ****/
define|#
directive|define
name|EC_CRYPTO_PERF_CNTR_TOTAL_TX_SECURED_PKTS_CIPHER_MODE_CMPR_MODE_MASK
value|0x0000000F
define|#
directive|define
name|EC_CRYPTO_PERF_CNTR_TOTAL_TX_SECURED_PKTS_CIPHER_MODE_CMPR_MODE_SHIFT
value|0
comment|/**** total_rx_secured_pkts_cipher_mode_cmpr register ****/
define|#
directive|define
name|EC_CRYPTO_PERF_CNTR_TOTAL_RX_SECURED_PKTS_CIPHER_MODE_CMPR_MODE_MASK
value|0x0000000F
define|#
directive|define
name|EC_CRYPTO_PERF_CNTR_TOTAL_RX_SECURED_PKTS_CIPHER_MODE_CMPR_MODE_SHIFT
value|0
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_EC_REG_H */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

