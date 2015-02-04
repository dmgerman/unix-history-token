begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014, Bryan Venteicher<bryanv@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X86_PVCLOCK
end_ifndef

begin_define
define|#
directive|define
name|X86_PVCLOCK
end_define

begin_struct
struct|struct
name|pvclock_vcpu_time_info
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|pad0
decl_stmt|;
name|uint64_t
name|tsc_timestamp
decl_stmt|;
name|uint64_t
name|system_time
decl_stmt|;
name|uint32_t
name|tsc_to_system_mul
decl_stmt|;
name|int8_t
name|tsc_shift
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PVCLOCK_FLAG_TSC_STABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PVCLOCK_FLAG_GUEST_PASUED
value|0x02
end_define

begin_struct
struct|struct
name|pvclock_wall_clock
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|sec
decl_stmt|;
name|uint32_t
name|nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pvclock_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|pvclock_get_last_cycles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|pvclock_get_timecount
parameter_list|(
name|struct
name|pvclock_vcpu_time_info
modifier|*
name|ti
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pvclock_get_wallclock
parameter_list|(
name|struct
name|pvclock_wall_clock
modifier|*
name|wc
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

