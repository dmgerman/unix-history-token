begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_NAE_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_NAE_H__
end_define

begin_comment
comment|/** * @file_name nae.h * @author Netlogic Microsystems * @brief Basic definitions of XLP Networt Accelerator Engine */
end_comment

begin_comment
comment|/* NAE specific registers */
end_comment

begin_define
define|#
directive|define
name|NAE_REG
parameter_list|(
name|blk
parameter_list|,
name|intf
parameter_list|,
name|reg
parameter_list|)
value|(((blk)<< 11) | ((intf)<< 7) | (reg))
end_define

begin_comment
comment|/* ingress path registers */
end_comment

begin_define
define|#
directive|define
name|NAE_RX_CONFIG
value|NAE_REG(7, 0, 0x10)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG0
value|NAE_REG(7, 0, 0x12)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG1
value|NAE_REG(7, 0, 0x13)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG2
value|NAE_REG(7, 0, 0x14)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG3
value|NAE_REG(7, 0, 0x15)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG4
value|NAE_REG(7, 0, 0x16)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG5
value|NAE_REG(7, 0, 0x17)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG6
value|NAE_REG(7, 0, 0x18)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG7
value|NAE_REG(7, 0, 0x19)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG8
value|NAE_REG(7, 0, 0x1a)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_BASE_CONFIG9
value|NAE_REG(7, 0, 0x1b)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_VEC_VALID
value|NAE_REG(7, 0, 0x1c)
end_define

begin_define
define|#
directive|define
name|NAE_RX_IF_SLOT_CAL
value|NAE_REG(7, 0, 0x1d)
end_define

begin_define
define|#
directive|define
name|NAE_PARSER_CONFIG
value|NAE_REG(7, 0, 0x1e)
end_define

begin_define
define|#
directive|define
name|NAE_PARSER_SEQ_FIFO_CFG
value|NAE_REG(7, 0, 0x1f)
end_define

begin_define
define|#
directive|define
name|NAE_FREE_IN_FIFO_CFG
value|NAE_REG(7, 0, 0x20)
end_define

begin_define
define|#
directive|define
name|NAE_RXBUF_BASE_DPTH_ADDR
value|NAE_REG(7, 0, 0x21)
end_define

begin_define
define|#
directive|define
name|NAE_RXBUF_BASE_DPTH
value|NAE_REG(7, 0, 0x22)
end_define

begin_define
define|#
directive|define
name|NAE_RX_UCORE_CFG
value|NAE_REG(7, 0, 0x23)
end_define

begin_define
define|#
directive|define
name|NAE_RX_UCORE_CAM_MASK0
value|NAE_REG(7, 0, 0x24)
end_define

begin_define
define|#
directive|define
name|NAE_RX_UCORE_CAM_MASK1
value|NAE_REG(7, 0, 0x25)
end_define

begin_define
define|#
directive|define
name|NAE_RX_UCORE_CAM_MASK2
value|NAE_REG(7, 0, 0x26)
end_define

begin_define
define|#
directive|define
name|NAE_RX_UCORE_CAM_MASK3
value|NAE_REG(7, 0, 0x27)
end_define

begin_define
define|#
directive|define
name|NAE_FREEIN_FIFO_UNIQ_SZ_CFG
value|NAE_REG(7, 0, 0x28)
end_define

begin_define
define|#
directive|define
name|NAE_RX_CRC_POLY0_CFG
value|NAE_REG(7, 0, 0x2a)
end_define

begin_define
define|#
directive|define
name|NAE_RX_CRC_POLY1_CFG
value|NAE_REG(7, 0, 0x2b)
end_define

begin_define
define|#
directive|define
name|NAE_FREE_SPILL0_MEM_CFG
value|NAE_REG(7, 0, 0x2c)
end_define

begin_define
define|#
directive|define
name|NAE_FREE_SPILL1_MEM_CFG
value|NAE_REG(7, 0, 0x2d)
end_define

begin_define
define|#
directive|define
name|NAE_FREEFIFO_THRESH_CFG
value|NAE_REG(7, 0, 0x2e)
end_define

begin_define
define|#
directive|define
name|NAE_FLOW_CRC16_POLY_CFG
value|NAE_REG(7, 0, 0x2f)
end_define

begin_define
define|#
directive|define
name|NAE_EGR_NIOR_CAL_LEN_REG
value|NAE_REG(7, 0, 0x4e)
end_define

begin_define
define|#
directive|define
name|NAE_EGR_NIOR_CRDT_CAL_PROG
value|NAE_REG(7, 0, 0x52)
end_define

begin_define
define|#
directive|define
name|NAE_TEST
value|NAE_REG(7, 0, 0x5f)
end_define

begin_define
define|#
directive|define
name|NAE_BIU_TIMEOUT_CFG
value|NAE_REG(7, 0, 0x60)
end_define

begin_define
define|#
directive|define
name|NAE_BIU_CFG
value|NAE_REG(7, 0, 0x61)
end_define

begin_define
define|#
directive|define
name|NAE_RX_FREE_FIFO_POP
value|NAE_REG(7, 0, 0x62)
end_define

begin_define
define|#
directive|define
name|NAE_RX_DSBL_ECC
value|NAE_REG(7, 0, 0x63)
end_define

begin_define
define|#
directive|define
name|NAE_FLOW_BASEMASK_CFG
value|NAE_REG(7, 0, 0x80)
end_define

begin_define
define|#
directive|define
name|NAE_POE_CLASS_SETUP_CFG
value|NAE_REG(7, 0, 0x81)
end_define

begin_define
define|#
directive|define
name|NAE_UCORE_IFACEMASK_CFG
value|NAE_REG(7, 0, 0x82)
end_define

begin_define
define|#
directive|define
name|NAE_RXBUF_XOFFON_THRESH
value|NAE_REG(7, 0, 0x83)
end_define

begin_define
define|#
directive|define
name|NAE_FLOW_TABLE1_CFG
value|NAE_REG(7, 0, 0x84)
end_define

begin_define
define|#
directive|define
name|NAE_FLOW_TABLE2_CFG
value|NAE_REG(7, 0, 0x85)
end_define

