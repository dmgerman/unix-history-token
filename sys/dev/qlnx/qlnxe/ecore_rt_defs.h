begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RT_DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__RT_DEFS_H__
end_define

begin_comment
comment|/* Runtime array offsets */
end_comment

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_0_RT_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_1_RT_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_2_RT_OFFSET
value|2
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_3_RT_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_4_RT_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_5_RT_OFFSET
value|5
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_6_RT_OFFSET
value|6
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_MAX_ICID_7_RT_OFFSET
value|7
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_0_RT_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_1_RT_OFFSET
value|9
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_2_RT_OFFSET
value|10
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_3_RT_OFFSET
value|11
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_4_RT_OFFSET
value|12
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_5_RT_OFFSET
value|13
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_6_RT_OFFSET
value|14
end_define

begin_define
define|#
directive|define
name|DORQ_REG_VF_MAX_ICID_7_RT_OFFSET
value|15
end_define

begin_define
define|#
directive|define
name|DORQ_REG_PF_WAKE_ALL_RT_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|DORQ_REG_TAG1_ETHERTYPE_RT_OFFSET
value|17
end_define

begin_define
define|#
directive|define
name|IGU_REG_PF_CONFIGURATION_RT_OFFSET
value|18
end_define

begin_define
define|#
directive|define
name|IGU_REG_VF_CONFIGURATION_RT_OFFSET
value|19
end_define

begin_define
define|#
directive|define
name|IGU_REG_ATTN_MSG_ADDR_L_RT_OFFSET
value|20
end_define

begin_define
define|#
directive|define
name|IGU_REG_ATTN_MSG_ADDR_H_RT_OFFSET
value|21
end_define

begin_define
define|#
directive|define
name|IGU_REG_LEADING_EDGE_LATCH_RT_OFFSET
value|22
end_define

begin_define
define|#
directive|define
name|IGU_REG_TRAILING_EDGE_LATCH_RT_OFFSET
value|23
end_define

begin_define
define|#
directive|define
name|CAU_REG_CQE_AGG_UNIT_SIZE_RT_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_OFFSET
value|1049
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_OFFSET
value|1049
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_ADDR_MEMORY_RT_OFFSET
value|2073
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_ADDR_MEMORY_RT_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CAU_REG_PI_MEMORY_RT_OFFSET
value|3097
end_define

begin_define
define|#
directive|define
name|CAU_REG_PI_MEMORY_RT_SIZE
value|4416
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_RESP_INITIATOR_TYPE_RT_OFFSET
value|7513
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_INITIATOR_PF_RT_OFFSET
value|7514
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_INITIATOR_VF_RT_OFFSET
value|7515
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_TARGET_PF_RT_OFFSET
value|7516
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_TARGET_VF_RT_OFFSET
value|7517
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_TCP_RT_OFFSET
value|7518
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_FCOE_RT_OFFSET
value|7519
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_ROCE_RT_OFFSET
value|7520
end_define

begin_define
define|#
directive|define
name|PRS_REG_ROCE_DEST_QP_MAX_VF_RT_OFFSET
value|7521
end_define

begin_define
define|#
directive|define
name|PRS_REG_ROCE_DEST_QP_MAX_PF_RT_OFFSET
value|7522
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_OPENFLOW_RT_OFFSET
value|7523
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_NON_IP_AS_OPENFLOW_RT_OFFSET
value|7524
end_define

begin_define
define|#
directive|define
name|PRS_REG_OPENFLOW_SUPPORT_ONLY_KNOWN_OVER_IP_RT_OFFSET
value|7525
end_define

begin_define
define|#
directive|define
name|PRS_REG_OPENFLOW_SEARCH_KEY_MASK_RT_OFFSET
value|7526
end_define

begin_define
define|#
directive|define
name|PRS_REG_TAG_ETHERTYPE_0_RT_OFFSET
value|7527
end_define

begin_define
define|#
directive|define
name|PRS_REG_LIGHT_L2_ETHERTYPE_EN_RT_OFFSET
value|7528
end_define

begin_define
define|#
directive|define
name|SRC_REG_FIRSTFREE_RT_OFFSET
value|7529
end_define

