begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1990 William F. Jolitz  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)segments.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SEGMENTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SEGMENTS_H_
end_define

begin_comment
comment|/*  * AMD64 Segmentation Data Structures and definitions  */
end_comment

begin_include
include|#
directive|include
file|<x86/segments.h>
end_include

begin_comment
comment|/*  * System segment descriptors (128 bit wide)  */
end_comment

begin_struct
struct|struct
name|system_segment_descriptor
block|{
name|u_int64_t
name|sd_lolimit
range|:
literal|16
decl_stmt|;
comment|/* segment extent (lsb) */
name|u_int64_t
name|sd_lobase
range|:
literal|24
decl_stmt|;
comment|/* segment base address (lsb) */
name|u_int64_t
name|sd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|u_int64_t
name|sd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|u_int64_t
name|sd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|u_int64_t
name|sd_hilimit
range|:
literal|4
decl_stmt|;
comment|/* segment extent (msb) */
name|u_int64_t
name|sd_xx0
range|:
literal|3
decl_stmt|;
comment|/* unused */
name|u_int64_t
name|sd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
name|u_int64_t
name|sd_hibase
range|:
literal|40
name|__packed
decl_stmt|;
comment|/* segment base address  (msb) */
name|u_int64_t
name|sd_xx1
range|:
literal|8
decl_stmt|;
name|u_int64_t
name|sd_mbz
range|:
literal|5
decl_stmt|;
comment|/* MUST be zero */
name|u_int64_t
name|sd_xx2
range|:
literal|19
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Software definitions are in this convenient format,  * which are translated into inconvenient segment descriptors  * when needed to be used by the 386 hardware  */
end_comment

begin_struct
struct|struct
name|soft_segment_descriptor
block|{
name|unsigned
name|long
name|ssd_base
decl_stmt|;
comment|/* segment base address  */
name|unsigned
name|long
name|ssd_limit
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|long
name|ssd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|long
name|ssd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|long
name|ssd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|long
name|ssd_long
range|:
literal|1
decl_stmt|;
comment|/* long mode (for %cs) */
name|unsigned
name|long
name|ssd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|long
name|ssd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * region descriptors, used to load gdt/idt tables before segments yet exist.  */
end_comment

begin_struct
struct|struct
name|region_descriptor
block|{
name|uint64_t
name|rd_limit
range|:
literal|16
decl_stmt|;
comment|/* segment extent */
name|uint64_t
name|rd_base
range|:
literal|64
name|__packed
decl_stmt|;
comment|/* base address  */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|user_segment_descriptor
name|gdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|soft_segment_descriptor
name|gdt_segs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gate_descriptor
modifier|*
name|idt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|region_descriptor
name|r_gdt
decl_stmt|,
name|r_idt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lgdt
parameter_list|(
name|struct
name|region_descriptor
modifier|*
name|rdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdtossd
parameter_list|(
name|struct
name|user_segment_descriptor
modifier|*
name|sdp
parameter_list|,
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssdtosd
parameter_list|(
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|,
name|struct
name|user_segment_descriptor
modifier|*
name|sdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssdtosyssd
parameter_list|(
name|struct
name|soft_segment_descriptor
modifier|*
name|ssdp
parameter_list|,
name|struct
name|system_segment_descriptor
modifier|*
name|sdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_gdt_gsbase
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|uint32_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_gdt_fsbase
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|uint32_t
name|base
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
comment|/* !_MACHINE_SEGMENTS_H_ */
end_comment

end_unit

