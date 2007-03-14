begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FIRMWARE_EXPORTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FIRMWARE_EXPORTS_H_
end_define

begin_comment
comment|/* WR OPCODES supported by the firmware.  */
end_comment

begin_define
define|#
directive|define
name|FW_WROPCODE_FORWARD
value|0x01
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_BYPASS
value|0x05
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_TUNNEL_TX_PKT
value|0x03
end_define

begin_define
define|#
directive|define
name|FW_WROPOCDE_ULPTX_DATA_SGL
value|0x00
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_ULPTX_MEM_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_ULPTX_PKT
value|0x04
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_ULPTX_INVALIDATE
value|0x06
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_TUNNEL_RX_PKT
value|0x07
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_GETTCB_RPL
value|0x08
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_CLOSE_CON
value|0x09
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_TP_ABORT_CON_REQ
value|0x0A
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_HOST_ABORT_CON_RPL
value|0x0F
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_HOST_ABORT_CON_REQ
value|0x0B
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_TP_ABORT_CON_RPL
value|0x0C
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_TX_DATA
value|0x0D
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_OFLD_TX_DATA_ACK
value|0x0E
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RDMA_INIT
value|0x10
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RDMA_WRITE
value|0x11
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RDMA_READ_REQ
value|0x12
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RDMA_READ_RESP
value|0x13
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_SEND
value|0x14
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_TERMINATE
value|0x15
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RDMA_READ
value|0x16
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_RECEIVE
value|0x17
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_BIND_MW
value|0x18
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_FASTREGISTER_MR
value|0x19
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_LOCAL_INV
value|0x1A
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_MODIFY_QP
value|0x1B
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_RI_BYPASS
value|0x1C
end_define

begin_define
define|#
directive|define
name|FW_WROPOCDE_RSVD
value|0x1E
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_SGE_EGRESSCONTEXT_RR
value|0x1F
end_define

begin_define
define|#
directive|define
name|FW_WROPCODE_MNGT
value|0x1D
end_define

begin_define
define|#
directive|define
name|FW_MNGTOPCODE_PKTSCHED_SET
value|0x00
end_define

begin_comment
comment|/* Maximum size of a WR sent from the host, limited by the SGE.   *  * Note: WR coming from ULP or TP are only limited by CIM.   */
end_comment

begin_define
define|#
directive|define
name|FW_WR_SIZE
value|128
end_define

begin_comment
comment|/* Maximum number of outstanding WRs sent from the host. Value must be  * programmed in the CTRL/TUNNEL/QP SGE Egress Context and used by   * offload modules to limit the number of WRs per connection.  */
end_comment

begin_define
define|#
directive|define
name|FW_T3_WR_NUM
value|16
end_define

begin_define
define|#
directive|define
name|FW_N3_WR_NUM
value|7
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|N3
end_ifndef

begin_define
define|#
directive|define
name|FW_WR_NUM
value|FW_T3_WR_NUM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FW_WR_NUM
value|FW_N3_WR_NUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FW_TUNNEL_NUM corresponds to the number of supported TUNNEL Queues. These  * queues must start at SGE Egress Context FW_TUNNEL_SGEEC_START and must  * start at 'TID' (or 'uP Token') FW_TUNNEL_TID_START.  *  * Ingress Traffic (e.g. DMA completion credit)  for TUNNEL Queue[i] is sent   * to RESP Queue[i].  */
end_comment

begin_define
define|#
directive|define
name|FW_TUNNEL_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FW_TUNNEL_SGEEC_START
value|8
end_define

begin_define
define|#
directive|define
name|FW_TUNNEL_TID_START
value|65544
end_define

begin_comment
comment|/* FW_CTRL_NUM corresponds to the number of supported CTRL Queues. These queues  * must start at SGE Egress Context FW_CTRL_SGEEC_START and must start at 'TID'  * (or 'uP Token') FW_CTRL_TID_START.  *  * Ingress Traffic for CTRL Queue[i] is sent to RESP Queue[i].  */
end_comment

begin_define
define|#
directive|define
name|FW_CTRL_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FW_CTRL_SGEEC_START
value|65528
end_define

begin_define
define|#
directive|define
name|FW_CTRL_TID_START
value|65536
end_define

begin_comment
comment|/* FW_OFLD_NUM corresponds to the number of supported OFFLOAD Queues. These   * queues must start at SGE Egress Context FW_OFLD_SGEEC_START.   *   * Note: the 'uP Token' in the SGE Egress Context fields is irrelevant for   * OFFLOAD Queues, as the host is responsible for providing the correct TID in  * every WR.  *  * Ingress Trafffic for OFFLOAD Queue[i] is sent to RESP Queue[i].  */
end_comment

begin_define
define|#
directive|define
name|FW_OFLD_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FW_OFLD_SGEEC_START
value|0
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|FW_RI_NUM
value|1
end_define

begin_define
define|#
directive|define
name|FW_RI_SGEEC_START
value|65527
end_define

begin_define
define|#
directive|define
name|FW_RI_TID_START
value|65552
end_define

begin_comment
comment|/*  * The RX_PKT_TID   */
end_comment

begin_define
define|#
directive|define
name|FW_RX_PKT_NUM
value|1
end_define

begin_define
define|#
directive|define
name|FW_RX_PKT_TID_START
value|65553
end_define

begin_comment
comment|/* FW_WRC_NUM corresponds to the number of Work Request Context that supported  * by the firmware.  */
end_comment

begin_define
define|#
directive|define
name|FW_WRC_NUM
define|\
value|(65536 + FW_TUNNEL_NUM + FW_CTRL_NUM + FW_RI_NUM + FW_RX_PKT_NUM)
end_define

begin_comment
comment|/*  * FW type and version.  */
end_comment

begin_define
define|#
directive|define
name|S_FW_VERSION_TYPE
value|28
end_define

begin_define
define|#
directive|define
name|M_FW_VERSION_TYPE
value|0xF
end_define

begin_define
define|#
directive|define
name|V_FW_VERSION_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VERSION_TYPE)
end_define

begin_define
define|#
directive|define
name|G_FW_VERSION_TYPE
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VERSION_TYPE)& M_FW_VERSION_TYPE)
end_define

begin_define
define|#
directive|define
name|S_FW_VERSION_MAJOR
value|16
end_define

begin_define
define|#
directive|define
name|M_FW_VERSION_MAJOR
value|0xFFF
end_define

begin_define
define|#
directive|define
name|V_FW_VERSION_MAJOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VERSION_MAJOR)
end_define

begin_define
define|#
directive|define
name|G_FW_VERSION_MAJOR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VERSION_MAJOR)& M_FW_VERSION_MAJOR)
end_define

begin_define
define|#
directive|define
name|S_FW_VERSION_MINOR
value|8
end_define

begin_define
define|#
directive|define
name|M_FW_VERSION_MINOR
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_FW_VERSION_MINOR
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|G_FW_VERSION_MINOR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VERSION_MINOR)& M_FW_VERSION_MINOR)
end_define

begin_define
define|#
directive|define
name|S_FW_VERSION_MICRO
value|0
end_define

begin_define
define|#
directive|define
name|M_FW_VERSION_MICRO
value|0xFF
end_define

begin_define
define|#
directive|define
name|V_FW_VERSION_MICRO
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_FW_VERSION_MICRO)
end_define

begin_define
define|#
directive|define
name|G_FW_VERSION_MICRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> S_FW_VERSION_MICRO)& M_FW_VERSION_MICRO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FIRMWARE_EXPORTS_H_ */
end_comment

end_unit

