begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and SMP safe.  */
end_comment

begin_function_decl
name|void
name|atomic_set_8
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_8
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_8
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_8
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_16
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_16
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_16
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_16
parameter_list|(
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_32
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_32
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_32
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_32
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_64
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_64
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_64
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_64
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|atomic_set_char
value|atomic_set_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
value|atomic_clear_8
end_define

begin_define
define|#
directive|define
name|atomic_add_char
value|atomic_add_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
value|atomic_subtract_8
end_define

begin_define
define|#
directive|define
name|atomic_set_short
value|atomic_set_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
value|atomic_clear_16
end_define

begin_define
define|#
directive|define
name|atomic_add_short
value|atomic_add_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
value|atomic_subtract_16
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_add_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

