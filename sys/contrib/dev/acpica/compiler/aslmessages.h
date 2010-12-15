begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslmessages.h - Compiler error/warning messages  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2010, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLMESSAGES_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLMESSAGES_H
end_define

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

begin_comment
comment|/* Values for all compiler messages */
end_comment

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
name|ASL_MSG_EX_INTERRUPT_LIST_MIN
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
name|ASL_MSG_LIST_LENGTH_LONG
block|,
name|ASL_MSG_LIST_LENGTH_SHORT
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
block|,
name|ASL_MSG_SERIALIZED
block|,
name|ASL_MSG_COMPILER_RESERVED
block|,
name|ASL_MSG_NAMED_OBJECT_IN_WHILE
block|,
name|ASL_MSG_LOCAL_OUTSIDE_METHOD
block|,
name|ASL_MSG_ALIGNMENT
block|,
name|ASL_MSG_ISA_ADDRESS
block|,
name|ASL_MSG_INVALID_MIN_MAX
block|,
name|ASL_MSG_INVALID_LENGTH
block|,
name|ASL_MSG_INVALID_LENGTH_FIXED
block|,
name|ASL_MSG_INVALID_GRANULARITY
block|,
name|ASL_MSG_INVALID_GRAN_FIXED
block|,
name|ASL_MSG_INVALID_ACCESS_SIZE
block|,
name|ASL_MSG_INVALID_ADDR_FLAGS
block|,
name|ASL_MSG_NULL_DESCRIPTOR
block|,
name|ASL_MSG_UPPER_CASE
block|,
name|ASL_MSG_HID_LENGTH
block|,
name|ASL_MSG_NULL_STRING
block|,
name|ASL_MSG_LEADING_ASTERISK
block|,
name|ASL_MSG_INVALID_FIELD_NAME
block|,
name|ASL_MSG_INTEGER_SIZE
block|,
name|ASL_MSG_INVALID_HEX_INTEGER
block|,
name|ASL_MSG_BUFFER_ELEMENT
block|,
name|ASL_MSG_RESERVED_VALUE
block|,
name|ASL_MSG_FLAG_VALUE
block|,
name|ASL_MSG_ZERO_VALUE
block|,
name|ASL_MSG_UNKNOWN_TABLE
block|,
name|ASL_MSG_UNKNOWN_SUBTABLE
block|,
name|ASL_MSG_OEM_TABLE
block|}
name|ASL_MESSAGE_IDS
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ASL_EXCEPTIONS
end_ifdef

begin_comment
comment|/* Actual message strings for each compiler message */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AslMessages
index|[]
init|=
block|{
comment|/*    The zeroth message is reserved */
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
comment|/*    ASL_MSG_EX_INTERRUPT_LIST_MIN */
literal|"Too few interrupts (1 minimum required)"
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
comment|/*    ASL_MSG_LIST_LENGTH_LONG */
literal|"Initializer list longer than declared package length"
block|,
comment|/*    ASL_MSG_LIST_LENGTH_SHORT */
literal|"Initializer list shorter than declared package length"
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
literal|"Invalid object type for reserved name"
block|,
comment|/*    ASL_MSG_RESERVED_RETURN_VALUE */
literal|"Reserved method must return a value"
block|,
comment|/*    ASL_MSG_RESERVED_USE */
literal|"Invalid use of reserved name"
block|,
comment|/*    ASL_MSG_RESERVED_WORD */
literal|"Use of reserved name"
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
literal|"Result is not used, possible operator timeout will be missed"
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
block|,
comment|/*    ASL_MSG_SERIALIZED */
literal|"Control Method marked Serialized"
block|,
comment|/*    ASL_MSG_COMPILER_RESERVED */
literal|"Use of compiler reserved name"
block|,
comment|/*    ASL_MSG_NAMED_OBJECT_IN_WHILE */
literal|"Creating a named object in a While loop"
block|,
comment|/*    ASL_MSG_LOCAL_OUTSIDE_METHOD */
literal|"Local or Arg used outside a control method"
block|,
comment|/*    ASL_MSG_ALIGNMENT */
literal|"Must be a multiple of alignment/granularity value"
block|,
comment|/*    ASL_MSG_ISA_ADDRESS */
literal|"Maximum 10-bit ISA address (0x3FF)"
block|,
comment|/*    ASL_MSG_INVALID_MIN_MAX */
literal|"Address Min is greater than Address Max"
block|,
comment|/*    ASL_MSG_INVALID_LENGTH */
literal|"Length is larger than Min/Max window"
block|,
comment|/*    ASL_MSG_INVALID_LENGTH_FIXED */
literal|"Length is not equal to fixed Min/Max window"
block|,
comment|/*    ASL_MSG_INVALID_GRANULARITY */
literal|"Granularity must be zero or a power of two minus one"
block|,
comment|/*    ASL_MSG_INVALID_GRAN_FIXED */
literal|"Granularity must be zero for fixed Min/Max"
block|,
comment|/*    ASL_MSG_INVALID_ACCESS_SIZE */
literal|"Invalid AccessSize (Maximum is 4 - QWord access)"
block|,
comment|/*    ASL_MSG_INVALID_ADDR_FLAGS */
literal|"Invalid combination of Length and Min/Max fixed flags"
block|,
comment|/*    ASL_MSG_NULL_DESCRIPTOR */
literal|"Min/Max/Length/Gran are all zero, but no resource tag"
block|,
comment|/*    ASL_MSG_UPPER_CASE */
literal|"Non-hex letters must be upper case"
block|,
comment|/*    ASL_MSG_HID_LENGTH */
literal|"_HID string must be exactly 7 or 8 characters"
block|,
comment|/*    ASL_MSG_NULL_STRING */
literal|"Invalid zero-length (null) string"
block|,
comment|/*    ASL_MSG_LEADING_ASTERISK */
literal|"Invalid leading asterisk"
block|,
comment|/* These messages are used by the data table compiler only */
comment|/*    ASL_MSG_INVALID_FIELD_NAME */
literal|"Invalid Field Name"
block|,
comment|/*    ASL_MSG_INTEGER_SIZE */
literal|"Integer too large for target"
block|,
comment|/*    ASL_MSG_INVALID_HEX_INTEGER */
literal|"Invalid hex integer constant"
block|,
comment|/*    ASL_MSG_BUFFER_ELEMENT */
literal|"Invalid element in buffer initializer list"
block|,
comment|/*    ASL_MSG_RESERVED_VALUE */
literal|"Reserved field must be zero"
block|,
comment|/*    ASL_MSG_FLAG_VALUE */
literal|"Flag value is too large"
block|,
comment|/*    ASL_MSG_ZERO_VALUE */
literal|"Value must be non-zero"
block|,
comment|/*    ASL_MSG_UNKNOWN_TABLE */
literal|"Unknown ACPI table signature"
block|,
comment|/*    ASL_MSG_UNKNOWN_SUBTABLE */
literal|"Unknown subtable type"
block|,
comment|/*    ASL_MSG_OEM_TABLE */
literal|"OEM table - unknown contents"
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASL_EXCEPTIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASLMESSAGES_H */
end_comment

end_unit

