begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Multicast Trivial File Transfer Protocol Definition  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.0  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_MTFTP4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_MTFTP4_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x2FE800BE, 0x8F01, 0x4aa6, {0x94, 0x6B, 0xD7, 0x13, 0x88, 0xE1, 0x83, 0x3F } \   }
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_PROTOCOL_GUID
define|\
value|{ \     0x78247c57, 0x63db, 0x4708, {0x99, 0xc2, 0xa8, 0xb4, 0xa9, 0xa6, 0x1f, 0x6b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_MTFTP4_PROTOCOL
name|EFI_MTFTP4_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_MTFTP4_TOKEN
name|EFI_MTFTP4_TOKEN
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//MTFTP4 packet opcode definition
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_RRQ
value|1
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_WRQ
value|2
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_DATA
value|3
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_ACK
value|4
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_OACK
value|6
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_DIR
value|7
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_DATA8
value|8
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_OPCODE_ACK8
value|9
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// MTFTP4 error code definition
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_NOT_DEFINED
value|0
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_FILE_NOT_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_ACCESS_VIOLATION
value|2
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_DISK_FULL
value|3
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_ILLEGAL_OPERATION
value|4
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_UNKNOWN_TRANSFER_ID
value|5
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_FILE_ALREADY_EXISTS
value|6
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_NO_SUCH_USER
value|7
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP4_ERRORCODE_REQUEST_DENIED
value|8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// MTFTP4 pacekt definitions
end_comment

begin_comment
comment|//
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
name|UINT16
name|OpCode
decl_stmt|;
name|UINT8
name|Filename
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_REQ_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_OACK_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT16
name|Block
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_DATA_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT16
name|Block
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_ACK_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT64
name|Block
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_DATA8_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT64
name|Block
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_ACK8_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|OpCode
decl_stmt|;
name|UINT16
name|ErrorCode
decl_stmt|;
name|UINT8
name|ErrorMessage
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP4_ERROR_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// Type of packets as defined by the MTFTPv4 packet opcodes.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// Read request packet header.
comment|///
name|EFI_MTFTP4_REQ_HEADER
name|Rrq
decl_stmt|;
comment|///
comment|/// Write request packet header.
comment|///
name|EFI_MTFTP4_REQ_HEADER
name|Wrq
decl_stmt|;
comment|///
comment|/// Option acknowledge packet header.
comment|///
name|EFI_MTFTP4_OACK_HEADER
name|Oack
decl_stmt|;
comment|///
comment|/// Data packet header.
comment|///
name|EFI_MTFTP4_DATA_HEADER
name|Data
decl_stmt|;
comment|///
comment|/// Acknowledgement packet header.
comment|///
name|EFI_MTFTP4_ACK_HEADER
name|Ack
decl_stmt|;
comment|///
comment|/// Data packet header with big block number.
comment|///
name|EFI_MTFTP4_DATA8_HEADER
name|Data8
decl_stmt|;
comment|///
comment|/// Acknowledgement header with big block num.
comment|///
name|EFI_MTFTP4_ACK8_HEADER
name|Ack8
decl_stmt|;
comment|///
comment|/// Error packet header.
comment|///
name|EFI_MTFTP4_ERROR_HEADER
name|Error
decl_stmt|;
block|}
name|EFI_MTFTP4_PACKET
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
comment|/// MTFTP4 option definition.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
modifier|*
name|OptionStr
decl_stmt|;
name|UINT8
modifier|*
name|ValueStr
decl_stmt|;
block|}
name|EFI_MTFTP4_OPTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|UseDefaultSetting
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|StationIp
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
name|UINT16
name|LocalPort
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|GatewayIp
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|ServerIp
decl_stmt|;
name|UINT16
name|InitialServerPort
decl_stmt|;
name|UINT16
name|TryCount
decl_stmt|;
name|UINT16
name|TimeoutValue
decl_stmt|;
block|}
name|EFI_MTFTP4_CONFIG_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_MTFTP4_CONFIG_DATA
name|ConfigData
decl_stmt|;
name|UINT8
name|SupportedOptionCount
decl_stmt|;
name|UINT8
modifier|*
modifier|*
name|SupportedOptoins
decl_stmt|;
name|UINT8
name|UnsupportedOptionCount
decl_stmt|;
name|UINT8
modifier|*
modifier|*
name|UnsupportedOptoins
decl_stmt|;
block|}
name|EFI_MTFTP4_MODE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_IPv4_ADDRESS
name|GatewayIp
decl_stmt|;
name|EFI_IPv4_ADDRESS
name|ServerIp
decl_stmt|;
name|UINT16
name|ServerPort
decl_stmt|;
name|UINT16
name|TryCount
decl_stmt|;
name|UINT16
name|TimeoutValue
decl_stmt|;
block|}
name|EFI_MTFTP4_OVERRIDE_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol interfaces definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   A callback function that is provided by the caller to intercept   the EFI_MTFTP4_OPCODE_DATA or EFI_MTFTP4_OPCODE_DATA8 packets processed in the   EFI_MTFTP4_PROTOCOL.ReadFile() function, and alternatively to intercept   EFI_MTFTP4_OPCODE_OACK or EFI_MTFTP4_OPCODE_ERROR packets during a call to   EFI_MTFTP4_PROTOCOL.ReadFile(), WriteFile() or ReadDirectory().    @param  This        The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token       The token that the caller provided in the                       EFI_MTFTP4_PROTOCOL.ReadFile(), WriteFile()                       or ReadDirectory() function.   @param  PacketLen   Indicates the length of the packet.   @param  Packet      The pointer to an MTFTPv4 packet.    @retval EFI_SUCCESS The operation was successful.   @retval Others      Aborts the transfer process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_CHECK_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINT16
name|PacketLen
parameter_list|,
name|IN
name|EFI_MTFTP4_PACKET
modifier|*
name|Paket
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Timeout callback function.    @param  This           The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token          The token that is provided in the                          EFI_MTFTP4_PROTOCOL.ReadFile() or                          EFI_MTFTP4_PROTOCOL.WriteFile() or                          EFI_MTFTP4_PROTOCOL.ReadDirectory() functions                          by the caller.    @retval EFI_SUCCESS   The operation was successful.   @retval Others        Aborts download process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_TIMEOUT_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   A callback function that the caller provides to feed data to the   EFI_MTFTP4_PROTOCOL.WriteFile() function.    @param  This   The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token  The token provided in the                  EFI_MTFTP4_PROTOCOL.WriteFile() by the caller.   @param  Length Indicates the length of the raw data wanted on input, and the                  length the data available on output.   @param  Buffer The pointer to the buffer where the data is stored.    @retval EFI_SUCCESS The operation was successful.   @retval Others      Aborts session.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_PACKET_NEEDED
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|OUT
name|UINT16
modifier|*
name|Length
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Submits an asynchronous interrupt transfer to an interrupt endpoint of a USB device.    @param  This     The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  ModeData The pointer to storage for the EFI MTFTPv4 Protocol driver mode data.    @retval EFI_SUCCESS           The configuration data was successfully returned.   @retval EFI_OUT_OF_RESOURCES  The required mode data could not be allocated.   @retval EFI_INVALID_PARAMETER This is NULL or ModeData is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_MTFTP4_MODE_DATA
modifier|*
name|ModeData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initializes, changes, or resets the default operational setting for this   EFI MTFTPv4 Protocol driver instance.    @param  This            The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  MtftpConfigData The pointer to the configuration data structure.    @retval EFI_SUCCESS           The EFI MTFTPv4 Protocol driver was configured successfully.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_ACCESS_DENIED     The EFI configuration could not be changed at this time because                                 there is one MTFTP background operation in progress.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) has not finished yet.   @retval EFI_UNSUPPORTED       A configuration protocol (DHCP, BOOTP, RARP, etc.) could not                                 be located when clients choose to use the default address                                 settings.   @retval EFI_OUT_OF_RESOURCES  The EFI MTFTPv4 Protocol driver instance data could not be                                 allocated.   @retval EFI_DEVICE_ERROR      An unexpected system or network error occurred. The EFI                                  MTFTPv4 Protocol driver instance is not configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_CONFIG_DATA
modifier|*
name|MtftpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets information about a file from an MTFTPv4 server.    @param  This         The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  OverrideData Data that is used to override the existing parameters. If NULL,                        the default parameters that were set in the                        EFI_MTFTP4_PROTOCOL.Configure() function are used.   @param  Filename     The pointer to null-terminated ASCII file name string.   @param  ModeStr      The pointer to null-terminated ASCII mode string. If NULL, "octet" will be used.   @param  OptionCount  Number of option/value string pairs in OptionList.   @param  OptionList   The pointer to array of option/value string pairs. Ignored if                        OptionCount is zero.   @param  PacketLength The number of bytes in the returned packet.   @param  Packet       The pointer to the received packet. This buffer must be freed by                        the caller.    @retval EFI_SUCCESS              An MTFTPv4 OACK packet was received and is in the Packet.   @retval EFI_INVALID_PARAMETER    One or more of the following conditions is TRUE:                                    - This is NULL.                                    - Filename is NULL.                                    - OptionCount is not zero and OptionList is NULL.                                    - One or more options in OptionList have wrong format.                                    - PacketLength is NULL.                                    - One or more IPv4 addresses in OverrideData are not valid                                      unicast IPv4 addresses if OverrideData is not NULL.   @retval EFI_UNSUPPORTED          One or more options in the OptionList are in the                                    unsupported list of structure EFI_MTFTP4_MODE_DATA.   @retval EFI_NOT_STARTED          The EFI MTFTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING           When using a default address, configuration (DHCP, BOOTP,                                    RARP, etc.) has not finished yet.   @retval EFI_ACCESS_DENIED        The previous operation has not completed yet.   @retval EFI_OUT_OF_RESOURCES     Required system resources could not be allocated.   @retval EFI_TFTP_ERROR           An MTFTPv4 ERROR packet was received and is in the Packet.   @retval EFI_NETWORK_UNREACHABLE  An ICMP network unreachable error packet was received and the Packet is set to NULL.   @retval EFI_HOST_UNREACHABLE     An ICMP host unreachable error packet was received and the Packet is set to NULL.   @retval EFI_PROTOCOL_UNREACHABLE An ICMP protocol unreachable error packet was received and the Packet is set to NULL.   @retval EFI_PORT_UNREACHABLE     An ICMP port unreachable error packet was received and the Packet is set to NULL.   @retval EFI_ICMP_ERROR           Some other ICMP ERROR packet was received and is in the Buffer.   @retval EFI_PROTOCOL_ERROR       An unexpected MTFTPv4 packet was received and is in the Packet.   @retval EFI_TIMEOUT              No responses were received from the MTFTPv4 server.   @retval EFI_DEVICE_ERROR         An unexpected network error or system error occurred.   @retval EFI_NO_MEDIA             There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_OVERRIDE_DATA
modifier|*
name|OverrideData
name|OPTIONAL
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Filename
parameter_list|,
name|IN
name|UINT8
modifier|*
name|ModeStr
name|OPTIONAL
parameter_list|,
name|IN
name|UINT8
name|OptionCount
parameter_list|,
name|IN
name|EFI_MTFTP4_OPTION
modifier|*
name|OptionList
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|PacketLength
parameter_list|,
name|OUT
name|EFI_MTFTP4_PACKET
modifier|*
modifier|*
name|Packet
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Parses the options in an MTFTPv4 OACK packet.    @param  This         The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  PacketLen    Length of the OACK packet to be parsed.   @param  Packet       The pointer to the OACK packet to be parsed.   @param  OptionCount  The pointer to the number of options in following OptionList.   @param  OptionList   The pointer to EFI_MTFTP4_OPTION storage. Call the EFI Boot                        Service FreePool() to release the OptionList if the options                        in this OptionList are not needed any more.    @retval EFI_SUCCESS           The OACK packet was valid and the OptionCount and                                 OptionList parameters have been updated.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - PacketLen is 0.                                 - Packet is NULL or Packet is not a valid MTFTPv4 packet.                                 - OptionCount is NULL.   @retval EFI_NOT_FOUND         No options were found in the OACK packet.   @retval EFI_OUT_OF_RESOURCES  Storage for the OptionList array cannot be allocated.   @retval EFI_PROTOCOL_ERROR    One or more of the option fields is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_PARSE_OPTIONS
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|PacketLen
parameter_list|,
name|IN
name|EFI_MTFTP4_PACKET
modifier|*
name|Packet
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|OptionCount
parameter_list|,
name|OUT
name|EFI_MTFTP4_OPTION
modifier|*
modifier|*
name|OptionList
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Downloads a file from an MTFTPv4 server.    @param  This  The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token The pointer to the token structure to provide the parameters that are                 used in this operation.    @retval EFI_SUCCESS              The data file has been transferred successfully.   @retval EFI_OUT_OF_RESOURCES     Required system resources could not be allocated.   @retval EFI_BUFFER_TOO_SMALL     BufferSize is not zero but not large enough to hold the                                    downloaded data in downloading process.   @retval EFI_ABORTED              Current operation is aborted by user.   @retval EFI_NETWORK_UNREACHABLE  An ICMP network unreachable error packet was received.   @retval EFI_HOST_UNREACHABLE     An ICMP host unreachable error packet was received.   @retval EFI_PROTOCOL_UNREACHABLE An ICMP protocol unreachable error packet was received.   @retval EFI_PORT_UNREACHABLE     An ICMP port unreachable error packet was received.   @retval EFI_ICMP_ERROR           Some other  ICMP ERROR packet was received.   @retval EFI_TIMEOUT              No responses were received from the MTFTPv4 server.   @retval EFI_TFTP_ERROR           An MTFTPv4 ERROR packet was received.   @retval EFI_DEVICE_ERROR         An unexpected network error or system error occurred.   @retval EFI_NO_MEDIA             There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_READ_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sends a file to an MTFTPv4 server.    @param  This  The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token The pointer to the token structure to provide the parameters that are                 used in this operation.    @retval EFI_SUCCESS           The upload session has started.   @retval EFI_UNSUPPORTED       The operation is not supported by this implementation.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_UNSUPPORTED       One or more options in the Token.OptionList are in                                 the unsupported list of structure EFI_MTFTP4_MODE_DATA.   @retval EFI_NOT_STARTED       The EFI MTFTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_ALREADY_STARTED   This Token is already being used in another MTFTPv4 session.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_ACCESS_DENIED     The previous operation has not completed yet.   @retval EFI_DEVICE_ERROR      An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_WRITE_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Downloads a data file "directory" from an MTFTPv4 server. May be unsupported in some EFI   implementations.    @param  This  The pointer to the EFI_MTFTP4_PROTOCOL instance.   @param  Token The pointer to the token structure to provide the parameters that are                 used in this operation.    @retval EFI_SUCCESS           The MTFTPv4 related file "directory" has been downloaded.   @retval EFI_UNSUPPORTED       The operation is not supported by this implementation.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_UNSUPPORTED       One or more options in the Token.OptionList are in                                 the unsupported list of structure EFI_MTFTP4_MODE_DATA.   @retval EFI_NOT_STARTED       The EFI MTFTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                 RARP, etc.) is not finished yet.   @retval EFI_ALREADY_STARTED   This Token is already being used in another MTFTPv4 session.   @retval EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval EFI_ACCESS_DENIED     The previous operation has not completed yet.   @retval EFI_DEVICE_ERROR      An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_READ_DIRECTORY
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP4_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    @param  This The pointer to the EFI_MTFTP4_PROTOCOL instance.    @retval  EFI_SUCCESS           Incoming or outgoing data was processed.   @retval  EFI_NOT_STARTED       This EFI MTFTPv4 Protocol instance has not been started.   @retval  EFI_NO_MAPPING        When using a default address, configuration (DHCP, BOOTP,                                  RARP, etc.) is not finished yet.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval  EFI_TIMEOUT           Data was dropped out of the transmit and/or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP4_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_MTFTP4_PROTOCOL is designed to be used by UEFI drivers and applications
end_comment

