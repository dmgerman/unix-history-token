begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides the protocol to install or remove an ACPI   table from a platform.       Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPI_TABLE_H___
end_ifndef

begin_define
define|#
directive|define
name|__ACPI_TABLE_H___
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_TABLE_PROTOCOL_GUID
define|\
value|{ 0xffe06bdd, 0x6107, 0x46a6, { 0x7b, 0xb2, 0x5a, 0x9c, 0x7e, 0xc5, 0x27, 0x5c }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ACPI_TABLE_PROTOCOL
name|EFI_ACPI_TABLE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**    The InstallAcpiTable() function allows a caller to install an      ACPI table. When successful, the table will be linked by the      RSDT/XSDT. AcpiTableBuffer specifies the table to be installed.      InstallAcpiTable() will make a copy of the table and insert the      copy into the RSDT/XSDT. InstallAcpiTable() must insert the new      table at the end of the RSDT/XSDT. To prevent namespace      collision, ACPI tables may be created using UEFI ACPI table      format. If this protocol is used to install a table with a   signature already present in the system, the new table will not   replace the existing table. It is a platform implementation   decision to add a new table with a signature matching an   existing table or disallow duplicate table signatures and   return EFI_ACCESS_DENIED. On successful output, TableKey is      initialized with a unique key. Its value may be used in a      subsequent call to UninstallAcpiTable to remove an ACPI table.      If an EFI application is running at the time of this call, the      relevant EFI_CONFIGURATION_TABLE pointer to the RSDT is no      longer considered valid.        @param This                 A pointer to a EFI_ACPI_TABLE_PROTOCOL.    @param AcpiTableBuffer      A pointer to a buffer containing the                               ACPI table to be installed.    @param AcpiTableBufferSize  Specifies the size, in bytes, of                               the AcpiTableBuffer buffer.     @param TableKey             Returns a key to refer to the ACPI table.      @retval EFI_SUCCESS           The table was successfully inserted      @retval EFI_INVALID_PARAMETER Either AcpiTableBuffer is NULL,                                 TableKey is NULL, or                                 AcpiTableBufferSize and the size                                 field embedded in the ACPI table                                 pointed to by AcpiTableBuffer                                 are not in sync.      @retval EFI_OUT_OF_RESOURCES  Insufficient resources exist to                                 complete the request.   @retval EFI_ACCESS_DENIED     The table signature matches a table already                                 present in the system and platform policy                                 does not allow duplicate tables of this type.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_TABLE_INSTALL_ACPI_TABLE
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_TABLE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|AcpiTableBuffer
parameter_list|,
name|IN
name|UINTN
name|AcpiTableBufferSize
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|TableKey
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**      The UninstallAcpiTable() function allows a caller to remove an   ACPI table. The routine will remove its reference from the   RSDT/XSDT. A table is referenced by the TableKey parameter   returned from a prior call to InstallAcpiTable(). If an EFI   application is running at the time of this call, the relevant   EFI_CONFIGURATION_TABLE pointer to the RSDT is no longer   considered valid.    @param This                   A pointer to a EFI_ACPI_TABLE_PROTOCOL.    @param TableKey               Specifies the table to uninstall. The key was                                 returned from InstallAcpiTable().    @retval EFI_SUCCESS           The table was successfully inserted    @retval EFI_NOT_FOUND         TableKey does not refer to a valid key                                 for a table entry.    @retval EFI_OUT_OF_RESOURCES  Insufficient resources exist to                                 complete the request.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE
function_decl|)
parameter_list|(
name|IN
name|EFI_ACPI_TABLE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|TableKey
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_ACPI_TABLE_PROTOCOL provides the ability for a component
end_comment

begin_comment
comment|/// to install and uninstall ACPI tables from a platform.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ACPI_TABLE_PROTOCOL
block|{
name|EFI_ACPI_TABLE_INSTALL_ACPI_TABLE
name|InstallAcpiTable
decl_stmt|;
name|EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE
name|UninstallAcpiTable
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAcpiTableProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

