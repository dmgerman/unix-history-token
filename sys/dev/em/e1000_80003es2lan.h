begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_80003ES2LAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_80003ES2LAN_H_
end_define

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_OFFSET_FIFO_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_OFFSET_INB_CTRL
value|0x02
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_OFFSET_HD_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_FIFO_CTRL_RX_BYPASS
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_FIFO_CTRL_TX_BYPASS
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_INB_CTRL_DIS_PADDING
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_HD_CTRL_10_100_DEFAULT
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_HD_CTRL_1000_DEFAULT
value|0x0000
end_define

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
name|DEFAULT_TCTL_EXT_GCEX_80003ES2LAN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DEFAULT_TIPG_IPGT_1000_80003ES2LAN
value|0x8
end_define

begin_define
define|#
directive|define
name|DEFAULT_TIPG_IPGT_10_100_80003ES2LAN
value|0x9
end_define

begin_comment
comment|/* GG82563 PHY Specific Status Register (Page 0, Register 16 */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_POLARITY_REVERSAL_DISABLE
value|0x0002
end_define

begin_comment
comment|/* 1=Reversal Disabled */
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
comment|/* 00=Manual MDI */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_MDIX
value|0x0020
end_define

begin_comment
comment|/* 01=Manual MDIX */
end_comment

begin_define
define|#
directive|define
name|GG82563_PSCR_CROSSOVER_MODE_AUTO
value|0x0060
end_define

begin_comment
comment|/* 11=Auto crossover */
end_comment

begin_comment
comment|/* PHY Specific Control Register 2 (Page 0, Register 26) */
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
name|GG82563_MSCR_TX_CLK_10MBPS_2_5
value|0x0004
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_100MBPS_25
value|0x0005
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_1000MBPS_2_5
value|0x0006
end_define

begin_define
define|#
directive|define
name|GG82563_MSCR_TX_CLK_1000MBPS_25
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
comment|/* 1=Enable SERDES Electrical Idle */
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
comment|/* Disable Padding */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

