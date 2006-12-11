begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Principal Author: Parag Patel  * Copyright (c) 2001  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Additonal Copyright (c) 2001 by Traakan Software under same licence.  * Secondary Author: Matthew Jacob  */
end_comment

begin_comment
comment|/*-  * Derived by information released by Intel under the following license:  *  * Copyright (c) 1999 - 2001, Intel Corporation   *   * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  *   *  1. Redistributions of source code must retain the above copyright notice,   *     this list of conditions and the following disclaimer.  *   *  2. Redistributions in binary form must reproduce the above copyright notice,  *     this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *   *  3. Neither the name of Intel Corporation nor the names of its contributors   *     may be used to endorse or promote products derived from this software   *     without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   */
end_comment

begin_comment
comment|/*  * Marvell E1000 PHY registers  */
end_comment

begin_define
define|#
directive|define
name|E1000_MAX_REG_ADDRESS
value|0x1F
end_define

begin_define
define|#
directive|define
name|E1000_CR
value|0x00
end_define

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|E1000_CR_SPEED_SELECT_MSB
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_CR_COLL_TEST_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_CR_FULL_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_CR_RESTART_AUTO_NEG
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_CR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_CR_POWER_DOWN
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_CR_AUTO_NEG_ENABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_CR_SPEED_SELECT_LSB
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_CR_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_CR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_CR_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_CR_SPEED_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_CR_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_SR
value|0x01
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|E1000_SR_EXTENDED
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_SR_JABBER_DETECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_SR_LINK_STATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_SR_AUTO_NEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_SR_REMOTE_FAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_SR_AUTO_NEG_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_SR_PREAMBLE_SUPPRESS
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_SR_EXTENDED_STATUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_SR_100T2
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_SR_100T2_FD
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_SR_10T
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_SR_10T_FD
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_SR_100TX
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_SR_100TX_FD
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_SR_100T4
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ID1
value|0x02
end_define

begin_comment
comment|/* ID register 1 */
end_comment

begin_define
define|#
directive|define
name|E1000_ID2
value|0x03
end_define

begin_comment
comment|/* ID register 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_ID_88E1000
value|0x01410C50
end_define

begin_define
define|#
directive|define
name|E1000_ID_88E1000S
value|0x01410C40
end_define

begin_define
define|#
directive|define
name|E1000_ID_88E1011
value|0x01410C20
end_define

begin_define
define|#
directive|define
name|E1000_ID_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|E1000_AR
value|0x04
end_define

begin_comment
comment|/* autonegotiation advertise reg */
end_comment

begin_define
define|#
directive|define
name|E1000_AR_SELECTOR_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_AR_10T
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_AR_10T_FD
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_AR_100TX
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_AR_100TX_FD
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_AR_100T4
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_AR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_AR_ASM_DIR
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_AR_REMOTE_FAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_AR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_AR_SPEED_MASK
value|0x01E0
end_define

begin_comment
comment|/* Autonegotiation register bits for fiber cards (Alaska Only!) */
end_comment

begin_define
define|#
directive|define
name|E1000_FA_1000X_FD
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_FA_1000X
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_FA_SYM_PAUSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_FA_ASYM_PAUSE
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_FA_FAULT1
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_FA_FAULT2
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_FA_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_LPAR
value|0x05
end_define

begin_comment
comment|/* autoneg link partner abilities reg */
end_comment

begin_define
define|#
directive|define
name|E1000_LPAR_SELECTOR_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_10T
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_10T_FD
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_100TX
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_100TX_FD
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_100T4
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_ASM_DIR
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_LPAR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* autoneg link partner ability register bits for fiber cards (Alaska Only!) */
end_comment

begin_define
define|#
directive|define
name|E1000_FPAR_1000X_FD
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_1000X
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_SYM_PAUSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_ASYM_PAUSE
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_FAULT1
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_FAULT2
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_FPAR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ER
value|0x06
end_define

begin_comment
comment|/* autoneg expansion reg */
end_comment

begin_define
define|#
directive|define
name|E1000_ER_LP_NWAY
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_ER_PAGE_RXD
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_ER_NEXT_PAGE
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_ER_LP_NEXT_PAGE
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_ER_PAR_DETECT_FAULT
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_NPTX
value|0x07
end_define

