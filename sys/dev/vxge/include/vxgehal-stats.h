begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_OP_READ
value|0
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_OP_CLEAR_STAT
value|1
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_OP_CLEAR_ALL_VPATH_STATS
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_OP_CLEAR_ALL_STATS_OF_LOC
value|2
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_OP_CLEAR_ALL_STATS
value|3
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_LOC_VPATH
parameter_list|(
name|n
parameter_list|)
value|n
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_LOC_AGGR
value|17
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_LOC_PORT
value|17
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x720+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_DATA_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x728+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_MCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x730+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_BCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x738+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_DISCARDED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x740+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_DISCARDED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_TX_ERRORED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x748+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_TX_ERRORED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x750+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_DATA_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x758+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_MCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x760+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_BCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x768+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_DISCARDED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x770+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_DISCARDED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_ERRORED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x778+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_ERRORED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_AGGRn_RX_U_SLOW_PROTO_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x780+(104*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_AGGRn_RX_U_SLOW_PROTO_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GLOBAL_PROG_EVENT_GNUM0_OFFSET
value|(0x7f0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_GLOBAL_PROG_EVENT_GNUM0
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GLOBAL_PROG_EVENT_GNUM1_OFFSET
value|(0x7f8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_GLOBAL_PROG_EVENT_GNUM1
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_TTL_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x000+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_TTL_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_TTL_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x008+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_TTL_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_DATA_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x010+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_MCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x018+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_BCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x020+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_UCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x028+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_UCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_TAGGED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x030+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_TAGGED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_VLD_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x038+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_VLD_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_VLD_IP_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x040+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_VLD_IP_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_ICMP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x048+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_ICMP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_TCP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x050+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_RST_TCP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x058+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_RST_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_UDP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x060+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_UDP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_UNKNOWN_PROTOCOL_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x068+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_UNKNOWN_PROTOCOL
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_PARSE_ERROR_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x068+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_PARSE_ERROR
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_PAUSE_CTRL_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x070+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_PAUSE_CTRL_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_LACPDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x078+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_LACPDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_MRKR_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x078+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_MRKR_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_MRKR_RESP_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x080+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_MRKR_RESP_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_DROP_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x080+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_DROP_IP
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_XGMII_CHAR1_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x088+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_XGMII_CHAR1_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_XGMII_CHAR2_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x088+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_XGMII_CHAR2_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_XGMII_COL1_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x090+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_XGMII_COL1_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_XGMII_COL2_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x090+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_XGMII_COL2_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_DROP_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x098+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_DROP_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_TX_ANY_ERR_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x098+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_TX_ANY_ERR_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0a0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_VLD_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0a8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_VLD_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_OFFLOAD_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0b0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_OFFLOAD_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0b8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_DATA_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0c0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_OFFLOAD_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0c8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_OFFLOAD_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_VLD_MCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0d0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_VLD_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_VLD_BCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0d8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_VLD_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ACC_UCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0e0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ACC_UCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ACC_NUCAST_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0e8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ACC_NUCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TAGGED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0f0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TAGGED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_LONG_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x0f8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_LONG_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_USIZED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x100+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_USIZED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_OSIZED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x108+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_OSIZED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_FRAG_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x110+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_FRAG_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_JABBER_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x118+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_JABBER_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_64_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x120+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_64_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_65_127_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x128+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_65_127_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_128_255_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x130+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_128_255_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_256_511_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x138+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_256_511_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_512_1023_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x140+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_512_1023_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_1024_1518_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x148+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_1024_1518_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_1519_4095_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x150+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_1519_4095_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_4096_81915_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x158+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_4096_8191_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_8192_MAX_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x160+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_8192_MAX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TTL_GT_MAX_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x168+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TTL_GT_MAX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x170+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ACC_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x178+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ACC_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_IP_OCTETS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x180+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_IP_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ERR_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x188+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ERR_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ICMP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x190+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ICMP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TCP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x198+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_UDP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1a0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_UDP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ERR_TCP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1a8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ERR_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_PAUSE_CNT_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1b0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_PAUSE_CNT
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_PAUSE_CTRL_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1b8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_PAUSE_CTRL_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_UNSUP_CTRL_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1c0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_UNSUP_CTRL_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_FCS_ERR_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1c8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_FCS_ERR_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_IN_RNG_LEN_ERR_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x1d0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_IN_RNG_LEN_ERR_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_OUT_RNG_LEN_ERR_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x1d8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_OUT_RNG_LEN_ERR_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_DROP_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1e0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_DROP_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_DISCARDED_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1e8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_DISCARDED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_DROP_IP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1f0+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_DROP_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_DRP_UDP_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x1f8+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_DRP_UDP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_LACPDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x200+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_LACPDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_MRKR_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x200+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_MRKR_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_MRKR_RESP_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x208+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_MRKR_RESP_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_UNKNOWN_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x208+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_UNKNOWN_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_ILLEGAL_PDU_FRMS_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x210+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_ILLEGAL_PDU_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_FCS_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x210+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_FCS_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_LEN_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x218+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_LEN_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_SWITCH_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x218+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_SWITCH_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_L2_MGMT_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x220+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_L2_MGMT_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_RPA_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x220+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_RPA_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_TRASH_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x228+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_TRASH_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_RTS_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x228+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_RTS_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_RED_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x230+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_RED_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_BUFF_FULL_DISCARD_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x230+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_BUFF_FULL_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_DATA_ERR_CNT_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x238+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_DATA_ERR_CNT
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_CTRL_ERR_CNT_OFFSET
parameter_list|(
name|n
parameter_list|)
define|\
value|((0x238+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_CTRL_ERR_CNT
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_ERR_SYM_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x240+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_ERR_SYM
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_CHAR1_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x240+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_CHAR1_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_CHAR2_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x248+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_CHAR2_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_COL1_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x248+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_COL1_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_XGMII_COL2_MATCH_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x250+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_XGMII_COL2_MATCH
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_LOCAL_FAULT_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x250+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_LOCAL_FAULT
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_REMOTE_FAULT_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x258+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_REMOTE_FAULT
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_PORTn_RX_JETTISON_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((0x258+(608*n))>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_PORTn_RX_JETTISON
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_TTL_ETH_FRMS_OFFSET
value|(0x000>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_TTL_ETH_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_TTL_ETH_OCTETS_OFFSET
value|(0x008>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_TTL_ETH_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_DATA_OCTETS_OFFSET
value|(0x010>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_MCAST_FRMS_OFFSET
value|(0x018>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_BCAST_FRMS_OFFSET
value|(0x020>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_UCAST_FRMS_OFFSET
value|(0x028>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_UCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_TAGGED_FRMS_OFFSET
value|(0x030>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_TAGGED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_VLD_IP_OFFSET
value|(0x038>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_VLD_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_VLD_IP_OCTETS_OFFSET
value|(0x040>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_VLD_IP_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_ICMP_OFFSET
value|(0x048>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_ICMP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_TCP_OFFSET
value|(0x050>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_RST_TCP_OFFSET
value|(0x058>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_RST_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_UDP_OFFSET
value|(0x060>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_UDP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_LOST_IP_OFFSET
value|(0x068>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_LOST_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_UNKNOWN_PROTOCOL_OFFSET
value|(0x068>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_UNKNOWN_PROTOCOL
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_PARSE_ERROR_OFFSET
value|(0x070>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_PARSE_ERROR
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_TCP_OFFLOAD_OFFSET
value|(0x078>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_TCP_OFFLOAD
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_RETX_TCP_OFFLOAD_OFFSET
value|(0x080>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_RETX_TCP_OFFLOAD
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_TX_LOST_IP_OFFLOAD_OFFSET
value|(0x088>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_TX_LOST_IP_OFFLOAD
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_ETH_FRMS_OFFSET
value|(0x090>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_ETH_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_VLD_FRMS_OFFSET
value|(0x098>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_VLD_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_OFFLOAD_FRMS_OFFSET
value|(0x0a0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_OFFLOAD_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_ETH_OCTETS_OFFSET
value|(0x0a8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_ETH_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_DATA_OCTETS_OFFSET
value|(0x0b0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_DATA_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_OFFLOAD_OCTETS_OFFSET
value|(0x0b8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_OFFLOAD_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_VLD_MCAST_FRMS_OFFSET
value|(0x0c0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_VLD_MCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_VLD_BCAST_FRMS_OFFSET
value|(0x0c8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_VLD_BCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ACC_UCAST_FRMS_OFFSET
value|(0x0d0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ACC_UCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ACC_NUCAST_FRMS_OFFSET
value|(0x0d8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ACC_NUCAST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TAGGED_FRMS_OFFSET
value|(0x0e0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TAGGED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_LONG_FRMS_OFFSET
value|(0x0e8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_LONG_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_USIZED_FRMS_OFFSET
value|(0x0f0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_USIZED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_OSIZED_FRMS_OFFSET
value|(0x0f8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_OSIZED_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_FRAG_FRMS_OFFSET
value|(0x100>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_FRAG_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_JABBER_FRMS_OFFSET
value|(0x108>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_JABBER_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_64_FRMS_OFFSET
value|(0x110>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_64_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_65_127_FRMS_OFFSET
value|(0x118>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_65_127_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_128_255_FRMS_OFFSET
value|(0x120>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_128_255_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_256_511_FRMS_OFFSET
value|(0x128>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_256_511_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_512_1023_FRMS_OFFSET
value|(0x130>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_512_1023_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_1024_1518_FRMS_OFFSET
value|(0x138>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_1024_1518_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_1519_4095_FRMS_OFFSET
value|(0x140>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_1519_4095_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_4096_8191_FRMS_OFFSET
value|(0x148>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_4096_8191_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_8192_MAX_FRMS_OFFSET
value|(0x150>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_8192_MAX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TTL_GT_MAX_FRMS_OFFSET
value|(0x158>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TTL_GT_MAX_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_IP_OFFSET
value|(0x160>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ACC_IP_OFFSET
value|(0x168>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ACC_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_IP_OCTETS_OFFSET
value|(0x170>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_IP_OCTETS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ERR_IP_OFFSET
value|(0x178>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ERR_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ICMP_OFFSET
value|(0x180>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ICMP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_TCP_OFFSET
value|(0x188>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_UDP_OFFSET
value|(0x190>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_UDP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_ERR_TCP_OFFSET
value|(0x198>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_ERR_TCP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_LOST_FRMS_OFFSET
value|(0x1a0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_LOST_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_LOST_IP_OFFSET
value|(0x1a8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_LOST_IP
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_LOST_IP_OFFLOAD_OFFSET
value|(0x1b0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_LOST_IP_OFFLOAD
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_QUEUE_FULL_DISCARD_OFFSET
value|(0x1b8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_QUEUE_FULL_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL16(bits, 8)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_RED_DISCARD_OFFSET
value|(0x1b8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_RED_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL16(bits, 24)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_SLEEP_DISCARD_OFFSET
value|(0x1b8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_SLEEP_DISCARD
parameter_list|(
name|bits
parameter_list|)
value|bVAL16(bits, 42)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_RX_MPA_OK_FRMS_OFFSET
value|(0x1c0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_RX_MPA_OK_FRMS
parameter_list|(
name|bits
parameter_list|)
value|bits
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_PROG_EVENT_VNUM0_OFFSET
value|(0x1d0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_PROG_EVENT_VNUM0
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_PROG_EVENT_VNUM1_OFFSET
value|(0x1d0>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_PROG_EVENT_VNUM1
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_PROG_EVENT_VNUM2_OFFSET
value|(0x1d8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_PROG_EVENT_VNUM2
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 0)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_VPATH_PROG_EVENT_VNUM3_OFFSET
value|(0x1d8>>3)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_STATS_GET_VPATH_PROG_EVENT_VNUM3
parameter_list|(
name|bits
parameter_list|)
value|bVAL32(bits, 32)
end_define

begin_comment
comment|/*  * struct vxge_hal_xmac_aggr_stats_t - Per-Aggregator XMAC Statistics  *  * @tx_frms: Count of data frames transmitted on this Aggregator on all  *		its Aggregation ports. Does not include LACPDUs or Marker PDUs.  *		However, does include frames discarded by the Distribution  *		function.  * @tx_data_octets: Count of data and padding octets of frames transmitted  *		on this Aggregator on all its Aggregation ports.Does not include  *		octets of LACPDUs or Marker PDUs. However,does include octets of  *		frames discarded by the Distribution function.  * @tx_mcast_frms: Count of data frames transmitted (to a group destination  *		address other than the broadcast address) on this Aggregator on  *		all its Aggregation ports. Does not include LACPDUs or Marker  *		PDUs. However, does include frames discarded by the Distribution  *		function.  * @tx_bcast_frms: Count of broadcast data frames transmitted on this Aggregator  *		on all its Aggregation ports. Does not include LACPDUs or Marker  *		PDUs. However, does include frames discarded by the Distribution  *		function.  * @tx_discarded_frms: Count of data frames to be transmitted on this Aggregator  *		that are discarded by the Distribution function.This occurs when  *		conversation are allocated to different ports and have to be  *		flushed on old ports  * @tx_errored_frms: Count of data frames transmitted on this Aggregator that  *		experience transmission errors on its Aggregation ports.  * @rx_frms: Count of data frames received on this Aggregator on all its  *		Aggregation ports. Does not include LACPDUs or Marker PDUs.  *		Also, does not include frames discarded by the Collection  *		function.  * @rx_data_octets: Count of data and padding octets of frames received on this  *		Aggregator on all its Aggregation ports. Does not include octets  *		of LACPDUs or Marker PDUs.Also,does not include octets of frames  *		discarded by the Collection function.  * @rx_mcast_frms: Count of data frames received (from a group destination  *		address other than the broadcast address) on this Aggregator on  *		all its Aggregation ports. Does not include LACPDUs or Marker  *		PDUs. Also, does not include frames discarded by the Collection  *		function.  * @rx_bcast_frms: Count of broadcast data frames received on this Aggregator on  *		all its Aggregation ports. Does not include LACPDUs or Marker  *		PDUs. Also, does not include frames discarded by the Collection  *		function.  * @rx_discarded_frms: Count of data frames received on this Aggregator that are  *		discarded by the Collection function because the Collection  *		function was disabled on the port which the frames are received.  * @rx_errored_frms: Count of data frames received on this Aggregator that are  *		discarded by its Aggregation ports, or are discarded by the  *		Collection function of the Aggregator, or that are discarded by  *		the Aggregator due to detection of an illegal Slow Protocols PDU  * @rx_unknown_slow_proto_frms: Count of data frames received on this Aggregator  *		that are discarded by its Aggregation ports due to detection of  *		an unknown Slow Protocols PDU.  *  * Per aggregator XMAC RX statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_xmac_aggr_stats_t
block|{
comment|/* 0x000 */
name|u64
name|tx_frms
decl_stmt|;
comment|/* 0x008 */
name|u64
name|tx_data_octets
decl_stmt|;
comment|/* 0x010 */
name|u64
name|tx_mcast_frms
decl_stmt|;
comment|/* 0x018 */
name|u64
name|tx_bcast_frms
decl_stmt|;
comment|/* 0x020 */
name|u64
name|tx_discarded_frms
decl_stmt|;
comment|/* 0x028 */
name|u64
name|tx_errored_frms
decl_stmt|;
comment|/* 0x030 */
name|u64
name|rx_frms
decl_stmt|;
comment|/* 0x038 */
name|u64
name|rx_data_octets
decl_stmt|;
comment|/* 0x040 */
name|u64
name|rx_mcast_frms
decl_stmt|;
comment|/* 0x048 */
name|u64
name|rx_bcast_frms
decl_stmt|;
comment|/* 0x050 */
name|u64
name|rx_discarded_frms
decl_stmt|;
comment|/* 0x058 */
name|u64
name|rx_errored_frms
decl_stmt|;
comment|/* 0x060 */
name|u64
name|rx_unknown_slow_proto_frms
decl_stmt|;
block|}
name|vxge_hal_xmac_aggr_stats_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_xmac_port_stats_t - XMAC Port Statistics  *  * @tx_ttl_frms: Count of successfully transmitted MAC frames  * @tx_ttl_octets: Count of total octets of transmitted frames, not including  *	   framing characters (i.e. less framing bits). To determine the  *	   total octets of transmitted frames, including framing characters,  *	   multiply PORTn_TX_TTL_FRMS by 8 and add it to this stat (unless  *	   otherwise configured, this stat only counts frames that have  *	   8 bytes of preamble for each frame). This stat can be configured  *	   (see XMAC_STATS_GLOBAL_CFG.TTL_FRMS_HANDLING) to count everything  *	   including the preamble octets.  * @tx_data_octets: Count of data and padding octets of successfully transmitted  *	   frames.  * @tx_mcast_frms: Count of successfully transmitted frames to a group address  *	   other than the broadcast address.  * @tx_bcast_frms: Count of successfully transmitted frames to the broadcast  *	   group address.  * @tx_ucast_frms: Count of transmitted frames containing a unicast address.  *	   Includes discarded frames that are not sent to the network.  * @tx_tagged_frms: Count of transmitted frames containing a VLAN tag.  * @tx_vld_ip: Count of transmitted IP datagrams that are passed to the network.  * @tx_vld_ip_octets: Count of total octets of transmitted IP datagrams that  *	   are passed to the network.  * @tx_icmp: Count of transmitted ICMP messages. Includes messages not sent  *	   due to problems within ICMP.  * @tx_tcp: Count of transmitted TCP segments. Does not include segments  *	   containing retransmitted octets.  * @tx_rst_tcp: Count of transmitted TCP segments containing the RST flag.  * @tx_udp: Count of transmitted UDP datagrams.  * @tx_parse_error: Increments when the TPA is unable to parse a packet. This  *	   generally occurs when a packet is corrupt somehow, including  *	   packets that have IP version mismatches, invalid Layer 2 control  *	   fields, etc. L3/L4 checksums are not offloaded, but the packet  *	   is still be transmitted.  * @tx_unknown_protocol: Increments when the TPA encounters an unknown  *	   protocol, such as a new IPv6 extension header, or an unsupported  *	   Routing Type. The packet still has a checksum calculated but it  *	   may be incorrect.  * @tx_pause_ctrl_frms: Count of MAC PAUSE control frames that are transmitted.  *	   Since, the only control frames supported by this device are  *	   PAUSE frames, this register is a count of all transmitted MAC  *	   control frames.  * @tx_marker_pdu_frms: Count of Marker PDUs transmitted on this Aggr port  * @tx_lacpdu_frms: Count of LACPDUs transmitted on this Aggregation port.  * @tx_drop_ip: Count of transmitted IP datagrams that could not be passed to  *	   the network. Increments because of: 1) An internal processing error  *	   (such as an uncorrectable ECC error). 2) A frame parsing error  *	   during IP checksum calculation.  * @tx_marker_resp_pdu_frms: Count of Marker Response PDUs transmitted on this  *	   Aggregation port.  * @tx_xgmii_char2_match: Maintains a count of the number of transmitted XGMII  *	   characters that match a pattern that is programmable through  *	   register XMAC_STATS_TX_XGMII_CHAR_PORTn. By default, the pattern  *	   is set to /T/ (i.e. the terminate character), thus the statistic  *	   tracks the number of transmitted Terminate characters.  * @tx_xgmii_char1_match: Maintains a count of the number of transmitted XGMII  *	   characters that match a pattern that is programmable through  *	   register XMAC_STATS_TX_XGMII_CHAR_PORTn. By default, the pattern  *	   is set to /S/ (i.e. the start character), thus the statistic tracks  *	   the number of transmitted Start characters.  * @tx_xgmii_column2_match: Maintains a count of the number of transmitted XGMII  *	   columns that match a pattern that is programmable through register  *	   XMAC_STATS_TX_XGMII_COLUMN2_PORTn. By default, the pattern is set  *	   to 4 x /E/ (i.e. a column containing all error characters), thus  *	   the statistic tracks the number of Error columns transmitted at  *	   any time. If XMAC_STATS_TX_XGMII_BEHAV_COLUMN2_PORTn.NEAR_COL1 is  *	   set to 1, then this stat increments when COLUMN2 is found within  *	   'n' clocks after COLUMN1. Here, 'n' is defined by  *	   XMAC_STATS_TX_XGMII_BEHAV_COLUMN2_PORTn.NUM_COL (if 'n' is set  *	   to 0, then it means to search anywhere for COLUMN2).  * @tx_xgmii_column1_match: Maintains a count of the number of transmitted XGMII  *	   columns that match a pattern that is programmable through register  *	   XMAC_STATS_TX_XGMII_COLUMN1_PORTn. By default, the pattern is set  *	   to 4 x /I/ (i.e. a column containing all idle characters), thus the  *	   statistic tracks the number of transmitted Idle columns.  * @unused1: Reserved  * @tx_any_err_frms: Count of transmitted frames containing any error that  *	   prevents them from being passed to the network. Increments if  *	   there is an ECC while reading the frame out of the transmit  *	   buffer. Also increments if the transmit protocol assist (TPA)  *	   block determines that the frame should not be sent.  * @tx_drop_frms: Count of frames that could not be sent for no other reason  *	   than internal MAC processing. Increments once whenever the  *	   transmit buffer is flushed (due to an ECC error on a memory  *	   descriptor).  * @rx_ttl_frms: Count of total received MAC frames, including frames received  *	   with frame-too-long, FCS, or length errors. This stat can be  *	   configured (see XMAC_STATS_GLOBAL_CFG.TTL_FRMS_HANDLING) to count  *	   everything, even "frames" as small one byte of preamble.  * @rx_vld_frms: Count of successfully received MAC frames. Does not include  *	   frames received with frame-too-long, FCS, or length errors.  * @rx_offload_frms: Count of offloaded received frames that are passed to  *	   the host.  * @rx_ttl_octets: Count of total octets of received frames, not including  *	   framing characters (i.e. less framing bits). To determine the  *	   total octets of received frames, including framing characters,  *	   multiply PORTn_RX_TTL_FRMS by 8 and add it to this stat (unless  *	   otherwise configured, this stat only counts frames that have 8  *	   bytes of preamble for each frame). This stat can be configured  *	   (see XMAC_STATS_GLOBAL_CFG.TTL_FRMS_HANDLING) to count everything,  *	   even the preamble octets of "frames" as small one byte of preamble.  * @rx_data_octets: Count of data and padding octets of successfully received  *	   frames. Does not include frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_offload_octets: Count of total octets, not including framing  *	   characters, of offloaded received frames that are passed  *	   to the host.  * @rx_vld_mcast_frms: Count of successfully received MAC frames containing a  *		 nonbroadcast group address. Does not include frames received  *	   with frame-too-long, FCS, or length errors.  * @rx_vld_bcast_frms: Count of successfully received MAC frames containing  *	   the broadcast group address. Does not include frames received  *	   with frame-too-long, FCS, or length errors.  * @rx_accepted_ucast_frms: Count of successfully received frames containing  *	   a unicast address. Only includes frames that are passed to  *	   the system.  * @rx_accepted_nucast_frms: Count of successfully received frames containing  *	   a non-unicast (broadcast or multicast) address. Only includes  *	   frames that are passed to the system. Could include, for instance,  *	   non-unicast frames that contain FCS errors if the MAC_ERROR_CFG  *	   register is set to pass FCS-errored frames to the host.  * @rx_tagged_frms: Count of received frames containing a VLAN tag.  * @rx_long_frms: Count of received frames that are longer than RX_MAX_PYLD_LEN  *	   + 18 bytes (+ 22 bytes if VLAN-tagged).  * @rx_usized_frms: Count of received frames of length (including FCS, but not  *	   framing bits) less than 64 octets, that are otherwise well-formed.  *	   In other words, counts runts.  * @rx_osized_frms: Count of received frames of length (including FCS, but not  *	   framing bits) more than 1518 octets, that are otherwise  *	   well-formed. Note: If register XMAC_STATS_GLOBAL_CFG.VLAN_HANDLING  *	   is set to 1, then "more than 1518 octets" becomes "more than 1518  *	   (1522 if VLAN-tagged) octets".  * @rx_frag_frms: Count of received frames of length (including FCS, but not  *	   framing bits) less than 64 octets that had bad FCS. In other  *	   words, counts fragments.  * @rx_jabber_frms: Count of received frames of length (including FCS, but not  *	   framing bits) more than 1518 octets that had bad FCS. In other  *	   words, counts jabbers. Note: If register  *	   XMAC_STATS_GLOBAL_CFG.VLAN_HANDLING is set to 1, then "more than  *	   1518 octets" becomes "more than 1518 (1522 if VLAN-tagged) octets".  * @rx_ttl_64_frms: Count of total received MAC frames with length (including  *	   FCS, but not framing bits) of exactly 64 octets. Includes frames  *	   received with frame-too-long, FCS, or length errors.  * @rx_ttl_65_127_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 65 and 127  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_128_255_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 128 and 255  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_256_511_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 256 and 511  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_512_1023_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 512 and 1023  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_1024_1518_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 1024 and 1518  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_1519_4095_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 1519 and 4095  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_4096_8191_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 4096 and 8191  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_8192_max_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 8192 and  *	   RX_MAX_PYLD_LEN+18 octets inclusive. Includes frames received  *	   with frame-too-long, FCS, or length errors.  * @rx_ttl_gt_max_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) exceeding  *	   RX_MAX_PYLD_LEN+18 (+22 bytes if VLAN-tagged) octets inclusive.  *	   Includes frames received with frame-too-long, FCS, or length errors.  * @rx_ip: Count of received IP datagrams. Includes errored IP datagrams.  * @rx_accepted_ip: Count of received IP datagrams that are passed to the system  * @rx_ip_octets: Count of number of octets in received IP datagrams. Includes  *	   errored IP datagrams.  * @rx_err_ip:	Count of received IP datagrams containing errors. For example,  *	   bad IP checksum.  * @rx_icmp: Count of received ICMP messages. Includes errored ICMP messages.  * @rx_tcp: Count of received TCP segments. Includes errored TCP segments.  *	   Note: This stat contains a count of all received TCP segments,  *	   regardless of whether or not they pertain to an established  *	   connection.  * @rx_udp: Count of received UDP datagrams.  * @rx_err_tcp: Count of received TCP segments containing errors. For example,  *	   bad TCP checksum.  * @rx_pause_count: Count of number of pause quanta that the MAC has been in  *	   the paused state. Recall, one pause quantum equates to 512  *	   bit times.  * @rx_pause_ctrl_frms: Count of received MAC PAUSE control frames.  * @rx_unsup_ctrl_frms: Count of received MAC control frames that do not  *	   contain the PAUSE opcode. The sum of RX_PAUSE_CTRL_FRMS and  *	   this register is a count of all received MAC control frames.  *	   Note: This stat may be configured to count all layer 2 errors  *	   (i.e. length errors and FCS errors).  * @rx_fcs_err_frms: Count of received MAC frames that do not pass FCS. Does  *	   not include frames received with frame-too-long or  *	   frame-too-short error.  * @rx_in_rng_len_err_frms: Count of received frames with a length/type field  *	   value between 46 (42 for VLAN-tagged frames) and 1500 (also 1500  *	   for VLAN-tagged frames), inclusive, that does not match the  *	   number of data octets (including pad) received. Also contains  *	   a count of received frames with a length/type field less than  *	   46 (42 for VLAN-tagged frames) and the number of data octets  *	   (including pad) received is greater than 46 (42 for VLAN-tagged  *	   frames).  * @rx_out_rng_len_err_frms:  Count of received frames with length/type field  *	   between 1501 and 1535 decimal, inclusive.  * @rx_drop_frms: Count of received frames that could not be passed to the host.  *	   See PORTn_RX_L2_MGMT_DISCARD, PORTn_RX_RPA_DISCARD,  *	   PORTn_RX_TRASH_DISCARD, PORTn_RX_RTS_DISCARD, PORTn_RX_RED_DISCARD  *	   for a list of reasons. Because the RMAC drops one frame at a time,  *	   this stat also indicates the number of drop events.  * @rx_discarded_frms: Count of received frames containing error that prevents  *	   them from being passed to the system. See PORTn_RX_FCS_DISCARD,  *	   PORTn_RX_LEN_DISCARD, and PORTn_RX_SWITCH_DISCARD for a list of  *	   reasons.  * @rx_drop_ip: Count of received IP datagrams that could not be passed to the  *	   host. See PORTn_RX_DROP_FRMS for a list of reasons.  * @rx_drop_udp: Count of received UDP datagrams that are not delivered to the  *	   host. See PORTn_RX_DROP_FRMS for a list of reasons.  * @rx_marker_pdu_frms: Count of valid Marker PDUs received on this Aggregation  *	   port.  * @rx_lacpdu_frms: Count of valid LACPDUs received on this Aggregation port.  * @rx_unknown_pdu_frms: Count of received frames (on this Aggregation port)  *	   that carry the Slow Protocols EtherType, but contain an unknown  *	   PDU. Or frames that contain the Slow Protocols group MAC address,  *	   but do not carry the Slow Protocols EtherType.  * @rx_marker_resp_pdu_frms: Count of valid Marker Response PDUs received on  *	   this Aggregation port.  * @rx_fcs_discard: Count of received frames that are discarded because the  *	   FCS check failed.  * @rx_illegal_pdu_frms: Count of received frames (on this Aggregation port)  *	   that carry the Slow Protocols EtherType, but contain a badly  *	   formed PDU. Or frames that carry the Slow Protocols EtherType,  *	   but contain an illegal value of Protocol Subtype.  * @rx_switch_discard: Count of received frames that are discarded by the  *	   internal switch because they did not have an entry in the  *	   Filtering Database. This includes frames that had an invalid  *	   destination MAC address or VLAN ID. It also includes frames are  *	   discarded because they did not satisfy the length requirements  *	   of the target VPATH.  * @rx_len_discard: Count of received frames that are discarded because of an  *	   invalid frame length (includes fragments, oversized frames and  *	   mismatch between frame length and length/type field). This stat  *	   can be configured (see XMAC_STATS_GLOBAL_CFG.LEN_DISCARD_HANDLING).  * @rx_rpa_discard: Count of received frames that were discarded because the  *	   receive protocol assist (RPA) discovered and error in the frame  *	   or was unable to parse the frame.  * @rx_l2_mgmt_discard: Count of Layer 2 management frames (eg. pause frames,  *	   Link Aggregation Control Protocol (LACP) frames, etc.) that are  *	   discarded.  * @rx_rts_discard: Count of received frames that are discarded by the receive  *	   traffic steering (RTS) logic. Includes those frame discarded  *	   because the SSC response contradicted the switch table, because  *	   the SSC timed out, or because the target queue could not fit the  *	   frame.  * @rx_trash_discard: Count of received frames that are discarded because  *	   receive traffic steering (RTS) steered the frame to the trash  *	   queue.  * @rx_buff_full_discard: Count of received frames that are discarded because  *	   internal buffers are full. Includes frames discarded because the  *	   RTS logic is waiting for an SSC lookup that has no timeout bound.  *	   Also, includes frames that are dropped because the MAC2FAU buffer  *	   is nearly full -- this can happen if the external receive buffer  *	   is full and the receive path is backing up.  * @rx_red_discard: Count of received frames that are discarded because of RED  *	   (Random Early Discard).  * @rx_xgmii_ctrl_err_cnt: Maintains a count of unexpected or misplaced control  *	   characters occurring between times of normal data transmission  *	   (i.e. not included in RX_XGMII_DATA_ERR_CNT). This counter is  *	   incremented when either -  *	   1) The Reconciliation Sublayer (RS) is expecting one control  *		  character and gets another (i.e. is expecting a Start  *		  character, but gets another control character).  *	   2) Start control character is not in lane 0  *	   Only increments the count by one for each XGMII column.  * @rx_xgmii_data_err_cnt: Maintains a count of unexpected control characters  *	   during normal data transmission. If the Reconciliation Sublayer  *	   (RS) receives a control character, other than a terminate control  *	   character, during receipt of data octets then this register is  *	   incremented. Also increments if the start frame delimiter is not  *	   found in the correct location. Only increments the count by one  *	   for each XGMII column.  * @rx_xgmii_char1_match: Maintains a count of the number of XGMII characters  *	   that match a pattern that is programmable through register  *	   XMAC_STATS_RX_XGMII_CHAR_PORTn. By default, the pattern is set  *	   to /E/ (i.e. the error character), thus the statistic tracks the  *	   number of Error characters received at any time.  * @rx_xgmii_err_sym: Count of the number of symbol errors in the received  *	   XGMII data (i.e. PHY indicates "Receive Error" on the XGMII).  *	   Only includes symbol errors that are observed between the XGMII  *	   Start Frame Delimiter and End Frame Delimiter, inclusive. And  *	   only increments the count by one for each frame.  * @rx_xgmii_column1_match: Maintains a count of the number of XGMII columns  *	   that match a pattern that is programmable through register  *	   XMAC_STATS_RX_XGMII_COLUMN1_PORTn. By default, the pattern is set  *	   to 4 x /E/ (i.e. a column containing all error characters), thus  *	   the statistic tracks the number of Error columns received at any  *	   time.  * @rx_xgmii_char2_match: Maintains a count of the number of XGMII characters  *	   that match a pattern that is programmable through register  *	   XMAC_STATS_RX_XGMII_CHAR_PORTn. By default, the pattern is set  *	   to /E/ (i.e. the error character), thus the statistic tracks the  *	   number of Error characters received at any time.  * @rx_local_fault: Maintains a count of the number of times that link  *	   transitioned from "up" to "down" due to a local fault.  * @rx_xgmii_column2_match: Maintains a count of the number of XGMII columns  *	   that match a pattern that is programmable through register  *	   XMAC_STATS_RX_XGMII_COLUMN2_PORTn. By default, the pattern is set  *	   to 4 x /E/ (i.e. a column containing all error characters), thus  *	   the statistic tracks the number of Error columns received at any  *	   time. If XMAC_STATS_RX_XGMII_BEHAV_COLUMN2_PORTn.NEAR_COL1 is set  *	   to 1, then this stat increments when COLUMN2 is found within 'n'  *	   clocks after COLUMN1. Here, 'n' is defined by  *	   XMAC_STATS_RX_XGMII_BEHAV_COLUMN2_PORTn.NUM_COL (if 'n' is set to  *	   0, then it means to search anywhere for COLUMN2).  * @rx_jettison: Count of received frames that are jettisoned because internal  *	   buffers are full.  * @rx_remote_fault: Maintains a count of the number of times that link  *	   transitioned from "up" to "down" due to a remote fault.  *  * XMAC Port Statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_xmac_port_stats_t
block|{
comment|/* 0x000 */
name|u64
name|tx_ttl_frms
decl_stmt|;
comment|/* 0x008 */
name|u64
name|tx_ttl_octets
decl_stmt|;
comment|/* 0x010 */
name|u64
name|tx_data_octets
decl_stmt|;
comment|/* 0x018 */
name|u64
name|tx_mcast_frms
decl_stmt|;
comment|/* 0x020 */
name|u64
name|tx_bcast_frms
decl_stmt|;
comment|/* 0x028 */
name|u64
name|tx_ucast_frms
decl_stmt|;
comment|/* 0x030 */
name|u64
name|tx_tagged_frms
decl_stmt|;
comment|/* 0x038 */
name|u64
name|tx_vld_ip
decl_stmt|;
comment|/* 0x040 */
name|u64
name|tx_vld_ip_octets
decl_stmt|;
comment|/* 0x048 */
name|u64
name|tx_icmp
decl_stmt|;
comment|/* 0x050 */
name|u64
name|tx_tcp
decl_stmt|;
comment|/* 0x058 */
name|u64
name|tx_rst_tcp
decl_stmt|;
comment|/* 0x060 */
name|u64
name|tx_udp
decl_stmt|;
comment|/* 0x068 */
name|u32
name|tx_parse_error
decl_stmt|;
comment|/* 0x06c */
name|u32
name|tx_unknown_protocol
decl_stmt|;
comment|/* 0x070 */
name|u64
name|tx_pause_ctrl_frms
decl_stmt|;
comment|/* 0x078 */
name|u32
name|tx_marker_pdu_frms
decl_stmt|;
comment|/* 0x07c */
name|u32
name|tx_lacpdu_frms
decl_stmt|;
comment|/* 0x080 */
name|u32
name|tx_drop_ip
decl_stmt|;
comment|/* 0x084 */
name|u32
name|tx_marker_resp_pdu_frms
decl_stmt|;
comment|/* 0x088 */
name|u32
name|tx_xgmii_char2_match
decl_stmt|;
comment|/* 0x08c */
name|u32
name|tx_xgmii_char1_match
decl_stmt|;
comment|/* 0x090 */
name|u32
name|tx_xgmii_column2_match
decl_stmt|;
comment|/* 0x094 */
name|u32
name|tx_xgmii_column1_match
decl_stmt|;
comment|/* 0x098 */
name|u32
name|unused1
decl_stmt|;
comment|/* 0x09c */
name|u16
name|tx_any_err_frms
decl_stmt|;
comment|/* 0x09e */
name|u16
name|tx_drop_frms
decl_stmt|;
comment|/* 0x0a0 */
name|u64
name|rx_ttl_frms
decl_stmt|;
comment|/* 0x0a8 */
name|u64
name|rx_vld_frms
decl_stmt|;
comment|/* 0x0b0 */
name|u64
name|rx_offload_frms
decl_stmt|;
comment|/* 0x0b8 */
name|u64
name|rx_ttl_octets
decl_stmt|;
comment|/* 0x0c0 */
name|u64
name|rx_data_octets
decl_stmt|;
comment|/* 0x0c8 */
name|u64
name|rx_offload_octets
decl_stmt|;
comment|/* 0x0d0 */
name|u64
name|rx_vld_mcast_frms
decl_stmt|;
comment|/* 0x0d8 */
name|u64
name|rx_vld_bcast_frms
decl_stmt|;
comment|/* 0x0e0 */
name|u64
name|rx_accepted_ucast_frms
decl_stmt|;
comment|/* 0x0e8 */
name|u64
name|rx_accepted_nucast_frms
decl_stmt|;
comment|/* 0x0f0 */
name|u64
name|rx_tagged_frms
decl_stmt|;
comment|/* 0x0f8 */
name|u64
name|rx_long_frms
decl_stmt|;
comment|/* 0x100 */
name|u64
name|rx_usized_frms
decl_stmt|;
comment|/* 0x108 */
name|u64
name|rx_osized_frms
decl_stmt|;
comment|/* 0x110 */
name|u64
name|rx_frag_frms
decl_stmt|;
comment|/* 0x118 */
name|u64
name|rx_jabber_frms
decl_stmt|;
comment|/* 0x120 */
name|u64
name|rx_ttl_64_frms
decl_stmt|;
comment|/* 0x128 */
name|u64
name|rx_ttl_65_127_frms
decl_stmt|;
comment|/* 0x130 */
name|u64
name|rx_ttl_128_255_frms
decl_stmt|;
comment|/* 0x138 */
name|u64
name|rx_ttl_256_511_frms
decl_stmt|;
comment|/* 0x140 */
name|u64
name|rx_ttl_512_1023_frms
decl_stmt|;
comment|/* 0x148 */
name|u64
name|rx_ttl_1024_1518_frms
decl_stmt|;
comment|/* 0x150 */
name|u64
name|rx_ttl_1519_4095_frms
decl_stmt|;
comment|/* 0x158 */
name|u64
name|rx_ttl_4096_8191_frms
decl_stmt|;
comment|/* 0x160 */
name|u64
name|rx_ttl_8192_max_frms
decl_stmt|;
comment|/* 0x168 */
name|u64
name|rx_ttl_gt_max_frms
decl_stmt|;
comment|/* 0x170 */
name|u64
name|rx_ip
decl_stmt|;
comment|/* 0x178 */
name|u64
name|rx_accepted_ip
decl_stmt|;
comment|/* 0x180 */
name|u64
name|rx_ip_octets
decl_stmt|;
comment|/* 0x188 */
name|u64
name|rx_err_ip
decl_stmt|;
comment|/* 0x190 */
name|u64
name|rx_icmp
decl_stmt|;
comment|/* 0x198 */
name|u64
name|rx_tcp
decl_stmt|;
comment|/* 0x1a0 */
name|u64
name|rx_udp
decl_stmt|;
comment|/* 0x1a8 */
name|u64
name|rx_err_tcp
decl_stmt|;
comment|/* 0x1b0 */
name|u64
name|rx_pause_count
decl_stmt|;
comment|/* 0x1b8 */
name|u64
name|rx_pause_ctrl_frms
decl_stmt|;
comment|/* 0x1c0 */
name|u64
name|rx_unsup_ctrl_frms
decl_stmt|;
comment|/* 0x1c8 */
name|u64
name|rx_fcs_err_frms
decl_stmt|;
comment|/* 0x1d0 */
name|u64
name|rx_in_rng_len_err_frms
decl_stmt|;
comment|/* 0x1d8 */
name|u64
name|rx_out_rng_len_err_frms
decl_stmt|;
comment|/* 0x1e0 */
name|u64
name|rx_drop_frms
decl_stmt|;
comment|/* 0x1e8 */
name|u64
name|rx_discarded_frms
decl_stmt|;
comment|/* 0x1f0 */
name|u64
name|rx_drop_ip
decl_stmt|;
comment|/* 0x1f8 */
name|u64
name|rx_drop_udp
decl_stmt|;
comment|/* 0x200 */
name|u32
name|rx_marker_pdu_frms
decl_stmt|;
comment|/* 0x204 */
name|u32
name|rx_lacpdu_frms
decl_stmt|;
comment|/* 0x208 */
name|u32
name|rx_unknown_pdu_frms
decl_stmt|;
comment|/* 0x20c */
name|u32
name|rx_marker_resp_pdu_frms
decl_stmt|;
comment|/* 0x210 */
name|u32
name|rx_fcs_discard
decl_stmt|;
comment|/* 0x214 */
name|u32
name|rx_illegal_pdu_frms
decl_stmt|;
comment|/* 0x218 */
name|u32
name|rx_switch_discard
decl_stmt|;
comment|/* 0x21c */
name|u32
name|rx_len_discard
decl_stmt|;
comment|/* 0x220 */
name|u32
name|rx_rpa_discard
decl_stmt|;
comment|/* 0x224 */
name|u32
name|rx_l2_mgmt_discard
decl_stmt|;
comment|/* 0x228 */
name|u32
name|rx_rts_discard
decl_stmt|;
comment|/* 0x22c */
name|u32
name|rx_trash_discard
decl_stmt|;
comment|/* 0x230 */
name|u32
name|rx_buff_full_discard
decl_stmt|;
comment|/* 0x234 */
name|u32
name|rx_red_discard
decl_stmt|;
comment|/* 0x238 */
name|u32
name|rx_xgmii_ctrl_err_cnt
decl_stmt|;
comment|/* 0x23c */
name|u32
name|rx_xgmii_data_err_cnt
decl_stmt|;
comment|/* 0x240 */
name|u32
name|rx_xgmii_char1_match
decl_stmt|;
comment|/* 0x244 */
name|u32
name|rx_xgmii_err_sym
decl_stmt|;
comment|/* 0x248 */
name|u32
name|rx_xgmii_column1_match
decl_stmt|;
comment|/* 0x24c */
name|u32
name|rx_xgmii_char2_match
decl_stmt|;
comment|/* 0x250 */
name|u32
name|rx_local_fault
decl_stmt|;
comment|/* 0x254 */
name|u32
name|rx_xgmii_column2_match
decl_stmt|;
comment|/* 0x258 */
name|u32
name|rx_jettison
decl_stmt|;
comment|/* 0x25c */
name|u32
name|rx_remote_fault
decl_stmt|;
block|}
name|vxge_hal_xmac_port_stats_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_mrpcim_xmac_stats_t - XMAC Statistics  *  * @aggr_stats: Statistics on aggregate port(port 0, port 1)  * @port_stats: Staticstics on ports(wire 0, wire 1, lag)  *  * XMAC Statistics.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mrpcim_xmac_stats_t
block|{
name|vxge_hal_xmac_aggr_stats_t
name|aggr_stats
index|[
name|VXGE_HAL_MAC_MAX_AGGR_PORTS
index|]
decl_stmt|;
name|vxge_hal_xmac_port_stats_t
name|port_stats
index|[
name|VXGE_HAL_MAC_MAX_PORTS
index|]
decl_stmt|;
block|}
name|vxge_hal_mrpcim_xmac_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_xmac_vpath_tx_stats_t - XMAC Vpath Tx Statistics  *  * @tx_ttl_eth_frms: Count of successfully transmitted MAC frames.  * @tx_ttl_eth_octets: Count of total octets of transmitted frames,  *		not including framing characters (i.e. less framing bits).  *		To determine the total octets of transmitted frames, including  *		framing characters, multiply TX_TTL_ETH_FRMS by 8 and add it to  *		this stat (the device always prepends 8 bytes of preamble for  *		each frame)  * @tx_data_octets: Count of data and padding octets of successfully transmitted  *		frames.  * @tx_mcast_frms: Count of successfully transmitted frames to a group address  *		other than the broadcast address.  * @tx_bcast_frms: Count of successfully transmitted frames to the broadcast  *		group address.  * @tx_ucast_frms: Count of transmitted frames containing a unicast address.  *		Includes discarded frames that are not sent to the network.  * @tx_tagged_frms: Count of transmitted frames containing a VLAN tag.  * @tx_vld_ip: Count of transmitted IP datagrams that are passed to the network.  * @tx_vld_ip_octets: Count of total octets of transmitted IP datagrams that  *	   are passed to the network.  * @tx_icmp: Count of transmitted ICMP messages. Includes messages not sent due  *	   to problems within ICMP.  * @tx_tcp: Count of transmitted TCP segments. Does not include segments  *	   containing retransmitted octets.  * @tx_rst_tcp: Count of transmitted TCP segments containing the RST flag.  * @tx_udp: Count of transmitted UDP datagrams.  * @tx_unknown_protocol: Increments when the TPA encounters an unknown protocol,  *	   such as a new IPv6 extension header, or an unsupported Routing  *	   Type. The packet still has a checksum calculated but it may be  *	   incorrect.  * @tx_lost_ip: Count of transmitted IP datagrams that could not be passed  *	   to the network. Increments because of: 1) An internal processing  *	   error (such as an uncorrectable ECC error). 2) A frame parsing  *	   error during IP checksum calculation.  * @unused1: Reserved.  * @tx_parse_error: Increments when the TPA is unable to parse a packet. This  *	   generally occurs when a packet is corrupt somehow, including  *	   packets that have IP version mismatches, invalid Layer 2 control  *	   fields, etc. L3/L4 checksums are not offloaded, but the packet  *	   is still be transmitted.  * @tx_tcp_offload: For frames belonging to offloaded sessions only, a count  *	   of transmitted TCP segments. Does not include segments containing  *	   retransmitted octets.  * @tx_retx_tcp_offload: For frames belonging to offloaded sessions only, the  *	   total number of segments retransmitted. Retransmitted segments  *	   that are sourced by the host are counted by the host.  * @tx_lost_ip_offload: For frames belonging to offloaded sessions only, a count  *	   of transmitted IP datagrams that could not be passed to the  *	   network.  *  * XMAC Vpath TX Statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_xmac_vpath_tx_stats_t
block|{
name|u64
name|tx_ttl_eth_frms
decl_stmt|;
name|u64
name|tx_ttl_eth_octets
decl_stmt|;
name|u64
name|tx_data_octets
decl_stmt|;
name|u64
name|tx_mcast_frms
decl_stmt|;
name|u64
name|tx_bcast_frms
decl_stmt|;
name|u64
name|tx_ucast_frms
decl_stmt|;
name|u64
name|tx_tagged_frms
decl_stmt|;
name|u64
name|tx_vld_ip
decl_stmt|;
name|u64
name|tx_vld_ip_octets
decl_stmt|;
name|u64
name|tx_icmp
decl_stmt|;
name|u64
name|tx_tcp
decl_stmt|;
name|u64
name|tx_rst_tcp
decl_stmt|;
name|u64
name|tx_udp
decl_stmt|;
name|u32
name|tx_unknown_protocol
decl_stmt|;
name|u32
name|tx_lost_ip
decl_stmt|;
name|u32
name|unused1
decl_stmt|;
name|u32
name|tx_parse_error
decl_stmt|;
name|u64
name|tx_tcp_offload
decl_stmt|;
name|u64
name|tx_retx_tcp_offload
decl_stmt|;
name|u64
name|tx_lost_ip_offload
decl_stmt|;
block|}
name|vxge_hal_xmac_vpath_tx_stats_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_xmac_vpath_rx_stats_t - XMAC Vpath RX Statistics  *  * @rx_ttl_eth_frms: Count of successfully received MAC frames.  * @rx_vld_frms: Count of successfully received MAC frames. Does not include  *	   frames received with frame-too-long, FCS, or length errors.  * @rx_offload_frms: Count of offloaded received frames that are passed to  *	   the host.  * @rx_ttl_eth_octets: Count of total octets of received frames, not including  *	   framing characters (i.e. less framing bits). Only counts octets  *	   of frames that are at least 14 bytes (18 bytes for VLAN-tagged)  *	   before FCS. To determine the total octets of received frames,  *	   including framing characters, multiply RX_TTL_ETH_FRMS by 8 and  *	   add it to this stat (the stat RX_TTL_ETH_FRMS only counts frames  *	   that have the required 8 bytes of preamble).  * @rx_data_octets: Count of data and padding octets of successfully received  *	   frames. Does not include frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_offload_octets: Count of total octets, not including framing characters,  *	   of offloaded received frames that are passed to the host.  * @rx_vld_mcast_frms: Count of successfully received MAC frames containing a  *	   nonbroadcast group address. Does not include frames received with  *	   frame-too-long, FCS, or length errors.  * @rx_vld_bcast_frms: Count of successfully received MAC frames containing the  *	   broadcast group address. Does not include frames received with  *	   frame-too-long, FCS, or length errors.  * @rx_accepted_ucast_frms: Count of successfully received frames containing  *	   a unicast address. Only includes frames that are passed to the  *	   system.  * @rx_accepted_nucast_frms: Count of successfully received frames containing  *	   a non-unicast (broadcast or multicast) address. Only includes  *	   frames that are passed to the system. Could include, for instance,  *	   non-unicast frames that contain FCS errors if the MAC_ERROR_CFG  *	   register is set to pass FCS-errored frames to the host.  * @rx_tagged_frms: Count of received frames containing a VLAN tag.  * @rx_long_frms: Count of received frames that are longer than RX_MAX_PYLD_LEN  *	   + 18 bytes (+ 22 bytes if VLAN-tagged).  * @rx_usized_frms: Count of received frames of length (including FCS, but not  *	   framing bits) less than 64 octets, that are otherwise well-formed.  *	   In other words, counts runts.  * @rx_osized_frms: Count of received frames of length (including FCS, but not  *	   framing bits) more than 1518 octets, that are otherwise  *	   well-formed.  * @rx_frag_frms: Count of received frames of length (including FCS, but not  *	   framing bits) less than 64 octets that had bad FCS. In other words,  *	   counts fragments.  * @rx_jabber_frms: Count of received frames of length (including FCS, but not  *	   framing bits) more than 1518 octets that had bad FCS. In other  *	   words, counts jabbers.  * @rx_ttl_64_frms: Count of total received MAC frames with length (including  *	   FCS, but not framing bits) of exactly 64 octets. Includes frames  *	   received with frame-too-long, FCS, or length errors.  * @rx_ttl_65_127_frms: Count of total received MAC frames with length(including  *	   FCS, but not framing bits) of between 65 and 127 octets inclusive.  *	   Includes frames received with frame-too-long, FCS, or length errors.  * @rx_ttl_128_255_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 128 and 255 octets  *	   inclusive. Includes frames received with frame-too-long, FCS,  *	   or length errors.  * @rx_ttl_256_511_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 256 and 511 octets  *	   inclusive. Includes frames received with frame-too-long, FCS, or  *	   length errors.  * @rx_ttl_512_1023_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 512 and 1023  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_1024_1518_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 1024 and 1518  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_1519_4095_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 1519 and 4095  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_4096_8191_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 4096 and 8191  *	   octets inclusive. Includes frames received with frame-too-long,  *	   FCS, or length errors.  * @rx_ttl_8192_max_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) of between 8192 and  *	   RX_MAX_PYLD_LEN+18 octets inclusive. Includes frames received  *	   with frame-too-long, FCS, or length errors.  * @rx_ttl_gt_max_frms: Count of total received MAC frames with length  *	   (including FCS, but not framing bits) exceeding RX_MAX_PYLD_LEN+18  *	   (+22 bytes if VLAN-tagged) octets inclusive. Includes frames  *	   received with frame-too-long, FCS, or length errors.  * @rx_ip: Count of received IP datagrams. Includes errored IP datagrams.  * @rx_accepted_ip: Count of received IP datagrams that are passed to the system  * @rx_ip_octets: Count of number of octets in received IP datagrams.  *	   Includes errored IP datagrams.  * @rx_err_ip: Count of received IP datagrams containing errors. For example,  *	   bad IP checksum.  * @rx_icmp: Count of received ICMP messages. Includes errored ICMP messages.  * @rx_tcp: Count of received TCP segments. Includes errored TCP segments.  *		Note: This stat contains a count of all received TCP segments,  *		regardless of whether or not they pertain to an established  *		connection.  * @rx_udp: Count of received UDP datagrams.  * @rx_err_tcp: Count of received TCP segments containing errors. For example,  *		bad TCP checksum.  * @rx_lost_frms: Count of received frames that could not be passed to the host.  *		See RX_QUEUE_FULL_DISCARD and RX_RED_DISCARD for list of reasons  * @rx_lost_ip: Count of received IP datagrams that could not be passed to  *		the host. See RX_LOST_FRMS for a list of reasons.  * @rx_lost_ip_offload: For frames belonging to offloaded sessions only, a count  *		of received IP datagrams that could not be passed to the host.  *		See RX_LOST_FRMS for a list of reasons.  * @rx_various_discard: Count of received frames that are discarded because  *		the target receive queue is full.  * @rx_sleep_discard: Count of received frames that are discarded because the  *	   target VPATH is asleep (a Wake-on-LAN magic packet can be used  *	   to awaken the VPATH).  * @rx_red_discard: Count of received frames that are discarded because of RED  *	   (Random Early Discard).  * @rx_queue_full_discard: Count of received frames that are discarded because  *		the target receive queue is full.  * @rx_mpa_ok_frms: Count of received frames that pass the MPA checks.  *  * XMAC Vpath RX Statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_xmac_vpath_rx_stats_t
block|{
name|u64
name|rx_ttl_eth_frms
decl_stmt|;
name|u64
name|rx_vld_frms
decl_stmt|;
name|u64
name|rx_offload_frms
decl_stmt|;
name|u64
name|rx_ttl_eth_octets
decl_stmt|;
name|u64
name|rx_data_octets
decl_stmt|;
name|u64
name|rx_offload_octets
decl_stmt|;
name|u64
name|rx_vld_mcast_frms
decl_stmt|;
name|u64
name|rx_vld_bcast_frms
decl_stmt|;
name|u64
name|rx_accepted_ucast_frms
decl_stmt|;
name|u64
name|rx_accepted_nucast_frms
decl_stmt|;
name|u64
name|rx_tagged_frms
decl_stmt|;
name|u64
name|rx_long_frms
decl_stmt|;
name|u64
name|rx_usized_frms
decl_stmt|;
name|u64
name|rx_osized_frms
decl_stmt|;
name|u64
name|rx_frag_frms
decl_stmt|;
name|u64
name|rx_jabber_frms
decl_stmt|;
name|u64
name|rx_ttl_64_frms
decl_stmt|;
name|u64
name|rx_ttl_65_127_frms
decl_stmt|;
name|u64
name|rx_ttl_128_255_frms
decl_stmt|;
name|u64
name|rx_ttl_256_511_frms
decl_stmt|;
name|u64
name|rx_ttl_512_1023_frms
decl_stmt|;
name|u64
name|rx_ttl_1024_1518_frms
decl_stmt|;
name|u64
name|rx_ttl_1519_4095_frms
decl_stmt|;
name|u64
name|rx_ttl_4096_8191_frms
decl_stmt|;
name|u64
name|rx_ttl_8192_max_frms
decl_stmt|;
name|u64
name|rx_ttl_gt_max_frms
decl_stmt|;
name|u64
name|rx_ip
decl_stmt|;
name|u64
name|rx_accepted_ip
decl_stmt|;
name|u64
name|rx_ip_octets
decl_stmt|;
name|u64
name|rx_err_ip
decl_stmt|;
name|u64
name|rx_icmp
decl_stmt|;
name|u64
name|rx_tcp
decl_stmt|;
name|u64
name|rx_udp
decl_stmt|;
name|u64
name|rx_err_tcp
decl_stmt|;
name|u64
name|rx_lost_frms
decl_stmt|;
name|u64
name|rx_lost_ip
decl_stmt|;
name|u64
name|rx_lost_ip_offload
decl_stmt|;
name|u16
name|rx_various_discard
decl_stmt|;
name|u16
name|rx_sleep_discard
decl_stmt|;
name|u16
name|rx_red_discard
decl_stmt|;
name|u16
name|rx_queue_full_discard
decl_stmt|;
name|u64
name|rx_mpa_ok_frms
decl_stmt|;
block|}
name|vxge_hal_xmac_vpath_rx_stats_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_device_xmac_stats_t - XMAC Statistics  *  * @vpath_tx_stats: Per vpath XMAC TX stats  * @vpath_rx_stats: Per vpath XMAC RX stats  *  * XMAC Statistics.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_device_xmac_stats_t
block|{
name|vxge_hal_xmac_vpath_tx_stats_t
name|vpath_tx_stats
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
name|vxge_hal_xmac_vpath_rx_stats_t
name|vpath_rx_stats
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
block|}
name|vxge_hal_device_xmac_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_hw_info_t - X3100 vpath hardware statistics.  * @ini_num_mwr_sent: The number of PCI memory writes initiated by the PIC block  *		for the given VPATH  * @unused1: Reserved  * @ini_num_mrd_sent: The number of PCI memory reads initiated by the PIC block  * @unused2: Reserved  * @ini_num_cpl_rcvd: The number of PCI read completions received by the  *		PIC block  * @unused3: Reserved  * @ini_num_mwr_byte_sent: The number of PCI memory write bytes sent by the PIC  *		block to the host  * @ini_num_cpl_byte_rcvd: The number of PCI read completion bytes received by  *		the PIC block  * @wrcrdtarb_xoff: TBD  * @unused4: Reserved  * @rdcrdtarb_xoff: TBD  * @unused5: Reserved  * @vpath_genstats_count0: Configurable statistic #1. Refer to the GENSTATS0_CFG  *		for information on configuring this statistic  * @vpath_genstats_count1: Configurable statistic #2. Refer to the GENSTATS1_CFG  *		for information on configuring this statistic  * @vpath_genstats_count2: Configurable statistic #3. Refer to the GENSTATS2_CFG  *		for information on configuring this statistic  * @vpath_genstats_count3: Configurable statistic #4. Refer to the GENSTATS3_CFG  *		for information on configuring this statistic  * @vpath_genstats_count4: Configurable statistic #5. Refer to the GENSTATS4_CFG  *		for information on configuring this statistic  * @unused6: Reserved  * @vpath_gennstats_count5: Configurable statistic #6. Refer to the  *		GENSTATS5_CFG for information on configuring this statistic  * @unused7: Reserved  * @tx_stats: Transmit stats  * @rx_stats: Receive stats  * @unused9: Reserved  * @prog_event_vnum1: Programmable statistic. Increments when internal logic  *		detects a certain event. See register  *		XMAC_STATS_CFG.EVENT_VNUM1_CFG for more information.  * @prog_event_vnum0: Programmable statistic. Increments when internal logic  *		detects a certain event. See register  *		XMAC_STATS_CFG.EVENT_VNUM0_CFG for more information.  * @prog_event_vnum3: Programmable statistic. Increments when internal logic  *		detects a certain event. See register  *		XMAC_STATS_CFG.EVENT_VNUM3_CFG for more information.  * @prog_event_vnum2: Programmable statistic. Increments when internal logic  *		detects a certain event. See register  *		XMAC_STATS_CFG.EVENT_VNUM2_CFG for more information.  * @rx_multi_cast_frame_discard: TBD  * @unused10: Reserved  * @rx_frm_transferred: TBD  * @unused11: Reserved  * @rxd_returned: TBD  * @unused12: Reserved  * @rx_mpa_len_fail_frms: Count of received frames failed the MPA length check  * @rx_mpa_mrk_fail_frms: Count of received frames failed the MPA marker check  * @rx_mpa_crc_fail_frms: Count of received frames failed the MPA CRC check  * @rx_permitted_frms: Count of frames that pass through the FAU and on to the  *		frame buffer (and subsequently to the host).  * @rx_vp_reset_discarded_frms: Count of receive frames that are discarded  *		because the VPATH is in reset  * @rx_wol_frms: Count of received "magic packet" frames. Stat increments  *		whenever the received frame matches the VPATH's Wake-on-LAN  *		signature(s) CRC.  * @tx_vp_reset_discarded_frms: Count of transmit frames that are discarded  *		because the VPATH is in reset.Includes frames that are discarded  *		because the current VPIN does not match that VPIN of the frame  *  * X3100 vpath hardware statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_hw_info_t
block|{
comment|/* 0x000 */
name|u32
name|ini_num_mwr_sent
decl_stmt|;
comment|/* 0x004 */
name|u32
name|unused1
decl_stmt|;
comment|/* 0x008 */
name|u32
name|ini_num_mrd_sent
decl_stmt|;
comment|/* 0x00c */
name|u32
name|unused2
decl_stmt|;
comment|/* 0x010 */
name|u32
name|ini_num_cpl_rcvd
decl_stmt|;
comment|/* 0x014 */
name|u32
name|unused3
decl_stmt|;
comment|/* 0x018 */
name|u64
name|ini_num_mwr_byte_sent
decl_stmt|;
comment|/* 0x020 */
name|u64
name|ini_num_cpl_byte_rcvd
decl_stmt|;
comment|/* 0x028 */
name|u32
name|wrcrdtarb_xoff
decl_stmt|;
comment|/* 0x02c */
name|u32
name|unused4
decl_stmt|;
comment|/* 0x030 */
name|u32
name|rdcrdtarb_xoff
decl_stmt|;
comment|/* 0x034 */
name|u32
name|unused5
decl_stmt|;
comment|/* 0x038 */
name|u32
name|vpath_genstats_count0
decl_stmt|;
comment|/* 0x03c */
name|u32
name|vpath_genstats_count1
decl_stmt|;
comment|/* 0x040 */
name|u32
name|vpath_genstats_count2
decl_stmt|;
comment|/* 0x044 */
name|u32
name|vpath_genstats_count3
decl_stmt|;
comment|/* 0x048 */
name|u32
name|vpath_genstats_count4
decl_stmt|;
comment|/* 0x04c */
name|u32
name|unused6
decl_stmt|;
comment|/* 0x050 */
name|u32
name|vpath_genstats_count5
decl_stmt|;
comment|/* 0x054 */
name|u32
name|unused7
decl_stmt|;
comment|/* 0x058 */
name|vxge_hal_xmac_vpath_tx_stats_t
name|tx_stats
decl_stmt|;
comment|/* 0x0e8 */
name|vxge_hal_xmac_vpath_rx_stats_t
name|rx_stats
decl_stmt|;
comment|/* 0x220 */
name|u64
name|unused9
decl_stmt|;
comment|/* 0x228 */
name|u32
name|prog_event_vnum1
decl_stmt|;
comment|/* 0x22c */
name|u32
name|prog_event_vnum0
decl_stmt|;
comment|/* 0x230 */
name|u32
name|prog_event_vnum3
decl_stmt|;
comment|/* 0x234 */
name|u32
name|prog_event_vnum2
decl_stmt|;
comment|/* 0x238 */
name|u16
name|rx_multi_cast_frame_discard
decl_stmt|;
comment|/* 0x23a */
name|u8
name|unused10
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x240 */
name|u32
name|rx_frm_transferred
decl_stmt|;
comment|/* 0x244 */
name|u32
name|unused11
decl_stmt|;
comment|/* 0x248 */
name|u16
name|rxd_returned
decl_stmt|;
comment|/* 0x24a */
name|u8
name|unused12
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x252 */
name|u16
name|rx_mpa_len_fail_frms
decl_stmt|;
comment|/* 0x254 */
name|u16
name|rx_mpa_mrk_fail_frms
decl_stmt|;
comment|/* 0x256 */
name|u16
name|rx_mpa_crc_fail_frms
decl_stmt|;
comment|/* 0x258 */
name|u16
name|rx_permitted_frms
decl_stmt|;
comment|/* 0x25c */
name|u64
name|rx_vp_reset_discarded_frms
decl_stmt|;
comment|/* 0x25e */
name|u64
name|rx_wol_frms
decl_stmt|;
comment|/* 0x260 */
name|u64
name|tx_vp_reset_discarded_frms
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_hw_info_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_device_stats_mrpcim_info_t - X3100 mrpcim hardware  *					    statistics.  * @pic_ini_rd_drop: Number of DMA reads initiated by the adapter that were  *		discarded because the VPATH is out of service  * @pic_ini_wr_drop: Number of DMA writes initiated by the adapter that were  *		discared because the VPATH is out of service  * @pic_wrcrdtarb_ph_crdt_depleted: Number of times the posted header credits  *		for upstream PCI writes were depleted  * @unused1: Reserved  * @pic_wrcrdtarb_ph_crdt_depleted_vplane: Array of structures containing above  *		two fields.  * @pic_wrcrdtarb_pd_crdt_depleted: Number of times the posted data credits for  *		upstream PCI writes were depleted  * @unused2: Reserved  * @pic_wrcrdtarb_pd_crdt_depleted_vplane: Array of structures containing above  *		two fields.  * @pic_rdcrdtarb_nph_crdt_depleted: Number of times the non-posted header  *		credits for upstream PCI reads were depleted  * @unused3: Reserved  * @pic_rdcrdtarb_nph_crdt_depleted_vplane: Array of structures containing above  *		two fields.  * @pic_ini_rd_vpin_drop: Number of DMA reads initiated by the adapter that were  *		discarded because the VPATH instance number does not match  * @pic_ini_wr_vpin_drop: Number of DMA writes initiated by the adapter that  *		were discarded because the VPATH instance number does not match  * @pic_genstats_count0: Configurable statistic #1. Refer to the GENSTATS0_CFG  *		for information on configuring this statistic  * @pic_genstats_count1: Configurable statistic #2. Refer to the GENSTATS1_CFG  *		for information on configuring this statistic  * @pic_genstats_count2: Configurable statistic #3. Refer to the GENSTATS2_CFG  *		for information on configuring this statistic  * @pic_genstats_count3: Configurable statistic #4. Refer to the GENSTATS3_CFG  *		for information on configuring this statistic  * @pic_genstats_count4: Configurable statistic #5. Refer to the GENSTATS4_CFG  *		for information on configuring this statistic  * @unused4: Reserved  * @pic_genstats_count5: Configurable statistic #6. Refer to the GENSTATS5_CFG  *		for information on configuring this statistic  * @unused5: Reserved  * @pci_rstdrop_cpl: TBD  * @pci_rstdrop_msg: TBD  * @pci_rstdrop_client1: TBD  * @pci_rstdrop_client0: TBD  * @pci_rstdrop_client2: TBD  * @unused6: Reserved  * @unused7: Reserved  * @pci_depl_cplh: Number of times completion header credits were depleted  * @pci_depl_nph: Number of times non posted header credits were depleted  * @pci_depl_ph: Number of times the posted header credits were depleted  * @pci_depl_h_vplane: Array of structures containing above four fields.  * @unused8: Reserved  * @pci_depl_cpld: Number of times completion data credits were depleted  * @pci_depl_npd: Number of times non posted data credits were depleted  * @pci_depl_pd: Number of times the posted data credits were depleted  * @pci_depl_d_vplane: Array of structures containing above four fields.  * @xgmac_port: Array of xmac port stats  * @xgmac_aggr: Array of aggr port stats  * @xgmac_global_prog_event_gnum0: Programmable statistic. Increments when  *		internal logic detects a certain event. See register  *		XMAC_STATS_GLOBAL_CFG.EVENT_GNUM0_CFG for more information.  * @xgmac_global_prog_event_gnum1: Programmable statistic. Increments when  *		internal logic detects a certain event. See register  *		XMAC_STATS_GLOBAL_CFG.EVENT_GNUM1_CFG for more information.  * @unused9: Reserved  * @xgmac.orp_lro_events: TBD  * @xgmac.orp_bs_events: TBD  * @xgmac.orp_iwarp_events: TBD  * @unused10: Reserved  * @xgmac.tx_permitted_frms: TBD  * @unused11: Reserved  * @unused12: Reserved  * @xgmac.port2_tx_any_frms: TBD  * @xgmac.port1_tx_any_frms: TBD  * @xgmac.port0_tx_any_frms: TBD  * @unused13: Reserved  * @unused14: Reserved  * @xgmac.port2_rx_any_frms: TBD  * @xgmac.port1_rx_any_frms: TBD  * @xgmac.port0_rx_any_frms: TBD  *  * X3100 mrpcim hardware statistics.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mrpcim_stats_hw_info_t
block|{
comment|/* 0x0000 */
name|u32
name|pic_ini_rd_drop
decl_stmt|;
comment|/* 0x0004 */
name|u32
name|pic_ini_wr_drop
decl_stmt|;
comment|/* 0x0008 */
struct|struct
block|{
comment|/* 0x0000 */
name|u32
name|pic_wrcrdtarb_ph_crdt_depleted
decl_stmt|;
comment|/* 0x0004 */
name|u32
name|unused1
decl_stmt|;
block|}
name|pic_wrcrdtarb_ph_crdt_depleted_vplane
index|[
literal|17
index|]
struct|;
comment|/* 0x0090 */
struct|struct
block|{
comment|/* 0x0000 */
name|u32
name|pic_wrcrdtarb_pd_crdt_depleted
decl_stmt|;
comment|/* 0x0004 */
name|u32
name|unused2
decl_stmt|;
block|}
name|pic_wrcrdtarb_pd_crdt_depleted_vplane
index|[
literal|17
index|]
struct|;
comment|/* 0x0118 */
struct|struct
block|{
comment|/* 0x0000 */
name|u32
name|pic_rdcrdtarb_nph_crdt_depleted
decl_stmt|;
comment|/* 0x0004 */
name|u32
name|unused3
decl_stmt|;
block|}
name|pic_rdcrdtarb_nph_crdt_depleted_vplane
index|[
literal|17
index|]
struct|;
comment|/* 0x01a0 */
name|u32
name|pic_ini_rd_vpin_drop
decl_stmt|;
comment|/* 0x01a4 */
name|u32
name|pic_ini_wr_vpin_drop
decl_stmt|;
comment|/* 0x01a8 */
name|u32
name|pic_genstats_count0
decl_stmt|;
comment|/* 0x01ac */
name|u32
name|pic_genstats_count1
decl_stmt|;
comment|/* 0x01b0 */
name|u32
name|pic_genstats_count2
decl_stmt|;
comment|/* 0x01b4 */
name|u32
name|pic_genstats_count3
decl_stmt|;
comment|/* 0x01b8 */
name|u32
name|pic_genstats_count4
decl_stmt|;
comment|/* 0x01bc */
name|u32
name|unused4
decl_stmt|;
comment|/* 0x01c0 */
name|u32
name|pic_genstats_count5
decl_stmt|;
comment|/* 0x01c4 */
name|u32
name|unused5
decl_stmt|;
comment|/* 0x01c8 */
name|u32
name|pci_rstdrop_cpl
decl_stmt|;
comment|/* 0x01cc */
name|u32
name|pci_rstdrop_msg
decl_stmt|;
comment|/* 0x01d0 */
name|u32
name|pci_rstdrop_client1
decl_stmt|;
comment|/* 0x01d4 */
name|u32
name|pci_rstdrop_client0
decl_stmt|;
comment|/* 0x01d8 */
name|u32
name|pci_rstdrop_client2
decl_stmt|;
comment|/* 0x01dc */
name|u32
name|unused6
decl_stmt|;
comment|/* 0x01e0 */
struct|struct
block|{
comment|/* 0x0000 */
name|u16
name|unused7
decl_stmt|;
comment|/* 0x0002 */
name|u16
name|pci_depl_cplh
decl_stmt|;
comment|/* 0x0004 */
name|u16
name|pci_depl_nph
decl_stmt|;
comment|/* 0x0006 */
name|u16
name|pci_depl_ph
decl_stmt|;
block|}
name|pci_depl_h_vplane
index|[
literal|17
index|]
struct|;
comment|/* 0x0268 */
struct|struct
block|{
comment|/* 0x0000 */
name|u16
name|unused8
decl_stmt|;
comment|/* 0x0002 */
name|u16
name|pci_depl_cpld
decl_stmt|;
comment|/* 0x0004 */
name|u16
name|pci_depl_npd
decl_stmt|;
comment|/* 0x0006 */
name|u16
name|pci_depl_pd
decl_stmt|;
block|}
name|pci_depl_d_vplane
index|[
literal|17
index|]
struct|;
comment|/* 0x02f0 */
name|vxge_hal_xmac_port_stats_t
name|xgmac_port
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x0a10 */
name|vxge_hal_xmac_aggr_stats_t
name|xgmac_aggr
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x0ae0 */
name|u64
name|xgmac_global_prog_event_gnum0
decl_stmt|;
comment|/* 0x0ae8 */
name|u64
name|xgmac_global_prog_event_gnum1
decl_stmt|;
comment|/* 0x0af0 */
name|u64
name|unused9
decl_stmt|;
comment|/* 0x0af8 */
name|u64
name|xgmac_orp_lro_events
decl_stmt|;
comment|/* 0x0b00 */
name|u64
name|xgmac_orp_bs_events
decl_stmt|;
comment|/* 0x0b08 */
name|u64
name|xgmac_orp_iwarp_events
decl_stmt|;
comment|/* 0x0b10 */
name|u32
name|unused10
decl_stmt|;
comment|/* 0x0b14 */
name|u32
name|xgmac_tx_permitted_frms
decl_stmt|;
comment|/* 0x0b18 */
name|u32
name|unused11
decl_stmt|;
comment|/* 0x0b1c */
name|u8
name|unused12
decl_stmt|;
comment|/* 0x0b1d */
name|u8
name|xgmac_port2_tx_any_frms
decl_stmt|;
comment|/* 0x0b1e */
name|u8
name|xgmac_port1_tx_any_frms
decl_stmt|;
comment|/* 0x0b1f */
name|u8
name|xgmac_port0_tx_any_frms
decl_stmt|;
comment|/* 0x0b20 */
name|u32
name|unused13
decl_stmt|;
comment|/* 0x0b24 */
name|u8
name|unused14
decl_stmt|;
comment|/* 0x0b25 */
name|u8
name|xgmac_port2_rx_any_frms
decl_stmt|;
comment|/* 0x0b26 */
name|u8
name|xgmac_port1_rx_any_frms
decl_stmt|;
comment|/* 0x0b27 */
name|u8
name|xgmac_port0_rx_any_frms
decl_stmt|;
block|}
name|vxge_hal_mrpcim_stats_hw_info_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * struct vxge_hal_mrpcim_xpak_stats_t - HAL xpak stats  * @excess_temp: excess transceiver_temperature count  * @excess_bias_current: excess laser_bias_current count  * @excess_laser_output: excess laser_output_power count  * @alarm_transceiver_temp_high: alarm_transceiver_temp_high count value  * @alarm_transceiver_temp_low : alarm_transceiver_temp_low count value  * @alarm_laser_bias_current_high: alarm_laser_bias_current_high count value  * @alarm_laser_bias_current_low: alarm_laser_bias_current_low count value  * @alarm_laser_output_power_high: alarm_laser_output_power_high count value  * @alarm_laser_output_power_low: alarm_laser_output_power_low count value  * @warn_transceiver_temp_high: warn_transceiver_temp_high count value  * @warn_transceiver_temp_low: warn_transceiver_temp_low count value  * @warn_laser_bias_current_high: warn_laser_bias_current_high count value  * @warn_laser_bias_current_low: warn_laser_bias_current_low count value  * @warn_laser_output_power_high: warn_laser_output_power_high count value  * @warn_laser_output_power_low: warn_laser_output_power_low count value  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_mrpcim_xpak_stats_t
block|{
name|u32
name|excess_temp
decl_stmt|;
name|u32
name|excess_bias_current
decl_stmt|;
name|u32
name|excess_laser_output
decl_stmt|;
name|u16
name|alarm_transceiver_temp_high
decl_stmt|;
name|u16
name|alarm_transceiver_temp_low
decl_stmt|;
name|u16
name|alarm_laser_bias_current_high
decl_stmt|;
name|u16
name|alarm_laser_bias_current_low
decl_stmt|;
name|u16
name|alarm_laser_output_power_high
decl_stmt|;
name|u16
name|alarm_laser_output_power_low
decl_stmt|;
name|u16
name|warn_transceiver_temp_high
decl_stmt|;
name|u16
name|warn_transceiver_temp_low
decl_stmt|;
name|u16
name|warn_laser_bias_current_high
decl_stmt|;
name|u16
name|warn_laser_bias_current_low
decl_stmt|;
name|u16
name|warn_laser_output_power_high
decl_stmt|;
name|u16
name|warn_laser_output_power_low
decl_stmt|;
block|}
name|vxge_hal_mrpcim_xpak_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_device_stats_hw_info_t - X3100 hardware statistics.  * @vpath_info: VPath statistics  * @vpath_info_sav: Vpath statistics saved  *  * X3100 hardware statistics.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_device_stats_hw_info_t
block|{
name|vxge_hal_vpath_stats_hw_info_t
modifier|*
name|vpath_info
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
name|vxge_hal_vpath_stats_hw_info_t
name|vpath_info_sav
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
block|}
name|vxge_hal_device_stats_hw_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_common_info_t - HAL common stats for queues.  * @full_cnt: Number of times the queue was full  * @usage_cnt: usage count.  * @usage_max: Maximum usage  * @avg_compl_per_intr_cnt: Average number of completions per interrupt.  *	   Note that a total number of completed descriptors  *	   for the given channel can be calculated as  *	   (@traffic_intr_cnt * @avg_compl_per_intr_cnt).  * @total_compl_cnt: Total completion count.  *	    @total_compl_cnt == (@traffic_intr_cnt * @avg_compl_per_intr_cnt).  *  * HAL common counters for queues  * See also: vxge_hal_vpath_stats_sw_fifo_info_t {},  *	  vxge_hal_vpath_stats_sw_ring_info_t {},  *	  vxge_hal_vpath_stats_sw_dmq_info_t {},  *	  vxge_hal_vpath_stats_sw_umq_info_t {},  *	  vxge_hal_vpath_stats_sw_srq_info_t {},  *	  vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_common_info_t
block|{
name|u32
name|full_cnt
decl_stmt|;
name|u32
name|usage_cnt
decl_stmt|;
name|u32
name|usage_max
decl_stmt|;
name|u32
name|avg_compl_per_intr_cnt
decl_stmt|;
name|u32
name|total_compl_cnt
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_common_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_fifo_info_t - HAL fifo statistics  * @common_stats: Common counters for all queues  * @total_posts: Total number of postings on the queue.  * @total_buffers: Total number of buffers posted.  * @avg_buffers_per_post: Average number of buffers transferred in a single  *	post operation. Calculated as @total_buffers/@total_posts.  * @copied_buffers: Number of buffers copied  * @avg_buffer_size: Average buffer size transferred by a single post  *		operation. Calculated as a total number of transmitted octets  *		divided by @total_buffers.  * @avg_post_size: Average amount of data transferred by a single post.  *		Calculated as a total number of transmitted octets divided by  *		@total_posts.  * @total_frags: Total number of fragments  * @copied_frags: Number of fragments copied  * @total_posts_dang_dtrs: Total number of posts involving dangling descriptors.  * @total_posts_dang_frags: Total number of dangling fragments posted during  *		 post request containing multiple descriptors.  * @txd_t_code_err_cnt: Array of transmit transfer codes. The position  * (index) in this array reflects the transfer code type, for instance  * 0xA - "loss of link".  * Value txd_t_code_err_cnt[i] reflects the  * number of times the corresponding transfer code was encountered.  *  * HAL fifo counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_fifo_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
name|u32
name|total_posts
decl_stmt|;
name|u32
name|total_buffers
decl_stmt|;
name|u32
name|avg_buffers_per_post
decl_stmt|;
name|u32
name|copied_buffers
decl_stmt|;
name|u32
name|avg_buffer_size
decl_stmt|;
name|u32
name|avg_post_size
decl_stmt|;
name|u32
name|total_frags
decl_stmt|;
name|u32
name|copied_frags
decl_stmt|;
name|u32
name|total_posts_dang_dtrs
decl_stmt|;
name|u32
name|total_posts_dang_frags
decl_stmt|;
name|u32
name|txd_t_code_err_cnt
index|[
literal|16
index|]
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_fifo_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_ring_info_t - HAL ring statistics  * @common_stats: Common counters for all queues  * @rxd_t_code_err_cnt: Array of receive transfer codes. The position  *		(index) in this array reflects the transfer code type,  *		for instance  *		0x7 - for "invalid receive buffer size", or 0x8 - for ECC.  *		Value rxd_t_code_err_cnt[i] reflects the  *		number of times the corresponding transfer code was encountered.  * @lro_clubbed_frms_cnt: Total no of Aggregated packets  * @lro_sending_both: Number of times the aggregation of packets broken  * @lro_outof_sequence_pkts: Number of out of order packets  * @lro_flush_max_pkts: Number of times we reached upper packet limit for  *		aggregation per session  * @lro_sum_avg_pkts_aggregated: Total number of packets considered for  *		aggregation  * @lro_num_aggregations: Number of packets sent to the stack  * @lro_max_pkts_aggr: Max number of aggr packet  per ring  * @lro_avg_agr_pkts: Average Aggregate packet  *  * HAL ring counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_ring_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
name|u32
name|rxd_t_code_err_cnt
index|[
literal|16
index|]
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_ring_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_dmq_info_t - HAL dmq statistics  * @common_stats: Common counters for all queues  *  * HAL dmq counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_dmq_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_dmq_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_umq_info_t - HAL umq statistics  * @common_stats: Common counters for all queues  *  * HAL dmq counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_umq_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_umq_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_sq_info_t - HAL sq statistics  * @common_stats: Common counters for all queues  *  * HAL srq counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_sq_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_sq_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_srq_info_t - HAL srq statistics  * @common_stats: Common counters for all queues  *  * HAL srq counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_cqrq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_srq_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_srq_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_cqrq_info_t - HAL cqrq statistics  * @common_stats: Common counters for all queues  *  * HAL cqrq counters  * See also: vxge_hal_vpath_stats_sw_common_info_t {},  *	     vxge_hal_vpath_stats_sw_fifo_info_t {},  *	     vxge_hal_vpath_stats_sw_ring_info_t {},  *	     vxge_hal_vpath_stats_sw_dmq_info_t {},  *	     vxge_hal_vpath_stats_sw_umq_info_t {},  *	     vxge_hal_vpath_stats_sw_sq_info_t {},  *	     vxge_hal_vpath_stats_sw_srq_info_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_cqrq_info_t
block|{
name|vxge_hal_vpath_stats_sw_common_info_t
name|common_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_cqrq_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_sw_obj_count_t - Usage count of obj ids in virtual path  *  * @no_nces: Number of NCEs on Adapter in this VP  * @no_sqs: Number of SQs on Adapter in this VP  * @no_srqs: Number of SRQs on Adapter in this VP  * @no_cqrqs: Number of CQRQs on Adapter in this VP  * @no_sessions: Number of sessions on Adapter in this VP  *  * This structure contains fields to keep the usage count of objects in  * a virtual path  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_sw_obj_count_t
block|{
name|u32
name|no_nces
decl_stmt|;
name|u32
name|no_sqs
decl_stmt|;
name|u32
name|no_srqs
decl_stmt|;
name|u32
name|no_cqrqs
decl_stmt|;
name|u32
name|no_sessions
decl_stmt|;
block|}
name|vxge_hal_vpath_sw_obj_count_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_err_t - HAL vpath error statistics  * @unknown_alarms: Unknown Alarm count  * @network_sustained_fault: Network sustained fault count  * @network_sustained_ok: Network sustained ok count  * @kdfcctl_fifo0_overwrite: Fifo 0 overwrite count  * @kdfcctl_fifo0_poison: Fifo 0 poison count  * @kdfcctl_fifo0_dma_error: Fifo 0 dma error count  * @kdfcctl_fifo1_overwrite: Fifo 1 overwrite count  * @kdfcctl_fifo1_poison: Fifo 1 poison count  * @kdfcctl_fifo1_dma_error: Fifo 1 dma error count  * @kdfcctl_fifo2_overwrite: Fifo 2 overwrite count  * @kdfcctl_fifo2_poison: Fifo 2 overwrite count  * @kdfcctl_fifo2_dma_error: Fifo 2 dma error count  * @dblgen_fifo0_overflow: Dblgen Fifo 0 overflow count  * @dblgen_fifo1_overflow: Dblgen Fifo 1 overflow count  * @dblgen_fifo2_overflow: Dblgen Fifo 2 overflow count  * @statsb_pif_chain_error: Statsb pif chain error count  * @statsb_drop_timeout: Statsb drop timeout count  * @target_illegal_access: Target illegal access count  * @ini_serr_det: Serious error detected count  * @pci_config_status_err: PCI config status error count  * @pci_config_uncor_err: PCI config uncorrectable error count  * @pci_config_cor_err: PCI config correctable error count  * @mrpcim_to_vpath_alarms: MRPCIM to vpath alarm count  * @srpcim_to_vpath_alarms: SRPCIM to vpath alarm count  * @srpcim_msg_to_vpath: SRPCIM to vpath message count  * @prc_ring_bumps: Ring controller ring bumps count  * @prc_rxdcm_sc_err: Ring controller rxdsm sc error count  * @prc_rxdcm_sc_abort: Ring controller rxdsm sc abort count  * @prc_quanta_size_err: Ring controller quanta size count  *  * HAL vpath error statistics  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_err_t
block|{
name|u32
name|unknown_alarms
decl_stmt|;
name|u32
name|network_sustained_fault
decl_stmt|;
name|u32
name|network_sustained_ok
decl_stmt|;
name|u32
name|kdfcctl_fifo0_overwrite
decl_stmt|;
name|u32
name|kdfcctl_fifo0_poison
decl_stmt|;
name|u32
name|kdfcctl_fifo0_dma_error
decl_stmt|;
name|u32
name|kdfcctl_fifo1_overwrite
decl_stmt|;
name|u32
name|kdfcctl_fifo1_poison
decl_stmt|;
name|u32
name|kdfcctl_fifo1_dma_error
decl_stmt|;
name|u32
name|kdfcctl_fifo2_overwrite
decl_stmt|;
name|u32
name|kdfcctl_fifo2_poison
decl_stmt|;
name|u32
name|kdfcctl_fifo2_dma_error
decl_stmt|;
name|u32
name|dblgen_fifo0_overflow
decl_stmt|;
name|u32
name|dblgen_fifo1_overflow
decl_stmt|;
name|u32
name|dblgen_fifo2_overflow
decl_stmt|;
name|u32
name|statsb_pif_chain_error
decl_stmt|;
name|u32
name|statsb_drop_timeout
decl_stmt|;
name|u32
name|target_illegal_access
decl_stmt|;
name|u32
name|ini_serr_det
decl_stmt|;
name|u32
name|pci_config_status_err
decl_stmt|;
name|u32
name|pci_config_uncor_err
decl_stmt|;
name|u32
name|pci_config_cor_err
decl_stmt|;
name|u32
name|mrpcim_to_vpath_alarms
decl_stmt|;
name|u32
name|srpcim_to_vpath_alarms
decl_stmt|;
name|u32
name|srpcim_msg_to_vpath
decl_stmt|;
name|u32
name|prc_ring_bumps
decl_stmt|;
name|u32
name|prc_rxdcm_sc_err
decl_stmt|;
name|u32
name|prc_rxdcm_sc_abort
decl_stmt|;
name|u32
name|prc_quanta_size_err
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_err_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_vpath_stats_sw_info_t - HAL vpath sw statistics  * @soft_reset_cnt: Number of times soft reset is done on this vpath.  * @obj_counts: Statistics for the VP  * @error_stats: error counters for the vpath  * @ring_stats: counters for ring belonging to the vpath  * @fifo_stats: counters for fifo belonging to the vpath  * @dmq_stats: counters for dmq belonging to the vpath  * @umq_stats: counters for umq belonging to the vpath  *  * HAL vpath sw statistics  * See also: vxge_hal_device_info_t {}}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_stats_sw_info_t
block|{
name|u32
name|soft_reset_cnt
decl_stmt|;
name|vxge_hal_vpath_sw_obj_count_t
name|obj_counts
decl_stmt|;
name|vxge_hal_vpath_stats_sw_err_t
name|error_stats
decl_stmt|;
name|vxge_hal_vpath_stats_sw_ring_info_t
name|ring_stats
decl_stmt|;
name|vxge_hal_vpath_stats_sw_fifo_info_t
name|fifo_stats
decl_stmt|;
name|vxge_hal_vpath_stats_sw_dmq_info_t
name|dmq_stats
decl_stmt|;
name|vxge_hal_vpath_stats_sw_umq_info_t
name|umq_stats
decl_stmt|;
block|}
name|vxge_hal_vpath_stats_sw_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_device_stats_sw_info_t - HAL own per-device statistics.  *  * @soft_reset_cnt: Number of times soft reset is done on this device.  * @vpath_info: please see vxge_hal_vpath_stats_sw_info_t {}  * HAL per-device statistics.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_device_stats_sw_info_t
block|{
name|u32
name|soft_reset_cnt
decl_stmt|;
name|vxge_hal_vpath_stats_sw_info_t
name|vpath_info
index|[
name|VXGE_HAL_MAX_VIRTUAL_PATHS
index|]
decl_stmt|;
block|}
name|vxge_hal_device_stats_sw_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_device_stats_sw_err_t - HAL device error statistics.  * @mrpcim_alarms: Number of mrpcim alarms  * @srpcim_alarms: Number of srpcim alarms  * @vpath_alarms: Number of vpath alarms  *  * HAL Device error stats  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_device_stats_sw_err_t
block|{
name|u32
name|mrpcim_alarms
decl_stmt|;
name|u32
name|srpcim_alarms
decl_stmt|;
name|u32
name|vpath_alarms
decl_stmt|;
block|}
name|vxge_hal_device_stats_sw_err_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_hal_device_stats_t - Contains HAL per-device statistics,  * including hw.  * @devh: HAL device handle.  *  * @hw_dev_info_stats: X3100 statistics maintained by the hardware.  * @sw_dev_err_stats: HAL's "soft" device error statistics.  * @sw_dev_info_stats: HAL's "soft" device informational statistics, e.g. number  *			of completions per interrupt.  *  * @is_enabled: True, if device stats collection is enabled.  *  * Structure-container of HAL per-device statistics. Note that per-channel  * statistics are kept in separate structures under HAL's fifo and ring  * channels.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_device_stats_t
block|{
comment|/* handles */
name|vxge_hal_device_h
name|devh
decl_stmt|;
comment|/* HAL device hardware statistics */
name|vxge_hal_device_stats_hw_info_t
name|hw_dev_info_stats
decl_stmt|;
comment|/* HAL device "soft" stats */
name|vxge_hal_device_stats_sw_err_t
name|sw_dev_err_stats
decl_stmt|;
name|vxge_hal_device_stats_sw_info_t
name|sw_dev_info_stats
decl_stmt|;
comment|/* flags */
name|int
name|is_enabled
decl_stmt|;
block|}
name|vxge_hal_device_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * vxge_hal_vpath_hw_stats_enable - Enable vpath h/w statistics.  * @vpath_handle: Virtual Path handle.  *  * Enable the DMA vpath statistics. The function is to be called to re-enable  * the adapter to update stats into the host memory  *  * See also: vxge_hal_vpath_hw_stats_disable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_hw_stats_enable
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_hw_stats_disable - Disable vpath h/w statistics.  * @vpath_handle: Virtual Path handle.  *  * Enable the DMA vpath statistics. The function is to be called to disable  * the adapter to update stats into the host memory. This function is not  * needed to be called, normally.  *  * See also: vxge_hal_vpath_hw_stats_enable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_hw_stats_disable
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_hw_stats_get - Get the vpath hw statistics.  * @vpath_handle: Virtual Path handle.  * @hw_stats: Hardware stats  *  * Returns the vpath h/w stats.  *  * See also: vxge_hal_vpath_hw_stats_enable(), vxge_hal_vpath_hw_stats_disable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_hw_stats_get
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|vxge_hal_vpath_stats_hw_info_t
modifier|*
name|hw_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_sw_stats_get - Get the vpath sw statistics.  * @vpath_handle: Virtual Path handle.  * @sw_stats: Software stats  *  * Returns the vpath s/w stats.  *  * See also: vxge_hal_vpath_hw_stats_get()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_sw_stats_get
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|vxge_hal_vpath_stats_sw_info_t
modifier|*
name|sw_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_stats_access - Get the statistics from the given location  *			  and offset and perform an operation  * @vpath_handle: Virtual path handle.  * @operation: Operation to be performed  * @offset: Offset with in the location  * @stat: Pointer to a buffer to return the value  *  * Get the statistics from the given location and offset.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_stats_access
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|u32
name|operation
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_xmac_tx_stats_get - Get the TX Statistics of a vpath  * @virtual_path: vpath handle.  * @vpath_tx_stats: Buffer to return TX Statistics of vpath.  *  * Get the TX Statistics of a vpath  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_xmac_tx_stats_get
parameter_list|(
name|vxge_hal_vpath_h
name|virtual_path
parameter_list|,
name|vxge_hal_xmac_vpath_tx_stats_t
modifier|*
name|vpath_tx_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_xmac_rx_stats_get - Get the RX Statistics of a vpath  * @virtual_path: vpath handle.  * @vpath_rx_stats: Buffer to return RX Statistics of vpath.  *  * Get the RX Statistics of a vpath  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_xmac_rx_stats_get
parameter_list|(
name|vxge_hal_vpath_h
name|virtual_path
parameter_list|,
name|vxge_hal_xmac_vpath_rx_stats_t
modifier|*
name|vpath_rx_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_vpath_stats_clear - Clear all the statistics of vpath  * @vpath_handle: Virtual path handle.  *  * Clear the statistics of the given vpath.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_vpath_stats_clear
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_hw_stats_enable - Enable device h/w statistics.  * @devh: HAL Device.  *  * Enable the DMA vpath statistics for the device. The function is to be called  * to re-enable the adapter to update stats into the host memory  *  * See also: vxge_hal_device_hw_stats_disable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_hw_stats_enable
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_hw_stats_disable - Disable device h/w statistics.  * @devh: HAL Device.  *  * Enable the DMA vpath statistics for the device. The function is to be called  * to disable the adapter to update stats into the host memory. This function  * is not needed to be called, normally.  *  * See also: vxge_hal_device_hw_stats_enable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_hw_stats_disable
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_hw_stats_get - Get the device hw statistics.  * @devh: HAL Device.  * @hw_stats: Hardware stats  *  * Returns the vpath h/w stats for the device.  *  * See also: vxge_hal_device_hw_stats_enable(),  *	     vxge_hal_device_hw_stats_disable(),  *	     vxge_hal_device_sw_stats_get(),  *	     vxge_hal_device_stats_get()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_hw_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_device_stats_hw_info_t
modifier|*
name|hw_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_sw_stats_get - Get the device sw statistics.  * @devh: HAL Device.  * @sw_stats: Software stats  *  * Returns the device s/w stats for the device.  *  * See also: vxge_hal_device_hw_stats_get(), vxge_hal_device_stats_get()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_sw_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_device_stats_sw_info_t
modifier|*
name|sw_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_stats_get - Get the device statistics.  * @devh: HAL Device.  * @stats: Device stats  *  * Returns the device stats for the device.  *  * See also: vxge_hal_device_hw_stats_get(), vxge_hal_device_sw_stats_get()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_device_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_device_xmac_stats_get - Get the XMAC Statistics  * @devh: HAL device handle.  * @xmac_stats: Buffer to return XMAC Statistics.  *  * Get the XMAC Statistics  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_device_xmac_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_device_xmac_stats_t
modifier|*
name|xmac_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_stats_enable - Enable mrpcim statistics.  * @devh: HAL Device.  *  * Enable the DMA mrpcim statistics for the device. The function is to be called  * to re-enable the adapter to update stats into the host memory  *  * See also: vxge_hal_mrpcim_stats_disable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_stats_enable
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_stats_disable - Disable mrpcim statistics.  * @devh: HAL Device.  *  * Enable the DMA mrpcim statistics for the device. The function is to be called  * to disable the adapter to update stats into the host memory. This function  * is not needed to be called, normally.  *  * See also: vxge_hal_mrpcim_stats_enable()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_stats_disable
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_stats_get - Get the mrpcim statistics.  * @devh: HAL Device.  * @stats: mrpcim stats  *  * Returns the device mrpcim stats for the device.  *  * See also: vxge_hal_device_stats_get()  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mrpcim_stats_hw_info_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_stats_access - Access the statistics from the given location  *			  and offset and perform an operation  * @devh: HAL Device handle.  * @operation: Operation to be performed  * @location: Location (one of vpath id, aggregate or port)  * @offset: Offset with in the location  * @stat: Pointer to a buffer to return the value  *  * Get the statistics from the given location and offset.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_stats_access
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|operation
parameter_list|,
name|u32
name|location
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u64
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_xmac_aggr_stats_get - Get the Statistics on aggregate port  * @devh: HAL device handle.  * @port: Number of the port (0 or 1)  * @aggr_stats: Buffer to return Statistics on aggregate port.  *  * Get the Statistics on aggregate port  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_xmac_aggr_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|,
name|vxge_hal_xmac_aggr_stats_t
modifier|*
name|aggr_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_xmac_port_stats_get - Get the Statistics on a port  * @devh: HAL device handle.  * @port: Number of the port (wire 0, wire 1 or LAG)  * @port_stats: Buffer to return Statistics on a port.  *  * Get the Statistics on port  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_xmac_port_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|,
name|vxge_hal_xmac_port_stats_t
modifier|*
name|port_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_xmac_stats_get - Get the XMAC Statistics  * @devh: HAL device handle.  * @xmac_stats: Buffer to return XMAC Statistics.  *  * Get the XMAC Statistics  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_xmac_stats_get
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|vxge_hal_mrpcim_xmac_stats_t
modifier|*
name|xmac_stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_stats_clear - Clear the statistics of the device  * @devh: HAL Device handle.  *  * Clear the statistics of the given Device.  *  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_stats_clear
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_hal_mrpcim_xpak_stats_poll -  Poll and update the Xpak error count.  * @devh: HAL device handle  * @port: Port number  *  * It is used to update the xpak stats value. Called by ULD periodically  */
end_comment

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_mrpcim_xpak_stats_poll
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_STATS_H */
end_comment

end_unit

