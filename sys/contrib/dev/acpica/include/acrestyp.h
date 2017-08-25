begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acrestyp.h - Defines, types, and structures for resource descriptors  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACRESTYP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACRESTYP_H__
end_define

begin_comment
comment|/*  * Definitions for Resource Attributes  */
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|ACPI_RS_LENGTH
typedef|;
end_typedef

begin_comment
comment|/* Resource Length field is fixed at 16 bits */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_RSDESC_SIZE
typedef|;
end_typedef

begin_comment
comment|/* Max Resource Descriptor size is (Length+3) = (64K-1)+3 */
end_comment

begin_comment
comment|/*  * Memory Attributes  */
end_comment

begin_define
define|#
directive|define
name|ACPI_READ_ONLY_MEMORY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_READ_WRITE_MEMORY
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NON_CACHEABLE_MEMORY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_CACHABLE_MEMORY
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_WRITE_COMBINING_MEMORY
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_PREFETCHABLE_MEMORY
value|(UINT8) 0x03
end_define

begin_comment
comment|/*! [Begin] no source code translation */
end_comment

begin_comment
comment|/*  * IO Attributes  * The ISA IO ranges are:     n000-n0FFh,  n400-n4FFh, n800-n8FFh, nC00-nCFFh.  * The non-ISA IO ranges are: n100-n3FFh,  n500-n7FFh, n900-nBFFh, nCD0-nFFFh.  */
end_comment

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_define
define|#
directive|define
name|ACPI_NON_ISA_ONLY_RANGES
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_ISA_ONLY_RANGES
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_ENTIRE_RANGE
value|(ACPI_NON_ISA_ONLY_RANGES | ACPI_ISA_ONLY_RANGES)
end_define

begin_comment
comment|/* Type of translation - 1=Sparse, 0=Dense */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPARSE_TRANSLATION
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  * IO Port Descriptor Decode  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DECODE_10
value|(UINT8) 0x00
end_define

begin_comment
comment|/* 10-bit IO address decode */
end_comment

begin_define
define|#
directive|define
name|ACPI_DECODE_16
value|(UINT8) 0x01
end_define

begin_comment
comment|/* 16-bit IO address decode */
end_comment

begin_comment
comment|/*  * Interrupt attributes - used in multiple descriptors  */
end_comment

begin_comment
comment|/* Triggering */
end_comment

begin_define
define|#
directive|define
name|ACPI_LEVEL_SENSITIVE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_EDGE_SENSITIVE
value|(UINT8) 0x01
end_define

begin_comment
comment|/* Polarity */
end_comment

begin_define
define|#
directive|define
name|ACPI_ACTIVE_HIGH
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ACTIVE_LOW
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_ACTIVE_BOTH
value|(UINT8) 0x02
end_define

begin_comment
comment|/* Sharing */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXCLUSIVE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_SHARED
value|(UINT8) 0x01
end_define

begin_comment
comment|/* Wake */
end_comment

begin_define
define|#
directive|define
name|ACPI_NOT_WAKE_CAPABLE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_WAKE_CAPABLE
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  * DMA Attributes  */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMPATIBILITY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_A
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_B
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_F
value|(UINT8) 0x03
end_define

begin_define
define|#
directive|define
name|ACPI_NOT_BUS_MASTER
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BUS_MASTER
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_8
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_8_16
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_16
value|(UINT8) 0x02
end_define

begin_comment
comment|/*  * Start Dependent Functions Priority definitions  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GOOD_CONFIGURATION
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ACCEPTABLE_CONFIGURATION
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_SUB_OPTIMAL_CONFIGURATION
value|(UINT8) 0x02
end_define

begin_comment
comment|/*  * 16, 32 and 64-bit Address Descriptor resource types  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEMORY_RANGE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_IO_RANGE
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_BUS_NUMBER_RANGE
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_NOT_FIXED
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_FIXED
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_POS_DECODE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_SUB_DECODE
value|(UINT8) 0x01
end_define

begin_comment
comment|/* Producer/Consumer */
end_comment

