begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI FTPv4 (File Transfer Protocol version 4) Protocol Definition   The EFI FTPv4 Protocol is used to locate communication devices that are    supported by an EFI FTPv4 Protocol driver and to create and destroy instances   of the EFI FTPv4 Protocol child protocol driver that can use the underlying   communication device.   The definitions in this file are defined in UEFI Specification 2.3, which have   not been verified by one implementation yet.    Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.2  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_FTP4_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_FTP4_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_FTP4_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xfaaecb1, 0x226e, 0x4782, {0xaa, 0xce, 0x7d, 0xb9, 0xbc, 0xbf, 0x4d, 0xaf } \   }
end_define

begin_define
define|#
directive|define
name|EFI_FTP4_PROTOCOL_GUID
define|\
value|{ \     0xeb338826, 0x681b, 0x4295, {0xb3, 0x56, 0x2b, 0x36, 0x4c, 0x75, 0x7b, 0x9 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_FTP4_PROTOCOL
name|EFI_FTP4_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FTP4_CONNECTION_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Event to signal after the connection is established and Status field is updated
comment|/// by the EFI FTP v4 Protocol driver. The type of Event must be
comment|/// EVENT_NOTIFY_SIGNAL, and its Task Priority Level (TPL) must be lower than or
comment|/// equal to TPL_CALLBACK. If it is set to NULL, this function will not return  until the
comment|/// function completes.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// The variable to receive the result of the completed operation.
comment|/// EFI_SUCCESS:              The FTP connection is established successfully
comment|/// EFI_ACCESS_DENIED:        The FTP server denied the access the user's request to access it.
comment|/// EFI_CONNECTION_RESET:     The connect fails because the connection is reset either by instance
comment|///                           itself or communication peer.
comment|/// EFI_TIMEOUT:              The connection establishment timer expired and no more specific
comment|///                           information is available.
comment|/// EFI_NETWORK_UNREACHABLE:  The active open fails because an ICMP network unreachable error is
comment|///                           received.
comment|/// EFI_HOST_UNREACHABLE:     The active open fails because an ICMP host unreachable error is
comment|///                           received.
comment|/// EFI_PROTOCOL_UNREACHABLE: The active open fails because an ICMP protocol unreachable error is
comment|///                           received.
comment|/// EFI_PORT_UNREACHABLE:     The connection establishment timer times out and an ICMP port
comment|///                           unreachable error is received.
comment|/// EFI_ICMP_ERROR:           The connection establishment timer timeout and some other ICMP
comment|///                           error is received.
comment|/// EFI_DEVICE_ERROR:         An unexpected system or network error occurred.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
block|}
name|EFI_FTP4_CONNECTION_TOKEN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FTP4_CONFIG_DATA
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Pointer to a ASCII string that contains user name. The caller is
comment|/// responsible for freeing Username after GetModeData() is called.
comment|///
name|UINT8
modifier|*
name|Username
decl_stmt|;
comment|///
comment|/// Pointer to a ASCII string that contains password. The caller is
comment|/// responsible for freeing Password after GetModeData() is called.
comment|///
name|UINT8
modifier|*
name|Password
decl_stmt|;
comment|///
comment|/// Set it to TRUE to initiate an active data connection. Set it to
comment|/// FALSE to initiate a passive data connection.
comment|///
name|BOOLEAN
name|Active
decl_stmt|;
comment|///
comment|/// Boolean value indicating if default network settting used.
comment|///
name|BOOLEAN
name|UseDefaultSetting
decl_stmt|;
comment|///
comment|/// IP address of station if UseDefaultSetting is FALSE.
comment|///
name|EFI_IPv4_ADDRESS
name|StationIp
decl_stmt|;
comment|///
comment|/// Subnet mask of station if UseDefaultSetting is FALSE.
comment|///
name|EFI_IPv4_ADDRESS
name|SubnetMask
decl_stmt|;
comment|///
comment|/// IP address of gateway if UseDefaultSetting is FALSE.
comment|///
name|EFI_IPv4_ADDRESS
name|GatewayIp
decl_stmt|;
comment|///
comment|/// IP address of FTPv4 server.
comment|///
name|EFI_IPv4_ADDRESS
name|ServerIp
decl_stmt|;
comment|///
comment|/// FTPv4 server port number of control connection, and the default
comment|/// value is 21 as convention.
comment|///
name|UINT16
name|ServerPort
decl_stmt|;
comment|///
comment|/// FTPv4 server port number of data connection. If it is zero, use
comment|/// (ServerPort - 1) by convention.
comment|///
name|UINT16
name|AltDataPort
decl_stmt|;
comment|///
comment|/// A byte indicate the representation type. The right 4 bit is used for
comment|/// first parameter, the left 4 bit is use for second parameter
comment|/// - For the first parameter, 0x0 = image, 0x1 = EBCDIC, 0x2 = ASCII, 0x3 = local
comment|/// - For the second parameter, 0x0 = Non-print, 0x1 = Telnet format effectors, 0x2 =
comment|///   Carriage Control.
comment|/// - If it is a local type, the second parameter is the local byte byte size.
comment|/// - If it is a image type, the second parameter is undefined.
comment|///
name|UINT8
name|RepType
decl_stmt|;
comment|///
comment|/// Defines the file structure in FTP used. 0x00 = file, 0x01 = record, 0x02 = page.
comment|///
name|UINT8
name|FileStruct
decl_stmt|;
comment|///
comment|/// Defines the transifer mode used in FTP. 0x00 = stream, 0x01 = Block, 0x02 = Compressed.
comment|///
name|UINT8
name|TransMode
decl_stmt|;
block|}
name|EFI_FTP4_CONFIG_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_FTP4_COMMAND_TOKEN
name|EFI_FTP4_COMMAND_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Callback function when process inbound or outbound data.    If it is receiving function that leads to inbound data, the callback function   is called when data buffer is full. Then, old data in the data buffer should be   flushed and new data is stored from the beginning of data buffer.   If it is a transmit function that lead to outbound data and the size of    Data in daata buffer has been transmitted, this callback function is called to    supply additional data to be transmitted.     @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token structure to provide the parameters that                                  are used in this operation.   @return  User defined Status.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_DATA_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_COMMAND_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FTP4_COMMAND_TOKEN
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FTP4_COMMAND_TOKEN
block|{
comment|///
comment|/// The Event to signal after request is finished and Status field
comment|/// is updated by the EFI FTP v4 Protocol driver. The type of Event
comment|/// must be EVT_NOTIFY_SIGNAL, and its Task Priority Level
comment|/// (TPL) must be lower than or equal to TPL_CALLBACK. If it is
comment|/// set to NULL, related function must wait until the function
comment|/// completes.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Pointer to a null-terminated ASCII name string.
comment|///
name|UINT8
modifier|*
name|Pathname
decl_stmt|;
comment|///
comment|/// The size of data buffer in bytes.
comment|///
name|UINT64
name|DataBufferSize
decl_stmt|;
comment|///
comment|/// Pointer to the data buffer. Data downloaded from FTP server
comment|/// through connection is downloaded here.
comment|///
name|VOID
modifier|*
name|DataBuffer
decl_stmt|;
comment|///
comment|/// Pointer to a callback function. If it is receiving function that leads
comment|/// to inbound data, the callback function is called when databuffer is
comment|/// full. Then, old data in the data buffer should be flushed and new
comment|/// data is stored from the beginning of data buffer. If it is a transmit
comment|/// function that lead to outbound data and DataBufferSize of
comment|/// Data in DataBuffer has been transmitted, this callback
comment|/// function is called to supply additional data to be transmitted. The
comment|/// size of additional data to be transmitted is indicated in
comment|/// DataBufferSize, again. If there is no data remained,
comment|/// DataBufferSize should be set to 0.
comment|///
name|EFI_FTP4_DATA_CALLBACK
modifier|*
name|DataCallback
decl_stmt|;
comment|///
comment|/// Pointer to the parameter for DataCallback.
comment|///
name|VOID
modifier|*
name|Context
decl_stmt|;
comment|///
comment|/// The variable to receive the result of the completed operation.
comment|/// EFI_SUCCESS:              The FTP command is completed successfully.
comment|/// EFI_ACCESS_DENIED:        The FTP server denied the access to the requested file.
comment|/// EFI_CONNECTION_RESET:     The connect fails because the connection is reset either
comment|///                           by instance itself or communication peer.
comment|/// EFI_TIMEOUT:              The connection establishment timer expired and no more
comment|///                           specific information is available.
comment|/// EFI_NETWORK_UNREACHABLE:  The active open fails because an ICMP network unreachable
comment|///                           error is received.
comment|/// EFI_HOST_UNREACHABLE:     The active open fails because an ICMP host unreachable
comment|///                           error is received.
comment|/// EFI_PROTOCOL_UNREACHABLE: The active open fails because an ICMP protocol unreachable
comment|///                           error is received.
comment|/// EFI_PORT_UNREACHABLE:     The connection establishment timer times out and an ICMP port
comment|///                           unreachable error is received.
comment|/// EFI_ICMP_ERROR:           The connection establishment timer timeout and some other ICMP
comment|///                           error is received.
comment|/// EFI_DEVICE_ERROR:         An unexpected system or network error occurred.
comment|///
name|EFI_STATUS
name|Status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   Gets the current operational settings.    The GetModeData() function reads the current operational settings of this   EFI FTPv4 Protocol driver instance. EFI_FTP4_CONFIG_DATA  is defined in the    EFI_FTP4_PROTOCOL.Configure.    @param[in]  This               Pointer to the EFI_FTP4_PROTOCOL instance.   @param[out] ModeData           Pointer to storage for the EFI FTPv4 Protocol driver                                   mode data. The string buffers for Username and Password                                  in EFI_FTP4_CONFIG_DATA are allocated by the function,                                  and the caller should take the responsibility to free the                                   buffer later.    @retval EFI_SUCCESS            This function is called successfully.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - ModeData is NULL.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started   @retval EFI_OUT_OF_RESOURCES   Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_GET_MODE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_FTP4_CONFIG_DATA
modifier|*
name|ModeData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnecting a FTP connection gracefully.    The Connect() function will initiate a connection request to the remote FTP server   with the corresponding connection token. If this function returns EFI_SUCCESS, the    connection sequence is initiated successfully.  If the connection succeeds or faild   due to any error, the Token->Event will be signaled and Token->Status will be updated   accordingly.    @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token used to establish control connection.    @retval EFI_SUCCESS            The connection sequence is successfully initiated.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token->Event is NULL.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES   Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_CONNECTION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnecting a FTP connection gracefully.    The Close() function will initiate a close request to the remote FTP server with the   corresponding connection token. If this function returns EFI_SUCCESS, the control    connection with the remote FTP server is closed.    @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token used to close control connection.    @retval EFI_SUCCESS            The close request is successfully initiated.   @retval EFI_INVALID_PARAMETER  One or more of the following are TRUE:                                  - This is NULL.                                  - Token is NULL.                                  - Token->Event is NULL.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES   Could not allocate enough resource to finish the operation.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_CLOSE
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_CONNECTION_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets or clears the operational parameters for the FTP child driver.    The Configure() function will configure the connected FTP session with the    configuration setting specified in  FtpConfigData. The configuration data can   be reset by calling Configure() with FtpConfigData set to NULL.    @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] FtpConfigData       Pointer to configuration data that will be assigned to                                   the FTP child driver instance. If NULL, the FTP child                                  driver instance is reset to startup defaults and all                                   pending transmit and receive requests are flushed.    @retval EFI_SUCCESS            The FTPv4 driver was configured successfully.   @retval EFI_INVALID_PARAMETER  One or more following conditions are TRUE:                                  - This is NULL.                                  - FtpConfigData.RepType is invalid.                                  - FtpConfigData.FileStruct is invalid.                                  - FtpConfigData.TransMode is invalid.                                  - IP address in FtpConfigData is invalid.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_UNSUPPORTED        One or more of the configuration parameters are not supported                                  by this implementation.    @retval EFI_OUT_OF_RESOURCES   The EFI FTPv4 Protocol driver instance data could not be                                   allocated.   @retval EFI_DEVICE_ERROR       An unexpected system or network error occurred. The EFI FTPv4                                   Protocol driver instance is not configured.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_CONFIGURE
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_CONFIG_DATA
modifier|*
name|FtpConfigData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Downloads a file from an FTPv4 server.     The ReadFile() function is used to initialize and start an FTPv4 download process   and optionally wait for completion. When the download operation completes, whether   successfully or not, the Token.Status field is updated by the EFI FTPv4 Protocol    driver and then Token.Event is signaled (if it is not NULL).    Data will be downloaded from the FTPv4 server into Token.DataBuffer. If the file size   is larger than Token.DataBufferSize, Token.DataCallback will be called to allow for    processing data and then new data will be placed at the beginning of Token.DataBuffer.    @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token structure to provide the parameters that                                  are used in this operation.    @retval EFI_SUCCESS            The data file is being downloaded successfully.   @retval EFI_INVALID_PARAMETER  One or more of the parameters is not valid.                                  - This is NULL.                                  - Token is NULL.                                  - Token.Pathname is NULL.                                  - Token. DataBuffer is NULL.                                  - Token. DataBufferSize is 0.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES   Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR       An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_READ_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_COMMAND_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Uploads a file from an FTPv4 server.     The WriteFile() function is used to initialize and start an FTPv4 upload process and   optionally wait for completion. When the upload operation completes, whether successfully   or not, the Token.Status field is updated by the EFI FTPv4 Protocol driver and then   Token.Event is signaled (if it is not NULL). Data to be  uploaded to server is stored   into Token.DataBuffer. Token.DataBufferSize is the number bytes to be transferred.    If the file size is larger than Token.DataBufferSize, Token.DataCallback will be called   to allow for processing data and then new data will be placed at the beginning of    Token.DataBuffer. Token.DataBufferSize is updated to reflect the actual number of bytes   to be transferred. Token.DataBufferSize is set to 0 by the call back to indicate the   completion of data transfer.    @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token structure to provide the parameters that                                  are used in this operation.    @retval EFI_SUCCESS            TThe data file is being uploaded successfully.   @retval EFI_UNSUPPORTED        The operation is not supported by this implementation.   @retval EFI_INVALID_PARAMETER  One or more of the parameters is not valid.                                  - This is NULL.                                  - Token is NULL.                                  - Token.Pathname is NULL.                                  - Token. DataBuffer is NULL.                                  - Token. DataBufferSize is 0.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES   Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR       An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_WRITE_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_COMMAND_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Download a data file "directory" from a FTPv4 server. May be unsupported in some EFI    implementations.    The ReadDirectory() function is used to return a list of files on the FTPv4 server that   logically (or operationally) related to Token.Pathname, and optionally wait for completion.   When the download operation completes, whether successfully or not, the Token.Status field    is updated by the EFI FTPv4 Protocol driver and then Token.Event is signaled (if it is not   NULL). Data will be downloaded from the FTPv4 server into Token.DataBuffer. If the file size   is larger than Token.DataBufferSize, Token.DataCallback will be called to allow for processing   data and then new data will be placed at the beginning of Token.DataBuffer.     @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.   @param[in] Token               Pointer to the token structure to provide the parameters that                                  are used in this operation.    @retval EFI_SUCCESS            The file list information is being downloaded successfully.   @retval EFI_UNSUPPORTED        The operation is not supported by this implementation.   @retval EFI_INVALID_PARAMETER  One or more of the parameters is not valid.                                  - This is NULL.                                  - Token is NULL.                                  - Token. DataBuffer is NULL.                                  - Token. DataBufferSize is 0.   @retval EFI_NOT_STARTED        The EFI FTPv4 Protocol driver has not been started.   @retval EFI_NO_MAPPING         When using a default address, configuration (DHCP, BOOTP,                                   RARP, etc.) is not finished yet.   @retval EFI_OUT_OF_RESOURCES   Required system resources could not be allocated.   @retval EFI_DEVICE_ERROR       An unexpected network error or system error occurred.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_READ_DIRECTORY
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_FTP4_COMMAND_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Polls for incoming data packets and processes outgoing data packets.     The Poll() function can be used by network drivers and applications to increase the   rate that data packets are moved between the communications device and the transmit   and receive queues. In some systems, the periodic timer event in the managed network   driver may not poll the underlying communications device fast enough to transmit    and/or receive all data packets without missing incoming packets or dropping outgoing   packets. Drivers and applications that are experiencing packet loss should try calling   the Poll() function more often.     @param[in] This                Pointer to the EFI_FTP4_PROTOCOL instance.    @retval EFI_SUCCESS            Incoming or outgoing data was processed.   @retval EFI_NOT_STARTED        This EFI FTPv4 Protocol instance has not been started.   @retval EFI_INVALID_PARAMETER  This is NULL.   @retval EFI_DEVICE_ERROR       EapAuthType An unexpected system or network error occurred.   @retval EFI_TIMEOUT            Data was dropped out of the transmit and/or receive queue.                                  Consider increasing the polling rate.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FTP4_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_FTP4_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FTP4_PROTOCOL
end_comment

begin_comment
comment|/// provides basic services for client-side FTP (File Transfer Protocol)
end_comment

begin_comment
comment|/// operations.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FTP4_PROTOCOL
block|{
name|EFI_FTP4_GET_MODE_DATA
name|GetModeData
decl_stmt|;
name|EFI_FTP4_CONNECT
name|Connect
decl_stmt|;
name|EFI_FTP4_CLOSE
name|Close
decl_stmt|;
name|EFI_FTP4_CONFIGURE
name|Configure
decl_stmt|;
name|EFI_FTP4_READ_FILE
name|ReadFile
decl_stmt|;
name|EFI_FTP4_WRITE_FILE
name|WriteFile
decl_stmt|;
name|EFI_FTP4_READ_DIRECTORY
name|ReadDirectory
decl_stmt|;
name|EFI_FTP4_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFtp4ServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFtp4ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

