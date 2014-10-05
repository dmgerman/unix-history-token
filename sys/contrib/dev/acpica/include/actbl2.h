begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl2.h - ACPI Table Definitions (tables not in ACPI spec)  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL2_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL2_H__
end_define

begin_comment
comment|/*******************************************************************************  *  * Additional ACPI Tables (2)  *  * These tables are not consumed directly by the ACPICA subsystem, but are  * included here to support device drivers and the AML disassembler.  *  * The tables in this file are defined by third-party specifications, and are  * not defined directly by the ACPI specification itself.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Values for description table header signatures for tables defined in this  * file. Useful because they make it more difficult to inadvertently type in  * the wrong signature.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_ASF
value|"ASF!"
end_define

begin_comment
comment|/* Alert Standard Format table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_BOOT
value|"BOOT"
end_define

begin_comment
comment|/* Simple Boot Flag Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_CSRT
value|"CSRT"
end_define

begin_comment
comment|/* Core System Resource Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_DBG2
value|"DBG2"
end_define

begin_comment
comment|/* Debug Port table type 2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_DBGP
value|"DBGP"
end_define

begin_comment
comment|/* Debug Port table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_DMAR
value|"DMAR"
end_define

begin_comment
comment|/* DMA Remapping table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_HPET
value|"HPET"
end_define

begin_comment
comment|/* High Precision Event Timer table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_IBFT
value|"IBFT"
end_define

begin_comment
comment|/* iSCSI Boot Firmware Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_IVRS
value|"IVRS"
end_define

begin_comment
comment|/* I/O Virtualization Reporting Structure */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_LPIT
value|"LPIT"
end_define

begin_comment
comment|/* Low Power Idle Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MCFG
value|"MCFG"
end_define

begin_comment
comment|/* PCI Memory Mapped Configuration table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MCHI
value|"MCHI"
end_define

begin_comment
comment|/* Management Controller Host Interface table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MTMR
value|"MTMR"
end_define

begin_comment
comment|/* MID Timer table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_SLIC
value|"SLIC"
end_define

begin_comment
comment|/* Software Licensing Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_SPCR
value|"SPCR"
end_define

begin_comment
comment|/* Serial Port Console Redirection table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_SPMI
value|"SPMI"
end_define

begin_comment
comment|/* Server Platform Management Interface table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_TCPA
value|"TCPA"
end_define

begin_comment
comment|/* Trusted Computing Platform Alliance table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_UEFI
value|"UEFI"
end_define

begin_comment
comment|/* Uefi Boot Optimization Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_VRTC
value|"VRTC"
end_define

begin_comment
comment|/* Virtual Real Time Clock Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_WAET
value|"WAET"
end_define

begin_comment
comment|/* Windows ACPI Emulated devices Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_WDAT
value|"WDAT"
end_define

begin_comment
comment|/* Watchdog Action Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_WDDT
value|"WDDT"
end_define

begin_comment
comment|/* Watchdog Timer Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_WDRT
value|"WDRT"
end_define

begin_comment
comment|/* Watchdog Resource Table */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_UNDEFINED_TABLES
end_ifdef

begin_comment
comment|/*  * These tables have been seen in the field, but no definition has been found  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_ATKG
value|"ATKG"
end_define

begin_define
define|#
directive|define
name|ACPI_SIG_GSCI
value|"GSCI"
end_define

begin_comment
comment|/* GMCH SCI table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_IEIT
value|"IEIT"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * All tables must be byte-packed to match the ACPI specification, since  * the tables are provided by the system BIOS.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/*  * Note: C bitfields are not used for this reason:  *  * "Bitfields are great and easy to read, but unfortunately the C language  * does not specify the layout of bitfields in memory, which means they are  * essentially useless for dealing with packed data in on-disk formats or  * binary wire protocols." (Or ACPI tables and buffers.) "If you ask me,  * this decision was a design error in C. Ritchie could have picked an order  * and stuck with it." Norman Ramsey.  * See http://stackoverflow.com/a/1053662/41661  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * ASF - Alert Standard Format table (Signature "ASF!")  *       Revision 0x10  *  * Conforms to the Alert Standard Format Specification V2.0, 23 April 2003  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_asf
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_ASF
typedef|;
end_typedef

begin_comment
comment|/* ASF subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_ASF_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_enum
enum|enum
name|AcpiAsfType
block|{
name|ACPI_ASF_TYPE_INFO
init|=
literal|0
block|,
name|ACPI_ASF_TYPE_ALERT
init|=
literal|1
block|,
name|ACPI_ASF_TYPE_CONTROL
init|=
literal|2
block|,
name|ACPI_ASF_TYPE_BOOT
init|=
literal|3
block|,
name|ACPI_ASF_TYPE_ADDRESS
init|=
literal|4
block|,
name|ACPI_ASF_TYPE_RESERVED
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|/*  * ASF subtables  */
end_comment

begin_comment
comment|/* 0: ASF Information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_info
block|{
name|ACPI_ASF_HEADER
name|Header
decl_stmt|;
name|UINT8
name|MinResetValue
decl_stmt|;
name|UINT8
name|MinPollInterval
decl_stmt|;
name|UINT16
name|SystemId
decl_stmt|;
name|UINT32
name|MfgId
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_ASF_INFO
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_ASF_SMBUS_PROTOCOLS
value|(1)
end_define

begin_comment
comment|/* 1: ASF Alerts */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_alert
block|{
name|ACPI_ASF_HEADER
name|Header
decl_stmt|;
name|UINT8
name|AssertMask
decl_stmt|;
name|UINT8
name|DeassertMask
decl_stmt|;
name|UINT8
name|Alerts
decl_stmt|;
name|UINT8
name|DataLength
decl_stmt|;
block|}
name|ACPI_ASF_ALERT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_alert_data
block|{
name|UINT8
name|Address
decl_stmt|;
name|UINT8
name|Command
decl_stmt|;
name|UINT8
name|Mask
decl_stmt|;
name|UINT8
name|Value
decl_stmt|;
name|UINT8
name|SensorType
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Offset
decl_stmt|;
name|UINT8
name|SourceType
decl_stmt|;
name|UINT8
name|Severity
decl_stmt|;
name|UINT8
name|SensorNumber
decl_stmt|;
name|UINT8
name|Entity
decl_stmt|;
name|UINT8
name|Instance
decl_stmt|;
block|}
name|ACPI_ASF_ALERT_DATA
typedef|;
end_typedef

