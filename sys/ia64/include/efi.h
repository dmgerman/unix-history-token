begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_EFI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_EFI_H_
end_define

begin_comment
comment|/*  * Memory types.  */
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVED_MEMORY_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_LOADER_CODE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_LOADER_DATA
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_CODE
value|3
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_DATA
value|4
end_define

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_CODE
value|5
end_define

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_DATA
value|6
end_define

begin_define
define|#
directive|define
name|EFI_CONVENTIONAL_MEMORY
value|7
end_define

begin_define
define|#
directive|define
name|EFI_UNUSABLE_MEMORY
value|8
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_RECLAIM_MEMORY
value|9
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_MEMORY_NVS
value|10
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_MAPPED_IO
value|11
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_MAPPED_IO_PORT_SPACE
value|12
end_define

begin_define
define|#
directive|define
name|EFI_PAL_CODE
value|13
end_define

begin_struct
struct|struct
name|efi_memory_descriptor
block|{
name|u_int32_t
name|emd_type
decl_stmt|;
name|vm_offset_t
name|emd_physical_start
decl_stmt|;
name|vm_offset_t
name|emd_virtul_start
decl_stmt|;
name|u_int64_t
name|emd_number_of_pages
decl_stmt|;
name|u_int64_t
name|emd_attribute
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Values for emd_attribute.  */
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_UC
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WC
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WT
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WB
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_UCE
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WP
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_RP
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_XP
value|0x0000000000004000
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_RUNTIME
value|0x8000000000000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_EFI_H_ */
end_comment

end_unit

