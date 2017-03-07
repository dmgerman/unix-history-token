begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_HASH_SERVICE_BINDING_PROTOCOL as defined in UEFI 2.0.   EFI_HASH_PROTOCOL as defined in UEFI 2.0.   The EFI Hash Service Binding Protocol is used to locate hashing services support    provided by a driver and to create and destroy instances of the EFI Hash Protocol    so that a multiple drivers can use the underlying hashing services.  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HASH_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HASH_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_HASH_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x42881c98, 0xa4f3, 0x44b0, {0xa3, 0x9d, 0xdf, 0xa1, 0x86, 0x67, 0xd8, 0xcd } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_PROTOCOL_GUID
define|\
value|{ \     0xc5184932, 0xdba5, 0x46db, {0xa5, 0xba, 0xcc, 0x0b, 0xda, 0x9c, 0x14, 0x35 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA1_GUID
define|\
value|{ \     0x2ae9d80f, 0x3fb2, 0x4095, {0xb7, 0xb1, 0xe9, 0x31, 0x57, 0xb9, 0x46, 0xb6 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA224_GUID
define|\
value|{ \     0x8df01a06, 0x9bd5, 0x4bf7, {0xb0, 0x21, 0xdb, 0x4f, 0xd9, 0xcc, 0xf4, 0x5b } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA256_GUID
define|\
value|{ \     0x51aa59de, 0xfdf2, 0x4ea3, {0xbc, 0x63, 0x87, 0x5f, 0xb7, 0x84, 0x2e, 0xe9 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA384_GUID
define|\
value|{ \     0xefa96432, 0xde33, 0x4dd2, {0xae, 0xe6, 0x32, 0x8c, 0x33, 0xdf, 0x77, 0x7a } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA512_GUID
define|\
value|{ \     0xcaa4381e, 0x750c, 0x4770, {0xb8, 0x70, 0x7a, 0x23, 0xb4, 0xe4, 0x21, 0x30 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORTIHM_MD5_GUID
define|\
value|{ \     0xaf7c79c, 0x65b5, 0x4319, {0xb0, 0xae, 0x44, 0xec, 0x48, 0x4e, 0x4a, 0xd7 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA1_NOPAD_GUID
define|\
value|{ \     0x24c5dc2f, 0x53e2, 0x40ca, {0x9e, 0xd6, 0xa5, 0xd9, 0xa4, 0x9f, 0x46, 0x3b } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH_ALGORITHM_SHA256_NOPAD_GUID
define|\
value|{ \     0x8628752a, 0x6cb7, 0x4814, {0x96, 0xfc, 0x24, 0xa8, 0x15, 0xac, 0x22, 0x26 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: Use of the following algorithms with EFI_HASH_PROTOCOL is deprecated.
end_comment

begin_comment
comment|//       EFI_HASH_ALGORITHM_SHA1_GUID
end_comment

begin_comment
comment|//       EFI_HASH_ALGORITHM_SHA224_GUID
end_comment

begin_comment
comment|//       EFI_HASH_ALGORITHM_SHA256_GUID
end_comment

begin_comment
comment|//       EFI_HASH_ALGORITHM_SHA384_GUID
end_comment

begin_comment
comment|//       EFI_HASH_ALGORITHM_SHA512_GUID
end_comment

begin_comment
comment|//       EFI_HASH_ALGORTIHM_MD5_GUID
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_HASH_PROTOCOL
name|EFI_HASH_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_MD5_HASH
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA1_HASH
index|[
literal|20
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA224_HASH
index|[
literal|28
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA256_HASH
index|[
literal|32
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA384_HASH
index|[
literal|48
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA512_HASH
index|[
literal|64
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_MD5_HASH
modifier|*
name|Md5Hash
decl_stmt|;
name|EFI_SHA1_HASH
modifier|*
name|Sha1Hash
decl_stmt|;
name|EFI_SHA224_HASH
modifier|*
name|Sha224Hash
decl_stmt|;
name|EFI_SHA256_HASH
modifier|*
name|Sha256Hash
decl_stmt|;
name|EFI_SHA384_HASH
modifier|*
name|Sha384Hash
decl_stmt|;
name|EFI_SHA512_HASH
modifier|*
name|Sha512Hash
decl_stmt|;
block|}
name|EFI_HASH_OUTPUT
typedef|;
end_typedef

begin_comment
comment|/**   Returns the size of the hash which results from a specific algorithm.    @param[in]  This                  Points to this instance of EFI_HASH_PROTOCOL.   @param[in]  HashAlgorithm         Points to the EFI_GUID which identifies the algorithm to use.   @param[out] HashSize              Holds the returned size of the algorithm's hash.    @retval EFI_SUCCESS           Hash size returned successfully.   @retval EFI_INVALID_PARAMETER HashSize is NULL or HashAlgorithm is NULL.   @retval EFI_UNSUPPORTED       The algorithm specified by HashAlgorithm is not supported                                  by this driver.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH_GET_HASH_SIZE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|HashAlgorithm
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|HashSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a hash for the specified message text.    @param[in]  This          Points to this instance of EFI_HASH_PROTOCOL.   @param[in]  HashAlgorithm Points to the EFI_GUID which identifies the algorithm to use.   @param[in]  Extend        Specifies whether to create a new hash (FALSE) or extend the specified                             existing hash (TRUE).   @param[in]  Message       Points to the start of the message.   @param[in]  MessageSize   The size of Message, in bytes.   @param[in,out]  Hash      On input, if Extend is TRUE, then this parameter holds a pointer                              to a pointer to an array containing the hash to extend. If Extend                              is FALSE, then this parameter holds a pointer to a pointer to a                              caller-allocated array that will receive the result of the hash                              computation. On output (regardless of the value of Extend), the                              array will contain the result of the hash computation.      @retval EFI_SUCCESS           Hash returned successfully.   @retval EFI_INVALID_PARAMETER Message or Hash, HashAlgorithm is NULL or MessageSize is 0.                                 MessageSize is not an integer multiple of block size.   @retval EFI_UNSUPPORTED       The algorithm specified by HashAlgorithm is not supported by this                                  driver. Or, Extend is TRUE, and the algorithm doesn't support extending the hash.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH_HASH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|HashAlgorithm
parameter_list|,
name|IN
name|BOOLEAN
name|Extend
parameter_list|,
name|IN
name|CONST
name|UINT8
modifier|*
name|Message
parameter_list|,
name|IN
name|UINT64
name|MessageSize
parameter_list|,
name|IN
name|OUT
name|EFI_HASH_OUTPUT
modifier|*
name|Hash
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol allows creating a hash of an arbitrary message digest
end_comment

begin_comment
comment|/// using one or more hash algorithms.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HASH_PROTOCOL
block|{
name|EFI_HASH_GET_HASH_SIZE
name|GetHashSize
decl_stmt|;
name|EFI_HASH_HASH
name|Hash
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha1Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha224Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha256Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha384Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha512Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmMD5Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha1NoPadGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHashAlgorithmSha256NoPadGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