begin_comment
comment|/* 2: ASF Remote Control */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_remote
block|{
name|ACPI_ASF_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Controls
decl_stmt|;
name|UINT8
name|DataLength
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
block|}
name|ACPI_ASF_REMOTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_control_data
block|{
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|Address
decl_stmt|;
name|UINT8
name|Command
decl_stmt|;
name|UINT8
name|Value
decl_stmt|;
block|}
name|ACPI_ASF_CONTROL_DATA
typedef|;
end_typedef

begin_comment
comment|/* 3: ASF RMCP Boot Options */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_rmcp
block|{
name|ACPI_ASF_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Capabilities
index|[
literal|7
index|]
decl_stmt|;
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT32
name|EnterpriseId
decl_stmt|;
name|UINT8
name|Command
decl_stmt|;
name|UINT16
name|Parameter
decl_stmt|;
name|UINT16
name|BootOptions
decl_stmt|;
name|UINT16
name|OemParameters
decl_stmt|;
block|}
name|ACPI_ASF_RMCP
typedef|;
end_typedef

begin_comment
comment|/* 4: ASF Address */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_asf_address
block|{
name|ACPI_ASF_HEADER
name|Header
decl_stmt|;
name|UINT8
name|EpromAddress
decl_stmt|;
name|UINT8
name|Devices
decl_stmt|;
block|}
name|ACPI_ASF_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * BOOT - Simple Boot Flag Table  *        Version 1  *  * Conforms to the "Simple Boot Flag Specification", Version 2.1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_boot
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|CmosIndex
decl_stmt|;
comment|/* Index in CMOS RAM for the boot register */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_TABLE_BOOT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * CSRT - Core System Resource Table  *        Version 0  *  * Conforms to the "Core System Resource Table (CSRT)", November 14, 2011  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_csrt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_CSRT
typedef|;
end_typedef

begin_comment
comment|/* Resource Group subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_csrt_group
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|VendorId
decl_stmt|;
name|UINT32
name|SubvendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|SubdeviceId
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|SharedInfoLength
decl_stmt|;
comment|/* Shared data immediately follows (Length = SharedInfoLength) */
block|}
name|ACPI_CSRT_GROUP
typedef|;
end_typedef

begin_comment
comment|/* Shared Info subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_csrt_shared_info
block|{
name|UINT16
name|MajorVersion
decl_stmt|;
name|UINT16
name|MinorVersion
decl_stmt|;
name|UINT32
name|MmioBaseLow
decl_stmt|;
name|UINT32
name|MmioBaseHigh
decl_stmt|;
name|UINT32
name|GsiInterrupt
decl_stmt|;
name|UINT8
name|InterruptPolarity
decl_stmt|;
name|UINT8
name|InterruptMode
decl_stmt|;
name|UINT8
name|NumChannels
decl_stmt|;
name|UINT8
name|DmaAddressWidth
decl_stmt|;
name|UINT16
name|BaseRequestLine
decl_stmt|;
name|UINT16
name|NumHandshakeSignals
decl_stmt|;
name|UINT32
name|MaxBlockSize
decl_stmt|;
comment|/* Resource descriptors immediately follow (Length = Group Length - SharedInfoLength) */
block|}
name|ACPI_CSRT_SHARED_INFO
typedef|;
end_typedef

begin_comment
comment|/* Resource Descriptor subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_csrt_descriptor
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Subtype
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
comment|/* Resource-specific information immediately follows */
block|}
name|ACPI_CSRT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/* Resource Types */
end_comment

begin_define
define|#
directive|define
name|ACPI_CSRT_TYPE_INTERRUPT
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_TYPE_TIMER
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_TYPE_DMA
value|0x0003
end_define

begin_comment
comment|/* Resource Subtypes */
end_comment

begin_define
define|#
directive|define
name|ACPI_CSRT_XRUPT_LINE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_XRUPT_CONTROLLER
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_TIMER
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_DMA_CHANNEL
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_CSRT_DMA_CONTROLLER
value|0x0001
end_define

begin_comment
comment|/*******************************************************************************  *  * DBG2 - Debug Port Table 2  *        Version 0 (Both main table and subtables)  *  * Conforms to "Microsoft Debug Port Table 2 (DBG2)", May 22 2012.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_dbg2
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|InfoOffset
decl_stmt|;
name|UINT32
name|InfoCount
decl_stmt|;
block|}
name|ACPI_TABLE_DBG2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_dbg2_header
block|{
name|UINT32
name|InfoOffset
decl_stmt|;
name|UINT32
name|InfoCount
decl_stmt|;
block|}
name|ACPI_DBG2_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Debug Device Information Subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dbg2_device
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|RegisterCount
decl_stmt|;
comment|/* Number of BaseAddress registers */
name|UINT16
name|NamepathLength
decl_stmt|;
name|UINT16
name|NamepathOffset
decl_stmt|;
name|UINT16
name|OemDataLength
decl_stmt|;
name|UINT16
name|OemDataOffset
decl_stmt|;
name|UINT16
name|PortType
decl_stmt|;
name|UINT16
name|PortSubtype
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT16
name|BaseAddressOffset
decl_stmt|;
name|UINT16
name|AddressSizeOffset
decl_stmt|;
comment|/*      * Data that follows:      *    BaseAddress (required) - Each in 12-byte Generic Address Structure format.      *    AddressSize (required) - Array of UINT32 sizes corresponding to each BaseAddress register.      *    Namepath    (required) - Null terminated string. Single dot if not supported.      *    OemData     (optional) - Length is OemDataLength.      */
block|}
name|ACPI_DBG2_DEVICE
typedef|;
end_typedef

