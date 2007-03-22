begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: osunixxf - UNIX OSL interfaces  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * These interfaces are required in order to compile the ASL compiler under  * Linux.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/amlcode.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acparser.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acdebug.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_OS_SERVICES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"osunixxf"
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|AcpiGbl_DebugFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|AcpiGbl_OutputFile
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ACPI_PHYSICAL_ADDRESS
name|AeLocalGetRootPointer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsInitialize, AcpiOsTerminate  *  * PARAMETERS:  None  *  * RETURN:      Status  *  * DESCRIPTION: Init and terminate.  Nothing to do.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
block|{
name|AcpiGbl_OutputFile
operator|=
name|stdout
expr_stmt|;
return|return
name|AE_OK
return|;
block|}
end_function

begin_function
name|ACPI_STATUS
name|AcpiOsTerminate
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetRootPointer  *  * PARAMETERS:  None  *  * RETURN:      RSDP physical address  *  * DESCRIPTION: Gets the root pointer (RSDP)  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_PHYSICAL_ADDRESS
name|AcpiOsGetRootPointer
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|AeLocalGetRootPointer
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsPredefinedOverride  *  * PARAMETERS:  InitVal     - Initial value of the predefined object  *              NewVal      - The new value for the object  *  * RETURN:      Status, pointer to value.  Null pointer returned if not  *              overriding.  *  * DESCRIPTION: Allow the OS to override predefined names  *  *****************************************************************************/
end_comment

