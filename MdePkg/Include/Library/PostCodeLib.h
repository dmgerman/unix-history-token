begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to send progress/error codes to a POST card.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__POST_CODE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__POST_CODE_LIB_H__
end_define

begin_define
define|#
directive|define
name|POST_CODE_PROPERTY_POST_CODE_ENABLED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|POST_CODE_PROPERTY_POST_CODE_DESCRIPTION_ENABLED
value|0x00000010
end_define

begin_comment
comment|/**   Sends a 32-bit value to a POST card.    Sends the 32-bit value specified by Value to a POST card, and returns Value.     Some implementations of this library function may perform I/O operations    directly to a POST card device.  Other implementations may send Value to    ReportStatusCode(), and the status code reporting mechanism will eventually    display the 32-bit value on the status reporting device.      PostCode() must actively prevent recursion.  If PostCode() is called while    processing another Post Code Library function, then    PostCode() must return Value immediately.    @param  Value  The 32-bit value to write to the POST card.    @return The 32-bit value to write to the POST card.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PostCode
parameter_list|(
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sends a 32-bit value to a POST and associated ASCII string.    Sends the 32-bit value specified by Value to a POST card, and returns Value.   If Description is not NULL, then the ASCII string specified by Description is    also passed to the handler that displays the POST card value.  Some    implementations of this library function may perform I/O operations directly    to a POST card device.  Other implementations may send Value to ReportStatusCode(),    and the status code reporting mechanism will eventually display the 32-bit    value on the status reporting device.      PostCodeWithDescription()must actively prevent recursion.  If    PostCodeWithDescription() is called while processing another any other Post    Code Library function, then PostCodeWithDescription() must return Value    immediately.    @param  Value        The 32-bit value to write to the POST card.   @param  Description  Pointer to an ASCII string that is a description of the                         POST code value.  This is an optional parameter that may                         be NULL.    @return The 32-bit value to write to the POST card.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PostCodeWithDescription
parameter_list|(
name|IN
name|UINT32
name|Value
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Description
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if POST Codes are enabled.    This function returns TRUE if the POST_CODE_PROPERTY_POST_CODE_ENABLED    bit of PcdPostCodePropertyMask is set.  Otherwise FALSE is returned.    @retval  TRUE   The POST_CODE_PROPERTY_POST_CODE_ENABLED bit of                    PcdPostCodeProperyMask is set.   @retval  FALSE  The POST_CODE_PROPERTY_POST_CODE_ENABLED bit of                    PcdPostCodeProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|PostCodeEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if POST code descriptions are enabled.    This function returns TRUE if the POST_CODE_PROPERTY_POST_CODE_DESCRIPTION_ENABLED   bit of PcdPostCodePropertyMask is set.  Otherwise FALSE is returned.    @retval  TRUE   The POST_CODE_PROPERTY_POST_CODE_DESCRIPTION_ENABLED bit of                   PcdPostCodeProperyMask is set.   @retval  FALSE  The POST_CODE_PROPERTY_POST_CODE_DESCRIPTION_ENABLED bit of                   PcdPostCodeProperyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|PostCodeDescriptionEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sends a 32-bit value to a POST card.    If POST codes are enabled in PcdPostCodeProperyMask, then call PostCode()    passing in Value.  Value is returned.    @param  Value  The 32-bit value to write to the POST card.    @return  Value The 32-bit value to write to the POST card.  **/
end_comment

begin_define
define|#
directive|define
name|POST_CODE
parameter_list|(
name|Value
parameter_list|)
value|PostCodeEnabled() ? PostCode(Value) : Value
end_define

begin_comment
comment|/**   Sends a 32-bit value to a POST and associated ASCII string.    If POST codes and POST code descriptions are enabled in    PcdPostCodeProperyMask, then call PostCodeWithDescription() passing in    Value and Description.  If only POST codes are enabled, then call PostCode()    passing in Value.  Value is returned.    @param  Value        The 32-bit value to write to the POST card.   @param  Description  Pointer to an ASCII string that is a description of the                         POST code value.    @return Value        The 32-bit value to write to the POST card. **/
end_comment

begin_define
define|#
directive|define
name|POST_CODE_WITH_DESCRIPTION
parameter_list|(
name|Value
parameter_list|,
name|Description
parameter_list|)
define|\
value|PostCodeEnabled()                              ?     \     (PostCodeDescriptionEnabled()                ?     \       PostCodeWithDescription(Value,Description) :     \       PostCode(Value))                           :     \     Value
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

