begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actables.h - ACPI table management  *       $Revision: 22 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights  * reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTABLES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTABLES_H__
end_define

begin_comment
comment|/* Used in AcpiTbMapAcpiTable for size parameter if table header is to be used */
end_comment

begin_define
define|#
directive|define
name|SIZE_IN_HEADER
value|0
end_define

begin_function_decl
name|ACPI_STATUS
name|AcpiTbHandleToObject
parameter_list|(
name|UINT16
name|TableId
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbget - Table "get" routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetTablePtr
parameter_list|(
name|ACPI_TABLE_TYPE
name|TableType
parameter_list|,
name|UINT32
name|Instance
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|TablePtrLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetTable
parameter_list|(
name|void
modifier|*
name|PhysicalAddress
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|BufferPtr
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbVerifyRsdp
parameter_list|(
name|void
modifier|*
name|RSDP_PhysicalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetTableFacs
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|BufferPtr
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbgetall - Get all firmware ACPI tables  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetAllTables
parameter_list|(
name|UINT32
name|NumberOfTables
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|BufferPtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbinstall - Table installation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbInstallTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|TablePtr
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbRecognizeTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|TablePtr
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbInitTableDescriptor
parameter_list|(
name|ACPI_TABLE_TYPE
name|TableType
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbremove - Table removal and deletion  */
end_comment

begin_function_decl
name|void
name|AcpiTbDeleteAcpiTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbDeleteAcpiTable
parameter_list|(
name|ACPI_TABLE_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbDeleteSingleTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_TABLE_DESC
modifier|*
name|AcpiTbUninstallTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbFreeAcpiTablesOfType
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbrsd - RSDP, RSDT utilities  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetTableRsdt
parameter_list|(
name|UINT32
modifier|*
name|NumberOfTables
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
modifier|*
name|AcpiTbScanMemoryForRsdp
parameter_list|(
name|UINT8
modifier|*
name|StartAddress
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbFindRsdp
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbutils - common table utilities  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiTbSystemTablePointer
parameter_list|(
name|void
modifier|*
name|Where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbMapAcpiTable
parameter_list|(
name|void
modifier|*
name|PhysicalAddress
parameter_list|,
name|UINT32
modifier|*
name|Size
parameter_list|,
name|void
modifier|*
modifier|*
name|LogicalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbVerifyTableChecksum
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|TableHeader
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiTbChecksum
parameter_list|(
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbValidateTableHeader
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|TableHeader
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTABLES_H__ */
end_comment

end_unit

