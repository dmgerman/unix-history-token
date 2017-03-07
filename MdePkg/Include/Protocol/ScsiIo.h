begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_SCSI_IO_PROTOCOL as defined in UEFI 2.0.   This protocol is used by code, typically drivers, running in the EFI boot    services environment to access SCSI devices. In particular, functions for    managing devices on SCSI buses are defined here.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SCSI_IO_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SCSI_IO_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_PROTOCOL_GUID
define|\
value|{ \     0x932f47e6, 0x2362, 0x4002, {0x80, 0x3e, 0x3c, 0xd5, 0x4b, 0x13, 0x8f, 0x85 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward reference for pure ANSI compatability
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_SCSI_IO_PROTOCOL
name|EFI_SCSI_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI Device type information, defined in the SCSI Primary Commands standard (e.g., SPC-4)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_DISK
value|0x00
end_define

begin_comment
comment|///< Disk device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_TAPE
value|0x01
end_define

begin_comment
comment|///< Tape device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_PRINTER
value|0x02
end_define

begin_comment
comment|///< Printer
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_PROCESSOR
value|0x03
end_define

begin_comment
comment|///< Processor
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_WORM
value|0x04
end_define

begin_comment
comment|///< Write-once read-multiple
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_CDROM
value|0x05
end_define

begin_comment
comment|///< CD or DVD device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_SCANNER
value|0x06
end_define

begin_comment
comment|///< Scanner device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_OPTICAL
value|0x07
end_define

begin_comment
comment|///< Optical memory device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_MEDIUMCHANGER
value|0x08
end_define

begin_comment
comment|///< Medium Changer device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_COMMUNICATION
value|0x09
end_define

begin_comment
comment|///< Communications device
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_A
value|0x0A
end_define

begin_comment
comment|///< Obsolete
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_B
value|0x0B
end_define

begin_comment
comment|///< Obsolete
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_RAID
value|0x0C
end_define

begin_comment
comment|///< Storage array controller device (e.g., RAID)
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_SES
value|0x0D
end_define

begin_comment
comment|///< Enclosure services device
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_RBC
value|0x0E
end_define

begin_comment
comment|///< Simplified direct-access device (e.g., magnetic disk)
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_OCRW
value|0x0F
end_define

begin_comment
comment|///< Optical card reader/writer device
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_BRIDGE
value|0x10
end_define

begin_comment
comment|///< Bridge Controller Commands
end_comment

begin_define
define|#
directive|define
name|MFI_SCSI_IO_TYPE_OSD
value|0x11
end_define

begin_comment
comment|///< Object-based Storage Device
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_RESERVED_LOW
value|0x12
end_define

begin_comment
comment|///< Reserved (low)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_RESERVED_HIGH
value|0x1E
end_define

begin_comment
comment|///< Reserved (high)
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_TYPE_UNKNOWN
value|0x1F
end_define

begin_comment
comment|///< Unknown no device type
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI Data Direction definition
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_DATA_DIRECTION_READ
value|0
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_DATA_DIRECTION_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_DATA_DIRECTION_BIDIRECTIONAL
value|2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI Host Adapter Status definition
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND
value|0x09
end_define

begin_comment
comment|///< timeout when processing the command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT
value|0x0b
end_define

begin_comment
comment|///< timeout when waiting for the command processing
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_MESSAGE_REJECT
value|0x0d
end_define

begin_comment
comment|///< a message reject was received when processing command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_RESET
value|0x0e
end_define

begin_comment
comment|///< a bus reset was detected
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_PARITY_ERROR
value|0x0f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED
value|0x10
end_define

begin_comment
comment|///< the adapter failed in issuing request sense command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT
value|0x11
end_define

begin_comment
comment|///< selection timeout
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN
value|0x12
end_define

begin_comment
comment|///< data overrun or data underrun
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_FREE
value|0x13
end_define

begin_comment
comment|///< Unexepected bus free
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|///< Target bus phase sequence failure
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_HOST_ADAPTER_OTHER
value|0x7f
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SCSI Target Status definition
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_CHECK_CONDITION
value|0x02
end_define

begin_comment
comment|///< check condition
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_CONDITION_MET
value|0x04
end_define

begin_comment
comment|///< condition met
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_BUSY
value|0x08
end_define

begin_comment
comment|///< busy
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE
value|0x10
end_define

begin_comment
comment|///< intermediate
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE_CONDITION_MET
value|0x14
end_define

begin_comment
comment|///< intermediate-condition met
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_RESERVATION_CONFLICT
value|0x18
end_define

begin_comment
comment|///< reservation conflict
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_COMMOND_TERMINATED
value|0x22
end_define

begin_comment
comment|///< command terminated
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_IO_STATUS_TARGET_QUEUE_FULL
value|0x28
end_define

begin_comment
comment|///< queue full
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The timeout, in 100 ns units, to use for the execution of this SCSI
comment|/// Request Packet. A Timeout value of 0 means that this function
comment|/// will wait indefinitely for the SCSI Request Packet to execute. If
comment|/// Timeout is greater than zero, then this function will return
comment|/// EFI_TIMEOUT if the time required to execute the SCSI Request
comment|/// Packet is greater than Timeout.
comment|///
name|UINT64
name|Timeout
decl_stmt|;
comment|///
comment|/// A pointer to the data buffer to transfer between the SCSI
comment|/// controller and the SCSI device for SCSI READ command
comment|///
name|VOID
modifier|*
name|InDataBuffer
decl_stmt|;
comment|///
comment|/// A pointer to the data buffer to transfer between the SCSI
comment|/// controller and the SCSI device for SCSI WRITE command.
comment|///
name|VOID
modifier|*
name|OutDataBuffer
decl_stmt|;
comment|///
comment|/// A pointer to the sense data that was generated by the execution of
comment|/// the SCSI Request Packet.
comment|///
name|VOID
modifier|*
name|SenseData
decl_stmt|;
comment|///
comment|/// A pointer to buffer that contains the Command Data Block to
comment|/// send to the SCSI device.
comment|///
name|VOID
modifier|*
name|Cdb
decl_stmt|;
comment|///
comment|/// On Input, the size, in bytes, of InDataBuffer. On output, the
comment|/// number of bytes transferred between the SCSI controller and the SCSI device.
comment|///
name|UINT32
name|InTransferLength
decl_stmt|;
comment|///
comment|/// On Input, the size, in bytes of OutDataBuffer. On Output, the
comment|/// Number of bytes transferred between SCSI Controller and the SCSI device.
comment|///
name|UINT32
name|OutTransferLength
decl_stmt|;
comment|///
comment|/// The length, in bytes, of the buffer Cdb. The standard values are
comment|/// 6, 10, 12, and 16, but other values are possible if a variable length CDB is used.
comment|///
name|UINT8
name|CdbLength
decl_stmt|;
comment|///
comment|/// The direction of the data transfer. 0 for reads, 1 for writes. A
comment|/// value of 2 is Reserved for Bi-Directional SCSI commands.
comment|///
name|UINT8
name|DataDirection
decl_stmt|;
comment|///
comment|/// The status of the SCSI Host Controller that produces the SCSI
comment|/// bus where the SCSI device attached when the SCSI Request
comment|/// Packet was executed on the SCSI Controller.
comment|///
name|UINT8
name|HostAdapterStatus
decl_stmt|;
comment|///
comment|/// The status returned by the SCSI device when the SCSI Request
comment|/// Packet was executed.
comment|///
name|UINT8
name|TargetStatus
decl_stmt|;
comment|///
comment|/// On input, the length in bytes of the SenseData buffer. On
comment|/// output, the number of bytes written to the SenseData buffer.
comment|///
name|UINT8
name|SenseDataLength
decl_stmt|;
block|}
name|EFI_SCSI_IO_SCSI_REQUEST_PACKET
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves the device type information of the SCSI Controller.    @param  This       Protocol instance pointer.   @param  DeviceType A pointer to the device type information                      retrieved from the SCSI Controller.    @retval EFI_SUCCESS           Retrieved the device type information successfully.   @retval EFI_INVALID_PARAMETER The DeviceType is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|DeviceType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the device location in the SCSI channel.    @param  This   Protocol instance pointer.   @param  Target A pointer to the Target ID of a SCSI device                  on the SCSI channel.   @param  Lun    A pointer to the LUN of the SCSI device on                  the SCSI channel.    @retval EFI_SUCCESS           Retrieves the device location successfully.   @retval EFI_INVALID_PARAMETER The Target or Lun is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
modifier|*
name|Target
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Lun
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets the SCSI Bus that the SCSI Controller is attached to.    @param  This Protocol instance pointer.    @retval EFI_SUCCESS      The SCSI bus is reset successfully.   @retval EFI_DEVICE_ERROR Errors encountered when resetting the SCSI bus.   @retval EFI_UNSUPPORTED  The bus reset operation is not supported by the                            SCSI Host Controller.   @retval EFI_TIMEOUT      A timeout occurred while attempting to reset                             the SCSI bus.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_IO_PROTOCOL_RESET_BUS
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets the SCSI Controller that the device handle specifies.    @param  This Protocol instance pointer.    @retval EFI_SUCCESS      Reset the SCSI controller successfully.   @retval EFI_DEVICE_ERROR Errors were encountered when resetting the                            SCSI Controller.   @retval EFI_UNSUPPORTED  The SCSI bus does not support a device                            reset operation.   @retval EFI_TIMEOUT      A timeout occurred while attempting to                            reset the SCSI Controller.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_IO_PROTOCOL_RESET_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sends a SCSI Request Packet to the SCSI Controller for execution.    @param  This    Protocol instance pointer.   @param  Packet  The SCSI request packet to send to the SCSI                   Controller specified by the device handle.   @param  Event   If the SCSI bus to which the SCSI device is attached                   does not support non-blocking I/O, then Event is                   ignored, and blocking I/O is performed.                   If Event is NULL, then blocking I/O is performed.                   If Event is not NULL and non-blocking I/O is                   supported, then non-blocking I/O is performed,                   and Event will be signaled when the SCSI Request                   Packet completes.    @retval EFI_SUCCESS               The SCSI Request Packet was sent by the host                                     successfully, and TransferLength bytes were                                     transferred to/from DataBuffer. See                                     HostAdapterStatus, TargetStatus,                                     SenseDataLength, and SenseData in that order                                     for additional status information.   @retval EFI_BAD_BUFFER_SIZE       The SCSI Request Packet was executed,                                     but the entire DataBuffer could not be transferred.                                     The actual number of bytes transferred is returned                                     in TransferLength. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.   @retval EFI_NOT_READY             The SCSI Request Packet could not be sent because                                     there are too many SCSI Command Packets already                                     queued.The caller may retry again later.   @retval EFI_DEVICE_ERROR          A device error occurred while attempting to send                                     the SCSI Request Packet. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.   @retval EFI_INVALID_PARAMETER     The contents of CommandPacket are invalid.                                     The SCSI Request Packet was not sent, so no                                     additional status information is available.   @retval EFI_UNSUPPORTED           The command described by the SCSI Request Packet                                     is not supported by the SCSI initiator(i.e., SCSI                                     Host Controller). The SCSI Request Packet was not                                     sent, so no additional status information is                                     available.   @retval EFI_TIMEOUT               A timeout occurred while waiting for the SCSI                                     Request Packet to execute. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_IO_PROTOCOL_EXEC_SCSI_COMMAND
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_SCSI_IO_SCSI_REQUEST_PACKET
modifier|*
name|Packet
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides services to manage and communicate with SCSI devices.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SCSI_IO_PROTOCOL
block|{
name|EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE
name|GetDeviceType
decl_stmt|;
name|EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION
name|GetDeviceLocation
decl_stmt|;
name|EFI_SCSI_IO_PROTOCOL_RESET_BUS
name|ResetBus
decl_stmt|;
name|EFI_SCSI_IO_PROTOCOL_RESET_DEVICE
name|ResetDevice
decl_stmt|;
name|EFI_SCSI_IO_PROTOCOL_EXEC_SCSI_COMMAND
name|ExecuteScsiCommand
decl_stmt|;
comment|///
comment|/// Supplies the alignment requirement for any buffer used in a data transfer.
comment|/// IoAlign values of 0 and 1 mean that the buffer can be placed anywhere in memory.
comment|/// Otherwise, IoAlign must be a power of 2, and the requirement is that the
comment|/// start address of a buffer must be evenly divisible by IoAlign with no remainder.
comment|///
name|UINT32
name|IoAlign
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiScsiIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

