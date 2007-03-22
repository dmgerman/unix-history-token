begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acexcep.h - Exception codes returned by the ACPI subsystem  *       $Revision: 1.79 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
name|AE_VERSION_MISMATCH
value|(ACPI_STATUS) (0x000F | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_SUPPORT
value|(ACPI_STATUS) (0x0010 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_SHARE
value|(ACPI_STATUS) (0x0011 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_LIMIT
value|(ACPI_STATUS) (0x0012 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_TIME
value|(ACPI_STATUS) (0x0013 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_UNKNOWN_STATUS
value|(ACPI_STATUS) (0x0014 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ACQUIRE_DEADLOCK
value|(ACPI_STATUS) (0x0015 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_RELEASE_DEADLOCK
value|(ACPI_STATUS) (0x0016 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NOT_ACQUIRED
value|(ACPI_STATUS) (0x0017 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ALREADY_ACQUIRED
value|(ACPI_STATUS) (0x0018 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_HARDWARE_RESPONSE
value|(ACPI_STATUS) (0x0019 | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_NO_GLOBAL_LOCK
value|(ACPI_STATUS) (0x001A | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_LOGICAL_ADDRESS
value|(ACPI_STATUS) (0x001B | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_ABORT_METHOD
value|(ACPI_STATUS) (0x001C | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_SAME_HANDLER
value|(ACPI_STATUS) (0x001D | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_WAKE_ONLY_GPE
value|(ACPI_STATUS) (0x001E | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_OWNER_ID_LIMIT
value|(ACPI_STATUS) (0x001F | AE_CODE_ENVIRONMENTAL)
end_define

begin_define
define|#
directive|define
name|AE_CODE_ENV_MAX
value|0x001F
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
name|AE_BAD_ADDRESS
value|(ACPI_STATUS) (0x0005 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_ALIGNMENT
value|(ACPI_STATUS) (0x0006 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_HEX_CONSTANT
value|(ACPI_STATUS) (0x0007 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_OCTAL_CONSTANT
value|(ACPI_STATUS) (0x0008 | AE_CODE_PROGRAMMER)
end_define

begin_define
define|#
directive|define
name|AE_BAD_DECIMAL_CONSTANT
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
name|AE_TABLE_NOT_SUPPORTED
value|(ACPI_STATUS) (0x0005 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_INVALID_TABLE_LENGTH
value|(ACPI_STATUS) (0x0006 | AE_CODE_ACPI_TABLES)
end_define

begin_define
define|#
directive|define
name|AE_CODE_TBL_MAX
value|0x0006
end_define

begin_comment
comment|/*  * AML exceptions.  These are caused by problems with  * the actual AML byte stream  */
end_comment

begin_define
define|#
directive|define
name|AE_AML_ERROR
value|(ACPI_STATUS) (0x0001 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_PARSE
value|(ACPI_STATUS) (0x0002 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_OPCODE
value|(ACPI_STATUS) (0x0003 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_OPERAND
value|(ACPI_STATUS) (0x0004 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_TYPE
value|(ACPI_STATUS) (0x0005 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_OPERAND_VALUE
value|(ACPI_STATUS) (0x0006 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_LOCAL
value|(ACPI_STATUS) (0x0007 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ARG
value|(ACPI_STATUS) (0x0008 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_UNINITIALIZED_ELEMENT
value|(ACPI_STATUS) (0x0009 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NUMERIC_OVERFLOW
value|(ACPI_STATUS) (0x000A | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGION_LIMIT
value|(ACPI_STATUS) (0x000B | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BUFFER_LIMIT
value|(ACPI_STATUS) (0x000C | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_PACKAGE_LIMIT
value|(ACPI_STATUS) (0x000D | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_DIVIDE_BY_ZERO
value|(ACPI_STATUS) (0x000E | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_NAME
value|(ACPI_STATUS) (0x000F | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NAME_NOT_FOUND
value|(ACPI_STATUS) (0x0010 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INTERNAL
value|(ACPI_STATUS) (0x0011 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_SPACE_ID
value|(ACPI_STATUS) (0x0012 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_STRING_LIMIT
value|(ACPI_STATUS) (0x0013 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RETURN_VALUE
value|(ACPI_STATUS) (0x0014 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_METHOD_LIMIT
value|(ACPI_STATUS) (0x0015 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NOT_OWNER
value|(ACPI_STATUS) (0x0016 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_ORDER
value|(ACPI_STATUS) (0x0017 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_MUTEX_NOT_ACQUIRED
value|(ACPI_STATUS) (0x0018 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_RESOURCE_TYPE
value|(ACPI_STATUS) (0x0019 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_INVALID_INDEX
value|(ACPI_STATUS) (0x001A | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_REGISTER_LIMIT
value|(ACPI_STATUS) (0x001B | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_WHILE
value|(ACPI_STATUS) (0x001C | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_ALIGNMENT
value|(ACPI_STATUS) (0x001D | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_NO_RESOURCE_END_TAG
value|(ACPI_STATUS) (0x001E | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_VALUE
value|(ACPI_STATUS) (0x001F | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_CIRCULAR_REFERENCE
value|(ACPI_STATUS) (0x0020 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_BAD_RESOURCE_LENGTH
value|(ACPI_STATUS) (0x0021 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_AML_ILLEGAL_ADDRESS
value|(ACPI_STATUS) (0x0022 | AE_CODE_AML)
end_define

begin_define
define|#
directive|define
name|AE_CODE_AML_MAX
value|0x0022
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
literal|"AE_VERSION_MISMATCH"
block|,
literal|"AE_SUPPORT"
block|,
literal|"AE_SHARE"
block|,
literal|"AE_LIMIT"
block|,
literal|"AE_TIME"
block|,
literal|"AE_UNKNOWN_STATUS"
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
literal|"AE_LOGICAL_ADDRESS"
block|,
literal|"AE_ABORT_METHOD"
block|,
literal|"AE_SAME_HANDLER"
block|,
literal|"AE_WAKE_ONLY_GPE"
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
literal|"AE_BAD_PARAMETER"
block|,
literal|"AE_BAD_CHARACTER"
block|,
literal|"AE_BAD_PATHNAME"
block|,
literal|"AE_BAD_DATA"
block|,
literal|"AE_BAD_ADDRESS"
block|,
literal|"AE_ALIGNMENT"
block|,
literal|"AE_BAD_HEX_CONSTANT"
block|,
literal|"AE_BAD_OCTAL_CONSTANT"
block|,
literal|"AE_BAD_DECIMAL_CONSTANT"
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
literal|"AE_BAD_SIGNATURE"
block|,
literal|"AE_BAD_HEADER"
block|,
literal|"AE_BAD_CHECKSUM"
block|,
literal|"AE_BAD_VALUE"
block|,
literal|"AE_TABLE_NOT_SUPPORTED"
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
literal|"AE_AML_ERROR"
block|,
literal|"AE_AML_PARSE"
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

