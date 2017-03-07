begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Image signature database are defined for the signed image validation.    Copyright (c) 2009 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUIDs defined in UEFI 2.5 spec. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IMAGE_AUTHTICATION_H__
end_ifndef

begin_define
define|#
directive|define
name|__IMAGE_AUTHTICATION_H__
end_define

begin_include
include|#
directive|include
file|<Guid/GlobalVariable.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/Hash.h>
end_include

begin_define
define|#
directive|define
name|EFI_IMAGE_SECURITY_DATABASE_GUID
define|\
value|{ \     0xd719b2cb, 0x3d3a, 0x4596, { 0xa3, 0xbc, 0xda, 0xd0, 0xe, 0x67, 0x65, 0x6f } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Varialbe name with guid EFI_IMAGE_SECURITY_DATABASE_GUID
end_comment

begin_comment
comment|/// for the authorized signature database.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SECURITY_DATABASE
value|L"db"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Varialbe name with guid EFI_IMAGE_SECURITY_DATABASE_GUID
end_comment

begin_comment
comment|/// for the forbidden signature database.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SECURITY_DATABASE1
value|L"dbx"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Variable name with guid EFI_IMAGE_SECURITY_DATABASE_GUID
end_comment

begin_comment
comment|/// for the timestamp signature database.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_SECURITY_DATABASE2
value|L"dbt"
end_define

begin_define
define|#
directive|define
name|SECURE_BOOT_MODE_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|SECURE_BOOT_MODE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|SETUP_MODE
value|1
end_define

begin_define
define|#
directive|define
name|USER_MODE
value|0
end_define

begin_comment
comment|//***********************************************************************
end_comment

begin_comment
comment|// Signature Database
end_comment

begin_comment
comment|//***********************************************************************
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format of a signature database.
end_comment

begin_comment
comment|///
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// An identifier which identifies the agent which added the signature to the list.
comment|///
name|EFI_GUID
name|SignatureOwner
decl_stmt|;
comment|///
comment|/// The format of the signature is defined by the SignatureType.
comment|///
name|UINT8
name|SignatureData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_SIGNATURE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Type of the signature. GUID signature types are defined in below.
comment|///
name|EFI_GUID
name|SignatureType
decl_stmt|;
comment|///
comment|/// Total size of the signature list, including this header.
comment|///
name|UINT32
name|SignatureListSize
decl_stmt|;
comment|///
comment|/// Size of the signature header which precedes the array of signatures.
comment|///
name|UINT32
name|SignatureHeaderSize
decl_stmt|;
comment|///
comment|/// Size of each signature.
comment|///
name|UINT32
name|SignatureSize
decl_stmt|;
comment|///
comment|/// Header before the array of signatures. The format of this header is specified
comment|/// by the SignatureType.
comment|/// UINT8           SignatureHeader[SignatureHeaderSize];
comment|///
comment|/// An array of signatures. Each signature is SignatureSize bytes in length.
comment|/// EFI_SIGNATURE_DATA Signatures[][SignatureSize];
comment|///
block|}
name|EFI_SIGNATURE_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The SHA256 hash of an X.509 certificate's To-Be-Signed contents.
comment|///
name|EFI_SHA256_HASH
name|ToBeSignedHash
decl_stmt|;
comment|///
comment|/// The time that the certificate shall be considered to be revoked.
comment|///
name|EFI_TIME
name|TimeOfRevocation
decl_stmt|;
block|}
name|EFI_CERT_X509_SHA256
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The SHA384 hash of an X.509 certificate's To-Be-Signed contents.
comment|///
name|EFI_SHA384_HASH
name|ToBeSignedHash
decl_stmt|;
comment|///
comment|/// The time that the certificate shall be considered to be revoked.
comment|///
name|EFI_TIME
name|TimeOfRevocation
decl_stmt|;
block|}
name|EFI_CERT_X509_SHA384
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The SHA512 hash of an X.509 certificate's To-Be-Signed contents.
comment|///
name|EFI_SHA512_HASH
name|ToBeSignedHash
decl_stmt|;
comment|///
comment|/// The time that the certificate shall be considered to be revoked.
comment|///
name|EFI_TIME
name|TimeOfRevocation
decl_stmt|;
block|}
name|EFI_CERT_X509_SHA512
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a SHA-256 hash. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of SignatureOwner component) +
end_comment

