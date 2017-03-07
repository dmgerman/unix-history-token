begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_HASH2_SERVICE_BINDING_PROTOCOL as defined in UEFI 2.5.   EFI_HASH2_PROTOCOL as defined in UEFI 2.5.   The EFI Hash2 Service Binding Protocol is used to locate hashing services support   provided by a driver and to create and destroy instances of the EFI Hash2 Protocol   so that a multiple drivers can use the underlying hashing services.   EFI_HASH2_PROTOCOL describes hashing functions for which the algorithm-required   message padding and finalization are performed by the supporting driver.  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HASH2_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HASH2_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_HASH2_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xda836f8d, 0x217f, 0x4ca0, { 0x99, 0xc2, 0x1c, 0xa4, 0xe1, 0x60, 0x77, 0xea } \   }
end_define

begin_define
define|#
directive|define
name|EFI_HASH2_PROTOCOL_GUID
define|\
value|{ \     0x55b1d734, 0xc5e1, 0x49db, { 0x96, 0x47, 0xb1, 0x6a, 0xfb, 0xe, 0x30, 0x5b } \   }
end_define

begin_include
include|#
directive|include
file|<Protocol/Hash.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE:
end_comment

begin_comment
comment|// Algorithms EFI_HASH_ALGORITHM_SHA1_NOPAD and
end_comment

begin_comment
comment|// EFI_HASH_ALGORITHM_SHA256_NOPAD_GUID are not compatible with
end_comment

begin_comment
comment|// EFI_HASH2_PROTOCOL and will return EFI_UNSUPPORTED if used with any
end_comment

begin_comment
comment|// EFI_HASH2_PROTOCOL function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: SHA-1 and MD5 are included for backwards compatibility.
end_comment

