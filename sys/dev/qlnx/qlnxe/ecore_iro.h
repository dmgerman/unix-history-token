begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IRO_H__
end_ifndef

begin_define
define|#
directive|define
name|__IRO_H__
end_define

begin_comment
comment|/* Ystorm flow control mode. Use enum fw_flow_ctrl_mode */
end_comment

begin_define
define|#
directive|define
name|YSTORM_FLOW_CONTROL_MODE_OFFSET
value|(IRO[0].base)
end_define

begin_define
define|#
directive|define
name|YSTORM_FLOW_CONTROL_MODE_SIZE
value|(IRO[0].size)
end_define

begin_comment
comment|/* Tstorm port statistics */
end_comment

begin_define
define|#
directive|define
name|TSTORM_PORT_STAT_OFFSET
parameter_list|(
name|port_id
parameter_list|)
value|(IRO[1].base + ((port_id) * IRO[1].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_PORT_STAT_SIZE
value|(IRO[1].size)
end_define

begin_comment
comment|/* Tstorm ll2 port statistics */
end_comment

begin_define
define|#
directive|define
name|TSTORM_LL2_PORT_STAT_OFFSET
parameter_list|(
name|port_id
parameter_list|)
value|(IRO[2].base + ((port_id) * IRO[2].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_LL2_PORT_STAT_SIZE
value|(IRO[2].size)
end_define

begin_comment
comment|/* Ustorm VF-PF Channel ready flag */
end_comment

begin_define
define|#
directive|define
name|USTORM_VF_PF_CHANNEL_READY_OFFSET
parameter_list|(
name|vf_id
parameter_list|)
value|(IRO[3].base + ((vf_id) * IRO[3].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_VF_PF_CHANNEL_READY_SIZE
value|(IRO[3].size)
end_define

begin_comment
comment|/* Ustorm Final flr cleanup ack */
end_comment

begin_define
define|#
directive|define
name|USTORM_FLR_FINAL_ACK_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[4].base + ((pf_id) * IRO[4].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_FLR_FINAL_ACK_SIZE
value|(IRO[4].size)
end_define

begin_comment
comment|/* Ustorm Event ring consumer */
end_comment

begin_define
define|#
directive|define
name|USTORM_EQE_CONS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[5].base + ((pf_id) * IRO[5].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_EQE_CONS_SIZE
value|(IRO[5].size)
end_define

begin_comment
comment|/* Ustorm eth queue zone */
end_comment

begin_define
define|#
directive|define
name|USTORM_ETH_QUEUE_ZONE_OFFSET
parameter_list|(
name|queue_zone_id
parameter_list|)
value|(IRO[6].base + ((queue_zone_id) * IRO[6].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_QUEUE_ZONE_SIZE
value|(IRO[6].size)
end_define

begin_comment
comment|/* Ustorm Common Queue ring consumer */
end_comment

begin_define
define|#
directive|define
name|USTORM_COMMON_QUEUE_CONS_OFFSET
parameter_list|(
name|queue_zone_id
parameter_list|)
value|(IRO[7].base + ((queue_zone_id) * IRO[7].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_COMMON_QUEUE_CONS_SIZE
value|(IRO[7].size)
end_define

begin_comment
comment|/* Xstorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|XSTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[8].base)
end_define

begin_define
define|#
directive|define
name|XSTORM_INTEG_TEST_DATA_SIZE
value|(IRO[8].size)
end_define

begin_comment
comment|/* Ystorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|YSTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[9].base)
end_define

begin_define
define|#
directive|define
name|YSTORM_INTEG_TEST_DATA_SIZE
value|(IRO[9].size)
end_define

begin_comment
comment|/* Pstorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|PSTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[10].base)
end_define

begin_define
define|#
directive|define
name|PSTORM_INTEG_TEST_DATA_SIZE
value|(IRO[10].size)
end_define

begin_comment
comment|/* Tstorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|TSTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[11].base)
end_define

begin_define
define|#
directive|define
name|TSTORM_INTEG_TEST_DATA_SIZE
value|(IRO[11].size)
end_define

begin_comment
comment|/* Mstorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|MSTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[12].base)
end_define

begin_define
define|#
directive|define
name|MSTORM_INTEG_TEST_DATA_SIZE
value|(IRO[12].size)
end_define

begin_comment
comment|/* Ustorm Integration Test Data */
end_comment

begin_define
define|#
directive|define
name|USTORM_INTEG_TEST_DATA_OFFSET
value|(IRO[13].base)
end_define

begin_define
define|#
directive|define
name|USTORM_INTEG_TEST_DATA_SIZE
value|(IRO[13].size)
end_define

begin_comment
comment|/* Tstorm producers */
end_comment

begin_define
define|#
directive|define
name|TSTORM_LL2_RX_PRODS_OFFSET
parameter_list|(
name|core_rx_queue_id
parameter_list|)
value|(IRO[14].base + ((core_rx_queue_id) * IRO[14].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_LL2_RX_PRODS_SIZE
value|(IRO[14].size)
end_define

begin_comment
comment|/* Tstorm LightL2 queue statistics */
end_comment

begin_define
define|#
directive|define
name|CORE_LL2_TSTORM_PER_QUEUE_STAT_OFFSET
parameter_list|(
name|core_rx_queue_id
parameter_list|)
value|(IRO[15].base + ((core_rx_queue_id) * IRO[15].m1))
end_define

begin_define
define|#
directive|define
name|CORE_LL2_TSTORM_PER_QUEUE_STAT_SIZE
value|(IRO[15].size)
end_define

begin_comment
comment|/* Ustorm LiteL2 queue statistics */
end_comment

begin_define
define|#
directive|define
name|CORE_LL2_USTORM_PER_QUEUE_STAT_OFFSET
parameter_list|(
name|core_rx_queue_id
parameter_list|)
value|(IRO[16].base + ((core_rx_queue_id) * IRO[16].m1))
end_define

begin_define
define|#
directive|define
name|CORE_LL2_USTORM_PER_QUEUE_STAT_SIZE
value|(IRO[16].size)
end_define

begin_comment
comment|/* Pstorm LiteL2 queue statistics */
end_comment

begin_define
define|#
directive|define
name|CORE_LL2_PSTORM_PER_QUEUE_STAT_OFFSET
parameter_list|(
name|core_tx_stats_id
parameter_list|)
value|(IRO[17].base + ((core_tx_stats_id) * IRO[17].m1))
end_define

begin_define
define|#
directive|define
name|CORE_LL2_PSTORM_PER_QUEUE_STAT_SIZE
value|(IRO[17].size)
end_define

begin_comment
comment|/* Mstorm queue statistics */
end_comment

begin_define
define|#
directive|define
name|MSTORM_QUEUE_STAT_OFFSET
parameter_list|(
name|stat_counter_id
parameter_list|)
value|(IRO[18].base + ((stat_counter_id) * IRO[18].m1))
end_define

begin_define
define|#
directive|define
name|MSTORM_QUEUE_STAT_SIZE
value|(IRO[18].size)
end_define

begin_comment
comment|/* Mstorm ETH PF queues producers */
end_comment

begin_define
define|#
directive|define
name|MSTORM_ETH_PF_PRODS_OFFSET
parameter_list|(
name|queue_id
parameter_list|)
value|(IRO[19].base + ((queue_id) * IRO[19].m1))
end_define

begin_define
define|#
directive|define
name|MSTORM_ETH_PF_PRODS_SIZE
value|(IRO[19].size)
end_define

begin_comment
comment|/* Mstorm ETH VF queues producers offset in RAM. Used in default VF zone size mode. */
end_comment

begin_define
define|#
directive|define
name|MSTORM_ETH_VF_PRODS_OFFSET
parameter_list|(
name|vf_id
parameter_list|,
name|vf_queue_id
parameter_list|)
value|(IRO[20].base + ((vf_id) * IRO[20].m1) + ((vf_queue_id) * IRO[20].m2))
end_define

begin_define
define|#
directive|define
name|MSTORM_ETH_VF_PRODS_SIZE
value|(IRO[20].size)
end_define

begin_comment
comment|/* TPA agregation timeout in us resolution (on ASIC) */
end_comment

begin_define
define|#
directive|define
name|MSTORM_TPA_TIMEOUT_US_OFFSET
value|(IRO[21].base)
end_define

begin_define
define|#
directive|define
name|MSTORM_TPA_TIMEOUT_US_SIZE
value|(IRO[21].size)
end_define

begin_comment
comment|/* Mstorm pf statistics */
end_comment

begin_define
define|#
directive|define
name|MSTORM_ETH_PF_STAT_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[22].base + ((pf_id) * IRO[22].m1))
end_define

begin_define
define|#
directive|define
name|MSTORM_ETH_PF_STAT_SIZE
value|(IRO[22].size)
end_define

begin_comment
comment|/* Ustorm queue statistics */
end_comment

begin_define
define|#
directive|define
name|USTORM_QUEUE_STAT_OFFSET
parameter_list|(
name|stat_counter_id
parameter_list|)
value|(IRO[23].base + ((stat_counter_id) * IRO[23].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_QUEUE_STAT_SIZE
value|(IRO[23].size)
end_define

begin_comment
comment|/* Ustorm pf statistics */
end_comment

begin_define
define|#
directive|define
name|USTORM_ETH_PF_STAT_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[24].base + ((pf_id) * IRO[24].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ETH_PF_STAT_SIZE
value|(IRO[24].size)
end_define

begin_comment
comment|/* Pstorm queue statistics */
end_comment

begin_define
define|#
directive|define
name|PSTORM_QUEUE_STAT_OFFSET
parameter_list|(
name|stat_counter_id
parameter_list|)
value|(IRO[25].base + ((stat_counter_id) * IRO[25].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_QUEUE_STAT_SIZE
value|(IRO[25].size)
end_define

begin_comment
comment|/* Pstorm pf statistics */
end_comment

begin_define
define|#
directive|define
name|PSTORM_ETH_PF_STAT_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[26].base + ((pf_id) * IRO[26].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_ETH_PF_STAT_SIZE
value|(IRO[26].size)
end_define

begin_comment
comment|/* Control frame's EthType configuration for TX control frame security */
end_comment

begin_define
define|#
directive|define
name|PSTORM_CTL_FRAME_ETHTYPE_OFFSET
parameter_list|(
name|ethType_id
parameter_list|)
value|(IRO[27].base + ((ethType_id) * IRO[27].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_CTL_FRAME_ETHTYPE_SIZE
value|(IRO[27].size)
end_define

begin_comment
comment|/* Tstorm last parser message */
end_comment

begin_define
define|#
directive|define
name|TSTORM_ETH_PRS_INPUT_OFFSET
value|(IRO[28].base)
end_define

begin_define
define|#
directive|define
name|TSTORM_ETH_PRS_INPUT_SIZE
value|(IRO[28].size)
end_define

begin_comment
comment|/* Tstorm Eth limit Rx rate */
end_comment

begin_define
define|#
directive|define
name|ETH_RX_RATE_LIMIT_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[29].base + ((pf_id) * IRO[29].m1))
end_define

begin_define
define|#
directive|define
name|ETH_RX_RATE_LIMIT_SIZE
value|(IRO[29].size)
end_define

begin_comment
comment|/* Xstorm queue zone */
end_comment

begin_define
define|#
directive|define
name|XSTORM_ETH_QUEUE_ZONE_OFFSET
parameter_list|(
name|queue_id
parameter_list|)
value|(IRO[30].base + ((queue_id) * IRO[30].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ETH_QUEUE_ZONE_SIZE
value|(IRO[30].size)
end_define

begin_comment
comment|/* Ystorm cqe producer */
end_comment

begin_define
define|#
directive|define
name|YSTORM_TOE_CQ_PROD_OFFSET
parameter_list|(
name|rss_id
parameter_list|)
value|(IRO[31].base + ((rss_id) * IRO[31].m1))
end_define

begin_define
define|#
directive|define
name|YSTORM_TOE_CQ_PROD_SIZE
value|(IRO[31].size)
end_define

begin_comment
comment|/* Ustorm cqe producer */
end_comment

begin_define
define|#
directive|define
name|USTORM_TOE_CQ_PROD_OFFSET
parameter_list|(
name|rss_id
parameter_list|)
value|(IRO[32].base + ((rss_id) * IRO[32].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_TOE_CQ_PROD_SIZE
value|(IRO[32].size)
end_define

begin_comment
comment|/* Ustorm grq producer */
end_comment

begin_define
define|#
directive|define
name|USTORM_TOE_GRQ_PROD_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[33].base + ((pf_id) * IRO[33].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_TOE_GRQ_PROD_SIZE
value|(IRO[33].size)
end_define

begin_comment
comment|/* Tstorm cmdq-cons of given command queue-id */
end_comment

begin_define
define|#
directive|define
name|TSTORM_SCSI_CMDQ_CONS_OFFSET
parameter_list|(
name|cmdq_queue_id
parameter_list|)
value|(IRO[34].base + ((cmdq_queue_id) * IRO[34].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_SCSI_CMDQ_CONS_SIZE
value|(IRO[34].size)
end_define

begin_comment
comment|/* Tstorm (reflects M-Storm) bdq-external-producer of given function ID, BDqueue-id */
end_comment

begin_define
define|#
directive|define
name|TSTORM_SCSI_BDQ_EXT_PROD_OFFSET
parameter_list|(
name|func_id
parameter_list|,
name|bdq_id
parameter_list|)
value|(IRO[35].base + ((func_id) * IRO[35].m1) + ((bdq_id) * IRO[35].m2))
end_define

begin_define
define|#
directive|define
name|TSTORM_SCSI_BDQ_EXT_PROD_SIZE
value|(IRO[35].size)
end_define

begin_comment
comment|/* Mstorm bdq-external-producer of given BDQ resource ID, BDqueue-id */
end_comment

begin_define
define|#
directive|define
name|MSTORM_SCSI_BDQ_EXT_PROD_OFFSET
parameter_list|(
name|func_id
parameter_list|,
name|bdq_id
parameter_list|)
value|(IRO[36].base + ((func_id) * IRO[36].m1) + ((bdq_id) * IRO[36].m2))
end_define

begin_define
define|#
directive|define
name|MSTORM_SCSI_BDQ_EXT_PROD_SIZE
value|(IRO[36].size)
end_define

begin_comment
comment|/* Tstorm iSCSI RX stats */
end_comment

begin_define
define|#
directive|define
name|TSTORM_ISCSI_RX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[37].base + ((pf_id) * IRO[37].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ISCSI_RX_STATS_SIZE
value|(IRO[37].size)
end_define

begin_comment
comment|/* Mstorm iSCSI RX stats */
end_comment

begin_define
define|#
directive|define
name|MSTORM_ISCSI_RX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[38].base + ((pf_id) * IRO[38].m1))
end_define

begin_define
define|#
directive|define
name|MSTORM_ISCSI_RX_STATS_SIZE
value|(IRO[38].size)
end_define

begin_comment
comment|/* Ustorm iSCSI RX stats */
end_comment

begin_define
define|#
directive|define
name|USTORM_ISCSI_RX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[39].base + ((pf_id) * IRO[39].m1))
end_define

begin_define
define|#
directive|define
name|USTORM_ISCSI_RX_STATS_SIZE
value|(IRO[39].size)
end_define

begin_comment
comment|/* Xstorm iSCSI TX stats */
end_comment

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[40].base + ((pf_id) * IRO[40].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_ISCSI_TX_STATS_SIZE
value|(IRO[40].size)
end_define

begin_comment
comment|/* Ystorm iSCSI TX stats */
end_comment

begin_define
define|#
directive|define
name|YSTORM_ISCSI_TX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[41].base + ((pf_id) * IRO[41].m1))
end_define

begin_define
define|#
directive|define
name|YSTORM_ISCSI_TX_STATS_SIZE
value|(IRO[41].size)
end_define

begin_comment
comment|/* Pstorm iSCSI TX stats */
end_comment

begin_define
define|#
directive|define
name|PSTORM_ISCSI_TX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[42].base + ((pf_id) * IRO[42].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_ISCSI_TX_STATS_SIZE
value|(IRO[42].size)
end_define

begin_comment
comment|/* Tstorm FCoE RX stats */
end_comment

begin_define
define|#
directive|define
name|TSTORM_FCOE_RX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[43].base + ((pf_id) * IRO[43].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_FCOE_RX_STATS_SIZE
value|(IRO[43].size)
end_define

begin_comment
comment|/* Pstorm FCoE TX stats */
end_comment

begin_define
define|#
directive|define
name|PSTORM_FCOE_TX_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[44].base + ((pf_id) * IRO[44].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_FCOE_TX_STATS_SIZE
value|(IRO[44].size)
end_define

begin_comment
comment|/* Pstorm RDMA queue statistics */
end_comment

begin_define
define|#
directive|define
name|PSTORM_RDMA_QUEUE_STAT_OFFSET
parameter_list|(
name|rdma_stat_counter_id
parameter_list|)
value|(IRO[45].base + ((rdma_stat_counter_id) * IRO[45].m1))
end_define

begin_define
define|#
directive|define
name|PSTORM_RDMA_QUEUE_STAT_SIZE
value|(IRO[45].size)
end_define

begin_comment
comment|/* Tstorm RDMA queue statistics */
end_comment

begin_define
define|#
directive|define
name|TSTORM_RDMA_QUEUE_STAT_OFFSET
parameter_list|(
name|rdma_stat_counter_id
parameter_list|)
value|(IRO[46].base + ((rdma_stat_counter_id) * IRO[46].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_RDMA_QUEUE_STAT_SIZE
value|(IRO[46].size)
end_define

begin_comment
comment|/* Xstorm iWARP rxmit stats */
end_comment

begin_define
define|#
directive|define
name|XSTORM_IWARP_RXMIT_STATS_OFFSET
parameter_list|(
name|pf_id
parameter_list|)
value|(IRO[47].base + ((pf_id) * IRO[47].m1))
end_define

begin_define
define|#
directive|define
name|XSTORM_IWARP_RXMIT_STATS_SIZE
value|(IRO[47].size)
end_define

begin_comment
comment|/* Tstorm RoCE Event Statistics */
end_comment

begin_define
define|#
directive|define
name|TSTORM_ROCE_EVENTS_STAT_OFFSET
parameter_list|(
name|roce_pf_id
parameter_list|)
value|(IRO[48].base + ((roce_pf_id) * IRO[48].m1))
end_define

begin_define
define|#
directive|define
name|TSTORM_ROCE_EVENTS_STAT_SIZE
value|(IRO[48].size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IRO_H__ */
end_comment

end_unit

