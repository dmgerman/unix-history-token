begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: amlresrc.h - AML resource descriptors  *              $Revision: 1.40 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_comment
comment|/* acpisrc:StructDefs -- for acpisrc conversion */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AMLRESRC_H
end_ifndef

begin_define
define|#
directive|define
name|__AMLRESRC_H
end_define

begin_comment
comment|/*  * Resource descriptor tags, as defined in the ACPI specification.  * Used to symbolically reference fields within a descriptor.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_ADDRESS
value|"_ADR"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_ALIGNMENT
value|"_ALN"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_ADDRESSSPACE
value|"_ASI"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_ACCESSSIZE
value|"_ASZ"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_TYPESPECIFICATTRIBUTES
value|"_ATT"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_BASEADDRESS
value|"_BAS"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_BUSMASTER
value|"_BM_"
end_define

begin_comment
comment|/* Master(1), Slave(0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_DECODE
value|"_DEC"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_DMA
value|"_DMA"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_DMATYPE
value|"_TYP"
end_define

begin_comment
comment|/* Compatible(0), A(1), B(2), F(3) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_GRANULARITY
value|"_GRA"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_INTERRUPT
value|"_INT"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_INTERRUPTLEVEL
value|"_LL_"
end_define

begin_comment
comment|/* ActiveLo(1), ActiveHi(0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_INTERRUPTSHARE
value|"_SHR"
end_define

begin_comment
comment|/* Shareable(1), NoShare(0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_INTERRUPTTYPE
value|"_HE_"
end_define

begin_comment
comment|/* Edge(1), Level(0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_LENGTH
value|"_LEN"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_MEMATTRIBUTES
value|"_MTP"
end_define

begin_comment
comment|/* Memory(0), Reserved(1), ACPI(2), NVS(3) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_MEMTYPE
value|"_MEM"
end_define

begin_comment
comment|/* NonCache(0), Cacheable(1) Cache+combine(2), Cache+prefetch(3) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_MAXADDR
value|"_MAX"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_MINADDR
value|"_MIN"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_MAXTYPE
value|"_MAF"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_MINTYPE
value|"_MIF"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_REGISTERBITOFFSET
value|"_RBO"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_REGISTERBITWIDTH
value|"_RBW"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_RANGETYPE
value|"_RNG"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_READWRITETYPE
value|"_RW_"
end_define

begin_comment
comment|/* ReadOnly(0), Writeable (1) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_TRANSLATION
value|"_TRA"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_TRANSTYPE
value|"_TRS"
end_define

begin_comment
comment|/* Sparse(1), Dense(0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_TYPE
value|"_TTP"
end_define

begin_comment
comment|/* Translation(1), Static (0) */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESTAG_XFERTYPE
value|"_SIZ"
end_define

begin_comment
comment|/* 8(0), 8And16(1), 16(2) */
end_comment

begin_comment
comment|/* Default sizes for "small" resource descriptors */
end_comment

begin_define
define|#
directive|define
name|ASL_RDESC_IRQ_SIZE
value|0x02
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_DMA_SIZE
value|0x02
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_ST_DEPEND_SIZE
value|0x00
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_END_DEPEND_SIZE
value|0x00
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_IO_SIZE
value|0x07
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_FIXED_IO_SIZE
value|0x03
end_define

begin_define
define|#
directive|define
name|ASL_RDESC_END_TAG_SIZE
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|asl_resource_node
block|{
name|UINT32
name|BufferLength
decl_stmt|;
name|void
modifier|*
name|Buffer
decl_stmt|;
name|struct
name|asl_resource_node
modifier|*
name|Next
decl_stmt|;
block|}
name|ASL_RESOURCE_NODE
typedef|;
end_typedef

begin_comment
comment|/* Macros used to generate AML resource length fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_AML_SIZE_LARGE
parameter_list|(
name|r
parameter_list|)
value|(sizeof (r) - sizeof (AML_RESOURCE_LARGE_HEADER))
end_define

begin_define
define|#
directive|define
name|ACPI_AML_SIZE_SMALL
parameter_list|(
name|r
parameter_list|)
value|(sizeof (r) - sizeof (AML_RESOURCE_SMALL_HEADER))
end_define

begin_comment
comment|/*  * Resource descriptors defined in the ACPI specification.  *  * Packing/alignment must be BYTE because these descriptors  * are used to overlay the raw AML byte stream.  */
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
comment|/*  * SMALL descriptors  */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_SMALL_HEADER_COMMON
define|\
value|UINT8                           DescriptorType;
end_define

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_small_header
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
block|}
name|AML_RESOURCE_SMALL_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_irq
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT16
name|IrqMask
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|AML_RESOURCE_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_irq_noflags
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT16
name|IrqMask
decl_stmt|;
block|}
name|AML_RESOURCE_IRQ_NOFLAGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_dma
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT8
name|DmaChannelMask
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|AML_RESOURCE_DMA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_start_dependent
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT8
name|Flags
decl_stmt|;
block|}
name|AML_RESOURCE_START_DEPENDENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_start_dependent_noprio
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
block|}
name|AML_RESOURCE_START_DEPENDENT_NOPRIO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_end_dependent
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
block|}
name|AML_RESOURCE_END_DEPENDENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_io
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT8
name|Flags
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
name|UINT8
name|Alignment
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
block|}
name|AML_RESOURCE_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_fixed_io
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT16
name|Address
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
block|}
name|AML_RESOURCE_FIXED_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_vendor_small
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
block|}
name|AML_RESOURCE_VENDOR_SMALL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_end_tag
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
name|UINT8
name|Checksum
decl_stmt|;
block|}
name|AML_RESOURCE_END_TAG
typedef|;
end_typedef

