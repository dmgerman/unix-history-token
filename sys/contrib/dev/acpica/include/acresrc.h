begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acresrc.h - Resource Manager function prototypes  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACRESRC_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACRESRC_H__
end_define

begin_comment
comment|/* Need the AML resource descriptor structs */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/amlresrc.h>
end_include

begin_comment
comment|/*  * If possible, pack the following structures to byte alignment, since we  * don't care about performance for debug output. Two cases where we cannot  * pack the structures:  *  * 1) Hardware does not support misaligned memory transfers  * 2) Compiler does not support pointers within packed structures  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACPI_PACKED_POINTERS_NOT_SUPPORTED
argument_list|)
operator|)
end_if

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
comment|/*  * Individual entry for the resource conversion tables  */
end_comment

begin_typedef
typedef|typedef
specifier|const
struct|struct
name|acpi_rsconvert_info
block|{
name|UINT8
name|Opcode
decl_stmt|;
name|UINT8
name|ResourceOffset
decl_stmt|;
name|UINT8
name|AmlOffset
decl_stmt|;
name|UINT8
name|Value
decl_stmt|;
block|}
name|ACPI_RSCONVERT_INFO
typedef|;
end_typedef

begin_comment
comment|/* Resource conversion opcodes */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACPI_RSC_INITGET
init|=
literal|0
block|,
name|ACPI_RSC_INITSET
block|,
name|ACPI_RSC_FLAGINIT
block|,
name|ACPI_RSC_1BITFLAG
block|,
name|ACPI_RSC_2BITFLAG
block|,
name|ACPI_RSC_3BITFLAG
block|,
name|ACPI_RSC_ADDRESS
block|,
name|ACPI_RSC_BITMASK
block|,
name|ACPI_RSC_BITMASK16
block|,
name|ACPI_RSC_COUNT
block|,
name|ACPI_RSC_COUNT16
block|,
name|ACPI_RSC_COUNT_GPIO_PIN
block|,
name|ACPI_RSC_COUNT_GPIO_RES
block|,
name|ACPI_RSC_COUNT_GPIO_VEN
block|,
name|ACPI_RSC_COUNT_SERIAL_RES
block|,
name|ACPI_RSC_COUNT_SERIAL_VEN
block|,
name|ACPI_RSC_DATA8
block|,
name|ACPI_RSC_EXIT_EQ
block|,
name|ACPI_RSC_EXIT_LE
block|,
name|ACPI_RSC_EXIT_NE
block|,
name|ACPI_RSC_LENGTH
block|,
name|ACPI_RSC_MOVE_GPIO_PIN
block|,
name|ACPI_RSC_MOVE_GPIO_RES
block|,
name|ACPI_RSC_MOVE_SERIAL_RES
block|,
name|ACPI_RSC_MOVE_SERIAL_VEN
block|,
name|ACPI_RSC_MOVE8
block|,
name|ACPI_RSC_MOVE16
block|,
name|ACPI_RSC_MOVE32
block|,
name|ACPI_RSC_MOVE64
block|,
name|ACPI_RSC_SET8
block|,
name|ACPI_RSC_SOURCE
block|,
name|ACPI_RSC_SOURCEX
block|}
name|ACPI_RSCONVERT_OPCODES
typedef|;
end_typedef

begin_comment
comment|/* Resource Conversion sub-opcodes */
end_comment

begin_define
define|#
directive|define
name|ACPI_RSC_COMPARE_AML_LENGTH
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_COMPARE_VALUE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_TABLE_SIZE
parameter_list|(
name|d
parameter_list|)
value|(sizeof (d) / sizeof (ACPI_RSCONVERT_INFO))
end_define

begin_define
define|#
directive|define
name|ACPI_RS_OFFSET
parameter_list|(
name|f
parameter_list|)
value|(UINT8) ACPI_OFFSET (ACPI_RESOURCE,f)
end_define

begin_define
define|#
directive|define
name|AML_OFFSET
parameter_list|(
name|f
parameter_list|)
value|(UINT8) ACPI_OFFSET (AML_RESOURCE,f)
end_define

begin_comment
comment|/*  * Individual entry for the resource dump tables  */
end_comment

begin_typedef
typedef|typedef
specifier|const
struct|struct
name|acpi_rsdump_info
block|{
name|UINT8
name|Opcode
decl_stmt|;
name|UINT8
name|Offset
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|Pointer
decl_stmt|;
block|}
name|ACPI_RSDUMP_INFO
typedef|;
end_typedef

