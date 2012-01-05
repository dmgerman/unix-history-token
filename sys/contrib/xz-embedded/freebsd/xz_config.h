begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Aleksandr Rybalko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FREEBSD_XZ_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__FREEBSD_XZ_CONFIG_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<contrib/xz-embedded/linux/include/linux/xz.h>
end_include

begin_include
include|#
directive|include
file|"xz_malloc.h"
end_include

begin_define
define|#
directive|define
name|XZ_DEC_SINGLE
value|1
end_define

begin_define
define|#
directive|define
name|XZ_PREBOOT
value|1
end_define

begin_undef
undef|#
directive|undef
name|XZ_EXTERN
end_undef

begin_define
define|#
directive|define
name|XZ_EXTERN
value|extern
end_define

begin_undef
undef|#
directive|undef
name|STATIC
end_undef

begin_define
define|#
directive|define
name|STATIC
end_define

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_define
define|#
directive|define
name|INIT
end_define

begin_undef
undef|#
directive|undef
name|bool
end_undef

begin_undef
undef|#
directive|undef
name|true
end_undef

begin_undef
undef|#
directive|undef
name|false
end_undef

begin_define
define|#
directive|define
name|bool
value|int
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|xz_malloc(size)
end_define

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|ptr
parameter_list|)
value|xz_free(ptr)
end_define

begin_define
define|#
directive|define
name|vmalloc
parameter_list|(
name|size
parameter_list|)
value|xz_malloc(size)
end_define

begin_define
define|#
directive|define
name|vfree
parameter_list|(
name|ptr
parameter_list|)
value|xz_free(ptr)
end_define

begin_define
define|#
directive|define
name|memeq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|size
parameter_list|)
value|(memcmp((a), (b), (size)) == 0)
end_define

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|bzero((buf), (size))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MIN((x), (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|min((x), (y))
end_define

begin_define
define|#
directive|define
name|get_le32
parameter_list|(
name|ptr
parameter_list|)
value|le32toh(*(const uint32_t *)(ptr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FREEBSD_XZ_CONFIG_H__ */
end_comment

end_unit