begin_function
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
block|{
if|if
condition|(
operator|!
name|InitVal
operator|||
operator|!
name|NewVal
condition|)
block|{
return|return
operator|(
name|AE_BAD_PARAMETER
operator|)
return|;
block|}
operator|*
name|NewVal
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsTableOverride  *  * PARAMETERS:  ExistingTable   - Header of current table (probably firmware)  *              NewTable        - Where an entire new table is returned.  *  * RETURN:      Status, pointer to new table.  Null pointer returned if no  *              table is available to override  *  * DESCRIPTION: Return a different version of a table if one is available  *  *****************************************************************************/
end_comment

begin_function
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
block|{
if|if
condition|(
operator|!
name|ExistingTable
operator|||
operator|!
name|NewTable
condition|)
block|{
return|return
operator|(
name|AE_BAD_PARAMETER
operator|)
return|;
block|}
operator|*
name|NewTable
operator|=
name|NULL
expr_stmt|;
ifdef|#
directive|ifdef
name|ACPI_EXEC_APP
comment|/* This code exercises the table override mechanism in the core */
if|if
condition|(
name|ACPI_COMPARE_NAME
argument_list|(
name|ExistingTable
operator|->
name|Signature
argument_list|,
name|ACPI_SIG_DSDT
argument_list|)
condition|)
block|{
comment|/* override DSDT with itself */
operator|*
name|NewTable
operator|=
name|AcpiGbl_DbTablePtr
expr_stmt|;
block|}
return|return
operator|(
name|AE_OK
operator|)
return|;
else|#
directive|else
return|return
name|AE_NO_ACPI_TABLES
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsReadable  *  * PARAMETERS:  Pointer             - Area to be verified  *              Length              - Size of area  *  * RETURN:      TRUE if readable for entire length  *  * DESCRIPTION: Verify that a pointer is valid for reading  *  *****************************************************************************/
end_comment

begin_function
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
block|{
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsWritable  *  * PARAMETERS:  Pointer             - Area to be verified  *              Length              - Size of area  *  * RETURN:      TRUE if writable for entire length  *  * DESCRIPTION: Verify that a pointer is valid for writing  *  *****************************************************************************/
end_comment

begin_function
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
block|{
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsRedirectOutput  *  * PARAMETERS:  Destination         - An open file handle/pointer  *  * RETURN:      None  *  * DESCRIPTION: Causes redirect of AcpiOsPrintf and AcpiOsVprintf  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsRedirectOutput
parameter_list|(
name|void
modifier|*
name|Destination
parameter_list|)
block|{
name|AcpiGbl_OutputFile
operator|=
name|Destination
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsPrintf  *  * PARAMETERS:  fmt, ...            Standard printf format  *  * RETURN:      None  *  * DESCRIPTION: Formatted output  *  *****************************************************************************/
end_comment

begin_function
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiOsPrintf
parameter_list|(
specifier|const
name|char
modifier|*
name|Fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|Args
decl_stmt|;
name|va_start
argument_list|(
name|Args
argument_list|,
name|Fmt
argument_list|)
expr_stmt|;
name|AcpiOsVprintf
argument_list|(
name|Fmt
argument_list|,
name|Args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|Args
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsVprintf  *  * PARAMETERS:  fmt                 Standard printf format  *              args                Argument list  *  * RETURN:      None  *  * DESCRIPTION: Formatted output with argument list pointer  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsVprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|Fmt
parameter_list|,
name|va_list
name|Args
parameter_list|)
block|{
name|INT32
name|Count
init|=
literal|0
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|Flags
operator|=
name|AcpiGbl_DbOutputFlags
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|ACPI_DB_REDIRECTABLE_OUTPUT
condition|)
block|{
comment|/* Output is directable to either a file (if open) or the console */
if|if
condition|(
name|AcpiGbl_DebugFile
condition|)
block|{
comment|/* Output file is open, send the output there */
name|Count
operator|=
name|vfprintf
argument_list|(
name|AcpiGbl_DebugFile
argument_list|,
name|Fmt
argument_list|,
name|Args
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* No redirection, send output to console (once only!) */
name|Flags
operator||=
name|ACPI_DB_CONSOLE_OUTPUT
expr_stmt|;
block|}
block|}
if|if
condition|(
name|Flags
operator|&
name|ACPI_DB_CONSOLE_OUTPUT
condition|)
block|{
name|Count
operator|=
name|vfprintf
argument_list|(
name|AcpiGbl_OutputFile
argument_list|,
name|Fmt
argument_list|,
name|Args
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetLine  *  * PARAMETERS:  fmt                 Standard printf format  *              args                Argument list  *  * RETURN:      Actual bytes read  *  * DESCRIPTION: Formatted input with argument list pointer  *  *****************************************************************************/
end_comment

begin_function
name|UINT32
name|AcpiOsGetLine
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
block|{
name|UINT8
name|Temp
decl_stmt|;
name|UINT32
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
condition|;
name|i
operator|++
control|)
block|{
name|scanf
argument_list|(
literal|"%1c"
argument_list|,
operator|&
name|Temp
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Temp
operator|||
name|Temp
operator|==
literal|'\n'
condition|)
block|{
break|break;
block|}
name|Buffer
index|[
name|i
index|]
operator|=
name|Temp
expr_stmt|;
block|}
comment|/* Null terminate the buffer */
name|Buffer
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
comment|/* Return the number of bytes in the string */
return|return
operator|(
name|i
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsMapMemory  *  * PARAMETERS:  where               Physical address of memory to be mapped  *              length              How much memory to map  *  * RETURN:      Pointer to mapped memory.  Null on error.  *  * DESCRIPTION: Map physical memory into caller's address space  *  *****************************************************************************/
end_comment

begin_function
name|void
modifier|*
name|AcpiOsMapMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|where
parameter_list|,
name|ACPI_SIZE
name|length
parameter_list|)
block|{
return|return
operator|(
name|ACPI_TO_POINTER
argument_list|(
operator|(
name|ACPI_NATIVE_UINT
operator|)
name|where
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsUnmapMemory  *  * PARAMETERS:  where               Logical address of memory to be unmapped  *              length              How much memory to unmap  *  * RETURN:      None.  *  * DESCRIPTION: Delete a previously created mapping.  Where and Length must  *              correspond to a previous mapping exactly.  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsUnmapMemory
parameter_list|(
name|void
modifier|*
name|where
parameter_list|,
name|ACPI_SIZE
name|length
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsAllocate  *  * PARAMETERS:  Size                Amount to allocate, in bytes  *  * RETURN:      Pointer to the new allocation.  Null on error.  *  * DESCRIPTION: Allocate memory.  Algorithm is dependent on the OS.  *  *****************************************************************************/
end_comment

begin_function
name|void
modifier|*
name|AcpiOsAllocate
parameter_list|(
name|ACPI_SIZE
name|size
parameter_list|)
block|{
name|void
modifier|*
name|Mem
decl_stmt|;
name|Mem
operator|=
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
name|size
argument_list|)
expr_stmt|;
return|return
name|Mem
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsFree  *  * PARAMETERS:  mem                 Pointer to previously allocated memory  *  * RETURN:      None.  *  * DESCRIPTION: Free memory allocated via AcpiOsAllocate  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsFree
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|)
block|{
name|free
argument_list|(
name|mem
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsCreateSemaphore  *  * PARAMETERS:  InitialUnits        - Units to be assigned to the new semaphore  *              OutHandle           - Where a handle will be returned  *  * RETURN:      Status  *  * DESCRIPTION: Create an OS semaphore  *  *****************************************************************************/
end_comment

begin_function
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
block|{
operator|*
name|OutHandle
operator|=
operator|(
name|ACPI_HANDLE
operator|)
literal|1
expr_stmt|;
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsDeleteSemaphore  *  * PARAMETERS:  Handle              - Handle returned by AcpiOsCreateSemaphore  *  * RETURN:      Status  *  * DESCRIPTION: Delete an OS semaphore  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsDeleteSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Handle
condition|)
block|{
return|return
name|AE_BAD_PARAMETER
return|;
block|}
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsWaitSemaphore  *  * PARAMETERS:  Handle              - Handle returned by AcpiOsCreateSemaphore  *              Units               - How many units to wait for  *              Timeout             - How long to wait  *  * RETURN:      Status  *  * DESCRIPTION: Wait for units  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsWaitSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsSignalSemaphore  *  * PARAMETERS:  Handle              - Handle returned by AcpiOsCreateSemaphore  *              Units               - Number of units to send  *  * RETURN:      Status  *  * DESCRIPTION: Send units  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsSignalSemaphore
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|Units
parameter_list|)
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_function
name|ACPI_STATUS
name|AcpiOsCreateLock
parameter_list|(
name|ACPI_SPINLOCK
modifier|*
name|OutHandle
parameter_list|)
block|{
return|return
operator|(
name|AcpiOsCreateSemaphore
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|OutHandle
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|AcpiOsDeleteLock
parameter_list|(
name|ACPI_SPINLOCK
name|Handle
parameter_list|)
block|{
name|AcpiOsDeleteSemaphore
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|ACPI_CPU_FLAGS
name|AcpiOsAcquireLock
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|)
block|{
name|AcpiOsWaitSemaphore
argument_list|(
name|Handle
argument_list|,
literal|1
argument_list|,
literal|0xFFFF
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|AcpiOsReleaseLock
parameter_list|(
name|ACPI_SPINLOCK
name|Handle
parameter_list|,
name|ACPI_CPU_FLAGS
name|Flags
parameter_list|)
block|{
name|AcpiOsSignalSemaphore
argument_list|(
name|Handle
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsInstallInterruptHandler  *  * PARAMETERS:  InterruptNumber     Level handler should respond to.  *              Isr                 Address of the ACPI interrupt handler  *              ExceptPtr           Where status is returned  *  * RETURN:      Handle to the newly installed handler.  *  * DESCRIPTION: Install an interrupt handler.  Used to install the ACPI  *              OS-independent handler.  *  *****************************************************************************/
end_comment

begin_function
name|UINT32
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
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsRemoveInterruptHandler  *  * PARAMETERS:  Handle              Returned when handler was installed  *  * RETURN:      Status  *  * DESCRIPTION: Uninstalls an interrupt handler.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsRemoveInterruptHandler
parameter_list|(
name|UINT32
name|InterruptNumber
parameter_list|,
name|ACPI_OSD_HANDLER
name|ServiceRoutine
parameter_list|)
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsExecute  *  * PARAMETERS:  Type            - Type of execution  *              Function        - Address of the function to execute  *              Context         - Passed as a parameter to the function  *  * RETURN:      Status.  *  * DESCRIPTION: Execute a new thread  *  *****************************************************************************/
end_comment

begin_function
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
block|{
comment|//    _beginthread (Function, (unsigned) 0, Context);
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsBreakpoint  *  * PARAMETERS:  Msg                 Message to print  *  * RETURN:      Status  *  * DESCRIPTION: Print a message and break to the debugger.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsBreakpoint
parameter_list|(
name|char
modifier|*
name|Msg
parameter_list|)
block|{
if|if
condition|(
name|Msg
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"AcpiOsBreakpoint: %s ****\n"
argument_list|,
name|Msg
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AcpiOsPrintf
argument_list|(
literal|"At AcpiOsBreakpoint ****\n"
argument_list|)
expr_stmt|;
block|}
return|return
name|AE_OK
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsStall  *  * PARAMETERS:  microseconds        To sleep  *  * RETURN:      Blocks until sleep is completed.  *  * DESCRIPTION: Sleep at microsecond granularity  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsStall
parameter_list|(
name|UINT32
name|microseconds
parameter_list|)
block|{
if|if
condition|(
name|microseconds
condition|)
block|{
name|usleep
argument_list|(
name|microseconds
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsSleep  *  * PARAMETERS:  milliseconds        To sleep  *  * RETURN:      Blocks until sleep is completed.  *  * DESCRIPTION: Sleep at millisecond granularity  *  *****************************************************************************/
end_comment

begin_function
name|void
name|AcpiOsSleep
parameter_list|(
name|ACPI_INTEGER
name|milliseconds
parameter_list|)
block|{
name|sleep
argument_list|(
name|milliseconds
operator|/
literal|1000
argument_list|)
expr_stmt|;
comment|/* Sleep for whole seconds */
comment|/*      * Arg to usleep() must be less than 1,000,000 (1 second)      */
name|usleep
argument_list|(
operator|(
name|milliseconds
operator|%
literal|1000
operator|)
operator|*
literal|1000
argument_list|)
expr_stmt|;
comment|/* Sleep for remaining usecs */
return|return;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetTimer  *  * PARAMETERS:  None  *  * RETURN:      Current time in 100 nanosecond units  *  * DESCRIPTION: Get the current system time  *  *****************************************************************************/
end_comment

begin_function
name|UINT64
name|AcpiOsGetTimer
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timeval
name|time
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|time
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Seconds * 10^7 = 100ns(10^-7), Microseconds(10^-6) * 10^1 = 100ns */
return|return
operator|(
operator|(
operator|(
name|UINT64
operator|)
name|time
operator|.
name|tv_sec
operator|*
literal|10000000
operator|)
operator|+
operator|(
operator|(
name|UINT64
operator|)
name|time
operator|.
name|tv_usec
operator|*
literal|10
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsValidateInterface  *  * PARAMETERS:  Interface           - Requested interface to be validated  *  * RETURN:      AE_OK if interface is supported, AE_SUPPORT otherwise  *  * DESCRIPTION: Match an interface string to the interfaces supported by the  *              host. Strings originate from an AML call to the _OSI method.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsValidateInterface
parameter_list|(
name|char
modifier|*
name|Interface
parameter_list|)
block|{
return|return
operator|(
name|AE_SUPPORT
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsValidateAddress  *  * PARAMETERS:  SpaceId             - ACPI space ID  *              Address             - Physical address  *              Length              - Address length  *  * RETURN:      AE_OK if Address/Length is valid for the SpaceId. Otherwise,  *              should return AE_AML_ILLEGAL_ADDRESS.  *  * DESCRIPTION: Validate a system address via the host OS. Used to validate  *              the addresses accessed by AML operation regions.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsValidateAddress
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsReadPciConfiguration  *  * PARAMETERS:  PciId               Seg/Bus/Dev  *              Register            Device Register  *              Value               Buffer where value is placed  *              Width               Number of bits  *  * RETURN:      Status  *  * DESCRIPTION: Read data from PCI configuration space  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsReadPciConfiguration
parameter_list|(
name|ACPI_PCI_ID
modifier|*
name|PciId
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|void
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsWritePciConfiguration  *  * PARAMETERS:  PciId               Seg/Bus/Dev  *              Register            Device Register  *              Value               Value to be written  *              Width               Number of bits  *  * RETURN:      Status.  *  * DESCRIPTION: Write data to PCI configuration space  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsWritePciConfiguration
parameter_list|(
name|ACPI_PCI_ID
modifier|*
name|PciId
parameter_list|,
name|UINT32
name|Register
parameter_list|,
name|ACPI_INTEGER
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* TEMPORARY STUB FUNCTION */
end_comment

begin_function
name|void
name|AcpiOsDerivePciId
parameter_list|(
name|ACPI_HANDLE
name|rhandle
parameter_list|,
name|ACPI_HANDLE
name|chandle
parameter_list|,
name|ACPI_PCI_ID
modifier|*
modifier|*
name|PciId
parameter_list|)
block|{  }
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsReadPort  *  * PARAMETERS:  Address             Address of I/O port/register to read  *              Value               Where value is placed  *              Width               Number of bits  *  * RETURN:      Value read from port  *  * DESCRIPTION: Read data from an I/O port or register  *  *****************************************************************************/
end_comment

begin_function
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
block|{
switch|switch
condition|(
name|Width
condition|)
block|{
case|case
literal|8
case|:
operator|*
name|Value
operator|=
literal|0xFF
expr_stmt|;
break|break;
case|case
literal|16
case|:
operator|*
name|Value
operator|=
literal|0xFFFF
expr_stmt|;
break|break;
case|case
literal|32
case|:
operator|*
name|Value
operator|=
literal|0xFFFFFFFF
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsWritePort  *  * PARAMETERS:  Address             Address of I/O port/register to write  *              Value               Value to write  *              Width               Number of bits  *  * RETURN:      None  *  * DESCRIPTION: Write data to an I/O port or register  *  *****************************************************************************/
end_comment

begin_function
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
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsReadMemory  *  * PARAMETERS:  Address             Physical Memory Address to read  *              Value               Where value is placed  *              Width               Number of bits  *  * RETURN:      Value read from physical memory address  *  * DESCRIPTION: Read data from a physical memory address  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsReadMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
block|{
switch|switch
condition|(
name|Width
condition|)
block|{
case|case
literal|8
case|:
case|case
literal|16
case|:
case|case
literal|32
case|:
operator|*
name|Value
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
return|return
operator|(
name|AE_BAD_PARAMETER
operator|)
return|;
break|break;
block|}
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsWriteMemory  *  * PARAMETERS:  Address             Physical Memory Address to write  *              Value               Value to write  *              Width               Number of bits  *  * RETURN:      None  *  * DESCRIPTION: Write data to a physical memory address  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsWriteMemory
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_function
name|ACPI_THREAD_ID
name|AcpiOsGetThreadId
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|getpid
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsSignal  *  * PARAMETERS:  Function            ACPI CA signal function code  *              Info                Pointer to function-dependent structure  *  * RETURN:      Status  *  * DESCRIPTION: Miscellaneous functions  *  *****************************************************************************/
end_comment

begin_function
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
block|{
switch|switch
condition|(
name|Function
condition|)
block|{
case|case
name|ACPI_SIGNAL_FATAL
case|:
break|break;
case|case
name|ACPI_SIGNAL_BREAKPOINT
case|:
if|if
condition|(
name|Info
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"AcpiOsBreakpoint: %s ****\n"
argument_list|,
name|Info
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AcpiOsPrintf
argument_list|(
literal|"At AcpiOsBreakpoint ****\n"
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

end_unit

