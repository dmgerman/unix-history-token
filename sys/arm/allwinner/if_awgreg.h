begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Jared McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Allwinner Gigabit Ethernet  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_AWGREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_AWGREG_H__
end_define

begin_define
define|#
directive|define
name|EMAC_BASIC_CTL_0
value|0x00
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SPEED
value|(0x3<< 2)
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SPEED_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SPEED_1000
value|0
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SPEED_10
value|2
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SPEED_100
value|3
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_LOOPBACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_DUPLEX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_BASIC_CTL_1
value|0x04
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_BURST_LEN
value|(0x3f<< 24)
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_BURST_LEN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_RX_TX_PRI
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BASIC_CTL_SOFT_RST
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_INT_STA
value|0x08
end_define

begin_define
define|#
directive|define
name|RX_BUF_UA_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RX_INT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TX_UNDERFLOW_INT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TX_BUF_UA_INT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TX_DMA_STOPPED_INT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TX_INT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_INT_EN
value|0x0c
end_define

begin_define
define|#
directive|define
name|RX_BUF_UA_INT_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RX_INT_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|TX_UNDERFLOW_INT_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TX_BUF_UA_INT_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TX_DMA_STOPPED_INT_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TX_INT_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_CTL_0
value|0x10
end_define

begin_define
define|#
directive|define
name|TX_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_CTL_1
value|0x14
end_define

begin_define
define|#
directive|define
name|TX_DMA_START
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|TX_DMA_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|TX_NEXT_FRAME
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TX_MD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FLUSH_TX_FIFO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_FLOW_CTL
value|0x1c
end_define

begin_define
define|#
directive|define
name|PAUSE_TIME
value|(0xffff<< 4)
end_define

begin_define
define|#
directive|define
name|PAUSE_TIME_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TX_FLOW_CTL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_DMA_LIST
value|0x20
end_define

begin_define
define|#
directive|define
name|EMAC_RX_CTL_0
value|0x24
end_define

begin_define
define|#
directive|define
name|RX_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|JUMBO_FRM_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|STRIP_FCS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|CHECK_CRC
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RX_FLOW_CTL_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_CTL_1
value|0x28
end_define

begin_define
define|#
directive|define
name|RX_DMA_START
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RX_DMA_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RX_MD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_DMA_LIST
value|0x34
end_define

begin_define
define|#
directive|define
name|EMAC_RX_FRM_FLT
value|0x38
end_define

begin_define
define|#
directive|define
name|DIS_ADDR_FILTER
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DIS_BROADCAST
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RX_ALL_MULTICAST
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|CTL_FRM_FILTER
value|(0x3<< 12)
end_define

begin_define
define|#
directive|define
name|CTL_FRM_FILTER_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HASH_MULTICAST
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HASH_UNICAST
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SA_FILTER_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SA_INV_FILTER
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DA_INV_FILTER
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FLT_MD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RX_ALL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_RX_HASH_0
value|0x40
end_define

begin_define
define|#
directive|define
name|EMAC_RX_HASH_1
value|0x44
end_define

begin_define
define|#
directive|define
name|EMAC_MII_CMD
value|0x48
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M
value|(0x7<< 20)
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M_16
value|0
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M_32
value|1
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M_64
value|2
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M_128
value|3
end_define

begin_define
define|#
directive|define
name|MDC_DIV_RATIO_M_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PHY_ADDR
value|(0x1f<< 12)
end_define

begin_define
define|#
directive|define
name|PHY_ADDR_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PHY_REG_ADDR
value|(0x1f<< 4)
end_define

begin_define
define|#
directive|define
name|PHY_REG_ADDR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MII_WR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MII_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EMAC_MII_DATA
value|0x4c
end_define

begin_define
define|#
directive|define
name|EMAC_ADDR_HIGH
parameter_list|(
name|n
parameter_list|)
value|(0x50 + (n) * 8)
end_define

begin_define
define|#
directive|define
name|EMAC_ADDR_LOW
parameter_list|(
name|n
parameter_list|)
value|(0x54 + (n) * 8)
end_define

begin_define
define|#
directive|define
name|EMAC_TX_DMA_STA
value|0xb0
end_define

begin_define
define|#
directive|define
name|EMAC_TX_DMA_CUR_DESC
value|0xb4
end_define

begin_define
define|#
directive|define
name|EMAC_TX_DMA_CUR_BUF
value|0xb8
end_define

