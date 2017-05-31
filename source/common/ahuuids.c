begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahuuids - Table of known ACPI-related UUIDs  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
file|"acuuid.h"
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
name|Gbl_AcpiUuids
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
literal|"[Processor Properties]"
block|,
name|NULL
block|}
block|,
block|{
literal|"Cache Properties"
block|,
name|UUID_CACHE_PROPERTIES
block|}
block|,
block|{
literal|"Physical Package Property"
block|,
name|UUID_PHYSICAL_PROPERTY
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
name|Gbl_AcpiUuids
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

