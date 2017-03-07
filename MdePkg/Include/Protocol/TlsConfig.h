begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI TLS Configuration Protocol as defined in UEFI 2.5.   The EFI TLS Configuration Protocol provides a way to set and get TLS configuration.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TLS_CONFIGURATION_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TLS_CONFIGURATION_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI Configuration protocol provides a way to set and get TLS configuration.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_TLS_CONFIGURATION_PROTOCOL_GUID
define|\
value|{ \     0x1682fe44, 0xbd7a, 0x4407, { 0xb7, 0xc7, 0xdc, 0xa3, 0x7c, 0xa3, 0x92, 0x2d }  \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TLS_CONFIGURATION_PROTOCOL
name|EFI_TLS_CONFIGURATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_TLS_CONFIG_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Local host configuration data: public certificate data.
comment|/// This data should be DER-encoded binary X.509 certificate
comment|/// or PEM-encoded X.509 certificate.
comment|///
name|EfiTlsConfigDataTypeHostPublicCert
block|,
comment|///
comment|/// Local host configuration data: private key data.
comment|///
name|EfiTlsConfigDataTypeHostPrivateKey
block|,
comment|///
comment|/// CA certificate to verify peer. This data should be PEM-encoded
comment|/// RSA or PKCS#8 private key.
comment|///
name|EfiTlsConfigDataTypeCACertificate
block|,
comment|///
comment|/// CA-supplied Certificate Revocation List data. This data should
comment|/// be DER-encoded CRL data.
comment|///
name|EfiTlsConfigDataTypeCertRevocationList
block|,
name|EfiTlsConfigDataTypeMaximum
block|}
name|EFI_TLS_CONFIG_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   Set TLS configuration data.    The SetData() function sets TLS configuration to non-volatile storage or volatile   storage.    @param[in]  This                Pointer to the EFI_TLS_CONFIGURATION_PROTOCOL instance.   @param[in]  DataType            Configuration data type.   @param[in]  Data                Pointer to configuration data.   @param[in]  DataSize            Total size of configuration data.    @retval EFI_SUCCESS             The TLS configuration data is set successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   Data is NULL.                                   DataSize is 0.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_OUT_OF_RESOURCES    Required system resources could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_CONFIGURATION_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TLS_CONFIG_DATA_TYPE
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
comment|/**   Get TLS configuration data.    The GetData() function gets TLS configuration.    @param[in]       This           Pointer to the EFI_TLS_CONFIGURATION_PROTOCOL instance.   @param[in]       DataType       Configuration data type.   @param[in, out]  Data           Pointer to configuration data.   @param[in, out]  DataSize       Total size of configuration data. On input, it means                                   the size of Data buffer. On output, it means the size                                   of copied Data buffer if EFI_SUCCESS, and means the                                   size of desired Data buffer if EFI_BUFFER_TOO_SMALL.    @retval EFI_SUCCESS             The TLS configuration data is got successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   This is NULL.                                   DataSize is NULL.                                   Data is NULL if *DataSize is not zero.   @retval EFI_UNSUPPORTED         The DataType is unsupported.   @retval EFI_NOT_FOUND           The TLS configuration data is not found.   @retval EFI_BUFFER_TOO_SMALL    The buffer is too small to hold the data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TLS_CONFIGURATION_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_TLS_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_TLS_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|OPTIONAL
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
comment|/// The EFI_TLS_CONFIGURATION_PROTOCOL is designed to provide a way to set and get
end_comment

begin_comment
comment|/// TLS configuration, such as Certificate, private key data.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TLS_CONFIGURATION_PROTOCOL
block|{
name|EFI_TLS_CONFIGURATION_SET_DATA
name|SetData
decl_stmt|;
name|EFI_TLS_CONFIGURATION_GET_DATA
name|GetData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTlsConfigurationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//__EFI_TLS_CONFIGURATION_PROTOCOL_H__
end_comment

end_unit

