begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acenv.h - Host and compiler configuration  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACENV_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACENV_H__
end_define

begin_comment
comment|/*  * Environment configuration. The purpose of this file is to interface ACPICA  * to the local environment. This includes compiler-specific, OS-specific,  * and machine-specific configuration.  */
end_comment

begin_comment
comment|/* Types for ACPI_MUTEX_TYPE */
end_comment

begin_define
define|#
directive|define
name|ACPI_BINARY_SEMAPHORE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_OSL_MUTEX
value|1
end_define

begin_comment
comment|/* Types for DEBUGGER_THREADING */
end_comment

begin_define
define|#
directive|define
name|DEBUGGER_SINGLE_THREADED
value|0
end_define

begin_define
define|#
directive|define
name|DEBUGGER_MULTI_THREADED
value|1
end_define

begin_comment
comment|/******************************************************************************  *  * Configuration for ACPI tools and utilities  *  *****************************************************************************/
end_comment

begin_comment
comment|/* iASL configuration */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_define
define|#
directive|define
name|ACPI_CONSTANT_EVAL_ONLY
end_define

begin_define
define|#
directive|define
name|ACPI_LARGE_NAMESPACE_NODE
end_define

begin_define
define|#
directive|define
name|ACPI_DATA_TABLE_DISASSEMBLY
end_define

begin_define
define|#
directive|define
name|ACPI_SINGLE_THREADED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiExec configuration. Multithreaded with full AML debugger */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_EXEC_APP
end_ifdef

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_FULL_DEBUG
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX_DEBUG
end_define

begin_define
define|#
directive|define
name|ACPI_DBG_TRACK_ALLOCATIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * AcpiBin/AcpiDump/AcpiHelp/AcpiNames/AcpiSrc/AcpiXtract/Example configuration.  * All single threaded.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_BIN_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_DUMP_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_HELP_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_NAMES_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_SRC_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_XTRACT_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_EXAMPLE_APP
operator|)
end_if

begin_define
define|#
directive|define
name|ACPI_APPLICATION
end_define

begin_define
define|#
directive|define
name|ACPI_SINGLE_THREADED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiHelp configuration. Error messages disabled. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_HELP_APP
end_ifdef

begin_define
define|#
directive|define
name|ACPI_NO_ERROR_MESSAGES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiNames configuration. Debug output enabled. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NAMES_APP
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiExec/AcpiNames/Example configuration. Native RSDP used. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_EXEC_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_EXAMPLE_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_NAMES_APP
operator|)
end_if

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_RSDP_POINTER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiDump configuration. Native mapping used if provied by OSPMs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DUMP_APP
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_MEMORY_MAPPING
end_define

begin_define
define|#
directive|define
name|USE_NATIVE_ALLOCATE_ZEROED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AcpiNames/Example configuration. Hardware disabled */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_EXAMPLE_APP
operator|)
operator|||
expr|\
operator|(
name|defined
name|ACPI_NAMES_APP
operator|)
end_if

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

begin_comment
comment|/* Linkable ACPICA library */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_LIBRARY
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common for all ACPICA applications */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common debug support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_FULL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [Begin] no source code translation */
end_comment

begin_comment
comment|/******************************************************************************  *  * Host configuration files. The compiler configuration files are included  * by the host files.  *  *****************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"aclinux.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_APPLE
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acmacosx.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/platform/acfreebsd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acnetbsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acsolaris.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MODESTO
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acmodesto.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NETWARE
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acnetware.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_CYGWIN
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"accygwin.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acwin.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WIN64
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acwin64.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WRS_LIB_BUILD
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acvxworks.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OS2__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acos2.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acefi.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acefi.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"achaiku.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Unknown environment */
end_comment

begin_error
error|#
directive|error
error|Unknown target environment
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_comment
comment|/******************************************************************************  *  * Setup defaults for the required symbols that were not defined in one of  * the host/compiler files above.  *  *****************************************************************************/
end_comment

begin_comment
comment|/* 64-bit data types */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DEPENDENT_INT64
end_ifndef

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DEPENDENT_UINT64
end_ifndef

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Type of mutex supported by host. Default is binary semaphores. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MUTEX_TYPE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MUTEX_TYPE
value|ACPI_BINARY_SEMAPHORE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Global Lock acquire/release */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_ACQUIRE_GLOBAL_LOCK
end_ifndef

begin_define
define|#
directive|define
name|ACPI_ACQUIRE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acquired
parameter_list|)
value|Acquired = 1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_RELEASE_GLOBAL_LOCK
end_ifndef

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Pending
parameter_list|)
value|Pending = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Flush CPU cache - used when going to sleep. Wbinvd or similar. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_FLUSH_CPU_CACHE
end_ifndef

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
comment|/* "inline" keywords - configurable since inline is not standardized */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INLINE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Configurable calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SYSTEM_XFACE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXTERNAL_XFACE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INTERNAL_XFACE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INTERNAL_VAR_XFACE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debugger threading model  * Use single threaded if the entire subsystem is contained in an application  * Use multiple threaded when the subsystem is running in the kernel.  *  * By default the model is single threaded if ACPI_APPLICATION is set,  * multi-threaded if ACPI_APPLICATION is not set.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUGGER_THREADING
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_SINGLE_THREADED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_MULTI_THREADED
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
comment|/* !DEBUGGER_THREADING */
end_comment

