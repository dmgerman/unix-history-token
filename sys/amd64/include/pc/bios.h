begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Michael Smith  * Copyright (c) 1998 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PC_BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PC_BIOS_H_
end_define

begin_comment
comment|/*  * Int 15:E820 'SMAP' structure  */
end_comment

begin_define
define|#
directive|define
name|SMAP_SIG
value|0x534D4150
end_define

begin_comment
comment|/* 'SMAP' */
end_comment

begin_define
define|#
directive|define
name|SMAP_TYPE_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_RESERVED
value|2
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_ACPI_RECLAIM
value|3
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_ACPI_NVS
value|4
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_ACPI_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_DISABLED
value|6
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_PMEM
value|7
end_define

begin_define
define|#
directive|define
name|SMAP_TYPE_PRAM
value|12
end_define

begin_define
define|#
directive|define
name|SMAP_XATTR_ENABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SMAP_XATTR_NON_VOLATILE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SMAP_XATTR_MASK
value|(SMAP_XATTR_ENABLED | SMAP_XATTR_NON_VOLATILE)
end_define

begin_struct
struct|struct
name|bios_smap
block|{
name|u_int64_t
name|base
decl_stmt|;
name|u_int64_t
name|length
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure extended to include extended attribute field in ACPI 3.0. */
end_comment

begin_struct
struct|struct
name|bios_smap_xattr
block|{
name|u_int64_t
name|base
decl_stmt|;
name|u_int64_t
name|length
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
name|u_int32_t
name|xattr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * System Management BIOS  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_START
value|0xf0000
end_define

begin_define
define|#
directive|define
name|SMBIOS_STEP
value|0x10
end_define

begin_define
define|#
directive|define
name|SMBIOS_OFF
value|0
end_define

begin_define
define|#
directive|define
name|SMBIOS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SMBIOS_SIG
value|"_SM_"
end_define

begin_struct
struct|struct
name|smbios_eps
block|{
name|uint8_t
name|anchor_string
index|[
literal|4
index|]
decl_stmt|;
comment|/* '_SM_' */
name|uint8_t
name|checksum
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|major_version
decl_stmt|;
name|uint8_t
name|minor_version
decl_stmt|;
name|uint16_t
name|maximum_structure_size
decl_stmt|;
name|uint8_t
name|entry_point_revision
decl_stmt|;
name|uint8_t
name|formatted_area
index|[
literal|5
index|]
decl_stmt|;
name|uint8_t
name|intermediate_anchor_string
index|[
literal|5
index|]
decl_stmt|;
comment|/* '_DMI_' */
name|uint8_t
name|intermediate_checksum
decl_stmt|;
name|uint16_t
name|structure_table_length
decl_stmt|;
name|uint32_t
name|structure_table_address
decl_stmt|;
name|uint16_t
name|number_structures
decl_stmt|;
name|uint8_t
name|BCD_revision
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|smbios_structure_header
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint16_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|BIOS_PADDRTOVADDR
parameter_list|(
name|x
parameter_list|)
value|((x) + KERNBASE)
end_define

begin_define
define|#
directive|define
name|BIOS_VADDRTOPADDR
parameter_list|(
name|x
parameter_list|)
value|((x) - KERNBASE)
end_define

begin_struct
struct|struct
name|bios_oem_signature
block|{
name|char
modifier|*
name|anchor
decl_stmt|;
comment|/* search anchor string in BIOS memory */
name|size_t
name|offset
decl_stmt|;
comment|/* offset from anchor (may be negative) */
name|size_t
name|totlen
decl_stmt|;
comment|/* total length of BIOS string to copy */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|bios_oem_range
block|{
name|u_int
name|from
decl_stmt|;
comment|/* shouldn't be below 0xe0000 */
name|u_int
name|to
decl_stmt|;
comment|/* shouldn't be above 0xfffff */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|bios_oem
block|{
name|struct
name|bios_oem_range
name|range
decl_stmt|;
name|struct
name|bios_oem_signature
name|signature
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|int
name|bios_oem_strings
parameter_list|(
name|struct
name|bios_oem
modifier|*
name|oem
parameter_list|,
name|u_char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bios_sigsearch
parameter_list|(
name|uint32_t
name|start
parameter_list|,
name|u_char
modifier|*
name|sig
parameter_list|,
name|int
name|siglen
parameter_list|,
name|int
name|paralen
parameter_list|,
name|int
name|sigofs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bios_add_smap_entries
parameter_list|(
name|struct
name|bios_smap
modifier|*
name|smapbase
parameter_list|,
name|u_int32_t
name|smapsize
parameter_list|,
name|vm_paddr_t
modifier|*
name|physmap
parameter_list|,
name|int
modifier|*
name|physmap_idx
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

begin_comment
comment|/* _MACHINE_PC_BIOS_H_ */
end_comment

end_unit

