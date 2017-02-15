begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AMD 10Gb Ethernet driver  *  * This file is available to you under your choice of the following two  * licenses:  *  * License 1: GPLv2  *  * Copyright (c) 2014-2016 Advanced Micro Devices, Inc.  *  * This file is free software; you may copy, redistribute and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation, either version 2 of the License, or (at  * your option) any later version.  *  * This file is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program.  If not, see<http://www.gnu.org/licenses/>.  *  * This file incorporates work covered by the following copyright and  * permission notice:  *     The Synopsys DWC ETHER XGMAC Software Driver and documentation  *     (hereinafter "Software") is an unsupported proprietary work of Synopsys,  *     Inc. unless otherwise expressly agreed to in writing between Synopsys  *     and you.  *  *     The Software IS NOT an item of Licensed Software or Licensed Product  *     under any End User Software License Agreement or Agreement for Licensed  *     Product with Synopsys or any supplement thereto.  Permission is hereby  *     granted, free of charge, to any person obtaining a copy of this software  *     annotated with this license and the Software, to deal in the Software  *     without restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or sell copies  *     of the Software, and to permit persons to whom the Software is furnished  *     to do so, subject to the following conditions:  *  *     The above copyright notice and this permission notice shall be included  *     in all copies or substantial portions of the Software.  *  *     THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS"  *     BASIS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  *     PARTICULAR PURPOSE ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS  *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  *     THE POSSIBILITY OF SUCH DAMAGE.  *  *  * License 2: Modified BSD  *  * Copyright (c) 2014-2016 Advanced Micro Devices, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Advanced Micro Devices, Inc. nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL<COPYRIGHT HOLDER> BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file incorporates work covered by the following copyright and  * permission notice:  *     The Synopsys DWC ETHER XGMAC Software Driver and documentation  *     (hereinafter "Software") is an unsupported proprietary work of Synopsys,  *     Inc. unless otherwise expressly agreed to in writing between Synopsys  *     and you.  *  *     The Software IS NOT an item of Licensed Software or Licensed Product  *     under any End User Software License Agreement or Agreement for Licensed  *     Product with Synopsys or any supplement thereto.  Permission is hereby  *     granted, free of charge, to any person obtaining a copy of this software  *     annotated with this license and the Software, to deal in the Software  *     without restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or sell copies  *     of the Software, and to permit persons to whom the Software is furnished  *     to do so, subject to the following conditions:  *  *     The above copyright notice and this permission notice shall be included  *     in all copies or substantial portions of the Software.  *  *     THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS"  *     BASIS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  *     TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  *     PARTICULAR PURPOSE ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS  *     BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *     CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *     SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *     INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *     ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  *     THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XGBE_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__XGBE_COMMON_H__
end_define

begin_comment
comment|/* DMA register offsets */
end_comment

begin_define
define|#
directive|define
name|DMA_MR
value|0x3000
end_define

begin_define
define|#
directive|define
name|DMA_SBMR
value|0x3004
end_define

begin_define
define|#
directive|define
name|DMA_ISR
value|0x3008
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR
value|0x3010
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR
value|0x3018
end_define

begin_define
define|#
directive|define
name|DMA_DSR0
value|0x3020
end_define

begin_define
define|#
directive|define
name|DMA_DSR1
value|0x3024
end_define

begin_comment
comment|/* DMA register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|DMA_AXIARCR_DRC_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_DRC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_DRD_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_DRD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_TEC_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_TEC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_TED_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_TED_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_THC_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_THC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_THD_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|DMA_AXIARCR_THD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_DWC_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_DWC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_DWD_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_DWD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RPC_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RPC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RPD_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RPD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RHC_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RHC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RHD_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_RHD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_TDC_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_TDC_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_TDD_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|DMA_AXIAWCR_TDD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|DMA_ISR_MACIS_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|DMA_ISR_MACIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_ISR_MTLIS_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_ISR_MTLIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_MR_SWR_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_MR_SWR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_EAME_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_EAME_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_BLEN_256_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_BLEN_256_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_UNDEF_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_SBMR_UNDEF_WIDTH
value|1
end_define

begin_comment
comment|/* DMA register values */
end_comment

begin_define
define|#
directive|define
name|DMA_DSR_RPS_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_DSR_TPS_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DMA_DSR_Q_WIDTH
value|(DMA_DSR_RPS_WIDTH + DMA_DSR_TPS_WIDTH)
end_define

begin_define
define|#
directive|define
name|DMA_DSR0_RPS_START
value|8
end_define

begin_define
define|#
directive|define
name|DMA_DSR0_TPS_START
value|12
end_define

begin_define
define|#
directive|define
name|DMA_DSRX_FIRST_QUEUE
value|3
end_define

begin_define
define|#
directive|define
name|DMA_DSRX_INC
value|4
end_define

begin_define
define|#
directive|define
name|DMA_DSRX_QPR
value|4
end_define

begin_define
define|#
directive|define
name|DMA_DSRX_RPS_START
value|0
end_define

begin_define
define|#
directive|define
name|DMA_DSRX_TPS_START
value|4
end_define

begin_define
define|#
directive|define
name|DMA_TPS_STOPPED
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_TPS_SUSPENDED
value|0x06
end_define

begin_comment
comment|/* DMA channel register offsets  *   Multiple channels can be active.  The first channel has registers  *   that begin at 0x3100.  Each subsequent channel has registers that  *   are accessed using an offset of 0x80 from the previous channel.  */
end_comment

begin_define
define|#
directive|define
name|DMA_CH_BASE
value|0x3100
end_define

begin_define
define|#
directive|define
name|DMA_CH_INC
value|0x80
end_define

begin_define
define|#
directive|define
name|DMA_CH_CR
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_CH_TDLR_HI
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_CH_TDLR_LO
value|0x14
end_define

begin_define
define|#
directive|define
name|DMA_CH_RDLR_HI
value|0x18
end_define

begin_define
define|#
directive|define
name|DMA_CH_RDLR_LO
value|0x1c
end_define

begin_define
define|#
directive|define
name|DMA_CH_TDTR_LO
value|0x24
end_define

begin_define
define|#
directive|define
name|DMA_CH_RDTR_LO
value|0x2c
end_define

begin_define
define|#
directive|define
name|DMA_CH_TDRLR
value|0x30
end_define

begin_define
define|#
directive|define
name|DMA_CH_RDRLR
value|0x34
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER
value|0x38
end_define

begin_define
define|#
directive|define
name|DMA_CH_RIWT
value|0x3c
end_define

begin_define
define|#
directive|define
name|DMA_CH_CATDR_LO
value|0x44
end_define

begin_define
define|#
directive|define
name|DMA_CH_CARDR_LO
value|0x4c
end_define

