begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl1.h - Additional ACPI table definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*******************************************************************************  *  * Additional ACPI Tables (1)  *  * These tables are not consumed directly by the ACPICA subsystem, but are  * included here to support device drivers and the AML disassembler.  *  * The tables in this file are fully defined within the ACPI specification.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Values for description table header signatures for tables defined in this  * file. Useful because they make it more difficult to inadvertently type in  * the wrong signature.  */
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
name|ACPI_SIG_CPEP
value|"CPEP"
end_define

begin_comment
comment|/* Corrected Platform Error Polling table */
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
name|ACPI_SIG_MADT
value|"APIC"
end_define

begin_comment
comment|/* Multiple APIC Description Table */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIG_MSCT
value|"MSCT"
end_define

begin_comment
comment|/* Maximum System Characteristics Table */
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
name|ACPI_SIG_SLIT
value|"SLIT"
end_define

begin_comment
comment|/* System Locality Distance Information Table */
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
comment|/*******************************************************************************  *  * Common subtable headers  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Generic subtable header (used in MADT, SRAT, etc.) */
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
comment|/* Subtable header for WHEA tables (EINJ, ERST, WDAT) */
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
comment|/*******************************************************************************  *  * BERT - Boot Error Record Table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
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
comment|/* Physical address of the error region */
block|}
name|ACPI_TABLE_BERT
typedef|;
end_typedef

begin_comment
comment|/* Boot Error Region (not a subtable, pointed to by Address field above) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_bert_region
block|{
name|UINT32
name|BlockStatus
decl_stmt|;
comment|/* Type of error information */
name|UINT32
name|RawDataOffset
decl_stmt|;
comment|/* Offset to raw error data */
name|UINT32
name|RawDataLength
decl_stmt|;
comment|/* Length of raw error data */
name|UINT32
name|DataLength
decl_stmt|;
comment|/* Length of generic error data */
name|UINT32
name|ErrorSeverity
decl_stmt|;
comment|/* Severity code */
block|}
name|ACPI_BERT_REGION
typedef|;
end_typedef

begin_comment
comment|/* Values for BlockStatus flags above */
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
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_MULTIPLE_UNCORRECTABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_MULTIPLE_CORRECTABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_BERT_ERROR_ENTRY_COUNT
value|(0xFF<<4)
end_define

begin_comment
comment|/* 8 bits, error count */
end_comment

begin_comment
comment|/* Values for ErrorSeverity above */
end_comment

