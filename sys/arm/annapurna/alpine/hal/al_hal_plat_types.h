begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_services Platform Services API  *  @{  * @file   plat_api/sample/al_hal_plat_types.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PLAT_TYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__PLAT_TYPES_H__
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
comment|/* Basic data types */
typedef|typedef
name|int
name|al_bool
typedef|;
comment|/** boolean */
define|#
directive|define
name|AL_TRUE
value|1
define|#
directive|define
name|AL_FALSE
value|0
comment|/* define types */
ifndef|#
directive|ifndef
name|AL_HAVE_TYPES
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
comment|/** unsigned 8 bits */
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
comment|/** unsigned 16 bits */
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
comment|/** unsigned 32 bits */
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
comment|/** unsigned 64 bits */
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
comment|/** signed 8 bits */
typedef|typedef
name|short
name|int
name|int16_t
typedef|;
comment|/** signed 16 bits */
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
comment|/** signed 32 bits */
comment|/** An unsigned int that is guaranteed to be the same size as a pointer */
comment|/** C99 standard */
typedef|typedef
name|unsigned
name|long
name|uintptr_t
typedef|;
endif|#
directive|endif
comment|/** in LPAE mode, the address address is 40 bit, we extend it to 64 bit */
typedef|typedef
name|uint64_t
name|al_phys_addr_t
typedef|;
comment|/** this defines the cpu endiancess. */
define|#
directive|define
name|PLAT_ARCH_IS_LITTLE
parameter_list|()
value|AL_TRUE
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
comment|/** @} end of Platform Services API group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PLAT_TYPES_H__ */
end_comment

end_unit

