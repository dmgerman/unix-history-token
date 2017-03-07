begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This protocol is defined to abstract TPM2 hardware access in boot phase.  Copyright (c) 2013 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials  are licensed and made available under the terms and conditions of the BSD License  which accompanies this distribution.  The full text of the license may be found at  http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__TREE_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/UefiTcgPlatform.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Tpm20.h>
end_include

begin_define
define|#
directive|define
name|EFI_TREE_PROTOCOL_GUID
define|\
value|{0x607f766c, 0x7455, 0x42be, 0x93, 0x0b, 0xe4, 0xd7, 0x6d, 0xb2, 0x72, 0x0f}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TREE_PROTOCOL
name|EFI_TREE_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TREE_VERSION
block|{
name|UINT8
name|Major
decl_stmt|;
name|UINT8
name|Minor
decl_stmt|;
block|}
name|TREE_VERSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|TREE_EVENT_LOG_BITMAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|TREE_EVENT_LOG_FORMAT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TREE_EVENT_LOG_FORMAT_TCG_1_2
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|_TREE_BOOT_SERVICE_CAPABILITY
block|{
comment|//
comment|// Allocated size of the structure passed in
comment|//
name|UINT8
name|Size
decl_stmt|;
comment|//
comment|// Version of the TREE_BOOT_SERVICE_CAPABILITY structure itself.
comment|// For this version of the protocol, the Major version shall be set to 1
comment|// and the Minor version shall be set to 0.
comment|//
name|TREE_VERSION
name|StructureVersion
decl_stmt|;
comment|//
comment|// Version of the TrEE protocol.
comment|// For this version of the protocol, the Major version shall be set to 1
comment|// and the Minor version shall be set to 0.
comment|//
name|TREE_VERSION
name|ProtocolVersion
decl_stmt|;
comment|//
comment|// Supported hash algorithms
comment|//
name|UINT32
name|HashAlgorithmBitmap
decl_stmt|;
comment|//
comment|// Bitmap of supported event log formats
comment|//
name|TREE_EVENT_LOG_BITMAP
name|SupportedEventLogs
decl_stmt|;
comment|//
comment|// False = TrEE not present
comment|//
name|BOOLEAN
name|TrEEPresentFlag
decl_stmt|;
comment|//
comment|// Max size (in bytes) of a command that can be sent to the TrEE
comment|//
name|UINT16
name|MaxCommandSize
decl_stmt|;
comment|//
comment|// Max size (in bytes) of a response that can be provided by the TrEE
comment|//
name|UINT16
name|MaxResponseSize
decl_stmt|;
comment|//
comment|// 4-byte Vendor ID (see Trusted Computing Group, "TCG Vendor ID Registry,"
comment|// Version 1.0, Revision 0.1, August 31, 2007, "TPM Capabilities Vendor ID" section)
comment|//
name|UINT32
name|ManufacturerID
decl_stmt|;
block|}
name|TREE_BOOT_SERVICE_CAPABILITY_1_0
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TREE_BOOT_SERVICE_CAPABILITY_1_0
name|TREE_BOOT_SERVICE_CAPABILITY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TREE_BOOT_HASH_ALG_SHA1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TREE_BOOT_HASH_ALG_SHA256
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TREE_BOOT_HASH_ALG_SHA384
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TREE_BOOT_HASH_ALG_SHA512
value|0x00000008
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This bit is shall be set when an event shall be extended but not logged.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TREE_EXTEND_ONLY
value|0x0000000000000001
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This bit shall be set when the intent is to measure a PE/COFF image.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PE_COFF_IMAGE
value|0x0000000000000010
end_define

begin_typedef
typedef|typedef
name|UINT32
name|TrEE_PCRINDEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|TrEE_EVENTTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PCR_INDEX
value|23
end_define

