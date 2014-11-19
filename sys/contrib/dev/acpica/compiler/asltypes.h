begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asltypes.h - compiler data types and struct definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
name|NODE_VISITED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NODE_AML_PACKAGE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NODE_IS_TARGET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NODE_IS_RESOURCE_DESC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NODE_IS_RESOURCE_FIELD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NODE_HAS_NO_EXIT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NODE_IF_HAS_NO_EXIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NODE_NAME_INTERNALIZED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NODE_METHOD_NO_RETVAL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NODE_METHOD_SOME_NO_RETVAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NODE_RESULT_NOT_USED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NODE_METHOD_TYPED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NODE_UNUSED_FLAG
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NODE_COMPILE_TIME_CONST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NODE_IS_TERM_ARG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NODE_WAS_ONES_OP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NODE_IS_NAME_DECLARATION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NODE_COMPILER_EMITTED
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NODE_IS_DUPLICATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NODE_IS_RESOURCE_DATA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NODE_IS_NULL_RETURN
value|0x00100000
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
comment|/*  * File types. Note: Any changes to this table must also be reflected  * in the Gbl_Files array.  */
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
name|ASL_FILE_AML_OUTPUT
block|,
comment|/* Don't move these first 4 file types */
name|ASL_FILE_SOURCE_OUTPUT
block|,
name|ASL_FILE_PREPROCESSOR
block|,
name|ASL_FILE_LISTING_OUTPUT
block|,
name|ASL_FILE_HEX_OUTPUT
block|,
name|ASL_FILE_NAMESPACE_OUTPUT
block|,
name|ASL_FILE_DEBUG_OUTPUT
block|,
name|ASL_FILE_ASM_SOURCE_OUTPUT
block|,
name|ASL_FILE_C_SOURCE_OUTPUT
block|,
name|ASL_FILE_ASM_INCLUDE_OUTPUT
block|,
name|ASL_FILE_C_INCLUDE_OUTPUT
block|,
name|ASL_FILE_C_OFFSET_OUTPUT
block|,
name|ASL_FILE_MAP_OUTPUT
block|}
name|ASL_FILE_TYPES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASL_MAX_FILE_TYPE
value|15
end_define

begin_define
define|#
directive|define
name|ASL_NUM_FILES
value|(ASL_MAX_FILE_TYPE + 1)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLTYPES_H */
end_comment

end_unit

