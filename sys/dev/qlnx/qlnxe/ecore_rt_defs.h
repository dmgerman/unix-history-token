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
value|761
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_SIZE
value|736
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_OFFSET
value|761
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_VAR_MEMORY_RT_SIZE
value|736
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_ADDR_MEMORY_RT_OFFSET
value|1497
end_define

begin_define
define|#
directive|define
name|CAU_REG_SB_ADDR_MEMORY_RT_SIZE
value|736
end_define

begin_define
define|#
directive|define
name|CAU_REG_PI_MEMORY_RT_OFFSET
value|2233
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
value|6649
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_INITIATOR_PF_RT_OFFSET
value|6650
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_INITIATOR_VF_RT_OFFSET
value|6651
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_TARGET_PF_RT_OFFSET
value|6652
end_define

begin_define
define|#
directive|define
name|PRS_REG_TASK_ID_MAX_TARGET_VF_RT_OFFSET
value|6653
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_TCP_RT_OFFSET
value|6654
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_FCOE_RT_OFFSET
value|6655
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_ROCE_RT_OFFSET
value|6656
end_define

begin_define
define|#
directive|define
name|PRS_REG_ROCE_DEST_QP_MAX_VF_RT_OFFSET
value|6657
end_define

begin_define
define|#
directive|define
name|PRS_REG_ROCE_DEST_QP_MAX_PF_RT_OFFSET
value|6658
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_OPENFLOW_RT_OFFSET
value|6659
end_define

begin_define
define|#
directive|define
name|PRS_REG_SEARCH_NON_IP_AS_OPENFLOW_RT_OFFSET
value|6660
end_define

begin_define
define|#
directive|define
name|PRS_REG_OPENFLOW_SUPPORT_ONLY_KNOWN_OVER_IP_RT_OFFSET
value|6661
end_define

begin_define
define|#
directive|define
name|PRS_REG_OPENFLOW_SEARCH_KEY_MASK_RT_OFFSET
value|6662
end_define

begin_define
define|#
directive|define
name|PRS_REG_TAG_ETHERTYPE_0_RT_OFFSET
value|6663
end_define

begin_define
define|#
directive|define
name|PRS_REG_LIGHT_L2_ETHERTYPE_EN_RT_OFFSET
value|6664
end_define

begin_define
define|#
directive|define
name|SRC_REG_FIRSTFREE_RT_OFFSET
value|6665
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
value|6667
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
value|6669
end_define

begin_define
define|#
directive|define
name|SRC_REG_NUMBER_HASH_BITS_RT_OFFSET
value|6670
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_P_SIZE_RT_OFFSET
value|6671
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_P_SIZE_RT_OFFSET
value|6672
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_P_SIZE_RT_OFFSET
value|6673
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_P_SIZE_RT_OFFSET
value|6674
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_P_SIZE_RT_OFFSET
value|6675
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_P_SIZE_RT_OFFSET
value|6676
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_FIRST_ILT_RT_OFFSET
value|6677
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_LAST_ILT_RT_OFFSET
value|6678
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_FIRST_ILT_RT_OFFSET
value|6679
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_QM_LAST_ILT_RT_OFFSET
value|6680
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_FIRST_ILT_RT_OFFSET
value|6681
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_SRC_LAST_ILT_RT_OFFSET
value|6682
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_FIRST_ILT_RT_OFFSET
value|6683
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_LAST_ILT_RT_OFFSET
value|6684
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_FIRST_ILT_RT_OFFSET
value|6685
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_LAST_ILT_RT_OFFSET
value|6686
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_FIRST_ILT_RT_OFFSET
value|6687
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TSDM_LAST_ILT_RT_OFFSET
value|6688
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|6689
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|6690
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_NUMBER_OF_PF_BLOCKS_RT_OFFSET
value|6691
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_VF_BLOCKS_RT_OFFSET
value|6692
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_VF_BLOCKS_RT_OFFSET
value|6693
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_VF_BLOCKS_RT_OFFSET
value|6694
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_TM_BLOCKS_FACTOR_RT_OFFSET
value|6695
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUT_BLOCKS_FACTOR_RT_OFFSET
value|6696
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_CDUC_BLOCKS_FACTOR_RT_OFFSET
value|6697
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_VF_BASE_RT_OFFSET
value|6698
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_VF_LAST_ILT_RT_OFFSET
value|6699
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_DRAM_ALIGN_WR_RT_OFFSET
value|6700
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_DRAM_ALIGN_RD_RT_OFFSET
value|6701
end_define

