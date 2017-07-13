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
name|_IXGBE_DCB_82598_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_DCB_82598_H_
end_define

begin_comment
comment|/* DCB register definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DPMCS_MTSOS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_DPMCS_TDPAC
value|0x00000001
end_define

begin_comment
comment|/* 0 Round Robin, 					    * 1 DFP - Deficit Fixed Priority */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DPMCS_TRM
value|0x00000010
end_define

begin_comment
comment|/* Transmit Recycle Mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DPMCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* DCB arbiter disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DPMCS_TSOEF
value|0x00080000
end_define

begin_comment
comment|/* TSO Expand Factor: 0=x4, 1=x2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RUPPBMR_MQA
value|0x80000000
end_define

begin_comment
comment|/* Enable UP to queue mapping */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RT2CR_MCL_SHIFT
value|12
end_define

begin_comment
comment|/* Offset to Max Credit Limit setting */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RT2CR_LSP
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
comment|/* DMA config for multiple packet 					    * buffers enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MCEN
value|0x00000040
end_define

begin_comment
comment|/* DMA config for multiple cores 					    * (RSS) enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCCR_MCL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCCR_BWG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCCR_GSP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCCR_LSP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCCR_MCL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCCR_BWG_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCCR_GSP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCCR_LSP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_PDPMCS_TPPAC
value|0x00000020
end_define

begin_comment
comment|/* 0 Round Robin, 					    * 1 DFP - Deficit Fixed Priority */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PDPMCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* Arbiter disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PDPMCS_TRM
value|0x00000100
end_define

begin_comment
comment|/* Transmit Recycle Mode enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DTXCTL_ENDBUBD
value|0x00000004
end_define

begin_comment
comment|/* Enable DBU buffer division */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE_40KB
value|0x0000A000
end_define

begin_comment
comment|/* 40KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_48KB
value|0x0000C000
end_define

begin_comment
comment|/* 48KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_64KB
value|0x00010000
end_define

begin_comment
comment|/* 64KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_80KB
value|0x00014000
end_define

begin_comment
comment|/* 80KB Packet Buffer */
end_comment

begin_comment
comment|/* DCB driver APIs */
end_comment

begin_comment
comment|/* DCB PFC */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_pfc_82598
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB stats */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_config_tc_stats_82598
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_dcb_get_tc_stats_82598
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
name|ixgbe_dcb_get_pfc_stats_82598
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
name|ixgbe_dcb_config_tx_desc_arbiter_82598
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
name|ixgbe_dcb_config_tx_data_arbiter_82598
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
name|ixgbe_dcb_config_rx_arbiter_82598
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCB initialization */
end_comment

begin_function_decl
name|s32
name|ixgbe_dcb_hw_config_82598
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
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_DCB_82958_H_ */
end_comment

end_unit

