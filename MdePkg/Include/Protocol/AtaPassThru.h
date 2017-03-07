begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The EFI_ATA_PASS_THRU_PROTOCOL provides information about an ATA controller and the ability   to send ATA Command Blocks to any ATA device attached to that ATA controller. The information   includes the attributes of the ATA controller.    Copyright (c) 2009 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATA_PASS_THROUGH_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATA_PASS_THROUGH_H__
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_GUID
define|\
value|{ \     0x1d3de7f0, 0x807, 0x424f, {0xaa, 0x69, 0x11, 0xa5, 0x4e, 0x19, 0xa4, 0x6f } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ATA_PASS_THRU_PROTOCOL
name|EFI_ATA_PASS_THRU_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Attributes
decl_stmt|;
name|UINT32
name|IoAlign
decl_stmt|;
block|}
name|EFI_ATA_PASS_THRU_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this bit is set, then the EFI_ATA_PASS_THRU_PROTOCOL interface is for physical
end_comment

begin_comment
comment|/// devices on the ATA controller.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_ATTRIBUTES_PHYSICAL
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this bit is set, then the EFI_ATA_PASS_THRU_PROTOCOL interface is for logical
end_comment

begin_comment
comment|/// devices on the ATA controller.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_ATTRIBUTES_LOGICAL
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this bit is set, then the EFI_ATA_PASS_THRU_PROTOCOL interface supports non blocking
end_comment

begin_comment
comment|/// I/O. Every EFI_ATA_PASS_THRU_PROTOCOL must support blocking I/O. The support of non-blocking
end_comment

