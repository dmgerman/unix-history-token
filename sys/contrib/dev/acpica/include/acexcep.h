begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acexcep.h - Exception codes returned by the ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACEXCEP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACEXCEP_H__
end_define

begin_comment
comment|/*  * Exceptions returned by external ACPI interfaces  */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_ENVIRONMENTAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|AE_CODE_PROGRAMMER
value|0x1000
end_define

begin_define
define|#
directive|define
name|AE_CODE_ACPI_TABLES
value|0x2000
end_define

begin_define
define|#
directive|define
name|AE_CODE_AML
value|0x3000
end_define

begin_define
define|#
directive|define
name|AE_CODE_CONTROL
value|0x4000
end_define

begin_define
define|#
directive|define
name|AE_CODE_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|ACPI_SUCCESS
parameter_list|(
name|a
parameter_list|)
value|(!(a))
end_define

begin_define
define|#
directive|define
name|ACPI_FAILURE
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|AE_OK
value|(ACPI_STATUS) 0x0000
end_define

begin_comment
comment|/*  * Environmental exceptions  */
end_comment

begin_define
define|#
directive|define
name|AE_ERROR
value|(ACPI_STATUS) (0x0001 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_ACPI_TABLES
value|(ACPI_STATUS) (0x0002 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_NAMESPACE
value|(ACPI_STATUS) (0x0003 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_MEMORY
value|(ACPI_STATUS) (0x0004 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NOT_FOUND
value|(ACPI_STATUS) (0x0005 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NOT_EXIST
value|(ACPI_STATUS) (0x0006 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ALREADY_EXISTS
value|(ACPI_STATUS) (0x0007 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_TYPE
value|(ACPI_STATUS) (0x0008 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NULL_OBJECT
value|(ACPI_STATUS) (0x0009 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NULL_ENTRY
value|(ACPI_STATUS) (0x000A | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_BUFFER_OVERFLOW
value|(ACPI_STATUS) (0x000B | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_STACK_OVERFLOW
value|(ACPI_STATUS) (0x000C | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_STACK_UNDERFLOW
value|(ACPI_STATUS) (0x000D | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NOT_IMPLEMENTED
value|(ACPI_STATUS) (0x000E | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_SUPPORT
value|(ACPI_STATUS) (0x000F | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_LIMIT
value|(ACPI_STATUS) (0x0010 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_TIME
value|(ACPI_STATUS) (0x0011 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ACQUIRE_DEADLOCK
value|(ACPI_STATUS) (0x0012 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_RELEASE_DEADLOCK
value|(ACPI_STATUS) (0x0013 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NOT_ACQUIRED
value|(ACPI_STATUS) (0x0014 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ALREADY_ACQUIRED
value|(ACPI_STATUS) (0x0015 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_HARDWARE_RESPONSE
value|(ACPI_STATUS) (0x0016 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_GLOBAL_LOCK
value|(ACPI_STATUS) (0x0017 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ABORT_METHOD
value|(ACPI_STATUS) (0x0018 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_SAME_HANDLER
value|(ACPI_STATUS) (0x0019 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_HANDLER
value|(ACPI_STATUS) (0x001A | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_OWNER_ID_LIMIT
value|(ACPI_STATUS) (0x001B | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_CODE_ENV_MAX
value|0x001B
end_define

begin_comment
comment|/*  * Programmer exceptions  */
end_comment

begin_define
define|#
directive|define
name|AE_BAD_PARAMETER
value|(ACPI_STATUS) (0x0001 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHARACTER
value|(ACPI_STATUS) (0x0002 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_PATHNAME
value|(ACPI_STATUS) (0x0003 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_DATA
value|(ACPI_STATUS) (0x0004 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEX_CONSTANT
value|(ACPI_STATUS) (0x0005 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_OCTAL_CONSTANT
value|(ACPI_STATUS) (0x0006 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_DECIMAL_CONSTANT
value|(ACPI_STATUS) (0x0007 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_MISSING_ARGUMENTS
value|(ACPI_STATUS) (0x0008 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_ADDRESS
value|(ACPI_STATUS) (0x0009 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_CODE_PGM_MAX
value|0x0009
end_define

begin_comment
comment|/*  * Acpi table exceptions  */
end_comment

begin_define
define|#
directive|define
name|AE_BAD_SIGNATURE
value|(ACPI_STATUS) (0x0001 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEADER
value|(ACPI_STATUS) (0x0002 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHECKSUM
value|(ACPI_STATUS) (0x0003 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_BAD_VALUE
value|(ACPI_STATUS) (0x0004 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_INVALID_TABLE_LENGTH
value|(ACPI_STATUS) (0x0005 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_CODE_TBL_MAX
value|0x0005
end_define

begin_comment
comment|/*  * AML exceptions.  These are caused by problems with  * the actual AML byte stream  */
end_comment

begin_define
define|#
directive|define
name|AE_AML_BAD_OPCODE
value|(ACPI_STATUS) (0x0001 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_OPERAND
value|(ACPI_STATUS) (0x0002 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_TYPE
value|(ACPI_STATUS) (0x0003 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_VALUE
value|(ACPI_STATUS) (0x0004 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_LOCAL
value|(ACPI_STATUS) (0x0005 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ARG
value|(ACPI_STATUS) (0x0006 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ELEMENT
value|(ACPI_STATUS) (0x0007 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NUMERIC_OVERFLOW
value|(ACPI_STATUS) (0x0008 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGION_LIMIT
value|(ACPI_STATUS) (0x0009 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BUFFER_LIMIT
value|(ACPI_STATUS) (0x000A | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_PACKAGE_LIMIT
value|(ACPI_STATUS) (0x000B | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_DIVIDE_BY_ZERO
value|(ACPI_STATUS) (0x000C | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_NAME
value|(ACPI_STATUS) (0x000D | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NAME_NOT_FOUND
value|(ACPI_STATUS) (0x000E | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INTERNAL
value|(ACPI_STATUS) (0x000F | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_SPACE_ID
value|(ACPI_STATUS) (0x0010 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_STRING_LIMIT
value|(ACPI_STATUS) (0x0011 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RETURN_VALUE
value|(ACPI_STATUS) (0x0012 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_METHOD_LIMIT
value|(ACPI_STATUS) (0x0013 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NOT_OWNER
value|(ACPI_STATUS) (0x0014 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_ORDER
value|(ACPI_STATUS) (0x0015 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_NOT_ACQUIRED
value|(ACPI_STATUS) (0x0016 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_RESOURCE_TYPE
value|(ACPI_STATUS) (0x0017 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_INDEX
value|(ACPI_STATUS) (0x0018 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGISTER_LIMIT
value|(ACPI_STATUS) (0x0019 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_WHILE
value|(ACPI_STATUS) (0x001A | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_ALIGNMENT
value|(ACPI_STATUS) (0x001B | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RESOURCE_END_TAG
value|(ACPI_STATUS) (0x001C | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_VALUE
value|(ACPI_STATUS) (0x001D | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_CIRCULAR_REFERENCE
value|(ACPI_STATUS) (0x001E | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_LENGTH
value|(ACPI_STATUS) (0x001F | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_ILLEGAL_ADDRESS
value|(ACPI_STATUS) (0x0020 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INFINITE_LOOP
value|(ACPI_STATUS) (0x0021 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_CODE_AML_MAX
value|0x0021
end_define

begin_comment
comment|/*  * Internal exceptions used for control  */
end_comment

begin_define
define|#
directive|define
name|AE_CTRL_RETURN_VALUE
value|(ACPI_STATUS) (0x0001 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PENDING
value|(ACPI_STATUS) (0x0002 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TERMINATE
value|(ACPI_STATUS) (0x0003 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TRUE
value|(ACPI_STATUS) (0x0004 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_FALSE
value|(ACPI_STATUS) (0x0005 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_DEPTH
value|(ACPI_STATUS) (0x0006 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_END
value|(ACPI_STATUS) (0x0007 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TRANSFER
value|(ACPI_STATUS) (0x0008 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_BREAK
value|(ACPI_STATUS) (0x0009 | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_CONTINUE
value|(ACPI_STATUS) (0x000A | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_SKIP
value|(ACPI_STATUS) (0x000B | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PARSE_CONTINUE
value|(ACPI_STATUS) (0x000C | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PARSE_PENDING
value|(ACPI_STATUS) (0x000D | AE_CODE_CONTROL)
end_define

begin_define
define|#
directive|define
name|AE_CODE_CTRL_MAX
value|0x000D
end_define

begin_comment
comment|/* Exception strings for AcpiFormatException */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_comment
comment|/*  * String versions of the exception codes above  * These strings must match the corresponding defines exactly  */
end_comment

begin_decl_stmt
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Env
index|[]
init|=
block|{
literal|"AE_OK"
block|,
literal|"AE_ERROR"
block|,
literal|"AE_NO_ACPI_TABLES"
block|,
literal|"AE_NO_NAMESPACE"
block|,
literal|"AE_NO_MEMORY"
block|,
literal|"AE_NOT_FOUND"
block|,
literal|"AE_NOT_EXIST"
block|,
literal|"AE_ALREADY_EXISTS"
block|,
literal|"AE_TYPE"
block|,
literal|"AE_NULL_OBJECT"
block|,
literal|"AE_NULL_ENTRY"
block|,
literal|"AE_BUFFER_OVERFLOW"
block|,
literal|"AE_STACK_OVERFLOW"
block|,
literal|"AE_STACK_UNDERFLOW"
block|,
literal|"AE_NOT_IMPLEMENTED"
block|,
literal|"AE_SUPPORT"
block|,
literal|"AE_LIMIT"
block|,
literal|"AE_TIME"
block|,
literal|"AE_ACQUIRE_DEADLOCK"
block|,
literal|"AE_RELEASE_DEADLOCK"
block|,
literal|"AE_NOT_ACQUIRED"
block|,
literal|"AE_ALREADY_ACQUIRED"
block|,
literal|"AE_NO_HARDWARE_RESPONSE"
block|,
literal|"AE_NO_GLOBAL_LOCK"
block|,
literal|"AE_ABORT_METHOD"
block|,
literal|"AE_SAME_HANDLER"
block|,
literal|"AE_NO_HANDLER"
block|,
literal|"AE_OWNER_ID_LIMIT"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Pgm
index|[]
init|=
block|{
name|NULL
block|,
literal|"AE_BAD_PARAMETER"
block|,
literal|"AE_BAD_CHARACTER"
block|,
literal|"AE_BAD_PATHNAME"
block|,
literal|"AE_BAD_DATA"
block|,
literal|"AE_BAD_HEX_CONSTANT"
block|,
literal|"AE_BAD_OCTAL_CONSTANT"
block|,
literal|"AE_BAD_DECIMAL_CONSTANT"
block|,
literal|"AE_MISSING_ARGUMENTS"
block|,
literal|"AE_BAD_ADDRESS"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Tbl
index|[]
init|=
block|{
name|NULL
block|,
literal|"AE_BAD_SIGNATURE"
block|,
literal|"AE_BAD_HEADER"
block|,
literal|"AE_BAD_CHECKSUM"
block|,
literal|"AE_BAD_VALUE"
block|,
literal|"AE_INVALID_TABLE_LENGTH"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Aml
index|[]
init|=
block|{
name|NULL
block|,
literal|"AE_AML_BAD_OPCODE"
block|,
literal|"AE_AML_NO_OPERAND"
block|,
literal|"AE_AML_OPERAND_TYPE"
block|,
literal|"AE_AML_OPERAND_VALUE"
block|,
literal|"AE_AML_UNINITIALIZED_LOCAL"
block|,
literal|"AE_AML_UNINITIALIZED_ARG"
block|,
literal|"AE_AML_UNINITIALIZED_ELEMENT"
block|,
literal|"AE_AML_NUMERIC_OVERFLOW"
block|,
literal|"AE_AML_REGION_LIMIT"
block|,
literal|"AE_AML_BUFFER_LIMIT"
block|,
literal|"AE_AML_PACKAGE_LIMIT"
block|,
literal|"AE_AML_DIVIDE_BY_ZERO"
block|,
literal|"AE_AML_BAD_NAME"
block|,
literal|"AE_AML_NAME_NOT_FOUND"
block|,
literal|"AE_AML_INTERNAL"
block|,
literal|"AE_AML_INVALID_SPACE_ID"
block|,
literal|"AE_AML_STRING_LIMIT"
block|,
literal|"AE_AML_NO_RETURN_VALUE"
block|,
literal|"AE_AML_METHOD_LIMIT"
block|,
literal|"AE_AML_NOT_OWNER"
block|,
literal|"AE_AML_MUTEX_ORDER"
block|,
literal|"AE_AML_MUTEX_NOT_ACQUIRED"
block|,
literal|"AE_AML_INVALID_RESOURCE_TYPE"
block|,
literal|"AE_AML_INVALID_INDEX"
block|,
literal|"AE_AML_REGISTER_LIMIT"
block|,
literal|"AE_AML_NO_WHILE"
block|,
literal|"AE_AML_ALIGNMENT"
block|,
literal|"AE_AML_NO_RESOURCE_END_TAG"
block|,
literal|"AE_AML_BAD_RESOURCE_VALUE"
block|,
literal|"AE_AML_CIRCULAR_REFERENCE"
block|,
literal|"AE_AML_BAD_RESOURCE_LENGTH"
block|,
literal|"AE_AML_ILLEGAL_ADDRESS"
block|,
literal|"AE_AML_INFINITE_LOOP"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Ctrl
index|[]
init|=
block|{
name|NULL
block|,
literal|"AE_CTRL_RETURN_VALUE"
block|,
literal|"AE_CTRL_PENDING"
block|,
literal|"AE_CTRL_TERMINATE"
block|,
literal|"AE_CTRL_TRUE"
block|,
literal|"AE_CTRL_FALSE"
block|,
literal|"AE_CTRL_DEPTH"
block|,
literal|"AE_CTRL_END"
block|,
literal|"AE_CTRL_TRANSFER"
block|,
literal|"AE_CTRL_BREAK"
block|,
literal|"AE_CTRL_CONTINUE"
block|,
literal|"AE_CTRL_SKIP"
block|,
literal|"AE_CTRL_PARSE_CONTINUE"
block|,
literal|"AE_CTRL_PARSE_PENDING"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI GLOBALS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACEXCEP_H__ */
end_comment

end_unit

