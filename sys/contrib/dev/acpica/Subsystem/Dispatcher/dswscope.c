begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: dswscope - Scope stack manipulation  *              $Revision: 42 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|__DSWSCOPE_C__
end_define

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"acinterp.h"
end_include

begin_include
include|#
directive|include
file|"acdispat.h"
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|NAMESPACE
end_define

begin_macro
name|MODULE_NAME
argument_list|(
literal|"dswscope"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|STACK_POP
parameter_list|(
name|head
parameter_list|)
value|head
end_define

begin_comment
comment|/****************************************************************************  *  * FUNCTION:    AcpiDsScopeStackClear  *  * PARAMETERS:  None  *  * DESCRIPTION: Pop (and free) everything on the scope stack except the  *              root scope object (which remains at the stack top.)  *  ***************************************************************************/
end_comment

begin_function
name|void
name|AcpiDsScopeStackClear
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
block|{
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
decl_stmt|;
while|while
condition|(
name|WalkState
operator|->
name|ScopeInfo
condition|)
block|{
comment|/* Pop a scope off the stack */
name|ScopeInfo
operator|=
name|WalkState
operator|->
name|ScopeInfo
expr_stmt|;
name|WalkState
operator|->
name|ScopeInfo
operator|=
name|ScopeInfo
operator|->
name|Scope
operator|.
name|Next
expr_stmt|;
name|DEBUG_PRINT
argument_list|(
name|TRACE_EXEC
argument_list|,
operator|(
literal|"Popped object type %X\n"
operator|,
name|ScopeInfo
operator|->
name|Common
operator|.
name|Value
operator|)
argument_list|)
expr_stmt|;
name|AcpiCmDeleteGenericState
argument_list|(
name|ScopeInfo
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/****************************************************************************  *  * FUNCTION:    AcpiDsScopeStackPush  *  * PARAMETERS:  *Node,              - Name to be made current  *              Type,               - Type of frame being pushed  *  * DESCRIPTION: Push the current scope on the scope stack, and make the  *              passed Node current.  *  ***************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDsScopeStackPush
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|OBJECT_TYPE_INTERNAL
name|Type
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
block|{
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
decl_stmt|;
name|FUNCTION_TRACE
argument_list|(
literal|"DsScopeStackPush"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Node
condition|)
block|{
comment|/*  invalid scope   */
name|REPORT_ERROR
argument_list|(
operator|(
literal|"DsScopeStackPush: null scope passed\n"
operator|)
argument_list|)
expr_stmt|;
name|return_ACPI_STATUS
argument_list|(
name|AE_BAD_PARAMETER
argument_list|)
expr_stmt|;
block|}
comment|/* Make sure object type is valid */
if|if
condition|(
operator|!
name|AcpiAmlValidateObjectType
argument_list|(
name|Type
argument_list|)
condition|)
block|{
name|REPORT_WARNING
argument_list|(
operator|(
literal|"DsScopeStackPush: type code out of range\n"
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* Allocate a new scope object */
name|ScopeInfo
operator|=
name|AcpiCmCreateGenericState
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ScopeInfo
condition|)
block|{
name|return_ACPI_STATUS
argument_list|(
name|AE_NO_MEMORY
argument_list|)
expr_stmt|;
block|}
comment|/* Init new scope object */
name|ScopeInfo
operator|->
name|Scope
operator|.
name|Node
operator|=
name|Node
expr_stmt|;
name|ScopeInfo
operator|->
name|Common
operator|.
name|Value
operator|=
operator|(
name|UINT16
operator|)
name|Type
expr_stmt|;
comment|/* Push new scope object onto stack */
name|AcpiCmPushGenericState
argument_list|(
operator|&
name|WalkState
operator|->
name|ScopeInfo
argument_list|,
name|ScopeInfo
argument_list|)
expr_stmt|;
name|return_ACPI_STATUS
argument_list|(
name|AE_OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/****************************************************************************  *  * FUNCTION:    AcpiDsScopeStackPop  *  * PARAMETERS:  Type                - The type of frame to be found  *  * DESCRIPTION: Pop the scope stack until a frame of the requested type  *              is found.  *  * RETURN:      Count of frames popped.  If no frame of the requested type  *              was found, the count is returned as a negative number and  *              the scope stack is emptied (which sets the current scope  *              to the root).  If the scope stack was empty at entry, the  *              function is a no-op and returns 0.  *  ***************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDsScopeStackPop
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
block|{
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
decl_stmt|;
name|FUNCTION_TRACE
argument_list|(
literal|"DsScopeStackPop"
argument_list|)
expr_stmt|;
comment|/*      * Pop scope info object off the stack.      */
name|ScopeInfo
operator|=
name|AcpiCmPopGenericState
argument_list|(
operator|&
name|WalkState
operator|->
name|ScopeInfo
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ScopeInfo
condition|)
block|{
name|return_ACPI_STATUS
argument_list|(
name|AE_STACK_UNDERFLOW
argument_list|)
expr_stmt|;
block|}
name|DEBUG_PRINT
argument_list|(
name|TRACE_EXEC
argument_list|,
operator|(
literal|"Popped object type %X\n"
operator|,
name|ScopeInfo
operator|->
name|Common
operator|.
name|Value
operator|)
argument_list|)
expr_stmt|;
name|AcpiCmDeleteGenericState
argument_list|(
name|ScopeInfo
argument_list|)
expr_stmt|;
name|return_ACPI_STATUS
argument_list|(
name|AE_OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

