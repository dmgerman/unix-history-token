begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actbl.h - Table data structures defined in ACPI specification  *       $Revision: 66 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2004, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
comment|/*  *  Values for description table header signatures  */
end_comment

begin_define
define|#
directive|define
name|RSDP_NAME
value|"RSDP"
end_define

begin_define
define|#
directive|define
name|RSDP_SIG
value|"RSD PTR "
end_define

begin_comment
comment|/* RSDT Pointer signature */
end_comment

begin_define
define|#
directive|define
name|APIC_SIG
value|"APIC"
end_define

begin_comment
comment|/* Multiple APIC Description Table */
end_comment

begin_define
define|#
directive|define
name|DSDT_SIG
value|"DSDT"
end_define

begin_comment
comment|/* Differentiated System Description Table */
end_comment

begin_define
define|#
directive|define
name|FADT_SIG
value|"FACP"
end_define

begin_comment
comment|/* Fixed ACPI Description Table */
end_comment

begin_define
define|#
directive|define
name|FACS_SIG
value|"FACS"
end_define

begin_comment
comment|/* Firmware ACPI Control Structure */
end_comment

begin_define
define|#
directive|define
name|PSDT_SIG
value|"PSDT"
end_define

begin_comment
comment|/* Persistent System Description Table */
end_comment

begin_define
define|#
directive|define
name|RSDT_SIG
value|"RSDT"
end_define

begin_comment
comment|/* Root System Description Table */
end_comment

begin_define
define|#
directive|define
name|XSDT_SIG
value|"XSDT"
end_define

begin_comment
comment|/* Extended  System Description Table */
end_comment

begin_define
define|#
directive|define
name|SSDT_SIG
value|"SSDT"
end_define

begin_comment
comment|/* Secondary System Description Table */
end_comment

begin_define
define|#
directive|define
name|SBST_SIG
value|"SBST"
end_define

begin_comment
comment|/* Smart Battery Specification Table */
end_comment

begin_define
define|#
directive|define
name|SPIC_SIG
value|"SPIC"
end_define

begin_comment
comment|/* IOSAPIC table */
end_comment

begin_define
define|#
directive|define
name|BOOT_SIG
value|"BOOT"
end_define

begin_comment
comment|/* Boot table */
end_comment

begin_define
define|#
directive|define
name|GL_OWNED
value|0x02
end_define

begin_comment
comment|/* Ownership of global lock is bit 1 */
end_comment

begin_comment
comment|/*  * Common table types.  The base code can remain  * constant if the underlying tables are changed  */
end_comment

begin_define
define|#
directive|define
name|RSDT_DESCRIPTOR
value|RSDT_DESCRIPTOR_REV2
end_define

begin_define
define|#
directive|define
name|XSDT_DESCRIPTOR
value|XSDT_DESCRIPTOR_REV2
end_define

begin_define
define|#
directive|define
name|FACS_DESCRIPTOR
value|FACS_DESCRIPTOR_REV2
end_define

begin_define
define|#
directive|define
name|FADT_DESCRIPTOR
value|FADT_DESCRIPTOR_REV2
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|/*  * ACPI Version-independent tables  *  * NOTE: The tables that are specific to ACPI versions (1.0, 2.0, etc.)  * are in separate files.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rsdp_descriptor
comment|/* Root System Descriptor Pointer */
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
comment|/* To make sum of struct == 0 */
name|char
name|OemId
index|[
literal|6
index|]
decl_stmt|;
comment|/* OEM identification */
name|UINT8
name|Revision
decl_stmt|;
comment|/* Must be 0 for 1.0, 2 for 2.0 */
name|UINT32
name|RsdtPhysicalAddress
decl_stmt|;
comment|/* 32-bit physical address of RSDT */
name|UINT32
name|Length
decl_stmt|;
comment|/* XSDT Length in bytes including hdr */
name|UINT64
name|XsdtPhysicalAddress
decl_stmt|;
comment|/* 64-bit physical address of XSDT */
name|UINT8
name|ExtendedChecksum
decl_stmt|;
comment|/* Checksum of entire table */
name|char
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved field must be 0 */
block|}
name|RSDP_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_common_facs
comment|/* Common FACS for internal use */
block|{
name|UINT32
modifier|*
name|GlobalLock
decl_stmt|;
name|UINT64
modifier|*
name|FirmwareWakingVector
decl_stmt|;
name|UINT8
name|VectorWidth
decl_stmt|;
block|}
name|ACPI_COMMON_FACS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_TABLE_HEADER_DEF
comment|/* ACPI common table header */
define|\
value|char                    Signature [4];
comment|/* ACPI signature (4 ASCII characters) */
value|\     UINT32                  Length;
comment|/* Length of table, in bytes, including header */
value|\     UINT8                   Revision;
comment|/* ACPI Specification minor version # */
value|\     UINT8                   Checksum;
comment|/* To make sum of entire table == 0 */
value|\     char                    OemId [6];
comment|/* OEM identification */
value|\     char                    OemTableId [8];
comment|/* OEM table identification */
value|\     UINT32                  OemRevision;
comment|/* OEM revision number */
value|\     char                    AslCompilerId [4];
comment|/* ASL compiler vendor ID */
value|\     UINT32                  AslCompilerRevision;
end_define

