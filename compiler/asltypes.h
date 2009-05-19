begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asltypes.h - compiler data types and struct definitions  *              $Revision: 1.89 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
name|NODE_IS_BIT_OFFSET
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

begin_comment
comment|/* Keeps information about individual control methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_method_info
block|{
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
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
decl_stmt|;
name|struct
name|asl_method_info
modifier|*
name|Next
decl_stmt|;
name|UINT8
name|HasBeenTyped
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
comment|/* An entry in the Reserved Name information table */
end_comment

begin_define
define|#
directive|define
name|ASL_RSVD_RETURN_VALUE
value|0x01
end_define

begin_define
define|#
directive|define
name|ASL_RSVD_RESOURCE_NAME
value|0x02
end_define

begin_define
define|#
directive|define
name|ASL_RSVD_SCOPE
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|asl_reserved_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT8
name|NumArguments
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_RESERVED_INFO
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
comment|/* File types */
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
name|ASL_FILE_SOURCE_OUTPUT
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
block|}
name|ASL_FILE_TYPES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ASL_MAX_FILE_TYPE
value|12
end_define

begin_define
define|#
directive|define
name|ASL_NUM_FILES
value|(ASL_MAX_FILE_TYPE + 1)
end_define

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
name|UINT32
name|FilenameLength
decl_stmt|;
name|UINT8
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

begin_define
define|#
directive|define
name|ASL_WARNING
value|0
end_define

begin_define
define|#
directive|define
name|ASL_WARNING2
value|1
end_define

begin_define
define|#
directive|define
name|ASL_WARNING3
value|2
end_define

begin_define
define|#
directive|define
name|ASL_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|ASL_REMARK
value|4
end_define

begin_define
define|#
directive|define
name|ASL_OPTIMIZATION
value|5
end_define

