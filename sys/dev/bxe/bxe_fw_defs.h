begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BXE_FW_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_BXE_FW_DEFS_H
end_define

begin_define
define|#
directive|define
name|CSTORM_ASSERT_LIST_INDEX_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x7000 : 0x1000)
end_define

begin_define
define|#
directive|define
name|CSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|idx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7020 + (idx * 0x10)) : (0x1020 + (idx * 0x10)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HC_DISABLE_C_OFFSET
parameter_list|(
name|function
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8622 + ((function>>1) * 0x40) + \ 	((function&1) * 0x100) + (index * 0x4)) : (0x3562 + (function * \ 	0x40) + (index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HC_DISABLE_U_OFFSET
parameter_list|(
name|function
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8822 + ((function>>1) * 0x80) + \ 	((function&1) * 0x200) + (index * 0x4)) : (0x35e2 + (function * \ 	0x80) + (index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HOST_SB_ADDR_C_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8600 + ((function>>1) * 0x40) + \ 	((function&1) * 0x100)) : (0x3540 + (function * 0x40)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HOST_SB_ADDR_U_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8800 + ((function>>1) * 0x80) + \ 	((function&1) * 0x200)) : (0x35c0 + (function * 0x80)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HOST_STATUS_BLOCK_C_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8608 + ((function>>1) * 0x40) + \ 	((function&1) * 0x100)) : (0x3548 + (function * 0x40)))
end_define

begin_define
define|#
directive|define
name|CSTORM_DEF_SB_HOST_STATUS_BLOCK_U_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8808 + ((function>>1) * 0x80) + \ 	((function&1) * 0x200)) : (0x35c8 + (function * 0x80)))
end_define

begin_define
define|#
directive|define
name|CSTORM_FUNCTION_MODE_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x11e8 : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|CSTORM_HC_BTR_C_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8c04 + (port * 0xf0)) : (0x36c4 + (port * 0xc0)))
end_define

begin_define
define|#
directive|define
name|CSTORM_HC_BTR_U_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8de4 + (port * 0xf0)) : (0x3844 + (port * 0xc0)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_CQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6680 + (function * 0x8)) : (0x25a0 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_CQ_SQN_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x66c0 + (function * 0x8)) : (0x25b0 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_CONS_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6040 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2410 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_EQE_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6044 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2414 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x604c + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x241c + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_NEXT_PAGE_ADDR_VALID_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6057 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2427 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_PROD_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6042 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2412 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_SB_INDEX_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6056 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2426 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_EQ_SB_NUM_OFFSET
parameter_list|(
name|function
parameter_list|,
name|eqIdx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6054 + (function * 0xc0) + (eqIdx * 0x18)) : \ 	(0x2424 + (function * 0xc0) + (eqIdx * 0x18)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_HQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6640 + (function * 0x8)) : (0x2590 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6004 + (function * 0x8)) : (0x2404 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6002 + (function * 0x8)) : (0x2402 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6000 + (function * 0x8)) : (0x2400 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HC_DISABLE_C_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x811a + (port * 0x280) + (cpu_id * 0x28) + \ 	(index * 0x4)) : (0x305a + (port * 0x280) + (cpu_id * 0x28) + \ 	(index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HC_DISABLE_U_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb01a + (port * 0x800) + (cpu_id * 0x80) + \ 	(index * 0x4)) : (0x401a + (port * 0x800) + (cpu_id * 0x80) + \ 	(index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HC_TIMEOUT_C_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8118 + (port * 0x280) + (cpu_id * 0x28) + \ 	(index * 0x4)) : (0x3058 + (port * 0x280) + (cpu_id * 0x28) + \ 	(index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HC_TIMEOUT_U_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb018 + (port * 0x800) + (cpu_id * 0x80) + \ 	(index * 0x4)) : (0x4018 + (port * 0x800) + (cpu_id * 0x80) + \ 	(index * 0x4)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HOST_SB_ADDR_C_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8100 + (port * 0x280) + (cpu_id * 0x28)) : \ 	(0x3040 + (port * 0x280) + (cpu_id * 0x28)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HOST_SB_ADDR_U_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb000 + (port * 0x800) + (cpu_id * 0x80)) : \ 	(0x4000 + (port * 0x800) + (cpu_id * 0x80)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HOST_STATUS_BLOCK_C_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8108 + (port * 0x280) + (cpu_id * 0x28)) : \ 	(0x3048 + (port * 0x280) + (cpu_id * 0x28)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_HOST_STATUS_BLOCK_U_OFFSET
parameter_list|(
name|port
parameter_list|,
name|cpu_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb008 + (port * 0x800) + (cpu_id * 0x80)) : \ 	(0x4008 + (port * 0x800) + (cpu_id * 0x80)))
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_STATUS_BLOCK_C_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|CSTORM_SB_STATUS_BLOCK_U_SIZE
value|0x60
end_define

begin_define
define|#
directive|define
name|CSTORM_STATS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1108 + (function * 0x8)) : (0x5108 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_APPROXIMATE_MATCH_MULTICAST_FILTERING_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x3200 + (function * 0x20)) : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|TSTORM_ASSERT_LIST_INDEX_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0xa000 : 0x1000)
end_define

begin_define
define|#
directive|define
name|TSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|idx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xa020 + (idx * 0x10)) : (0x1020 + (idx * 0x10)))
end_define

