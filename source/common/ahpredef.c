begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahpredef - Table of all known ACPI predefined names  *  *****************************************************************************/
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

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"ahpredef"
argument_list|)
end_macro

begin_comment
comment|/*  * iASL only needs a partial table (short descriptions only).  * AcpiHelp needs the full table.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_define
define|#
directive|define
name|AH_PREDEF
parameter_list|(
name|Name
parameter_list|,
name|ShortDesc
parameter_list|,
name|LongDesc
parameter_list|)
value|{Name, ShortDesc}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AH_PREDEF
parameter_list|(
name|Name
parameter_list|,
name|ShortDesc
parameter_list|,
name|LongDesc
parameter_list|)
value|{Name, ShortDesc, LongDesc}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Predefined ACPI names, with short description and return value.  * This table was extracted directly from the ACPI specification.  */
end_comment

begin_decl_stmt
specifier|const
name|AH_PREDEFINED_NAME
name|AslPredefinedInfo
index|[]
init|=
block|{
name|AH_PREDEF
argument_list|(
literal|"_ACx"
argument_list|,
literal|"Active Cooling"
argument_list|,
literal|"Returns the active cooling policy threshold values"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ADR"
argument_list|,
literal|"Address"
argument_list|,
literal|"Returns address of a device on parent bus, and resource field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_AEI"
argument_list|,
literal|"ACPI Event Interrupts"
argument_list|,
literal|"Returns a list of GPIO events to be used as ACPI events"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALC"
argument_list|,
literal|"Ambient Light Chromaticity"
argument_list|,
literal|"Returns the ambient light color chromaticity"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALI"
argument_list|,
literal|"Ambient Light Illuminance"
argument_list|,
literal|"Returns the ambient light brightness"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALN"
argument_list|,
literal|"Alignment"
argument_list|,
literal|"Base alignment, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALP"
argument_list|,
literal|"Ambient Light Polling"
argument_list|,
literal|"Returns the ambient light sensor polling frequency"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALR"
argument_list|,
literal|"Ambient Light Response"
argument_list|,
literal|"Returns the ambient light brightness to display brightness mappings"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALT"
argument_list|,
literal|"Ambient Light Temperature"
argument_list|,
literal|"Returns the ambient light color temperature"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ALx"
argument_list|,
literal|"Active List"
argument_list|,
literal|"Returns a list of active cooling device objects"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ART"
argument_list|,
literal|"Active Cooling Relationship Table"
argument_list|,
literal|"Returns thermal relationship information between platform devices and fan devices"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ASI"
argument_list|,
literal|"Address Space Id"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ASZ"
argument_list|,
literal|"Access Size"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ATT"
argument_list|,
literal|"Type-Specific Attribute"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BAS"
argument_list|,
literal|"Base Address"
argument_list|,
literal|"Range base address, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BBN"
argument_list|,
literal|"BIOS Bus Number"
argument_list|,
literal|"Returns the PCI bus number returned by the BIOS"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BCL"
argument_list|,
literal|"Brightness Control Levels"
argument_list|,
literal|"Returns a list of supported brightness control levels"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BCM"
argument_list|,
literal|"Brightness Control Method"
argument_list|,
literal|"Sets the brightness level of the display device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BCT"
argument_list|,
literal|"Battery Charge Time"
argument_list|,
literal|"Returns time remaining to complete charging battery"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BDN"
argument_list|,
literal|"BIOS Dock Name"
argument_list|,
literal|"Returns the Dock ID returned by the BIOS"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BFS"
argument_list|,
literal|"Back From Sleep"
argument_list|,
literal|"Inform AML of a wake event"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BIF"
argument_list|,
literal|"Battery Information"
argument_list|,
literal|"Returns a Control Method Battery information block"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BIX"
argument_list|,
literal|"Battery Information Extended"
argument_list|,
literal|"Returns a Control Method Battery extended information block"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BLT"
argument_list|,
literal|"Battery Level Threshold"
argument_list|,
literal|"Set battery level threshold preferences"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BM_"
argument_list|,
literal|"Bus Master"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BMA"
argument_list|,
literal|"Battery Measurement Averaging Interval"
argument_list|,
literal|"Sets battery measurement averaging interval"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BMC"
argument_list|,
literal|"Battery Maintenance Control"
argument_list|,
literal|"Sets battery maintenance and control features"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BMD"
argument_list|,
literal|"Battery Maintenance Data"
argument_list|,
literal|"Returns battery maintenance, control, and state data"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BMS"
argument_list|,
literal|"Battery Measurement Sampling Time"
argument_list|,
literal|"Sets the battery measurement sampling time"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BQC"
argument_list|,
literal|"Brightness Query Current"
argument_list|,
literal|"Returns the current display brightness level"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BST"
argument_list|,
literal|"Battery Status"
argument_list|,
literal|"Returns a Control Method Battery status block"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BTH"
argument_list|,
literal|"Battery Throttle Limit"
argument_list|,
literal|"Thermal limit for charging and discharging"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BTM"
argument_list|,
literal|"Battery Time"
argument_list|,
literal|"Returns the battery runtime"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_BTP"
argument_list|,
literal|"Battery Trip Point"
argument_list|,
literal|"Sets a Control Method Battery trip point"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CBA"
argument_list|,
literal|"Configuration Base Address"
argument_list|,
literal|"Sets the base address for a PCI Express host bridge"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CCA"
argument_list|,
literal|"Cache Coherency Attribute"
argument_list|,
literal|"Returns a device's support level for cache coherency"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CDM"
argument_list|,
literal|"Clock Domain"
argument_list|,
literal|"Returns a logical processor's clock domain identifier"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CID"
argument_list|,
literal|"Compatible ID"
argument_list|,
literal|"Returns a device's Plug and Play Compatible ID list"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CLS"
argument_list|,
literal|"Class Code"
argument_list|,
literal|"Returns PCI class code and subclass"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CPC"
argument_list|,
literal|"Continuous Performance Control"
argument_list|,
literal|"Returns a list of performance control interfaces"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CR3"
argument_list|,
literal|"Warm/Standby Temperature"
argument_list|,
literal|"Temperature for a fast low power state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CRS"
argument_list|,
literal|"Current Resource Settings"
argument_list|,
literal|"Returns the current resource settings for a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CRT"
argument_list|,
literal|"Critical Temperature"
argument_list|,
literal|"Returns the shutdown critical temperature"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CSD"
argument_list|,
literal|"C-State Dependencies"
argument_list|,
literal|"Returns a list of C-state dependencies"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CST"
argument_list|,
literal|"C-States"
argument_list|,
literal|"Returns a list of supported C-states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_CWS"
argument_list|,
literal|"Clear Wake Alarm Status"
argument_list|,
literal|"Clear the status of wake alarms"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DBT"
argument_list|,
literal|"Debounce Timeout"
argument_list|,
literal|"Timeout value, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DCK"
argument_list|,
literal|"Dock Present"
argument_list|,
literal|"Sets docking isolation. Presence indicates device is a docking station"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DCS"
argument_list|,
literal|"Display Current Status"
argument_list|,
literal|"Returns status of the display output device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DDC"
argument_list|,
literal|"Display Data Current"
argument_list|,
literal|"Returns the EDID for the display output device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DDN"
argument_list|,
literal|"DOS Device Name"
argument_list|,
literal|"Returns a device logical name"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DEC"
argument_list|,
literal|"Decode"
argument_list|,
literal|"Device decoding type, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DEP"
argument_list|,
literal|"Dependencies"
argument_list|,
literal|"Returns a list of operation region dependencies"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DGS"
argument_list|,
literal|"Display Graphics State"
argument_list|,
literal|"Return the current state of the output device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DIS"
argument_list|,
literal|"Disable Device"
argument_list|,
literal|"Disables a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DLM"
argument_list|,
literal|"Device Lock Mutex"
argument_list|,
literal|"Defines mutex for OS/AML sharing"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DMA"
argument_list|,
literal|"Direct Memory Access"
argument_list|,
literal|"Returns device current resources for DMA transactions, and resource field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DOD"
argument_list|,
literal|"Display Output Devices"
argument_list|,
literal|"Enumerate all devices attached to the display adapter"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DOS"
argument_list|,
literal|"Disable Output Switching"
argument_list|,
literal|"Sets the display output switching mode"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DPL"
argument_list|,
literal|"Device Selection Polarity"
argument_list|,
literal|"Polarity of Device Selection signal, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DRS"
argument_list|,
literal|"Drive Strength"
argument_list|,
literal|"Drive Strength setting for GPIO connection, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DSD"
argument_list|,
literal|"Device-Specific Data"
argument_list|,
literal|"Returns a list of device property information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DSM"
argument_list|,
literal|"Device-Specific Method"
argument_list|,
literal|"Executes device-specific functions"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DSS"
argument_list|,
literal|"Device Set State"
argument_list|,
literal|"Sets the display device state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DSW"
argument_list|,
literal|"Device Sleep Wake"
argument_list|,
literal|"Sets the sleep and wake transition states for a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_DTI"
argument_list|,
literal|"Device Temperature Indication"
argument_list|,
literal|"Conveys native device temperature to the platform"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_Exx"
argument_list|,
literal|"Edge-Triggered GPE"
argument_list|,
literal|"Method executed as a result of a general-purpose event"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_EC_"
argument_list|,
literal|"Embedded Controller"
argument_list|,
literal|"returns EC offset and query information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_EDL"
argument_list|,
literal|"Eject Device List"
argument_list|,
literal|"Returns a list of devices that are dependent on a device (docking)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_EJD"
argument_list|,
literal|"Ejection Dependent Device"
argument_list|,
literal|"Returns the name of dependent (parent) device (docking)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_EJx"
argument_list|,
literal|"Eject Device"
argument_list|,
literal|"Begin or cancel a device ejection request (docking)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_END"
argument_list|,
literal|"Endianness"
argument_list|,
literal|"Endian orientation, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_EVT"
argument_list|,
literal|"Event"
argument_list|,
literal|"Event method for GPIO events"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FDE"
argument_list|,
literal|"Floppy Disk Enumerate"
argument_list|,
literal|"Returns floppy disk configuration information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FDI"
argument_list|,
literal|"Floppy Drive Information"
argument_list|,
literal|"Returns a floppy drive information block"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FDM"
argument_list|,
literal|"Floppy Drive Mode"
argument_list|,
literal|"Sets a floppy drive speed"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FIF"
argument_list|,
literal|"Fan Information"
argument_list|,
literal|"Returns fan device information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FIT"
argument_list|,
literal|"Firmware Interface Table"
argument_list|,
literal|"Returns a list of NFIT structures"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FIX"
argument_list|,
literal|"Fixed Register Resource Provider"
argument_list|,
literal|"Returns a list of devices that implement FADT register blocks"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FLC"
argument_list|,
literal|"Flow Control"
argument_list|,
literal|"Flow control, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FPS"
argument_list|,
literal|"Fan Performance States"
argument_list|,
literal|"Returns a list of supported fan performance states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FSL"
argument_list|,
literal|"Fan Set Level"
argument_list|,
literal|"Control method that sets the fan device's speed level (performance state)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FST"
argument_list|,
literal|"Fan Status"
argument_list|,
literal|"Returns current status information for a fan device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_FUN"
argument_list|,
literal|"Function Number"
argument_list|,
literal|"Resource descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GAI"
argument_list|,
literal|"Get Averaging Interval"
argument_list|,
literal|"Returns the power meter averaging interval"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GCP"
argument_list|,
literal|"Get Capabilities"
argument_list|,
literal|"Get device time capabilities"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GHL"
argument_list|,
literal|"Get Hardware Limit"
argument_list|,
literal|"Returns the hardware limit enforced by the power meter"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GL_"
argument_list|,
literal|"Global Lock"
argument_list|,
literal|"OS-defined Global Lock mutex object"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GLK"
argument_list|,
literal|"Get Global Lock Requirement"
argument_list|,
literal|"Returns a device's Global Lock requirement for device access"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GPD"
argument_list|,
literal|"Get Post Data"
argument_list|,
literal|"Returns the value of the VGA device that will be posted at boot"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GPE"
argument_list|,
literal|"General Purpose Events"
argument_list|,
literal|"Predefined scope (\\_GPE) or SCI number for EC"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GRA"
argument_list|,
literal|"Granularity"
argument_list|,
literal|"Address space granularity, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GRT"
argument_list|,
literal|"Get Real Time"
argument_list|,
literal|"Returns current time-of-day from a time/alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GSB"
argument_list|,
literal|"Global System Interrupt Base"
argument_list|,
literal|"Returns the GSB for a I/O APIC device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GTF"
argument_list|,
literal|"Get Task File"
argument_list|,
literal|"Returns a list of ATA commands to restore a drive to default state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GTM"
argument_list|,
literal|"Get Timing Mode"
argument_list|,
literal|"Returns a list of IDE controller timing information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GTS"
argument_list|,
literal|"Going To Sleep"
argument_list|,
literal|"Inform AML of pending sleep"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_GWS"
argument_list|,
literal|"Get Wake Status"
argument_list|,
literal|"Return status of wake alarms"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HE_"
argument_list|,
literal|"High-Edge"
argument_list|,
literal|"Interrupt triggering, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HID"
argument_list|,
literal|"Hardware ID"
argument_list|,
literal|"Returns a device's Plug and Play Hardware ID"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HMA"
argument_list|,
literal|"Heterogeneous Memory Attributes"
argument_list|,
literal|"Returns a list of HMAT structures."
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HOT"
argument_list|,
literal|"Hot Temperature"
argument_list|,
literal|"Returns the critical temperature for sleep (entry to S4)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HPP"
argument_list|,
literal|"Hot Plug Parameters"
argument_list|,
literal|"Returns a list of hot-plug information for a PCI device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HPX"
argument_list|,
literal|"Hot Plug Parameter Extensions"
argument_list|,
literal|"Returns a list of hot-plug information for a PCI device. Supersedes _HPP"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_HRV"
argument_list|,
literal|"Hardware Revision"
argument_list|,
literal|"Returns a hardware revision value"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_IFT"
argument_list|,
literal|"IPMI Interface Type"
argument_list|,
literal|"See the Intelligent Platform Management Interface Specification"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_INI"
argument_list|,
literal|"Initialize"
argument_list|,
literal|"Performs device specific initialization"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_INT"
argument_list|,
literal|"Interrupts"
argument_list|,
literal|"Interrupt mask bits, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_IOR"
argument_list|,
literal|"I/O Restriction"
argument_list|,
literal|"Restriction type, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_IRC"
argument_list|,
literal|"Inrush Current"
argument_list|,
literal|"Presence indicates that a device has a significant inrush current draw"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_Lxx"
argument_list|,
literal|"Level-Triggered GPE"
argument_list|,
literal|"Control method executed as a result of a general-purpose event"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LCK"
argument_list|,
literal|"Lock Device"
argument_list|,
literal|"Locks or unlocks a device (docking)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LEN"
argument_list|,
literal|"Length"
argument_list|,
literal|"Range length, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LID"
argument_list|,
literal|"Lid Status"
argument_list|,
literal|"Returns the open/closed status of the lid on a mobile system"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LIN"
argument_list|,
literal|"Lines In Use"
argument_list|,
literal|"Handshake lines, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LL_"
argument_list|,
literal|"Low Level"
argument_list|,
literal|"Interrupt polarity, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LPD"
argument_list|,
literal|"Low Power Dependencies"
argument_list|,
literal|"Returns a list of dependencies for low power idle entry"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LPI"
argument_list|,
literal|"Low Power Idle States"
argument_list|,
literal|"Returns a list of supported low power idle states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LSI"
argument_list|,
literal|"Label Storage Information"
argument_list|,
literal|"Returns information about the Label Storage Area associated with the NVDIMM object."
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LSR"
argument_list|,
literal|"Label Storage Read"
argument_list|,
literal|"Returns label data from the Label Storage Area of the NVDIMM object."
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_LSW"
argument_list|,
literal|"Label Storage Write"
argument_list|,
literal|"Writes label data in to the Label Storage Area of the NVDIMM object."
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MAF"
argument_list|,
literal|"Maximum Address Fixed"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MAT"
argument_list|,
literal|"Multiple APIC Table Entry"
argument_list|,
literal|"Returns a list of MADT APIC structure entries"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MAX"
argument_list|,
literal|"Maximum Base Address"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MBM"
argument_list|,
literal|"Memory Bandwidth Monitoring Data"
argument_list|,
literal|"Returns bandwidth monitoring data for a memory device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MEM"
argument_list|,
literal|"Memory Attributes"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MIF"
argument_list|,
literal|"Minimum Address Fixed"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MIN"
argument_list|,
literal|"Minimum Base Address"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MLS"
argument_list|,
literal|"Multiple Language String"
argument_list|,
literal|"Returns a device description in multiple languages"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MOD"
argument_list|,
literal|"Mode"
argument_list|,
literal|"Interrupt mode, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MSG"
argument_list|,
literal|"Message"
argument_list|,
literal|"Sets the system message waiting status indicator"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MSM"
argument_list|,
literal|"Memory Set Monitoring"
argument_list|,
literal|"Sets bandwidth monitoring parameters for a memory device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MTL"
argument_list|,
literal|"Minimum Throttle Limit"
argument_list|,
literal|"Returns the minimum throttle limit for a thermal zone"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_MTP"
argument_list|,
literal|"Memory Type"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_NTT"
argument_list|,
literal|"Notification Temperature Threshold"
argument_list|,
literal|"Returns a threshold for device temperature change that requires platform notification"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_OFF"
argument_list|,
literal|"Power Off"
argument_list|,
literal|"Sets a power resource to the off state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ON_"
argument_list|,
literal|"Power On"
argument_list|,
literal|"Sets a power resource to the on state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_OS_"
argument_list|,
literal|"Operating System"
argument_list|,
literal|"Returns a string that identifies the operating system"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_OSC"
argument_list|,
literal|"Operating System Capabilities"
argument_list|,
literal|"Inform AML of host features and capabilities"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_OSI"
argument_list|,
literal|"Operating System Interfaces"
argument_list|,
literal|"Returns supported interfaces, behaviors, and features"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_OST"
argument_list|,
literal|"OSPM Status Indication"
argument_list|,
literal|"Inform AML of event processing status"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PAI"
argument_list|,
literal|"Power Averaging Interval"
argument_list|,
literal|"Sets the averaging interval for a power meter"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PAR"
argument_list|,
literal|"Parity"
argument_list|,
literal|"Parity bits, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PCL"
argument_list|,
literal|"Power Consumer List"
argument_list|,
literal|"Returns a list of devices powered by a power source"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PCT"
argument_list|,
literal|"Performance Control"
argument_list|,
literal|"Returns processor performance control and status registers"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PDC"
argument_list|,
literal|"Processor Driver Capabilities"
argument_list|,
literal|"Inform AML of processor driver capabilities"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PDL"
argument_list|,
literal|"P-state Depth Limit"
argument_list|,
literal|"Returns the lowest available performance P-state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PHA"
argument_list|,
literal|"Clock Phase"
argument_list|,
literal|"Clock phase, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PIC"
argument_list|,
literal|"Interrupt Model"
argument_list|,
literal|"Inform AML of the interrupt model in use"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PIF"
argument_list|,
literal|"Power Source Information"
argument_list|,
literal|"Returns a Power Source information block"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PIN"
argument_list|,
literal|"Pin List"
argument_list|,
literal|"Pin list, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PLD"
argument_list|,
literal|"Physical Location of Device"
argument_list|,
literal|"Returns a device's physical location information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PMC"
argument_list|,
literal|"Power Meter Capabilities"
argument_list|,
literal|"Returns a list of Power Meter capabilities info"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PMD"
argument_list|,
literal|"Power Metered Devices"
argument_list|,
literal|"Returns a list of devices that are measured by the power meter device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PMM"
argument_list|,
literal|"Power Meter Measurement"
argument_list|,
literal|"Returns the current value of the Power Meter"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_POL"
argument_list|,
literal|"Polarity"
argument_list|,
literal|"Interrupt polarity, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PPC"
argument_list|,
literal|"Performance Present Capabilities"
argument_list|,
literal|"Returns a list of the performance states currently supported by the platform"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PPE"
argument_list|,
literal|"Polling for Platform Error"
argument_list|,
literal|"Returns the polling interval to retrieve Corrected Platform Error information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PPI"
argument_list|,
literal|"Pin Configuration"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PR"
argument_list|,
literal|"Processor"
argument_list|,
literal|"Predefined scope for processor objects"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PR0"
argument_list|,
literal|"Power Resources for D0"
argument_list|,
literal|"Returns a list of dependent power resources to enter state D0 (fully on)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PR1"
argument_list|,
literal|"Power Resources for D1"
argument_list|,
literal|"Returns a list of dependent power resources to enter state D1"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PR2"
argument_list|,
literal|"Power Resources for D2"
argument_list|,
literal|"Returns a list of dependent power resources to enter state D2"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PR3"
argument_list|,
literal|"Power Resources for D3hot"
argument_list|,
literal|"Returns a list of dependent power resources to enter state D3hot"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRE"
argument_list|,
literal|"Power Resources for Enumeration"
argument_list|,
literal|"Returns a list of dependent power resources to enumerate devices on a bus"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRL"
argument_list|,
literal|"Power Source Redundancy List"
argument_list|,
literal|"Returns a list of power source devices in the same redundancy grouping"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRR"
argument_list|,
literal|"Power Resource for Reset"
argument_list|,
literal|"Execute a reset on a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRS"
argument_list|,
literal|"Possible Resource Settings"
argument_list|,
literal|"Returns a list of a device's possible resource settings"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRT"
argument_list|,
literal|"PCI Routing Table"
argument_list|,
literal|"Returns a list of PCI interrupt mappings"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PRW"
argument_list|,
literal|"Power Resources for Wake"
argument_list|,
literal|"Returns a list of dependent power resources for waking"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PS0"
argument_list|,
literal|"Power State 0"
argument_list|,
literal|"Sets a device's power state to D0 (device fully on)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PS1"
argument_list|,
literal|"Power State 1"
argument_list|,
literal|"Sets a device's power state to D1"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PS2"
argument_list|,
literal|"Power State 2"
argument_list|,
literal|"Sets a device's power state to D2"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PS3"
argument_list|,
literal|"Power State 3"
argument_list|,
literal|"Sets a device's power state to D3 (device off)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSC"
argument_list|,
literal|"Power State Current"
argument_list|,
literal|"Returns a device's current power state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSD"
argument_list|,
literal|"Power State Dependencies"
argument_list|,
literal|"Returns processor P-State dependencies"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSE"
argument_list|,
literal|"Power State for Enumeration"
argument_list|,
literal|"Put a bus into enumeration power mode"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSL"
argument_list|,
literal|"Passive List"
argument_list|,
literal|"Returns a list of passive cooling device objects"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSR"
argument_list|,
literal|"Power Source"
argument_list|,
literal|"Returns the power source device currently in use"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSS"
argument_list|,
literal|"Performance Supported States"
argument_list|,
literal|"Returns a list of supported processor performance states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSV"
argument_list|,
literal|"Passive Temperature"
argument_list|,
literal|"Returns the passive trip point temperature"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PSW"
argument_list|,
literal|"Power State Wake"
argument_list|,
literal|"Sets a device's wake function"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PTC"
argument_list|,
literal|"Processor Throttling Control"
argument_list|,
literal|"Returns throttling control and status registers"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PTP"
argument_list|,
literal|"Power Trip Points"
argument_list|,
literal|"Sets trip points for the Power Meter device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PTS"
argument_list|,
literal|"Prepare To Sleep"
argument_list|,
literal|"Inform the platform of an impending sleep transition"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PUR"
argument_list|,
literal|"Processor Utilization Request"
argument_list|,
literal|"Returns the number of processors that the platform would like to idle"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_PXM"
argument_list|,
literal|"Device Proximity"
argument_list|,
literal|"Returns a device's proximity domain identifier"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_Qxx"
argument_list|,
literal|"EC Query"
argument_list|,
literal|"Embedded Controller query and SMBus Alarm control method"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RBO"
argument_list|,
literal|"Register Bit Offset"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RBW"
argument_list|,
literal|"Register Bit Width"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RDI"
argument_list|,
literal|"Resource Dependencies for Idle"
argument_list|,
literal|"Returns a list of dependencies for idle states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_REG"
argument_list|,
literal|"Region Availability"
argument_list|,
literal|"Inform AML code of an operation region availability change"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_REV"
argument_list|,
literal|"Supported Integer Width"
argument_list|,
literal|"Returns the supported integer width (<= 1: 32 bits only,>=2: both 32 and 64 bits"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RMV"
argument_list|,
literal|"Removal Status"
argument_list|,
literal|"Returns a device's removal ability status (docking)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RNG"
argument_list|,
literal|"Range"
argument_list|,
literal|"Memory range type, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RST"
argument_list|,
literal|"Device Reset"
argument_list|,
literal|"Executes a reset on a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_ROM"
argument_list|,
literal|"Read-Only Memory"
argument_list|,
literal|"Returns a copy of the ROM data for a display device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RT_"
argument_list|,
literal|"Resource Type"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RTV"
argument_list|,
literal|"Relative Temperature Values"
argument_list|,
literal|"Returns temperature value information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RW_"
argument_list|,
literal|"Read-Write Status"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_RXL"
argument_list|,
literal|"Receive Buffer Size"
argument_list|,
literal|"Serial channel buffer, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S0_"
argument_list|,
literal|"S0 System State"
argument_list|,
literal|"Returns values to enter the system into the S0 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S1_"
argument_list|,
literal|"S1 System State"
argument_list|,
literal|"Returns values to enter the system into the S1 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S2_"
argument_list|,
literal|"S2 System State"
argument_list|,
literal|"Returns values to enter the system into the S2 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S3_"
argument_list|,
literal|"S3 System State"
argument_list|,
literal|"Returns values to enter the system into the S3 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S4_"
argument_list|,
literal|"S4 System State"
argument_list|,
literal|"Returns values to enter the system into the S4 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S5_"
argument_list|,
literal|"S5 System State"
argument_list|,
literal|"Returns values to enter the system into the S5 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S1D"
argument_list|,
literal|"S1 Device State"
argument_list|,
literal|"Returns the highest D-state supported by a device when in the S1 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S2D"
argument_list|,
literal|"S2 Device State"
argument_list|,
literal|"Returns the highest D-state supported by a device when in the S2 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S3D"
argument_list|,
literal|"S3 Device State"
argument_list|,
literal|"Returns the highest D-state supported by a device when in the S3 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S4D"
argument_list|,
literal|"S4 Device State"
argument_list|,
literal|"Returns the highest D-state supported by a device when in the S4 state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S0W"
argument_list|,
literal|"S0 Device Wake State"
argument_list|,
literal|"Returns the lowest D-state that the device can wake itself from S0"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S1W"
argument_list|,
literal|"S1 Device Wake State"
argument_list|,
literal|"Returns the lowest D-state for this device that can wake the system from S1"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S2W"
argument_list|,
literal|"S2 Device Wake State"
argument_list|,
literal|"Returns the lowest D-state for this device that can wake the system from S2"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S3W"
argument_list|,
literal|"S3 Device Wake State"
argument_list|,
literal|"Returns the lowest D-state for this device that can wake the system from S3"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_S4W"
argument_list|,
literal|"S4 Device Wake State"
argument_list|,
literal|"Returns the lowest D-state for this device that can wake the system from S4"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SB_"
argument_list|,
literal|"System Bus"
argument_list|,
literal|"Predefined scope for device and bus objects"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SBS"
argument_list|,
literal|"Smart Battery Subsystem"
argument_list|,
literal|"Returns the subsystem configuration"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SCP"
argument_list|,
literal|"Set Cooling Policy"
argument_list|,
literal|"Sets the cooling policy (active or passive)"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SDD"
argument_list|,
literal|"Set Device Data"
argument_list|,
literal|"Sets data for a SATA device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SEG"
argument_list|,
literal|"PCI Segment"
argument_list|,
literal|"Returns a device's PCI Segment Group number"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SHL"
argument_list|,
literal|"Set Hardware Limit"
argument_list|,
literal|"Sets the hardware limit enforced by the Power Meter"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SHR"
argument_list|,
literal|"Sharable"
argument_list|,
literal|"Interrupt share status, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SI_"
argument_list|,
literal|"System Indicators"
argument_list|,
literal|"Predefined scope"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SIZ"
argument_list|,
literal|"Size"
argument_list|,
literal|"DMA transfer size, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SLI"
argument_list|,
literal|"System Locality Information"
argument_list|,
literal|"Returns a list of NUMA system localities"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SLV"
argument_list|,
literal|"Slave Mode"
argument_list|,
literal|"Mode setting, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SPD"
argument_list|,
literal|"Set Post Device"
argument_list|,
literal|"Sets which video device will be posted at boot"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SPE"
argument_list|,
literal|"Speed"
argument_list|,
literal|"Connection speed, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SRS"
argument_list|,
literal|"Set Resource Settings"
argument_list|,
literal|"Sets a device's resource allocation"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SRT"
argument_list|,
literal|"Set Real Time"
argument_list|,
literal|"Sets the current time for a time/alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SRV"
argument_list|,
literal|"IPMI Spec Revision"
argument_list|,
literal|"See the Intelligent Platform Management Interface Specification"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SST"
argument_list|,
literal|"System Status"
argument_list|,
literal|"Sets the system status indicator"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STA"
argument_list|,
literal|"Status"
argument_list|,
literal|"Returns the current status of a Device or Power Resource"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STB"
argument_list|,
literal|"Stop Bits"
argument_list|,
literal|"Serial channel stop bits, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STM"
argument_list|,
literal|"Set Timing Mode"
argument_list|,
literal|"Sets an IDE controller transfer timings"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STP"
argument_list|,
literal|"Set Expired Timer Wake Policy"
argument_list|,
literal|"Sets expired timer policies of the wake alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STR"
argument_list|,
literal|"Description String"
argument_list|,
literal|"Returns a device's description string"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_STV"
argument_list|,
literal|"Set Timer Value"
argument_list|,
literal|"Set timer values of the wake alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SUB"
argument_list|,
literal|"Subsystem ID"
argument_list|,
literal|"Returns the subsystem ID for a device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SUN"
argument_list|,
literal|"Slot User Number"
argument_list|,
literal|"Returns the slot unique ID number"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_SWS"
argument_list|,
literal|"System Wake Source"
argument_list|,
literal|"Returns the source event that caused the system to wake"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_T_x"
argument_list|,
literal|"Emitted by ASL Compiler"
argument_list|,
literal|"Reserved for use by ASL compilers"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TC1"
argument_list|,
literal|"Thermal Constant 1"
argument_list|,
literal|"Returns TC1 for the passive cooling formula"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TC2"
argument_list|,
literal|"Thermal Constant 2"
argument_list|,
literal|"Returns TC2 for the passive cooling formula"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TDL"
argument_list|,
literal|"T-State Depth Limit"
argument_list|,
literal|"Returns the _TSS entry number of the lowest power throttling state"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TFP"
argument_list|,
literal|"Thermal Fast Sampling Period"
argument_list|,
literal|"Returns the sampling period for passive cooling"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TIP"
argument_list|,
literal|"Expired Timer Wake Policy"
argument_list|,
literal|"Returns timer policies of the wake alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TIV"
argument_list|,
literal|"Timer Values"
argument_list|,
literal|"Returns remaining time of the wake alarm device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TMP"
argument_list|,
literal|"Temperature"
argument_list|,
literal|"Returns a thermal zone's current temperature"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TPC"
argument_list|,
literal|"Throttling Present Capabilities"
argument_list|,
literal|"Returns the current number of supported throttling states"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TPT"
argument_list|,
literal|"Trip Point Temperature"
argument_list|,
literal|"Inform AML that a device's embedded temperature sensor has crossed a temperature trip point"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TRA"
argument_list|,
literal|"Translation"
argument_list|,
literal|"Address translation offset, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TRS"
argument_list|,
literal|"Translation Sparse"
argument_list|,
literal|"Sparse/dense flag, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TRT"
argument_list|,
literal|"Thermal Relationship Table"
argument_list|,
literal|"Returns thermal relationships between platform devices"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TSD"
argument_list|,
literal|"Throttling State Dependencies"
argument_list|,
literal|"Returns a list of T-state dependencies"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TSF"
argument_list|,
literal|"Type-Specific Flags"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TSN"
argument_list|,
literal|"Thermal Sensor Device"
argument_list|,
literal|"Returns a reference to a thermal sensor"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TSP"
argument_list|,
literal|"Thermal Sampling Period"
argument_list|,
literal|"Returns the thermal sampling period for passive cooling"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TSS"
argument_list|,
literal|"Throttling Supported States"
argument_list|,
literal|"Returns supported throttling state information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TST"
argument_list|,
literal|"Temperature Sensor Threshold"
argument_list|,
literal|"Returns the minimum separation for a device's temperature trip points"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TTP"
argument_list|,
literal|"Translation Type"
argument_list|,
literal|"Translation/static flag, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TTS"
argument_list|,
literal|"Transition To State"
argument_list|,
literal|"Inform AML of an S-state transition"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TXL"
argument_list|,
literal|"Transmit Buffer Size"
argument_list|,
literal|"Serial Channel buffer, Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TYP"
argument_list|,
literal|"Type"
argument_list|,
literal|"DMA channel type (speed), Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TZ_"
argument_list|,
literal|"Thermal Zone"
argument_list|,
literal|"Predefined scope: ACPI 1.0"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TZD"
argument_list|,
literal|"Thermal Zone Devices"
argument_list|,
literal|"Returns a list of device names associated with a Thermal Zone"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TZM"
argument_list|,
literal|"Thermal Zone Member"
argument_list|,
literal|"Returns a reference to the thermal zone of which a device is a member"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_TZP"
argument_list|,
literal|"Thermal Zone Polling"
argument_list|,
literal|"Returns a Thermal zone's polling frequency"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_UID"
argument_list|,
literal|"Unique ID"
argument_list|,
literal|"Return a device's unique persistent ID"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_UPC"
argument_list|,
literal|"USB Port Capabilities"
argument_list|,
literal|"Returns a list of USB port capabilities"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_UPD"
argument_list|,
literal|"User Presence Detect"
argument_list|,
literal|"Returns user detection information"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_UPP"
argument_list|,
literal|"User Presence Polling"
argument_list|,
literal|"Returns the recommended user presence polling interval"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_VAL"
argument_list|,
literal|"Pin Configuration Value"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_VEN"
argument_list|,
literal|"Vendor Data"
argument_list|,
literal|"Resource Descriptor field"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_VPO"
argument_list|,
literal|"Video Post Options"
argument_list|,
literal|"Returns the implemented video post options"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_Wxx"
argument_list|,
literal|"Wake Event"
argument_list|,
literal|"Method executed as a result of a wake event"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_WAK"
argument_list|,
literal|"Wake"
argument_list|,
literal|"Inform AML that the system has just awakened"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_WPC"
argument_list|,
literal|"Wireless Power Calibration"
argument_list|,
literal|"Calibrate power and notify wireless device"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
literal|"_WPP"
argument_list|,
literal|"Wireless Power Polling"
argument_list|,
literal|"Get recommended polling interval"
argument_list|)
block|,
name|AH_PREDEF
argument_list|(
argument|NULL
argument_list|,
argument|NULL
argument_list|,
argument|NULL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiAhMatchPredefinedName  *  * PARAMETERS:  Nameseg                 - Predefined name string  *  * RETURN:      ID info struct. NULL if Nameseg not found  *  * DESCRIPTION: Lookup a predefined name.  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|AH_PREDEFINED_NAME
modifier|*
name|AcpiAhMatchPredefinedName
parameter_list|(
name|char
modifier|*
name|Nameseg
parameter_list|)
block|{
specifier|const
name|AH_PREDEFINED_NAME
modifier|*
name|Info
decl_stmt|;
comment|/* Nameseg must start with an underscore */
if|if
condition|(
operator|*
name|Nameseg
operator|!=
literal|'_'
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* Search for a match in the predefined name table */
for|for
control|(
name|Info
operator|=
name|AslPredefinedInfo
init|;
name|Info
operator|->
name|Name
condition|;
name|Info
operator|++
control|)
block|{
if|if
condition|(
name|ACPI_COMPARE_NAME
argument_list|(
name|Nameseg
argument_list|,
name|Info
operator|->
name|Name
argument_list|)
condition|)
block|{
return|return
operator|(
name|Info
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

