begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdragonfly.h - OS specific for DragonFly BSD  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2003, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_MATH64
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

