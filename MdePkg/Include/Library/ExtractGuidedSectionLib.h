begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This library provides common functions to process the different guided section data.       This library provides functions to process GUIDed sections of FFS files.  Handlers may    be registered to decode GUIDed sections of FFS files.  Services are provided to determine    the set of supported section GUIDs, collection information about a specific GUIDed section,    and decode a specific GUIDed section.       A library instance that produces this library class may be used to produce a    EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI or a EFI_GUIDED_SECTION_EXTRACTION_PROTOCOL    providing a simple method to extend the number of GUIDed sections types a platform supports.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTRACT_GUIDED_SECTION_H__
end_ifndef

begin_define
define|#
directive|define
name|__EXTRACT_GUIDED_SECTION_H__
end_define

begin_comment
comment|/**   Examines a GUIDed section and returns the size of the decoded buffer and the   size of an optional scratch buffer required to actually decode the data in a GUIDed section.    Examines a GUIDed section specified by InputSection.     If GUID for InputSection does not match the GUID that this handler supports,   then RETURN_UNSUPPORTED is returned.     If the required information can not be retrieved from InputSection,   then RETURN_INVALID_PARAMETER is returned.   If the GUID of InputSection does match the GUID that this handler supports,   then the size required to hold the decoded buffer is returned in OututBufferSize,   the size of an optional scratch buffer is returned in ScratchSize, and the Attributes field   from EFI_GUID_DEFINED_SECTION header of InputSection is returned in SectionAttribute.      If InputSection is NULL, then ASSERT().   If OutputBufferSize is NULL, then ASSERT().   If ScratchBufferSize is NULL, then ASSERT().   If SectionAttribute is NULL, then ASSERT().     @param[in]  InputSection       A pointer to a GUIDed section of an FFS formatted file.   @param[out] OutputBufferSize   A pointer to the size, in bytes, of an output buffer required                                  if the buffer specified by InputSection were decoded.   @param[out] ScratchBufferSize  A pointer to the size, in bytes, required as scratch space                                  if the buffer specified by InputSection were decoded.   @param[out] SectionAttribute   A pointer to the attributes of the GUIDed section. See the Attributes                                  field of EFI_GUID_DEFINED_SECTION in the PI Specification.    @retval  RETURN_SUCCESS            The information about InputSection was returned.   @retval  RETURN_UNSUPPORTED        The section specified by InputSection does not match the GUID this handler supports.   @retval  RETURN_INVALID_PARAMETER  The information can not be retrieved from the section specified by InputSection.  **/
end_comment

begin_typedef
typedef|typedef
name|RETURN_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER
function_decl|)
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|InputSection
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|OutputBufferSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ScratchBufferSize
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|SectionAttribute
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Decodes a GUIDed section into a caller allocated output buffer.      Decodes the GUIDed section specified by InputSection.     If GUID for InputSection does not match the GUID that this handler supports, then RETURN_UNSUPPORTED is returned.     If the data in InputSection can not be decoded, then RETURN_INVALID_PARAMETER is returned.   If the GUID of InputSection does match the GUID that this handler supports, then InputSection   is decoded into the buffer specified by OutputBuffer and the authentication status of this   decode operation is returned in AuthenticationStatus.  If the decoded buffer is identical to the   data in InputSection, then OutputBuffer is set to point at the data in InputSection.  Otherwise,   the decoded data will be placed in caller allocated buffer specified by OutputBuffer.      If InputSection is NULL, then ASSERT().   If OutputBuffer is NULL, then ASSERT().   If ScratchBuffer is NULL and this decode operation requires a scratch buffer, then ASSERT().   If AuthenticationStatus is NULL, then ASSERT().     @param[in]  InputSection  A pointer to a GUIDed section of an FFS formatted file.   @param[out] OutputBuffer  A pointer to a buffer that contains the result of a decode operation.    @param[out] ScratchBuffer A caller allocated buffer that may be required by this function                             as a scratch buffer to perform the decode operation.    @param[out] AuthenticationStatus                              A pointer to the authentication status of the decoded output buffer.                             See the definition of authentication status in the EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI                             section of the PI Specification. EFI_AUTH_STATUS_PLATFORM_OVERRIDE must                             never be set by this handler.    @retval  RETURN_SUCCESS            The buffer specified by InputSection was decoded.   @retval  RETURN_UNSUPPORTED        The section specified by InputSection does not match the GUID this handler supports.   @retval  RETURN_INVALID_PARAMETER  The section specified by InputSection can not be decoded.  **/
end_comment

