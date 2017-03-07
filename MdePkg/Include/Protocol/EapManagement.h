begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI EAP Management Protocol Definition   The EFI EAP Management Protocol is designed to provide ease of management and   ease of test for EAPOL state machine. It is intended for the supplicant side.    It conforms to IEEE 802.1x specification.    The definitions in this file are defined in UEFI Specification 2.2, which have   not been verified by one implementation yet.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_EAP_MANAGEMENT_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_EAP_MANAGEMENT_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/Eap.h>
end_include

begin_define
define|#
directive|define
name|EFI_EAP_MANAGEMENT_PROTOCOL_GUID
define|\
value|{ \     0xbb62e663, 0x625d, 0x40b2, {0xa0, 0x88, 0xbb, 0xe8, 0x36, 0x23, 0xa2, 0x45 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_EAP_MANAGEMENT_PROTOCOL
name|EFI_EAP_MANAGEMENT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PAE Capabilities
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|PAE_SUPPORT_AUTHENTICATOR
value|0x01
end_define

begin_define
define|#
directive|define
name|PAE_SUPPORT_SUPPLICANT
value|0x02
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_EAPOL_PORT_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_EAPOL_PORT_INFO
block|{
comment|///
comment|/// The identification number assigned to the Port by the System in
comment|/// which the Port resides.
comment|///
name|EFI_PORT_HANDLE
name|PortNumber
decl_stmt|;
comment|///
comment|/// The protocol version number of the EAPOL implementation
comment|/// supported by the Port.
comment|///
name|UINT8
name|ProtocolVersion
decl_stmt|;
comment|///
comment|/// The capabilities of the PAE associated with the Port. This field
comment|/// indicates whether Authenticator functionality, Supplicant
comment|/// functionality, both, or neither, is supported by the Port's PAE.
comment|///
name|UINT8
name|PaeCapabilities
decl_stmt|;
block|}
name|EFI_EAPOL_PORT_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Supplicant PAE state machine (IEEE Std 802.1X Section 8.5.10)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_EFI_EAPOL_SUPPLICANT_PAE_STATE
block|{
name|Logoff
block|,
name|Disconnected
block|,
name|Connecting
block|,
name|Acquired
block|,
name|Authenticating
block|,
name|Held
block|,
name|Authenticated
block|,
name|MaxSupplicantPaeState
block|}
name|EFI_EAPOL_SUPPLICANT_PAE_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definitions for ValidFieldMask
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|AUTH_PERIOD_FIELD_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|HELD_PERIOD_FIELD_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|START_PERIOD_FIELD_VALID
value|0x04
end_define

begin_define
define|#
directive|define
name|MAX_START_FIELD_VALID
value|0x08
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
block|{
comment|///
comment|/// Indicates which of the following fields are valid.
comment|///
name|UINT8
name|ValidFieldMask
decl_stmt|;
comment|///
comment|/// The initial value for the authWhile timer. Its default value is 30s.
comment|///
name|UINTN
name|AuthPeriod
decl_stmt|;
comment|///
comment|/// The initial value for the heldWhile timer. Its default value is 60s.
comment|///
name|UINTN
name|HeldPeriod
decl_stmt|;
comment|///
comment|/// The initial value for the startWhen timer. Its default value is 30s.
comment|///
name|UINTN
name|StartPeriod
decl_stmt|;
comment|///
comment|/// The maximum number of successive EAPOL-Start messages will
comment|/// be sent before the Supplicant assumes that there is no
comment|/// Authenticator present. Its default value is 3.
comment|///
name|UINTN
name|MaxStart
decl_stmt|;
block|}
name|EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Supplicant Statistics (IEEE Std 802.1X Section 9.5.2)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_EAPOL_SUPPLICANT_PAE_STATISTICS
block|{
comment|///
comment|/// The number of EAPOL frames of any type that have been received by this Supplican.
comment|///
name|UINTN
name|EapolFramesReceived
decl_stmt|;
comment|///
comment|/// The number of EAPOL frames of any type that have been transmitted by this Supplicant.
comment|///
name|UINTN
name|EapolFramesTransmitted
decl_stmt|;
comment|///
comment|/// The number of EAPOL Start frames that have been transmitted by this Supplicant.
comment|///
name|UINTN
name|EapolStartFramesTransmitted
decl_stmt|;
comment|///
comment|/// The number of EAPOL Logoff frames that have been transmitted by this Supplicant.
comment|///
name|UINTN
name|EapolLogoffFramesTransmitted
decl_stmt|;
comment|///
comment|/// The number of EAP Resp/Id frames that have been transmitted by this Supplicant.
comment|///
name|UINTN
name|EapRespIdFramesTransmitted
decl_stmt|;
comment|///
comment|/// The number of valid EAP Response frames (other than Resp/Id frames) that have been
comment|/// transmitted by this Supplicant.
comment|///
name|UINTN
name|EapResponseFramesTransmitted
decl_stmt|;
comment|///
comment|/// The number of EAP Req/Id frames that have been received by this Supplicant.
comment|///
name|UINTN
name|EapReqIdFramesReceived
decl_stmt|;
comment|///
comment|/// The number of EAP Request frames (other than Rq/Id frames) that have been received
comment|/// by this Supplicant.
comment|///
name|UINTN
name|EapRequestFramesReceived
decl_stmt|;
comment|///
comment|/// The number of EAPOL frames that have been received by this Supplicant in which the
comment|/// frame type is not recognized.
comment|///
name|UINTN
name|InvalidEapolFramesReceived
decl_stmt|;
comment|///
comment|/// The number of EAPOL frames that have been received by this Supplicant in which the
comment|/// Packet Body Length field (7.5.5) is invalid.
comment|///
name|UINTN
name|EapLengthErrorFramesReceived
decl_stmt|;
comment|///
comment|/// The protocol version number carried in the most recently received EAPOL frame.
comment|///
name|UINTN
name|LastEapolFrameVersion
decl_stmt|;
comment|///
comment|/// The source MAC address carried in the most recently received EAPOL frame.
comment|///
name|UINTN
name|LastEapolFrameSource
decl_stmt|;
block|}
name|EFI_EAPOL_SUPPLICANT_PAE_STATISTICS
typedef|;
end_typedef

begin_comment
comment|/**   Read the system configuration information associated with the Port.     The GetSystemConfiguration() function reads the system configuration   information associated with the Port, including the value of the    SystemAuthControl parameter of the System is returned in SystemAuthControl   and the Port's information is returned in the buffer pointed to by PortInfo.   The Port's information is optional.    If PortInfo is NULL, then reading the Port's information is ignored.    If SystemAuthControl is NULL, then EFI_INVALID_PARAMETER is returned.    @param[in]  This               A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.   @param[out] SystemAuthControl  Returns the value of the SystemAuthControl                                  parameter of the System.                                   TRUE means Enabled. FALSE means Disabled.   @param[out] PortInfo           Returns EFI_EAPOL_PORT_INFO structure to describe                                  the Port's information. This parameter can be NULL                                  to ignore reading the Port's information.    @retval EFI_SUCCESS            The system configuration information of the                                  Port is read successfully.   @retval EFI_INVALID_PARAMETER  SystemAuthControl is NULL.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_GET_SYSTEM_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|SystemAuthControl
parameter_list|,
name|OUT
name|EFI_EAPOL_PORT_INFO
modifier|*
name|PortInfo
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the system configuration information associated with the Port.     The SetSystemConfiguration() function sets the value of the SystemAuthControl    parameter of the System to SystemAuthControl.    @param[in] This                A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.   @param[in] SystemAuthControl   The desired value of the SystemAuthControl                                   parameter of the System.                                   TRUE means Enabled. FALSE means Disabled.    @retval EFI_SUCCESS            The system configuration information of the                                  Port is set successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_SET_SYSTEM_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|SystemAuthControl
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Cause the EAPOL state machines for the Port to be initialized.    The InitializePort() function causes the EAPOL state machines for the Port.    @param[in] This                A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.    @retval EFI_SUCCESS            The Port is initialized successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_INITIALIZE_PORT
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Notify the EAPOL state machines for the Port that the user of the System has   logged on.    The UserLogon() function notifies the EAPOL state machines for the Port.    @param[in] This                A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.    @retval EFI_SUCCESS            The Port is notified successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_USER_LOGON
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Notify the EAPOL state machines for the Port that the user of the System has    logged off.    The UserLogoff() function notifies the EAPOL state machines for the Port.    @param[in] This                A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.    @retval EFI_SUCCESS            The Port is notified successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_USER_LOGOFF
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Read the status of the Supplicant PAE state machine for the Port, including the   current state and the configuration of the operational parameters.    The GetSupplicantStatus() function reads the status of the Supplicant PAE state   machine for the Port, including the current state CurrentState  and the configuration   of the operational parameters Configuration. The configuration of the operational   parameters is optional. If Configuration is NULL, then reading the configuration    is ignored. The operational parameters in Configuration to be read can also be    specified by Configuration.ValidFieldMask.    If CurrentState is NULL, then EFI_INVALID_PARAMETER is returned.    @param[in]      This           A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.   @param[out]     CurrentState   Returns the current state of the Supplicant PAE                                  state machine for the Port.   @param[in, out] Configuration  Returns the configuration of the operational                                  parameters of the Supplicant PAE state machine                                  for the Port as required. This parameter can be                                  NULL to ignore reading the configuration.                                   On input, Configuration.ValidFieldMask specifies the                                   operational parameters to be read.                                  On output, Configuration returns the configuration                                  of the required operational parameters.     @retval EFI_SUCCESS            The configuration of the operational parameter                                  of the Supplicant PAE state machine for the Port                                  is set successfully.   @retval EFI_INVALID_PARAMETER  CurrentState is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_GET_SUPPLICANT_STATUS
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_EAPOL_SUPPLICANT_PAE_STATE
modifier|*
name|CurrentState
parameter_list|,
name|IN
name|OUT
name|EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
modifier|*
name|Configuration
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the configuration of the operational parameter of the Supplicant PAE    state machine for the Port.    The SetSupplicantConfiguration() function sets the configuration of the    operational Parameter of the Supplicant PAE state machine for the Port to   Configuration. The operational parameters in Configuration to be set can be   specified by Configuration.ValidFieldMask.    If Configuration is NULL, then EFI_INVALID_PARAMETER is returned.    @param[in] This                A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.   @param[in] Configuration       The desired configuration of the operational                                   parameters of the Supplicant PAE state machine                                  for the Port as required.    @retval EFI_SUCCESS            The configuration of the operational parameter                                  of the Supplicant PAE state machine for the Port                                  is set successfully.   @retval EFI_INVALID_PARAMETER  Configuration is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_SET_SUPPLICANT_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
modifier|*
name|Configuration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Read the statistical information regarding the operation of the Supplicant   associated with the Port.     The GetSupplicantStatistics() function reads the statistical information    Statistics regarding the operation of the Supplicant associated with the Port.      If Statistics is NULL, then EFI_INVALID_PARAMETER is returned.    @param[in]  This               A pointer to the EFI_EAP_MANAGEMENT_PROTOCOL                                  instance that indicates the calling context.   @param[out] Statistics         Returns the statistical information regarding the                                   operation of the Supplicant for the Port.     @retval EFI_SUCCESS            The statistical information regarding the operation                                  of the Supplicant for the Port is read successfully.   @retval EFI_INVALID_PARAMETER  Statistics is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_GET_SUPPLICANT_STATISTICS
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_MANAGEMENT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_EAPOL_SUPPLICANT_PAE_STATISTICS
modifier|*
name|Statistics
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_EAP_MANAGEMENT_PROTOCOL
end_comment

begin_comment
comment|/// is used to control, configure and monitor EAPOL state machine on
end_comment

begin_comment
comment|/// a Port. EAPOL state machine is built on a per-Port basis. Herein,
end_comment

begin_comment
comment|/// a Port means a NIC. For the details of EAPOL, please refer to
end_comment

begin_comment
comment|/// IEEE 802.1x specification.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EAP_MANAGEMENT_PROTOCOL
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
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEapManagementProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

