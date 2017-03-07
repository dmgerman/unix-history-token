begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_PKCS7_VERIFY_PROTOCOL as defined in UEFI 2.5.   The EFI_PKCS7_VERIFY_PROTOCOL is used to verify data signed using PKCS#7   formatted authentication. The PKCS#7 data to be verified must be binary   DER encoded.   PKCS#7 is a general-purpose cryptographic standard (defined by RFC2315,   available at http://tools.ietf.org/html/rfc2315).  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_PKCS7_VERIFY_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_PKCS7_VERIFY_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Guid/ImageAuthentication.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the PKCS7 Verification Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PKCS7_VERIFY_PROTOCOL_GUID
define|\
value|{ \     0x47889fb2, 0xd671, 0x4fab, {0xa0, 0xca, 0xdf, 0x0e, 0x44, 0xdf, 0x70, 0xd6 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PKCS7_VERIFY_PROTOCOL
name|EFI_PKCS7_VERIFY_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Processes a buffer containing binary DER-encoded PKCS7 signature.   The signed data content may be embedded within the buffer or separated. Funtion   verifies the signature of the content is valid and signing certificate was not   revoked and is contained within a list of trusted signers.    @param[in]     This                 Pointer to EFI_PKCS7_VERIFY_PROTOCOL instance.   @param[in]     SignedData           Points to buffer containing ASN.1 DER-encoded PKCS7                                       signature.   @param[in]     SignedDataSize       The size of SignedData buffer in bytes.   @param[in]     InData               In case of detached signature, InData points to                                       buffer containing the raw message data previously                                       signed and to be verified by function. In case of                                       SignedData containing embedded data, InData must be                                       NULL.   @param[in]     InDataSize           When InData is used, the size of InData buffer in                                       bytes. When InData is NULL. This parameter must be                                       0.   @param[in]     AllowedDb            Pointer to a list of pointers to EFI_SIGNATURE_LIST                                       structures. The list is terminated by a null                                       pointer. The EFI_SIGNATURE_LIST structures contain                                       lists of X.509 certificates of approved signers.                                       Function recognizes signer certificates of type                                       EFI_CERT_X509_GUID. Any hash certificate in AllowedDb                                       list is ignored by this function. Function returns                                       success if signer of the buffer is within this list                                       (and not within RevokedDb). This parameter is                                       required.   @param[in]     RevokedDb            Optional pointer to a list of pointers to                                       EFI_SIGNATURE_LIST structures. The list is terminated                                       by a null pointer. List of X.509 certificates of                                       revoked signers and revoked file hashes. Except as                                       noted in description of TimeStampDb signature                                       verification will always fail if the signer of the                                       file or the hash of the data component of the buffer                                       is in RevokedDb list. This list is optional and                                       caller may pass Null or pointer to NULL if not                                       required.   @param[in]     TimeStampDb          Optional pointer to a list of pointers to                                       EFI_SIGNATURE_LIST structures. The list is terminated                                       by a null pointer. This parameter can be used to pass                                       a list of X.509 certificates of trusted time stamp                                       signers. This list is optional and caller must pass                                       Null or pointer to NULL if not required.   @param[out]    Content              On input, points to an optional caller-allocated                                       buffer into which the function will copy the content                                       portion of the file after verification succeeds.                                       This parameter is optional and if NULL, no copy of                                       content from file is performed.   @param[in,out] ContentSize          On input, points to the size in bytes of the optional                                       buffer Content previously allocated by caller. On                                       output, if the verification succeeds, the value                                       referenced by ContentSize will contain the actual                                       size of the content from signed file. If ContentSize                                       indicates the caller-allocated buffer is too small                                       to contain content, an error is returned, and                                       ContentSize will be updated with the required size.                                       This parameter must be 0 if Content is Null.    @retval EFI_SUCCESS                 Content signature was verified against hash of                                       content, the signer's certificate was not found in                                       RevokedDb, and was found in AllowedDb or if in signer                                       is found in both AllowedDb and RevokedDb, the                                       signing was allowed by reference to TimeStampDb as                                       described above, and no hash matching content hash                                       was found in RevokedDb.   @retval EFI_SECURITY_VIOLATION      The SignedData buffer was correctly formatted but                                       signer was in RevokedDb or not in AllowedDb. Also                                       returned if matching content hash found in RevokedDb.   @retval EFI_COMPROMISED_DATA        Calculated hash differs from signed hash.   @retval EFI_INVALID_PARAMETER       SignedData is NULL or SignedDataSize is zero.                                       AllowedDb is NULL.   @retval EFI_INVALID_PARAMETER       Content is not NULL and ContentSize is NULL.   @retval EFI_ABORTED                 Unsupported or invalid format in TimeStampDb,                                       RevokedDb or AllowedDb list contents was detected.   @retval EFI_NOT_FOUND               Content not found because InData is NULL and no                                       content embedded in SignedData.   @retval EFI_UNSUPPORTED             The SignedData buffer was not correctly formatted                                       for processing by the function.   @retval EFI_UNSUPPORTED             Signed data embedded in SignedData but InData is not                                       NULL.   @retval EFI_BUFFER_TOO_SMALL        The size of buffer indicated by ContentSize is too                                       small to hold the content. ContentSize updated to                                       required size.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PKCS7_VERIFY_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_PKCS7_VERIFY_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|SignedData
parameter_list|,
name|IN
name|UINTN
name|SignedDataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|InData
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|InDataSize
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|AllowedDb
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|RevokedDb
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|TimeStampDb
name|OPTIONAL
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Content
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ContentSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Processes a buffer containing binary DER-encoded detached PKCS7 signature.   The hash of the signed data content is calculated and passed by the caller. Function   verifies the signature of the content is valid and signing certificate was not revoked   and is contained within a list of trusted signers.    @param[in]     This                 Pointer to EFI_PKCS7_VERIFY_PROTOCOL instance.   @param[in]     Signature            Points to buffer containing ASN.1 DER-encoded PKCS                                       detached signature.   @param[in]     SignatureSize        The size of Signature buffer in bytes.   @param[in]     InHash               InHash points to buffer containing the caller                                       calculated hash of the data. The parameter may not                                       be NULL.   @param[in]     InHashSize           The size in bytes of InHash buffer.   @param[in]     AllowedDb            Pointer to a list of pointers to EFI_SIGNATURE_LIST                                       structures. The list is terminated by a null                                       pointer. The EFI_SIGNATURE_LIST structures contain                                       lists of X.509 certificates of approved signers.                                       Function recognizes signer certificates of type                                       EFI_CERT_X509_GUID. Any hash certificate in AllowedDb                                       list is ignored by this function. Function returns                                       success if signer of the buffer is within this list                                       (and not within RevokedDb). This parameter is                                       required.   @param[in]     RevokedDb            Optional pointer to a list of pointers to                                       EFI_SIGNATURE_LIST structures. The list is terminated                                       by a null pointer. List of X.509 certificates of                                       revoked signers and revoked file hashes. Signature                                       verification will always fail if the signer of the                                       file or the hash of the data component of the buffer                                       is in RevokedDb list. This parameter is optional                                       and caller may pass Null if not required.   @param[in]     TimeStampDb          Optional pointer to a list of pointers to                                       EFI_SIGNATURE_LIST structures. The list is terminated                                       by a null pointer. This parameter can be used to pass                                       a list of X.509 certificates of trusted time stamp                                       counter-signers.    @retval EFI_SUCCESS                 Signed hash was verified against caller-provided                                       hash of content, the signer's certificate was not                                       found in RevokedDb, and was found in AllowedDb or                                       if in signer is found in both AllowedDb and                                       RevokedDb, the signing was allowed by reference to                                       TimeStampDb as described above, and no hash matching                                       content hash was found in RevokedDb.   @retval EFI_SECURITY_VIOLATION      The SignedData buffer was correctly formatted but                                       signer was in RevokedDb or not in AllowedDb. Also                                       returned if matching content hash found in RevokedDb.   @retval EFI_COMPROMISED_DATA        Caller provided hash differs from signed hash. Or,                                       caller and encrypted hash are different sizes.   @retval EFI_INVALID_PARAMETER       Signature is NULL or SignatureSize is zero. InHash                                       is NULL or InHashSize is zero. AllowedDb is NULL.   @retval EFI_ABORTED                 Unsupported or invalid format in TimeStampDb,                                       RevokedDb or AllowedDb list contents was detected.   @retval EFI_UNSUPPORTED             The Signature buffer was not correctly formatted                                       for processing by the function.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PKCS7_VERIFY_SIGNATURE
function_decl|)
parameter_list|(
name|IN
name|EFI_PKCS7_VERIFY_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Signature
parameter_list|,
name|IN
name|UINTN
name|SignatureSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|InHash
parameter_list|,
name|IN
name|UINTN
name|InHashSize
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|AllowedDb
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|RevokedDb
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_SIGNATURE_LIST
modifier|*
modifier|*
name|TimeStampDb
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_PKCS7_VERIFY_PROTOCOL is used to verify data signed using PKCS7
end_comment

begin_comment
comment|/// structure. The PKCS7 data to be verified must be ASN.1 (DER) encoded.
end_comment

begin_comment
comment|/// SHA256 must be supported as digest algorithm with RSA digest encryption.
end_comment

begin_comment
comment|/// Support of other hash algorithms is optional.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PKCS7_VERIFY_PROTOCOL
block|{
name|EFI_PKCS7_VERIFY_BUFFER
name|VerifyBuffer
decl_stmt|;
name|EFI_PKCS7_VERIFY_SIGNATURE
name|VerifySignature
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPkcs7VerifyProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