begin_define
define|#
directive|define
name|DMA_CH_CATBR_HI
value|0x50
end_define

begin_define
define|#
directive|define
name|DMA_CH_CATBR_LO
value|0x54
end_define

begin_define
define|#
directive|define
name|DMA_CH_CARBR_HI
value|0x58
end_define

begin_define
define|#
directive|define
name|DMA_CH_CARBR_LO
value|0x5c
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR
value|0x60
end_define

begin_comment
comment|/* DMA channel register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|DMA_CH_CR_PBLX8_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CH_CR_PBLX8_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_CR_SPH_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|DMA_CH_CR_SPH_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_AIE_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_AIE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_FBEE_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_FBEE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_NIE_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_NIE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RBUE_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RBUE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RIE_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RIE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RSE_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_RSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TBUE_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TBUE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TIE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TIE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TXSE_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_IER_TXSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_PBL_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_PBL_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_RBSZ_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_RBSZ_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_SR_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_CH_RCR_SR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_RIWT_RWT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_CH_RIWT_RWT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_FBE_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_FBE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RBU_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RBU_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RI_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RI_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RPS_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_RPS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TBU_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TBU_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TI_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TI_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TPS_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_SR_TPS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_OSP_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_OSP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_PBL_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_PBL_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_ST_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_ST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_TSE_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|DMA_CH_TCR_TSE_WIDTH
value|1
end_define

begin_comment
comment|/* DMA channel register values */
end_comment

begin_define
define|#
directive|define
name|DMA_OSP_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_OSP_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_PBL_1
value|1
end_define

begin_define
define|#
directive|define
name|DMA_PBL_2
value|2
end_define

begin_define
define|#
directive|define
name|DMA_PBL_4
value|4
end_define

begin_define
define|#
directive|define
name|DMA_PBL_8
value|8
end_define

begin_define
define|#
directive|define
name|DMA_PBL_16
value|16
end_define

begin_define
define|#
directive|define
name|DMA_PBL_32
value|32
end_define

begin_define
define|#
directive|define
name|DMA_PBL_64
value|64
end_define

begin_comment
comment|/* 8 x 8 */
end_comment

begin_define
define|#
directive|define
name|DMA_PBL_128
value|128
end_define

begin_comment
comment|/* 8 x 16 */
end_comment

begin_define
define|#
directive|define
name|DMA_PBL_256
value|256
end_define

begin_comment
comment|/* 8 x 32 */
end_comment

begin_define
define|#
directive|define
name|DMA_PBL_X8_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_PBL_X8_ENABLE
value|0x01
end_define

begin_comment
comment|/* MAC register offsets */
end_comment

begin_define
define|#
directive|define
name|MAC_TCR
value|0x0000
end_define

begin_define
define|#
directive|define
name|MAC_RCR
value|0x0004
end_define

begin_define
define|#
directive|define
name|MAC_PFR
value|0x0008
end_define

begin_define
define|#
directive|define
name|MAC_WTR
value|0x000c
end_define

begin_define
define|#
directive|define
name|MAC_HTR0
value|0x0010
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR
value|0x0050
end_define

begin_define
define|#
directive|define
name|MAC_VLANHTR
value|0x0058
end_define

begin_define
define|#
directive|define
name|MAC_VLANIR
value|0x0060
end_define

begin_define
define|#
directive|define
name|MAC_IVLANIR
value|0x0064
end_define

begin_define
define|#
directive|define
name|MAC_RETMR
value|0x006c
end_define

begin_define
define|#
directive|define
name|MAC_Q0TFCR
value|0x0070
end_define

begin_define
define|#
directive|define
name|MAC_RFCR
value|0x0090
end_define

begin_define
define|#
directive|define
name|MAC_RQC0R
value|0x00a0
end_define

begin_define
define|#
directive|define
name|MAC_RQC1R
value|0x00a4
end_define

begin_define
define|#
directive|define
name|MAC_RQC2R
value|0x00a8
end_define

begin_define
define|#
directive|define
name|MAC_RQC3R
value|0x00ac
end_define

begin_define
define|#
directive|define
name|MAC_ISR
value|0x00b0
end_define

begin_define
define|#
directive|define
name|MAC_IER
value|0x00b4
end_define

begin_define
define|#
directive|define
name|MAC_RTSR
value|0x00b8
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR
value|0x00c0
end_define

begin_define
define|#
directive|define
name|MAC_RWKPFR
value|0x00c4
end_define

begin_define
define|#
directive|define
name|MAC_LPICSR
value|0x00d0
end_define

begin_define
define|#
directive|define
name|MAC_LPITCR
value|0x00d4
end_define

begin_define
define|#
directive|define
name|MAC_VR
value|0x0110
end_define

begin_define
define|#
directive|define
name|MAC_DR
value|0x0114
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R
value|0x011c
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R
value|0x0120
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R
value|0x0124
end_define

begin_define
define|#
directive|define
name|MAC_GPIOCR
value|0x0278
end_define

begin_define
define|#
directive|define
name|MAC_GPIOSR
value|0x027c
end_define

begin_define
define|#
directive|define
name|MAC_MACA0HR
value|0x0300
end_define

begin_define
define|#
directive|define
name|MAC_MACA0LR
value|0x0304
end_define

begin_define
define|#
directive|define
name|MAC_MACA1HR
value|0x0308
end_define

begin_define
define|#
directive|define
name|MAC_MACA1LR
value|0x030c
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR
value|0x0c80
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR
value|0x0c88
end_define

begin_define
define|#
directive|define
name|MAC_RSSDR
value|0x0c8c
end_define

begin_define
define|#
directive|define
name|MAC_TSCR
value|0x0d00
end_define

begin_define
define|#
directive|define
name|MAC_SSIR
value|0x0d04
end_define

begin_define
define|#
directive|define
name|MAC_STSR
value|0x0d08
end_define

begin_define
define|#
directive|define
name|MAC_STNR
value|0x0d0c
end_define

begin_define
define|#
directive|define
name|MAC_STSUR
value|0x0d10
end_define

begin_define
define|#
directive|define
name|MAC_STNUR
value|0x0d14
end_define

begin_define
define|#
directive|define
name|MAC_TSAR
value|0x0d18
end_define

begin_define
define|#
directive|define
name|MAC_TSSR
value|0x0d20
end_define

begin_define
define|#
directive|define
name|MAC_TXSNR
value|0x0d30
end_define

begin_define
define|#
directive|define
name|MAC_TXSSR
value|0x0d34
end_define

begin_define
define|#
directive|define
name|MAC_QTFCR_INC
value|4
end_define

begin_define
define|#
directive|define
name|MAC_MACA_INC
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HTR_INC
value|4
end_define

begin_define
define|#
directive|define
name|MAC_RQC2_INC
value|4
end_define

