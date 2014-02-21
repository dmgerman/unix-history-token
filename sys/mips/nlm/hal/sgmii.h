begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_SGMII_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_SGMII_H__
end_define

begin_comment
comment|/** * @file_name sgmii.h * @author Netlogic Microsystems * @brief Basic definitions of XLP SGMII ports */
end_comment

begin_define
define|#
directive|define
name|SGMII_MAC_CONF1
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x00)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_CONF2
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x01)
end_define

begin_define
define|#
directive|define
name|SGMII_IPG_IFG
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x02)
end_define

begin_define
define|#
directive|define
name|SGMII_HLF_DUP
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x03)
end_define

begin_define
define|#
directive|define
name|SGMII_MAX_FRAME
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x04)
end_define

begin_define
define|#
directive|define
name|SGMII_TEST
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x07)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_CONF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x08)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_CMD
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x09)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_ADDR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0a)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_CTRL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0b)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_STAT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0c)
end_define

begin_define
define|#
directive|define
name|SGMII_MIIM_IND
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0d)
end_define

begin_define
define|#
directive|define
name|SGMII_IO_CTRL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0e)
end_define

begin_define
define|#
directive|define
name|SGMII_IO_STAT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x0f)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_MLR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x1f)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TR64
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x20)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TR127
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x21)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TR255
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x22)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TR511
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x23)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TR1K
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x24)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TRMAX
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x25)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TRMGV
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x26)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RBYT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x27)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RPKT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x28)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RFCS
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x29)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RMCA
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2a)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RBCA
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2b)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RXCF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2c)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RXPF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2d)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RXUO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2e)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RALN
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x2f)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RFLR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x30)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RCDE
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x31)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RCSE
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x32)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RUND
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x33)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_ROVR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x34)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RFRG
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x35)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_RJBR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x36)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TBYT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x38)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TPKT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x39)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TMCA
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3a)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TBCA
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3b)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TXPF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3c)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TDFR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3d)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TEDF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3e)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TSCL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x3f)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TMCL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x40)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TLCL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x41)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TXCL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x42)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TNCL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x43)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TJBR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x46)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TFCS
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x47)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TXCF
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x48)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TOVR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x49)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TUND
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4a)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_TFRG
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4b)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_CAR1
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4c)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_CAR2
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4d)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_CAM1
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4e)
end_define

begin_define
define|#
directive|define
name|SGMII_STATS_CAM2
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x4f)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR0_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x50)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR0_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x51)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR1_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x52)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR1_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x53)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR2_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x54)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR2_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x55)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR3_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x56)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR3_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x57)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR_MASK0_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x58)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR_MASK0_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x59)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR_MASK1_LO
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x5a)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_ADDR_MASK1_HI
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x5b)
end_define

begin_define
define|#
directive|define
name|SGMII_MAC_FILTER_CONFIG
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x5c)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B31_0
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x60)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B63_32
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x61)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B95_64
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x62)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B127_96
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x63)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B159_128
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x64)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B191_160
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x65)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B223_192
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x66)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B255_224
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x67)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B287_256
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x68)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B319_288
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x69)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B351_320
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6a)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B383_352
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6b)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B415_384
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6c)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B447_416
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6d)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B479_448
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6e)
end_define

begin_define
define|#
directive|define
name|SGMII_HASHTBL_VEC_B511_480
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x6f)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_VLANTYPE_FILTER
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x76)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_RXDROP_CNTR
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x77)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_PAUSE_QUANTAMULT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x78)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_MAC_CTRL_OPCODE
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x79)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_MAC_DA_H
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7a)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_MAC_DA_L
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7b)
end_define

begin_define
define|#
directive|define
name|SGMII_NET_IFACE_CTRL3
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7c)
end_define

begin_define
define|#
directive|define
name|SGMII_NETIOR_GMAC_STAT
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7d)
end_define

begin_define
define|#
directive|define
name|SGMII_NET_IFACE_CTRL2
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7e)
end_define

