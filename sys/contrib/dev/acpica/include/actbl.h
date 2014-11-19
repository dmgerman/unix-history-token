begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl.h - Basic ACPI Table Definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*******************************************************************************  *  * Fundamental ACPI tables  *  * This file contains definitions for the ACPI tables that are directly consumed  * by ACPICA. All other tables are consumed by the OS-dependent ACPI-related  * device drivers and other OS support code.  *  * The RSDP and FACS do not use the common ACPI table header. All other ACPI  * tables use the header.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Values for description table header signatures for tables defined in this  * file. Useful because they make it more difficult to inadvertently type in  * the wrong signature.  */
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
comment|/*  * Note: C bitfields are not used for this reason:  *  * "Bitfields are great and easy to read, but unfortunately the C language  * does not specify the layout of bitfields in memory, which means they are  * essentially useless for dealing with packed data in on-disk formats or  * binary wire protocols." (Or ACPI tables and buffers.) "If you ask me,  * this decision was a design error in C. Ritchie could have picked an order  * and stuck with it." Norman Ramsey.  * See http://stackoverflow.com/a/1053662/41661  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * Master ACPI Table Header. This common header is used by all ACPI tables  * except the RSDP and FACS.  *  ******************************************************************************/
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
comment|/* ACPI Specification minor version number */
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
comment|/*******************************************************************************  *  * GAS - Generic Address Structure (ACPI 2.0+)  *  * Note: Since this structure is used in the ACPI tables, it is byte aligned.  * If misaligned access is not supported by the hardware, accesses to the  * 64-bit Address field must be performed with care.  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * RSDP - Root System Description Pointer (Signature is "RSD PTR ")  *        Version 2  *  ******************************************************************************/
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

begin_comment
comment|/* Standalone struct for the ACPI 1.0 RSDP */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_rsdp_common
block|{
name|char
name|Signature
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|char
name|OemId
index|[
name|ACPI_OEM_ID_SIZE
index|]
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT32
name|RsdtPhysicalAddress
decl_stmt|;
block|}
name|ACPI_RSDP_COMMON
typedef|;
end_typedef

begin_comment
comment|/* Standalone struct for the extended part of the RSDP (ACPI 2.0+) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_rsdp_extension
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT64
name|XsdtPhysicalAddress
decl_stmt|;
name|UINT8
name|ExtendedChecksum
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_RSDP_EXTENSION
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * RSDT/XSDT - Root System Description Tables  *             Version 1 (both)  *  ******************************************************************************/
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

begin_define
define|#
directive|define
name|ACPI_RSDT_ENTRY_SIZE
value|(sizeof (UINT32))
end_define

begin_define
define|#
directive|define
name|ACPI_XSDT_ENTRY_SIZE
value|(sizeof (UINT64))
end_define

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
literal|3
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|OspmFlags
decl_stmt|;
comment|/* Flags to be set by OSPM (ACPI 4.0) */
name|UINT8
name|Reserved1
index|[
literal|24
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_TABLE_FACS
typedef|;
end_typedef

begin_comment
comment|/* Masks for GlobalLock flag field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_GLOCK_PENDING
value|(1)
end_define

begin_comment
comment|/* 00: Pending global lock ownership */
end_comment

begin_define
define|#
directive|define
name|ACPI_GLOCK_OWNED
value|(1<<1)
end_define

begin_comment
comment|/* 01: Global lock is owned */
end_comment

begin_comment
comment|/* Masks for Flags field above  */
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

begin_define
define|#
directive|define
name|ACPI_FACS_64BIT_WAKE
value|(1<<1)
end_define

begin_comment
comment|/* 01: 64-bit wake vector supported (ACPI 4.0) */
end_comment

begin_comment
comment|/* Masks for OspmFlags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_FACS_64BIT_ENVIRONMENT
value|(1)
end_define

begin_comment
comment|/* 00: 64-bit wake environment is required (ACPI 4.0) */
end_comment

begin_comment
comment|/*******************************************************************************  *  * FADT - Fixed ACPI Description Table (Signature "FACP")  *        Version 4  *  ******************************************************************************/
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
comment|/* Value to write to SMI_CMD to enable ACPI */
name|UINT8
name|AcpiDisable
decl_stmt|;
comment|/* Value to write to SMI_CMD to disable ACPI */
name|UINT8
name|S4BiosRequest
decl_stmt|;
comment|/* Value to write to SMI_CMD to enter S4BIOS state */
name|UINT8
name|PstateControl
decl_stmt|;
comment|/* Processor performance state control*/
name|UINT32
name|Pm1aEventBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt 1a Event Reg Blk */
name|UINT32
name|Pm1bEventBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt 1b Event Reg Blk */
name|UINT32
name|Pm1aControlBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt 1a Control Reg Blk */
name|UINT32
name|Pm1bControlBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt 1b Control Reg Blk */
name|UINT32
name|Pm2ControlBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt 2 Control Reg Blk */
name|UINT32
name|PmTimerBlock
decl_stmt|;
comment|/* 32-bit port address of Power Mgt Timer Ctrl Reg Blk */
name|UINT32
name|Gpe0Block
decl_stmt|;
comment|/* 32-bit port address of General Purpose Event 0 Reg Blk */
name|UINT32
name|Gpe1Block
decl_stmt|;
comment|/* 32-bit port address of General Purpose Event 1 Reg Blk */
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
comment|/* Support for the _CST object and C-States change notification */
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
comment|/* Processor memory cache line width, in bytes */
name|UINT16
name|FlushStride
decl_stmt|;
comment|/* Number of flush strides that need to be read */
name|UINT8
name|DutyOffset
decl_stmt|;
comment|/* Processor duty cycle index in processor P_CNT reg */
name|UINT8
name|DutyWidth
decl_stmt|;
comment|/* Processor duty cycle value bit width in P_CNT register */
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
comment|/* IA-PC Boot Architecture Flags (see below for individual flags) */
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
name|UINT16
name|ArmBootFlags
decl_stmt|;
comment|/* ARM-Specific Boot Flags (see below for individual flags) (ACPI 5.1) */
name|UINT8
name|MinorRevision
decl_stmt|;
comment|/* FADT Minor Revision (ACPI 5.1) */
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
name|ACPI_GENERIC_ADDRESS
name|SleepControl
decl_stmt|;
comment|/* 64-bit Sleep Control register (ACPI 5.0) */
name|ACPI_GENERIC_ADDRESS
name|SleepStatus
decl_stmt|;
comment|/* 64-bit Sleep Status register (ACPI 5.0) */
block|}
name|ACPI_TABLE_FADT
typedef|;
end_typedef

