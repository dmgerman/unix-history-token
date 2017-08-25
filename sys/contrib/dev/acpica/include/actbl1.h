begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl1.h - Additional ACPI table definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
name|ACPI_SIG_HMAT
value|"HMAT"
end_define

begin_comment
comment|/* Heterogeneous Memory Attributes Table */
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
name|ACPI_SIG_PPTT
value|"PPTT"
end_define

begin_comment
comment|/* Processor Properties Topology Table */
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

begin_define
define|#
directive|define
name|ACPI_SIG_NFIT
value|"NFIT"
end_define

begin_comment
comment|/* NVDIMM Firmware Interface Table */
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
name|ACPI_EINJ_GET_EXECUTE_TIMINGS
init|=
literal|9
block|,
name|ACPI_EINJ_ACTION_RESERVED
init|=
literal|10
block|,
comment|/* 10 and greater are reserved */
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
name|ACPI_ERST_EXECUTE_TIMINGS
init|=
literal|16
block|,
name|ACPI_ERST_ACTION_RESERVED
init|=
literal|17
comment|/* 17 and greater are reserved */
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
name|ACPI_HEST_TYPE_GENERIC_ERROR_V2
init|=
literal|10
block|,
name|ACPI_HEST_TYPE_IA32_DEFERRED_CHECK
init|=
literal|11
block|,
name|ACPI_HEST_TYPE_RESERVED
init|=
literal|12
comment|/* 12 and greater are reserved */
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

begin_define
define|#
directive|define
name|ACPI_HEST_GHES_ASSIST
value|(1<<2)
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
name|ACPI_HEST_NOTIFY_GPIO
init|=
literal|7
block|,
comment|/* ACPI 6.0 */
name|ACPI_HEST_NOTIFY_SEA
init|=
literal|8
block|,
comment|/* ACPI 6.1 */
name|ACPI_HEST_NOTIFY_SEI
init|=
literal|9
block|,
comment|/* ACPI 6.1 */
name|ACPI_HEST_NOTIFY_GSIV
init|=
literal|10
block|,
comment|/* ACPI 6.1 */
name|ACPI_HEST_NOTIFY_SOFTWARE_DELEGATED
init|=
literal|11
block|,
comment|/* ACPI 6.2 */
name|ACPI_HEST_NOTIFY_RESERVED
init|=
literal|12
comment|/* 12 and greater are reserved */
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
comment|/* See flags ACPI_HEST_GLOBAL, etc. above */
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
comment|/* See flags ACPI_HEST_GLOBAL, etc. above */
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
comment|/* 10: Generic Hardware Error Source, version 2 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_generic_v2
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
name|ACPI_GENERIC_ADDRESS
name|ReadAckRegister
decl_stmt|;
name|UINT64
name|ReadAckPreserve
decl_stmt|;
name|UINT64
name|ReadAckWrite
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC_V2
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
comment|/* Extension for revision 0x0300 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_generic_data_v300
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
name|UINT64
name|TimeStamp
decl_stmt|;
block|}
name|ACPI_HEST_GENERIC_DATA_V300
typedef|;
end_typedef

begin_comment
comment|/* Values for ErrorSeverity above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_ERROR_RECOVERABLE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_ERROR_FATAL
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_ERROR_CORRECTED
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_ERROR_NONE
value|3
end_define

begin_comment
comment|/* Flags for ValidationBits above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_VALID_FRU_ID
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_VALID_FRU_STRING
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ACPI_HEST_GEN_VALID_TIMESTAMP
value|(1<<2)
end_define

begin_comment
comment|/* 11: IA32 Deferred Machine Check Exception (ACPI 6.2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hest_ia_deferred_check
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
comment|/* See flags ACPI_HEST_GLOBAL, etc. above */
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
name|ACPI_HEST_IA_DEFERRED_CHECK
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * HMAT - Heterogeneous Memory Attributes Table (ACPI 6.2)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_hmat
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|ACPI_TABLE_HMAT
typedef|;
end_typedef

begin_comment
comment|/* Values for HMAT structure types */
end_comment