begin_define
define|#
directive|define
name|NAE_FLOW_TABLE3_CFG
value|NAE_REG(7, 0, 0x86)
end_define

begin_define
define|#
directive|define
name|NAE_RX_FREE_FIFO_THRESH
value|NAE_REG(7, 0, 0x87)
end_define

begin_define
define|#
directive|define
name|NAE_RX_PARSER_UNCLA
value|NAE_REG(7, 0, 0x88)
end_define

begin_define
define|#
directive|define
name|NAE_RX_BUF_INTR_THRESH
value|NAE_REG(7, 0, 0x89)
end_define

begin_define
define|#
directive|define
name|NAE_IFACE_FIFO_CFG
value|NAE_REG(7, 0, 0x8a)
end_define

begin_define
define|#
directive|define
name|NAE_PARSER_SEQ_FIFO_THRESH_CFG
value|NAE_REG(7, 0, 0x8b)
end_define

begin_define
define|#
directive|define
name|NAE_RX_ERRINJ_CTRL0
value|NAE_REG(7, 0, 0x8c)
end_define

begin_define
define|#
directive|define
name|NAE_RX_ERRINJ_CTRL1
value|NAE_REG(7, 0, 0x8d)
end_define

begin_define
define|#
directive|define
name|NAE_RX_ERR_LATCH0
value|NAE_REG(7, 0, 0x8e)
end_define

begin_define
define|#
directive|define
name|NAE_RX_ERR_LATCH1
value|NAE_REG(7, 0, 0x8f)
end_define

begin_define
define|#
directive|define
name|NAE_RX_PERF_CTR_CFG
value|NAE_REG(7, 0, 0xa0)
end_define

begin_define
define|#
directive|define
name|NAE_RX_PERF_CTR_VAL
value|NAE_REG(7, 0, 0xa1)
end_define

begin_comment
comment|/* NAE hardware parser registers */
end_comment

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT0
value|NAE_REG(7, 0, 0x210)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT1
value|NAE_REG(7, 0, 0x211)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT2
value|NAE_REG(7, 0, 0x212)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT3
value|NAE_REG(7, 0, 0x213)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT4
value|NAE_REG(7, 0, 0x214)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT5
value|NAE_REG(7, 0, 0x215)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT6
value|NAE_REG(7, 0, 0x216)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT7
value|NAE_REG(7, 0, 0x217)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT8
value|NAE_REG(7, 0, 0x218)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT9
value|NAE_REG(7, 0, 0x219)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT10
value|NAE_REG(7, 0, 0x21a)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT11
value|NAE_REG(7, 0, 0x21b)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT12
value|NAE_REG(7, 0, 0x21c)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT13
value|NAE_REG(7, 0, 0x21d)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT14
value|NAE_REG(7, 0, 0x21e)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT15
value|NAE_REG(7, 0, 0x21f)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT16
value|NAE_REG(7, 0, 0x220)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT17
value|NAE_REG(7, 0, 0x221)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT18
value|NAE_REG(7, 0, 0x222)
end_define

begin_define
define|#
directive|define
name|NAE_L2_TYPE_PORT19
value|NAE_REG(7, 0, 0x223)
end_define

begin_define
define|#
directive|define
name|NAE_L3_CTABLE_MASK0
value|NAE_REG(7, 0, 0x22c)
end_define

begin_define
define|#
directive|define
name|NAE_L3_CTABLE_MASK1
value|NAE_REG(7, 0, 0x22d)
end_define

begin_define
define|#
directive|define
name|NAE_L3_CTABLE_MASK2
value|NAE_REG(7, 0, 0x22e)
end_define

begin_define
define|#
directive|define
name|NAE_L3_CTABLE_MASK3
value|NAE_REG(7, 0, 0x22f)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE0
value|NAE_REG(7, 0, 0x230)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE1
value|NAE_REG(7, 0, 0x231)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE2
value|NAE_REG(7, 0, 0x232)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE3
value|NAE_REG(7, 0, 0x233)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE4
value|NAE_REG(7, 0, 0x234)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE5
value|NAE_REG(7, 0, 0x235)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE6
value|NAE_REG(7, 0, 0x236)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE7
value|NAE_REG(7, 0, 0x237)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE8
value|NAE_REG(7, 0, 0x238)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE9
value|NAE_REG(7, 0, 0x239)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE10
value|NAE_REG(7, 0, 0x23a)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE11
value|NAE_REG(7, 0, 0x23b)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE12
value|NAE_REG(7, 0, 0x23c)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE13
value|NAE_REG(7, 0, 0x23d)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE14
value|NAE_REG(7, 0, 0x23e)
end_define

begin_define
define|#
directive|define
name|NAE_L3CTABLE15
value|NAE_REG(7, 0, 0x23f)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE0
value|NAE_REG(7, 0, 0x250)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE1
value|NAE_REG(7, 0, 0x251)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE2
value|NAE_REG(7, 0, 0x252)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE3
value|NAE_REG(7, 0, 0x253)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE4
value|NAE_REG(7, 0, 0x254)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE5
value|NAE_REG(7, 0, 0x255)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE6
value|NAE_REG(7, 0, 0x256)
end_define

begin_define
define|#
directive|define
name|NAE_L4CTABLE7
value|NAE_REG(7, 0, 0x257)
end_define

begin_define
define|#
directive|define
name|NAE_IPV6_EXT_HEADER0
value|NAE_REG(7, 0, 0x260)
end_define

begin_define
define|#
directive|define
name|NAE_IPV6_EXT_HEADER1
value|NAE_REG(7, 0, 0x261)
end_define

begin_define
define|#
directive|define
name|NAE_VLAN_TYPES01
value|NAE_REG(7, 0, 0x262)
end_define

begin_define
define|#
directive|define
name|NAE_VLAN_TYPES23
value|NAE_REG(7, 0, 0x263)
end_define

begin_comment
comment|/* NAE Egress path registers */
end_comment

begin_define
define|#
directive|define
name|NAE_TX_CONFIG
value|NAE_REG(7, 0, 0x11)
end_define

