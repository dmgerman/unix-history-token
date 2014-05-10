begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECORE_FW_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|ECORE_FW_DEFS_H
end_define

begin_define
define|#
directive|define
name|CSTORM_ASSERT_LIST_INDEX_OFFSET
value|(IRO[148].base)
end_define

begin_define
define|#
directive|define
name|CSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|assertListEntry
parameter_list|)
define|\
value|(IRO[147].base + ((assertListEntry) * IRO[147].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_EVENT_RING_DATA_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[153].base + (((pfId)>>1) * IRO[153].m1) + (((pfId)&1) * \ 	IRO[153].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_EVENT_RING_PROD_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[154].base + (((pfId)>>1) * IRO[154].m1) + (((pfId)&1) * \ 	IRO[154].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_FINAL_CLEANUP_COMPLETE_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[159].base + ((funcId) * IRO[159].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_FUNC_EN_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[149].base + ((funcId) * IRO[149].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_HC_SYNC_LINE_INDEX_E1X_OFFSET
parameter_list|(
name|hcIndex
parameter_list|,
name|sbId
parameter_list|)
define|\
value|(IRO[139].base + ((hcIndex) * IRO[139].m1) + ((sbId) * IRO[139].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_HC_SYNC_LINE_INDEX_E2_OFFSET
parameter_list|(
name|hcIndex
parameter_list|,
name|sbId
parameter_list|)
define|\
value|(IRO[138].base + (((hcIndex)>>2) * IRO[138].m1) + (((hcIndex)&3) \ 	* IRO[138].m2) + ((sbId) * IRO[138].m3))
end_define

begin_define
define|#
directive|define
name|CSTORM_IGU_MODE_OFFSET
value|(IRO[157].base)
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_CQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[317].base + ((pfId) * IRO[317].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_CQ_SQN_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[318].base + ((pfId) * IRO[318].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_CONS_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[310].base + ((pfId) * IRO[310].m1) + ((iscsiEqId) * IRO[310].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_EQE_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[312].base + ((pfId) * IRO[312].m1) + ((iscsiEqId) * IRO[312].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[311].base + ((pfId) * IRO[311].m1) + ((iscsiEqId) * IRO[311].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_VALID_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[313].base + ((pfId) * IRO[313].m1) + ((iscsiEqId) * IRO[313].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_PROD_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[309].base + ((pfId) * IRO[309].m1) + ((iscsiEqId) * IRO[309].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_SB_INDEX_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[315].base + ((pfId) * IRO[315].m1) + ((iscsiEqId) * IRO[315].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_SB_NUM_OFFSET
parameter_list|(
name|pfId
parameter_list|,
name|iscsiEqId
parameter_list|)
define|\
value|(IRO[314].base + ((pfId) * IRO[314].m1) + ((iscsiEqId) * IRO[314].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_HQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[316].base + ((pfId) * IRO[316].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[308].base + ((pfId) * IRO[308].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[307].base + ((pfId) * IRO[307].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[306].base + ((pfId) * IRO[306].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_RECORD_SLOW_PATH_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[151].base + ((funcId) * IRO[151].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_STATUS_BLOCK_DATA_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[142].base + ((pfId) * IRO[142].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_STATUS_BLOCK_DATA_STATE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[143].base + ((pfId) * IRO[143].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_STATUS_BLOCK_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[141].base + ((pfId) * IRO[141].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_STATUS_BLOCK_SIZE
value|(IRO[141].size)
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_SYNC_BLOCK_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[144].base + ((pfId) * IRO[144].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SP_SYNC_BLOCK_SIZE
value|(IRO[144].size)
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_DATA_FLAGS_OFFSET
parameter_list|(
name|sbId
parameter_list|,
name|hcIndex
parameter_list|)
define|\
value|(IRO[136].base + ((sbId) * IRO[136].m1) + ((hcIndex) * IRO[136].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_DATA_OFFSET
parameter_list|(
name|sbId
parameter_list|)
define|\
value|(IRO[133].base + ((sbId) * IRO[133].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_DATA_STATE_OFFSET
parameter_list|(
name|sbId
parameter_list|)
define|\
value|(IRO[134].base + ((sbId) * IRO[134].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_DATA_TIMEOUT_OFFSET
parameter_list|(
name|sbId
parameter_list|,
name|hcIndex
parameter_list|)
define|\
value|(IRO[135].base + ((sbId) * IRO[135].m1) + ((hcIndex) * IRO[135].m2))
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_OFFSET
parameter_list|(
name|sbId
parameter_list|)
define|\
value|(IRO[132].base + ((sbId) * IRO[132].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_STATUS_BLOCK_SIZE
value|(IRO[132].size)
end_define

begin_define
define|#
directive|define
name|CSTORM_SYNC_BLOCK_OFFSET
parameter_list|(
name|sbId
parameter_list|)
define|\
value|(IRO[137].base + ((sbId) * IRO[137].m1))
end_define

begin_define
define|#
directive|define
name|CSTORM_SYNC_BLOCK_SIZE
value|(IRO[137].size)
end_define

begin_define
define|#
directive|define
name|CSTORM_VF_TO_PF_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[150].base + ((funcId) * IRO[150].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ACCEPT_CLASSIFY_FAILED_OFFSET
value|(IRO[204].base)
end_define

begin_define
define|#
directive|define
name|TSTORM_APPROXIMATE_MATCH_MULTICAST_FILTERING_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[203].base + ((pfId) * IRO[203].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ASSERT_LIST_INDEX_OFFSET
value|(IRO[102].base)
end_define

begin_define
define|#
directive|define
name|TSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|assertListEntry
parameter_list|)
define|\
value|(IRO[101].base + ((assertListEntry) * IRO[101].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_FUNCTION_COMMON_CONFIG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[201].base + ((pfId) * IRO[201].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_FUNC_EN_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[103].base + ((funcId) * IRO[103].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_ERROR_BITMAP_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[272].base + ((pfId) * IRO[272].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[271].base + ((pfId) * IRO[271].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[270].base + ((pfId) * IRO[270].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[269].base + ((pfId) * IRO[269].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_RQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[268].base + ((pfId) * IRO[268].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_LOCAL_ADV_WND_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[278].base + ((pfId) * IRO[278].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[264].base + ((pfId) * IRO[264].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_LSB_LOCAL_MAC_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[265].base + ((pfId) * IRO[265].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_MID_LOCAL_MAC_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[266].base + ((pfId) * IRO[266].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_MSB_LOCAL_MAC_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[267].base + ((pfId) * IRO[267].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_MAC_FILTER_CONFIG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[202].base + ((pfId) * IRO[202].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_RECORD_SLOW_PATH_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[105].base + ((funcId) * IRO[105].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_TCP_MAX_CWND_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[217].base + ((pfId) * IRO[217].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_VF_TO_PF_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[104].base + ((funcId) * IRO[104].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_AGG_DATA_OFFSET
value|(IRO[206].base)
end_define

begin_define
define|#
directive|define
name|USTORM_AGG_DATA_SIZE
value|(IRO[206].size)
end_define

begin_define
define|#
directive|define
name|USTORM_ASSERT_LIST_INDEX_OFFSET
value|(IRO[177].base)
end_define

begin_define
define|#
directive|define
name|USTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|assertListEntry
parameter_list|)
define|\
value|(IRO[176].base + ((assertListEntry) * IRO[176].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_PAUSE_ENABLED_OFFSET
parameter_list|(
name|portId
parameter_list|)
define|\
value|(IRO[183].base + ((portId) * IRO[183].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_FCOE_EQ_PROD_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[319].base + ((pfId) * IRO[319].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_FUNC_EN_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[178].base + ((funcId) * IRO[178].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_CQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[283].base + ((pfId) * IRO[283].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_CQ_SQN_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[284].base + ((pfId) * IRO[284].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_ERROR_BITMAP_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[288].base + ((pfId) * IRO[288].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_GLOBAL_BUF_PHYS_ADDR_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[285].base + ((pfId) * IRO[285].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[281].base + ((pfId) * IRO[281].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[280].base + ((pfId) * IRO[280].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[279].base + ((pfId) * IRO[279].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_R2TQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[282].base + ((pfId) * IRO[282].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_RQ_BUFFER_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[286].base + ((pfId) * IRO[286].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_RQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[287].base + ((pfId) * IRO[287].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_MEM_WORKAROUND_ADDRESS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[182].base + ((pfId) * IRO[182].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_RECORD_SLOW_PATH_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[180].base + ((funcId) * IRO[180].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_RX_PRODS_E1X_OFFSET
parameter_list|(
name|portId
parameter_list|,
name|clientId
parameter_list|)
define|\
value|(IRO[209].base + ((portId) * IRO[209].m1) + ((clientId) * \ 	IRO[209].m2))
end_define

begin_define
define|#
directive|define
name|USTORM_RX_PRODS_E2_OFFSET
parameter_list|(
name|qzoneId
parameter_list|)
define|\
value|(IRO[210].base + ((qzoneId) * IRO[210].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_TPA_BTR_OFFSET
value|(IRO[207].base)
end_define

begin_define
define|#
directive|define
name|USTORM_TPA_BTR_SIZE
value|(IRO[207].size)
end_define

begin_define
define|#
directive|define
name|USTORM_VF_TO_PF_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[179].base + ((funcId) * IRO[179].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_AGG_INT_FINAL_CLEANUP_COMP_TYPE
value|(IRO[67].base)
end_define

begin_define
define|#
directive|define
name|XSTORM_AGG_INT_FINAL_CLEANUP_INDEX
value|(IRO[66].base)
end_define

begin_define
define|#
directive|define
name|XSTORM_ASSERT_LIST_INDEX_OFFSET
value|(IRO[51].base)
end_define

begin_define
define|#
directive|define
name|XSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|assertListEntry
parameter_list|)
define|\
value|(IRO[50].base + ((assertListEntry) * IRO[50].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_CMNG_PER_PORT_VARS_OFFSET
parameter_list|(
name|portId
parameter_list|)
define|\
value|(IRO[43].base + ((portId) * IRO[43].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_FAIRNESS_PER_VN_VARS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[45].base + ((pfId) * IRO[45].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_FUNC_EN_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[47].base + ((funcId) * IRO[47].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_HQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[296].base + ((pfId) * IRO[296].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR0_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[299].base + ((pfId) * IRO[299].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR1_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[300].base + ((pfId) * IRO[300].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR2_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[301].base + ((pfId) * IRO[301].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR3_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[302].base + ((pfId) * IRO[302].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR4_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[303].base + ((pfId) * IRO[303].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR5_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[304].base + ((pfId) * IRO[304].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_VLAN_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[305].base + ((pfId) * IRO[305].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[295].base + ((pfId) * IRO[295].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[294].base + ((pfId) * IRO[294].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[293].base + ((pfId) * IRO[293].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_R2TQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[298].base + ((pfId) * IRO[298].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_SQ_SIZE_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[297].base + ((pfId) * IRO[297].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_ADV_WND_SCL_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[292].base + ((pfId) * IRO[292].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[291].base + ((pfId) * IRO[291].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_TOS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[290].base + ((pfId) * IRO[290].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_TTL_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[289].base + ((pfId) * IRO[289].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_RATE_SHAPING_PER_VN_VARS_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[44].base + ((pfId) * IRO[44].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_RECORD_SLOW_PATH_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[49].base + ((funcId) * IRO[49].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_DATA_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[32].base + ((funcId) * IRO[32].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_DATA_SIZE
value|(IRO[32].size)
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_PAGE_BASE_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[30].base + ((funcId) * IRO[30].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_PROD_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[31].base + ((funcId) * IRO[31].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_ENABLED_OFFSET
parameter_list|(
name|portId
parameter_list|)
define|\
value|(IRO[211].base + ((portId) * IRO[211].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_MAX_COUNT_OFFSET
parameter_list|(
name|portId
parameter_list|)
define|\
value|(IRO[212].base + ((portId) * IRO[212].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_TX_SWS_TIMER_VAL_OFFSET
parameter_list|(
name|pfId
parameter_list|)
define|\
value|(IRO[214].base + (((pfId)>>1) * IRO[214].m1) + (((pfId)&1) * \ 	IRO[214].m2))
end_define

begin_define
define|#
directive|define
name|XSTORM_VF_TO_PF_OFFSET
parameter_list|(
name|funcId
parameter_list|)
define|\
value|(IRO[48].base + ((funcId) * IRO[48].m1))
end_define

begin_define
define|#
directive|define
name|COMMON_ASM_INVALID_ASSERT_OPCODE
value|(IRO[7].base)
end_define

begin_comment
comment|/* Ethernet Ring parameters */
end_comment

begin_define
define|#
directive|define
name|X_ETH_LOCAL_RING_SIZE
value|13
end_define

begin_define
define|#
directive|define
name|FIRST_BD_IN_PKT
value|0
end_define

begin_define
define|#
directive|define
name|PARSE_BD_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|NUM_OF_ETH_BDS_IN_PAGE
value|((PAGE_SIZE)/(STRUCT_SIZE(eth_tx_bd)/8))
end_define

begin_define
define|#
directive|define
name|U_ETH_NUM_OF_SGES_TO_FETCH
value|8
end_define

begin_define
define|#
directive|define
name|U_ETH_MAX_SGES_FOR_PACKET
value|3
end_define

begin_comment
comment|/* Rx ring params */
end_comment

begin_define
define|#
directive|define
name|U_ETH_LOCAL_BD_RING_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|U_ETH_LOCAL_SGE_RING_SIZE
value|10
end_define

begin_define
define|#
directive|define
name|U_ETH_SGL_SIZE
value|8
end_define

begin_comment
comment|/* The fw will padd the buffer with this value, so the IP header \ 	will be align to 4 Byte */
end_comment

begin_define
define|#
directive|define
name|IP_HEADER_ALIGNMENT_PADDING
value|2
end_define

begin_define
define|#
directive|define
name|U_ETH_SGES_PER_PAGE_INVERSE_MASK
define|\
value|(0xFFFF - ((PAGE_SIZE/((STRUCT_SIZE(eth_rx_sge))/8))-1))
end_define

begin_define
define|#
directive|define
name|TU_ETH_CQES_PER_PAGE
value|(PAGE_SIZE/(STRUCT_SIZE(eth_rx_cqe)/8))
end_define

begin_define
define|#
directive|define
name|U_ETH_BDS_PER_PAGE
value|(PAGE_SIZE/(STRUCT_SIZE(eth_rx_bd)/8))
end_define

begin_define
define|#
directive|define
name|U_ETH_SGES_PER_PAGE
value|(PAGE_SIZE/(STRUCT_SIZE(eth_rx_sge)/8))
end_define

begin_define
define|#
directive|define
name|U_ETH_BDS_PER_PAGE_MASK
value|(U_ETH_BDS_PER_PAGE-1)
end_define

begin_define
define|#
directive|define
name|U_ETH_CQE_PER_PAGE_MASK
value|(TU_ETH_CQES_PER_PAGE-1)
end_define

begin_define
define|#
directive|define
name|U_ETH_SGES_PER_PAGE_MASK
value|(U_ETH_SGES_PER_PAGE-1)
end_define

begin_define
define|#
directive|define
name|U_ETH_UNDEFINED_Q
value|0xFF
end_define

begin_define
define|#
directive|define
name|T_ETH_INDIRECTION_TABLE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|T_ETH_RSS_KEY
value|10
end_define

begin_define
define|#
directive|define
name|ETH_NUM_OF_RSS_ENGINES_E2
value|72
end_define

begin_define
define|#
directive|define
name|FILTER_RULES_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|MULTICAST_RULES_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|CLASSIFY_RULES_COUNT
value|16
end_define

begin_comment
comment|/*The CRC32 seed, that is used for the hash(reduction) multicast address */
end_comment

begin_define
define|#
directive|define
name|ETH_CRC32_HASH_SEED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ETH_CRC32_HASH_BIT_SIZE
value|(8)
end_define

begin_define
define|#
directive|define
name|ETH_CRC32_HASH_MASK
value|EVAL((1<<ETH_CRC32_HASH_BIT_SIZE)-1)
end_define

begin_comment
comment|/* Maximal L2 clients supported */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_RX_CLIENTS_E1
value|18
end_define

begin_define
define|#
directive|define
name|ETH_MAX_RX_CLIENTS_E1H
value|28
end_define

begin_define
define|#
directive|define
name|ETH_MAX_RX_CLIENTS_E2
value|152
end_define

begin_comment
comment|/* Maximal statistics client Ids */
end_comment

begin_define
define|#
directive|define
name|MAX_STAT_COUNTER_ID_E1
value|36
end_define

begin_define
define|#
directive|define
name|MAX_STAT_COUNTER_ID_E1H
value|56
end_define

begin_define
define|#
directive|define
name|MAX_STAT_COUNTER_ID_E2
value|140
end_define

begin_define
define|#
directive|define
name|MAX_MAC_CREDIT_E1
value|192
end_define

begin_comment
comment|/* Per Chip */
end_comment

begin_define
define|#
directive|define
name|MAX_MAC_CREDIT_E1H
value|256
end_define

begin_comment
comment|/* Per Chip */
end_comment

begin_define
define|#
directive|define
name|MAX_MAC_CREDIT_E2
value|272
end_define

begin_comment
comment|/* Per Path */
end_comment

begin_define
define|#
directive|define
name|MAX_VLAN_CREDIT_E1
value|0
end_define

begin_comment
comment|/* Per Chip */
end_comment

begin_define
define|#
directive|define
name|MAX_VLAN_CREDIT_E1H
value|0
end_define

begin_comment
comment|/* Per Chip */
end_comment

begin_define
define|#
directive|define
name|MAX_VLAN_CREDIT_E2
value|272
end_define

begin_comment
comment|/* Per Path */
end_comment

begin_comment
comment|/* Maximal aggregation queues supported */
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_AGGREGATION_QUEUES_E1
value|32
end_define

begin_define
define|#
directive|define
name|ETH_MAX_AGGREGATION_QUEUES_E1H_E2
value|64
end_define

begin_define
define|#
directive|define
name|ETH_NUM_OF_MCAST_BINS
value|256
end_define

begin_define
define|#
directive|define
name|ETH_NUM_OF_MCAST_ENGINES_E2
value|72
end_define

begin_define
define|#
directive|define
name|ETH_MIN_RX_CQES_WITHOUT_TPA
value|(MAX_RAMRODS_PER_PORT + 3)
end_define

begin_define
define|#
directive|define
name|ETH_MIN_RX_CQES_WITH_TPA_E1
define|\
value|(ETH_MAX_AGGREGATION_QUEUES_E1 + ETH_MIN_RX_CQES_WITHOUT_TPA)
end_define

begin_define
define|#
directive|define
name|ETH_MIN_RX_CQES_WITH_TPA_E1H_E2
define|\
value|(ETH_MAX_AGGREGATION_QUEUES_E1H_E2 + ETH_MIN_RX_CQES_WITHOUT_TPA)
end_define

begin_define
define|#
directive|define
name|DISABLE_STATISTIC_COUNTER_ID_VALUE
value|0
end_define

begin_comment
comment|/* This file defines HSI constants common to all microcode flows */
end_comment

begin_comment
comment|/* offset in bits of protocol in the state context parameter */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_STATE_BIT_OFFSET
value|6
end_define

begin_define
define|#
directive|define
name|ETH_STATE
value|(ETH_CONNECTION_TYPE<< PROTOCOL_STATE_BIT_OFFSET)
end_define

begin_define
define|#
directive|define
name|TOE_STATE
value|(TOE_CONNECTION_TYPE<< PROTOCOL_STATE_BIT_OFFSET)
end_define

begin_define
define|#
directive|define
name|RDMA_STATE
value|(RDMA_CONNECTION_TYPE<< PROTOCOL_STATE_BIT_OFFSET)
end_define

begin_comment
comment|/* microcode fixed page page size 4K (chains and ring segments) */
end_comment

begin_define
define|#
directive|define
name|MC_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/* Number of indices per slow-path SB */
end_comment

begin_define
define|#
directive|define
name|HC_SP_SB_MAX_INDICES
value|16
end_define

begin_comment
comment|/* The Maximum of all */
end_comment

begin_comment
comment|/* Number of indices per SB */
end_comment

begin_define
define|#
directive|define
name|HC_SB_MAX_INDICES_E1X
value|8
end_define

begin_comment
comment|/* Multiple of 4 */
end_comment

begin_define
define|#
directive|define
name|HC_SB_MAX_INDICES_E2
value|8
end_define

begin_comment
comment|/* Multiple of 4 */
end_comment

begin_comment
comment|/* Number of SB */
end_comment

begin_define
define|#
directive|define
name|HC_SB_MAX_SB_E1X
value|32
end_define

begin_define
define|#
directive|define
name|HC_SB_MAX_SB_E2
value|136
end_define

begin_comment
comment|/* include PF */
end_comment

begin_comment
comment|/* ID of slow path status block */
end_comment

begin_define
define|#
directive|define
name|HC_SP_SB_ID
value|0xde
end_define

begin_comment
comment|/* Num of State machines */
end_comment

begin_define
define|#
directive|define
name|HC_SB_MAX_SM
value|2
end_define

begin_comment
comment|/* Fixed */
end_comment

begin_comment
comment|/* Num of dynamic indices */
end_comment

begin_define
define|#
directive|define
name|HC_SB_MAX_DYNAMIC_INDICES
value|4
end_define

begin_comment
comment|/* 0..3 fixed */
end_comment

begin_comment
comment|/* max number of slow path commands per port */
end_comment

begin_define
define|#
directive|define
name|MAX_RAMRODS_PER_PORT
value|8
end_define

begin_comment
comment|/**** DEFINES FOR TIMERS/CLOCKS RESOLUTIONS ****/
end_comment

begin_comment
comment|/* chip timers frequency constants */
end_comment

begin_define
define|#
directive|define
name|TIMERS_TICK_SIZE_CHIP
value|(1e-3)
end_define

begin_comment
comment|/* used in toe: TsRecentAge, MaxRt, and temporarily RTT */
end_comment

begin_define
define|#
directive|define
name|TSEMI_CLK1_RESUL_CHIP
value|(1e-3)
end_define

begin_comment
comment|/* temporarily used for RTT */
end_comment

begin_define
define|#
directive|define
name|XSEMI_CLK1_RESUL_CHIP
value|(1e-3)
end_define

begin_comment
comment|/* used for Host Coallescing */
end_comment

begin_define
define|#
directive|define
name|SDM_TIMER_TICK_RESUL_CHIP
value|(4 * (1e-6))
end_define

begin_comment
comment|/**** END DEFINES FOR TIMERS/CLOCKS RESOLUTIONS ****/
end_comment

begin_define
define|#
directive|define
name|XSTORM_IP_ID_ROLL_HALF
value|0x8000
end_define

begin_define
define|#
directive|define
name|XSTORM_IP_ID_ROLL_ALL
value|0
end_define

begin_comment
comment|/* assert list: number of entries */
end_comment

begin_define
define|#
directive|define
name|FW_LOG_LIST_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|NUM_OF_SAFC_BITS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_COS_NUMBER
value|4
end_define

begin_define
define|#
directive|define
name|MAX_TRAFFIC_TYPES
value|8
end_define

begin_define
define|#
directive|define
name|MAX_PFC_PRIORITIES
value|8
end_define

begin_comment
comment|/* used by array traffic_type_to_priority[] to mark traffic type \ 	that is not mapped to priority*/
end_comment

begin_define
define|#
directive|define
name|LLFC_TRAFFIC_TYPE_TO_PRIORITY_UNMAPPED
value|0xFF
end_define

begin_comment
comment|/* Event Ring definitions */
end_comment

begin_define
define|#
directive|define
name|C_ERES_PER_PAGE
define|\
value|(PAGE_SIZE / BITS_TO_BYTES(STRUCT_SIZE(event_ring_elem)))
end_define

begin_define
define|#
directive|define
name|C_ERE_PER_PAGE_MASK
value|(C_ERES_PER_PAGE - 1)
end_define

begin_comment
comment|/* number of statistic command */
end_comment

begin_define
define|#
directive|define
name|STATS_QUERY_CMD_COUNT
value|16
end_define

begin_comment
comment|/* niv list table size */
end_comment

begin_define
define|#
directive|define
name|AFEX_LIST_TABLE_SIZE
value|4096
end_define

begin_comment
comment|/* invalid VNIC Id. used in VNIC classification */
end_comment

begin_define
define|#
directive|define
name|INVALID_VNIC_ID
value|0xFF
end_define

begin_comment
comment|/* used for indicating an undefined RAM offset in the IRO arrays */
end_comment

begin_define
define|#
directive|define
name|UNDEF_IRO
value|0x80000000
end_define

begin_comment
comment|/* used for defining the amount of FCoE tasks supported for PF */
end_comment

begin_define
define|#
directive|define
name|MAX_FCOE_FUNCS_PER_ENGINE
value|2
end_define

begin_define
define|#
directive|define
name|MAX_NUM_FCOE_TASKS_PER_ENGINE
define|\
value|4096
end_define

begin_comment
comment|/*Each port can have at max 1 function*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECORE_FW_DEFS_H */
end_comment

end_unit