begin_comment
comment|/******************************************************************************  *  * C library configuration  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * ACPI_USE_SYSTEM_CLIBRARY - Define this if linking to an actual C library.  *      Otherwise, local versions of string/memory functions will be used.  * ACPI_USE_STANDARD_HEADERS - Define this if linking to a C library and  *      the standard header files may be used.  *  * The ACPICA subsystem only uses low level C library functions that do not call  * operating system services and may therefore be inlined in the code.  *  * It may be necessary to tailor these include files to the target  * generation environment.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_SYSTEM_CLIBRARY
end_ifdef

begin_comment
comment|/* Use the standard C library headers. We want to keep these to a minimum. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_STANDARD_HEADERS
end_ifdef

begin_comment
comment|/* Use the standard headers from the standard locations */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_STANDARD_HEADERS */
end_comment

begin_comment
comment|/* We will be linking to the standard Clib functions */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRSTR
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strstr((s1), (s2))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCHR
parameter_list|(
name|s1
parameter_list|,
name|c
parameter_list|)
value|strchr((s1), (c))
end_define

begin_define
define|#
directive|define
name|ACPI_STRLEN
parameter_list|(
name|s
parameter_list|)
value|(ACPI_SIZE) strlen((s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) strcpy((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) strncpy((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncmp((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|strcmp((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) strcat((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strncat((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRTOUL
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|strtoul((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp((const char *)(s1), (const char *)(s2), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) memcpy((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMSET
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) memset((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_TOUPPER
parameter_list|(
name|i
parameter_list|)
value|toupper((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_TOLOWER
parameter_list|(
name|i
parameter_list|)
value|tolower((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_XDIGIT
parameter_list|(
name|i
parameter_list|)
value|isxdigit((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_DIGIT
parameter_list|(
name|i
parameter_list|)
value|isdigit((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_SPACE
parameter_list|(
name|i
parameter_list|)
value|isspace((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_UPPER
parameter_list|(
name|i
parameter_list|)
value|isupper((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_PRINT
parameter_list|(
name|i
parameter_list|)
value|isprint((int) (i))
end_define

begin_define
define|#
directive|define
name|ACPI_IS_ALPHA
parameter_list|(
name|i
parameter_list|)
value|isalpha((int) (i))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/******************************************************************************  *  * Not using native C library, use local implementations  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Use local definitions of C library macros and functions. These function  * implementations may not be as efficient as an inline or assembly code  * implementation provided by a native C library, but they are functionally  * equivalent.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|va_arg
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_VALIST
end_ifndef

begin_define
define|#
directive|define
name|_VALIST
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VALIST */
end_comment

begin_comment
comment|/* Storage alignment properties */
end_comment

begin_define
define|#
directive|define
name|_AUPBND
value|(sizeof (ACPI_NATIVE_INT) - 1)
end_define

begin_define
define|#
directive|define
name|_ADNBND
value|(sizeof (ACPI_NATIVE_INT) - 1)
end_define

begin_comment
comment|/* Variable argument list macro definitions */
end_comment

begin_define
define|#
directive|define
name|_Bnd
parameter_list|(
name|X
parameter_list|,
name|bnd
parameter_list|)
value|(((sizeof (X)) + (bnd))& (~(bnd)))
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|T
parameter_list|)
value|(*(T *)(((ap) += (_Bnd (T, _AUPBND))) - (_Bnd (T,_ADNBND))))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|(ap = (va_list) NULL)
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|A
parameter_list|)
value|(void) ((ap) = (((char *)&(A)) + (_Bnd (A,_AUPBND))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* va_arg */
end_comment

begin_comment
comment|/* Use the local (ACPICA) definitions of the clib functions */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRSTR
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|AcpiUtStrstr ((s1), (s2))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCHR
parameter_list|(
name|s1
parameter_list|,
name|c
parameter_list|)
value|AcpiUtStrchr ((s1), (c))
end_define

begin_define
define|#
directive|define
name|ACPI_STRLEN
parameter_list|(
name|s
parameter_list|)
value|(ACPI_SIZE) AcpiUtStrlen ((s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) AcpiUtStrcpy ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtStrncpy ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrncmp ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCMP
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|AcpiUtStrcmp ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|(void) AcpiUtStrcat ((d), (s))
end_define

begin_define
define|#
directive|define
name|ACPI_STRNCAT
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrncat ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_STRTOUL
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|AcpiUtStrtoul ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|AcpiUtMemcmp((const char *)(s1), (const char *)(s2), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMCPY
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtMemcpy ((d), (s), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_MEMSET
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|(void) AcpiUtMemset ((d), (v), (ACPI_SIZE)(n))
end_define

begin_define
define|#
directive|define
name|ACPI_TOUPPER
parameter_list|(
name|c
parameter_list|)
value|AcpiUtToUpper ((int) (c))
end_define

begin_define
define|#
directive|define
name|ACPI_TOLOWER
parameter_list|(
name|c
parameter_list|)
value|AcpiUtToLower ((int) (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_CLIBRARY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_FILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|ACPI_FILE
value|FILE *
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_OUT
value|stdout
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_ERR
value|stderr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_FILE
value|void *
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_OUT
value|NULL
end_define

begin_define
define|#
directive|define
name|ACPI_FILE_ERR
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_APPLICATION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_FILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACENV_H__ */
end_comment

end_unit

