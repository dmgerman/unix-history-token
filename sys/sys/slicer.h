begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FLASH_SLICER_H_
end_ifndef

begin_define
define|#
directive|define
name|_FLASH_SLICER_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|FLASH_SLICES_MAX_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_MAX_NAME_LEN
value|(32 + 1)
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_FLAG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_FLAG_RO
value|1
end_define

begin_comment
comment|/* Read only */
end_comment

begin_define
define|#
directive|define
name|FLASH_SLICES_FMT
value|"%ss.%s"
end_define

begin_struct
struct|struct
name|flash_slice
block|{
name|off_t
name|base
decl_stmt|;
name|off_t
name|size
decl_stmt|;
specifier|const
name|char
modifier|*
name|label
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|flash_slicer_t
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|provider
parameter_list|,
name|struct
name|flash_slice
modifier|*
name|slices
parameter_list|,
name|int
modifier|*
name|slices_num
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|FLASH_SLICES_TYPE_NAND
value|0
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_TYPE_CFI
value|1
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_TYPE_SPI
value|2
end_define

begin_define
define|#
directive|define
name|FLASH_SLICES_TYPE_MMC
value|3
end_define

begin_comment
comment|/* Use NULL for deregistering a slicer */
end_comment

begin_function_decl
name|void
name|flash_register_slicer
parameter_list|(
name|flash_slicer_t
name|slicer
parameter_list|,
name|u_int
name|type
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FLASH_SLICER_H_ */
end_comment

end_unit

