begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_MBX_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_MBX_H_
end_define

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_comment
comment|/* Define mailbox register bits */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_REQ
value|0x00000001
end_define

begin_comment
comment|/* Request for PF Ready bit */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_ACK
value|0x00000002
end_define

begin_comment
comment|/* Ack PF message received */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_VFU
value|0x00000004
end_define

begin_comment
comment|/* VF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_PFU
value|0x00000008
end_define

begin_comment
comment|/* PF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_PFSTS
value|0x00000010
end_define

begin_comment
comment|/* PF wrote a message in the MB */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_PFACK
value|0x00000020
end_define

begin_comment
comment|/* PF ack the previous VF msg */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_RSTI
value|0x00000040
end_define

begin_comment
comment|/* PF has reset indication */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_RSTD
value|0x00000080
end_define

begin_comment
comment|/* PF has indicated reset done */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX_R2C_BITS
value|0x000000B0
end_define

begin_comment
comment|/* All read to clear bits */
end_comment

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX_STS
value|0x00000001
end_define

begin_comment
comment|/* Initiate message send to VF */
end_comment

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX_ACK
value|0x00000002
end_define

begin_comment
comment|/* Ack message recv'd from VF */
end_comment

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX_VFU
value|0x00000004
end_define

begin_comment
comment|/* VF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX_PFU
value|0x00000008
end_define

begin_comment
comment|/* PF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX_RVFU
value|0x00000010
end_define

begin_comment
comment|/* Reset VFU - used when VF stuck */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFICR_VFREQ_MASK
value|0x000000FF
end_define

begin_comment
comment|/* bits for VF messages */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFICR_VFREQ_VF1
value|0x00000001
end_define

begin_comment
comment|/* bit for VF 1 message */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFICR_VFACK_MASK
value|0x00FF0000
end_define

begin_comment
comment|/* bits for VF acks */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFICR_VFACK_VF1
value|0x00010000
end_define

begin_comment
comment|/* bit for VF 1 ack */
end_comment

begin_define
define|#
directive|define
name|E1000_VFMAILBOX_SIZE
value|16
end_define

begin_comment
comment|/* 16 32 bit words - 64 bytes */
end_comment

begin_comment
comment|/* If it's a E1000_VF_* msg then it originates in the VF and is sent to the  * PF.  The reverse is TRUE if it is E1000_PF_*.  * Message ACK's are the value or'd with 0xF0000000  */
end_comment

begin_comment
comment|/* Msgs below or'd with this are the ACK */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_MSGTYPE_ACK
value|0x80000000
end_define

begin_comment
comment|/* Msgs below or'd with this are the NACK */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_MSGTYPE_NACK
value|0x40000000
end_define

begin_comment
comment|/* Indicates that VF is still clear to send requests */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_MSGTYPE_CTS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_VT_MSGINFO_SHIFT
value|16
end_define

begin_comment
comment|/* bits 23:16 are used for extra info for certain messages */
end_comment

begin_define
define|#
directive|define
name|E1000_VT_MSGINFO_MASK
value|(0xFF<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VF_RESET
value|0x01
end_define

begin_comment
comment|/* VF requests reset */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_MAC_ADDR
value|0x02
end_define

begin_comment
comment|/* VF requests to set MAC addr */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_MULTICAST
value|0x03
end_define

begin_comment
comment|/* VF requests to set MC addr */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_MULTICAST_COUNT_MASK
value|(0x1F<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VF_SET_MULTICAST_OVERFLOW
value|(0x80<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VF_SET_VLAN
value|0x04
end_define

begin_comment
comment|/* VF requests to set VLAN */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_VLAN_ADD
value|(0x01<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VF_SET_LPE
value|0x05
end_define

begin_comment
comment|/* reqs to set VMOLR.LPE */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_PROMISC
value|0x06
end_define

begin_comment
comment|/* reqs to clear VMOLR.ROPE/MPME*/
end_comment

begin_define
define|#
directive|define
name|E1000_VF_SET_PROMISC_UNICAST
value|(0x01<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_VF_SET_PROMISC_MULTICAST
value|(0x02<< E1000_VT_MSGINFO_SHIFT)
end_define

begin_define
define|#
directive|define
name|E1000_PF_CONTROL_MSG
value|0x0100
end_define

begin_comment
comment|/* PF control message */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_MBX_INIT_TIMEOUT
value|2000
end_define

begin_comment
comment|/* number of retries on mailbox */
end_comment

begin_define
define|#
directive|define
name|E1000_VF_MBX_INIT_DELAY
value|500
end_define

begin_comment
comment|/* microseconds between retries */
end_comment

begin_function_decl
name|s32
name|e1000_read_mbx
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_mbx
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_posted_mbx
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_posted_mbx
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_check_for_msg
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_check_for_ack
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_check_for_rst
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_init_mbx_ops_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_init_mbx_params_vf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_init_mbx_params_pf
parameter_list|(
name|struct
name|e1000_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E1000_MBX_H_ */
end_comment

end_unit

