begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acnetbsd.h - OS specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACNETBSD_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACNETBSD_H__
end_define

begin_comment
comment|/* NetBSD uses GCC */
end_comment

begin_include
include|#
directive|include
file|"acgcc.h"
end_include

begin_define
define|#
directive|define
name|ACPI_UINTPTR_T
value|uintptr_t
end_define

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_PTHREAD_T
parameter_list|(
name|x
parameter_list|)
value|((ACPI_THREAD_ID) ACPI_TO_INTEGER (x))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL_OPT
end_ifdef

begin_include
include|#
directive|include
file|"opt_acpi.h"
end_include

begin_comment
comment|/* collect build-time options here */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL_OPT */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<machine/acpi_func.h>
end_include

begin_define
define|#
directive|define
name|asm
value|__asm
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

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

begin_define
define|#
directive|define
name|ACPI_DBG_TRACK_ALLOCATIONS
end_define

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
value|0
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
name|ACPI_DISASSEMBLER
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUG */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined(_KERNEL) || defined(_STANDALONE) */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* Not building kernel code, so use libc */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_define
define|#
directive|define
name|__cli
parameter_list|()
end_define

begin_define
define|#
directive|define
name|__sti
parameter_list|()
end_define

begin_define
define|#
directive|define
name|__cdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) || defined(_STANDALONE) */
end_comment

begin_comment
comment|/* Always use NetBSD code over our local versions */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
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

begin_comment
comment|/* __ACNETBSD_H__ */
end_comment

end_unit