begin_define
define|#
directive|define
name|SRC_REG_FIRSTFREE_RT_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|SRC_REG_LASTFREE_RT_OFFSET
value|7531
end_define

begin_define
define|#
directive|define
name|SRC_REG_LASTFREE_RT_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|SRC_REG_COUNTFREE_RT_OFFSET
value|7533
end_define

begin_define
define|#
directive|define
name|SRC_REG_NUMBER_HASH_BITS_RT_OFFSET
value|7534
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_P_SIZE_RT_OFFSET
value|7535
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_P_SIZE_RT_OFFSET
value|7536
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_P_SIZE_RT_OFFSET
value|7537
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_P_SIZE_RT_OFFSET
value|7538
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_P_SIZE_RT_OFFSET
value|7539
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_P_SIZE_RT_OFFSET
value|7540
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_FIRST_ILT_RT_OFFSET
value|7541
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_LAST_ILT_RT_OFFSET
value|7542
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_FIRST_ILT_RT_OFFSET
value|7543
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_LAST_ILT_RT_OFFSET
value|7544
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_FIRST_ILT_RT_OFFSET
value|7545
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_LAST_ILT_RT_OFFSET
value|7546
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_FIRST_ILT_RT_OFFSET
value|7547
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_LAST_ILT_RT_OFFSET
value|7548
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_FIRST_ILT_RT_OFFSET
value|7549
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_LAST_ILT_RT_OFFSET
value|7550
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_FIRST_ILT_RT_OFFSET
value|7551
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_LAST_ILT_RT_OFFSET
value|7552
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|7553
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|7554
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|7555
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_VF_BLOCKS_RT_OFFSET
value|7556
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_VF_BLOCKS_RT_OFFSET
value|7557
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_VF_BLOCKS_RT_OFFSET
value|7558
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_BLOCKS_FACTOR_RT_OFFSET
value|7559
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_BLOCKS_FACTOR_RT_OFFSET
value|7560
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_BLOCKS_FACTOR_RT_OFFSET
value|7561
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_VF_BASE_RT_OFFSET
value|7562
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_VF_LAST_ILT_RT_OFFSET
value|7563
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_DRAM_ALIGN_WR_RT_OFFSET
value|7564
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_DRAM_ALIGN_RD_RT_OFFSET
value|7565
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_ILT_MEMORY_RT_OFFSET
value|7566
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_ILT_MEMORY_RT_SIZE
value|22000
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_VF_BASE_RT_OFFSET
value|29566
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_MSDM_OFFSET_MASK_B_RT_OFFSET
value|29567
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_MSDM_VF_SHIFT_B_RT_OFFSET
value|29568
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_CACHE_LINE_SIZE_RT_OFFSET
value|29569
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_PF_BAR0_SIZE_RT_OFFSET
value|29570
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_PF_BAR1_SIZE_RT_OFFSET
value|29571
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_VF_BAR1_SIZE_RT_OFFSET
value|29572
end_define

begin_define
define|#
directive|define
name|TM_REG_VF_ENABLE_CONN_RT_OFFSET
value|29573
end_define

begin_define
define|#
directive|define
name|TM_REG_PF_ENABLE_CONN_RT_OFFSET
value|29574
end_define

begin_define
define|#
directive|define
name|TM_REG_PF_ENABLE_TASK_RT_OFFSET
value|29575
end_define

begin_define
define|#
directive|define
name|TM_REG_GROUP_SIZE_RESOLUTION_CONN_RT_OFFSET
value|29576
end_define

begin_define
define|#
directive|define
name|TM_REG_GROUP_SIZE_RESOLUTION_TASK_RT_OFFSET
value|29577
end_define

begin_define
define|#
directive|define
name|TM_REG_CONFIG_CONN_MEM_RT_OFFSET
value|29578
end_define

begin_define
define|#
directive|define
name|TM_REG_CONFIG_CONN_MEM_RT_SIZE
value|416
end_define

begin_define
define|#
directive|define
name|TM_REG_CONFIG_TASK_MEM_RT_OFFSET
value|29994
end_define

