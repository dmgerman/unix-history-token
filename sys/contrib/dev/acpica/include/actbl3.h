begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl3.h - ACPI Table Definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTBL3_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTBL3_H__
end_define

begin_comment
comment|/*******************************************************************************  *  * Additional ACPI Tables (3)  *  * These tables are not consumed directly by the ACPICA subsystem, but are  * included here to support device drivers and the AML disassembler.  *  * In general, the tables in this file are fully defined within the ACPI  * specification.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Values for description table header signatures for tables defined in this  * file. Useful because they make it more difficult to inadvertently type in  * the wrong signature.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_BGRT
value|"BGRT"
end_define

begin_comment
comment|/* Boot Graphics Resource Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_DRTM
value|"DRTM"
end_define

begin_comment
comment|/* Dynamic Root of Trust for Measurement table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_FPDT
value|"FPDT"
end_define

begin_comment
comment|/* Firmware Performance Data Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_GTDT
value|"GTDT"
end_define

begin_comment
comment|/* Generic Timer Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MPST
value|"MPST"
end_define

begin_comment
comment|/* Memory Power State Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_PCCT
value|"PCCT"
end_define

begin_comment
comment|/* Platform Communications Channel Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_PMTT
value|"PMTT"
end_define

begin_comment
comment|/* Platform Memory Topology Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_RASF
value|"RASF"
end_define

begin_comment
comment|/* RAS Feature table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_STAO
value|"STAO"
end_define

begin_comment
comment|/* Status Override table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_WPBT
value|"WPBT"
end_define

begin_comment
comment|/* Windows Platform Binary Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_XENV
value|"XENV"
end_define

begin_comment
comment|/* Xen Environment table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_S3PT
value|"S3PT"
end_define

begin_comment
comment|/* S3 Performance (sub)Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_PCCS
value|"PCC"
end_define

begin_comment
comment|/* PCC Shared Memory Region */
end_comment

begin_comment
comment|/* Reserved table signatures */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MATR
value|"MATR"
end_define

begin_comment
comment|/* Memory Address Translation Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MSDM
value|"MSDM"
end_define

begin_comment
comment|/* Microsoft Data Management Table */
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
comment|/*  * Note: C bitfields are not used for this reason:  *  * "Bitfields are great and easy to read, but unfortunately the C language  * does not specify the layout of bitfields in memory, which means they are  * essentially useless for dealing with packed data in on-disk formats or  * binary wire protocols." (Or ACPI tables and buffers.) "If you ask me,  * this decision was a design error in C. Ritchie could have picked an order  * and stuck with it." Norman Ramsey.  * See http://stackoverflow.com/a/1053662/41661  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * BGRT - Boot Graphics Resource Table (ACPI 5.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_bgrt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT16
name|Version
decl_stmt|;
name|UINT8
name|Status
decl_stmt|;
name|UINT8
name|ImageType
decl_stmt|;
name|UINT64
name|ImageAddress
decl_stmt|;
name|UINT32
name|ImageOffsetX
decl_stmt|;
name|UINT32
name|ImageOffsetY
decl_stmt|;
block|}
name|ACPI_TABLE_BGRT
typedef|;
end_typedef

begin_comment
comment|/* Flags for Status field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_BGRT_DISPLAYED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_BGRT_ORIENTATION_OFFSET
value|(3<< 1)
end_define

begin_comment
comment|/*******************************************************************************  *  * DRTM - Dynamic Root of Trust for Measurement table  * Conforms to "TCG D-RTM Architecture" June 17 2013, Version 1.0.0  * Table version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_drtm
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|EntryBaseAddress
decl_stmt|;
name|UINT64
name|EntryLength
decl_stmt|;
name|UINT32
name|EntryAddress32
decl_stmt|;
name|UINT64
name|EntryAddress64
decl_stmt|;
name|UINT64
name|ExitAddress
decl_stmt|;
name|UINT64
name|LogAreaAddress
decl_stmt|;
name|UINT32
name|LogAreaLength
decl_stmt|;
name|UINT64
name|ArchDependentAddress
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_DRTM
typedef|;
end_typedef

begin_comment
comment|/* Flag Definitions for above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DRTM_ACCESS_ALLOWED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_DRTM_ENABLE_GAP_CODE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_DRTM_INCOMPLETE_MEASUREMENTS
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_DRTM_AUTHORITY_ORDER
value|(1<<3)
end_define

begin_comment
comment|/* 1) Validated Tables List (64-bit addresses) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_drtm_vtable_list
block|{
name|UINT32
name|ValidatedTableCount
decl_stmt|;
name|UINT64
name|ValidatedTables
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_DRTM_VTABLE_LIST
typedef|;
end_typedef

begin_comment
comment|/* 2) Resources List (of Resource Descriptors) */
end_comment

