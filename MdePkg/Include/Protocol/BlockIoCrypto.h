begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The UEFI Inline Cryptographic Interface protocol provides services to abstract   access to inline cryptographic capabilities.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BLOCK_IO_CRYPTO_H__
end_ifndef

begin_define
define|#
directive|define
name|__BLOCK_IO_CRYPTO_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/BlockIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL_GUID
define|\
value|{ \       0xa00490ba, 0x3f1a, 0x4b4c, {0xab, 0x90, 0x4f, 0xa9, 0x97, 0x26, 0xa1, 0xe8} \     }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BLOCK_IO_CRYPTO_PROTOCOL
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The struct of Block I/O Crypto Token.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If Event is NULL, then blocking I/O is performed. If Event is not NULL and
comment|// non-blocking I/O is supported, then non-blocking I/O is performed, and
comment|// Event will be signaled when the read request is completed and data was
comment|// decrypted  (when Index was specified).
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Defines whether or not the signaled event encountered an error.
comment|//
name|EFI_STATUS
name|TransactionStatus
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// GUID of the algorithm.
comment|//
name|EFI_GUID
name|Algorithm
decl_stmt|;
comment|//
comment|// Specifies KeySizein bits used with this Algorithm.
comment|//
name|UINT64
name|KeySize
decl_stmt|;
comment|//
comment|// Specifies bitmask of block sizes supported by this algorithm.
comment|// Bit j being set means that 2^j bytes crypto block size is supported.
comment|//
name|UINT64
name|CryptoBlockSizeBitMask
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_CAPABILITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLOCK_IO_CRYPTO_IV_INPUT structure is used as a common header in CryptoIvInput
end_comment

begin_comment
comment|/// parameters passed to the ReadExtended and WriteExtended methods for Inline
end_comment

begin_comment
comment|/// Cryptographic Interface.
end_comment

begin_comment
comment|/// Its purpose is to pass size of the entire CryptoIvInputparameter memory buffer to
end_comment

begin_comment
comment|/// the Inline Cryptographic Interface.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|InputSize
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_IV_INPUT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_CRYPTO_ALGO_GUID_AES_XTS
define|\
value|{ \       0x2f87ba6a, 0x5c04, 0x4385, {0xa7, 0x80, 0xf3, 0xbf, 0x78, 0xa9, 0x7b, 0xec} \     }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBlockIoCryptoAlgoAesXtsGuid
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_BLOCK_IO_CRYPTO_IV_INPUT
name|Header
decl_stmt|;
name|UINT64
name|CryptoBlockNumber
decl_stmt|;
name|UINT64
name|CryptoBlockByteSize
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_IV_INPUT_AES_XTS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_CRYPTO_ALGO_GUID_AES_CBC_MICROSOFT_BITLOCKER
define|\
value|{ \       0x689e4c62, 0x70bf, 0x4cf3, {0x88, 0xbb, 0x33, 0xb3, 0x18, 0x26, 0x86, 0x70} \     }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBlockIoCryptoAlgoAesCbcMsBitlockerGuid
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_BLOCK_IO_CRYPTO_IV_INPUT
name|Header
decl_stmt|;
name|UINT64
name|CryptoBlockByteOffset
decl_stmt|;
name|UINT64
name|CryptoBlockByteSize
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_IV_INPUT_AES_CBC_MICROSOFT_BITLOCKER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_CRYPTO_INDEX_ANY
value|0xFFFFFFFFFFFFFFFF
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Is inline cryptographic capability supported on this device.
comment|//
name|BOOLEAN
name|Supported
decl_stmt|;
comment|//
comment|// Maximum number of keys that can be configured at the same time.
comment|//
name|UINT64
name|KeyCount
decl_stmt|;
comment|//
comment|// Number of supported capabilities.
comment|//
name|UINT64
name|CapabilityCount
decl_stmt|;
comment|//
comment|// Array of supported capabilities.
comment|//
name|EFI_BLOCK_IO_CRYPTO_CAPABILITY
name|Capabilities
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_CAPABILITIES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Configuration table index. A special Index EFI_BLOCK_IO_CRYPTO_INDEX_ANY can be
comment|// used to set any available entry in the configuration table.
comment|//
name|UINT64
name|Index
decl_stmt|;
comment|//
comment|// Identifies the owner of the configuration table entry. Entry can also be used
comment|// with the Nil value to clear key from the configuration table index.
comment|//
name|EFI_GUID
name|KeyOwnerGuid
decl_stmt|;
comment|//
comment|// A supported capability to be used. The CryptoBlockSizeBitMask field of the
comment|// structure should have only one bit set from the supported mask.
comment|//
name|EFI_BLOCK_IO_CRYPTO_CAPABILITY
name|Capability
decl_stmt|;
comment|//
comment|// Pointer to the key. The size of the key is defined by the KeySize field of
comment|// the capability specified by the Capability parameter.
comment|//
name|VOID
modifier|*
name|CryptoKey
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_CONFIGURATION_TABLE_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Configuration table index.
comment|//
name|UINT64
name|Index
decl_stmt|;
comment|//
comment|// Identifies the current owner of the entry.
comment|//
name|EFI_GUID
name|KeyOwnerGuid
decl_stmt|;
comment|//
comment|// The capability to be used. The CryptoBlockSizeBitMask field of the structure
comment|// has only one bit set from the supported mask.
comment|//
name|EFI_BLOCK_IO_CRYPTO_CAPABILITY
name|Capability
decl_stmt|;
block|}
name|EFI_BLOCK_IO_CRYPTO_RESPONSE_CONFIGURATION_ENTRY
typedef|;
end_typedef