begin_define
define|#
directive|define
name|TM_REG_CONFIG_TASK_MEM_RT_SIZE
value|608
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZE_0_RT_OFFSET
value|30602
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZE_1_RT_OFFSET
value|30603
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZE_2_RT_OFFSET
value|30604
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_0_RT_OFFSET
value|30605
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_1_RT_OFFSET
value|30606
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_2_RT_OFFSET
value|30607
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_3_RT_OFFSET
value|30608
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_4_RT_OFFSET
value|30609
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_5_RT_OFFSET
value|30610
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_6_RT_OFFSET
value|30611
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_7_RT_OFFSET
value|30612
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_8_RT_OFFSET
value|30613
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_9_RT_OFFSET
value|30614
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_10_RT_OFFSET
value|30615
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_11_RT_OFFSET
value|30616
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_12_RT_OFFSET
value|30617
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_13_RT_OFFSET
value|30618
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_14_RT_OFFSET
value|30619
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_15_RT_OFFSET
value|30620
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_16_RT_OFFSET
value|30621
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_17_RT_OFFSET
value|30622
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_18_RT_OFFSET
value|30623
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_19_RT_OFFSET
value|30624
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_20_RT_OFFSET
value|30625
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_21_RT_OFFSET
value|30626
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_22_RT_OFFSET
value|30627
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_23_RT_OFFSET
value|30628
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_24_RT_OFFSET
value|30629
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_25_RT_OFFSET
value|30630
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_26_RT_OFFSET
value|30631
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_27_RT_OFFSET
value|30632
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_28_RT_OFFSET
value|30633
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_29_RT_OFFSET
value|30634
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_30_RT_OFFSET
value|30635
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_31_RT_OFFSET
value|30636
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_32_RT_OFFSET
value|30637
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_33_RT_OFFSET
value|30638
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_34_RT_OFFSET
value|30639
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_35_RT_OFFSET
value|30640
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_36_RT_OFFSET
value|30641
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_37_RT_OFFSET
value|30642
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_38_RT_OFFSET
value|30643
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_39_RT_OFFSET
value|30644
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_40_RT_OFFSET
value|30645
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_41_RT_OFFSET
value|30646
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_42_RT_OFFSET
value|30647
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_43_RT_OFFSET
value|30648
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_44_RT_OFFSET
value|30649
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_45_RT_OFFSET
value|30650
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_46_RT_OFFSET
value|30651
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_47_RT_OFFSET
value|30652
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_48_RT_OFFSET
value|30653
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_49_RT_OFFSET
value|30654
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_50_RT_OFFSET
value|30655
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_51_RT_OFFSET
value|30656
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_52_RT_OFFSET
value|30657
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_53_RT_OFFSET
value|30658
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_54_RT_OFFSET
value|30659
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_55_RT_OFFSET
value|30660
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_56_RT_OFFSET
value|30661
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_57_RT_OFFSET
value|30662
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_58_RT_OFFSET
value|30663
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_59_RT_OFFSET
value|30664
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_60_RT_OFFSET
value|30665
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_61_RT_OFFSET
value|30666
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_62_RT_OFFSET
value|30667
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_63_RT_OFFSET
value|30668
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDROTHERPQ_RT_OFFSET
value|30669
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDROTHERPQ_RT_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRPFWFQ_RT_OFFSET
value|30797
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRVPWFQ_RT_OFFSET
value|30798
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRPFRL_RT_OFFSET
value|30799
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRGLBLRL_RT_OFFSET
value|30800
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLOPRTNSTCCRDMASK_RT_OFFSET
value|30801
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_0_RT_OFFSET
value|30802
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_1_RT_OFFSET
value|30803
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_2_RT_OFFSET
value|30804
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_3_RT_OFFSET
value|30805
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_4_RT_OFFSET
value|30806
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_5_RT_OFFSET
value|30807
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_6_RT_OFFSET
value|30808
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_7_RT_OFFSET
value|30809
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_8_RT_OFFSET
value|30810
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_9_RT_OFFSET
value|30811
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_10_RT_OFFSET
value|30812
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_11_RT_OFFSET
value|30813
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_12_RT_OFFSET
value|30814
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_13_RT_OFFSET
value|30815
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_14_RT_OFFSET
value|30816
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_15_RT_OFFSET
value|30817
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_0_RT_OFFSET
value|30818
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_1_RT_OFFSET
value|30819
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_2_RT_OFFSET
value|30820
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_3_RT_OFFSET
value|30821
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRTXGRPWEIGHT_0_RT_OFFSET
value|30822
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRTXGRPWEIGHT_1_RT_OFFSET
value|30823
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_0_RT_OFFSET
value|30824
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_1_RT_OFFSET
value|30825
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_2_RT_OFFSET
value|30826
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_3_RT_OFFSET
value|30827
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_4_RT_OFFSET
value|30828
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_5_RT_OFFSET
value|30829
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_6_RT_OFFSET
value|30830
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_7_RT_OFFSET
value|30831
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_8_RT_OFFSET
value|30832
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_9_RT_OFFSET
value|30833
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_10_RT_OFFSET
value|30834
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_11_RT_OFFSET
value|30835
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_12_RT_OFFSET
value|30836
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_13_RT_OFFSET
value|30837
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_14_RT_OFFSET
value|30838
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_15_RT_OFFSET
value|30839
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_16_RT_OFFSET
value|30840
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_17_RT_OFFSET
value|30841
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_18_RT_OFFSET
value|30842
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_19_RT_OFFSET
value|30843
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_20_RT_OFFSET
value|30844
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_21_RT_OFFSET
value|30845
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_22_RT_OFFSET
value|30846
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_23_RT_OFFSET
value|30847
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_24_RT_OFFSET
value|30848
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_25_RT_OFFSET
value|30849
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_26_RT_OFFSET
value|30850
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_27_RT_OFFSET
value|30851
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_28_RT_OFFSET
value|30852
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_29_RT_OFFSET
value|30853
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_30_RT_OFFSET
value|30854
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_31_RT_OFFSET
value|30855
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_32_RT_OFFSET
value|30856
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_33_RT_OFFSET
value|30857
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_34_RT_OFFSET
value|30858
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_35_RT_OFFSET
value|30859
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_36_RT_OFFSET
value|30860
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_37_RT_OFFSET
value|30861
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_38_RT_OFFSET
value|30862
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_39_RT_OFFSET
value|30863
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_40_RT_OFFSET
value|30864
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_41_RT_OFFSET
value|30865
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_42_RT_OFFSET
value|30866
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_43_RT_OFFSET
value|30867
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_44_RT_OFFSET
value|30868
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_45_RT_OFFSET
value|30869
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_46_RT_OFFSET
value|30870
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_47_RT_OFFSET
value|30871
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_48_RT_OFFSET
value|30872
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_49_RT_OFFSET
value|30873
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_50_RT_OFFSET
value|30874
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_51_RT_OFFSET
value|30875
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_52_RT_OFFSET
value|30876
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_53_RT_OFFSET
value|30877
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_54_RT_OFFSET
value|30878
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_55_RT_OFFSET
value|30879
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_56_RT_OFFSET
value|30880
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_57_RT_OFFSET
value|30881
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_58_RT_OFFSET
value|30882
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_59_RT_OFFSET
value|30883
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_60_RT_OFFSET
value|30884
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_61_RT_OFFSET
value|30885
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_62_RT_OFFSET
value|30886
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_63_RT_OFFSET
value|30887
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_0_RT_OFFSET
value|30888
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_1_RT_OFFSET
value|30889
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_2_RT_OFFSET
value|30890
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_3_RT_OFFSET
value|30891
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_4_RT_OFFSET
value|30892
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_5_RT_OFFSET
value|30893
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_6_RT_OFFSET
value|30894
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_7_RT_OFFSET
value|30895
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_8_RT_OFFSET
value|30896
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_9_RT_OFFSET
value|30897
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_10_RT_OFFSET
value|30898
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_11_RT_OFFSET
value|30899
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_12_RT_OFFSET
value|30900
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_13_RT_OFFSET
value|30901
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_14_RT_OFFSET
value|30902
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_15_RT_OFFSET
value|30903
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIOD_0_RT_OFFSET
value|30904
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIOD_1_RT_OFFSET
value|30905
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODTIMER_0_RT_OFFSET
value|30906
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODTIMER_1_RT_OFFSET
value|30907
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_0_RT_OFFSET
value|30908
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_1_RT_OFFSET
value|30909
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_2_RT_OFFSET
value|30910
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_3_RT_OFFSET
value|30911
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_4_RT_OFFSET
value|30912
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_5_RT_OFFSET
value|30913
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_6_RT_OFFSET
value|30914
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_7_RT_OFFSET
value|30915
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLINCVAL_RT_OFFSET
value|30916
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLINCVAL_RT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLUPPERBOUND_RT_OFFSET
value|31172
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLUPPERBOUND_RT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLCRD_RT_OFFSET
value|31428
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLCRD_RT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLENABLE_RT_OFFSET
value|31684
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFPERIOD_RT_OFFSET
value|31685
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFPERIODTIMER_RT_OFFSET
value|31686
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFINCVAL_RT_OFFSET
value|31687
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFINCVAL_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFUPPERBOUND_RT_OFFSET
value|31703
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFUPPERBOUND_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFCRD_RT_OFFSET
value|31719
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFCRD_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFENABLE_RT_OFFSET
value|31735
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFVOQENABLE_RT_OFFSET
value|31736
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFWEIGHT_RT_OFFSET
value|31737
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFWEIGHT_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFUPPERBOUND_RT_OFFSET
value|31753
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFUPPERBOUND_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFCRD_RT_OFFSET
value|31769
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFCRD_RT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFENABLE_RT_OFFSET
value|32025
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPENABLE_RT_OFFSET
value|32026
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDRTXPQ_RT_OFFSET
value|32027
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDRTXPQ_RT_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|QM_REG_TXPQMAP_RT_OFFSET
value|32539
end_define

