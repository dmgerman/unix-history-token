begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SATI_TRANSLATOR_SEQUENCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SATI_TRANSLATOR_SEQUENCE_H_
end_define

begin_comment
comment|/**  * @file  * @brief This file contains all of the defintions for the SATI translator  *        sequence.  A translator sequence is simply a defintion for the  *        various sequences of commands that occur in this translator.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_device.h>
end_include

begin_comment
comment|/**  * @enum _SATI_TRANSLATOR_SEQUENCE_TYPE  *  * @brief This enumeration defines the possible sequence types for the  *        translator.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_SATI_TRANSLATOR_SEQUENCE_TYPE
block|{
comment|// SCSI Primary Command (SPC) sequences.
name|SATI_SEQUENCE_REPORT_LUNS
block|,
name|SATI_SEQUENCE_TEST_UNIT_READY
block|,
name|SATI_SEQUENCE_INQUIRY_STANDARD
block|,
name|SATI_SEQUENCE_INQUIRY_SUPPORTED_PAGES
block|,
name|SATI_SEQUENCE_INQUIRY_SERIAL_NUMBER
block|,
name|SATI_SEQUENCE_INQUIRY_DEVICE_ID
block|,
name|SATI_SEQUENCE_INQUIRY_ATA_INFORMATION
block|,
name|SATI_SEQUENCE_INQUIRY_BLOCK_DEVICE
block|,
name|SATI_SEQUENCE_INQUIRY_EXECUTE_DEVICE_DIAG
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_CACHING
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_INFORMATIONAL_EXCP_CONTROL
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_READ_WRITE_ERROR
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_DISCONNECT_RECONNECT
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_CONTROL
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_POWER_CONDITION
block|,
name|SATI_SEQUENCE_MODE_SENSE_6_ALL_PAGES
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_CACHING
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_INFORMATIONAL_EXCP_CONTROL
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_READ_WRITE_ERROR
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_DISCONNECT_RECONNECT
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_CONTROL
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_POWER_CONDITION
block|,
name|SATI_SEQUENCE_MODE_SENSE_10_ALL_PAGES
block|,
name|SATI_SEQUENCE_MODE_SELECT_MODE_PAGE_CACHING
block|,
name|SATI_SEQUENCE_MODE_SELECT_MODE_POWER_CONDITION
block|,
name|SATI_SEQUENCE_MODE_SELECT_MODE_INFORMATION_EXCEPT_CONTROL
block|,
comment|//Log Sense Sequences
name|SATI_SEQUENCE_LOG_SENSE_SELF_TEST_LOG_PAGE
block|,
name|SATI_SEQUENCE_LOG_SENSE_EXTENDED_SELF_TEST_LOG_PAGE
block|,
name|SATI_SEQUENCE_LOG_SENSE_SUPPORTED_LOG_PAGE
block|,
name|SATI_SEQUENCE_LOG_SENSE_INFO_EXCEPTION_LOG_PAGE
block|,
comment|// SCSI Block Command (SBC) sequences.
name|SATI_SEQUENCE_READ_6
block|,
name|SATI_SEQUENCE_READ_10
block|,
name|SATI_SEQUENCE_READ_12
block|,
name|SATI_SEQUENCE_READ_16
block|,
name|SATI_SEQUENCE_READ_CAPACITY_10
block|,
name|SATI_SEQUENCE_READ_CAPACITY_16
block|,
name|SATI_SEQUENCE_SYNCHRONIZE_CACHE
block|,
name|SATI_SEQUENCE_VERIFY_10
block|,
name|SATI_SEQUENCE_VERIFY_12
block|,
name|SATI_SEQUENCE_VERIFY_16
block|,
name|SATI_SEQUENCE_WRITE_6
block|,
name|SATI_SEQUENCE_WRITE_10
block|,
name|SATI_SEQUENCE_WRITE_12
block|,
name|SATI_SEQUENCE_WRITE_16
block|,
name|SATI_SEQUENCE_WRITE_AND_VERIFY
block|,
name|SATI_SEQUENCE_START_STOP_UNIT
block|,
name|SATI_SEQUENCE_REASSIGN_BLOCKS
block|,
comment|// SCSI Task Requests sequences
name|SATI_SEQUENCE_LUN_RESET
block|,
name|SATI_SEQUENCE_ABORT_TASK_SET
block|,
name|SATI_SEQUENCE_REQUEST_SENSE_SMART_RETURN_STATUS
block|,
name|SATI_SEQUENCE_REQUEST_SENSE_CHECK_POWER_MODE
block|,
name|SATI_SEQUENCE_WRITE_LONG
block|,
name|SATI_SEQUENCE_UNMAP
block|,
name|SATI_SEQUENCE_ATA_PASSTHROUGH_12
block|,
name|SATI_SEQUENCE_ATA_PASSTHROUGH_16
block|,
name|SATI_SEQUENCE_READ_BUFFER
block|,
name|SATI_SEQUENCE_WRITE_BUFFER
block|,
name|SATI_SEQUENCE_WRITE_BUFFER_MICROCODE
block|}
name|SATI_TRANSLATOR_SEQUENCE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SATI_SEQUENCE_TYPE_READ_MIN
value|SATI_SEQUENCE_READ_6
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_TYPE_READ_MAX
value|SATI_SEQUENCE_READ_16
end_define

begin_comment
comment|/**  * @name SATI_SEQUENCE_STATES  *  * These constants depict the various state values associated with a  * translation sequence.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_TRANSLATE_DATA
value|1
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_AWAIT_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_FINAL
value|3
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_INCOMPLETE
value|4
end_define

begin_define
define|#
directive|define
name|SATI_SEQUENCE_STATE_READ_ERROR
value|5
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @name SATI_DATA_DIRECTIONS  *  * These constants depict the various types of data directions for a  * translation sequence.  Data can flow in/out (read/write) or no data at  * all.  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_define
define|#
directive|define
name|SATI_DATA_DIRECTION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SATI_DATA_DIRECTION_IN
value|1
end_define

begin_define
define|#
directive|define
name|SATI_DATA_DIRECTION_OUT
value|2
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/**  * @struct SATI_MODE_SELECT_PROCESSING_STATE  *  * @brief This structure contains all of the current processing states  *        for processing mode select 6 and 10 commands' parameter fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_MODE_SELECT_PROCESSING_STATE
block|{
name|U8
modifier|*
name|mode_pages
decl_stmt|;
name|U32
name|mode_page_offset
decl_stmt|;
name|U32
name|mode_pages_size
decl_stmt|;
name|U32
name|size_of_data_processed
decl_stmt|;
name|U32
name|total_ata_command_sent
decl_stmt|;
name|U32
name|ata_command_sent_for_cmp
decl_stmt|;
comment|// cmp: current mode page
name|BOOL
name|current_mode_page_processed
decl_stmt|;
block|}
name|SATI_MODE_SELECT_PROCESSING_STATE_T
typedef|;
end_typedef

begin_enum
enum|enum
name|SATI_REASSIGN_BLOCKS_ATA_COMMAND_STATUS
block|{
name|SATI_REASSIGN_BLOCKS_READY_TO_SEND
block|,
name|SATI_REASSIGN_BLOCKS_COMMAND_FAIL
block|,
name|SATI_REASSIGN_BLOCKS_COMMAND_SUCCESS
block|, }
enum|;
end_enum

begin_comment
comment|/**  * @struct SATI_REASSIGN_BLOCKS_PROCESSING_STATE  *  * @brief This structure contains all of the current processing states  *        for processing reassign block command's parameter fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_REASSIGN_BLOCKS_PROCESSING_STATE
block|{
name|U32
name|lba_offset
decl_stmt|;
name|U32
name|block_lists_size
decl_stmt|;
name|U8
name|lba_size
decl_stmt|;
name|U32
name|size_of_data_processed
decl_stmt|;
name|U32
name|ata_command_sent_for_current_lba
decl_stmt|;
name|BOOL
name|current_lba_processed
decl_stmt|;
name|enum
name|SATI_REASSIGN_BLOCKS_ATA_COMMAND_STATUS
name|ata_command_status
decl_stmt|;
block|}
name|SATI_REASSIGN_BLOCKS_PROCESSING_STATE_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SATI_ATAPI_REQUEST_SENSE_CDB_LENGTH
value|12
end_define

begin_comment
comment|/**  * @struct SATI_ATAPI_DATA  *  * @brief The SATI_ATAPI_DATA structure is for sati atapi IO specific data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_ATAPI_DATA
block|{
name|U8
name|request_sense_cdb
index|[
name|SATI_ATAPI_REQUEST_SENSE_CDB_LENGTH
index|]
decl_stmt|;
block|}
name|SATI_ATAPI_DATA_T
typedef|;
end_typedef

begin_enum
enum|enum
name|SATI_UNMAP_ATA_COMMAND_STATUS
block|{
name|SATI_UNMAP_READY_TO_SEND
block|,
name|SATI_UNMAP_COMMAND_FAIL
block|,
name|SATI_UNMAP_COMMAND_SUCCESS
block|, }
enum|;
end_enum

begin_comment
comment|/**  * @struct SATI_UNMAP_PROCESSING_STATE  *  * @brief This structure contains all of the current processing states  *        for processing unmap command data translation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_UNMAP_PROCESSING_STATE
block|{
name|U32
name|max_unmap_block_descriptors
decl_stmt|;
name|U32
name|current_unmap_block_descriptor_index
decl_stmt|;
name|U32
name|current_lba_count
decl_stmt|;
name|SATI_LBA
name|current_lba
decl_stmt|;
name|SATI_LBA
name|next_lba
decl_stmt|;
name|U32
name|max_lba_range_entries
decl_stmt|;
name|void
modifier|*
name|current_dsm_descriptor
decl_stmt|;
name|void
modifier|*
name|virtual_unmap_buffer
decl_stmt|;
name|U32
name|physical_unmap_buffer_low
decl_stmt|;
name|U32
name|physical_unmap_buffer_high
decl_stmt|;
name|void
modifier|*
name|unmap_buffer_sgl_pair
decl_stmt|;
block|}
name|SATI_UNMAP_PROCESSING_STATE_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SATI_TRANSLATOR_SEQUENCE  *  * @brief This structure contains all of the translation information  *        associated with a particular request.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SATI_TRANSLATOR_SEQUENCE
block|{
comment|/**     * This field contains the sequence type determined by the SATI.     */
name|U8
name|type
decl_stmt|;
comment|/**     * This field indicates the current state for the sequence.     */
name|U8
name|state
decl_stmt|;
comment|/**     * This field indicates the data direction (none, read, or write) for     * the translated request.     */
name|U8
name|data_direction
decl_stmt|;
comment|/**     * This field contains the SATA/ATA protocol to be utilized during     * the IO transfer.     */
name|U8
name|protocol
decl_stmt|;
comment|/**     * This field is utilized for sequences requiring data translation.     * It specifies the amount of data requested by the caller from the     * operation.  It's necessary, because at times the user requests less     * data than is available.  Thus, we need to avoid overrunning the     * buffer.     */
name|U32
name|allocation_length
decl_stmt|;
comment|/**     * This field specifies the amount of data that will actually be     * transfered across the wire for this ATA request.     */
name|U32
name|ata_transfer_length
decl_stmt|;
comment|/**    * This field specifies the amount of data bytes that have been    * set in a translation sequence. It will be incremented every time    * a data byte has been set by a sati translation.    */
name|U16
name|number_data_bytes_set
decl_stmt|;
comment|/**    * This field indicates whether or not the sense response has been set    * by the translation sequence.    */
name|BOOL
name|is_sense_response_set
decl_stmt|;
comment|/**     * This field indicates whether or not the translation requires     * response translation.     */
name|BOOL
name|is_translate_response_required
decl_stmt|;
comment|/**     * This field specifies the remote device context for which this     * translator sequence is destined.     */
name|SATI_DEVICE_T
modifier|*
name|device
decl_stmt|;
comment|/**     * This field is utilized to provide the translator with memory space     * required for translations that utilize multiple requests.     */
union|union
block|{
name|U32
name|translated_command
decl_stmt|;
name|U32
name|move_sector_count
decl_stmt|;
name|U32
name|scratch
decl_stmt|;
name|SATI_REASSIGN_BLOCKS_PROCESSING_STATE_T
name|reassign_blocks_process_state
decl_stmt|;
name|SATI_MODE_SELECT_PROCESSING_STATE_T
name|process_state
decl_stmt|;
name|SATI_UNMAP_PROCESSING_STATE_T
name|unmap_process_state
decl_stmt|;
name|SATI_ATAPI_DATA_T
name|sati_atapi_data
decl_stmt|;
block|}
name|command_specific_data
union|;
block|}
name|SATI_TRANSLATOR_SEQUENCE_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SATI_TRANSLATOR_SEQUENCE_H_
end_comment

end_unit

