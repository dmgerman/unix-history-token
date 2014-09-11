begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: achaiku.h - OS specific defines, etc. for Haiku (www.haiku-os.org)  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACHAIKU_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACHAIKU_H__
end_define

begin_include
include|#
directive|include
file|"acgcc.h"
end_include

begin_include
include|#
directive|include
file|<KernelExport.h>
end_include

begin_struct_decl
struct_decl|struct
name|mutex
struct_decl|;
end_struct_decl

begin_comment
comment|/* Host-dependent types and defines for user- and kernel-space ACPICA */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX_TYPE
value|ACPI_OSL_MUTEX
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX
value|struct mutex *
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* #define ACPI_THREAD_ID               thread_id */
end_comment

begin_define
define|#
directive|define
name|ACPI_SEMAPHORE
value|sem_id
end_define

begin_define
define|#
directive|define
name|ACPI_SPINLOCK
value|spinlock *
end_define

begin_define
define|#
directive|define
name|ACPI_CPU_FLAGS
value|cpu_status
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|int64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|uint64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|B_HAIKU_64_BIT
end_ifdef

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL_MODE
end_ifdef

begin_comment
comment|/* Host-dependent types and defines for in-kernel ACPICA */
end_comment

begin_comment
comment|/* ACPICA cache implementation is adequate. */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
value|__asm __volatile("wbinvd");
end_define

begin_comment
comment|/* Based on FreeBSD's due to lack of documentation */
end_comment

begin_function_decl
specifier|extern
name|int
name|AcpiOsAcquireGlobalLock
parameter_list|(
name|uint32
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|AcpiOsReleaseGlobalLock
parameter_list|(
name|uint32
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_ACQUIRE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
value|do {                \         (Acq) = AcpiOsAcquireGlobalLock(&((GLptr)->GlobalLock));    \ } while (0)
end_define

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
value|do {                \         (Acq) = AcpiOsReleaseGlobalLock(&((GLptr)->GlobalLock));    \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL_MODE */
end_comment

begin_comment
comment|/* Host-dependent types and defines for user-space ACPICA */
end_comment

begin_error
error|#
directive|error
literal|"We only support kernel mode ACPI atm."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL_MODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACHAIKU_H__ */
end_comment

end_unit

