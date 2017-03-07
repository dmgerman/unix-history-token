begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Configuration Protocol as defined in the PI 1.2 specification.    This protocol is used to:   1) report the portions of SMRAM regions which cannot be used for the SMRAM heap.   2) register the SMM Foundation entry point with the processor code. The entry      point will be invoked by the SMM processor entry code.      Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_CONFIGURATION_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_CONFIGURATION_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiSmmCis.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_CONFIGURATION_PROTOCOL_GUID
define|\
value|{ \     0x26eeb3de, 0xb689, 0x492e, {0x80, 0xf0, 0xbe, 0x8b, 0xd7, 0xda, 0x4b, 0xa7 }  \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Structure describing a SMRAM region which cannot be used for the SMRAM heap.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SMM_RESERVED_SMRAM_REGION
block|{
comment|///
comment|/// Starting address of the reserved SMRAM area, as it appears while SMRAM is open.
comment|/// Ignored if SmramReservedSize is 0.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|SmramReservedStart
decl_stmt|;
comment|///
comment|/// Number of bytes occupied by the reserved SMRAM area. A size of zero indicates the
comment|/// last SMRAM area.
comment|///
name|UINT64
name|SmramReservedSize
decl_stmt|;
block|}
name|EFI_SMM_RESERVED_SMRAM_REGION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_CONFIGURATION_PROTOCOL
name|EFI_SMM_CONFIGURATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Register the SMM Foundation entry point.      This function registers the SMM Foundation entry point with the processor code. This entry point    will be invoked by the SMM Processor entry code.    @param[in] This                The EFI_SMM_CONFIGURATION_PROTOCOL instance.   @param[in] SmmEntryPoint       SMM Foundation entry point.      @retval EFI_SUCCESS            Success to register SMM Entry Point.   @retval EFI_INVALID_PARAMETER  SmmEntryPoint is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_REGISTER_SMM_ENTRY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMM_ENTRY_POINT
name|SmmEntryPoint
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI SMM Configuration Protocol is a mandatory protocol published by a DXE CPU driver to
end_comment

begin_comment
comment|/// indicate which areas within SMRAM are reserved for use by the CPU for any purpose,
end_comment

begin_comment
comment|/// such as stack, save state or SMM entry point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The RegisterSmmEntry() function allows the SMM IPL DXE driver to register the SMM
end_comment

begin_comment
comment|/// Foundation entry point with the SMM entry vector code.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_CONFIGURATION_PROTOCOL
block|{
comment|///
comment|/// A pointer to an array SMRAM ranges used by the initial SMM entry code.
comment|///
name|EFI_SMM_RESERVED_SMRAM_REGION
modifier|*
name|SmramReservedRegions
decl_stmt|;
name|EFI_SMM_REGISTER_SMM_ENTRY
name|RegisterSmmEntry
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmConfigurationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

