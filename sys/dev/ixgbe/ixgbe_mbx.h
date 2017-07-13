begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_MBX_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_MBX_H_
end_define

begin_include
include|#
directive|include
file|"ixgbe_type.h"
end_include

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_SIZE
value|16
end_define

begin_comment
comment|/* 16 32 bit words - 64 bytes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ERR_MBX
value|-100
end_define

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX
value|0x002FC
end_define

begin_define
define|#
directive|define
name|IXGBE_VFMBMEM
value|0x00200
end_define

begin_comment
comment|/* Define mailbox register bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_REQ
value|0x00000001
end_define

begin_comment
comment|/* Request for PF Ready bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_ACK
value|0x00000002
end_define

begin_comment
comment|/* Ack PF message received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_VFU
value|0x00000004
end_define

begin_comment
comment|/* VF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_PFU
value|0x00000008
end_define

begin_comment
comment|/* PF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_PFSTS
value|0x00000010
end_define

begin_comment
comment|/* PF wrote a message in the MB */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_PFACK
value|0x00000020
end_define

begin_comment
comment|/* PF ack the previous VF msg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_RSTI
value|0x00000040
end_define

begin_comment
comment|/* PF has reset indication */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_RSTD
value|0x00000080
end_define

begin_comment
comment|/* PF has indicated reset done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFMAILBOX_R2C_BITS
value|0x000000B0
end_define

begin_comment
comment|/* All read to clear bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX_STS
value|0x00000001
end_define

begin_comment
comment|/* Initiate message send to VF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX_ACK
value|0x00000002
end_define

begin_comment
comment|/* Ack message recv'd from VF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX_VFU
value|0x00000004
end_define

begin_comment
comment|/* VF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX_PFU
value|0x00000008
end_define

begin_comment
comment|/* PF owns the mailbox buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX_RVFU
value|0x00000010
end_define

begin_comment
comment|/* Reset VFU - used when VF stuck */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MBVFICR_VFREQ_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* bits for VF messages */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MBVFICR_VFREQ_VF1
value|0x00000001
end_define

begin_comment
comment|/* bit for VF 1 message */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MBVFICR_VFACK_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* bits for VF acks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MBVFICR_VFACK_VF1
value|0x00010000
end_define

begin_comment
comment|/* bit for VF 1 ack */
end_comment

begin_comment
comment|/* If it's a IXGBE_VF_* msg then it originates in the VF and is sent to the  * PF.  The reverse is TRUE if it is IXGBE_PF_*.  * Message ACK's are the value or'd with 0xF0000000  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_MSGTYPE_ACK
value|0x80000000
end_define

begin_comment
comment|/* Messages below or'd with 					    * this are the ACK */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_MSGTYPE_NACK
value|0x40000000
end_define

begin_comment
comment|/* Messages below or'd with 					    * this are the NACK */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_MSGTYPE_CTS
value|0x20000000
end_define

begin_comment
comment|/* Indicates that VF is still 					    * clear to send requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_MSGINFO_SHIFT
value|16
end_define

begin_comment
comment|/* bits 23:16 are used for extra info for certain messages */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_MSGINFO_MASK
value|(0xFF<< IXGBE_VT_MSGINFO_SHIFT)
end_define

begin_comment
comment|/* definitions to support mailbox API version negotiation */
end_comment

begin_comment
comment|/*  * each element denotes a version of the API; existing numbers may not  * change; any additions must go at the end  */
end_comment

begin_enum
enum|enum
name|ixgbe_pfvf_api_rev
block|{
name|ixgbe_mbox_api_10
block|,
comment|/* API version 1.0, linux/freebsd VF driver */
name|ixgbe_mbox_api_20
block|,
comment|/* API version 2.0, solaris Phase1 VF driver */
name|ixgbe_mbox_api_11
block|,
comment|/* API version 1.1, linux/freebsd VF driver */
name|ixgbe_mbox_api_12
block|,
comment|/* API version 1.2, linux/freebsd VF driver */
name|ixgbe_mbox_api_13
block|,
comment|/* API version 1.3, linux/freebsd VF driver */
comment|/* This value should always be last */
name|ixgbe_mbox_api_unknown
block|,
comment|/* indicates that API version is not known */
block|}
enum|;
end_enum