begin_enum
enum|enum
name|AcpiBertErrorSeverity
block|{
name|ACPI_BERT_ERROR_CORRECTABLE
init|=
literal|0
block|,
name|ACPI_BERT_ERROR_FATAL
init|=
literal|1
block|,
name|ACPI_BERT_ERROR_CORRECTED
init|=
literal|2
block|,
name|ACPI_BERT_ERROR_NONE
init|=
literal|3
block|,
name|ACPI_BERT_ERROR_RESERVED
init|=
literal|4
comment|/* 4 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Note: The generic error data that follows the ErrorSeverity field above  * uses the ACPI_HEST_GENERIC_DATA defined under the HEST table below  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * CPEP - Corrected Platform Error Polling table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
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
name|ACPI_SUBTABLE_HEADER
name|Header
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
comment|/*******************************************************************************  *  * ECDT - Embedded Controller Boot Resources Table  *        Version 1  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * EINJ - Error Injection Table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
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
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_EINJ_PRESERVE
value|(1)
end_define

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
name|ACPI_EINJ_SET_ERROR_TYPE_WITH_ADDRESS
init|=
literal|8
block|,
name|ACPI_EINJ_ACTION_RESERVED
init|=
literal|9
block|,
comment|/* 9 and greater are reserved */
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
name|ACPI_EINJ_FLUSH_CACHELINE
init|=
literal|5
block|,
name|ACPI_EINJ_INSTRUCTION_RESERVED
init|=
literal|6
comment|/* 6 and greater are reserved */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|acpi_einj_error_type_with_addr
block|{
name|UINT32
name|ErrorType
decl_stmt|;
name|UINT32
name|VendorStructOffset
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ApicId
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
name|UINT64
name|Range
decl_stmt|;
name|UINT32
name|PcieId
decl_stmt|;
block|}
name|ACPI_EINJ_ERROR_TYPE_WITH_ADDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_einj_vendor
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|PcieId
decl_stmt|;
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_EINJ_VENDOR
typedef|;
end_typedef

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
comment|/* Command status return values */
end_comment

begin_enum
enum|enum
name|AcpiEinjCommandStatus
block|{
name|ACPI_EINJ_SUCCESS
init|=
literal|0
block|,
name|ACPI_EINJ_FAILURE
init|=
literal|1
block|,
name|ACPI_EINJ_INVALID_ACCESS
init|=
literal|2
block|,
name|ACPI_EINJ_STATUS_RESERVED
init|=
literal|3
comment|/* 3 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* Error types returned from ACPI_EINJ_GET_ERROR_TYPE (bitfield) */
end_comment

begin_define
define|#
directive|define
name|ACPI_EINJ_PROCESSOR_CORRECTABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PROCESSOR_UNCORRECTABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PROCESSOR_FATAL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_MEMORY_CORRECTABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_MEMORY_UNCORRECTABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_MEMORY_FATAL
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PCIX_CORRECTABLE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PCIX_UNCORRECTABLE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PCIX_FATAL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PLATFORM_CORRECTABLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PLATFORM_UNCORRECTABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_PLATFORM_FATAL
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|ACPI_EINJ_VENDOR_DEFINED
value|(1<<31)
end_define

begin_comment
comment|/*******************************************************************************  *  * ERST - Error Record Serialization Table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
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
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_ERST_PRESERVE
value|(1)
end_define

begin_comment
comment|/* Values for Action field above */
end_comment

begin_enum
enum|enum
name|AcpiErstActions
block|{
name|ACPI_ERST_BEGIN_WRITE
init|=
literal|0
block|,
name|ACPI_ERST_BEGIN_READ
init|=
literal|1
block|,
name|ACPI_ERST_BEGIN_CLEAR
init|=
literal|2
block|,
name|ACPI_ERST_END
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
name|ACPI_ERST_GET_RECORD_ID
init|=
literal|8
block|,
name|ACPI_ERST_SET_RECORD_ID
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
comment|/* Command status return values */
end_comment

begin_enum
enum|enum
name|AcpiErstCommandStatus
block|{
name|ACPI_ERST_SUCESS
init|=
literal|0
block|,
name|ACPI_ERST_NO_SPACE
init|=
literal|1
block|,
name|ACPI_ERST_NOT_AVAILABLE
init|=
literal|2
block|,
name|ACPI_ERST_FAILURE
init|=
literal|3
block|,
name|ACPI_ERST_RECORD_EMPTY
init|=
literal|4
block|,
name|ACPI_ERST_NOT_FOUND
init|=
literal|5
block|,
name|ACPI_ERST_STATUS_RESERVED
init|=
literal|6
comment|/* 6 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* Error Record Serialization Information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_erst_info
block|{
name|UINT16
name|Signature
decl_stmt|;
comment|/* Should be "ER" */
name|UINT8
name|Data
index|[
literal|48
index|]
decl_stmt|;
block|}
name|ACPI_ERST_INFO
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * HEST - Hardware Error Source Table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
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
name|UINT16
name|SourceId
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
name|ACPI_HEST_TYPE_IA32_CHECK
init|=
literal|0
block|,
name|ACPI_HEST_TYPE_IA32_CORRECTED_CHECK
init|=
literal|1
block|,
name|ACPI_HEST_TYPE_IA32_NMI
init|=
literal|2
block|,
name|ACPI_HEST_TYPE_NOT_USED3
init|=
literal|3
block|,
name|ACPI_HEST_TYPE_NOT_USED4
init|=
literal|4
block|,
name|ACPI_HEST_TYPE_NOT_USED5
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
name|ACPI_HEST_TYPE_GENERIC_ERROR
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
comment|/*  * HEST substructures contained in subtables  */
end_comment

begin_comment
comment|/*  * IA32 Error Bank(s) - Follows the ACPI_HEST_IA_MACHINE_CHECK and  * ACPI_HEST_IA_CORRECTED structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ia_error_bank
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
name|Reserved
decl_stmt|;
name|UINT32
name|ControlRegister
decl_stmt|;
name|UINT64
name|ControlData
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
name|ACPI_HEST_IA_ERROR_BANK
typedef|;
end_typedef

begin_comment
comment|/* Common HEST sub-structure for PCI/AER structures below (6,7,8) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_aer_common
block|{
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreallocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|Bus
decl_stmt|;
comment|/* Bus and Segment numbers */
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
name|Reserved2
decl_stmt|;
name|UINT32
name|UncorrectableMask
decl_stmt|;
name|UINT32
name|UncorrectableSeverity
decl_stmt|;
name|UINT32
name|CorrectableMask
decl_stmt|;
name|UINT32
name|AdvancedCapabilities
decl_stmt|;
block|}
name|ACPI_HEST_AER_COMMON
typedef|;
end_typedef

begin_comment
comment|/* Masks for HEST Flags fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_FIRMWARE_FIRST
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GLOBAL
value|(1<<1)
end_define

begin_comment
comment|/*  * Macros to access the bus/segment numbers in Bus field above:  *  Bus number is encoded in bits 7:0  *  Segment number is encoded in bits 23:8  */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_BUS
parameter_list|(
name|Bus
parameter_list|)
value|((Bus)& 0xFF)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_SEGMENT
parameter_list|(
name|Bus
parameter_list|)
value|(((Bus)>> 8)& 0xFFFF)
end_define

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
name|ACPI_HEST_NOTIFY_CMCI
init|=
literal|5
block|,
comment|/* ACPI 5.0 */
name|ACPI_HEST_NOTIFY_MCE
init|=
literal|6
block|,
comment|/* ACPI 5.0 */
name|ACPI_HEST_NOTIFY_RESERVED
init|=
literal|7
comment|/* 7 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/* Values for ConfigWriteEnable bitfield above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_TYPE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_POLL_INTERVAL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_POLL_THRESHOLD_VALUE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_POLL_THRESHOLD_WINDOW
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_ERR_THRESHOLD_VALUE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_ERR_THRESHOLD_WINDOW
value|(1<<5)
end_define

begin_comment
comment|/*  * HEST subtables  */
end_comment

begin_comment
comment|/* 0: IA32 Machine Check Exception */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ia_machine_check
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreallocate
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
name|Reserved3
index|[
literal|7
index|]
decl_stmt|;
block|}
name|ACPI_HEST_IA_MACHINE_CHECK
typedef|;
end_typedef

begin_comment
comment|/* 1: IA32 Corrected Machine Check */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ia_corrected
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreallocate
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
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_HEST_IA_CORRECTED
typedef|;
end_typedef

begin_comment
comment|/* 2: IA32 Non-Maskable Interrupt */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ia_nmi
block|{
name|ACPI_HEST_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT32
name|RecordsToPreallocate
decl_stmt|;
name|UINT32
name|MaxSectionsPerRecord
decl_stmt|;
name|UINT32
name|MaxRawDataLength
decl_stmt|;
block|}
name|ACPI_HEST_IA_NMI
typedef|;
end_typedef

begin_comment
comment|/* 3,4,5: Not used */
end_comment

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
name|UncorrectableMask2
decl_stmt|;
name|UINT32
name|UncorrectableSeverity2
decl_stmt|;
name|UINT32
name|AdvancedCapabilities2
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
name|RelatedSourceId
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT8
name|Enabled
decl_stmt|;
name|UINT32
name|RecordsToPreallocate
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
name|ErrorBlockLength
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC
typedef|;
end_typedef

begin_comment
comment|/* Generic Error Status block */
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
comment|/* Values for BlockStatus flags above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_UNCORRECTABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_CORRECTABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_MULTIPLE_UNCORRECTABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_MULTIPLE_CORRECTABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_ERROR_ENTRY_COUNT
value|(0xFF<<4)
end_define

begin_comment
comment|/* 8 bits, error count */
end_comment

begin_comment
comment|/* Generic Error Data entry */
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
comment|/*******************************************************************************  *  * MADT - Multiple APIC Description Table  *        Version 3  *  ******************************************************************************/
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
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_PCAT_COMPAT
value|(1)
end_define

begin_comment
comment|/* 00: System also has dual 8259s */
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
comment|/* Values for MADT subtable type in ACPI_SUBTABLE_HEADER */
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
name|ACPI_MADT_TYPE_GENERIC_INTERRUPT
init|=
literal|11
block|,
name|ACPI_MADT_TYPE_GENERIC_DISTRIBUTOR
init|=
literal|12
block|,
name|ACPI_MADT_TYPE_GENERIC_MSI_FRAME
init|=
literal|13
block|,
name|ACPI_MADT_TYPE_GENERIC_REDISTRIBUTOR
init|=
literal|14
block|,
name|ACPI_MADT_TYPE_RESERVED
init|=
literal|15
comment|/* 15 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * MADT Subtables, correspond to Type in ACPI_SUBTABLE_HEADER  */
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
comment|/* Masks for Flags field above */
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
comment|/* 11: Generic Interrupt (ACPI 5.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_generic_interrupt
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|CpuInterfaceNumber
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ParkingVersion
decl_stmt|;
name|UINT32
name|PerformanceInterrupt
decl_stmt|;
name|UINT64
name|ParkedAddress
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT64
name|GicvBaseAddress
decl_stmt|;
name|UINT64
name|GichBaseAddress
decl_stmt|;
name|UINT32
name|VgicInterrupt
decl_stmt|;
name|UINT64
name|GicrBaseAddress
decl_stmt|;
name|UINT64
name|ArmMpidr
decl_stmt|;
block|}
name|ACPI_MADT_GENERIC_INTERRUPT
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_comment
comment|/* ACPI_MADT_ENABLED                    (1)      Processor is usable if set */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_PERFORMANCE_IRQ_MODE
value|(1<<1)
end_define

begin_comment
comment|/* 01: Performance Interrupt Mode */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_VGIC_IRQ_MODE
value|(1<<2)
end_define

begin_comment
comment|/* 02: VGIC Maintenance Interrupt mode */
end_comment

begin_comment
comment|/* 12: Generic Distributor (ACPI 5.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_generic_distributor
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|GicId
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|GlobalIrqBase
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
comment|/* Reserved - must be zero */
block|}
name|ACPI_MADT_GENERIC_DISTRIBUTOR
typedef|;
end_typedef

