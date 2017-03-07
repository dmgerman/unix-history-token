begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TCG Service Protocol as defined in TCG_EFI_Protocol_1_22_Final   See http://trustedcomputinggroup.org for the latest specification  Copyright (c) 2007 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TCG_SERVICE_PROTOCOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_TCG_SERVICE_PROTOCOL_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/UefiTcgPlatform.h>
end_include

begin_define
define|#
directive|define
name|EFI_TCG_PROTOCOL_GUID
define|\
value|{0xf541796d, 0xa62e, 0x4954, { 0xa7, 0x75, 0x95, 0x84, 0xf6, 0x1b, 0x9c, 0xdd } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TCG_PROTOCOL
name|EFI_TCG_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Major
decl_stmt|;
name|UINT8
name|Minor
decl_stmt|;
name|UINT8
name|RevMajor
decl_stmt|;
name|UINT8
name|RevMinor
decl_stmt|;
block|}
name|TCG_VERSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TCG_EFI_BOOT_SERVICE_CAPABILITY
block|{
name|UINT8
name|Size
decl_stmt|;
comment|/// Size of this structure.
name|TCG_VERSION
name|StructureVersion
decl_stmt|;
name|TCG_VERSION
name|ProtocolSpecVersion
decl_stmt|;
name|UINT8
name|HashAlgorithmBitmap
decl_stmt|;
comment|/// Hash algorithms .
comment|/// This protocol is capable of : 01=SHA-1.
name|BOOLEAN
name|TPMPresentFlag
decl_stmt|;
comment|/// 00h = TPM not present.
name|BOOLEAN
name|TPMDeactivatedFlag
decl_stmt|;
comment|/// 01h = TPM currently deactivated.
block|}
name|TCG_EFI_BOOT_SERVICE_CAPABILITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|TCG_ALGORITHM_ID
typedef|;
end_typedef