begin_comment
comment|/* ASL compiler revision number */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_header
comment|/* ACPI common table header */
block|{
name|ACPI_TABLE_HEADER_DEF
block|}
name|ACPI_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * MADT values and structures  */
end_comment

begin_comment
comment|/* Values for MADT PCATCompat */
end_comment

begin_define
define|#
directive|define
name|DUAL_PIC
value|0
end_define

begin_define
define|#
directive|define
name|MULTIPLE_APIC
value|1
end_define

begin_comment
comment|/* Master MADT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|multiple_apic_table
block|{
name|ACPI_TABLE_HEADER_DEF
comment|/* ACPI common table header */
name|UINT32
name|LocalApicAddress
decl_stmt|;
comment|/* Physical address of local APIC */
name|UINT32_BIT
name|PCATCompat
range|:
literal|1
decl_stmt|;
comment|/* A one indicates system also has dual 8259s */
name|UINT32_BIT
name|Reserved1
range|:
literal|31
decl_stmt|;
block|}
name|MULTIPLE_APIC_TABLE
typedef|;
end_typedef

begin_comment
comment|/* Values for Type in APIC_HEADER_DEF */
end_comment

begin_define
define|#
directive|define
name|APIC_PROCESSOR
value|0
end_define

begin_define
define|#
directive|define
name|APIC_IO
value|1
end_define

begin_define
define|#
directive|define
name|APIC_XRUPT_OVERRIDE
value|2
end_define

begin_define
define|#
directive|define
name|APIC_NMI
value|3
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_NMI
value|4
end_define

begin_define
define|#
directive|define
name|APIC_ADDRESS_OVERRIDE
value|5
end_define

begin_define
define|#
directive|define
name|APIC_IO_SAPIC
value|6
end_define

begin_define
define|#
directive|define
name|APIC_LOCAL_SAPIC
value|7
end_define

begin_define
define|#
directive|define
name|APIC_XRUPT_SOURCE
value|8
end_define

begin_define
define|#
directive|define
name|APIC_RESERVED
value|9
end_define

begin_comment
comment|/* 9 and greater are reserved */
end_comment

begin_comment
comment|/*  * MADT sub-structures (Follow MULTIPLE_APIC_DESCRIPTION_TABLE)  */
end_comment

begin_define
define|#
directive|define
name|APIC_HEADER_DEF
comment|/* Common APIC sub-structure header */
define|\
value|UINT8                   Type; \     UINT8                   Length;
end_define

begin_typedef
typedef|typedef
struct|struct
name|apic_header
block|{
name|APIC_HEADER_DEF
block|}
name|APIC_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Values for MPS INTI flags */
end_comment

begin_define
define|#
directive|define
name|POLARITY_CONFORMS
value|0
end_define

begin_define
define|#
directive|define
name|POLARITY_ACTIVE_HIGH
value|1
end_define

begin_define
define|#
directive|define
name|POLARITY_RESERVED
value|2
end_define

begin_define
define|#
directive|define
name|POLARITY_ACTIVE_LOW
value|3
end_define

begin_define
define|#
directive|define
name|TRIGGER_CONFORMS
value|0
end_define

begin_define
define|#
directive|define
name|TRIGGER_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|TRIGGER_RESERVED
value|2
end_define

begin_define
define|#
directive|define
name|TRIGGER_LEVEL
value|3
end_define

begin_comment
comment|/* Common flag definitions */
end_comment

begin_define
define|#
directive|define
name|MPS_INTI_FLAGS
define|\
value|UINT16_BIT              Polarity        : 2;
comment|/* Polarity of APIC I/O input signals */
value|\     UINT16_BIT              TriggerMode     : 2;
comment|/* Trigger mode of APIC input signals */
value|\     UINT16_BIT              Reserved1       : 12;
end_define

begin_comment
comment|/* Reserved, must be zero */
end_comment

begin_define
define|#
directive|define
name|LOCAL_APIC_FLAGS
define|\
value|UINT32_BIT              ProcessorEnabled: 1;
comment|/* Processor is usable if set */
value|\     UINT32_BIT              Reserved2       : 31;
end_define

begin_comment
comment|/* Reserved, must be zero */
end_comment