begin_comment
comment|/* autoneg next page TX */
end_comment

begin_define
define|#
directive|define
name|E1000_NPTX_MSG_CODE_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_NPTX_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_NPTX_ACKNOWLDGE2
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_NPTX_MSG_PAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_NPTX_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_RNPR
value|0x08
end_define

begin_comment
comment|/* autoneg link-partner (?) next page */
end_comment

begin_define
define|#
directive|define
name|E1000_RNPR_MSG_CODE_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_RNPR_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_RNPR_ACKNOWLDGE2
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_RNPR_MSG_PAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_RNPR_ACKNOWLDGE
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_RNPR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR
value|0x09
end_define

begin_comment
comment|/* 1000T (1G) control reg */
end_comment

begin_define
define|#
directive|define
name|E1000_1GCR_ASYM_PAUSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_1000T
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_1000T_FD
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_REPEATER_DTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_MS_VALUE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_MS_ENABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_TEST_MODE_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_TEST_MODE_1
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_TEST_MODE_2
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_TEST_MODE_3
value|0x6000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_TEST_MODE_4
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_1GCR_SPEED_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|E1000_1GSR
value|0x0A
end_define

begin_comment
comment|/* 1000T (1G) status reg */
end_comment

begin_define
define|#
directive|define
name|E1000_1GSR_IDLE_ERROR_CNT
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_LP
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_LP_FD
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_REMOTE_RX_STATUS
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_LOCAL_RX_STATUS
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_MS_CONFIG_RES
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_1GSR_MS_CONFIG_FAULT
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ESR
value|0x0F
end_define

begin_comment
comment|/* IEEE extended status reg */
end_comment

begin_define
define|#
directive|define
name|E1000_ESR_1000T
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_ESR_1000T_FD
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_ESR_1000X
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_ESR_1000X_FD
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_TX_POLARITY_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_TX_NORMAL_POLARITY
value|0
end_define

begin_define
define|#
directive|define
name|E1000_AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_SCR
value|0x10
end_define

begin_comment
comment|/* special control register */
end_comment

begin_define
define|#
directive|define
name|E1000_SCR_JABBER_DISABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_SCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_SCR_SQE_TEST
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_SCR_INT_FIFO_DISABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_SCR_CLK125_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_SCR_AUTO_X_1000T
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_SCR_AUTO_X_MODE
value|0x0060
end_define

begin_define
define|#
directive|define
name|E1000_SCR_10BT_EXT_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_SCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_SCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_SCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_SCR_RX_FIFO_DEPTH_6
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_RX_FIFO_DEPTH_8
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_RX_FIFO_DEPTH_10
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_RX_FIFO_DEPTH_12
value|0x3000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_TX_FIFO_DEPTH_6
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_TX_FIFO_DEPTH_8
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_TX_FIFO_DEPTH_10
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_TX_FIFO_DEPTH_12
value|0xC000
end_define

begin_define
define|#
directive|define
name|E1000_SCR_EN_DETECT_MASK
value|0x0300
end_define

begin_comment
comment|/* 88E1112 page 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_SCR_MODE_MASK
value|0x0380
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MODE_AUTO
value|0x0180
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MODE_COPPER
value|0x0280
end_define

begin_define
define|#
directive|define
name|E1000_SCR_MODE_1000BX
value|0x0380
end_define

begin_define
define|#
directive|define
name|E1000_SSR
value|0x11
end_define

begin_comment
comment|/* special status register */
end_comment

begin_define
define|#
directive|define
name|E1000_SSR_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_SSR_REV_POLARITY
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_SSR_MDIX
value|0x0020
end_define

begin_define
define|#
directive|define
name|E1000_SSR_LINK
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_SSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_SSR_PAGE_RCVD
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_SSR_DUPLEX
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_SSR_SPEED
value|0xC000
end_define

begin_define
define|#
directive|define
name|E1000_SSR_10MBS
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_SSR_100MBS
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_SSR_1000MBS
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_IER
value|0x12
end_define

begin_comment
comment|/* interrupt enable reg */
end_comment