begin_comment
comment|/* Types for PortType field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DBG2_SERIAL_PORT
value|0x8000
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_1394_PORT
value|0x8001
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_USB_PORT
value|0x8002
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_NET_PORT
value|0x8003
end_define

begin_comment
comment|/* Subtypes for PortSubtype field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DBG2_16550_COMPATIBLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_16550_SUBSET
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_1394_STANDARD
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_USB_XHCI
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_DBG2_USB_EHCI
value|0x0001
end_define

begin_comment
comment|/*******************************************************************************  *  * DBGP - Debug Port table  *        Version 1  *  * Conforms to the "Debug Port Specification", Version 1.00, 2/9/2000  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_dbgp
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|Type
decl_stmt|;
comment|/* 0=full 16550, 1=subset of 16550 */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DebugPort
decl_stmt|;
block|}
name|ACPI_TABLE_DBGP
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * DMAR - DMA Remapping table  *        Version 1  *  * Conforms to "Intel Virtualization Technology for Directed I/O",  * Version 2.2, Sept. 2013  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_dmar
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|Width
decl_stmt|;
comment|/* Host Address Width */
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|ACPI_TABLE_DMAR
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMAR_INTR_REMAP
value|(1)
end_define

begin_comment
comment|/* DMAR subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_header
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_DMAR_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for subtable type in ACPI_DMAR_HEADER */
end_comment

begin_enum
enum|enum
name|AcpiDmarType
block|{
name|ACPI_DMAR_TYPE_HARDWARE_UNIT
init|=
literal|0
block|,
name|ACPI_DMAR_TYPE_RESERVED_MEMORY
init|=
literal|1
block|,
name|ACPI_DMAR_TYPE_ROOT_ATS
init|=
literal|2
block|,
name|ACPI_DMAR_TYPE_HARDWARE_AFFINITY
init|=
literal|3
block|,
name|ACPI_DMAR_TYPE_NAMESPACE
init|=
literal|4
block|,
name|ACPI_DMAR_TYPE_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* DMAR Device Scope structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_device_scope
block|{
name|UINT8
name|EntryType
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT8
name|EnumerationId
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
block|}
name|ACPI_DMAR_DEVICE_SCOPE
typedef|;
end_typedef

begin_comment
comment|/* Values for EntryType in ACPI_DMAR_DEVICE_SCOPE - device types */
end_comment

begin_enum
enum|enum
name|AcpiDmarScopeType
block|{
name|ACPI_DMAR_SCOPE_TYPE_NOT_USED
init|=
literal|0
block|,
name|ACPI_DMAR_SCOPE_TYPE_ENDPOINT
init|=
literal|1
block|,
name|ACPI_DMAR_SCOPE_TYPE_BRIDGE
init|=
literal|2
block|,
name|ACPI_DMAR_SCOPE_TYPE_IOAPIC
init|=
literal|3
block|,
name|ACPI_DMAR_SCOPE_TYPE_HPET
init|=
literal|4
block|,
name|ACPI_DMAR_SCOPE_TYPE_NAMESPACE
init|=
literal|5
block|,
name|ACPI_DMAR_SCOPE_TYPE_RESERVED
init|=
literal|6
comment|/* 6 and greater are reserved */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_pci_path
block|{
name|UINT8
name|Device
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
block|}
name|ACPI_DMAR_PCI_PATH
typedef|;
end_typedef

begin_comment
comment|/*  * DMAR Subtables, correspond to Type in ACPI_DMAR_HEADER  */
end_comment

begin_comment
comment|/* 0: Hardware Unit Definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_hardware_unit
block|{
name|ACPI_DMAR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|Segment
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
comment|/* Register Base Address */
block|}
name|ACPI_DMAR_HARDWARE_UNIT
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMAR_INCLUDE_ALL
value|(1)
end_define

begin_comment
comment|/* 1: Reserved Memory Defininition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_reserved_memory
block|{
name|ACPI_DMAR_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT16
name|Segment
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
comment|/* 4K aligned base address */
name|UINT64
name|EndAddress
decl_stmt|;
comment|/* 4K aligned limit address */
block|}
name|ACPI_DMAR_RESERVED_MEMORY
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMAR_ALLOW_ALL
value|(1)
end_define

begin_comment
comment|/* 2: Root Port ATS Capability Reporting Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_atsr
block|{
name|ACPI_DMAR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|Segment
decl_stmt|;
block|}
name|ACPI_DMAR_ATSR
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMAR_ALL_PORTS
value|(1)
end_define

begin_comment
comment|/* 3: Remapping Hardware Static Affinity Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_rhsa
block|{
name|ACPI_DMAR_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|ProximityDomain
decl_stmt|;
block|}
name|ACPI_DMAR_RHSA
typedef|;
end_typedef

begin_comment
comment|/* 4: ACPI Namespace Device Declaration Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmar_andd
block|{
name|ACPI_DMAR_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|DeviceNumber
decl_stmt|;
name|char
name|DeviceName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_DMAR_ANDD
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * HPET - High Precision Event Timer table  *        Version 1  *  * Conforms to "IA-PC HPET (High Precision Event Timers) Specification",  * Version 1.0a, October 2004  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_hpet
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Id
decl_stmt|;
comment|/* Hardware ID of event timer block */
name|ACPI_GENERIC_ADDRESS
name|Address
decl_stmt|;
comment|/* Address of event timer block */
name|UINT8
name|Sequence
decl_stmt|;
comment|/* HPET sequence number */
name|UINT16
name|MinimumTick
decl_stmt|;
comment|/* Main counter min tick, periodic mode */
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_HPET
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HPET_PAGE_PROTECT_MASK
value|(3)
end_define

begin_comment
comment|/* Values for Page Protect flags */
end_comment

