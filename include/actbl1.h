begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl1.h - Additional ACPI table definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2009, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL1_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL1_H__
end_define

begin_comment
comment|/*******************************************************************************  *  * Additional ACPI Tables  *  * These tables are not consumed directly by the ACPICA subsystem, but are  * included here to support device drivers and the AML disassembler.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Values for description table header signatures. Useful because they make  * it more difficult to inadvertently type in the wrong signature.  */
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
name|ACPI_SIG_BERT
value|"BERT"
end_define

begin_comment
comment|/* Boot Error Record Table */
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
name|ACPI_SIG_CPEP
value|"CPEP"
end_define

begin_comment
comment|/* Corrected Platform Error Polling table */
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
name|ACPI_SIG_ECDT
value|"ECDT"
end_define

begin_comment
comment|/* Embedded Controller Boot Resources Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_EINJ
value|"EINJ"
end_define

begin_comment
comment|/* Error Injection table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_ERST
value|"ERST"
end_define

begin_comment
comment|/* Error Record Serialization Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_HEST
value|"HEST"
end_define

begin_comment
comment|/* Hardware Error Source Table */
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
name|ACPI_SIG_MADT
value|"APIC"
end_define

begin_comment
comment|/* Multiple APIC Description Table */
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
name|ACPI_SIG_SBST
value|"SBST"
end_define

begin_comment
comment|/* Smart Battery Specification Table */
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
name|ACPI_SIG_SLIT
value|"SLIT"
end_define

begin_comment
comment|/* System Locality Distance Information Table */
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
name|ACPI_SIG_SRAT
value|"SRAT"
end_define

begin_comment
comment|/* System Resource Affinity Table */
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
comment|/* Common Subtable header (used in MADT, SRAT, etc.) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_subtable_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|ACPI_SUBTABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Common Subtable header for WHEA tables (EINJ, ERST, WDAT) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_whea_header
block|{
name|UINT8
name|Action
decl_stmt|;
name|UINT8
name|Instruction
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|RegisterRegion
decl_stmt|;
name|UINT64
name|Value
decl_stmt|;
comment|/* Value used with Read/Write register */
name|UINT64
name|Mask
decl_stmt|;
comment|/* Bitmask required for this register instruction */
block|}
name|ACPI_WHEA_HEADER
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * ASF - Alert Standard Format table (Signature "ASF!")  *  * Conforms to the Alert Standard Format Specification V2.0, 23 April 2003  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * BERT - Boot Error Record Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_bert
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|RegionLength
decl_stmt|;
comment|/* Length of the boot error region */
name|UINT64
name|Address
decl_stmt|;
comment|/* Physical addresss of the error region */
block|}
name|ACPI_TABLE_BERT
typedef|;
end_typedef

begin_comment
comment|/* Boot Error Region */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_bert_region
block|{
name|UINT32
name|BlockStatus
decl_stmt|;
name|UINT32
name|RawDataOffset
decl_stmt|;
name|UINT32
name|RawDataLength
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
block|}
name|ACPI_BERT_REGION
typedef|;
end_typedef

begin_comment
comment|/* BlockStatus Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_BERT_UNCORRECTABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_CORRECTABLE
value|(2)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_MULTIPLE_UNCORRECTABLE
value|(4)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_MULTIPLE_CORRECTABLE
value|(8)
end_define

begin_comment
comment|/*******************************************************************************  *  * BOOT - Simple Boot Flag Table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * CPEP - Corrected Platform Error Polling table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_cpep
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|ACPI_TABLE_CPEP
typedef|;
end_typedef

begin_comment
comment|/* Subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_cpep_polling
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
comment|/* Processor ID */
name|UINT8
name|Eid
decl_stmt|;
comment|/* Processor EID */
name|UINT32
name|Interval
decl_stmt|;
comment|/* Polling interval (msec) */
block|}
name|ACPI_CPEP_POLLING
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * DBGP - Debug Port table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * DMAR - DMA Remapping table  *        From "Intel Virtualization Technology for Directed I/O", Sept. 2007  *  ******************************************************************************/
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
comment|/* Flags */
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
name|ACPI_DMAR_TYPE_RESERVED
init|=
literal|3
comment|/* 3 and greater are reserved */
block|}
enum|;
end_enum

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
comment|/* Flags */
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
comment|/* Flags */
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
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMAR_ALL_PORTS
value|(1)
end_define

