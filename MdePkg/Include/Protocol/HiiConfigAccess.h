begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file    The EFI HII results processing protocol invokes this type of protocol    when it needs to forward results to a driver's configuration handler.    This protocol is published by drivers providing and requesting    configuration data from HII. It may only be invoked by HII.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HII_CONFIG_ACCESS_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HII_CONFIG_ACCESS_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/FormBrowser2.h>
end_include

begin_define
define|#
directive|define
name|EFI_HII_CONFIG_ACCESS_PROTOCOL_GUID
define|\
value|{ 0x330d4706, 0xf2a0, 0x4e4f, { 0xa3, 0x69, 0xb6, 0x6f, 0xa8, 0xd5, 0x43, 0x85 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HII_CONFIG_ACCESS_PROTOCOL
name|EFI_HII_CONFIG_ACCESS_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINTN
name|EFI_BROWSER_ACTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_CHANGING
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_CHANGED
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_RETRIEVE
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_FORM_OPEN
value|3
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_FORM_CLOSE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_SUBMITTED
value|5
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_STANDARD
value|0x1000
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_MANUFACTURING
value|0x1001
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_SAFE
value|0x1002
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_PLATFORM
value|0x2000
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_HARDWARE
value|0x3000
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_DEFAULT_FIRMWARE
value|0x4000
end_define

begin_comment
comment|/**       This function allows the caller to request the current   configuration for one or more named elements. The resulting   string is in<ConfigAltResp> format. Any and all alternative   configuration strings shall also be appended to the end of the   current configuration string. If they are, they must appear   after the current configuration. They must contain the same   routing (GUID, NAME, PATH) as the current configuration string.   They must have an additional description indicating the type of   alternative configuration the string represents,   "ALTCFG=<StringToken>". That<StringToken> (when   converted from Hex UNICODE to binary) is a reference to a   string in the associated string pack.    @param This       Points to the EFI_HII_CONFIG_ACCESS_PROTOCOL.    @param Request    A null-terminated Unicode string in<ConfigRequest> format. Note that this                     includes the routing information as well as                     the configurable name / value pairs. It is                     invalid for this string to be in<MultiConfigRequest> format.                      If a NULL is passed in for the Request field,                      all of the settings being abstracted by this function                      will be returned in the Results field.  In addition,                      if a ConfigHdr is passed in with no request elements,                      all of the settings being abstracted for that particular                      ConfigHdr reference will be returned in the Results Field.    @param Progress   On return, points to a character in the                     Request string. Points to the string's null                     terminator if request was successful. Points                     to the most recent "&" before the first                     failing name / value pair (or the beginning                     of the string if the failure is in the first                     name / value pair) if the request was not                     successful.    @param Results    A null-terminated Unicode string in<MultiConfigAltResp> format which has all values                     filled in for the names in the Request string.                     String to be allocated by the called function.    @retval EFI_SUCCESS             The Results string is filled with the                                   values corresponding to all requested                                   names.    @retval EFI_OUT_OF_RESOURCES    Not enough memory to store the                                   parts of the results that must be                                   stored awaiting possible future                                   protocols.    @retval EFI_NOT_FOUND           A configuration element matching                                    the routing data is not found.                                   Progress set to the first character                                   in the routing header.    @retval EFI_INVALID_PARAMETER   Illegal syntax. Progress set                                   to most recent "&" before the                                   error or the beginning of the                                   string.    @retval EFI_INVALID_PARAMETER   Unknown name. Progress points                                   to the& before the name in                                   question.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_ACCESS_EXTRACT_CONFIG
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_CONFIG_ACCESS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|Request
parameter_list|,
name|OUT
name|EFI_STRING
modifier|*
name|Progress
parameter_list|,
name|OUT
name|EFI_STRING
modifier|*
name|Results
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**       This function applies changes in a driver's configuration.   Input is a Configuration, which has the routing data for this   driver followed by name / value configuration pairs. The driver   must apply those pairs to its configurable storage. If the   driver's configuration is stored in a linear block of data   and the driver's name / value pairs are in<BlockConfig>   format, it may use the ConfigToBlock helper function (above) to   simplify the job.    @param This           Points to the EFI_HII_CONFIG_ACCESS_PROTOCOL.    @param Configuration  A null-terminated Unicode string in<ConfigString> format.       @param Progress       A pointer to a string filled in with the                         offset of the most recent '&' before the                         first failing name / value pair (or the                         beginn ing of the string if the failure                         is in the first name / value pair) or                         the terminating NULL if all was                         successful.    @retval EFI_SUCCESS             The results have been distributed or are                                   awaiting distribution.      @retval EFI_OUT_OF_RESOURCES    Not enough memory to store the                                   parts of the results that must be                                   stored awaiting possible future                                   protocols.      @retval EFI_INVALID_PARAMETERS  Passing in a NULL for the                                   Results parameter would result                                   in this type of error.      @retval EFI_NOT_FOUND           Target for the specified routing data                                   was not found  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_ACCESS_ROUTE_CONFIG
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_CONFIG_ACCESS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|Configuration
parameter_list|,
name|OUT
name|EFI_STRING
modifier|*
name|Progress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**       This function is called to provide results data to the driver.   This data consists of a unique key that is used to identify   which data is either being passed back or being asked for.    @param  This                   Points to the EFI_HII_CONFIG_ACCESS_PROTOCOL.   @param  Action                 Specifies the type of action taken by the browser.   @param  QuestionId             A unique value which is sent to the original                                  exporting driver so that it can identify the type                                  of data to expect. The format of the data tends to                                   vary based on the opcode that generated the callback.   @param  Type                   The type of value for the question.   @param  Value                  A pointer to the data being sent to the original                                  exporting driver.   @param  ActionRequest          On return, points to the action requested by the                                  callback function.    @retval EFI_SUCCESS            The callback successfully handled the action.   @retval EFI_OUT_OF_RESOURCES   Not enough storage is available to hold the                                  variable and its data.   @retval EFI_DEVICE_ERROR       The variable could not be saved.   @retval EFI_UNSUPPORTED        The specified Action is not supported by the                                  callback. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_ACCESS_FORM_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_CONFIG_ACCESS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BROWSER_ACTION
name|Action
parameter_list|,
name|IN
name|EFI_QUESTION_ID
name|QuestionId
parameter_list|,
name|IN
name|UINT8
name|Type
parameter_list|,
name|IN
name|OUT
name|EFI_IFR_TYPE_VALUE
modifier|*
name|Value
parameter_list|,
name|OUT
name|EFI_BROWSER_ACTION_REQUEST
modifier|*
name|ActionRequest
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides a callable interface between the HII and
end_comment

begin_comment
comment|/// drivers. Only drivers which provide IFR data to HII are required
end_comment

begin_comment
comment|/// to publish this protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HII_CONFIG_ACCESS_PROTOCOL
block|{
name|EFI_HII_ACCESS_EXTRACT_CONFIG
name|ExtractConfig
decl_stmt|;
name|EFI_HII_ACCESS_ROUTE_CONFIG
name|RouteConfig
decl_stmt|;
name|EFI_HII_ACCESS_FORM_CALLBACK
name|Callback
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiConfigAccessProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

