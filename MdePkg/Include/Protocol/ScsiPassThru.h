begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SCSI Pass Through protocol as defined in EFI 1.1.   This protocol allows information about a SCSI channel to be collected,    and allows SCSI Request Packets to be sent to any SCSI devices on a SCSI   channel even if those devices are not boot devices. This protocol is attached    to the device handle of each SCSI channel in a system that the protocol    supports, and can be used for diagnostics. It may also be used to build    a Block I/O driver for SCSI hard drives and SCSI CD-ROM or DVD drives to   allow those devices to become boot devices.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCSI_PASS_THROUGH_H__
end_ifndef

begin_define
define|#
directive|define
name|__SCSI_PASS_THROUGH_H__
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_PASS_THRU_PROTOCOL_GUID
define|\
value|{ \     0xa59e8fcf, 0xbda0, 0x43bb, {0x90, 0xb1, 0xd3, 0x73, 0x2e, 0xca, 0xa8, 0x77 } \   }
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
name|_EFI_SCSI_PASS_THRU_PROTOCOL
name|EFI_SCSI_PASS_THRU_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SCSI_PASS_THRU_ATTRIBUTES_PHYSICAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_PASS_THRU_ATTRIBUTES_LOGICAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_PASS_THRU_ATTRIBUTES_NONBLOCKIO
value|0x0004
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
name|EFI_SCSI_STATUS_HOST_ADAPTER_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND
value|0x09
end_define

begin_comment
comment|// timeout when processing the command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_TIMEOUT
value|0x0b
end_define

begin_comment
comment|// timeout when waiting for the command processing
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_MESSAGE_REJECT
value|0x0d
end_define

begin_comment
comment|// a message reject was received when processing command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_BUS_RESET
value|0x0e
end_define

begin_comment
comment|// a bus reset was detected
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_PARITY_ERROR
value|0x0f
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED
value|0x10
end_define

begin_comment
comment|// the adapter failed in issuing request sense command
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT
value|0x11
end_define

begin_comment
comment|// selection timeout
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN
value|0x12
end_define

begin_comment
comment|// data overrun or data underrun
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_BUS_FREE
value|0x13
end_define

begin_comment
comment|// Unexepected bus free
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_PHASE_ERROR
value|0x14
end_define

begin_comment
comment|// Target bus phase sequence failure
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_HOST_ADAPTER_OTHER
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
name|EFI_SCSI_STATUS_TARGET_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_CHECK_CONDITION
value|0x02
end_define

begin_comment
comment|// check condition
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_CONDITION_MET
value|0x04
end_define

begin_comment
comment|// condition met
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_BUSY
value|0x08
end_define

begin_comment
comment|// busy
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_INTERMEDIATE
value|0x10
end_define

begin_comment
comment|// intermediate
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_INTERMEDIATE_CONDITION_MET
value|0x14
end_define

begin_comment
comment|// intermediate-condition met
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_RESERVATION_CONFLICT
value|0x18
end_define

begin_comment
comment|// reservation conflict
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_COMMOND_TERMINATED
value|0x22
end_define

begin_comment
comment|// command terminated
end_comment

begin_define
define|#
directive|define
name|EFI_SCSI_STATUS_TARGET_QUEUE_FULL
value|0x28
end_define

begin_comment
comment|// queue full
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
comment|/// controller and the SCSI device. Must be aligned to the boundary
comment|/// specified in the IoAlign field of the
comment|/// EFI_SCSI_PASS_THRU_MODE structure.
comment|///
name|VOID
modifier|*
name|DataBuffer
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
name|TransferLength
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
name|EFI_SCSI_PASS_THRU_SCSI_REQUEST_PACKET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A Null-terminated Unicode string that represents the printable name of the SCSI controller.
comment|///
name|CHAR16
modifier|*
name|ControllerName
decl_stmt|;
comment|///
comment|/// A Null-terminated Unicode string that represents the printable name of the SCSI channel.
comment|///
name|CHAR16
modifier|*
name|ChannelName
decl_stmt|;
comment|///
comment|/// The Target ID of the host adapter on the SCSI channel.
comment|///
name|UINT32
name|AdapterId
decl_stmt|;
comment|///
comment|/// Additional information on the attributes of the SCSI channel.
comment|///
name|UINT32
name|Attributes
decl_stmt|;
comment|///
comment|/// Supplies the alignment requirement for any buffer used in a data transfer.
comment|///
name|UINT32
name|IoAlign
decl_stmt|;
block|}
name|EFI_SCSI_PASS_THRU_MODE
typedef|;
end_typedef