begin_comment
comment|/*******************************************************************************  *  * ECDT - Embedded Controller Boot Resources Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_ecdt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|ACPI_GENERIC_ADDRESS
name|Control
decl_stmt|;
comment|/* Address of EC command/status register */
name|ACPI_GENERIC_ADDRESS
name|Data
decl_stmt|;
comment|/* Address of EC data register */
name|UINT32
name|Uid
decl_stmt|;
comment|/* Unique ID - must be same as the EC _UID method */
name|UINT8
name|Gpe
decl_stmt|;
comment|/* The GPE for the EC */
name|UINT8
name|Id
index|[
literal|1
index|]
decl_stmt|;
comment|/* Full namepath of the EC in the ACPI namespace */
block|}
name|ACPI_TABLE_ECDT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * EINJ - Error Injection Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_einj
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|HeaderLength
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|Entries
decl_stmt|;
block|}
name|ACPI_TABLE_EINJ
typedef|;
end_typedef

begin_comment
comment|/* EINJ Injection Instruction Entries (actions) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_einj_entry
block|{
name|ACPI_WHEA_HEADER
name|WheaHeader
decl_stmt|;
comment|/* Common header for WHEA tables */
block|}
name|ACPI_EINJ_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Values for Action field above */
end_comment

begin_enum
enum|enum
name|AcpiEinjActions
block|{
name|ACPI_EINJ_BEGIN_OPERATION
init|=
literal|0
block|,
name|ACPI_EINJ_GET_TRIGGER_TABLE
init|=
literal|1
block|,
name|ACPI_EINJ_SET_ERROR_TYPE
init|=
literal|2
block|,
name|ACPI_EINJ_GET_ERROR_TYPE
init|=
literal|3
block|,
name|ACPI_EINJ_END_OPERATION
init|=
literal|4
block|,
name|ACPI_EINJ_EXECUTE_OPERATION
init|=
literal|5
block|,
name|ACPI_EINJ_CHECK_BUSY_STATUS
init|=
literal|6
block|,
name|ACPI_EINJ_GET_COMMAND_STATUS
init|=
literal|7
block|,
name|ACPI_EINJ_ACTION_RESERVED
init|=
literal|8
block|,
comment|/* 8 and greater are reserved */
name|ACPI_EINJ_TRIGGER_ERROR
init|=
literal|0xFF
comment|/* Except for this value */
block|}
enum|;
end_enum

begin_comment
comment|/* Values for Instruction field above */
end_comment

begin_enum
enum|enum
name|AcpiEinjInstructions
block|{
name|ACPI_EINJ_READ_REGISTER
init|=
literal|0
block|,
name|ACPI_EINJ_READ_REGISTER_VALUE
init|=
literal|1
block|,
name|ACPI_EINJ_WRITE_REGISTER
init|=
literal|2
block|,
name|ACPI_EINJ_WRITE_REGISTER_VALUE
init|=
literal|3
block|,
name|ACPI_EINJ_NOOP
init|=
literal|4
block|,
name|ACPI_EINJ_INSTRUCTION_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* EINJ Trigger Error Action Table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_einj_trigger
block|{
name|UINT32
name|HeaderSize
decl_stmt|;
name|UINT32
name|Revision
decl_stmt|;
name|UINT32
name|TableSize
decl_stmt|;
name|UINT32
name|EntryCount
decl_stmt|;
block|}
name|ACPI_EINJ_TRIGGER
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * ERST - Error Record Serialization Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_erst
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|HeaderLength
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|Entries
decl_stmt|;
block|}
name|ACPI_TABLE_ERST
typedef|;
end_typedef

begin_comment
comment|/* ERST Serialization Entries (actions) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_erst_entry
block|{
name|ACPI_WHEA_HEADER
name|WheaHeader
decl_stmt|;
comment|/* Common header for WHEA tables */
block|}
name|ACPI_ERST_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Values for Action field above */
end_comment

