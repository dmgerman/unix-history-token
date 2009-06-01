begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl.h - Basic ACPI Table Definitions  *       $Revision: 1.84 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL_H__
end_define

begin_comment
comment|/*  * Values for description table header signatures. Useful because they make  * it more difficult to inadvertently type in the wrong signature.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_DSDT
value|"DSDT"
end_define

begin_comment
comment|/* Differentiated System Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_FADT
value|"FACP"
end_define

begin_comment
comment|/* Fixed ACPI Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_FACS
value|"FACS"
end_define

begin_comment
comment|/* Firmware ACPI Control Structure */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_PSDT
value|"PSDT"
end_define

begin_comment
comment|/* Persistent System Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_RSDP
value|"RSD PTR "
end_define

begin_comment
comment|/* Root System Description Pointer */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_RSDT
value|"RSDT"
end_define

begin_comment
comment|/* Root System Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_XSDT
value|"XSDT"
end_define

begin_comment
comment|/* Extended  System Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_SSDT
value|"SSDT"
end_define

begin_comment
comment|/* Secondary System Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_RSDP_NAME
value|"RSDP"
end_define

begin_comment
comment|/* Short name for RSDP, not signature */
end_comment

begin_comment
comment|/*  * All tables and structures must be byte-packed to match the ACPI  * specification, since the tables are provided by the system BIOS  */
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
comment|/*  * These are the ACPI tables that are directly consumed by the subsystem.  *  * The RSDP and FACS do not use the common ACPI table header. All other ACPI  * tables use the header.  *  * Note about bitfields: The UINT8 type is used for bitfields in ACPI tables.  * This is the only type that is even remotely portable. Anything else is not  * portable, so do not use any other bitfield types.  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * ACPI Table Header. This common header is used by all tables except the  * RSDP and FACS. The define is used for direct inclusion of header into  * other ACPI tables  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_header
block|{
name|char
name|Signature
index|[
name|ACPI_NAME_SIZE
index|]
decl_stmt|;
comment|/* ASCII table signature */
name|UINT32
name|Length
decl_stmt|;
comment|/* Length of table in bytes, including this header */
name|UINT8
name|Revision
decl_stmt|;
comment|/* ACPI Specification minor version # */
name|UINT8
name|Checksum
decl_stmt|;
comment|/* To make sum of entire table == 0 */
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
name|UINT32
name|OemRevision
decl_stmt|;
comment|/* OEM revision number */
name|char
name|AslCompilerId
index|[
name|ACPI_NAME_SIZE
index|]
decl_stmt|;
comment|/* ASCII ASL compiler vendor ID */
name|UINT32
name|AslCompilerRevision
decl_stmt|;
comment|/* ASL compiler version */
block|}
name|ACPI_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * GAS - Generic Address Structure (ACPI 2.0+)  *  * Note: Since this structure is used in the ACPI tables, it is byte aligned.  * If misalignment is not supported, access to the Address field must be  * performed with care.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_generic_address
block|{
name|UINT8
name|SpaceId
decl_stmt|;
comment|/* Address space where struct or register exists */
name|UINT8
name|BitWidth
decl_stmt|;
comment|/* Size in bits of given register */
name|UINT8
name|BitOffset
decl_stmt|;
comment|/* Bit offset within the register */
name|UINT8
name|AccessWidth
decl_stmt|;
comment|/* Minimum Access size (ACPI 3.0) */
name|UINT64
name|Address
decl_stmt|;
comment|/* 64-bit address of struct or register */
block|}
name|ACPI_GENERIC_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * RSDP - Root System Description Pointer (Signature is "RSD PTR ")  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_rsdp
block|{
name|char
name|Signature
index|[
literal|8
index|]
decl_stmt|;
comment|/* ACPI signature, contains "RSD PTR " */
name|UINT8
name|Checksum
decl_stmt|;
comment|/* ACPI 1.0 checksum */
name|char
name|OemId
index|[
name|ACPI_OEM_ID_SIZE
index|]
decl_stmt|;
comment|/* OEM identification */
name|UINT8
name|Revision
decl_stmt|;
comment|/* Must be (0) for ACPI 1.0 or (2) for ACPI 2.0+ */
name|UINT32
name|RsdtPhysicalAddress
decl_stmt|;
comment|/* 32-bit physical address of the RSDT */
name|UINT32
name|Length
decl_stmt|;
comment|/* Table length in bytes, including header (ACPI 2.0+) */
name|UINT64
name|XsdtPhysicalAddress
decl_stmt|;
comment|/* 64-bit physical address of the XSDT (ACPI 2.0+) */
name|UINT8
name|ExtendedChecksum
decl_stmt|;
comment|/* Checksum of entire table (ACPI 2.0+) */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_TABLE_RSDP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_RSDP_REV0_SIZE
value|20
end_define

begin_comment
comment|/* Size of original ACPI 1.0 RSDP */
end_comment

begin_comment
comment|/*******************************************************************************  *  * RSDT/XSDT - Root System Description Tables  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_rsdt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|TableOffsetEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of pointers to ACPI tables */
block|}
name|ACPI_TABLE_RSDT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_xsdt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|TableOffsetEntry
index|[
literal|1
index|]
decl_stmt|;
comment|/* Array of pointers to ACPI tables */
block|}
name|ACPI_TABLE_XSDT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * FACS - Firmware ACPI Control Structure (FACS)  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_facs
block|{
name|char
name|Signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* ASCII table signature */
name|UINT32
name|Length
decl_stmt|;
comment|/* Length of structure, in bytes */
name|UINT32
name|HardwareSignature
decl_stmt|;
comment|/* Hardware configuration signature */
name|UINT32
name|FirmwareWakingVector
decl_stmt|;
comment|/* 32-bit physical address of the Firmware Waking Vector */
name|UINT32
name|GlobalLock
decl_stmt|;
comment|/* Global Lock for shared hardware resources */
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|XFirmwareWakingVector
decl_stmt|;
comment|/* 64-bit version of the Firmware Waking Vector (ACPI 2.0+) */
name|UINT8
name|Version
decl_stmt|;
comment|/* Version of this table (ACPI 2.0+) */
name|UINT8
name|Reserved
index|[
literal|31
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_TABLE_FACS
typedef|;
end_typedef

begin_comment
comment|/* Flag macros */
end_comment

begin_define
define|#
directive|define
name|ACPI_FACS_S4_BIOS_PRESENT
value|(1)
end_define

begin_comment
comment|/* 00: S4BIOS support is present */
end_comment

begin_comment
comment|/* Global lock flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_GLOCK_PENDING
value|0x01
end_define

begin_comment
comment|/* 00: Pending global lock ownership */
end_comment

begin_define
define|#
directive|define
name|ACPI_GLOCK_OWNED
value|0x02
end_define

begin_comment
comment|/* 01: Global lock is owned */
end_comment

begin_comment
comment|/*******************************************************************************  *  * FADT - Fixed ACPI Description Table (Signature "FACP")  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Fields common to all versions of the FADT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_fadt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Facs
decl_stmt|;
comment|/* 32-bit physical address of FACS */
name|UINT32
name|Dsdt
decl_stmt|;
comment|/* 32-bit physical address of DSDT */
name|UINT8
name|Model
decl_stmt|;
comment|/* System Interrupt Model (ACPI 1.0) - not used in ACPI 2.0+ */
name|UINT8
name|PreferredProfile
decl_stmt|;
comment|/* Conveys preferred power management profile to OSPM. */
name|UINT16
name|SciInterrupt
decl_stmt|;
comment|/* System vector of SCI interrupt */
name|UINT32
name|SmiCommand
decl_stmt|;
comment|/* 32-bit Port address of SMI command port */
name|UINT8
name|AcpiEnable
decl_stmt|;
comment|/* Value to write to smi_cmd to enable ACPI */
name|UINT8
name|AcpiDisable
decl_stmt|;
comment|/* Value to write to smi_cmd to disable ACPI */
name|UINT8
name|S4BiosRequest
decl_stmt|;
comment|/* Value to write to SMI CMD to enter S4BIOS state */
name|UINT8
name|PstateControl
decl_stmt|;
comment|/* Processor performance state control*/
name|UINT32
name|Pm1aEventBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt 1a Event Reg Blk */
name|UINT32
name|Pm1bEventBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt 1b Event Reg Blk */
name|UINT32
name|Pm1aControlBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt 1a Control Reg Blk */
name|UINT32
name|Pm1bControlBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt 1b Control Reg Blk */
name|UINT32
name|Pm2ControlBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt 2 Control Reg Blk */
name|UINT32
name|PmTimerBlock
decl_stmt|;
comment|/* 32-bit Port address of Power Mgt Timer Ctrl Reg Blk */
name|UINT32
name|Gpe0Block
decl_stmt|;
comment|/* 32-bit Port address of General Purpose Event 0 Reg Blk */
name|UINT32
name|Gpe1Block
decl_stmt|;
comment|/* 32-bit Port address of General Purpose Event 1 Reg Blk */
name|UINT8
name|Pm1EventLength
decl_stmt|;
comment|/* Byte Length of ports at Pm1xEventBlock */
name|UINT8
name|Pm1ControlLength
decl_stmt|;
comment|/* Byte Length of ports at Pm1xControlBlock */
name|UINT8
name|Pm2ControlLength
decl_stmt|;
comment|/* Byte Length of ports at Pm2ControlBlock */
name|UINT8
name|PmTimerLength
decl_stmt|;
comment|/* Byte Length of ports at PmTimerBlock */
name|UINT8
name|Gpe0BlockLength
decl_stmt|;
comment|/* Byte Length of ports at Gpe0Block */
name|UINT8
name|Gpe1BlockLength
decl_stmt|;
comment|/* Byte Length of ports at Gpe1Block */
name|UINT8
name|Gpe1Base
decl_stmt|;
comment|/* Offset in GPE number space where GPE1 events start */
name|UINT8
name|CstControl
decl_stmt|;
comment|/* Support for the _CST object and C States change notification */
name|UINT16
name|C2Latency
decl_stmt|;
comment|/* Worst case HW latency to enter/exit C2 state */
name|UINT16
name|C3Latency
decl_stmt|;
comment|/* Worst case HW latency to enter/exit C3 state */
name|UINT16
name|FlushSize
decl_stmt|;
comment|/* Processor's memory cache line width, in bytes */
name|UINT16
name|FlushStride
decl_stmt|;
comment|/* Number of flush strides that need to be read */
name|UINT8
name|DutyOffset
decl_stmt|;
comment|/* Processor duty cycle index in processor's P_CNT reg*/
name|UINT8
name|DutyWidth
decl_stmt|;
comment|/* Processor duty cycle value bit width in P_CNT register.*/
name|UINT8
name|DayAlarm
decl_stmt|;
comment|/* Index to day-of-month alarm in RTC CMOS RAM */
name|UINT8
name|MonthAlarm
decl_stmt|;
comment|/* Index to month-of-year alarm in RTC CMOS RAM */
name|UINT8
name|Century
decl_stmt|;
comment|/* Index to century in RTC CMOS RAM */
name|UINT16
name|BootFlags
decl_stmt|;
comment|/* IA-PC Boot Architecture Flags. See Table 5-10 for description */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|Flags
decl_stmt|;
comment|/* Miscellaneous flag bits (see below for individual flags) */
name|ACPI_GENERIC_ADDRESS
name|ResetRegister
decl_stmt|;
comment|/* 64-bit address of the Reset register */
name|UINT8
name|ResetValue
decl_stmt|;
comment|/* Value to write to the ResetRegister port to reset the system */
name|UINT8
name|Reserved4
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT64
name|XFacs
decl_stmt|;
comment|/* 64-bit physical address of FACS */
name|UINT64
name|XDsdt
decl_stmt|;
comment|/* 64-bit physical address of DSDT */
name|ACPI_GENERIC_ADDRESS
name|XPm1aEventBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt 1a Event Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1bEventBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt 1b Event Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1aControlBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt 1a Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm1bControlBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt 1b Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPm2ControlBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt 2 Control Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XPmTimerBlock
decl_stmt|;
comment|/* 64-bit Extended Power Mgt Timer Ctrl Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XGpe0Block
decl_stmt|;
comment|/* 64-bit Extended General Purpose Event 0 Reg Blk address */
name|ACPI_GENERIC_ADDRESS
name|XGpe1Block
decl_stmt|;
comment|/* 64-bit Extended General Purpose Event 1 Reg Blk address */
block|}
name|ACPI_TABLE_FADT
typedef|;
end_typedef

begin_comment
comment|/* FADT flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_WBINVD
value|(1)
end_define

begin_comment
comment|/* 00: The wbinvd instruction works properly */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_WBINVD_FLUSH
value|(1<<1)
end_define

begin_comment
comment|/* 01: The wbinvd flushes but does not invalidate */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_C1_SUPPORTED
value|(1<<2)
end_define

begin_comment
comment|/* 02: All processors support C1 state */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_C2_MP_SUPPORTED
value|(1<<3)
end_define

begin_comment
comment|/* 03: C2 state works on MP system */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_POWER_BUTTON
value|(1<<4)
end_define

begin_comment
comment|/* 04: Power button is handled as a generic feature */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SLEEP_BUTTON
value|(1<<5)
end_define

begin_comment
comment|/* 05: Sleep button is handled as a generic feature, or  not present */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_FIXED_RTC
value|(1<<6)
end_define

begin_comment
comment|/* 06: RTC wakeup stat not in fixed register space */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_S4_RTC_WAKE
value|(1<<7)
end_define

begin_comment
comment|/* 07: RTC wakeup stat not possible from S4 */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_32BIT_TIMER
value|(1<<8)
end_define

begin_comment
comment|/* 08: tmr_val is 32 bits 0=24-bits */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_DOCKING_SUPPORTED
value|(1<<9)
end_define

begin_comment
comment|/* 09: Docking supported */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_RESET_REGISTER
value|(1<<10)
end_define

begin_comment
comment|/* 10: System reset via the FADT RESET_REG supported */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SEALED_CASE
value|(1<<11)
end_define

begin_comment
comment|/* 11: No internal expansion capabilities and case is sealed */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_HEADLESS
value|(1<<12)
end_define

begin_comment
comment|/* 12: No local video capabilities or local input devices */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SLEEP_TYPE
value|(1<<13)
end_define

begin_comment
comment|/* 13: Must execute native instruction after writing  SLP_TYPx register */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PCI_EXPRESS_WAKE
value|(1<<14)
end_define

begin_comment
comment|/* 14: System supports PCIEXP_WAKE (STS/EN) bits (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PLATFORM_CLOCK
value|(1<<15)
end_define

begin_comment
comment|/* 15: OSPM should use platform-provided timer (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_S4_RTC_VALID
value|(1<<16)
end_define

begin_comment
comment|/* 16: Contents of RTC_STS valid after S4 wake (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_REMOTE_POWER_ON
value|(1<<17)
end_define

begin_comment
comment|/* 17: System is compatible with remote power on (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_APIC_CLUSTER
value|(1<<18)
end_define

begin_comment
comment|/* 18: All local APICs must use cluster model (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_APIC_PHYSICAL
value|(1<<19)
end_define

begin_comment
comment|/* 19: All local xAPICs must use physical dest mode (ACPI 3.0) */
end_comment

begin_comment
comment|/*  * FADT Prefered Power Management Profiles  */
end_comment

begin_enum
enum|enum
name|AcpiPreferedPmProfiles
block|{
name|PM_UNSPECIFIED
init|=
literal|0
block|,
name|PM_DESKTOP
init|=
literal|1
block|,
name|PM_MOBILE
init|=
literal|2
block|,
name|PM_WORKSTATION
init|=
literal|3
block|,
name|PM_ENTERPRISE_SERVER
init|=
literal|4
block|,
name|PM_SOHO_SERVER
init|=
literal|5
block|,
name|PM_APPLIANCE_PC
init|=
literal|6
block|}
enum|;
end_enum

begin_comment
comment|/* FADT Boot Arch Flags */
end_comment

begin_define
define|#
directive|define
name|BAF_LEGACY_DEVICES
value|0x0001
end_define

begin_define
define|#
directive|define
name|BAF_8042_KEYBOARD_CONTROLLER
value|0x0002
end_define

begin_define
define|#
directive|define
name|FADT2_REVISION_ID
value|3
end_define

begin_define
define|#
directive|define
name|FADT2_MINUS_REVISION_ID
value|2
end_define

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

begin_comment
comment|/*  * Get the remaining ACPI tables  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/actbl1.h>
end_include

begin_comment
comment|/* Macros used to generate offsets to specific table fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_OFFSET
parameter_list|(
name|f
parameter_list|)
value|(UINT8) ACPI_OFFSET (ACPI_TABLE_FADT, f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTBL_H__ */
end_comment

end_unit

