begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FDT_H_
end_define

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<x86/bus.h>
end_include

begin_comment
comment|/* Max interrupt number. */
end_comment

begin_define
define|#
directive|define
name|FDT_INTR_MAX
value|NUM_IO_INTS
end_define

begin_comment
comment|/* Map phandle/intpin pair to global IRQ number */
end_comment

begin_define
define|#
directive|define
name|FDT_MAP_IRQ
parameter_list|(
name|node
parameter_list|,
name|pin
parameter_list|)
define|\
value|(panic("%s: FDT_MAP_IRQ(%#x, %#x)", __func__, node, pin), -1)
end_define

begin_comment
comment|/* Bus space tag. XXX we only support I/O port space this way. */
end_comment

begin_define
define|#
directive|define
name|fdtbus_bs_tag
value|X86_BUS_SPACE_IO
end_define

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
name|__BEGIN_DECLS
name|int
name|x86_init_fdt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FDT_H_ */
end_comment

end_unit

