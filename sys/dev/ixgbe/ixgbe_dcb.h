begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_DCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_DCB_H_
end_define

begin_include
include|#
directive|include
file|"ixgbe_type.h"
end_include

begin_comment
comment|/* DCB defines */
end_comment

begin_comment
comment|/* DCB credit calculation defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_CREDIT_QUANTUM
value|64
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_CREDIT_REFILL
value|200
end_define

begin_comment
comment|/* 200 * 64B = 12800B */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_TSO_SIZE
value|(32 * 1024)
end_define

begin_comment
comment|/* Max TSO pkt size in DCB*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_CREDIT
value|(2 * IXGBE_DCB_MAX_CREDIT_REFILL)
end_define

begin_comment
comment|/* 513 for 32KB TSO packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_MIN_TSO_CREDIT
define|\
value|((IXGBE_DCB_MAX_TSO_SIZE / IXGBE_DCB_CREDIT_QUANTUM) + 1)
end_define

begin_comment
comment|/* DCB configuration defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_USER_PRIORITY
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_BW_GROUP
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_BW_PERCENT
value|100
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_TX_CONFIG
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_RX_CONFIG
value|1
end_define

begin_comment
comment|/* DCB capability defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_PG_SUPPORT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_PFC_SUPPORT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_BCN_SUPPORT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_UP2TC_SUPPORT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_DCB_GSP_SUPPORT
value|0x00000010
end_define

begin_struct
struct|struct
name|ixgbe_dcb_support
block|{
name|u32
name|capabilities
decl_stmt|;
comment|/* DCB capabilities */
comment|/* Each bit represents a number of TCs configurable in the hw. 	 * If 8 traffic classes can be configured, the value is 0x80. */
name|u8
name|traffic_classes
decl_stmt|;
name|u8
name|pfc_traffic_classes
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ixgbe_dcb_tsa
block|{
name|ixgbe_dcb_tsa_ets
init|=
literal|0
block|,
name|ixgbe_dcb_tsa_group_strict_cee
block|,
name|ixgbe_dcb_tsa_strict
block|}
enum|;
end_enum

begin_comment
comment|/* Traffic class bandwidth allocation per direction */
end_comment

begin_struct
struct|struct
name|ixgbe_dcb_tc_path
block|{
name|u8
name|bwg_id
decl_stmt|;
comment|/* Bandwidth Group (BWG) ID */
name|u8
name|bwg_percent
decl_stmt|;
comment|/* % of BWG's bandwidth */
name|u8
name|link_percent
decl_stmt|;
comment|/* % of link bandwidth */
name|u8
name|up_to_tc_bitmap
decl_stmt|;
comment|/* User Priority to Traffic Class mapping */
name|u16
name|data_credits_refill
decl_stmt|;
comment|/* Credit refill amount in 64B granularity */
name|u16
name|data_credits_max
decl_stmt|;
comment|/* Max credits for a configured packet buffer 			       * in 64B granularity.*/
name|enum
name|ixgbe_dcb_tsa
name|tsa
decl_stmt|;
comment|/* Link or Group Strict Priority */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ixgbe_dcb_pfc
block|{
name|ixgbe_dcb_pfc_disabled
init|=
literal|0
block|,
name|ixgbe_dcb_pfc_enabled
block|,
name|ixgbe_dcb_pfc_enabled_txonly
block|,
name|ixgbe_dcb_pfc_enabled_rxonly
block|}
enum|;
end_enum

begin_comment
comment|/* Traffic class configuration */
end_comment

begin_struct
struct|struct
name|ixgbe_dcb_tc_config
block|{
name|struct
name|ixgbe_dcb_tc_path
name|path
index|[
literal|2
index|]
decl_stmt|;
comment|/* One each for Tx/Rx */
name|enum
name|ixgbe_dcb_pfc
name|pfc
decl_stmt|;
comment|/* Class based flow control setting */
name|u16
name|desc_credits_max
decl_stmt|;
comment|/* For Tx Descriptor arbitration */
name|u8
name|tc
decl_stmt|;
comment|/* Traffic class (TC) */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ixgbe_dcb_pba
block|{
comment|/* PBA[0-7] each use 64KB FIFO */
name|ixgbe_dcb_pba_equal
init|=
name|PBA_STRATEGY_EQUAL
block|,
comment|/* PBA[0-3] each use 80KB, PBA[4-7] each use 48KB */
name|ixgbe_dcb_pba_80_48
init|=
name|PBA_STRATEGY_WEIGHTED
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ixgbe_dcb_num_tcs
block|{
name|u8
name|pg_tcs
decl_stmt|;
name|u8
name|pfc_tcs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_dcb_config
block|{
name|struct
name|ixgbe_dcb_tc_config
name|tc_config
index|[
name|IXGBE_DCB_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
name|struct
name|ixgbe_dcb_support
name|support
decl_stmt|;
name|struct
name|ixgbe_dcb_num_tcs
name|num_tcs
decl_stmt|;
name|u8
name|bw_percentage
index|[
literal|2
index|]
index|[
name|IXGBE_DCB_MAX_BW_GROUP
index|]
decl_stmt|;
comment|/* One each for Tx/Rx */
name|bool
name|pfc_mode_enable
decl_stmt|;
name|bool
name|round_robin_enable
decl_stmt|;
name|enum
name|ixgbe_dcb_pba
name|rx_pba_cfg
decl_stmt|;
name|u32
name|dcb_cfg_version
decl_stmt|;
comment|/* Not used...OS-specific? */
name|u32
name|link_speed
decl_stmt|;
comment|/* For bandwidth allocation validation purpose */
name|bool
name|vt_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DCB driver APIs */
end_comment

begin_comment
comment|/* DCB rule checking */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_check_config_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB credits calculation */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_calculate_tc_credits
parameter_list|(
name|u8
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_calculate_tc_credits_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB PFC */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_pfc
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_config_pfc_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB stats */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_tc_stats
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_get_tc_stats
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_hw_stats
modifier|*
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_get_pfc_stats
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_hw_stats
modifier|*
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB config arbiters */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_tx_desc_arbiter_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_config_tx_data_arbiter_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_config_rx_arbiter_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB unpack routines */
end_comment

begin_function_decl
name|void
name|ixgbe_dcb_unpack_pfc_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dcb_unpack_refill_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dcb_unpack_max_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dcb_unpack_bwgid_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dcb_unpack_tsa_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_dcb_unpack_map_cee
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|ixgbe_dcb_get_tc_from_up
parameter_list|(
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB initialization */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_hw_config
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_hw_config_cee
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|struct
name|ixgbe_dcb_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_DCB_H_ */
end_comment

end_unit