begin_enum
enum|enum
name|AcpiHpetPageProtect
block|{
name|ACPI_HPET_NO_PAGE_PROTECT
init|=
literal|0
block|,
name|ACPI_HPET_PAGE_PROTECT4
init|=
literal|1
block|,
name|ACPI_HPET_PAGE_PROTECT64
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/*******************************************************************************  *  * IBFT - Boot Firmware Table  *        Version 1  *  * Conforms to "iSCSI Boot Firmware Table (iBFT) as Defined in ACPI 3.0b  * Specification", Version 1.01, March 1, 2007  *  * Note: It appears that this table is not intended to appear in the RSDT/XSDT.  * Therefore, it is not currently supported by the disassembler.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_ibft
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|Reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|ACPI_TABLE_IBFT
typedef|;
end_typedef

begin_comment
comment|/* IBFT common subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ibft_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Version
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Index
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_IBFT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_enum
enum|enum
name|AcpiIbftType
block|{
name|ACPI_IBFT_TYPE_NOT_USED
init|=
literal|0
block|,
name|ACPI_IBFT_TYPE_CONTROL
init|=
literal|1
block|,
name|ACPI_IBFT_TYPE_INITIATOR
init|=
literal|2
block|,
name|ACPI_IBFT_TYPE_NIC
init|=
literal|3
block|,
name|ACPI_IBFT_TYPE_TARGET
init|=
literal|4
block|,
name|ACPI_IBFT_TYPE_EXTENSIONS
init|=
literal|5
block|,
name|ACPI_IBFT_TYPE_RESERVED
init|=
literal|6
comment|/* 6 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* IBFT subtables */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ibft_control
block|{
name|ACPI_IBFT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Extensions
decl_stmt|;
name|UINT16
name|InitiatorOffset
decl_stmt|;
name|UINT16
name|Nic0Offset
decl_stmt|;
name|UINT16
name|Target0Offset
decl_stmt|;
name|UINT16
name|Nic1Offset
decl_stmt|;
name|UINT16
name|Target1Offset
decl_stmt|;
block|}
name|ACPI_IBFT_CONTROL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_ibft_initiator
block|{
name|ACPI_IBFT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|SnsServer
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SlpServer
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|PrimaryServer
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SecondaryServer
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|NameLength
decl_stmt|;
name|UINT16
name|NameOffset
decl_stmt|;
block|}
name|ACPI_IBFT_INITIATOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_ibft_nic
block|{
name|ACPI_IBFT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|IpAddress
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SubnetMaskPrefix
decl_stmt|;
name|UINT8
name|Origin
decl_stmt|;
name|UINT8
name|Gateway
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|PrimaryDns
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SecondaryDns
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|Dhcp
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|Vlan
decl_stmt|;
name|UINT8
name|MacAddress
index|[
literal|6
index|]
decl_stmt|;
name|UINT16
name|PciAddress
decl_stmt|;
name|UINT16
name|NameLength
decl_stmt|;
name|UINT16
name|NameOffset
decl_stmt|;
block|}
name|ACPI_IBFT_NIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_ibft_target
block|{
name|ACPI_IBFT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|TargetIpAddress
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|TargetIpSocket
decl_stmt|;
name|UINT8
name|TargetBootLun
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|ChapType
decl_stmt|;
name|UINT8
name|NicAssociation
decl_stmt|;
name|UINT16
name|TargetNameLength
decl_stmt|;
name|UINT16
name|TargetNameOffset
decl_stmt|;
name|UINT16
name|ChapNameLength
decl_stmt|;
name|UINT16
name|ChapNameOffset
decl_stmt|;
name|UINT16
name|ChapSecretLength
decl_stmt|;
name|UINT16
name|ChapSecretOffset
decl_stmt|;
name|UINT16
name|ReverseChapNameLength
decl_stmt|;
name|UINT16
name|ReverseChapNameOffset
decl_stmt|;
name|UINT16
name|ReverseChapSecretLength
decl_stmt|;
name|UINT16
name|ReverseChapSecretOffset
decl_stmt|;
block|}
name|ACPI_IBFT_TARGET
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * IVRS - I/O Virtualization Reporting Structure  *        Version 1  *  * Conforms to "AMD I/O Virtualization Technology (IOMMU) Specification",  * Revision 1.26, February 2009.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_ivrs
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Info
decl_stmt|;
comment|/* Common virtualization info */
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|ACPI_TABLE_IVRS
typedef|;
end_typedef

begin_comment
comment|/* Values for Info field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVRS_PHYSICAL_SIZE
value|0x00007F00
end_define

begin_comment
comment|/* 7 bits, physical address size */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVRS_VIRTUAL_SIZE
value|0x003F8000
end_define

begin_comment
comment|/* 7 bits, virtual address size */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVRS_ATS_RESERVED
value|0x00400000
end_define

begin_comment
comment|/* ATS address translation range reserved */
end_comment

begin_comment
comment|/* IVRS subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_header
block|{
name|UINT8
name|Type
decl_stmt|;
comment|/* Subtable type */
name|UINT8
name|Flags
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
comment|/* Subtable length */
name|UINT16
name|DeviceId
decl_stmt|;
comment|/* ID of IOMMU */
block|}
name|ACPI_IVRS_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for subtable Type above */
end_comment

begin_enum
enum|enum
name|AcpiIvrsType
block|{
name|ACPI_IVRS_TYPE_HARDWARE
init|=
literal|0x10
block|,
name|ACPI_IVRS_TYPE_MEMORY1
init|=
literal|0x20
block|,
name|ACPI_IVRS_TYPE_MEMORY2
init|=
literal|0x21
block|,
name|ACPI_IVRS_TYPE_MEMORY3
init|=
literal|0x22
block|}
enum|;
end_enum

begin_comment
comment|/* Masks for Flags field above for IVHD subtable */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_TT_ENABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_PASS_PW
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_RES_PASS_PW
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_ISOC
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_IOTLB
value|(1<<4)
end_define

begin_comment
comment|/* Masks for Flags field above for IVMD subtable */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVMD_UNITY
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVMD_READ
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVMD_WRITE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_IVMD_EXCLUSION_RANGE
value|(1<<3)
end_define