begin_comment
comment|/// I/O is optional.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_ATTRIBUTES_NONBLOCKIO
value|0x0004
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_ATA_COMMAND_BLOCK
block|{
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|AtaCommand
decl_stmt|;
name|UINT8
name|AtaFeatures
decl_stmt|;
name|UINT8
name|AtaSectorNumber
decl_stmt|;
name|UINT8
name|AtaCylinderLow
decl_stmt|;
name|UINT8
name|AtaCylinderHigh
decl_stmt|;
name|UINT8
name|AtaDeviceHead
decl_stmt|;
name|UINT8
name|AtaSectorNumberExp
decl_stmt|;
name|UINT8
name|AtaCylinderLowExp
decl_stmt|;
name|UINT8
name|AtaCylinderHighExp
decl_stmt|;
name|UINT8
name|AtaFeaturesExp
decl_stmt|;
name|UINT8
name|AtaSectorCount
decl_stmt|;
name|UINT8
name|AtaSectorCountExp
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_ATA_COMMAND_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_ATA_STATUS_BLOCK
block|{
name|UINT8
name|Reserved1
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|AtaStatus
decl_stmt|;
name|UINT8
name|AtaError
decl_stmt|;
name|UINT8
name|AtaSectorNumber
decl_stmt|;
name|UINT8
name|AtaCylinderLow
decl_stmt|;
name|UINT8
name|AtaCylinderHigh
decl_stmt|;
name|UINT8
name|AtaDeviceHead
decl_stmt|;
name|UINT8
name|AtaSectorNumberExp
decl_stmt|;
name|UINT8
name|AtaCylinderLowExp
decl_stmt|;
name|UINT8
name|AtaCylinderHighExp
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
name|UINT8
name|AtaSectorCount
decl_stmt|;
name|UINT8
name|AtaSectorCountExp
decl_stmt|;
name|UINT8
name|Reserved3
index|[
literal|6
index|]
decl_stmt|;
block|}
name|EFI_ATA_STATUS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|EFI_ATA_PASS_THRU_CMD_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_ATA_HARDWARE_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_ATA_SOFTWARE_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_ATA_NON_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_PIO_DATA_IN
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_PIO_DATA_OUT
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_DMA
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_DMA_QUEUED
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_DEVICE_DIAGNOSTIC
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_DEVICE_RESET
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_UDMA_DATA_IN
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_UDMA_DATA_OUT
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_FPDMA
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_PROTOCOL_RETURN_RESPONSE
value|0xFF
end_define

begin_typedef
typedef|typedef
name|UINT8
name|EFI_ATA_PASS_THRU_LENGTH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_BYTES
value|0x80
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_NO_DATA_TRANSFER
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_FEATURES
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_SECTOR_COUNT
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_TPSIU
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_ATA_PASS_THRU_LENGTH_COUNT
value|0x0F
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A pointer to the sense data that was generated by the execution of the ATA
comment|/// command. It must be aligned to the boundary specified in the IoAlign field
comment|/// in the EFI_ATA_PASS_THRU_MODE structure.
comment|///
name|EFI_ATA_STATUS_BLOCK
modifier|*
name|Asb
decl_stmt|;
comment|///
comment|/// A pointer to buffer that contains the Command Data Block to send to the ATA
comment|/// device specified by Port and PortMultiplierPort.
comment|///
name|EFI_ATA_COMMAND_BLOCK
modifier|*
name|Acb
decl_stmt|;
comment|///
comment|/// The timeout, in 100 ns units, to use for the execution of this ATA command.
comment|/// A Timeout value of 0 means that this function will wait indefinitely for the
comment|/// ATA command to execute. If Timeout is greater than zero, then this function
comment|/// will return EFI_TIMEOUT if the time required to execute the ATA command is
comment|/// greater than Timeout.
comment|///
name|UINT64
name|Timeout
decl_stmt|;
comment|///
comment|/// A pointer to the data buffer to transfer between the ATA controller and the
comment|/// ATA device for read and bidirectional commands. For all write and non data
comment|/// commands where InTransferLength is 0 this field is optional and may be NULL.
comment|/// If this field is not NULL, then it must be aligned on the boundary specified
comment|/// by the IoAlign field in the EFI_ATA_PASS_THRU_MODE structure.
comment|///
name|VOID
modifier|*
name|InDataBuffer
decl_stmt|;
comment|///
comment|/// A pointer to the data buffer to transfer between the ATA controller and the
comment|/// ATA device for write or bidirectional commands. For all read and non data
comment|/// commands where OutTransferLength is 0 this field is optional and may be NULL.
comment|/// If this field is not NULL, then it must be aligned on the boundary specified
comment|/// by the IoAlign field in the EFI_ATA_PASS_THRU_MODE structure.
comment|///
name|VOID
modifier|*
name|OutDataBuffer
decl_stmt|;
comment|///
comment|/// On input, the size, in bytes, of InDataBuffer. On output, the number of bytes
comment|/// transferred between the ATA controller and the ATA device. If InTransferLength
comment|/// is larger than the ATA controller can handle, no data will be transferred,
comment|/// InTransferLength will be updated to contain the number of bytes that the ATA
comment|/// controller is able to transfer, and EFI_BAD_BUFFER_SIZE will be returned.
comment|///
name|UINT32
name|InTransferLength
decl_stmt|;
comment|///
comment|/// On Input, the size, in bytes of OutDataBuffer. On Output, the Number of bytes
comment|/// transferred between ATA Controller and the ATA device. If OutTransferLength is
comment|/// larger than the ATA controller can handle, no data will be transferred,
comment|/// OutTransferLength will be updated to contain the number of bytes that the ATA
comment|/// controller is able to transfer, and EFI_BAD_BUFFER_SIZE will be returned.
comment|///
name|UINT32
name|OutTransferLength
decl_stmt|;
comment|///
comment|/// Specifies the protocol used when the ATA device executes the command.
comment|///
name|EFI_ATA_PASS_THRU_CMD_PROTOCOL
name|Protocol
decl_stmt|;
comment|///
comment|/// Specifies the way in which the ATA command length is encoded.
comment|///
name|EFI_ATA_PASS_THRU_LENGTH
name|Length
decl_stmt|;
block|}
name|EFI_ATA_PASS_THRU_COMMAND_PACKET
typedef|;
end_typedef

