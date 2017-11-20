begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989, 1990 William F. Jolitz  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)segments.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
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
comment|/*  * 386 Segmentation Data Structures and definitions  *	William F. Jolitz (william@ernie.berkeley.edu) 6/20/1989  */
end_comment

begin_include
include|#
directive|include
file|<x86/segments.h>
end_include

begin_comment
comment|/*  * Software definitions are in this convenient format,  * which are translated into inconvenient segment descriptors  * when needed to be used by the 386 hardware  */
end_comment

begin_struct
struct|struct
name|soft_segment_descriptor
block|{
name|unsigned
name|ssd_base
decl_stmt|;
comment|/* segment base address  */
name|unsigned
name|ssd_limit
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|ssd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|ssd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|ssd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|ssd_xx
range|:
literal|4
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_xx1
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|ssd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * region descriptors, used to load gdt/idt tables before segments yet exist.  */
end_comment

begin_struct
struct|struct
name|region_descriptor
block|{
name|unsigned
name|rd_limit
range|:
literal|16
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|rd_base
range|:
literal|32
name|__packed
decl_stmt|;
comment|/* base address  */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Segment Protection Exception code bits  */
end_comment

begin_define
define|#
directive|define
name|SEGEX_EXT
value|0x01
end_define

begin_comment
comment|/* recursive or externally induced */
end_comment

begin_define
define|#
directive|define
name|SEGEX_IDT
value|0x02
end_define

begin_comment
comment|/* interrupt descriptor table */
end_comment

begin_define
define|#
directive|define
name|SEGEX_TI
value|0x04
end_define

begin_comment
comment|/* local descriptor table */
end_comment

begin_comment
comment|/* other bits are affected descriptor index */
end_comment

begin_define
define|#
directive|define
name|SEGEX_IDX
parameter_list|(
name|s
parameter_list|)
value|(((s)>>3)&0x1fff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|_default_ldt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|descriptor
name|gdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|descriptor
name|ldt
index|[
name|NLDT
index|]
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
name|segment_descriptor
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
name|segment_descriptor
modifier|*
name|sdp
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

