begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Cavium Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NIC_REG_H
end_ifndef

begin_define
define|#
directive|define
name|NIC_REG_H
end_define

begin_define
define|#
directive|define
name|NIC_PF_REG_COUNT
value|29573
end_define

begin_define
define|#
directive|define
name|NIC_VF_REG_COUNT
value|249
end_define

begin_comment
comment|/* Physical function register offsets */
end_comment

begin_define
define|#
directive|define
name|NIC_PF_CFG
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_STATUS
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTR_TIMER_CFG
value|(0x0030)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BIST_STATUS
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|NIC_PF_SOFT_RESET
value|(0x0050)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TCP_TIMER
value|(0x0060)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BP_CFG
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|NIC_PF_RRM_CFG
value|(0x0088)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CQM_CF
value|(0x00A0)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CNM_CF
value|(0x00A8)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CNM_STATUS
value|(0x00B0)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CQ_AVG_CFG
value|(0x00C0)
end_define

begin_define
define|#
directive|define
name|NIC_PF_RRM_AVG_CFG
value|(0x00C8)
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTF_0_1_SEND_CFG
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTF_0_1_BP_CFG
value|(0x0208)
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTF_0_1_BP_DIS_0_1
value|(0x0210)
end_define

begin_define
define|#
directive|define
name|NIC_PF_INTF_0_1_BP_SW_0_1
value|(0x0220)
end_define

begin_define
define|#
directive|define
name|NIC_PF_RBDR_BP_STATE_0_3
value|(0x0240)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MAILBOX_INT
value|(0x0410)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MAILBOX_INT_W1S
value|(0x0430)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MAILBOX_ENA_W1C
value|(0x0450)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MAILBOX_ENA_W1S
value|(0x0470)
end_define

begin_define
define|#
directive|define
name|NIC_PF_RX_ETYPE_0_7
value|(0x0500)
end_define

begin_define
define|#
directive|define
name|NIC_PF_PKIND_0_15_CFG
value|(0x0600)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_FLIP0
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_FLIP0
value|(0x1008)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_FLIP0
value|(0x1010)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_FLIP0
value|(0x1018)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_FLIP1
value|(0x1080)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_FLIP1
value|(0x1088)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_FLIP1
value|(0x1090)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_FLIP1
value|(0x1098)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_CDIS
value|(0x1100)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_CDIS
value|(0x1108)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_CDIS
value|(0x1110)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_CDIS
value|(0x1118)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BIST0_STATUS
value|(0x1280)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BIST1_STATUS
value|(0x1288)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BIST2_STATUS
value|(0x1290)
end_define

