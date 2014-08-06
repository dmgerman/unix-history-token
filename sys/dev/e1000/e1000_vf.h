begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_VF_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_VF_H_
end_define

begin_include
include|#
directive|include
file|"e1000_osdep.h"
end_include

begin_include
include|#
directive|include
file|"e1000_regs.h"
end_include

begin_include
include|#
directive|include
file|"e1000_defines.h"
end_include

begin_struct_decl
struct_decl|struct
name|e1000_hw
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|E1000_DEV_ID_82576_VF
value|0x10CA
end_define

begin_define
define|#
directive|define
name|E1000_DEV_ID_I350_VF
value|0x1520
end_define

begin_define
define|#
directive|define
name|E1000_VF_INIT_TIMEOUT
value|200
end_define

begin_comment
comment|/* Num of retries to clear RSTI */
end_comment

begin_comment
comment|/* Additional Descriptor Control definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDCTL_QUEUE_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Ena specific Tx Queue */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDCTL_QUEUE_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Ena specific Rx Queue */
end_comment

begin_comment
comment|/* SRRCTL bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x0280C + ((_n) * 0x100)) : \ 				 (0x0C00C + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEPKT_SHIFT
value|10
end_define

begin_comment
comment|/* Shift _right_ */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDRSIZE_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDRSIZE_SHIFT
value|2
end_define

begin_comment
comment|/* Shift _left_ */
end_comment

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_LEGACY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_ADV_ONEBUF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_SPLIT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_SPLIT_ALWAYS
value|0x0A000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_REPLICATION
value|0x06000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_HDR_REPLICATION_LARGE_PKT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DESCTYPE_MASK
value|0x0E000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_DROP_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEPKT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL_BSIZEHDR_MASK
value|0x00003F00
end_define

begin_comment
comment|/* Interrupt Defines */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR
value|0x01580
end_define

begin_comment
comment|/* Ext. Interrupt Cause Read - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_EITR
parameter_list|(
name|_n
parameter_list|)
value|(0x01680 + ((_n)<< 2))
end_define

begin_define
define|#
directive|define
name|E1000_EICS
value|0x01520
end_define

begin_comment
comment|/* Ext. Intr Cause Set -W0 */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS
value|0x01524
end_define

begin_comment
comment|/* Ext. Intr Mask Set/Read -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMC
value|0x01528
end_define

begin_comment
comment|/* Ext. Intr Mask Clear -WO */
end_comment

begin_define
define|#
directive|define
name|E1000_EIAC
value|0x0152C
end_define

begin_comment
comment|/* Ext. Intr Auto Clear -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EIAM
value|0x01530
end_define

begin_comment
comment|/* Ext. Intr Ack Auto Clear Mask -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IVAR0
value|0x01700
end_define

begin_comment
comment|/* Intr Vector Alloc (array) -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IVAR_MISC
value|0x01740
end_define

begin_comment
comment|/* IVAR for "other" causes -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IVAR_VALID
value|0x80
end_define

begin_comment
comment|/* Receive Descriptor - Advanced */
end_comment