begin_comment
comment|/* Masks for FADT IA-PC Boot Architecture Flags (boot_flags) [Vx]=Introduced in this FADT revision */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_LEGACY_DEVICES
value|(1)
end_define

begin_comment
comment|/* 00: [V2] System has LPC or ISA bus devices */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_8042
value|(1<<1)
end_define

begin_comment
comment|/* 01: [V3] System has an 8042 controller on port 60/64 */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_NO_VGA
value|(1<<2)
end_define

begin_comment
comment|/* 02: [V4] It is not safe to probe for VGA hardware */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_NO_MSI
value|(1<<3)
end_define

begin_comment
comment|/* 03: [V4] Message Signaled Interrupts (MSI) must not be enabled */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_NO_ASPM
value|(1<<4)
end_define

begin_comment
comment|/* 04: [V4] PCIe ASPM control must not be enabled */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_NO_CMOS_RTC
value|(1<<5)
end_define

begin_comment
comment|/* 05: [V5] No CMOS real-time clock present */
end_comment

begin_comment
comment|/* Masks for FADT ARM Boot Architecture Flags (arm_boot_flags) ACPI 5.1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PSCI_COMPLIANT
value|(1)
end_define

begin_comment
comment|/* 00: [V5+] PSCI 0.2+ is implemented */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PSCI_USE_HVC
value|(1<<1)
end_define

begin_comment
comment|/* 01: [V5+] HVC must be used instead of SMC as the PSCI conduit */
end_comment

begin_comment
comment|/* Masks for FADT flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_WBINVD
value|(1)
end_define

begin_comment
comment|/* 00: [V1] The WBINVD instruction works properly */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_WBINVD_FLUSH
value|(1<<1)
end_define

begin_comment
comment|/* 01: [V1] WBINVD flushes but does not invalidate caches */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_C1_SUPPORTED
value|(1<<2)
end_define

begin_comment
comment|/* 02: [V1] All processors support C1 state */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_C2_MP_SUPPORTED
value|(1<<3)
end_define

begin_comment
comment|/* 03: [V1] C2 state works on MP system */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_POWER_BUTTON
value|(1<<4)
end_define

begin_comment
comment|/* 04: [V1] Power button is handled as a control method device */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SLEEP_BUTTON
value|(1<<5)
end_define

begin_comment
comment|/* 05: [V1] Sleep button is handled as a control method device */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_FIXED_RTC
value|(1<<6)
end_define

begin_comment
comment|/* 06: [V1] RTC wakeup status is not in fixed register space */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_S4_RTC_WAKE
value|(1<<7)
end_define

begin_comment
comment|/* 07: [V1] RTC alarm can wake system from S4 */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_32BIT_TIMER
value|(1<<8)
end_define

begin_comment
comment|/* 08: [V1] ACPI timer width is 32-bit (0=24-bit) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_DOCKING_SUPPORTED
value|(1<<9)
end_define

begin_comment
comment|/* 09: [V1] Docking supported */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_RESET_REGISTER
value|(1<<10)
end_define

begin_comment
comment|/* 10: [V2] System reset via the FADT RESET_REG supported */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SEALED_CASE
value|(1<<11)
end_define

