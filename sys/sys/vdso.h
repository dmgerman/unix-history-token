begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2012 Konstantin Belousov<kib@FreeBSD.ORG>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VDSO_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VDSO_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/vdso.h>
end_include

begin_struct
struct|struct
name|vdso_timehands
block|{
name|uint32_t
name|th_algo
decl_stmt|;
name|uint32_t
name|th_gen
decl_stmt|;
name|uint64_t
name|th_scale
decl_stmt|;
name|uint32_t
name|th_offset_count
decl_stmt|;
name|uint32_t
name|th_counter_mask
decl_stmt|;
name|struct
name|bintime
name|th_offset
decl_stmt|;
name|struct
name|bintime
name|th_boottime
decl_stmt|;
name|VDSO_TIMEHANDS_MD
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vdso_timekeep
block|{
name|uint32_t
name|tk_ver
decl_stmt|;
name|uint32_t
name|tk_enabled
decl_stmt|;
name|uint32_t
name|tk_current
decl_stmt|;
name|struct
name|vdso_timehands
name|tk_th
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VDSO_TK_CURRENT_BUSY
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|VDSO_TK_VER_1
value|0x1
end_define

begin_define
define|#
directive|define
name|VDSO_TK_VER_CURR
value|VDSO_TK_VER_1
end_define

begin_define
define|#
directive|define
name|VDSO_TH_ALGO_1
value|0x1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timezone
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|__vdso_clock_gettime
parameter_list|(
name|clockid_t
name|clock_id
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__vdso_gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|timezone
modifier|*
name|tz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|__vdso_gettc
parameter_list|(
specifier|const
name|struct
name|vdso_timehands
modifier|*
name|vdso_th
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__vdso_gettimekeep
parameter_list|(
name|struct
name|vdso_timekeep
modifier|*
modifier|*
name|tk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|timecounter
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|timekeep_push_vdso
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|tc_fill_vdso_timehands
parameter_list|(
name|struct
name|vdso_timehands
modifier|*
name|vdso_th
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The cpu_fill_vdso_timehands() function should fill MD-part of the  * struct vdso_timehands, which is both machine- and  * timecounter-depended. The return value should be 1 if fast  * userspace timecounter is enabled by hardware, and 0 otherwise. The  * global sysctl enable override is handled by machine-independed code  * after cpu_fill_vdso_timehands() call is made.  */
end_comment

begin_function_decl
name|uint32_t
name|cpu_fill_vdso_timehands
parameter_list|(
name|struct
name|vdso_timehands
modifier|*
name|vdso_th
parameter_list|,
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VDSO_TH_NUM
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_struct
struct|struct
name|bintime32
block|{
name|uint32_t
name|sec
decl_stmt|;
name|uint32_t
name|frac
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vdso_timehands32
block|{
name|uint32_t
name|th_algo
decl_stmt|;
name|uint32_t
name|th_gen
decl_stmt|;
name|uint32_t
name|th_scale
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|th_offset_count
decl_stmt|;
name|uint32_t
name|th_counter_mask
decl_stmt|;
name|struct
name|bintime32
name|th_offset
decl_stmt|;
name|struct
name|bintime32
name|th_boottime
decl_stmt|;
name|VDSO_TIMEHANDS_MD32
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vdso_timekeep32
block|{
name|uint32_t
name|tk_ver
decl_stmt|;
name|uint32_t
name|tk_enabled
decl_stmt|;
name|uint32_t
name|tk_current
decl_stmt|;
name|struct
name|vdso_timehands32
name|tk_th
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|uint32_t
name|tc_fill_vdso_timehands32
parameter_list|(
name|struct
name|vdso_timehands32
modifier|*
name|vdso_th32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|cpu_fill_vdso_timehands32
parameter_list|(
name|struct
name|vdso_timehands32
modifier|*
name|vdso_th32
parameter_list|,
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