begin_define
define|#
directive|define
name|PSWRQ2_REG_ILT_MEMORY_RT_OFFSET
value|6702
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
value|28702
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_MSDM_OFFSET_MASK_B_RT_OFFSET
value|28703
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_MSDM_VF_SHIFT_B_RT_OFFSET
value|28704
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_CACHE_LINE_SIZE_RT_OFFSET
value|28705
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_PF_BAR0_SIZE_RT_OFFSET
value|28706
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_PF_BAR1_SIZE_RT_OFFSET
value|28707
end_define

begin_define
define|#
directive|define
name|PGLUE_REG_B_VF_BAR1_SIZE_RT_OFFSET
value|28708
end_define

begin_define
define|#
directive|define
name|TM_REG_VF_ENABLE_CONN_RT_OFFSET
value|28709
end_define

begin_define
define|#
directive|define
name|TM_REG_PF_ENABLE_CONN_RT_OFFSET
value|28710
end_define

begin_define
define|#
directive|define
name|TM_REG_PF_ENABLE_TASK_RT_OFFSET
value|28711
end_define

begin_define
define|#
directive|define
name|TM_REG_GROUP_SIZE_RESOLUTION_CONN_RT_OFFSET
value|28712
end_define

begin_define
define|#
directive|define
name|TM_REG_GROUP_SIZE_RESOLUTION_TASK_RT_OFFSET
value|28713
end_define

begin_define
define|#
directive|define
name|TM_REG_CONFIG_CONN_MEM_RT_OFFSET
value|28714
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
value|29130
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
value|29738
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZE_1_RT_OFFSET
value|29739
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZE_2_RT_OFFSET
value|29740
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_0_RT_OFFSET
value|29741
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_1_RT_OFFSET
value|29742
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_2_RT_OFFSET
value|29743
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_3_RT_OFFSET
value|29744
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_4_RT_OFFSET
value|29745
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_5_RT_OFFSET
value|29746
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_6_RT_OFFSET
value|29747
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_7_RT_OFFSET
value|29748
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_8_RT_OFFSET
value|29749
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_9_RT_OFFSET
value|29750
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_10_RT_OFFSET
value|29751
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_11_RT_OFFSET
value|29752
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_12_RT_OFFSET
value|29753
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_13_RT_OFFSET
value|29754
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_14_RT_OFFSET
value|29755
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_15_RT_OFFSET
value|29756
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_16_RT_OFFSET
value|29757
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_17_RT_OFFSET
value|29758
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_18_RT_OFFSET
value|29759
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_19_RT_OFFSET
value|29760
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_20_RT_OFFSET
value|29761
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_21_RT_OFFSET
value|29762
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_22_RT_OFFSET
value|29763
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_23_RT_OFFSET
value|29764
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_24_RT_OFFSET
value|29765
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_25_RT_OFFSET
value|29766
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_26_RT_OFFSET
value|29767
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_27_RT_OFFSET
value|29768
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_28_RT_OFFSET
value|29769
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_29_RT_OFFSET
value|29770
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_30_RT_OFFSET
value|29771
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_31_RT_OFFSET
value|29772
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_32_RT_OFFSET
value|29773
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_33_RT_OFFSET
value|29774
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_34_RT_OFFSET
value|29775
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_35_RT_OFFSET
value|29776
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_36_RT_OFFSET
value|29777
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_37_RT_OFFSET
value|29778
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_38_RT_OFFSET
value|29779
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_39_RT_OFFSET
value|29780
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_40_RT_OFFSET
value|29781
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_41_RT_OFFSET
value|29782
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_42_RT_OFFSET
value|29783
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_43_RT_OFFSET
value|29784
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_44_RT_OFFSET
value|29785
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_45_RT_OFFSET
value|29786
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_46_RT_OFFSET
value|29787
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_47_RT_OFFSET
value|29788
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_48_RT_OFFSET
value|29789
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_49_RT_OFFSET
value|29790
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_50_RT_OFFSET
value|29791
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_51_RT_OFFSET
value|29792
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_52_RT_OFFSET
value|29793
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_53_RT_OFFSET
value|29794
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_54_RT_OFFSET
value|29795
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_55_RT_OFFSET
value|29796
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_56_RT_OFFSET
value|29797
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_57_RT_OFFSET
value|29798
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_58_RT_OFFSET
value|29799
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_59_RT_OFFSET
value|29800
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_60_RT_OFFSET
value|29801
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_61_RT_OFFSET
value|29802
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_62_RT_OFFSET
value|29803
end_define

