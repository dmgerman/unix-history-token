begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: apmain - Main module for the acpidump utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2013, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|_DECLARE_GLOBALS
end_define

begin_include
include|#
directive|include
file|"acpidump.h"
end_include

begin_include
include|#
directive|include
file|"acapps.h"
end_include

begin_comment
comment|/*  * acpidump - A portable utility for obtaining system ACPI tables and dumping  * them in an ASCII hex format suitable for binary extraction via acpixtract.  *  * Obtaining the system ACPI tables is an OS-specific operation.  *  * This utility can be ported to any host operating system by providing a  * module containing system-specific versions of these interfaces:  *  *      AcpiOsGetTableByAddress  *      AcpiOsGetTableByIndex  *      AcpiOsGetTableByName  *  * See the ACPICA Reference Guide for the exact definitions of these  * interfaces. Also, see these ACPICA source code modules for example  * implementations:  *  *      source/os_specific/service_layers/oswintbl.c  *      source/os_specific/service_layers/oslinuxtbl.c  */
end_comment

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|ApDisplayUsage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ApDoOptions
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ApInsertAction
parameter_list|(
name|char
modifier|*
name|Argument
parameter_list|,
name|UINT32
name|ToBeDone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Table for deferred actions from command line options */
end_comment

begin_decl_stmt
name|AP_DUMP_ACTION
name|ActionTable
index|[
name|AP_MAX_ACTIONS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UINT32
name|CurrentAction
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AP_UTILITY_NAME
value|"ACPI Binary Table Dump Utility"
end_define

begin_define
define|#
directive|define
name|AP_SUPPORTED_OPTIONS
value|"?a:bf:hn:o:rsv"
end_define

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    ApDisplayUsage  *  * DESCRIPTION: Usage message for the AcpiDump utility  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|ApDisplayUsage
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_USAGE_HEADER
argument_list|(
literal|"acpidump [options]"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-b"
argument_list|,
literal|"Dump tables to binary files"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-h -?"
argument_list|,
literal|"This help message"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-o<File>"
argument_list|,
literal|"Redirect output to file"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-r"
argument_list|,
literal|"Revision (version)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-s"
argument_list|,
literal|"Print table summaries only"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-v"
argument_list|,
literal|"Verbose mode"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nTable Options:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-a<Address>"
argument_list|,
literal|"Get table via physical address"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-f<BinaryFile>"
argument_list|,
literal|"Get table via binary file"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-n<Signature>"
argument_list|,
literal|"Get table via name/signature"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
literal|"Invocation without parameters dumps all available tables\n"
literal|"Multiple mixed instances of -a, -f, and -n are supported\n\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    ApInsertAction  *  * PARAMETERS:  Argument            - Pointer to the argument for this action  *              ToBeDone            - What to do to process this action  *  * RETURN:      None. Exits program if action table becomes full.  *  * DESCRIPTION: Add an action item to the action table  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|ApInsertAction
parameter_list|(
name|char
modifier|*
name|Argument
parameter_list|,
name|UINT32
name|ToBeDone
parameter_list|)
block|{
comment|/* Insert action and check for table overflow */
name|ActionTable
index|[
name|CurrentAction
index|]
operator|.
name|Argument
operator|=
name|Argument
expr_stmt|;
name|ActionTable
index|[
name|CurrentAction
index|]
operator|.
name|ToBeDone
operator|=
name|ToBeDone
expr_stmt|;
name|CurrentAction
operator|++
expr_stmt|;
if|if
condition|(
name|CurrentAction
operator|>
name|AP_MAX_ACTIONS
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Too many table options (max %u)\n"
argument_list|,
name|AP_MAX_ACTIONS
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    ApDoOptions  *  * PARAMETERS:  argc/argv           - Standard argc/argv  *  * RETURN:      Status  *  * DESCRIPTION: Command line option processing. The main actions for getting  *              and dumping tables are deferred via the action table.  *  *****************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|ApDoOptions
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|j
decl_stmt|;
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
name|AP_SUPPORTED_OPTIONS
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
comment|/*      * Global options      */
case|case
literal|'b'
case|:
comment|/* Dump all input tables to binary files */
name|Gbl_BinaryMode
operator|=
name|TRUE
expr_stmt|;
continue|continue;
case|case
literal|'h'
case|:
case|case
literal|'?'
case|:
name|ApDisplayUsage
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'o'
case|:
comment|/* Redirect output to a single file */
if|if
condition|(
name|ApOpenOutputFile
argument_list|(
name|AcpiGbl_Optarg
argument_list|)
condition|)
block|{
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
continue|continue;
case|case
literal|'r'
case|:
comment|/* Revision/version */
name|printf
argument_list|(
name|ACPI_COMMON_SIGNON
argument_list|(
name|AP_UTILITY_NAME
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'s'
case|:
comment|/* Print table summaries only */
name|Gbl_SummaryMode
operator|=
name|TRUE
expr_stmt|;
continue|continue;
case|case
literal|'v'
case|:
comment|/* Verbose mode */
name|Gbl_VerboseMode
operator|=
name|TRUE
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|ACPI_COMMON_SIGNON
argument_list|(
name|AP_UTILITY_NAME
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
comment|/*      * Table options      */
case|case
literal|'a'
case|:
comment|/* Get table by physical address */
name|ApInsertAction
argument_list|(
name|AcpiGbl_Optarg
argument_list|,
name|AP_DUMP_TABLE_BY_ADDRESS
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* Get table from a file */
name|ApInsertAction
argument_list|(
name|AcpiGbl_Optarg
argument_list|,
name|AP_DUMP_TABLE_BY_FILE
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
comment|/* Get table by input name (signature) */
name|ApInsertAction
argument_list|(
name|AcpiGbl_Optarg
argument_list|,
name|AP_DUMP_TABLE_BY_NAME
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ApDisplayUsage
argument_list|()
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* If there are no actions, this means "get/dump all tables" */
if|if
condition|(
name|CurrentAction
operator|==
literal|0
condition|)
block|{
name|ApInsertAction
argument_list|(
name|NULL
argument_list|,
name|AP_DUMP_ALL_TABLES
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    main  *  * PARAMETERS:  argc/argv           - Standard argc/argv  *  * RETURN:      Status  *  * DESCRIPTION: C main function for acpidump utility  *  ******************************************************************************/
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
name|int
name|Status
init|=
literal|0
decl_stmt|;
name|AP_DUMP_ACTION
modifier|*
name|Action
decl_stmt|;
name|UINT32
name|FileSize
decl_stmt|;
name|UINT32
name|i
decl_stmt|;
name|ACPI_DEBUG_INITIALIZE
argument_list|()
expr_stmt|;
comment|/* For debug version only */
comment|/* Process command line options */
if|if
condition|(
name|ApDoOptions
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Get/dump ACPI table(s) as requested */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|CurrentAction
condition|;
name|i
operator|++
control|)
block|{
name|Action
operator|=
operator|&
name|ActionTable
index|[
name|i
index|]
expr_stmt|;
switch|switch
condition|(
name|Action
operator|->
name|ToBeDone
condition|)
block|{
case|case
name|AP_DUMP_ALL_TABLES
case|:
name|Status
operator|=
name|ApDumpAllTables
argument_list|()
expr_stmt|;
break|break;
case|case
name|AP_DUMP_TABLE_BY_ADDRESS
case|:
name|Status
operator|=
name|ApDumpTableByAddress
argument_list|(
name|Action
operator|->
name|Argument
argument_list|)
expr_stmt|;
break|break;
case|case
name|AP_DUMP_TABLE_BY_NAME
case|:
name|Status
operator|=
name|ApDumpTableByName
argument_list|(
name|Action
operator|->
name|Argument
argument_list|)
expr_stmt|;
break|break;
case|case
name|AP_DUMP_TABLE_BY_FILE
case|:
name|Status
operator|=
name|ApDumpTableFromFile
argument_list|(
name|Action
operator|->
name|Argument
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Internal error, invalid action: 0x%X\n"
argument_list|,
name|Action
operator|->
name|ToBeDone
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
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
block|}
if|if
condition|(
name|Gbl_OutputFile
condition|)
block|{
if|if
condition|(
name|Gbl_VerboseMode
condition|)
block|{
comment|/* Summary for the output file */
name|FileSize
operator|=
name|ApGetFileSize
argument_list|(
name|Gbl_OutputFile
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Output file %s contains 0x%X (%u) bytes\n\n"
argument_list|,
name|Gbl_OutputFilename
argument_list|,
name|FileSize
argument_list|,
name|FileSize
argument_list|)
expr_stmt|;
block|}
name|fclose
argument_list|(
name|Gbl_OutputFile
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|Status
operator|)
return|;
block|}
end_function

end_unit

