begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HSTI_DXE_H_
end_ifndef

begin_define
define|#
directive|define
name|_HSTI_DXE_H_
end_define

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Hsti.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/AdapterInformation.h>
end_include

begin_define
define|#
directive|define
name|HSTI_AIP_PRIVATE_SIGNATURE
value|SIGNATURE_32('H', 'S', 'T', 'I')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
name|LIST_ENTRY
name|Link
decl_stmt|;
name|EFI_ADAPTER_INFORMATION_PROTOCOL
name|Aip
decl_stmt|;
name|VOID
modifier|*
name|Hsti
decl_stmt|;
name|UINTN
name|HstiSize
decl_stmt|;
name|UINTN
name|HstiMaxSize
decl_stmt|;
block|}
name|HSTI_AIP_PRIVATE_DATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HSTI_AIP_PRIVATE_DATA_FROM_THIS
parameter_list|(
name|a
parameter_list|)
define|\
value|CR (a, \       HSTI_AIP_PRIVATE_DATA, \       Aip, \       HSTI_AIP_PRIVATE_SIGNATURE \       )
end_define

begin_define
define|#
directive|define
name|HSTI_DEFAULT_ERROR_STRING_LEN
value|255
end_define

begin_decl_stmt
specifier|extern
name|EFI_ADAPTER_INFORMATION_PROTOCOL
name|mAdapterInformationProtocol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   Return if input HSTI data follows HSTI specification.    @param HstiData  HSTI data   @param HstiSize  HSTI size    @retval TRUE  HSTI data follows HSTI specification.   @retval FALSE HSTI data does not follow HSTI specification. **/
end_comment

begin_function_decl
name|BOOLEAN
name|InternalHstiIsValidTable
parameter_list|(
name|IN
name|VOID
modifier|*
name|HstiData
parameter_list|,
name|IN
name|UINTN
name|HstiSize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

