begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   If a GUID-defined section is encountered when doing section extraction,    the PEI Foundation or the EFI_PEI_FILE_LOADER_PPI instance    calls the appropriate instance of the GUIDed Section Extraction PPI    to extract the section stream contained therein.     Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_GUIDED_SECTION_EXTRACTION_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_GUIDED_SECTION_EXTRACTION_PPI_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Typically, protocol interface structures are identified
end_comment

begin_comment
comment|// by associating them with a GUID. Each instance of
end_comment

begin_comment
comment|// a protocol with a given GUID must have
end_comment

begin_comment
comment|// the same interface structure. While all instances of
end_comment

begin_comment
comment|// the GUIDed Section Extraction PPI must have
end_comment

begin_comment
comment|// the same interface structure, they do not all have
end_comment

begin_comment
comment|// te same GUID. The GUID that is associated with
end_comment

begin_comment
comment|// an instance of the GUIDed Section Extraction Protocol
end_comment

begin_comment
comment|// is used to correlate it with the GUIDed section type
end_comment

begin_comment
comment|// that it is intended to process.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI
name|EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Processes the input section and returns the data contained therein    along with the authentication status.    The ExtractSection() function processes the input section and   returns a pointer to the section contents. If the section being   extracted does not require processing (if the section   GuidedSectionHeader.Attributes has the   EFI_GUIDED_SECTION_PROCESSING_REQUIRED field cleared), then   OutputBuffer is just updated to point to the start of the   section's contents. Otherwise, *Buffer must be allocated   from PEI permanent memory.    @param This                   Indicates the EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI                                 instance.   @param InputSection           Buffer containing the input GUIDed section to be                                 processed.   @param OutputBuffer           *OutputBuffer is allocated from PEI permanent memory                                 and contains the new section stream.   @param OutputSize             A pointer to a caller-allocated UINTN in which                                 the size of *OutputBuffer allocation is stored.                                 If the function returns anything other than                                 EFI_SUCCESS, the value of *OutputSize is undefined.   @param AuthenticationStatus   A pointer to a caller-allocated UINT32 that indicates                                 the authentication status of the output buffer.                                 If the input section's                                 GuidedSectionHeader.Attributes field has the                                 EFI_GUIDED_SECTION_AUTH_STATUS_VALID bit as clear,                                 *AuthenticationStatus must return zero. These bits                                 reflect the status of the extraction operation.                                 If the function returns anything other than EFI_SUCCESS,                                 the value of *AuthenticationStatus is undefined.      @retval EFI_SUCCESS           The InputSection was successfully processed and the                                 section contents were returned.   @retval EFI_OUT_OF_RESOURCES  The system has insufficient resources to process the request.   @retval EFI_INVALID_PARAMETER The GUID in InputSection does not match this instance of the                                 GUIDed Section Extraction PPI. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_EXTRACT_GUIDED_SECTION
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|InputSection
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|OutputBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|OutputSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// If a GUID-defined section is encountered when doing section extraction,
end_comment

begin_comment
comment|/// the PEI Foundation or the EFI_PEI_FILE_LOADER_PPI instance
end_comment

begin_comment
comment|/// calls the appropriate instance of the GUIDed Section
end_comment

begin_comment
comment|/// Extraction PPI to extract the section stream contained
end_comment

begin_comment
comment|/// therein.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI
block|{
name|EFI_PEI_EXTRACT_GUIDED_SECTION
name|ExtractSection
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

