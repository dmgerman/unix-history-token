begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclinux.h - OS specific defines, etc. for Linux  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
comment|/* Kernel specific ACPICA configuration */
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ACPI_DEBUGGER
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_ACPI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_MUTEX_DEBUG
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

begin_define
define|#
directive|define
name|ACPI_INIT_FUNCTION
value|__init
end_define

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
name|ACPI_USE_NATIVE_MATH64
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

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsInitializeDebugger
end_define

begin_define
define|#
directive|define
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTerminateDebugger
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

begin_define
define|#
directive|define
name|ACPI_MSG_ERROR
value|KERN_ERR "ACPI Error: "
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_EXCEPTION
value|KERN_ERR "ACPI Exception: "
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_WARNING
value|KERN_WARNING "ACPI Warning: "
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_INFO
value|KERN_INFO "ACPI: "
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_BIOS_ERROR
value|KERN_ERR "ACPI BIOS Error (bug): "
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_BIOS_WARNING
value|KERN_WARNING "ACPI BIOS Warning (bug): "
end_define

begin_comment
comment|/*  * Linux wants to use designated initializers for function pointer structs.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRUCT_INIT
parameter_list|(
name|field
parameter_list|,
name|value
parameter_list|)
value|.field = value
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__KERNEL__ */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_STANDARD_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|__iomem
end_ifndef

begin_define
define|#
directive|define
name|__iomem
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
operator|||
expr|\
name|defined
argument_list|(
name|__s390x__
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

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_MATH64
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACLINUX_H__ */
end_comment

end_unit