begin_define
define|#
directive|define
name|QM_REG_TXPQMAP_RT_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPWEIGHT_RT_OFFSET
value|33051
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPWEIGHT_RT_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPCRD_RT_OFFSET
value|33563
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPCRD_RT_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPMAP_RT_OFFSET
value|34075
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPMAP_RT_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFCRD_MSB_RT_OFFSET
value|34587
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFCRD_MSB_RT_SIZE
value|320
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQCRDLINE_RT_OFFSET
value|34907
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQCRDLINE_RT_SIZE
value|36
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCRDLINE_RT_OFFSET
value|34943
end_define

begin_define
define|#
directive|define
name|QM_REG_VOQINITCRDLINE_RT_SIZE
value|36
end_define

begin_define
define|#
directive|define
name|NIG_REG_TAG_ETHERTYPE_0_RT_OFFSET
value|34979
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST0_RT_OFFSET
value|34980
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST1_RT_OFFSET
value|34981
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST2_RT_OFFSET
value|34982
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST3_RT_OFFSET
value|34983
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_MASK_RT_OFFSET
value|34984
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAGMAC_CLS_TYPE_RT_OFFSET
value|34985
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_EN_RT_OFFSET
value|34986
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_EN_RT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_HDR_SEL_RT_OFFSET
value|34990
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_HDR_SEL_RT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_VALUE_RT_OFFSET
value|34994
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_VALUE_RT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_NO_TAG_RT_OFFSET
value|34998
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_VALUE_RT_OFFSET
value|34999
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_VALUE_RT_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_EN_RT_OFFSET
value|35031
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_EN_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_MODE_RT_OFFSET
value|35047
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_MODE_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_PROTOCOL_TYPE_RT_OFFSET
value|35063
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_PROTOCOL_TYPE_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_HDR_SEL_RT_OFFSET
value|35079
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_HDR_SEL_RT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|NIG_REG_TX_EDPM_CTRL_RT_OFFSET
value|35095
end_define