begin_comment
comment|/* mailbox API, legacy requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_RESET
value|0x01
end_define

begin_comment
comment|/* VF requests reset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_MAC_ADDR
value|0x02
end_define

begin_comment
comment|/* VF requests PF to set MAC addr */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_MULTICAST
value|0x03
end_define

begin_comment
comment|/* VF requests PF to set MC addr */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_VLAN
value|0x04
end_define

begin_comment
comment|/* VF requests PF to set VLAN */
end_comment

begin_comment
comment|/* mailbox API, version 1.0 VF requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_LPE
value|0x05
end_define

begin_comment
comment|/* VF requests PF to set VMOLR.LPE */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_MACVLAN
value|0x06
end_define

begin_comment
comment|/* VF requests PF for unicast filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_API_NEGOTIATE
value|0x08
end_define

begin_comment
comment|/* negotiate API version */
end_comment

begin_comment
comment|/* mailbox API, version 1.1 VF requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_QUEUES
value|0x09
end_define

begin_comment
comment|/* get queue configuration */
end_comment

begin_comment
comment|/* mailbox API, version 1.2 VF requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_RETA
value|0x0a
end_define

begin_comment
comment|/* VF request for RETA */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_RSS_KEY
value|0x0b
end_define

begin_comment
comment|/* get RSS key */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_UPDATE_XCAST_MODE
value|0x0c
end_define

begin_comment
comment|/* mode choices for IXGBE_VF_UPDATE_XCAST_MODE */
end_comment

begin_enum
enum|enum
name|ixgbevf_xcast_modes
block|{
name|IXGBEVF_XCAST_MODE_NONE
init|=
literal|0
block|,
name|IXGBEVF_XCAST_MODE_MULTI
block|,
name|IXGBEVF_XCAST_MODE_ALLMULTI
block|,
name|IXGBEVF_XCAST_MODE_PROMISC
block|, }
enum|;
end_enum

begin_comment
comment|/* GET_QUEUES return data indices within the mailbox */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_TX_QUEUES
value|1
end_define

begin_comment
comment|/* number of Tx queues supported */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_RX_QUEUES
value|2
end_define

begin_comment
comment|/* number of Rx queues supported */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_TRANS_VLAN
value|3
end_define

begin_comment
comment|/* Indication of port vlan */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_DEF_QUEUE
value|4
end_define

begin_comment
comment|/* Default queue offset */
end_comment

begin_comment
comment|/* length of permanent address message returned from PF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_PERMADDR_MSG_LEN
value|4
end_define

begin_comment
comment|/* word in permanent address message with the current multicast type */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_MC_TYPE_WORD
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_PF_CONTROL_MSG
value|0x0100
end_define

begin_comment
comment|/* PF control message */
end_comment

begin_comment
comment|/* mailbox API, version 2.0 VF requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_API_NEGOTIATE
value|0x08
end_define

begin_comment
comment|/* negotiate API version */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_QUEUES
value|0x09
end_define

begin_comment
comment|/* get queue configuration */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_ENABLE_MACADDR
value|0x0A
end_define

begin_comment
comment|/* enable MAC address */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_DISABLE_MACADDR
value|0x0B
end_define

begin_comment
comment|/* disable MAC address */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_MACADDRS
value|0x0C
end_define

begin_comment
comment|/* get all configured MAC addrs */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_MCAST_PROMISC
value|0x0D
end_define

begin_comment
comment|/* enable multicast promiscuous */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_GET_MTU
value|0x0E
end_define

begin_comment
comment|/* get bounds on MTU */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_SET_MTU
value|0x0F
end_define

begin_comment
comment|/* set a specific MTU */
end_comment

begin_comment
comment|/* mailbox API, version 2.0 PF requests */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PF_TRANSPARENT_VLAN
value|0x0101
end_define

begin_comment
comment|/* enable transparent vlan */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_MBX_INIT_TIMEOUT
value|2000
end_define

begin_comment
comment|/* number of retries on mailbox */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VF_MBX_INIT_DELAY
value|500
end_define

begin_comment
comment|/* microseconds between retries */
end_comment

begin_function_decl
name|void
name|ixgbe_init_mbx_ops_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_init_mbx_params_vf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_init_mbx_params_pf
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_MBX_H_ */
end_comment

end_unit