begin_comment
comment|/*  * IVRS subtables, correspond to Type in ACPI_IVRS_HEADER  */
end_comment

begin_comment
comment|/* 0x10: I/O Virtualization Hardware Definition Block (IVHD) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_hardware
block|{
name|ACPI_IVRS_HEADER
name|Header
decl_stmt|;
name|UINT16
name|CapabilityOffset
decl_stmt|;
comment|/* Offset for IOMMU control fields */
name|UINT64
name|BaseAddress
decl_stmt|;
comment|/* IOMMU control registers */
name|UINT16
name|PciSegmentGroup
decl_stmt|;
name|UINT16
name|Info
decl_stmt|;
comment|/* MSI number and unit ID */
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|ACPI_IVRS_HARDWARE
typedef|;
end_typedef

begin_comment
comment|/* Masks for Info field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_MSI_NUMBER_MASK
value|0x001F
end_define

begin_comment
comment|/* 5 bits, MSI message number */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_UNIT_ID_MASK
value|0x1F00
end_define

begin_comment
comment|/* 5 bits, UnitID */
end_comment

begin_comment
comment|/*  * Device Entries for IVHD subtable, appear after ACPI_IVRS_HARDWARE structure.  * Upper two bits of the Type field are the (encoded) length of the structure.  * Currently, only 4 and 8 byte entries are defined. 16 and 32 byte entries  * are reserved for future use but not defined.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_de_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT16
name|Id
decl_stmt|;
name|UINT8
name|DataSetting
decl_stmt|;
block|}
name|ACPI_IVRS_DE_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Length of device entry is in the top two bits of Type field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_ENTRY_LENGTH
value|0xC0
end_define

begin_comment
comment|/* Values for device entry Type field above */
end_comment

begin_enum
enum|enum
name|AcpiIvrsDeviceEntryType
block|{
comment|/* 4-byte device entries, all use ACPI_IVRS_DEVICE4 */
name|ACPI_IVRS_TYPE_PAD4
init|=
literal|0
block|,
name|ACPI_IVRS_TYPE_ALL
init|=
literal|1
block|,
name|ACPI_IVRS_TYPE_SELECT
init|=
literal|2
block|,
name|ACPI_IVRS_TYPE_START
init|=
literal|3
block|,
name|ACPI_IVRS_TYPE_END
init|=
literal|4
block|,
comment|/* 8-byte device entries */
name|ACPI_IVRS_TYPE_PAD8
init|=
literal|64
block|,
name|ACPI_IVRS_TYPE_NOT_USED
init|=
literal|65
block|,
name|ACPI_IVRS_TYPE_ALIAS_SELECT
init|=
literal|66
block|,
comment|/* Uses ACPI_IVRS_DEVICE8A */
name|ACPI_IVRS_TYPE_ALIAS_START
init|=
literal|67
block|,
comment|/* Uses ACPI_IVRS_DEVICE8A */
name|ACPI_IVRS_TYPE_EXT_SELECT
init|=
literal|70
block|,
comment|/* Uses ACPI_IVRS_DEVICE8B */
name|ACPI_IVRS_TYPE_EXT_START
init|=
literal|71
block|,
comment|/* Uses ACPI_IVRS_DEVICE8B */
name|ACPI_IVRS_TYPE_SPECIAL
init|=
literal|72
comment|/* Uses ACPI_IVRS_DEVICE8C */
block|}
enum|;
end_enum

begin_comment
comment|/* Values for Data field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_INIT_PASS
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_EINT_PASS
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_NMI_PASS
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_SYSTEM_MGMT
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_LINT0_PASS
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_LINT1_PASS
value|(1<<7)
end_define

begin_comment
comment|/* Types 0-4: 4-byte device entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_device4
block|{
name|ACPI_IVRS_DE_HEADER
name|Header
decl_stmt|;
block|}
name|ACPI_IVRS_DEVICE4
typedef|;
end_typedef

begin_comment
comment|/* Types 66-67: 8-byte device entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_device8a
block|{
name|ACPI_IVRS_DE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|UsedId
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
block|}
name|ACPI_IVRS_DEVICE8A
typedef|;
end_typedef

begin_comment
comment|/* Types 70-71: 8-byte device entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_device8b
block|{
name|ACPI_IVRS_DE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ExtendedData
decl_stmt|;
block|}
name|ACPI_IVRS_DEVICE8B
typedef|;
end_typedef

begin_comment
comment|/* Values for ExtendedData above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_ATS_DISABLED
value|(1<<31)
end_define

begin_comment
comment|/* Type 72: 8-byte device entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_device8c
block|{
name|ACPI_IVRS_DE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Handle
decl_stmt|;
name|UINT16
name|UsedId
decl_stmt|;
name|UINT8
name|Variety
decl_stmt|;
block|}
name|ACPI_IVRS_DEVICE8C
typedef|;
end_typedef

begin_comment
comment|/* Values for Variety field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IVHD_IOAPIC
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_IVHD_HPET
value|2
end_define

begin_comment
comment|/* 0x20, 0x21, 0x22: I/O Virtualization Memory Definition Block (IVMD) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_ivrs_memory
block|{
name|ACPI_IVRS_HEADER
name|Header
decl_stmt|;
name|UINT16
name|AuxData
decl_stmt|;
name|UINT64
name|Reserved
decl_stmt|;
name|UINT64
name|StartAddress
decl_stmt|;
name|UINT64
name|MemoryLength
decl_stmt|;
block|}
name|ACPI_IVRS_MEMORY
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * LPIT - Low Power Idle Table  *  * Conforms to "ACPI Low Power Idle Table (LPIT) and _LPD Proposal (DRAFT)"  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_lpit
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_LPIT
typedef|;
end_typedef

begin_comment
comment|/* LPIT subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_lpit_header
block|{
name|UINT32
name|Type
decl_stmt|;
comment|/* Subtable type */
name|UINT32
name|Length
decl_stmt|;
comment|/* Subtable length */
name|UINT16
name|UniqueId
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|ACPI_LPIT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for subtable Type above */
end_comment

