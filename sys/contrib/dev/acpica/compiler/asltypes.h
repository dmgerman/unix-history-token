begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asltypes.h - compiler data types and struct definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLTYPES_H
end_define

begin_comment
comment|/*******************************************************************************  *  * Structure definitions  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Op flags for the ACPI_PARSE_OBJECT */
end_comment

begin_define
define|#
directive|define
name|OP_VISITED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OP_AML_PACKAGE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|OP_IS_TARGET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|OP_IS_RESOURCE_DESC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|OP_IS_RESOURCE_FIELD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|OP_HAS_NO_EXIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|OP_IF_HAS_NO_EXIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|OP_NAME_INTERNALIZED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|OP_METHOD_NO_RETVAL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|OP_METHOD_SOME_NO_RETVAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|OP_RESULT_NOT_USED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|OP_METHOD_TYPED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|OP_COULD_NOT_REDUCE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|OP_COMPILE_TIME_CONST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|OP_IS_TERM_ARG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|OP_WAS_ONES_OP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|OP_IS_NAME_DECLARATION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|OP_COMPILER_EMITTED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|OP_IS_DUPLICATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|OP_IS_RESOURCE_DATA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|OP_IS_NULL_RETURN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_OP_FLAGS
value|0x21
end_define

begin_comment
comment|/* Keeps information about individual control methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_method_info
block|{
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|CurrentOp
decl_stmt|;
name|struct
name|asl_method_info
modifier|*
name|Next
decl_stmt|;
name|UINT32
name|ValidArgTypes
index|[
name|ACPI_METHOD_NUM_ARGS
index|]
decl_stmt|;
name|UINT32
name|ValidReturnTypes
decl_stmt|;
name|UINT32
name|NumReturnNoValue
decl_stmt|;
name|UINT32
name|NumReturnWithValue
decl_stmt|;
name|UINT8
name|NumArguments
decl_stmt|;
name|UINT8
name|LocalInitialized
index|[
name|ACPI_METHOD_NUM_LOCALS
index|]
decl_stmt|;
name|UINT8
name|ArgInitialized
index|[
name|ACPI_METHOD_NUM_ARGS
index|]
decl_stmt|;
name|UINT8
name|HasBeenTyped
decl_stmt|;
name|UINT8
name|ShouldBeSerialized
decl_stmt|;
block|}
name|ASL_METHOD_INFO
typedef|;
end_typedef

begin_comment
comment|/* Parse tree walk info for control method analysis */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_analysis_walk_info
block|{
name|ASL_METHOD_INFO
modifier|*
name|MethodStack
decl_stmt|;
block|}
name|ASL_ANALYSIS_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/* An entry in the ParseOpcode to AmlOpcode mapping table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_mapping_entry
block|{
name|UINT32
name|Value
decl_stmt|;
name|UINT32
name|AcpiBtype
decl_stmt|;
comment|/* Object type or return type */
name|UINT16
name|AmlOpcode
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_MAPPING_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Parse tree walk info structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_walk_info
block|{
name|ACPI_PARSE_OBJECT
modifier|*
modifier|*
name|NodePtr
decl_stmt|;
name|UINT32
modifier|*
name|LevelPtr
decl_stmt|;
block|}
name|ASL_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/* File info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_file_info
block|{
name|FILE
modifier|*
name|Handle
decl_stmt|;
name|char
modifier|*
name|Filename
decl_stmt|;
specifier|const
name|char
modifier|*
name|ShortDescription
decl_stmt|;
specifier|const
name|char
modifier|*
name|Description
decl_stmt|;
block|}
name|ASL_FILE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_file_status
block|{
name|UINT32
name|Line
decl_stmt|;
name|UINT32
name|Offset
decl_stmt|;
block|}
name|ASL_FILE_STATUS
typedef|;
end_typedef

begin_comment
comment|/*  * File types. Note: Any changes to this table must also be reflected  * in the Gbl_Files array.  *  * Corresponding filename suffixes are in comments  *  * NOTE: Don't move the first 4 file types  *  * .xxx file extension: this is used as a temporary .aml file for  * the ASL/ASL+ converter and is deleted after conversion. This file  * should never be used in the interpreter.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ASL_FILE_STDOUT
init|=
literal|0
block|,
name|ASL_FILE_STDERR
block|,
name|ASL_FILE_INPUT
block|,
comment|/* .asl */
name|ASL_FILE_AML_OUTPUT
block|,
comment|/* .aml */
name|ASL_FILE_SOURCE_OUTPUT
block|,
comment|/* .src */
name|ASL_FILE_PREPROCESSOR
block|,
comment|/* .pre */
name|ASL_FILE_PREPROCESSOR_USER
block|,
comment|/* .i   */
name|ASL_FILE_LISTING_OUTPUT
block|,
comment|/* .lst */
name|ASL_FILE_HEX_OUTPUT
block|,
comment|/* .hex */
name|ASL_FILE_NAMESPACE_OUTPUT
block|,
comment|/* .nsp */
name|ASL_FILE_DEBUG_OUTPUT
block|,
comment|/* .txt */
name|ASL_FILE_ASM_SOURCE_OUTPUT
block|,
comment|/* .asm */
name|ASL_FILE_C_SOURCE_OUTPUT
block|,
comment|/* .c   */
name|ASL_FILE_ASM_INCLUDE_OUTPUT
block|,
comment|/* .inc */
name|ASL_FILE_C_INCLUDE_OUTPUT
block|,
comment|/* .h   */
name|ASL_FILE_C_OFFSET_OUTPUT
block|,
comment|/* .offset.h */
name|ASL_FILE_MAP_OUTPUT
block|,
comment|/* .map */
name|ASL_FILE_XREF_OUTPUT
block|,
comment|/* .xrf */
name|ASL_FILE_CONV_DEBUG_OUTPUT
block|,
comment|/* .cdb */
name|ASL_FILE_CONV_OUTPUT
comment|/* .xxx */
block|}
name|ASL_FILE_TYPES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASL_MAX_FILE_TYPE
value|18
end_define