begin_enum
enum|enum
name|AcpiErstActions
block|{
name|ACPI_ERST_BEGIN_WRITE_OPERATION
init|=
literal|0
block|,
name|ACPI_ERST_BEGIN_READ_OPERATION
init|=
literal|1
block|,
name|ACPI_ERST_BETGIN_CLEAR_OPERATION
init|=
literal|2
block|,
name|ACPI_ERST_END_OPERATION
init|=
literal|3
block|,
name|ACPI_ERST_SET_RECORD_OFFSET
init|=
literal|4
block|,
name|ACPI_ERST_EXECUTE_OPERATION
init|=
literal|5
block|,
name|ACPI_ERST_CHECK_BUSY_STATUS
init|=
literal|6
block|,
name|ACPI_ERST_GET_COMMAND_STATUS
init|=
literal|7
block|,
name|ACPI_ERST_GET_RECORD_IDENTIFIER
init|=
literal|8
block|,
name|ACPI_ERST_SET_RECORD_IDENTIFIER
init|=
literal|9
block|,
name|ACPI_ERST_GET_RECORD_COUNT
init|=
literal|10
block|,
name|ACPI_ERST_BEGIN_DUMMY_WRIITE
init|=
literal|11
block|,
name|ACPI_ERST_NOT_USED
init|=
literal|12
block|,
name|ACPI_ERST_GET_ERROR_RANGE
init|=
literal|13
block|,
name|ACPI_ERST_GET_ERROR_LENGTH
init|=
literal|14
block|,
name|ACPI_ERST_GET_ERROR_ATTRIBUTES
init|=
literal|15
block|,
name|ACPI_ERST_ACTION_RESERVED
init|=
literal|16
comment|/* 16 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* Values for Instruction field above */
end_comment

begin_enum
enum|enum
name|AcpiErstInstructions
block|{
name|ACPI_ERST_READ_REGISTER
init|=
literal|0
block|,
name|ACPI_ERST_READ_REGISTER_VALUE
init|=
literal|1
block|,
name|ACPI_ERST_WRITE_REGISTER
init|=
literal|2
block|,
name|ACPI_ERST_WRITE_REGISTER_VALUE
init|=
literal|3
block|,
name|ACPI_ERST_NOOP
init|=
literal|4
block|,
name|ACPI_ERST_LOAD_VAR1
init|=
literal|5
block|,
name|ACPI_ERST_LOAD_VAR2
init|=
literal|6
block|,
name|ACPI_ERST_STORE_VAR1
init|=
literal|7
block|,
name|ACPI_ERST_ADD
init|=
literal|8
block|,
name|ACPI_ERST_SUBTRACT
init|=
literal|9
block|,
name|ACPI_ERST_ADD_VALUE
init|=
literal|10
block|,
name|ACPI_ERST_SUBTRACT_VALUE
init|=
literal|11
block|,
name|ACPI_ERST_STALL
init|=
literal|12
block|,
name|ACPI_ERST_STALL_WHILE_TRUE
init|=
literal|13
block|,
name|ACPI_ERST_SKIP_NEXT_IF_TRUE
init|=
literal|14
block|,
name|ACPI_ERST_GOTO
init|=
literal|15
block|,
name|ACPI_ERST_SET_SRC_ADDRESS_BASE
init|=
literal|16
block|,
name|ACPI_ERST_SET_DST_ADDRESS_BASE
init|=
literal|17
block|,
name|ACPI_ERST_MOVE_DATA
init|=
literal|18
block|,
name|ACPI_ERST_INSTRUCTION_RESERVED
init|=
literal|19
comment|/* 19 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*******************************************************************************  *  * HEST - Hardware Error Source Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_hest
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|ErrorSourceCount
decl_stmt|;
block|}
name|ACPI_TABLE_HEST
typedef|;
end_typedef

begin_comment
comment|/* HEST subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_header
block|{
name|UINT16
name|Type
decl_stmt|;
block|}
name|ACPI_HEST_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above for subtables */
end_comment

begin_enum
enum|enum
name|AcpiHestTypes
block|{
name|ACPI_HEST_TYPE_XPF_MACHINE_CHECK
init|=
literal|0
block|,
name|ACPI_HEST_TYPE_XPF_CORRECTED_MACHINE_CHECK
init|=
literal|1
block|,
name|ACPI_HEST_TYPE_XPF_UNUSED
init|=
literal|2
block|,
name|ACPI_HEST_TYPE_XPF_NON_MASKABLE_INTERRUPT
init|=
literal|3
block|,
name|ACPI_HEST_TYPE_IPF_CORRECTED_MACHINE_CHECK
init|=
literal|4
block|,
name|ACPI_HEST_TYPE_IPF_CORRECTED_PLATFORM_ERROR
init|=
literal|5
block|,
name|ACPI_HEST_TYPE_AER_ROOT_PORT
init|=
literal|6
block|,
name|ACPI_HEST_TYPE_AER_ENDPOINT
init|=
literal|7
block|,
name|ACPI_HEST_TYPE_AER_BRIDGE
init|=
literal|8
block|,
name|ACPI_HEST_TYPE_GENERIC_HARDWARE_ERROR_SOURCE
init|=
literal|9
block|,
name|ACPI_HEST_TYPE_RESERVED
init|=
literal|10
comment|/* 10 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * HEST Sub-subtables  */
end_comment

begin_comment
comment|/* XPF Machine Check Error Bank */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_xpf_error_bank
block|{
name|UINT8
name|BankNumber
decl_stmt|;
name|UINT8
name|ClearStatusOnInit
decl_stmt|;
name|UINT8
name|StatusFormat
decl_stmt|;
name|UINT8
name|ConfigWriteEnable
decl_stmt|;
name|UINT32
name|ControlRegister
decl_stmt|;
name|UINT64
name|ControlInitData
decl_stmt|;
name|UINT32
name|StatusRegister
decl_stmt|;
name|UINT32
name|AddressRegister
decl_stmt|;
name|UINT32
name|MiscRegister
decl_stmt|;
block|}
name|ACPI_HEST_XPF_ERROR_BANK
typedef|;
end_typedef

begin_comment
comment|/* Generic Error Status */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_generic_status
block|{
name|UINT32
name|BlockStatus
decl_stmt|;
name|UINT32
name|RawDataOffset
decl_stmt|;
name|UINT32
name|RawDataLength
decl_stmt|;
name|UINT32
name|DataLength
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC_STATUS
typedef|;
end_typedef

begin_comment
comment|/* Generic Error Data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_generic_data
block|{
name|UINT8
name|SectionType
index|[
literal|16
index|]
decl_stmt|;
name|UINT32
name|ErrorSeverity
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|ValidationBits
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT32
name|ErrorDataLength
decl_stmt|;
name|UINT8
name|FruId
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|FruText
index|[
literal|20
index|]
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC_DATA
typedef|;
end_typedef

begin_comment
comment|/* Common HEST structure for PCI/AER types below (6,7,8) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_aer_common
block|{
name|UINT16
name|SourceId
decl_stmt|;
name|UINT16
name|ConfigWriteEnable
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|Bus
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Function
decl_stmt|;
name|UINT16
name|DeviceControl
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|UncorrectableErrorMask
decl_stmt|;
name|UINT32
name|UncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|CorrectableErrorMask
decl_stmt|;
name|UINT32
name|AdvancedErrorCapabilities
decl_stmt|;
block|}
name|ACPI_HEST_AER_COMMON
typedef|;
end_typedef

begin_comment
comment|/* Hardware Error Notification */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_notify
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|ConfigWriteEnable
decl_stmt|;
name|UINT32
name|PollInterval
decl_stmt|;
name|UINT32
name|Vector
decl_stmt|;
name|UINT32
name|PollingThresholdValue
decl_stmt|;
name|UINT32
name|PollingThresholdWindow
decl_stmt|;
name|UINT32
name|ErrorThresholdValue
decl_stmt|;
name|UINT32
name|ErrorThresholdWindow
decl_stmt|;
block|}
name|ACPI_HEST_NOTIFY
typedef|;
end_typedef

begin_comment
comment|/* Values for Notify Type field above */
end_comment

begin_enum
enum|enum
name|AcpiHestNotifyTypes
block|{
name|ACPI_HEST_NOTIFY_POLLED
init|=
literal|0
block|,
name|ACPI_HEST_NOTIFY_EXTERNAL
init|=
literal|1
block|,
name|ACPI_HEST_NOTIFY_LOCAL
init|=
literal|2
block|,
name|ACPI_HEST_NOTIFY_SCI
init|=
literal|3
block|,
name|ACPI_HEST_NOTIFY_NMI
init|=
literal|4
block|,
name|ACPI_HEST_NOTIFY_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * HEST subtables  *  * From WHEA Design Document, 16 May 2007.  * Note: There is no subtable type 2 in this version of the document,  * and there are two different subtable type 3s.  */
end_comment

begin_comment
comment|/* 0: XPF Machine Check Exception */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_xpf_machine_check
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT16
name|ConfigWriteEnable
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT32
name|RecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT64
name|GlobalCapabilityData
decl_stmt|;
name|UINT64
name|GlobalControlData
decl_stmt|;
name|UINT8
name|NumHardwareBanks
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|7
index|]
decl_stmt|;
block|}
name|ACPI_HEST_XPF_MACHINE_CHECK
typedef|;
end_typedef

begin_comment
comment|/* 1: XPF Corrected Machine Check */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_hest_xpf_corrected
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT16
name|ConfigWriteEnable
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|ACPI_HEST_NOTIFY
name|Notify
decl_stmt|;
name|UINT8
name|NumHardwareBanks
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_HEST_XPF_CORRECTED
typedef|;
end_typedef

begin_comment
comment|/* 3: XPF Non-Maskable Interrupt */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_xpf_nmi
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|RecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|MaxRawDataLength
decl_stmt|;
block|}
name|ACPI_HEST_XPF_NMI
typedef|;
end_typedef

begin_comment
comment|/* 4: IPF Corrected Machine Check */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ipf_corrected
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|ACPI_HEST_IPF_CORRECTED
typedef|;
end_typedef

begin_comment
comment|/* 5: IPF Corrected Platform Error */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ipf_corrected_platform
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|ACPI_HEST_IPF_CORRECTED_PLATFORM
typedef|;
end_typedef

begin_comment
comment|/* 6: PCI Express Root Port AER */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_aer_root
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|ACPI_HEST_AER_COMMON
name|Aer
decl_stmt|;
name|UINT32
name|RootErrorCommand
decl_stmt|;
block|}
name|ACPI_HEST_AER_ROOT
typedef|;
end_typedef

