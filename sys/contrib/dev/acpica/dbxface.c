begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: dbxface - AML Debugger external interfaces  *              $Revision: 46 $  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"acparser.h"
end_include

begin_include
include|#
directive|include
file|"amlcode.h"
end_include

begin_include
include|#
directive|include
file|"acnamesp.h"
end_include

begin_include
include|#
directive|include
file|"acparser.h"
end_include

begin_include
include|#
directive|include
file|"acevents.h"
end_include

begin_include
include|#
directive|include
file|"acinterp.h"
end_include

begin_include
include|#
directive|include
file|"acdebug.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_DEBUGGER
end_ifdef

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_DEBUGGER
end_define

begin_macro
name|MODULE_NAME
argument_list|(
literal|"dbxface"
argument_list|)
end_macro

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbSingleStep  *  * PARAMETERS:  WalkState       - Current walk  *              Op              - Current executing op  *              OpcodeClass     - Class of the current AML Opcode  *  * RETURN:      Status  *  * DESCRIPTION: Called just before execution of an AML opcode.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDbSingleStep
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|OpcodeClass
parameter_list|)
block|{
name|ACPI_PARSE_OBJECT
modifier|*
name|Next
decl_stmt|;
name|ACPI_STATUS
name|Status
init|=
name|AE_OK
decl_stmt|;
name|UINT32
name|OriginalDebugLevel
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|DisplayOp
decl_stmt|;
name|FUNCTION_ENTRY
argument_list|()
expr_stmt|;
comment|/* Is there a breakpoint set? */
if|if
condition|(
name|WalkState
operator|->
name|MethodBreakpoint
condition|)
block|{
comment|/* Check if the breakpoint has been reached or passed */
if|if
condition|(
name|WalkState
operator|->
name|MethodBreakpoint
operator|<=
name|Op
operator|->
name|AmlOffset
condition|)
block|{
comment|/* Hit the breakpoint, resume single step, reset breakpoint */
name|AcpiOsPrintf
argument_list|(
literal|"***Break*** at AML offset %X\n"
argument_list|,
name|Op
operator|->
name|AmlOffset
argument_list|)
expr_stmt|;
name|AcpiGbl_CmSingleStep
operator|=
name|TRUE
expr_stmt|;
name|AcpiGbl_StepToNextCall
operator|=
name|FALSE
expr_stmt|;
name|WalkState
operator|->
name|MethodBreakpoint
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/*      * Check if this is an opcode that we are interested in --      * namely, opcodes that have arguments      */
if|if
condition|(
name|Op
operator|->
name|Opcode
operator|==
name|AML_INT_NAMEDFIELD_OP
condition|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
switch|switch
condition|(
name|OpcodeClass
condition|)
block|{
case|case
name|AML_CLASS_UNKNOWN
case|:
case|case
name|AML_CLASS_ARGUMENT
case|:
comment|/* constants, literals, etc.  do nothing */
return|return
operator|(
name|AE_OK
operator|)
return|;
break|break;
block|}
comment|/*      * Under certain debug conditions, display this opcode and its operands      */
if|if
condition|(
operator|(
name|AcpiGbl_DbOutputToFile
operator|)
operator|||
operator|(
name|AcpiGbl_CmSingleStep
operator|)
operator|||
operator|(
name|AcpiDbgLevel
operator|&
name|ACPI_LV_PARSE
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|AcpiGbl_DbOutputToFile
operator|)
operator|||
operator|(
name|AcpiDbgLevel
operator|&
name|ACPI_LV_PARSE
operator|)
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"\n[AmlDebug] Next AML Opcode to execute:\n"
argument_list|)
expr_stmt|;
block|}
comment|/*          * Display this op (and only this op - zero out the NEXT field temporarily,          * and disable parser trace output for the duration of the display because          * we don't want the extraneous debug output)          */
name|OriginalDebugLevel
operator|=
name|AcpiDbgLevel
expr_stmt|;
name|AcpiDbgLevel
operator|&=
operator|~
operator|(
name|ACPI_LV_PARSE
operator||
name|ACPI_LV_FUNCTIONS
operator|)
expr_stmt|;
name|Next
operator|=
name|Op
operator|->
name|Next
expr_stmt|;
name|Op
operator|->
name|Next
operator|=
name|NULL
expr_stmt|;
name|DisplayOp
operator|=
name|Op
expr_stmt|;
if|if
condition|(
name|Op
operator|->
name|Parent
condition|)
block|{
if|if
condition|(
operator|(
name|Op
operator|->
name|Parent
operator|->
name|Opcode
operator|==
name|AML_IF_OP
operator|)
operator|||
operator|(
name|Op
operator|->
name|Parent
operator|->
name|Opcode
operator|==
name|AML_WHILE_OP
operator|)
condition|)
block|{
name|DisplayOp
operator|=
name|Op
operator|->
name|Parent
expr_stmt|;
block|}
block|}
comment|/* Now we can display it */
name|AcpiDbDisplayOp
argument_list|(
name|WalkState
argument_list|,
name|DisplayOp
argument_list|,
name|ACPI_UINT32_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|Op
operator|->
name|Opcode
operator|==
name|AML_IF_OP
operator|)
operator|||
operator|(
name|Op
operator|->
name|Opcode
operator|==
name|AML_WHILE_OP
operator|)
condition|)
block|{
if|if
condition|(
name|WalkState
operator|->
name|ControlState
operator|->
name|Common
operator|.
name|Value
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"Predicate was TRUE, executed block\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AcpiOsPrintf
argument_list|(
literal|"Predicate is FALSE, skipping block\n"
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|Op
operator|->
name|Opcode
operator|==
name|AML_ELSE_OP
condition|)
block|{
comment|/* TBD */
block|}
comment|/* Restore everything */
name|Op
operator|->
name|Next
operator|=
name|Next
expr_stmt|;
name|AcpiOsPrintf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|AcpiDbgLevel
operator|=
name|OriginalDebugLevel
expr_stmt|;
block|}
comment|/* If we are not single stepping, just continue executing the method */
if|if
condition|(
operator|!
name|AcpiGbl_CmSingleStep
condition|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
comment|/*      * If we are executing a step-to-call command,      * Check if this is a method call.      */
if|if
condition|(
name|AcpiGbl_StepToNextCall
condition|)
block|{
if|if
condition|(
name|Op
operator|->
name|Opcode
operator|!=
name|AML_INT_METHODCALL_OP
condition|)
block|{
comment|/* Not a method call, just keep executing */
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
comment|/* Found a method call, stop executing */
name|AcpiGbl_StepToNextCall
operator|=
name|FALSE
expr_stmt|;
block|}
comment|/*      * If the next opcode is a method call, we will "step over" it      * by default.      */
if|if
condition|(
name|Op
operator|->
name|Opcode
operator|==
name|AML_INT_METHODCALL_OP
condition|)
block|{
name|AcpiGbl_CmSingleStep
operator|=
name|FALSE
expr_stmt|;
comment|/* No more single step while executing called method */
comment|/* Set the breakpoint on the call, it will stop execution as soon as we return */
comment|/* TBD: [Future] don't kill the user breakpoint! */
name|WalkState
operator|->
name|MethodBreakpoint
operator|=
comment|/* Op->AmlOffset + */
literal|1
expr_stmt|;
comment|/* Must be non-zero! */
block|}
comment|/* TBD: [Investigate] what are the namespace locking issues here */
comment|/* AcpiUtReleaseMutex (ACPI_MTX_NAMESPACE); */
comment|/* Go into the command loop and await next user command */
name|AcpiGbl_MethodExecuting
operator|=
name|TRUE
expr_stmt|;
name|Status
operator|=
name|AE_CTRL_TRUE
expr_stmt|;
while|while
condition|(
name|Status
operator|==
name|AE_CTRL_TRUE
condition|)
block|{
if|if
condition|(
name|AcpiGbl_DebuggerConfiguration
operator|==
name|DEBUGGER_MULTI_THREADED
condition|)
block|{
comment|/* Handshake with the front-end that gets user command lines */
name|AcpiUtReleaseMutex
argument_list|(
name|ACPI_MTX_DEBUG_CMD_COMPLETE
argument_list|)
expr_stmt|;
name|AcpiUtAcquireMutex
argument_list|(
name|ACPI_MTX_DEBUG_CMD_READY
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Single threaded, we must get a command line ourselves */
comment|/* Force output to console until a command is entered */
name|AcpiDbSetOutputDestination
argument_list|(
name|DB_CONSOLE_OUTPUT
argument_list|)
expr_stmt|;
comment|/* Different prompt if method is executing */
if|if
condition|(
operator|!
name|AcpiGbl_MethodExecuting
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"%1c "
argument_list|,
name|DB_COMMAND_PROMPT
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AcpiOsPrintf
argument_list|(
literal|"%1c "
argument_list|,
name|DB_EXECUTE_PROMPT
argument_list|)
expr_stmt|;
block|}
comment|/* Get the user input line */
name|AcpiOsGetLine
argument_list|(
name|AcpiGbl_DbLineBuf
argument_list|)
expr_stmt|;
block|}
name|Status
operator|=
name|AcpiDbCommandDispatch
argument_list|(
name|AcpiGbl_DbLineBuf
argument_list|,
name|WalkState
argument_list|,
name|Op
argument_list|)
expr_stmt|;
block|}
comment|/* AcpiUtAcquireMutex (ACPI_MTX_NAMESPACE); */
comment|/* User commands complete, continue execution of the interrupted method */
return|return
operator|(
name|Status
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbInitialize  *  * PARAMETERS:  None  *  * RETURN:      Status  *  * DESCRIPTION: Init and start debugger  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiDbInitialize
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Init globals */
name|AcpiGbl_DbBuffer
operator|=
name|AcpiOsCallocate
argument_list|(
name|ACPI_DEBUG_BUFFER_SIZE
argument_list|)
expr_stmt|;
comment|/* Initial scope is the root */
name|AcpiGbl_DbScopeBuf
index|[
literal|0
index|]
operator|=
literal|'\\'
expr_stmt|;
name|AcpiGbl_DbScopeBuf
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
comment|/*      * If configured for multi-thread support, the debug executor runs in      * a separate thread so that the front end can be in another address      * space, environment, or even another machine.      */
if|if
condition|(
name|AcpiGbl_DebuggerConfiguration
operator|&
name|DEBUGGER_MULTI_THREADED
condition|)
block|{
comment|/* These were created with one unit, grab it */
name|AcpiUtAcquireMutex
argument_list|(
name|ACPI_MTX_DEBUG_CMD_COMPLETE
argument_list|)
expr_stmt|;
name|AcpiUtAcquireMutex
argument_list|(
name|ACPI_MTX_DEBUG_CMD_READY
argument_list|)
expr_stmt|;
comment|/* Create the debug execution thread to execute commands */
name|AcpiOsQueueForExecution
argument_list|(
literal|0
argument_list|,
name|AcpiDbExecuteThread
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|AcpiGbl_DbOpt_verbose
condition|)
block|{
name|AcpiGbl_DbDisasmIndent
operator|=
literal|"    "
expr_stmt|;
name|AcpiGbl_DbOpt_disasm
operator|=
name|TRUE
expr_stmt|;
name|AcpiGbl_DbOpt_stats
operator|=
name|FALSE
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbTerminate  *  * PARAMETERS:  None  *  * RETURN:      Status  *  * DESCRIPTION: Stop debugger  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDbTerminate
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|AcpiGbl_DbTablePtr
condition|)
block|{
name|AcpiOsFree
argument_list|(
name|AcpiGbl_DbTablePtr
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|AcpiGbl_DbBuffer
condition|)
block|{
name|AcpiOsFree
argument_list|(
name|AcpiGbl_DbBuffer
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_DEBUGGER */
end_comment

end_unit

