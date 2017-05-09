begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  ******************************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2014 - 2015 Intel Mobile Communications GmbH  * Copyright(c) 2016 Intel Deutschland GmbH  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<linuxwifi@intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2014 Intel Corporation. All rights reserved.  * Copyright(c) 2014 - 2015 Intel Mobile Communications GmbH  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_wlan.h"
end_include

begin_include
include|#
directive|include
file|"opt_iwm.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"if_iwm_config.h"
end_include

begin_define
define|#
directive|define
name|IWM8000_FW
value|"iwm8000Cfw"
end_define

begin_define
define|#
directive|define
name|IWM_NVM_HW_SECTION_NUM_FAMILY_8000
value|10
end_define

begin_define
define|#
directive|define
name|IWM_DEVICE_8000_COMMON
define|\
value|.device_family = IWM_DEVICE_FAMILY_8000,			\ 	.eeprom_size = IWM_OTP_LOW_IMAGE_SIZE_FAMILY_8000,		\ 	.nvm_hw_section_num = IWM_NVM_HW_SECTION_NUM_FAMILY_8000
end_define

begin_decl_stmt
specifier|const
name|struct
name|iwm_cfg
name|iwm8260_cfg
init|=
block|{
operator|.
name|name
operator|=
literal|"Intel(R) Dual Band Wireless AC 8260"
block|,
operator|.
name|fw_name
operator|=
name|IWM8000_FW
block|,
name|IWM_DEVICE_8000_COMMON
block|,
operator|.
name|host_interrupt_operation_mode
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

