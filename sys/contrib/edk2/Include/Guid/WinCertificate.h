begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID for UEFI WIN_CERTIFICATE structure.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUID defined in UEFI 2.0 spec. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_WIN_CERTIFICATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_WIN_CERTIFICATE_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// _WIN_CERTIFICATE.wCertificateType
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|WIN_CERT_TYPE_PKCS_SIGNED_DATA
value|0x0002
end_define

begin_define
define|#
directive|define
name|WIN_CERT_TYPE_EFI_PKCS115
value|0x0EF0
end_define

begin_define
define|#
directive|define
name|WIN_CERT_TYPE_EFI_GUID
value|0x0EF1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The WIN_CERTIFICATE structure is part of the PE/COFF specification.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The length of the entire certificate,
comment|/// including the length of the header, in bytes.
comment|///
name|UINT32
name|dwLength
decl_stmt|;
comment|///
comment|/// The revision level of the WIN_CERTIFICATE
comment|/// structure. The current revision level is 0x0200.
comment|///
name|UINT16
name|wRevision
decl_stmt|;
comment|///
comment|/// The certificate type. See WIN_CERT_TYPE_xxx for the UEFI
comment|/// certificate types. The UEFI specification reserves the range of
comment|/// certificate type values from 0x0EF0 to 0x0EFF.
comment|///
name|UINT16
name|wCertificateType
decl_stmt|;
comment|///
comment|/// The following is the actual certificate. The format of
comment|/// the certificate depends on wCertificateType.
comment|///
comment|/// UINT8 bCertificate[ANYSIZE_ARRAY];
comment|///
block|}
name|WIN_CERTIFICATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// WIN_CERTIFICATE_UEFI_GUID.CertType
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_TYPE_RSA2048_SHA256_GUID
define|\
value|{0xa7717414, 0xc616, 0x4977, {0x94, 0x20, 0x84, 0x47, 0x12, 0xa7, 0x35, 0xbf } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// WIN_CERTIFICATE_UEFI_GUID.CertData
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_GUID
name|HashType
decl_stmt|;
name|UINT8
name|PublicKey
index|[
literal|256
index|]
decl_stmt|;
name|UINT8
name|Signature
index|[
literal|256
index|]
decl_stmt|;
block|}
name|EFI_CERT_BLOCK_RSA_2048_SHA256
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Certificate which encapsulates a GUID-specific digital signature
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This is the standard WIN_CERTIFICATE header, where
comment|/// wCertificateType is set to WIN_CERT_TYPE_EFI_GUID.
comment|///
name|WIN_CERTIFICATE
name|Hdr
decl_stmt|;
comment|///
comment|/// This is the unique id which determines the
comment|/// format of the CertData. .
comment|///
name|EFI_GUID
name|CertType
decl_stmt|;
comment|///
comment|/// The following is the certificate data. The format of
comment|/// the data is determined by the CertType.
comment|/// If CertType is EFI_CERT_TYPE_RSA2048_SHA256_GUID,
comment|/// the CertData will be EFI_CERT_BLOCK_RSA_2048_SHA256 structure.
comment|///
name|UINT8
name|CertData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|WIN_CERTIFICATE_UEFI_GUID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Certificate which encapsulates the RSASSA_PKCS1-v1_5 digital signature.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The WIN_CERTIFICATE_UEFI_PKCS1_15 structure is derived from
end_comment

begin_comment
comment|/// WIN_CERTIFICATE and encapsulate the information needed to
end_comment

begin_comment
comment|/// implement the RSASSA-PKCS1-v1_5 digital signature algorithm as
end_comment

begin_comment
comment|/// specified in RFC2437.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This is the standard WIN_CERTIFICATE header, where
comment|/// wCertificateType is set to WIN_CERT_TYPE_UEFI_PKCS1_15.
comment|///
name|WIN_CERTIFICATE
name|Hdr
decl_stmt|;
comment|///
comment|/// This is the hashing algorithm which was performed on the
comment|/// UEFI executable when creating the digital signature.
comment|///
name|EFI_GUID
name|HashAlgorithm
decl_stmt|;
comment|///
comment|/// The following is the actual digital signature. The
comment|/// size of the signature is the same size as the key
comment|/// (1024-bit key is 128 bytes) and can be determined by
comment|/// subtracting the length of the other parts of this header
comment|/// from the total length of the certificate as found in
comment|/// Hdr.dwLength.
comment|///
comment|/// UINT8 Signature[];
comment|///
block|}
name|WIN_CERTIFICATE_EFI_PKCS1_15
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertTypeRsa2048Sha256Guid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

