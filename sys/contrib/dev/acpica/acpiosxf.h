begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acpiosxf.h - All interfaces to the OS-dependent layer.  These  *                    interfaces must be implemented by the OS-dependent  *                    front-end to the ACPI subsystem.  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPIOSD_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPIOSD_H__
end_define

begin_include
include|#
directive|include
file|"acenv.h"
end_include

begin_include
include|#
directive|include
file|"actypes.h"
end_include

begin_comment
comment|/* Priorities for AcpiOsQueueForExecution */
end_comment

begin_define
define|#
directive|define
name|OSD_PRIORITY_GPE
value|1
end_define

begin_define
define|#
directive|define
name|OSD_PRIORITY_HIGH
value|2
end_define

begin_define
define|#
directive|define
name|OSD_PRIORITY_MED
value|3
end_define

begin_define
define|#
directive|define
name|OSD_PRIORITY_LO
value|4
end_define

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
comment|/*  * Types specific to the OS-dependent layer interfaces  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
modifier|*
name|OSD_HANDLER
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|OSD_EXECUTION_CALLBACK
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Initialization and shutdown primitives  (Optional)  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Synchronization primitives  */
end_comment

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
name|ACPI_HANDLE
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsDeleteSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWaitSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|,
name|UINT32
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsSignalSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Memory allocation and mapping  */
end_comment

begin_function_decl
name|void
modifier|*
name|AcpiOsAllocate
parameter_list|(
name|UINT32
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AcpiOsCallocate
parameter_list|(
name|UINT32
name|Size
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|ACPI_STATUS
name|AcpiOsMapMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|PhysicalAddress
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|void
modifier|*
modifier|*
name|LogicalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsUnmapMemory
parameter_list|(
name|void
modifier|*
name|LogicalAddress
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/*  * Interrupt handlers  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiOsInstallInterruptHandler
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|OSD_HANDLER
name|ServiceRoutine
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsRemoveInterruptHandler
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|OSD_HANDLER
name|ServiceRoutine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Scheduling  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiOsQueueForExecution
parameter_list|(
name|UINT32
name|Priority
parameter_list|,
name|OSD_EXECUTION_CALLBACK
name|Function
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsSleep
parameter_list|(
name|UINT32
name|Seconds
parameter_list|,
name|UINT32
name|Milliseconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsSleepUsec
parameter_list|(
name|UINT32
name|Microseconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform/Hardware independent I/O interfaces  */
end_comment

begin_function_decl
name|UINT8
name|AcpiOsIn8
parameter_list|(
name|ACPI_IO_ADDRESS
name|InPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AcpiOsIn16
parameter_list|(
name|ACPI_IO_ADDRESS
name|InPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiOsIn32
parameter_list|(
name|ACPI_IO_ADDRESS
name|InPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsOut8
parameter_list|(
name|ACPI_IO_ADDRESS
name|OutPort
parameter_list|,
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsOut16
parameter_list|(
name|ACPI_IO_ADDRESS
name|OutPort
parameter_list|,
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsOut32
parameter_list|(
name|ACPI_IO_ADDRESS
name|OutPort
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Platform/Hardware independent physical memory interfaces  */
end_comment

begin_function_decl
name|UINT8
name|AcpiOsMemIn8
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|InAddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AcpiOsMemIn16
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|InAddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiOsMemIn32
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|InAddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsMemOut8
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|OutAddr
parameter_list|,
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsMemOut16
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|OutAddr
parameter_list|,
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiOsMemOut32
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|OutAddr
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Standard access to PCI configuration space  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadPciCfgByte
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT8
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadPciCfgWord
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT16
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsReadPciCfgDword
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWritePciCfgByte
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWritePciCfgWord
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsWritePciCfgDword
parameter_list|(
name|UINT32
name|Bus
parameter_list|,
name|UINT32
name|DeviceFunction
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Miscellaneous  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiOsBreakpoint
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiOsReadable
parameter_list|(
name|void
modifier|*
name|Pointer
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiOsWritable
parameter_list|(
name|void
modifier|*
name|Pointer
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debug print routines  */
end_comment

begin_function_decl
name|INT32
name|AcpiOsPrintf
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|INT32
name|AcpiOsVprintf
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debug input  */
end_comment

begin_function_decl
name|UINT32
name|AcpiOsGetLine
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debug  */
end_comment

begin_function_decl
name|void
name|AcpiOsDbgAssert
parameter_list|(
name|void
modifier|*
name|FailedAssertion
parameter_list|,
name|void
modifier|*
name|FileName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Message
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACPIOSD_H__ */
end_comment

end_unit

