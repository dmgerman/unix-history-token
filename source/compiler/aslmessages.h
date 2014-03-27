begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslmessages.h - Compiler error/warning messages  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|ASL_OPTIMIZATION
init|=
literal|0
block|,
name|ASL_REMARK
block|,
name|ASL_WARNING
block|,
name|ASL_WARNING2
block|,
name|ASL_WARNING3
block|,
name|ASL_ERROR
block|,
name|ASL_NUM_REPORT_LEVELS
block|}
name|ASL_MESSAGE_TYPES
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ASL_EXCEPTIONS
end_ifdef

begin_comment
comment|/* Strings for message reporting levels, must match values above */
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
comment|/*  * Values for all compiler messages.  *  * NOTE: With the introduction of the -vw option to disable specific messages,  * new messages should only be added to the end of this list, so that values  * for existing messages are not disturbed.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ASL_MSG_RESERVED
init|=
literal|0
block|,
name|ASL_MSG_ALIGNMENT
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
name|ASL_MSG_BUFFER_LENGTH
block|,
name|ASL_MSG_CLOSE
block|,
name|ASL_MSG_COMPILER_INTERNAL
block|,
name|ASL_MSG_COMPILER_RESERVED
block|,
name|ASL_MSG_CONNECTION_MISSING
block|,
name|ASL_MSG_CONNECTION_INVALID
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
name|ASL_MSG_GPE_NAME_CONFLICT
block|,
name|ASL_MSG_HID_LENGTH
block|,
name|ASL_MSG_HID_PREFIX
block|,
name|ASL_MSG_HID_SUFFIX
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
name|ASL_MSG_INVALID_ACCESS_SIZE
block|,
name|ASL_MSG_INVALID_ADDR_FLAGS
block|,
name|ASL_MSG_INVALID_CONSTANT_OP
block|,
name|ASL_MSG_INVALID_EISAID
block|,
name|ASL_MSG_INVALID_ESCAPE
block|,
name|ASL_MSG_INVALID_GRAN_FIXED
block|,
name|ASL_MSG_INVALID_GRANULARITY
block|,
name|ASL_MSG_INVALID_LENGTH
block|,
name|ASL_MSG_INVALID_LENGTH_FIXED
block|,
name|ASL_MSG_INVALID_MIN_MAX
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
name|ASL_MSG_ISA_ADDRESS
block|,
name|ASL_MSG_LEADING_ASTERISK
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
name|ASL_MSG_LOCAL_OUTSIDE_METHOD
block|,
name|ASL_MSG_LONG_LINE
block|,
name|ASL_MSG_MEMORY_ALLOCATION
block|,
name|ASL_MSG_MISSING_ENDDEPENDENT
block|,
name|ASL_MSG_MISSING_STARTDEPENDENT
block|,
name|ASL_MSG_MULTIPLE_DEFAULT
block|,
name|ASL_MSG_MULTIPLE_TYPES
block|,
name|ASL_MSG_NAME_EXISTS
block|,
name|ASL_MSG_NAME_OPTIMIZATION
block|,
name|ASL_MSG_NAMED_OBJECT_IN_WHILE
block|,
name|ASL_MSG_NESTED_COMMENT
block|,
name|ASL_MSG_NO_CASES
block|,
name|ASL_MSG_NO_REGION
block|,
name|ASL_MSG_NO_RETVAL
block|,
name|ASL_MSG_NO_WHILE
block|,
name|ASL_MSG_NON_ASCII
block|,
name|ASL_MSG_NON_ZERO
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
name|ASL_MSG_NOT_REFERENCED
block|,
name|ASL_MSG_NULL_DESCRIPTOR
block|,
name|ASL_MSG_NULL_STRING
block|,
name|ASL_MSG_OPEN
block|,
name|ASL_MSG_OUTPUT_FILE_OPEN
block|,
name|ASL_MSG_OUTPUT_FILENAME
block|,
name|ASL_MSG_PACKAGE_LENGTH
block|,
name|ASL_MSG_PREPROCESSOR_FILENAME
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
name|ASL_MSG_RESERVED_NO_RETURN_VAL
block|,
name|ASL_MSG_RESERVED_OPERAND_TYPE
block|,
name|ASL_MSG_RESERVED_PACKAGE_LENGTH
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
name|ASL_MSG_RESULT_NOT_USED
block|,
name|ASL_MSG_RETURN_TYPES
block|,
name|ASL_MSG_SCOPE_FWD_REF
block|,
name|ASL_MSG_SCOPE_TYPE
block|,
name|ASL_MSG_SEEK
block|,
name|ASL_MSG_SERIALIZED
block|,
name|ASL_MSG_SERIALIZED_REQUIRED
block|,
name|ASL_MSG_SINGLE_NAME_OPTIMIZATION
block|,
name|ASL_MSG_SOME_NO_RETVAL
block|,
name|ASL_MSG_STRING_LENGTH
block|,
name|ASL_MSG_SWITCH_TYPE
block|,
name|ASL_MSG_SYNC_LEVEL
block|,
name|ASL_MSG_SYNTAX
block|,
name|ASL_MSG_TABLE_SIGNATURE
block|,
name|ASL_MSG_TAG_LARGER
block|,
name|ASL_MSG_TAG_SMALLER
block|,
name|ASL_MSG_TIMEOUT
block|,
name|ASL_MSG_TOO_MANY_TEMPS
block|,
name|ASL_MSG_TRUNCATION
block|,
name|ASL_MSG_UNKNOWN_RESERVED_NAME
block|,
name|ASL_MSG_UNREACHABLE_CODE
block|,
name|ASL_MSG_UNSUPPORTED
block|,
name|ASL_MSG_UPPER_CASE
block|,
name|ASL_MSG_VENDOR_LIST
block|,
name|ASL_MSG_WRITE
block|,
name|ASL_MSG_RANGE
block|,
name|ASL_MSG_BUFFER_ALLOCATION
block|,
comment|/* These messages are used by the Preprocessor only */
name|ASL_MSG_DIRECTIVE_SYNTAX
block|,
name|ASL_MSG_ENDIF_MISMATCH
block|,
name|ASL_MSG_ERROR_DIRECTIVE
block|,
name|ASL_MSG_EXISTING_NAME
block|,
name|ASL_MSG_INVALID_INVOCATION
block|,
name|ASL_MSG_MACRO_SYNTAX
block|,
name|ASL_MSG_TOO_MANY_ARGUMENTS
block|,
name|ASL_MSG_UNKNOWN_DIRECTIVE
block|,
name|ASL_MSG_UNKNOWN_PRAGMA
block|,
name|ASL_MSG_WARNING_DIRECTIVE
block|,
comment|/* These messages are used by the data table compiler only */
name|ASL_MSG_BUFFER_ELEMENT
block|,
name|ASL_MSG_DIVIDE_BY_ZERO
block|,
name|ASL_MSG_FLAG_VALUE
block|,
name|ASL_MSG_INTEGER_SIZE
block|,
name|ASL_MSG_INVALID_EXPRESSION
block|,
name|ASL_MSG_INVALID_FIELD_NAME
block|,
name|ASL_MSG_INVALID_HEX_INTEGER
block|,
name|ASL_MSG_OEM_TABLE
block|,
name|ASL_MSG_RESERVED_VALUE
block|,
name|ASL_MSG_UNKNOWN_LABEL
block|,
name|ASL_MSG_UNKNOWN_SUBTABLE
block|,
name|ASL_MSG_UNKNOWN_TABLE
block|,
name|ASL_MSG_ZERO_VALUE
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
comment|/*  * Actual message strings for each compiler message.  *  * NOTE: With the introduction of the -vw option to disable specific messages,  * new messages should only be added to the end of this list, so that values  * for existing messages are not disturbed.  */
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
literal|"64-bit integer in 32-bit table, truncating (DSDT version< 2)"
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
literal|"64-bit return value will be truncated to 32 bits (DSDT version< 2)"
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
comment|/* Preprocessor */
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
comment|/* Table compiler */
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

