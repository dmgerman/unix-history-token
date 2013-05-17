begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: oslinuxtbl - Linux OSL for obtaining ACPI tables  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2013, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_OS_SERVICES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"oslinuxtbl"
argument_list|)
end_macro

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetTableByAddress  *  * PARAMETERS:  Address         - Physical address of the ACPI table  *              Table           - Where a pointer to the table is returned  *  * RETURN:      Status; Table buffer is returned if AE_OK.  *              AE_NOT_FOUND: A valid table was not found at the address  *  * DESCRIPTION: Get an ACPI table via a physical memory address.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsGetTableByAddress
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Linux version not implemented yet\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|AE_SUPPORT
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetTableByIndex  *  * PARAMETERS:  Index           - Which table to get  *              Table           - Where a pointer to the table is returned  *              Address         - Where the table physical address is returned  *  * RETURN:      Status; Table buffer and physical address returned if AE_OK.  *              AE_LIMIT: Index is beyond valid limit  *  * DESCRIPTION: Get an ACPI table via an index value (0 through n). Returns  *              AE_LIMIT when an invalid index is reached. Index is not  *              necessarily an index into the RSDT/XSDT.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsGetTableByIndex
parameter_list|(
name|UINT32
name|Index
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|Address
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Linux version not implemented yet\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|AE_SUPPORT
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiOsGetTableByName  *  * PARAMETERS:  Signature       - ACPI Signature for desired table. Must be  *                                a null terminated 4-character string.  *              Instance        - For SSDTs (0...n)  *              Table           - Where a pointer to the table is returned  *              Address         - Where the table physical address is returned  *  * RETURN:      Status; Table buffer and physical address returned if AE_OK.  *  * RETURN:      Status; Table buffer and physical address returned if AE_OK.  *              AE_LIMIT: Instance is beyond valid limit  *              AE_NOT_FOUND: A table with the signature was not found  *  * NOTE:        Assumes the input signature is uppercase.  *  *****************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiOsGetTableByName
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|,
name|UINT32
name|Instance
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|Table
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|Address
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Linux version not implemented yet\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|AE_SUPPORT
operator|)
return|;
block|}
end_function

end_unit