begin_comment
comment|/* Sub-structures for MADT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|madt_processor_apic
block|{
name|APIC_HEADER_DEF
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|LocalApicId
decl_stmt|;
comment|/* Processor's local APIC id */
name|LOCAL_APIC_FLAGS
block|}
name|MADT_PROCESSOR_APIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_io_apic
block|{
name|APIC_HEADER_DEF
name|UINT8
name|IoApicId
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
name|Interrupt
decl_stmt|;
comment|/* Global system interrupt where INTI                                                      * lines start */
block|}
name|MADT_IO_APIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_interrupt_override
block|{
name|APIC_HEADER_DEF
name|UINT8
name|Bus
decl_stmt|;
comment|/* 0 - ISA */
name|UINT8
name|Source
decl_stmt|;
comment|/* Interrupt source (IRQ) */
name|UINT32
name|Interrupt
decl_stmt|;
comment|/* Global system interrupt */
name|MPS_INTI_FLAGS
block|}
name|MADT_INTERRUPT_OVERRIDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_nmi_source
block|{
name|APIC_HEADER_DEF
name|MPS_INTI_FLAGS
name|UINT32
name|Interrupt
decl_stmt|;
comment|/* Global system interrupt */
block|}
name|MADT_NMI_SOURCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_local_apic_nmi
block|{
name|APIC_HEADER_DEF
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|MPS_INTI_FLAGS
name|UINT8
name|Lint
decl_stmt|;
comment|/* LINTn to which NMI is connected */
block|}
name|MADT_LOCAL_APIC_NMI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_address_override
block|{
name|APIC_HEADER_DEF
name|UINT16
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT64
name|Address
decl_stmt|;
comment|/* APIC physical address */
block|}
name|MADT_ADDRESS_OVERRIDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_io_sapic
block|{
name|APIC_HEADER_DEF
name|UINT8
name|IoSapicId
decl_stmt|;
comment|/* I/O SAPIC ID */
name|UINT8
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
name|UINT32
name|InterruptBase
decl_stmt|;
comment|/* Glocal interrupt for SAPIC start */
name|UINT64
name|Address
decl_stmt|;
comment|/* SAPIC physical address */
block|}
name|MADT_IO_SAPIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_local_sapic
block|{
name|APIC_HEADER_DEF
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* ACPI processor id */
name|UINT8
name|LocalSapicId
decl_stmt|;
comment|/* SAPIC ID */
name|UINT8
name|LocalSapicEid
decl_stmt|;
comment|/* SAPIC EID */
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved - must be zero */
name|LOCAL_APIC_FLAGS
block|}
name|MADT_LOCAL_SAPIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|madt_interrupt_source
block|{
name|APIC_HEADER_DEF
name|MPS_INTI_FLAGS
name|UINT8
name|InterruptType
decl_stmt|;
comment|/* 1=PMI, 2=INIT, 3=corrected */
name|UINT8
name|ProcessorId
decl_stmt|;
comment|/* Processor ID */
name|UINT8
name|ProcessorEid
decl_stmt|;
comment|/* Processor EID */
name|UINT8
name|IoSapicVector
decl_stmt|;
comment|/* Vector value for PMI interrupts */
name|UINT32
name|Interrupt
decl_stmt|;
comment|/* Global system interrupt */
name|UINT32
name|Reserved
decl_stmt|;
comment|/* Reserved - must be zero */
block|}
name|MADT_INTERRUPT_SOURCE
typedef|;
end_typedef

begin_comment
comment|/*  * Smart Battery  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smart_battery_table
block|{
name|ACPI_TABLE_HEADER_DEF
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
name|SMART_BATTERY_TABLE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * ACPI Table information.  We save the table address, length,  * and type of memory allocation (mapped or allocated) for each  * table for 1) when we exit, and 2) if a new table is installed  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEM_NOT_ALLOCATED
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_ALLOCATED
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_MAPPED
value|2
end_define

begin_comment
comment|/* Definitions for the Flags bitfield member of ACPI_TABLE_SUPPORT */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_SINGLE
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_MULTIPLE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_EXECUTABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_ROOT
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_PRIMARY
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_SECONDARY
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_ALL
value|0x30
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_TYPE_MASK
value|0x30
end_define

begin_comment
comment|/* Data about each known table type */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_support
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Signature
decl_stmt|;
name|void
modifier|*
modifier|*
name|GlobalPtr
decl_stmt|;
name|UINT8
name|SigLength
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_SUPPORT
typedef|;
end_typedef

begin_comment
comment|/*  * Get the ACPI version-specific tables  */
end_comment

begin_include
include|#
directive|include
file|"actbl1.h"
end_include

begin_comment
comment|/* Acpi 1.0 table definitions */
end_comment

begin_include
include|#
directive|include
file|"actbl2.h"
end_include

begin_comment
comment|/* Acpi 2.0 table definitions */
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
comment|/*  * High performance timer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hpet_table
block|{
name|ACPI_TABLE_HEADER_DEF
name|UINT32
name|HardwareId
decl_stmt|;
name|ACPI_GENERIC_ADDRESS
name|BaseAddress
decl_stmt|;
name|UINT8
name|HpetNumber
decl_stmt|;
name|UINT16
name|ClockTick
decl_stmt|;
name|UINT8
name|Attributes
decl_stmt|;
block|}
name|HPET_TABLE
typedef|;
end_typedef

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
comment|/* __ACTBL_H__ */
end_comment

end_unit