begin_define
define|#
directive|define
name|TSTORM_CLIENT_CONFIG_OFFSET
parameter_list|(
name|port
parameter_list|,
name|client_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x33a0 + (port * 0x1a0) + (client_id * 0x10)) \ 	: (0x9c0 + (port * 0x120) + (client_id * 0x10)))
end_define

begin_define
define|#
directive|define
name|TSTORM_COMMON_SAFC_WORKAROUND_ENABLE_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x1ed8 : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|TSTORM_COMMON_SAFC_WORKAROUND_TIMEOUT_10USEC_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x1eda : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|TSTORM_DEF_SB_HC_DISABLE_OFFSET
parameter_list|(
name|function
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb01a + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0) + (index * 0x4)) : (0x141a + (function * \ 	0x28) + (index * 0x4)))
end_define

begin_define
define|#
directive|define
name|TSTORM_DEF_SB_HOST_SB_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb000 + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0)) : (0x1400 + (function * 0x28)))
end_define

begin_define
define|#
directive|define
name|TSTORM_DEF_SB_HOST_STATUS_BLOCK_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb008 + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0)) : (0x1408 + (function * 0x28)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ETH_STATS_QUERY_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2940 + (function * 0x8)) : (0x4928 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_FUNCTION_COMMON_CONFIG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x3000 + (function * 0x40)) : (0x1500 + \ 	(function * 0x40)))
end_define

begin_define
define|#
directive|define
name|TSTORM_FUNCTION_MODE_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x1ed0 : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|TSTORM_HC_BTR_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xb144 + (port * 0x30)) : (0x1454 + (port * 0x18)))
end_define

begin_define
define|#
directive|define
name|TSTORM_INDIRECTION_TABLE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x12c8 + (function * 0x80)) : (0x22c8 + \ 	(function * 0x80)))
end_define

begin_define
define|#
directive|define
name|TSTORM_INDIRECTION_TABLE_SIZE
value|0x80
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_CONN_BUF_PBL_OFFSET
parameter_list|(
name|function
parameter_list|,
name|pblEntry
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x60c0 + (function * 0x40) + (pblEntry * 0x8)) \ 	: (0x4c30 + (function * 0x40) + (pblEntry * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_ERROR_BITMAP_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6340 + (function * 0x8)) : (0x4cd0 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6004 + (function * 0x8)) : (0x4c04 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6002 + (function * 0x8)) : (0x4c02 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6000 + (function * 0x8)) : (0x4c00 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_RQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6080 + (function * 0x8)) : (0x4c20 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6040 + (function * 0x8)) : (0x4c10 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_LSB_LOCAL_MAC_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6042 + (function * 0x8)) : (0x4c12 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_TCP_VARS_MSB_LOCAL_MAC_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x6044 + (function * 0x8)) : (0x4c14 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_MAC_FILTER_CONFIG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x3008 + (function * 0x40)) : (0x1508 + \ 	(function * 0x40)))
end_define

