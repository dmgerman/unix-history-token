begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: dbfileio - Debugger file I/O commands. These can't usually  *              be used when running the debugger in Ring 0 (Kernel mode)  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2016, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acdebug.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actables.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acapps.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_CA_DEBUGGER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"dbfileio"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbCloseDebugFile  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: If open, close the current debug output file  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDbCloseDebugFile
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
if|if
condition|(
name|AcpiGbl_DebugFile
condition|)
block|{
name|fclose
argument_list|(
name|AcpiGbl_DebugFile
argument_list|)
expr_stmt|;
name|AcpiGbl_DebugFile
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_DbOutputToFile
operator|=
name|FALSE
expr_stmt|;
name|AcpiOsPrintf
argument_list|(
literal|"Debug output file %s closed\n"
argument_list|,
name|AcpiGbl_DbDebugFilename
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbOpenDebugFile  *  * PARAMETERS:  Name                - Filename to open  *  * RETURN:      None  *  * DESCRIPTION: Open a file where debug output will be directed.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDbOpenDebugFile
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
name|AcpiDbCloseDebugFile
argument_list|()
expr_stmt|;
name|AcpiGbl_DebugFile
operator|=
name|fopen
argument_list|(
name|Name
argument_list|,
literal|"w+"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|AcpiGbl_DebugFile
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"Could not open debug file %s\n"
argument_list|,
name|Name
argument_list|)
expr_stmt|;
return|return;
block|}
name|AcpiOsPrintf
argument_list|(
literal|"Debug output file %s opened\n"
argument_list|,
name|Name
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|AcpiGbl_DbDebugFilename
argument_list|,
name|Name
argument_list|,
sizeof|sizeof
argument_list|(
name|AcpiGbl_DbDebugFilename
argument_list|)
argument_list|)
expr_stmt|;
name|AcpiGbl_DbOutputToFile
operator|=
name|TRUE
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbLoadTables  *  * PARAMETERS:  ListHead        - List of ACPI tables to load  *  * RETURN:      Status  *  * DESCRIPTION: Load ACPI tables from a previously constructed table list.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDbLoadTables
parameter_list|(
name|ACPI_NEW_TABLE_DESC
modifier|*
name|ListHead
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|ACPI_NEW_TABLE_DESC
modifier|*
name|TableListHead
decl_stmt|;
name|ACPI_TABLE_HEADER
modifier|*
name|Table
decl_stmt|;
comment|/* Load all ACPI tables in the list */
name|TableListHead
operator|=
name|ListHead
expr_stmt|;
while|while
condition|(
name|TableListHead
condition|)
block|{
name|Table
operator|=
name|TableListHead
operator|->
name|Table
expr_stmt|;
name|Status
operator|=
name|AcpiLoadTable
argument_list|(
name|Table
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
if|if
condition|(
name|Status
operator|==
name|AE_ALREADY_EXISTS
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"Table %4.4s is already installed\n"
argument_list|,
name|Table
operator|->
name|Signature
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|AcpiOsPrintf
argument_list|(
literal|"Could not install table, %s\n"
argument_list|,
name|AcpiFormatException
argument_list|(
name|Status
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|Status
operator|)
return|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Acpi table [%4.4s] successfully installed and loaded\n"
argument_list|,
name|Table
operator|->
name|Signature
argument_list|)
expr_stmt|;
name|TableListHead
operator|=
name|TableListHead
operator|->
name|Next
expr_stmt|;
block|}
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

end_unit

