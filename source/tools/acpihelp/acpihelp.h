begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpihelp.h - Include file for AcpiHelp utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPIHELP_H
end_ifndef

begin_define
define|#
directive|define
name|__ACPIHELP_H
end_define

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"accommon.h"
end_include

begin_include
include|#
directive|include
file|"acapps.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global variables. Defined in ahmain.c only, externed in all other files  */
end_comment

begin_undef
undef|#
directive|undef
name|ACPI_GLOBAL
end_undef

begin_undef
undef|#
directive|undef
name|ACPI_INIT_GLOBAL
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_AHELP_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name; \     type name
end_define

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|type name=value
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|ACPI_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|extern type name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_INIT_GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|extern type name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AH_BUFFER_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|AH_LINE_BUFFER_LENGTH
value|512
end_define

begin_define
define|#
directive|define
name|AH_MAX_ASL_LINE_LENGTH
value|70
end_define

begin_define
define|#
directive|define
name|AH_MAX_AML_LINE_LENGTH
value|100
end_define

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_Buffer
index|[
name|AH_BUFFER_LENGTH
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|Gbl_LineBuffer
index|[
name|AH_LINE_BUFFER_LENGTH
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|AH_DISPLAY_EXCEPTION
parameter_list|(
name|Status
parameter_list|,
name|Name
parameter_list|)
define|\
value|printf ("%.4X: %s\n", Status, Name)
end_define

begin_define
define|#
directive|define
name|AH_DISPLAY_EXCEPTION_TEXT
parameter_list|(
name|Status
parameter_list|,
name|Exception
parameter_list|)
define|\
value|printf ("%.4X: %-28s (%s)\n", Status,\     Exception->Name, Exception->Description)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AH_DECODE_DEFAULT
init|=
literal|0
block|,
name|AH_DECODE_ASL
block|,
name|AH_DECODE_ASL_KEYWORD
block|,
name|AH_DECODE_PREDEFINED_NAME
block|,
name|AH_DECODE_AML
block|,
name|AH_DECODE_AML_OPCODE
block|,
name|AH_DECODE_AML_TYPE
block|,
name|AH_DECODE_ASL_AML
block|,
name|AH_DECODE_EXCEPTION
block|,
name|AH_DISPLAY_DEVICE_IDS
block|,
name|AH_DISPLAY_UUIDS
block|,
name|AH_DISPLAY_TABLES
block|,
name|AH_DISPLAY_DIRECTIVES
block|}
name|AH_OPTION_TYPES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ah_aml_opcode
block|{
name|UINT16
name|OpcodeRangeStart
decl_stmt|;
name|UINT16
name|OpcodeRangeEnd
decl_stmt|;
name|char
modifier|*
name|OpcodeString
decl_stmt|;
name|char
modifier|*
name|OpcodeName
decl_stmt|;
name|char
modifier|*
name|Type
decl_stmt|;
name|char
modifier|*
name|FixedArguments
decl_stmt|;
name|char
modifier|*
name|VariableArguments
decl_stmt|;
name|char
modifier|*
name|Grammar
decl_stmt|;
block|}
name|AH_AML_OPCODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ah_aml_type
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Description
decl_stmt|;
block|}
name|AH_AML_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ah_asl_operator
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Syntax
decl_stmt|;
name|char
modifier|*
name|Description
decl_stmt|;
block|}
name|AH_ASL_OPERATOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ah_asl_keyword
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Description
decl_stmt|;
name|char
modifier|*
name|KeywordList
decl_stmt|;
block|}
name|AH_ASL_KEYWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ah_directive_info
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Description
decl_stmt|;
block|}
name|AH_DIRECTIVE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Externals for various data tables */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|AH_AML_OPCODE
name|Gbl_AmlOpcodeInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_AML_TYPE
name|Gbl_AmlTypesInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_ASL_OPERATOR
name|Gbl_AslOperatorInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_ASL_KEYWORD
name|Gbl_AslKeywordInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_UUID
name|Gbl_AcpiUuids
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_DIRECTIVE_INFO
name|Gbl_PreprocessorDirectives
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_TABLE
name|Gbl_AcpiSupportedTables
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|AhFindAmlOpcode
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDecodeAmlOpcode
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDecodeException
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhFindPredefinedNames
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhFindAslAndAmlOperators
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AhFindAslOperators
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhFindAslKeywords
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhFindAmlTypes
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDisplayDeviceIds
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDisplayTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|AH_TABLE
modifier|*
name|AcpiAhGetTableInfo
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDisplayUuids
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhDisplayDirectives
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AhPrintOneField
parameter_list|(
name|UINT32
name|Indent
parameter_list|,
name|UINT32
name|CurrentPosition
parameter_list|,
name|UINT32
name|MaxPosition
parameter_list|,
specifier|const
name|char
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACPIHELP_H */
end_comment

end_unit