begin_define
define|#
directive|define
name|NAE_DMA_TX_CREDIT_TH
value|NAE_REG(7, 0, 0x29)
end_define

begin_define
define|#
directive|define
name|NAE_STG1_STG2CRDT_CMD
value|NAE_REG(7, 0, 0x30)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_EHCRDT_CMD
value|NAE_REG(7, 0, 0x32)
end_define

begin_define
define|#
directive|define
name|NAE_EH_FREECRDT_CMD
value|NAE_REG(7, 0, 0x34)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_STRCRDT_CMD
value|NAE_REG(7, 0, 0x36)
end_define

begin_define
define|#
directive|define
name|NAE_TXFIFO_IFACEMAP_CMD
value|NAE_REG(7, 0, 0x38)
end_define

begin_define
define|#
directive|define
name|NAE_VFBID_DESTMAP_CMD
value|NAE_REG(7, 0, 0x3a)
end_define

begin_define
define|#
directive|define
name|NAE_STG1_PMEM_PROG
value|NAE_REG(7, 0, 0x3c)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_PMEM_PROG
value|NAE_REG(7, 0, 0x3e)
end_define

begin_define
define|#
directive|define
name|NAE_EH_PMEM_PROG
value|NAE_REG(7, 0, 0x40)
end_define

begin_define
define|#
directive|define
name|NAE_FREE_PMEM_PROG
value|NAE_REG(7, 0, 0x42)
end_define

begin_define
define|#
directive|define
name|NAE_TX_DDR_ACTVLIST_CMD
value|NAE_REG(7, 0, 0x44)
end_define

begin_define
define|#
directive|define
name|NAE_TX_IF_BURSTMAX_CMD
value|NAE_REG(7, 0, 0x46)
end_define

begin_define
define|#
directive|define
name|NAE_TX_IF_ENABLE_CMD
value|NAE_REG(7, 0, 0x48)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PKTLEN_PMEM_CMD
value|NAE_REG(7, 0, 0x4a)
end_define

begin_define
define|#
directive|define
name|NAE_TX_SCHED_MAP_CMD0
value|NAE_REG(7, 0, 0x4c)
end_define

begin_define
define|#
directive|define
name|NAE_TX_SCHED_MAP_CMD1
value|NAE_REG(7, 0, 0x4d)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PKT_PMEM_CMD0
value|NAE_REG(7, 0, 0x50)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PKT_PMEM_CMD1
value|NAE_REG(7, 0, 0x51)
end_define

begin_define
define|#
directive|define
name|NAE_TX_SCHED_CTRL
value|NAE_REG(7, 0, 0x53)
end_define

begin_define
define|#
directive|define
name|NAE_TX_CRC_POLY0
value|NAE_REG(7, 0, 0x54)
end_define

begin_define
define|#
directive|define
name|NAE_TX_CRC_POLY1
value|NAE_REG(7, 0, 0x55)
end_define

begin_define
define|#
directive|define
name|NAE_TX_CRC_POLY2
value|NAE_REG(7, 0, 0x56)
end_define

begin_define
define|#
directive|define
name|NAE_TX_CRC_POLY3
value|NAE_REG(7, 0, 0x57)
end_define

begin_define
define|#
directive|define
name|NAE_STR_PMEM_CMD
value|NAE_REG(7, 0, 0x58)
end_define

begin_define
define|#
directive|define
name|NAE_TX_IORCRDT_INIT
value|NAE_REG(7, 0, 0x59)
end_define

begin_define
define|#
directive|define
name|NAE_TX_DSBL_ECC
value|NAE_REG(7, 0, 0x5a)
end_define

begin_define
define|#
directive|define
name|NAE_TX_IORCRDT_IGNORE
value|NAE_REG(7, 0, 0x5b)
end_define

begin_define
define|#
directive|define
name|NAE_IF0_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x300)
end_define

begin_define
define|#
directive|define
name|NAE_IF1_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x302)
end_define

begin_define
define|#
directive|define
name|NAE_IF2_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x304)
end_define

begin_define
define|#
directive|define
name|NAE_IF3_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x306)
end_define

begin_define
define|#
directive|define
name|NAE_IF4_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x308)
end_define

begin_define
define|#
directive|define
name|NAE_IF5_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x30a)
end_define

begin_define
define|#
directive|define
name|NAE_IF6_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x30c)
end_define

begin_define
define|#
directive|define
name|NAE_IF7_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x30e)
end_define

begin_define
define|#
directive|define
name|NAE_IF8_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x310)
end_define

begin_define
define|#
directive|define
name|NAE_IF9_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x312)
end_define

begin_define
define|#
directive|define
name|NAE_IF10_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x314)
end_define

begin_define
define|#
directive|define
name|NAE_IF11_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x316)
end_define

begin_define
define|#
directive|define
name|NAE_IF12_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x318)
end_define

begin_define
define|#
directive|define
name|NAE_IF13_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x31a)
end_define

begin_define
define|#
directive|define
name|NAE_IF14_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x31c)
end_define

begin_define
define|#
directive|define
name|NAE_IF15_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x31e)
end_define

begin_define
define|#
directive|define
name|NAE_IF16_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x320)
end_define

begin_define
define|#
directive|define
name|NAE_IF17_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x322)
end_define

begin_define
define|#
directive|define
name|NAE_IF18_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x324)
end_define

begin_define
define|#
directive|define
name|NAE_IF19_1588_TMSTMP_HI
value|NAE_REG(7, 0, 0x326)
end_define

begin_define
define|#
directive|define
name|NAE_IF0_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x301)
end_define

begin_define
define|#
directive|define
name|NAE_IF1_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x303)
end_define

begin_define
define|#
directive|define
name|NAE_IF2_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x305)
end_define

begin_define
define|#
directive|define
name|NAE_IF3_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x307)
end_define

begin_define
define|#
directive|define
name|NAE_IF4_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x309)
end_define

begin_define
define|#
directive|define
name|NAE_IF5_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x30b)
end_define

begin_define
define|#
directive|define
name|NAE_IF6_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x30d)
end_define

begin_define
define|#
directive|define
name|NAE_IF7_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x30f)
end_define

