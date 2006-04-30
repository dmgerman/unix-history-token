begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: amlresrc.h - AML resource descriptors  *              $Revision: 25 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2004, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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

begin_define
define|#
directive|define
name|ASL_RESNAME_ADDRESS
value|"_ADR"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_ALIGNMENT
value|"_ALN"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_ADDRESSSPACE
value|"_ASI"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_BASEADDRESS
value|"_BAS"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_BUSMASTER
value|"_BM_"
end_define

begin_comment
comment|/* Master(1), Slave(0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_DECODE
value|"_DEC"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_DMA
value|"_DMA"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_DMATYPE
value|"_TYP"
end_define

begin_comment
comment|/* Compatible(0), A(1), B(2), F(3) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_GRANULARITY
value|"_GRA"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_INTERRUPT
value|"_INT"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_INTERRUPTLEVEL
value|"_LL_"
end_define

begin_comment
comment|/* ActiveLo(1), ActiveHi(0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_INTERRUPTSHARE
value|"_SHR"
end_define

begin_comment
comment|/* Shareable(1), NoShare(0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_INTERRUPTTYPE
value|"_HE_"
end_define

begin_comment
comment|/* Edge(1), Level(0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_LENGTH
value|"_LEN"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_MEMATTRIBUTES
value|"_MTP"
end_define

begin_comment
comment|/* Memory(0), Reserved(1), ACPI(2), NVS(3) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_MEMTYPE
value|"_MEM"
end_define

begin_comment
comment|/* NonCache(0), Cacheable(1) Cache+combine(2), Cache+prefetch(3) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_MAXADDR
value|"_MAX"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_MINADDR
value|"_MIN"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_MAXTYPE
value|"_MAF"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_MINTYPE
value|"_MIF"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_REGISTERBITOFFSET
value|"_RBO"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_REGISTERBITWIDTH
value|"_RBW"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_RANGETYPE
value|"_RNG"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_READWRITETYPE
value|"_RW_"
end_define

begin_comment
comment|/* ReadOnly(0), Writeable (1) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_TRANSLATION
value|"_TRA"
end_define

begin_define
define|#
directive|define
name|ASL_RESNAME_TRANSTYPE
value|"_TRS"
end_define

begin_comment
comment|/* Sparse(1), Dense(0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_TYPE
value|"_TTP"
end_define

begin_comment
comment|/* Translation(1), Static (0) */
end_comment

