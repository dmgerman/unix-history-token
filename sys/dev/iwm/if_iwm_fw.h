begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  * Driver version we are currently based off of is  * Linux 4.7.3 (tag id d7f6728f57e3ecbb7ef34eb7d9f564d514775d75)  *  ***********************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2013 - 2015 Intel Mobile Communications GmbH  * Copyright(c) 2016        Intel Deutschland GmbH  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<linuxwifi@intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2013 - 2015 Intel Mobile Communications GmbH  * Copyright(c) 2016        Intel Deutschland GmbH  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWM_FW_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWM_FW_H__
end_define

begin_comment
comment|/*  * Block paging calculations  */
end_comment

begin_define
define|#
directive|define
name|IWM_PAGE_2_EXP_SIZE
value|12
end_define

begin_comment
comment|/* 4K == 2^12 */
end_comment

begin_define
define|#
directive|define
name|IWM_FW_PAGING_SIZE
value|(1<< IWM_PAGE_2_EXP_SIZE)
end_define

begin_comment
comment|/* page size is 4KB */
end_comment

begin_define
define|#
directive|define
name|IWM_PAGE_PER_GROUP_2_EXP_SIZE
value|3
end_define

begin_comment
comment|/* 8 pages per group */
end_comment

begin_define
define|#
directive|define
name|IWM_NUM_OF_PAGE_PER_GROUP
value|(1<< IWM_PAGE_PER_GROUP_2_EXP_SIZE)
end_define

begin_comment
comment|/* don't change, support only 32KB size */
end_comment

begin_define
define|#
directive|define
name|IWM_PAGING_BLOCK_SIZE
value|(IWM_NUM_OF_PAGE_PER_GROUP * IWM_FW_PAGING_SIZE)
end_define

begin_comment
comment|/* 32K == 2^15 */
end_comment

begin_define
define|#
directive|define
name|IWM_BLOCK_2_EXP_SIZE
value|(IWM_PAGE_2_EXP_SIZE + IWM_PAGE_PER_GROUP_2_EXP_SIZE)
end_define

begin_comment
comment|/*  * Image paging calculations  */
end_comment

begin_define
define|#
directive|define
name|IWM_BLOCK_PER_IMAGE_2_EXP_SIZE
value|5
end_define

begin_comment
comment|/* 2^5 == 32 blocks per image */
end_comment

begin_define
define|#
directive|define
name|IWM_NUM_OF_BLOCK_PER_IMAGE
value|(1<< IWM_BLOCK_PER_IMAGE_2_EXP_SIZE)
end_define

begin_comment
comment|/* maximum image size 1024KB */
end_comment

begin_define
define|#
directive|define
name|IWM_MAX_PAGING_IMAGE_SIZE
value|(IWM_NUM_OF_BLOCK_PER_IMAGE * IWM_PAGING_BLOCK_SIZE)
end_define

begin_comment
comment|/* Virtual address signature */
end_comment

begin_define
define|#
directive|define
name|IWM_PAGING_ADDR_SIG
value|0xAA000000
end_define

begin_define
define|#
directive|define
name|IWM_PAGING_CMD_IS_SECURED
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IWM_PAGING_CMD_IS_ENABLED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IWM_PAGING_CMD_NUM_OF_PAGES_IN_LAST_GRP_POS
value|0
end_define

begin_define
define|#
directive|define
name|IWM_PAGING_TLV_SECURE_MASK
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|iwm_free_fw_paging
parameter_list|(
name|struct
name|iwm_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iwm_save_fw_paging
parameter_list|(
name|struct
name|iwm_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|iwm_fw_sects
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iwm_send_paging_cmd
parameter_list|(
name|struct
name|iwm_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|iwm_fw_sects
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWM_FW_H__ */
end_comment

end_unit