begin_define
define|#
directive|define
name|MAC_RQC2_Q_PER_REG
value|4
end_define

begin_comment
comment|/* MAC register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|MAC_HWF0R_ADDMACADRSEL_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_ADDMACADRSEL_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_ARPOFFSEL_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_ARPOFFSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_EEESEL_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_EEESEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_GMIISEL_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_GMIISEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_MGKSEL_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_MGKSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_MMCSEL_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_MMCSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_RWKSEL_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_RWKSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_RXCOESEL_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_RXCOESEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_SAVLANINS_INDEX
value|27
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_SAVLANINS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_SMASEL_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_SMASEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TSSEL_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TSSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TSSTSSEL_INDEX
value|25
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TSSTSSEL_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TXCOESEL_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_TXCOESEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_VLHASH_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HWF0R_VLHASH_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_ADDR64_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_ADDR64_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_ADVTHWORD_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_ADVTHWORD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_DBGMEMA_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_DBGMEMA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_DCBEN_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_DCBEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_HASHTBLSZ_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_HASHTBLSZ_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_L3L4FNUM_INDEX
value|27
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_L3L4FNUM_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_NUMTC_INDEX
value|21
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_NUMTC_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_RSSEN_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_RSSEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_RXFIFOSIZE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_RXFIFOSIZE_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_SPHEN_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_SPHEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_TSOEN_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_TSOEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_TXFIFOSIZE_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|MAC_HWF1R_TXFIFOSIZE_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_AUXSNAPNUM_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_AUXSNAPNUM_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_PPSOUTNUM_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_PPSOUTNUM_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_RXCHCNT_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_RXCHCNT_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_RXQCNT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_RXQCNT_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_TXCHCNT_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_TXCHCNT_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_TXQCNT_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|MAC_HWF2R_TXQCNT_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_IER_TSIE_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_IER_TSIE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_ISR_MMCRXIS_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MAC_ISR_MMCRXIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_ISR_MMCTXIS_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MAC_ISR_MMCTXIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_ISR_PMTIS_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MAC_ISR_PMTIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_ISR_TSIS_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_ISR_TSIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_MACA1HR_AE_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|MAC_MACA1HR_AE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HMC_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HMC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HPF_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HPF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HUC_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_HUC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_PM_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MAC_PFR_PM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_PR_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_PFR_PR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PFR_VTFE_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_PFR_VTFE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_MGKPKTEN_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_MGKPKTEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_PWRDWN_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_PWRDWN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_RWKFILTRST_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_RWKFILTRST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_RWKPKTEN_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_PMTCSR_RWKPKTEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_Q0TFCR_PT_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_Q0TFCR_PT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MAC_Q0TFCR_TFE_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_Q0TFCR_TFE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_ACS_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_ACS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_CST_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_RCR_CST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_DCRCC_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|MAC_RCR_DCRCC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_HDSMS_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_RCR_HDSMS_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MAC_RCR_IPC_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MAC_RCR_IPC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_JE_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_RCR_JE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_LM_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MAC_RCR_LM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RCR_RE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RCR_RE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_PFCE_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_PFCE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_RFE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_RFE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_UP_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RFCR_UP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RQC0R_RXQ0EN_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RQC0R_RXQ0EN_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_ADDRT_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_ADDRT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_CT_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_CT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_OB_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_OB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_RSSIA_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_RSSAR_RSSIA_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_IP2TE_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_IP2TE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_RSSE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_RSSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_TCP4TE_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_TCP4TE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_UDP4TE_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|MAC_RSSCR_UDP4TE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_RSSDR_DMCH_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_RSSDR_DMCH_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MAC_SSIR_SNSINC_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_SSIR_SNSINC_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MAC_SSIR_SSINC_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_SSIR_SSINC_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MAC_TCR_SS_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|MAC_TCR_SS_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_TCR_TE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_TCR_TE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_AV8021ASMEN_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_AV8021ASMEN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_SNAPTYPSEL_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_SNAPTYPSEL_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSADDREG_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSADDREG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSCFUPDT_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSCFUPDT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSCTRLSSR_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSCTRLSSR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSENA_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSENALL_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSENALL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSEVNTENA_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSEVNTENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSINIT_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSINIT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPENA_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPV4ENA_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPV4ENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPV6ENA_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSIPV6ENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSMSTRENA_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSMSTRENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSVER2ENA_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TSVER2ENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TXTSSTSM_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|MAC_TSCR_TXTSSTSM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TSSR_TXTSC_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|MAC_TSSR_TXTSC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_TXSNR_TXTSSTSMIS_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|MAC_TXSNR_TXTSSTSMIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANHTR_VLHT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_VLANHTR_VLHT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MAC_VLANIR_VLTI_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|MAC_VLANIR_VLTI_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANIR_CSVL_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|MAC_VLANIR_CSVL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_DOVLTC_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_DOVLTC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ERSVLM_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ERSVLM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ESVL_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ESVL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ETV_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_ETV_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_EVLS_INDEX
value|21
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_EVLS_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_EVLRXS_INDEX
value|24
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_EVLRXS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VL_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VTHM_INDEX
value|25
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VTHM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VTIM_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|MAC_VLANTR_VTIM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MAC_VR_DEVID_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MAC_VR_DEVID_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MAC_VR_SNPSVER_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MAC_VR_SNPSVER_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MAC_VR_USERVER_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MAC_VR_USERVER_WIDTH
value|8
end_define

begin_comment
comment|/* MMC register offsets */
end_comment

begin_define
define|#
directive|define
name|MMC_CR
value|0x0800
end_define

begin_define
define|#
directive|define
name|MMC_RISR
value|0x0804
end_define

begin_define
define|#
directive|define
name|MMC_TISR
value|0x0808
end_define

begin_define
define|#
directive|define
name|MMC_RIER
value|0x080c
end_define

begin_define
define|#
directive|define
name|MMC_TIER
value|0x0810
end_define

begin_define
define|#
directive|define
name|MMC_TXOCTETCOUNT_GB_LO
value|0x0814
end_define

begin_define
define|#
directive|define
name|MMC_TXOCTETCOUNT_GB_HI
value|0x0818
end_define

begin_define
define|#
directive|define
name|MMC_TXFRAMECOUNT_GB_LO
value|0x081c
end_define

begin_define
define|#
directive|define
name|MMC_TXFRAMECOUNT_GB_HI
value|0x0820
end_define

begin_define
define|#
directive|define
name|MMC_TXBROADCASTFRAMES_G_LO
value|0x0824
end_define

begin_define
define|#
directive|define
name|MMC_TXBROADCASTFRAMES_G_HI
value|0x0828
end_define

begin_define
define|#
directive|define
name|MMC_TXMULTICASTFRAMES_G_LO
value|0x082c
end_define

