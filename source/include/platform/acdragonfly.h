begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdragonfly.h - OS specific for DragonFly BSD  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACDRAGONFLY_H_
end_ifndef

begin_define
define|#
directive|define
name|__ACDRAGONFLY_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
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

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ACPI_UINTPTR_T
value|uintptr_t
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|int64_t
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|uint64_t
end_define

begin_define
define|#
directive|define
name|ACPI_USE_DO_WHILE_0
end_define

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"opt_acpi.h"
end_include

begin_include
include|#
directive|include
file|<sys/ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/acpica_machdep.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_comment
comment|/* enable debug output */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGER_THREADING
end_ifdef

begin_undef
undef|#
directive|undef
name|DEBUGGER_THREADING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUGGER_THREADING */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_SINGLE_THREADED
end_define

begin_comment
comment|/* integrated with DDB */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DDB */
end_comment

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_CACHE
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReleaseObject
end_define

begin_define
define|#
directive|define
name|AcpiOsReleaseObject
parameter_list|(
name|Cache
parameter_list|,
name|Object
parameter_list|)
define|\
value|_AcpiOsReleaseObject((Cache), (Object), __func__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_LOCKS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAcquireLock
end_define

begin_define
define|#
directive|define
name|AcpiOsAcquireLock
parameter_list|(
name|Handle
parameter_list|)
define|\
value|_AcpiOsAcquireLock((Handle), __func__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_MEMMAP
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsMapMemory
end_define

begin_define
define|#
directive|define
name|AcpiOsMapMemory
parameter_list|(
name|Where
parameter_list|,
name|Length
parameter_list|)
define|\
value|_AcpiOsMapMemory((Where), (Length), __func__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsUnmapMemory
end_define

begin_define
define|#
directive|define
name|AcpiOsUnmapMemory
parameter_list|(
name|LogicalAddress
parameter_list|,
name|Size
parameter_list|)
define|\
value|_AcpiOsUnmapMemory((LogicalAddress), (Size), __func__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX TBI */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWaitEventsComplete
end_define

begin_define
define|#
directive|define
name|AcpiOsWaitEventsComplete
parameter_list|()
end_define

begin_define
define|#
directive|define
name|USE_NATIVE_ALLOCATE_ZEROED
end_define

begin_define
define|#
directive|define
name|ACPI_SPINLOCK
value|struct acpi_spinlock *
end_define

begin_struct_decl
struct_decl|struct
name|acpi_spinlock
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|struct acpicache
end_define

begin_struct_decl
struct_decl|struct
name|acpicache
struct_decl|;
end_struct_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_PTHREAD_T
parameter_list|(
name|pthread
parameter_list|)
value|((ACPI_THREAD_ID) ACPI_TO_INTEGER (pthread))
end_define

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
end_define

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
comment|/* __ACDRAGONFLY_H_ */
end_comment

end_unit