begin_define
define|#
directive|define
name|NIG_REG_ROCE_DUPLICATE_TO_HOST_RT_OFFSET
value|35096
end_define

begin_define
define|#
directive|define
name|CDU_REG_CID_ADDR_PARAMS_RT_OFFSET
value|35097
end_define

begin_define
define|#
directive|define
name|CDU_REG_SEGMENT0_PARAMS_RT_OFFSET
value|35098
end_define

begin_define
define|#
directive|define
name|CDU_REG_SEGMENT1_PARAMS_RT_OFFSET
value|35099
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG0_TYPE_OFFSET_RT_OFFSET
value|35100
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG1_TYPE_OFFSET_RT_OFFSET
value|35101
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG2_TYPE_OFFSET_RT_OFFSET
value|35102
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG3_TYPE_OFFSET_RT_OFFSET
value|35103
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG0_TYPE_OFFSET_RT_OFFSET
value|35104
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG1_TYPE_OFFSET_RT_OFFSET
value|35105
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG2_TYPE_OFFSET_RT_OFFSET
value|35106
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG3_TYPE_OFFSET_RT_OFFSET
value|35107
end_define

begin_define
define|#
directive|define
name|CDU_REG_VF_SEG_TYPE_OFFSET_RT_OFFSET
value|35108
end_define

