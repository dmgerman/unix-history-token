begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI EAP Management2 protocol.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_EAP_MANAGEMENT2_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_EAP_MANAGEMENT2_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/EapManagement.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// This EFI EAP Management2 protocol provides the ability to configure and control EAPOL
end_comment

begin_comment
comment|/// state machine, and retrieve the information, status and the statistics information of
end_comment

begin_comment
comment|/// EAPOL state machine.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_EAP_MANAGEMENT2_PROTOCOL_GUID
define|\
value|{ \     0x5e93c847, 0x456d, 0x40b3, {0xa6, 0xb4, 0x78, 0xb0, 0xc9, 0xcf, 0x7f, 0x20 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_EAP_MANAGEMENT2_PROTOCOL
name|EFI_EAP_MANAGEMENT2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Return key generated through EAP process.    The GetKey() function return the key generated through EAP process, so that the 802.11   MAC layer driver can use MSK to derive more keys, e.g. PMK (Pairwise Master Key).    @param[in]       This           Pointer to the EFI_EAP_MANAGEMENT2_PROTOCOL instance.   @param[in, out]  Msk            Pointer to MSK (Master Session Key) buffer.   @param[in, out]  MskSize        MSK buffer size.   @param[in, out]  Emsk           Pointer to EMSK (Extended Master Session Key) buffer.   @param[in, out]  EmskSize       EMSK buffer size.    @retval EFI_SUCCESS             The operation completed successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   Msk is NULL.                                   MskSize is NULL.                                   Emsk is NULL.                                   EmskSize is NULL.   @retval EFI_NOT_READY           MSK and EMSK are not generated in current session yet.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_GET_KEY
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|Msk
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|MskSize
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|Emsk
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|EmskSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_EAP_MANAGEMENT2_PROTOCOL
end_comment

begin_comment
comment|/// is used to control, configure and monitor EAPOL state machine on a Port, and return
end_comment

begin_comment
comment|/// information of the Port. EAPOL state machine is built on a per-Port basis. Herein, a
end_comment

begin_comment
comment|/// Port means a NIC. For the details of EAPOL, please refer to IEEE 802.1x
end_comment

begin_comment
comment|/// specification.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EAP_MANAGEMENT2_PROTOCOL
block|{
name|EFI_EAP_GET_SYSTEM_CONFIGURATION
name|GetSystemConfiguration
decl_stmt|;
name|EFI_EAP_SET_SYSTEM_CONFIGURATION
name|SetSystemConfiguration
decl_stmt|;
name|EFI_EAP_INITIALIZE_PORT
name|InitializePort
decl_stmt|;
name|EFI_EAP_USER_LOGON
name|UserLogon
decl_stmt|;
name|EFI_EAP_USER_LOGOFF
name|UserLogoff
decl_stmt|;
name|EFI_EAP_GET_SUPPLICANT_STATUS
name|GetSupplicantStatus
decl_stmt|;
name|EFI_EAP_SET_SUPPLICANT_CONFIGURATION
name|SetSupplicantConfiguration
decl_stmt|;
name|EFI_EAP_GET_SUPPLICANT_STATISTICS
name|GetSupplicantStatistics
decl_stmt|;
name|EFI_EAP_GET_KEY
name|GetKey
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEapManagement2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