begin_define
define|#
directive|define
name|TSTORM_PER_COUNTER_ID_STATS_OFFSET
parameter_list|(
name|port
parameter_list|,
name|stats_counter_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2010 + (port * 0x490) + (stats_counter_id * \ 	0x40)) : (0x4010 + (port * 0x490) + (stats_counter_id * 0x40)))
end_define

begin_define
define|#
directive|define
name|TSTORM_STATS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x29c0 + (function * 0x8)) : (0x4948 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|TSTORM_TCP_MAX_CWND_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x4004 + (function * 0x8)) : (0x1fb4 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_AGG_DATA_OFFSET
value|(IS_E1H_OFFSET ? 0xa000 : 0x3000)
end_define

begin_define
define|#
directive|define
name|USTORM_AGG_DATA_SIZE
value|(IS_E1H_OFFSET ? 0x2000 : 0x1000)
end_define

begin_define
define|#
directive|define
name|USTORM_ASSERT_LIST_INDEX_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x8000 : 0x1000)
end_define

begin_define
define|#
directive|define
name|USTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|idx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8020 + (idx * 0x10)) : (0x1020 + (idx * 0x10)))
end_define

begin_define
define|#
directive|define
name|USTORM_CQE_PAGE_BASE_OFFSET
parameter_list|(
name|port
parameter_list|,
name|clientId
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1010 + (port * 0x680) + (clientId * 0x40)) : \ 	(0x4010 + (port * 0x360) + (clientId * 0x30)))
end_define

begin_define
define|#
directive|define
name|USTORM_CQE_PAGE_NEXT_OFFSET
parameter_list|(
name|port
parameter_list|,
name|clientId
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1028 + (port * 0x680) + (clientId * 0x40)) : \ 	(0x4028 + (port * 0x360) + (clientId * 0x30)))
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_PAUSE_ENABLED_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2ad4 + (port * 0x8)) : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_RING_PAUSE_DATA_OFFSET
parameter_list|(
name|port
parameter_list|,
name|clientId
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1030 + (port * 0x680) + (clientId * 0x40)) : \ 	0xffffffff)
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_STATS_QUERY_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2a50 + (function * 0x8)) : (0x1dd0 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_FUNCTION_MODE_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x2448 : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_CQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7044 + (function * 0x8)) : (0x2414 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_CQ_SQN_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7046 + (function * 0x8)) : (0x2416 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_ERROR_BITMAP_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7688 + (function * 0x8)) : (0x29c8 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_GLOBAL_BUF_PHYS_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7648 + (function * 0x8)) : (0x29b8 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7004 + (function * 0x8)) : (0x2404 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7002 + (function * 0x8)) : (0x2402 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7000 + (function * 0x8)) : (0x2400 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_R2TQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7040 + (function * 0x8)) : (0x2410 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_RQ_BUFFER_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7080 + (function * 0x8)) : (0x2420 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_RQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x7084 + (function * 0x8)) : (0x2424 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_MAX_AGG_SIZE_OFFSET
parameter_list|(
name|port
parameter_list|,
name|clientId
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1018 + (port * 0x680) + (clientId * 0x40)) : \ 	(0x4018 + (port * 0x360) + (clientId * 0x30)))
end_define

begin_define
define|#
directive|define
name|USTORM_MEM_WORKAROUND_ADDRESS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2408 + (function * 0x8)) : (0x1da8 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_PER_COUNTER_ID_STATS_OFFSET
parameter_list|(
name|port
parameter_list|,
name|stats_counter_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2450 + (port * 0x2d0) + (stats_counter_id * \ 	0x28)) : (0x1500 + (port * 0x2d0) + (stats_counter_id * 0x28)))
end_define

begin_define
define|#
directive|define
name|USTORM_RX_PRODS_OFFSET
parameter_list|(
name|port
parameter_list|,
name|client_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x1000 + (port * 0x680) + (client_id * 0x40)) \ 	: (0x4000 + (port * 0x360) + (client_id * 0x30)))
end_define