begin_define
define|#
directive|define
name|NAE_IF8_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x311)
end_define

begin_define
define|#
directive|define
name|NAE_IF9_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x313)
end_define

begin_define
define|#
directive|define
name|NAE_IF10_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x315)
end_define

begin_define
define|#
directive|define
name|NAE_IF11_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x317)
end_define

begin_define
define|#
directive|define
name|NAE_IF12_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x319)
end_define

begin_define
define|#
directive|define
name|NAE_IF13_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x31b)
end_define

begin_define
define|#
directive|define
name|NAE_IF14_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x31d)
end_define

begin_define
define|#
directive|define
name|NAE_IF15_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x31f)
end_define

begin_define
define|#
directive|define
name|NAE_IF16_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x321)
end_define

begin_define
define|#
directive|define
name|NAE_IF17_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x323)
end_define

begin_define
define|#
directive|define
name|NAE_IF18_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x325)
end_define

begin_define
define|#
directive|define
name|NAE_IF19_1588_TMSTMP_LO
value|NAE_REG(7, 0, 0x327)
end_define

begin_define
define|#
directive|define
name|NAE_TX_EL0
value|NAE_REG(7, 0, 0x328)
end_define

begin_define
define|#
directive|define
name|NAE_TX_EL1
value|NAE_REG(7, 0, 0x329)
end_define

begin_define
define|#
directive|define
name|NAE_EIC0
value|NAE_REG(7, 0, 0x32a)
end_define

begin_define
define|#
directive|define
name|NAE_EIC1
value|NAE_REG(7, 0, 0x32b)
end_define

begin_define
define|#
directive|define
name|NAE_STG1_STG2CRDT_STATUS
value|NAE_REG(7, 0, 0x32c)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_EHCRDT_STATUS
value|NAE_REG(7, 0, 0x32d)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_FREECRDT_STATUS
value|NAE_REG(7, 0, 0x32e)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_STRCRDT_STATUS
value|NAE_REG(7, 0, 0x32f)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR_INTR_STATUS
value|NAE_REG(7, 0, 0x330)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR_ROLL_STATUS
value|NAE_REG(7, 0, 0x331)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR0
value|NAE_REG(7, 0, 0x332)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR1
value|NAE_REG(7, 0, 0x334)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR2
value|NAE_REG(7, 0, 0x336)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR3
value|NAE_REG(7, 0, 0x338)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR4
value|NAE_REG(7, 0, 0x33a)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR0_CTL
value|NAE_REG(7, 0, 0x333)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR1_CTL
value|NAE_REG(7, 0, 0x335)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR2_CTL
value|NAE_REG(7, 0, 0x337)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR3_CTL
value|NAE_REG(7, 0, 0x339)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PERF_CNTR4_CTL
value|NAE_REG(7, 0, 0x33b)
end_define

begin_define
define|#
directive|define
name|NAE_VFBID_DESTMAP_STATUS
value|NAE_REG(7, 0, 0x380)
end_define

begin_define
define|#
directive|define
name|NAE_STG2_PMEM_STATUS
value|NAE_REG(7, 0, 0x381)
end_define

begin_define
define|#
directive|define
name|NAE_EH_PMEM_STATUS
value|NAE_REG(7, 0, 0x382)
end_define

begin_define
define|#
directive|define
name|NAE_FREE_PMEM_STATUS
value|NAE_REG(7, 0, 0x383)
end_define

begin_define
define|#
directive|define
name|NAE_TX_DDR_ACTVLIST_STATUS
value|NAE_REG(7, 0, 0x384)
end_define

begin_define
define|#
directive|define
name|NAE_TX_IF_BURSTMAX_STATUS
value|NAE_REG(7, 0, 0x385)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PKTLEN_PMEM_STATUS
value|NAE_REG(7, 0, 0x386)
end_define

begin_define
define|#
directive|define
name|NAE_TX_SCHED_MAP_STATUS0
value|NAE_REG(7, 0, 0x387)
end_define

begin_define
define|#
directive|define
name|NAE_TX_SCHED_MAP_STATUS1
value|NAE_REG(7, 0, 0x388)
end_define

begin_define
define|#
directive|define
name|NAE_TX_PKT_PMEM_STATUS
value|NAE_REG(7, 0, 0x389)
end_define

begin_define
define|#
directive|define
name|NAE_STR_PMEM_STATUS
value|NAE_REG(7, 0, 0x38a)
end_define

begin_comment
comment|/* Network interface interrupt registers */
end_comment

begin_define
define|#
directive|define
name|NAE_NET_IF0_INTR_STAT
value|NAE_REG(7, 0, 0x280)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF1_INTR_STAT
value|NAE_REG(7, 0, 0x282)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF2_INTR_STAT
value|NAE_REG(7, 0, 0x284)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF3_INTR_STAT
value|NAE_REG(7, 0, 0x286)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF4_INTR_STAT
value|NAE_REG(7, 0, 0x288)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF5_INTR_STAT
value|NAE_REG(7, 0, 0x28a)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF6_INTR_STAT
value|NAE_REG(7, 0, 0x28c)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF7_INTR_STAT
value|NAE_REG(7, 0, 0x28e)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF8_INTR_STAT
value|NAE_REG(7, 0, 0x290)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF9_INTR_STAT
value|NAE_REG(7, 0, 0x292)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF10_INTR_STAT
value|NAE_REG(7, 0, 0x294)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF11_INTR_STAT
value|NAE_REG(7, 0, 0x296)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF12_INTR_STAT
value|NAE_REG(7, 0, 0x298)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF13_INTR_STAT
value|NAE_REG(7, 0, 0x29a)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF14_INTR_STAT
value|NAE_REG(7, 0, 0x29c)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF15_INTR_STAT
value|NAE_REG(7, 0, 0x29e)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF16_INTR_STAT
value|NAE_REG(7, 0, 0x2a0)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF17_INTR_STAT
value|NAE_REG(7, 0, 0x2a2)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF18_INTR_STAT
value|NAE_REG(7, 0, 0x2a4)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF19_INTR_STAT
value|NAE_REG(7, 0, 0x2a6)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF0_INTR_MASK
value|NAE_REG(7, 0, 0x281)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF1_INTR_MASK
value|NAE_REG(7, 0, 0x283)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF2_INTR_MASK
value|NAE_REG(7, 0, 0x285)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF3_INTR_MASK
value|NAE_REG(7, 0, 0x287)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF4_INTR_MASK
value|NAE_REG(7, 0, 0x289)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF5_INTR_MASK
value|NAE_REG(7, 0, 0x28b)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF6_INTR_MASK
value|NAE_REG(7, 0, 0x28d)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF7_INTR_MASK
value|NAE_REG(7, 0, 0x28f)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF8_INTR_MASK
value|NAE_REG(7, 0, 0x291)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF9_INTR_MASK
value|NAE_REG(7, 0, 0x293)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF10_INTR_MASK
value|NAE_REG(7, 0, 0x295)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF11_INTR_MASK
value|NAE_REG(7, 0, 0x297)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF12_INTR_MASK
value|NAE_REG(7, 0, 0x299)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF13_INTR_MASK
value|NAE_REG(7, 0, 0x29b)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF14_INTR_MASK
value|NAE_REG(7, 0, 0x29d)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF15_INTR_MASK
value|NAE_REG(7, 0, 0x29f)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF16_INTR_MASK
value|NAE_REG(7, 0, 0x2a1)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF17_INTR_MASK
value|NAE_REG(7, 0, 0x2a3)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF18_INTR_MASK
value|NAE_REG(7, 0, 0x2a5)
end_define