begin_enum
enum|enum
name|AcpiHmatType
block|{
name|ACPI_HMAT_TYPE_ADDRESS_RANGE
init|=
literal|0
block|,
comment|/* Memory subystem address range */
name|ACPI_HMAT_TYPE_LOCALITY
init|=
literal|1
block|,
comment|/* System locality latency and bandwidth information */
name|ACPI_HMAT_TYPE_CACHE
init|=
literal|2
block|,
comment|/* Memory side cache information */
name|ACPI_HMAT_TYPE_RESERVED
init|=
literal|3
comment|/* 3 and greater are reserved */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|acpi_hmat_structure
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|ACPI_HMAT_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|/*  * HMAT Structures, correspond to Type in ACPI_HMAT_STRUCTURE  */
end_comment

begin_comment
comment|/* 0: Memory subystem address range */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hmat_address_range
block|{
name|ACPI_HMAT_STRUCTURE
name|Header
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT32
name|ProcessorPD
decl_stmt|;
comment|/* Processor proximity domain */
name|UINT32
name|MemoryPD
decl_stmt|;
comment|/* Memory proximity domain */
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT64
name|PhysicalAddressBase
decl_stmt|;
comment|/* Physical address range base */
name|UINT64
name|PhysicalAddressLength
decl_stmt|;
comment|/* Physical address range length */
block|}
name|ACPI_HMAT_ADDRESS_RANGE
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_PROCESSOR_PD_VALID
value|(1)
end_define

begin_comment
comment|/* 1: ProcessorPD field is valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_MEMORY_PD_VALID
value|(1<<1)
end_define

begin_comment
comment|/* 1: MemoryPD field is valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_RESERVATION_HINT
value|(1<<2)
end_define

begin_comment
comment|/* 1: Reservation hint */
end_comment

begin_comment
comment|/* 1: System locality latency and bandwidth information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hmat_locality
block|{
name|ACPI_HMAT_STRUCTURE
name|Header
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|DataType
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT32
name|NumberOfInitiatorPDs
decl_stmt|;
name|UINT32
name|NumberOfTargetPDs
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT64
name|EntryBaseUnit
decl_stmt|;
block|}
name|ACPI_HMAT_LOCALITY
typedef|;
end_typedef

begin_comment
comment|/* Masks for Flags field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_MEMORY_HIERARCHY
value|(0x0F)
end_define

begin_comment
comment|/* Values for Memory Hierarchy flag */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_LAST_LEVEL_CACHE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_1ST_LEVEL_CACHE
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_2ND_LEVEL_CACHE
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_3RD_LEVEL_CACHE
value|4
end_define

begin_comment
comment|/* Values for DataType field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_ACCESS_LATENCY
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_READ_LATENCY
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_WRITE_LATENCY
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_ACCESS_BANDWIDTH
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_READ_BANDWIDTH
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_WRITE_BANDWIDTH
value|5
end_define

begin_comment
comment|/* 2: Memory side cache information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_hmat_cache
block|{
name|ACPI_HMAT_STRUCTURE
name|Header
decl_stmt|;
name|UINT32
name|MemoryPD
decl_stmt|;
name|UINT32
name|Reserved1
decl_stmt|;
name|UINT64
name|CacheSize
decl_stmt|;
name|UINT32
name|CacheAttributes
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
name|UINT16
name|NumberOfSMBIOSHandles
decl_stmt|;
block|}
name|ACPI_HMAT_CACHE
typedef|;
end_typedef

begin_comment
comment|/* Masks for CacheAttributes field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_TOTAL_CACHE_LEVEL
value|(0x0000000F)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CACHE_LEVEL
value|(0x000000F0)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CACHE_ASSOCIATIVITY
value|(0x00000F00)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_WRITE_POLICY
value|(0x0000F000)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CACHE_LINE_SIZE
value|(0xFFFF0000)
end_define

begin_comment
comment|/* Values for cache associativity flag */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_CA_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CA_DIRECT_MAPPED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CA_COMPLEX_CACHE_INDEXING
value|(2)
end_define

begin_comment
comment|/* Values for write policy flag */
end_comment

begin_define
define|#
directive|define
name|ACPI_HMAT_CP_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CP_WB
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_HMAT_CP_WT
value|(2)
end_define

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
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MADT_MULTIPLE_APIC
value|0
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
name|ACPI_MADT_TYPE_GENERIC_TRANSLATOR
init|=
literal|15
block|,
name|ACPI_MADT_TYPE_RESERVED
init|=
literal|16
comment|/* 16 and greater are reserved */
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
comment|/* 11: Generic Interrupt (ACPI 5.0 + ACPI 6.0 changes) */
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
name|UINT8
name|EfficiencyClass
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
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
comment|/* 12: Generic Distributor (ACPI 5.0 + ACPI 6.0 changes) */
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
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved - must be zero */
block|}
name|ACPI_MADT_GENERIC_DISTRIBUTOR
typedef|;
end_typedef

