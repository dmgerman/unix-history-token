begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: amlresrc.h - AML resource descriptors  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2012, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
name|ACPI_RESTAG_DEBOUNCETIME
value|"_DBT"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_DECODE
value|"_DEC"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_DEVICEPOLARITY
value|"_DPL"
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
name|ACPI_RESTAG_DRIVESTRENGTH
value|"_DRS"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_ENDIANNESS
value|"_END"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_FLOWCONTROL
value|"_FLC"
end_define

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
name|ACPI_RESTAG_IORESTRICTION
value|"_IOR"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_LENGTH
value|"_LEN"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_LINE
value|"_LIN"
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
name|ACPI_RESTAG_MODE
value|"_MOD"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_PARITY
value|"_PAR"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_PHASE
value|"_PHA"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_PIN
value|"_PIN"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_PINCONFIG
value|"_PPI"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_POLARITY
value|"_POL"
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
name|ACPI_RESTAG_LENGTH_RX
value|"_RXL"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_LENGTH_TX
value|"_TXL"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_SLAVEMODE
value|"_SLV"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_SPEED
value|"_SPE"
end_define

begin_define
define|#
directive|define
name|ACPI_RESTAG_STOPBITS
value|"_STB"
end_define

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

begin_define
define|#
directive|define
name|ACPI_RESTAG_VENDORDATA
value|"_VEN"
end_define

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
name|ASL_RDESC_FIXED_DMA_SIZE
value|0x05
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

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_fixed_dma
block|{
name|AML_RESOURCE_SMALL_HEADER_COMMON
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
name|AML_RESOURCE_FIXED_DMA
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

begin_comment
comment|/* General Flags for address space resource descriptors */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_FLAG_DEC
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_FLAG_MIF
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_FLAG_MAF
value|8
end_define

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
comment|/* Common descriptor for GpioInt and GpioIo (ACPI 5.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_gpio
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|UINT8
name|RevisionId
decl_stmt|;
name|UINT8
name|ConnectionType
decl_stmt|;
name|UINT16
name|Flags
decl_stmt|;
name|UINT16
name|IntFlags
decl_stmt|;
name|UINT8
name|PinConfig
decl_stmt|;
name|UINT16
name|DriveStrength
decl_stmt|;
name|UINT16
name|DebounceTimeout
decl_stmt|;
name|UINT16
name|PinTableOffset
decl_stmt|;
name|UINT8
name|ResSourceIndex
decl_stmt|;
name|UINT16
name|ResSourceOffset
decl_stmt|;
name|UINT16
name|VendorOffset
decl_stmt|;
name|UINT16
name|VendorLength
decl_stmt|;
comment|/*      * Optional fields follow immediately:      * 1) PIN list (Words)      * 2) Resource Source String      * 3) Vendor Data bytes      */
block|}
name|AML_RESOURCE_GPIO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_GPIO_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_comment
comment|/* Values for ConnectionType above */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_GPIO_TYPE_INT
value|0
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_GPIO_TYPE_IO
value|1
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_MAX_GPIOTYPE
value|1
end_define

begin_comment
comment|/* Common preamble for all serial descriptors (ACPI 5.0) */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_SERIAL_COMMON
define|\
value|UINT8                           RevisionId; \     UINT8                           ResSourceIndex; \     UINT8                           Type; \     UINT8                           Flags; \     UINT16                          TypeSpecificFlags; \     UINT8                           TypeRevisionId; \     UINT16                          TypeDataLength;
end_define

begin_comment
unit|\
comment|/* Values for the type field above */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_I2C_SERIALBUSTYPE
value|1
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_SPI_SERIALBUSTYPE
value|2
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_UART_SERIALBUSTYPE
value|3
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_MAX_SERIALBUSTYPE
value|3
end_define

begin_define
define|#
directive|define
name|AML_RESOURCE_VENDOR_SERIALBUSTYPE
value|192
end_define

begin_comment
comment|/* Vendor defined is 0xC0-0xFF (NOT SUPPORTED) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_common_serialbus
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_SERIAL_COMMON
block|}
name|AML_RESOURCE_COMMON_SERIALBUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_i2c_serialbus
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_SERIAL_COMMON
name|UINT32
name|ConnectionSpeed
decl_stmt|;
name|UINT16
name|SlaveAddress
decl_stmt|;
comment|/*      * Optional fields follow immediately:      * 1) Vendor Data bytes      * 2) Resource Source String      */
block|}
name|AML_RESOURCE_I2C_SERIALBUS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_I2C_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_I2C_TYPE_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_I2C_MIN_DATA_LEN
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_spi_serialbus
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_SERIAL_COMMON
name|UINT32
name|ConnectionSpeed
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
comment|/*      * Optional fields follow immediately:      * 1) Vendor Data bytes      * 2) Resource Source String      */
block|}
name|AML_RESOURCE_SPI_SERIALBUS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_SPI_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_SPI_TYPE_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_SPI_MIN_DATA_LEN
value|9
end_define

begin_typedef
typedef|typedef
struct|struct
name|aml_resource_uart_serialbus
block|{
name|AML_RESOURCE_LARGE_HEADER_COMMON
name|AML_RESOURCE_SERIAL_COMMON
name|UINT32
name|DefaultBaudRate
decl_stmt|;
name|UINT16
name|RxFifoSize
decl_stmt|;
name|UINT16
name|TxFifoSize
decl_stmt|;
name|UINT8
name|Parity
decl_stmt|;
name|UINT8
name|LinesEnabled
decl_stmt|;
comment|/*      * Optional fields follow immediately:      * 1) Vendor Data bytes      * 2) Resource Source String      */
block|}
name|AML_RESOURCE_UART_SERIALBUS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AML_RESOURCE_UART_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_UART_TYPE_REVISION
value|1
end_define

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_define
define|#
directive|define
name|AML_RESOURCE_UART_MIN_DATA_LEN
value|10
end_define

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
name|AML_RESOURCE_FIXED_DMA
name|FixedDma
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
name|AML_RESOURCE_GPIO
name|Gpio
decl_stmt|;
name|AML_RESOURCE_I2C_SERIALBUS
name|I2cSerialBus
decl_stmt|;
name|AML_RESOURCE_SPI_SERIALBUS
name|SpiSerialBus
decl_stmt|;
name|AML_RESOURCE_UART_SERIALBUS
name|UartSerialBus
decl_stmt|;
name|AML_RESOURCE_COMMON_SERIALBUS
name|CommonSerialBus
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