begin_comment
comment|/* Resource Descriptor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_drtm_resource
block|{
name|UINT8
name|Size
index|[
literal|7
index|]
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ACPI_DRTM_RESOURCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_drtm_resource_list
block|{
name|UINT32
name|ResourceCount
decl_stmt|;
name|ACPI_DRTM_RESOURCE
name|Resources
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_DRTM_RESOURCE_LIST
typedef|;
end_typedef

begin_comment
comment|/* 3) Platform-specific Identifiers List */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_drtm_dps_id
block|{
name|UINT32
name|DpsIdLength
decl_stmt|;
name|UINT8
name|DpsId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ACPI_DRTM_DPS_ID
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * FPDT - Firmware Performance Data Table (ACPI 5.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_fpdt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_FPDT
typedef|;
end_typedef

begin_comment
comment|/* FPDT subtable header (Performance Record Structure) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fpdt_header
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
block|}
name|ACPI_FPDT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_enum
enum|enum
name|AcpiFpdtType
block|{
name|ACPI_FPDT_TYPE_BOOT
init|=
literal|0
block|,
name|ACPI_FPDT_TYPE_S3PERF
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/*  * FPDT subtables  */
end_comment

begin_comment
comment|/* 0: Firmware Basic Boot Performance Record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fpdt_boot_pointer
block|{
name|ACPI_FPDT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ACPI_FPDT_BOOT_POINTER
typedef|;
end_typedef

begin_comment
comment|/* 1: S3 Performance Table Pointer Record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fpdt_s3pt_pointer
block|{
name|ACPI_FPDT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ACPI_FPDT_S3PT_POINTER
typedef|;
end_typedef

begin_comment
comment|/*  * S3PT - S3 Performance Table. This table is pointed to by the  * S3 Pointer Record above.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_s3pt
block|{
name|UINT8
name|Signature
index|[
literal|4
index|]
decl_stmt|;
comment|/* "S3PT" */
name|UINT32
name|Length
decl_stmt|;
block|}
name|ACPI_TABLE_S3PT
typedef|;
end_typedef

begin_comment
comment|/*  * S3PT Subtables (Not part of the actual FPDT)  */
end_comment

begin_comment
comment|/* Values for Type field in S3PT header */
end_comment

begin_enum
enum|enum
name|AcpiS3ptType
block|{
name|ACPI_S3PT_TYPE_RESUME
init|=
literal|0
block|,
name|ACPI_S3PT_TYPE_SUSPEND
init|=
literal|1
block|,
name|ACPI_FPDT_BOOT_PERFORMANCE
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|acpi_s3pt_resume
block|{
name|ACPI_FPDT_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ResumeCount
decl_stmt|;
name|UINT64
name|FullResume
decl_stmt|;
name|UINT64
name|AverageResume
decl_stmt|;
block|}
name|ACPI_S3PT_RESUME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_s3pt_suspend
block|{
name|ACPI_FPDT_HEADER
name|Header
decl_stmt|;
name|UINT64
name|SuspendStart
decl_stmt|;
name|UINT64
name|SuspendEnd
decl_stmt|;
block|}
name|ACPI_S3PT_SUSPEND
typedef|;
end_typedef

begin_comment
comment|/*  * FPDT Boot Performance Record (Not part of the actual FPDT)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fpdt_boot
block|{
name|ACPI_FPDT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
name|UINT64
name|ResetEnd
decl_stmt|;
name|UINT64
name|LoadStart
decl_stmt|;
name|UINT64
name|StartupStart
decl_stmt|;
name|UINT64
name|ExitServicesEntry
decl_stmt|;
name|UINT64
name|ExitServicesExit
decl_stmt|;
block|}
name|ACPI_FPDT_BOOT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * GTDT - Generic Timer Description Table (ACPI 5.1)  *        Version 2  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_gtdt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|CounterBlockAddresss
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|SecureEl1Interrupt
decl_stmt|;
name|UINT32
name|SecureEl1Flags
decl_stmt|;
name|UINT32
name|NonSecureEl1Interrupt
decl_stmt|;
name|UINT32
name|NonSecureEl1Flags
decl_stmt|;
name|UINT32
name|VirtualTimerInterrupt
decl_stmt|;
name|UINT32
name|VirtualTimerFlags
decl_stmt|;
name|UINT32
name|NonSecureEl2Interrupt
decl_stmt|;
name|UINT32
name|NonSecureEl2Flags
decl_stmt|;
name|UINT64
name|CounterReadBlockAddress
decl_stmt|;
name|UINT32
name|PlatformTimerCount
decl_stmt|;
name|UINT32
name|PlatformTimerOffset
decl_stmt|;
block|}
name|ACPI_TABLE_GTDT
typedef|;
end_typedef

begin_comment
comment|/* Flag Definitions: Timer Block Physical Timers and Virtual timers */
end_comment

begin_define
define|#
directive|define
name|ACPI_GTDT_INTERRUPT_MODE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_INTERRUPT_POLARITY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_ALWAYS_ON
value|(1<<2)
end_define

begin_comment
comment|/* Common GTDT subtable header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gtdt_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_GTDT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for GTDT subtable type above */
end_comment

begin_enum
enum|enum
name|AcpiGtdtType
block|{
name|ACPI_GTDT_TYPE_TIMER_BLOCK
init|=
literal|0
block|,
name|ACPI_GTDT_TYPE_WATCHDOG
init|=
literal|1
block|,
name|ACPI_GTDT_TYPE_RESERVED
init|=
literal|2
comment|/* 2 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* GTDT Subtables, correspond to Type in acpi_gtdt_header */
end_comment

begin_comment
comment|/* 0: Generic Timer Block */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gtdt_timer_block
block|{
name|ACPI_GTDT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|BlockAddress
decl_stmt|;
name|UINT32
name|TimerCount
decl_stmt|;
name|UINT32
name|TimerOffset
decl_stmt|;
block|}
name|ACPI_GTDT_TIMER_BLOCK
typedef|;
end_typedef

begin_comment
comment|/* Timer Sub-Structure, one per timer */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gtdt_timer_entry
block|{
name|UINT8
name|FrameNumber
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|El0BaseAddress
decl_stmt|;
name|UINT32
name|TimerInterrupt
decl_stmt|;
name|UINT32
name|TimerFlags
decl_stmt|;
name|UINT32
name|VirtualTimerInterrupt
decl_stmt|;
name|UINT32
name|VirtualTimerFlags
decl_stmt|;
name|UINT32
name|CommonFlags
decl_stmt|;
block|}
name|ACPI_GTDT_TIMER_ENTRY
typedef|;
end_typedef

begin_comment
comment|/* Flag Definitions: TimerFlags and VirtualTimerFlags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_GTDT_GT_IRQ_MODE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_GT_IRQ_POLARITY
value|(1<<1)
end_define

begin_comment
comment|/* Flag Definitions: CommonFlags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_GTDT_GT_IS_SECURE_TIMER
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_GT_ALWAYS_ON
value|(1<<1)
end_define

begin_comment
comment|/* 1: SBSA Generic Watchdog Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gtdt_watchdog
block|{
name|ACPI_GTDT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|RefreshFrameAddress
decl_stmt|;
name|UINT64
name|ControlFrameAddress
decl_stmt|;
name|UINT32
name|TimerInterrupt
decl_stmt|;
name|UINT32
name|TimerFlags
decl_stmt|;
block|}
name|ACPI_GTDT_WATCHDOG
typedef|;
end_typedef

begin_comment
comment|/* Flag Definitions: TimerFlags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_GTDT_WATCHDOG_IRQ_MODE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_WATCHDOG_IRQ_POLARITY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_GTDT_WATCHDOG_SECURE
value|(1<<2)
end_define

begin_comment
comment|/*******************************************************************************  *  * MPST - Memory Power State Table (ACPI 5.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACPI_MPST_CHANNEL_INFO
define|\
value|UINT8                   ChannelId; \     UINT8                   Reserved1[3]; \     UINT16                  PowerNodeCount; \     UINT16                  Reserved2;
end_define

begin_comment
comment|/* Main table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_mpst
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|ACPI_MPST_CHANNEL_INFO
comment|/* Platform Communication Channel */
block|}
name|ACPI_TABLE_MPST
typedef|;
end_typedef

begin_comment
comment|/* Memory Platform Communication Channel Info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_channel
block|{
name|ACPI_MPST_CHANNEL_INFO
comment|/* Platform Communication Channel */
block|}
name|ACPI_MPST_CHANNEL
typedef|;
end_typedef

begin_comment
comment|/* Memory Power Node Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_power_node
block|{
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|NodeId
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT64
name|RangeAddress
decl_stmt|;
name|UINT64
name|RangeLength
decl_stmt|;
name|UINT32
name|NumPowerStates
decl_stmt|;
name|UINT32
name|NumPhysicalComponents
decl_stmt|;
block|}
name|ACPI_MPST_POWER_NODE
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_MPST_ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MPST_POWER_MANAGED
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MPST_HOT_PLUG_CAPABLE
value|4
end_define

begin_comment
comment|/* Memory Power State Structure (follows POWER_NODE above) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_power_state
block|{
name|UINT8
name|PowerState
decl_stmt|;
name|UINT8
name|InfoIndex
decl_stmt|;
block|}
name|ACPI_MPST_POWER_STATE
typedef|;
end_typedef

begin_comment
comment|/* Physical Component ID Structure (follows POWER_STATE above) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_component
block|{
name|UINT16
name|ComponentId
decl_stmt|;
block|}
name|ACPI_MPST_COMPONENT
typedef|;
end_typedef

begin_comment
comment|/* Memory Power State Characteristics Structure (follows all POWER_NODEs) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_data_hdr
block|{
name|UINT16
name|CharacteristicsCount
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
block|}
name|ACPI_MPST_DATA_HDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_power_data
block|{
name|UINT8
name|StructureId
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT32
name|AveragePower
decl_stmt|;
name|UINT32
name|PowerSaving
decl_stmt|;
name|UINT64
name|ExitLatency
decl_stmt|;
name|UINT64
name|Reserved2
decl_stmt|;
block|}
name|ACPI_MPST_POWER_DATA
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_MPST_PRESERVE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MPST_AUTOENTRY
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MPST_AUTOEXIT
value|4
end_define

begin_comment
comment|/* Shared Memory Region (not part of an ACPI table) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mpst_shared
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT16
name|PccCommand
decl_stmt|;
name|UINT16
name|PccStatus
decl_stmt|;
name|UINT32
name|CommandRegister
decl_stmt|;
name|UINT32
name|StatusRegister
decl_stmt|;
name|UINT32
name|PowerStateId
decl_stmt|;
name|UINT32
name|PowerNodeId
decl_stmt|;
name|UINT64
name|EnergyConsumed
decl_stmt|;
name|UINT64
name|AveragePower
decl_stmt|;
block|}
name|ACPI_MPST_SHARED
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * PCCT - Platform Communications Channel Table (ACPI 5.0)  *        Version 2 (ACPI 6.2)  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_pcct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Flags
decl_stmt|;
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|ACPI_TABLE_PCCT
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PCCT_DOORBELL
value|1
end_define

begin_comment
comment|/* Values for subtable type in ACPI_SUBTABLE_HEADER */
end_comment

begin_enum
enum|enum
name|AcpiPcctType
block|{
name|ACPI_PCCT_TYPE_GENERIC_SUBSPACE
init|=
literal|0
block|,
name|ACPI_PCCT_TYPE_HW_REDUCED_SUBSPACE
init|=
literal|1
block|,
name|ACPI_PCCT_TYPE_HW_REDUCED_SUBSPACE_TYPE2
init|=
literal|2
block|,
comment|/* ACPI 6.1 */
name|ACPI_PCCT_TYPE_EXT_PCC_MASTER_SUBSPACE
init|=
literal|3
block|,
comment|/* ACPI 6.2 */
name|ACPI_PCCT_TYPE_EXT_PCC_SLAVE_SUBSPACE
init|=
literal|4
block|,
comment|/* ACPI 6.2 */
name|ACPI_PCCT_TYPE_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * PCCT Subtables, correspond to Type in ACPI_SUBTABLE_HEADER  */
end_comment

begin_comment
comment|/* 0: Generic Communications Subspace */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_subspace
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|PreserveMask
decl_stmt|;
name|UINT64
name|WriteMask
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|UINT32
name|MaxAccessRate
decl_stmt|;
name|UINT16
name|MinTurnaroundTime
decl_stmt|;
block|}
name|ACPI_PCCT_SUBSPACE
typedef|;
end_typedef

begin_comment
comment|/* 1: HW-reduced Communications Subspace (ACPI 5.1) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_hw_reduced
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|PlatformInterrupt
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|PreserveMask
decl_stmt|;
name|UINT64
name|WriteMask
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|UINT32
name|MaxAccessRate
decl_stmt|;
name|UINT16
name|MinTurnaroundTime
decl_stmt|;
block|}
name|ACPI_PCCT_HW_REDUCED
typedef|;
end_typedef

begin_comment
comment|/* 2: HW-reduced Communications Subspace Type 2 (ACPI 6.1) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_hw_reduced_type2
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|PlatformInterrupt
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|PreserveMask
decl_stmt|;
name|UINT64
name|WriteMask
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|UINT32
name|MaxAccessRate
decl_stmt|;
name|UINT16
name|MinTurnaroundTime
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|PlatformAckRegister
decl_stmt|;
name|UINT64
name|AckPreserveMask
decl_stmt|;
name|UINT64
name|AckWriteMask
decl_stmt|;
block|}
name|ACPI_PCCT_HW_REDUCED_TYPE2
typedef|;
end_typedef

begin_comment
comment|/* 3: Extended PCC Master Subspace Type 3 (ACPI 6.2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_ext_pcc_master
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|PlatformInterrupt
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|PreserveMask
decl_stmt|;
name|UINT64
name|WriteMask
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|UINT32
name|MaxAccessRate
decl_stmt|;
name|UINT32
name|MinTurnaroundTime
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|PlatformAckRegister
decl_stmt|;
name|UINT64
name|AckPreserveMask
decl_stmt|;
name|UINT64
name|AckSetMask
decl_stmt|;
name|UINT64
name|Reserved2
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|CmdCompleteRegister
decl_stmt|;
name|UINT64
name|CmdCompleteMask
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|CmdUpdateRegister
decl_stmt|;
name|UINT64
name|CmdUpdatePreserveMask
decl_stmt|;
name|UINT64
name|CmdUpdateSetMask
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ErrorStatusRegister
decl_stmt|;
name|UINT64
name|ErrorStatusMask
decl_stmt|;
block|}
name|ACPI_PCCT_EXT_PCC_MASTER
typedef|;
end_typedef

begin_comment
comment|/* 4: Extended PCC Slave Subspace Type 4 (ACPI 6.2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_ext_pcc_slave
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|PlatformInterrupt
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|DoorbellRegister
decl_stmt|;
name|UINT64
name|PreserveMask
decl_stmt|;
name|UINT64
name|WriteMask
decl_stmt|;
name|UINT32
name|Latency
decl_stmt|;
name|UINT32
name|MaxAccessRate
decl_stmt|;
name|UINT32
name|MinTurnaroundTime
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|PlatformAckRegister
decl_stmt|;
name|UINT64
name|AckPreserveMask
decl_stmt|;
name|UINT64
name|AckSetMask
decl_stmt|;
name|UINT64
name|Reserved2
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|CmdCompleteRegister
decl_stmt|;
name|UINT64
name|CmdCompleteMask
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|CmdUpdateRegister
decl_stmt|;
name|UINT64
name|CmdUpdatePreserveMask
decl_stmt|;
name|UINT64
name|CmdUpdateSetMask
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|ErrorStatusRegister
decl_stmt|;
name|UINT64
name|ErrorStatusMask
decl_stmt|;
block|}
name|ACPI_PCCT_EXT_PCC_SLAVE
typedef|;
end_typedef

begin_comment
comment|/* Values for doorbell flags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PCCT_INTERRUPT_POLARITY
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_PCCT_INTERRUPT_MODE
value|(1<<1)
end_define

begin_comment
comment|/*  * PCC memory structures (not part of the ACPI table)  */
end_comment

begin_comment
comment|/* Shared Memory Region */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_shared_memory
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT16
name|Command
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
block|}
name|ACPI_PCCT_SHARED_MEMORY
typedef|;
end_typedef

