begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  *  * @brief This file contains all of the unsolicited frame related  *        management for the address table, the headers, and actual  *        payload buffers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_UNSOLICITED_FRAME_CONTROL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_UNSOLICITED_FRAME_CONTROL_H_
end_define

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
file|<dev/isci/types.h>
include|#
directive|include
file|<dev/isci/scil/scu_unsolicited_frame.h>
include|#
directive|include
file|<dev/isci/scil/sci_memory_descriptor_list.h>
include|#
directive|include
file|<dev/isci/scil/scu_constants.h>
include|#
directive|include
file|<dev/isci/scil/sci_status.h>
comment|/**  * @enum UNSOLICITED_FRAME_STATE  *  * This enumeration represents the current unsolicited frame state.  The  * controller object can not updtate the hardware unsolicited frame put  * pointer unless it has already processed the priror unsolicited frames.  */
enum|enum
name|UNSOLICITED_FRAME_STATE
block|{
comment|/**     * This state is when the frame is empty and not in use.  It is     * different from the released state in that the hardware could DMA     * data to this frame buffer.     */
name|UNSOLICITED_FRAME_EMPTY
block|,
comment|/**     * This state is set when the frame buffer is in use by by some     * object in the system.     */
name|UNSOLICITED_FRAME_IN_USE
block|,
comment|/**     * This state is set when the frame is returned to the free pool     * but one or more frames prior to this one are still in use.     * Once all of the frame before this one are freed it will go to     * the empty state.     */
name|UNSOLICITED_FRAME_RELEASED
block|,
name|UNSOLICITED_FRAME_MAX_STATES
block|}
enum|;
comment|/**  * @struct SCIC_SDS_UNSOLICITED_FRAME  *  * This is the unsolicited frame data structure it acts as the container for  * the current frame state, frame header and frame buffer.  */
typedef|typedef
struct|struct
name|SCIC_SDS_UNSOLICITED_FRAME
block|{
comment|/**     * This field contains the current frame state     */
name|enum
name|UNSOLICITED_FRAME_STATE
name|state
decl_stmt|;
comment|/**     * This field points to the frame header data.     */
name|SCU_UNSOLICITED_FRAME_HEADER_T
modifier|*
name|header
decl_stmt|;
comment|/**     * This field points to the frame buffer data.     */
name|void
modifier|*
name|buffer
decl_stmt|;
block|}
name|SCIC_SDS_UNSOLICITED_FRAME_T
typedef|;
comment|/**  * @struct SCIC_SDS_UF_HEADER_ARRAY  *  * This structure contains all of the unsolicited frame header  * information.  */
typedef|typedef
struct|struct
name|SCIC_SDS_UF_HEADER_ARRAY
block|{
comment|/**     * This field is represents a virtual pointer to the start     * address of the UF address table.  The table contains     * 64-bit pointers as required by the hardware.     */
name|SCU_UNSOLICITED_FRAME_HEADER_T
modifier|*
name|array
decl_stmt|;
comment|/**     * This field specifies the physical address location for the UF     * buffer array.     */
name|SCI_PHYSICAL_ADDRESS
name|physical_address
decl_stmt|;
block|}
name|SCIC_SDS_UF_HEADER_ARRAY_T
typedef|;
comment|// Determine the size of the unsolicited frame array including
comment|// unused buffers.
if|#
directive|if
name|SCU_UNSOLICITED_FRAME_COUNT
operator|<=
name|SCU_MIN_UF_TABLE_ENTRIES
define|#
directive|define
name|SCU_UNSOLICITED_FRAME_CONTROL_ARRAY_SIZE
value|SCU_MIN_UF_TABLE_ENTRIES
else|#
directive|else
define|#
directive|define
name|SCU_UNSOLICITED_FRAME_CONTROL_ARRAY_SIZE
value|SCU_MAX_UNSOLICITED_FRAMES
endif|#
directive|endif
comment|// SCU_UNSOLICITED_FRAME_COUNT<= SCU_MIN_UF_TABLE_ENTRIES
comment|/**  * @struct SCIC_SDS_UF_BUFFER_ARRAY  *  * This structure contains all of the unsolicited frame buffer (actual  * payload) information.  */
typedef|typedef
struct|struct
name|SCIC_SDS_UF_BUFFER_ARRAY
block|{
comment|/**     * This field is the minimum number of unsolicited frames supported by the     * hardware and the number of unsolicited frames requested by the software.     */
name|U32
name|count
decl_stmt|;
comment|/**     * This field is the SCIC_UNSOLICITED_FRAME data its used to manage     * the data for the unsolicited frame requests.  It also represents     * the virtual address location that corresponds to the     * physical_address field.     */
name|SCIC_SDS_UNSOLICITED_FRAME_T
name|array
index|[
name|SCU_UNSOLICITED_FRAME_CONTROL_ARRAY_SIZE
index|]
decl_stmt|;
comment|/**     * This field specifies the physical address location for the UF     * buffer array.     */
name|SCI_PHYSICAL_ADDRESS
name|physical_address
decl_stmt|;
block|}
name|SCIC_SDS_UF_BUFFER_ARRAY_T
typedef|;
comment|/**  * @struct SCIC_SDS_UF_ADDRESS_TABLE_ARRAY  *  * This object maintains all of the unsolicited frame address  * table specific data.  The address table is a collection of  * 64-bit pointers that point to 1KB buffers into which  * the silicon will DMA unsolicited frames.  */
typedef|typedef
struct|struct
name|SCIC_SDS_UF_ADDRESS_TABLE_ARRAY
block|{
comment|/**     * This field specifies the actual programmed size of the     * unsolicited frame buffer address table.  The size of the table     * can be larger than the actual number of UF buffers, but it must     * be a power of 2 and the last entry in the table is not allowed     * to be NULL.     */
name|U32
name|count
decl_stmt|;
comment|/**     * This field represents a virtual pointer that refers to the     * starting address of the UF address table.     * 64-bit pointers are required by the hardware.     */
name|SCI_PHYSICAL_ADDRESS
modifier|*
name|array
decl_stmt|;
comment|/**     * This field specifies the physical address location for the UF     * address table.     */
name|SCI_PHYSICAL_ADDRESS
name|physical_address
decl_stmt|;
block|}
name|SCIC_SDS_UF_ADDRESS_TABLE_ARRAY_T
typedef|;
comment|/**  * @struct SCIC_SDS_UNSOLICITED_FRAME_CONTROL  *  * This object contains all of the data necessary to handle  * unsolicited frames.  */
typedef|typedef
struct|struct
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL
block|{
comment|/**     * This field is the software copy of the unsolicited frame queue     * get pointer.  The controller object writes this value to the     * hardware to let the hardware put more unsolicited frame entries.     */
name|U32
name|get
decl_stmt|;
comment|/**     * This field contains all of the unsolicited frame header     * specific fields.     */
name|SCIC_SDS_UF_HEADER_ARRAY_T
name|headers
decl_stmt|;
comment|/**     * This field contains all of the unsolicited frame buffer     * specific fields.     */
name|SCIC_SDS_UF_BUFFER_ARRAY_T
name|buffers
decl_stmt|;
comment|/**     * This field contains all of the unsolicited frame address table     * specific fields.     */
name|SCIC_SDS_UF_ADDRESS_TABLE_ARRAY_T
name|address_table
decl_stmt|;
block|}
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
typedef|;
name|void
name|scic_sds_unsolicited_frame_control_set_address_table_count
parameter_list|(
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
modifier|*
name|uf_control
parameter_list|)
function_decl|;
struct_decl|struct
name|SCIC_SDS_CONTROLLER
struct_decl|;
name|void
name|scic_sds_unsolicited_frame_control_construct
parameter_list|(
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
modifier|*
name|uf_control
parameter_list|,
name|SCI_PHYSICAL_MEMORY_DESCRIPTOR_T
modifier|*
name|mde
parameter_list|,
name|struct
name|SCIC_SDS_CONTROLLER
modifier|*
name|this_controller
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scic_sds_unsolicited_frame_control_get_header
parameter_list|(
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
modifier|*
name|uf_control
parameter_list|,
name|U32
name|frame_index
parameter_list|,
name|void
modifier|*
modifier|*
name|frame_header
parameter_list|)
function_decl|;
name|SCI_STATUS
name|scic_sds_unsolicited_frame_control_get_buffer
parameter_list|(
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
modifier|*
name|uf_control
parameter_list|,
name|U32
name|frame_index
parameter_list|,
name|void
modifier|*
modifier|*
name|frame_buffer
parameter_list|)
function_decl|;
name|BOOL
name|scic_sds_unsolicited_frame_control_release_frame
parameter_list|(
name|SCIC_SDS_UNSOLICITED_FRAME_CONTROL_T
modifier|*
name|uf_control
parameter_list|,
name|U32
name|frame_index
parameter_list|)
function_decl|;
comment|/**  * This macro simply calculates the size of the memory descriptor  * entry that relates to unsolicited frames and the surrounding  * silicon memory required to utilize it.  */
define|#
directive|define
name|scic_sds_unsolicited_frame_control_get_mde_size
parameter_list|(
name|uf_control
parameter_list|)
define|\
value|( ((uf_control).buffers.count * SCU_UNSOLICITED_FRAME_BUFFER_SIZE) \    + ((uf_control).address_table.count * sizeof(SCI_PHYSICAL_ADDRESS)) \    + ((uf_control).buffers.count * sizeof(SCU_UNSOLICITED_FRAME_HEADER_T)) )
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
comment|// _SCIC_SDS_UNSOLICITED_FRAME_CONTROL_H_
end_comment

end_unit