begin_comment
comment|/// 32 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_SHA256_GUID
define|\
value|{ \     0xc1c41626, 0x504c, 0x4092, {0xac, 0xa9, 0x41, 0xf9, 0x36, 0x93, 0x43, 0x28} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing an RSA-2048 key. The key (only the modulus
end_comment

begin_comment
comment|/// since the public key exponent is known to be 0x10001) shall be stored in big-endian
end_comment

begin_comment
comment|/// order.
end_comment

begin_comment
comment|/// The SignatureHeader size shall always be 0. The SignatureSize shall always be 16 (size
end_comment

begin_comment
comment|/// of SignatureOwner component) + 256 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_RSA2048_GUID
define|\
value|{ \     0x3c5766e8, 0x269c, 0x4e34, {0xaa, 0x14, 0xed, 0x77, 0x6e, 0x85, 0xb3, 0xb6} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a RSA-2048 signature of a SHA-256 hash.  The
end_comment

begin_comment
comment|/// SignatureHeader size shall always be 0. The SignatureSize shall always be 16 (size of
end_comment

begin_comment
comment|/// SignatureOwner component) + 256 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_RSA2048_SHA256_GUID
define|\
value|{ \     0xe2b36190, 0x879b, 0x4a3d, {0xad, 0x8d, 0xf2, 0xe7, 0xbb, 0xa3, 0x27, 0x84} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a SHA-1 hash.  The SignatureSize shall always
end_comment

begin_comment
comment|/// be 16 (size of SignatureOwner component) + 20 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_SHA1_GUID
define|\
value|{ \     0x826ca512, 0xcf10, 0x4ac9, {0xb1, 0x87, 0xbe, 0x1, 0x49, 0x66, 0x31, 0xbd} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TThis identifies a signature containing a RSA-2048 signature of a SHA-1 hash.  The
end_comment

begin_comment
comment|/// SignatureHeader size shall always be 0. The SignatureSize shall always be 16 (size of
end_comment

begin_comment
comment|/// SignatureOwner component) + 256 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_RSA2048_SHA1_GUID
define|\
value|{ \     0x67f8444f, 0x8743, 0x48f1, {0xa3, 0x28, 0x1e, 0xaa, 0xb8, 0x73, 0x60, 0x80} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature based on an X.509 certificate. If the signature is an X.509
end_comment

begin_comment
comment|/// certificate then verification of the signature of an image should validate the public
end_comment

begin_comment
comment|/// key certificate in the image using certificate path verification, up to this X.509
end_comment

begin_comment
comment|/// certificate as a trusted root.  The SignatureHeader size shall always be 0. The
end_comment

begin_comment
comment|/// SignatureSize may vary but shall always be 16 (size of the SignatureOwner component) +
end_comment

begin_comment
comment|/// the size of the certificate itself.
end_comment

begin_comment
comment|/// Note: This means that each certificate will normally be in a separate EFI_SIGNATURE_LIST.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_X509_GUID
define|\
value|{ \     0xa5c059a1, 0x94e4, 0x4aa7, {0x87, 0xb5, 0xab, 0x15, 0x5c, 0x2b, 0xf0, 0x72} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a SHA-224 hash. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of SignatureOwner component) +
end_comment

begin_comment
comment|/// 28 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_SHA224_GUID
define|\
value|{ \     0xb6e5233, 0xa65c, 0x44c9, {0x94, 0x7, 0xd9, 0xab, 0x83, 0xbf, 0xc8, 0xbd} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a SHA-384 hash. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of SignatureOwner component) +
end_comment

begin_comment
comment|/// 48 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_SHA384_GUID
define|\
value|{ \     0xff3e5307, 0x9fd0, 0x48c9, {0x85, 0xf1, 0x8a, 0xd5, 0x6c, 0x70, 0x1e, 0x1} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a SHA-512 hash. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of SignatureOwner component) +
end_comment

begin_comment
comment|/// 64 bytes.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_SHA512_GUID
define|\
value|{ \     0x93e0fae, 0xa6c4, 0x4f50, {0x9f, 0x1b, 0xd4, 0x1e, 0x2b, 0x89, 0xc1, 0x9a} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing the SHA256 hash of an X.509 certificate's
end_comment

begin_comment
comment|/// To-Be-Signed contents, and a time of revocation. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of the SignatureOwner component)
end_comment

begin_comment
comment|/// + 48 bytes for an EFI_CERT_X509_SHA256 structure. If the TimeOfRevocation is non-zero,
end_comment

begin_comment
comment|/// the certificate should be considered to be revoked from that time and onwards, and
end_comment

begin_comment
comment|/// otherwise the certificate shall be considered to always be revoked.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_X509_SHA256_GUID
define|\
value|{ \     0x3bd2a492, 0x96c0, 0x4079, {0xb4, 0x20, 0xfc, 0xf9, 0x8e, 0xf1, 0x03, 0xed } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing the SHA384 hash of an X.509 certificate's
end_comment

begin_comment
comment|/// To-Be-Signed contents, and a time of revocation. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of the SignatureOwner component)
end_comment

begin_comment
comment|/// + 64 bytes for an EFI_CERT_X509_SHA384 structure. If the TimeOfRevocation is non-zero,
end_comment

begin_comment
comment|/// the certificate should be considered to be revoked from that time and onwards, and
end_comment

begin_comment
comment|/// otherwise the certificate shall be considered to always be revoked.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_X509_SHA384_GUID
define|\
value|{ \     0x7076876e, 0x80c2, 0x4ee6, {0xaa, 0xd2, 0x28, 0xb3, 0x49, 0xa6, 0x86, 0x5b } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing the SHA512 hash of an X.509 certificate's
end_comment

begin_comment
comment|/// To-Be-Signed contents, and a time of revocation. The SignatureHeader size shall
end_comment

begin_comment
comment|/// always be 0. The SignatureSize shall always be 16 (size of the SignatureOwner component)
end_comment

begin_comment
comment|/// + 80 bytes for an EFI_CERT_X509_SHA512 structure. If the TimeOfRevocation is non-zero,
end_comment

begin_comment
comment|/// the certificate should be considered to be revoked from that time and onwards, and
end_comment

begin_comment
comment|/// otherwise the certificate shall be considered to always be revoked.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_X509_SHA512_GUID
define|\
value|{ \     0x446dbf63, 0x2502, 0x4cda, {0xbc, 0xfa, 0x24, 0x65, 0xd2, 0xb0, 0xfe, 0x9d } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This identifies a signature containing a DER-encoded PKCS #7 version 1.5 [RFC2315]
end_comment

begin_comment
comment|/// SignedData value.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_CERT_TYPE_PKCS7_GUID
define|\
value|{ \     0x4aafd29d, 0x68df, 0x49ee, {0x8a, 0xa9, 0x34, 0x7d, 0x37, 0x56, 0x65, 0xa7} \   }
end_define

begin_comment
comment|//***********************************************************************
end_comment

begin_comment
comment|// Image Execution Information Table Definition
end_comment

begin_comment
comment|//***********************************************************************
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_IMAGE_EXECUTION_ACTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTHENTICATION
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTH_UNTESTED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTH_SIG_FAILED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTH_SIG_PASSED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTH_SIG_NOT_FOUND
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_AUTH_SIG_FOUND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_POLICY_FAILED
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_EXECUTION_INITIALIZED
value|0x00000008
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_IMAGE_EXECUTION_INFO is added to EFI System Configuration Table
end_comment

begin_comment
comment|// and assigned the GUID EFI_IMAGE_SECURITY_DATABASE_GUID.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Describes the action taken by the firmware regarding this image.
comment|///
name|EFI_IMAGE_EXECUTION_ACTION
name|Action
decl_stmt|;
comment|///
comment|/// Size of all of the entire structure.
comment|///
name|UINT32
name|InfoSize
decl_stmt|;
comment|///
comment|/// If this image was a UEFI device driver (for option ROM, for example) this is the
comment|/// null-terminated, user-friendly name for the device. If the image was for an application,
comment|/// then this is the name of the application. If this cannot be determined, then a simple
comment|/// NULL character should be put in this position.
comment|/// CHAR16                    Name[];
comment|///
comment|///
comment|/// For device drivers, this is the device path of the device for which this device driver
comment|/// was intended. In some cases, the driver itself may be stored as part of the system
comment|/// firmware, but this field should record the device's path, not the firmware path. For
comment|/// applications, this is the device path of the application. If this cannot be determined,
comment|/// a simple end-of-path device node should be put in this position.
comment|/// EFI_DEVICE_PATH_PROTOCOL  DevicePath;
comment|///
comment|///
comment|/// Zero or more image signatures. If the image contained no signatures,
comment|/// then this field is empty.
comment|/// EFI_SIGNATURE_LIST            Signature;
comment|///
block|}
name|EFI_IMAGE_EXECUTION_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Number of EFI_IMAGE_EXECUTION_INFO structures.
comment|///
name|UINTN
name|NumberOfImages
decl_stmt|;
comment|///
comment|/// Number of image instances of EFI_IMAGE_EXECUTION_INFO structures.
comment|///
comment|// EFI_IMAGE_EXECUTION_INFO  InformationInfo[]
block|}
name|EFI_IMAGE_EXECUTION_INFO_TABLE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiImageSecurityDatabaseGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertSha256Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertRsa2048Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertRsa2048Sha256Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertSha1Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertRsa2048Sha1Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertX509Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertSha224Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertSha384Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertSha512Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertX509Sha256Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertX509Sha384Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertX509Sha512Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCertPkcs7Guid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

