begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Defines Windows SMM Security Mitigation Table   @ https://msdn.microsoft.com/windows/hardware/drivers/bringup/acpi-system-description-tables#wsmt    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials    are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINDOWS_SMM_SECURITY_MITIGATION_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_WINDOWS_SMM_SECURITY_MITIGATION_TABLE_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi.h>
end_include

begin_define
define|#
directive|define
name|EFI_ACPI_WINDOWS_SMM_SECURITY_MITIGATION_TABLE_SIGNATURE
value|SIGNATURE_32('W', 'S', 'M', 'T')
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_define
define|#
directive|define
name|EFI_WSMT_TABLE_REVISION
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ProtectionFlags
decl_stmt|;
block|}
name|EFI_ACPI_WSMT_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_WSMT_PROTECTION_FLAGS_FIXED_COMM_BUFFERS
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_WSMT_PROTECTION_FLAGS_COMM_BUFFER_NESTED_PTR_PROTECTION
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_WSMT_PROTECTION_FLAGS_SYSTEM_RESOURCE_PROTECTION
value|0x4
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

