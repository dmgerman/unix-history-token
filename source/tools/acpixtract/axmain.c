begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: axmain - main module for acpixtract utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

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

begin_function_decl
specifier|static
name|void
name|DisplayUsage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxExtractTables
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|,
name|unsigned
name|int
name|MinimumInstances
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AxListTables
parameter_list|(
name|char
modifier|*
name|InputPathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Options */
end_comment

begin_define
define|#
directive|define
name|AX_EXTRACT_ALL
value|0
end_define

begin_define
define|#
directive|define
name|AX_LIST_ALL
value|1
end_define

begin_define
define|#
directive|define
name|AX_EXTRACT_SIGNATURE
value|2
end_define

begin_define
define|#
directive|define
name|AX_EXTRACT_AML_TABLES
value|3
end_define

begin_decl_stmt
specifier|static
name|int
name|AxAction
init|=
name|AX_EXTRACT_AML_TABLES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DSDT& SSDTs */
end_comment

begin_define
define|#
directive|define
name|AX_OPTIONAL_TABLES
value|0
end_define

begin_define
define|#
directive|define
name|AX_REQUIRED_TABLE
value|1
end_define

begin_define
define|#
directive|define
name|AX_UTILITY_NAME
value|"ACPI Binary Table Extraction Utility"
end_define

begin_define
define|#
directive|define
name|AX_SUPPORTED_OPTIONS
value|"ahls:v"
end_define

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    DisplayUsage  *  * DESCRIPTION: Usage message  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|DisplayUsage
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_USAGE_HEADER
argument_list|(
literal|"acpixtract [option]<InputFile>"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-a"
argument_list|,
literal|"Extract all tables, not just DSDT/SSDT"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-l"
argument_list|,
literal|"List table summaries, do not extract"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-s<signature>"
argument_list|,
literal|"Extract all tables with<signature>"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-v"
argument_list|,
literal|"Display version information"
argument_list|)
expr_stmt|;
name|ACPI_USAGE_TEXT
argument_list|(
literal|"\nExtract binary ACPI tables from text acpidump output\n"
argument_list|)
expr_stmt|;
name|ACPI_USAGE_TEXT
argument_list|(
literal|"Default invocation extracts the DSDT and all SSDTs\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    main  *  * DESCRIPTION: C main function  *  ******************************************************************************/
end_comment

begin_function
name|int
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
name|Filename
decl_stmt|;
name|int
name|Status
decl_stmt|;
name|int
name|j
decl_stmt|;
name|ACPI_DEBUG_INITIALIZE
argument_list|()
expr_stmt|;
comment|/* For debug version only */
name|AcpiOsInitialize
argument_list|()
expr_stmt|;
name|printf
argument_list|(
name|ACPI_COMMON_SIGNON
argument_list|(
name|AX_UTILITY_NAME
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|DisplayUsage
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
name|AX_SUPPORTED_OPTIONS
argument_list|)
operator|)
operator|!=
name|ACPI_OPT_END
condition|)
switch|switch
condition|(
name|j
condition|)
block|{
case|case
literal|'a'
case|:
name|AxAction
operator|=
name|AX_EXTRACT_ALL
expr_stmt|;
comment|/* Extract all tables found */
break|break;
case|case
literal|'l'
case|:
name|AxAction
operator|=
name|AX_LIST_ALL
expr_stmt|;
comment|/* List tables only, do not extract */
break|break;
case|case
literal|'s'
case|:
name|AxAction
operator|=
name|AX_EXTRACT_SIGNATURE
expr_stmt|;
comment|/* Extract only tables with this sig */
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
name|DisplayUsage
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* Input filename is always required */
name|Filename
operator|=
name|argv
index|[
name|AcpiGbl_Optind
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|Filename
condition|)
block|{
name|printf
argument_list|(
literal|"Missing required input filename\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Perform requested action */
switch|switch
condition|(
name|AxAction
condition|)
block|{
case|case
name|AX_EXTRACT_ALL
case|:
name|Status
operator|=
name|AxExtractTables
argument_list|(
name|Filename
argument_list|,
name|NULL
argument_list|,
name|AX_OPTIONAL_TABLES
argument_list|)
expr_stmt|;
break|break;
case|case
name|AX_LIST_ALL
case|:
name|Status
operator|=
name|AxListTables
argument_list|(
name|Filename
argument_list|)
expr_stmt|;
break|break;
case|case
name|AX_EXTRACT_SIGNATURE
case|:
name|Status
operator|=
name|AxExtractTables
argument_list|(
name|Filename
argument_list|,
name|AcpiGbl_Optarg
argument_list|,
name|AX_REQUIRED_TABLE
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/*          * Default output is the DSDT and all SSDTs. One DSDT is required,          * any SSDTs are optional.          */
name|Status
operator|=
name|AxExtractTables
argument_list|(
name|Filename
argument_list|,
literal|"DSDT"
argument_list|,
name|AX_REQUIRED_TABLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|Status
condition|)
block|{
return|return
operator|(
name|Status
operator|)
return|;
block|}
name|Status
operator|=
name|AxExtractTables
argument_list|(
name|Filename
argument_list|,
literal|"SSDT"
argument_list|,
name|AX_OPTIONAL_TABLES
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|Status
operator|)
return|;
block|}
end_function

end_unit

