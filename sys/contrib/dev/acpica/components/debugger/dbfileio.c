begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: dbfileio - Debugger file I/O commands. These can't usually  *              be used when running the debugger in Ring 0 (Kernel mode)  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_DEBUGGER
operator|||
name|defined
name|ACPI_DISASSEMBLER
operator|)
end_if

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
name|ACPI_STRNCPY
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

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AeLocalLoadTable  *  * PARAMETERS:  Table           - pointer to a buffer containing the entire  *                                table to be loaded  *  * RETURN:      Status  *  * DESCRIPTION: This function is called to load a table from the caller's  *              buffer. The buffer must contain an entire ACPI Table including  *              a valid header. The header fields will be verified, and if it  *              is determined that the table is invalid, the call will fail.  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|ACPI_STATUS
name|AeLocalLoadTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
init|=
name|AE_OK
decl_stmt|;
comment|/*    ACPI_TABLE_DESC         TableInfo; */
name|ACPI_FUNCTION_TRACE
argument_list|(
name|AeLocalLoadTable
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|if (!Table)     {         return_ACPI_STATUS (AE_BAD_PARAMETER);     }      TableInfo.Pointer = Table;     Status = AcpiTbRecognizeTable (&TableInfo, ACPI_TABLE_ALL);     if (ACPI_FAILURE (Status))     {         return_ACPI_STATUS (Status);     }
comment|/* Install the new table into the local data structures */
block|Status = AcpiTbInitTableDescriptor (&TableInfo);     if (ACPI_FAILURE (Status))     {         if (Status == AE_ALREADY_EXISTS)         {
comment|/* Table already exists, no error */
block|Status = AE_OK;         }
comment|/* Free table allocated by AcpiTbGetTable */
block|AcpiTbDeleteSingleTable (&TableInfo);         return_ACPI_STATUS (Status);     }
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|ACPI_NO_METHOD_EXECUTION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACPI_CONSTANT_EVAL_ONLY
argument_list|)
operator|)
block|Status = AcpiNsLoadTable (TableInfo.InstalledDesc, AcpiGbl_RootNode);     if (ACPI_FAILURE (Status))     {
comment|/* Uninstall table and free the buffer */
block|AcpiTbDeleteTablesByType (ACPI_TABLE_ID_DSDT);         return_ACPI_STATUS (Status);     }
endif|#
directive|endif
endif|#
directive|endif
name|return_ACPI_STATUS
argument_list|(
name|Status
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDbGetTableFromFile  *  * PARAMETERS:  Filename        - File where table is located  *              ReturnTable     - Where a pointer to the table is returned  *  * RETURN:      Status  *  * DESCRIPTION: Load an ACPI table from a file  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDbGetTableFromFile
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|ReturnTable
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
name|ACPI_STATUS
name|Status
decl_stmt|;
name|ACPI_TABLE_HEADER
modifier|*
name|Table
decl_stmt|;
name|BOOLEAN
name|IsAmlTable
init|=
name|TRUE
decl_stmt|;
name|Status
operator|=
name|AcpiUtReadTableFromFile
argument_list|(
name|Filename
argument_list|,
operator|&
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
return|return
operator|(
name|Status
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|ACPI_DATA_TABLE_DISASSEMBLY
name|IsAmlTable
operator|=
name|AcpiUtIsAmlTable
argument_list|(
name|Table
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|IsAmlTable
condition|)
block|{
comment|/* Attempt to recognize and install the table */
name|Status
operator|=
name|AeLocalLoadTable
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
name|AcpiTbPrintTableHeader
argument_list|(
literal|0
argument_list|,
name|Table
argument_list|)
expr_stmt|;
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
block|}
name|AcpiGbl_AcpiHardwarePresent
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|ReturnTable
condition|)
block|{
operator|*
name|ReturnTable
operator|=
name|Table
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ACPI_APPLICATION */
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUGGER */
end_comment

end_unit

