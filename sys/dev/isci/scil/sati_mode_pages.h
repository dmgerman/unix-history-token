begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file  * @brief This file contains the mode page constants and members that are  *        supported by this translation implementation.  */
end_comment

begin_include
include|#
directive|include
file|<dev/isci/scil/sati_types.h>
end_include

begin_comment
comment|// These values represent the mode page (not including header and block
end_comment

begin_comment
comment|// descriptor).  The page length fields in the mode sense data are equivalent
end_comment

begin_comment
comment|// to the constant values below less 2.  The minus 2 is due to not including
end_comment

begin_comment
comment|// the page code byte (byte 0) and the page length byte (byte 1).
end_comment

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_01_LENGTH
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_02_LENGTH
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_08_LENGTH
value|0x14
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_0A_LENGTH
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_19_LENGTH
value|0x8
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_1A_LENGTH
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_1C_LENGTH
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_PAGE_3F_LENGTH
value|SCSI_MODE_PAGE_08_LENGTH    \                                    + SCSI_MODE_PAGE_1C_LENGTH  \  #define SATI_MODE_PAGE_UNSUPPORTED_INDEX 0xFFFF
end_define

begin_define
define|#
directive|define
name|SAT_SUPPORTED_MODE_PAGES_LENGTH
value|sizeof(sat_supported_mode_pages)/sizeof(U8)
end_define

begin_typedef
typedef|typedef
enum|enum
name|_RETURN_PAGE
block|{
name|CHANGEABLE_PAGE
block|,
name|DEFAULT_PAGE
block|}
name|RETURN_PAGE
typedef|;
end_typedef

begin_comment
comment|/**  * @struct SCSI_MODE_SELECT_MODE_PARAMETER_HEADER_6  *  * @brief This structure contains mode parameter header fields for 6 byte  *        mode select command.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCSI_MODE_SELECT_MODE_PARAMETER_HEADER_6
block|{
name|U8
name|mode_data_length
decl_stmt|;
name|U8
name|medium_type
decl_stmt|;
comment|//Should be 0
name|U8
name|device_specific_parameter
decl_stmt|;
name|U8
name|block_descriptor_length
decl_stmt|;
block|}
name|SCSI_MODE_SELECT_MODE_PARAMETER_HEADER_6_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct MODE_PARAMETER_HEADER_10  *  * @brief This structure contains mode parameter header fields for 10 byte  *        mode select command.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCSI_MODE_SELECT_MODE_PARAMETER_HEADER_10
block|{
name|U8
name|mode_data_length
index|[
literal|2
index|]
decl_stmt|;
name|U8
name|medium_type
decl_stmt|;
comment|//Should be 0
name|U8
name|device_specific_parameter
decl_stmt|;
name|U8
name|long_lba
decl_stmt|;
name|U8
name|reserve
decl_stmt|;
name|U8
name|block_descriptor_length
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SCSI_MODE_SELECT_MODE_PARAMETER_HEADER_10_T
typedef|;
end_typedef

begin_comment
comment|/**  * @struct MODE_PARAMETER_BLOCK_DESCRIPTOR  *  * @brief This structure contains mode parameter block descriptor fields.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SCSI_MODE_SELECT_MODE_PARAMETER_BLOCK_DESCRIPTOR
block|{
name|U8
name|density_code
decl_stmt|;
name|U8
name|number_of_blocks
index|[
literal|3
index|]
decl_stmt|;
name|U8
name|reserved
decl_stmt|;
name|U8
name|block_length
index|[
literal|3
index|]
decl_stmt|;
block|}
name|SCSI_MODE_SELECT_MODE_PARAMETER_BLOCK_DESCRIPTOR_T
typedef|;
end_typedef

begin_function_decl
name|U16
name|sati_mode_page_get_page_index
parameter_list|(
name|U8
name|page_code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|U8
modifier|*
name|sati_mode_page_get_mode_page
parameter_list|(
name|U8
name|page_code
parameter_list|,
name|RETURN_PAGE
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|U8
modifier|*
name|sat_changeable_mode_pages
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U8
modifier|*
name|sat_default_mode_pages
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U16
name|sat_mode_page_sizes
index|[]
decl_stmt|;
end_decl_stmt

end_unit

