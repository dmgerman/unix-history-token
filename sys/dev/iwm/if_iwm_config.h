begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Based on BSD-licensed source modules in the Linux iwlwifi driver,  * which were used as the reference documentation for this implementation.  *  ******************************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2007 - 2014 Intel Corporation. All rights reserved.  * Copyright (C) 2016 Intel Deutschland GmbH  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<linuxwifi@intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.  * Copyright (C) 2016 Intel Deutschland GmbH  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IWM_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IWM_CONFIG_H__
end_define

begin_enum
enum|enum
name|iwm_device_family
block|{
name|IWM_DEVICE_FAMILY_UNDEFINED
block|,
name|IWM_DEVICE_FAMILY_7000
block|,
name|IWM_DEVICE_FAMILY_8000
block|, }
enum|;
end_enum

begin_comment
comment|/* Antenna presence definitions */
end_comment

begin_define
define|#
directive|define
name|IWM_ANT_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|IWM_ANT_A
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_B
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_C
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_AB
value|(IWM_ANT_A | IWM_ANT_B)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_AC
value|(IWM_ANT_A | IWM_ANT_C)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_BC
value|(IWM_ANT_B | IWM_ANT_C)
end_define

begin_define
define|#
directive|define
name|IWM_ANT_ABC
value|(IWM_ANT_A | IWM_ANT_B | IWM_ANT_C)
end_define

begin_function
specifier|static
specifier|inline
name|uint8_t
name|num_of_ant
parameter_list|(
name|uint8_t
name|mask
parameter_list|)
block|{
return|return
operator|!
operator|!
operator|(
operator|(
name|mask
operator|)
operator|&
name|IWM_ANT_A
operator|)
operator|+
operator|!
operator|!
operator|(
operator|(
name|mask
operator|)
operator|&
name|IWM_ANT_B
operator|)
operator|+
operator|!
operator|!
operator|(
operator|(
name|mask
operator|)
operator|&
name|IWM_ANT_C
operator|)
return|;
block|}
end_function

begin_comment
comment|/* lower blocks contain EEPROM image and calibration data */
end_comment

begin_define
define|#
directive|define
name|IWM_OTP_LOW_IMAGE_SIZE_FAMILY_7000
value|(16 * 512 * sizeof(uint16_t))
end_define

begin_comment
comment|/* 16 KB */
end_comment

begin_define
define|#
directive|define
name|IWM_OTP_LOW_IMAGE_SIZE_FAMILY_8000
value|(32 * 512 * sizeof(uint16_t))
end_define

begin_comment
comment|/* 32 KB */
end_comment

begin_define
define|#
directive|define
name|IWM_OTP_LOW_IMAGE_SIZE_FAMILY_9000
value|IWM_OTP_LOW_IMAGE_SIZE_FAMILY_8000
end_define

begin_comment
comment|/**  * struct iwm_cfg  * @name: Official name of the device  * @fw_name: Firmware filename.  * @host_interrupt_operation_mode: device needs host interrupt operation  *      mode set  * @nvm_hw_section_num: the ID of the HW NVM section  * @apmg_wake_up_wa: should the MAC access REQ be asserted when a command  *      is in flight. This is due to a HW bug in 7260, 3160 and 7265.  */
end_comment

begin_struct
struct|struct
name|iwm_cfg
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|fw_name
decl_stmt|;
name|uint16_t
name|eeprom_size
decl_stmt|;
name|enum
name|iwm_device_family
name|device_family
decl_stmt|;
name|int
name|host_interrupt_operation_mode
decl_stmt|;
name|uint8_t
name|nvm_hw_section_num
decl_stmt|;
name|int
name|apmg_wake_up_wa
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This list declares the config structures for all devices.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm7260_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm3160_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm3165_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm7265_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm7265d_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm8260_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|iwm_cfg
name|iwm8265_cfg
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IWM_CONFIG_H__ */
end_comment

end_unit