begin_define
define|#
directive|define
name|ACPI_PRODUCER
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_CONSUMER
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  * If possible, pack the following structures to byte alignment  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UUID data structures for use in vendor-defined resource descriptors */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_uuid
block|{
name|UINT8
name|Data
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_UUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_vendor_uuid
block|{
name|UINT8
name|Subtype
decl_stmt|;
name|UINT8
name|Data
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_VENDOR_UUID
typedef|;
end_typedef

begin_comment
comment|/*  * Structures used to describe device resources  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_irq
block|{
name|UINT8
name|DescriptorLength
decl_stmt|;
name|UINT8
name|Triggering
decl_stmt|;
name|UINT8
name|Polarity
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
name|UINT8
name|WakeCapable
decl_stmt|;
name|UINT8
name|InterruptCount
decl_stmt|;
name|UINT8
name|Interrupts
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_dma
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|BusMaster
decl_stmt|;
name|UINT8
name|Transfer
decl_stmt|;
name|UINT8
name|ChannelCount
decl_stmt|;
name|UINT8
name|Channels
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_DMA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_start_dependent
block|{
name|UINT8
name|DescriptorLength
decl_stmt|;
name|UINT8
name|CompatibilityPriority
decl_stmt|;
name|UINT8
name|PerformanceRobustness
decl_stmt|;
block|}
name|ACPI_RESOURCE_START_DEPENDENT
typedef|;
end_typedef

begin_comment
comment|/*  * The END_DEPENDENT_FUNCTIONS_RESOURCE struct is not  * needed because it has no fields  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_io
block|{
name|UINT8
name|IoDecode
decl_stmt|;
name|UINT8
name|Alignment
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
block|}
name|ACPI_RESOURCE_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_fixed_io
block|{
name|UINT16
name|Address
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_fixed_dma
block|{
name|UINT16
name|RequestLines
decl_stmt|;
name|UINT16
name|Channels
decl_stmt|;
name|UINT8
name|Width
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_DMA
typedef|;
end_typedef

begin_comment
comment|/* Values for Width field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH8
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH16
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH32
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH64
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH128
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_DMA_WIDTH256
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_vendor
block|{
name|UINT16
name|ByteLength
decl_stmt|;
name|UINT8
name|ByteData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_VENDOR
typedef|;
end_typedef

begin_comment
comment|/* Vendor resource with UUID info (introduced in ACPI 3.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_vendor_typed
block|{
name|UINT16
name|ByteLength
decl_stmt|;
name|UINT8
name|UuidSubtype
decl_stmt|;
name|UINT8
name|Uuid
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
name|UINT8
name|ByteData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_VENDOR_TYPED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_end_tag
block|{
name|UINT8
name|Checksum
decl_stmt|;
block|}
name|ACPI_RESOURCE_END_TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_memory24
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
name|UINT16
name|Alignment
decl_stmt|;
name|UINT16
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEMORY24
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_memory32
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT32
name|Minimum
decl_stmt|;
name|UINT32
name|Maximum
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEMORY32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_fixed_memory32
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT32
name|Address
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_MEMORY32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_memory_attribute
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT8
name|Caching
decl_stmt|;
name|UINT8
name|RangeType
decl_stmt|;
name|UINT8
name|Translation
decl_stmt|;
block|}
name|ACPI_MEMORY_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_io_attribute
block|{
name|UINT8
name|RangeType
decl_stmt|;
name|UINT8
name|Translation
decl_stmt|;
name|UINT8
name|TranslationType
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
block|}
name|ACPI_IO_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_resource_attribute
block|{
name|ACPI_MEMORY_ATTRIBUTE
name|Mem
decl_stmt|;
name|ACPI_IO_ATTRIBUTE
name|Io
decl_stmt|;
comment|/* Used for the *WordSpace macros */
name|UINT8
name|TypeSpecific
decl_stmt|;
block|}
name|ACPI_RESOURCE_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_label
block|{
name|UINT16
name|StringLength
decl_stmt|;
name|char
modifier|*
name|StringPtr
decl_stmt|;
block|}
name|ACPI_RESOURCE_LABEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_source
block|{
name|UINT8
name|Index
decl_stmt|;
name|UINT16
name|StringLength
decl_stmt|;
name|char
modifier|*
name|StringPtr
decl_stmt|;
block|}
name|ACPI_RESOURCE_SOURCE
typedef|;
end_typedef

begin_comment
comment|/* Fields common to all address descriptors, 16/32/64 bit */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_ADDRESS_COMMON
define|\
value|UINT8                           ResourceType; \     UINT8                           ProducerConsumer; \     UINT8                           Decode; \     UINT8                           MinAddressFixed; \     UINT8                           MaxAddressFixed; \     ACPI_RESOURCE_ATTRIBUTE         Info;
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_address16_attribute
block|{
name|UINT16
name|Granularity
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
name|UINT16
name|TranslationOffset
decl_stmt|;
name|UINT16
name|AddressLength
decl_stmt|;
block|}
name|ACPI_ADDRESS16_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_address32_attribute
block|{
name|UINT32
name|Granularity
decl_stmt|;
name|UINT32
name|Minimum
decl_stmt|;
name|UINT32
name|Maximum
decl_stmt|;
name|UINT32
name|TranslationOffset
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|ACPI_ADDRESS32_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_address64_attribute
block|{
name|UINT64
name|Granularity
decl_stmt|;
name|UINT64
name|Minimum
decl_stmt|;
name|UINT64
name|Maximum
decl_stmt|;
name|UINT64
name|TranslationOffset
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
block|}
name|ACPI_ADDRESS64_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
block|}
name|ACPI_RESOURCE_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address16
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|ACPI_ADDRESS16_ATTRIBUTE
name|Address
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS16
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address32
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|ACPI_ADDRESS32_ATTRIBUTE
name|Address
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address64
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|ACPI_ADDRESS64_ATTRIBUTE
name|Address
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_extended_address64
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|UINT8
name|RevisionID
decl_stmt|;
name|ACPI_ADDRESS64_ATTRIBUTE
name|Address
decl_stmt|;
name|UINT64
name|TypeSpecific
decl_stmt|;
block|}
name|ACPI_RESOURCE_EXTENDED_ADDRESS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_extended_irq
block|{
name|UINT8
name|ProducerConsumer
decl_stmt|;
name|UINT8
name|Triggering
decl_stmt|;
name|UINT8
name|Polarity
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
name|UINT8
name|WakeCapable
decl_stmt|;
name|UINT8
name|InterruptCount
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|UINT32
name|Interrupts
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_EXTENDED_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_generic_register
block|{
name|UINT8
name|SpaceId
decl_stmt|;
name|UINT8
name|BitWidth
decl_stmt|;
name|UINT8
name|BitOffset
decl_stmt|;
name|UINT8
name|AccessSize
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ACPI_RESOURCE_GENERIC_REGISTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_gpio
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ConnectionType
decl_stmt|;
name|UINT8
name|ProducerConsumer
decl_stmt|;
comment|/* For values, see Producer/Consumer above */
name|UINT8
name|PinConfig
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT8
name|WakeCapable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT8
name|IoRestriction
decl_stmt|;
name|UINT8
name|Triggering
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT8
name|Polarity
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT16
name|DriveStrength
decl_stmt|;
name|UINT16
name|DebounceTimeout
decl_stmt|;
name|UINT16
name|PinTableLength
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|UINT16
modifier|*
name|PinTable
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_GPIO
typedef|;
end_typedef

begin_comment
comment|/* Values for GPIO ConnectionType field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_GPIO_TYPE_INT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_GPIO_TYPE_IO
value|1
end_define

begin_comment
comment|/* Values for PinConfig field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_PULLUP
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_PULLDOWN
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_NOPULL
value|3
end_define

begin_comment
comment|/* Values for IoRestriction field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_IO_RESTRICT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_IO_RESTRICT_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_IO_RESTRICT_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_IO_RESTRICT_NONE_PRESERVE
value|3
end_define

begin_comment
comment|/* Common structure for I2C, SPI, and UART serial descriptors */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_SERIAL_COMMON
define|\
value|UINT8                           RevisionId; \     UINT8                           Type; \     UINT8                           ProducerConsumer;
comment|/* For values, see Producer/Consumer above */
value|\     UINT8                           SlaveMode; \     UINT8                           ConnectionSharing; \     UINT8                           TypeRevisionId; \     UINT16                          TypeDataLength; \     UINT16                          VendorLength; \     ACPI_RESOURCE_SOURCE            ResourceSource; \     UINT8                           *VendorData;
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_common_serialbus
block|{
name|ACPI_RESOURCE_SERIAL_COMMON
block|}
name|ACPI_RESOURCE_COMMON_SERIALBUS
typedef|;
end_typedef

begin_comment
comment|/* Values for the Type field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_SERIAL_TYPE_I2C
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_SERIAL_TYPE_SPI
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_SERIAL_TYPE_UART
value|3
end_define

begin_comment
comment|/* Values for SlaveMode field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_CONTROLLER_INITIATED
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_DEVICE_INITIATED
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_i2c_serialbus
block|{
name|ACPI_RESOURCE_SERIAL_COMMON
name|UINT8
name|AccessMode
decl_stmt|;
name|UINT16
name|SlaveAddress
decl_stmt|;
name|UINT32
name|ConnectionSpeed
decl_stmt|;
block|}
name|ACPI_RESOURCE_I2C_SERIALBUS
typedef|;
end_typedef

begin_comment
comment|/* Values for AccessMode field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_I2C_7BIT_MODE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_I2C_10BIT_MODE
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_spi_serialbus
block|{
name|ACPI_RESOURCE_SERIAL_COMMON
name|UINT8
name|WireMode
decl_stmt|;
name|UINT8
name|DevicePolarity
decl_stmt|;
name|UINT8
name|DataBitLength
decl_stmt|;
name|UINT8
name|ClockPhase
decl_stmt|;
name|UINT8
name|ClockPolarity
decl_stmt|;
name|UINT16
name|DeviceSelection
decl_stmt|;
name|UINT32
name|ConnectionSpeed
decl_stmt|;
block|}
name|ACPI_RESOURCE_SPI_SERIALBUS
typedef|;
end_typedef

begin_comment
comment|/* Values for WireMode field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPI_4WIRE_MODE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SPI_3WIRE_MODE
value|1
end_define

begin_comment
comment|/* Values for DevicePolarity field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPI_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SPI_ACTIVE_HIGH
value|1
end_define

begin_comment
comment|/* Values for ClockPhase field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPI_FIRST_PHASE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SPI_SECOND_PHASE
value|1
end_define

begin_comment
comment|/* Values for ClockPolarity field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPI_START_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SPI_START_HIGH
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_uart_serialbus
block|{
name|ACPI_RESOURCE_SERIAL_COMMON
name|UINT8
name|Endian
decl_stmt|;
name|UINT8
name|DataBits
decl_stmt|;
name|UINT8
name|StopBits
decl_stmt|;
name|UINT8
name|FlowControl
decl_stmt|;
name|UINT8
name|Parity
decl_stmt|;
name|UINT8
name|LinesEnabled
decl_stmt|;
name|UINT16
name|RxFifoSize
decl_stmt|;
name|UINT16
name|TxFifoSize
decl_stmt|;
name|UINT32
name|DefaultBaudRate
decl_stmt|;
block|}
name|ACPI_RESOURCE_UART_SERIALBUS
typedef|;
end_typedef

begin_comment
comment|/* Values for Endian field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_LITTLE_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_UART_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Values for DataBits field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_5_DATA_BITS
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_UART_6_DATA_BITS
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_UART_7_DATA_BITS
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_UART_8_DATA_BITS
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_UART_9_DATA_BITS
value|4
end_define

begin_comment
comment|/* Values for StopBits field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_NO_STOP_BITS
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_UART_1_STOP_BIT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_UART_1P5_STOP_BITS
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_UART_2_STOP_BITS
value|3
end_define

begin_comment
comment|/* Values for FlowControl field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_FLOW_CONTROL_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_UART_FLOW_CONTROL_HW
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_UART_FLOW_CONTROL_XON_XOFF
value|2
end_define

begin_comment
comment|/* Values for Parity field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_PARITY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_UART_PARITY_EVEN
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_UART_PARITY_ODD
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_UART_PARITY_MARK
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_UART_PARITY_SPACE
value|4
end_define

begin_comment
comment|/* Values for LinesEnabled bitfield above */
end_comment

begin_define
define|#
directive|define
name|ACPI_UART_CARRIER_DETECT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ACPI_UART_RING_INDICATOR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ACPI_UART_DATA_SET_READY
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ACPI_UART_DATA_TERMINAL_READY
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ACPI_UART_CLEAR_TO_SEND
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ACPI_UART_REQUEST_TO_SEND
value|(1<<7)
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_pin_function
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|PinConfig
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT16
name|FunctionNumber
decl_stmt|;
name|UINT16
name|PinTableLength
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|UINT16
modifier|*
name|PinTable
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_PIN_FUNCTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_pin_config
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ProducerConsumer
decl_stmt|;
comment|/* For values, see Producer/Consumer above */
name|UINT8
name|Sharable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT8
name|PinConfigType
decl_stmt|;
name|UINT32
name|PinConfigValue
decl_stmt|;
name|UINT16
name|PinTableLength
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|UINT16
modifier|*
name|PinTable
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_PIN_CONFIG
typedef|;
end_typedef

begin_comment
comment|/* Values for PinConfigType field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_PULL_UP
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_PULL_DOWN
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_DISABLE
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_HIGH_IMPEDANCE
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_BIAS_BUS_HOLD
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DRIVE_OPEN_DRAIN
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DRIVE_OPEN_SOURCE
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DRIVE_PUSH_PULL
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_DRIVE_STRENGTH
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_SLEW_RATE
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_INPUT_DEBOUNCE
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_PIN_CONFIG_INPUT_SCHMITT_TRIGGER
value|13
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_pin_group
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ProducerConsumer
decl_stmt|;
comment|/* For values, see Producer/Consumer above */
name|UINT16
name|PinTableLength
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|UINT16
modifier|*
name|PinTable
decl_stmt|;
name|ACPI_RESOURCE_LABEL
name|ResourceLabel
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_PIN_GROUP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_pin_group_function
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ProducerConsumer
decl_stmt|;
comment|/* For values, see Producer/Consumer above */
name|UINT8
name|Sharable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT16
name|FunctionNumber
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|ACPI_RESOURCE_LABEL
name|ResourceSourceLabel
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_PIN_GROUP_FUNCTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_pin_group_config
block|{
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ProducerConsumer
decl_stmt|;
comment|/* For values, see Producer/Consumer above */
name|UINT8
name|Sharable
decl_stmt|;
comment|/* For values, see Interrupt Attributes above */
name|UINT8
name|PinConfigType
decl_stmt|;
comment|/* For values, see PinConfigType above */
name|UINT32
name|PinConfigValue
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|ACPI_RESOURCE_LABEL
name|ResourceSourceLabel
decl_stmt|;
name|UINT8
modifier|*
name|VendorData
decl_stmt|;
block|}
name|ACPI_RESOURCE_PIN_GROUP_CONFIG
typedef|;
end_typedef

begin_comment
comment|/* ACPI_RESOURCE_TYPEs */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_IRQ
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_DMA
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_START_DEPENDENT
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_END_DEPENDENT
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_IO
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_FIXED_IO
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_VENDOR
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_END_TAG
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MEMORY24
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MEMORY32
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_FIXED_MEMORY32
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS16
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS32
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS64
value|13
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64
value|14
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_EXTENDED_IRQ
value|15
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_GENERIC_REGISTER
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_GPIO
value|17
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_FIXED_DMA
value|18
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_SERIAL_BUS
value|19
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_PIN_FUNCTION
value|20
end_define

begin_comment
comment|/* ACPI 6.2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_PIN_CONFIG
value|21
end_define

begin_comment
comment|/* ACPI 6.2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_PIN_GROUP
value|22
end_define

begin_comment
comment|/* ACPI 6.2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_PIN_GROUP_FUNCTION
value|23
end_define

begin_comment
comment|/* ACPI 6.2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_PIN_GROUP_CONFIG
value|24
end_define

begin_comment
comment|/* ACPI 6.2 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MAX
value|24
end_define

begin_comment
comment|/* Master union for resource descriptors */
end_comment

begin_typedef
typedef|typedef
union|union
name|acpi_resource_data
block|{
name|ACPI_RESOURCE_IRQ
name|Irq
decl_stmt|;
name|ACPI_RESOURCE_DMA
name|Dma
decl_stmt|;
name|ACPI_RESOURCE_START_DEPENDENT
name|StartDpf
decl_stmt|;
name|ACPI_RESOURCE_IO
name|Io
decl_stmt|;
name|ACPI_RESOURCE_FIXED_IO
name|FixedIo
decl_stmt|;
name|ACPI_RESOURCE_FIXED_DMA
name|FixedDma
decl_stmt|;
name|ACPI_RESOURCE_VENDOR
name|Vendor
decl_stmt|;
name|ACPI_RESOURCE_VENDOR_TYPED
name|VendorTyped
decl_stmt|;
name|ACPI_RESOURCE_END_TAG
name|EndTag
decl_stmt|;
name|ACPI_RESOURCE_MEMORY24
name|Memory24
decl_stmt|;
name|ACPI_RESOURCE_MEMORY32
name|Memory32
decl_stmt|;
name|ACPI_RESOURCE_FIXED_MEMORY32
name|FixedMemory32
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS16
name|Address16
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS32
name|Address32
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS64
name|Address64
decl_stmt|;
name|ACPI_RESOURCE_EXTENDED_ADDRESS64
name|ExtAddress64
decl_stmt|;
name|ACPI_RESOURCE_EXTENDED_IRQ
name|ExtendedIrq
decl_stmt|;
name|ACPI_RESOURCE_GENERIC_REGISTER
name|GenericReg
decl_stmt|;
name|ACPI_RESOURCE_GPIO
name|Gpio
decl_stmt|;
name|ACPI_RESOURCE_I2C_SERIALBUS
name|I2cSerialBus
decl_stmt|;
name|ACPI_RESOURCE_SPI_SERIALBUS
name|SpiSerialBus
decl_stmt|;
name|ACPI_RESOURCE_UART_SERIALBUS
name|UartSerialBus
decl_stmt|;
name|ACPI_RESOURCE_COMMON_SERIALBUS
name|CommonSerialBus
decl_stmt|;
name|ACPI_RESOURCE_PIN_FUNCTION
name|PinFunction
decl_stmt|;
name|ACPI_RESOURCE_PIN_CONFIG
name|PinConfig
decl_stmt|;
name|ACPI_RESOURCE_PIN_GROUP
name|PinGroup
decl_stmt|;
name|ACPI_RESOURCE_PIN_GROUP_FUNCTION
name|PinGroupFunction
decl_stmt|;
name|ACPI_RESOURCE_PIN_GROUP_CONFIG
name|PinGroupConfig
decl_stmt|;
comment|/* Common fields */
name|ACPI_RESOURCE_ADDRESS
name|Address
decl_stmt|;
comment|/* Common 16/32/64 address fields */
block|}
name|ACPI_RESOURCE_DATA
typedef|;
end_typedef

begin_comment
comment|/* Common resource header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource
block|{
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|ACPI_RESOURCE_DATA
name|Data
decl_stmt|;
block|}
name|ACPI_RESOURCE
typedef|;
end_typedef

begin_comment
comment|/* restore default alignment */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|ACPI_RS_SIZE_NO_DATA
value|8
end_define

begin_comment
comment|/* Id + Length fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_RS_SIZE_MIN
value|(UINT32) ACPI_ROUND_UP_TO_NATIVE_WORD (12)
end_define

begin_define
define|#
directive|define
name|ACPI_RS_SIZE
parameter_list|(
name|Type
parameter_list|)
value|(UINT32) (ACPI_RS_SIZE_NO_DATA + sizeof (Type))
end_define

begin_comment
comment|/* Macro for walking resource templates with multiple descriptors */
end_comment

begin_define
define|#
directive|define
name|ACPI_NEXT_RESOURCE
parameter_list|(
name|Res
parameter_list|)
define|\
value|ACPI_ADD_PTR (ACPI_RESOURCE, (Res), (Res)->Length)
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_pci_routing_table
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|Pin
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
comment|/* here for 64-bit alignment */
name|UINT32
name|SourceIndex
decl_stmt|;
name|char
name|Source
index|[
literal|4
index|]
decl_stmt|;
comment|/* pad to 64 bits so sizeof() works in all cases */
block|}
name|ACPI_PCI_ROUTING_TABLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACRESTYP_H__ */
end_comment

end_unit