begin_define
define|#
directive|define
name|MMC_TXMULTICASTFRAMES_G_HI
value|0x0830
end_define

begin_define
define|#
directive|define
name|MMC_TX64OCTETS_GB_LO
value|0x0834
end_define

begin_define
define|#
directive|define
name|MMC_TX64OCTETS_GB_HI
value|0x0838
end_define

begin_define
define|#
directive|define
name|MMC_TX65TO127OCTETS_GB_LO
value|0x083c
end_define

begin_define
define|#
directive|define
name|MMC_TX65TO127OCTETS_GB_HI
value|0x0840
end_define

begin_define
define|#
directive|define
name|MMC_TX128TO255OCTETS_GB_LO
value|0x0844
end_define

begin_define
define|#
directive|define
name|MMC_TX128TO255OCTETS_GB_HI
value|0x0848
end_define

begin_define
define|#
directive|define
name|MMC_TX256TO511OCTETS_GB_LO
value|0x084c
end_define

begin_define
define|#
directive|define
name|MMC_TX256TO511OCTETS_GB_HI
value|0x0850
end_define

begin_define
define|#
directive|define
name|MMC_TX512TO1023OCTETS_GB_LO
value|0x0854
end_define

begin_define
define|#
directive|define
name|MMC_TX512TO1023OCTETS_GB_HI
value|0x0858
end_define

begin_define
define|#
directive|define
name|MMC_TX1024TOMAXOCTETS_GB_LO
value|0x085c
end_define

begin_define
define|#
directive|define
name|MMC_TX1024TOMAXOCTETS_GB_HI
value|0x0860
end_define

begin_define
define|#
directive|define
name|MMC_TXUNICASTFRAMES_GB_LO
value|0x0864
end_define

begin_define
define|#
directive|define
name|MMC_TXUNICASTFRAMES_GB_HI
value|0x0868
end_define

begin_define
define|#
directive|define
name|MMC_TXMULTICASTFRAMES_GB_LO
value|0x086c
end_define

begin_define
define|#
directive|define
name|MMC_TXMULTICASTFRAMES_GB_HI
value|0x0870
end_define

begin_define
define|#
directive|define
name|MMC_TXBROADCASTFRAMES_GB_LO
value|0x0874
end_define

begin_define
define|#
directive|define
name|MMC_TXBROADCASTFRAMES_GB_HI
value|0x0878
end_define

begin_define
define|#
directive|define
name|MMC_TXUNDERFLOWERROR_LO
value|0x087c
end_define

begin_define
define|#
directive|define
name|MMC_TXUNDERFLOWERROR_HI
value|0x0880
end_define

begin_define
define|#
directive|define
name|MMC_TXOCTETCOUNT_G_LO
value|0x0884
end_define

begin_define
define|#
directive|define
name|MMC_TXOCTETCOUNT_G_HI
value|0x0888
end_define

begin_define
define|#
directive|define
name|MMC_TXFRAMECOUNT_G_LO
value|0x088c
end_define

begin_define
define|#
directive|define
name|MMC_TXFRAMECOUNT_G_HI
value|0x0890
end_define

begin_define
define|#
directive|define
name|MMC_TXPAUSEFRAMES_LO
value|0x0894
end_define

begin_define
define|#
directive|define
name|MMC_TXPAUSEFRAMES_HI
value|0x0898
end_define

begin_define
define|#
directive|define
name|MMC_TXVLANFRAMES_G_LO
value|0x089c
end_define

begin_define
define|#
directive|define
name|MMC_TXVLANFRAMES_G_HI
value|0x08a0
end_define

begin_define
define|#
directive|define
name|MMC_RXFRAMECOUNT_GB_LO
value|0x0900
end_define

begin_define
define|#
directive|define
name|MMC_RXFRAMECOUNT_GB_HI
value|0x0904
end_define

begin_define
define|#
directive|define
name|MMC_RXOCTETCOUNT_GB_LO
value|0x0908
end_define

begin_define
define|#
directive|define
name|MMC_RXOCTETCOUNT_GB_HI
value|0x090c
end_define

begin_define
define|#
directive|define
name|MMC_RXOCTETCOUNT_G_LO
value|0x0910
end_define

begin_define
define|#
directive|define
name|MMC_RXOCTETCOUNT_G_HI
value|0x0914
end_define

begin_define
define|#
directive|define
name|MMC_RXBROADCASTFRAMES_G_LO
value|0x0918
end_define

begin_define
define|#
directive|define
name|MMC_RXBROADCASTFRAMES_G_HI
value|0x091c
end_define

begin_define
define|#
directive|define
name|MMC_RXMULTICASTFRAMES_G_LO
value|0x0920
end_define

begin_define
define|#
directive|define
name|MMC_RXMULTICASTFRAMES_G_HI
value|0x0924
end_define

begin_define
define|#
directive|define
name|MMC_RXCRCERROR_LO
value|0x0928
end_define

begin_define
define|#
directive|define
name|MMC_RXCRCERROR_HI
value|0x092c
end_define

begin_define
define|#
directive|define
name|MMC_RXRUNTERROR
value|0x0930
end_define

begin_define
define|#
directive|define
name|MMC_RXJABBERERROR
value|0x0934
end_define

begin_define
define|#
directive|define
name|MMC_RXUNDERSIZE_G
value|0x0938
end_define

begin_define
define|#
directive|define
name|MMC_RXOVERSIZE_G
value|0x093c
end_define

begin_define
define|#
directive|define
name|MMC_RX64OCTETS_GB_LO
value|0x0940
end_define

begin_define
define|#
directive|define
name|MMC_RX64OCTETS_GB_HI
value|0x0944
end_define

begin_define
define|#
directive|define
name|MMC_RX65TO127OCTETS_GB_LO
value|0x0948
end_define

begin_define
define|#
directive|define
name|MMC_RX65TO127OCTETS_GB_HI
value|0x094c
end_define

begin_define
define|#
directive|define
name|MMC_RX128TO255OCTETS_GB_LO
value|0x0950
end_define

begin_define
define|#
directive|define
name|MMC_RX128TO255OCTETS_GB_HI
value|0x0954
end_define

begin_define
define|#
directive|define
name|MMC_RX256TO511OCTETS_GB_LO
value|0x0958
end_define

begin_define
define|#
directive|define
name|MMC_RX256TO511OCTETS_GB_HI
value|0x095c
end_define

begin_define
define|#
directive|define
name|MMC_RX512TO1023OCTETS_GB_LO
value|0x0960
end_define

begin_define
define|#
directive|define
name|MMC_RX512TO1023OCTETS_GB_HI
value|0x0964
end_define

begin_define
define|#
directive|define
name|MMC_RX1024TOMAXOCTETS_GB_LO
value|0x0968
end_define

