begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acpiosxf.h - All interfaces to the OS Services Layer (OSL). These  *                    interfaces must be implemented by OSL to interface the  *                    ACPI components to the host operating system.  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPIOSXF_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPIOSXF_H__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/platform/acenv.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actypes.h>
end_include

begin_comment
comment|/* Types for AcpiOsExecute */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OSL_GLOBAL_LOCK_HANDLER
block|,
name|OSL_NOTIFY_HANDLER
block|,
name|OSL_GPE_HANDLER
block|,
name|OSL_DEBUGGER_MAIN_THREAD
block|,
name|OSL_DEBUGGER_EXEC_THREAD
block|,
name|OSL_EC_POLL_HANDLER
block|,
name|OSL_EC_BURST_HANDLER
block|}
name|ACPI_EXECUTE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_NO_UNIT_LIMIT
value|((UINT32) -1)
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX_SEM
value|1
end_define

begin_comment
comment|/* Functions for AcpiOsSignal */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIGNAL_FATAL
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SIGNAL_BREAKPOINT
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_signal_fatal_info
block|{
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|Code
decl_stmt|;
name|UINT32
name|Argument
decl_stmt|;
block|}
name|ACPI_SIGNAL_FATAL_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * OSL Initialization and shutdown primitives  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsInitialize
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTerminate
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ACPI Table interfaces  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetRootPointer
end_ifndef

