begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCU_TASK_CONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCU_TASK_CONTEXT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the structures and constants for the SCU hardware  *        task context.  */
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
include|#
directive|include
file|<dev/isci/scil/sci_types.h>
comment|/**  * @enum SCU_SSP_TASK_TYPE  *  * @brief This enumberation defines the various SSP task types the SCU  *        hardware will accept.  *  * The definition for the various task types the SCU hardware will accept can  * be found in the DS specification.  */
typedef|typedef
enum|enum
block|{
name|SCU_TASK_TYPE_IOREAD
block|,
comment|///< IO READ direction or no direction
name|SCU_TASK_TYPE_IOWRITE
block|,
comment|///< IO Write direction
name|SCU_TASK_TYPE_SMP_REQUEST
block|,
comment|///< SMP Request type
name|SCU_TASK_TYPE_RESPONSE
block|,
comment|///< Driver generated response frame (targt mode)
name|SCU_TASK_TYPE_RAW_FRAME
block|,
comment|///< Raw frame request type
name|SCU_TASK_TYPE_PRIMITIVE
comment|///< Request for a primitive to be transmitted
block|}
name|SCU_SSP_TASK_TYPE
typedef|;
comment|/**  * @enum SCU_SATA_TASK_TYPE  *  * @brief This enumeration defines the various SATA task types the SCU  *        hardware will accept.  *  * The definition for the various task types the SCU hardware will accept can  * be found in the DS specification.  */
typedef|typedef
enum|enum
block|{
name|SCU_TASK_TYPE_DMA_IN
block|,
comment|///< Read request
name|SCU_TASK_TYPE_FPDMAQ_READ
block|,
comment|///< NCQ read request
name|SCU_TASK_TYPE_PACKET_DMA_IN
block|,
comment|///< Packet read request
name|SCU_TASK_TYPE_SATA_RAW_FRAME
block|,
comment|///< Raw frame request
name|RESERVED_4
block|,
name|RESERVED_5
block|,
name|RESERVED_6
block|,
name|RESERVED_7
block|,
name|SCU_TASK_TYPE_DMA_OUT
block|,
comment|///< Write request
name|SCU_TASK_TYPE_FPDMAQ_WRITE
block|,
comment|///< NCQ write Request
name|SCU_TASK_TYPE_PACKET_DMA_OUT
comment|///< Packet write request
block|}
name|SCU_SATA_TASK_TYPE
typedef|;
comment|/**  * @name SCU_CONTEXT_TYPE  */
comment|/*@{*/
define|#
directive|define
name|SCU_TASK_CONTEXT_TYPE
value|0
define|#
directive|define
name|SCU_RNC_CONTEXT_TYPE
value|1
comment|/*@}*/
comment|/**  * @name SCU_TASK_CONTEXT_VALIDITY  */
comment|/*@{*/
define|#
directive|define
name|SCU_TASK_CONTEXT_INVALID
value|0
define|#
directive|define
name|SCU_TASK_CONTEXT_VALID
value|1
comment|/*@}*/
comment|/**  * @name SCU_COMMAND_CODE  */
comment|/*@{*/
define|#
directive|define
name|SCU_COMMAND_CODE_INITIATOR_NEW_TASK
value|0
define|#
directive|define
name|SCU_COMMAND_CODE_ACTIVE_TASK
value|1
define|#
directive|define
name|SCU_COMMAND_CODE_PRIMITIVE_SEQ_TASK
value|2
define|#
directive|define
name|SCU_COMMAND_CODE_TARGET_RAW_FRAMES
value|3
comment|/*@}*/
comment|/**  * @name SCU_TASK_PRIORITY  */
comment|/*@{*/
comment|/**  * This priority is used when there is no priority request for this request.  */
define|#
directive|define
name|SCU_TASK_PRIORITY_NORMAL
value|0
comment|/**  * This priority indicates that the task should be scheduled to the head  * of the queue.  The task will NOT be executed if the TX is suspended for  * the remote node.  */
define|#
directive|define
name|SCU_TASK_PRIORITY_HEAD_OF_Q
value|1
comment|/**  * This priority indicates that the task will be executed before all  * SCU_TASK_PRIORITY_NORMAL and SCU_TASK_PRIORITY_HEAD_OF_Q tasks.  * The task WILL be executed if the TX is suspended for the remote node.  */
define|#
directive|define
name|SCU_TASK_PRIORITY_HIGH
value|2
comment|/**  * This task priority is reserved and should not be used.  */
define|#
directive|define
name|SCU_TASK_PRIORITY_RESERVED
value|3
comment|/*@}*/
define|#
directive|define
name|SCU_TASK_INITIATOR_MODE
value|1
define|#
directive|define
name|SCU_TASK_TARGET_MODE
value|0
define|#
directive|define
name|SCU_TASK_REGULAR
value|0
define|#
directive|define
name|SCU_TASK_ABORTED
value|1
comment|//direction bit defintion
comment|/**  * @name SATA_DIRECTION  */
comment|/*@{*/
define|#
directive|define
name|SCU_SATA_WRITE_DATA_DIRECTION
value|0
define|#
directive|define
name|SCU_SATA_READ_DATA_DIRECTION
value|1
comment|/*@}*/
comment|/**  * @name SCU_COMMAND_CONTEXT_MACROS  *  * These macros provide the mask and shift operations to construct the various  * SCU commands  */
comment|/*@{*/
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_SHIFT
value|21UL
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_MASK
value|0x00E00000UL
define|#
directive|define
name|scu_get_command_request_type
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& SCU_CONTEXT_COMMAND_REQUEST_TYPE_MASK)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_SUBTYPE_SHIFT
value|18UL
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_SUBTYPE_MASK
value|0x001C0000UL
define|#
directive|define
name|scu_get_command_request_subtype
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& SCU_CONTEXT_COMMAND_REQUEST_SUBTYPE_MASK)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_FULLTYPE_MASK
define|\
value|(                                                     \        SCU_CONTEXT_COMMAND_REQUEST_TYPE_MASK             \      | SCU_CONTEXT_COMMAND_REQUEST_SUBTYPE_MASK          \    )
define|#
directive|define
name|scu_get_command_request_full_type
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& SCU_CONTEXT_COMMAND_REQUEST_FULLTYPE_MASK)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_PROTOCOL_ENGINE_GROUP_SHIFT
value|16UL
define|#
directive|define
name|SCU_CONTEXT_COMMAND_PROTOCOL_ENGINE_GROUP_MASK
value|0x00010000UL
define|#
directive|define
name|scu_get_command_protocl_engine_group
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& SCU_CONTEXT_COMMAND_PROTOCOL_ENGINE_GROUP_MASK)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_LOGICAL_PORT_SHIFT
value|12UL
define|#
directive|define
name|SCU_CONTEXT_COMMAND_LOGICAL_PORT_MASK
value|0x00007000UL
define|#
directive|define
name|scu_get_command_reqeust_logical_port
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& SCU_CONTEXT_COMMAND_LOGICAL_PORT_MASK)
define|#
directive|define
name|MAKE_SCU_CONTEXT_COMMAND_TYPE
parameter_list|(
name|type
parameter_list|)
define|\
value|((U32)(type)<< SCU_CONTEXT_COMMAND_REQUEST_TYPE_SHIFT)
comment|/*@}*/
comment|/**  * @name SCU_COMMAND_TYPES  *  * These constants provide the grouping of the different SCU command types.  */
comment|/*@{*/
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_TC
value|MAKE_SCU_CONTEXT_COMMAND_TYPE(0UL)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_TC
value|MAKE_SCU_CONTEXT_COMMAND_TYPE(1UL)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_RNC
value|MAKE_SCU_CONTEXT_COMMAND_TYPE(2UL)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_RNC
value|MAKE_SCU_CONTEXT_COMMAND_TYPE(3UL)
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC
value|MAKE_SCU_CONTEXT_COMMAND_TYPE(6UL)
comment|/*@}*/
define|#
directive|define
name|MAKE_SCU_CONTEXT_COMMAND_REQUEST
parameter_list|(
name|type
parameter_list|,
name|command
parameter_list|)
define|\
value|((type) | (((U32)(command))<< SCU_CONTEXT_COMMAND_REQUEST_SUBTYPE_SHIFT))
comment|/**  * @name SCU_REQUEST_TYPES  *  * These constants are the various request types that can be posted to the SCU  * hardware.  */
comment|/*@{*/
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUST_POST_TC
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_TC, 0))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUEST_POST_TC_ABORT
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_TC, 1))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_REQUST_DUMP_TC
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_TC, 0))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_32
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_RNC, 0))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_96
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_RNC, 1))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_INVALIDATE
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_POST_RNC, 2))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_DUMP_RNC_32
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_RNC, 0))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_DUMP_RNC_96
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_DUMP_RNC, 1))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_SUSPEND_TX
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC, 0))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_SUSPEND_TX_RX
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC, 1))
define|#
directive|define
name|SCU_CONTEXT_COMMAND_POST_RNC_RESUME
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC, 2))
define|#
directive|define
name|SCU_CONTEXT_IT_NEXUS_LOSS_TIMER_ENABLE
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC, 3))
define|#
directive|define
name|SCU_CONTEXT_IT_NEXUS_LOSS_TIMER_DISABLE
define|\
value|(MAKE_SCU_CONTEXT_COMMAND_REQUEST(SCU_CONTEXT_COMMAND_REQUEST_TYPE_OTHER_RNC, 4))
comment|/*@}*/
comment|/**  * @name SCU_TASK_CONTEXT_PROTOCOL  * SCU Task context protocol types this is uesd to program the SCU Task  * context protocol field in word 0x00.  */
comment|/*@{*/
define|#
directive|define
name|SCU_TASK_CONTEXT_PROTOCOL_SMP
value|0x00
define|#
directive|define
name|SCU_TASK_CONTEXT_PROTOCOL_SSP
value|0x01
define|#
directive|define
name|SCU_TASK_CONTEXT_PROTOCOL_STP
value|0x02
define|#
directive|define
name|SCU_TASK_CONTEXT_PROTOCOL_NONE
value|0x07
comment|/*@}*/
comment|/**  * @struct SSP_TASK_CONTEXT  *  * @brief This is the SCU hardware definition for an SSP request.  */
struct|struct
name|SSP_TASK_CONTEXT
block|{
comment|// OFFSET 0x18
name|U32
name|reserved00
range|:
literal|24
decl_stmt|;
name|U32
name|frame_type
range|:
literal|8
decl_stmt|;
comment|// OFFSET 0x1C
name|U32
name|reserved01
decl_stmt|;
comment|// OFFSET 0x20
name|U32
name|fill_bytes
range|:
literal|2
decl_stmt|;
name|U32
name|reserved02
range|:
literal|6
decl_stmt|;
name|U32
name|changing_data_pointer
range|:
literal|1
decl_stmt|;
name|U32
name|retransmit
range|:
literal|1
decl_stmt|;
name|U32
name|retry_data_frame
range|:
literal|1
decl_stmt|;
name|U32
name|tlr_control
range|:
literal|2
decl_stmt|;
name|U32
name|reserved03
range|:
literal|19
decl_stmt|;
comment|// OFFSET 0x24
name|U32
name|uiRsvd4
decl_stmt|;
comment|// OFFSET 0x28
name|U32
name|target_port_transfer_tag
range|:
literal|16
decl_stmt|;
name|U32
name|tag
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0x2C
name|U32
name|data_offset
decl_stmt|;
block|}
struct|;
comment|/**  * @struct STP_TASK_CONTEXT  *  * @brief This is the SCU hardware definition for an STP request.  */
struct|struct
name|STP_TASK_CONTEXT
block|{
comment|// OFFSET 0x18
name|U32
name|fis_type
range|:
literal|8
decl_stmt|;
name|U32
name|pm_port
range|:
literal|4
decl_stmt|;
name|U32
name|reserved0
range|:
literal|3
decl_stmt|;
name|U32
name|control
range|:
literal|1
decl_stmt|;
name|U32
name|command
range|:
literal|8
decl_stmt|;
name|U32
name|features
range|:
literal|8
decl_stmt|;
comment|// OFFSET 0x1C
name|U32
name|reserved1
decl_stmt|;
comment|// OFFSET 0x20
name|U32
name|reserved2
decl_stmt|;
comment|// OFFSET 0x24
name|U32
name|reserved3
decl_stmt|;
comment|// OFFSET 0x28
name|U32
name|ncq_tag
range|:
literal|5
decl_stmt|;
name|U32
name|reserved4
range|:
literal|27
decl_stmt|;
comment|// OFFSET 0x2C
name|U32
name|data_offset
decl_stmt|;
comment|// TODO: What is this used for?
block|}
struct|;
comment|/**  * @struct SMP_TASK_CONTEXT  *  * @brief This is the SCU hardware definition for an SMP request.  */
struct|struct
name|SMP_TASK_CONTEXT
block|{
comment|// OFFSET 0x18
name|U32
name|response_length
range|:
literal|8
decl_stmt|;
name|U32
name|function_result
range|:
literal|8
decl_stmt|;
name|U32
name|function
range|:
literal|8
decl_stmt|;
name|U32
name|frame_type
range|:
literal|8
decl_stmt|;
comment|// OFFSET 0x1C
name|U32
name|smp_response_ufi
range|:
literal|12
decl_stmt|;
name|U32
name|reserved1
range|:
literal|20
decl_stmt|;
comment|// OFFSET 0x20
name|U32
name|reserved2
decl_stmt|;
comment|// OFFSET 0x24
name|U32
name|reserved3
decl_stmt|;
comment|// OFFSET 0x28
name|U32
name|reserved4
decl_stmt|;
comment|// OFFSET 0x2C
name|U32
name|reserved5
decl_stmt|;
block|}
struct|;
comment|/**  * @struct PRIMITIVE_TASK_CONTEXT  *  * @brief This is the SCU hardware definition used when the driver wants to  *        send a primitive on the link.  */
struct|struct
name|PRIMITIVE_TASK_CONTEXT
block|{
comment|// OFFSET 0x18
comment|/**     * This field is the control word and it must be 0.     */
name|U32
name|control
decl_stmt|;
comment|///< must be set to 0
comment|// OFFSET 0x1C
comment|/**     * This field specifies the primitive that is to be transmitted.     */
name|U32
name|sequence
decl_stmt|;
comment|// OFFSET 0x20
name|U32
name|reserved0
decl_stmt|;
comment|// OFFSET 0x24
name|U32
name|reserved1
decl_stmt|;
comment|// OFFSET 0x28
name|U32
name|reserved2
decl_stmt|;
comment|// OFFSET 0x2C
name|U32
name|reserved3
decl_stmt|;
block|}
struct|;
comment|/**  * @union PROTOCOL_CONTEXT  *  * @brief The union of the protocols that can be selected in the SCU task  *        context field.  */
union|union
name|PROTOCOL_CONTEXT
block|{
name|struct
name|SSP_TASK_CONTEXT
name|ssp
decl_stmt|;
name|struct
name|STP_TASK_CONTEXT
name|stp
decl_stmt|;
name|struct
name|SMP_TASK_CONTEXT
name|smp
decl_stmt|;
name|struct
name|PRIMITIVE_TASK_CONTEXT
name|primitive
decl_stmt|;
name|U32
name|words
index|[
literal|6
index|]
decl_stmt|;
block|}
union|;
comment|/**  * @struct SCU_SGL_ELEMENT  * @typedef SCU_SGL_ELEMENT_T  *  * @brief This structure represents a single SCU defined SGL element.  *  * SCU SGLs contain a 64 bit address with the maximum data transfer being 24  * bits in size.  The SGL can not cross a 4GB boundary.  */
typedef|typedef
struct|struct
name|SCU_SGL_ELEMENT
block|{
comment|/**     * This field is the upper 32 bits of the 64 bit physical address.     */
name|U32
name|address_upper
decl_stmt|;
comment|/**     * This field is the lower 32 bits of the 64 bit physical address.     */
name|U32
name|address_lower
decl_stmt|;
comment|/**     * This field is the number of bytes to transfer.     */
name|U32
name|length
range|:
literal|24
decl_stmt|;
comment|/**     * This field is the address modifier to be used when a virtual function is     * requesting a data transfer.     */
name|U32
name|address_modifier
range|:
literal|8
decl_stmt|;
block|}
name|SCU_SGL_ELEMENT_T
typedef|;
define|#
directive|define
name|SCU_SGL_ELEMENT_PAIR_A
value|0
define|#
directive|define
name|SCU_SGL_ELEMENT_PAIR_B
value|1
comment|/**  * @struct SCU_SGL_ELEMENT_PAIR  *  * @brief This structure is the SCU hardware definition of a pair of SGL  *        elements.  *  * The SCU hardware always works on SGL pairs.  They are refered to in the DS  * specification as SGL A and SGL B.  Each SGL pair is followed by the address  * of the next pair.  */
typedef|typedef
struct|struct
name|SCU_SGL_ELEMENT_PAIR
block|{
comment|// OFFSET 0x60-0x68
comment|/**     * This field is the SGL element A of the SGL pair.     */
name|SCU_SGL_ELEMENT_T
name|A
decl_stmt|;
comment|// OFFSET 0x6C-0x74
comment|/**     * This field is the SGL element B of the SGL pair.     */
name|SCU_SGL_ELEMENT_T
name|B
decl_stmt|;
comment|// OFFSET 0x78-0x7C
comment|/**     * This field is the upper 32 bits of the 64 bit address to the next SGL     * element pair.     */
name|U32
name|next_pair_upper
decl_stmt|;
comment|/**     * This field is the lower 32 bits of the 64 bit address to the next SGL     * element pair.     */
name|U32
name|next_pair_lower
decl_stmt|;
block|}
name|SCU_SGL_ELEMENT_PAIR_T
typedef|;
comment|/**  * @struct TRANSPORT_SNAPSHOT  *  * @brief This structure is the SCU hardware scratch area for the task  *        context.  *  * This is set to 0 by the driver but can be read by issuing a dump TC request  * to the SCU.  */
struct|struct
name|TRANSPORT_SNAPSHOT
block|{
comment|// OFFSET 0x48
name|U32
name|xfer_rdy_write_data_length
decl_stmt|;
comment|// OFFSET 0x4C
name|U32
name|data_offset
decl_stmt|;
comment|// OFFSET 0x50
name|U32
name|data_transfer_size
range|:
literal|24
decl_stmt|;
name|U32
name|reserved_50_0
range|:
literal|8
decl_stmt|;
comment|// OFFSET 0x54
name|U32
name|next_initiator_write_data_offset
decl_stmt|;
comment|// OFFSET 0x58
name|U32
name|next_initiator_write_data_xfer_size
range|:
literal|24
decl_stmt|;
name|U32
name|reserved_58_0
range|:
literal|8
decl_stmt|;
block|}
struct|;
comment|/**  * @struct SCU_TASK_CONTEXT  *  * @brief This structure defines the contents of the SCU silicon task context.  *        It lays out all of the fields according to the expected order and  *        location for the Storage Controller unit.  */
typedef|typedef
struct|struct
name|SCU_TASK_CONTEXT
block|{
comment|// OFFSET 0x00 ------
comment|/**     * This field must be encoded to one of the valid SCU task priority values     *    - SCU_TASK_PRIORITY_NORMAL     *    - SCU_TASK_PRIORITY_HEAD_OF_Q     *    - SCU_TASK_PRIORITY_HIGH     */
name|U32
name|priority
range|:
literal|2
decl_stmt|;
comment|/**     * This field must be set to TRUE if this is an initiator generated request.     * Until target mode is supported all task requests are initiator requests.     */
name|U32
name|initiator_request
range|:
literal|1
decl_stmt|;
comment|/**     * This field must be set to one of the valid connection rates valid values     * are 0x8, 0x9, and 0xA.     */
name|U32
name|connection_rate
range|:
literal|4
decl_stmt|;
comment|/**     * This field muse be programed when generating an SMP response since the SMP     * connection remains open until the SMP response is generated.     */
name|U32
name|protocol_engine_index
range|:
literal|3
decl_stmt|;
comment|/**     * This field must contain the logical port for the task request.     */
name|U32
name|logical_port_index
range|:
literal|3
decl_stmt|;
comment|/**     * This field must be set to one of the SCU_TASK_CONTEXT_PROTOCOL values     *    - SCU_TASK_CONTEXT_PROTOCOL_SMP     *    - SCU_TASK_CONTEXT_PROTOCOL_SSP     *    - SCU_TASK_CONTEXT_PROTOCOL_STP     *    - SCU_TASK_CONTEXT_PROTOCOL_NONE     */
name|U32
name|protocol_type
range|:
literal|3
decl_stmt|;
comment|/**     * This filed must be set to the TCi allocated for this task     */
name|U32
name|task_index
range|:
literal|12
decl_stmt|;
comment|/**     * This field is reserved and must be set to 0x00     */
name|U32
name|reserved_00_0
range|:
literal|1
decl_stmt|;
comment|/**     * For a normal task request this must be set to 0.  If this is an abort of     * this task request it must be set to 1.     */
name|U32
name|abort
range|:
literal|1
decl_stmt|;
comment|/**     * This field must be set to TRUE for the SCU hardware to process the task.     */
name|U32
name|valid
range|:
literal|1
decl_stmt|;
comment|/**     * This field must be set to SCU_TASK_CONTEXT_TYPE     */
name|U32
name|context_type
range|:
literal|1
decl_stmt|;
comment|// OFFSET 0x04
comment|/**     * This field contains the RNi that is the target of this request.     */
name|U32
name|remote_node_index
range|:
literal|12
decl_stmt|;
comment|/**     * This field is programmed if this is a mirrored request, which we are not     * using, in which case it is the RNi for the mirrored target.     */
name|U32
name|mirrored_node_index
range|:
literal|12
decl_stmt|;
comment|/**     * This field is programmed with the direction of the SATA reqeust     *    - SCU_SATA_WRITE_DATA_DIRECTION     *    - SCU_SATA_READ_DATA_DIRECTION     */
name|U32
name|sata_direction
range|:
literal|1
decl_stmt|;
comment|/**     * This field is programmsed with one of the following SCU_COMMAND_CODE     *    - SCU_COMMAND_CODE_INITIATOR_NEW_TASK     *    - SCU_COMMAND_CODE_ACTIVE_TASK     *    - SCU_COMMAND_CODE_PRIMITIVE_SEQ_TASK     *    - SCU_COMMAND_CODE_TARGET_RAW_FRAMES     */
name|U32
name|command_code
range|:
literal|2
decl_stmt|;
comment|/**     * This field is set to TRUE if the remote node should be suspended.     * This bit is only valid for SSP& SMP target devices.     */
name|U32
name|suspend_node
range|:
literal|1
decl_stmt|;
comment|/**     * This field is programmed with one of the following command type codes     *     * For SAS requests use the SCU_SSP_TASK_TYPE     *    - SCU_TASK_TYPE_IOREAD     *    - SCU_TASK_TYPE_IOWRITE     *    - SCU_TASK_TYPE_SMP_REQUEST     *    - SCU_TASK_TYPE_RESPONSE     *    - SCU_TASK_TYPE_RAW_FRAME     *    - SCU_TASK_TYPE_PRIMITIVE     *     * For SATA requests use the SCU_SATA_TASK_TYPE     *    - SCU_TASK_TYPE_DMA_IN     *    - SCU_TASK_TYPE_FPDMAQ_READ     *    - SCU_TASK_TYPE_PACKET_DMA_IN     *    - SCU_TASK_TYPE_SATA_RAW_FRAME     *    - SCU_TASK_TYPE_DMA_OUT     *    - SCU_TASK_TYPE_FPDMAQ_WRITE     *    - SCU_TASK_TYPE_PACKET_DMA_OUT     */
name|U32
name|task_type
range|:
literal|4
decl_stmt|;
comment|// OFFSET 0x08
comment|/**     * This field is reserved and the must be set to 0x00     */
name|U32
name|link_layer_control
range|:
literal|8
decl_stmt|;
comment|// presently all reserved
comment|/**     * This field is set to TRUE when TLR is to be enabled     */
name|U32
name|ssp_tlr_enable
range|:
literal|1
decl_stmt|;
comment|/**     * This is field specifies if the SCU DMAs a response frame to host     * memory for good response frames when operating in target mode.     */
name|U32
name|dma_ssp_target_good_response
range|:
literal|1
decl_stmt|;
comment|/**     * This field indicates if the SCU should DMA the response frame to     * host memory.     */
name|U32
name|do_not_dma_ssp_good_response
range|:
literal|1
decl_stmt|;
comment|/**     * This field is set to TRUE when strict ordering is to be enabled     */
name|U32
name|strict_ordering
range|:
literal|1
decl_stmt|;
comment|/**     * This field indicates the type of endianess to be utilized for the     * frame.  command, task, and response frames utilized control_frame     * set to 1.     */
name|U32
name|control_frame
range|:
literal|1
decl_stmt|;
comment|/**     * This field is reserved and the driver should set to 0x00     */
name|U32
name|tl_control_reserved
range|:
literal|3
decl_stmt|;
comment|/**     * This field is set to TRUE when the SCU hardware task timeout control is to     * be enabled     */
name|U32
name|timeout_enable
range|:
literal|1
decl_stmt|;
comment|/**     * This field is reserved and the driver should set it to 0x00     */
name|U32
name|pts_control_reserved
range|:
literal|7
decl_stmt|;
comment|/**     * This field should be set to TRUE when block guard is to be enabled     */
name|U32
name|block_guard_enable
range|:
literal|1
decl_stmt|;
comment|/**     * This field is reserved and the driver should set to 0x00     */
name|U32
name|sdma_control_reserved
range|:
literal|7
decl_stmt|;
comment|// OFFSET 0x0C
comment|/**     * This field is the address modifier for this io request it should be     * programmed with the virtual function that is making the request.     */
name|U32
name|address_modifier
range|:
literal|16
decl_stmt|;
comment|/**     * @todo What we support mirrored SMP response frame?     */
name|U32
name|mirrored_protocol_engine
range|:
literal|3
decl_stmt|;
comment|// mirrored protocol Engine Index
comment|/**     * If this is a mirrored request the logical port index for the mirrored RNi     * must be programmed.     */
name|U32
name|mirrored_logical_port
range|:
literal|4
decl_stmt|;
comment|// mirrored local port index
comment|/**     * This field is reserved and the driver must set it to 0x00     */
name|U32
name|reserved_0C_0
range|:
literal|8
decl_stmt|;
comment|/**     * This field must be set to TRUE if the mirrored request processing is to be     * enabled.     */
name|U32
name|mirror_request_enable
range|:
literal|1
decl_stmt|;
comment|// Mirrored request Enable
comment|// OFFSET 0x10
comment|/**     * This field is the command iu length in dwords     */
name|U32
name|ssp_command_iu_length
range|:
literal|8
decl_stmt|;
comment|/**     * This is the target TLR enable bit it must be set to 0 when creatning the     * task context.     */
name|U32
name|xfer_ready_tlr_enable
range|:
literal|1
decl_stmt|;
comment|/**     * This field is reserved and the driver must set it to 0x00     */
name|U32
name|reserved_10_0
range|:
literal|7
decl_stmt|;
comment|/**     * This is the maximum burst size that the SCU hardware will send in one     * connection its value is (N x 512) and N must be a multiple of 2.  If the     * value is 0x00 then maximum burst size is disabled.     */
name|U32
name|ssp_max_burst_size
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0x14
comment|/**     * This filed is set to the number of bytes to be transfered in the request.     */
name|U32
name|transfer_length_bytes
range|:
literal|24
decl_stmt|;
comment|// In terms of bytes
comment|/**     * This field is reserved and the driver should set it to 0x00     */
name|U32
name|reserved_14_0
range|:
literal|8
decl_stmt|;
comment|// OFFSET 0x18-0x2C
comment|/**     * This union provides for the protocol specif part of the SCU Task Context.     */
name|union
name|PROTOCOL_CONTEXT
name|type
decl_stmt|;
comment|// OFFSET 0x30-0x34
comment|/**     * This field is the upper 32 bits of the 64 bit physical address of the     * command iu buffer     */
name|U32
name|command_iu_upper
decl_stmt|;
comment|/**     * This field is the lower 32 bits of the 64 bit physical address of the     * command iu buffer     */
name|U32
name|command_iu_lower
decl_stmt|;
comment|// OFFSET 0x38-0x3C
comment|/**     * This field is the upper 32 bits of the 64 bit physical address of the     * response iu buffer     */
name|U32
name|response_iu_upper
decl_stmt|;
comment|/**     * This field is the lower 32 bits of the 64 bit physical address of the     * response iu buffer     */
name|U32
name|response_iu_lower
decl_stmt|;
comment|// OFFSET 0x40
comment|/**     * This field is set to the task phase of the SCU hardware. The driver must     * set this to 0x01     */
name|U32
name|task_phase
range|:
literal|8
decl_stmt|;
comment|/**     * This field is set to the transport layer task status.  The driver must set     * this to 0x00     */
name|U32
name|task_status
range|:
literal|8
decl_stmt|;
comment|/**     * This field is used during initiator write TLR     */
name|U32
name|previous_extended_tag
range|:
literal|4
decl_stmt|;
comment|/**     * This field is set the maximum number of retries for a STP non-data FIS     */
name|U32
name|stp_retry_count
range|:
literal|2
decl_stmt|;
comment|/**     * This field is reserved and the driver must set it to 0x00     */
name|U32
name|reserved_40_1
range|:
literal|2
decl_stmt|;
comment|/**     * This field is used by the SCU TL to determine when to take a snapshot when     * tranmitting read data frames.     *    - 0x00 The entire IO     *    - 0x01 32k     *    - 0x02 64k     *    - 0x04 128k     *    - 0x08 256k     */
name|U32
name|ssp_tlr_threshold
range|:
literal|4
decl_stmt|;
comment|/**     * This field is reserved and the driver must set it to 0x00     */
name|U32
name|reserved_40_2
range|:
literal|4
decl_stmt|;
comment|// OFFSET 0x44
name|U32
name|write_data_length
decl_stmt|;
comment|// read only set to 0
comment|// OFFSET 0x48-0x58
name|struct
name|TRANSPORT_SNAPSHOT
name|snapshot
decl_stmt|;
comment|// read only set to 0
comment|// OFFSET 0x5C
name|U32
name|block_protection_enable
range|:
literal|1
decl_stmt|;
name|U32
name|block_size
range|:
literal|2
decl_stmt|;
name|U32
name|block_protection_function
range|:
literal|2
decl_stmt|;
name|U32
name|reserved_5C_0
range|:
literal|9
decl_stmt|;
name|U32
name|active_sgl_element
range|:
literal|2
decl_stmt|;
comment|// read only set to 0
name|U32
name|sgl_exhausted
range|:
literal|1
decl_stmt|;
comment|// read only set to 0
name|U32
name|payload_data_transfer_error
range|:
literal|4
decl_stmt|;
comment|// read only set to 0
name|U32
name|frame_buffer_offset
range|:
literal|11
decl_stmt|;
comment|// read only set to 0
comment|// OFFSET 0x60-0x7C
comment|/**     * This field is the first SGL element pair found in the TC data structure.     */
name|SCU_SGL_ELEMENT_PAIR_T
name|sgl_pair_ab
decl_stmt|;
comment|// OFFSET 0x80-0x9C
comment|/**     * This field is the second SGL element pair found in the TC data structure.     */
name|SCU_SGL_ELEMENT_PAIR_T
name|sgl_pair_cd
decl_stmt|;
comment|// OFFSET 0xA0-BC
name|SCU_SGL_ELEMENT_PAIR_T
name|sgl_snapshot_ac
decl_stmt|;
comment|// OFFSET 0xC0
name|U32
name|active_sgl_element_pair
decl_stmt|;
comment|// read only set to 0
comment|// OFFSET 0xC4-0xCC
name|U32
name|reserved_C4_CC
index|[
literal|3
index|]
decl_stmt|;
comment|// OFFSET 0xD0
name|U32
name|intermediate_crc_value
range|:
literal|16
decl_stmt|;
name|U32
name|initial_crc_seed
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0xD4
name|U32
name|application_tag_for_verify
range|:
literal|16
decl_stmt|;
name|U32
name|application_tag_for_generate
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0xD8
name|U32
name|reference_tag_seed_for_verify_function
decl_stmt|;
comment|// OFFSET 0xDC
name|U32
name|reserved_DC
decl_stmt|;
comment|// OFFSET 0xE0
name|U32
name|reserved_E0_0
range|:
literal|16
decl_stmt|;
name|U32
name|application_tag_mask_for_generate
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0xE4
name|U32
name|block_protection_control
range|:
literal|16
decl_stmt|;
name|U32
name|application_tag_mask_for_verify
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0xE8
name|U32
name|block_protection_error
range|:
literal|8
decl_stmt|;
name|U32
name|reserved_E8_0
range|:
literal|24
decl_stmt|;
comment|// OFFSET 0xEC
name|U32
name|reference_tag_seed_for_verify
decl_stmt|;
comment|// OFFSET 0xF0
name|U32
name|intermediate_crc_valid_snapshot
range|:
literal|16
decl_stmt|;
name|U32
name|reserved_F0_0
range|:
literal|16
decl_stmt|;
comment|// OFFSET 0xF4
name|U32
name|reference_tag_seed_for_verify_function_snapshot
decl_stmt|;
comment|// OFFSET 0xF8
name|U32
name|snapshot_of_reserved_dword_DC_of_tc
decl_stmt|;
comment|// OFFSET 0xFC
name|U32
name|reference_tag_seed_for_generate_function_snapshot
decl_stmt|;
block|}
name|SCU_TASK_CONTEXT_T
typedef|;
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
comment|// _SCU_TASK_CONTEXT_H_
end_comment

end_unit