begin_comment
comment|/* 7: PCI Express AER (AER Endpoint) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_aer
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|ACPI_HEST_AER_COMMON
name|Aer
decl_stmt|;
block|}
name|ACPI_HEST_AER
typedef|;
end_typedef

begin_comment
comment|/* 8: PCI Express/PCI-X Bridge AER */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_aer_bridge
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|ACPI_HEST_AER_COMMON
name|Aer
decl_stmt|;
name|UINT32
name|SecondaryUncorrectableErrorMask
decl_stmt|;
name|UINT32
name|SecondaryUncorrectableErrorSeverity
decl_stmt|;
name|UINT32
name|SecondaryAdvancedCapabilities
decl_stmt|;
block|}
name|ACPI_HEST_AER_BRIDGE
typedef|;
end_typedef

begin_comment
comment|/* 9: Generic Hardware Error Source */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_generic
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|SourceId
decl_stmt|;
name|UINT16
name|RelatedSourceId
decl_stmt|;
name|UINT8
name|ConfigWriteEnable
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreAllocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|MaxRawDataLength
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ErrorStatusAddress
decl_stmt|;
name|ACPI_HEST_NOTIFY
name|Notify
decl_stmt|;
name|UINT32
name|ErrorStatusBlockLength
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * HPET - High Precision Event Timer table  *  ******************************************************************************/
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
comment|/*! Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_HPET_PAGE_PROTECT
value|(1)
end_define

begin_comment
comment|/* 00: No page protection */
end_comment