begin_define
define|#
directive|define
name|NAE_NET_IF19_INTR_MASK
value|NAE_REG(7, 0, 0x2a7)
end_define

begin_define
define|#
directive|define
name|NAE_COMMON0_INTR_STAT
value|NAE_REG(7, 0, 0x2a8)
end_define

begin_define
define|#
directive|define
name|NAE_COMMON0_INTR_MASK
value|NAE_REG(7, 0, 0x2a9)
end_define

begin_define
define|#
directive|define
name|NAE_COMMON1_INTR_STAT
value|NAE_REG(7, 0, 0x2aa)
end_define

begin_define
define|#
directive|define
name|NAE_COMMON1_INTR_MASK
value|NAE_REG(7, 0, 0x2ab)
end_define

begin_comment
comment|/* Network Interface Low-block Registers */
end_comment

begin_define
define|#
directive|define
name|NAE_PHY_LANE0_STATUS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 0)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE1_STATUS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 1)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE2_STATUS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 2)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE3_STATUS
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 3)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE0_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 4)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE1_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 5)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE2_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 6)
end_define

begin_define
define|#
directive|define
name|NAE_PHY_LANE3_CTRL
parameter_list|(
name|block
parameter_list|)
value|NAE_REG(block, 0xe, 7)
end_define

begin_comment
comment|/* Network interface Top-block registers */
end_comment

begin_define
define|#
directive|define
name|NAE_LANE_CFG_CPLX_0_1
value|NAE_REG(7, 0, 0x780)
end_define

begin_define
define|#
directive|define
name|NAE_LANE_CFG_CPLX_2_3
value|NAE_REG(7, 0, 0x781)
end_define

begin_define
define|#
directive|define
name|NAE_LANE_CFG_CPLX_4
value|NAE_REG(7, 0, 0x782)
end_define

begin_define
define|#
directive|define
name|NAE_LANE_CFG_SOFTRESET
value|NAE_REG(7, 0, 0x783)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_OFFSET_HI
value|NAE_REG(7, 0, 0x784)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_OFFSET_LO
value|NAE_REG(7, 0, 0x785)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_INC_DEN
value|NAE_REG(7, 0, 0x786)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_INC_NUM
value|NAE_REG(7, 0, 0x787)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_INC_INTG
value|NAE_REG(7, 0, 0x788)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_CONTROL
value|NAE_REG(7, 0, 0x789)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_STATUS
value|NAE_REG(7, 0, 0x78a)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_USER_VALUE_HI
value|NAE_REG(7, 0, 0x78b)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_USER_VALUE_LO
value|NAE_REG(7, 0, 0x78c)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR1_HI
value|NAE_REG(7, 0, 0x78d)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR1_LO
value|NAE_REG(7, 0, 0x78e)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR2_HI
value|NAE_REG(7, 0, 0x78f)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR2_LO
value|NAE_REG(7, 0, 0x790)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR3_HI
value|NAE_REG(7, 0, 0x791)
end_define

begin_define
define|#
directive|define
name|NAE_1588_PTP_TMR3_LO
value|NAE_REG(7, 0, 0x792)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_IDX_TBL_CTRL
value|NAE_REG(7, 0, 0x793)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_TBL_CTRL
value|NAE_REG(7, 0, 0x794)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_TBL_DATA0
value|NAE_REG(7, 0, 0x795)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_TBL_DATA1
value|NAE_REG(7, 0, 0x796)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_TBL_DATA2
value|NAE_REG(7, 0, 0x797)
end_define

begin_define
define|#
directive|define
name|NAE_TX_FC_CAL_TBL_DATA3
value|NAE_REG(7, 0, 0x798)
end_define

begin_define
define|#
directive|define
name|NAE_INT_MDIO_CTRL
value|NAE_REG(7, 0, 0x799)
end_define

begin_define
define|#
directive|define
name|NAE_INT_MDIO_CTRL_DATA
value|NAE_REG(7, 0, 0x79a)
end_define

begin_define
define|#
directive|define
name|NAE_INT_MDIO_RD_STAT
value|NAE_REG(7, 0, 0x79b)
end_define

