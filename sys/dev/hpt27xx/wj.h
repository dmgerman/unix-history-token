begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dev/hpt27xx/hpt27xx_config.h>
end_include

begin_comment
comment|/*  * NVRAM write journaling interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WJ_H_
end_ifndef

begin_define
define|#
directive|define
name|_WJ_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUPPORT_BBU
argument_list|)
operator|||
name|defined
argument_list|(
name|SUPPORT_NVRAM
argument_list|)
end_if

begin_function_decl
name|void
name|wj_init
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|void
modifier|*
name|nvram_addr
parameter_list|,
name|HPT_U32
name|nvram_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|wj_add_entry
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|PVDEV
name|vd
parameter_list|,
name|HPT_LBA
name|lba
parameter_list|,
name|HPT_U16
name|sectors
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|wj_get_entry
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|PVDEV
modifier|*
name|vd_p
parameter_list|,
name|HPT_LBA
modifier|*
name|lba_p
parameter_list|,
name|HPT_U16
modifier|*
name|sectors_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wj_del_entry
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wj_del_vd
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|PVDEV
name|vd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wj_sync_stamp
parameter_list|(
name|PVBUS
name|vbus
parameter_list|,
name|PVDEV
name|vd
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|wj_add_entry
parameter_list|(
name|vbus
parameter_list|,
name|vd
parameter_list|,
name|lba
parameter_list|,
name|sectors
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|wj_get_entry
parameter_list|(
name|vbus
parameter_list|,
name|vd_p
parameter_list|,
name|lba_p
parameter_list|,
name|sectors_p
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|wj_del_entry
parameter_list|(
name|vbus
parameter_list|,
name|handle
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|wj_del_vd
parameter_list|(
name|vbus
parameter_list|,
name|vd
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|wj_sync_stamp
parameter_list|(
name|vbus
parameter_list|,
name|vd
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

