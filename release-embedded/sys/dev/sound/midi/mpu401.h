begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Mathew Kanner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPU401_H
end_ifndef

begin_define
define|#
directive|define
name|MPU401_H
end_define

begin_struct_decl
struct_decl|struct
name|mpu401
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|mpu401_intr_t
parameter_list|(
name|struct
name|mpu401
modifier|*
name|_obj
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|mpu401
modifier|*
name|mpu401_init
parameter_list|(
name|kobj_class_t
name|_cls
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|driver_intr_t
modifier|*
name|_softintr
parameter_list|,
name|mpu401_intr_t
modifier|*
modifier|*
name|_cb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mpu401_uninit
parameter_list|(
name|struct
name|mpu401
modifier|*
name|_obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