begin_union
union|union
name|e1000_adv_rx_desc
block|{
struct|struct
block|{
name|u64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|u64
name|hdr_addr
decl_stmt|;
comment|/* Header buffer address */
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
union|union
block|{
name|u32
name|data
decl_stmt|;
struct|struct
block|{
comment|/* RSS type, Packet type */
name|u16
name|pkt_info
decl_stmt|;
comment|/* Split Header, header buffer len */
name|u16
name|hdr_info
decl_stmt|;
block|}
name|hs_rss
struct|;
block|}
name|lo_dword
union|;
union|union
block|{
name|u32
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|u16
name|ip_id
decl_stmt|;
comment|/* IP id */
name|u16
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
name|u32
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|u16
name|length
decl_stmt|;
comment|/* Packet length */
name|u16
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
name|E1000_RXDADV_HDRBUFLEN_MASK
value|0x7FE0
end_define

begin_define
define|#
directive|define
name|E1000_RXDADV_HDRBUFLEN_SHIFT
value|5
end_define

begin_comment
comment|/* Transmit Descriptor - Advanced */
end_comment

begin_union
union|union
name|e1000_adv_tx_desc
block|{
struct|struct
block|{
name|u64
name|buffer_addr
decl_stmt|;
comment|/* Address of descriptor's data buf */
name|u32
name|cmd_type_len
decl_stmt|;
name|u32
name|olinfo_status
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
name|u64
name|rsvd
decl_stmt|;
comment|/* Reserved */
name|u32
name|nxtseq_seed
decl_stmt|;
name|u32
name|status
decl_stmt|;
block|}
name|wb
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Adv Transmit Descriptor Config Masks */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DTYP_CTXT
value|0x00200000
end_define

begin_comment
comment|/* Advanced Context Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DTYP_DATA
value|0x00300000
end_define

begin_comment
comment|/* Advanced Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Descriptor extension (1=Adv) */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* VLAN pkt enable */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_DCMD_TSE
value|0x80000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_PAYLEN_SHIFT
value|14
end_define

begin_comment
comment|/* Adv desc PAYLEN shift */
end_comment

begin_comment
comment|/* Context descriptors */
end_comment

begin_struct
struct|struct
name|e1000_adv_tx_context_desc
block|{
name|u32
name|vlan_macip_lens
decl_stmt|;
name|u32
name|seqnum_seed
decl_stmt|;
name|u32
name|type_tucmd_mlhl
decl_stmt|;
name|u32
name|mss_l4len_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E1000_ADVTXD_MACLEN_SHIFT
value|9
end_define

begin_comment
comment|/* Adv ctxt desc mac len shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_IPV4
value|0x00000400
end_define

begin_comment
comment|/* IP Packet Type: 1=IPv4 */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_TUCMD_L4T_TCP
value|0x00000800
end_define

begin_comment
comment|/* L4 Packet TYPE of TCP */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_L4LEN_SHIFT
value|8
end_define

begin_comment
comment|/* Adv ctxt L4LEN shift */
end_comment

begin_define
define|#
directive|define
name|E1000_ADVTXD_MSS_SHIFT
value|16
end_define

begin_comment
comment|/* Adv ctxt MSS shift */
end_comment

begin_enum
enum|enum
name|e1000_mac_type
block|{
name|e1000_undefined
init|=
literal|0
block|,
name|e1000_vfadapt
block|,
name|e1000_vfadapt_i350
block|,
name|e1000_num_macs
comment|/* List is 1-based, so subtract 1 for TRUE count. */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|e1000_vf_stats
block|{
name|u64
name|base_gprc
decl_stmt|;
name|u64
name|base_gptc
decl_stmt|;
name|u64
name|base_gorc
decl_stmt|;
name|u64
name|base_gotc
decl_stmt|;
name|u64
name|base_mprc
decl_stmt|;
name|u64
name|base_gotlbc
decl_stmt|;
name|u64
name|base_gptlbc
decl_stmt|;
name|u64
name|base_gorlbc
decl_stmt|;
name|u64
name|base_gprlbc
decl_stmt|;
name|u32
name|last_gprc
decl_stmt|;
name|u32
name|last_gptc
decl_stmt|;
name|u32
name|last_gorc
decl_stmt|;
name|u32
name|last_gotc
decl_stmt|;
name|u32
name|last_mprc
decl_stmt|;
name|u32
name|last_gotlbc
decl_stmt|;
name|u32
name|last_gptlbc
decl_stmt|;
name|u32
name|last_gorlbc
decl_stmt|;
name|u32
name|last_gprlbc
decl_stmt|;
name|u64
name|gprc
decl_stmt|;
name|u64
name|gptc
decl_stmt|;
name|u64
name|gorc
decl_stmt|;
name|u64
name|gotc
decl_stmt|;
name|u64
name|mprc
decl_stmt|;
name|u64
name|gotlbc
decl_stmt|;
name|u64
name|gptlbc
decl_stmt|;
name|u64
name|gorlbc
decl_stmt|;
name|u64
name|gprlbc
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"e1000_mbx.h"
end_include

begin_struct
struct|struct
name|e1000_mac_operations
block|{
comment|/* Function pointers for the MAC. */
name|s32
function_decl|(
modifier|*
name|init_params
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_link
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clear_vfta
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_bus_info
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_link_up_info
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|update_mc_addr_list
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|reset_hw
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|init_hw
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_link
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|write_vfta
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rar_set
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_mac_addr
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_mac_info
block|{
name|struct
name|e1000_mac_operations
name|ops
decl_stmt|;
name|u8
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|u8
name|perm_addr
index|[
literal|6
index|]
decl_stmt|;
name|enum
name|e1000_mac_type
name|type
decl_stmt|;
name|u16
name|mta_reg_count
decl_stmt|;
name|u16
name|rar_entry_count
decl_stmt|;
name|bool
name|get_link_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_mbx_operations
block|{
name|s32
function_decl|(
modifier|*
name|init_params
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_posted
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_posted
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_msg
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_ack
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_rst
function_decl|)
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_mbx_stats
block|{
name|u32
name|msgs_tx
decl_stmt|;
name|u32
name|msgs_rx
decl_stmt|;
name|u32
name|acks
decl_stmt|;
name|u32
name|reqs
decl_stmt|;
name|u32
name|rsts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_mbx_info
block|{
name|struct
name|e1000_mbx_operations
name|ops
decl_stmt|;
name|struct
name|e1000_mbx_stats
name|stats
decl_stmt|;
name|u32
name|timeout
decl_stmt|;
name|u32
name|usec_delay
decl_stmt|;
name|u16
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_dev_spec_vf
block|{
name|u32
name|vf_number
decl_stmt|;
name|u32
name|v2p_mailbox
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e1000_hw
block|{
name|void
modifier|*
name|back
decl_stmt|;
name|u8
modifier|*
name|hw_addr
decl_stmt|;
name|u8
modifier|*
name|flash_address
decl_stmt|;
name|unsigned
name|long
name|io_base
decl_stmt|;
name|struct
name|e1000_mac_info
name|mac
decl_stmt|;
name|struct
name|e1000_mbx_info
name|mbx
decl_stmt|;
union|union
block|{
name|struct
name|e1000_dev_spec_vf
name|vf
decl_stmt|;
block|}
name|dev_spec
union|;
name|u16
name|device_id
decl_stmt|;
name|u16
name|subsystem_vendor_id
decl_stmt|;
name|u16
name|subsystem_device_id
decl_stmt|;
name|u16
name|vendor_id
decl_stmt|;
name|u8
name|revision_id
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|e1000_promisc_type
block|{
name|e1000_promisc_disabled
init|=
literal|0
block|,
comment|/* all promisc modes disabled */
name|e1000_promisc_unicast
init|=
literal|1
block|,
comment|/* unicast promiscuous enabled */
name|e1000_promisc_multicast
init|=
literal|2
block|,
comment|/* multicast promiscuous enabled */
name|e1000_promisc_enabled
init|=
literal|3
block|,
comment|/* both uni and multicast promisc */
name|e1000_num_promisc_types
block|}
enum|;
end_enum

begin_comment
comment|/* These functions must be implemented by drivers */
end_comment

begin_function_decl
name|s32
name|e1000_read_pcie_cap_reg
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg
parameter_list|,
name|u16
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_vfta_set_vf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_rlpml_set_vf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_promisc_set_vf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|enum
name|e1000_promisc_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E1000_VF_H_ */
end_comment

end_unit

