begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acefi.h - OS specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACEFI_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACEFI_H__
end_define

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|<efistdarg.h>
end_include

begin_include
include|#
directive|include
file|<efilib.h>
end_include

begin_comment
comment|/* AED EFI definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
end_if

begin_comment
comment|/* _int64 works for both IA32 and IA64 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|__int64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned __int64
end_define

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
end_define

begin_comment
comment|/* warn C4142: redefinition of type */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4142
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU EFI definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
end_if

begin_comment
comment|/* Using GCC for GNU EFI */
end_comment

begin_include
include|#
directive|include
file|"acgcc.h"
end_include

begin_undef
undef|#
directive|undef
name|ACPI_USE_SYSTEM_CLIBRARY
end_undef

begin_undef
undef|#
directive|undef
name|ACPI_USE_STANDARD_HEADERS
end_undef

begin_undef
undef|#
directive|undef
name|ACPI_USE_NATIVE_DIVIDE
end_undef

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_INTTYPES
end_define

begin_define
define|#
directive|define
name|ACPI_FILE
value|SIMPLE_TEXT_OUTPUT_INTERFACE *
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_OUT
value|ST->ConOut
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_ERR
value|ST->ConOut
end_define

begin_comment
comment|/*  * Math helpers  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DIV_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|d32
parameter_list|,
name|q32
parameter_list|,
name|r32
parameter_list|)
define|\
value|do {                                             \         UINT64 __n = ((UINT64) n_hi)<< 32 | (n_lo); \         (q32) = DivU64x32 ((__n), (d32),&(r32));    \     } while (0)
end_define

begin_define
define|#
directive|define
name|ACPI_SHIFT_RIGHT_64
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|)
define|\
value|do {                                \         (n_lo)>>= 1;                   \         (n_lo) |= (((n_hi)& 1)<< 31); \         (n_hi)>>= 1;                   \     } while (0)
end_define

begin_comment
comment|/*  * EFI specific prototypes  */
end_comment

begin_function_decl
name|EFI_STATUS
name|efi_main
parameter_list|(
name|EFI_HANDLE
name|Image
parameter_list|,
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acpi_main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
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
comment|/* __ACEFI_H__ */
end_comment

end_unit

