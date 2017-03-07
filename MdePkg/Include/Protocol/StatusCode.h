begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Status code Runtime Protocol as defined in PI Specification 1.4a VOLUME 2 DXE    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STATUS_CODE_RUNTIME_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__STATUS_CODE_RUNTIME_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_RUNTIME_PROTOCOL_GUID
define|\
value|{ 0xd2b2b828, 0x826, 0x48a7,  { 0xb3, 0xdf, 0x98, 0x3c, 0x0, 0x60, 0x24, 0xf0 } }
end_define

begin_comment
comment|/**   Provides an interface that a software module can call to report a status code.    @param  Type             Indicates the type of status code being reported.   @param  Value            Describes the current status of a hardware or software entity.                            This included information about the class and subclass that is used to                            classify the entity as well as an operation.   @param  Instance         The enumeration of a hardware or software entity within                            the system. Valid instance numbers start with 1.   @param  CallerId         This optional parameter may be used to identify the caller.                            This parameter allows the status code driver to apply different rules to                            different callers.   @param  Data             This optional parameter may be used to pass additional data.    @retval EFI_SUCCESS           The function completed successfully   @retval EFI_DEVICE_ERROR      The function should not be completed due to a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REPORT_STATUS_CODE
function_decl|)
parameter_list|(
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
name|EFI_GUID
modifier|*
name|CallerId
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_STATUS_CODE_DATA
modifier|*
name|Data
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the service required to report a status code to the platform firmware.
end_comment

begin_comment
comment|/// This protocol must be produced by a runtime DXE driver.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_STATUS_CODE_PROTOCOL
block|{
name|EFI_REPORT_STATUS_CODE
name|ReportStatusCode
decl_stmt|;
block|}
name|EFI_STATUS_CODE_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiStatusCodeRuntimeProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

