begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_RTAS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_RTAS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_comment
comment|/*  * RTAS functions are defined by 32-bit integer tokens. These vary from  * system to system, and can be looked up from their standardized names  * using rtas_token_lookup(). If RTAS is not available, rtas_token_lookup()  * and rtas_call_method() return -1; this can be checked in advance using  * rtas_exists(). Otherwise, rtas_call_method() returns one of the RTAS  * status codes from the bottom of this file.  */
end_comment

begin_function_decl
name|int
name|rtas_exists
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtas_call_method
parameter_list|(
name|cell_t
name|token
parameter_list|,
name|int
name|nargs
parameter_list|,
name|int
name|nreturns
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cell_t
name|rtas_token_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* RTAS Status Codes: see CHRP or PAPR specification */
end_comment

begin_define
define|#
directive|define
name|RTAS_OK
value|0
end_define

begin_define
define|#
directive|define
name|RTAS_HW_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|RTAS_BUSY
value|-2
end_define

begin_define
define|#
directive|define
name|RTAS_PARAM_ERROR
value|-3
end_define

begin_define
define|#
directive|define
name|RTAS_STATE_CHANGE
value|-7
end_define

begin_define
define|#
directive|define
name|RTAS_VENDOR_BEGIN
value|9000
end_define

begin_define
define|#
directive|define
name|RTAS_EXTENDED_DELAY
value|9900
end_define

begin_define
define|#
directive|define
name|RTAS_ISOLATION_ERROR
value|-9000
end_define

begin_define
define|#
directive|define
name|RTAS_VENDOR_ERROR_BEGIN
value|-9004
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_RTAS_H_ */
end_comment

end_unit