begin_define
define|#
directive|define
name|NIC_PF_BIST3_STATUS
value|(0x1298)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_SBE_INT
value|(0x2000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_SBE_INT_W1S
value|(0x2008)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_SBE_ENA_W1C
value|(0x2010)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_SBE_ENA_W1S
value|(0x2018)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_DBE_INT
value|(0x2100)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_DBE_INT_W1S
value|(0x2108)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_DBE_ENA_W1C
value|(0x2110)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC0_DBE_ENA_W1S
value|(0x2118)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_SBE_INT
value|(0x2200)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_SBE_INT_W1S
value|(0x2208)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_SBE_ENA_W1C
value|(0x2210)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_SBE_ENA_W1S
value|(0x2218)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_DBE_INT
value|(0x2300)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_DBE_INT_W1S
value|(0x2308)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_DBE_ENA_W1C
value|(0x2310)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC1_DBE_ENA_W1S
value|(0x2318)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_SBE_INT
value|(0x2400)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_SBE_INT_W1S
value|(0x2408)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_SBE_ENA_W1C
value|(0x2410)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_SBE_ENA_W1S
value|(0x2418)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_DBE_INT
value|(0x2500)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_DBE_INT_W1S
value|(0x2508)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_DBE_ENA_W1C
value|(0x2510)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC2_DBE_ENA_W1S
value|(0x2518)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_SBE_INT
value|(0x2600)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_SBE_INT_W1S
value|(0x2608)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_SBE_ENA_W1C
value|(0x2610)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_SBE_ENA_W1S
value|(0x2618)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_DBE_INT
value|(0x2700)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_DBE_INT_W1S
value|(0x2708)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_DBE_ENA_W1C
value|(0x2710)
end_define

begin_define
define|#
directive|define
name|NIC_PF_ECC3_DBE_ENA_W1S
value|(0x2718)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CPI_0_2047_CFG
value|(0x200000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MPI_0_2047_CFG
value|(0x210000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_RSSI_0_4097_RQ
value|(0x220000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_LMAC_0_7_CFG
value|(0x240000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_LMAC_0_7_SW_XOFF
value|(0x242000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_LMAC_0_7_CREDIT
value|(0x244000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CHAN_0_255_TX_CFG
value|(0x400000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CHAN_0_255_RX_CFG
value|(0x420000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CHAN_0_255_SW_XOFF
value|(0x440000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CHAN_0_255_CREDIT
value|(0x460000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_CHAN_0_255_RX_BP_CFG
value|(0x480000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_SW_SYNC_RX
value|(0x490000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_SW_SYNC_RX_DONE
value|(0x490008)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL2_0_63_CFG
value|(0x500000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL2_0_63_PRI
value|(0x520000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL2_0_63_SH_STATUS
value|(0x580000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3A_0_63_CFG
value|(0x5F0000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_CFG
value|(0x600000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_CHAN
value|(0x620000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_PIR
value|(0x640000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_SW_XOFF
value|(0x660000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_CNM_RATE
value|(0x680000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL3_0_255_SH_STATUS
value|(0x6A0000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4A_0_255_CFG
value|(0x6F0000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4_0_1023_CFG
value|(0x800000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4_0_1023_SW_XOFF
value|(0x820000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4_0_1023_SH_STATUS
value|(0x840000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4A_0_1023_CNM_RATE
value|(0x880000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_TL4A_0_1023_CNM_STATUS
value|(0x8A0000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_VF_0_127_MAILBOX_0_1
value|(0x20002030)
end_define

begin_define
define|#
directive|define
name|NIC_PF_VNIC_0_127_TX_STAT_0_4
value|(0x20004000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_VNIC_0_127_RX_STAT_0_13
value|(0x20004100)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_LOCK_0_15
value|(0x20006000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_CFG
value|(0x20010000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_RQ_0_7_CFG
value|(0x20010400)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_RQ_0_7_DROP_CFG
value|(0x20010420)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_RQ_0_7_BP_CFG
value|(0x20010500)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_RQ_0_7_STAT_0_1
value|(0x20010600)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_SQ_0_7_CFG
value|(0x20010C00)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_SQ_0_7_CFG2
value|(0x20010C08)
end_define

begin_define
define|#
directive|define
name|NIC_PF_QSET_0_127_SQ_0_7_STAT_0_1
value|(0x20010D00)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MSIX_VEC_0_18_ADDR
value|(0x000000)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MSIX_VEC_0_CTL
value|(0x000008)
end_define

begin_define
define|#
directive|define
name|NIC_PF_MSIX_PBA_0
value|(0x0F0000)
end_define

begin_comment
comment|/* Virtual function register offsets */
end_comment

begin_define
define|#
directive|define
name|NIC_VNIC_CFG
value|(0x000020)
end_define

begin_define
define|#
directive|define
name|NIC_VF_PF_MAILBOX_0_1
value|(0x000130)
end_define

begin_define
define|#
directive|define
name|NIC_VF_INT
value|(0x000200)
end_define

begin_define
define|#
directive|define
name|NIC_VF_INT_W1S
value|(0x000220)
end_define

begin_define
define|#
directive|define
name|NIC_VF_ENA_W1C
value|(0x000240)
end_define

begin_define
define|#
directive|define
name|NIC_VF_ENA_W1S
value|(0x000260)
end_define

begin_define
define|#
directive|define
name|NIC_VNIC_RSS_CFG
value|(0x0020E0)
end_define

begin_define
define|#
directive|define
name|NIC_VNIC_RSS_KEY_0_4
value|(0x002200)
end_define

begin_define
define|#
directive|define
name|NIC_VNIC_TX_STAT_0_4
value|(0x004000)
end_define

begin_define
define|#
directive|define
name|NIC_VNIC_RX_STAT_0_13
value|(0x004100)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RQ_GEN_CFG
value|(0x010010)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_CFG
value|(0x010400)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_CFG2
value|(0x010408)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_THRESH
value|(0x010410)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_BASE
value|(0x010420)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_HEAD
value|(0x010428)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_TAIL
value|(0x010430)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_DOOR
value|(0x010438)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_STATUS
value|(0x010440)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_STATUS2
value|(0x010448)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_CQ_0_7_DEBUG
value|(0x010450)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RQ_0_7_CFG
value|(0x010600)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RQ_0_7_STAT_0_1
value|(0x010700)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_CFG
value|(0x010800)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_THRESH
value|(0x010810)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_BASE
value|(0x010820)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_HEAD
value|(0x010828)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_TAIL
value|(0x010830)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_DOOR
value|(0x010838)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_STATUS
value|(0x010840)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_DEBUG
value|(0x010848)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_CNM_CHG
value|(0x010860)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_SQ_0_7_STAT_0_1
value|(0x010900)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_CFG
value|(0x010C00)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_THRESH
value|(0x010C10)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_BASE
value|(0x010C20)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_HEAD
value|(0x010C28)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_TAIL
value|(0x010C30)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_DOOR
value|(0x010C38)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_STATUS0
value|(0x010C40)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_STATUS1
value|(0x010C48)
end_define

begin_define
define|#
directive|define
name|NIC_QSET_RBDR_0_1_PREFETCH_STATUS
value|(0x010C50)
end_define

begin_define
define|#
directive|define
name|NIC_VF_MSIX_VECTOR_0_19_ADDR
value|(0x000000)
end_define

begin_define
define|#
directive|define
name|NIC_VF_MSIX_VECTOR_0_19_CTL
value|(0x000008)
end_define

begin_define
define|#
directive|define
name|NIC_VF_MSIX_PBA
value|(0x0F0000)
end_define

begin_comment
comment|/* Offsets within registers */
end_comment

begin_define
define|#
directive|define
name|NIC_MSIX_VEC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|NIC_Q_NUM_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|NIC_QS_ID_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|NIC_VF_NUM_SHIFT
value|21
end_define

begin_comment
comment|/* Port kind configuration register */
end_comment

begin_struct
struct|struct
name|pkind_cfg
block|{
name|uint64_t
name|minlen
range|:
literal|16
decl_stmt|;
name|uint64_t
name|maxlen
range|:
literal|16
decl_stmt|;
name|uint64_t
name|reserved_32_32
range|:
literal|1
decl_stmt|;
name|uint64_t
name|lenerr_en
range|:
literal|1
decl_stmt|;
name|uint64_t
name|rx_hdr
range|:
literal|3
decl_stmt|;
name|uint64_t
name|hdr_sl
range|:
literal|5
decl_stmt|;
name|uint64_t
name|reserved_42_63
range|:
literal|22
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NIC_REG_H */
end_comment

end_unit

