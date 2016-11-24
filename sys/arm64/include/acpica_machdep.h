begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mitsuru IWASAKI  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/******************************************************************************  *  * Name: acpica_machdep.h - arch-specific defines, etc.  *       $Revision$  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPICA_MACHDEP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPICA_MACHDEP_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/_bus.h>
end_include

begin_comment
comment|/* Only use the reduced hardware model */
end_comment

begin_define
define|#
directive|define
name|ACPI_REDUCED_HARDWARE
value|1
end_define

begin_comment
comment|/* Section 5.2.10.1: global lock acquire/release functions */
end_comment

begin_function_decl
name|int
name|acpi_acquire_global_lock
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_release_global_lock
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|acpi_map_table
parameter_list|(
name|vm_paddr_t
name|pa
parameter_list|,
specifier|const
name|char
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|acpi_unmap_table
parameter_list|(
name|void
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|acpi_find_table
parameter_list|(
specifier|const
name|char
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|acpi_generic_address
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|acpi_map_addr
parameter_list|(
name|struct
name|acpi_generic_address
modifier|*
parameter_list|,
name|bus_space_tag_t
modifier|*
parameter_list|,
name|bus_space_handle_t
modifier|*
parameter_list|,
name|bus_size_t
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
comment|/* __ACPICA_MACHDEP_H__ */
end_comment

end_unit