begin_comment
comment|/**   Reset the block device hardware.    The Reset() function resets the block device hardware.    As part of the initialization process, the firmware/device will make a quick but   reasonable attempt to verify that the device is functioning.    If the ExtendedVerificationflag is TRUE the firmware may take an extended amount   of time to verify the device is operating on reset. Otherwise the reset operation   is to occur as quickly as possible.    The hardware verification process is not defined by this specification and is left   up to the platform firmware or driver to implement.    @param[in]  This                 Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in]  ExtendedVerification Indicates that the driver may perform a more exhausive                                    verification operation of the device during reset.    @retval EFI_SUCCESS              The block device was reset.   @retval EFI_DEVICE_ERROR         The block device is not functioning correctly and could                                    not be reset.   @retval EFI_INVALID_PARAMETER    This is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the capabilities of the underlying inline cryptographic interface.    The GetCapabilities() function determines whether pre-OS controllable inline crypto   is supported by the system for the current disk and, if so, returns the capabilities   of the crypto engine.    The caller is responsible for providing the Capabilities structure with a sufficient   number of entries.    If the structure is too small, the EFI_BUFFER_TOO_SMALL error code is returned and the   CapabilityCount field contains the number of entries needed to contain the capabilities.    @param[in]  This              Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[out] Capabilities      Pointer to the EFI_BLOCK_IO_CRYPTO_CAPABILITIES structure.    @retval EFI_SUCCESS           The ICI is ready for use.   @retval EFI_BUFFER_TOO_SMALL  The Capabilities structure was too small. The number of                                 entries needed is returned in the CapabilityCount field                                 of the structure.   @retval EFI_NO_RESPONSE       No response was received from the ICI.   @retval EFI_DEVICE_ERROR      An error occurred when attempting to access the ICI.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_INVALID_PARAMETER Capabilities is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_GET_CAPABILITIES
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_BLOCK_IO_CRYPTO_CAPABILITIES
modifier|*
name|Capabilities
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the configuration of the underlying inline cryptographic interface.    The SetConfiguration() function allows the user to set the current configuration of the   inline cryptographic interface and should be called before attempting any crypto operations.    This configures the configuration table entries with algorithms, key sizes and keys. Each   configured entry can later be referred to by index at the time of storage transaction.    The configuration table index will refer to the combination ofKeyOwnerGuid, Algorithm, and   CryptoKey.    KeyOwnerGuid identifies the component taking ownership of the entry. It helps components to   identify their own entries, cooperate with other owner components, and avoid conflicts. This   Guid identifier is there to help coordination between cooperating components and not a security   or synchronization feature. The Nil GUID can be used by a component to release use of entry   owned. It is also used to identify potentially available entries (see GetConfiguration).    CryptoKey specifies algorithm-specific key material to use within parameters of selected crypto   capability.    This function is called infrequently typically once, on device start, before IO starts. It   can be called at later times in cases the number of keysused on the drive is higher than what   can be configured at a time or a new key has to be added.    Components setting or changing an entry or entries for a given index or indices must ensure   that IO referencing affected indices is temporarily blocked (run-down) at the time of change.    Indices parameters in each parameter table entry allow to set only a portion of the available   table entries in the crypto module anywhere from single entry to entire table supported.    If corresponding table entry or entries being set are already in use by another owner the call   should be failed and none of the entries should be modified. The interface implementation must   enforce atomicity of this operation (should either succeed fully or fail completely without   modifying state).    Note that components using GetConfiguration command to discover available entries should be   prepared that by the time of calling SetConfiguration the previously available entry may have   become occupied. Such components should be prepared to re-try the sequence of operations.    Alternatively EFI_BLOCK_IO_CRYPTO_INDEX_ANY can be used to have the implementation discover   and allocate available,if any, indices atomically.    An optional ResultingTable pointer can be provided by the caller to receive the newly configured   entries. The array provided by the caller must have at least ConfigurationCount of entries.    @param[in]  This                Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in]  ConfigurationCount  Number of entries being configured with this call.   @param[in]  ConfigurationTable  Pointer to a table used to populate the configuration table.   @param[out] ResultingTable      Optional pointer to a table that receives the newly configured                                   entries.    @retval EFI_SUCCESS             The ICI is ready for use.   @retval EFI_NO_RESPONSE         No response was received from the ICI.   @retval EFI_DEVICE_ERROR        An error occurred when attempting to access the ICI.   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_INVALID_PARAMETER   ConfigurationTable is NULL.   @retval EFI_INVALID_PARAMETER   ConfigurationCount is 0.   @retval EFI_OUT_OF_RESOURCES    Could not find the requested number of available entries in the                                   configuration table.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_SET_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|ConfigurationCount
parameter_list|,
name|IN
name|EFI_BLOCK_IO_CRYPTO_CONFIGURATION_TABLE_ENTRY
modifier|*
name|ConfigurationTable
parameter_list|,
name|OUT
name|EFI_BLOCK_IO_CRYPTO_RESPONSE_CONFIGURATION_ENTRY
modifier|*
name|ResultingTable
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the configuration of the underlying inline cryptographic interface.    The GetConfiguration() function allows the user to get the configuration of the inline   cryptographic interface.    Retrieves, entirely or partially, the currently configured key table. Note that the keys   themselves are not retrieved, but rather just indices, owner GUIDs and capabilities.    If fewer entries than specified by ConfigurationCount are returned, the Index field of the   unused entries is set to EFI_BLOCK_IO_CRYPTO_INDEX_ANY.    @param[in]  This                Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in]  StartIndex          Configuration table index at which to start the configuration                                   query.   @param[in]  ConfigurationCount  Number of entries to return in the response table.   @param[in]  KeyOwnerGuid        Optional parameter to filter response down to entries with a                                   given owner. A pointer to the Nil value can be used to return                                   available entries. Set to NULL when no owner filtering is required.   @param[out] ConfigurationTable  Table of configured configuration table entries (with no CryptoKey                                   returned): configuration table index, KeyOwnerGuid, Capability.                                   Should have sufficient space to store up to ConfigurationCount                                   entries.    @retval EFI_SUCCESS             The ICI is ready for use.   @retval EFI_NO_RESPONSE         No response was received from the ICI.   @retval EFI_DEVICE_ERROR        An error occurred when attempting to access the ICI.   @retval EFI_INVALID_PARAMETER   This is NULL.   @retval EFI_INVALID_PARAMETER   Configuration table is NULL.   @retval EFI_INVALID_PARAMETER   StartIndex is out of bounds.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_GET_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|StartIndex
parameter_list|,
name|IN
name|UINT64
name|ConfigurationCount
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|KeyOwnerGuid
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_BLOCK_IO_CRYPTO_RESPONSE_CONFIGURATION_ENTRY
modifier|*
name|ConfigurationTable
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads the requested number of blocks from the device and optionally decrypts   them inline.    TheReadExtended() function allows the caller to perform a storage device read   operation. The function reads the requested number of blocks from the device   and then if Index is specified decrypts them inline. All the blocks are read   and decrypted (if decryption requested),  or an error is returned.    If there is no media in the device, the function returns EFI_NO_MEDIA. If the   MediaId is not the ID for the current media in the device, the function returns   EFI_MEDIA_CHANGED.    If EFI_DEVICE_ERROR, EFI_NO_MEDIA, or EFI_MEDIA_CHANGED is returned and nonblocking   I/O is being used, the Event associated with this request will not be signaled.    In addition to standard storage transaction parameters (LBA, IO size, and buffer),   this command will also specify a configuration table Index and CryptoIvInput   when data has  to be decrypted inline by the controller after being read from   the storage device. If an Index parameter is not specified, no decryption is   performed.    @param[in]      This          Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in]      MediaId       The media ID that the read request is for.   @param[in]      LBA           The starting logical block address to read from on                                 the device.   @param[in, out] Token         A pointer to the token associated with the transaction.   @param[in]      BufferSize    The size of the Buffer in bytes. This must be a multiple                                 of the intrinsic block size of the device.   @param[out]     Buffer        A pointer to the destination buffer for the data. The                                 caller is responsible for either having implicit or                                 explicit ownership of the buffer.   @param[in]      Index         A pointer to the configuration table index. This is                                 optional.   @param[in]      CryptoIvInput A pointer to a buffer that contains additional                                 cryptographic parameters as required by the capability                                 referenced by the configuration table index, such as                                 cryptographic initialization vector.    @retval EFI_SUCCESS           The read request was queued if Token-> Event is not NULL.                                 The data was read correctly from the device if the                                 Token->Event is NULL.   @retval EFI_DEVICE_ERROR      The device reported an error while attempting to perform                                 the read operation and/or decryption operation.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHANGED     The MediaId is not for the current media.   @retval EFI_BAD_BUFFER_SIZE   The BufferSize parameter is not a multiple of the intrinsic                                 block size of the device.   @retval EFI_INVALID_PARAMETER This is NULL, or the read request contains LBAs that are                                 not valid, or the buffer is not on proper alignment.   @retval EFI_INVALID_PARAMETER CryptoIvInput is incorrect.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of                                 resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_READ_EXTENDED
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|LBA
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO_CRYPTO_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINT64
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT64
modifier|*
name|Index
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|CryptoIvInput
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Optionally encrypts a specified number of blocks inline and then writes to the   device.    The WriteExtended() function allows the caller to perform a storage device write   operation. The function encrypts the requested number of blocks inline if Index   is specified  and then writes them to the device. All the blocks are encrypted   (if encryption requested) and  written, or an error is returned.    If there is no media in the device, the function returns EFI_NO_MEDIA. If the   MediaId is not the ID for the current media in the device, the function returns   EFI_MEDIA_CHANGED.    If EFI_DEVICE_ERROR, EFI_NO_MEDIA, or EFI_MEDIA_CHANGED is returned and nonblocking   I/O is being used, the Event associated with this request will not be signaled.    In addition to standard storage transaction parameters (LBA, IO size, and buffer),   this command will also specify a configuration table Index and a CryptoIvInput   when data has to be decrypted inline by the controller before being written to   the storage device. If no Index parameter is specified, no encryption is performed.    @param[in]      This          Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in]      MediaId       The media ID that the read request is for.   @param[in]      LBA           The starting logical block address to read from on                                 the device.   @param[in, out] Token         A pointer to the token associated with the transaction.   @param[in]      BufferSize    The size of the Buffer in bytes. This must be a multiple                                 of the intrinsic block size of the device.   @param[in]      Buffer        A pointer to the source buffer for the data.   @param[in]      Index         A pointer to the configuration table index. This is                                 optional.   @param[in]      CryptoIvInput A pointer to a buffer that contains additional                                 cryptographic parameters as required by the capability                                 referenced by the configuration table index, such as                                 cryptographic initialization vector.    @retval EFI_SUCCESS           The request to encrypt (optionally) and write was queued                                 if Event is not NULL. The data was encrypted (optionally)                                 and written correctly to the device if the Event is NULL.   @retval EFI_WRITE_PROTECTED   The device cannot be written to.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHANGED     The MediaId is not for the current media.   @retval EFI_DEVICE_ERROR      The device reported an error while attempting to encrypt                                 blocks or to perform the write operation.   @retval EFI_BAD_BUFFER_SIZE   The BufferSize parameter is not a multiple of the intrinsic                                 block size of the device.   @retval EFI_INVALID_PARAMETER This is NULL, or the write request contains LBAs that are                                 not valid, or the buffer is not on proper alignment.   @retval EFI_INVALID_PARAMETER CryptoIvInput is incorrect.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of                                 resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_WRITE_EXTENDED
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|LBA
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO_CRYPTO_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINT64
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINT64
modifier|*
name|Index
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|CryptoIvInput
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Flushes all modified data toa physical block device.    The FlushBlocks() function flushes all modified data to the physical block device.   Any modified data that has to be encrypted must have been already encrypted as a   part of WriteExtended() operation - inline crypto operation cannot be a part of   flush operation.    All data written to the device prior to the flush must be physically written before   returning EFI_SUCCESS from this function. This would include any cached data the   driver may have cached, and cached data the device may have cached. A flush may   cause a read request following the flush to force a device access.    If EFI_DEVICE_ERROR, EFI_NO_MEDIA, EFI_WRITE_PROTECTED or EFI_MEDIA_CHANGED is   returned and non-blocking I/O is being used, the Event associated with this request   will not be signaled.    @param[in]      This          Pointer to the EFI_BLOCK_IO_CRYPTO_PROTOCOL instance.   @param[in, out] Token         A pointer to the token associated with the transaction.    @retval EFI_SUCCESS           The flush request was queued if Event is not NULL. All                                 outstanding data was written correctly to the device if                                 the Event is NULL.   @retval EFI_DEVICE_ERROR      The device reported an error while attempting to write data.   @retval EFI_WRITE_PROTECTED   The device cannot be written to.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHANGED     The MediaId is not for the current media.   @retval EFI_INVALID_PARAMETER This is NULL.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of                                 resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_IO_CRYPTO_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_CRYPTO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO_CRYPTO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_BLOCK_IO_CRYPTO_PROTOCOL defines a UEFI protocol that can be used by UEFI
end_comment

begin_comment
comment|/// drivers and applications to perform block encryption on a storage device, such as UFS.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BLOCK_IO_CRYPTO_PROTOCOL
block|{
name|EFI_BLOCK_IO_MEDIA
modifier|*
name|Media
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_RESET
name|Reset
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_GET_CAPABILITIES
name|GetCapabilities
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_SET_CONFIGURATION
name|SetConfiguration
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_GET_CONFIGURATION
name|GetConfiguration
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_READ_EXTENDED
name|ReadExtended
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_WRITE_EXTENDED
name|WriteExtended
decl_stmt|;
name|EFI_BLOCK_IO_CRYPTO_FLUSH
name|FlushBlocks
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBlockIoCryptoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