begin_comment
comment|/* Values for the Opcode field above */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACPI_RSD_TITLE
init|=
literal|0
block|,
name|ACPI_RSD_1BITFLAG
block|,
name|ACPI_RSD_2BITFLAG
block|,
name|ACPI_RSD_3BITFLAG
block|,
name|ACPI_RSD_ADDRESS
block|,
name|ACPI_RSD_DWORDLIST
block|,
name|ACPI_RSD_LITERAL
block|,
name|ACPI_RSD_LONGLIST
block|,
name|ACPI_RSD_SHORTLIST
block|,
name|ACPI_RSD_SHORTLISTX
block|,
name|ACPI_RSD_SOURCE
block|,
name|ACPI_RSD_STRING
block|,
name|ACPI_RSD_UINT8
block|,
name|ACPI_RSD_UINT16
block|,
name|ACPI_RSD_UINT32
block|,
name|ACPI_RSD_UINT64
block|,
name|ACPI_RSD_WORDLIST
block|}
name|ACPI_RSDUMP_OPCODES
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
comment|/* Resource tables indexed by internal resource type */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_AmlResourceSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_AmlResourceSerialBusSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_SetResourceDispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Resource tables indexed by raw AML resource descriptor type */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_ResourceStructSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_ResourceStructSerialBusSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_GetResourceDispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_ConvertResourceSerialBusDispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|acpi_vendor_walk_info
block|{
name|ACPI_VENDOR_UUID
modifier|*
name|Uuid
decl_stmt|;
name|ACPI_BUFFER
modifier|*
name|Buffer
decl_stmt|;
name|ACPI_STATUS
name|Status
decl_stmt|;
block|}
name|ACPI_VENDOR_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * rscreate  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiRsCreateResourceList
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|AmlBuffer
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|OutputBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsCreateAmlResources
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|ResourceList
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|OutputBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsCreatePciRoutingTable
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|PackageObject
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|OutputBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rsutils  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetPrtMethodData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetCrsMethodData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetPrsMethodData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetMethodData
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|char
modifier|*
name|Path
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsSetSrsMethodData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetAeiMethodData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rscalc  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetListLength
parameter_list|(
name|UINT8
modifier|*
name|AmlBuffer
parameter_list|,
name|UINT32
name|AmlBufferLength
parameter_list|,
name|ACPI_SIZE
modifier|*
name|SizeNeeded
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetAmlLength
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|ResourceList
parameter_list|,
name|ACPI_SIZE
name|ResourceListSize
parameter_list|,
name|ACPI_SIZE
modifier|*
name|SizeNeeded
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsGetPciRoutingTableLength
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|PackageObject
parameter_list|,
name|ACPI_SIZE
modifier|*
name|BufferSizeNeeded
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsConvertAmlToResources
parameter_list|(
name|UINT8
modifier|*
name|Aml
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Offset
parameter_list|,
name|UINT8
name|ResourceIndex
parameter_list|,
name|void
modifier|*
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsConvertResourcesToAml
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|ACPI_SIZE
name|AmlSizeNeeded
parameter_list|,
name|UINT8
modifier|*
name|OutputBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rsaddr  */
end_comment

begin_function_decl
name|void
name|AcpiRsSetAddressCommon
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|,
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiRsGetAddressCommon
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rsmisc  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiRsConvertAmlToResource
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|,
name|ACPI_RSCONVERT_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRsConvertResourceToAml
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|,
name|ACPI_RSCONVERT_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rsutils  */
end_comment

begin_function_decl
name|void
name|AcpiRsMoveData
parameter_list|(
name|void
modifier|*
name|Destination
parameter_list|,
name|void
modifier|*
name|Source
parameter_list|,
name|UINT16
name|ItemCount
parameter_list|,
name|UINT8
name|MoveType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiRsDecodeBitmask
parameter_list|(
name|UINT16
name|Mask
parameter_list|,
name|UINT8
modifier|*
name|List
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AcpiRsEncodeBitmask
parameter_list|(
name|UINT8
modifier|*
name|List
parameter_list|,
name|UINT8
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_RS_LENGTH
name|AcpiRsGetResourceSource
parameter_list|(
name|ACPI_RS_LENGTH
name|ResourceLength
parameter_list|,
name|ACPI_RS_LENGTH
name|MinimumLength
parameter_list|,
name|ACPI_RESOURCE_SOURCE
modifier|*
name|ResourceSource
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|,
name|char
modifier|*
name|StringPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_RSDESC_SIZE
name|AcpiRsSetResourceSource
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|,
name|ACPI_RS_LENGTH
name|MinimumLength
parameter_list|,
name|ACPI_RESOURCE_SOURCE
modifier|*
name|ResourceSource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiRsSetResourceHeader
parameter_list|(
name|UINT8
name|DescriptorType
parameter_list|,
name|ACPI_RSDESC_SIZE
name|TotalLength
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiRsSetResourceLength
parameter_list|(
name|ACPI_RSDESC_SIZE
name|TotalLength
parameter_list|,
name|AML_RESOURCE
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * rsdump  */
end_comment

begin_function_decl
name|void
name|AcpiRsDumpResourceList
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiRsDumpIrqList
parameter_list|(
name|UINT8
modifier|*
name|RouteTable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Resource conversion tables  */
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertDma
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertEndDpf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertIo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertFixedIo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertEndTag
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertMemory24
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertGenericReg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertMemory32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertFixedMemory32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertAddress32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertAddress16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertExtIrq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertAddress64
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertExtAddress64
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertGpio
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertFixedDma
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertI2cSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertSpiSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsConvertUartSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These resources require separate get/set tables */
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsGetIrq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsGetStartDpf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsGetVendorSmall
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsGetVendorLarge
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsSetIrq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsSetStartDpf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSCONVERT_INFO
name|AcpiRsSetVendor
index|[]
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
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_comment
comment|/*  * rsinfo  */
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
modifier|*
name|AcpiGbl_DumpResourceDispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
modifier|*
name|AcpiGbl_DumpSerialBusDispatch
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * rsdumpinfo  */
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpIrq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpPrt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpDma
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpStartDpf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpEndDpf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpIo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpIoFlags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpFixedIo
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpVendor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpEndTag
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpMemory24
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpMemory32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpMemoryFlags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpFixedMemory32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpAddress16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpAddress32
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpAddress64
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpExtAddress64
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpExtIrq
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpGenericReg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpGpio
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpFixedDma
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpCommonSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpI2cSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpSpiSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpUartSerialBus
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_RSDUMP_INFO
name|AcpiRsDumpGeneralFlags
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACRESRC_H__ */
end_comment

end_unit

