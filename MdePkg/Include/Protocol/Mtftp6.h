begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Multicast Trivial File Transfer Protocol v6 Definition, which is built upon   the EFI UDPv6 Protocol and provides basic services for client-side unicast and/or   multicast TFTP operations.    Copyright (c) 2008 - 2011, Intel Corporation. All rights reserved.<BR>   (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_MTFTP6_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_MTFTP6_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP6_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xd9760ff3, 0x3cca, 0x4267, {0x80, 0xf9, 0x75, 0x27, 0xfa, 0xfa, 0x42, 0x23 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_MTFTP6_PROTOCOL_GUID
define|\
value|{ \     0xbf0a78ba, 0xec29, 0x49cf, {0xa1, 0xc9, 0x7a, 0xe5, 0x4e, 0xab, 0x6a, 0x51 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_MTFTP6_PROTOCOL
name|EFI_MTFTP6_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_MTFTP6_TOKEN
name|EFI_MTFTP6_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MTFTP Packet OpCodes
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_RRQ
value|1
end_define

begin_comment
comment|///< The MTFTPv6 packet is a read request.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_WRQ
value|2
end_define

begin_comment
comment|///< The MTFTPv6 packet is a write request.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_DATA
value|3
end_define

begin_comment
comment|///< The MTFTPv6 packet is a data packet.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_ACK
value|4
end_define

begin_comment
comment|///< The MTFTPv6 packet is an acknowledgement packet.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_ERROR
value|5
end_define

begin_comment
comment|///< The MTFTPv6 packet is an error packet.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_OACK
value|6
end_define

begin_comment
comment|///< The MTFTPv6 packet is an option acknowledgement packet.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_DIR
value|7
end_define

begin_comment
comment|///< The MTFTPv6 packet is a directory query packet.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_DATA8
value|8
end_define

begin_comment
comment|///< The MTFTPv6 packet is a data packet with a big block number.
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_OPCODE_ACK8
value|9
end_define

begin_comment
comment|///< The MTFTPv6 packet is an acknowledgement packet with a big block number.
end_comment

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// MTFTP ERROR Packet ErrorCodes
end_comment

begin_comment
comment|///@{
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The error code is not defined. See the error message in the packet (if any) for details.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_NOT_DEFINED
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The file was not found.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_FILE_NOT_FOUND
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// There was an access violation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_ACCESS_VIOLATION
value|2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The disk was full or its allocation was exceeded.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_DISK_FULL
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The MTFTPv6 operation was illegal.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_ILLEGAL_OPERATION
value|4
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The transfer ID is unknown.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_UNKNOWN_TRANSFER_ID
value|5
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The file already exists.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_FILE_ALREADY_EXISTS
value|6
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is no such user.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_NO_SUCH_USER
value|7
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The request has been denied due to option negotiation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MTFTP6_ERRORCODE_REQUEST_DENIED
value|8
end_define

begin_comment
comment|///@}
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_REQ_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_RRQ for a read request
comment|/// or OpCode = EFI_MTFTP6_OPCODE_WRQ for a write request.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The file name to be downloaded or uploaded.
comment|///
name|UINT8
name|Filename
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_REQ_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_OACK_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_OACK.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The option strings in the option acknowledgement packet.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_OACK_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_DATA_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_DATA.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// Block number of this data packet.
comment|///
name|UINT16
name|Block
decl_stmt|;
comment|///
comment|/// The content of this data packet.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_DATA_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_ACK_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_ACK.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The block number of the data packet that is being acknowledged.
comment|///
name|UINT16
name|Block
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_ACK_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_DATA8_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_DATA8.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The block number of data packet.
comment|///
name|UINT64
name|Block
decl_stmt|;
comment|///
comment|/// The content of this data packet.
comment|///
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_DATA8_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_ACK8_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_ACK8.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The block number of the data packet that is being acknowledged.
comment|///
name|UINT64
name|Block
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_ACK8_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_ERROR_HEADER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// For this packet type, OpCode = EFI_MTFTP6_OPCODE_ERROR.
comment|///
name|UINT16
name|OpCode
decl_stmt|;
comment|///
comment|/// The error number as defined by the MTFTPv6 packet error codes.
comment|///
name|UINT16
name|ErrorCode
decl_stmt|;
comment|///
comment|/// Error message string.
comment|///
name|UINT8
name|ErrorMessage
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_MTFTP6_ERROR_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_PACKET
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|UINT16
name|OpCode
decl_stmt|;
comment|///< Type of packets as defined by the MTFTPv6 packet opcodes.
name|EFI_MTFTP6_REQ_HEADER
name|Rrq
decl_stmt|;
comment|///< Read request packet header.
name|EFI_MTFTP6_REQ_HEADER
name|Wrq
decl_stmt|;
comment|///< write request packet header.
name|EFI_MTFTP6_OACK_HEADER
name|Oack
decl_stmt|;
comment|///< Option acknowledge packet header.
name|EFI_MTFTP6_DATA_HEADER
name|Data
decl_stmt|;
comment|///< Data packet header.
name|EFI_MTFTP6_ACK_HEADER
name|Ack
decl_stmt|;
comment|///< Acknowledgement packet header.
name|EFI_MTFTP6_DATA8_HEADER
name|Data8
decl_stmt|;
comment|///< Data packet header with big block number.
name|EFI_MTFTP6_ACK8_HEADER
name|Ack8
decl_stmt|;
comment|///< Acknowledgement header with big block number.
name|EFI_MTFTP6_ERROR_HEADER
name|Error
decl_stmt|;
comment|///< Error packet header.
block|}
name|EFI_MTFTP6_PACKET
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
comment|/// EFI_MTFTP6_CONFIG_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The local IP address to use. Set to zero to let the underlying IPv6
comment|/// driver choose a source address. If not zero it must be one of the
comment|/// configured IP addresses in the underlying IPv6 driver.
comment|///
name|EFI_IPv6_ADDRESS
name|StationIp
decl_stmt|;
comment|///
comment|/// Local port number. Set to zero to use the automatically assigned port number.
comment|///
name|UINT16
name|LocalPort
decl_stmt|;
comment|///
comment|/// The IP address of the MTFTPv6 server.
comment|///
name|EFI_IPv6_ADDRESS
name|ServerIp
decl_stmt|;
comment|///
comment|/// The initial MTFTPv6 server port number. Request packets are
comment|/// sent to this port. This number is almost always 69 and using zero
comment|/// defaults to 69.
name|UINT16
name|InitialServerPort
decl_stmt|;
comment|///
comment|/// The number of times to transmit MTFTPv6 request packets and wait for a response.
comment|///
name|UINT16
name|TryCount
decl_stmt|;
comment|///
comment|/// The number of seconds to wait for a response after sending the MTFTPv6 request packet.
comment|///
name|UINT16
name|TimeoutValue
decl_stmt|;
block|}
name|EFI_MTFTP6_CONFIG_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_MODE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The configuration data of this instance.
comment|///
name|EFI_MTFTP6_CONFIG_DATA
name|ConfigData
decl_stmt|;
comment|///
comment|/// The number of option strings in the following SupportedOptions array.
comment|///
name|UINT8
name|SupportedOptionCount
decl_stmt|;
comment|///
comment|/// An array of null-terminated ASCII option strings that are recognized and supported by
comment|/// this EFI MTFTPv6 Protocol driver implementation. The buffer is
comment|/// read only to the caller and the caller should NOT free the buffer.
comment|///
name|UINT8
modifier|*
modifier|*
name|SupportedOptions
decl_stmt|;
block|}
name|EFI_MTFTP6_MODE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP_OVERRIDE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// IP address of the MTFTPv6 server. If set to all zero, the value that
comment|/// was set by the EFI_MTFTP6_PROTOCOL.Configure() function will be used.
comment|///
name|EFI_IPv6_ADDRESS
name|ServerIp
decl_stmt|;
comment|///
comment|/// MTFTPv6 server port number. If set to zero, it will use the value
comment|/// that was set by the EFI_MTFTP6_PROTOCOL.Configure() function.
comment|///
name|UINT16
name|ServerPort
decl_stmt|;
comment|///
comment|/// Number of times to transmit MTFTPv6 request packets and wait
comment|/// for a response. If set to zero, the value that was set by
comment|/// theEFI_MTFTP6_PROTOCOL.Configure() function will be used.
comment|///
name|UINT16
name|TryCount
decl_stmt|;
comment|///
comment|/// Number of seconds to wait for a response after sending the
comment|/// MTFTPv6 request packet. If set to zero, the value that was set by
comment|/// the EFI_MTFTP6_PROTOCOL.Configure() function will be used.
comment|///
name|UINT16
name|TimeoutValue
decl_stmt|;
block|}
name|EFI_MTFTP6_OVERRIDE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_MTFTP6_OPTION
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
comment|///< Pointer to the null-terminated ASCII MTFTPv6 option string.
name|UINT8
modifier|*
name|ValueStr
decl_stmt|;
comment|///< Pointer to the null-terminated ASCII MTFTPv6 value string.
block|}
name|EFI_MTFTP6_OPTION
typedef|;
end_typedef

