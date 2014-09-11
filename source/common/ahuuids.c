begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahuuids - Table of known ACPI-related UUIDs  *  *****************************************************************************/
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

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"ahuuids"
argument_list|)
end_macro

begin_comment
comment|/*  * Table of "known" (ACPI-related) UUIDs  */
end_comment

begin_decl_stmt
specifier|const
name|AH_UUID
name|AcpiUuids
index|[]
init|=
block|{
block|{
literal|"PCI Host Bridge Device"
block|,
literal|"33db4d5b-1ff7-401c-9657-7441c03dd766"
block|}
block|,
block|{
literal|"Platform-wide Capabilities"
block|,
literal|"0811b06e-4a27-44f9-8d60-3cbbc22e7b48"
block|}
block|,
block|{
literal|"Dynamic Enumeration"
block|,
literal|"d8c1a3a6-be9b-4c9b-91bf-c3cb81fc5daf"
block|}
block|,
block|{
literal|"GPIO Controller"
block|,
literal|"4f248f40-d5e2-499f-834c-27758ea1cd3f"
block|}
block|,
block|{
literal|"Battery Thermal Limit"
block|,
literal|"4c2067e3-887d-475c-9720-4af1d3ed602e"
block|}
block|,
block|{
literal|"Thermal Extensions"
block|,
literal|"14d399cd-7a27-4b18-8fb4-7cb7b9f4e500"
block|}
block|,
block|{
literal|"USB Controller"
block|,
literal|"ce2ee385-00e6-48cb-9f05-2edb927c4899"
block|}
block|,
block|{
literal|"HID I2C Device"
block|,
literal|"3cdff6f7-4267-4555-ad05-b30a3d8938de"
block|}
block|,
block|{
literal|"Power Button Device"
block|,
literal|"dfbcf3c5-e7a5-44e6-9c1f-29c76f6e059c"
block|}
block|,
block|{
literal|"Device Labeling Interface"
block|,
literal|"e5c937d0-3553-4d7a-9117-ea4d19c3434d"
block|}
block|,
block|{
literal|"SATA Controller"
block|,
literal|"e4db149b-fcfe-425b-a6d8-92357d78fc7f"
block|}
block|,
block|{
literal|"Physical Presence Interface"
block|,
literal|"3dddfaa6-361b-4eb4-a424-8d10089d1653"
block|}
block|,
block|{
literal|"Device Properties for _DSD"
block|,
literal|"daffd814-6eba-4d8c-8a91-bc9bbf4aa301"
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiAhMatchUuid  *  * PARAMETERS:  Data                - Data buffer containing a UUID  *  * RETURN:      ASCII description string for the UUID if it is found.  *  * DESCRIPTION: Returns a description string for "known" UUIDs, which are  *              are UUIDs that are related to ACPI in some way.  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|AcpiAhMatchUuid
parameter_list|(
name|UINT8
modifier|*
name|Data
parameter_list|)
block|{
specifier|const
name|AH_UUID
modifier|*
name|Info
decl_stmt|;
name|UINT8
name|UuidBuffer
index|[
name|UUID_BUFFER_LENGTH
index|]
decl_stmt|;
comment|/* Walk the table of known ACPI-related UUIDs */
for|for
control|(
name|Info
operator|=
name|AcpiUuids
init|;
name|Info
operator|->
name|Description
condition|;
name|Info
operator|++
control|)
block|{
name|AcpiUtConvertStringToUuid
argument_list|(
name|Info
operator|->
name|String
argument_list|,
name|UuidBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ACPI_MEMCMP
argument_list|(
name|Data
argument_list|,
name|UuidBuffer
argument_list|,
name|UUID_BUFFER_LENGTH
argument_list|)
condition|)
block|{
return|return
operator|(
name|Info
operator|->
name|Description
operator|)
return|;
block|}
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

