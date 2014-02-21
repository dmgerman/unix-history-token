begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCU_VIIT_DATA_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_SCU_VIIT_DATA_HEADER_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains the constants and structures for the SCU hardware  *        VIIT table entries.  */
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
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_MASK
value|(0xC0000000UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_SHIFT
value|(30UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_FUNCTION_MASK
value|(0x0FF00000UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_FUNCTION_SHIFT
value|(20UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_IPPTMODE_MASK
value|(0x0001F800UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_IPPTMODE_SHIFT
value|(12UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_LPVIE_MASK
value|(0x00000F00UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_LPVIE_SHIFT
value|(8UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_STATUS_MASK
value|(0x000000FFUL)
define|#
directive|define
name|SCU_VIIT_ENTRY_STATUS_SHIFT
value|(0UL)
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_INVALID
value|(0UL<< SCU_VIIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_VIIT
value|(1UL<< SCU_VIIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_IIT
value|(2UL<< SCU_VIIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_VIIT_ENTRY_ID_VIRT_EXP
value|(3UL<< SCU_VIIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_VIIT_IPPT_SSP_INITIATOR
value|(0x01UL<< SCU_VIIT_ENTRY_IPPTMODE_SHIFT)
define|#
directive|define
name|SCU_VIIT_IPPT_SMP_INITIATOR
value|(0x02UL<< SCU_VIIT_ENTRY_IPPTMODE_SHIFT)
define|#
directive|define
name|SCU_VIIT_IPPT_STP_INITIATOR
value|(0x04UL<< SCU_VIIT_ENTRY_IPPTMODE_SHIFT)
define|#
directive|define
name|SCU_VIIT_IPPT_INITIATOR
define|\
value|(                                \        SCU_VIIT_IPPT_SSP_INITIATOR  \      | SCU_VIIT_IPPT_SMP_INITIATOR  \      | SCU_VIIT_IPPT_STP_INITIATOR  \    )
define|#
directive|define
name|SCU_VIIT_STATUS_RNC_VALID
value|(0x01UL<< SCU_VIIT_ENTRY_STATUS_SHIFT)
define|#
directive|define
name|SCU_VIIT_STATUS_ADDRESS_VALID
value|(0x02UL<< SCU_VIIT_ENTRY_STATUS_SHIFT)
define|#
directive|define
name|SCU_VIIT_STATUS_RNI_VALID
value|(0x04UL<< SCU_VIIT_ENTRY_STATUS_SHIFT)
define|#
directive|define
name|SCU_VIIT_STATUS_ALL_VALID
define|\
value|(                                   \        SCU_VIIT_STATUS_RNC_VALID       \      | SCU_VIIT_STATUS_ADDRESS_VALID   \      | SCU_VIIT_STATUS_RNI_VALID       \    )
define|#
directive|define
name|SCU_VIIT_IPPT_SMP_TARGET
value|(0x10UL<< SCU_VIIT_ENTRY_IPPTMODE_SHIFT)
comment|/**  * @struct SCU_VIIT_ENTRY  *  * @brief This is the SCU Virtual Initiator Table Entry  */
typedef|typedef
struct|struct
name|SCU_VIIT_ENTRY
block|{
comment|/**     * This must be encoded as to the type of initiator that is being constructed     * for this port.     */
name|U32
name|status
decl_stmt|;
comment|/**     * Virtual initiator high SAS Address     */
name|U32
name|initiator_sas_address_hi
decl_stmt|;
comment|/**     * Virtual initiator low SAS Address     */
name|U32
name|initiator_sas_address_lo
decl_stmt|;
comment|/**     * This must be 0     */
name|U32
name|reserved
decl_stmt|;
block|}
name|SCU_VIIT_ENTRY_T
typedef|;
comment|// IIT Status Defines
define|#
directive|define
name|SCU_IIT_ENTRY_ID_MASK
value|(0xC0000000UL)
define|#
directive|define
name|SCU_IIT_ENTRY_ID_SHIFT
value|(30UL)
define|#
directive|define
name|SCU_IIT_ENTRY_STATUS_UPDATE_MASK
value|(0x20000000UL)
define|#
directive|define
name|SCU_IIT_ENTRY_STATUS_UPDATE_SHIFT
value|(29UL)
define|#
directive|define
name|SCU_IIT_ENTRY_LPI_MASK
value|(0x00000F00UL)
define|#
directive|define
name|SCU_IIT_ENTRY_LPI_SHIFT
value|(8UL)
define|#
directive|define
name|SCU_IIT_ENTRY_STATUS_MASK
value|(0x000000FFUL)
define|#
directive|define
name|SCU_IIT_ENTRY_STATUS_SHIFT
value|(0UL)
comment|// IIT Remote Initiator Defines
define|#
directive|define
name|SCU_IIT_ENTRY_REMOTE_TAG_MASK
value|(0x0000FFFFUL)
define|#
directive|define
name|SCU_IIT_ENTRY_REMOTE_TAG_SHIFT
value|(0UL)
define|#
directive|define
name|SCU_IIT_ENTRY_REMOTE_RNC_MASK
value|(0x0FFF0000UL)
define|#
directive|define
name|SCU_IIT_ENTRY_REMOTE_RNC_SHIFT
value|(16UL)
define|#
directive|define
name|SCU_IIT_ENTRY_ID_INVALID
value|(0UL<< SCU_IIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_IIT_ENTRY_ID_VIIT
value|(1UL<< SCU_IIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_IIT_ENTRY_ID_IIT
value|(2UL<< SCU_IIT_ENTRY_ID_SHIFT)
define|#
directive|define
name|SCU_IIT_ENTRY_ID_VIRT_EXP
value|(3UL<< SCU_IIT_ENTRY_ID_SHIFT)
comment|/**  * @struct SCU_IIT_ENTRY  *  * @brief This will be implemented later when we support virtual functions  */
typedef|typedef
struct|struct
name|SCU_IIT_ENTRY
block|{
name|U32
name|status
decl_stmt|;
name|U32
name|remote_initiator_sas_address_hi
decl_stmt|;
name|U32
name|remote_initiator_sas_address_lo
decl_stmt|;
name|U32
name|remote_initiator
decl_stmt|;
block|}
name|SCU_IIT_ENTRY_T
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
comment|// _SCU_VIIT_DATA_HEADER_
end_comment

end_unit

