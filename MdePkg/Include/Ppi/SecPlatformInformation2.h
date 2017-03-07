begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Sec Platform Information2 PPI.    This service is the primary handoff state into the PEI Foundation.   This service abstracts platform-specific information for many CPU's.  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced from PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SEC_PLATFORM_INFORMATION2_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__SEC_PLATFORM_INFORMATION2_PPI_H__
end_define

begin_include
include|#
directive|include
file|<Ppi/SecPlatformInformation.h>
end_include

begin_define
define|#
directive|define
name|EFI_SEC_PLATFORM_INFORMATION2_GUID
define|\
value|{ \     0x9e9f374b, 0x8f16, 0x4230, {0x98, 0x24, 0x58, 0x46, 0xee, 0x76, 0x6a, 0x97 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SEC_PLATFORM_INFORMATION2_PPI
name|EFI_SEC_PLATFORM_INFORMATION2_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SEC_PLATFORM_INFORMATION_CPU.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|CpuLocation
decl_stmt|;
name|EFI_SEC_PLATFORM_INFORMATION_RECORD
name|InfoRecord
decl_stmt|;
block|}
name|EFI_SEC_PLATFORM_INFORMATION_CPU
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SEC_PLATFORM_INFORMATION_RECORD2.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The CPU location would be the local APIC ID
comment|///
name|UINT32
name|NumberOfCpus
decl_stmt|;
name|EFI_SEC_PLATFORM_INFORMATION_CPU
name|CpuInstance
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_SEC_PLATFORM_INFORMATION_RECORD2
typedef|;
end_typedef

begin_comment
comment|/**   This interface conveys state information out of the Security (SEC) phase into PEI.    This service is published by the SEC phase.    @param  PeiServices                The pointer to the PEI Services Table.   @param  StructureSize              The pointer to the variable describing size of the input buffer.   @param  PlatformInformationRecord2 The pointer to the EFI_SEC_PLATFORM_INFORMATION_RECORD2.    @retval EFI_SUCCESS                The data was successfully returned.   @retval EFI_BUFFER_TOO_SMALL       The buffer was too small. The current buffer size needed to                                      hold the record is returned in StructureSize.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SEC_PLATFORM_INFORMATION2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|StructureSize
parameter_list|,
name|OUT
name|EFI_SEC_PLATFORM_INFORMATION_RECORD2
modifier|*
name|PlatformInformationRecord2
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This service abstracts platform-specific information for many CPU's.
end_comment

begin_comment
comment|/// It is the multi-processor equivalent of PlatformInformation for
end_comment

begin_comment
comment|/// implementations that synchronize some, if not all CPU's in the SEC phase.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SEC_PLATFORM_INFORMATION2_PPI
block|{
name|EFI_SEC_PLATFORM_INFORMATION2
name|PlatformInformation2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSecPlatformInformation2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