begin_comment
comment|/**   Sends an ATA command to an ATA device that is attached to the ATA controller. This function   supports both blocking I/O and non-blocking I/O. The blocking I/O functionality is required,   and the non-blocking I/O functionality is optional.    @param[in]     This                A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.    @param[in]     Port                The port number of the ATA device to send the command.    @param[in]     PortMultiplierPort  The port multiplier port number of the ATA device to send the command.                                      If there is no port multiplier, then specify 0xFFFF.   @param[in,out] Packet              A pointer to the ATA command to send to the ATA device specified by Port                                      and PortMultiplierPort.   @param[in]     Event               If non-blocking I/O is not supported then Event is ignored, and blocking                                      I/O is performed. If Event is NULL, then blocking I/O is performed. If                                      Event is not NULL and non blocking I/O is supported, then non-blocking                                      I/O is performed, and Event will be signaled when the ATA command completes.    @retval EFI_SUCCESS                The ATA command was sent by the host. For bi-directional commands,                                       InTransferLength bytes were transferred from InDataBuffer. For write and                                      bi-directional commands, OutTransferLength bytes were transferred by OutDataBuffer.   @retval EFI_BAD_BUFFER_SIZE        The ATA command was not executed. The number of bytes that could be transferred                                      is returned in InTransferLength. For write and bi-directional commands,                                       OutTransferLength bytes were transferred by OutDataBuffer.   @retval EFI_NOT_READY              The ATA command could not be sent because there are too many ATA commands                                      already queued. The caller may retry again later.   @retval EFI_DEVICE_ERROR           A device error occurred while attempting to send the ATA command.   @retval EFI_INVALID_PARAMETER      Port, PortMultiplierPort, or the contents of Acb are invalid. The ATA                                      command was not sent, so no additional status information is available.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_PASSTHRU
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Port
parameter_list|,
name|IN
name|UINT16
name|PortMultiplierPort
parameter_list|,
name|IN
name|OUT
name|EFI_ATA_PASS_THRU_COMMAND_PACKET
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
comment|/**   Used to retrieve the list of legal port numbers for ATA devices on an ATA controller.   These can either be the list of ports where ATA devices are actually present or the   list of legal port numbers for the ATA controller. Regardless, the caller of this   function must probe the port number returned to see if an ATA device is actually   present at that location on the ATA controller.    The GetNextPort() function retrieves the port number on an ATA controller. If on input   Port is 0xFFFF, then the port number of the first port on the ATA controller is returned   in Port and EFI_SUCCESS is returned.    If Port is a port number that was returned on a previous call to GetNextPort(), then the   port number of the next port on the ATA controller is returned in Port, and EFI_SUCCESS   is returned. If Port is not 0xFFFF and Port was not returned on a previous call to   GetNextPort(), then EFI_INVALID_PARAMETER is returned.    If Port is the port number of the last port on the ATA controller, then EFI_NOT_FOUND is   returned.    @param[in]     This           A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.    @param[in,out] Port           On input, a pointer to the port number on the ATA controller.                                 On output, a pointer to the next port number on the ATA                                 controller. An input value of 0xFFFF retrieves the first port                                 number on the ATA controller.    @retval EFI_SUCCESS           The next port number on the ATA controller was returned in Port.   @retval EFI_NOT_FOUND         There are no more ports on this ATA controller.   @retval EFI_INVALID_PARAMETER Port is not 0xFFFF and Port was not returned on a previous call                                 to GetNextPort().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_GET_NEXT_PORT
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT16
modifier|*
name|Port
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to retrieve the list of legal port multiplier port numbers for ATA devices on a port of an ATA    controller. These can either be the list of port multiplier ports where ATA devices are actually    present on port or the list of legal port multiplier ports on that port. Regardless, the caller of this    function must probe the port number and port multiplier port number returned to see if an ATA    device is actually present.    The GetNextDevice() function retrieves the port multiplier port number of an ATA device    present on a port of an ATA controller.      If PortMultiplierPort points to a port multiplier port number value that was returned on a    previous call to GetNextDevice(), then the port multiplier port number of the next ATA device   on the port of the ATA controller is returned in PortMultiplierPort, and EFI_SUCCESS is   returned.      If PortMultiplierPort points to 0xFFFF, then the port multiplier port number of the first    ATA device on port of the ATA controller is returned in PortMultiplierPort and    EFI_SUCCESS is returned.      If PortMultiplierPort is not 0xFFFF and the value pointed to by PortMultiplierPort   was not returned on a previous call to GetNextDevice(), then EFI_INVALID_PARAMETER   is returned.      If PortMultiplierPort is the port multiplier port number of the last ATA device on the port of    the ATA controller, then EFI_NOT_FOUND is returned.    @param[in]     This                A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.   @param[in]     Port                The port number present on the ATA controller.   @param[in,out] PortMultiplierPort  On input, a pointer to the port multiplier port number of an                                      ATA device present on the ATA controller.                                       If on input a PortMultiplierPort of 0xFFFF is specified,                                       then the port multiplier port number of the first ATA device                                      is returned. On output, a pointer to the port multiplier port                                      number of the next ATA device present on an ATA controller.    @retval EFI_SUCCESS                The port multiplier port number of the next ATA device on the port                                      of the ATA controller was returned in PortMultiplierPort.   @retval EFI_NOT_FOUND              There are no more ATA devices on this port of the ATA controller.   @retval EFI_INVALID_PARAMETER      PortMultiplierPort is not 0xFFFF, and PortMultiplierPort was not                                      returned on a previous call to GetNextDevice().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_GET_NEXT_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Port
parameter_list|,
name|IN
name|OUT
name|UINT16
modifier|*
name|PortMultiplierPort
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to allocate and build a device path node for an ATA device on an ATA controller.    The BuildDevicePath() function allocates and builds a single device node for the ATA   device specified by Port and PortMultiplierPort. If the ATA device specified by Port and   PortMultiplierPort is not present on the ATA controller, then EFI_NOT_FOUND is returned.   If DevicePath is NULL, then EFI_INVALID_PARAMETER is returned. If there are not enough   resources to allocate the device path node, then EFI_OUT_OF_RESOURCES is returned.    Otherwise, DevicePath is allocated with the boot service AllocatePool(), the contents of   DevicePath are initialized to describe the ATA device specified by Port and PortMultiplierPort,   and EFI_SUCCESS is returned.    @param[in]     This                A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.   @param[in]     Port                Port specifies the port number of the ATA device for which a                                      device path node is to be allocated and built.   @param[in]     PortMultiplierPort  The port multiplier port number of the ATA device for which a                                      device path node is to be allocated and built. If there is no                                      port multiplier, then specify 0xFFFF.   @param[in,out] DevicePath          A pointer to a single device path node that describes the ATA                                      device specified by Port and PortMultiplierPort. This function                                      is responsible for allocating the buffer DevicePath with the                                      boot service AllocatePool(). It is the caller's responsibility                                      to free DevicePath when the caller is finished with DevicePath.   @retval EFI_SUCCESS                The device path node that describes the ATA device specified by                                      Port and PortMultiplierPort was allocated and returned in DevicePath.   @retval EFI_NOT_FOUND              The ATA device specified by Port and PortMultiplierPort does not                                      exist on the ATA controller.   @retval EFI_INVALID_PARAMETER      DevicePath is NULL.   @retval EFI_OUT_OF_RESOURCES       There are not enough resources to allocate DevicePath.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_BUILD_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Port
parameter_list|,
name|IN
name|UINT16
name|PortMultiplierPort
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
comment|/**   Used to translate a device path node to a port number and port multiplier port number.    The GetDevice() function determines the port and port multiplier port number associated with   the ATA device described by DevicePath. If DevicePath is a device path node type that the   ATA Pass Thru driver supports, then the ATA Pass Thru driver will attempt to translate the contents    DevicePath into a port number and port multiplier port number.    If this translation is successful, then that port number and port multiplier port number are returned   in Port and PortMultiplierPort, and EFI_SUCCESS is returned.    If DevicePath, Port, or PortMultiplierPort are NULL, then EFI_INVALID_PARAMETER is returned.    If DevicePath is not a device path node type that the ATA Pass Thru driver supports, then    EFI_UNSUPPORTED is returned.    If DevicePath is a device path node type that the ATA Pass Thru driver supports, but there is not    a valid translation from DevicePath to a port number and port multiplier port number, then    EFI_NOT_FOUND is returned.    @param[in]  This                A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.   @param[in]  DevicePath          A pointer to the device path node that describes an ATA device on the                                   ATA controller.   @param[out] Port                On return, points to the port number of an ATA device on the ATA controller.   @param[out] PortMultiplierPort  On return, points to the port multiplier port number of an ATA device                                   on the ATA controller.    @retval EFI_SUCCESS             DevicePath was successfully translated to a port number and port multiplier                                   port number, and they were returned in Port and PortMultiplierPort.   @retval EFI_INVALID_PARAMETER   DevicePath is NULL.   @retval EFI_INVALID_PARAMETER   Port is NULL.   @retval EFI_INVALID_PARAMETER   PortMultiplierPort is NULL.   @retval EFI_UNSUPPORTED         This driver does not support the device path node type in DevicePath.   @retval EFI_NOT_FOUND           A valid translation from DevicePath to a port number and port multiplier                                   port number does not exist. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_GET_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Port
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|PortMultiplierPort
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets a specific port on the ATA controller. This operation also resets all the ATA devices   connected to the port.    The ResetChannel() function resets an a specific port on an ATA controller. This operation   resets all the ATA devices connected to that port. If this ATA controller does not support   a reset port operation, then EFI_UNSUPPORTED is returned.    If a device error occurs while executing that port reset operation, then EFI_DEVICE_ERROR is   returned.    If a timeout occurs during the execution of the port reset operation, then EFI_TIMEOUT is returned.    If the port reset operation is completed, then EFI_SUCCESS is returned.    @param[in]  This          A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.   @param[in]  Port          The port number on the ATA controller.    @retval EFI_SUCCESS       The ATA controller port was reset.   @retval EFI_UNSUPPORTED   The ATA controller does not support a port reset operation.   @retval EFI_DEVICE_ERROR  A device error occurred while attempting to reset the ATA port.   @retval EFI_TIMEOUT       A timeout occurred while attempting to reset the ATA port.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_RESET_PORT
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Port
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets an ATA device that is connected to an ATA controller.    The ResetDevice() function resets the ATA device specified by Port and PortMultiplierPort.   If this ATA controller does not support a device reset operation, then EFI_UNSUPPORTED is   returned.    If Port or PortMultiplierPort are not in a valid range for this ATA controller, then    EFI_INVALID_PARAMETER is returned.    If a device error occurs while executing that device reset operation, then EFI_DEVICE_ERROR   is returned.    If a timeout occurs during the execution of the device reset operation, then EFI_TIMEOUT is   returned.    If the device reset operation is completed, then EFI_SUCCESS is returned.    @param[in] This                A pointer to the EFI_ATA_PASS_THRU_PROTOCOL instance.   @param[in] Port                Port represents the port number of the ATA device to be reset.   @param[in] PortMultiplierPort  The port multiplier port number of the ATA device to reset.                                  If there is no port multiplier, then specify 0xFFFF.   @retval EFI_SUCCESS            The ATA device specified by Port and PortMultiplierPort was reset.   @retval EFI_UNSUPPORTED        The ATA controller does not support a device reset operation.   @retval EFI_INVALID_PARAMETER  Port or PortMultiplierPort are invalid.   @retval EFI_DEVICE_ERROR       A device error occurred while attempting to reset the ATA device                                  specified by Port and PortMultiplierPort.   @retval EFI_TIMEOUT            A timeout occurred while attempting to reset the ATA device                                  specified by Port and PortMultiplierPort.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ATA_PASS_THRU_RESET_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_ATA_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Port
parameter_list|,
name|IN
name|UINT16
name|PortMultiplierPort
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_ATA_PASS_THRU_PROTOCOL
block|{
name|EFI_ATA_PASS_THRU_MODE
modifier|*
name|Mode
decl_stmt|;
name|EFI_ATA_PASS_THRU_PASSTHRU
name|PassThru
decl_stmt|;
name|EFI_ATA_PASS_THRU_GET_NEXT_PORT
name|GetNextPort
decl_stmt|;
name|EFI_ATA_PASS_THRU_GET_NEXT_DEVICE
name|GetNextDevice
decl_stmt|;
name|EFI_ATA_PASS_THRU_BUILD_DEVICE_PATH
name|BuildDevicePath
decl_stmt|;
name|EFI_ATA_PASS_THRU_GET_DEVICE
name|GetDevice
decl_stmt|;
name|EFI_ATA_PASS_THRU_RESET_PORT
name|ResetPort
decl_stmt|;
name|EFI_ATA_PASS_THRU_RESET_DEVICE
name|ResetDevice
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiAtaPassThruProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