begin_enum
enum|enum
name|AcpiLpitType
block|{
name|ACPI_LPIT_TYPE_NATIVE_CSTATE
init|=
literal|0x00
block|,
name|ACPI_LPIT_TYPE_SIMPLE_IO
init|=
literal|0x01
block|}
enum|;
end_enum

begin_comment
comment|/* Masks for Flags field above  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LPIT_STATE_DISABLED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_LPIT_NO_COUNTER
value|(1<<1)
end_define

begin_comment
comment|/*  * LPIT subtables, correspond to Type in ACPI_LPIT_HEADER  */
end_comment

begin_comment
comment|/* 0x00: Native C-state instruction based LPI structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_lpit_native
block|{
name|ACPI_LPIT_HEADER
name|Header
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|EntryTrigger
decl_stmt|;
name|UINT32
name|Residency
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ResidencyCounter
decl_stmt|;
name|UINT64
name|CounterFrequency
decl_stmt|;
block|}
name|ACPI_LPIT_NATIVE
typedef|;
end_typedef

begin_comment
comment|/* 0x01: Simple I/O based LPI structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_lpit_io
block|{
name|ACPI_LPIT_HEADER
name|Header
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|EntryTrigger
decl_stmt|;
name|UINT32
name|TriggerAction
decl_stmt|;
name|UINT64
name|TriggerValue
decl_stmt|;
name|UINT64
name|TriggerMask
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|MinimumIdleState
decl_stmt|;
name|UINT32
name|Residency
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ResidencyCounter
decl_stmt|;
name|UINT64
name|CounterFrequency
decl_stmt|;
block|}
name|ACPI_LPIT_IO
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * MCFG - PCI Memory Mapped Configuration table and subtable  *        Version 1  *  * Conforms to "PCI Firmware Specification", Revision 3.0, June 20, 2005  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_mcfg
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|ACPI_TABLE_MCFG
typedef|;
end_typedef

begin_comment
comment|/* Subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mcfg_allocation
block|{
name|UINT64
name|Address
decl_stmt|;
comment|/* Base address, processor-relative */
name|UINT16
name|PciSegment
decl_stmt|;
comment|/* PCI segment group number */
name|UINT8
name|StartBusNumber
decl_stmt|;
comment|/* Starting PCI Bus number */
name|UINT8
name|EndBusNumber
decl_stmt|;
comment|/* Final PCI Bus number */
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|ACPI_MCFG_ALLOCATION
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * MCHI - Management Controller Host Interface Table  *        Version 1  *  * Conforms to "Management Component Transport Protocol (MCTP) Host  * Interface Specification", Revision 1.0.0a, October 13, 2009  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_mchi
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|InterfaceType
decl_stmt|;
name|UINT8
name|Protocol
decl_stmt|;
name|UINT64
name|ProtocolData
decl_stmt|;
name|UINT8
name|InterruptType
decl_stmt|;
name|UINT8
name|Gpe
decl_stmt|;
name|UINT8
name|PciDeviceFlag
decl_stmt|;
name|UINT32
name|GlobalInterrupt
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ControlRegister
decl_stmt|;
name|UINT8
name|PciSegment
decl_stmt|;
name|UINT8
name|PciBus
decl_stmt|;
name|UINT8
name|PciDevice
decl_stmt|;
name|UINT8
name|PciFunction
decl_stmt|;
block|}
name|ACPI_TABLE_MCHI
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * MTMR - MID Timer Table  *        Version 1  *  * Conforms to "Simple Firmware Interface Specification",  * Draft 0.8.2, Oct 19, 2010  * NOTE: The ACPI MTMR is equivalent to the SFI MTMR table.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_mtmr
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_MTMR
typedef|;
end_typedef

begin_comment
comment|/* MTMR entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mtmr_entry
block|{
name|ACPI_GENERIC_ADDRESS
name|PhysicalAddress
decl_stmt|;
name|UINT32
name|Frequency
decl_stmt|;
name|UINT32
name|Irq
decl_stmt|;
block|}
name|ACPI_MTMR_ENTRY
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SLIC - Software Licensing Description Table  *        Version 1  *  * Conforms to "OEM Activation 2.0 for Windows Vista Operating Systems",  * Copyright 2006  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Basic SLIC table is only the common ACPI header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_slic
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_SLIC
typedef|;
end_typedef

begin_comment
comment|/* Common SLIC subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_slic_header
block|{
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|ACPI_SLIC_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_enum
enum|enum
name|AcpiSlicType
block|{
name|ACPI_SLIC_TYPE_PUBLIC_KEY
init|=
literal|0
block|,
name|ACPI_SLIC_TYPE_WINDOWS_MARKER
init|=
literal|1
block|,
name|ACPI_SLIC_TYPE_RESERVED
init|=
literal|2
comment|/* 2 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * SLIC Subtables, correspond to Type in ACPI_SLIC_HEADER  */
end_comment

