begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The EFI_SIMPLE_NETWORK_PROTOCOL provides services to initialize a network interface,    transmit packets, receive packets, and close a network interface.    Basic network device abstraction.    Rx    - Received   Tx    - Transmit   MCast - MultiCast   ...  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.       @par Revision Reference:             This Protocol is introduced in EFI Specification 1.10.            **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_NETWORK_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_NETWORK_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_PROTOCOL_GUID
define|\
value|{ \     0xA19832B9, 0xAC25, 0x11D3, {0x9A, 0x2D, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_NETWORK_PROTOCOL
name|EFI_SIMPLE_NETWORK_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_SIMPLE_NETWORK_PROTOCOL
name|EFI_SIMPLE_NETWORK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Simple Network Protocol data structures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Total number of frames received.  Includes frames with errors and
comment|/// dropped frames.
comment|///
name|UINT64
name|RxTotalFrames
decl_stmt|;
comment|///
comment|/// Number of valid frames received and copied into receive buffers.
comment|///
name|UINT64
name|RxGoodFrames
decl_stmt|;
comment|///
comment|/// Number of frames below the minimum length for the media.
comment|/// This would be<64 for ethernet.
comment|///
name|UINT64
name|RxUndersizeFrames
decl_stmt|;
comment|///
comment|/// Number of frames longer than the maxminum length for the
comment|/// media.  This would be>1500 for ethernet.
comment|///
name|UINT64
name|RxOversizeFrames
decl_stmt|;
comment|///
comment|/// Valid frames that were dropped because receive buffers were full.
comment|///
name|UINT64
name|RxDroppedFrames
decl_stmt|;
comment|///
comment|/// Number of valid unicast frames received and not dropped.
comment|///
name|UINT64
name|RxUnicastFrames
decl_stmt|;
comment|///
comment|/// Number of valid broadcast frames received and not dropped.
comment|///
name|UINT64
name|RxBroadcastFrames
decl_stmt|;
comment|///
comment|/// Number of valid mutlicast frames received and not dropped.
comment|///
name|UINT64
name|RxMulticastFrames
decl_stmt|;
comment|///
comment|/// Number of frames w/ CRC or alignment errors.
comment|///
name|UINT64
name|RxCrcErrorFrames
decl_stmt|;
comment|///
comment|/// Total number of bytes received.  Includes frames with errors
comment|/// and dropped frames.
comment|//
name|UINT64
name|RxTotalBytes
decl_stmt|;
comment|///
comment|/// Transmit statistics.
comment|///
name|UINT64
name|TxTotalFrames
decl_stmt|;
name|UINT64
name|TxGoodFrames
decl_stmt|;
name|UINT64
name|TxUndersizeFrames
decl_stmt|;
name|UINT64
name|TxOversizeFrames
decl_stmt|;
name|UINT64
name|TxDroppedFrames
decl_stmt|;
name|UINT64
name|TxUnicastFrames
decl_stmt|;
name|UINT64
name|TxBroadcastFrames
decl_stmt|;
name|UINT64
name|TxMulticastFrames
decl_stmt|;
name|UINT64
name|TxCrcErrorFrames
decl_stmt|;
name|UINT64
name|TxTotalBytes
decl_stmt|;
comment|///
comment|/// Number of collisions detection on this subnet.
comment|///
name|UINT64
name|Collisions
decl_stmt|;
comment|///
comment|/// Number of frames destined for unsupported protocol.
comment|///
name|UINT64
name|UnsupportedProtocol
decl_stmt|;
comment|///
comment|/// Number of valid frames received that were duplicated.
comment|///
name|UINT64
name|RxDuplicatedFrames
decl_stmt|;
comment|///
comment|/// Number of encrypted frames received that failed to decrypt.
comment|///
name|UINT64
name|RxDecryptErrorFrames
decl_stmt|;
comment|///
comment|/// Number of frames that failed to transmit after exceeding the retry limit.
comment|///
name|UINT64
name|TxErrorFrames
decl_stmt|;
comment|///
comment|/// Number of frames transmitted successfully after more than one attempt.
comment|///
name|UINT64
name|TxRetryFrames
decl_stmt|;
block|}
name|EFI_NETWORK_STATISTICS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The state of the network interface.
end_comment

begin_comment
comment|/// When an EFI_SIMPLE_NETWORK_PROTOCOL driver initializes a
end_comment

begin_comment
comment|/// network interface, the network interface is left in the EfiSimpleNetworkStopped state.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiSimpleNetworkStopped
block|,
name|EfiSimpleNetworkStarted
block|,
name|EfiSimpleNetworkInitialized
block|,
name|EfiSimpleNetworkMaxState
block|}
name|EFI_SIMPLE_NETWORK_STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_UNICAST
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_MULTICAST
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_BROADCAST
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_PROMISCUOUS
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_PROMISCUOUS_MULTICAST
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_RECEIVE_INTERRUPT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_TRANSMIT_INTERRUPT
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_COMMAND_INTERRUPT
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_SOFTWARE_INTERRUPT
value|0x08
end_define