begin_define
define|#
directive|define
name|MMC_RX1024TOMAXOCTETS_GB_HI
value|0x096c
end_define

begin_define
define|#
directive|define
name|MMC_RXUNICASTFRAMES_G_LO
value|0x0970
end_define

begin_define
define|#
directive|define
name|MMC_RXUNICASTFRAMES_G_HI
value|0x0974
end_define

begin_define
define|#
directive|define
name|MMC_RXLENGTHERROR_LO
value|0x0978
end_define

begin_define
define|#
directive|define
name|MMC_RXLENGTHERROR_HI
value|0x097c
end_define

begin_define
define|#
directive|define
name|MMC_RXOUTOFRANGETYPE_LO
value|0x0980
end_define

begin_define
define|#
directive|define
name|MMC_RXOUTOFRANGETYPE_HI
value|0x0984
end_define

begin_define
define|#
directive|define
name|MMC_RXPAUSEFRAMES_LO
value|0x0988
end_define

begin_define
define|#
directive|define
name|MMC_RXPAUSEFRAMES_HI
value|0x098c
end_define

begin_define
define|#
directive|define
name|MMC_RXFIFOOVERFLOW_LO
value|0x0990
end_define

begin_define
define|#
directive|define
name|MMC_RXFIFOOVERFLOW_HI
value|0x0994
end_define

begin_define
define|#
directive|define
name|MMC_RXVLANFRAMES_GB_LO
value|0x0998
end_define

begin_define
define|#
directive|define
name|MMC_RXVLANFRAMES_GB_HI
value|0x099c
end_define

begin_define
define|#
directive|define
name|MMC_RXWATCHDOGERROR
value|0x09a0
end_define

begin_comment
comment|/* MMC register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|MMC_CR_CR_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MMC_CR_CR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_CR_CSR_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MMC_CR_CSR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_CR_ROR_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MMC_CR_ROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_CR_MCF_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|MMC_CR_MCF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_CR_MCT_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MMC_CR_MCT_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MMC_RIER_ALL_INTERRUPTS_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MMC_RIER_ALL_INTERRUPTS_WIDTH
value|23
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXFRAMECOUNT_GB_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXFRAMECOUNT_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOCTETCOUNT_GB_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOCTETCOUNT_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOCTETCOUNT_G_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOCTETCOUNT_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXBROADCASTFRAMES_G_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXBROADCASTFRAMES_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXMULTICASTFRAMES_G_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXMULTICASTFRAMES_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXCRCERROR_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXCRCERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXRUNTERROR_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXRUNTERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXJABBERERROR_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXJABBERERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXUNDERSIZE_G_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXUNDERSIZE_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOVERSIZE_G_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOVERSIZE_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX64OCTETS_GB_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX64OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX65TO127OCTETS_GB_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX65TO127OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX128TO255OCTETS_GB_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX128TO255OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX256TO511OCTETS_GB_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX256TO511OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX512TO1023OCTETS_GB_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX512TO1023OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX1024TOMAXOCTETS_GB_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RX1024TOMAXOCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXUNICASTFRAMES_G_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXUNICASTFRAMES_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXLENGTHERROR_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXLENGTHERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOUTOFRANGETYPE_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXOUTOFRANGETYPE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXPAUSEFRAMES_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXPAUSEFRAMES_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXFIFOOVERFLOW_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXFIFOOVERFLOW_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXVLANFRAMES_GB_INDEX
value|21
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXVLANFRAMES_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXWATCHDOGERROR_INDEX
value|22
end_define

begin_define
define|#
directive|define
name|MMC_RISR_RXWATCHDOGERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TIER_ALL_INTERRUPTS_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MMC_TIER_ALL_INTERRUPTS_WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXOCTETCOUNT_GB_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXOCTETCOUNT_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXFRAMECOUNT_GB_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXFRAMECOUNT_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXBROADCASTFRAMES_G_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXBROADCASTFRAMES_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXMULTICASTFRAMES_G_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXMULTICASTFRAMES_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX64OCTETS_GB_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX64OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX65TO127OCTETS_GB_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX65TO127OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX128TO255OCTETS_GB_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX128TO255OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX256TO511OCTETS_GB_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX256TO511OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX512TO1023OCTETS_GB_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX512TO1023OCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX1024TOMAXOCTETS_GB_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TX1024TOMAXOCTETS_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXUNICASTFRAMES_GB_INDEX
value|10
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXUNICASTFRAMES_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXMULTICASTFRAMES_GB_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXMULTICASTFRAMES_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXBROADCASTFRAMES_GB_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXBROADCASTFRAMES_GB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXUNDERFLOWERROR_INDEX
value|13
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXUNDERFLOWERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXOCTETCOUNT_G_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXOCTETCOUNT_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXFRAMECOUNT_G_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXFRAMECOUNT_G_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXPAUSEFRAMES_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXPAUSEFRAMES_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXVLANFRAMES_G_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|MMC_TISR_TXVLANFRAMES_G_WIDTH
value|1
end_define

begin_comment
comment|/* MTL register offsets */
end_comment

begin_define
define|#
directive|define
name|MTL_OMR
value|0x1000
end_define

begin_define
define|#
directive|define
name|MTL_FDCR
value|0x1008
end_define

begin_define
define|#
directive|define
name|MTL_FDSR
value|0x100c
end_define

begin_define
define|#
directive|define
name|MTL_FDDR
value|0x1010
end_define

begin_define
define|#
directive|define
name|MTL_ISR
value|0x1020
end_define

begin_define
define|#
directive|define
name|MTL_RQDCM0R
value|0x1030
end_define

begin_define
define|#
directive|define
name|MTL_TCPM0R
value|0x1040
end_define

begin_define
define|#
directive|define
name|MTL_TCPM1R
value|0x1044
end_define

begin_define
define|#
directive|define
name|MTL_RQDCM_INC
value|4
end_define

begin_define
define|#
directive|define
name|MTL_RQDCM_Q_PER_REG
value|4
end_define

begin_define
define|#
directive|define
name|MTL_TCPM_INC
value|4
end_define

begin_define
define|#
directive|define
name|MTL_TCPM_TC_PER_REG
value|4
end_define

begin_comment
comment|/* MTL register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|MTL_OMR_ETSALG_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MTL_OMR_ETSALG_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MTL_OMR_RAA_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MTL_OMR_RAA_WIDTH
value|1
end_define

begin_comment
comment|/* MTL queue register offsets  *   Multiple queues can be active.  The first queue has registers  *   that begin at 0x1100.  Each subsequent queue has registers that  *   are accessed using an offset of 0x80 from the previous queue.  */
end_comment

begin_define
define|#
directive|define
name|MTL_Q_BASE
value|0x1100
end_define