begin_define
define|#
directive|define
name|ACPI_HPET_PAGE_PROTECT_4
value|(1<<1)
end_define

begin_comment
comment|/* 01: 4KB page protected */
end_comment

begin_define
define|#
directive|define
name|ACPI_HPET_PAGE_PROTECT_64
value|(1<<2)
end_define

begin_comment
comment|/* 02: 64KB page protected */
end_comment

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_comment
comment|/*******************************************************************************  *  * IBFT - Boot Firmware Table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * MADT - Multiple APIC Description Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_madt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Address
decl_stmt|;
comment|/* Physical address of local APIC */
name|UINT32
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_MADT
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_PCAT_COMPAT
value|(1)
end_define

begin_comment
comment|/* 00:    System also has dual 8259s */
end_comment

begin_comment
comment|/* Values for PCATCompat flag */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_DUAL_PIC
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_MULTIPLE_APIC
value|1
end_define

begin_comment
comment|/* Values for subtable type in ACPI_SUBTABLE_HEADER */
end_comment

begin_enum
enum|enum
name|AcpiMadtType
block|{
name|ACPI_MADT_TYPE_LOCAL_APIC
init|=
literal|0
block|,
name|ACPI_MADT_TYPE_IO_APIC
init|=
literal|1
block|,
name|ACPI_MADT_TYPE_INTERRUPT_OVERRIDE
init|=
literal|2
block|,
name|ACPI_MADT_TYPE_NMI_SOURCE
init|=
literal|3
block|,
name|ACPI_MADT_TYPE_LOCAL_APIC_NMI
init|=
literal|4
block|,
name|ACPI_MADT_TYPE_LOCAL_APIC_OVERRIDE
init|=
literal|5
block|,
name|ACPI_MADT_TYPE_IO_SAPIC
init|=
literal|6
block|,
name|ACPI_MADT_TYPE_LOCAL_SAPIC
init|=
literal|7
block|,
name|ACPI_MADT_TYPE_INTERRUPT_SOURCE
init|=
literal|8
block|,
name|ACPI_MADT_TYPE_LOCAL_X2APIC
init|=
literal|9
block|,
name|ACPI_MADT_TYPE_LOCAL_X2APIC_NMI
init|=
literal|10
block|,
name|ACPI_MADT_TYPE_RESERVED
init|=
literal|11
comment|/* 11 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * MADT Sub-tables, correspond to Type in ACPI_SUBTABLE_HEADER  */
end_comment

begin_comment
comment|/* 0: Processor Local APIC */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_apic
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|Id
decl_stmt|;
comment|/* Processor's local APIC id */
name|UINT32
name|LapicFlags
decl_stmt|;
block|}
name|ACPI_MADT_LOCAL_APIC
typedef|;
end_typedef

