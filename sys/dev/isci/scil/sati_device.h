begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATI_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATI_DEVICE_H_
end_define

begin_comment
comment|/**  * @file  * @brief This file contains all of the defintions for the SATI remote  *        device object.  Some translations require information to be  *        remembered on a per device basis.  This information is stored  *        in the object defined in this file.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/isci/scil/intel_ata.h>
end_include

begin_comment
comment|/**  * @enum _SATI_DEVICE_STATE  *  * @brief This enumeration depicts the various states possible for the a  *        translation remote device object.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SATI_DEVICE_STATE
block|{
name|SATI_DEVICE_STATE_OPERATIONAL
block|,
name|SATI_DEVICE_STATE_STOPPED
block|,
name|SATI_DEVICE_STATE_STANDBY
block|,
name|SATI_DEVICE_STATE_IDLE
block|,
name|SATI_DEVICE_STATE_DEVICE_FAULT_OCCURRED
block|,
name|SATI_DEVICE_STATE_FORMAT_UNIT_IN_PROGRESS
block|,
name|SATI_DEVICE_STATE_SELF_TEST_IN_PROGRESS
block|,
name|SATI_DEVICE_STATE_SEQUENCE_INCOMPLETE
block|,
name|SATI_DEVICE_STATE_UNIT_ATTENTION_CONDITION
block|}
name|SATI_DEVICE_STATE
typedef|;
end_typedef

begin_comment
comment|/**  * @name SATI_DEVICE_CAPABILITIES  *  * These constants define the various capabilities that a remote device may  * support for which there is an impact on translation.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_UDMA_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_NCQ_REQUESTED_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_NCQ_SUPPORTED_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_48BIT_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_DMA_FUA_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_SMART_SUPPORT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_REMOVABLE_MEDIA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_SMART_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_WRITE_UNCORRECTABLE_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_MULTIPLE_SECTORS_PER_PHYSCIAL_SECTOR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_SMART_SELF_TEST_SUPPORT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_SSD
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_DSM_TRIM_SUPPORT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_DETERMINISTIC_READ_AFTER_TRIM
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_READ_ZERO_AFTER_TRIM
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_STANDBY_ENABLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SATI_DEVICE_CAP_IGNORE_FUA
value|0x00010000
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @struct SATI_DEVICE  *  * @brief The SATI_DEVICE structure define the state of the remote device  *        with respect to translation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_DEVICE
block|{
comment|/**     * This field simply dictates the state of the SATI device.     */
name|SATI_DEVICE_STATE
name|state
decl_stmt|;
comment|/**     * This field indicates features supported by the remote device that     * impact translation execution.     */
name|U16
name|capabilities
decl_stmt|;
comment|/**     * This field indicates the depth of the native command queue supported     * by the device.     */
name|U8
name|ncq_depth
decl_stmt|;
comment|/**     * This field stores the additional sense code for a unit attention     * condition.     */
name|U8
name|unit_attention_asc
decl_stmt|;
comment|/**     * This field indicates the additional sense code qualifier for a unit     * attention condition.     */
name|U8
name|unit_attention_ascq
decl_stmt|;
comment|/**     * This field indicates the ATA standby timer value set throught the     * ATA IDLE and ATA Standby commands     */
name|U8
name|ata_standby_timer
decl_stmt|;
comment|/**     * This field indicates the maximum number of data set management     * descriptor entries the device supports in blocks.     */
name|U16
name|max_lba_range_entry_blocks
decl_stmt|;
comment|/**     * The field is the reported logical block size for the device     */
name|U32
name|logical_block_size
decl_stmt|;
comment|/**     * This field is the maximum number of blocks per Download Microcode command     * for this device.     */
name|U16
name|max_blocks_per_microcode_command
decl_stmt|;
comment|/**    * This field is the minimum number of blocks per Download Microcode command    * for this device.    */
name|U16
name|min_blocks_per_microcode_command
decl_stmt|;
comment|/**     * This field indicates the type of constructed sense data if enabled descriptor     * sense data will be constructed     */
name|U8
name|descriptor_sense_enable
decl_stmt|;
block|}
name|SATI_DEVICE_T
typedef|;
end_typedef

begin_function_decl
name|void
name|sati_device_construct
parameter_list|(
name|SATI_DEVICE_T
modifier|*
name|device
parameter_list|,
name|BOOL
name|is_ncq_enabled
parameter_list|,
name|U8
name|max_ncq_depth
parameter_list|,
name|BOOL
name|ignore_fua
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sati_device_update_capabilities
parameter_list|(
name|SATI_DEVICE_T
modifier|*
name|device
parameter_list|,
name|ATA_IDENTIFY_DEVICE_DATA_T
modifier|*
name|identify
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATI_TRANSLATOR_SEQUENCE_H_
end_comment

end_unit