begin_comment
comment|/* 0: Public Key Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_slic_key
block|{
name|ACPI_SLIC_HEADER
name|Header
decl_stmt|;
name|UINT8
name|KeyType
decl_stmt|;
name|UINT8
name|Version
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|Algorithm
decl_stmt|;
name|char
name|Magic
index|[
literal|4
index|]
decl_stmt|;
name|UINT32
name|BitLength
decl_stmt|;
name|UINT32
name|Exponent
decl_stmt|;
name|UINT8
name|Modulus
index|[
literal|128
index|]
decl_stmt|;
block|}
name|ACPI_SLIC_KEY
typedef|;
end_typedef

begin_comment
comment|/* 1: Windows Marker Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_slic_marker
block|{
name|ACPI_SLIC_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Version
decl_stmt|;
name|char
name|OemId
index|[
name|ACPI_OEM_ID_SIZE
index|]
decl_stmt|;
comment|/* ASCII OEM identification */
name|char
name|OemTableId
index|[
name|ACPI_OEM_TABLE_ID_SIZE
index|]
decl_stmt|;
comment|/* ASCII OEM table identification */
name|char
name|WindowsFlag
index|[
literal|8
index|]
decl_stmt|;
name|UINT32
name|SlicVersion
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|Signature
index|[
literal|128
index|]
decl_stmt|;
block|}
name|ACPI_SLIC_MARKER
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SPCR - Serial Port Console Redirection table  *        Version 1  *  * Conforms to "Serial Port Console Redirection Table",  * Version 1.00, January 11, 2002  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_spcr
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|InterfaceType
decl_stmt|;
comment|/* 0=full 16550, 1=subset of 16550 */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|SerialPort
decl_stmt|;
name|UINT8
name|InterruptType
decl_stmt|;
name|UINT8
name|PcInterrupt
decl_stmt|;
name|UINT32
name|Interrupt
decl_stmt|;
name|UINT8
name|BaudRate
decl_stmt|;
name|UINT8
name|Parity
decl_stmt|;
name|UINT8
name|StopBits
decl_stmt|;
name|UINT8
name|FlowControl
decl_stmt|;
name|UINT8
name|TerminalType
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|PciDeviceId
decl_stmt|;
name|UINT16
name|PciVendorId
decl_stmt|;
name|UINT8
name|PciBus
decl_stmt|;
name|UINT8
name|PciDevice
decl_stmt|;
name|UINT8
name|PciFunction
decl_stmt|;
name|UINT32
name|PciFlags
decl_stmt|;
name|UINT8
name|PciSegment
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|ACPI_TABLE_SPCR
typedef|;
end_typedef

begin_comment
comment|/* Masks for PciFlags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPCR_DO_NOT_DISABLE
value|(1)
end_define

begin_comment
comment|/*******************************************************************************  *  * SPMI - Server Platform Management Interface table  *        Version 5  *  * Conforms to "Intelligent Platform Management Interface Specification  * Second Generation v2.0", Document Revision 1.0, February 12, 2004 with  * June 12, 2009 markup.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_spmi
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|InterfaceType
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Must be 1 */
name|UINT16
name|SpecRevision
decl_stmt|;
comment|/* Version of IPMI */
name|UINT8
name|InterruptType
decl_stmt|;
name|UINT8
name|GpeNumber
decl_stmt|;
comment|/* GPE assigned */
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT8
name|PciDeviceFlag
decl_stmt|;
name|UINT32
name|Interrupt
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|IpmiRegister
decl_stmt|;
name|UINT8
name|PciSegment
decl_stmt|;
name|UINT8
name|PciBus
decl_stmt|;
name|UINT8
name|PciDevice
decl_stmt|;
name|UINT8
name|PciFunction
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
block|}
name|ACPI_TABLE_SPMI
typedef|;
end_typedef

begin_comment
comment|/* Values for InterfaceType above */
end_comment

begin_enum
enum|enum
name|AcpiSpmiInterfaceTypes
block|{
name|ACPI_SPMI_NOT_USED
init|=
literal|0
block|,
name|ACPI_SPMI_KEYBOARD
init|=
literal|1
block|,
name|ACPI_SPMI_SMI
init|=
literal|2
block|,
name|ACPI_SPMI_BLOCK_TRANSFER
init|=
literal|3
block|,
name|ACPI_SPMI_SMBUS
init|=
literal|4
block|,
name|ACPI_SPMI_RESERVED
init|=
literal|5
comment|/* 5 and above are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*******************************************************************************  *  * TCPA - Trusted Computing Platform Alliance table  *        Version 1  *  * Conforms to "TCG PC Specific Implementation Specification",  * Version 1.1, August 18, 2003  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_tcpa
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|MaxLogLength
decl_stmt|;
comment|/* Maximum length for the event log area */
name|UINT64
name|LogAddress
decl_stmt|;
comment|/* Address of the event log area */
block|}
name|ACPI_TABLE_TCPA
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * UEFI - UEFI Boot optimization Table  *        Version 1  *  * Conforms to "Unified Extensible Firmware Interface Specification",  * Version 2.3, May 8, 2009  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_uefi
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|Identifier
index|[
literal|16
index|]
decl_stmt|;
comment|/* UUID identifier */
name|UINT16
name|DataOffset
decl_stmt|;
comment|/* Offset of remaining data in table */
block|}
name|ACPI_TABLE_UEFI
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * VRTC - Virtual Real Time Clock Table  *        Version 1  *  * Conforms to "Simple Firmware Interface Specification",  * Draft 0.8.2, Oct 19, 2010  * NOTE: The ACPI VRTC is equivalent to The SFI MRTC table.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_vrtc
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_VRTC
typedef|;
end_typedef

begin_comment
comment|/* VRTC entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_vrtc_entry
block|{
name|ACPI_GENERIC_ADDRESS
name|PhysicalAddress
decl_stmt|;
name|UINT32
name|Irq
decl_stmt|;
block|}
name|ACPI_VRTC_ENTRY
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * WAET - Windows ACPI Emulated devices Table  *        Version 1  *  * Conforms to "Windows ACPI Emulated Devices Table", version 1.0, April 6, 2009  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_waet
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_WAET
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_WAET_RTC_NO_ACK
value|(1)
end_define

begin_comment
comment|/* RTC requires no int acknowledge */
end_comment

begin_define
define|#
directive|define
name|ACPI_WAET_TIMER_ONE_READ
value|(1<<1)
end_define

begin_comment
comment|/* PM timer requires only one read */
end_comment