begin_comment
comment|/* Values for Version field above */
end_comment

begin_enum
enum|enum
name|AcpiMadtGicVersion
block|{
name|ACPI_MADT_GIC_VERSION_NONE
init|=
literal|0
block|,
name|ACPI_MADT_GIC_VERSION_V1
init|=
literal|1
block|,
name|ACPI_MADT_GIC_VERSION_V2
init|=
literal|2
block|,
name|ACPI_MADT_GIC_VERSION_V3
init|=
literal|3
block|,
name|ACPI_MADT_GIC_VERSION_V4
init|=
literal|4
block|,
name|ACPI_MADT_GIC_VERSION_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
block|}
enum|;
end_enum

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
comment|/* 15: Generic Translator (ACPI 6.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_madt_generic_translator
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* reserved - must be zero */
name|UINT32
name|TranslationId
decl_stmt|;
name|UINT64
name|BaseAddress
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
block|}
name|ACPI_MADT_GENERIC_TRANSLATOR
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
comment|/*******************************************************************************  *  * NFIT - NVDIMM Interface Table (ACPI 6.0+)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_nfit
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
name|UINT32
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_TABLE_NFIT
typedef|;
end_typedef

begin_comment
comment|/* Subtable header for NFIT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_header
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|ACPI_NFIT_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for subtable type in ACPI_NFIT_HEADER */
end_comment

begin_enum
enum|enum
name|AcpiNfitType
block|{
name|ACPI_NFIT_TYPE_SYSTEM_ADDRESS
init|=
literal|0
block|,
name|ACPI_NFIT_TYPE_MEMORY_MAP
init|=
literal|1
block|,
name|ACPI_NFIT_TYPE_INTERLEAVE
init|=
literal|2
block|,
name|ACPI_NFIT_TYPE_SMBIOS
init|=
literal|3
block|,
name|ACPI_NFIT_TYPE_CONTROL_REGION
init|=
literal|4
block|,
name|ACPI_NFIT_TYPE_DATA_REGION
init|=
literal|5
block|,
name|ACPI_NFIT_TYPE_FLUSH_ADDRESS
init|=
literal|6
block|,
name|ACPI_NFIT_TYPE_RESERVED
init|=
literal|7
comment|/* 7 and greater are reserved */
block|}
enum|;
end_enum

begin_comment
comment|/*  * NFIT Subtables  */
end_comment

begin_comment
comment|/* 0: System Physical Address Range Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_system_address
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|RangeIndex
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|/* Reseved, must be zero */
name|UINT32
name|ProximityDomain
decl_stmt|;
name|UINT8
name|RangeGuid
index|[
literal|16
index|]
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
name|UINT64
name|MemoryMapping
decl_stmt|;
block|}
name|ACPI_NFIT_SYSTEM_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_ADD_ONLINE_ONLY
value|(1)
end_define

begin_comment
comment|/* 00: Add/Online Operation Only */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_PROXIMITY_VALID
value|(1<<1)
end_define

begin_comment
comment|/* 01: Proximity Domain Valid */
end_comment

begin_comment
comment|/* Range Type GUIDs appear in the include/acuuid.h file */
end_comment