begin_comment
comment|/* 13: Generic MSI Frame (ACPI 5.1) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_generic_msi_frame
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|MsiFrameId
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT16
name|SpiCount
decl_stmt|;
name|UINT16
name|SpiBase
decl_stmt|;
block|}
name|ACPI_MADT_GENERIC_MSI_FRAME
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_MADT_OVERRIDE_SPI_VALUES
value|(1)
end_define

begin_comment
comment|/* 14: Generic Redistributor (ACPI 5.1) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_generic_redistributor
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* reserved - must be zero */
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|ACPI_MADT_GENERIC_REDISTRIBUTOR
typedef|;
end_typedef

begin_comment
comment|/*  * Common flags fields for MADT subtables  */
end_comment

begin_comment
comment|/* MADT Local APIC flags */
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
comment|/*******************************************************************************  *  * MSCT - Maximum System Characteristics Table (ACPI 4.0)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_msct
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|ProximityOffset
decl_stmt|;
comment|/* Location of proximity info struct(s) */
name|UINT32
name|MaxProximityDomains
decl_stmt|;
comment|/* Max number of proximity domains */
name|UINT32
name|MaxClockDomains
decl_stmt|;
comment|/* Max number of clock domains */
name|UINT64
name|MaxAddress
decl_stmt|;
comment|/* Max physical address in system */
block|}
name|ACPI_TABLE_MSCT
typedef|;
end_typedef