begin_define
define|#
directive|define
name|CDU_REG_VF_FL_SEG_TYPE_OFFSET_RT_OFFSET
value|35109
end_define

begin_define
define|#
directive|define
name|PBF_REG_TAG_ETHERTYPE_0_RT_OFFSET
value|35110
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SIZE_RT_OFFSET
value|35111
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ0_RT_OFFSET
value|35112
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ0_RT_OFFSET
value|35113
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ0_RT_OFFSET
value|35114
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ1_RT_OFFSET
value|35115
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ1_RT_OFFSET
value|35116
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ1_RT_OFFSET
value|35117
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ2_RT_OFFSET
value|35118
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ2_RT_OFFSET
value|35119
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ2_RT_OFFSET
value|35120
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ3_RT_OFFSET
value|35121
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ3_RT_OFFSET
value|35122
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ3_RT_OFFSET
value|35123
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ4_RT_OFFSET
value|35124
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ4_RT_OFFSET
value|35125
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ4_RT_OFFSET
value|35126
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ5_RT_OFFSET
value|35127
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ5_RT_OFFSET
value|35128
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ5_RT_OFFSET
value|35129
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ6_RT_OFFSET
value|35130
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ6_RT_OFFSET
value|35131
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ6_RT_OFFSET
value|35132
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ7_RT_OFFSET
value|35133
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ7_RT_OFFSET
value|35134
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ7_RT_OFFSET
value|35135
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ8_RT_OFFSET
value|35136
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ8_RT_OFFSET
value|35137
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ8_RT_OFFSET
value|35138
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ9_RT_OFFSET
value|35139
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ9_RT_OFFSET
value|35140
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ9_RT_OFFSET
value|35141
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ10_RT_OFFSET
value|35142
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ10_RT_OFFSET
value|35143
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ10_RT_OFFSET
value|35144
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ11_RT_OFFSET
value|35145
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ11_RT_OFFSET
value|35146
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ11_RT_OFFSET
value|35147
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ12_RT_OFFSET
value|35148
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ12_RT_OFFSET
value|35149
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ12_RT_OFFSET
value|35150
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ13_RT_OFFSET
value|35151
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ13_RT_OFFSET
value|35152
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ13_RT_OFFSET
value|35153
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ14_RT_OFFSET
value|35154
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ14_RT_OFFSET
value|35155
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ14_RT_OFFSET
value|35156
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ15_RT_OFFSET
value|35157
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ15_RT_OFFSET
value|35158
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ15_RT_OFFSET
value|35159
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ16_RT_OFFSET
value|35160
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ16_RT_OFFSET
value|35161
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ16_RT_OFFSET
value|35162
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ17_RT_OFFSET
value|35163
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ17_RT_OFFSET
value|35164
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ17_RT_OFFSET
value|35165
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ18_RT_OFFSET
value|35166
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ18_RT_OFFSET
value|35167
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ18_RT_OFFSET
value|35168
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ19_RT_OFFSET
value|35169
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ19_RT_OFFSET
value|35170
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ19_RT_OFFSET
value|35171
end_define

begin_define
define|#
directive|define
name|XCM_REG_CON_PHY_Q3_RT_OFFSET
value|35172
end_define

begin_define
define|#
directive|define
name|RUNTIME_ARRAY_SIZE
value|35173
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RT_DEFS_H__ */
end_comment

end_unit