begin_define
define|#
directive|define
name|QM_REG_MAXPQSIZETXSEL_63_RT_OFFSET
value|29804
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDROTHERPQ_RT_OFFSET
value|29805
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
value|29933
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRVPWFQ_RT_OFFSET
value|29934
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRPFRL_RT_OFFSET
value|29935
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLQMBYPTHRGLBLRL_RT_OFFSET
value|29936
end_define

begin_define
define|#
directive|define
name|QM_REG_AFULLOPRTNSTCCRDMASK_RT_OFFSET
value|29937
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_0_RT_OFFSET
value|29938
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_1_RT_OFFSET
value|29939
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_2_RT_OFFSET
value|29940
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_3_RT_OFFSET
value|29941
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_4_RT_OFFSET
value|29942
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_5_RT_OFFSET
value|29943
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_6_RT_OFFSET
value|29944
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_7_RT_OFFSET
value|29945
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_8_RT_OFFSET
value|29946
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_9_RT_OFFSET
value|29947
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_10_RT_OFFSET
value|29948
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_11_RT_OFFSET
value|29949
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_12_RT_OFFSET
value|29950
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_13_RT_OFFSET
value|29951
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_14_RT_OFFSET
value|29952
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERPQGRP_15_RT_OFFSET
value|29953
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_0_RT_OFFSET
value|29954
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_1_RT_OFFSET
value|29955
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_2_RT_OFFSET
value|29956
end_define

begin_define
define|#
directive|define
name|QM_REG_WRROTHERGRPWEIGHT_3_RT_OFFSET
value|29957
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRTXGRPWEIGHT_0_RT_OFFSET
value|29958
end_define

begin_define
define|#
directive|define
name|QM_REG_WRRTXGRPWEIGHT_1_RT_OFFSET
value|29959
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_0_RT_OFFSET
value|29960
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_1_RT_OFFSET
value|29961
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_2_RT_OFFSET
value|29962
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_3_RT_OFFSET
value|29963
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_4_RT_OFFSET
value|29964
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_5_RT_OFFSET
value|29965
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_6_RT_OFFSET
value|29966
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_7_RT_OFFSET
value|29967
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_8_RT_OFFSET
value|29968
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_9_RT_OFFSET
value|29969
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_10_RT_OFFSET
value|29970
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_11_RT_OFFSET
value|29971
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_12_RT_OFFSET
value|29972
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_13_RT_OFFSET
value|29973
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_14_RT_OFFSET
value|29974
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_15_RT_OFFSET
value|29975
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_16_RT_OFFSET
value|29976
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_17_RT_OFFSET
value|29977
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_18_RT_OFFSET
value|29978
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_19_RT_OFFSET
value|29979
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_20_RT_OFFSET
value|29980
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_21_RT_OFFSET
value|29981
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_22_RT_OFFSET
value|29982
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_23_RT_OFFSET
value|29983
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_24_RT_OFFSET
value|29984
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_25_RT_OFFSET
value|29985
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_26_RT_OFFSET
value|29986
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_27_RT_OFFSET
value|29987
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_28_RT_OFFSET
value|29988
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_29_RT_OFFSET
value|29989
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_30_RT_OFFSET
value|29990
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_31_RT_OFFSET
value|29991
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_32_RT_OFFSET
value|29992
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_33_RT_OFFSET
value|29993
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_34_RT_OFFSET
value|29994
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_35_RT_OFFSET
value|29995
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_36_RT_OFFSET
value|29996
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_37_RT_OFFSET
value|29997
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_38_RT_OFFSET
value|29998
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_39_RT_OFFSET
value|29999
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_40_RT_OFFSET
value|30000
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_41_RT_OFFSET
value|30001
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_42_RT_OFFSET
value|30002
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_43_RT_OFFSET
value|30003
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_44_RT_OFFSET
value|30004
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_45_RT_OFFSET
value|30005
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_46_RT_OFFSET
value|30006
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_47_RT_OFFSET
value|30007
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_48_RT_OFFSET
value|30008
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_49_RT_OFFSET
value|30009
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_50_RT_OFFSET
value|30010
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_51_RT_OFFSET
value|30011
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_52_RT_OFFSET
value|30012
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_53_RT_OFFSET
value|30013
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_54_RT_OFFSET
value|30014
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_55_RT_OFFSET
value|30015
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_56_RT_OFFSET
value|30016
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_57_RT_OFFSET
value|30017
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_58_RT_OFFSET
value|30018
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_59_RT_OFFSET
value|30019
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_60_RT_OFFSET
value|30020
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_61_RT_OFFSET
value|30021
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_62_RT_OFFSET
value|30022
end_define

