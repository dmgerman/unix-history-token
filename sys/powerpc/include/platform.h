begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996 Wolfgang Solfrank.  * Copyright (C) 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: powerpc.h,v 1.3 2000/06/01 00:49:59 matt Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PLATFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PLATFORM_H_
end_define

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_struct
struct|struct
name|mem_region
block|{
name|vm_offset_t
name|mr_start
decl_stmt|;
name|vm_size_t
name|mr_size
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|mem_regions
parameter_list|(
name|struct
name|mem_region
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|mem_region
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|platform_real_maxaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|platform_timebase_freq
parameter_list|(
name|struct
name|cpuref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_smp_first_cpu
parameter_list|(
name|struct
name|cpuref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_smp_next_cpu
parameter_list|(
name|struct
name|cpuref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_smp_get_bsp
parameter_list|(
name|struct
name|cpuref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_smp_start_cpu
parameter_list|(
name|struct
name|pcpu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_smp_ap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|installed_platform
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_probe_and_attach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_sleep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PLATFORM_H_ */
end_comment

end_unit

