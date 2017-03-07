begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Vector Handoff Info PPI that describes an array of   interrupt and/or exception vectors that are in use and need to persist.    This is an optional PPI that may be produced by SEC. If present, it provides   a description of the interrupt and/or exception vectors that were established   in the SEC Phase and need to persist into PEI and DXE.     Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VECTOR_HANDOFF_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__VECTOR_HANDOFF_INFO_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: EFI_PEI_VECTOR_HANDOFF_INFO_PPI_GUID can also be used in the PEI Phase
end_comment

begin_comment
comment|/// to build a GUIDed HOB that contains an array of EFI_VECTOR_HANDOFF_INFO.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_VECTOR_HANDOFF_INFO_PPI_GUID
define|\
value|{ 0x3cd652b4, 0x6d33, 0x4dce, { 0x89, 0xdb, 0x83, 0xdf, 0x97, 0x66, 0xfc, 0xca }}
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Vector Handoff Info Attributes
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_VECTOR_HANDOFF_DO_NOT_HOOK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_VECTOR_HANDOFF_HOOK_BEFORE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_VECTOR_HANDOFF_HOOK_AFTER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_VECTOR_HANDOFF_LAST_ENTRY
value|0x80000000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_VECTOR_HANDOFF_INFO entries that describes the interrupt and/or
end_comment

begin_comment
comment|/// exception vectors in use in the PEI Phase.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// The interrupt or exception vector that is in use and must be preserved.
comment|//
name|UINT32
name|VectorNumber
decl_stmt|;
comment|//
comment|// A bitmask that describes the attributes ofthe interrupt or exception vector.
comment|//
name|UINT32
name|Attribute
decl_stmt|;
comment|//
comment|// The GUID identifies the party who created the entry. For the
comment|// EFI_VECTOR_HANDOFF_DO_NOT_HOOK case, this establishes the single owner.
comment|//
name|EFI_GUID
name|Owner
decl_stmt|;
block|}
name|EFI_VECTOR_HANDOFF_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a description of the interrupt and/or exception vectors that
end_comment

begin_comment
comment|/// were established in the SEC Phase and need to persist into PEI and DXE.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_PEI_VECTOR_HANDOFF_INFO_PPI
block|{
comment|//
comment|// Pointer to an array of interrupt and /or exception vectors.
comment|//
name|EFI_VECTOR_HANDOFF_INFO
modifier|*
name|Info
decl_stmt|;
block|}
name|EFI_PEI_VECTOR_HANDOFF_INFO_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVectorHandoffInfoPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