begin_comment
comment|/* 1: IO APIC */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_io_apic
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
comment|/* I/O APIC ID */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|Address
decl_stmt|;
comment|/* APIC physical address */
name|UINT32
name|GlobalIrqBase
decl_stmt|;
comment|/* Global system interrupt where INTI lines start */
block|}
name|ACPI_MADT_IO_APIC
typedef|;
end_typedef

begin_comment
comment|/* 2: Interrupt Override */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_interrupt_override
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
comment|/* 0 - ISA */
name|UINT8
name|SourceIrq
decl_stmt|;
comment|/* Interrupt source (IRQ) */
name|UINT32
name|GlobalIrq
decl_stmt|;
comment|/* Global system interrupt */
name|UINT16
name|IntiFlags
decl_stmt|;
block|}
name|ACPI_MADT_INTERRUPT_OVERRIDE
typedef|;
end_typedef

begin_comment
comment|/* 3: NMI Source */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_nmi_source
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|IntiFlags
decl_stmt|;
name|UINT32
name|GlobalIrq
decl_stmt|;
comment|/* Global system interrupt */
block|}
name|ACPI_MADT_NMI_SOURCE
typedef|;
end_typedef

begin_comment
comment|/* 4: Local APIC NMI */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_apic_nmi
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT16
name|IntiFlags
decl_stmt|;
name|UINT8
name|Lint
decl_stmt|;
comment|/* LINTn to which NMI is connected */
block|}
name|ACPI_MADT_LOCAL_APIC_NMI
typedef|;
end_typedef

begin_comment
comment|/* 5: Address Override */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_apic_override
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT64
name|Address
decl_stmt|;
comment|/* APIC physical address */
block|}
name|ACPI_MADT_LOCAL_APIC_OVERRIDE
typedef|;
end_typedef