begin_comment
comment|/* 1: Memory Device to System Address Range Map Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_memory_map
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT32
name|DeviceHandle
decl_stmt|;
name|UINT16
name|PhysicalId
decl_stmt|;
name|UINT16
name|RegionId
decl_stmt|;
name|UINT16
name|RangeIndex
decl_stmt|;
name|UINT16
name|RegionIndex
decl_stmt|;
name|UINT64
name|RegionSize
decl_stmt|;
name|UINT64
name|RegionOffset
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
name|UINT16
name|InterleaveIndex
decl_stmt|;
name|UINT16
name|InterleaveWays
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_NFIT_MEMORY_MAP
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_SAVE_FAILED
value|(1)
end_define

begin_comment
comment|/* 00: Last SAVE to Memory Device failed */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_RESTORE_FAILED
value|(1<<1)
end_define

begin_comment
comment|/* 01: Last RESTORE from Memory Device failed */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_FLUSH_FAILED
value|(1<<2)
end_define

begin_comment
comment|/* 02: Platform flush failed */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_NOT_ARMED
value|(1<<3)
end_define

begin_comment
comment|/* 03: Memory Device is not armed */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_HEALTH_OBSERVED
value|(1<<4)
end_define

begin_comment
comment|/* 04: Memory Device observed SMART/health events */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_HEALTH_ENABLED
value|(1<<5)
end_define

begin_comment
comment|/* 05: SMART/health events enabled */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_MEM_MAP_FAILED
value|(1<<6)
end_define

begin_comment
comment|/* 06: Mapping to SPA failed */
end_comment

begin_comment
comment|/* 2: Interleave Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_interleave
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|InterleaveIndex
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|LineCount
decl_stmt|;
name|UINT32
name|LineSize
decl_stmt|;
name|UINT32
name|LineOffset
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length */
block|}
name|ACPI_NFIT_INTERLEAVE
typedef|;
end_typedef

begin_comment
comment|/* 3: SMBIOS Management Information Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_smbios
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length */
block|}
name|ACPI_NFIT_SMBIOS
typedef|;
end_typedef

begin_comment
comment|/* 4: NVDIMM Control Region Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_control_region
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|RegionIndex
decl_stmt|;
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|RevisionId
decl_stmt|;
name|UINT16
name|SubsystemVendorId
decl_stmt|;
name|UINT16
name|SubsystemDeviceId
decl_stmt|;
name|UINT16
name|SubsystemRevisionId
decl_stmt|;
name|UINT8
name|ValidFields
decl_stmt|;
name|UINT8
name|ManufacturingLocation
decl_stmt|;
name|UINT16
name|ManufacturingDate
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT32
name|SerialNumber
decl_stmt|;
name|UINT16
name|Code
decl_stmt|;
name|UINT16
name|Windows
decl_stmt|;
name|UINT64
name|WindowSize
decl_stmt|;
name|UINT64
name|CommandOffset
decl_stmt|;
name|UINT64
name|CommandSize
decl_stmt|;
name|UINT64
name|StatusOffset
decl_stmt|;
name|UINT64
name|StatusSize
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|6
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
block|}
name|ACPI_NFIT_CONTROL_REGION
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_CONTROL_BUFFERED
value|(1)
end_define

begin_comment
comment|/* Block Data Windows implementation is buffered */
end_comment

begin_comment
comment|/* ValidFields bits */
end_comment

begin_define
define|#
directive|define
name|ACPI_NFIT_CONTROL_MFG_INFO_VALID
value|(1)
end_define

begin_comment
comment|/* Manufacturing fields are valid */
end_comment

begin_comment
comment|/* 5: NVDIMM Block Data Window Region Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_data_region
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT16
name|RegionIndex
decl_stmt|;
name|UINT16
name|Windows
decl_stmt|;
name|UINT64
name|Offset
decl_stmt|;
name|UINT64
name|Size
decl_stmt|;
name|UINT64
name|Capacity
decl_stmt|;
name|UINT64
name|StartAddress
decl_stmt|;
block|}
name|ACPI_NFIT_DATA_REGION
typedef|;
end_typedef

begin_comment
comment|/* 6: Flush Hint Address Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_nfit_flush_address
block|{
name|ACPI_NFIT_HEADER
name|Header
decl_stmt|;
name|UINT32
name|DeviceHandle
decl_stmt|;
name|UINT16
name|HintCount
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
comment|/* Reserved, must be zero */
name|UINT64
name|HintAddress
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length */
block|}
name|ACPI_NFIT_FLUSH_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * PPTT - Processor Properties Topology Table (ACPI 6.2)  *        Version 1  *  ******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_pptt
block|{
name|ACPI_TABLE_HEADER
name|Header
decl_stmt|;
comment|/* Common ACPI table header */
block|}
name|ACPI_TABLE_PPTT
typedef|;
end_typedef

