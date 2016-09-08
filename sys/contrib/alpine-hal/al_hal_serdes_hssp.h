begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_serdes_api API  * SerDes HAL driver API  * @ingroup group_serdes SerDes  * @{  *  * @file   al_hal_serdes.h  *  * @brief Header file for the SerDes HAL driver  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_SERDES_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_SERDES_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_serdes_interface.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_serdes_hssp_regs.h"
end_include

begin_comment
comment|/* *INDENT-OFF* */
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
comment|/* *INDENT-ON* */
comment|/**  * Initializes a SERDES group object  *  * @param  serdes_regs_base  *             The SERDES register file base pointer  *  * @param obj  *             An allocated, non initialized object context  *  * @return 0 if no error found.  *  */
name|int
name|al_serdes_hssp_handle_init
parameter_list|(
name|void
name|__iomem
modifier|*
name|serdes_regs_base
parameter_list|,
name|struct
name|al_serdes_grp_obj
modifier|*
name|obj
parameter_list|)
function_decl|;
comment|/* *INDENT-OFF* */
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
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_SRDS__ */
end_comment

begin_comment
comment|/** @} end of SERDES group */
end_comment

end_unit

