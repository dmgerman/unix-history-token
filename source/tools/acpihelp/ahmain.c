begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahmain - Main module for the acpi help utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpihelp.h"
end_include

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|AhDisplayUsage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AH_UTILITY_NAME
value|"ACPI Help Utility"
end_define

begin_define
define|#
directive|define
name|AH_SUPPORTED_OPTIONS
value|"aehikmopsv"
end_define

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AhDisplayUsage  *  * DESCRIPTION: Usage message  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|AhDisplayUsage
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_USAGE_HEADER
argument_list|(
literal|"acpihelp<options> [Name/Prefix | HexValue]"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-h"
argument_list|,
literal|"Display help"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-v"
argument_list|,
literal|"Display version information"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nAML (ACPI Machine Language) Names and Encodings:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-a [Name/Prefix]"
argument_list|,
literal|"Find/Display both ASL operator and AML opcode name(s)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-m [Name/Prefix]"
argument_list|,
literal|"Find/Display AML opcode name(s)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nASL (ACPI Source Language) Names and Symbols:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-k [Name/Prefix]"
argument_list|,
literal|"Find/Display ASL non-operator keyword(s)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-p [Name/Prefix]"
argument_list|,
literal|"Find/Display ASL predefined method name(s)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-s [Name/Prefix]"
argument_list|,
literal|"Find/Display ASL operator name(s)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nOther ACPI Names:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-i [Name/Prefix]"
argument_list|,
literal|"Find/Display ACPI/PNP Hardware ID(s)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nACPI Values:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-e [HexValue]"
argument_list|,
literal|"Decode ACPICA exception code"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-o [HexValue]"
argument_list|,
literal|"Decode hex AML opcode"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nName/Prefix or HexValue not specified means \"Display All\"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nDefault search with valid Name/Prefix and no options:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    Find ASL/AML operator names - if NamePrefix does not start with underscore\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    Find ASL predefined method names - if NamePrefix starts with underscore\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    main  *  * DESCRIPTION: C main function for AcpiHelp utility.  *  ******************************************************************************/
end_comment

begin_function
name|int
name|ACPI_SYSTEM_XFACE
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT32
name|DecodeType
decl_stmt|;
name|int
name|j
decl_stmt|;
name|ACPI_DEBUG_INITIALIZE
argument_list|()
expr_stmt|;
comment|/* For debug version only */
name|printf
argument_list|(
name|ACPI_COMMON_SIGNON
argument_list|(
name|AH_UTILITY_NAME
argument_list|)
argument_list|)
expr_stmt|;
name|DecodeType
operator|=
name|AH_DECODE_DEFAULT
expr_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|AhDisplayUsage
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Command line options */
while|while
condition|(
operator|(
name|j
operator|=
name|AcpiGetopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|AH_SUPPORTED_OPTIONS
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
switch|switch
condition|(
name|j
condition|)
block|{
case|case
literal|'a'
case|:
name|DecodeType
operator|=
name|AH_DECODE_ASL_AML
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
name|DecodeType
operator|=
name|AH_DECODE_EXCEPTION
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
name|DecodeType
operator|=
name|AH_DISPLAY_DEVICE_IDS
expr_stmt|;
break|break;
case|case
literal|'k'
case|:
name|DecodeType
operator|=
name|AH_DECODE_ASL_KEYWORD
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|DecodeType
operator|=
name|AH_DECODE_AML
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|DecodeType
operator|=
name|AH_DECODE_AML_OPCODE
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|DecodeType
operator|=
name|AH_DECODE_PREDEFINED_NAME
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|DecodeType
operator|=
name|AH_DECODE_ASL
expr_stmt|;
break|break;
case|case
literal|'v'
case|:
comment|/* -v: (Version): signon already emitted, just exit */
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|'h'
case|:
default|default:
name|AhDisplayUsage
argument_list|()
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Missing (null) name means "display all" */
name|Name
operator|=
name|argv
index|[
name|AcpiGbl_Optind
index|]
expr_stmt|;
switch|switch
condition|(
name|DecodeType
condition|)
block|{
case|case
name|AH_DECODE_ASL_AML
case|:
name|AhFindAslAndAmlOperators
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_AML
case|:
name|AhFindAmlOpcode
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_AML_OPCODE
case|:
name|AhDecodeAmlOpcode
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_PREDEFINED_NAME
case|:
name|AhFindPredefinedNames
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_ASL
case|:
name|AhFindAslOperators
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_ASL_KEYWORD
case|:
name|AhFindAslKeywords
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DISPLAY_DEVICE_IDS
case|:
name|AhDisplayDeviceIds
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
case|case
name|AH_DECODE_EXCEPTION
case|:
name|AhDecodeException
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|!
name|Name
condition|)
block|{
name|AhFindAslOperators
argument_list|(
name|Name
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|*
name|Name
operator|==
literal|'_'
condition|)
block|{
name|AhFindPredefinedNames
argument_list|(
name|Name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AhFindAslAndAmlOperators
argument_list|(
name|Name
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AhStrupr (strupr)  *  * PARAMETERS:  SrcString           - The source string to convert  *  * RETURN:      None  *  * DESCRIPTION: Convert string to uppercase  *  * NOTE: This is not a POSIX function, so it appears here, not in utclib.c  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AhStrupr
parameter_list|(
name|char
modifier|*
name|SrcString
parameter_list|)
block|{
name|char
modifier|*
name|String
decl_stmt|;
if|if
condition|(
operator|!
name|SrcString
condition|)
block|{
return|return;
block|}
comment|/* Walk entire string, uppercasing the letters */
for|for
control|(
name|String
operator|=
name|SrcString
init|;
operator|*
name|String
condition|;
name|String
operator|++
control|)
block|{
operator|*
name|String
operator|=
operator|(
name|char
operator|)
name|toupper
argument_list|(
operator|(
name|int
operator|)
operator|*
name|String
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

end_unit

