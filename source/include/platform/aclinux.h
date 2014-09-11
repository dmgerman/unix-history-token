begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclinux.h - OS specific defines, etc. for Linux  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACLINUX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACLINUX_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/* ACPICA external files should not include ACPICA headers directly. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDING_ACPICA
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LINUX_ACPI_H
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Please don't include<acpi/acpi.h> directly, include<linux/acpi.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common (in-kernel/user-space) ACPICA configuration */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_define
define|#
directive|define
name|ACPI_USE_DO_WHILE_0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_INTTYPES
end_define

begin_comment
comment|/* Compile for reduced hardware mode only with this kernel config */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ACPI_REDUCED_HARDWARE_ONLY
end_ifdef

begin_define
define|#
directive|define
name|ACPI_REDUCED_HARDWARE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/ctype.h>
end_include

begin_include
include|#
directive|include
file|<linux/sched.h>
end_include

begin_include
include|#
directive|include
file|<linux/atomic.h>
end_include

begin_include
include|#
directive|include
file|<linux/math64.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EXPORT_ACPI_INTERFACES
end_ifdef

begin_include
include|#
directive|include
file|<linux/export.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ACPI
end_ifdef

begin_include
include|#
directive|include
file|<asm/acenv.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_ACPI
end_ifndef

begin_comment
comment|/* External globals for __KERNEL__, stubs is needed */
end_comment

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_comment
comment|/* Generating stubs for configurable ACPICA macros */
end_comment

begin_define
define|#
directive|define
name|ACPI_NO_MEM_ALLOCATIONS
end_define

begin_comment
comment|/* Generating stubs for configurable ACPICA functions */
end_comment

begin_define
define|#
directive|define
name|ACPI_NO_ERROR_MESSAGES
end_define

begin_undef
undef|#
directive|undef
name|ACPI_DEBUG_OUTPUT
end_undef

begin_comment
comment|/* External interface for __KERNEL__, stub is needed */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_NOT_CONFIGURED);}
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_OK);}
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_UINT32
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(0);}
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_RETURN_PTR
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(NULL);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_ACPI */
end_comment

begin_comment
comment|/* Host-dependent types and defines for in-kernel ACPICA */
end_comment

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|BITS_PER_LONG
end_define

begin_define
define|#
directive|define
name|ACPI_EXPORT_SYMBOL
parameter_list|(
name|symbol
parameter_list|)
value|EXPORT_SYMBOL(symbol);
end_define

begin_define
define|#
directive|define
name|strtoul
value|simple_strtoul
end_define

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|struct kmem_cache
end_define

begin_define
define|#
directive|define
name|ACPI_SPINLOCK
value|spinlock_t *
end_define

begin_define
define|#
directive|define
name|ACPI_CPU_FLAGS
value|unsigned long
end_define

begin_comment
comment|/* Use native linux version of AcpiOsAllocateZeroed */
end_comment

begin_define
define|#
directive|define
name|USE_NATIVE_ALLOCATE_ZEROED
end_define

begin_comment
comment|/*  * Overrides for in-kernel ACPICA  */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsInitialize
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTerminate
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAllocate
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAllocateZeroed
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsFree
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAcquireObject
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetThreadId
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCreateLock
end_define

begin_comment
comment|/*  * OSL interfaces used by debugger/disassembler  */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReadable
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWritable
end_define

begin_comment
comment|/*  * OSL interfaces used by utilities  */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsRedirectOutput
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetLine
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByName
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByIndex
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByAddress
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsOpenDirectory
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetNextFilename
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCloseDirectory
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__KERNEL__ */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* Define/disable kernel-specific declarators */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__init
end_ifndef

begin_define
define|#
directive|define
name|__init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Host-dependent types and defines for user-space ACPICA */
end_comment

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_PTHREAD_T
parameter_list|(
name|Pthread
parameter_list|)
value|((ACPI_THREAD_ID) (Pthread))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__PPC64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long
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

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long long
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cdecl
end_ifndef

begin_define
define|#
directive|define
name|__cdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/* Linux uses GCC */
end_comment

begin_include
include|#
directive|include
file|"acgcc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACLINUX_H__ */
end_comment

end_unit