begin_define
define|#
directive|define
name|MAX_MCAST_FILTER_CNT
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Reports the current state of the network interface.
comment|///
name|UINT32
name|State
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the network interface's HW address.
comment|///
name|UINT32
name|HwAddressSize
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the network interface's media header.
comment|///
name|UINT32
name|MediaHeaderSize
decl_stmt|;
comment|///
comment|/// The maximum size, in bytes, of the packets supported by the network interface.
comment|///
name|UINT32
name|MaxPacketSize
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the NVRAM device attached to the network interface.
comment|///
name|UINT32
name|NvRamSize
decl_stmt|;
comment|///
comment|/// The size that must be used for all NVRAM reads and writes. The
comment|/// start address for NVRAM read and write operations and the total
comment|/// length of those operations, must be a multiple of this value. The
comment|/// legal values for this field are 0, 1, 2, 4, and 8.
comment|///
name|UINT32
name|NvRamAccessSize
decl_stmt|;
comment|///
comment|/// The multicast receive filter settings supported by the network interface.
comment|///
name|UINT32
name|ReceiveFilterMask
decl_stmt|;
comment|///
comment|/// The current multicast receive filter settings.
comment|///
name|UINT32
name|ReceiveFilterSetting
decl_stmt|;
comment|///
comment|/// The maximum number of multicast address receive filters supported by the driver.
comment|///
name|UINT32
name|MaxMCastFilterCount
decl_stmt|;
comment|///
comment|/// The current number of multicast address receive filters.
comment|///
name|UINT32
name|MCastFilterCount
decl_stmt|;
comment|///
comment|/// Array containing the addresses of the current multicast address receive filters.
comment|///
name|EFI_MAC_ADDRESS
name|MCastFilter
index|[
name|MAX_MCAST_FILTER_CNT
index|]
decl_stmt|;
comment|///
comment|/// The current HW MAC address for the network interface.
comment|///
name|EFI_MAC_ADDRESS
name|CurrentAddress
decl_stmt|;
comment|///
comment|/// The current HW MAC address for broadcast packets.
comment|///
name|EFI_MAC_ADDRESS
name|BroadcastAddress
decl_stmt|;
comment|///
comment|/// The permanent HW MAC address for the network interface.
comment|///
name|EFI_MAC_ADDRESS
name|PermanentAddress
decl_stmt|;
comment|///
comment|/// The interface type of the network interface.
comment|///
name|UINT8
name|IfType
decl_stmt|;
comment|///
comment|/// TRUE if the HW MAC address can be changed.
comment|///
name|BOOLEAN
name|MacAddressChangeable
decl_stmt|;
comment|///
comment|/// TRUE if the network interface can transmit more than one packet at a time.
comment|///
name|BOOLEAN
name|MultipleTxSupported
decl_stmt|;
comment|///
comment|/// TRUE if the presence of media can be determined; otherwise FALSE.
comment|///
name|BOOLEAN
name|MediaPresentSupported
decl_stmt|;
comment|///
comment|/// TRUE if media are connected to the network interface; otherwise FALSE.
comment|///
name|BOOLEAN
name|MediaPresent
decl_stmt|;
block|}
name|EFI_SIMPLE_NETWORK_MODE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol Member Functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Changes the state of a network interface from "stopped" to "started".    @param  This Protocol instance pointer.    @retval EFI_SUCCESS           The network interface was started.   @retval EFI_ALREADY_STARTED   The network interface is already in the started state.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_START
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Changes the state of a network interface from "started" to "stopped".    @param  This Protocol instance pointer.    @retval EFI_SUCCESS           The network interface was stopped.   @retval EFI_ALREADY_STARTED   The network interface is already in the stopped state.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets a network adapter and allocates the transmit and receive buffers    required by the network interface; optionally, also requests allocation    of additional transmit and receive buffers.    @param  This              The protocol instance pointer.   @param  ExtraRxBufferSize The size, in bytes, of the extra receive buffer space                             that the driver should allocate for the network interface.                             Some network interfaces will not be able to use the extra                             buffer, and the caller will not know if it is actually                             being used.   @param  ExtraTxBufferSize The size, in bytes, of the extra transmit buffer space                             that the driver should allocate for the network interface.                             Some network interfaces will not be able to use the extra                             buffer, and the caller will not know if it is actually                             being used.    @retval EFI_SUCCESS           The network interface was initialized.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory for the transmit and                                 receive buffers.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_INITIALIZE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|ExtraRxBufferSize
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|ExtraTxBufferSize
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets a network adapter and re-initializes it with the parameters that were    provided in the previous call to Initialize().      @param  This                 The protocol instance pointer.   @param  ExtendedVerification Indicates that the driver may perform a more                                exhaustive verification operation of the device                                during reset.    @retval EFI_SUCCESS           The network interface was reset.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
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
comment|/**   Resets a network adapter and leaves it in a state that is safe for    another driver to initialize.    @param  This Protocol instance pointer.    @retval EFI_SUCCESS           The network interface was shutdown.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_SHUTDOWN
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Manages the multicast receive filters of a network interface.    @param  This             The protocol instance pointer.   @param  Enable           A bit mask of receive filters to enable on the network interface.   @param  Disable          A bit mask of receive filters to disable on the network interface.   @param  ResetMCastFilter Set to TRUE to reset the contents of the multicast receive                            filters on the network interface to their default values.   @param  McastFilterCnt   Number of multicast HW MAC addresses in the new                            MCastFilter list. This value must be less than or equal to                            the MCastFilterCnt field of EFI_SIMPLE_NETWORK_MODE. This                            field is optional if ResetMCastFilter is TRUE.   @param  MCastFilter      A pointer to a list of new multicast receive filter HW MAC                            addresses. This list will replace any existing multicast                            HW MAC address list. This field is optional if                            ResetMCastFilter is TRUE.    @retval EFI_SUCCESS           The multicast receive filter list was updated.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_RECEIVE_FILTERS
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Enable
parameter_list|,
name|IN
name|UINT32
name|Disable
parameter_list|,
name|IN
name|BOOLEAN
name|ResetMCastFilter
parameter_list|,
name|IN
name|UINTN
name|MCastFilterCnt
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|MCastFilter
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Modifies or resets the current station address, if supported.    @param  This  The protocol instance pointer.   @param  Reset Flag used to reset the station address to the network interfaces                 permanent address.   @param  New   The new station address to be used for the network interface.    @retval EFI_SUCCESS           The network interfaces station address was updated.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_STATION_ADDRESS
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Reset
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|New
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets or collects the statistics on a network interface.    @param  This            Protocol instance pointer.   @param  Reset           Set to TRUE to reset the statistics for the network interface.   @param  StatisticsSize  On input the size, in bytes, of StatisticsTable. On                           output the size, in bytes, of the resulting table of                           statistics.   @param  StatisticsTable A pointer to the EFI_NETWORK_STATISTICS structure that                           contains the statistics.    @retval EFI_SUCCESS           The statistics were collected from the network interface.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_BUFFER_TOO_SMALL  The Statistics buffer was too small. The current buffer                                 size needed to hold the statistics is returned in                                 StatisticsSize.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_STATISTICS
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|Reset
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|StatisticsSize
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_NETWORK_STATISTICS
modifier|*
name|StatisticsTable
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts a multicast IP address to a multicast HW MAC address.    @param  This The protocol instance pointer.   @param  IPv6 Set to TRUE if the multicast IP address is IPv6 [RFC 2460]. Set                to FALSE if the multicast IP address is IPv4 [RFC 791].   @param  IP   The multicast IP address that is to be converted to a multicast                HW MAC address.   @param  MAC  The multicast HW MAC address that is to be generated from IP.    @retval EFI_SUCCESS           The multicast IP address was mapped to the multicast                                 HW MAC address.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_BUFFER_TOO_SMALL  The Statistics buffer was too small. The current buffer                                 size needed to hold the statistics is returned in                                 StatisticsSize.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_MCAST_IP_TO_MAC
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|IPv6
parameter_list|,
name|IN
name|EFI_IP_ADDRESS
modifier|*
name|IP
parameter_list|,
name|OUT
name|EFI_MAC_ADDRESS
modifier|*
name|MAC
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Performs read and write operations on the NVRAM device attached to a    network interface.    @param  This       The protocol instance pointer.   @param  ReadWrite  TRUE for read operations, FALSE for write operations.   @param  Offset     Byte offset in the NVRAM device at which to start the read or                      write operation. This must be a multiple of NvRamAccessSize and                      less than NvRamSize.   @param  BufferSize The number of bytes to read or write from the NVRAM device.                      This must also be a multiple of NvramAccessSize.   @param  Buffer     A pointer to the data buffer.    @retval EFI_SUCCESS           The NVRAM access was performed.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_NVDATA
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ReadWrite
parameter_list|,
name|IN
name|UINTN
name|Offset
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads the current interrupt status and recycled transmit buffer status from    a network interface.    @param  This            The protocol instance pointer.   @param  InterruptStatus A pointer to the bit mask of the currently active interrupts                           If this is NULL, the interrupt status will not be read from                           the device. If this is not NULL, the interrupt status will                           be read from the device. When the  interrupt status is read,                           it will also be cleared. Clearing the transmit  interrupt                           does not empty the recycled transmit buffer array.   @param  TxBuf           Recycled transmit buffer address. The network interface will                           not transmit if its internal recycled transmit buffer array                           is full. Reading the transmit buffer does not clear the                           transmit interrupt. If this is NULL, then the transmit buffer                           status will not be read. If there are no transmit buffers to                           recycle and TxBuf is not NULL, * TxBuf will be set to NULL.    @retval EFI_SUCCESS           The status of the network interface was retrieved.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_GET_STATUS
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|InterruptStatus
name|OPTIONAL
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|TxBuf
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Places a packet in the transmit queue of a network interface.    @param  This       The protocol instance pointer.   @param  HeaderSize The size, in bytes, of the media header to be filled in by                      the Transmit() function. If HeaderSize is non-zero, then it                      must be equal to This->Mode->MediaHeaderSize and the DestAddr                      and Protocol parameters must not be NULL.   @param  BufferSize The size, in bytes, of the entire packet (media header and                      data) to be transmitted through the network interface.   @param  Buffer     A pointer to the packet (media header followed by data) to be                      transmitted. This parameter cannot be NULL. If HeaderSize is zero,                      then the media header in Buffer must already be filled in by the                      caller. If HeaderSize is non-zero, then the media header will be                      filled in by the Transmit() function.   @param  SrcAddr    The source HW MAC address. If HeaderSize is zero, then this parameter                      is ignored. If HeaderSize is non-zero and SrcAddr is NULL, then                      This->Mode->CurrentAddress is used for the source HW MAC address.   @param  DestAddr   The destination HW MAC address. If HeaderSize is zero, then this                      parameter is ignored.   @param  Protocol   The type of header to build. If HeaderSize is zero, then this                      parameter is ignored. See RFC 1700, section "Ether Types", for                      examples.    @retval EFI_SUCCESS           The packet was placed on the transmit queue.   @retval EFI_NOT_STARTED       The network interface has not been started.   @retval EFI_NOT_READY         The network interface is too busy to accept this transmit request.                         @retval EFI_BUFFER_TOO_SMALL  The BufferSize parameter is too small.   @retval EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_TRANSMIT
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|HeaderSize
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|SrcAddr
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_MAC_ADDRESS
modifier|*
name|DestAddr
name|OPTIONAL
parameter_list|,
name|IN
name|UINT16
modifier|*
name|Protocol
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Receives a packet from a network interface.    @param  This       The protocol instance pointer.   @param  HeaderSize The size, in bytes, of the media header received on the network                      interface. If this parameter is NULL, then the media header size                      will not be returned.   @param  BufferSize On entry, the size, in bytes, of Buffer. On exit, the size, in                      bytes, of the packet that was received on the network interface.   @param  Buffer     A pointer to the data buffer to receive both the media header and                      the data.   @param  SrcAddr    The source HW MAC address. If this parameter is NULL, the                      HW MAC source address will not be extracted from the media                      header.   @param  DestAddr   The destination HW MAC address. If this parameter is NULL,                      the HW MAC destination address will not be extracted from the                      media header.   @param  Protocol   The media header type. If this parameter is NULL, then the                      protocol will not be extracted from the media header. See                      RFC 1700 section "Ether Types" for examples.    @retval  EFI_SUCCESS           The received data was stored in Buffer, and BufferSize has                                  been updated to the number of bytes received.   @retval  EFI_NOT_STARTED       The network interface has not been started.   @retval  EFI_NOT_READY         The network interface is too busy to accept this transmit                                  request.   @retval  EFI_BUFFER_TOO_SMALL  The BufferSize parameter is too small.   @retval  EFI_INVALID_PARAMETER One or more of the parameters has an unsupported value.   @retval  EFI_DEVICE_ERROR      The command could not be sent to the network interface.   @retval  EFI_UNSUPPORTED       This function is not supported by the network interface.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_NETWORK_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_NETWORK_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|HeaderSize
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|EFI_MAC_ADDRESS
modifier|*
name|SrcAddr
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_MAC_ADDRESS
modifier|*
name|DestAddr
name|OPTIONAL
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Protocol
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_PROTOCOL_REVISION
value|0x00010000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Revision defined in EFI1.1
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SIMPLE_NETWORK_INTERFACE_REVISION
value|EFI_SIMPLE_NETWORK_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SIMPLE_NETWORK_PROTOCOL protocol is used to initialize access
end_comment

begin_comment
comment|/// to a network adapter. Once the network adapter initializes,
end_comment

begin_comment
comment|/// the EFI_SIMPLE_NETWORK_PROTOCOL protocol provides services that
end_comment

begin_comment
comment|/// allow packets to be transmitted and received.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SIMPLE_NETWORK_PROTOCOL
block|{
comment|///
comment|/// Revision of the EFI_SIMPLE_NETWORK_PROTOCOL. All future revisions must
comment|/// be backwards compatible. If a future version is not backwards compatible
comment|/// it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_SIMPLE_NETWORK_START
name|Start
decl_stmt|;
name|EFI_SIMPLE_NETWORK_STOP
name|Stop
decl_stmt|;
name|EFI_SIMPLE_NETWORK_INITIALIZE
name|Initialize
decl_stmt|;
name|EFI_SIMPLE_NETWORK_RESET
name|Reset
decl_stmt|;
name|EFI_SIMPLE_NETWORK_SHUTDOWN
name|Shutdown
decl_stmt|;
name|EFI_SIMPLE_NETWORK_RECEIVE_FILTERS
name|ReceiveFilters
decl_stmt|;
name|EFI_SIMPLE_NETWORK_STATION_ADDRESS
name|StationAddress
decl_stmt|;
name|EFI_SIMPLE_NETWORK_STATISTICS
name|Statistics
decl_stmt|;
name|EFI_SIMPLE_NETWORK_MCAST_IP_TO_MAC
name|MCastIpToMac
decl_stmt|;
name|EFI_SIMPLE_NETWORK_NVDATA
name|NvData
decl_stmt|;
name|EFI_SIMPLE_NETWORK_GET_STATUS
name|GetStatus
decl_stmt|;
name|EFI_SIMPLE_NETWORK_TRANSMIT
name|Transmit
decl_stmt|;
name|EFI_SIMPLE_NETWORK_RECEIVE
name|Receive
decl_stmt|;
comment|///
comment|/// Event used with WaitForEvent() to wait for a packet to be received.
comment|///
name|EFI_EVENT
name|WaitForPacket
decl_stmt|;
comment|///
comment|/// Pointer to the EFI_SIMPLE_NETWORK_MODE data for the device.
comment|///
name|EFI_SIMPLE_NETWORK_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimpleNetworkProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

