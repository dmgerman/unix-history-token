begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl2.h - ACPI Specification Revision 2.0 Tables  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2010, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
name|ACPI_SIG_MCFG
value|"MCFG"
end_define

begin_comment
comment|/* PCI Memory Mapped Configuration table */
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
name|ACPI_SIG_WDRT
value|"WDRT"
end_define

begin_comment
comment|/* Watchdog Resource Table */
end_comment

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
comment|/*  * Note about bitfields: The UINT8 type is used for bitfields in ACPI tables.  * This is the only type that is even remotely portable. Anything else is not  * portable, so do not use any other bitfield types.  */
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
comment|/*******************************************************************************  *  * DMAR - DMA Remapping table  *        Version 1  *  * Conforms to "Intel Virtualization Technology for Directed I/O",  * Version 1.2, Sept. 2008  *  ******************************************************************************/
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
name|ACPI_DMAR_TYPE_ATSR
init|=
literal|2
block|,
name|ACPI_DMAR_HARDWARE_AFFINITY
init|=
literal|3
block|,
name|ACPI_DMAR_TYPE_RESERVED
init|=
literal|4
comment|/* 4 and greater are reserved */
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
comment|/* Values for EntryType in ACPI_DMAR_DEVICE_SCOPE */
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
name|ACPI_DMAR_SCOPE_TYPE_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
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
comment|/*  * DMAR Sub-tables, correspond to Type in ACPI_DMAR_HEADER  */
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
comment|/*******************************************************************************  *  * MCFG - PCI Memory Mapped Configuration table and sub-table  *        Version 1  *  * Conforms to "PCI Firmware Specification", Revision 3.0, June 20, 2005  *  ******************************************************************************/
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