begin_typedef
typedef|typedef
name|RETURN_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EXTRACT_GUIDED_SECTION_DECODE_HANDLER
function_decl|)
parameter_list|(
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
name|IN
name|VOID
modifier|*
name|ScratchBuffer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Registers handlers of type EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER and EXTRACT_GUIDED_SECTION_DECODE_HANDLER   for a specific GUID section type.    Registers the handlers specified by GetInfoHandler and DecodeHandler with the GUID specified by SectionGuid.   If the GUID value specified by SectionGuid has already been registered, then return RETURN_ALREADY_STARTED.   If there are not enough resources available to register the handlers  then RETURN_OUT_OF_RESOURCES is returned.      If SectionGuid is NULL, then ASSERT().   If GetInfoHandler is NULL, then ASSERT().   If DecodeHandler is NULL, then ASSERT().    @param[in]  SectionGuid    A pointer to the GUID associated with the the handlers                              of the GUIDed section type being registered.   @param[in]  GetInfoHandler Pointer to a function that examines a GUIDed section and returns the                              size of the decoded buffer and the size of an optional scratch buffer                              required to actually decode the data in a GUIDed section.   @param[in]  DecodeHandler  Pointer to a function that decodes a GUIDed section into a caller                              allocated output buffer.     @retval  RETURN_SUCCESS           The handlers were registered.   @retval  RETURN_OUT_OF_RESOURCES  There are not enough resources available to register the handlers.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|ExtractGuidedSectionRegisterHandlers
parameter_list|(
name|IN
name|CONST
name|GUID
modifier|*
name|SectionGuid
parameter_list|,
name|IN
name|EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER
name|GetInfoHandler
parameter_list|,
name|IN
name|EXTRACT_GUIDED_SECTION_DECODE_HANDLER
name|DecodeHandler
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieve the list GUIDs that have been registered through ExtractGuidedSectionRegisterHandlers().    Sets ExtractHandlerGuidTable so it points at a callee allocated array of registered GUIDs.   The total number of GUIDs in the array are returned. Since the array of GUIDs is callee allocated   and caller must treat this array of GUIDs as read-only data.    If ExtractHandlerGuidTable is NULL, then ASSERT().    @param[out]  ExtractHandlerGuidTable  A pointer to the array of GUIDs that have been registered through                                         ExtractGuidedSectionRegisterHandlers().    @return the number of the supported extract guided Handler.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|ExtractGuidedSectionGetGuidList
parameter_list|(
name|OUT
name|GUID
modifier|*
modifier|*
name|ExtractHandlerGuidTable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves a GUID from a GUIDed section and uses that GUID to select an associated handler of type   EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER that was registered with ExtractGuidedSectionRegisterHandlers().   The selected handler is used to retrieve and return the size of the decoded buffer and the size of an   optional scratch buffer required to actually decode the data in a GUIDed section.    Examines a GUIDed section specified by InputSection.     If GUID for InputSection does not match any of the GUIDs registered through ExtractGuidedSectionRegisterHandlers(),   then RETURN_UNSUPPORTED is returned.     If the GUID of InputSection does match the GUID that this handler supports, then the the associated handler    of type EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER that was registered with ExtractGuidedSectionRegisterHandlers()   is used to retrieve the OututBufferSize, ScratchSize, and Attributes values. The return status from the handler of   type EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER is returned.      If InputSection is NULL, then ASSERT().   If OutputBufferSize is NULL, then ASSERT().   If ScratchBufferSize is NULL, then ASSERT().   If SectionAttribute is NULL, then ASSERT().    @param[in]  InputSection       A pointer to a GUIDed section of an FFS formatted file.   @param[out] OutputBufferSize   A pointer to the size, in bytes, of an output buffer required if the buffer                                  specified by InputSection were decoded.   @param[out] ScratchBufferSize  A pointer to the size, in bytes, required as scratch space if the buffer specified by                                  InputSection were decoded.   @param[out] SectionAttribute   A pointer to the attributes of the GUIDed section.  See the Attributes field of                                  EFI_GUID_DEFINED_SECTION in the PI Specification.    @retval  RETURN_SUCCESS      Get the required information successfully.   @retval  RETURN_UNSUPPORTED  The GUID from the section specified by InputSection does not match any of                                the GUIDs registered with ExtractGuidedSectionRegisterHandlers().   @retval  Others              The return status from the handler associated with the GUID retrieved from                                the section specified by InputSection.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|ExtractGuidedSectionGetInfo
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|InputSection
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|OutputBufferSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ScratchBufferSize
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|SectionAttribute
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the GUID from a GUIDed section and uses that GUID to select an associated handler of type   EXTRACT_GUIDED_SECTION_DECODE_HANDLER that was registered with ExtractGuidedSectionRegisterHandlers().   The selected handler is used to decode the data in a GUIDed section and return the result in a caller   allocated output buffer.    Decodes the GUIDed section specified by InputSection.     If GUID for InputSection does not match any of the GUIDs registered through ExtractGuidedSectionRegisterHandlers(),   then RETURN_UNSUPPORTED is returned.     If the GUID of InputSection does match the GUID that this handler supports, then the the associated handler   of type EXTRACT_GUIDED_SECTION_DECODE_HANDLER that was registered with ExtractGuidedSectionRegisterHandlers()   is used to decode InputSection into the buffer specified by OutputBuffer and the authentication status of this   decode operation is returned in AuthenticationStatus.  If the decoded buffer is identical to the data in InputSection,   then OutputBuffer is set to point at the data in InputSection.  Otherwise, the decoded data will be placed in caller   allocated buffer specified by OutputBuffer.    This function is responsible for computing the  EFI_AUTH_STATUS_PLATFORM_OVERRIDE   bit of in AuthenticationStatus.  The return status from the handler of type EXTRACT_GUIDED_SECTION_DECODE_HANDLER is returned.        If InputSection is NULL, then ASSERT().   If OutputBuffer is NULL, then ASSERT().   If ScratchBuffer is NULL and this decode operation requires a scratch buffer, then ASSERT().   If AuthenticationStatus is NULL, then ASSERT().      @param[in]  InputSection   A pointer to a GUIDed section of an FFS formatted file.   @param[out] OutputBuffer   A pointer to a buffer that contains the result of a decode operation.    @param[in]  ScratchBuffer  A caller allocated buffer that may be required by this function as a scratch buffer to perform the decode operation.    @param[out] AuthenticationStatus                               A pointer to the authentication status of the decoded output buffer. See the definition                              of authentication status in the EFI_PEI_GUIDED_SECTION_EXTRACTION_PPI section of the PI                              Specification.    @retval  RETURN_SUCCESS           The buffer specified by InputSection was decoded.   @retval  RETURN_UNSUPPORTED       The section specified by InputSection does not match the GUID this handler supports.   @retval  RETURN_INVALID_PARAMETER The section specified by InputSection can not be decoded.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|ExtractGuidedSectionDecode
parameter_list|(
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
name|IN
name|VOID
modifier|*
name|ScratchBuffer
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT32
modifier|*
name|AuthenticationStatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves handlers of type EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER and    EXTRACT_GUIDED_SECTION_DECODE_HANDLER for a specific GUID section type.      Retrieves the handlers associated with SectionGuid and returns them in    GetInfoHandler and DecodeHandler.    If the GUID value specified by SectionGuid has not been registered, then    return RETURN_NOT_FOUND.      If SectionGuid is NULL, then ASSERT().    @param[in]  SectionGuid    A pointer to the GUID associated with the handlersof the GUIDed                               section type being retrieved.   @param[out] GetInfoHandler Pointer to a function that examines a GUIDed section and returns                               the size of the decoded buffer and the size of an optional scratch                               buffer required to actually decode the data in a GUIDed section.                                This is an optional parameter that may be NULL. If it is NULL, then                               the previously registered handler is not returned.   @param[out] DecodeHandler  Pointer to a function that decodes a GUIDed section into a caller                              allocated output buffer. This is an optional parameter that may be NULL.                              If it is NULL, then the previously registered handler is not returned.    @retval  RETURN_SUCCESS     The handlers were retrieved.   @retval  RETURN_NOT_FOUND   No handlers have been registered with the specified GUID.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|ExtractGuidedSectionGetHandlers
parameter_list|(
name|IN
name|CONST
name|GUID
modifier|*
name|SectionGuid
parameter_list|,
name|OUT
name|EXTRACT_GUIDED_SECTION_GET_INFO_HANDLER
modifier|*
name|GetInfoHandler
parameter_list|,
name|OPTIONAL
name|OUT
name|EXTRACT_GUIDED_SECTION_DECODE_HANDLER
modifier|*
name|DecodeHandler
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

