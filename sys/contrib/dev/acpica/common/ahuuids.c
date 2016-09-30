begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahuuids - Table of known ACPI-related UUIDs  *  *****************************************************************************/
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
file|<contrib/dev/acpica/include/acuuid.h>
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
literal|"[Controllers]"
block|,
name|NULL
block|}
block|,
block|{
literal|"GPIO Controller"
block|,
name|UUID_GPIO_CONTROLLER
block|}
block|,
block|{
literal|"USB Controller"
block|,
name|UUID_USB_CONTROLLER
block|}
block|,
block|{
literal|"SATA Controller"
block|,
name|UUID_SATA_CONTROLLER
block|}
block|,
block|{
literal|"[Devices]"
block|,
name|NULL
block|}
block|,
block|{
literal|"PCI Host Bridge Device"
block|,
name|UUID_PCI_HOST_BRIDGE
block|}
block|,
block|{
literal|"HID I2C Device"
block|,
name|UUID_I2C_DEVICE
block|}
block|,
block|{
literal|"Power Button Device"
block|,
name|UUID_POWER_BUTTON
block|}
block|,
block|{
literal|"[Interfaces]"
block|,
name|NULL
block|}
block|,
block|{
literal|"Device Labeling Interface"
block|,
name|UUID_DEVICE_LABELING
block|}
block|,
block|{
literal|"Physical Presence Interface"
block|,
name|UUID_PHYSICAL_PRESENCE
block|}
block|,
block|{
literal|"[Non-volatile DIMM and NFIT table]"
block|,
name|NULL
block|}
block|,
block|{
literal|"Volatile Memory Region"
block|,
name|UUID_VOLATILE_MEMORY
block|}
block|,
block|{
literal|"Persistent Memory Region"
block|,
name|UUID_PERSISTENT_MEMORY
block|}
block|,
block|{
literal|"NVDIMM Control Region"
block|,
name|UUID_CONTROL_REGION
block|}
block|,
block|{
literal|"NVDIMM Data Region"
block|,
name|UUID_DATA_REGION
block|}
block|,
block|{
literal|"Volatile Virtual Disk"
block|,
name|UUID_VOLATILE_VIRTUAL_DISK
block|}
block|,
block|{
literal|"Volatile Virtual CD"
block|,
name|UUID_VOLATILE_VIRTUAL_CD
block|}
block|,
block|{
literal|"Persistent Virtual Disk"
block|,
name|UUID_PERSISTENT_VIRTUAL_DISK
block|}
block|,
block|{
literal|"Persistent Virtual CD"
block|,
name|UUID_PERSISTENT_VIRTUAL_CD
block|}
block|,
block|{
literal|"[Miscellaneous]"
block|,
name|NULL
block|}
block|,
block|{
literal|"Platform-wide Capabilities"
block|,
name|UUID_PLATFORM_CAPABILITIES
block|}
block|,
block|{
literal|"Dynamic Enumeration"
block|,
name|UUID_DYNAMIC_ENUMERATION
block|}
block|,
block|{
literal|"Battery Thermal Limit"
block|,
name|UUID_BATTERY_THERMAL_LIMIT
block|}
block|,
block|{
literal|"Thermal Extensions"
block|,
name|UUID_THERMAL_EXTENSIONS
block|}
block|,
block|{
literal|"Device Properties for _DSD"
block|,
name|UUID_DEVICE_PROPERTIES
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
comment|/* Null string means desciption is a UUID class */
if|if
condition|(
operator|!
name|Info
operator|->
name|String
condition|)
block|{
continue|continue;
block|}
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
name|memcmp
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

