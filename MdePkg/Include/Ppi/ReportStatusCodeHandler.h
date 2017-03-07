begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI provides registering and unregistering services to status code consumers.      Copyright (c) 2007 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REPORT_STATUS_CODE_HANDLER_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__REPORT_STATUS_CODE_HANDLER_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_RSC_HANDLER_PPI_GUID
define|\
value|{ \     0x65d394, 0x9951, 0x4144, {0x82, 0xa3, 0xa, 0xfc, 0x85, 0x79, 0xc2, 0x51} \   }
end_define

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_RSC_HANDLER_CALLBACK
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
name|EFI_STATUS_CODE_TYPE
name|Type
parameter_list|,
name|IN
name|EFI_STATUS_CODE_VALUE
name|Value
parameter_list|,
name|IN
name|UINT32
name|Instance
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|CallerId
parameter_list|,
name|IN
name|CONST
name|EFI_STATUS_CODE_DATA
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register the callback function for ReportStatusCode() notification.      When this function is called the function pointer is added to an internal list and any future calls to   ReportStatusCode() will be forwarded to the Callback function.    @param[in] Callback           A pointer to a function of type EFI_PEI_RSC_HANDLER_CALLBACK that is called                                 when a call to ReportStatusCode() occurs.                            @retval EFI_SUCCESS           Function was successfully registered.   @retval EFI_INVALID_PARAMETER The callback function was NULL.   @retval EFI_OUT_OF_RESOURCES  The internal buffer ran out of space. No more functions can be                                 registered.   @retval EFI_ALREADY_STARTED   The function was already registered. It can't be registered again.                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_RSC_HANDLER_REGISTER
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_RSC_HANDLER_CALLBACK
name|Callback
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove a previously registered callback function from the notification list.      ReportStatusCode() messages will no longer be forwarded to the Callback function.      @param[in] Callback           A pointer to a function of type EFI_PEI_RSC_HANDLER_CALLBACK that is to be                                 unregistered.    @retval EFI_SUCCESS           The function was successfully unregistered.   @retval EFI_INVALID_PARAMETER The callback function was NULL.   @retval EFI_NOT_FOUND         The callback function was not found to be unregistered.                          **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_RSC_HANDLER_UNREGISTER
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_RSC_HANDLER_CALLBACK
name|Callback
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_PEI_RSC_HANDLER_PPI
block|{
name|EFI_PEI_RSC_HANDLER_REGISTER
name|Register
decl_stmt|;
name|EFI_PEI_RSC_HANDLER_UNREGISTER
name|Unregister
decl_stmt|;
block|}
name|EFI_PEI_RSC_HANDLER_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiRscHandlerPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __REPORT_STATUS_CODE_HANDLER_PPI_H__
end_comment

end_unit

