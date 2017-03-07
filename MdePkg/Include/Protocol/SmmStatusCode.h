begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Status Code Protocol as defined in the PI 1.2 specification.    This protocol provides the basic status code services while in SMM.     Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_STATUS_CODE_H__
end_ifndef

begin_define
define|#
directive|define
name|_SMM_STATUS_CODE_H__
end_define

begin_define
define|#
directive|define
name|EFI_SMM_STATUS_CODE_PROTOCOL_GUID
define|\
value|{ \     0x6afd2b77, 0x98c1, 0x4acd, {0xa6, 0xf9, 0x8a, 0x94, 0x39, 0xde, 0xf, 0xb1} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_STATUS_CODE_PROTOCOL
name|EFI_SMM_STATUS_CODE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Service to emit the status code in SMM.        The EFI_SMM_STATUS_CODE_PROTOCOL.ReportStatusCode() function enables a driver    to emit a status code while in SMM.  The reason that there is a separate protocol definition from the    DXE variant of this service is that the publisher of this protocol will provide a service that is    capability of coexisting with a foreground operational environment, such as an operating system    after the termination of boot services.      @param[in] This                Points to this instance of the EFI_SMM_STATUS_CODE_PROTOCOL.   @param[in] CodeType            DIndicates the type of status code being reported.    @param[in] Value               Describes the current status of a hardware or software entity.    @param[in] Instance            The enumeration of a hardware or software entity within the system.   @param[in] CallerId            This optional parameter may be used to identify the caller.   @param[in] Data                This optional parameter may be used to pass additional data.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_INVALID_PARAMETER  The function should not be completed due to a device error. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_REPORT_STATUS_CODE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_STATUS_CODE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_STATUS_CODE_TYPE
name|CodeType
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
name|EFI_STATUS_CODE_DATA
modifier|*
name|Data
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_SMM_STATUS_CODE_PROTOCOL
block|{
name|EFI_SMM_REPORT_STATUS_CODE
name|ReportStatusCode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmStatusCodeProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