begin_define
define|#
directive|define
name|USTORM_STATS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x29f0 + (function * 0x8)) : (0x1db8 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|USTORM_TPA_BTR_OFFSET
value|(IS_E1H_OFFSET ? 0x3da5 : 0x5095)
end_define

begin_define
define|#
directive|define
name|USTORM_TPA_BTR_SIZE
value|0x1
end_define

begin_define
define|#
directive|define
name|XSTORM_ASSERT_LIST_INDEX_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x9000 : 0x1000)
end_define

begin_define
define|#
directive|define
name|XSTORM_ASSERT_LIST_OFFSET
parameter_list|(
name|idx
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x9020 + (idx * 0x10)) : (0x1020 + (idx * 0x10)))
end_define

begin_define
define|#
directive|define
name|XSTORM_CMNG_PER_PORT_VARS_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x24a8 + (port * 0x50)) : (0x3a80 + (port * 0x50)))
end_define

begin_define
define|#
directive|define
name|XSTORM_DEF_SB_HC_DISABLE_OFFSET
parameter_list|(
name|function
parameter_list|,
name|index
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xa01a + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0) + (index * 0x4)) : (0x141a + (function * \ 	0x28) + (index * 0x4)))
end_define

begin_define
define|#
directive|define
name|XSTORM_DEF_SB_HOST_SB_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xa000 + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0)) : (0x1400 + (function * 0x28)))
end_define

begin_define
define|#
directive|define
name|XSTORM_DEF_SB_HOST_STATUS_BLOCK_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xa008 + ((function>>1) * 0x28) + \ 	((function&1) * 0xa0)) : (0x1408 + (function * 0x28)))
end_define

begin_define
define|#
directive|define
name|XSTORM_E1HOV_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2c10 + (function * 0x8)) : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|XSTORM_ETH_STATS_QUERY_ADDR_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2418 + (function * 0x8)) : (0x3a50 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_FAIRNESS_PER_VN_VARS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2588 + (function * 0x90)) : (0x3b60 + \ 	(function * 0x90)))
end_define

begin_define
define|#
directive|define
name|XSTORM_FUNCTION_MODE_OFFSET
define|\
value|(IS_E1H_OFFSET ? 0x2c50 : 0xffffffff)
end_define

begin_define
define|#
directive|define
name|XSTORM_HC_BTR_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xa144 + (port * 0x30)) : (0x1454 + (port * 0x18)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_HQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x80c0 + (function * 0x8)) : (0x1c30 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR0_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8080 + (function * 0x8)) : (0x1c20 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR1_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8081 + (function * 0x8)) : (0x1c21 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR2_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8082 + (function * 0x8)) : (0x1c22 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR3_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8083 + (function * 0x8)) : (0x1c23 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR4_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8084 + (function * 0x8)) : (0x1c24 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_MAC_ADDR5_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8085 + (function * 0x8)) : (0x1c25 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_LOCAL_VLAN_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8086 + (function * 0x8)) : (0x1c26 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_NUM_OF_TASKS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8004 + (function * 0x8)) : (0x1c04 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_PAGE_SIZE_LOG_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8002 + (function * 0x8)) : (0x1c02 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_PAGE_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8000 + (function * 0x8)) : (0x1c00 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_R2TQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x80c4 + (function * 0x8)) : (0x1c34 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_SQ_SIZE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x80c2 + (function * 0x8)) : (0x1c32 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_ADV_WND_SCL_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8043 + (function * 0x8)) : (0x1c13 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8042 + (function * 0x8)) : (0x1c12 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_TOS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8041 + (function * 0x8)) : (0x1c11 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TCP_VARS_TTL_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x8040 + (function * 0x8)) : (0x1c10 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_PER_COUNTER_ID_STATS_OFFSET
parameter_list|(
name|port
parameter_list|,
name|stats_counter_id
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0xc000 + (port * 0x360) + (stats_counter_id * \ 	0x30)) : (0x3378 + (port * 0x360) + (stats_counter_id * 0x30)))
end_define

begin_define
define|#
directive|define
name|XSTORM_RATE_SHAPING_PER_VN_VARS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2548 + (function * 0x90)) : (0x3b20 + \ 	(function * 0x90)))
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_PAGE_BASE_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2000 + (function * 0x10)) : (0x3328 + \ 	(function * 0x10)))
end_define

