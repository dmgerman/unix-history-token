begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: ahids - Table of ACPI/PNP _HID/_CID values  *  *****************************************************************************/
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

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"ahids"
argument_list|)
end_macro

begin_comment
comment|/*  * ACPI/PNP Device IDs with description strings  */
end_comment

begin_decl_stmt
specifier|const
name|AH_DEVICE_ID
name|AslDeviceIds
index|[]
init|=
block|{
block|{
literal|"10EC5640"
block|,
literal|"Realtek I2S Audio Codec"
block|}
block|,
block|{
literal|"80860F09"
block|,
literal|"Intel PWM Controller"
block|}
block|,
block|{
literal|"80860F0A"
block|,
literal|"Intel Atom UART Controller"
block|}
block|,
block|{
literal|"80860F0E"
block|,
literal|"Intel SPI Controller"
block|}
block|,
block|{
literal|"80860F14"
block|,
literal|"Intel Baytrail SDIO/MMC Host Controller"
block|}
block|,
block|{
literal|"80860F28"
block|,
literal|"Intel SST Audio DSP"
block|}
block|,
block|{
literal|"80860F41"
block|,
literal|"Intel Baytrail I2C Host Controller"
block|}
block|,
block|{
literal|"ACPI0001"
block|,
literal|"SMBus 1.0 Host Controller"
block|}
block|,
block|{
literal|"ACPI0002"
block|,
literal|"Smart Battery Subsystem"
block|}
block|,
block|{
literal|"ACPI0003"
block|,
literal|"Power Source Device"
block|}
block|,
block|{
literal|"ACPI0004"
block|,
literal|"Module Device"
block|}
block|,
block|{
literal|"ACPI0005"
block|,
literal|"SMBus 2.0 Host Controller"
block|}
block|,
block|{
literal|"ACPI0006"
block|,
literal|"GPE Block Device"
block|}
block|,
block|{
literal|"ACPI0007"
block|,
literal|"Processor Device"
block|}
block|,
block|{
literal|"ACPI0008"
block|,
literal|"Ambient Light Sensor Device"
block|}
block|,
block|{
literal|"ACPI0009"
block|,
literal|"I/O xAPIC Device"
block|}
block|,
block|{
literal|"ACPI000A"
block|,
literal|"I/O APIC Device"
block|}
block|,
block|{
literal|"ACPI000B"
block|,
literal|"I/O SAPIC Device"
block|}
block|,
block|{
literal|"ACPI000C"
block|,
literal|"Processor Aggregator Device"
block|}
block|,
block|{
literal|"ACPI000D"
block|,
literal|"Power Meter Device"
block|}
block|,
block|{
literal|"ACPI000E"
block|,
literal|"Time and Alarm Device"
block|}
block|,
block|{
literal|"ACPI000F"
block|,
literal|"User Presence Detection Device"
block|}
block|,
block|{
literal|"ADMA0F28"
block|,
literal|"Intel Audio DMA"
block|}
block|,
block|{
literal|"AMCR0F28"
block|,
literal|"Intel Audio Machine Driver"
block|}
block|,
block|{
literal|"ATK4001"
block|,
literal|"Asus Radio Control Button"
block|}
block|,
block|{
literal|"ATML1000"
block|,
literal|"Atmel Touchscreen Controller"
block|}
block|,
block|{
literal|"AUTH2750"
block|,
literal|"AuthenTec AES2750"
block|}
block|,
block|{
literal|"BCM2E39"
block|,
literal|"Broadcom BT Serial Bus Driver over UART Bus Enumerator"
block|}
block|,
block|{
literal|"BCM4752E"
block|,
literal|"Broadcom GPS Controller"
block|}
block|,
block|{
literal|"BMG0160"
block|,
literal|"Bosch Gyro Sensor"
block|}
block|,
block|{
literal|"CPLM3218"
block|,
literal|"Capella Micro CM3218x Ambient Light Sensor"
block|}
block|,
block|{
literal|"DELLABCE"
block|,
literal|"Dell Airplane Mode Switch Driver"
block|}
block|,
block|{
literal|"DLAC3002"
block|,
literal|"Qualcomm Atheros Bluetooth UART Transport"
block|}
block|,
block|{
literal|"FTTH5506"
block|,
literal|"FocalTech 5506 Touch Controller"
block|}
block|,
block|{
literal|"HAD0F28"
block|,
literal|"Intel HDMI Audio Driver"
block|}
block|,
block|{
literal|"INBC0000"
block|,
literal|"GPIO Expander"
block|}
block|,
block|{
literal|"INT0002"
block|,
literal|"Virtual GPIO Controller"
block|}
block|,
block|{
literal|"INT0800"
block|,
literal|"Intel 82802 Firmware Hub Device"
block|}
block|,
block|{
literal|"INT3394"
block|,
literal|"ACPI System Fan"
block|}
block|,
block|{
literal|"INT3396"
block|,
literal|"Standard Power Management Controller"
block|}
block|,
block|{
literal|"INT33A0"
block|,
literal|"Intel Smart Connect Technology Device"
block|}
block|,
block|{
literal|"INT33A1"
block|,
literal|"Intel Power Engine"
block|}
block|,
block|{
literal|"INT33BB"
block|,
literal|"Intel Baytrail SD Host Controller"
block|}
block|,
block|{
literal|"INT33BD"
block|,
literal|"Intel Baytrail Mailbox Device"
block|}
block|,
block|{
literal|"INT33BE"
block|,
literal|"Camera Sensor OV5693"
block|}
block|,
block|{
literal|"INT33C0"
block|,
literal|"Intel Serial I/O SPI Host Controller"
block|}
block|,
block|{
literal|"INT33C1"
block|,
literal|"Intel Serial I/O SPI Host Controller"
block|}
block|,
block|{
literal|"INT33C2"
block|,
literal|"Intel Serial I/O I2C Host Controller"
block|}
block|,
block|{
literal|"INT33C3"
block|,
literal|"Intel Serial I/O I2C Host Controller"
block|}
block|,
block|{
literal|"INT33C4"
block|,
literal|"Intel Serial I/O UART Host Controller"
block|}
block|,
block|{
literal|"INT33C5"
block|,
literal|"Intel Serial I/O UART Host Controller"
block|}
block|,
block|{
literal|"INT33C6"
block|,
literal|"Intel SD Host Controller"
block|}
block|,
block|{
literal|"INT33C7"
block|,
literal|"Intel Serial I/O GPIO Host Controller"
block|}
block|,
block|{
literal|"INT33C8"
block|,
literal|"Intel Smart Sound Technology Host Controller"
block|}
block|,
block|{
literal|"INT33C9"
block|,
literal|"Wolfson Microelectronics Audio WM5102"
block|}
block|,
block|{
literal|"INT33CA"
block|,
literal|"Intel SPB Peripheral"
block|}
block|,
block|{
literal|"INT33CB"
block|,
literal|"Intel Smart Sound Technology Audio Codec"
block|}
block|,
block|{
literal|"INT33D1"
block|,
literal|"Intel GPIO Buttons"
block|}
block|,
block|{
literal|"INT33D2"
block|,
literal|"Intel GPIO Buttons"
block|}
block|,
block|{
literal|"INT33D3"
block|,
literal|"Intel GPIO Buttons"
block|}
block|,
block|{
literal|"INT33D4"
block|,
literal|"Intel GPIO Buttons"
block|}
block|,
block|{
literal|"INT33D6"
block|,
literal|"Intel Virtual Buttons Device"
block|}
block|,
block|{
literal|"INT33F0"
block|,
literal|"Camera Sensor MT9M114"
block|}
block|,
block|{
literal|"INT33F4"
block|,
literal|"XPOWER PMIC Controller"
block|}
block|,
block|{
literal|"INT33F5"
block|,
literal|"TI PMIC Controller"
block|}
block|,
block|{
literal|"INT33FB"
block|,
literal|"MIPI-CSI Camera Sensor OV2722"
block|}
block|,
block|{
literal|"INT33FC"
block|,
literal|"Intel Baytrail GPIO Controller"
block|}
block|,
block|{
literal|"INT33FD"
block|,
literal|"Intel Baytrail Power Management IC"
block|}
block|,
block|{
literal|"INT33FE"
block|,
literal|"XPOWER Battery Device"
block|}
block|,
block|{
literal|"INT3400"
block|,
literal|"Intel Dynamic Power Performance Management"
block|}
block|,
block|{
literal|"INT3401"
block|,
literal|"Intel Extended Thermal Model CPU"
block|}
block|,
block|{
literal|"INT3403"
block|,
literal|"DPTF Temperature Sensor"
block|}
block|,
block|{
literal|"INT3406"
block|,
literal|"Intel Dynamic Platform& Thermal Framework Display Participant"
block|}
block|,
block|{
literal|"INT3407"
block|,
literal|"DPTF Platform Power Meter"
block|}
block|,
block|{
literal|"INT340E"
block|,
literal|"Motherboard Resources"
block|}
block|,
block|{
literal|"INT3420"
block|,
literal|"Intel Bluetooth RF Kill"
block|}
block|,
block|{
literal|"INT3F0D"
block|,
literal|"ACPI Motherboard Resources"
block|}
block|,
block|{
literal|"INTCF1A"
block|,
literal|"Sony IMX175 Camera Sensor"
block|}
block|,
block|{
literal|"INTCFD9"
block|,
literal|"Intel Baytrail SOC GPIO Controller"
block|}
block|,
block|{
literal|"INTL9C60"
block|,
literal|"Intel Baytrail SOC DMA Controller"
block|}
block|,
block|{
literal|"INVN6500"
block|,
literal|"InvenSense MPU-6500 Six Axis Gyroscope and Accelerometer"
block|}
block|,
block|{
literal|"LNXCPU"
block|,
literal|"Linux Logical CPU"
block|}
block|,
block|{
literal|"LNXPOWER"
block|,
literal|"ACPI Power Resource (power gating)"
block|}
block|,
block|{
literal|"LNXPWRBN"
block|,
literal|"System Power Button"
block|}
block|,
block|{
literal|"LNXSYBUS"
block|,
literal|"System Bus"
block|}
block|,
block|{
literal|"LNXSYSTM"
block|,
literal|"ACPI Root Node"
block|}
block|,
block|{
literal|"LNXTHERM"
block|,
literal|"ACPI Thermal Zone"
block|}
block|,
block|{
literal|"LNXVIDEO"
block|,
literal|"ACPI Video Controller"
block|}
block|,
block|{
literal|"MAX17047"
block|,
literal|"Fuel Gauge Controller"
block|}
block|,
block|{
literal|"MSFT0101"
block|,
literal|"TPM 2.0 Security Device"
block|}
block|,
block|{
literal|"NXP5442"
block|,
literal|"NXP 5442 Near Field Communications Controller"
block|}
block|,
block|{
literal|"NXP5472"
block|,
literal|"NXP NFC"
block|}
block|,
block|{
literal|"PNP0000"
block|,
literal|"8259-compatible Programmable Interrupt Controller"
block|}
block|,
block|{
literal|"PNP0001"
block|,
literal|"EISA Interrupt Controller"
block|}
block|,
block|{
literal|"PNP0002"
block|,
literal|"MCA Interrupt Controller"
block|}
block|,
block|{
literal|"PNP0003"
block|,
literal|"IO-APIC Interrupt Controller"
block|}
block|,
block|{
literal|"PNP0100"
block|,
literal|"PC-class System Timer"
block|}
block|,
block|{
literal|"PNP0103"
block|,
literal|"HPET System Timer"
block|}
block|,
block|{
literal|"PNP0200"
block|,
literal|"PC-class DMA Controller"
block|}
block|,
block|{
literal|"PNP0300"
block|,
literal|"IBM PC/XT Keyboard Controller (83 key)"
block|}
block|,
block|{
literal|"PNP0301"
block|,
literal|"IBM PC/XT Keyboard Controller (86 key)"
block|}
block|,
block|{
literal|"PNP0302"
block|,
literal|"IBM PC/XT Keyboard Controller (84 key)"
block|}
block|,
block|{
literal|"PNP0303"
block|,
literal|"IBM Enhanced Keyboard (101/102-key, PS/2 Mouse)"
block|}
block|,
block|{
literal|"PNP0400"
block|,
literal|"Standard LPT Parallel Port"
block|}
block|,
block|{
literal|"PNP0401"
block|,
literal|"ECP Parallel Port"
block|}
block|,
block|{
literal|"PNP0500"
block|,
literal|"Standard PC COM Serial Port"
block|}
block|,
block|{
literal|"PNP0501"
block|,
literal|"16550A-compatible COM Serial Port"
block|}
block|,
block|{
literal|"PNP0510"
block|,
literal|"Generic IRDA-compatible Device"
block|}
block|,
block|{
literal|"PNP0800"
block|,
literal|"Microsoft Sound System Compatible Device"
block|}
block|,
block|{
literal|"PNP0A03"
block|,
literal|"PCI Bus"
block|}
block|,
block|{
literal|"PNP0A05"
block|,
literal|"Generic Container Device"
block|}
block|,
block|{
literal|"PNP0A06"
block|,
literal|"Generic Container Device"
block|}
block|,
block|{
literal|"PNP0A08"
block|,
literal|"PCI Express Bus"
block|}
block|,
block|{
literal|"PNP0B00"
block|,
literal|"AT Real-Time Clock"
block|}
block|,
block|{
literal|"PNP0B01"
block|,
literal|"Intel PIIX4-compatible RTC/CMOS Device"
block|}
block|,
block|{
literal|"PNP0B02"
block|,
literal|"Dallas Semiconductor-compatible RTC/CMOS Device"
block|}
block|,
block|{
literal|"PNP0C01"
block|,
literal|"System Board"
block|}
block|,
block|{
literal|"PNP0C02"
block|,
literal|"PNP Motherboard Resources"
block|}
block|,
block|{
literal|"PNP0C04"
block|,
literal|"x87-compatible Floating Point Processing Unit"
block|}
block|,
block|{
literal|"PNP0C08"
block|,
literal|"ACPI Core Hardware"
block|}
block|,
block|{
literal|"PNP0C09"
block|,
literal|"Embedded Controller Device"
block|}
block|,
block|{
literal|"PNP0C0A"
block|,
literal|"Control Method Battery"
block|}
block|,
block|{
literal|"PNP0C0B"
block|,
literal|"Fan (Thermal Solution)"
block|}
block|,
block|{
literal|"PNP0C0C"
block|,
literal|"Power Button Device"
block|}
block|,
block|{
literal|"PNP0C0D"
block|,
literal|"Lid Device"
block|}
block|,
block|{
literal|"PNP0C0E"
block|,
literal|"Sleep Button Device"
block|}
block|,
block|{
literal|"PNP0C0F"
block|,
literal|"PCI Interrupt Link Device"
block|}
block|,
block|{
literal|"PNP0C10"
block|,
literal|"System Indicator Device"
block|}
block|,
block|{
literal|"PNP0C11"
block|,
literal|"Thermal Zone"
block|}
block|,
block|{
literal|"PNP0C12"
block|,
literal|"Device Bay Controller"
block|}
block|,
block|{
literal|"PNP0C14"
block|,
literal|"Windows Management Instrumentation Device"
block|}
block|,
block|{
literal|"PNP0C15"
block|,
literal|"Docking Station"
block|}
block|,
block|{
literal|"PNP0C40"
block|,
literal|"Standard Button Controller"
block|}
block|,
block|{
literal|"PNP0C50"
block|,
literal|"HID Protocol Device (I2C bus)"
block|}
block|,
block|{
literal|"PNP0C60"
block|,
literal|"Display Sensor Device"
block|}
block|,
block|{
literal|"PNP0C70"
block|,
literal|"Dock Sensor Device"
block|}
block|,
block|{
literal|"PNP0C80"
block|,
literal|"Memory Device"
block|}
block|,
block|{
literal|"PNP0D10"
block|,
literal|"XHCI USB Controller with debug"
block|}
block|,
block|{
literal|"PNP0D15"
block|,
literal|"XHCI USB Controller without debug"
block|}
block|,
block|{
literal|"PNP0D20"
block|,
literal|"EHCI USB Controller without debug"
block|}
block|,
block|{
literal|"PNP0D25"
block|,
literal|"EHCI USB Controller with debug"
block|}
block|,
block|{
literal|"PNP0D40"
block|,
literal|"SDA Standard Compliant SD Host Controller"
block|}
block|,
block|{
literal|"PNP0D80"
block|,
literal|"Windows-compatible System Power Management Controller"
block|}
block|,
block|{
literal|"PNP0F03"
block|,
literal|"Microsoft PS/2-style Mouse"
block|}
block|,
block|{
literal|"PNP0F13"
block|,
literal|"PS/2 Mouse"
block|}
block|,
block|{
literal|"RTL8723"
block|,
literal|"Realtek Wireless Controller"
block|}
block|,
block|{
literal|"SMB0349"
block|,
literal|"Charger"
block|}
block|,
block|{
literal|"SMO91D0"
block|,
literal|"Sensor Hub"
block|}
block|,
block|{
literal|"SMSC3750"
block|,
literal|"SMSC 3750 USB MUX"
block|}
block|,
block|{
literal|"SSPX0000"
block|,
literal|"Intel SSP Device"
block|}
block|,
block|{
literal|"TBQ24296"
block|,
literal|"Charger"
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiAhMatchHardwareId  *  * PARAMETERS:  HardwareId          - String representation of an _HID or _CID  *  * RETURN:      ID info struct. NULL if HardwareId is not found  *  * DESCRIPTION: Lookup an _HID/_CID in the device ID table  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|AH_DEVICE_ID
modifier|*
name|AcpiAhMatchHardwareId
parameter_list|(
name|char
modifier|*
name|HardwareId
parameter_list|)
block|{
specifier|const
name|AH_DEVICE_ID
modifier|*
name|Info
decl_stmt|;
for|for
control|(
name|Info
operator|=
name|AslDeviceIds
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
operator|!
name|ACPI_STRCMP
argument_list|(
name|HardwareId
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