begin_function_decl
name|ACPI_PHYSICAL_ADDRESS
name|AcpiOsGetRootPointer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsPredefinedOverride
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsPredefinedOverride
parameter_list|(
specifier|const
name|ACPI_PREDEFINED_NAMES
modifier|*
name|InitVal
parameter_list|,
name|ACPI_STRING
modifier|*
name|NewVal
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTableOverride
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsTableOverride
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|ExistingTable
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|NewTable
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsPhysicalTableOverride
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsPhysicalTableOverride
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|ExistingTable
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|NewAddress
parameter_list|,
name|UINT32
modifier|*
name|NewTableLength
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Spinlock primitives  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCreateLock
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsCreateLock
parameter_list|(
name|ACPI_SPINLOCK
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsDeleteLock
end_ifndef

begin_function_decl
name|void
name|AcpiOsDeleteLock
parameter_list|(
name|ACPI_SPINLOCK
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAcquireLock
end_ifndef

begin_function_decl
name|ACPI_CPU_FLAGS
name|AcpiOsAcquireLock
parameter_list|(
name|ACPI_SPINLOCK
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReleaseLock
end_ifndef

begin_function_decl
name|void
name|AcpiOsReleaseLock
parameter_list|(
name|ACPI_SPINLOCK
name|Handle
parameter_list|,
name|ACPI_CPU_FLAGS
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Semaphore primitives  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCreateSemaphore
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsCreateSemaphore
parameter_list|(
name|UINT32
name|MaxUnits
parameter_list|,
name|UINT32
name|InitialUnits
parameter_list|,
name|ACPI_SEMAPHORE
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsDeleteSemaphore
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsDeleteSemaphore
parameter_list|(
name|ACPI_SEMAPHORE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWaitSemaphore
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWaitSemaphore
parameter_list|(
name|ACPI_SEMAPHORE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsSignalSemaphore
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsSignalSemaphore
parameter_list|(
name|ACPI_SEMAPHORE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mutex primitives. May be configured to use semaphores instead via  * ACPI_MUTEX_TYPE (see platform/acenv.h)  */
end_comment

begin_if
if|#
directive|if
operator|(
name|ACPI_MUTEX_TYPE
operator|!=
name|ACPI_BINARY_SEMAPHORE
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCreateMutex
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsCreateMutex
parameter_list|(
name|ACPI_MUTEX
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsDeleteMutex
end_ifndef

begin_function_decl
name|void
name|AcpiOsDeleteMutex
parameter_list|(
name|ACPI_MUTEX
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAcquireMutex
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsAcquireMutex
parameter_list|(
name|ACPI_MUTEX
name|Handle
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReleaseMutex
end_ifndef

begin_function_decl
name|void
name|AcpiOsReleaseMutex
parameter_list|(
name|ACPI_MUTEX
name|Handle
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
comment|/*  * Memory allocation and mapping  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAllocate
end_ifndef

begin_function_decl
name|void
modifier|*
name|AcpiOsAllocate
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAllocateZeroed
end_ifndef

begin_function_decl
name|void
modifier|*
name|AcpiOsAllocateZeroed
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsFree
end_ifndef

begin_function_decl
name|void
name|AcpiOsFree
parameter_list|(
name|void
modifier|*
name|Memory
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsMapMemory
end_ifndef

begin_function_decl
name|void
modifier|*
name|AcpiOsMapMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Where
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsUnmapMemory
end_ifndef

begin_function_decl
name|void
name|AcpiOsUnmapMemory
parameter_list|(
name|void
modifier|*
name|LogicalAddress
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetPhysicalAddress
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsGetPhysicalAddress
parameter_list|(
name|void
modifier|*
name|LogicalAddress
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|PhysicalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Memory/Object Cache  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCreateCache
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsCreateCache
parameter_list|(
name|char
modifier|*
name|CacheName
parameter_list|,
name|UINT16
name|ObjectSize
parameter_list|,
name|UINT16
name|MaxDepth
parameter_list|,
name|ACPI_CACHE_T
modifier|*
modifier|*
name|ReturnCache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsDeleteCache
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsDeleteCache
parameter_list|(
name|ACPI_CACHE_T
modifier|*
name|Cache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsPurgeCache
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsPurgeCache
parameter_list|(
name|ACPI_CACHE_T
modifier|*
name|Cache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsAcquireObject
end_ifndef

begin_function_decl
name|void
modifier|*
name|AcpiOsAcquireObject
parameter_list|(
name|ACPI_CACHE_T
modifier|*
name|Cache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReleaseObject
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReleaseObject
parameter_list|(
name|ACPI_CACHE_T
modifier|*
name|Cache
parameter_list|,
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interrupt handlers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsInstallInterruptHandler
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsInstallInterruptHandler
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|ACPI_OSD_HANDLER
name|ServiceRoutine
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsRemoveInterruptHandler
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsRemoveInterruptHandler
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|ACPI_OSD_HANDLER
name|ServiceRoutine
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Threads and Scheduling  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetThreadId
end_ifndef

begin_function_decl
name|ACPI_THREAD_ID
name|AcpiOsGetThreadId
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsExecute
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsExecute
parameter_list|(
name|ACPI_EXECUTE_TYPE
name|Type
parameter_list|,
name|ACPI_OSD_EXEC_CALLBACK
name|Function
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWaitEventsComplete
end_ifndef

begin_function_decl
name|void
name|AcpiOsWaitEventsComplete
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsSleep
end_ifndef

begin_function_decl
name|void
name|AcpiOsSleep
parameter_list|(
name|UINT64
name|Milliseconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsStall
end_ifndef

begin_function_decl
name|void
name|AcpiOsStall
parameter_list|(
name|UINT32
name|Microseconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Platform and hardware-independent I/O interfaces  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReadPort
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadPort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWritePort
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWritePort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Platform and hardware-independent physical memory interfaces  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReadMemory
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWriteMemory
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWriteMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT64
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Platform and hardware-independent PCI configuration space access  * Note: Can't use "Register" as a parameter, changed to "Reg" --  * certain compilers complain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReadPciConfiguration
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadPciConfiguration
parameter_list|(
name|ACPI_PCI_ID
modifier|*
name|PciId
parameter_list|,
name|UINT32
name|Reg
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWritePciConfiguration
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWritePciConfiguration
parameter_list|(
name|ACPI_PCI_ID
modifier|*
name|PciId
parameter_list|,
name|UINT32
name|Reg
parameter_list|,
name|UINT64
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsReadable
end_ifndef

begin_function_decl
name|BOOLEAN
name|AcpiOsReadable
parameter_list|(
name|void
modifier|*
name|Pointer
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWritable
end_ifndef

begin_function_decl
name|BOOLEAN
name|AcpiOsWritable
parameter_list|(
name|void
modifier|*
name|Pointer
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTimer
end_ifndef

begin_function_decl
name|UINT64
name|AcpiOsGetTimer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsSignal
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsSignal
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsEnterSleep
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsEnterSleep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|,
name|UINT32
name|RegaValue
parameter_list|,
name|UINT32
name|RegbValue
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debug print routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsPrintf
end_ifndef

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiOsPrintf
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsVprintf
end_ifndef

begin_function_decl
name|void
name|AcpiOsVprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsRedirectOutput
end_ifndef

begin_function_decl
name|void
name|AcpiOsRedirectOutput
parameter_list|(
name|void
modifier|*
name|Destination
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Debug IO  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetLine
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsGetLine
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|,
name|UINT32
modifier|*
name|BytesRead
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsInitializeDebugger
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsInitializeDebugger
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTerminateDebugger
end_ifndef

begin_function_decl
name|void
name|AcpiOsTerminateDebugger
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsWaitCommandReady
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWaitCommandReady
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsNotifyCommandComplete
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsNotifyCommandComplete
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsTracePoint
end_ifndef

begin_function_decl
name|void
name|AcpiOsTracePoint
parameter_list|(
name|ACPI_TRACE_EVENT_TYPE
name|Type
parameter_list|,
name|BOOLEAN
name|Begin
parameter_list|,
name|UINT8
modifier|*
name|Aml
parameter_list|,
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Obtain ACPI table(s)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByName
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsGetTableByName
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|,
name|UINT32
name|Instance
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByIndex
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsGetTableByIndex
parameter_list|(
name|UINT32
name|Index
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|,
name|UINT32
modifier|*
name|Instance
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetTableByAddress
end_ifndef

begin_function_decl
name|ACPI_STATUS
name|AcpiOsGetTableByAddress
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Directory manipulation  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsOpenDirectory
end_ifndef

begin_function_decl
name|void
modifier|*
name|AcpiOsOpenDirectory
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|,
name|char
modifier|*
name|WildcardSpec
parameter_list|,
name|char
name|RequestedFileType
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RequesteFileType values */
end_comment

begin_define
define|#
directive|define
name|REQUEST_FILE_ONLY
value|0
end_define

begin_define
define|#
directive|define
name|REQUEST_DIR_ONLY
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsGetNextFilename
end_ifndef

begin_function_decl
name|char
modifier|*
name|AcpiOsGetNextFilename
parameter_list|(
name|void
modifier|*
name|DirHandle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_ALTERNATE_PROTOTYPE_AcpiOsCloseDirectory
end_ifndef

begin_function_decl
name|void
name|AcpiOsCloseDirectory
parameter_list|(
name|void
modifier|*
name|DirHandle
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
comment|/* __ACPIOSXF_H__ */
end_comment

end_unit