begin_define
define|#
directive|define
name|ASL_NUM_FILES
value|(ASL_MAX_FILE_TYPE + 1)
end_define

begin_comment
comment|/* Name suffixes used to create filenames for output files */
end_comment

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASL_CODE
value|"asl"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_AML_CODE
value|"aml"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_SOURCE
value|"src"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_PREPROCESSOR
value|"pre"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_PREPROC_USER
value|"i"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_LISTING
value|"lst"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_HEX_DUMP
value|"hex"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_NAMESPACE
value|"nsp"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_DEBUG
value|"txt"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASM_SOURCE
value|"asm"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_SOURCE
value|"c"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASM_INCLUDE
value|"inc"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_INCLUDE
value|"h"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_OFFSET
value|"offset.h"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_MAP
value|"map"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_XREF
value|"xrf"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_CONVERT_AML
value|"xxx"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_CONVERT_DEBUG
value|"cdb"
end_define

begin_comment
comment|/* Cache block structure for ParseOps and Strings */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_cache_info
block|{
name|void
modifier|*
name|Next
decl_stmt|;
name|char
name|Buffer
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ASL_CACHE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_include_dir
block|{
name|char
modifier|*
name|Dir
decl_stmt|;
name|struct
name|asl_include_dir
modifier|*
name|Next
decl_stmt|;
block|}
name|ASL_INCLUDE_DIR
typedef|;
end_typedef

begin_comment
comment|/* An entry in the exception list, one for each error/warning */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_error_msg
block|{
name|UINT32
name|LineNumber
decl_stmt|;
name|UINT32
name|LogicalLineNumber
decl_stmt|;
name|UINT32
name|LogicalByteOffset
decl_stmt|;
name|UINT32
name|Column
decl_stmt|;
name|char
modifier|*
name|Message
decl_stmt|;
name|struct
name|asl_error_msg
modifier|*
name|Next
decl_stmt|;
name|char
modifier|*
name|Filename
decl_stmt|;
name|char
modifier|*
name|SourceLine
decl_stmt|;
name|UINT32
name|FilenameLength
decl_stmt|;
name|UINT16
name|MessageId
decl_stmt|;
name|UINT8
name|Level
decl_stmt|;
block|}
name|ASL_ERROR_MSG
typedef|;
end_typedef

begin_comment
comment|/* An entry in the expected messages array */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_expected_message
block|{
name|UINT32
name|MessageId
decl_stmt|;
name|char
modifier|*
name|MessageIdStr
decl_stmt|;
name|BOOLEAN
name|MessageReceived
decl_stmt|;
block|}
name|ASL_EXPECTED_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/* An entry in the listing file stack (for include files) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_listing_node
block|{
name|char
modifier|*
name|Filename
decl_stmt|;
name|UINT32
name|LineNumber
decl_stmt|;
name|struct
name|asl_listing_node
modifier|*
name|Next
decl_stmt|;
block|}
name|ASL_LISTING_NODE
typedef|;
end_typedef

begin_comment
comment|/* Callback interface for a parse tree walk */
end_comment

begin_comment
comment|/*  * TBD - another copy of this is in adisasm.h, fix  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASL_WALK_CALLBACK_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ASL_WALK_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ASL_WALK_CALLBACK_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|asl_event_info
block|{
name|UINT64
name|StartTime
decl_stmt|;
name|UINT64
name|EndTime
decl_stmt|;
name|char
modifier|*
name|EventName
decl_stmt|;
name|BOOLEAN
name|Valid
decl_stmt|;
block|}
name|ASL_EVENT_INFO
typedef|;
end_typedef

begin_comment
comment|/* Hardware mapping file structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpio_info
block|{
name|struct
name|acpi_gpio_info
modifier|*
name|Next
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
name|char
modifier|*
name|DeviceName
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|TargetNode
decl_stmt|;
name|UINT32
name|References
decl_stmt|;
name|UINT32
name|PinCount
decl_stmt|;
name|UINT32
name|PinIndex
decl_stmt|;
name|UINT16
name|PinNumber
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Direction
decl_stmt|;
name|UINT8
name|Polarity
decl_stmt|;
block|}
name|ACPI_GPIO_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_serial_info
block|{
name|struct
name|acpi_serial_info
modifier|*
name|Next
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
name|char
modifier|*
name|DeviceName
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|TargetNode
decl_stmt|;
name|AML_RESOURCE
modifier|*
name|Resource
decl_stmt|;
name|UINT32
name|Speed
decl_stmt|;
name|UINT16
name|Address
decl_stmt|;
block|}
name|ACPI_SERIAL_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_method_local
block|{
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_METHOD_LOCAL
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ASL_LOCAL_INITIALIZED
value|(1)
end_define

begin_define
define|#
directive|define
name|ASL_LOCAL_REFERENCED
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ASL_ARG_IS_LOCAL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ASL_ARG_INITIALIZED
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ASL_ARG_REFERENCED
value|(1<<4)
end_define

begin_comment
comment|/* Info used to track method counts for cross reference output file */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_xref_info
block|{
name|UINT32
name|ThisMethodInvocations
decl_stmt|;
name|UINT32
name|TotalPredefinedMethods
decl_stmt|;
name|UINT32
name|TotalUserMethods
decl_stmt|;
name|UINT32
name|TotalUnreferenceUserMethods
decl_stmt|;
name|UINT32
name|ThisObjectReferences
decl_stmt|;
name|UINT32
name|TotalObjects
decl_stmt|;
name|UINT32
name|TotalUnreferencedObjects
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|MethodOp
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|CurrentMethodOp
decl_stmt|;
block|}
name|ASL_XREF_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_file_node
block|{
name|FILE
modifier|*
name|File
decl_stmt|;
name|UINT32
name|CurrentLineNumber
decl_stmt|;
name|void
modifier|*
name|State
decl_stmt|;
name|char
modifier|*
name|Filename
decl_stmt|;
name|struct
name|asl_file_node
modifier|*
name|Next
decl_stmt|;
block|}
name|ASL_FILE_NODE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLTYPES_H */
end_comment

end_unit