begin_define
define|#
directive|define
name|MTL_Q_INC
value|0x80
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQUR
value|0x04
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQDR
value|0x08
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR
value|0x40
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQMPOCR
value|0x44
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQDR
value|0x48
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQFCR
value|0x50
end_define

begin_define
define|#
directive|define
name|MTL_Q_IER
value|0x70
end_define

begin_define
define|#
directive|define
name|MTL_Q_ISR
value|0x74
end_define

begin_comment
comment|/* MTL queue register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|MTL_Q_RQDR_PRXQ_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQDR_PRXQ_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQDR_RXQSTS_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQDR_RXQSTS_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQFCR_RFA_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQFCR_RFA_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQFCR_RFD_INDEX
value|17
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQFCR_RFD_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_EHFC_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_EHFC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RQS_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RQS_WIDTH
value|9
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RSF_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RSF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RTC_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MTL_Q_RQOMR_RTC_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_FTQ_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_FTQ_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_Q2TCMAP_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_Q2TCMAP_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TQS_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TQS_WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TSF_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TSF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TTC_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TTC_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TXQEN_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|MTL_Q_TQOMR_TXQEN_WIDTH
value|2
end_define

begin_comment
comment|/* MTL queue register value */
end_comment

begin_define
define|#
directive|define
name|MTL_RSF_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_RSF_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|MTL_TSF_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_TSF_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|MTL_RX_THRESHOLD_64
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_RX_THRESHOLD_96
value|0x02
end_define

begin_define
define|#
directive|define
name|MTL_RX_THRESHOLD_128
value|0x03
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_32
value|0x01
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_64
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_96
value|0x02
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_128
value|0x03
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_192
value|0x04
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_256
value|0x05
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_384
value|0x06
end_define

begin_define
define|#
directive|define
name|MTL_TX_THRESHOLD_512
value|0x07
end_define

begin_define
define|#
directive|define
name|MTL_ETSALG_WRR
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_ETSALG_WFQ
value|0x01
end_define

begin_define
define|#
directive|define
name|MTL_ETSALG_DWRR
value|0x02
end_define

begin_define
define|#
directive|define
name|MTL_RAA_SP
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_RAA_WSP
value|0x01
end_define

begin_define
define|#
directive|define
name|MTL_Q_DISABLED
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_Q_ENABLED
value|0x02
end_define

begin_comment
comment|/* MTL traffic class register offsets  *   Multiple traffic classes can be active.  The first class has registers  *   that begin at 0x1100.  Each subsequent queue has registers that  *   are accessed using an offset of 0x80 from the previous queue.  */
end_comment

begin_define
define|#
directive|define
name|MTL_TC_BASE
value|MTL_Q_BASE
end_define

begin_define
define|#
directive|define
name|MTL_TC_INC
value|MTL_Q_INC
end_define

begin_define
define|#
directive|define
name|MTL_TC_ETSCR
value|0x10
end_define

begin_define
define|#
directive|define
name|MTL_TC_ETSSR
value|0x14
end_define

begin_define
define|#
directive|define
name|MTL_TC_QWR
value|0x18
end_define

begin_comment
comment|/* MTL traffic class register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|MTL_TC_ETSCR_TSA_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MTL_TC_ETSCR_TSA_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MTL_TC_QWR_QW_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MTL_TC_QWR_QW_WIDTH
value|21
end_define

begin_comment
comment|/* MTL traffic class register value */
end_comment

begin_define
define|#
directive|define
name|MTL_TSA_SP
value|0x00
end_define

begin_define
define|#
directive|define
name|MTL_TSA_ETS
value|0x02
end_define

begin_comment
comment|/* PCS MMD select register offset  *  The MMD select register is used for accessing PCS registers  *  when the underlying APB3 interface is using indirect addressing.  *  Indirect addressing requires accessing registers in two phases,  *  an address phase and a data phase.  The address phases requires  *  writing an address selection value to the MMD select regiesters.  */
end_comment

begin_define
define|#
directive|define
name|PCS_MMD_SELECT
value|0xff
end_define

begin_comment
comment|/* SerDes integration register offsets */
end_comment

begin_define
define|#
directive|define
name|SIR0_KR_RT_1
value|0x002c
end_define

begin_define
define|#
directive|define
name|SIR0_STATUS
value|0x0040
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED
value|0x0000
end_define

begin_comment
comment|/* SerDes integration register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|SIR0_KR_RT_1_RESET_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|SIR0_KR_RT_1_RESET_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SIR0_STATUS_RX_READY_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|SIR0_STATUS_RX_READY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SIR0_STATUS_TX_READY_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|SIR0_STATUS_TX_READY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_CDR_RATE_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_CDR_RATE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_DATARATE_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_DATARATE_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_PLLSEL_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_PLLSEL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_RATECHANGE_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_RATECHANGE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_TXAMP_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_TXAMP_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_WORDMODE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|SIR1_SPEED_WORDMODE_WIDTH
value|3
end_define

begin_comment
comment|/* SerDes RxTx register offsets */
end_comment

begin_define
define|#
directive|define
name|RXTX_REG6
value|0x0018
end_define

begin_define
define|#
directive|define
name|RXTX_REG20
value|0x0050
end_define

begin_define
define|#
directive|define
name|RXTX_REG22
value|0x0058
end_define

begin_define
define|#
directive|define
name|RXTX_REG114
value|0x01c8
end_define

begin_define
define|#
directive|define
name|RXTX_REG129
value|0x0204
end_define

begin_comment
comment|/* SerDes RxTx register entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|RXTX_REG6_RESETB_RXD_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|RXTX_REG6_RESETB_RXD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RXTX_REG20_BLWC_ENA_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|RXTX_REG20_BLWC_ENA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RXTX_REG114_PQ_REG_INDEX
value|9
end_define

begin_define
define|#
directive|define
name|RXTX_REG114_PQ_REG_WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|RXTX_REG129_RXDFE_CONFIG_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|RXTX_REG129_RXDFE_CONFIG_WIDTH
value|2
end_define

begin_comment
comment|/* Descriptor/Packet entry bit positions and sizes */
end_comment

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_CRC_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_CRC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_FRAME_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_FRAME_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_LENGTH_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_LENGTH_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_OVERRUN_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ERRORS_OVERRUN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CSUM_DONE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CSUM_DONE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_VLAN_CTAG_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_VLAN_CTAG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_INCOMPLETE_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_INCOMPLETE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CONTEXT_NEXT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CONTEXT_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_CONTEXT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_RX_TSTAMP_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_RX_TSTAMP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_RSS_HASH_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|RX_PACKET_ATTRIBUTES_RSS_HASH_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC0_OVT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC0_OVT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC2_HL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC2_HL_WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_CDA_INDEX
value|27
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_CDA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_CTXT_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_CTXT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_ES_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_ES_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_ETLT_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_ETLT_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_FD_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_FD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_INTE_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_INTE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_L34T_INDEX
value|20
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_L34T_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_LD_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_LD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_OWN_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_OWN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_PL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_PL_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_RSV_INDEX
value|26
end_define

