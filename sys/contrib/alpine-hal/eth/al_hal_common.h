begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_common HAL Common Layer  * Includes all common header files used by HAL  *  @{  * @file   al_hal_common.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_COMMON_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_COMMON_H__
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

begin_include
include|#
directive|include
file|"al_hal_types.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_reg_utils.h"
end_include

begin_comment
comment|/* Get the maximal value out of two typed values */
end_comment

begin_define
define|#
directive|define
name|al_max_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({		\ 	type __max1 = (x);			\ 	type __max2 = (y);			\ 	__max1> __max2 ? __max1 : __max2; })
end_define

begin_comment
comment|/* Get the minimal value out of two typed values */
end_comment

begin_define
define|#
directive|define
name|al_min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|({		\ 	type __min1 = (x);			\ 	type __min2 = (y);			\ 	__min1< __min2 ? __min1 : __min2; })
end_define

begin_comment
comment|/* Get the number of elements in an array */
end_comment

begin_define
define|#
directive|define
name|AL_ARR_SIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof((arr)[0]))
end_define

begin_comment
comment|/** @} end of Common group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_COMMON_H__ */
end_comment

end_unit

