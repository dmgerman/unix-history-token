begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpihelp.h - Include file for AcpiHelp utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|AH_DECODE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|AH_DECODE_ASL
value|1
end_define

begin_define
define|#
directive|define
name|AH_DECODE_ASL_KEYWORD
value|2
end_define

begin_define
define|#
directive|define
name|AH_DECODE_PREDEFINED_NAME
value|3
end_define

begin_define
define|#
directive|define
name|AH_DECODE_AML
value|4
end_define

begin_define
define|#
directive|define
name|AH_DECODE_AML_OPCODE
value|5
end_define

begin_define
define|#
directive|define
name|AH_DISPLAY_DEVICE_IDS
value|6
end_define

begin_define
define|#
directive|define
name|AH_DECODE_EXCEPTION
value|7
end_define

begin_define
define|#
directive|define
name|AH_DECODE_ASL_AML
value|8
end_define

begin_define
define|#
directive|define
name|AH_DISPLAY_UUIDS
value|9
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

begin_decl_stmt
specifier|extern
specifier|const
name|AH_AML_OPCODE
name|AmlOpcodeInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_ASL_OPERATOR
name|AslOperatorInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_ASL_KEYWORD
name|AslKeywordInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_UUID
name|AcpiUuids
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AhDisplayAll
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|AhStrupr
parameter_list|(
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

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
name|AhDisplayUuids
parameter_list|(
name|void
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