begin_comment
comment|/*  * LARGE descriptors  */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_LARGE_HEADER_COMMON
define|\
value|UINT8                           DescriptorType;\     UINT16                          ResourceLength;
end_define

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_large_header
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
block|}
name|AML_RESOURCE_LARGE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_memory24
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|Flags
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
name|AML_RESOURCE_MEMORY24
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_vendor_large
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
block|}
name|AML_RESOURCE_VENDOR_LARGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_memory32
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|Flags
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
name|AML_RESOURCE_MEMORY32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_fixed_memory32
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|Flags
decl_stmt|;
name|UINT32
name|Address
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|AML_RESOURCE_FIXED_MEMORY32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_ADDRESS_COMMON
define|\
value|UINT8                           ResourceType; \     UINT8                           Flags; \     UINT8                           SpecificFlags;
end_define

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_address
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_ADDRESS_COMMON
block|}
name|AML_RESOURCE_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_extended_address64
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_ADDRESS_COMMON
name|UINT8
name|RevisionID
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
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
name|UINT64
name|TypeSpecific
decl_stmt|;
block|}
name|AML_RESOURCE_EXTENDED_ADDRESS64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_EXTENDED_ADDRESS_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_address64
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_ADDRESS_COMMON
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
name|AML_RESOURCE_ADDRESS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_address32
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_ADDRESS_COMMON
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
name|AML_RESOURCE_ADDRESS32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_address16
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_ADDRESS_COMMON
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
name|AML_RESOURCE_ADDRESS16
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_extended_irq
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|InterruptCount
decl_stmt|;
name|UINT32
name|Interrupts
index|[
literal|1
index|]
decl_stmt|;
comment|/* ResSourceIndex, ResSource optional fields follow */
block|}
name|AML_RESOURCE_EXTENDED_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_generic_register
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|AddressSpaceId
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
comment|/* ACPI 3.0, was previously Reserved */
name|UINT64
name|Address
decl_stmt|;
block|}
name|AML_RESOURCE_GENERIC_REGISTER
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

begin_comment
comment|/* Union of all resource descriptors, so we can allocate the worst case */
end_comment

begin_typedef
typedef|typedef
union|union
name|aml_resource
block|{
comment|/* Descriptor headers */
name|UINT8
name|DescriptorType
decl_stmt|;
name|AML_RESOURCE_SMALL_HEADER
name|SmallHeader
decl_stmt|;
name|AML_RESOURCE_LARGE_HEADER
name|LargeHeader
decl_stmt|;
comment|/* Small resource descriptors */
name|AML_RESOURCE_IRQ
name|Irq
decl_stmt|;
name|AML_RESOURCE_DMA
name|Dma
decl_stmt|;
name|AML_RESOURCE_START_DEPENDENT
name|StartDpf
decl_stmt|;
name|AML_RESOURCE_END_DEPENDENT
name|EndDpf
decl_stmt|;
name|AML_RESOURCE_IO
name|Io
decl_stmt|;
name|AML_RESOURCE_FIXED_IO
name|FixedIo
decl_stmt|;
name|AML_RESOURCE_VENDOR_SMALL
name|VendorSmall
decl_stmt|;
name|AML_RESOURCE_END_TAG
name|EndTag
decl_stmt|;
comment|/* Large resource descriptors */
name|AML_RESOURCE_MEMORY24
name|Memory24
decl_stmt|;
name|AML_RESOURCE_GENERIC_REGISTER
name|GenericReg
decl_stmt|;
name|AML_RESOURCE_VENDOR_LARGE
name|VendorLarge
decl_stmt|;
name|AML_RESOURCE_MEMORY32
name|Memory32
decl_stmt|;
name|AML_RESOURCE_FIXED_MEMORY32
name|FixedMemory32
decl_stmt|;
name|AML_RESOURCE_ADDRESS16
name|Address16
decl_stmt|;
name|AML_RESOURCE_ADDRESS32
name|Address32
decl_stmt|;
name|AML_RESOURCE_ADDRESS64
name|Address64
decl_stmt|;
name|AML_RESOURCE_EXTENDED_ADDRESS64
name|ExtAddress64
decl_stmt|;
name|AML_RESOURCE_EXTENDED_IRQ
name|ExtendedIrq
decl_stmt|;
comment|/* Utility overlays */
name|AML_RESOURCE_ADDRESS
name|Address
decl_stmt|;
name|UINT32
name|DwordItem
decl_stmt|;
name|UINT16
name|WordItem
decl_stmt|;
name|UINT8
name|ByteItem
decl_stmt|;
block|}
name|AML_RESOURCE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