begin_define
define|#
directive|define
name|RX_NORMAL_DESC3_RSV_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV4_TCP
value|1
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV4_UDP
value|2
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV4_ICMP
value|3
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV6_TCP
value|9
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV6_UDP
value|10
end_define

begin_define
define|#
directive|define
name|RX_DESC3_L34T_IPV6_ICMP
value|11
end_define

begin_define
define|#
directive|define
name|RX_CONTEXT_DESC3_TSA_INDEX
value|4
end_define

begin_define
define|#
directive|define
name|RX_CONTEXT_DESC3_TSA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RX_CONTEXT_DESC3_TSD_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|RX_CONTEXT_DESC3_TSD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_CSUM_ENABLE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_CSUM_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_TSO_ENABLE_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_TSO_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_VLAN_CTAG_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_VLAN_CTAG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_PTP_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|TX_PACKET_ATTRIBUTES_PTP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC2_MSS_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC2_MSS_WIDTH
value|15
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_CTXT_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_CTXT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_TCMSSV_INDEX
value|26
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_TCMSSV_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_VLTV_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_VLTV_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_VT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_CONTEXT_DESC3_VT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_HL_B1L_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_HL_B1L_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_IC_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_IC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_TTSE_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_TTSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_VTIR_INDEX
value|14
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_VTIR_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CIC_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CIC_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CPC_INDEX
value|26
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CPC_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CTXT_INDEX
value|30
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_CTXT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_FD_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_FD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_FL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_FL_WIDTH
value|15
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_LD_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_LD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_OWN_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_OWN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TCPHDRLEN_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TCPHDRLEN_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TCPPL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TCPPL_WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TSE_INDEX
value|18
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC3_TSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_NORMAL_DESC2_VLAN_INSERT
value|0x2
end_define

begin_comment
comment|/* MDIO undefined or vendor specific registers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_PMA_10GBR_PMD_CTRL
end_ifndef

begin_define
define|#
directive|define
name|MDIO_PMA_10GBR_PMD_CTRL
value|0x0096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_PMA_10GBR_FECCTRL
end_ifndef

begin_define
define|#
directive|define
name|MDIO_PMA_10GBR_FECCTRL
value|0x00ab
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_AN_XNP
end_ifndef

begin_define
define|#
directive|define
name|MDIO_AN_XNP
value|0x0016
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_AN_LPX
end_ifndef

begin_define
define|#
directive|define
name|MDIO_AN_LPX
value|0x0019
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_AN_COMP_STAT
end_ifndef

begin_define
define|#
directive|define
name|MDIO_AN_COMP_STAT
value|0x0030
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_AN_INTMASK
end_ifndef

begin_define
define|#
directive|define
name|MDIO_AN_INTMASK
value|0x8001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_AN_INT
end_ifndef

begin_define
define|#
directive|define
name|MDIO_AN_INT
value|0x8002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MDIO_CTRL1_SPEED1G
end_ifndef

begin_define
define|#
directive|define
name|MDIO_CTRL1_SPEED1G
value|(MDIO_CTRL1_SPEED10G& ~BMCR_SPEED100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDIO mask values */
end_comment

begin_define
define|#
directive|define
name|XGBE_XNP_MCF_NULL_MESSAGE
value|0x001
end_define

begin_define
define|#
directive|define
name|XGBE_XNP_ACK_PROCESSED
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|XGBE_XNP_MP_FORMATTED
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|XGBE_XNP_NP_EXCHANGE
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|XGBE_KR_TRAINING_START
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|XGBE_KR_TRAINING_ENABLE
value|BIT(1)
end_define

begin_comment
comment|/* Bit setting and getting macros  *  The get macro will extract the current bit field value from within  *  the variable  *  *  The set macro will clear the current bit field value within the  *  variable and then set the bit field of the variable to the  *  specified value  */
end_comment

begin_define
define|#
directive|define
name|GET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_index
parameter_list|,
name|_width
parameter_list|)
define|\
value|(((_var)>> (_index))& ((0x1<< (_width)) - 1))
end_define

begin_define
define|#
directive|define
name|SET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_index
parameter_list|,
name|_width
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	(_var)&= ~(((0x1<< (_width)) - 1)<< (_index));		\ 	(_var) |= (((_val)& ((0x1<< (_width)) - 1))<< (_index));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|GET_BITS_LE
parameter_list|(
name|_var
parameter_list|,
name|_index
parameter_list|,
name|_width
parameter_list|)
define|\
value|((le32_to_cpu((_var))>> (_index))& ((0x1<< (_width)) - 1))
end_define

begin_define
define|#
directive|define
name|SET_BITS_LE
parameter_list|(
name|_var
parameter_list|,
name|_index
parameter_list|,
name|_width
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	(_var)&= cpu_to_le32(~(((0x1<< (_width)) - 1)<< (_index)));	\ 	(_var) |= cpu_to_le32((((_val)&				\ 			      ((0x1<< (_width)) - 1))<< (_index)));	\ } while (0)
end_define

begin_comment
comment|/* Bit setting and getting macros based on register fields  *  The get macro uses the bit field definitions formed using the input  *  names to extract the current bit field value from within the  *  variable  *  *  The set macro uses the bit field definitions formed using the input  *  names to set the bit field of the variable to the specified value  */
end_comment

