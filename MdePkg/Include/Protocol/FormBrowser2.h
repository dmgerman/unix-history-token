begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This protocol is defined in UEFI spec.      The EFI_FORM_BROWSER2_PROTOCOL is the interface to call for drivers to    leverage the EFI configuration driver interface.    Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_FORM_BROWSER2_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_FORM_BROWSER2_H__
end_define

begin_include
include|#
directive|include
file|<Guid/HiiPlatformSetupFormset.h>
end_include

begin_define
define|#
directive|define
name|EFI_FORM_BROWSER2_PROTOCOL_GUID
define|\
value|{0xb9d4c360, 0xbcfb, 0x4f9b, {0x92, 0x98, 0x53, 0xc1, 0x36, 0x98, 0x22, 0x58 }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_FORM_BROWSER2_PROTOCOL
name|EFI_FORM_BROWSER2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**       @param LeftColumn   The value that designates the text column                       where the browser window will begin from                       the left-hand side of the screen                          @param RightColumn  The value that designates the text                       column where the browser window will end                       on the right-hand side of the screen.    @param TopRow       The value that designates the text row from the                       top of the screen where the browser window                       will start.    @param BottomRow    The value that designates the text row from the                       bottom of the screen where the browser                       window will end.  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINTN
name|LeftColumn
decl_stmt|;
name|UINTN
name|RightColumn
decl_stmt|;
name|UINTN
name|TopRow
decl_stmt|;
name|UINTN
name|BottomRow
decl_stmt|;
block|}
name|EFI_SCREEN_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINTN
name|EFI_BROWSER_ACTION_REQUEST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_RESET
value|1
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_SUBMIT
value|2
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_EXIT
value|3
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_FORM_SUBMIT_EXIT
value|4
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_FORM_DISCARD_EXIT
value|5
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_FORM_APPLY
value|6
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_FORM_DISCARD
value|7
end_define

begin_define
define|#
directive|define
name|EFI_BROWSER_ACTION_REQUEST_RECONNECT
value|8
end_define

begin_comment
comment|/**   Initialize the browser to display the specified configuration forms.    This function is the primary interface to the internal forms-based browser.    The forms browser will display forms associated with the specified Handles.    The browser will select all forms in packages which have the specified Type    and (for EFI_HII_PACKAGE_TYPE_GUID) the specified PackageGuid.    @param This            A pointer to the EFI_FORM_BROWSER2_PROTOCOL instance    @param Handles         A pointer to an array of Handles. This value should correspond                           to the value of the HII form package that is required to be displayed.    @param HandleCount     The number of Handles specified in Handle.    @param FormSetGuid     This field points to the EFI_GUID which must match the Guid field or one of the                          elements of the ClassId field  in the EFI_IFR_FORM_SET op-code.  If                          FormsetGuid is NULL, then this function will display the form set class                          EFI_HII_PLATFORM_SETUP_FORMSET_GUID.    @param FormId          This field specifies the identifier of the form within the form set to render as the first                          displayable page. If this field has a value of 0x0000, then the Forms Browser will                          render the first enabled form in the form set.    @param ScreenDimensions Points to recommended form dimensions, including any non-content area, in                            characters.    @param ActionRequest   Points to the action recommended by the form.    @retval EFI_SUCCESS           The function completed successfully      @retval EFI_NOT_FOUND         The variable was not found.      @retval EFI_INVALID_PARAMETER One of the parameters has an                                 invalid value.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SEND_FORM2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FORM_BROWSER2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_HANDLE
modifier|*
name|Handle
parameter_list|,
name|IN
name|UINTN
name|HandleCount
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|FormSetGuid
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_FORM_ID
name|FormId
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_SCREEN_DESCRIPTOR
modifier|*
name|ScreenDimensions
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_BROWSER_ACTION_REQUEST
modifier|*
name|ActionRequest
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function is called by a callback handler to retrieve uncommitted state data from the browser.    This routine is called by a routine which was called by the   browser. This routine called this service in the browser to   retrieve or set certain uncommitted state information.    @param This           A pointer to the EFI_FORM_BROWSER2_PROTOCOL instance.    @param ResultsDataSize  A pointer to the size of the buffer                           associated with ResultsData. On input, the size in                           bytes of ResultsData. On output, the size of data                            returned in ResultsData.    @param ResultsData    A string returned from an IFR browser or                         equivalent. The results string will have                         no routing information in them.    @param RetrieveData   A BOOLEAN field which allows an agent to                         retrieve (if RetrieveData = TRUE) data                         from the uncommitted browser state                         information or set (if RetrieveData =                         FALSE) data in the uncommitted browser                         state information.    @param VariableGuid   An optional field to indicate the target                         variable GUID name to use.    @param VariableName   An optional field to indicate the target                         human-readable variable name.    @retval EFI_SUCCESS           The results have been distributed or are                                 awaiting distribution.      @retval EFI_OUT_OF_RESOURCES  The ResultsDataSize specified                                 was too small to contain the                                 results data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BROWSER_CALLBACK2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FORM_BROWSER2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ResultsDataSize
parameter_list|,
name|IN
name|OUT
name|EFI_STRING
name|ResultsData
parameter_list|,
name|IN
name|CONST
name|BOOLEAN
name|RetrieveData
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|VariableGuid
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR16
modifier|*
name|VariableName
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This interface will allow the caller to direct the configuration
end_comment

begin_comment
comment|/// driver to use either the HII database or use the passed-in packet of data.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FORM_BROWSER2_PROTOCOL
block|{
name|EFI_SEND_FORM2
name|SendForm
decl_stmt|;
name|EFI_BROWSER_CALLBACK2
name|BrowserCallback
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFormBrowser2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