begin_comment
comment|/* Subtable - Maximum Proximity Domain Information. Version 1 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_msct_proximity
block|{
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT32
name|RangeStart
decl_stmt|;
comment|/* Start of domain range */
name|UINT32
name|RangeEnd
decl_stmt|;
comment|/* End of domain range */
name|UINT32
name|ProcessorCapacity
decl_stmt|;
name|UINT64
name|MemoryCapacity
decl_stmt|;
comment|/* In bytes */
block|}
name|ACPI_MSCT_PROXIMITY
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * SBST - Smart Battery Specification Table  *        Version 1  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * SLIT - System Locality Distance Information Table  *        Version 1  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * SRAT - System Resource Affinity Table  *        Version 3  *  ******************************************************************************/
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
name|ACPI_SRAT_TYPE_GICC_AFFINITY
init|=
literal|3
block|,
name|ACPI_SRAT_TYPE_RESERVED
init|=
literal|4
comment|/* 4 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * SRAT Subtables, correspond to Type in ACPI_SUBTABLE_HEADER  */
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
name|ClockDomain
decl_stmt|;
block|}
name|ACPI_SRAT_CPU_AFFINITY
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_CPU_USE_AFFINITY
value|(1)
end_define

begin_comment
comment|/* 00: Use affinity structure */
end_comment

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
comment|/* 3: GICC Affinity (ACPI 5.1) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_srat_gicc_affinity
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT32
name|AcpiProcessorUid
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|ClockDomain
decl_stmt|;
block|}
name|ACPI_SRAT_GICC_AFFINITY
typedef|;
end_typedef

begin_comment
comment|/* Flags for ACPI_SRAT_GICC_AFFINITY */
end_comment

begin_define
define|#
directive|define
name|ACPI_SRAT_GICC_ENABLED
value|(1)
end_define

begin_comment
comment|/* 00: Use affinity structure */
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

