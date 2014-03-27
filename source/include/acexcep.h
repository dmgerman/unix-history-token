begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acexcep.h - Exception codes returned by the ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/* This module contains all possible exception codes for ACPI_STATUS */
end_comment

begin_comment
comment|/*  * Exception code classes  */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_ENVIRONMENTAL
value|0x0000
end_define

begin_comment
comment|/* General ACPICA environment */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_PROGRAMMER
value|0x1000
end_define

begin_comment
comment|/* External ACPICA interface caller */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_ACPI_TABLES
value|0x2000
end_define

begin_comment
comment|/* ACPI tables */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_AML
value|0x3000
end_define

begin_comment
comment|/* From executing AML code */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_CONTROL
value|0x4000
end_define

begin_comment
comment|/* Internal control codes */
end_comment

begin_define
define|#
directive|define
name|AE_CODE_MAX
value|0x4000
end_define

begin_define
define|#
directive|define
name|AE_CODE_MASK
value|0xF000
end_define

begin_comment
comment|/*  * Macros to insert the exception code classes  */
end_comment

begin_define
define|#
directive|define
name|EXCEP_ENV
parameter_list|(
name|code
parameter_list|)
value|((ACPI_STATUS) (code | AE_CODE_ENVIRONMENTAL))
end_define

begin_define
define|#
directive|define
name|EXCEP_PGM
parameter_list|(
name|code
parameter_list|)
value|((ACPI_STATUS) (code | AE_CODE_PROGRAMMER))
end_define

begin_define
define|#
directive|define
name|EXCEP_TBL
parameter_list|(
name|code
parameter_list|)
value|((ACPI_STATUS) (code | AE_CODE_ACPI_TABLES))
end_define

begin_define
define|#
directive|define
name|EXCEP_AML
parameter_list|(
name|code
parameter_list|)
value|((ACPI_STATUS) (code | AE_CODE_AML))
end_define

begin_define
define|#
directive|define
name|EXCEP_CTL
parameter_list|(
name|code
parameter_list|)
value|((ACPI_STATUS) (code | AE_CODE_CONTROL))
end_define

begin_comment
comment|/*  * Exception info table. The "Description" field is used only by the  * ACPICA help application (acpihelp).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_exception_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPI_HELP_APP
name|char
modifier|*
name|Description
decl_stmt|;
endif|#
directive|endif
block|}
name|ACPI_EXCEPTION_INFO
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_HELP_APP
end_ifdef

begin_define
define|#
directive|define
name|EXCEP_TXT
parameter_list|(
name|Name
parameter_list|,
name|Description
parameter_list|)
value|{Name, Description}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXCEP_TXT
parameter_list|(
name|Name
parameter_list|,
name|Description
parameter_list|)
value|{Name}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Success is always zero, failure is non-zero  */
end_comment

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
value|EXCEP_ENV (0x0001)
end_define

begin_define
define|#
directive|define
name|AE_NO_ACPI_TABLES
value|EXCEP_ENV (0x0002)
end_define

begin_define
define|#
directive|define
name|AE_NO_NAMESPACE
value|EXCEP_ENV (0x0003)
end_define

begin_define
define|#
directive|define
name|AE_NO_MEMORY
value|EXCEP_ENV (0x0004)
end_define

begin_define
define|#
directive|define
name|AE_NOT_FOUND
value|EXCEP_ENV (0x0005)
end_define

begin_define
define|#
directive|define
name|AE_NOT_EXIST
value|EXCEP_ENV (0x0006)
end_define

begin_define
define|#
directive|define
name|AE_ALREADY_EXISTS
value|EXCEP_ENV (0x0007)
end_define

begin_define
define|#
directive|define
name|AE_TYPE
value|EXCEP_ENV (0x0008)
end_define

begin_define
define|#
directive|define
name|AE_NULL_OBJECT
value|EXCEP_ENV (0x0009)
end_define

begin_define
define|#
directive|define
name|AE_NULL_ENTRY
value|EXCEP_ENV (0x000A)
end_define

begin_define
define|#
directive|define
name|AE_BUFFER_OVERFLOW
value|EXCEP_ENV (0x000B)
end_define

begin_define
define|#
directive|define
name|AE_STACK_OVERFLOW
value|EXCEP_ENV (0x000C)
end_define

begin_define
define|#
directive|define
name|AE_STACK_UNDERFLOW
value|EXCEP_ENV (0x000D)
end_define

