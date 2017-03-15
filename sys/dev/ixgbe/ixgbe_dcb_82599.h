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
name|_IXGBE_DCB_82599_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_DCB_82599_H_
end_define

begin_comment
comment|/* DCB register definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_TDPAC
value|0x00000001
end_define

begin_comment
comment|/* 0 Round Robin, 					    * 1 WSP - Weighted Strict Priority 					    */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_VMPAC
value|0x00000002
end_define

begin_comment
comment|/* 0 Round Robin, 					    * 1 WRR - Weighted Round Robin 					    */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_TDRM
value|0x00000010
end_define

begin_comment
comment|/* Transmit Recycle Mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_BDPM
value|0x00400000
end_define

begin_comment
comment|/* Bypass Data Pipe - must clear! */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_BPBFSM
value|0x00800000
end_define

begin_comment
comment|/* Bypass PB Free Space - must 					     * clear! 					     */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_SPEED_CHG
value|0x80000000
end_define

begin_comment
comment|/* Link speed change */
end_comment

begin_comment
comment|/* Receive UP2TC mapping */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRUP2TC_UP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_RTRUP2TC_UP_MASK
value|7
end_define

begin_comment
comment|/* Transmit UP2TC mapping */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTUP2TC_UP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_RTRPT4C_MCL_SHIFT
value|12
end_define

begin_comment
comment|/* Offset to Max Credit Limit setting */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPT4C_BWG_SHIFT
value|9
end_define

begin_comment
comment|/* Offset to BWG index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPT4C_GSP
value|0x40000000
end_define

begin_comment
comment|/* GSP enable bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPT4C_LSP
value|0x80000000
end_define

begin_comment
comment|/* LSP enable bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MPBEN
value|0x00000010
end_define

begin_comment
comment|/* DMA config for multiple packet 					    * buffers enable 					    */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MCEN
value|0x00000040
end_define

begin_comment
comment|/* DMA config for multiple cores 					    * (RSS) enable 					    */
end_comment

begin_comment
comment|/* RTRPCS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPCS_RRM
value|0x00000002
end_define

begin_comment
comment|/* Receive Recycle Mode enable */
end_comment

begin_comment
comment|/* Receive Arbitration Control: 0 Round Robin, 1 DFP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPCS_RAC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_RTRPCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* Arbitration disable bit */
end_comment

begin_comment
comment|/* RTTDT2C Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDT2C_MCL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDT2C_BWG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDT2C_GSP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDT2C_LSP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTPT2C_MCL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTPT2C_BWG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTPT2C_GSP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTPT2C_LSP
value|0x80000000
end_define

begin_comment
comment|/* RTTPCS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPCS_TPPAC
value|0x00000020
end_define

begin_comment
comment|/* 0 Round Robin, 					    * 1 SP - Strict Priority 					    */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* Arbiter disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPCS_TPRM
value|0x00000100
end_define

begin_comment
comment|/* Transmit Recycle Mode enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPCS_ARBD_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTPCS_ARBD_DCB
value|0x4
end_define

begin_comment
comment|/* Arbitration delay in DCB mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXPBTHRESH_DCB
value|0xA
end_define

begin_comment
comment|/* THRESH value for DCB mode */
end_comment

begin_comment
comment|/* SECTXMINIFG DCB */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SECTX_DCB
value|0x00001F00
end_define

begin_comment
comment|/* DCB TX Buffer SEC IFG */
end_comment

begin_comment
comment|/* BCN register definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RF_INT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RS_ENA
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_MNG_CMTGI
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_MGN_BCNA_MODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_RSV7_11_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_G
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_I
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_H
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_VER_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR_CMT_ETH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNACL_SMAC_L_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNTG_BCNA_MODE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRTT_TS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRTT_TXQ_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRD_BCN_CLEAR_ALL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRD_DRIFT_FAC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRD_DRIFT_INT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRD_DRIFT_ENA
value|0x80000000
end_define

begin_comment
comment|/* DCB driver APIs */
end_comment

begin_comment
comment|/* DCB PFC */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_pfc_82599
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

begin_comment
comment|/* DCB stats */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_tc_stats_82599
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
name|ixgbe_dcb_get_tc_stats_82599
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
name|ixgbe_dcb_get_pfc_stats_82599
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
name|ixgbe_dcb_config_tx_desc_arbiter_82599
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_config_tx_data_arbiter_82599
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
name|ixgbe_dcb_config_rx_arbiter_82599
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

begin_comment
comment|/* DCB initialization */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_82599
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
name|ixgbe_dcb_hw_config_82599
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_DCB_82959_H_ */
end_comment

end_unit