begin_define
define|#
directive|define
name|ASL_RESNAME_XFERTYPE
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
comment|/*  * Resource descriptors defined in the ACPI specification.  *  * Packing/alignment must be BYTE because these descriptors  * are used to overlay the AML byte stream.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|asl_irq_format_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|IrqMask
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_IRQ_FORMAT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_irq_noflags_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|IrqMask
decl_stmt|;
block|}
name|ASL_IRQ_NOFLAGS_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_dma_format_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|DmaChannelMask
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_DMA_FORMAT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_start_dependent_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ASL_START_DEPENDENT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_start_dependent_noprio_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
block|}
name|ASL_START_DEPENDENT_NOPRIO_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_end_dependent_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
block|}
name|ASL_END_DEPENDENT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_io_port_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT16
name|AddressMin
decl_stmt|;
name|UINT16
name|AddressMax
decl_stmt|;
name|UINT8
name|Alignment
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|ASL_IO_PORT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_fixed_io_port_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|BaseAddress
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|ASL_FIXED_IO_PORT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_small_vendor_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|VendorDefined
index|[
literal|7
index|]
decl_stmt|;
block|}
name|ASL_SMALL_VENDOR_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_end_tag_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
block|}
name|ASL_END_TAG_DESC
typedef|;
end_typedef

begin_comment
comment|/* LARGE descriptors */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|asl_memory_24_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT16
name|AddressMin
decl_stmt|;
name|UINT16
name|AddressMax
decl_stmt|;
name|UINT16
name|Alignment
decl_stmt|;
name|UINT16
name|RangeLength
decl_stmt|;
block|}
name|ASL_MEMORY_24_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_large_vendor_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|VendorDefined
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ASL_LARGE_VENDOR_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_memory_32_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT32
name|AddressMin
decl_stmt|;
name|UINT32
name|AddressMax
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ASL_MEMORY_32_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_fixed_memory_32_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Information
decl_stmt|;
name|UINT32
name|BaseAddress
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ASL_FIXED_MEMORY_32_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_qword_address_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|ResourceType
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|SpecificFlags
decl_stmt|;
name|UINT64
name|Granularity
decl_stmt|;
name|UINT64
name|AddressMin
decl_stmt|;
name|UINT64
name|AddressMax
decl_stmt|;
name|UINT64
name|TranslationOffset
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
name|UINT8
name|OptionalFields
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ASL_QWORD_ADDRESS_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_dword_address_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|ResourceType
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|SpecificFlags
decl_stmt|;
name|UINT32
name|Granularity
decl_stmt|;
name|UINT32
name|AddressMin
decl_stmt|;
name|UINT32
name|AddressMax
decl_stmt|;
name|UINT32
name|TranslationOffset
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
name|UINT8
name|OptionalFields
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ASL_DWORD_ADDRESS_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_word_address_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|ResourceType
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|SpecificFlags
decl_stmt|;
name|UINT16
name|Granularity
decl_stmt|;
name|UINT16
name|AddressMin
decl_stmt|;
name|UINT16
name|AddressMax
decl_stmt|;
name|UINT16
name|TranslationOffset
decl_stmt|;
name|UINT16
name|AddressLength
decl_stmt|;
name|UINT8
name|OptionalFields
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ASL_WORD_ADDRESS_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_extended_xrupt_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|TableLength
decl_stmt|;
name|UINT32
name|InterruptNumber
index|[
literal|1
index|]
decl_stmt|;
comment|/* ResSourceIndex, ResSource optional fields follow */
block|}
name|ASL_EXTENDED_XRUPT_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asl_general_register_desc
block|{
name|UINT8
name|DescriptorType
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
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
name|Reserved
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ASL_GENERAL_REGISTER_DESC
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
name|asl_resource_desc
block|{
name|ASL_IRQ_FORMAT_DESC
name|Irq
decl_stmt|;
name|ASL_DMA_FORMAT_DESC
name|Dma
decl_stmt|;
name|ASL_START_DEPENDENT_DESC
name|Std
decl_stmt|;
name|ASL_END_DEPENDENT_DESC
name|End
decl_stmt|;
name|ASL_IO_PORT_DESC
name|Iop
decl_stmt|;
name|ASL_FIXED_IO_PORT_DESC
name|Fio
decl_stmt|;
name|ASL_SMALL_VENDOR_DESC
name|Smv
decl_stmt|;
name|ASL_END_TAG_DESC
name|Et
decl_stmt|;
name|ASL_MEMORY_24_DESC
name|M24
decl_stmt|;
name|ASL_LARGE_VENDOR_DESC
name|Lgv
decl_stmt|;
name|ASL_MEMORY_32_DESC
name|M32
decl_stmt|;
name|ASL_FIXED_MEMORY_32_DESC
name|F32
decl_stmt|;
name|ASL_QWORD_ADDRESS_DESC
name|Qas
decl_stmt|;
name|ASL_DWORD_ADDRESS_DESC
name|Das
decl_stmt|;
name|ASL_WORD_ADDRESS_DESC
name|Was
decl_stmt|;
name|ASL_EXTENDED_XRUPT_DESC
name|Exx
decl_stmt|;
name|ASL_GENERAL_REGISTER_DESC
name|Grg
decl_stmt|;
name|UINT32
name|U32Item
decl_stmt|;
name|UINT16
name|U16Item
decl_stmt|;
name|UINT8
name|U8Item
decl_stmt|;
block|}
name|ASL_RESOURCE_DESC
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

