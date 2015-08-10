begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_common HAL Common Layer  *  @{  * @file   al_hal_types.h  *  * @brief  macros used by HALs and platform layer  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_TYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_TYPES_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_plat_services.h"
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
comment|/* Common defines */
if|#
directive|if
operator|(
operator|!
name|AL_TRUE
operator|)
operator|||
operator|(
name|AL_FALSE
operator|)
error|#
directive|error
literal|"AL_TRUE must be non zero and AL_FALSE must be zero"
endif|#
directive|endif
typedef|typedef
name|int
name|AL_RETURN
typedef|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NULL
argument_list|)
define|#
directive|define
name|NULL
value|(void *)0
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|likely
argument_list|)
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect(!!(x), 1))
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|(__builtin_expect(!!(x), 0))
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GNUC__
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__packed
argument_list|)
define|#
directive|define
name|__packed
value|__attribute__ ((packed))
endif|#
directive|endif
comment|/* packed and alinged types */
define|#
directive|define
name|__packed_a4
value|__attribute__ ((packed, aligned(4)))
define|#
directive|define
name|__packed_a8
value|__attribute__ ((packed, aligned(8)))
define|#
directive|define
name|__packed_a16
value|__attribute__ ((packed, aligned(16)))
else|#
directive|else
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__packed
argument_list|)
error|#
directive|error
literal|"__packed is not defined!!"
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__iomem
argument_list|)
define|#
directive|define
name|__iomem
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cache_aligned
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
define|#
directive|define
name|__cache_aligned
value|__attribute__ ((__aligned__(64)))
else|#
directive|else
define|#
directive|define
name|__cache_aligned
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INLINE
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
define|#
directive|define
name|INLINE
value|inline
else|#
directive|else
define|#
directive|define
name|INLINE
endif|#
directive|endif
endif|#
directive|endif
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

begin_comment
comment|/** @} end of Common group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPES_H__ */
end_comment

end_unit

