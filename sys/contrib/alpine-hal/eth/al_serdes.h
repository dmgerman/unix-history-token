begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* Copyright (C) 2013 Annapurna Labs Ltd.  This file is licensed under the terms of the Annapurna Labs' Commercial License Agreement distributed with the file or available on the software download site. Recipient shall use the content of this file only on semiconductor devices or systems developed by or for Annapurna Labs.   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_serdes_init SerDes Initialization  * @ingroup group_serdes SerDes  * @{  *  * @file   al_serdes.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_SERDES_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_SERDES_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_serdes_interface.h"
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
ifdef|#
directive|ifdef
name|AL_DEV_ID
define|#
directive|define
name|CHECK_ALPINE_V1
value|(AL_DEV_ID == AL_DEV_ID_ALPINE_V1)
define|#
directive|define
name|CHECK_ALPINE_V2
value|(AL_DEV_ID == AL_DEV_ID_ALPINE_V2)
else|#
directive|else
define|#
directive|define
name|CHECK_ALPINE_V1
value|1
define|#
directive|define
name|CHECK_ALPINE_V2
value|1
endif|#
directive|endif
enum|enum
name|al_serdes_group
block|{
name|AL_SRDS_GRP_A
init|=
literal|0
block|,
name|AL_SRDS_GRP_B
block|,
name|AL_SRDS_GRP_C
block|,
name|AL_SRDS_GRP_D
block|,
name|AL_SRDS_NUM_HSSP_GROUPS
block|,
if|#
directive|if
name|CHECK_ALPINE_V2
name|AL_SRDS_GRP_E
init|=
name|AL_SRDS_NUM_HSSP_GROUPS
block|,
name|AL_SRDS_NUM_GROUPS
block|,
else|#
directive|else
name|AL_SRDS_NUM_GROUPS
init|=
name|AL_SRDS_NUM_HSSP_GROUPS
block|,
endif|#
directive|endif
block|}
enum|;
name|int
name|al_serdes_handle_grp_init
parameter_list|(
name|void
name|__iomem
modifier|*
name|serdes_regs_base
parameter_list|,
name|enum
name|al_serdes_group
name|grp
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
comment|/** @} end of SERDES group */
end_comment

end_unit