begin_comment
comment|/*******************************************************************************  *  * WDAT - Watchdog Action Table  *        Version 1  *  * Conforms to "Hardware Watchdog Timers Design Specification",  * Copyright 2006 Microsoft Corporation.  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_wdat
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|HeaderLength
decl_stmt|;
comment|/* Watchdog Header Length */
name|UINT16
name|PciSegment
decl_stmt|;
comment|/* PCI Segment number */
name|UINT8
name|PciBus
decl_stmt|;
comment|/* PCI Bus number */
name|UINT8
name|PciDevice
decl_stmt|;
comment|/* PCI Device number */
name|UINT8
name|PciFunction
decl_stmt|;
comment|/* PCI Function number */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|TimerPeriod
decl_stmt|;
comment|/* Period of one timer count (msec) */
name|UINT32
name|MaxCount
decl_stmt|;
comment|/* Maximum counter value supported */
name|UINT32
name|MinCount
decl_stmt|;
comment|/* Minimum counter value */
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|Entries
decl_stmt|;
comment|/* Number of watchdog entries that follow */
block|}
name|ACPI_TABLE_WDAT
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_WDAT_ENABLED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_WDAT_STOPPED
value|0x80
end_define

begin_comment
comment|/* WDAT Instruction Entries (actions) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_wdat_entry
block|{
name|UINT8
name|Action
decl_stmt|;
name|UINT8
name|Instruction
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|RegisterRegion
decl_stmt|;
name|UINT32
name|Value
decl_stmt|;
comment|/* Value used with Read/Write register */
name|UINT32
name|Mask
decl_stmt|;
comment|/* Bitmask required for this register instruction */
block|}
name|ACPI_WDAT_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Values for Action field above */
end_comment

begin_enum
enum|enum
name|AcpiWdatActions
block|{
name|ACPI_WDAT_RESET
init|=
literal|1
block|,
name|ACPI_WDAT_GET_CURRENT_COUNTDOWN
init|=
literal|4
block|,
name|ACPI_WDAT_GET_COUNTDOWN
init|=
literal|5
block|,
name|ACPI_WDAT_SET_COUNTDOWN
init|=
literal|6
block|,
name|ACPI_WDAT_GET_RUNNING_STATE
init|=
literal|8
block|,
name|ACPI_WDAT_SET_RUNNING_STATE
init|=
literal|9
block|,
name|ACPI_WDAT_GET_STOPPED_STATE
init|=
literal|10
block|,
name|ACPI_WDAT_SET_STOPPED_STATE
init|=
literal|11
block|,
name|ACPI_WDAT_GET_REBOOT
init|=
literal|16
block|,
name|ACPI_WDAT_SET_REBOOT
init|=
literal|17
block|,
name|ACPI_WDAT_GET_SHUTDOWN
init|=
literal|18
block|,
name|ACPI_WDAT_SET_SHUTDOWN
init|=
literal|19
block|,
name|ACPI_WDAT_GET_STATUS
init|=
literal|32
block|,
name|ACPI_WDAT_SET_STATUS
init|=
literal|33
block|,
name|ACPI_WDAT_ACTION_RESERVED
init|=
literal|34
comment|/* 34 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* Values for Instruction field above */
end_comment

begin_enum
enum|enum
name|AcpiWdatInstructions
block|{
name|ACPI_WDAT_READ_VALUE
init|=
literal|0
block|,
name|ACPI_WDAT_READ_COUNTDOWN
init|=
literal|1
block|,
name|ACPI_WDAT_WRITE_VALUE
init|=
literal|2
block|,
name|ACPI_WDAT_WRITE_COUNTDOWN
init|=
literal|3
block|,
name|ACPI_WDAT_INSTRUCTION_RESERVED
init|=
literal|4
block|,
comment|/* 4 and greater are reserved */
name|ACPI_WDAT_PRESERVE_REGISTER
init|=
literal|0x80
comment|/* Except for this value */
block|}
enum|;
end_enum

begin_comment
comment|/*******************************************************************************  *  * WDDT - Watchdog Descriptor Table  *        Version 1  *  * Conforms to "Using the Intel ICH Family Watchdog Timer (WDT)",  * Version 001, September 2002  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_wddt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT16
name|SpecVersion
decl_stmt|;
name|UINT16
name|TableVersion
decl_stmt|;
name|UINT16
name|PciVendorId
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|Address
decl_stmt|;
name|UINT16
name|MaxCount
decl_stmt|;
comment|/* Maximum counter value supported */
name|UINT16
name|MinCount
decl_stmt|;
comment|/* Minimum counter value supported */
name|UINT16
name|Period
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
name|UINT16
name|Capability
decl_stmt|;
block|}
name|ACPI_TABLE_WDDT
typedef|;
end_typedef

begin_comment
comment|/* Flags for Status field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_WDDT_AVAILABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_ACTIVE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_TCO_OS_OWNED
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_USER_RESET
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_WDT_RESET
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_POWER_FAIL
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_UNKNOWN_RESET
value|(1<<14)
end_define

begin_comment
comment|/* Flags for Capability field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_WDDT_AUTO_RESET
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_WDDT_ALERT_SUPPORT
value|(1<<1)
end_define

begin_comment
comment|/*******************************************************************************  *  * WDRT - Watchdog Resource Table  *        Version 1  *  * Conforms to "Watchdog Timer Hardware Requirements for Windows Server 2003",  * Version 1.01, August 28, 2006  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_wdrt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|ACPI_GENERIC_ADDRESS
name|ControlRegister
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|CountRegister
decl_stmt|;
name|UINT16
name|PciDeviceId
decl_stmt|;
name|UINT16
name|PciVendorId
decl_stmt|;
name|UINT8
name|PciBus
decl_stmt|;
comment|/* PCI Bus number */
name|UINT8
name|PciDevice
decl_stmt|;
comment|/* PCI Device number */
name|UINT8
name|PciFunction
decl_stmt|;
comment|/* PCI Function number */
name|UINT8
name|PciSegment
decl_stmt|;
comment|/* PCI Segment number */
name|UINT16
name|MaxCount
decl_stmt|;
comment|/* Maximum counter value supported */
name|UINT8
name|Units
decl_stmt|;
block|}
name|ACPI_TABLE_WDRT
typedef|;
end_typedef

begin_comment
comment|/* Reset to default packing */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTBL2_H__ */
end_comment

end_unit

