begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Doug Rabson  * Copyright (c) 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPIDUMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPIDUMP_H_
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acconfig.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/actbl1.h>
end_include

begin_comment
comment|/* GAS address space ID constants. */
end_comment

begin_define
define|#
directive|define
name|ACPI_GAS_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_IO
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_PCI
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_EMBEDDED
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_SMBUS
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_CMOS
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_PCIBAR
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_DATATABLE
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_GAS_FIXED
value|0x7f
end_define

begin_comment
comment|/* Subfields in the HPET Id member. */
end_comment

begin_define
define|#
directive|define
name|ACPI_HPET_ID_HARDWARE_REV_ID
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|ACPI_HPET_ID_COMPARATORS
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|ACPI_HPET_ID_COUNT_SIZE_CAP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACPI_HPET_ID_LEGACY_CAPABLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ACPI_HPET_ID_PCI_VENDOR_ID
value|0xffff0000
end_define

begin_comment
comment|/* Find and map the RSD PTR structure and return it for parsing */
end_comment

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|sdt_load_devmem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Load the DSDT from a previous save file.  Note that other tables are  * not saved (i.e. FADT)  */
end_comment

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|dsdt_load_file
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Save the DSDT to a file */
end_comment

begin_function_decl
name|void
name|dsdt_save_file
parameter_list|(
name|char
modifier|*
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print out as many fixed tables as possible, given the RSD PTR */
end_comment

begin_function_decl
name|void
name|sdt_print_all
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disassemble the AML in the DSDT */
end_comment

begin_function_decl
name|void
name|aml_disassemble
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines for accessing tables in physical memory */
end_comment

begin_function_decl
name|ACPI_TABLE_RSDP
modifier|*
name|acpi_find_rsd_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|acpi_map_physical
parameter_list|(
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|sdt_from_rsdt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|dsdt_from_fadt
parameter_list|(
name|ACPI_TABLE_FADT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_checksum
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Command line flags */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ACPIDUMP_H_ */
end_comment

end_unit