begin_comment
comment|/* 6: I/O Sapic */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_io_sapic
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Id
decl_stmt|;
comment|/* I/O SAPIC ID */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|GlobalIrqBase
decl_stmt|;
comment|/* Global interrupt for SAPIC start */
name|UINT64
name|Address
decl_stmt|;
comment|/* SAPIC physical address */
block|}
name|ACPI_MADT_IO_SAPIC
typedef|;
end_typedef

begin_comment
comment|/* 7: Local Sapic */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_sapic
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|Id
decl_stmt|;
comment|/* SAPIC ID */
name|UINT8
name|Eid
decl_stmt|;
comment|/* SAPIC EID */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|LapicFlags
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
comment|/* Numeric UID - ACPI 3.0 */
name|char
name|UidString
index|[
literal|1
index|]
decl_stmt|;
comment|/* String UID  - ACPI 3.0 */
block|}
name|ACPI_MADT_LOCAL_SAPIC
typedef|;
end_typedef

begin_comment
comment|/* 8: Platform Interrupt Source */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_interrupt_source
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|IntiFlags
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
comment|/* 1=PMI, 2=INIT, 3=corrected */
name|UINT8
name|Id
decl_stmt|;
comment|/* Processor ID */
name|UINT8
name|Eid
decl_stmt|;
comment|/* Processor EID */
name|UINT8
name|IoSapicVector
decl_stmt|;
comment|/* Vector value for PMI interrupts */
name|UINT32
name|GlobalIrq
decl_stmt|;
comment|/* Global system interrupt */
name|UINT32
name|Flags
decl_stmt|;
comment|/* Interrupt Source Flags */
block|}
name|ACPI_MADT_INTERRUPT_SOURCE
typedef|;
end_typedef

begin_comment
comment|/* Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_CPEI_OVERRIDE
value|(1)
end_define

begin_comment
comment|/* 9: Processor Local X2APIC (ACPI 4.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_x2apic
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|LocalApicId
decl_stmt|;
comment|/* Processor x2APIC ID  */
name|UINT32
name|LapicFlags
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
comment|/* ACPI processor UID */
block|}
name|ACPI_MADT_LOCAL_X2APIC
typedef|;
end_typedef

begin_comment
comment|/* 10: Local X2APIC NMI (ACPI 4.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_local_x2apic_nmi
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|IntiFlags
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
comment|/* ACPI processor UID */
name|UINT8
name|Lint
decl_stmt|;
comment|/* LINTn to which NMI is connected */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved - must be zero */
block|}
name|ACPI_MADT_LOCAL_X2APIC_NMI
typedef|;
end_typedef

begin_comment
comment|/*  * Common flags fields for MADT subtables  */
end_comment

begin_comment
comment|/* MADT Local APIC flags (LapicFlags) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_ENABLED
value|(1)
end_define

begin_comment
comment|/* 00: Processor is usable if set */
end_comment

begin_comment
comment|/* MADT MPS INTI flags (IntiFlags) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_POLARITY_MASK
value|(3)
end_define

begin_comment
comment|/* 00-01: Polarity of APIC I/O input signals */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_TRIGGER_MASK
value|(3<<2)
end_define

begin_comment
comment|/* 02-03: Trigger mode of APIC input signals */
end_comment

begin_comment
comment|/* Values for MPS INTI flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_POLARITY_CONFORMS
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_POLARITY_ACTIVE_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_POLARITY_RESERVED
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_POLARITY_ACTIVE_LOW
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_TRIGGER_CONFORMS
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_TRIGGER_EDGE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_TRIGGER_RESERVED
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_TRIGGER_LEVEL
value|(3<<2)
end_define

begin_comment
comment|/*******************************************************************************  *  * MCFG - PCI Memory Mapped Configuration table and sub-table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * SBST - Smart Battery Specification Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_sbst
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|WarningLevel
decl_stmt|;
name|UINT32
name|LowLevel
decl_stmt|;
name|UINT32
name|CriticalLevel
decl_stmt|;
block|}
name|ACPI_TABLE_SBST
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SLIT - System Locality Distance Information Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_slit
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|LocalityCount
decl_stmt|;
name|UINT8
name|Entry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Real size = localities^2 */
block|}
name|ACPI_TABLE_SLIT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SPCR - Serial Port Console Redirection table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * SPMI - Server Platform Management Interface table  *  ******************************************************************************/
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
name|Reserved
decl_stmt|;
name|UINT8
name|InterfaceType
decl_stmt|;
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
block|}
name|ACPI_TABLE_SPMI
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SRAT - System Resource Affinity Table  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_srat
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|TableRevision
decl_stmt|;
comment|/* Must be value '1' */
name|UINT64
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_TABLE_SRAT
typedef|;
end_typedef

