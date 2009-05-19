begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: rsinfo - Dispatch and Info tables  *              $Revision: 1.8 $  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|__RSINFO_C__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acresrc.h>
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
comment|/* 0x10, ACPI_RESOURCE_TYPE_GENERIC_REGISTER */
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
name|NULL
block|,
comment|/* 0x0A, Reserved */
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
comment|/* 0x0B, ACPI_RESOURCE_NAME_EXTENDED_ADDRESS64 */
block|}
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
expr|sizeof
operator|(
name|AML_RESOURCE_GENERIC_REGISTER
operator|)
comment|/* ACPI_RESOURCE_TYPE_GENERIC_REGISTER */
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
argument|ACPI_RESOURCE_EXTENDED_ADDRESS64
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

end_unit