begin_define
define|#
directive|define
name|XSTORM_SPQ_PROD_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x2008 + (function * 0x10)) : (0x3330 + \ 	(function * 0x10)))
end_define

begin_define
define|#
directive|define
name|XSTORM_STATS_FLAGS_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x23d8 + (function * 0x8)) : (0x3a40 + \ 	(function * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_ENABLED_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x4000 + (port * 0x8)) : (0x1960 + (port * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_GLOBAL_DEL_ACK_COUNTER_MAX_COUNT_OFFSET
parameter_list|(
name|port
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x4001 + (port * 0x8)) : (0x1961 + (port * 0x8)))
end_define

begin_define
define|#
directive|define
name|XSTORM_TCP_TX_SWS_TIMER_VAL_OFFSET
parameter_list|(
name|function
parameter_list|)
define|\
value|(IS_E1H_OFFSET ? (0x4060 + ((function>>1) * 0x8) + ((function&1) \ 	* 0x4)) : (0x1978 + (function * 0x4)))
end_define

begin_define
define|#
directive|define
name|COMMON_ASM_INVALID_ASSERT_OPCODE
value|0x0
end_define

begin_comment
comment|/** * This file defines HSI constants for the ETH flow */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_EVEREST_MICROCODE
end_ifdef

begin_include
include|#
directive|include
file|"microcode_constants.h"
end_include

begin_include
include|#
directive|include
file|"eth_rx_bd.h"
end_include

begin_include
include|#
directive|include
file|"eth_tx_bd.h"
end_include

begin_include
include|#
directive|include
file|"eth_rx_cqe.h"
end_include

begin_include
include|#
directive|include
file|"eth_rx_sge.h"
end_include

begin_include
include|#
directive|include
file|"eth_rx_cqe_next_page.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSS hash types */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HASH_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|IPV4_HASH_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|TCP_IPV4_HASH_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|IPV6_HASH_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|TCP_IPV6_HASH_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|VLAN_PRI_HASH_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|E1HOV_PRI_HASH_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|DSCP_HASH_TYPE
value|7
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

begin_comment
comment|/* values of command IDs in the ramrod message */
end_comment

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_PORT_SETUP
value|80
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_CLIENT_SETUP
value|85
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_STAT_QUERY
value|90
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_UPDATE
value|100
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_HALT
value|105
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_SET_MAC
value|110
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_CFC_DEL
value|115
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_PORT_DEL
value|120
end_define

begin_define
define|#
directive|define
name|RAMROD_CMD_ID_ETH_FORWARD_SETUP
value|125
end_define

begin_comment
comment|/* command values for set mac command */
end_comment

begin_define
define|#
directive|define
name|T_ETH_MAC_COMMAND_SET
value|0
end_define

begin_define
define|#
directive|define
name|T_ETH_MAC_COMMAND_INVALIDATE
value|1
end_define

begin_define
define|#
directive|define
name|T_ETH_INDIRECTION_TABLE_SIZE
value|128
end_define

begin_comment
comment|/*The CRC32 seed, that is used for the hash(reduction) multicast address */
end_comment

begin_define
define|#
directive|define
name|T_ETH_CRC32_HASH_SEED
value|0x00000000
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
value|26
end_define

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
name|ETH_MAX_AGGREGATION_QUEUES_E1H
value|64
end_define

begin_comment
comment|/* ETH RSS modes */
end_comment

begin_define
define|#
directive|define
name|ETH_RSS_MODE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|ETH_RSS_MODE_REGULAR
value|1
end_define

begin_define
define|#
directive|define
name|ETH_RSS_MODE_VLAN_PRI
value|2
end_define

begin_define
define|#
directive|define
name|ETH_RSS_MODE_E1HOV_PRI
value|3
end_define

begin_define
define|#
directive|define
name|ETH_RSS_MODE_IP_DSCP
value|4
end_define

begin_comment
comment|/** * This file defines HSI constants common to all microcode flows */
end_comment

begin_comment
comment|/* Connection types */
end_comment

begin_define
define|#
directive|define
name|ETH_CONNECTION_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|TOE_CONNECTION_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|RDMA_CONNECTION_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|ISCSI_CONNECTION_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|FCOE_CONNECTION_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|RESERVED_CONNECTION_TYPE_0
value|5
end_define

begin_define
define|#
directive|define
name|RESERVED_CONNECTION_TYPE_1
value|6
end_define

begin_define
define|#
directive|define
name|RESERVED_CONNECTION_TYPE_2
value|7
end_define

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
comment|/* Host coalescing constants */
end_comment

begin_define
define|#
directive|define
name|HC_IGU_BC_MODE
value|0
end_define

begin_define
define|#
directive|define
name|HC_IGU_NBC_MODE
value|1
end_define

begin_define
define|#
directive|define
name|HC_REGULAR_SEGMENT
value|0
end_define

begin_define
define|#
directive|define
name|HC_DEFAULT_SEGMENT
value|1
end_define

begin_comment
comment|/* index numbers */
end_comment

begin_define
define|#
directive|define
name|HC_USTORM_DEF_SB_NUM_INDICES
value|8
end_define

begin_define
define|#
directive|define
name|HC_CSTORM_DEF_SB_NUM_INDICES
value|8
end_define

begin_define
define|#
directive|define
name|HC_XSTORM_DEF_SB_NUM_INDICES
value|4
end_define

begin_define
define|#
directive|define
name|HC_TSTORM_DEF_SB_NUM_INDICES
value|4
end_define

begin_define
define|#
directive|define
name|HC_USTORM_SB_NUM_INDICES
value|4
end_define

begin_define
define|#
directive|define
name|HC_CSTORM_SB_NUM_INDICES
value|4
end_define

begin_comment
comment|/* index values - which counter to update */
end_comment

begin_define
define|#
directive|define
name|HC_INDEX_U_TOE_RX_CQ_CONS
value|0
end_define

begin_define
define|#
directive|define
name|HC_INDEX_U_ETH_RX_CQ_CONS
value|1
end_define

begin_define
define|#
directive|define
name|HC_INDEX_U_ETH_RX_BD_CONS
value|2
end_define

begin_define
define|#
directive|define
name|HC_INDEX_U_FCOE_EQ_CONS
value|3
end_define

begin_define
define|#
directive|define
name|HC_INDEX_C_TOE_TX_CQ_CONS
value|0
end_define

begin_define
define|#
directive|define
name|HC_INDEX_C_ETH_TX_CQ_CONS
value|1
end_define

begin_define
define|#
directive|define
name|HC_INDEX_C_ISCSI_EQ_CONS
value|2
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_X_SPQ_CONS
value|0
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_RDMA_EQ_CONS
value|0
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_RDMA_NAL_PROD
value|1
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_ETH_FW_TX_CQ_CONS
value|2
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_ETH_SLOW_PATH
value|3
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_ETH_RDMA_CQ_CONS
value|4
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_ETH_ISCSI_CQ_CONS
value|5
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_C_ETH_FCOE_CQ_CONS
value|6
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_RDMA_RX_CQ_CONS
value|0
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_ISCSI_RX_CQ_CONS
value|1
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_RDMA_RX_BD_CONS
value|2
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_ISCSI_RX_BD_CONS
value|3
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_FCOE_RX_CQ_CONS
value|4
end_define

begin_define
define|#
directive|define
name|HC_INDEX_DEF_U_ETH_FCOE_RX_BD_CONS
value|5
end_define

begin_comment
comment|/* used by the driver to get the SB offset */
end_comment

begin_define
define|#
directive|define
name|USTORM_ID
value|0
end_define

begin_define
define|#
directive|define
name|CSTORM_ID
value|1
end_define

begin_define
define|#
directive|define
name|XSTORM_ID
value|2
end_define

begin_define
define|#
directive|define
name|TSTORM_ID
value|3
end_define

begin_define
define|#
directive|define
name|ATTENTION_ID
value|4
end_define

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
comment|/* values for RX ETH CQE type field */
end_comment

begin_define
define|#
directive|define
name|RX_ETH_CQE_TYPE_ETH_FASTPATH
value|0
end_define

begin_define
define|#
directive|define
name|RX_ETH_CQE_TYPE_ETH_RAMROD
value|1
end_define

begin_comment
comment|/**** DEFINES FOR TIMERS/CLOCKS RESOLUTIONS ****/
end_comment

begin_define
define|#
directive|define
name|EMULATION_FREQUENCY_FACTOR
value|1600
end_define

begin_define
define|#
directive|define
name|FPGA_FREQUENCY_FACTOR
value|100
end_define

begin_define
define|#
directive|define
name|TIMERS_TICK_SIZE_CHIP
value|(1e-3)
end_define

begin_define
define|#
directive|define
name|TIMERS_TICK_SIZE_EMUL
define|\
value|((TIMERS_TICK_SIZE_CHIP)/((EMULATION_FREQUENCY_FACTOR)))
end_define

begin_define
define|#
directive|define
name|TIMERS_TICK_SIZE_FPGA
define|\
value|((TIMERS_TICK_SIZE_CHIP)/((FPGA_FREQUENCY_FACTOR)))
end_define

begin_define
define|#
directive|define
name|TSEMI_CLK1_RESUL_CHIP
value|(1e-3)
end_define

begin_define
define|#
directive|define
name|TSEMI_CLK1_RESUL_EMUL
define|\
value|((TSEMI_CLK1_RESUL_CHIP)/(EMULATION_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|TSEMI_CLK1_RESUL_FPGA
define|\
value|((TSEMI_CLK1_RESUL_CHIP)/(FPGA_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|USEMI_CLK1_RESUL_CHIP
value|(TIMERS_TICK_SIZE_CHIP)
end_define

begin_define
define|#
directive|define
name|USEMI_CLK1_RESUL_EMUL
value|(TIMERS_TICK_SIZE_EMUL)
end_define

begin_define
define|#
directive|define
name|USEMI_CLK1_RESUL_FPGA
value|(TIMERS_TICK_SIZE_FPGA)
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK1_RESUL_CHIP
value|(1e-3)
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK1_RESUL_EMUL
define|\
value|((XSEMI_CLK1_RESUL_CHIP)/(EMULATION_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK1_RESUL_FPGA
define|\
value|((XSEMI_CLK1_RESUL_CHIP)/(FPGA_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK2_RESUL_CHIP
value|(1e-6)
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK2_RESUL_EMUL
define|\
value|((XSEMI_CLK2_RESUL_CHIP)/(EMULATION_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|XSEMI_CLK2_RESUL_FPGA
define|\
value|((XSEMI_CLK2_RESUL_CHIP)/(FPGA_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|SDM_TIMER_TICK_RESUL_CHIP
value|(4*(1e-6))
end_define

begin_define
define|#
directive|define
name|SDM_TIMER_TICK_RESUL_EMUL
define|\
value|((SDM_TIMER_TICK_RESUL_CHIP)/(EMULATION_FREQUENCY_FACTOR))
end_define

begin_define
define|#
directive|define
name|SDM_TIMER_TICK_RESUL_FPGA
define|\
value|((SDM_TIMER_TICK_RESUL_CHIP)/(FPGA_FREQUENCY_FACTOR))
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

begin_define
define|#
directive|define
name|FW_LOG_LIST_SIZE
value|50
end_define

begin_define
define|#
directive|define
name|NUM_OF_PROTOCOLS
value|4
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
name|MAX_T_STAT_COUNTER_ID
value|18
end_define

begin_define
define|#
directive|define
name|MAX_X_STAT_COUNTER_ID
value|18
end_define

begin_define
define|#
directive|define
name|MAX_U_STAT_COUNTER_ID
value|18
end_define

begin_define
define|#
directive|define
name|UNKNOWN_ADDRESS
value|0
end_define

begin_define
define|#
directive|define
name|UNICAST_ADDRESS
value|1
end_define

begin_define
define|#
directive|define
name|MULTICAST_ADDRESS
value|2
end_define

begin_define
define|#
directive|define
name|BROADCAST_ADDRESS
value|3
end_define

begin_define
define|#
directive|define
name|SINGLE_FUNCTION
value|0
end_define

begin_define
define|#
directive|define
name|MULTI_FUNCTION
value|1
end_define

begin_define
define|#
directive|define
name|IP_V4
value|0
end_define

begin_define
define|#
directive|define
name|IP_V6
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