begin_comment
comment|/**   EFI_MTFTP6_TIMEOUT_CALLBACK is a callback function that the caller provides to capture the   timeout event in the EFI_MTFTP6_PROTOCOL.ReadFile(), EFI_MTFTP6_PROTOCOL.WriteFile() or   EFI_MTFTP6_PROTOCOL.ReadDirectory() functions.    Whenever a timeout occurs, the EFI MTFTPv6 Protocol driver will call the EFI_MTFTP6_TIMEOUT_CALLBACK   function to notify the caller of the timeout event. Any status code other than EFI_SUCCESS   that is returned from this function will abort the current download process.    @param[in] This          Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in] Token         The token that the caller provided in the EFI_MTFTP6_PROTOCOl.ReadFile(),                            WriteFile() or ReadDirectory() function.   @param[in] PacketLen     Indicates the length of the packet.   @param[in] Packet        Pointer to an MTFTPv6 packet.    @retval EFI_SUCCESS      Operation success.   @retval Others           Aborts session.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_CHECK_PACKET
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINT16
name|PacketLen
parameter_list|,
name|IN
name|EFI_MTFTP6_PACKET
modifier|*
name|Packet
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   EFI_MTFTP6_TIMEOUT_CALLBACK is a callback function that the caller provides to capture the   timeout event in the EFI_MTFTP6_PROTOCOL.ReadFile(), EFI_MTFTP6_PROTOCOL.WriteFile() or   EFI_MTFTP6_PROTOCOL.ReadDirectory() functions.    Whenever a timeout occurs, the EFI MTFTPv6 Protocol driver will call the EFI_MTFTP6_TIMEOUT_CALLBACK   function to notify the caller of the timeout event. Any status code other than EFI_SUCCESS   that is returned from this function will abort the current download process.    @param[in]      This     Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]      Token    The token that is provided in the EFI_MTFTP6_PROTOCOL.ReadFile() or                            EFI_MTFTP6_PROTOCOL.WriteFile() or EFI_MTFTP6_PROTOCOL.ReadDirectory()                            functions by the caller.    @retval EFI_SUCCESS      Operation success.   @retval Others           Aborts session.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_TIMEOUT_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   EFI_MTFTP6_PACKET_NEEDED is a callback function that the caller provides to feed data to the   EFI_MTFTP6_PROTOCOL.WriteFile() function.    EFI_MTFTP6_PACKET_NEEDED provides another mechanism for the caller to provide data to upload   other than a static buffer. The EFI MTFTP6 Protocol driver always calls EFI_MTFTP6_PACKET_NEEDED   to get packet data from the caller if no static buffer was given in the initial call to   EFI_MTFTP6_PROTOCOL.WriteFile() function. Setting *Length to zero signals the end of the session.   Returning a status code other than EFI_SUCCESS aborts the session.    @param[in]      This     Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]      Token    The token provided in the EFI_MTFTP6_PROTOCOL.WriteFile() by the caller.   @param[in, out] Length   Indicates the length of the raw data wanted on input, and the                            length the data available on output.   @param[out]     Buffer   Pointer to the buffer where the data is stored.    @retval EFI_SUCCESS      Operation success.   @retval Others           Aborts session.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_PACKET_NEEDED
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
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

begin_struct
struct|struct
name|_EFI_MTFTP6_TOKEN
block|{
comment|///
comment|/// The status that is returned to the caller at the end of the operation
comment|/// to indicate whether this operation completed successfully.
comment|/// Defined Status values are listed below.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// The event that will be signaled when the operation completes. If
comment|/// set to NULL, the corresponding function will wait until the read or
comment|/// write operation finishes. The type of Event must be EVT_NOTIFY_SIGNAL.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// If not NULL, the data that will be used to override the existing
comment|/// configure data.
comment|///
name|EFI_MTFTP6_OVERRIDE_DATA
modifier|*
name|OverrideData
decl_stmt|;
comment|///
comment|/// Pointer to the null-terminated ASCII file name string.
comment|///
name|UINT8
modifier|*
name|Filename
decl_stmt|;
comment|///
comment|/// Pointer to the null-terminated ASCII mode string. If NULL, octet is used.
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
comment|/// Pointer to an array of option/value string pairs. Ignored if
comment|/// OptionCount is zero. Both a remote server and this driver
comment|/// implementation should support these options. If one or more
comment|/// options are unrecognized by this implementation, it is sent to the
comment|/// remote server without being changed.
comment|///
name|EFI_MTFTP6_OPTION
modifier|*
name|OptionList
decl_stmt|;
comment|///
comment|/// On input, the size, in bytes, of Buffer. On output, the number
comment|/// of bytes transferred.
comment|///
name|UINT64
name|BufferSize
decl_stmt|;
comment|///
comment|/// Pointer to the data buffer. Data that is downloaded from the
comment|/// MTFTPv6 server is stored here. Data that is uploaded to the
comment|/// MTFTPv6 server is read from here. Ignored if BufferSize is zero.
comment|///
name|VOID
modifier|*
name|Buffer
decl_stmt|;
comment|///
comment|/// Pointer to the context that will be used by CheckPacket,
comment|/// TimeoutCallback and PacketNeeded.
comment|///
name|VOID
modifier|*
name|Context
decl_stmt|;
comment|///
comment|/// Pointer to the callback function to check the contents of the
comment|/// received packet.
comment|///
name|EFI_MTFTP6_CHECK_PACKET
name|CheckPacket
decl_stmt|;
comment|///
comment|/// Pointer to the function to be called when a timeout occurs.
comment|///
name|EFI_MTFTP6_TIMEOUT_CALLBACK
name|TimeoutCallback
decl_stmt|;
comment|///
comment|/// Pointer to the function to provide the needed packet contents.
comment|/// Only used in WriteFile() operation.
comment|///
name|EFI_MTFTP6_PACKET_NEEDED
name|PacketNeeded
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   Read the current operational settings.    The GetModeData() function reads the current operational settings of this EFI MTFTPv6   Protocol driver instance.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[out] ModeData           The buffer in which the EFI MTFTPv6 Protocol driver mode                                  data is returned.    @retval  EFI_SUCCESS           The configuration data was successfully returned.   @retval  EFI_OUT_OF_RESOURCES  The required mode data could not be allocated.   @retval  EFI_INVALID_PARAMETER This is NULL or ModeData is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_MTFTP6_MODE_DATA
modifier|*
name|ModeData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initializes, changes, or resets the default operational setting for this EFI MTFTPv6   Protocol driver instance.    The Configure() function is used to set and change the configuration data for this EFI   MTFTPv6 Protocol driver instance. The configuration data can be reset to startup defaults by calling   Configure() with MtftpConfigData set to NULL. Whenever the instance is reset, any   pending operation is aborted. By changing the EFI MTFTPv6 Protocol driver instance configuration   data, the client can connect to different MTFTPv6 servers. The configuration parameters in   MtftpConfigData are used as the default parameters in later MTFTPv6 operations and can be   overridden in later operations.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  MtftpConfigData    Pointer to the configuration data structure.    @retval  EFI_SUCCESS           The EFI MTFTPv6 Protocol instance was configured successfully.   @retval  EFI_INVALID_PARAMETER One or more following conditions are TRUE:                                  - This is NULL.                                  - MtftpConfigData.StationIp is neither zero nor one                                    of the configured IP addresses in the underlying IPv6 driver.                                  - MtftpCofigData.ServerIp is not a valid IPv6 unicast address.   @retval  EFI_ACCESS_DENIED     - The configuration could not be changed at this time because there                                    is some MTFTP background operation in progress.                                  - MtftpCofigData.LocalPort is already in use.   @retval  EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                  address for this instance, but no source address was available for use.   @retval  EFI_OUT_OF_RESOURCES  The EFI MTFTPv6 Protocol driver instance data could not be                                  allocated.   @retval  EFI_DEVICE_ERROR      An unexpected system or network error occurred. The EFI                                  MTFTPv6 Protocol driver instance is not configured.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_CONFIG_DATA
modifier|*
name|MtftpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get information about a file from an MTFTPv6 server.    The GetInfo() function assembles an MTFTPv6 request packet with options, sends it to the   MTFTPv6 server, and may return an MTFTPv6 OACK, MTFTPv6 ERROR, or ICMP ERROR packet.   Retries occur only if no response packets are received from the MTFTPv6 server before the   timeout expires.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  OverrideData       Data that is used to override the existing parameters. If NULL, the                                  default parameters that were set in the EFI_MTFTP6_PROTOCOL.Configure()                                  function are used.   @param[in]  Filename           Pointer to null-terminated ASCII file name string.   @param[in]  ModeStr            Pointer to null-terminated ASCII mode string. If NULL, octet will be used   @param[in]  OptionCount        Number of option/value string pairs in OptionList.   @param[in]  OptionList         Pointer to array of option/value string pairs. Ignored if                                  OptionCount is zero.   @param[out] PacketLength       The number of bytes in the returned packet.   @param[out] Packet             The pointer to the received packet. This buffer must be freed by                                  the caller.    @retval  EFI_SUCCESS              An MTFTPv6 OACK packet was received and is in the Packet.   @retval  EFI_INVALID_PARAMETER    One or more of the following conditions is TRUE:                                     - This is NULL.                                     - Filename is NULL                                     - OptionCount is not zero and OptionList is NULL.                                     - One or more options in OptionList have wrong format.                                     - PacketLength is NULL.                                     - OverrideData.ServerIp is not valid unicast IPv6 addresses.   @retval  EFI_UNSUPPORTED          One or more options in the OptionList are unsupported by                                     this implementation.   @retval  EFI_NOT_STARTED          The EFI MTFTPv6 Protocol driver has not been started.   @retval  EFI_NO_MAPPING           The underlying IPv6 driver was responsible for choosing a source                                     address for this instance, but no source address was available for use.   @retval  EFI_ACCESS_DENIED        The previous operation has not completed yet.   @retval  EFI_OUT_OF_RESOURCES     Required system resources could not be allocated.   @retval  EFI_TFTP_ERROR           An MTFTPv6 ERROR packet was received and is in the Packet.   @retval  EFI_NETWORK_UNREACHABLE  An ICMP network unreachable error packet was received and the Packet is set to NULL.   @retval  EFI_HOST_UNREACHABLE     An ICMP host unreachable error packet was received and the Packet is set to NULL.   @retval  EFI_PROTOCOL_UNREACHABLE An ICMP protocol unreachable error packet was received and the Packet is set to NULL.   @retval  EFI_PORT_UNREACHABLE     An ICMP port unreachable error packet was received and the Packet is set to NULL.   @retval  EFI_ICMP_ERROR           Some other ICMP ERROR packet was received and the Packet is set to NULL.   @retval  EFI_PROTOCOL_ERROR       An unexpected MTFTPv6 packet was received and is in the Packet.   @retval  EFI_TIMEOUT              No responses were received from the MTFTPv6 server.   @retval  EFI_DEVICE_ERROR         An unexpected network error or system error occurred.   @retval  EFI_NO_MEDIA             There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_OVERRIDE_DATA
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
name|EFI_MTFTP6_OPTION
modifier|*
name|OptionList
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|PacketLength
parameter_list|,
name|OUT
name|EFI_MTFTP6_PACKET
modifier|*
modifier|*
name|Packet
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Parse the options in an MTFTPv6 OACK packet.    The ParseOptions() function parses the option fields in an MTFTPv6 OACK packet and   returns the number of options that were found and optionally a list of pointers to   the options in the packet.   If one or more of the option fields are not valid, then EFI_PROTOCOL_ERROR is returned   and *OptionCount and *OptionList stop at the last valid option.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  PacketLen          Length of the OACK packet to be parsed.   @param[in]  Packet             Pointer to the OACK packet to be parsed.   @param[out] OptionCount        Pointer to the number of options in the following OptionList.   @param[out] OptionList         Pointer to EFI_MTFTP6_OPTION storage. Each pointer in the                                  OptionList points to the corresponding MTFTP option buffer                                  in the Packet. Call the EFI Boot Service FreePool() to                                  release the OptionList if the options in this OptionList                                  are not needed any more.    @retval  EFI_SUCCESS           The OACK packet was valid and the OptionCount and                                  OptionList parameters have been updated.   @retval  EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                  - PacketLen is 0.                                  - Packet is NULL or Packet is not a valid MTFTPv6 packet.                                  - OptionCount is NULL.   @retval  EFI_NOT_FOUND         No options were found in the OACK packet.   @retval  EFI_OUT_OF_RESOURCES  Storage for the OptionList array can not be allocated.   @retval  EFI_PROTOCOL_ERROR    One or more of the option fields is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_PARSE_OPTIONS
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|PacketLen
parameter_list|,
name|IN
name|EFI_MTFTP6_PACKET
modifier|*
name|Packet
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|OptionCount
parameter_list|,
name|OUT
name|EFI_MTFTP6_OPTION
modifier|*
modifier|*
name|OptionList
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Download a file from an MTFTPv6 server.    The ReadFile() function is used to initialize and start an MTFTPv6 download process and   optionally wait for completion. When the download operation completes, whether successfully or   not, the Token.Status field is updated by the EFI MTFTPv6 Protocol driver and then   Token.Event is signaled if it is not NULL.    Data can be downloaded from the MTFTPv6 server into either of the following locations:   - A fixed buffer that is pointed to by Token.Buffer   - A download service function that is pointed to by Token.CheckPacket    If both Token.Buffer and Token.CheckPacket are used, then Token.CheckPacket   will be called first. If the call is successful, the packet will be stored in Token.Buffer.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  Token              Pointer to the token structure to provide the parameters that are                                  used in this operation.    @retval  EFI_SUCCESS              The data file has been transferred successfully.   @retval  EFI_OUT_OF_RESOURCES     Required system resources could not be allocated.   @retval  EFI_BUFFER_TOO_SMALL     BufferSize is not zero but not large enough to hold the                                     downloaded data in downloading process.   @retval  EFI_ABORTED              Current operation is aborted by user.   @retval  EFI_NETWORK_UNREACHABLE  An ICMP network unreachable error packet was received.   @retval  EFI_HOST_UNREACHABLE     An ICMP host unreachable error packet was received.   @retval  EFI_PROTOCOL_UNREACHABLE An ICMP protocol unreachable error packet was received.   @retval  EFI_PORT_UNREACHABLE     An ICMP port unreachable error packet was received.   @retval  EFI_ICMP_ERROR           An ICMP ERROR packet was received.   @retval  EFI_TIMEOUT              No responses were received from the MTFTPv6 server.   @retval  EFI_TFTP_ERROR           An MTFTPv6 ERROR packet was received.   @retval  EFI_DEVICE_ERROR         An unexpected network error or system error occurred.   @retval  EFI_NO_MEDIA             There was a media error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_READ_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Send a file to an MTFTPv6 server. May be unsupported in some implementations.    The WriteFile() function is used to initialize an uploading operation with the given option list   and optionally wait for completion. If one or more of the options is not supported by the server, the   unsupported options are ignored and a standard TFTP process starts instead. When the upload   process completes, whether successfully or not, Token.Event is signaled, and the EFI MTFTPv6   Protocol driver updates Token.Status.    The caller can supply the data to be uploaded in the following two modes:   - Through the user-provided buffer   - Through a callback function    With the user-provided buffer, the Token.BufferSize field indicates the length of the buffer,   and the driver will upload the data in the buffer. With an EFI_MTFTP6_PACKET_NEEDED   callback function, the driver will call this callback function to get more data from the user to upload.   See the definition of EFI_MTFTP6_PACKET_NEEDED for more information. These two modes   cannot be used at the same time. The callback function will be ignored if the user provides the   buffer.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  Token              Pointer to the token structure to provide the parameters that are                                  used in this operation.    @retval  EFI_SUCCESS           The upload session has started.   @retval  EFI_UNSUPPORTED       The operation is not supported by this implementation.   @retval  EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token.Filename is NULL.                                  - Token.OptionCount is not zero and Token.OptionList is NULL.                                  - One or more options in Token.OptionList have wrong format.                                  - Token.Buffer and Token.PacketNeeded are both NULL.                                  - Token.OverrideData.ServerIp is not valid unicast IPv6 addresses.   @retval  EFI_UNSUPPORTED       One or more options in the Token.OptionList are not                                  supported by this implementation.   @retval  EFI_NOT_STARTED       The EFI MTFTPv6 Protocol driver has not been started.   @retval  EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                  address for this instance, but no source address was available for use.   @retval  EFI_ALREADY_STARTED   This Token is already being used in another MTFTPv6 session.   @retval  EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval  EFI_ACCESS_DENIED     The previous operation has not completed yet.   @retval  EFI_DEVICE_ERROR      An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_WRITE_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Download a data file directory from an MTFTPv6 server. May be unsupported in some implementations.    The ReadDirectory() function is used to return a list of files on the MTFTPv6 server that are   logically (or operationally) related to Token.Filename. The directory request packet that is sent   to the server is built with the option list that was provided by caller, if present.    The file information that the server returns is put into either of the following locations:   - A fixed buffer that is pointed to by Token.Buffer   - A download service function that is pointed to by Token.CheckPacket    If both Token.Buffer and Token.CheckPacket are used, then Token.CheckPacket   will be called first. If the call is successful, the packet will be stored in Token.Buffer.    The returned directory listing in the Token.Buffer or EFI_MTFTP6_PACKET consists of a list   of two or three variable-length ASCII strings, each terminated by a null character, for each file in the   directory. If the multicast option is involved, the first field of each directory entry is the static   multicast IP address and UDP port number that is associated with the file name. The format of the   field is ip:ip:ip:ip:port. If the multicast option is not involved, this field and its terminating   null character are not present.    The next field of each directory entry is the file name and the last field is the file information string.   The information string contains the file size and the create/modify timestamp. The format of the   information string is filesize yyyy-mm-dd hh:mm:ss:ffff. The timestamp is   Coordinated Universal Time (UTC; also known as Greenwich Mean Time [GMT]).    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.   @param[in]  Token              Pointer to the token structure to provide the parameters that are                                  used in this operation.    @retval  EFI_SUCCESS           The MTFTPv6 related file "directory" has been downloaded.   @retval  EFI_UNSUPPORTED       The EFI MTFTPv6 Protocol driver does not support this function.   @retval  EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token.Filename is NULL.                                  - Token.OptionCount is not zero and Token.OptionList is NULL.                                  - One or more options in Token.OptionList have wrong format.                                  - Token.Buffer and Token.CheckPacket are both NULL.                                  - Token.OverrideData.ServerIp is not valid unicast IPv6 addresses.   @retval  EFI_UNSUPPORTED       One or more options in the Token.OptionList are not                                  supported by this implementation.   @retval  EFI_NOT_STARTED       The EFI MTFTPv6 Protocol driver has not been started.   @retval  EFI_NO_MAPPING        The underlying IPv6 driver was responsible for choosing a source                                  address for this instance, but no source address was available for use.   @retval  EFI_ALREADY_STARTED   This Token is already being used in another MTFTPv6 session.   @retval  EFI_OUT_OF_RESOURCES  Required system resources could not be allocated.   @retval  EFI_ACCESS_DENIED     The previous operation has not completed yet.   @retval  EFI_DEVICE_ERROR      An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_READ_DIRECTORY
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_MTFTP6_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.    The Poll() function can be used by network drivers and applications to increase the rate that data   packets are moved between the communications device and the transmit and receive queues.   In some systems, the periodic timer event in the managed network driver may not poll the   underlying communications device fast enough to transmit and/or receive all data packets without   missing incoming packets or dropping outgoing packets. Drivers and applications that are   experiencing packet loss should try calling the Poll() function more often.    @param[in]  This               Pointer to the EFI_MTFTP6_PROTOCOL instance.    @retval  EFI_SUCCESS           Incoming or outgoing data was processed.   @retval  EFI_NOT_STARTED       This EFI MTFTPv6 Protocol instance has not been started.   @retval  EFI_INVALID_PARAMETER This is NULL.   @retval  EFI_DEVICE_ERROR      An unexpected system or network error occurred.   @retval  EFI_TIMEOUT           Data was dropped out of the transmit and/or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_MTFTP6_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_MTFTP6_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_MTFTP6_PROTOCOL is designed to be used by UEFI drivers and applications to transmit
end_comment

begin_comment
comment|/// and receive data files. The EFI MTFTPv6 Protocol driver uses the underlying EFI UDPv6 Protocol
end_comment

begin_comment
comment|/// driver and EFI IPv6 Protocol driver.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_MTFTP6_PROTOCOL
block|{
name|EFI_MTFTP6_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_MTFTP6_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_MTFTP6_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_MTFTP6_PARSE_OPTIONS
name|ParseOptions
decl_stmt|;
name|EFI_MTFTP6_READ_FILE
name|ReadFile
decl_stmt|;
name|EFI_MTFTP6_WRITE_FILE
name|WriteFile
decl_stmt|;
name|EFI_MTFTP6_READ_DIRECTORY
name|ReadDirectory
decl_stmt|;
name|EFI_MTFTP6_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMtftp6ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMtftp6ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