begin_define
define|#
directive|define
name|QM_REG_PQTX2PF_63_RT_OFFSET
value|30023
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_0_RT_OFFSET
value|30024
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_1_RT_OFFSET
value|30025
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_2_RT_OFFSET
value|30026
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_3_RT_OFFSET
value|30027
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_4_RT_OFFSET
value|30028
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_5_RT_OFFSET
value|30029
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_6_RT_OFFSET
value|30030
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_7_RT_OFFSET
value|30031
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_8_RT_OFFSET
value|30032
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_9_RT_OFFSET
value|30033
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_10_RT_OFFSET
value|30034
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_11_RT_OFFSET
value|30035
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_12_RT_OFFSET
value|30036
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_13_RT_OFFSET
value|30037
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_14_RT_OFFSET
value|30038
end_define

begin_define
define|#
directive|define
name|QM_REG_PQOTHER2PF_15_RT_OFFSET
value|30039
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIOD_0_RT_OFFSET
value|30040
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIOD_1_RT_OFFSET
value|30041
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODTIMER_0_RT_OFFSET
value|30042
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODTIMER_1_RT_OFFSET
value|30043
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_0_RT_OFFSET
value|30044
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_1_RT_OFFSET
value|30045
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_2_RT_OFFSET
value|30046
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_3_RT_OFFSET
value|30047
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_4_RT_OFFSET
value|30048
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_5_RT_OFFSET
value|30049
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_6_RT_OFFSET
value|30050
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLPERIODSEL_7_RT_OFFSET
value|30051
end_define

begin_define
define|#
directive|define
name|QM_REG_RLGLBLINCVAL_RT_OFFSET
value|30052
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
value|30308
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
value|30564
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
value|30820
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFPERIOD_RT_OFFSET
value|30821
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFPERIODTIMER_RT_OFFSET
value|30822
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFINCVAL_RT_OFFSET
value|30823
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
value|30839
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
value|30855
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
value|30871
end_define

begin_define
define|#
directive|define
name|QM_REG_RLPFVOQENABLE_RT_OFFSET
value|30872
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQPFWEIGHT_RT_OFFSET
value|30873
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
value|30889
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
value|30905
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
value|31161
end_define

begin_define
define|#
directive|define
name|QM_REG_WFQVPENABLE_RT_OFFSET
value|31162
end_define

begin_define
define|#
directive|define
name|QM_REG_BASEADDRTXPQ_RT_OFFSET
value|31163
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
value|31675
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
value|32187
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
value|32699
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
value|33211
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
value|33723
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
value|34043
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
value|34079
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
value|34115
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST0_RT_OFFSET
value|34116
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST1_RT_OFFSET
value|34117
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST2_RT_OFFSET
value|34118
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_LIST3_RT_OFFSET
value|34119
end_define

begin_define
define|#
directive|define
name|NIG_REG_OUTER_TAG_VALUE_MASK_RT_OFFSET
value|34120
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAGMAC_CLS_TYPE_RT_OFFSET
value|34121
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_TAG_EN_RT_OFFSET
value|34122
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
value|34126
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
value|34130
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
value|34134
end_define

begin_define
define|#
directive|define
name|NIG_REG_LLH_FUNC_FILTER_VALUE_RT_OFFSET
value|34135
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
value|34167
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
value|34183
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
value|34199
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
value|34215
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
value|34231
end_define

begin_define
define|#
directive|define
name|NIG_REG_ROCE_DUPLICATE_TO_HOST_RT_OFFSET
value|34232
end_define

begin_define
define|#
directive|define
name|CDU_REG_CID_ADDR_PARAMS_RT_OFFSET
value|34233
end_define

begin_define
define|#
directive|define
name|CDU_REG_SEGMENT0_PARAMS_RT_OFFSET
value|34234
end_define

