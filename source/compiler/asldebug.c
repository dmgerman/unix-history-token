begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asldebug -- Debug output support  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"aslcompiler.h"
end_include

begin_include
include|#
directive|include
file|"aslcompiler.y.h"
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_COMPILER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"asldebug"
argument_list|)
end_macro

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|UtDumpParseOpName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|UINT32
name|DataLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    UtDumpIntegerOp  *  * PARAMETERS:  Op                  - Current parse op  *              Level               - Current output indentation level  *              IntegerLength       - Output length of the integer (2/4/8/16)  *  * RETURN:      None  *  * DESCRIPTION: Emit formatted debug output for "integer" ops.  *              Note: IntegerLength must be one of 2,4,8,16.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|UtDumpIntegerOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|UINT32
name|IntegerLength
parameter_list|)
block|{
comment|/* Emit the ParseOp name, leaving room for the integer */
name|UtDumpParseOpName
argument_list|(
name|Op
argument_list|,
name|Level
argument_list|,
name|IntegerLength
argument_list|)
expr_stmt|;
comment|/* Emit the integer based upon length */
switch|switch
condition|(
name|IntegerLength
condition|)
block|{
case|case
literal|2
case|:
comment|/* Byte */
case|case
literal|4
case|:
comment|/* Word */
case|case
literal|8
case|:
comment|/* Dword */
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%*.*X"
argument_list|,
name|IntegerLength
argument_list|,
name|IntegerLength
argument_list|,
name|Op
operator|->
name|Asl
operator|.
name|Value
operator|.
name|Integer
argument_list|)
expr_stmt|;
break|break;
case|case
literal|16
case|:
comment|/* Qword and Integer */
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%8.8X%8.8X"
argument_list|,
name|ACPI_FORMAT_UINT64
argument_list|(
name|Op
operator|->
name|Asl
operator|.
name|Value
operator|.
name|Integer
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    UtDumpStringOp  *  * PARAMETERS:  Op                  - Current parse op  *              Level               - Current output indentation level  *  * RETURN:      None  *  * DESCRIPTION: Emit formatted debug output for String/Pathname ops.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|UtDumpStringOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|)
block|{
name|char
modifier|*
name|String
decl_stmt|;
name|String
operator|=
name|Op
operator|->
name|Asl
operator|.
name|Value
operator|.
name|String
expr_stmt|;
if|if
condition|(
name|Op
operator|->
name|Asl
operator|.
name|ParseOpcode
operator|!=
name|PARSEOP_STRING_LITERAL
condition|)
block|{
comment|/*          * For the "path" ops NAMEPATH, NAMESEG, METHODCALL -- if the          * ExternalName is valid, it takes precedence. In these cases the          * Value.String is the raw "internal" name from the AML code, which          * we don't want to use, because it contains non-ascii characters.          */
if|if
condition|(
name|Op
operator|->
name|Asl
operator|.
name|ExternalName
condition|)
block|{
name|String
operator|=
name|Op
operator|->
name|Asl
operator|.
name|ExternalName
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|String
condition|)
block|{
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|" ERROR: Could not find a valid String/Path pointer\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Emit the ParseOp name, leaving room for the string */
name|UtDumpParseOpName
argument_list|(
name|Op
argument_list|,
name|Level
argument_list|,
name|strlen
argument_list|(
name|String
argument_list|)
argument_list|)
expr_stmt|;
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%s"
argument_list|,
name|String
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    UtDumpBasicOp  *  * PARAMETERS:  Op                  - Current parse op  *              Level               - Current output indentation level  *  * RETURN:      None  *  * DESCRIPTION: Generic formatted debug output for "basic" ops that have no  *              associated strings or integer values.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|UtDumpBasicOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|)
block|{
comment|/* Just print out the ParseOp name, there is no extra data */
name|UtDumpParseOpName
argument_list|(
name|Op
argument_list|,
name|Level
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    UtDumpParseOpName  *  * PARAMETERS:  Op                  - Current parse op  *              Level               - Current output indentation level  *              DataLength          - Length of data to appear after the name  *  * RETURN:      None  *  * DESCRIPTION: Indent and emit the ascii ParseOp name for the op  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|UtDumpParseOpName
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|UINT32
name|DataLength
parameter_list|)
block|{
name|char
modifier|*
name|ParseOpName
decl_stmt|;
name|UINT32
name|IndentLength
decl_stmt|;
name|UINT32
name|NameLength
decl_stmt|;
name|UINT32
name|LineLength
decl_stmt|;
name|UINT32
name|PaddingLength
decl_stmt|;
comment|/* Emit the LineNumber/IndentLevel prefix on each output line */
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%5.5d [%2d]"
argument_list|,
name|Op
operator|->
name|Asl
operator|.
name|LogicalLineNumber
argument_list|,
name|Level
argument_list|)
expr_stmt|;
name|ParseOpName
operator|=
name|UtGetOpName
argument_list|(
name|Op
operator|->
name|Asl
operator|.
name|ParseOpcode
argument_list|)
expr_stmt|;
comment|/* Calculate various lengths for output alignment */
name|IndentLength
operator|=
name|Level
operator|*
name|DEBUG_SPACES_PER_INDENT
expr_stmt|;
name|NameLength
operator|=
name|strlen
argument_list|(
name|ParseOpName
argument_list|)
expr_stmt|;
name|LineLength
operator|=
name|IndentLength
operator|+
literal|1
operator|+
name|NameLength
operator|+
literal|1
operator|+
name|DataLength
expr_stmt|;
name|PaddingLength
operator|=
operator|(
name|DEBUG_MAX_LINE_LENGTH
operator|+
literal|1
operator|)
operator|-
name|LineLength
expr_stmt|;
comment|/* Parse tree indentation is based upon the nesting/indent level */
if|if
condition|(
name|Level
condition|)
block|{
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%*s"
argument_list|,
name|IndentLength
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
block|}
comment|/* Emit the actual name here */
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|" %s"
argument_list|,
name|ParseOpName
argument_list|)
expr_stmt|;
comment|/* Emit extra padding blanks for alignment of later data items */
if|if
condition|(
name|LineLength
operator|>
name|DEBUG_MAX_LINE_LENGTH
condition|)
block|{
comment|/* Split a long line immediately after the ParseOpName string */
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"\n%*s"
argument_list|,
operator|(
name|DEBUG_FULL_LINE_LENGTH
operator|-
name|DataLength
operator|)
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|DbgPrint
argument_list|(
name|ASL_TREE_OUTPUT
argument_list|,
literal|"%*s"
argument_list|,
name|PaddingLength
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

