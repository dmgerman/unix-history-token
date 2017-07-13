begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_VF_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_VF_H_
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_IRQ_CLEAR_MASK
value|7
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_MAX_TX_QUEUES
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_MAX_RX_QUEUES
value|8
end_define

begin_comment
comment|/* DCB define */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_MAX_TRAFFIC_CLASS
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_VFCTRL
value|0x00000
end_define

begin_define
define|#
directive|define
name|IXGBE_VFSTATUS
value|0x00008
end_define

begin_define
define|#
directive|define
name|IXGBE_VFLINKS
value|0x00010
end_define

begin_define
define|#
directive|define
name|IXGBE_VFFRTIMER
value|0x00048
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRXMEMWRAP
value|0x03190
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEICR
value|0x00100
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEICS
value|0x00104
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEIMS
value|0x00108
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEIMC
value|0x0010C
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEIAC
value|0x00110
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEIAM
value|0x00114
end_define

begin_define
define|#
directive|define
name|IXGBE_VTEITR
parameter_list|(
name|x
parameter_list|)
value|(0x00820 + (4 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VTIVAR
parameter_list|(
name|x
parameter_list|)
value|(0x00120 + (4 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VTIVAR_MISC
value|0x00140
end_define

begin_define
define|#
directive|define
name|IXGBE_VTRSCINT
parameter_list|(
name|x
parameter_list|)
value|(0x00180 + (4 * (x)))
end_define

begin_comment
comment|/* define IXGBE_VFPBACL  still says TBD in EAS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFRDBAL
parameter_list|(
name|x
parameter_list|)
value|(0x01000 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRDBAH
parameter_list|(
name|x
parameter_list|)
value|(0x01004 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRDLEN
parameter_list|(
name|x
parameter_list|)
value|(0x01008 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRDH
parameter_list|(
name|x
parameter_list|)
value|(0x01010 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRDT
parameter_list|(
name|x
parameter_list|)
value|(0x01018 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRXDCTL
parameter_list|(
name|x
parameter_list|)
value|(0x01028 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFSRRCTL
parameter_list|(
name|x
parameter_list|)
value|(0x01014 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRSCCTL
parameter_list|(
name|x
parameter_list|)
value|(0x0102C + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFPSRTYPE
value|0x00300
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDBAL
parameter_list|(
name|x
parameter_list|)
value|(0x02000 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDBAH
parameter_list|(
name|x
parameter_list|)
value|(0x02004 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDLEN
parameter_list|(
name|x
parameter_list|)
value|(0x02008 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDH
parameter_list|(
name|x
parameter_list|)
value|(0x02010 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDT
parameter_list|(
name|x
parameter_list|)
value|(0x02018 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTXDCTL
parameter_list|(
name|x
parameter_list|)
value|(0x02028 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDWBAL
parameter_list|(
name|x
parameter_list|)
value|(0x02038 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTDWBAH
parameter_list|(
name|x
parameter_list|)
value|(0x0203C + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFDCA_RXCTRL
parameter_list|(
name|x
parameter_list|)
value|(0x0100C + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFDCA_TXCTRL
parameter_list|(
name|x
parameter_list|)
value|(0x0200c + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGPRC
value|0x0101C
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGPTC
value|0x0201C
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGORC_LSB
value|0x01020
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGORC_MSB
value|0x01024
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGOTC_LSB
value|0x02020
end_define

begin_define
define|#
directive|define
name|IXGBE_VFGOTC_MSB
value|0x02024
end_define

begin_define
define|#
directive|define
name|IXGBE_VFMPRC
value|0x01034
end_define

begin_define
define|#
directive|define
name|IXGBE_VFMRQC
value|0x3000
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRSSRK
parameter_list|(
name|x
parameter_list|)
value|(0x3100 + ((x) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFRETA
parameter_list|(
name|x
parameter_list|)
value|(0x3200 + ((x) * 4))
end_define

begin_struct
struct|struct
name|ixgbevf_hw_stats
block|{
name|u64
name|base_vfgprc
decl_stmt|;
name|u64
name|base_vfgptc
decl_stmt|;
name|u64
name|base_vfgorc
decl_stmt|;
name|u64
name|base_vfgotc
decl_stmt|;
name|u64
name|base_vfmprc
decl_stmt|;
name|u64
name|last_vfgprc
decl_stmt|;
name|u64
name|last_vfgptc
decl_stmt|;
name|u64
name|last_vfgorc
decl_stmt|;
name|u64
name|last_vfgotc
decl_stmt|;
name|u64
name|last_vfmprc
decl_stmt|;
name|u64
name|vfgprc
decl_stmt|;
name|u64
name|vfgptc
decl_stmt|;
name|u64
name|vfgorc
decl_stmt|;
name|u64
name|vfgotc
decl_stmt|;
name|u64
name|vfmprc
decl_stmt|;
name|u64
name|saved_reset_vfgprc
decl_stmt|;
name|u64
name|saved_reset_vfgptc
decl_stmt|;
name|u64
name|saved_reset_vfgorc
decl_stmt|;
name|u64
name|saved_reset_vfgotc
decl_stmt|;
name|u64
name|saved_reset_vfmprc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|s32
name|ixgbe_init_ops_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_init_hw_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_start_hw_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_reset_hw_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_stop_adapter_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ixgbe_get_num_of_tx_queues_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|ixgbe_get_num_of_rx_queues_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_mac_addr_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
name|mac_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_mac_link_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
name|speed
parameter_list|,
name|bool
name|autoneg_wait_to_complete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_check_mac_link_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
modifier|*
name|speed
parameter_list|,
name|bool
modifier|*
name|link_up
parameter_list|,
name|bool
name|autoneg_wait_to_complete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_set_rar_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|index
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|,
name|u32
name|vmdq
parameter_list|,
name|u32
name|enable_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbevf_set_uc_addr_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|index
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_update_mc_addr_list_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
name|mc_addr_list
parameter_list|,
name|u32
name|mc_addr_count
parameter_list|,
name|ixgbe_mc_addr_itr
parameter_list|,
name|bool
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbevf_update_xcast_mode
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|int
name|xcast_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_set_vfta_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|vlan
parameter_list|,
name|u32
name|vind
parameter_list|,
name|bool
name|vlan_on
parameter_list|,
name|bool
name|vlvf_bypass
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbevf_rlpml_set_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|max_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbevf_negotiate_api_version
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|int
name|api
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixgbevf_get_queues
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|unsigned
name|int
modifier|*
name|num_tcs
parameter_list|,
name|unsigned
name|int
modifier|*
name|default_tc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IXGBE_VF_H__ */
end_comment

end_unit