begin_define
define|#
directive|define
name|EMAC_RX_DMA_STA
value|0xc0
end_define

begin_define
define|#
directive|define
name|EMAC_RX_DMA_CUR_DESC
value|0xc4
end_define

begin_define
define|#
directive|define
name|EMAC_RX_DMA_CUR_BUF
value|0xc8
end_define

begin_define
define|#
directive|define
name|EMAC_RGMII_STA
value|0xd0
end_define

begin_struct
struct|struct
name|emac_desc
block|{
name|uint32_t
name|status
decl_stmt|;
comment|/* Transmit */
define|#
directive|define
name|TX_DESC_CTL
value|(1<< 31)
define|#
directive|define
name|TX_HEADER_ERR
value|(1<< 16)
define|#
directive|define
name|TX_LENGTH_ERR
value|(1<< 14)
define|#
directive|define
name|TX_PAYLOAD_ERR
value|(1<< 12)
define|#
directive|define
name|TX_CRS_ERR
value|(1<< 10)
define|#
directive|define
name|TX_COL_ERR_0
value|(1<< 9)
define|#
directive|define
name|TX_COL_ERR_1
value|(1<< 8)
define|#
directive|define
name|TX_COL_CNT
value|(0xf<< 3)
define|#
directive|define
name|TX_COL_CNT_SHIFT
value|3
define|#
directive|define
name|TX_DEFER_ERR
value|(1<< 2)
define|#
directive|define
name|TX_UNDERFLOW_ERR
value|(1<< 1)
define|#
directive|define
name|TX_DEFER
value|(1<< 0)
comment|/* Receive */
define|#
directive|define
name|RX_DESC_CTL
value|(1<< 31)
define|#
directive|define
name|RX_DAF_FAIL
value|(1<< 30)
define|#
directive|define
name|RX_FRM_LEN
value|(0x3fff<< 16)
define|#
directive|define
name|RX_FRM_LEN_SHIFT
value|16
define|#
directive|define
name|RX_NO_ENOUGH_BUF_ERR
value|(1<< 14)
define|#
directive|define
name|RX_SAF_FAIL
value|(1<< 13)
define|#
directive|define
name|RX_OVERFLOW_ERR
value|(1<< 11)
define|#
directive|define
name|RX_FIR_DESC
value|(1<< 9)
define|#
directive|define
name|RX_LAST_DESC
value|(1<< 8)
define|#
directive|define
name|RX_HEADER_ERR
value|(1<< 7)
define|#
directive|define
name|RX_COL_ERR
value|(1<< 6)
define|#
directive|define
name|RX_FRM_TYPE
value|(1<< 5)
define|#
directive|define
name|RX_LENGTH_ERR
value|(1<< 4)
define|#
directive|define
name|RX_PHY_ERR
value|(1<< 3)
define|#
directive|define
name|RX_CRC_ERR
value|(1<< 1)
define|#
directive|define
name|RX_PAYLOAD_ERR
value|(1<< 0)
name|uint32_t
name|size
decl_stmt|;
comment|/* Transmit */
define|#
directive|define
name|TX_INT_CTL
value|(1<< 31)
define|#
directive|define
name|TX_LAST_DESC
value|(1<< 30)
define|#
directive|define
name|TX_FIR_DESC
value|(1<< 29)
define|#
directive|define
name|TX_CHECKSUM_CTL
value|(0x3<< 27)
define|#
directive|define
name|TX_CHECKSUM_CTL_IP
value|1
define|#
directive|define
name|TX_CHECKSUM_CTL_NO_PSE
value|2
define|#
directive|define
name|TX_CHECKSUM_CTL_FULL
value|3
define|#
directive|define
name|TX_CHECKSUM_CTL_SHIFT
value|27
define|#
directive|define
name|TX_CRC_CTL
value|(1<< 26)
define|#
directive|define
name|TX_BUF_SIZE
value|(0xfff<< 0)
define|#
directive|define
name|TX_BUF_SIZE_SHIFT
value|0
comment|/* Receive */
define|#
directive|define
name|RX_INT_CTL
value|(1<< 31)
define|#
directive|define
name|RX_BUF_SIZE
value|(0xfff<< 0)
define|#
directive|define
name|RX_BUF_SIZE_SHIFT
value|0
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|next
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IF_AWGREG_H__ */
end_comment

end_unit

