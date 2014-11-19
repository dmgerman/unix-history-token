begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: rsinfo - Dispatch and Info tables  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__RSINFO_C__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acresrc.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_RESOURCES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"rsinfo"
argument_list|)
end_macro

begin_comment
comment|/*  * Resource dispatch and information tables. Any new resource types (either  * Large or Small) must be reflected in each of these tables, so they are here  * in one place.  *  * The tables for Large descriptors are indexed by bits 6:0 of the AML  * descriptor type byte. The tables for Small descriptors are indexed by  * bits 6:3 of the descriptor byte. The tables for internal resource  * descriptors are indexed by the ACPI_RESOURCE_TYPE field.  */
end_comment

begin_comment
comment|/* Dispatch table for resource-to-AML (Set Resource) conversion functions */
end_comment

begin_decl_stmt
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_SetResourceDispatch
index|[]
init|=
block|{
name|AcpiRsSetIrq
block|,
comment|/* 0x00, ACPI_RESOURCE_TYPE_IRQ */
name|AcpiRsConvertDma
block|,
comment|/* 0x01, ACPI_RESOURCE_TYPE_DMA */
name|AcpiRsSetStartDpf
block|,
comment|/* 0x02, ACPI_RESOURCE_TYPE_START_DEPENDENT */
name|AcpiRsConvertEndDpf
block|,
comment|/* 0x03, ACPI_RESOURCE_TYPE_END_DEPENDENT */
name|AcpiRsConvertIo
block|,
comment|/* 0x04, ACPI_RESOURCE_TYPE_IO */
name|AcpiRsConvertFixedIo
block|,
comment|/* 0x05, ACPI_RESOURCE_TYPE_FIXED_IO */
name|AcpiRsSetVendor
block|,
comment|/* 0x06, ACPI_RESOURCE_TYPE_VENDOR */
name|AcpiRsConvertEndTag
block|,
comment|/* 0x07, ACPI_RESOURCE_TYPE_END_TAG */
name|AcpiRsConvertMemory24
block|,
comment|/* 0x08, ACPI_RESOURCE_TYPE_MEMORY24 */
name|AcpiRsConvertMemory32
block|,
comment|/* 0x09, ACPI_RESOURCE_TYPE_MEMORY32 */
name|AcpiRsConvertFixedMemory32
block|,
comment|/* 0x0A, ACPI_RESOURCE_TYPE_FIXED_MEMORY32 */
name|AcpiRsConvertAddress16
block|,
comment|/* 0x0B, ACPI_RESOURCE_TYPE_ADDRESS16 */
name|AcpiRsConvertAddress32
block|,
comment|/* 0x0C, ACPI_RESOURCE_TYPE_ADDRESS32 */
name|AcpiRsConvertAddress64
block|,
comment|/* 0x0D, ACPI_RESOURCE_TYPE_ADDRESS64 */
name|AcpiRsConvertExtAddress64
block|,
comment|/* 0x0E, ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64 */
name|AcpiRsConvertExtIrq
block|,
comment|/* 0x0F, ACPI_RESOURCE_TYPE_EXTENDED_IRQ */
name|AcpiRsConvertGenericReg
block|,
comment|/* 0x10, ACPI_RESOURCE_TYPE_GENERIC_REGISTER */
name|AcpiRsConvertGpio
block|,
comment|/* 0x11, ACPI_RESOURCE_TYPE_GPIO */
name|AcpiRsConvertFixedDma
block|,
comment|/* 0x12, ACPI_RESOURCE_TYPE_FIXED_DMA */
name|NULL
block|,
comment|/* 0x13, ACPI_RESOURCE_TYPE_SERIAL_BUS - Use subtype table below */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dispatch tables for AML-to-resource (Get Resource) conversion functions */
end_comment

begin_decl_stmt
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_GetResourceDispatch
index|[]
init|=
block|{
comment|/* Small descriptors */
name|NULL
block|,
comment|/* 0x00, Reserved */
name|NULL
block|,
comment|/* 0x01, Reserved */
name|NULL
block|,
comment|/* 0x02, Reserved */
name|NULL
block|,
comment|/* 0x03, Reserved */
name|AcpiRsGetIrq
block|,
comment|/* 0x04, ACPI_RESOURCE_NAME_IRQ */
name|AcpiRsConvertDma
block|,
comment|/* 0x05, ACPI_RESOURCE_NAME_DMA */
name|AcpiRsGetStartDpf
block|,
comment|/* 0x06, ACPI_RESOURCE_NAME_START_DEPENDENT */
name|AcpiRsConvertEndDpf
block|,
comment|/* 0x07, ACPI_RESOURCE_NAME_END_DEPENDENT */
name|AcpiRsConvertIo
block|,
comment|/* 0x08, ACPI_RESOURCE_NAME_IO */
name|AcpiRsConvertFixedIo
block|,
comment|/* 0x09, ACPI_RESOURCE_NAME_FIXED_IO */
name|AcpiRsConvertFixedDma
block|,
comment|/* 0x0A, ACPI_RESOURCE_NAME_FIXED_DMA */
name|NULL
block|,
comment|/* 0x0B, Reserved */
name|NULL
block|,
comment|/* 0x0C, Reserved */
name|NULL
block|,
comment|/* 0x0D, Reserved */
name|AcpiRsGetVendorSmall
block|,
comment|/* 0x0E, ACPI_RESOURCE_NAME_VENDOR_SMALL */
name|AcpiRsConvertEndTag
block|,
comment|/* 0x0F, ACPI_RESOURCE_NAME_END_TAG */
comment|/* Large descriptors */
name|NULL
block|,
comment|/* 0x00, Reserved */
name|AcpiRsConvertMemory24
block|,
comment|/* 0x01, ACPI_RESOURCE_NAME_MEMORY24 */
name|AcpiRsConvertGenericReg
block|,
comment|/* 0x02, ACPI_RESOURCE_NAME_GENERIC_REGISTER */
name|NULL
block|,
comment|/* 0x03, Reserved */
name|AcpiRsGetVendorLarge
block|,
comment|/* 0x04, ACPI_RESOURCE_NAME_VENDOR_LARGE */
name|AcpiRsConvertMemory32
block|,
comment|/* 0x05, ACPI_RESOURCE_NAME_MEMORY32 */
name|AcpiRsConvertFixedMemory32
block|,
comment|/* 0x06, ACPI_RESOURCE_NAME_FIXED_MEMORY32 */
name|AcpiRsConvertAddress32
block|,
comment|/* 0x07, ACPI_RESOURCE_NAME_ADDRESS32 */
name|AcpiRsConvertAddress16
block|,
comment|/* 0x08, ACPI_RESOURCE_NAME_ADDRESS16 */
name|AcpiRsConvertExtIrq
block|,
comment|/* 0x09, ACPI_RESOURCE_NAME_EXTENDED_IRQ */
name|AcpiRsConvertAddress64
block|,
comment|/* 0x0A, ACPI_RESOURCE_NAME_ADDRESS64 */
name|AcpiRsConvertExtAddress64
block|,
comment|/* 0x0B, ACPI_RESOURCE_NAME_EXTENDED_ADDRESS64 */
name|AcpiRsConvertGpio
block|,
comment|/* 0x0C, ACPI_RESOURCE_NAME_GPIO */
name|NULL
block|,
comment|/* 0x0D, Reserved */
name|NULL
block|,
comment|/* 0x0E, ACPI_RESOURCE_NAME_SERIAL_BUS - Use subtype table below */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Subtype table for SerialBus -- I2C, SPI, and UART */
end_comment

begin_decl_stmt
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_ConvertResourceSerialBusDispatch
index|[]
init|=
block|{
name|NULL
block|,
name|AcpiRsConvertI2cSerialBus
block|,
name|AcpiRsConvertSpiSerialBus
block|,
name|AcpiRsConvertUartSerialBus
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_comment
comment|/* Dispatch table for resource dump functions */
end_comment

begin_decl_stmt
name|ACPI_RSDUMP_INFO
modifier|*
name|AcpiGbl_DumpResourceDispatch
index|[]
init|=
block|{
name|AcpiRsDumpIrq
block|,
comment|/* ACPI_RESOURCE_TYPE_IRQ */
name|AcpiRsDumpDma
block|,
comment|/* ACPI_RESOURCE_TYPE_DMA */
name|AcpiRsDumpStartDpf
block|,
comment|/* ACPI_RESOURCE_TYPE_START_DEPENDENT */
name|AcpiRsDumpEndDpf
block|,
comment|/* ACPI_RESOURCE_TYPE_END_DEPENDENT */
name|AcpiRsDumpIo
block|,
comment|/* ACPI_RESOURCE_TYPE_IO */
name|AcpiRsDumpFixedIo
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_IO */
name|AcpiRsDumpVendor
block|,
comment|/* ACPI_RESOURCE_TYPE_VENDOR */
name|AcpiRsDumpEndTag
block|,
comment|/* ACPI_RESOURCE_TYPE_END_TAG */
name|AcpiRsDumpMemory24
block|,
comment|/* ACPI_RESOURCE_TYPE_MEMORY24 */
name|AcpiRsDumpMemory32
block|,
comment|/* ACPI_RESOURCE_TYPE_MEMORY32 */
name|AcpiRsDumpFixedMemory32
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_MEMORY32 */
name|AcpiRsDumpAddress16
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS16 */
name|AcpiRsDumpAddress32
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS32 */
name|AcpiRsDumpAddress64
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS64 */
name|AcpiRsDumpExtAddress64
block|,
comment|/* ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64 */
name|AcpiRsDumpExtIrq
block|,
comment|/* ACPI_RESOURCE_TYPE_EXTENDED_IRQ */
name|AcpiRsDumpGenericReg
block|,
comment|/* ACPI_RESOURCE_TYPE_GENERIC_REGISTER */
name|AcpiRsDumpGpio
block|,
comment|/* ACPI_RESOURCE_TYPE_GPIO */
name|AcpiRsDumpFixedDma
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_DMA */
name|NULL
block|,
comment|/* ACPI_RESOURCE_TYPE_SERIAL_BUS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_RSDUMP_INFO
modifier|*
name|AcpiGbl_DumpSerialBusDispatch
index|[]
init|=
block|{
name|NULL
block|,
name|AcpiRsDumpI2cSerialBus
block|,
comment|/* AML_RESOURCE_I2C_BUS_TYPE */
name|AcpiRsDumpSpiSerialBus
block|,
comment|/* AML_RESOURCE_SPI_BUS_TYPE */
name|AcpiRsDumpUartSerialBus
block|,
comment|/* AML_RESOURCE_UART_BUS_TYPE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Base sizes for external AML resource descriptors, indexed by internal type.  * Includes size of the descriptor header (1 byte for small descriptors,  * 3 bytes for large descriptors)  */
end_comment

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_AmlResourceSizes
index|[]
init|=
block|{
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_IRQ
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_IRQ (optional Byte 3 always created) */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_DMA
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_DMA */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_START_DEPENDENT
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_START_DEPENDENT (optional Byte 1 always created) */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_END_DEPENDENT
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_END_DEPENDENT */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_IO
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_IO */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_FIXED_IO
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_IO */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_VENDOR_SMALL
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_VENDOR */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_END_TAG
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_END_TAG */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_MEMORY24
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_MEMORY24 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_MEMORY32
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_MEMORY32 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_FIXED_MEMORY32
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_MEMORY32 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_ADDRESS16
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS16 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_ADDRESS32
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS32 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_ADDRESS64
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_ADDRESS64 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_EXTENDED_ADDRESS64
argument_list|)
block|,
comment|/*ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64 */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_EXTENDED_IRQ
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_EXTENDED_IRQ */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_GENERIC_REGISTER
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_GENERIC_REGISTER */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_GPIO
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_GPIO */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_FIXED_DMA
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_FIXED_DMA */
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_COMMON_SERIALBUS
argument_list|)
block|,
comment|/* ACPI_RESOURCE_TYPE_SERIAL_BUS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_ResourceStructSizes
index|[]
init|=
block|{
comment|/* Small descriptors */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_IRQ
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_DMA
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_START_DEPENDENT
argument_list|)
block|,
name|ACPI_RS_SIZE_MIN
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_IO
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_FIXED_IO
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_FIXED_DMA
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_VENDOR
argument_list|)
block|,
name|ACPI_RS_SIZE_MIN
block|,
comment|/* Large descriptors */
literal|0
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_MEMORY24
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_GENERIC_REGISTER
argument_list|)
block|,
literal|0
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_VENDOR
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_MEMORY32
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_FIXED_MEMORY32
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_ADDRESS32
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_ADDRESS16
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_EXTENDED_IRQ
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_ADDRESS64
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_EXTENDED_ADDRESS64
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_GPIO
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
argument|ACPI_RESOURCE_COMMON_SERIALBUS
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_AmlResourceSerialBusSizes
index|[]
init|=
block|{
literal|0
block|,
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_I2C_SERIALBUS
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_SPI_SERIALBUS
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_UART_SERIALBUS
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_ResourceStructSerialBusSizes
index|[]
init|=
block|{
literal|0
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_I2C_SERIALBUS
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_SPI_SERIALBUS
argument_list|)
block|,
name|ACPI_RS_SIZE
argument_list|(
name|ACPI_RESOURCE_UART_SERIALBUS
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

end_unit