begin_comment
comment|/* Values for Type field above */
end_comment

begin_enum
enum|enum
name|AcpiPpttType
block|{
name|ACPI_PPTT_TYPE_PROCESSOR
init|=
literal|0
block|,
name|ACPI_PPTT_TYPE_CACHE
init|=
literal|1
block|,
name|ACPI_PPTT_TYPE_ID
init|=
literal|2
block|,
name|ACPI_PPTT_TYPE_RESERVED
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* 0: Processor Hierarchy Node Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pptt_processor
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|Parent
decl_stmt|;
name|UINT32
name|AcpiProcessorId
decl_stmt|;
name|UINT32
name|NumberOfPrivResources
decl_stmt|;
block|}
name|ACPI_PPTT_PROCESSOR
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_PHYSICAL_PACKAGE
value|(1)
end_define

begin_comment
comment|/* Physical package */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_ACPI_PROCESSOR_ID_VALID
value|(2)
end_define

begin_comment
comment|/* ACPI Processor ID valid */
end_comment

begin_comment
comment|/* 1: Cache Type Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pptt_cache
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|NextLevelOfCache
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT32
name|NumberOfSets
decl_stmt|;
name|UINT8
name|Associativity
decl_stmt|;
name|UINT8
name|Attributes
decl_stmt|;
name|UINT16
name|LineSize
decl_stmt|;
block|}
name|ACPI_PPTT_CACHE
typedef|;
end_typedef

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_SIZE_PROPERTY_VALID
value|(1)
end_define

begin_comment
comment|/* Physical property valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_NUMBER_OF_SETS_VALID
value|(1<<1)
end_define

begin_comment
comment|/* Number of sets valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_ASSOCIATIVITY_VALID
value|(1<<2)
end_define

begin_comment
comment|/* Associativity valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_ALLOCATION_TYPE_VALID
value|(1<<3)
end_define

begin_comment
comment|/* Allocation type valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_CACHE_TYPE_VALID
value|(1<<4)
end_define

begin_comment
comment|/* Cache type valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_WRITE_POLICY_VALID
value|(1<<5)
end_define

begin_comment
comment|/* Write policy valid */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_LINE_SIZE_VALID
value|(1<<6)
end_define

begin_comment
comment|/* Line size valid */
end_comment

begin_comment
comment|/* Masks for Attributes */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_MASK_ALLOCATION_TYPE
value|(0x03)
end_define

begin_comment
comment|/* Allocation type */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_MASK_CACHE_TYPE
value|(0x0C)
end_define

begin_comment
comment|/* Cache type */
end_comment

begin_define
define|#
directive|define
name|ACPI_PPTT_MASK_WRITE_POLICY
value|(0x10)
end_define

begin_comment
comment|/* Write policy */
end_comment

begin_comment
comment|/* 2: ID Structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pptt_id
block|{
name|ACPI_SUBTABLE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|UINT32
name|VendorId
decl_stmt|;
name|UINT64
name|Level1Id
decl_stmt|;
name|UINT64
name|Level2Id
decl_stmt|;
name|UINT16
name|MajorRev
decl_stmt|;
name|UINT16
name|MinorRev
decl_stmt|;
name|UINT16
name|SpinRev
decl_stmt|;
block|}
name|ACPI_PPTT_ID
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
name|ACPI_SRAT_TYPE_GIC_ITS_AFFINITY
init|=
literal|4
block|,
comment|/* ACPI 6.2 */
name|ACPI_SRAT_TYPE_RESERVED
init|=
literal|5
comment|/* 5 and greater are reserved */
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
comment|/* 4: GCC ITS Affinity (ACPI 6.2) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_srat_gic_its_affinity
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
name|UINT32
name|ItsId
decl_stmt|;
block|}
name|ACPI_SRAT_GIC_ITS_AFFINITY
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
comment|/* __ACTBL1_H__ */
end_comment

end_unit