begin_comment
comment|/* Values for subtable type in ACPI_SUBTABLE_HEADER */
end_comment

begin_enum
enum|enum
name|AcpiSratType
block|{
name|ACPI_SRAT_TYPE_CPU_AFFINITY
init|=
literal|0
block|,
name|ACPI_SRAT_TYPE_MEMORY_AFFINITY
init|=
literal|1
block|,
name|ACPI_SRAT_TYPE_X2APIC_CPU_AFFINITY
init|=
literal|2
block|,
name|ACPI_SRAT_TYPE_RESERVED
init|=
literal|3
comment|/* 3 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * SRAT Sub-tables, correspond to Type in ACPI_SUBTABLE_HEADER  */
end_comment

begin_comment
comment|/* 0: Processor Local APIC/SAPIC Affinity */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_srat_cpu_affinity
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|ProximityDomainLo
decl_stmt|;
name|UINT8
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT8
name|LocalSapicEid
decl_stmt|;
name|UINT8
name|ProximityDomainHi
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_SRAT_CPU_AFFINITY
typedef|;
end_typedef

begin_comment
comment|/* 1: Memory Affinity */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_srat_mem_affinity
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
name|UINT32
name|Reserved1
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|Reserved2
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_SRAT_MEM_AFFINITY
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_MEM_ENABLED
value|(1)
end_define

begin_comment
comment|/* 00: Use affinity structure */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_MEM_HOT_PLUGGABLE
value|(1<<1)
end_define

begin_comment
comment|/* 01: Memory region is hot pluggable */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_MEM_NON_VOLATILE
value|(1<<2)
end_define

begin_comment
comment|/* 02: Memory region is non-volatile */
end_comment

begin_comment
comment|/* 2: Processor Local X2_APIC Affinity (ACPI 4.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_srat_x2apic_cpu_affinity
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT32
name|ApicId
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ClockDomain
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|ACPI_SRAT_X2APIC_CPU_AFFINITY
typedef|;
end_typedef

begin_comment
comment|/* Flags for ACPI_SRAT_CPU_AFFINITY and ACPI_SRAT_X2APIC_CPU_AFFINITY */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_CPU_ENABLED
value|(1)
end_define

begin_comment
comment|/* 00: Use affinity structure */
end_comment

begin_comment
comment|/*******************************************************************************  *  * TCPA - Trusted Computing Platform Alliance table  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * UEFI - UEFI Boot optimization Table  *  ******************************************************************************/
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
name|UINT8
name|Data
decl_stmt|;
block|}
name|ACPI_TABLE_UEFI
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * WDAT - Watchdog Action Table  *  ******************************************************************************/
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
comment|/* WDAT Instruction Entries (actions) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_wdat_entry
block|{
name|ACPI_WHEA_HEADER
name|WheaHeader
decl_stmt|;
comment|/* Common header for WHEA tables */
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
comment|/*******************************************************************************  *  * WDRT - Watchdog Resource Table  *  ******************************************************************************/
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
name|UINT32
name|HeaderLength
decl_stmt|;
comment|/* Watchdog Header Length */
name|UINT8
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
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|Entries
decl_stmt|;
comment|/* Number of watchdog entries that follow */
block|}
name|ACPI_TABLE_WDRT
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_WDRT_TIMER_ENABLED
value|(1)
end_define

begin_comment
comment|/* 00: Timer enabled */
end_comment

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
comment|/* __ACTBL1_H__ */
end_comment

end_unit

