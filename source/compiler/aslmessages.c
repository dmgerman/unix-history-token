begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslmessages.c - Compiler error/warning message strings  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"aslcompiler.h"
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
literal|"aslmessages"
argument_list|)
end_macro

begin_comment
comment|/*  * Strings for message reporting levels, must match error  * type string tables in aslmessages.c  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AslErrorLevel
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
init|=
block|{
literal|"Optimize"
block|,
literal|"Remark  "
block|,
literal|"Warning "
block|,
literal|"Warning "
block|,
literal|"Warning "
block|,
literal|"Error   "
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All lowercase versions for IDEs */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AslErrorLevelIde
index|[
name|ASL_NUM_REPORT_LEVELS
index|]
init|=
block|{
literal|"optimize"
block|,
literal|"remark  "
block|,
literal|"warning "
block|,
literal|"warning "
block|,
literal|"warning "
block|,
literal|"error   "
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Actual message strings for each compiler message ID. There are currently  * three distinct blocks of error messages (so that they can be expanded  * individually):  *      Main ASL compiler  *      Data Table compiler  *      Preprocessor  *  * NOTE1: These tables must match the enum list of message IDs in the file  * aslmessages.h exactly.  *  * NOTE2: With the introduction of the -vw option to disable specific messages,  * new messages should only be added to the end of this list, so that values  * for existing messages are not disturbed.  */
end_comment

begin_comment
comment|/* ASL compiler */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AslCompilerMsgs
index|[]
init|=
block|{
comment|/*    The zeroth message is reserved */
literal|""
block|,
comment|/*    ASL_MSG_ALIGNMENT */
literal|"Must be a multiple of alignment/granularity value"
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
comment|/*    ASL_MSG_BUFFER_LENGTH */
literal|"Effective AML buffer length is zero"
block|,
comment|/*    ASL_MSG_CLOSE */
literal|"Could not close file"
block|,
comment|/*    ASL_MSG_COMPILER_INTERNAL */
literal|"Internal compiler error"
block|,
comment|/*    ASL_MSG_COMPILER_RESERVED */
literal|"Use of compiler reserved name"
block|,
comment|/*    ASL_MSG_CONNECTION_MISSING */
literal|"A Connection operator is required for this field SpaceId"
block|,
comment|/*    ASL_MSG_CONNECTION_INVALID */
literal|"Invalid OpRegion SpaceId for use of Connection operator"
block|,
comment|/*    ASL_MSG_CONSTANT_EVALUATION */
literal|"Could not evaluate constant expression"
block|,
comment|/*    ASL_MSG_CONSTANT_FOLDED */
literal|"Constant expression evaluated and reduced"
block|,
comment|/*    ASL_MSG_CORE_EXCEPTION */
literal|"From ACPICA Subsystem"
block|,
comment|/*    ASL_MSG_DEBUG_FILE_OPEN */
literal|"Could not open debug file"
block|,
comment|/*    ASL_MSG_DEBUG_FILENAME */
literal|"Could not create debug filename"
block|,
comment|/*    ASL_MSG_DEPENDENT_NESTING */
literal|"Dependent function macros cannot be nested"
block|,
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
comment|/*    ASL_MSG_GPE_NAME_CONFLICT */
literal|"Name conflicts with a previous GPE method"
block|,
comment|/*    ASL_MSG_HID_LENGTH */
literal|"_HID string must be exactly 7 or 8 characters"
block|,
comment|/*    ASL_MSG_HID_PREFIX */
literal|"_HID prefix must be all uppercase or decimal digits"
block|,
comment|/*    ASL_MSG_HID_SUFFIX */
literal|"_HID suffix must be all hex digits"
block|,
comment|/*    ASL_MSG_INCLUDE_FILE_OPEN */
literal|"Could not open include file"
block|,
comment|/*    ASL_MSG_INPUT_FILE_OPEN */
literal|"Could not open input file"
block|,
comment|/*    ASL_MSG_INTEGER_LENGTH */
literal|"64-bit integer in 32-bit table, truncating (DSDT or SSDT version< 2)"
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
comment|/*    ASL_MSG_INVALID_ACCESS_SIZE */
literal|"Invalid AccessSize (Maximum is 4 - QWord access)"
block|,
comment|/*    ASL_MSG_INVALID_ADDR_FLAGS */
literal|"Invalid combination of Length and Min/Max fixed flags"
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
comment|/*    ASL_MSG_INVALID_GRAN_FIXED */
literal|"Granularity must be zero for fixed Min/Max"
block|,
comment|/*    ASL_MSG_INVALID_GRANULARITY */
literal|"Granularity must be zero or a power of two minus one"
block|,
comment|/*    ASL_MSG_INVALID_LENGTH */
literal|"Length is larger than Min/Max window"
block|,
comment|/*    ASL_MSG_INVALID_LENGTH_FIXED */
literal|"Length is not equal to fixed Min/Max window"
block|,
comment|/*    ASL_MSG_INVALID_MIN_MAX */
literal|"Address Min is greater than Address Max"
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
comment|/*    ASL_MSG_ISA_ADDRESS */
literal|"Maximum 10-bit ISA address (0x3FF)"
block|,
comment|/*    ASL_MSG_LEADING_ASTERISK */
literal|"Invalid leading asterisk"
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
comment|/*    ASL_MSG_LOCAL_OUTSIDE_METHOD */
literal|"Local or Arg used outside a control method"
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
comment|/*    ASL_MSG_MULTIPLE_DEFAULT */
literal|"More than one Default statement within Switch construct"
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
comment|/*    ASL_MSG_NAMED_OBJECT_IN_WHILE */
literal|"Creating a named object in a While loop"
block|,
comment|/*    ASL_MSG_NESTED_COMMENT */
literal|"Nested comment found"
block|,
comment|/*    ASL_MSG_NO_CASES */
literal|"No Case statements under Switch"
block|,
comment|/*    ASL_MSG_NO_REGION */
literal|"_REG has no corresponding Operation Region"
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
comment|/*    ASL_MSG_NON_ZERO */
literal|"Operand evaluates to zero"
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
comment|/*    ASL_MSG_NOT_REFERENCED */
literal|"Object is not referenced"
block|,
comment|/*    ASL_MSG_NULL_DESCRIPTOR */
literal|"Min/Max/Length/Gran are all zero, but no resource tag"
block|,
comment|/*    ASL_MSG_NULL_STRING */
literal|"Invalid zero-length (null) string"
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
comment|/*    ASL_MSG_PREPROCESSOR_FILENAME */
literal|"Could not create preprocessor filename"
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
comment|/*    ASL_MSG_RESERVED_NO_RETURN_VAL */
literal|"Reserved method should not return a value"
block|,
comment|/*    ASL_MSG_RESERVED_OPERAND_TYPE */
literal|"Invalid object type for reserved name"
block|,
comment|/*    ASL_MSG_RESERVED_PACKAGE_LENGTH */
literal|"Invalid package length for reserved name"
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
comment|/*    ASL_MSG_RESULT_NOT_USED */
literal|"Result is not used, operator has no effect"
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
comment|/*    ASL_MSG_SERIALIZED */
literal|"Control Method marked Serialized"
block|,
comment|/*    ASL_MSG_SERIALIZED_REQUIRED */
literal|"Control Method should be made Serialized"
block|,
comment|/*    ASL_MSG_SINGLE_NAME_OPTIMIZATION */
literal|"NamePath optimized to NameSeg (uses run-time search path)"
block|,
comment|/*    ASL_MSG_SOME_NO_RETVAL */
literal|"Called method may not always return a value"
block|,
comment|/*    ASL_MSG_STRING_LENGTH */
literal|"String literal too long"
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
comment|/*    ASL_MSG_TAG_LARGER */
literal|"ResourceTag larger than Field"
block|,
comment|/*    ASL_MSG_TAG_SMALLER */
literal|"ResourceTag smaller than Field"
block|,
comment|/*    ASL_MSG_TIMEOUT */
literal|"Result is not used, possible operator timeout will be missed"
block|,
comment|/*    ASL_MSG_TOO_MANY_TEMPS */
literal|"Method requires too many temporary variables (_T_x)"
block|,
comment|/*    ASL_MSG_TRUNCATION */
literal|"64-bit return value will be truncated to 32 bits (DSDT or SSDT version< 2)"
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
comment|/*    ASL_MSG_UPPER_CASE */
literal|"Non-hex letters must be upper case"
block|,
comment|/*    ASL_MSG_VENDOR_LIST */
literal|"Too many vendor data bytes (7 max)"
block|,
comment|/*    ASL_MSG_WRITE */
literal|"Could not write file"
block|,
comment|/*    ASL_MSG_RANGE */
literal|"Constant out of range"
block|,
comment|/*    ASL_MSG_BUFFER_ALLOCATION */
literal|"Could not allocate line buffer"
block|,
comment|/*    ASL_MSG_MISSING_DEPENDENCY */
literal|"Missing dependency"
block|,
comment|/*    ASL_MSG_ILLEGAL_FORWARD_REF */
literal|"Illegal forward reference within a method"
block|,
comment|/*    ASL_MSG_ILLEGAL_METHOD_REF */
literal|"Illegal reference across two methods"
block|,
comment|/*    ASL_MSG_LOCAL_NOT_USED */
literal|"Method Local is set but never used"
block|,
comment|/*    ASL_MSG_ARG_AS_LOCAL_NOT_USED */
literal|"Method Argument (as a local) is set but never used"
block|,
comment|/*    ASL_MSG_ARG_NOT_USED */
literal|"Method Argument is never used"
block|,
comment|/*    ASL_MSG_CONSTANT_REQUIRED */
literal|"Non-reducible expression"
block|,
comment|/*    ASL_MSG_CROSS_TABLE_SCOPE */
literal|"Illegal open scope on external object from within DSDT"
block|,
comment|/*    ASL_MSG_EXCEPTION_NOT_RECEIVED */
literal|"Expected remark, warning, or error did not occur. Message ID:"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table compiler */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AslTableCompilerMsgs
index|[]
init|=
block|{
comment|/*    ASL_MSG_BUFFER_ELEMENT */
literal|"Invalid element in buffer initializer list"
block|,
comment|/*    ASL_MSG_DIVIDE_BY_ZERO */
literal|"Expression contains divide-by-zero"
block|,
comment|/*    ASL_MSG_FLAG_VALUE */
literal|"Flag value is too large"
block|,
comment|/*    ASL_MSG_INTEGER_SIZE */
literal|"Integer too large for target"
block|,
comment|/*    ASL_MSG_INVALID_EXPRESSION */
literal|"Invalid expression"
block|,
comment|/*    ASL_MSG_INVALID_FIELD_NAME */
literal|"Invalid Field Name"
block|,
comment|/*    ASL_MSG_INVALID_HEX_INTEGER */
literal|"Invalid hex integer constant"
block|,
comment|/*    ASL_MSG_OEM_TABLE */
literal|"OEM table - unknown contents"
block|,
comment|/*    ASL_MSG_RESERVED_VALUE */
literal|"Reserved field"
block|,
comment|/*    ASL_MSG_UNKNOWN_LABEL */
literal|"Label is undefined"
block|,
comment|/*    ASL_MSG_UNKNOWN_SUBTABLE */
literal|"Unknown subtable type"
block|,
comment|/*    ASL_MSG_UNKNOWN_TABLE */
literal|"Unknown ACPI table signature"
block|,
comment|/*    ASL_MSG_ZERO_VALUE */
literal|"Value must be non-zero"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Preprocessor */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AslPreprocessorMsgs
index|[]
init|=
block|{
comment|/*    ASL_MSG_DIRECTIVE_SYNTAX */
literal|"Invalid directive syntax"
block|,
comment|/*    ASL_MSG_ENDIF_MISMATCH */
literal|"Mismatched #endif"
block|,
comment|/*    ASL_MSG_ERROR_DIRECTIVE */
literal|"#error"
block|,
comment|/*    ASL_MSG_EXISTING_NAME */
literal|"Name is already defined"
block|,
comment|/*    ASL_MSG_INVALID_INVOCATION */
literal|"Invalid macro invocation"
block|,
comment|/*    ASL_MSG_MACRO_SYNTAX */
literal|"Invalid macro syntax"
block|,
comment|/*    ASL_MSG_TOO_MANY_ARGUMENTS */
literal|"Too many macro arguments"
block|,
comment|/*    ASL_MSG_UNKNOWN_DIRECTIVE */
literal|"Unknown directive"
block|,
comment|/*    ASL_MSG_UNKNOWN_PRAGMA */
literal|"Unknown pragma"
block|,
comment|/*    ASL_MSG_WARNING_DIRECTIVE */
literal|"#warning"
block|,
comment|/*    ASL_MSG_INCLUDE_FILE */
literal|"Found a # preprocessor directive in ASL Include() file"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AeDecodeMessageId  *  * PARAMETERS:  MessageId               - ASL message ID (exception code) to be  *                                        formatted. Possibly fully encoded.  *  * RETURN:      A string containing the exception message text.  *  * DESCRIPTION: This function validates and translates an ASL message ID into  *              an ASCII string.  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|AeDecodeMessageId
parameter_list|(
name|UINT16
name|MessageId
parameter_list|)
block|{
name|UINT32
name|Index
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|MessageTable
decl_stmt|;
comment|/* Main ASL Compiler messages */
if|if
condition|(
name|MessageId
operator|<=
name|ASL_MSG_MAIN_COMPILER_END
condition|)
block|{
name|MessageTable
operator|=
name|AslCompilerMsgs
expr_stmt|;
name|Index
operator|=
name|MessageId
expr_stmt|;
if|if
condition|(
name|Index
operator|>=
name|ACPI_ARRAY_LENGTH
argument_list|(
name|AslCompilerMsgs
argument_list|)
condition|)
block|{
return|return
operator|(
literal|"[Unknown ASL Compiler exception ID]"
operator|)
return|;
block|}
block|}
comment|/* Data Table Compiler messages */
elseif|else
if|if
condition|(
name|MessageId
operator|<=
name|ASL_MSG_TABLE_COMPILER_END
condition|)
block|{
name|MessageTable
operator|=
name|AslTableCompilerMsgs
expr_stmt|;
name|Index
operator|=
name|MessageId
operator|-
name|ASL_MSG_TABLE_COMPILER
expr_stmt|;
if|if
condition|(
name|Index
operator|>=
name|ACPI_ARRAY_LENGTH
argument_list|(
name|AslTableCompilerMsgs
argument_list|)
condition|)
block|{
return|return
operator|(
literal|"[Unknown Table Compiler exception ID]"
operator|)
return|;
block|}
block|}
comment|/* Preprocessor messages */
elseif|else
if|if
condition|(
name|MessageId
operator|<=
name|ASL_MSG_PREPROCESSOR_END
condition|)
block|{
name|MessageTable
operator|=
name|AslPreprocessorMsgs
expr_stmt|;
name|Index
operator|=
name|MessageId
operator|-
name|ASL_MSG_PREPROCESSOR
expr_stmt|;
if|if
condition|(
name|Index
operator|>=
name|ACPI_ARRAY_LENGTH
argument_list|(
name|AslPreprocessorMsgs
argument_list|)
condition|)
block|{
return|return
operator|(
literal|"[Unknown Preprocessor exception ID]"
operator|)
return|;
block|}
block|}
comment|/* Everything else is unknown */
else|else
block|{
return|return
operator|(
literal|"[Unknown exception/component ID]"
operator|)
return|;
block|}
return|return
operator|(
name|MessageTable
index|[
name|Index
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AeDecodeExceptionLevel  *  * PARAMETERS:  Level               - The ASL error level to be decoded  *  * RETURN:      A string containing the error level text  *  * DESCRIPTION: This function validates and translates an ASL error level into  *              an ASCII string.  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|AeDecodeExceptionLevel
parameter_list|(
name|UINT8
name|Level
parameter_list|)
block|{
comment|/* Range check on Level */
if|if
condition|(
name|Level
operator|>=
name|ACPI_ARRAY_LENGTH
argument_list|(
name|AslErrorLevel
argument_list|)
condition|)
block|{
return|return
operator|(
literal|"Unknown exception level"
operator|)
return|;
block|}
comment|/* Differentiate the string type to be used (IDE is all lower case) */
if|if
condition|(
name|Gbl_VerboseErrors
condition|)
block|{
return|return
operator|(
name|AslErrorLevel
index|[
name|Level
index|]
operator|)
return|;
block|}
return|return
operator|(
name|AslErrorLevelIde
index|[
name|Level
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AeBuildFullExceptionCode  *  * PARAMETERS:  Level               - ASL error level  *              MessageId           - ASL exception code to be formatted  *  * RETURN:      Fully encoded exception code  *  * DESCRIPTION: Build the full exception code from the error level and the  *              actual message ID.  *  ******************************************************************************/
end_comment

begin_function
name|UINT16
name|AeBuildFullExceptionCode
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|)
block|{
comment|/*      * Error level is in the thousands slot (error/warning/remark, etc.)      * Error codes are 0 - 999      */
return|return
operator|(
operator|(
operator|(
name|Level
operator|+
literal|1
operator|)
operator|*
literal|1000
operator|)
operator|+
name|MessageId
operator|)
return|;
block|}
end_function

end_unit