begin_define
define|#
directive|define
name|NAE_INT_MDIO_LINK_STAT
value|NAE_REG(7, 0, 0x79c)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G0_MDIO_CTRL
value|NAE_REG(7, 0, 0x79d)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G1_MDIO_CTRL
value|NAE_REG(7, 0, 0x7a1)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G0_MDIO_CTRL_DATA
value|NAE_REG(7, 0, 0x79e)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G1_MDIO_CTRL_DATA
value|NAE_REG(7, 0, 0x7a2)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G0_MDIO_RD_STAT
value|NAE_REG(7, 0, 0x79f)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G1_MDIO_RD_STAT
value|NAE_REG(7, 0, 0x7a3)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G0_MDIO_LINK_STAT
value|NAE_REG(7, 0, 0x7a0)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_G1_MDIO_LINK_STAT
value|NAE_REG(7, 0, 0x7a4)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG0_MDIO_CTRL
value|NAE_REG(7, 0, 0x7a5)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG1_MDIO_CTRL
value|NAE_REG(7, 0, 0x7a9)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG0_MDIO_CTRL_DATA
value|NAE_REG(7, 0, 0x7a6)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG1_MDIO_CTRL_DATA
value|NAE_REG(7, 0, 0x7aa)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG0_MDIO_RD_STAT
value|NAE_REG(7, 0, 0x7a7)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG1_MDIO_RD_STAT
value|NAE_REG(7, 0, 0x7ab)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG0_MDIO_LINK_STAT
value|NAE_REG(7, 0, 0x7a8)
end_define

begin_define
define|#
directive|define
name|NAE_EXT_XG1_MDIO_LINK_STAT
value|NAE_REG(7, 0, 0x7ac)
end_define

begin_define
define|#
directive|define
name|NAE_GMAC_FC_SLOT0
value|NAE_REG(7, 0, 0x7ad)
end_define

begin_define
define|#
directive|define
name|NAE_GMAC_FC_SLOT1
value|NAE_REG(7, 0, 0x7ae)
end_define

begin_define
define|#
directive|define
name|NAE_GMAC_FC_SLOT2
value|NAE_REG(7, 0, 0x7af)
end_define

begin_define
define|#
directive|define
name|NAE_GMAC_FC_SLOT3
value|NAE_REG(7, 0, 0x7b0)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_NTB_SLOT
value|NAE_REG(7, 0, 0x7b1)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_MISC_CTRL0
value|NAE_REG(7, 0, 0x7b2)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT0
value|NAE_REG(7, 0, 0x7b3)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT0_MASK
value|NAE_REG(7, 0, 0x7b4)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT1
value|NAE_REG(7, 0, 0x7b5)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT1_MASK
value|NAE_REG(7, 0, 0x7b6)
end_define

begin_define
define|#
directive|define
name|NAE_GMAC_PFC_REPEAT
value|NAE_REG(7, 0, 0x7b7)
end_define

begin_define
define|#
directive|define
name|NAE_XGMAC_PFC_REPEAT
value|NAE_REG(7, 0, 0x7b8)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_MISC_CTRL1
value|NAE_REG(7, 0, 0x7b9)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_MISC_CTRL2
value|NAE_REG(7, 0, 0x7ba)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT2
value|NAE_REG(7, 0, 0x7bb)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_INT2_MASK
value|NAE_REG(7, 0, 0x7bc)
end_define

begin_define
define|#
directive|define
name|NAE_NETIOR_MISC_CTRL3
value|NAE_REG(7, 0, 0x7bd)
end_define

begin_comment
comment|/* Network interface lane configuration registers */
end_comment

begin_define
define|#
directive|define
name|NAE_LANE_CFG_MISCREG1
value|NAE_REG(7, 0xf, 0x39)
end_define

begin_define
define|#
directive|define
name|NAE_LANE_CFG_MISCREG2
value|NAE_REG(7, 0xf, 0x3A)
end_define

begin_comment
comment|/* Network interface soft reset register */
end_comment

begin_define
define|#
directive|define
name|NAE_SOFT_RESET
value|NAE_REG(7, 0xf, 3)
end_define

begin_comment
comment|/* ucore instruction/shared CAM RAM access */
end_comment

begin_define
define|#
directive|define
name|NAE_UCORE_SHARED_RAM_OFFSET
value|0x10000
end_define

begin_define
define|#
directive|define
name|PORTS_PER_CMPLX
value|4
end_define

begin_define
define|#
directive|define
name|NAE_CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|PHY_LANE_0_CTRL
value|4
end_define

begin_define
define|#
directive|define
name|PHY_LANE_1_CTRL
value|5
end_define

begin_define
define|#
directive|define
name|PHY_LANE_2_CTRL
value|6
end_define

begin_define
define|#
directive|define
name|PHY_LANE_3_CTRL
value|7
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_SRCS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_STD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_SFEA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_STCS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_SPC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_XLF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PHY_LANE_STAT_PCR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_DATA_POS
value|0
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_ADDR_POS
value|8
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_CMD_READ
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_CMD_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_CMD_START
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_CMD_PENDING
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_ALL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_FAST_INIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_REXSEL_POS
value|23
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_PHYMODE_POS
value|25
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_PWRDOWN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_RST
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_RST_XAUI
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|PHY_LANE_CTRL_BPC_XAUI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LANE_CFG_CPLX_0_1
value|0x0
end_define

begin_define
define|#
directive|define
name|LANE_CFG_CPLX_2_3
value|0x1
end_define

begin_define
define|#
directive|define
name|LANE_CFG_CPLX_4
value|0x2
end_define

begin_define
define|#
directive|define
name|MAC_CONF1
value|0x0
end_define

begin_define
define|#
directive|define
name|MAC_CONF2
value|0x1
end_define

begin_define
define|#
directive|define
name|MAX_FRM
value|0x4
end_define

begin_define
define|#
directive|define
name|NETIOR_GMAC_CTRL1
value|0x7F
end_define

begin_define
define|#
directive|define
name|NETIOR_GMAC_CTRL2
value|0x7E
end_define

begin_define
define|#
directive|define
name|NETIOR_GMAC_CTRL3
value|0x7C
end_define

begin_define
define|#
directive|define
name|SGMII_CAL_SLOTS
value|3
end_define

begin_define
define|#
directive|define
name|XAUI_CAL_SLOTS
value|13
end_define

begin_define
define|#
directive|define
name|IL8_CAL_SLOTS
value|26
end_define

begin_define
define|#
directive|define
name|IL4_CAL_SLOTS
value|10
end_define

begin_define
define|#
directive|define
name|NAE_DRR_QUANTA
value|2048
end_define

