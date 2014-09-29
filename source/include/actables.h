begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actables.h - ACPI table management  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

begin_function_decl
name|ACPI_STATUS
name|AcpiAllocateRootTable
parameter_list|(
name|UINT32
name|InitialTableCount
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbxfroot - Root pointer utilities  */
end_comment

begin_function_decl
name|UINT32
name|AcpiTbGetRsdpLength
parameter_list|(
name|ACPI_TABLE_RSDP
modifier|*
name|Rsdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbValidateRsdp
parameter_list|(
name|ACPI_TABLE_RSDP
modifier|*
name|Rsdp
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

begin_comment
comment|/*  * tbdata - table data structure management  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetNextRootIndex
parameter_list|(
name|UINT32
modifier|*
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbInitTableDescriptor
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT8
name|Flags
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbAcquireTempTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT8
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbReleaseTempTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbValidateTempTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbVerifyTempTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiTbIsTableLoaded
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbSetTableLoadedFlag
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|BOOLEAN
name|IsLoaded
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbfadt - FADT parse/convert/validate  */
end_comment

begin_function_decl
name|void
name|AcpiTbParseFadt
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbCreateLocalFadt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbfind - find ACPI table  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbFindTable
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|,
name|char
modifier|*
name|OemId
parameter_list|,
name|char
modifier|*
name|OemTableId
parameter_list|,
name|UINT32
modifier|*
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbinstal - Table removal and deletion  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbResizeRootTableList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbValidateTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbInvalidateTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbOverrideTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|OldTableDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbAcquireTable
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|TableDesc
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|TablePtr
parameter_list|,
name|UINT32
modifier|*
name|TableLength
parameter_list|,
name|UINT8
modifier|*
name|TableFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbReleaseTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|TableLength
parameter_list|,
name|UINT8
name|TableFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbInstallStandardTable
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT8
name|Flags
parameter_list|,
name|BOOLEAN
name|Reload
parameter_list|,
name|BOOLEAN
name|Override
parameter_list|,
name|UINT32
modifier|*
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbStoreTable
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT8
name|Flags
parameter_list|,
name|UINT32
modifier|*
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
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
name|AcpiTbTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbDeleteNamespaceByOwner
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbAllocateOwnerId
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbReleaseOwnerId
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbGetOwnerId
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_OWNER_ID
modifier|*
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tbutils - table manager utilities  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiTbInitializeFacs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiTbTablesLoaded
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbPrintTableHeader
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|Header
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiTbChecksum
parameter_list|(
name|UINT8
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
name|AcpiTbVerifyChecksum
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbCheckDsdtHeader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_TABLE_HEADER
modifier|*
name|AcpiTbCopyDsdt
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiTbInstallTableWithOverride
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_TABLE_DESC
modifier|*
name|NewTableDesc
parameter_list|,
name|BOOLEAN
name|Override
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbInstallFixedTable
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|char
modifier|*
name|Signature
parameter_list|,
name|UINT32
name|TableIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTbParseRootTable
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|RsdpAddress
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

