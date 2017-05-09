begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIBFDT_ENV_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBFDT_ENV_H
end_define

begin_comment
comment|/*  * libfdt - Flat Device Tree manipulation  * Copyright (C) 2006 David Gibson, IBM Corporation.  * Copyright 2012 Kim Phillips, Freescale Semiconductor.  *  * libfdt is dual licensed: you can use it either under the terms of  * the GPL, or the BSD license, at your option.  *  *  a) This library is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This library is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  *     You should have received a copy of the GNU General Public  *     License along with this library; if not, write to the Free  *     Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,  *     MA 02110-1301 USA  *  * Alternatively,  *  *  b) Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *     1. Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *     2. Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND  *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,  *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__CHECKER__
end_ifdef

begin_define
define|#
directive|define
name|__force
value|__attribute__((force))
end_define

begin_define
define|#
directive|define
name|__bitwise
value|__attribute__((bitwise))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__force
end_define

begin_define
define|#
directive|define
name|__bitwise
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint16_t
name|__bitwise
name|fdt16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__bitwise
name|fdt32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__bitwise
name|fdt64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXTRACT_BYTE
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|((unsigned long long)((uint8_t *)&x)[n])
end_define

begin_define
define|#
directive|define
name|CPU_TO_FDT16
parameter_list|(
name|x
parameter_list|)
value|((EXTRACT_BYTE(x, 0)<< 8) | EXTRACT_BYTE(x, 1))
end_define

begin_define
define|#
directive|define
name|CPU_TO_FDT32
parameter_list|(
name|x
parameter_list|)
value|((EXTRACT_BYTE(x, 0)<< 24) | (EXTRACT_BYTE(x, 1)<< 16) | \ 			 (EXTRACT_BYTE(x, 2)<< 8) | EXTRACT_BYTE(x, 3))
end_define

begin_define
define|#
directive|define
name|CPU_TO_FDT64
parameter_list|(
name|x
parameter_list|)
value|((EXTRACT_BYTE(x, 0)<< 56) | (EXTRACT_BYTE(x, 1)<< 48) | \ 			 (EXTRACT_BYTE(x, 2)<< 40) | (EXTRACT_BYTE(x, 3)<< 32) | \ 			 (EXTRACT_BYTE(x, 4)<< 24) | (EXTRACT_BYTE(x, 5)<< 16) | \ 			 (EXTRACT_BYTE(x, 6)<< 8) | EXTRACT_BYTE(x, 7))
end_define

begin_function
specifier|static
specifier|inline
name|uint16_t
name|fdt16_to_cpu
parameter_list|(
name|fdt16_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|uint16_t
operator|)
name|CPU_TO_FDT16
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|fdt16_t
name|cpu_to_fdt16
parameter_list|(
name|uint16_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|fdt16_t
operator|)
name|CPU_TO_FDT16
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|fdt32_to_cpu
parameter_list|(
name|fdt32_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|uint32_t
operator|)
name|CPU_TO_FDT32
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|fdt32_t
name|cpu_to_fdt32
parameter_list|(
name|uint32_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|fdt32_t
operator|)
name|CPU_TO_FDT32
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|fdt64_to_cpu
parameter_list|(
name|fdt64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|uint64_t
operator|)
name|CPU_TO_FDT64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|fdt64_t
name|cpu_to_fdt64
parameter_list|(
name|uint64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|__force
name|fdt64_t
operator|)
name|CPU_TO_FDT64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|CPU_TO_FDT64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TO_FDT32
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TO_FDT16
end_undef

begin_undef
undef|#
directive|undef
name|EXTRACT_BYTE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBFDT_ENV_H */
end_comment

end_unit