begin_comment
comment|/* Extended PCC Subspace Shared Memory Region (ACPI 6.2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pcct_ext_pcc_shared_memory
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|Command
decl_stmt|;
block|}
name|ACPI_PCCT_EXT_PCC_SHARED_MEMORY
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * PMTT - Platform Memory Topology Table (ACPI 5.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_pmtt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|ACPI_TABLE_PMTT
typedef|;
end_typedef

begin_comment
comment|/* Common header for PMTT subtables that follow main table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pmtt_header
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
block|}
name|ACPI_PMTT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PMTT_TYPE_SOCKET
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_PMTT_TYPE_CONTROLLER
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_PMTT_TYPE_DIMM
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_PMTT_TYPE_RESERVED
value|3
end_define

begin_comment
comment|/* 0x03-0xFF are reserved */
end_comment

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PMTT_TOP_LEVEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_PMTT_PHYSICAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_PMTT_MEMORY_TYPE
value|0x000C
end_define

begin_comment
comment|/*  * PMTT subtables, correspond to Type in acpi_pmtt_header  */
end_comment

begin_comment
comment|/* 0: Socket Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pmtt_socket
block|{
name|ACPI_PMTT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|SocketId
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
block|}
name|ACPI_PMTT_SOCKET
typedef|;
end_typedef

begin_comment
comment|/* 1: Memory Controller subtable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pmtt_controller
block|{
name|ACPI_PMTT_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ReadLatency
decl_stmt|;
name|UINT32
name|WriteLatency
decl_stmt|;
name|UINT32
name|ReadBandwidth
decl_stmt|;
name|UINT32
name|WriteBandwidth
decl_stmt|;
name|UINT16
name|AccessWidth
decl_stmt|;
name|UINT16
name|Alignment
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT16
name|DomainCount
decl_stmt|;
block|}
name|ACPI_PMTT_CONTROLLER
typedef|;
end_typedef

begin_comment
comment|/* 1a: Proximity Domain substructure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pmtt_domain
block|{
name|UINT32
name|ProximityDomain
decl_stmt|;
block|}
name|ACPI_PMTT_DOMAIN
typedef|;
end_typedef

begin_comment
comment|/* 2: Physical Component Identifier (DIMM) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pmtt_physical_component
block|{
name|ACPI_PMTT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|ComponentId
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|MemorySize
decl_stmt|;
name|UINT32
name|BiosHandle
decl_stmt|;
block|}
name|ACPI_PMTT_PHYSICAL_COMPONENT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * RASF - RAS Feature Table (ACPI 5.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_rasf
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|ChannelId
index|[
literal|12
index|]
decl_stmt|;
block|}
name|ACPI_TABLE_RASF
typedef|;
end_typedef

begin_comment
comment|/* RASF Platform Communication Channel Shared Memory Region */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_rasf_shared_memory
block|{
name|UINT32
name|Signature
decl_stmt|;
name|UINT16
name|Command
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
name|UINT16
name|Version
decl_stmt|;
name|UINT8
name|Capabilities
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|SetCapabilities
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|NumParameterBlocks
decl_stmt|;
name|UINT32
name|SetCapabilitiesStatus
decl_stmt|;
block|}
name|ACPI_RASF_SHARED_MEMORY
typedef|;
end_typedef

