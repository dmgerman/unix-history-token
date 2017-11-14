begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This is the header file for conveniency wrapper routines (API glue)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_API_GLUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_API_GLUE_H_
end_define

begin_include
include|#
directive|include
file|"api_public.h"
end_include

begin_comment
comment|/*  * Mask used to align the start address for API signature search to 1MiB  */
end_comment

begin_define
define|#
directive|define
name|API_SIG_SEARCH_MASK
value|~0x000fffff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_comment
comment|/*  * On MIPS, U-Boot passes us a hint address, which is very close to the end of  * RAM (less than 1MiB), so searching for the API signature within more than  * that leads to exception.  */
end_comment

begin_define
define|#
directive|define
name|API_SIG_SEARCH_LEN
value|0x00100000
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Search for the API signature within 3MiB of the 1MiB-aligned address that  * U-Boot has hinted us.  */
end_comment

begin_define
define|#
directive|define
name|API_SIG_SEARCH_LEN
value|0x00300000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
modifier|*
name|syscall_ptr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|api_parse_cmdline_sig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|struct
name|api_signature
modifier|*
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|api_search_sig
parameter_list|(
name|struct
name|api_signature
modifier|*
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UB_MAX_MR
value|16
end_define

begin_comment
comment|/* max mem regions number */
end_comment

begin_define
define|#
directive|define
name|UB_MAX_DEV
value|6
end_define

begin_comment
comment|/* max devices number */
end_comment

begin_comment
comment|/*  * The ub_ library calls are part of the application, not U-Boot code!  They  * are front-end wrappers that are used by the consumer application: they  * prepare arguments for particular syscall and jump to the low level  * syscall()  */
end_comment

begin_comment
comment|/* console */
end_comment

begin_function_decl
name|int
name|ub_getc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_tstc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_putc
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_puts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* system */
end_comment

begin_function_decl
name|void
name|ub_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sys_info
modifier|*
name|ub_get_sys_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* time */
end_comment

begin_function_decl
name|void
name|ub_udelay
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|ub_get_timer
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* env vars */
end_comment

begin_function_decl
name|char
modifier|*
name|ub_env_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_env_set
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ub_env_enum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* devices */
end_comment

begin_function_decl
name|int
name|ub_dev_enum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_dev_open
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_dev_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_dev_read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|lbasize_t
parameter_list|,
name|lbastart_t
parameter_list|,
name|lbasize_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_dev_send
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ub_dev_recv
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|device_info
modifier|*
name|ub_dev_get
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_dump_di
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ub_dump_si
parameter_list|(
name|struct
name|sys_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ub_mem_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ub_stor_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _API_GLUE_H_ */
end_comment

end_unit