begin_comment
comment|/// to transmit and receive data files. The EFI MTFTPv4 Protocol driver uses
end_comment

begin_comment
comment|/// the underlying EFI UDPv4 Protocol driver and EFI IPv4 Protocol driver.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_MTFTP4_PROTOCOL
block|{
name|EFI_MTFTP4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_MTFTP4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_MTFTP4_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_MTFTP4_PARSE_OPTIONS
name|ParseOptions
decl_stmt|;
name|EFI_MTFTP4_READ_FILE
name|ReadFile
decl_stmt|;
name|EFI_MTFTP4_WRITE_FILE
name|WriteFile
decl_stmt|;
name|EFI_MTFTP4_READ_DIRECTORY
name|ReadDirectory
decl_stmt|;
name|EFI_MTFTP4_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_EFI_MTFTP4_TOKEN
block|{
comment|///
comment|/// The status that is returned to the caller at the end of the operation
comment|/// to indicate whether this operation completed successfully.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// The event that will be signaled when the operation completes. If
comment|/// set to NULL, the corresponding function will wait until the read or
comment|/// write operation finishes. The type of Event must be
comment|/// EVT_NOTIFY_SIGNAL. The Task Priority Level (TPL) of
comment|/// Event must be lower than or equal to TPL_CALLBACK.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// If not NULL, the data that will be used to override the existing configure data.
comment|///
name|EFI_MTFTP4_OVERRIDE_DATA
modifier|*
name|OverrideData
decl_stmt|;
comment|///
comment|/// The pointer to the null-terminated ASCII file name string.
comment|///
name|UINT8
modifier|*
name|Filename
decl_stmt|;
comment|///
comment|/// The pointer to the null-terminated ASCII mode string. If NULL, "octet" is used.
comment|///
name|UINT8
modifier|*
name|ModeStr
decl_stmt|;
comment|///
comment|/// Number of option/value string pairs.
comment|///
name|UINT32
name|OptionCount
decl_stmt|;
comment|///
comment|/// The pointer to an array of option/value string pairs. Ignored if OptionCount is zero.
comment|///
name|EFI_MTFTP4_OPTION
modifier|*
name|OptionList
decl_stmt|;
comment|///
comment|/// The size of the data buffer.
comment|///
name|UINT64
name|BufferSize
decl_stmt|;
comment|///
comment|/// The pointer to the data buffer. Data that is downloaded from the
comment|/// MTFTPv4 server is stored here. Data that is uploaded to the
comment|/// MTFTPv4 server is read from here. Ignored if BufferSize is zero.
comment|///
name|VOID
modifier|*
name|Buffer
decl_stmt|;
comment|///
comment|/// The pointer to the context that will be used by CheckPacket,
comment|/// TimeoutCallback and PacketNeeded.
comment|///
name|VOID
modifier|*
name|Context
decl_stmt|;
comment|///
comment|/// The pointer to the callback function to check the contents of the received packet.
comment|///
name|EFI_MTFTP4_CHECK_PACKET
name|CheckPacket
decl_stmt|;
comment|///
comment|/// The pointer to the function to be called when a timeout occurs.
comment|///
name|EFI_MTFTP4_TIMEOUT_CALLBACK
name|TimeoutCallback
decl_stmt|;
comment|///
comment|/// The pointer to the function to provide the needed packet contents.
comment|///
name|EFI_MTFTP4_PACKET_NEEDED
name|PacketNeeded
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMtftp4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMtftp4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

