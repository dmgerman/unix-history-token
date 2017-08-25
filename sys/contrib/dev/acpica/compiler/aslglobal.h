begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslglobal.h - Global variable definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLGLOBAL_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLGLOBAL_H
end_define

begin_comment
comment|/*  * Global variables. Defined in aslmain.c only, externed in all other files  */
end_comment

begin_undef
undef|#
directive|undef
name|ASL_EXTERN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ASL_EXTERN
end_define

begin_define
define|#
directive|define
name|ASL_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)=(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASL_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|ASL_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_GLOBALS
end_ifdef

begin_decl_stmt
name|UINT32
name|Gbl_ExceptionCount
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table below must match ASL_FILE_TYPES in asltypes.h */
end_comment

begin_decl_stmt
name|ASL_FILE_INFO
name|Gbl_Files
index|[
name|ASL_NUM_FILES
index|]
init|=
block|{
block|{
name|NULL
block|,
name|NULL
block|,
literal|"stdout:       "
block|,
literal|"Standard Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"stderr:       "
block|,
literal|"Standard Error"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Table Input:  "
block|,
literal|"Source Input"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Binary Output:"
block|,
literal|"AML Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Source Output:"
block|,
literal|"Source Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Preprocessor: "
block|,
literal|"Preprocessor Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Preprocessor: "
block|,
literal|"Preprocessor Temp File"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Listing File: "
block|,
literal|"Listing Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Hex Dump:     "
block|,
literal|"Hex Table Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Namespace:    "
block|,
literal|"Namespace Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Debug File:   "
block|,
literal|"Debug Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"ASM Source:   "
block|,
literal|"Assembly Code Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"C Source:     "
block|,
literal|"C Code Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"ASM Include:  "
block|,
literal|"Assembly Header Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"C Include:    "
block|,
literal|"C Header Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Offset Table: "
block|,
literal|"C Offset Table Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Device Map:   "
block|,
literal|"Device Map Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Cross Ref:    "
block|,
literal|"Cross-reference Output"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
literal|"Converter db :"
block|,
literal|"Converter debug Output"
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table below must match the defines with the same names in actypes.h */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|Gbl_OpFlagNames
index|[
name|ACPI_NUM_OP_FLAGS
index|]
init|=
block|{
literal|"OP_VISITED"
block|,
literal|"OP_AML_PACKAGE"
block|,
literal|"OP_IS_TARGET"
block|,
literal|"OP_IS_RESOURCE_DESC"
block|,
literal|"OP_IS_RESOURCE_FIELD"
block|,
literal|"OP_HAS_NO_EXIT"
block|,
literal|"OP_IF_HAS_NO_EXIT"
block|,
literal|"OP_NAME_INTERNALIZED"
block|,
literal|"OP_METHOD_NO_RETVAL"
block|,
literal|"OP_METHOD_SOME_NO_RETVAL"
block|,
literal|"OP_RESULT_NOT_USED"
block|,
literal|"OP_METHOD_TYPED"
block|,
literal|"OP_COULD_NOT_REDUCE"
block|,
literal|"OP_COMPILE_TIME_CONST"
block|,
literal|"OP_IS_TERM_ARG"
block|,
literal|"OP_WAS_ONES_OP"
block|,
literal|"OP_IS_NAME_DECLARATION"
block|,
literal|"OP_COMPILER_EMITTED"
block|,
literal|"OP_IS_DUPLICATE"
block|,
literal|"OP_IS_RESOURCE_DATA"
block|,
literal|"OP_IS_NULL_RETURN"
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_ExceptionCount
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ASL_FILE_INFO
name|Gbl_Files
index|[
name|ASL_NUM_FILES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|Gbl_OpFlagNames
index|[
name|ACPI_NUM_OP_FLAGS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Parser and other externals  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|AslCompilerin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|DtParserdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PrParserdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ASL_MAPPING_ENTRY
name|AslKeywordMapping
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AslCompilertext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Older versions of Bison won't emit this external in the generated header.  * Newer versions do emit the external, so we don't need to do it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASLCOMPILER_ASLCOMPILERPARSE_H
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|AslCompilerdebug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASL_DEFAULT_LINE_BUFFER_SIZE
value|(1024 * 32)
end_define

begin_comment
comment|/* 32K */
end_comment

begin_define
define|#
directive|define
name|ASL_MSG_BUFFER_SIZE
value|(1024 * 32)
end_define

begin_comment
comment|/* 32k */
end_comment

begin_define
define|#
directive|define
name|ASL_MAX_DISABLED_MESSAGES
value|32
end_define

begin_define
define|#
directive|define
name|ASL_MAX_EXPECTED_MESSAGES
value|32
end_define

begin_define
define|#
directive|define
name|HEX_TABLE_LINE_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|HEX_LISTING_LINE_SIZE
value|8
end_define

begin_comment
comment|/* Source code buffers and pointers for error reporting */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_CurrentLineBuffer
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_LineBufPtr
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_LineBufferSize
parameter_list|,
name|ASL_DEFAULT_LINE_BUFFER_SIZE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentColumn
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLineNumber
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_LogicalLineNumber
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLineOffset
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_OriginalInputFileSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_SyntaxError
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exception reporting */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ERROR_MSG
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ErrorLog
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ERROR_MSG
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_NextError
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Option flags */
end_comment

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoCompile
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoSignon
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_PreprocessOnly
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_PreprocessFlag
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisassembleAll
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_UseDefaultAmlFilename
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_MapfileFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_NsOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_PreprocessorOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_KeepPreprocessorTempFile
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DebugFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_CrossReferenceOutput
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_AsmOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_C_OutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_C_OffsetTableFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_AsmIncludeOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_C_IncludeOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ListingFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_IgnoreErrors
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_SourceOutputFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ParseOnlyFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_CompileTimesFlag
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_FoldConstants
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_VerboseErrors
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_NoErrors
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_WarningsAsErrors
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_NoResourceChecking
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_IntegerOptimizationFlag
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_ReferenceOptimizationFlag
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisplayRemarks
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisplayWarnings
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DisplayOptimizations
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_WarningLevel
parameter_list|,
name|ASL_WARNING
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_UseOriginalCompilerId
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_VerboseTemplates
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoTemplates
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_CompileGeneric
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_AllExceptionsDisabled
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_PruneParseTree
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoTypechecking
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_EnableReferenceTypechecking
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoExternals
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoExternalsInPlace
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_DoAslConversion
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_OptimizeTrivialParseNodes
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HEX_OUTPUT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|HEX_OUTPUT_C
value|1
end_define

begin_define
define|#
directive|define
name|HEX_OUTPUT_ASM
value|2
end_define

begin_define
define|#
directive|define
name|HEX_OUTPUT_ASL
value|3
end_define

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HexOutputFlag
parameter_list|,
name|HEX_OUTPUT_NONE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Files */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|char
modifier|*
name|Gbl_DirectoryPath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_IncludeFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_OutputFilenamePrefix
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_INCLUDE_DIR
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_IncludeDirList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
modifier|*
name|Gbl_CurrentInputFilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ExternalRefFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_PreviousIncludeFilename
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ASL_EXTERN
name|BOOLEAN
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HasIncludeFiles
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Statistics */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_InputByteCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_InputFieldCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_NsLookupCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalKeywords
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalNamedObjects
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalExecutableOpcodes
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalParseNodes
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalMethods
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalAllocations
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalAllocated
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|TotalFolds
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local caches */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_ParseOpCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_CACHE_INFO
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ParseOpCacheList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ParseOpCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ParseOpCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_StringCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_StringSize
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_CACHE_INFO
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_StringCacheList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_StringCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_StringCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map file */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_GPIO_INFO
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_GpioList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_SERIAL_INFO
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_SerialList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Misc */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_RevisionOverride
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_TempCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ParseTreeRoot
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ExternalsListHead
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_TableLength
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_SourceLine
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_LISTING_NODE
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_ListingNode
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_FileType
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_Signature
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_PARSE_OBJECT
modifier|*
name|Gbl_FirstLevelInsertionNode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentHexColumn
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentAmlOffset
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentLine
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_DisabledMessagesIndex
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_ExpectedMessagesIndex
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
parameter_list|(
name|Gbl_HexBytesWereWritten
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_NumNamespaceObjects
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_ReservedMethods
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_TableSignature
argument_list|,
literal|"NO_SIG"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_TableId
argument_list|,
literal|"NO_ID"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_PruneDepth
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT16
name|ASL_INIT_GLOBAL
argument_list|(
name|Gbl_PruneType
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_FILE_NODE
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_IncludeFileStack
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specific to the -q option */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_COMMENT_STATE
name|Gbl_CommentState
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Determines if an inline comment should be saved in the InlineComment or NodeEndComment  *  field of ACPI_PARSE_OBJECT.  */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_COMMENT_NODE
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_CommentListHead
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_COMMENT_NODE
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_CommentListTail
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|ASL_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_InlineCommentBuffer
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Static structures */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|ASL_ANALYSIS_WALK_INFO
name|AnalysisWalkInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ACPI_TABLE_HEADER
name|TableHeader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Event timing */
end_comment

begin_define
define|#
directive|define
name|ASL_NUM_EVENTS
value|24
end_define

begin_decl_stmt
name|ASL_EXTERN
name|ASL_EVENT_INFO
name|AslGbl_Events
index|[
name|ASL_NUM_EVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|AslGbl_NextEvent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|AslGbl_NamespaceEvent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scratch buffers */
end_comment

begin_decl_stmt
name|ASL_EXTERN
name|UINT8
name|Gbl_AmlBuffer
index|[
name|HEX_LISTING_LINE_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|MsgBuffer
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|StringBuffer
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|char
name|StringBuffer2
index|[
name|ASL_MSG_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|UINT32
name|Gbl_DisabledMessages
index|[
name|ASL_MAX_DISABLED_MESSAGES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ASL_EXTERN
name|ASL_EXPECTED_MESSAGE
name|Gbl_ExpectedMessages
index|[
name|ASL_MAX_EXPECTED_MESSAGES
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLGLOBAL_H */
end_comment

end_unit