begin_define
define|#
directive|define
name|ASL_NUM_REPORT_LEVELS
value|6
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ASL_MSG_RESERVED
init|=
literal|0
block|,
name|ASL_MSG_ALPHANUMERIC_STRING
block|,
name|ASL_MSG_AML_NOT_IMPLEMENTED
block|,
name|ASL_MSG_ARG_COUNT_HI
block|,
name|ASL_MSG_ARG_COUNT_LO
block|,
name|ASL_MSG_ARG_INIT
block|,
name|ASL_MSG_BACKWARDS_OFFSET
block|,
name|ASL_MSG_BITS_TO_BYTES
block|,
name|ASL_MSG_BUFFER_LENGTH
block|,
name|ASL_MSG_BYTES_TO_BITS
block|,
name|ASL_MSG_CLOSE
block|,
name|ASL_MSG_COMPILER_INTERNAL
block|,
name|ASL_MSG_CONSTANT_EVALUATION
block|,
name|ASL_MSG_CONSTANT_FOLDED
block|,
name|ASL_MSG_CORE_EXCEPTION
block|,
name|ASL_MSG_DEBUG_FILE_OPEN
block|,
name|ASL_MSG_DEBUG_FILENAME
block|,
name|ASL_MSG_DEPENDENT_NESTING
block|,
name|ASL_MSG_DMA_CHANNEL
block|,
name|ASL_MSG_DMA_LIST
block|,
name|ASL_MSG_DUPLICATE_CASE
block|,
name|ASL_MSG_DUPLICATE_ITEM
block|,
name|ASL_MSG_EARLY_EOF
block|,
name|ASL_MSG_ENCODING_LENGTH
block|,
name|ASL_MSG_EX_INTERRUPT_LIST
block|,
name|ASL_MSG_EX_INTERRUPT_NUMBER
block|,
name|ASL_MSG_FIELD_ACCESS_WIDTH
block|,
name|ASL_MSG_FIELD_UNIT_ACCESS_WIDTH
block|,
name|ASL_MSG_FIELD_UNIT_OFFSET
block|,
name|ASL_MSG_INCLUDE_FILE_OPEN
block|,
name|ASL_MSG_INPUT_FILE_OPEN
block|,
name|ASL_MSG_INTEGER_LENGTH
block|,
name|ASL_MSG_INTEGER_OPTIMIZATION
block|,
name|ASL_MSG_INTERRUPT_LIST
block|,
name|ASL_MSG_INTERRUPT_NUMBER
block|,
name|ASL_MSG_INVALID_CONSTANT_OP
block|,
name|ASL_MSG_INVALID_EISAID
block|,
name|ASL_MSG_INVALID_ESCAPE
block|,
name|ASL_MSG_INVALID_OPERAND
block|,
name|ASL_MSG_INVALID_PERFORMANCE
block|,
name|ASL_MSG_INVALID_PRIORITY
block|,
name|ASL_MSG_INVALID_STRING
block|,
name|ASL_MSG_INVALID_TARGET
block|,
name|ASL_MSG_INVALID_TIME
block|,
name|ASL_MSG_INVALID_TYPE
block|,
name|ASL_MSG_INVALID_UUID
block|,
name|ASL_MSG_LIST_LENGTH
block|,
name|ASL_MSG_LISTING_FILE_OPEN
block|,
name|ASL_MSG_LISTING_FILENAME
block|,
name|ASL_MSG_LOCAL_INIT
block|,
name|ASL_MSG_LONG_LINE
block|,
name|ASL_MSG_MEMORY_ALLOCATION
block|,
name|ASL_MSG_MISSING_ENDDEPENDENT
block|,
name|ASL_MSG_MISSING_STARTDEPENDENT
block|,
name|ASL_MSG_MULTIPLE_TYPES
block|,
name|ASL_MSG_NAME_EXISTS
block|,
name|ASL_MSG_NAME_OPTIMIZATION
block|,
name|ASL_MSG_NESTED_COMMENT
block|,
name|ASL_MSG_NO_CASES
block|,
name|ASL_MSG_NO_RETVAL
block|,
name|ASL_MSG_NO_WHILE
block|,
name|ASL_MSG_NON_ASCII
block|,
name|ASL_MSG_NOT_EXIST
block|,
name|ASL_MSG_NOT_FOUND
block|,
name|ASL_MSG_NOT_METHOD
block|,
name|ASL_MSG_NOT_PARAMETER
block|,
name|ASL_MSG_NOT_REACHABLE
block|,
name|ASL_MSG_OPEN
block|,
name|ASL_MSG_OUTPUT_FILE_OPEN
block|,
name|ASL_MSG_OUTPUT_FILENAME
block|,
name|ASL_MSG_PACKAGE_LENGTH
block|,
name|ASL_MSG_READ
block|,
name|ASL_MSG_RECURSION
block|,
name|ASL_MSG_REGION_BUFFER_ACCESS
block|,
name|ASL_MSG_REGION_BYTE_ACCESS
block|,
name|ASL_MSG_RESERVED_ARG_COUNT_HI
block|,
name|ASL_MSG_RESERVED_ARG_COUNT_LO
block|,
name|ASL_MSG_RESERVED_METHOD
block|,
name|ASL_MSG_RESERVED_OPERAND_TYPE
block|,
name|ASL_MSG_RESERVED_RETURN_VALUE
block|,
name|ASL_MSG_RESERVED_USE
block|,
name|ASL_MSG_RESERVED_WORD
block|,
name|ASL_MSG_RESOURCE_FIELD
block|,
name|ASL_MSG_RESOURCE_INDEX
block|,
name|ASL_MSG_RESOURCE_LIST
block|,
name|ASL_MSG_RESOURCE_SOURCE
block|,
name|ASL_MSG_RETURN_TYPES
block|,
name|ASL_MSG_SCOPE_FWD_REF
block|,
name|ASL_MSG_SCOPE_TYPE
block|,
name|ASL_MSG_SEEK
block|,
name|ASL_MSG_SINGLE_NAME_OPTIMIZATION
block|,
name|ASL_MSG_SOME_NO_RETVAL
block|,
name|ASL_MSG_SWITCH_TYPE
block|,
name|ASL_MSG_SYNC_LEVEL
block|,
name|ASL_MSG_SYNTAX
block|,
name|ASL_MSG_TABLE_SIGNATURE
block|,
name|ASL_MSG_TOO_MANY_TEMPS
block|,
name|ASL_MSG_UNKNOWN_RESERVED_NAME
block|,
name|ASL_MSG_UNREACHABLE_CODE
block|,
name|ASL_MSG_UNSUPPORTED
block|,
name|ASL_MSG_VENDOR_LIST
block|,
name|ASL_MSG_WRITE
block|,
name|ASL_MSG_MULTIPLE_DEFAULT
block|,
name|ASL_MSG_TIMEOUT
block|,
name|ASL_MSG_RESULT_NOT_USED
block|,
name|ASL_MSG_NOT_REFERENCED
block|,
name|ASL_MSG_NON_ZERO
block|,
name|ASL_MSG_STRING_LENGTH
block|}
name|ASL_MESSAGE_IDS
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ASL_EXCEPTIONS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|AslMessages
index|[]
init|=
block|{
comment|/*    The zeroth message is resesrved */
literal|""
block|,
comment|/*    ASL_MSG_ALPHANUMERIC_STRING */
literal|"String must be entirely alphanumeric"
block|,
comment|/*    ASL_MSG_AML_NOT_IMPLEMENTED */
literal|"Opcode is not implemented in compiler AML code generator"
block|,
comment|/*    ASL_MSG_ARG_COUNT_HI */
literal|"Too many arguments"
block|,
comment|/*    ASL_MSG_ARG_COUNT_LO */
literal|"Too few arguments"
block|,
comment|/*    ASL_MSG_ARG_INIT */
literal|"Method argument is not initialized"
block|,
comment|/*    ASL_MSG_BACKWARDS_OFFSET */
literal|"Invalid backwards offset"
block|,
comment|/*    ASL_MSG_BITS_TO_BYTES */
literal|"Field offset is in bits, but a byte offset is required"
block|,
comment|/*    ASL_MSG_BUFFER_LENGTH */
literal|"Effective AML buffer length is zero"
block|,
comment|/*    ASL_MSG_BYTES_TO_BITS */
literal|"Field offset is in bytes, but a bit offset is required"
block|,
comment|/*    ASL_MSG_CLOSE */
literal|"Could not close file"
block|,
comment|/*    ASL_MSG_COMPILER_INTERNAL */
literal|"Internal compiler error"
block|,
comment|/*    ASL_MSG_CONSTANT_EVALUATION */
literal|"Could not evaluate constant expression"
block|,
comment|/*    ASL_MSG_CONSTANT_FOLDED */
literal|"Constant expression evaluated and reduced"
block|,
comment|/*    ASL_MSG_CORE_EXCEPTION */
literal|"From ACPI CA Subsystem"
block|,
comment|/*    ASL_MSG_DEBUG_FILE_OPEN */
literal|"Could not open debug file"
block|,
comment|/*    ASL_MSG_DEBUG_FILENAME */
literal|"Could not create debug filename"
block|,
comment|/*    ASL_MSG_DEPENDENT_NESTING */
literal|"Dependent function macros cannot be nested"
block|,\
comment|/*    ASL_MSG_DMA_CHANNEL */
literal|"Invalid DMA channel (must be 0-7)"
block|,
comment|/*    ASL_MSG_DMA_LIST */
literal|"Too many DMA channels (8 max)"
block|,
comment|/*    ASL_MSG_DUPLICATE_CASE */
literal|"Case value already specified"
block|,
comment|/*    ASL_MSG_DUPLICATE_ITEM */
literal|"Duplicate value in list"
block|,
comment|/*    ASL_MSG_EARLY_EOF */
literal|"Premature end-of-file reached"
block|,
comment|/*    ASL_MSG_ENCODING_LENGTH */
literal|"Package length too long to encode"
block|,
comment|/*    ASL_MSG_EX_INTERRUPT_LIST */
literal|"Too many interrupts (255 max)"
block|,
comment|/*    ASL_MSG_EX_INTERRUPT_NUMBER */
literal|"Invalid interrupt number (must be 32 bits)"
block|,
comment|/*    ASL_MSG_FIELD_ACCESS_WIDTH */
literal|"Access width is greater than region size"
block|,
comment|/*    ASL_MSG_FIELD_UNIT_ACCESS_WIDTH */
literal|"Access width of Field Unit extends beyond region limit"
block|,
comment|/*    ASL_MSG_FIELD_UNIT_OFFSET */
literal|"Field Unit extends beyond region limit"
block|,
comment|/*    ASL_MSG_INCLUDE_FILE_OPEN */
literal|"Could not open include file"
block|,
comment|/*    ASL_MSG_INPUT_FILE_OPEN */
literal|"Could not open input file"
block|,
comment|/*    ASL_MSG_INTEGER_LENGTH */
literal|"64-bit integer in 32-bit table, truncating"
block|,
comment|/*    ASL_MSG_INTEGER_OPTIMIZATION */
literal|"Integer optimized to single-byte AML opcode"
block|,
comment|/*    ASL_MSG_INTERRUPT_LIST */
literal|"Too many interrupts (16 max)"
block|,
comment|/*    ASL_MSG_INTERRUPT_NUMBER */
literal|"Invalid interrupt number (must be 0-15)"
block|,
comment|/*    ASL_MSG_INVALID_CONSTANT_OP */
literal|"Invalid operator in constant expression (not type 3/4/5)"
block|,
comment|/*    ASL_MSG_INVALID_EISAID */
literal|"EISAID string must be of the form \"UUUXXXX\" (3 uppercase, 4 hex digits)"
block|,
comment|/*    ASL_MSG_INVALID_ESCAPE */
literal|"Invalid or unknown escape sequence"
block|,
comment|/*    ASL_MSG_INVALID_OPERAND */
literal|"Invalid operand"
block|,
comment|/*    ASL_MSG_INVALID_PERFORMANCE */
literal|"Invalid performance/robustness value"
block|,
comment|/*    ASL_MSG_INVALID_PRIORITY */
literal|"Invalid priority value"
block|,
comment|/*    ASL_MSG_INVALID_STRING */
literal|"Invalid Hex/Octal Escape - Non-ASCII or NULL"
block|,
comment|/*    ASL_MSG_INVALID_TARGET */
literal|"Target operand not allowed in constant expression"
block|,
comment|/*    ASL_MSG_INVALID_TIME */
literal|"Time parameter too long (255 max)"
block|,
comment|/*    ASL_MSG_INVALID_TYPE */
literal|"Invalid type"
block|,
comment|/*    ASL_MSG_INVALID_UUID */
literal|"UUID string must be of the form \"aabbccdd-eeff-gghh-iijj-kkllmmnnoopp\""
block|,
comment|/*    ASL_MSG_LIST_LENGTH */
literal|"Initializer list too long"
block|,
comment|/*    ASL_MSG_LISTING_FILE_OPEN */
literal|"Could not open listing file"
block|,
comment|/*    ASL_MSG_LISTING_FILENAME */
literal|"Could not create listing filename"
block|,
comment|/*    ASL_MSG_LOCAL_INIT */
literal|"Method local variable is not initialized"
block|,
comment|/*    ASL_MSG_LONG_LINE */
literal|"Splitting long input line"
block|,
comment|/*    ASL_MSG_MEMORY_ALLOCATION */
literal|"Memory allocation failure"
block|,
comment|/*    ASL_MSG_MISSING_ENDDEPENDENT */
literal|"Missing EndDependentFn() macro in dependent resource list"
block|,
comment|/*    ASL_MSG_MISSING_STARTDEPENDENT */
literal|"Missing StartDependentFn() macro in dependent resource list"
block|,
comment|/*    ASL_MSG_MULTIPLE_TYPES */
literal|"Multiple types"
block|,
comment|/*    ASL_MSG_NAME_EXISTS */
literal|"Name already exists in scope"
block|,
comment|/*    ASL_MSG_NAME_OPTIMIZATION */
literal|"NamePath optimized"
block|,
comment|/*    ASL_MSG_NESTED_COMMENT */
literal|"Nested comment found"
block|,
comment|/*    ASL_MSG_NO_CASES */
literal|"No Case statements under Switch"
block|,
comment|/*    ASL_MSG_NO_RETVAL */
literal|"Called method returns no value"
block|,
comment|/*    ASL_MSG_NO_WHILE */
literal|"No enclosing While statement"
block|,
comment|/*    ASL_MSG_NON_ASCII */
literal|"Invalid characters found in file"
block|,
comment|/*    ASL_MSG_NOT_EXIST */
literal|"Object does not exist"
block|,
comment|/*    ASL_MSG_NOT_FOUND */
literal|"Object not found or not accessible from scope"
block|,
comment|/*    ASL_MSG_NOT_METHOD */
literal|"Not a control method, cannot invoke"
block|,
comment|/*    ASL_MSG_NOT_PARAMETER */
literal|"Not a parameter, used as local only"
block|,
comment|/*    ASL_MSG_NOT_REACHABLE */
literal|"Object is not accessible from this scope"
block|,
comment|/*    ASL_MSG_OPEN */
literal|"Could not open file"
block|,
comment|/*    ASL_MSG_OUTPUT_FILE_OPEN */
literal|"Could not open output AML file"
block|,
comment|/*    ASL_MSG_OUTPUT_FILENAME */
literal|"Could not create output filename"
block|,
comment|/*    ASL_MSG_PACKAGE_LENGTH */
literal|"Effective AML package length is zero"
block|,
comment|/*    ASL_MSG_READ */
literal|"Could not read file"
block|,
comment|/*    ASL_MSG_RECURSION */
literal|"Recursive method call"
block|,
comment|/*    ASL_MSG_REGION_BUFFER_ACCESS */
literal|"Host Operation Region requires BufferAcc access"
block|,
comment|/*    ASL_MSG_REGION_BYTE_ACCESS */
literal|"Host Operation Region requires ByteAcc access"
block|,
comment|/*    ASL_MSG_RESERVED_ARG_COUNT_HI */
literal|"Reserved method has too many arguments"
block|,
comment|/*    ASL_MSG_RESERVED_ARG_COUNT_LO */
literal|"Reserved method has too few arguments"
block|,
comment|/*    ASL_MSG_RESERVED_METHOD */
literal|"Reserved name must be a control method"
block|,
comment|/*    ASL_MSG_RESERVED_OPERAND_TYPE */
literal|"Invalid operand type for reserved name, must be"
block|,
comment|/*    ASL_MSG_RESERVED_RETURN_VALUE */
literal|"Reserved method must return a value"
block|,
comment|/*    ASL_MSG_RESERVED_USE */
literal|"Invalid use of reserved name"
block|,
comment|/*    ASL_MSG_RESERVED_WORD */
literal|"Use of reserved word"
block|,
comment|/*    ASL_MSG_RESOURCE_FIELD */
literal|"Resource field name cannot be used as a target"
block|,
comment|/*    ASL_MSG_RESOURCE_INDEX */
literal|"Missing ResourceSourceIndex (required)"
block|,
comment|/*    ASL_MSG_RESOURCE_LIST */
literal|"Too many resource items (internal error)"
block|,
comment|/*    ASL_MSG_RESOURCE_SOURCE */
literal|"Missing ResourceSource string (required)"
block|,
comment|/*    ASL_MSG_RETURN_TYPES */
literal|"Not all control paths return a value"
block|,
comment|/*    ASL_MSG_SCOPE_FWD_REF */
literal|"Forward references from Scope operator not allowed"
block|,
comment|/*    ASL_MSG_SCOPE_TYPE */
literal|"Existing object has invalid type for Scope operator"
block|,
comment|/*    ASL_MSG_SEEK */
literal|"Could not seek file"
block|,
comment|/*    ASL_MSG_SINGLE_NAME_OPTIMIZATION */
literal|"NamePath optimized to NameSeg (uses run-time search path)"
block|,
comment|/*    ASL_MSG_SOME_NO_RETVAL */
literal|"Called method may not always return a value"
block|,
comment|/*    ASL_MSG_SWITCH_TYPE */
literal|"Switch expression is not a static Integer/Buffer/String data type, defaulting to Integer"
block|,
comment|/*    ASL_MSG_SYNC_LEVEL */
literal|"SyncLevel must be in the range 0-15"
block|,
comment|/*    ASL_MSG_SYNTAX */
literal|""
block|,
comment|/*    ASL_MSG_TABLE_SIGNATURE */
literal|"Invalid Table Signature"
block|,
comment|/*    ASL_MSG_TOO_MANY_TEMPS */
literal|"Method requires too many temporary variables (_T_x)"
block|,
comment|/*    ASL_MSG_UNKNOWN_RESERVED_NAME */
literal|"Unknown reserved name"
block|,
comment|/*    ASL_MSG_UNREACHABLE_CODE */
literal|"Statement is unreachable"
block|,
comment|/*    ASL_MSG_UNSUPPORTED */
literal|"Unsupported feature"
block|,
comment|/*    ASL_MSG_VENDOR_LIST */
literal|"Too many vendor data bytes (7 max)"
block|,
comment|/*    ASL_MSG_WRITE */
literal|"Could not write file"
block|,
comment|/*    ASL_MSG_MULTIPLE_DEFAULT */
literal|"More than one Default statement within Switch construct"
block|,
comment|/*    ASL_MSG_TIMEOUT */
literal|"Possible operator timeout is ignored"
block|,
comment|/*    ASL_MSG_RESULT_NOT_USED */
literal|"Result is not used, operator has no effect"
block|,
comment|/*    ASL_MSG_NOT_REFERENCED */
literal|"Namespace object is not referenced"
block|,
comment|/*    ASL_MSG_NON_ZERO */
literal|"Operand evaluates to zero"
block|,
comment|/*    ASL_MSG_STRING_LENGTH */
literal|"String literal too long"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|AslErrorLevel
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
init|=
block|{
literal|"Warning "
block|,
literal|"Warning "
block|,
literal|"Warning "
block|,
literal|"Error   "
block|,
literal|"Remark  "
block|,
literal|"Optimize"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASL_ERROR_LEVEL_LENGTH
value|8
end_define

begin_comment
comment|/* Length of strings above */
end_comment

begin_comment
comment|/* Exception counters */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLTYPES_H */
end_comment

end_unit