begin_define
define|#
directive|define
name|CDU_REG_SEGMENT1_PARAMS_RT_OFFSET
value|34235
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG0_TYPE_OFFSET_RT_OFFSET
value|34236
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG1_TYPE_OFFSET_RT_OFFSET
value|34237
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG2_TYPE_OFFSET_RT_OFFSET
value|34238
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_SEG3_TYPE_OFFSET_RT_OFFSET
value|34239
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG0_TYPE_OFFSET_RT_OFFSET
value|34240
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG1_TYPE_OFFSET_RT_OFFSET
value|34241
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG2_TYPE_OFFSET_RT_OFFSET
value|34242
end_define

begin_define
define|#
directive|define
name|CDU_REG_PF_FL_SEG3_TYPE_OFFSET_RT_OFFSET
value|34243
end_define

begin_define
define|#
directive|define
name|CDU_REG_VF_SEG_TYPE_OFFSET_RT_OFFSET
value|34244
end_define

begin_define
define|#
directive|define
name|CDU_REG_VF_FL_SEG_TYPE_OFFSET_RT_OFFSET
value|34245
end_define

begin_define
define|#
directive|define
name|PBF_REG_TAG_ETHERTYPE_0_RT_OFFSET
value|34246
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SIZE_RT_OFFSET
value|34247
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ0_RT_OFFSET
value|34248
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ0_RT_OFFSET
value|34249
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ0_RT_OFFSET
value|34250
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ1_RT_OFFSET
value|34251
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ1_RT_OFFSET
value|34252
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ1_RT_OFFSET
value|34253
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ2_RT_OFFSET
value|34254
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ2_RT_OFFSET
value|34255
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ2_RT_OFFSET
value|34256
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ3_RT_OFFSET
value|34257
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ3_RT_OFFSET
value|34258
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ3_RT_OFFSET
value|34259
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ4_RT_OFFSET
value|34260
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ4_RT_OFFSET
value|34261
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ4_RT_OFFSET
value|34262
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ5_RT_OFFSET
value|34263
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ5_RT_OFFSET
value|34264
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ5_RT_OFFSET
value|34265
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ6_RT_OFFSET
value|34266
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ6_RT_OFFSET
value|34267
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ6_RT_OFFSET
value|34268
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ7_RT_OFFSET
value|34269
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ7_RT_OFFSET
value|34270
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ7_RT_OFFSET
value|34271
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ8_RT_OFFSET
value|34272
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ8_RT_OFFSET
value|34273
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ8_RT_OFFSET
value|34274
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ9_RT_OFFSET
value|34275
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ9_RT_OFFSET
value|34276
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ9_RT_OFFSET
value|34277
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ10_RT_OFFSET
value|34278
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ10_RT_OFFSET
value|34279
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ10_RT_OFFSET
value|34280
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ11_RT_OFFSET
value|34281
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ11_RT_OFFSET
value|34282
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ11_RT_OFFSET
value|34283
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ12_RT_OFFSET
value|34284
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ12_RT_OFFSET
value|34285
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ12_RT_OFFSET
value|34286
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ13_RT_OFFSET
value|34287
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ13_RT_OFFSET
value|34288
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ13_RT_OFFSET
value|34289
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ14_RT_OFFSET
value|34290
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ14_RT_OFFSET
value|34291
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ14_RT_OFFSET
value|34292
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ15_RT_OFFSET
value|34293
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ15_RT_OFFSET
value|34294
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ15_RT_OFFSET
value|34295
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ16_RT_OFFSET
value|34296
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ16_RT_OFFSET
value|34297
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ16_RT_OFFSET
value|34298
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ17_RT_OFFSET
value|34299
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ17_RT_OFFSET
value|34300
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ17_RT_OFFSET
value|34301
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ18_RT_OFFSET
value|34302
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ18_RT_OFFSET
value|34303
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ18_RT_OFFSET
value|34304
end_define

begin_define
define|#
directive|define
name|PBF_REG_YCMD_QS_NUM_LINES_VOQ19_RT_OFFSET
value|34305
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_GUARANTEED_VOQ19_RT_OFFSET
value|34306
end_define

begin_define
define|#
directive|define
name|PBF_REG_BTB_SHARED_AREA_SETUP_VOQ19_RT_OFFSET
value|34307
end_define

begin_define
define|#
directive|define
name|XCM_REG_CON_PHY_Q3_RT_OFFSET
value|34308
end_define

begin_define
define|#
directive|define
name|RUNTIME_ARRAY_SIZE
value|34309
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RT_DEFS_H__ */
end_comment

end_unit

