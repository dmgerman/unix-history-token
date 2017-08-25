begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acenv.h - Host and compiler configuration  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
comment|/* Common application configuration. All single threaded except for AcpiExec. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_ASL_COMPILER
operator|)
operator|||
expr|\
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
operator|||
expr|\
operator|(
name|defined
name|ACPI_EFI_HELLO
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
name|ACPI_32BIT_PHYSICAL_ADDRESS
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
value|1
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
comment|/* AcpiDump configuration. Native mapping used if provided by the host */
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
comment|/* Linkable ACPICA library. Two versions, one with full debug. */
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

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
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
name|ACPI_USE_LOCAL_CACHE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Common debug/disassembler support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_FULL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_DEBUG_OUTPUT
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUGGER
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_DISASSEMBLER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [Begin] no source code translation */
end_comment

begin_comment
comment|/******************************************************************************  *  * Host configuration files. The compiler configuration files are included  * first.  *  *****************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/platform/acgcc.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acmsvc.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acintel.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|__DragonFly__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acdragonfly.h"
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
name|__HAIKU__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"achaiku.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__QNX__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acqnx.h"
end_include

begin_comment
comment|/*  * EFI applications can be built with -nostdlib, in this case, it must be  * included after including all other host environmental definitions, in  * order to override the definitions.  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AED_EFI
argument_list|)
operator|||
name|defined
argument_list|(
name|_GNU_EFI
argument_list|)
operator|||
name|defined
argument_list|(
name|_EDK2_EFI
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"acefi.h"
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
comment|/* Use ordered initialization if compiler doesn't support designated. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_STRUCT_INIT
end_ifndef

begin_define
define|#
directive|define
name|ACPI_STRUCT_INIT
parameter_list|(
name|field
parameter_list|,
name|value
parameter_list|)
value|value
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACPI_APPLICATION
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_EXEC_APP
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_MULTI_THREADED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGGER_THREADING
value|DEBUGGER_SINGLE_THREADED
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
comment|/*  * ACPI_USE_SYSTEM_CLIBRARY - Define this if linking to an actual C library.  *      Otherwise, local versions of string/memory functions will be used.  * ACPI_USE_STANDARD_HEADERS - Define this if linking to a C library and  *      the standard header files may be used. Defining this implies that  *      ACPI_USE_SYSTEM_CLIBRARY has been defined.  *  * The ACPICA subsystem only uses low level C library functions that do not  * call operating system services and may therefore be inlined in the code.  *  * It may be necessary to tailor these include files to the target  * generation environment.  */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_APPLICATION
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_LIBRARY
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_STANDARD_HEADERS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INIT_FUNCTION
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INIT_FUNCTION
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
comment|/* __ACENV_H__ */
end_comment

end_unit