begin_define
define|#
directive|define
name|AE_NOT_IMPLEMENTED
value|EXCEP_ENV (0x000E)
end_define

begin_define
define|#
directive|define
name|AE_SUPPORT
value|EXCEP_ENV (0x000F)
end_define

begin_define
define|#
directive|define
name|AE_LIMIT
value|EXCEP_ENV (0x0010)
end_define

begin_define
define|#
directive|define
name|AE_TIME
value|EXCEP_ENV (0x0011)
end_define

begin_define
define|#
directive|define
name|AE_ACQUIRE_DEADLOCK
value|EXCEP_ENV (0x0012)
end_define

begin_define
define|#
directive|define
name|AE_RELEASE_DEADLOCK
value|EXCEP_ENV (0x0013)
end_define

begin_define
define|#
directive|define
name|AE_NOT_ACQUIRED
value|EXCEP_ENV (0x0014)
end_define

begin_define
define|#
directive|define
name|AE_ALREADY_ACQUIRED
value|EXCEP_ENV (0x0015)
end_define

begin_define
define|#
directive|define
name|AE_NO_HARDWARE_RESPONSE
value|EXCEP_ENV (0x0016)
end_define

begin_define
define|#
directive|define
name|AE_NO_GLOBAL_LOCK
value|EXCEP_ENV (0x0017)
end_define

begin_define
define|#
directive|define
name|AE_ABORT_METHOD
value|EXCEP_ENV (0x0018)
end_define

begin_define
define|#
directive|define
name|AE_SAME_HANDLER
value|EXCEP_ENV (0x0019)
end_define

begin_define
define|#
directive|define
name|AE_NO_HANDLER
value|EXCEP_ENV (0x001A)
end_define

begin_define
define|#
directive|define
name|AE_OWNER_ID_LIMIT
value|EXCEP_ENV (0x001B)
end_define

begin_define
define|#
directive|define
name|AE_NOT_CONFIGURED
value|EXCEP_ENV (0x001C)
end_define

begin_define
define|#
directive|define
name|AE_ACCESS
value|EXCEP_ENV (0x001D)
end_define

begin_define
define|#
directive|define
name|AE_CODE_ENV_MAX
value|0x001D
end_define

begin_comment
comment|/*  * Programmer exceptions  */
end_comment

begin_define
define|#
directive|define
name|AE_BAD_PARAMETER
value|EXCEP_PGM (0x0001)
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHARACTER
value|EXCEP_PGM (0x0002)
end_define

begin_define
define|#
directive|define
name|AE_BAD_PATHNAME
value|EXCEP_PGM (0x0003)
end_define

begin_define
define|#
directive|define
name|AE_BAD_DATA
value|EXCEP_PGM (0x0004)
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEX_CONSTANT
value|EXCEP_PGM (0x0005)
end_define

begin_define
define|#
directive|define
name|AE_BAD_OCTAL_CONSTANT
value|EXCEP_PGM (0x0006)
end_define

begin_define
define|#
directive|define
name|AE_BAD_DECIMAL_CONSTANT
value|EXCEP_PGM (0x0007)
end_define

begin_define
define|#
directive|define
name|AE_MISSING_ARGUMENTS
value|EXCEP_PGM (0x0008)
end_define

begin_define
define|#
directive|define
name|AE_BAD_ADDRESS
value|EXCEP_PGM (0x0009)
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
value|EXCEP_TBL (0x0001)
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEADER
value|EXCEP_TBL (0x0002)
end_define

begin_define
define|#
directive|define
name|AE_BAD_CHECKSUM
value|EXCEP_TBL (0x0003)
end_define

begin_define
define|#
directive|define
name|AE_BAD_VALUE
value|EXCEP_TBL (0x0004)
end_define

begin_define
define|#
directive|define
name|AE_INVALID_TABLE_LENGTH
value|EXCEP_TBL (0x0005)
end_define

begin_define
define|#
directive|define
name|AE_CODE_TBL_MAX
value|0x0005
end_define

begin_comment
comment|/*  * AML exceptions. These are caused by problems with  * the actual AML byte stream  */
end_comment

begin_define
define|#
directive|define
name|AE_AML_BAD_OPCODE
value|EXCEP_AML (0x0001)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_OPERAND
value|EXCEP_AML (0x0002)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_TYPE
value|EXCEP_AML (0x0003)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_VALUE
value|EXCEP_AML (0x0004)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_LOCAL
value|EXCEP_AML (0x0005)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ARG
value|EXCEP_AML (0x0006)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ELEMENT
value|EXCEP_AML (0x0007)
end_define

