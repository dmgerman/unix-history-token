begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: pswalk - Parser routines to walk parsed op tree(s)  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acparser.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_PARSER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"pswalk"
argument_list|)
end_macro

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiPsDeleteParseTree  *  * PARAMETERS:  SubtreeRoot         - Root of tree (or subtree) to delete  *  * RETURN:      None  *  * DESCRIPTION: Delete a portion of or an entire parse tree.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiPsDeleteParseTree
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|SubtreeRoot
parameter_list|)
block|{
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
init|=
name|SubtreeRoot
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|Next
init|=
name|NULL
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|Parent
init|=
name|NULL
decl_stmt|;
name|ACPI_FUNCTION_TRACE_PTR
argument_list|(
name|PsDeleteParseTree
argument_list|,
name|SubtreeRoot
argument_list|)
expr_stmt|;
comment|/* Visit all nodes in the subtree */
while|while
condition|(
name|Op
condition|)
block|{
comment|/* Check if we are not ascending */
if|if
condition|(
name|Op
operator|!=
name|Parent
condition|)
block|{
comment|/* Look for an argument or child of the current op */
name|Next
operator|=
name|AcpiPsGetArg
argument_list|(
name|Op
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next
condition|)
block|{
comment|/* Still going downward in tree (Op is not completed yet) */
name|Op
operator|=
name|Next
expr_stmt|;
continue|continue;
block|}
block|}
comment|/* No more children, this Op is complete. */
name|Next
operator|=
name|Op
operator|->
name|Common
operator|.
name|Next
expr_stmt|;
name|Parent
operator|=
name|Op
operator|->
name|Common
operator|.
name|Parent
expr_stmt|;
name|AcpiPsFreeOp
argument_list|(
name|Op
argument_list|)
expr_stmt|;
comment|/* If we are back to the starting point, the walk is complete. */
if|if
condition|(
name|Op
operator|==
name|SubtreeRoot
condition|)
block|{
name|return_VOID
expr_stmt|;
block|}
if|if
condition|(
name|Next
condition|)
block|{
name|Op
operator|=
name|Next
expr_stmt|;
block|}
else|else
block|{
name|Op
operator|=
name|Parent
expr_stmt|;
block|}
block|}
name|return_VOID
expr_stmt|;
block|}
end_function

end_unit

