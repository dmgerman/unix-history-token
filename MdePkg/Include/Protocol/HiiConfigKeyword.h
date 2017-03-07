begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides the mechanism to set and get the values    associated with a keyword exposed through a x-UEFI- prefixed    configuration language namespace.    Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_CONFIG_KEYWORD_HANDLER_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_CONFIG_KEYWORD_HANDLER_H__
end_define

begin_define
define|#
directive|define
name|EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL_GUID
define|\
value|{ \   0x0a8badd5, 0x03b8, 0x4d19, {0xb1, 0x28, 0x7b, 0x8f, 0x0e, 0xda, 0xa5, 0x96 } \ }
end_define

begin_comment
comment|//***********************************************************
end_comment

begin_comment
comment|// Progress Errors
end_comment

begin_comment
comment|//***********************************************************
end_comment

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_NO_ERROR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_NAMESPACE_ID_NOT_FOUND
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_MALFORMED_STRING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_KEYWORD_NOT_FOUND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_INCOMPATIBLE_VALUE_DETECTED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_ACCESS_NOT_PERMITTED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KEYWORD_HANDLER_UNDEFINED_PROCESSING_ERROR
value|0x80000000
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL
name|EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**    This function accepts a<MultiKeywordResp> formatted string, finds the associated   keyword owners, creates a<MultiConfigResp> string from it and forwards it to the   EFI_HII_ROUTING_PROTOCOL.RouteConfig function.      If there is an issue in resolving the contents of the KeywordString, then the    function returns an error and also sets the Progress and ProgressErr with the    appropriate information about where the issue occurred and additional data about   the nature of the issue.       In the case when KeywordString containing multiple keywords, when an EFI_NOT_FOUND   error is generated during processing the second or later keyword element, the system   storage associated with earlier keywords is not modified. All elements of the    KeywordString must successfully pass all tests for format and access prior to making   any modifications to storage.      In the case when EFI_DEVICE_ERROR is returned from the processing of a KeywordString   containing multiple keywords, the state of storage associated with earlier keywords   is undefined.     @param This             Pointer to the EFI_KEYWORD_HANDLER _PROTOCOL instance.    @param KeywordString    A null-terminated string in<MultiKeywordResp> format.     @param Progress         On return, points to a character in the KeywordString.                            Points to the string's NULL terminator if the request                            was successful. Points to the most recent '&' before                            the first failing name / value pair (or the beginning                           of the string if the failure is in the first name / value                           pair) if the request was not successful.    @param ProgressErr      If during the processing of the KeywordString there was                           a failure, this parameter gives additional information                            about the possible source of the problem. The various                            errors are defined in "Related Definitions" below.     @retval EFI_SUCCESS             The specified action was completed successfully.    @retval EFI_INVALID_PARAMETER   One or more of the following are TRUE:                                   1. KeywordString is NULL.                                   2. Parsing of the KeywordString resulted in an                                       error. See Progress and ProgressErr for more data.    @retval EFI_NOT_FOUND           An element of the KeywordString was not found.                                    See ProgressErr for more data.    @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.                                     See ProgressErr for more data.                                      @retval EFI_ACCESS_DENIED       The action violated system policy. See ProgressErr                                    for more data.    @retval EFI_DEVICE_ERROR        An unexpected system error occurred. See ProgressErr                                   for more data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONFIG_KEYWORD_HANDLER_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|KeywordString
parameter_list|,
name|OUT
name|EFI_STRING
modifier|*
name|Progress
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ProgressErr
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**    This function accepts a<MultiKeywordRequest> formatted string, finds the underlying    keyword owners, creates a<MultiConfigRequest> string from it and forwards it to the   EFI_HII_ROUTING_PROTOCOL.ExtractConfig function.      If there is an issue in resolving the contents of the KeywordString, then the function   returns an EFI_INVALID_PARAMETER and also set the Progress and ProgressErr with the   appropriate information about where the issue occurred and additional data about the   nature of the issue.      In the case when KeywordString is NULL, or contains multiple keywords, or when   EFI_NOT_FOUND is generated while processing the keyword elements, the Results string   contains values returned for all keywords processed prior to the keyword generating the    error but no values for the keyword with error or any following keywords.       @param This           Pointer to the EFI_KEYWORD_HANDLER _PROTOCOL instance.      @param NameSpaceId    A null-terminated string containing the platform configuration                         language to search through in the system. If a NULL is passed                         in, then it is assumed that any platform configuration language                         with the prefix of "x-UEFI-" are searched.                            @param KeywordString  A null-terminated string in<MultiKeywordRequest> format. If a                         NULL is passed in the KeywordString field, all of the known                          keywords in the system for the NameSpaceId specified are                          returned in the Results field.      @param Progress       On return, points to a character in the KeywordString. Points                         to the string's NULL terminator if the request was successful.                          Points to the most recent '&' before the first failing name / value                         pair (or the beginning of the string if the failure is in the first                         name / value pair) if the request was not successful.                            @param ProgressErr    If during the processing of the KeywordString there was a                         failure, this parameter gives additional information about the                          possible source of the problem. See the definitions in SetData()                         for valid value definitions.      @param Results        A null-terminated string in<MultiKeywordResp> format is returned                         which has all the values filled in for the keywords in the                          KeywordString. This is a callee-allocated field, and must be freed                         by the caller after being used.     @retval EFI_SUCCESS             The specified action was completed successfully.      @retval EFI_INVALID_PARAMETER   One or more of the following are TRUE:                                   1.Progress, ProgressErr, or Results is NULL.                                   2.Parsing of the KeywordString resulted in an error. See                                     Progress and ProgressErr for more data.       @retval EFI_NOT_FOUND           An element of the KeywordString was not found. See                                   ProgressErr for more data.    @retval EFI_NOT_FOUND           The NamespaceId specified was not found.  See ProgressErr                                   for more data.    @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.  See                                   ProgressErr for more data.                                      @retval EFI_ACCESS_DENIED       The action violated system policy.  See ProgressErr for                                   more data.    @retval EFI_DEVICE_ERROR        An unexpected system error occurred.  See ProgressErr                                   for more data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONFIG_KEYWORD_HANDLER_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|NameSpaceId
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_STRING
name|KeywordString
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_STRING
modifier|*
name|Progress
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|ProgressErr
parameter_list|,
name|OUT
name|EFI_STRING
modifier|*
name|Results
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL provides the mechanism
end_comment

begin_comment
comment|/// to set and get the values associated with a keyword exposed
end_comment

begin_comment
comment|/// through a x-UEFI- prefixed configuration language namespace
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL
block|{
name|EFI_CONFIG_KEYWORD_HANDLER_SET_DATA
name|SetData
decl_stmt|;
name|EFI_CONFIG_KEYWORD_HANDLER_GET_DATA
name|GetData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiConfigKeywordHandlerProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