begin_comment
comment|/* RASF Parameter Block Structure Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_rasf_parameter_block
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Version
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_RASF_PARAMETER_BLOCK
typedef|;
end_typedef

begin_comment
comment|/* RASF Parameter Block Structure for PATROL_SCRUB */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_rasf_patrol_scrub_parameter
block|{
name|ACPI_RASF_PARAMETER_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|PatrolScrubCommand
decl_stmt|;
name|UINT64
name|RequestedAddressRange
index|[
literal|2
index|]
decl_stmt|;
name|UINT64
name|ActualAddressRange
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|RequestedSpeed
decl_stmt|;
block|}
name|ACPI_RASF_PATROL_SCRUB_PARAMETER
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags and Speed fields above */
end_comment

begin_define
define|#
directive|define
name|ACPI_RASF_SCRUBBER_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_SPEED
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_SPEED_SLOW
value|(0<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_SPEED_MEDIUM
value|(4<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_SPEED_FAST
value|(7<<1)
end_define

begin_comment
comment|/* Channel Commands */
end_comment

begin_enum
enum|enum
name|AcpiRasfCommands
block|{
name|ACPI_RASF_EXECUTE_RASF_COMMAND
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* Platform RAS Capabilities */
end_comment

begin_enum
enum|enum
name|AcpiRasfCapabiliities
block|{
name|ACPI_HW_PATROL_SCRUB_SUPPORTED
init|=
literal|0
block|,
name|ACPI_SW_PATROL_SCRUB_EXPOSED
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* Patrol Scrub Commands */
end_comment

begin_enum
enum|enum
name|AcpiRasfPatrolScrubCommands
block|{
name|ACPI_RASF_GET_PATROL_PARAMETERS
init|=
literal|1
block|,
name|ACPI_RASF_START_PATROL_SCRUBBER
init|=
literal|2
block|,
name|ACPI_RASF_STOP_PATROL_SCRUBBER
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* Channel Command flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_RASF_GENERATE_SCI
value|(1<<15)
end_define

begin_comment
comment|/* Status values */
end_comment

begin_enum
enum|enum
name|AcpiRasfStatus
block|{
name|ACPI_RASF_SUCCESS
init|=
literal|0
block|,
name|ACPI_RASF_NOT_VALID
init|=
literal|1
block|,
name|ACPI_RASF_NOT_SUPPORTED
init|=
literal|2
block|,
name|ACPI_RASF_BUSY
init|=
literal|3
block|,
name|ACPI_RASF_FAILED
init|=
literal|4
block|,
name|ACPI_RASF_ABORTED
init|=
literal|5
block|,
name|ACPI_RASF_INVALID_DATA
init|=
literal|6
block|}
enum|;
end_enum

begin_comment
comment|/* Status flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_RASF_COMMAND_COMPLETE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_SCI_DOORBELL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_ERROR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_RASF_STATUS
value|(0x1F<<3)
end_define

begin_comment
comment|/*******************************************************************************  *  * STAO - Status Override Table (_STA override) - ACPI 6.0  *        Version 1  *  * Conforms to "ACPI Specification for Status Override Table"  * 6 January 2015  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_stao
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT8
name|IgnoreUart
decl_stmt|;
block|}
name|ACPI_TABLE_STAO
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * WPBT - Windows Platform Environment Table (ACPI 6.0)  *        Version 1  *  * Conforms to "Windows Platform Binary Table (WPBT)" 29 November 2011  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_wpbt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|HandoffSize
decl_stmt|;
name|UINT64
name|HandoffAddress
decl_stmt|;
name|UINT8
name|Layout
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT16
name|ArgumentsLength
decl_stmt|;
block|}
name|ACPI_TABLE_WPBT
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * XENV - Xen Environment Table (ACPI 6.0)  *        Version 1  *  * Conforms to "ACPI Specification for Xen Environment Table" 4 January 2015  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_xenv
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT64
name|GrantTableAddress
decl_stmt|;
name|UINT64
name|GrantTableSize
decl_stmt|;
name|UINT32
name|EventInterrupt
decl_stmt|;
name|UINT8
name|EventFlags
decl_stmt|;
block|}
name|ACPI_TABLE_XENV
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
comment|/* __ACTBL3_H__ */
end_comment

end_unit