begin_comment
comment|/* 11: [V3] No internal expansion capabilities and case is sealed */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_HEADLESS
value|(1<<12)
end_define

begin_comment
comment|/* 12: [V3] No local video capabilities or local input devices */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_SLEEP_TYPE
value|(1<<13)
end_define

begin_comment
comment|/* 13: [V3] Must execute native instruction after writing  SLP_TYPx register */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PCI_EXPRESS_WAKE
value|(1<<14)
end_define

begin_comment
comment|/* 14: [V4] System supports PCIEXP_WAKE (STS/EN) bits (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_PLATFORM_CLOCK
value|(1<<15)
end_define

begin_comment
comment|/* 15: [V4] OSPM should use platform-provided timer (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_S4_RTC_VALID
value|(1<<16)
end_define

begin_comment
comment|/* 16: [V4] Contents of RTC_STS valid after S4 wake (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_REMOTE_POWER_ON
value|(1<<17)
end_define

begin_comment
comment|/* 17: [V4] System is compatible with remote power on (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_APIC_CLUSTER
value|(1<<18)
end_define

begin_comment
comment|/* 18: [V4] All local APICs must use cluster model (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_APIC_PHYSICAL
value|(1<<19)
end_define

begin_comment
comment|/* 19: [V4] All local xAPICs must use physical dest mode (ACPI 3.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_HW_REDUCED
value|(1<<20)
end_define

begin_comment
comment|/* 20: [V5] ACPI hardware is not implemented (ACPI 5.0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_LOW_POWER_S0
value|(1<<21)
end_define

begin_comment
comment|/* 21: [V5] S0 power savings are equal or better than S3 (ACPI 5.0) */
end_comment

begin_comment
comment|/* Values for PreferredProfile (Preferred Power Management Profiles) */
end_comment

begin_enum
enum|enum
name|AcpiPreferredPmProfiles
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
block|,
name|PM_PERFORMANCE_SERVER
init|=
literal|7
block|,
name|PM_TABLET
init|=
literal|8
block|}
enum|;
end_enum

begin_comment
comment|/* Values for SleepStatus and SleepControl registers (V5 FADT) */
end_comment

begin_define
define|#
directive|define
name|ACPI_X_WAKE_STATUS
value|0x80
end_define

begin_define
define|#
directive|define
name|ACPI_X_SLEEP_TYPE_MASK
value|0x1C
end_define

begin_define
define|#
directive|define
name|ACPI_X_SLEEP_TYPE_POSITION
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_X_SLEEP_ENABLE
value|0x20
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
comment|/*  * Internal table-related structures  */
end_comment

begin_typedef
typedef|typedef
union|union
name|acpi_name_union
block|{
name|UINT32
name|Integer
decl_stmt|;
name|char
name|Ascii
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ACPI_NAME_UNION
typedef|;
end_typedef

begin_comment
comment|/* Internal ACPI Table Descriptor. One per ACPI table. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_desc
block|{
name|ACPI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
name|ACPI_TABLE_HEADER
modifier|*
name|Pointer
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
comment|/* Length fixed at 32 bits (fixed in table header) */
name|ACPI_NAME_UNION
name|Signature
decl_stmt|;
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_DESC
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL
value|(0)
end_define

begin_comment
comment|/* Virtual address, external maintained */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL
value|(1)
end_define

begin_comment
comment|/* Physical address, internally mapped */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL
value|(2)
end_define

begin_comment
comment|/* Virtual address, internallly allocated */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_MASK
value|(3)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_IS_LOADED
value|(8)
end_define

begin_comment
comment|/*  * Get the remaining ACPI tables  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actbl1.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actbl2.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actbl3.h>
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
value|(UINT16) ACPI_OFFSET (ACPI_TABLE_FADT, f)
end_define

begin_comment
comment|/*  * Sizes of the various flavors of FADT. We need to look closely  * at the FADT length because the version number essentially tells  * us nothing because of many BIOS bugs where the version does not  * match the expected length. In other words, the length of the  * FADT is the bottom line as to what the version really is.  *  * For reference, the values below are as follows:  *     FADT V1  size: 0x074  *     FADT V2  size: 0x084  *     FADT V3  size: 0x0F4  *     FADT V4  size: 0x0F4  *     FADT V5  size: 0x10C  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FADT_V1_SIZE
value|(UINT32) (ACPI_FADT_OFFSET (Flags) + 4)
end_define

begin_define
define|#
directive|define
name|ACPI_FADT_V2_SIZE
value|(UINT32) (ACPI_FADT_OFFSET (MinorRevision) + 1)
end_define

begin_define
define|#
directive|define
name|ACPI_FADT_V3_SIZE
value|(UINT32) (ACPI_FADT_OFFSET (SleepControl))
end_define

begin_define
define|#
directive|define
name|ACPI_FADT_V5_SIZE
value|(UINT32) (sizeof (ACPI_TABLE_FADT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTBL_H__ */
end_comment

end_unit

