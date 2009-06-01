begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acresrc.h - Resource Manager function prototypes  *       $Revision: 1.60 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,   * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
file|<contrib/dev/acpica/amlresrc.h>
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

begin_define
define|#
directive|define
name|ACPI_RSC_INITGET
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_INITSET
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_FLAGINIT
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_1BITFLAG
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_2BITFLAG
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_COUNT16
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_LENGTH
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_MOVE8
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_MOVE16
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_MOVE32
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_MOVE64
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_SET8
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_DATA8
value|13
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_ADDRESS
value|14
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_SOURCE
value|15
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_SOURCEX
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_BITMASK
value|17
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_BITMASK16
value|18
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_EXIT_NE
value|19
end_define

begin_define
define|#
directive|define
name|ACPI_RSC_EXIT_LE
value|20
end_define

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

begin_define
define|#
directive|define
name|ACPI_RSD_TITLE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_LITERAL
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_STRING
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_UINT8
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_UINT16
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_UINT32
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_UINT64
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_1BITFLAG
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_2BITFLAG
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_SHORTLIST
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_LONGLIST
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_DWORDLIST
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_ADDRESS
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RSD_SOURCE
value|13
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
name|ACPI_RSCONVERT_INFO
modifier|*
name|AcpiGbl_GetResourceDispatch
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
name|ACPI_RESOURCE
modifier|*
name|LinkedListBuffer
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
name|LinkedListBuffer
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

begin_comment
comment|/*  * rsdump  */
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