begin_define
define|#
directive|define
name|XGMAC_GET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS((_var),						\ 		 _prefix##_##_field##_INDEX,				\ 		 _prefix##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XGMAC_SET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|SET_BITS((_var),						\ 		 _prefix##_##_field##_INDEX,				\ 		 _prefix##_##_field##_WIDTH, (_val))
end_define

begin_define
define|#
directive|define
name|XGMAC_GET_BITS_LE
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS_LE((_var),						\ 		 _prefix##_##_field##_INDEX,				\ 		 _prefix##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XGMAC_SET_BITS_LE
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|SET_BITS_LE((_var),						\ 		 _prefix##_##_field##_INDEX,				\ 		 _prefix##_##_field##_WIDTH, (_val))
end_define

begin_comment
comment|/* Macros for reading or writing registers  *  The ioread macros will get bit fields or full values using the  *  register definitions formed using the input names  *  *  The iowrite macros will set bit fields or full values using the  *  register definitions formed using the input names  */
end_comment

begin_define
define|#
directive|define
name|XGMAC_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread32((_pdata)->xgmac_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_IOREAD_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XGMAC_IOREAD((_pdata), _reg),				\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XGMAC_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite32((_val), (_pdata)->xgmac_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_IOWRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u32 reg_val = XGMAC_IOREAD((_pdata), _reg);			\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XGMAC_IOWRITE((_pdata), _reg, reg_val);				\ } while (0)
end_define

begin_comment
comment|/* Macros for reading or writing MTL queue or traffic class registers  *  Similar to the standard read and write macros except that the  *  base register value is calculated by the queue or traffic class number  */
end_comment

begin_define
define|#
directive|define
name|XGMAC_MTL_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_n
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread32((_pdata)->xgmac_regs +					\ 		 MTL_Q_BASE + ((_n) * MTL_Q_INC) + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_MTL_IOREAD_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_n
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XGMAC_MTL_IOREAD((_pdata), (_n), _reg),		\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XGMAC_MTL_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_n
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite32((_val), (_pdata)->xgmac_regs +			\ 		  MTL_Q_BASE + ((_n) * MTL_Q_INC) + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_MTL_IOWRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_n
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u32 reg_val = XGMAC_MTL_IOREAD((_pdata), (_n), _reg);		\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XGMAC_MTL_IOWRITE((_pdata), (_n), _reg, reg_val);		\ } while (0)
end_define

begin_comment
comment|/* Macros for reading or writing DMA channel registers  *  Similar to the standard read and write macros except that the  *  base register value is obtained from the ring  */
end_comment

begin_define
define|#
directive|define
name|XGMAC_DMA_IOREAD
parameter_list|(
name|_channel
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread32((_channel)->dma_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_DMA_IOREAD_BITS
parameter_list|(
name|_channel
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XGMAC_DMA_IOREAD((_channel), _reg),			\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XGMAC_DMA_IOWRITE
parameter_list|(
name|_channel
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite32((_val), (_channel)->dma_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XGMAC_DMA_IOWRITE_BITS
parameter_list|(
name|_channel
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u32 reg_val = XGMAC_DMA_IOREAD((_channel), _reg);		\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XGMAC_DMA_IOWRITE((_channel), _reg, reg_val);			\ } while (0)
end_define

begin_comment
comment|/* Macros for building, reading or writing register values or bits  * within the register values of XPCS registers.  */
end_comment

begin_define
define|#
directive|define
name|XPCS_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_off
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite32(_val, (_pdata)->xpcs_regs + (_off))
end_define

begin_define
define|#
directive|define
name|XPCS_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_off
parameter_list|)
define|\
value|ioread32((_pdata)->xpcs_regs + (_off))
end_define

begin_comment
comment|/* Macros for building, reading or writing register values or bits  * within the register values of SerDes integration registers.  */
end_comment

begin_define
define|#
directive|define
name|XSIR_GET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS((_var),                                                \ 		 _prefix##_##_field##_INDEX,                            \ 		 _prefix##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XSIR_SET_BITS
parameter_list|(
name|_var
parameter_list|,
name|_prefix
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|SET_BITS((_var),                                                \ 		 _prefix##_##_field##_INDEX,                            \ 		 _prefix##_##_field##_WIDTH, (_val))
end_define

begin_define
define|#
directive|define
name|XSIR0_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread16((_pdata)->sir0_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XSIR0_IOREAD_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XSIR0_IOREAD((_pdata), _reg),				\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XSIR0_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite16((_val), (_pdata)->sir0_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XSIR0_IOWRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u16 reg_val = XSIR0_IOREAD((_pdata), _reg);			\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XSIR0_IOWRITE((_pdata), _reg, reg_val);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|XSIR1_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread16((_pdata)->sir1_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XSIR1_IOREAD_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XSIR1_IOREAD((_pdata), _reg),				\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XSIR1_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite16((_val), (_pdata)->sir1_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XSIR1_IOWRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u16 reg_val = XSIR1_IOREAD((_pdata), _reg);			\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XSIR1_IOWRITE((_pdata), _reg, reg_val);				\ } while (0)
end_define

begin_comment
comment|/* Macros for building, reading or writing register values or bits  * within the register values of SerDes RxTx registers.  */
end_comment

begin_define
define|#
directive|define
name|XRXTX_IOREAD
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|)
define|\
value|ioread16((_pdata)->rxtx_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XRXTX_IOREAD_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|)
define|\
value|GET_BITS(XRXTX_IOREAD((_pdata), _reg),				\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH)
end_define

begin_define
define|#
directive|define
name|XRXTX_IOWRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|iowrite16((_val), (_pdata)->rxtx_regs + _reg)
end_define

begin_define
define|#
directive|define
name|XRXTX_IOWRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_reg
parameter_list|,
name|_field
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u16 reg_val = XRXTX_IOREAD((_pdata), _reg);			\ 	SET_BITS(reg_val,						\ 		 _reg##_##_field##_INDEX,				\ 		 _reg##_##_field##_WIDTH, (_val));			\ 	XRXTX_IOWRITE((_pdata), _reg, reg_val);				\ } while (0)
end_define

begin_comment
comment|/* Macros for building, reading or writing register values or bits  * using MDIO.  Different from above because of the use of standardized  * Linux include values.  No shifting is performed with the bit  * operations, everything works on mask values.  */
end_comment

begin_define
define|#
directive|define
name|XMDIO_READ
parameter_list|(
name|_pdata
parameter_list|,
name|_mmd
parameter_list|,
name|_reg
parameter_list|)
define|\
value|((_pdata)->hw_if.read_mmd_regs((_pdata), 0,			\ 		MII_ADDR_C45 | (_mmd<< 16) | ((_reg)& 0xffff)))
end_define

begin_define
define|#
directive|define
name|XMDIO_READ_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_mmd
parameter_list|,
name|_reg
parameter_list|,
name|_mask
parameter_list|)
define|\
value|(XMDIO_READ((_pdata), _mmd, _reg)& _mask)
end_define

begin_define
define|#
directive|define
name|XMDIO_WRITE
parameter_list|(
name|_pdata
parameter_list|,
name|_mmd
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|((_pdata)->hw_if.write_mmd_regs((_pdata), 0,			\ 		MII_ADDR_C45 | (_mmd<< 16) | ((_reg)& 0xffff), (_val)))
end_define

begin_define
define|#
directive|define
name|XMDIO_WRITE_BITS
parameter_list|(
name|_pdata
parameter_list|,
name|_mmd
parameter_list|,
name|_reg
parameter_list|,
name|_mask
parameter_list|,
name|_val
parameter_list|)
define|\
value|do {									\ 	u32 mmd_val = XMDIO_READ((_pdata), _mmd, _reg);			\ 	mmd_val&= ~_mask;						\ 	mmd_val |= (_val);						\ 	XMDIO_WRITE((_pdata), _mmd, _reg, mmd_val);			\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