begin_define
define|#
directive|define
name|XLP3XX_STG2_FIFO_SZ
value|512
end_define

begin_define
define|#
directive|define
name|XLP3XX_EH_FIFO_SZ
value|512
end_define

begin_define
define|#
directive|define
name|XLP3XX_FROUT_FIFO_SZ
value|512
end_define

begin_define
define|#
directive|define
name|XLP3XX_MS_FIFO_SZ
value|512
end_define

begin_define
define|#
directive|define
name|XLP3XX_PKT_FIFO_SZ
value|8192
end_define

begin_define
define|#
directive|define
name|XLP3XX_PKTLEN_FIFO_SZ
value|512
end_define

begin_define
define|#
directive|define
name|XLP3XX_MAX_STG2_OFFSET
value|0x7F
end_define

begin_define
define|#
directive|define
name|XLP3XX_MAX_EH_OFFSET
value|0x1f
end_define

begin_define
define|#
directive|define
name|XLP3XX_MAX_FREE_OUT_OFFSET
value|0x1f
end_define

begin_define
define|#
directive|define
name|XLP3XX_MAX_MS_OFFSET
value|0xF
end_define

begin_define
define|#
directive|define
name|XLP3XX_MAX_PMEM_OFFSET
value|0x7FE
end_define

begin_define
define|#
directive|define
name|XLP3XX_STG1_2_CREDIT
value|XLP3XX_STG2_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP3XX_STG2_EH_CREDIT
value|XLP3XX_EH_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP3XX_STG2_FROUT_CREDIT
value|XLP3XX_FROUT_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP3XX_STG2_MS_CREDIT
value|XLP3XX_MS_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP8XX_STG2_FIFO_SZ
value|2048
end_define

begin_define
define|#
directive|define
name|XLP8XX_EH_FIFO_SZ
value|4096
end_define

begin_define
define|#
directive|define
name|XLP8XX_FROUT_FIFO_SZ
value|4096
end_define

begin_define
define|#
directive|define
name|XLP8XX_MS_FIFO_SZ
value|2048
end_define

begin_define
define|#
directive|define
name|XLP8XX_PKT_FIFO_SZ
value|16384
end_define

begin_define
define|#
directive|define
name|XLP8XX_PKTLEN_FIFO_SZ
value|2048
end_define

begin_define
define|#
directive|define
name|XLP8XX_MAX_STG2_OFFSET
value|0x7F
end_define

begin_define
define|#
directive|define
name|XLP8XX_MAX_EH_OFFSET
value|0x7F
end_define

begin_define
define|#
directive|define
name|XLP8XX_MAX_FREE_OUT_OFFSET
value|0x7F
end_define

begin_define
define|#
directive|define
name|XLP8XX_MAX_MS_OFFSET
value|0x1F
end_define

begin_define
define|#
directive|define
name|XLP8XX_MAX_PMEM_OFFSET
value|0x7FE
end_define

begin_define
define|#
directive|define
name|XLP8XX_STG1_2_CREDIT
value|XLP8XX_STG2_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP8XX_STG2_EH_CREDIT
value|XLP8XX_EH_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP8XX_STG2_FROUT_CREDIT
value|XLP8XX_FROUT_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|XLP8XX_STG2_MS_CREDIT
value|XLP8XX_MS_FIFO_SZ
end_define

begin_define
define|#
directive|define
name|MAX_CAL_SLOTS
value|64
end_define

begin_define
define|#
directive|define
name|XLP_MAX_PORTS
value|18
end_define

begin_define
define|#
directive|define
name|XLP_STORM_MAX_PORTS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_FREE_FIFO_POOL_8XX
value|20
end_define

begin_define
define|#
directive|define
name|MAX_FREE_FIFO_POOL_3XX
value|9
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

begin_define
define|#
directive|define
name|nlm_read_nae_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg_xkphys(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_nae_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg_xkphys(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_nae_pcibase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_NAE_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_nae_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_xkphys_map_pcibar0(nlm_get_nae_pcibase(node))
end_define

begin_define
define|#
directive|define
name|MAX_POE_CLASSES
value|8
end_define

begin_define
define|#
directive|define
name|MAX_POE_CLASS_CTXT_TBL_SZ
value|((NUM_CONTEXTS / MAX_POE_CLASSES) + 1)
end_define

begin_define
define|#
directive|define
name|TXINITIORCR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7ffff)<< 8)
end_define