begin_define
define|#
directive|define
name|TREE_EVENT_HEADER_VERSION
value|1
end_define

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
comment|//
comment|// Size of the event header itself (sizeof(TrEE_EVENT_HEADER)).
comment|//
name|UINT32
name|HeaderSize
decl_stmt|;
comment|//
comment|// Header version. For this version of this specification, the value shall be 1.
comment|//
name|UINT16
name|HeaderVersion
decl_stmt|;
comment|//
comment|// Index of the PCR that shall be extended (0 - 23).
comment|//
name|TrEE_PCRINDEX
name|PCRIndex
decl_stmt|;
comment|//
comment|// Type of the event that shall be extended (and optionally logged).
comment|//
name|TrEE_EVENTTYPE
name|EventType
decl_stmt|;
block|}
name|TrEE_EVENT_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Total size of the event including the Size component, the header and the Event data.
comment|//
name|UINT32
name|Size
decl_stmt|;
name|TrEE_EVENT_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Event
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TrEE_EVENT
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
comment|/**   The EFI_TREE_PROTOCOL GetCapability function call provides protocol   capability information and state information about the TrEE.    @param[in]  This               Indicates the calling context   @param[out] ProtocolCapability The caller allocates memory for a TREE_BOOT_SERVICE_CAPABILITY                                  structure and sets the size field to the size of the structure allocated.                                  The callee fills in the fields with the EFI protocol capability information                                  and the current TrEE state information up to the number of fields which                                  fit within the size of the structure passed in.    @retval EFI_SUCCESS            Operation completed successfully.   @retval EFI_DEVICE_ERROR       The command was unsuccessful.                                  The ProtocolCapability variable will not be populated.    @retval EFI_INVALID_PARAMETER  One or more of the parameters are incorrect.                                  The ProtocolCapability variable will not be populated.   @retval EFI_BUFFER_TOO_SMALL   The ProtocolCapability variable is too small to hold the full response.                                  It will be partially populated (required Size field will be set).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TREE_GET_CAPABILITY
function_decl|)
parameter_list|(
name|IN
name|EFI_TREE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|TREE_BOOT_SERVICE_CAPABILITY
modifier|*
name|ProtocolCapability
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The EFI_TREE_PROTOCOL Get Event Log function call allows a caller to   retrieve the address of a given event log and its last entry.     @param[in]  This               Indicates the calling context   @param[in]  EventLogFormat     The type of the event log for which the information is requested.   @param[out] EventLogLocation   A pointer to the memory address of the event log.   @param[out] EventLogLastEntry  If the Event Log contains more than one entry, this is a pointer to the                                  address of the start of the last entry in the event log in memory.   @param[out] EventLogTruncated  If the Event Log is missing at least one entry because an event would                                  have exceeded the area allocated for events, this value is set to TRUE.                                  Otherwise, the value will be FALSE and the Event Log will be complete.    @retval EFI_SUCCESS            Operation completed successfully.   @retval EFI_INVALID_PARAMETER  One or more of the parameters are incorrect                                  (e.g. asking for an event log whose format is not supported). **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TREE_GET_EVENT_LOG
function_decl|)
parameter_list|(
name|IN
name|EFI_TREE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|TREE_EVENT_LOG_FORMAT
name|EventLogFormat
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
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|EventLogTruncated
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The EFI_TREE_PROTOCOL HashLogExtendEvent function call provides callers with   an opportunity to extend and optionally log events without requiring   knowledge of actual TPM commands.    The extend operation will occur even if this function cannot create an event   log entry (e.g. due to the event log being full).     @param[in]  This               Indicates the calling context   @param[in]  Flags              Bitmap providing additional information.   @param[in]  DataToHash         Physical address of the start of the data buffer to be hashed.    @param[in]  DataToHashLen      The length in bytes of the buffer referenced by DataToHash.   @param[in]  Event              Pointer to data buffer containing information about the event.    @retval EFI_SUCCESS            Operation completed successfully.   @retval EFI_DEVICE_ERROR       The command was unsuccessful.   @retval EFI_VOLUME_FULL        The extend operation occurred, but the event could not be written to one or more event logs.   @retval EFI_INVALID_PARAMETER  One or more of the parameters are incorrect.   @retval EFI_UNSUPPORTED        The PE/COFF image type is not supported. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TREE_HASH_LOG_EXTEND_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_TREE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Flags
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|DataToHash
parameter_list|,
name|IN
name|UINT64
name|DataToHashLen
parameter_list|,
name|IN
name|TrEE_EVENT
modifier|*
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This service enables the sending of commands to the TrEE.    @param[in]  This                     Indicates the calling context   @param[in]  InputParameterBlockSize  Size of the TrEE input parameter block.   @param[in]  InputParameterBlock      Pointer to the TrEE input parameter block.   @param[in]  OutputParameterBlockSize Size of the TrEE output parameter block.   @param[in]  OutputParameterBlock     Pointer to the TrEE output parameter block.    @retval EFI_SUCCESS            The command byte stream was successfully sent to the device and a response was successfully received.   @retval EFI_DEVICE_ERROR       The command was not successfully sent to the device or a response was not successfully received from the device.   @retval EFI_INVALID_PARAMETER  One or more of the parameters are incorrect.   @retval EFI_BUFFER_TOO_SMALL   The output parameter block is too small.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TREE_SUBMIT_COMMAND
function_decl|)
parameter_list|(
name|IN
name|EFI_TREE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|InputParameterBlockSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|InputParameterBlock
parameter_list|,
name|IN
name|UINT32
name|OutputParameterBlockSize
parameter_list|,
name|IN
name|UINT8
modifier|*
name|OutputParameterBlock
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_TREE_PROTOCOL
block|{
name|EFI_TREE_GET_CAPABILITY
name|GetCapability
decl_stmt|;
name|EFI_TREE_GET_EVENT_LOG
name|GetEventLog
decl_stmt|;
name|EFI_TREE_HASH_LOG_EXTEND_EVENT
name|HashLogExtendEvent
decl_stmt|;
name|EFI_TREE_SUBMIT_COMMAND
name|SubmitCommand
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTrEEProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