begin_define
define|#
directive|define
name|E1000_IER_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_IER_POLARITY_CHANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_IER_MDIX_CHANGE
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_IER_FIFO_OVER_UNDERUN
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_IER_FALSE_CARRIER
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_IER_SYMBOL_ERROR
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_IER_LINK_STAT_CHANGE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_IER_AUTO_NEG_COMPLETE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_IER_PAGE_RECEIVED
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_IER_DUPLEX_CHANGED
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_IER_SPEED_CHANGED
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_IER_AUTO_NEG_ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ISR
value|0x13
end_define

begin_comment
comment|/* interrupt status reg */
end_comment

begin_define
define|#
directive|define
name|E1000_ISR_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_ISR_POLARITY_CHANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_ISR_MDIX_CHANGE
value|0x0040
end_define

begin_define
define|#
directive|define
name|E1000_ISR_FIFO_OVER_UNDERUN
value|0x0080
end_define

begin_define
define|#
directive|define
name|E1000_ISR_FALSE_CARRIER
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_ISR_SYMBOL_ERROR
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_ISR_LINK_STAT_CHANGE
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_ISR_AUTO_NEG_COMPLETE
value|0x0800
end_define

begin_define
define|#
directive|define
name|E1000_ISR_PAGE_RECEIVED
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_ISR_DUPLEX_CHANGED
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_ISR_SPEED_CHANGED
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_ISR_AUTO_NEG_ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ESCR
value|0x14
end_define

begin_comment
comment|/* extended special control reg */
end_comment

begin_define
define|#
directive|define
name|E1000_ESCR_FIBER_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_ESCR_DOWN_NO_IDLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|E1000_ESCR_TX_CLK_2_5
value|0x0060
end_define

begin_define
define|#
directive|define
name|E1000_ESCR_TX_CLK_25
value|0x0070
end_define

begin_define
define|#
directive|define
name|E1000_ESCR_TX_CLK_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_RECR
value|0x15
end_define

begin_comment
comment|/* RX error counter reg */
end_comment

begin_define
define|#
directive|define
name|E1000_EADR
value|0x16
end_define

begin_comment
comment|/* extended address reg */
end_comment

begin_define
define|#
directive|define
name|E1000_LCR
value|0x18
end_define

begin_comment
comment|/* LED control reg */
end_comment

begin_define
define|#
directive|define
name|E1000_LCR_LED_TX
value|0x0001
end_define

begin_define
define|#
directive|define
name|E1000_LCR_LED_RX
value|0x0002
end_define

begin_define
define|#
directive|define
name|E1000_LCR_LED_DUPLEX
value|0x0004
end_define

begin_define
define|#
directive|define
name|E1000_LCR_LINK
value|0x0008
end_define

begin_define
define|#
directive|define
name|E1000_LCR_BLINK_42MS
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_BLINK_84MS
value|0x0100
end_define

begin_define
define|#
directive|define
name|E1000_LCR_BLINK_170MS
value|0x0200
end_define

begin_define
define|#
directive|define
name|E1000_LCR_BLINK_340MS
value|0x0300
end_define

begin_define
define|#
directive|define
name|E1000_LCR_BLINK_670MS
value|0x0400
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_OFF
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_21_42MS
value|0x1000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_42_84MS
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_84_170MS
value|0x3000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_170_340MS
value|0x4000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_340_670MS
value|0x5000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_670_13S
value|0x6000
end_define

begin_define
define|#
directive|define
name|E1000_LCR_PULSE_13_26S
value|0x7000
end_define

begin_comment
comment|/* The following register is found only on the 88E1011 Alaska PHY */
end_comment

begin_define
define|#
directive|define
name|E1000_ESSR
value|0x1B
end_define

begin_comment
comment|/* Extended PHY specific sts */
end_comment

begin_define
define|#
directive|define
name|E1000_ESSR_FIBER_LINK
value|0x2000
end_define

begin_define
define|#
directive|define
name|E1000_ESSR_GMII_COPPER
value|0x000f
end_define

begin_define
define|#
directive|define
name|E1000_ESSR_GMII_FIBER
value|0x0007
end_define

begin_define
define|#
directive|define
name|E1000_ESSR_TBI_COPPER
value|0x000d
end_define

begin_define
define|#
directive|define
name|E1000_ESSR_TBI_FIBER
value|0x0005
end_define

end_unit

