begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCU_EVENT_CODES_HEADER__
end_ifndef

begin_define
define|#
directive|define
name|__SCU_EVENT_CODES_HEADER__
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the constants and macros for the SCU event codes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// __cplusplus
define|#
directive|define
name|SCU_EVENT_TYPE_CODE_SHIFT
value|24
define|#
directive|define
name|SCU_EVENT_TYPE_CODE_MASK
value|0x0F000000
define|#
directive|define
name|SCU_EVENT_SPECIFIC_CODE_SHIFT
value|18
define|#
directive|define
name|SCU_EVENT_SPECIFIC_CODE_MASK
value|0x00FC0000
define|#
directive|define
name|SCU_EVENT_CODE_MASK
define|\
value|(SCU_EVENT_TYPE_CODE_MASK | SCU_EVENT_SPECIFIC_CODE_MASK)
comment|/**  * This macro constructs an SCU event type from the type value.  */
define|#
directive|define
name|SCU_EVENT_TYPE
parameter_list|(
name|type
parameter_list|)
define|\
value|((U32)(type)<< SCU_EVENT_TYPE_CODE_SHIFT)
comment|/**  * This macro constructs an SCU event specifier from the code value.  */
define|#
directive|define
name|SCU_EVENT_SPECIFIC
parameter_list|(
name|code
parameter_list|)
define|\
value|((U32)(code)<< SCU_EVENT_SPECIFIC_CODE_SHIFT)
comment|/**  * This macro constructs a combines an SCU event type and SCU event specifier  * from the type and code values.  */
define|#
directive|define
name|SCU_EVENT_MESSAGE
parameter_list|(
name|type
parameter_list|,
name|code
parameter_list|)
define|\
value|((type) | SCU_EVENT_SPECIFIC(code))
comment|/**  * @name SCU_EVENT_TYPES  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_TYPE_SMU_COMMAND_ERROR
value|SCU_EVENT_TYPE(0x08)
define|#
directive|define
name|SCU_EVENT_TYPE_SMU_PCQ_ERROR
value|SCU_EVENT_TYPE(0x09)
define|#
directive|define
name|SCU_EVENT_TYPE_SMU_ERROR
value|SCU_EVENT_TYPE(0x00)
define|#
directive|define
name|SCU_EVENT_TYPE_TRANSPORT_ERROR
value|SCU_EVENT_TYPE(0x01)
define|#
directive|define
name|SCU_EVENT_TYPE_BROADCAST_CHANGE
value|SCU_EVENT_TYPE(0x02)
define|#
directive|define
name|SCU_EVENT_TYPE_OSSP_EVENT
value|SCU_EVENT_TYPE(0x03)
define|#
directive|define
name|SCU_EVENT_TYPE_FATAL_MEMORY_ERROR
value|SCU_EVENT_TYPE(0x0F)
define|#
directive|define
name|SCU_EVENT_TYPE_RNC_SUSPEND_TX
value|SCU_EVENT_TYPE(0x04)
define|#
directive|define
name|SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX
value|SCU_EVENT_TYPE(0x05)
define|#
directive|define
name|SCU_EVENT_TYPE_RNC_OPS_MISC
value|SCU_EVENT_TYPE(0x06)
define|#
directive|define
name|SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT
value|SCU_EVENT_TYPE(0x07)
define|#
directive|define
name|SCU_EVENT_TYPE_ERR_CNT_EVENT
value|SCU_EVENT_TYPE(0x0A)
comment|/*@}*/
comment|/**  * @name SCU_EVENT_SPECIFIERS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_SPECIFIER_DRIVER_SUSPEND
value|0x20
define|#
directive|define
name|SCU_EVENT_SPECIFIER_RNC_RELEASE
value|0x00
comment|/*@}*/
comment|/**  * @name SMU_COMMAND_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_INVALID_CONTEXT_COMMAND
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_COMMAND_ERROR, 0x00)
comment|/*@}*/
comment|/**  * @name SMU_PCQ_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_UNCORRECTABLE_PCQ_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_PCQ_ERROR, 0x00)
comment|/*@}*/
comment|/**  *  @name SMU_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_UNCORRECTABLE_REGISTER_WRITE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x02)
define|#
directive|define
name|SCU_EVENT_UNCORRECTABLE_REGISTER_READ
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x03)
define|#
directive|define
name|SCU_EVENT_PCIE_INTERFACE_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x04)
define|#
directive|define
name|SCU_EVENT_FUNCTION_LEVEL_RESET
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x05)
comment|/*@}*/
comment|/**  * @name TRANSPORT_LEVEL_ERRORS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_ACK_NAK_TIMEOUT_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_TRANSPORT_ERROR, 0x00)
comment|/*@}*/
comment|/**  * @name BROADCAST_CHANGE_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_BROADCAST_CHANGE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x01)
define|#
directive|define
name|SCU_EVENT_BROADCAST_RESERVED0
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x02)
define|#
directive|define
name|SCU_EVENT_BROADCAST_RESERVED1
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x03)
define|#
directive|define
name|SCU_EVENT_BROADCAST_SES
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x04)
define|#
directive|define
name|SCU_EVENT_BROADCAST_EXPANDER
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x05)
define|#
directive|define
name|SCU_EVENT_BROADCAST_AEN
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x06)
define|#
directive|define
name|SCU_EVENT_BROADCAST_RESERVED3
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x07)
define|#
directive|define
name|SCU_EVENT_BROADCAST_RESERVED4
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x08)
define|#
directive|define
name|SCU_EVENT_PE_SUSPENDED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x09)
comment|/*@}*/
comment|/**  * @name OSSP_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_PORT_SELECTOR_DETECTED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x10)
define|#
directive|define
name|SCU_EVENT_SENT_PORT_SELECTION
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x11)
define|#
directive|define
name|SCU_EVENT_HARD_RESET_TRANSMITTED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x12)
define|#
directive|define
name|SCU_EVENT_HARD_RESET_RECEIVED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x13)
define|#
directive|define
name|SCU_EVENT_RECEIVED_IDENTIFY_TIMEOUT
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x15)
define|#
directive|define
name|SCU_EVENT_LINK_FAILURE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x16)
define|#
directive|define
name|SCU_EVENT_SATA_SPINUP_HOLD
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x17)
define|#
directive|define
name|SCU_EVENT_SAS_15_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x18)
define|#
directive|define
name|SCU_EVENT_SAS_15
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x19)
define|#
directive|define
name|SCU_EVENT_SAS_30_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1A)
define|#
directive|define
name|SCU_EVENT_SAS_30
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1B)
define|#
directive|define
name|SCU_EVENT_SAS_60_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1C)
define|#
directive|define
name|SCU_EVENT_SAS_60
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1D)
define|#
directive|define
name|SCU_EVENT_SATA_15_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1E)
define|#
directive|define
name|SCU_EVENT_SATA_15
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1F)
define|#
directive|define
name|SCU_EVENT_SATA_30_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x20)
define|#
directive|define
name|SCU_EVENT_SATA_30
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x21)
define|#
directive|define
name|SCU_EVENT_SATA_60_SSC
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x22)
define|#
directive|define
name|SCU_EVENT_SATA_60
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x23)
define|#
directive|define
name|SCU_EVENT_SAS_PHY_DETECTED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x24)
define|#
directive|define
name|SCU_EVENT_SATA_PHY_DETECTED
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x25)
comment|/*@}*/
comment|/**  * @name FATAL_INTERNAL_MEMORY_ERROR_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_TSC_RNSC_UNCORRECTABLE_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x00)
define|#
directive|define
name|SCU_EVENT_TC_RNC_UNCORRECTABLE_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x01)
define|#
directive|define
name|SCU_EVENT_ZPT_UNCORRECTABLE_ERROR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x02)
comment|/*@}*/
comment|/**  * @name REMOTE_NODE_SUSPEND_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x00)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_RX
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x00)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_DATA_LEN_ERR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x1A)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_OFFSET_ERR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x20)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_DMASETUP_DIERR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x27)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_XFERCNT_ERR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x28)
define|#
directive|define
name|SCU_EVENT_TL_RNC_SUSPEND_TX_RX_DONE_PLD_LEN_ERR
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x21)
define|#
directive|define
name|SCU_EVENT_DRIVER_POST_RNC_SUSPEND_TX
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x20)
define|#
directive|define
name|SCU_EVENT_DRIVER_POST_RNC_SUSPEND_TX_RX
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x20)
comment|/*@}*/
comment|/**  * @name REMOTE_NODE_MISC_EVENTS  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_POST_RCN_RELEASE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC,SCU_EVENT_SPECIFIER_RNC_RELEASE)
define|#
directive|define
name|SCU_EVENT_POST_IT_NEXUS_LOSS_TIMER_ENABLE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x01)
define|#
directive|define
name|SCU_EVENT_POST_IT_NEXUS_LOSS_TIMER_DISABLE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x02)
define|#
directive|define
name|SCU_EVENT_POST_RNC_COMPLETE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x03)
define|#
directive|define
name|SCU_EVENT_POST_RNC_INVALIDATE_COMPLETE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x04)
comment|/*@}*/
comment|/**  * @name ERROR_COUNT_EVENT  */
comment|/*@{*/
define|#
directive|define
name|SCU_ERR_CNT_RX_CREDIT_BLOCKED_RECEIVED_INDEX
value|0x00
define|#
directive|define
name|SCU_ERR_CNT_TX_DONE_CREDIT_TIMEOUT_INDEX
value|0x01
define|#
directive|define
name|SCU_ERR_CNT_RX_DONE_CREDIT_TIMEOUT_INDEX
value|0x02
define|#
directive|define
name|SCU_ERR_CNT_INACTIVITY_TIMER_EXPIRED_INDEX
value|0x03
define|#
directive|define
name|SCU_ERR_CNT_TX_DONE_ACK_NAK_TIMEOUT_INDEX
value|0x04
define|#
directive|define
name|SCU_ERR_CNT_RX_DONE_ACK_NAK_TIMEOUT_INDEX
value|0x05
define|#
directive|define
name|SCU_ERR_CNT_MAX_INDEX
value|0x06
define|#
directive|define
name|SCU_EVENT_ERR_CNT
parameter_list|(
name|name
parameter_list|)
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_ERR_CNT_EVENT, SCU_ERR_CNT_ ## name ## _INDEX)
comment|/*@}*/
comment|/**  * This macro returns the SCU event type from the event code.  */
define|#
directive|define
name|scu_get_event_type
parameter_list|(
name|event_code
parameter_list|)
define|\
value|((event_code)& SCU_EVENT_TYPE_CODE_MASK)
comment|/**  * This macro returns the SCU event specifier from the event code.  */
define|#
directive|define
name|scu_get_event_specifier
parameter_list|(
name|event_code
parameter_list|)
define|\
value|((event_code)& SCU_EVENT_SPECIFIC_CODE_MASK)
comment|/**  * This macro returns the combined SCU event type and SCU event specifier from  * the event code.  */
define|#
directive|define
name|scu_get_event_code
parameter_list|(
name|event_code
parameter_list|)
define|\
value|((event_code)& SCU_EVENT_CODE_MASK)
comment|/**  * @name PTS_SCHEDULE_EVENT  */
comment|/*@{*/
define|#
directive|define
name|SCU_EVENT_SMP_RESPONSE_NO_PE
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x00)
define|#
directive|define
name|SCU_EVENT_SPECIFIC_SMP_RESPONSE_NO_PE
define|\
value|scu_get_event_specifier(SCU_EVENT_SMP_RESPONSE_NO_PE)
define|#
directive|define
name|SCU_EVENT_TASK_TIMEOUT
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x01)
define|#
directive|define
name|SCU_EVENT_SPECIFIC_TASK_TIMEOUT
define|\
value|scu_get_event_specifier(SCU_EVENT_TASK_TIMEOUT)
define|#
directive|define
name|SCU_EVENT_IT_NEXUS_TIMEOUT
define|\
value|SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x02)
define|#
directive|define
name|SCU_EVENT_SPECIFIC_IT_NEXUS_TIMEOUT
define|\
value|scu_get_event_specifier(SCU_EVENT_IT_NEXUS_TIMEOUT)
comment|/*@}*/
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __SCU_EVENT_CODES_HEADER__
end_comment

end_unit