begin_comment
comment|/**   Sends a SCSI Request Packet to a SCSI device that is attached to    the SCSI channel. This function supports both blocking I/O and    non-blocking I/O.  The blocking I/O functionality is required,    and the non-blocking I/O functionality is optional.    @param  This   Protocol instance pointer.   @param  Target The Target ID of the SCSI device to                  send the SCSI Request Packet.   @param  Lun    The LUN of the SCSI device to send the                  SCSI Request Packet.   @param  Packet A pointer to the SCSI Request Packet to send                  to the SCSI device specified by Target and Lun.   @param  Event  If non-blocking I/O is not supported then Event                  is ignored, and blocking I/O is performed.                  If Event is NULL, then blocking I/O is performed.                  If Event is not NULL and non blocking I/O is                  supported, then non-blocking I/O is performed,                  and Event will be signaled when the SCSI Request                  Packet completes    @retval EFI_SUCCESS               The SCSI Request Packet was sent by the host, and                                     TransferLength bytes were transferred to/from                                     DataBuffer. See HostAdapterStatus, TargetStatus,                                     SenseDataLength, and SenseData in that order                                     for additional status information.   @retval EFI_BAD_BUFFER_SIZE       The SCSI Request Packet was executed, but the                                     entire DataBuffer could not be transferred.                                     The actual number of bytes transferred is returned                                     in TransferLength. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.   @retval EFI_NOT_READY             The SCSI Request Packet could not be sent because                                     there are too many SCSI Request Packets already                                     queued.  The caller may retry again later.   @retval EFI_DEVICE_ERROR          A device error occurred while attempting to send                                     the SCSI Request Packet. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.   @retval EFI_INVALID_PARAMETER     Target, Lun, or the contents of ScsiRequestPacket                                     are invalid. The SCSI Request Packet was not sent,                                     so no additional status information is available.   @retval EFI_UNSUPPORTED           The command described by the SCSI Request Packet                                     is not supported by the host adapter. The SCSI                                     Request Packet was not sent, so no additional                                     status information is available.   @retval EFI_TIMEOUT               A timeout occurred while waiting for the SCSI                                     Request Packet to execute. See HostAdapterStatus,                                     TargetStatus, SenseDataLength, and SenseData in                                     that order for additional status information.                                      **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_PASSTHRU
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Target
parameter_list|,
name|IN
name|UINT64
name|Lun
parameter_list|,
name|IN
name|OUT
name|EFI_SCSI_PASS_THRU_SCSI_REQUEST_PACKET
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
comment|/**   Used to retrieve the list of legal Target IDs for SCSI devices    on a SCSI channel.    @param  This   Protocol instance pointer.   @param  Target On input, a pointer to the Target ID of a                  SCSI device present on the SCSI channel.                  On output, a pointer to the Target ID of                  the next SCSI device present on a SCSI channel.                  An input value of 0xFFFFFFFF retrieves the                  Target ID of the first SCSI device present on                  a SCSI channel.   @param  Lun    On input, a pointer to the LUN of a SCSI device                  present on the SCSI channel. On output, a pointer                  to the LUN of the next SCSI device present on a                  SCSI channel.    @retval EFI_SUCCESS           The Target ID of the next SCSI device on the SCSI                                 channel was returned in Target and Lun.   @retval EFI_NOT_FOUND         There are no more SCSI devices on this SCSI channel.   @retval EFI_INVALID_PARAMETER Target is not 0xFFFFFFFF, and Target and Lun were                                  not returned on a previous call to GetNextDevice().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_GET_NEXT_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|Target
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|Lun
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to allocate and build a device path node for a SCSI device    on a SCSI channel.    @param  This       Protocol instance pointer.   @param  Target     The Target ID of the SCSI device for which                      a device path node is to be allocated and built.   @param  Lun        The LUN of the SCSI device for which a device                      path node is to be allocated and built.   @param  DevicePath A pointer to a single device path node that                      describes the SCSI device specified by                      Target and Lun. This function is responsible                      for allocating the buffer DevicePath with the boot                      service AllocatePool().  It is the caller's                      responsibility to free DevicePath when the caller                      is finished with DevicePath.    @retval EFI_SUCCESS           The device path node that describes the SCSI device                                 specified by Target and Lun was allocated and                                 returned in DevicePath.   @retval EFI_NOT_FOUND         The SCSI devices specified by Target and Lun does                                 not exist on the SCSI channel.   @retval EFI_INVALID_PARAMETER DevicePath is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to allocate                                 DevicePath.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_BUILD_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Target
parameter_list|,
name|IN
name|UINT64
name|Lun
parameter_list|,
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to translate a device path node to a Target ID and LUN.    @param  This       Protocol instance pointer.   @param  DevicePath A pointer to the device path node that                      describes a SCSI device on the SCSI channel.   @param  Target     A pointer to the Target ID of a SCSI device                      on the SCSI channel.   @param  Lun        A pointer to the LUN of a SCSI device on                      the SCSI channel.    @retval EFI_SUCCESS           DevicePath was successfully translated to a                                 Target ID and LUN, and they were returned                                 in Target and Lun.   @retval EFI_INVALID_PARAMETER DevicePath is NULL.   @retval EFI_INVALID_PARAMETER Target is NULL.   @retval EFI_INVALID_PARAMETER Lun is NULL.   @retval EFI_UNSUPPORTED       This driver does not support the device path                                 node type in DevicePath.   @retval EFI_NOT_FOUND         A valid translation from DevicePath to a                                 Target ID and LUN does not exist.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_GET_TARGET_LUN
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|UINT32
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
comment|/**   Resets a SCSI channel.This operation resets all the    SCSI devices connected to the SCSI channel.    @param  This Protocol instance pointer.    @retval EFI_SUCCESS      The SCSI channel was reset.   @retval EFI_UNSUPPORTED  The SCSI channel does not support                            a channel reset operation.   @retval EFI_DEVICE_ERROR A device error occurred while                            attempting to reset the SCSI channel.   @retval EFI_TIMEOUT      A timeout occurred while attempting                            to reset the SCSI channel.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_RESET_CHANNEL
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets a SCSI device that is connected to a SCSI channel.    @param  This   Protocol instance pointer.   @param  Target The Target ID of the SCSI device to reset.   @param  Lun    The LUN of the SCSI device to reset.    @retval EFI_SUCCESS           The SCSI device specified by Target and                                 Lun was reset.   @retval EFI_UNSUPPORTED       The SCSI channel does not support a target                                 reset operation.   @retval EFI_INVALID_PARAMETER Target or Lun are invalid.   @retval EFI_DEVICE_ERROR      A device error occurred while attempting                                 to reset the SCSI device specified by Target                                 and Lun.   @retval EFI_TIMEOUT           A timeout occurred while attempting to reset                                 the SCSI device specified by Target and Lun.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SCSI_PASS_THRU_RESET_TARGET
function_decl|)
parameter_list|(
name|IN
name|EFI_SCSI_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Target
parameter_list|,
name|IN
name|UINT64
name|Lun
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_SCSI_PASS_THRU_PROTOCOL provides information about a SCSI channel and
end_comment

begin_comment
comment|/// the ability to send SCSI Request Packets to any SCSI device attached to that SCSI channel. The
end_comment

begin_comment
comment|/// information includes the Target ID of the host controller on the SCSI channel, the attributes of
end_comment

begin_comment
comment|/// the SCSI channel, the printable name for the SCSI controller, and the printable name of the
end_comment

begin_comment
comment|/// SCSI channel.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SCSI_PASS_THRU_PROTOCOL
block|{
comment|///
comment|/// A pointer to the EFI_SCSI_PASS_THRU_MODE data for this SCSI channel.
comment|///
name|EFI_SCSI_PASS_THRU_MODE
modifier|*
name|Mode
decl_stmt|;
name|EFI_SCSI_PASS_THRU_PASSTHRU
name|PassThru
decl_stmt|;
name|EFI_SCSI_PASS_THRU_GET_NEXT_DEVICE
name|GetNextDevice
decl_stmt|;
name|EFI_SCSI_PASS_THRU_BUILD_DEVICE_PATH
name|BuildDevicePath
decl_stmt|;
name|EFI_SCSI_PASS_THRU_GET_TARGET_LUN
name|GetTargetLun
decl_stmt|;
name|EFI_SCSI_PASS_THRU_RESET_CHANNEL
name|ResetChannel
decl_stmt|;
name|EFI_SCSI_PASS_THRU_RESET_TARGET
name|ResetTarget
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiScsiPassThruProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