begin_define
define|#
directive|define
name|AE_AML_NUMERIC_OVERFLOW
value|EXCEP_AML (0x0008)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGION_LIMIT
value|EXCEP_AML (0x0009)
end_define

begin_define
define|#
directive|define
name|AE_AML_BUFFER_LIMIT
value|EXCEP_AML (0x000A)
end_define

begin_define
define|#
directive|define
name|AE_AML_PACKAGE_LIMIT
value|EXCEP_AML (0x000B)
end_define

begin_define
define|#
directive|define
name|AE_AML_DIVIDE_BY_ZERO
value|EXCEP_AML (0x000C)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_NAME
value|EXCEP_AML (0x000D)
end_define

begin_define
define|#
directive|define
name|AE_AML_NAME_NOT_FOUND
value|EXCEP_AML (0x000E)
end_define

begin_define
define|#
directive|define
name|AE_AML_INTERNAL
value|EXCEP_AML (0x000F)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_SPACE_ID
value|EXCEP_AML (0x0010)
end_define

begin_define
define|#
directive|define
name|AE_AML_STRING_LIMIT
value|EXCEP_AML (0x0011)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RETURN_VALUE
value|EXCEP_AML (0x0012)
end_define

begin_define
define|#
directive|define
name|AE_AML_METHOD_LIMIT
value|EXCEP_AML (0x0013)
end_define

begin_define
define|#
directive|define
name|AE_AML_NOT_OWNER
value|EXCEP_AML (0x0014)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_ORDER
value|EXCEP_AML (0x0015)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_NOT_ACQUIRED
value|EXCEP_AML (0x0016)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_RESOURCE_TYPE
value|EXCEP_AML (0x0017)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_INDEX
value|EXCEP_AML (0x0018)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGISTER_LIMIT
value|EXCEP_AML (0x0019)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_WHILE
value|EXCEP_AML (0x001A)
end_define

begin_define
define|#
directive|define
name|AE_AML_ALIGNMENT
value|EXCEP_AML (0x001B)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RESOURCE_END_TAG
value|EXCEP_AML (0x001C)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_VALUE
value|EXCEP_AML (0x001D)
end_define

begin_define
define|#
directive|define
name|AE_AML_CIRCULAR_REFERENCE
value|EXCEP_AML (0x001E)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_LENGTH
value|EXCEP_AML (0x001F)
end_define

begin_define
define|#
directive|define
name|AE_AML_ILLEGAL_ADDRESS
value|EXCEP_AML (0x0020)
end_define

begin_define
define|#
directive|define
name|AE_AML_INFINITE_LOOP
value|EXCEP_AML (0x0021)
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
value|EXCEP_CTL (0x0001)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PENDING
value|EXCEP_CTL (0x0002)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TERMINATE
value|EXCEP_CTL (0x0003)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TRUE
value|EXCEP_CTL (0x0004)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_FALSE
value|EXCEP_CTL (0x0005)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_DEPTH
value|EXCEP_CTL (0x0006)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_END
value|EXCEP_CTL (0x0007)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_TRANSFER
value|EXCEP_CTL (0x0008)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_BREAK
value|EXCEP_CTL (0x0009)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_CONTINUE
value|EXCEP_CTL (0x000A)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_SKIP
value|EXCEP_CTL (0x000B)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PARSE_CONTINUE
value|EXCEP_CTL (0x000C)
end_define

begin_define
define|#
directive|define
name|AE_CTRL_PARSE_PENDING
value|EXCEP_CTL (0x000D)
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
name|ACPI_DEFINE_EXCEPTION_TABLE
end_ifdef