begin_define
define|#
directive|define
name|SGMII_NET_IFACE_CTRL
parameter_list|(
name|block
parameter_list|,
name|i
parameter_list|)
value|NAE_REG(block, i, 0x7f)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_comment
comment|/* speed */
end_comment

begin_enum
enum|enum
name|nlm_sgmii_speed
block|{
name|NLM_SGMII_SPEED_10
block|,
name|NLM_SGMII_SPEED_100
block|,
name|NLM_SGMII_SPEED_1000
block|,
name|NLM_SGMII_SPEED_RSVD
block|}
enum|;
end_enum

begin_comment
comment|/* duplexity */
end_comment

begin_enum
enum|enum
name|nlm_sgmii_duplex_mode
block|{
name|NLM_SGMII_DUPLEX_AUTO
block|,
name|NLM_SGMII_DUPLEX_HALF
block|,
name|NLM_SGMII_DUPLEX_FULL
block|}
enum|;
end_enum

begin_comment
comment|/* stats */
end_comment

begin_enum
enum|enum
block|{
name|nlm_sgmii_stats_mlr
block|,
name|nlm_sgmii_stats_tr64
block|,
name|nlm_sgmii_stats_tr127
block|,
name|nlm_sgmii_stats_tr255
block|,
name|nlm_sgmii_stats_tr511
block|,
name|nlm_sgmii_stats_tr1k
block|,
name|nlm_sgmii_stats_trmax
block|,
name|nlm_sgmii_stats_trmgv
block|,
name|nlm_sgmii_stats_rbyt
block|,
name|nlm_sgmii_stats_rpkt
block|,
name|nlm_sgmii_stats_rfcs
block|,
name|nlm_sgmii_stats_rmca
block|,
name|nlm_sgmii_stats_rbca
block|,
name|nlm_sgmii_stats_rxcf
block|,
name|nlm_sgmii_stats_rxpf
block|,
name|nlm_sgmii_stats_rxuo
block|,
name|nlm_sgmii_stats_raln
block|,
name|nlm_sgmii_stats_rflr
block|,
name|nlm_sgmii_stats_rcde
block|,
name|nlm_sgmii_stats_rcse
block|,
name|nlm_sgmii_stats_rund
block|,
name|nlm_sgmii_stats_rovr
block|,
name|nlm_sgmii_stats_rfrg
block|,
name|nlm_sgmii_stats_rjbr
block|,
name|nlm_sgmii_stats_rdummy
block|,
comment|/* not used */
name|nlm_sgmii_stats_tbyt
block|,
name|nlm_sgmii_stats_tpkt
block|,
name|nlm_sgmii_stats_tmca
block|,
name|nlm_sgmii_stats_tbca
block|,
name|nlm_sgmii_stats_txpf
block|,
name|nlm_sgmii_stats_tdfr
block|,
name|nlm_sgmii_stats_tedf
block|,
name|nlm_sgmii_stats_tscl
block|,
name|nlm_sgmii_stats_tmcl
block|,
name|nlm_sgmii_stats_tlcl
block|,
name|nlm_sgmii_stats_txcl
block|,
name|nlm_sgmii_stats_tncl
block|,
name|nlm_sgmii_stats_tjbr
block|,
name|nlm_sgmii_stats_tfcs
block|,
name|nlm_sgmii_stats_txcf
block|,
name|nlm_sgmii_stats_tovr
block|,
name|nlm_sgmii_stats_tund
block|,
name|nlm_sgmii_stats_tfrg
block|,
name|nlm_sgmii_stats_car1
block|,
name|nlm_sgmii_stats_car2
block|,
name|nlm_sgmii_stats_cam1
block|,
name|nlm_sgmii_stats_cam2
block|}
enum|;
end_enum

begin_function_decl
name|void
name|nlm_configure_sgmii_interface
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_sgmii_pcs_init
parameter_list|(
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_setup_mac
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_setup_rx_mode_sgmii
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_setup_mac_addr_sgmii
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(LOCORE)&& !(__ASSEMBLY__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