begin_enum
enum|enum
name|XLPNAE_TX_TYPE
block|{
name|P2D_NEOP
init|=
literal|0
block|,
name|P2P
block|,
name|P2D_EOP
block|,
name|MSC
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nblock_type
block|{
name|UNKNOWN
init|=
literal|0
block|,
comment|/* DONT MAKE IT NON-ZERO */
name|SGMIIC
init|=
literal|1
block|,
name|XAUIC
init|=
literal|2
block|,
name|ILC
init|=
literal|3
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nae_interface_type
block|{
name|GMAC_0
init|=
literal|0
block|,
name|GMAC_1
block|,
name|GMAC_2
block|,
name|GMAC_3
block|,
name|XGMAC
block|,
name|INTERLAKEN
block|,
name|PHY
init|=
literal|0xE
block|,
name|LANE_CFG
init|=
literal|0xF
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|LM_UNCONNECTED
init|=
literal|0
block|,
name|LM_SGMII
init|=
literal|1
block|,
name|LM_XAUI
init|=
literal|2
block|,
name|LM_IL
init|=
literal|3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|nae_block
block|{
name|BLOCK_0
init|=
literal|0
block|,
name|BLOCK_1
block|,
name|BLOCK_2
block|,
name|BLOCK_3
block|,
name|BLOCK_4
block|,
name|BLOCK_5
block|,
name|BLOCK_6
block|,
name|BLOCK_7
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PHYMODE_NONE
init|=
literal|0
block|,
name|PHYMODE_HS_SGMII
init|=
literal|1
block|,
name|PHYMODE_XAUI
init|=
literal|1
block|,
name|PHYMODE_SGMII
init|=
literal|2
block|,
name|PHYMODE_IL
init|=
literal|3
block|, }
enum|;
end_enum

begin_function
specifier|static
name|__inline
name|int
name|nae_num_complex
parameter_list|(
name|uint64_t
name|nae_pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|nae_pcibase
argument_list|,
name|XLP_PCI_DEVINFO_REG0
argument_list|)
operator|&
literal|0xff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|nae_num_context
parameter_list|(
name|uint64_t
name|nae_pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|nae_pcibase
argument_list|,
name|XLP_PCI_DEVINFO_REG5
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* per port config structure */
end_comment

begin_struct
struct|struct
name|nae_port_config
block|{
name|int
name|node
decl_stmt|;
comment|/* node id (quickread) */
name|int
name|block
decl_stmt|;
comment|/* network block id (quickread) */
name|int
name|port
decl_stmt|;
comment|/* port id - among the 18 in XLP */
name|int
name|type
decl_stmt|;
comment|/* port type - see xlp_gmac_port_types */
name|int
name|mdio_bus
decl_stmt|;
name|int
name|phy_addr
decl_stmt|;
name|int
name|num_channels
decl_stmt|;
name|int
name|num_free_descs
decl_stmt|;
name|int
name|free_desc_sizes
decl_stmt|;
name|int
name|ucore_mask
decl_stmt|;
name|int
name|loopback_mode
decl_stmt|;
comment|/* is complex is in loopback? */
name|uint32_t
name|freein_spill_size
decl_stmt|;
comment|/* Freein spill size for each port */
name|uint32_t
name|free_fifo_size
decl_stmt|;
comment|/* (512entries x 2desc/entry)1024desc */
name|uint32_t
name|iface_fifo_size
decl_stmt|;
comment|/* 256 entries x 64B/entry    = 16KB */
name|uint32_t
name|pseq_fifo_size
decl_stmt|;
comment|/* 1024 entries - 1 pktlen/entry */
name|uint32_t
name|rxbuf_size
decl_stmt|;
comment|/* 4096 entries x 64B = 256KB */
name|uint32_t
name|rx_if_base_config
decl_stmt|;
name|uint32_t
name|rx_slots_reqd
decl_stmt|;
name|uint32_t
name|tx_slots_reqd
decl_stmt|;
name|uint32_t
name|stg2_fifo_size
decl_stmt|;
name|uint32_t
name|eh_fifo_size
decl_stmt|;
name|uint32_t
name|frout_fifo_size
decl_stmt|;
name|uint32_t
name|ms_fifo_size
decl_stmt|;
name|uint32_t
name|pkt_fifo_size
decl_stmt|;
name|uint32_t
name|pktlen_fifo_size
decl_stmt|;
name|uint32_t
name|max_stg2_offset
decl_stmt|;
name|uint32_t
name|max_eh_offset
decl_stmt|;
name|uint32_t
name|max_frout_offset
decl_stmt|;
name|uint32_t
name|max_ms_offset
decl_stmt|;
name|uint32_t
name|max_pmem_offset
decl_stmt|;
name|uint32_t
name|stg1_2_credit
decl_stmt|;
name|uint32_t
name|stg2_eh_credit
decl_stmt|;
name|uint32_t
name|stg2_frout_credit
decl_stmt|;
name|uint32_t
name|stg2_ms_credit
decl_stmt|;
name|uint32_t
name|vlan_pri_en
decl_stmt|;
name|uint32_t
name|txq
decl_stmt|;
name|uint32_t
name|rxfreeq
decl_stmt|;
name|uint32_t
name|ieee1588_inc_intg
decl_stmt|;
name|uint32_t
name|ieee1588_inc_den
decl_stmt|;
name|uint32_t
name|ieee1588_inc_num
decl_stmt|;
name|uint64_t
name|ieee1588_userval
decl_stmt|;
name|uint64_t
name|ieee1588_ptpoff
decl_stmt|;
name|uint64_t
name|ieee1588_tmr1
decl_stmt|;
name|uint64_t
name|ieee1588_tmr2
decl_stmt|;
name|uint64_t
name|ieee1588_tmr3
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|nlm_nae_flush_free_fifo
parameter_list|(
name|uint64_t
name|nae_base
parameter_list|,
name|int
name|nblocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_program_nae_parser_seq_fifo
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_rx_cal_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_tx_cal_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_deflate_frin_fifo_carving
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_reset_nae
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_set_nae_frequency
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_poe_class_config
parameter_list|(
name|uint64_t
name|nae_base
parameter_list|,
name|int
name|max_poe_classes
parameter_list|,
name|int
name|num_contexts
parameter_list|,
name|int
modifier|*
name|poe_cl_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_vfbid_mapping
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_flow_crc_poly
parameter_list|(
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_iface_fifo_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_rx_base_config
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_rx_buf_config
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_freein_fifo_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_get_flow_mask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_program_flow_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlp_ax_nae_lane_reset_txpll
parameter_list|(
name|uint64_t
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
name|xlp_nae_lane_reset_txpll
parameter_list|(
name|uint64_t
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
name|xlp_nae_config_lane_gmac
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_egress_fifo_carvings
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
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_egress_fifo_credits
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
name|struct
name|nae_port_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_config_freein_fifo_uniq_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_config_ucore_iface_mask_cfg
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_nae_init_netior
parameter_list|(
name|uint64_t
name|nae_base
parameter_list|,
name|int
name|nblocks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_init_ingress
parameter_list|(
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_init_egress
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ucore_spray_config
parameter_list|(
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_nae_init_ucore
parameter_list|(
name|uint64_t
name|nae_base
parameter_list|,
name|int
name|if_num
parameter_list|,
name|uint32_t
name|ucore_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_nae_open_if
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_mac_enable
parameter_list|(
name|uint64_t
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
name|nlm_mac_disable
parameter_list|(
name|uint64_t
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
name|uint64_t
name|nae_tx_desc
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l2type
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l3ctable_mask
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l3ctable_even
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l3ctable_odd
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l4ctable_even
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_l4ctable_odd
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_enable_hardware_parser
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_enable_hardware_parser_per_port
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_prepad_enable
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_setup_1588_timer
parameter_list|(
name|uint64_t
parameter_list|,
name|struct
name|nae_port_config
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

