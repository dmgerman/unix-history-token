begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpihelp.h - Include file for AcpiHelp utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