begin_comment
comment|/*  * String versions of the exception codes above  * These strings must match the corresponding defines exactly  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_EXCEPTION_INFO
name|AcpiGbl_ExceptionNames_Env
index|[]
init|=
block|{
name|EXCEP_TXT
argument_list|(
literal|"AE_OK"
argument_list|,
literal|"No error"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ERROR"
argument_list|,
literal|"Unspecified error"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_ACPI_TABLES"
argument_list|,
literal|"ACPI tables could not be found"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_NAMESPACE"
argument_list|,
literal|"A namespace has not been loaded"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_MEMORY"
argument_list|,
literal|"Insufficient dynamic memory"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NOT_FOUND"
argument_list|,
literal|"A requested entity is not found"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NOT_EXIST"
argument_list|,
literal|"A required entity does not exist"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ALREADY_EXISTS"
argument_list|,
literal|"An entity already exists"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_TYPE"
argument_list|,
literal|"The object type is incorrect"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NULL_OBJECT"
argument_list|,
literal|"A required object was missing"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NULL_ENTRY"
argument_list|,
literal|"The requested object does not exist"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BUFFER_OVERFLOW"
argument_list|,
literal|"The buffer provided is too small"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_STACK_OVERFLOW"
argument_list|,
literal|"An internal stack overflowed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_STACK_UNDERFLOW"
argument_list|,
literal|"An internal stack underflowed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NOT_IMPLEMENTED"
argument_list|,
literal|"The feature is not implemented"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_SUPPORT"
argument_list|,
literal|"The feature is not supported"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_LIMIT"
argument_list|,
literal|"A predefined limit was exceeded"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_TIME"
argument_list|,
literal|"A time limit or timeout expired"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ACQUIRE_DEADLOCK"
argument_list|,
literal|"Internal error, attempt was made to acquire a mutex in improper order"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_RELEASE_DEADLOCK"
argument_list|,
literal|"Internal error, attempt was made to release a mutex in improper order"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NOT_ACQUIRED"
argument_list|,
literal|"An attempt to release a mutex or Global Lock without a previous acquire"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ALREADY_ACQUIRED"
argument_list|,
literal|"Internal error, attempt was made to acquire a mutex twice"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_HARDWARE_RESPONSE"
argument_list|,
literal|"Hardware did not respond after an I/O operation"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_GLOBAL_LOCK"
argument_list|,
literal|"There is no FACS Global Lock"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ABORT_METHOD"
argument_list|,
literal|"A control method was aborted"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_SAME_HANDLER"
argument_list|,
literal|"Attempt was made to install the same handler that is already installed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NO_HANDLER"
argument_list|,
literal|"A handler for the operation is not installed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_OWNER_ID_LIMIT"
argument_list|,
literal|"There are no more Owner IDs available for ACPI tables or control methods"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_NOT_CONFIGURED"
argument_list|,
literal|"The interface is not part of the current subsystem configuration"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_ACCESS"
argument_list|,
literal|"Permission denied for the requested operation"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_EXCEPTION_INFO
name|AcpiGbl_ExceptionNames_Pgm
index|[]
init|=
block|{
name|EXCEP_TXT
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_PARAMETER"
argument_list|,
literal|"A parameter is out of range or invalid"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_CHARACTER"
argument_list|,
literal|"An invalid character was found in a name"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_PATHNAME"
argument_list|,
literal|"An invalid character was found in a pathname"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_DATA"
argument_list|,
literal|"A package or buffer contained incorrect data"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_HEX_CONSTANT"
argument_list|,
literal|"Invalid character in a Hex constant"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_OCTAL_CONSTANT"
argument_list|,
literal|"Invalid character in an Octal constant"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_DECIMAL_CONSTANT"
argument_list|,
literal|"Invalid character in a Decimal constant"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_MISSING_ARGUMENTS"
argument_list|,
literal|"Too few arguments were passed to a control method"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_ADDRESS"
argument_list|,
literal|"An illegal null I/O address"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_EXCEPTION_INFO
name|AcpiGbl_ExceptionNames_Tbl
index|[]
init|=
block|{
name|EXCEP_TXT
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_SIGNATURE"
argument_list|,
literal|"An ACPI table has an invalid signature"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_HEADER"
argument_list|,
literal|"Invalid field in an ACPI table header"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_CHECKSUM"
argument_list|,
literal|"An ACPI table checksum is not correct"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_BAD_VALUE"
argument_list|,
literal|"An invalid value was found in a table"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_INVALID_TABLE_LENGTH"
argument_list|,
literal|"The FADT or FACS has improper length"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_EXCEPTION_INFO
name|AcpiGbl_ExceptionNames_Aml
index|[]
init|=
block|{
name|EXCEP_TXT
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_BAD_OPCODE"
argument_list|,
literal|"Invalid AML opcode encountered"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NO_OPERAND"
argument_list|,
literal|"A required operand is missing"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_OPERAND_TYPE"
argument_list|,
literal|"An operand of an incorrect type was encountered"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_OPERAND_VALUE"
argument_list|,
literal|"The operand had an inappropriate or invalid value"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_UNINITIALIZED_LOCAL"
argument_list|,
literal|"Method tried to use an uninitialized local variable"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_UNINITIALIZED_ARG"
argument_list|,
literal|"Method tried to use an uninitialized argument"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_UNINITIALIZED_ELEMENT"
argument_list|,
literal|"Method tried to use an empty package element"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NUMERIC_OVERFLOW"
argument_list|,
literal|"Overflow during BCD conversion or other"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_REGION_LIMIT"
argument_list|,
literal|"Tried to access beyond the end of an Operation Region"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_BUFFER_LIMIT"
argument_list|,
literal|"Tried to access beyond the end of a buffer"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_PACKAGE_LIMIT"
argument_list|,
literal|"Tried to access beyond the end of a package"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_DIVIDE_BY_ZERO"
argument_list|,
literal|"During execution of AML Divide operator"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_BAD_NAME"
argument_list|,
literal|"An ACPI name contains invalid character(s)"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NAME_NOT_FOUND"
argument_list|,
literal|"Could not resolve a named reference"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_INTERNAL"
argument_list|,
literal|"An internal error within the interprete"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_INVALID_SPACE_ID"
argument_list|,
literal|"An Operation Region SpaceID is invalid"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_STRING_LIMIT"
argument_list|,
literal|"String is longer than 200 characters"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NO_RETURN_VALUE"
argument_list|,
literal|"A method did not return a required value"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_METHOD_LIMIT"
argument_list|,
literal|"A control method reached the maximum reentrancy limit of 255"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NOT_OWNER"
argument_list|,
literal|"A thread tried to release a mutex that it does not own"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_MUTEX_ORDER"
argument_list|,
literal|"Mutex SyncLevel release mismatch"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_MUTEX_NOT_ACQUIRED"
argument_list|,
literal|"Attempt to release a mutex that was not previously acquired"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_INVALID_RESOURCE_TYPE"
argument_list|,
literal|"Invalid resource type in resource list"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_INVALID_INDEX"
argument_list|,
literal|"Invalid Argx or Localx (x too large)"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_REGISTER_LIMIT"
argument_list|,
literal|"Bank value or Index value beyond range of register"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NO_WHILE"
argument_list|,
literal|"Break or Continue without a While"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_ALIGNMENT"
argument_list|,
literal|"Non-aligned memory transfer on platform that does not support this"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_NO_RESOURCE_END_TAG"
argument_list|,
literal|"No End Tag in a resource list"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_BAD_RESOURCE_VALUE"
argument_list|,
literal|"Invalid value of a resource element"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_CIRCULAR_REFERENCE"
argument_list|,
literal|"Two references refer to each other"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_BAD_RESOURCE_LENGTH"
argument_list|,
literal|"The length of a Resource Descriptor in the AML is incorrect"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_ILLEGAL_ADDRESS"
argument_list|,
literal|"A memory, I/O, or PCI configuration address is invalid"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_AML_INFINITE_LOOP"
argument_list|,
literal|"An apparent infinite AML While loop, method was aborted"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_EXCEPTION_INFO
name|AcpiGbl_ExceptionNames_Ctrl
index|[]
init|=
block|{
name|EXCEP_TXT
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_RETURN_VALUE"
argument_list|,
literal|"A Method returned a value"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_PENDING"
argument_list|,
literal|"Method is calling another method"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_TERMINATE"
argument_list|,
literal|"Terminate the executing method"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_TRUE"
argument_list|,
literal|"An If or While predicate result"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_FALSE"
argument_list|,
literal|"An If or While predicate result"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_DEPTH"
argument_list|,
literal|"Maximum search depth has been reached"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_END"
argument_list|,
literal|"An If or While predicate is false"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_TRANSFER"
argument_list|,
literal|"Transfer control to called method"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_BREAK"
argument_list|,
literal|"A Break has been executed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_CONTINUE"
argument_list|,
literal|"A Continue has been executed"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_SKIP"
argument_list|,
literal|"Not currently used"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_PARSE_CONTINUE"
argument_list|,
literal|"Used to skip over bad opcodes"
argument_list|)
block|,
name|EXCEP_TXT
argument_list|(
literal|"AE_CTRL_PARSE_PENDING"
argument_list|,
literal|"Used to implement AML While loops"
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXCEPTION_TABLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACEXCEP_H__ */
end_comment

end_unit

