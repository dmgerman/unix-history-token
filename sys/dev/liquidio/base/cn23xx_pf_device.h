begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* \file  cn23xx_device.h  * \brief Host Driver: Routines that perform CN23XX specific operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CN23XX_PF_DEVICE_H__
end_ifndef

begin_define
define|#
directive|define
name|__CN23XX_PF_DEVICE_H__
end_define

begin_include
include|#
directive|include
file|"cn23xx_pf_regs.h"
end_include

begin_comment
comment|/*  * Register address and configuration for a CN23XX devices.  * If device specific changes need to be made then add a struct to include  * device specific fields as shown in the commented section  */
end_comment

begin_struct
struct|struct
name|lio_cn23xx_pf
block|{
comment|/* PCI interrupt summary register */
name|uint32_t
name|intr_sum_reg64
decl_stmt|;
comment|/* PCI interrupt enable register */
name|uint32_t
name|intr_enb_reg64
decl_stmt|;
comment|/* The PCI interrupt mask used by interrupt handler */
name|uint64_t
name|intr_mask64
decl_stmt|;
name|struct
name|lio_config
modifier|*
name|conf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BUSY_READING_REG_PF_LOOP_COUNT
value|10000
end_define

begin_function_decl
name|int
name|lio_cn23xx_pf_setup_device
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|lio_cn23xx_pf_get_oq_ticks
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|,
name|uint32_t
name|time_intr_in_us
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lio_cn23xx_pf_fw_loaded
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|oct
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CN23XX_PF_DEVICE_H__ */
end_comment

end_unit

