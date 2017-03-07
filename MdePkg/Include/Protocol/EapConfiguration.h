begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI EAP Configuration protocol.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_EAP_CONFIGURATION_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_EAP_CONFIGURATION_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI EAP Configuration protocol provides a way to set and get EAP configuration.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_EAP_CONFIGURATION_PROTOCOL_GUID
define|\
value|{ \     0xe5b58dbb, 0x7688, 0x44b4, {0x97, 0xbf, 0x5f, 0x1d, 0x4b, 0x7c, 0xc8, 0xdb } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_EAP_CONFIGURATION_PROTOCOL
name|EFI_EAP_CONFIGURATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Make sure it not conflict with any real EapTypeXXX
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_ATTRIBUTE
value|0
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// EFI_EAP_TYPE_ATTRIBUTE
comment|///
name|EfiEapConfigEapAuthMethod
block|,
name|EfiEapConfigEapSupportedAuthMethod
block|,
comment|///
comment|/// EapTypeIdentity
comment|///
name|EfiEapConfigIdentityString
block|,
comment|///
comment|/// EapTypeEAPTLS/EapTypePEAP
comment|///
name|EfiEapConfigEapTlsCACert
block|,
name|EfiEapConfigEapTlsClientCert
block|,
name|EfiEapConfigEapTlsClientPrivateKeyFile
block|,
name|EfiEapConfigEapTlsClientPrivateKeyFilePassword
block|,
comment|// ASCII format, Volatile
name|EfiEapConfigEapTlsCipherSuite
block|,
name|EfiEapConfigEapTlsSupportedCipherSuite
block|,
comment|///
comment|/// EapTypeMSChapV2
comment|///
name|EfiEapConfigEapMSChapV2Password
block|,
comment|// UNICODE format, Volatile
comment|///
comment|/// EapTypePEAP
comment|///
name|EfiEapConfigEap2ndAuthMethod
block|,
comment|///
comment|/// More...
comment|///
block|}
name|EFI_EAP_CONFIG_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_EAP_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|EFI_EAP_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_ATTRIBUTE
value|0
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_IDENTITY
value|1
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_NOTIFICATION
value|2
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_NAK
value|3
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_MD5CHALLENGE
value|4
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_OTP
value|5
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_GTC
value|6
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_EAPTLS
value|13
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_EAPSIM
value|18
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_TTLS
value|21
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_PEAP
value|25
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_MSCHAPV2
value|26
end_define

begin_define
define|#
directive|define
name|EFI_EAP_TYPE_EAP_EXTENSION
value|33
end_define

begin_comment
comment|/**   Set EAP configuration data.    The SetData() function sets EAP configuration to non-volatile storage or volatile   storage.    @param[in]  This                Pointer to the EFI_EAP_CONFIGURATION_PROTOCOL instance.   @param[in]  EapType             EAP type.   @param[in]  DataType            Configuration data type.   @param[in]  Data                Pointer to configuration data.   @param[in]  DataSize            Total size of configuration data.    @retval EFI_SUCCESS             The EAP configuration data is set successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   Data is NULL.                                   DataSize is 0.   @retval EFI_UNSUPPORTED         The EapType or DataType is unsupported.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_CONFIGURATION_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EAP_TYPE
name|EapType
parameter_list|,
name|IN
name|EFI_EAP_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get EAP configuration data.    The GetData() function gets EAP configuration.    @param[in]       This           Pointer to the EFI_EAP_CONFIGURATION_PROTOCOL instance.   @param[in]       EapType        EAP type.   @param[in]       DataType       Configuration data type.   @param[in, out]  Data           Pointer to configuration data.   @param[in, out]  DataSize       Total size of configuration data. On input, it means                                   the size of Data buffer. On output, it means the size                                   of copied Data buffer if EFI_SUCCESS, and means the                                   size of desired Data buffer if EFI_BUFFER_TOO_SMALL.    @retval EFI_SUCCESS             The EAP configuration data is got successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   Data is NULL.                                   DataSize is NULL.   @retval EFI_UNSUPPORTED         The EapType or DataType is unsupported.   @retval EFI_NOT_FOUND           The EAP configuration data is not found.   @retval EFI_BUFFER_TOO_SMALL    The buffer is too small to hold the buffer. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EAP_CONFIGURATION_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_EAP_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_EAP_TYPE
name|EapType
parameter_list|,
name|IN
name|EFI_EAP_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_EAP_CONFIGURATION_PROTOCOL
end_comment

begin_comment
comment|/// is designed to provide a way to set and get EAP configuration, such as Certificate,
end_comment

begin_comment
comment|/// private key file.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EAP_CONFIGURATION_PROTOCOL
block|{
name|EFI_EAP_CONFIGURATION_SET_DATA
name|SetData
decl_stmt|;
name|EFI_EAP_CONFIGURATION_GET_DATA
name|GetData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEapConfigurationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