begin_comment
comment|// New driver implementations are encouraged to consider stronger algorithms.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_HASH2_PROTOCOL
name|EFI_HASH2_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_MD5_HASH2
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA1_HASH2
index|[
literal|20
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA224_HASH2
index|[
literal|28
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA256_HASH2
index|[
literal|32
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA384_HASH2
index|[
literal|48
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_SHA512_HASH2
index|[
literal|64
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_MD5_HASH2
name|Md5Hash
decl_stmt|;
name|EFI_SHA1_HASH2
name|Sha1Hash
decl_stmt|;
name|EFI_SHA224_HASH2
name|Sha224Hash
decl_stmt|;
name|EFI_SHA256_HASH2
name|Sha256Hash
decl_stmt|;
name|EFI_SHA384_HASH2
name|Sha384Hash
decl_stmt|;
name|EFI_SHA512_HASH2
name|Sha512Hash
decl_stmt|;
block|}
name|EFI_HASH2_OUTPUT
typedef|;
end_typedef

begin_comment
comment|/**   Returns the size of the hash which results from a specific algorithm.    @param[in]  This                  Points to this instance of EFI_HASH2_PROTOCOL.   @param[in]  HashAlgorithm         Points to the EFI_GUID which identifies the algorithm to use.   @param[out] HashSize              Holds the returned size of the algorithm's hash.    @retval EFI_SUCCESS           Hash size returned successfully.   @retval EFI_INVALID_PARAMETER This or HashSize is NULL.   @retval EFI_UNSUPPORTED       The algorithm specified by HashAlgorithm is not supported by this driver                                 or HashAlgorithm is null.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH2_GET_HASH_SIZE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH2_PROTOCOL
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
comment|/**   Creates a hash for the specified message text. The hash is not extendable.   The output is final with any algorithm-required padding added by the function.    @param[in]  This          Points to this instance of EFI_HASH2_PROTOCOL.   @param[in]  HashAlgorithm Points to the EFI_GUID which identifies the algorithm to use.   @param[in]  Message       Points to the start of the message.   @param[in]  MessageSize   The size of Message, in bytes.   @param[in,out]  Hash      On input, points to a caller-allocated buffer of the size                               returned by GetHashSize() for the specified HashAlgorithm.                             On output, the buffer holds the resulting hash computed from the message.    @retval EFI_SUCCESS           Hash returned successfully.   @retval EFI_INVALID_PARAMETER This or Hash is NULL.   @retval EFI_UNSUPPORTED       The algorithm specified by HashAlgorithm is not supported by this driver                                 or HashAlgorithm is Null.   @retval EFI_OUT_OF_RESOURCES  Some resource required by the function is not available                                 or MessageSize is greater than platform maximum.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH2_HASH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH2_PROTOCOL
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
name|CONST
name|UINT8
modifier|*
name|Message
parameter_list|,
name|IN
name|UINTN
name|MessageSize
parameter_list|,
name|IN
name|OUT
name|EFI_HASH2_OUTPUT
modifier|*
name|Hash
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function must be called to initialize a digest calculation to be subsequently performed using the   EFI_HASH2_PROTOCOL functions HashUpdate() and HashFinal().    @param[in]  This          Points to this instance of EFI_HASH2_PROTOCOL.   @param[in]  HashAlgorithm Points to the EFI_GUID which identifies the algorithm to use.    @retval EFI_SUCCESS           Initialized successfully.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_UNSUPPORTED       The algorithm specified by HashAlgorithm is not supported by this driver                                 or HashAlgorithm is Null.   @retval EFI_OUT_OF_RESOURCES  Process failed due to lack of required resource.   @retval EFI_ALREADY_STARTED   This function is called when the operation in progress is still in processing Hash(),                                 or HashInit() is already called before and not terminated by HashFinal() yet on the same instance.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH2_HASH_INIT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|HashAlgorithm
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Updates the hash of a computation in progress by adding a message text.    @param[in]  This          Points to this instance of EFI_HASH2_PROTOCOL.   @param[in]  Message       Points to the start of the message.   @param[in]  MessageSize   The size of Message, in bytes.    @retval EFI_SUCCESS           Digest in progress updated successfully.   @retval EFI_INVALID_PARAMETER This or Hash is NULL.   @retval EFI_OUT_OF_RESOURCES  Some resource required by the function is not available                                 or MessageSize is greater than platform maximum.   @retval EFI_NOT_READY         This call was not preceded by a valid call to HashInit(),                                 or the operation in progress was terminated by a call to Hash() or HashFinal() on the same instance.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH2_HASH_UPDATE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|UINT8
modifier|*
name|Message
parameter_list|,
name|IN
name|UINTN
name|MessageSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Finalizes a hash operation in progress and returns calculation result.   The output is final with any necessary padding added by the function.   The hash may not be further updated or extended after HashFinal().    @param[in]  This          Points to this instance of EFI_HASH2_PROTOCOL.   @param[in,out]  Hash      On input, points to a caller-allocated buffer of the size                               returned by GetHashSize() for the specified HashAlgorithm specified in preceding HashInit().                             On output, the buffer holds the resulting hash computed from the message.    @retval EFI_SUCCESS           Hash returned successfully.   @retval EFI_INVALID_PARAMETER This or Hash is NULL.   @retval EFI_NOT_READY         This call was not preceded by a valid call to HashInit() and at least one call to HashUpdate(),                                 or the operation in progress was canceled by a call to Hash() on the same instance.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HASH2_HASH_FINAL
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HASH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_HASH2_OUTPUT
modifier|*
name|Hash
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol describes hashing functions for which the algorithm-required message padding and
end_comment

begin_comment
comment|/// finalization are performed by the supporting driver.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HASH2_PROTOCOL
block|{
name|EFI_HASH2_GET_HASH_SIZE
name|GetHashSize
decl_stmt|;
name|EFI_HASH2_HASH
name|Hash
decl_stmt|;
name|EFI_HASH2_HASH_INIT
name|HashInit
decl_stmt|;
name|EFI_HASH2_HASH_UPDATE
name|HashUpdate
decl_stmt|;
name|EFI_HASH2_HASH_FINAL
name|HashFinal
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHash2ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHash2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