begin_comment
comment|/**   This service provides EFI protocol capability information, state information    about the TPM, and Event Log state information.    @param  This                   Indicates the calling context   @param  ProtocolCapability     The callee allocates memory for a TCG_BOOT_SERVICE_CAPABILITY                                   structure and fills in the fields with the EFI protocol                                   capability information and the current TPM state information.   @param  TCGFeatureFlags        This is a pointer to the feature flags. No feature                                   flags are currently defined so this parameter                                   MUST be set to 0. However, in the future,                                   feature flags may be defined that, for example,                                   enable hash algorithm agility.   @param  EventLogLocation       This is a pointer to the address of the event log in memory.   @param  EventLogLastEntry      If the Event Log contains more than one entry,                                   this is a pointer to the address of the start of                                   the last entry in the event log in memory.     @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_INVALID_PARAMETER  ProtocolCapability does not match TCG capability. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCG_STATUS_CHECK
function_decl|)
parameter_list|(
name|IN
name|EFI_TCG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|TCG_EFI_BOOT_SERVICE_CAPABILITY
modifier|*
name|ProtocolCapability
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TCGFeatureFlags
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|EventLogLocation
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|EventLogLastEntry
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service abstracts the capability to do a hash operation on a data buffer.      @param  This                   Indicates the calling context.   @param  HashData               The pointer to the data buffer to be hashed.   @param  HashDataLen            The length of the data buffer to be hashed.   @param  AlgorithmId            Identification of the Algorithm to use for the hashing operation.   @param  HashedDataLen          Resultant length of the hashed data.   @param  HashedDataResult       Resultant buffer of the hashed data.      @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_INVALID_PARAMETER  HashDataLen is NULL.   @retval EFI_INVALID_PARAMETER  HashDataLenResult is NULL.   @retval EFI_OUT_OF_RESOURCES   Cannot allocate buffer of size *HashedDataLen.   @retval EFI_UNSUPPORTED        AlgorithmId not supported.   @retval EFI_BUFFER_TOO_SMALL   *HashedDataLen< sizeof (TCG_DIGEST). **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCG_HASH_ALL
function_decl|)
parameter_list|(
name|IN
name|EFI_TCG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
modifier|*
name|HashData
parameter_list|,
name|IN
name|UINT64
name|HashDataLen
parameter_list|,
name|IN
name|TCG_ALGORITHM_ID
name|AlgorithmId
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|HashedDataLen
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
modifier|*
name|HashedDataResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service abstracts the capability to add an entry to the Event Log.    @param  This                   Indicates the calling context   @param  TCGLogData             The pointer to the start of the data buffer containing                                   the TCG_PCR_EVENT data structure. All fields in                                   this structure are properly filled by the caller.   @param  EventNumber            The event number of the event just logged.   @param  Flags                  Indicates additional flags. Only one flag has been                                   defined at this time, which is 0x01 and means the                                   extend operation should not be performed. All                                   other bits are reserved.      @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_OUT_OF_RESOURCES   Insufficient memory in the event log to complete this action. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCG_LOG_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|TCG_PCR_EVENT
modifier|*
name|TCGLogData
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|EventNumber
parameter_list|,
name|IN
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service is a proxy for commands to the TPM.    @param  This                        Indicates the calling context.   @param  TpmInputParameterBlockSize  Size of the TPM input parameter block.   @param  TpmInputParameterBlock      The pointer to the TPM input parameter block.   @param  TpmOutputParameterBlockSize Size of the TPM output parameter block.   @param  TpmOutputParameterBlock     The pointer to the TPM output parameter block.    @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_INVALID_PARAMETER  Invalid ordinal.   @retval EFI_UNSUPPORTED        Current Task Priority Level>= EFI_TPL_CALLBACK.   @retval EFI_TIMEOUT            The TIS timed-out. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCG_PASS_THROUGH_TO_TPM
function_decl|)
parameter_list|(
name|IN
name|EFI_TCG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|TpmInputParameterBlockSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|TpmInputParameterBlock
parameter_list|,
name|IN
name|UINT32
name|TpmOutputParameterBlockSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|TpmOutputParameterBlock
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service abstracts the capability to do a hash operation on a data buffer, extend a specific TPM PCR with the hash result, and add an entry to the Event Log    @param  This                   Indicates the calling context   @param  HashData               The physical address of the start of the data buffer                                   to be hashed, extended, and logged.   @param  HashDataLen            The length, in bytes, of the buffer referenced by HashData   @param  AlgorithmId            Identification of the Algorithm to use for the hashing operation   @param  TCGLogData             The physical address of the start of the data                                   buffer containing the TCG_PCR_EVENT data structure.   @param  EventNumber            The event number of the event just logged.   @param  EventLogLastEntry      The physical address of the first byte of the entry                                   just placed in the Event Log. If the Event Log was                                   empty when this function was called then this physical                                   address will be the same as the physical address of                                   the start of the Event Log.    @retval EFI_SUCCESS            The operation completed successfully.   @retval EFI_UNSUPPORTED        AlgorithmId != TPM_ALG_SHA.   @retval EFI_UNSUPPORTED        Current TPL>= EFI_TPL_CALLBACK.   @retval EFI_DEVICE_ERROR       The command was unsuccessful. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TCG_HASH_LOG_EXTEND_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_TCG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|HashData
parameter_list|,
name|IN
name|UINT64
name|HashDataLen
parameter_list|,
name|IN
name|TCG_ALGORITHM_ID
name|AlgorithmId
parameter_list|,
name|IN
name|OUT
name|TCG_PCR_EVENT
modifier|*
name|TCGLogData
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|EventNumber
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|EventLogLastEntry
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_TCG Protocol abstracts TCG activity.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TCG_PROTOCOL
block|{
name|EFI_TCG_STATUS_CHECK
name|StatusCheck
decl_stmt|;
name|EFI_TCG_HASH_ALL
name|HashAll
decl_stmt|;
name|EFI_TCG_LOG_EVENT
name|LogEvent
decl_stmt|;
name|EFI_TCG_PASS_THROUGH_TO_TPM
name|PassThroughToTpm
decl_stmt|;
name|EFI_TCG_HASH_LOG_EXTEND_EVENT
name|HashLogExtendEvent
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTcgProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

