begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahpredef - Table of all known ACPI predefined names  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpihelp.h"
end_include

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
block|{
literal|"_ACx"
block|,
literal|"Active Cooling"
block|,
literal|"Returns the active cooling policy threshold values"
block|}
block|,
block|{
literal|"_ADR"
block|,
literal|"Address"
block|,
literal|"Returns the address of a device on its parent bus"
block|}
block|,
block|{
literal|"_ALC"
block|,
literal|"Ambient Light Chromaticity"
block|,
literal|"Returns the ambient light color chromaticity"
block|}
block|,
block|{
literal|"_ALI"
block|,
literal|"Ambient Light Illuminance"
block|,
literal|"Returns the ambient light brightness"
block|}
block|,
block|{
literal|"_ALN"
block|,
literal|"Alignment"
block|,
literal|"Base alignment, Resource Descriptor field"
block|}
block|,
block|{
literal|"_ALP"
block|,
literal|"Ambient Light Polling"
block|,
literal|"Returns the ambient light sensor polling frequency"
block|}
block|,
block|{
literal|"_ALR"
block|,
literal|"Ambient Light Response"
block|,
literal|"Returns the ambient light brightness to display brightness mappings"
block|}
block|,
block|{
literal|"_ALT"
block|,
literal|"Ambient Light Temperature"
block|,
literal|"Returns the ambient light color temperature"
block|}
block|,
block|{
literal|"_ALx"
block|,
literal|"Active List"
block|,
literal|"Returns a list of active cooling device objects"
block|}
block|,
block|{
literal|"_ART"
block|,
literal|"Active cooling Relationship Table"
block|,
literal|"Returns thermal relationship information between platform devices and fan devices"
block|}
block|,
block|{
literal|"_ASI"
block|,
literal|"Address Space Id"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_ASZ"
block|,
literal|"Access Size"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_ATT"
block|,
literal|"Type-Specific Attribute"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_BAS"
block|,
literal|"Base Address"
block|,
literal|"Range base address, Resource Descriptor field"
block|}
block|,
block|{
literal|"_BBN"
block|,
literal|"Bios Bus Number"
block|,
literal|"Returns the PCI bus number returned by the BIOS"
block|}
block|,
block|{
literal|"_BCL"
block|,
literal|"Brightness Control Levels"
block|,
literal|"Returns a list of supported brightness control levels"
block|}
block|,
block|{
literal|"_BCM"
block|,
literal|"Brightness Control Method"
block|,
literal|"Sets the brightness level of the display device"
block|}
block|,
block|{
literal|"_BCT"
block|,
literal|"Battery Charge Time"
block|,
literal|"Returns time remaining to complete charging battery"
block|}
block|,
block|{
literal|"_BDN"
block|,
literal|"Bios Dock Name"
block|,
literal|"Returns the Dock ID returned by the BIOS"
block|}
block|,
block|{
literal|"_BFS"
block|,
literal|"Back From Sleep"
block|,
literal|"Inform AML of a wake event"
block|}
block|,
block|{
literal|"_BIF"
block|,
literal|"Battery Information"
block|,
literal|"Returns a Control Method Battery information block"
block|}
block|,
block|{
literal|"_BIX"
block|,
literal|"Battery Information Extended"
block|,
literal|"Returns a Control Method Battery extended information block"
block|}
block|,
block|{
literal|"_BLT"
block|,
literal|"Battery Level Threshold"
block|,
literal|"Set battery level threshold preferences"
block|}
block|,
block|{
literal|"_BM_"
block|,
literal|"Bus Master"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_BMA"
block|,
literal|"Battery Measurement Averaging Interval"
block|,
literal|"Sets battery measurement averaging interval"
block|}
block|,
block|{
literal|"_BMC"
block|,
literal|"Battery Maintenance Control"
block|,
literal|"Sets battery maintenance and control features"
block|}
block|,
block|{
literal|"_BMD"
block|,
literal|"Battery Maintenance Data"
block|,
literal|"Returns battery maintenance, control, and state data"
block|}
block|,
block|{
literal|"_BMS"
block|,
literal|"Battery Measurement Sampling Time"
block|,
literal|"Sets the battery measurement sampling time"
block|}
block|,
block|{
literal|"_BQC"
block|,
literal|"Brightness Query Current"
block|,
literal|"Returns the current display brightness level"
block|}
block|,
block|{
literal|"_BST"
block|,
literal|"Battery Status"
block|,
literal|"Returns a Control Method Battery status block"
block|}
block|,
block|{
literal|"_BTM"
block|,
literal|"Battery Time"
block|,
literal|"Returns the battery runtime"
block|}
block|,
block|{
literal|"_BTP"
block|,
literal|"Battery Trip Point"
block|,
literal|"Sets a Control Method Battery trip point"
block|}
block|,
block|{
literal|"_CBA"
block|,
literal|"Configuration Base Address"
block|,
literal|"Sets the CBA for a PCI Express host bridge"
block|}
block|,
block|{
literal|"_CDM"
block|,
literal|"Clock Domain"
block|,
literal|"Returns a logical processor's clock domain identifier"
block|}
block|,
block|{
literal|"_CID"
block|,
literal|"Compatible ID"
block|,
literal|"Returns a device's Plug and Play Compatible ID list"
block|}
block|,
block|{
literal|"_CRS"
block|,
literal|"Current Resource Settings"
block|,
literal|"Returns the current resource settings for a device"
block|}
block|,
block|{
literal|"_CRT"
block|,
literal|"Critical Temperature"
block|,
literal|"Returns the shutdown critical temperature"
block|}
block|,
block|{
literal|"_CSD"
block|,
literal|"C State Dependencies"
block|,
literal|"Returns a list of C-state dependencies"
block|}
block|,
block|{
literal|"_CST"
block|,
literal|"C States"
block|,
literal|"Returns a list of supported C-states"
block|}
block|,
block|{
literal|"_DCK"
block|,
literal|"Dock"
block|,
literal|"Sets docking isolation. Presence indicates device is a docking station"
block|}
block|,
block|{
literal|"_DCS"
block|,
literal|"Display Current Status"
block|,
literal|"Returns status of the display output device"
block|}
block|,
block|{
literal|"_DDC"
block|,
literal|"Display Data Current"
block|,
literal|"Returns the EDID for the display output device"
block|}
block|,
block|{
literal|"_DDN"
block|,
literal|"Dos Device Name"
block|,
literal|"Returns a device logical name"
block|}
block|,
block|{
literal|"_DEC"
block|,
literal|"Decode"
block|,
literal|"Device decoding type, Resource Descriptor field"
block|}
block|,
block|{
literal|"_DGS"
block|,
literal|"Display Graphics State"
block|,
literal|"Return the current state of the output device"
block|}
block|,
block|{
literal|"_DIS"
block|,
literal|"Disable"
block|,
literal|"Disables a device"
block|}
block|,
block|{
literal|"_DMA"
block|,
literal|"Direct Memory Access"
block|,
literal|"Returns a device's current resources for DMA transactions"
block|}
block|,
block|{
literal|"_DOD"
block|,
literal|"Display Output Devices"
block|,
literal|"Enumerate all devices attached to the display adapter"
block|}
block|,
block|{
literal|"_DOS"
block|,
literal|"Disable Output Switching"
block|,
literal|"Sets the display output switching mode"
block|}
block|,
block|{
literal|"_DSM"
block|,
literal|"Device Specific Method"
block|,
literal|"Executes device-specific functions"
block|}
block|,
block|{
literal|"_DSS"
block|,
literal|"Device Set State"
block|,
literal|"Sets the display device state"
block|}
block|,
block|{
literal|"_DSW"
block|,
literal|"Device Sleep Wake"
block|,
literal|"Sets the sleep and wake transition states for a device"
block|}
block|,
block|{
literal|"_DTI"
block|,
literal|"Device Temperature Indication"
block|,
literal|"Conveys native device temperature to the platform"
block|}
block|,
block|{
literal|"_Exx"
block|,
literal|"Edge GPE"
block|,
literal|"Method executed as a result of a general-purpose event"
block|}
block|,
block|{
literal|"_EC_"
block|,
literal|"Embedded Controller"
block|,
literal|"returns EC offset and query information"
block|}
block|,
block|{
literal|"_EDL"
block|,
literal|"Eject Device List"
block|,
literal|"Returns a list of devices that are dependent on a device (docking)"
block|}
block|,
block|{
literal|"_EJD"
block|,
literal|"Ejection Dependent Device"
block|,
literal|"Returns the name of dependent (parent) device (docking)"
block|}
block|,
block|{
literal|"_EJx"
block|,
literal|"Eject"
block|,
literal|"Begin or cancel a device ejection request (docking)"
block|}
block|,
block|{
literal|"_FDE"
block|,
literal|"Floppy Disk Enumerate"
block|,
literal|"Returns floppy disk configuration information"
block|}
block|,
block|{
literal|"_FDI"
block|,
literal|"Floppy Drive Information"
block|,
literal|"Returns a floppy drive information block"
block|}
block|,
block|{
literal|"_FDM"
block|,
literal|"Floppy Drive Mode"
block|,
literal|"Sets a floppy drive speed"
block|}
block|,
block|{
literal|"_FIF"
block|,
literal|"Fan Information"
block|,
literal|"Returns fan device information"
block|}
block|,
block|{
literal|"_FIX"
block|,
literal|"Fixed Register Resource Provider"
block|,
literal|"Returns a list of devices that implement FADT register blocks"
block|}
block|,
block|{
literal|"_FPS"
block|,
literal|"Fan Performance States"
block|,
literal|"Returns a list of supported fan performance states"
block|}
block|,
block|{
literal|"_FSL"
block|,
literal|"Fan Set Level"
block|,
literal|"Control method that sets the fan device's speed level (performance state)"
block|}
block|,
block|{
literal|"_FST"
block|,
literal|"Fan Status"
block|,
literal|"Returns current status information for a fan device"
block|}
block|,
block|{
literal|"_GAI"
block|,
literal|"Get Averaging Interval"
block|,
literal|"Returns the power meter averaging interval"
block|}
block|,
block|{
literal|"_GHL"
block|,
literal|"Get Hardware Limit"
block|,
literal|"Returns the hardware limit enforced by the power meter"
block|}
block|,
block|{
literal|"_GL_"
block|,
literal|"Global Lock"
block|,
literal|"OS-defined Global Lock mutex object"
block|}
block|,
block|{
literal|"_GLK"
block|,
literal|"Global Lock"
block|,
literal|"Returns a device's Global Lock requirement for device access"
block|}
block|,
block|{
literal|"_GPD"
block|,
literal|"Get Post Data"
block|,
literal|"Returns the value of the VGA device that will be posted at boot"
block|}
block|,
block|{
literal|"_GPE"
block|,
literal|"General Purpose Events"
block|,
literal|"(1) predefined Scope (\\_GPE.)"
block|}
block|,
block|{
literal|"_GRA"
block|,
literal|"Granularity"
block|,
literal|"Address space granularity, Resource Descriptor field"
block|}
block|,
block|{
literal|"_GSB"
block|,
literal|"Global System Interrupt Base"
block|,
literal|"Returns the GSB for a I/O APIC device"
block|}
block|,
block|{
literal|"_GTF"
block|,
literal|"Get Task File"
block|,
literal|"Returns a list of ATA commands to restore a drive to default state"
block|}
block|,
block|{
literal|"_GTM"
block|,
literal|"Get Timing Mode"
block|,
literal|"Returns a list of IDE controller timing information"
block|}
block|,
block|{
literal|"_GTS"
block|,
literal|"Going To Sleep"
block|,
literal|"Inform AML of pending sleep"
block|}
block|,
block|{
literal|"_HE_"
block|,
literal|"High-Edge"
block|,
literal|"Interrupt triggering, Resource Descriptor field"
block|}
block|,
block|{
literal|"_HID"
block|,
literal|"Hardware ID"
block|,
literal|"Returns a device's Plug and Play Hardware ID"
block|}
block|,
block|{
literal|"_HOT"
block|,
literal|"Hot Temperature"
block|,
literal|"Returns the critical temperature for sleep (entry to S4)"
block|}
block|,
block|{
literal|"_HPP"
block|,
literal|"Hot Plug Parameters"
block|,
literal|"Returns a list of hot-plug information for a PCI device"
block|}
block|,
block|{
literal|"_HPX"
block|,
literal|"Hot Plug Parameter Extensions"
block|,
literal|"Returns a list of hot-plug information for a PCI device. Supersedes _HPP"
block|}
block|,
block|{
literal|"_IFT"
block|,
literal|"IPMI Interface Type"
block|,
literal|"See the Intelligent Platform Management Interface Specification"
block|}
block|,
block|{
literal|"_INI"
block|,
literal|"Initialize"
block|,
literal|"Performs device specific initialization"
block|}
block|,
block|{
literal|"_INT"
block|,
literal|"Interrupts"
block|,
literal|"Interrupt mask bits, Resource Descriptor field"
block|}
block|,
block|{
literal|"_IRC"
block|,
literal|"Inrush Current"
block|,
literal|"Presence indicates that a device has a significant inrush current draw"
block|}
block|,
block|{
literal|"_Lxx"
block|,
literal|"Level GPE"
block|,
literal|"Control method executed as a result of a general-purpose event"
block|}
block|,
block|{
literal|"_LCK"
block|,
literal|"Lock"
block|,
literal|"Locks or unlocks a device (docking)"
block|}
block|,
block|{
literal|"_LEN"
block|,
literal|"Length"
block|,
literal|"Range length, Resource Descriptor field"
block|}
block|,
block|{
literal|"_LID"
block|,
literal|"Lid"
block|,
literal|"Returns the open/closed status of the lid on a mobile system"
block|}
block|,
block|{
literal|"_LL_"
block|,
literal|"Low Level"
block|,
literal|"Interrupt polarity, Resource Descriptor field"
block|}
block|,
block|{
literal|"_MAF"
block|,
literal|"Maximum Address Fixed"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_MAT"
block|,
literal|"Multiple Apic Table Entry"
block|,
literal|"Returns a list of MADT APIC structure entries"
block|}
block|,
block|{
literal|"_MAX"
block|,
literal|"Maximum Base Address"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_MBM"
block|,
literal|"Memory Bandwidth Monitoring Data"
block|,
literal|"Returns bandwidth monitoring data for a memory device"
block|}
block|,
block|{
literal|"_MEM"
block|,
literal|"Memory Attributes"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_MIF"
block|,
literal|"Minimum Address Fixed"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_MIN"
block|,
literal|"Minimum Base Address"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_MLS"
block|,
literal|"Multiple Language String"
block|,
literal|"Returns a device description in multiple languages"
block|}
block|,
block|{
literal|"_MSG"
block|,
literal|"Message"
block|,
literal|"Sets the system message waiting status indicator"
block|}
block|,
block|{
literal|"_MSM"
block|,
literal|"Memory Set Monitoring"
block|,
literal|"Sets bandwidth monitoring parameters for a memory device"
block|}
block|,
block|{
literal|"_MTP"
block|,
literal|"Memory Type"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_NTT"
block|,
literal|"Notification Temperature Threshold"
block|,
literal|"Returns a threshold for device temperature change that requires platform notification"
block|}
block|,
block|{
literal|"_OFF"
block|,
literal|"Off"
block|,
literal|"Sets a power resource to the off state"
block|}
block|,
block|{
literal|"_ON_"
block|,
literal|"On"
block|,
literal|"Sets a power resource to the on state"
block|}
block|,
block|{
literal|"_OS_"
block|,
literal|"Operating System"
block|,
literal|"Returns a string that identifies the operating system"
block|}
block|,
block|{
literal|"_OSC"
block|,
literal|"Operating System Capabilities"
block|,
literal|"Inform AML of host features and capabilities"
block|}
block|,
block|{
literal|"_OSI"
block|,
literal|"Operating System Interfaces"
block|,
literal|"Returns supported interfaces, behaviors, and features"
block|}
block|,
block|{
literal|"_OST"
block|,
literal|"Ospm Status Indication"
block|,
literal|"Inform AML of event processing status"
block|}
block|,
block|{
literal|"_PAI"
block|,
literal|"Power Averaging Interval"
block|,
literal|"Sets the averaging interval for a power meter"
block|}
block|,
block|{
literal|"_PCL"
block|,
literal|"Power Consumer List"
block|,
literal|"Returns a list of devices powered by a power source"
block|}
block|,
block|{
literal|"_PCT"
block|,
literal|"Performance Control"
block|,
literal|"Returns processor performance control and status registers"
block|}
block|,
block|{
literal|"_PDC"
block|,
literal|"Processor Driver Capabilities"
block|,
literal|"Inform AML of processor driver capabilities"
block|}
block|,
block|{
literal|"_PDL"
block|,
literal|"P-state Depth Limit"
block|,
literal|"Returns the lowest available performance P-state"
block|}
block|,
block|{
literal|"_PIC"
block|,
literal|"PIC"
block|,
literal|"Inform AML of the interrupt model in use"
block|}
block|,
block|{
literal|"_PIF"
block|,
literal|"Power Source Information"
block|,
literal|"Returns a Power Source information block"
block|}
block|,
block|{
literal|"_PLD"
block|,
literal|"Physical Device Location"
block|,
literal|"Returns a device's physical location information"
block|}
block|,
block|{
literal|"_PMC"
block|,
literal|"Power Meter Capabilities"
block|,
literal|"Returns a list of Power Meter capabilities info"
block|}
block|,
block|{
literal|"_PMD"
block|,
literal|"Power Metered Devices"
block|,
literal|"Returns a list of devices that are measured by the power meter device"
block|}
block|,
block|{
literal|"_PMM"
block|,
literal|"Power Meter Measurement"
block|,
literal|"Returns the current value of the Power Meter"
block|}
block|,
block|{
literal|"_PPC"
block|,
literal|"Performance Present Capabilites"
block|,
literal|"Returns a list of the performance states currently supported by the platform"
block|}
block|,
block|{
literal|"_PPE"
block|,
literal|"Polling for Platform Error"
block|,
literal|"Returns the polling interval to retrieve Corrected Platform Error information"
block|}
block|,
block|{
literal|"_PR"
block|,
literal|"Processor"
block|,
literal|"Predefined scope for processor objects"
block|}
block|,
block|{
literal|"_PR0"
block|,
literal|"Power Resources for D0"
block|,
literal|"Returns a list of dependent power resources to enter state D0 (fully on)"
block|}
block|,
block|{
literal|"_PR1"
block|,
literal|"Power Resources for D1"
block|,
literal|"Returns a list of dependent power resources to enter state D1"
block|}
block|,
block|{
literal|"_PR2"
block|,
literal|"Power Resources for D2"
block|,
literal|"Returns a list of dependent power resources to enter state D2"
block|}
block|,
block|{
literal|"_PR3"
block|,
literal|"Power Resources for D3hot"
block|,
literal|"Returns a list of dependent power resources to enter state D3hot"
block|}
block|,
block|{
literal|"_PRL"
block|,
literal|"Power Source Redundancy List"
block|,
literal|"Returns a list of power source devices in the same redundancy grouping"
block|}
block|,
block|{
literal|"_PRS"
block|,
literal|"Possible Resource Settings"
block|,
literal|"Returns a list of a device's possible resource settings"
block|}
block|,
block|{
literal|"_PRT"
block|,
literal|"Pci Routing Table"
block|,
literal|"Returns a list of PCI interrupt mappings"
block|}
block|,
block|{
literal|"_PRW"
block|,
literal|"Power Resources for Wake"
block|,
literal|"Returns a list of dependent power resources for waking"
block|}
block|,
block|{
literal|"_PS0"
block|,
literal|"Power State 0"
block|,
literal|"Sets a device's power state to D0 (device fully on)"
block|}
block|,
block|{
literal|"_PS1"
block|,
literal|"Power State 1"
block|,
literal|"Sets a device's power state to D1"
block|}
block|,
block|{
literal|"_PS2"
block|,
literal|"Power State 2"
block|,
literal|"Sets a device's power state to D2"
block|}
block|,
block|{
literal|"_PS3"
block|,
literal|"Power State 3"
block|,
literal|"Sets a device's power state to D3 (device off)"
block|}
block|,
block|{
literal|"_PSC"
block|,
literal|"Power State Current"
block|,
literal|"Returns a device's current power state"
block|}
block|,
block|{
literal|"_PSD"
block|,
literal|"Processor State Dependencies"
block|,
literal|"Returns processor P-State dependencies"
block|}
block|,
block|{
literal|"_PSL"
block|,
literal|"Passive List"
block|,
literal|"Returns a list of passive cooling device objects"
block|}
block|,
block|{
literal|"_PSR"
block|,
literal|"Power Source"
block|,
literal|"Returns the power source device currently in use"
block|}
block|,
block|{
literal|"_PSS"
block|,
literal|"Performance Supported States"
block|,
literal|"Returns a list of supported processor performance states"
block|}
block|,
block|{
literal|"_PSV"
block|,
literal|"Passive"
block|,
literal|"Returns the passive trip point temperature"
block|}
block|,
block|{
literal|"_PSW"
block|,
literal|"Power State Wake"
block|,
literal|"Sets a device's wake function"
block|}
block|,
block|{
literal|"_PTC"
block|,
literal|"Processor Throttling Control"
block|,
literal|"Returns throttling control and status registers"
block|}
block|,
block|{
literal|"_PTP"
block|,
literal|"Power Trip Points"
block|,
literal|"Sets trip points for the Power Meter device"
block|}
block|,
block|{
literal|"_PTS"
block|,
literal|"Prepare To Sleep"
block|,
literal|"Inform the platform of an impending sleep transition"
block|}
block|,
block|{
literal|"_PUR"
block|,
literal|"Processor Utilization Request"
block|,
literal|"Returns the number of processors that the platform would like to idle"
block|}
block|,
block|{
literal|"_PXM"
block|,
literal|"Proximity"
block|,
literal|"Returns a device's proximity domain identifier"
block|}
block|,
block|{
literal|"_Qxx"
block|,
literal|"Query"
block|,
literal|"Embedded Controller query and SMBus Alarm control method"
block|}
block|,
block|{
literal|"_RBO"
block|,
literal|"Register Bit Offset"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_RBW"
block|,
literal|"Register Bit Width"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_REG"
block|,
literal|"Region"
block|,
literal|"Inform AML code of an operation region availability change"
block|}
block|,
block|{
literal|"_REV"
block|,
literal|"Revision"
block|,
literal|"Returns the revision of the ACPI specification that is implemented"
block|}
block|,
block|{
literal|"_RMV"
block|,
literal|"Remove"
block|,
literal|"Returns a device's removal ability status (docking)"
block|}
block|,
block|{
literal|"_RNG"
block|,
literal|"Range"
block|,
literal|"Memory range type, Resource Descriptor field"
block|}
block|,
block|{
literal|"_ROM"
block|,
literal|"Read-Only Memory"
block|,
literal|"Returns a copy of the ROM data for a display device"
block|}
block|,
block|{
literal|"_RT_"
block|,
literal|"Resource Type"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_RTV"
block|,
literal|"Relative Temperature Values"
block|,
literal|"Returns temperature value information"
block|}
block|,
block|{
literal|"_RW_"
block|,
literal|"Read-Write Status"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_S0_"
block|,
literal|"S0 System State"
block|,
literal|"Returns values to enter the system into the S0 state"
block|}
block|,
block|{
literal|"_S1_"
block|,
literal|"S1 System State"
block|,
literal|"Returns values to enter the system into the S1 state"
block|}
block|,
block|{
literal|"_S2_"
block|,
literal|"S2 System State"
block|,
literal|"Returns values to enter the system into the S2 state"
block|}
block|,
block|{
literal|"_S3_"
block|,
literal|"S3 System State"
block|,
literal|"Returns values to enter the system into the S3 state"
block|}
block|,
block|{
literal|"_S4_"
block|,
literal|"S4 System State"
block|,
literal|"Returns values to enter the system into the S4 state"
block|}
block|,
block|{
literal|"_S5_"
block|,
literal|"S5 System State"
block|,
literal|"Returns values to enter the system into the S5 state"
block|}
block|,
block|{
literal|"_S1D"
block|,
literal|"S1 Device State"
block|,
literal|"Returns the highest D-state supported by a device when in the S1 state"
block|}
block|,
block|{
literal|"_S2D"
block|,
literal|"S2 Device State"
block|,
literal|"Returns the highest D-state supported by a device when in the S2 state"
block|}
block|,
block|{
literal|"_S3D"
block|,
literal|"S3 Device State"
block|,
literal|"Returns the highest D-state supported by a device when in the S3 state"
block|}
block|,
block|{
literal|"_S4D"
block|,
literal|"S4 Device State"
block|,
literal|"Returns the highest D-state supported by a device when in the S4 state"
block|}
block|,
block|{
literal|"_S0W"
block|,
literal|"S0 Device Wake State"
block|,
literal|"Returns the lowest D-state that the device can wake itself from S0"
block|}
block|,
block|{
literal|"_S1W"
block|,
literal|"S1 Device Wake State"
block|,
literal|"Returns the lowest D-state for this device that can wake the system from S1"
block|}
block|,
block|{
literal|"_S2W"
block|,
literal|"S2 Device Wake State"
block|,
literal|"Returns the lowest D-state for this device that can wake the system from S2"
block|}
block|,
block|{
literal|"_S3W"
block|,
literal|"S3 Device Wake State"
block|,
literal|"Returns the lowest D-state for this device that can wake the system from S3"
block|}
block|,
block|{
literal|"_S4W"
block|,
literal|"S4 Device Wake State"
block|,
literal|"Returns the lowest D-state for this device that can wake the system from S4"
block|}
block|,
block|{
literal|"_SB_"
block|,
literal|"System Bus"
block|,
literal|"Scope for device and bus objects"
block|}
block|,
block|{
literal|"_SBS"
block|,
literal|"Smart Battery Subsystem"
block|,
literal|"Returns the subsystem configuration"
block|}
block|,
block|{
literal|"_SCP"
block|,
literal|"Set Cooling Policy"
block|,
literal|"Sets the cooling policy (active or passive)"
block|}
block|,
block|{
literal|"_SDD"
block|,
literal|"Set Device Data"
block|,
literal|"Sets data for a SATA device"
block|}
block|,
block|{
literal|"_SEG"
block|,
literal|"Segment"
block|,
literal|"Returns a device's PCI Segment Group number"
block|}
block|,
block|{
literal|"_SHL"
block|,
literal|"Set Hardware Limit"
block|,
literal|"Sets the hardware limit enforced by the Power Meter"
block|}
block|,
block|{
literal|"_SHR"
block|,
literal|"Sharable"
block|,
literal|"Interrupt share status, Resource Descriptor field"
block|}
block|,
block|{
literal|"_SI_"
block|,
literal|"System Indicators"
block|,
literal|"Predefined scope"
block|}
block|,
block|{
literal|"_SIZ"
block|,
literal|"Size"
block|,
literal|"DMA transfer size, Resource Descriptor field"
block|}
block|,
block|{
literal|"_SLI"
block|,
literal|"System Locality Information"
block|,
literal|"Returns a list of NUMA system localities"
block|}
block|,
block|{
literal|"_SPD"
block|,
literal|"Set Post Device"
block|,
literal|"Sets which video device will be posted at boot"
block|}
block|,
block|{
literal|"_SRS"
block|,
literal|"Set Resource Settings"
block|,
literal|"Sets a device's resource allocation"
block|}
block|,
block|{
literal|"_SRV"
block|,
literal|"IPMI Spec Revision"
block|,
literal|"See the Intelligent Platform Management Interface Specification"
block|}
block|,
block|{
literal|"_SST"
block|,
literal|"System Status"
block|,
literal|"Sets the system status indicator"
block|}
block|,
block|{
literal|"_STA"
block|,
literal|"Status"
block|,
literal|" (1) returns the current status of a device"
block|}
block|,
block|{
literal|"_STM"
block|,
literal|"Set Timing Mode"
block|,
literal|"Sets an IDE controller transfer timings"
block|}
block|,
block|{
literal|"_STP"
block|,
literal|"Set Expired Timer Wake Policy"
block|,
literal|"Sets expired timer policies of the wake alarm device"
block|}
block|,
block|{
literal|"_STR"
block|,
literal|"String"
block|,
literal|"Returns a device's description string"
block|}
block|,
block|{
literal|"_STV"
block|,
literal|"Set Timer Value"
block|,
literal|"Set timer values of the wake alarm device"
block|}
block|,
block|{
literal|"_SUN"
block|,
literal|"Slot User Number"
block|,
literal|"Returns the slot unique ID number"
block|}
block|,
block|{
literal|"_SWS"
block|,
literal|"System Wake Source"
block|,
literal|"Returns the source event that caused the system to wake"
block|}
block|,
block|{
literal|"_T_x"
block|,
literal|"Temporary"
block|,
literal|"Reserved for use by ASL compilers"
block|}
block|,
block|{
literal|"_TC1"
block|,
literal|"Thermal Constant 1"
block|,
literal|"Returns TC1 for the passive cooling formula"
block|}
block|,
block|{
literal|"_TC2"
block|,
literal|"Thermal Constant 2"
block|,
literal|"Returns TC2 for the passive cooling formula"
block|}
block|,
block|{
literal|"_TDL"
block|,
literal|"T-State Depth Limit"
block|,
literal|"Returns the _TSS entry number of the lowest power throttling state"
block|}
block|,
block|{
literal|"_TIP"
block|,
literal|"Expired Timer Wake Policy"
block|,
literal|"Returns timer policies of the wake alarm device"
block|}
block|,
block|{
literal|"_TIV"
block|,
literal|"Timer Values"
block|,
literal|"Returns remaining time of the wake alarm device"
block|}
block|,
block|{
literal|"_TMP"
block|,
literal|"Temperature"
block|,
literal|"Returns a thermal zone's current temperature"
block|}
block|,
block|{
literal|"_TPC"
block|,
literal|"Throttling Present Capabilities"
block|,
literal|"Returns the current number of supported throttling states"
block|}
block|,
block|{
literal|"_TPT"
block|,
literal|"Trip Point Temperature"
block|,
literal|"Inform AML that a device's embedded temperature sensor has crossed a temperature trip point"
block|}
block|,
block|{
literal|"_TRA"
block|,
literal|"Translation"
block|,
literal|"Address translation offset, Resource Descriptor field"
block|}
block|,
block|{
literal|"_TRS"
block|,
literal|"Translation Sparse"
block|,
literal|"Sparse/dense flag, Resource Descriptor field"
block|}
block|,
block|{
literal|"_TRT"
block|,
literal|"Thermal Relationship Table"
block|,
literal|"Returns thermal relationships between platform devices"
block|}
block|,
block|{
literal|"_TSD"
block|,
literal|"Throttling State Dependencies"
block|,
literal|"Returns a list of T-state dependencies"
block|}
block|,
block|{
literal|"_TSF"
block|,
literal|"Type-Specific Flags"
block|,
literal|"Resource Descriptor field"
block|}
block|,
block|{
literal|"_TSP"
block|,
literal|"Thermal Sampling Period"
block|,
literal|"Returns the thermal sampling period for passive cooling"
block|}
block|,
block|{
literal|"_TSS"
block|,
literal|"Throttling Supported States"
block|,
literal|"Returns supported throttling state information"
block|}
block|,
block|{
literal|"_TST"
block|,
literal|"Temperature Sensor Threshold"
block|,
literal|"Returns the minimum separation for a device's temperature trip points"
block|}
block|,
block|{
literal|"_TTP"
block|,
literal|"Translation Type"
block|,
literal|"Translation/static flag, Resource Descriptor field"
block|}
block|,
block|{
literal|"_TTS"
block|,
literal|"Transition To State"
block|,
literal|"Inform AML of an S-state transition"
block|}
block|,
block|{
literal|"_TYP"
block|,
literal|"Type"
block|,
literal|"DMA channel type (speed), Resource Descriptor field"
block|}
block|,
block|{
literal|"_TZ_"
block|,
literal|"Thermal Zone"
block|,
literal|"Predefined scope: ACPI 1.0"
block|}
block|,
block|{
literal|"_TZD"
block|,
literal|"Thermal Zone Devices"
block|,
literal|"Returns a list of device names associated with a Thermal Zone"
block|}
block|,
block|{
literal|"_TZM"
block|,
literal|"Thermal Zone Member"
block|,
literal|"Returns a reference to the thermal zone of which a device is a member"
block|}
block|,
block|{
literal|"_TZP"
block|,
literal|"Thermal Zone Polling"
block|,
literal|"Returns a Thermal zone's polling frequency"
block|}
block|,
block|{
literal|"_UID"
block|,
literal|"Unique ID"
block|,
literal|"Return a device's unique persistent ID"
block|}
block|,
block|{
literal|"_UPC"
block|,
literal|"USB Port Capabilities"
block|,
literal|"Returns a list of USB port capabilities"
block|}
block|,
block|{
literal|"_UPD"
block|,
literal|"User Presence Detect"
block|,
literal|"Returns user detection information"
block|}
block|,
block|{
literal|"_UPP"
block|,
literal|"User Presence Polling"
block|,
literal|"Returns the recommended user presence polling interval"
block|}
block|,
block|{
literal|"_VPO"
block|,
literal|"Video Post Options"
block|,
literal|"Returns the implemented video post options"
block|}
block|,
block|{
literal|"_WAK"
block|,
literal|"Wake"
block|,
literal|"Inform AML that the system has just awakened"
block|}
block|,
block|{
literal|"_Wxx"
block|,
literal|"Wake Event"
block|,
literal|"Method executed as a result of a wake event"
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

