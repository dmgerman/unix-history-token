begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The EFI_SD_MMC_PASS_THRU_PROTOCOL provides the ability to send SD/MMC Commands   to any SD/MMC device attached to the SD compatible pci host controller.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SD_MMC_PASS_THRU_H__
end_ifndef

begin_define
define|#
directive|define
name|__SD_MMC_PASS_THRU_H__
end_define

begin_define
define|#
directive|define
name|EFI_SD_MMC_PASS_THRU_PROTOCOL_GUID
define|\
value|{ \     0x716ef0d9, 0xff83, 0x4f69, {0x81, 0xe9, 0x51, 0x8b, 0xd3, 0x9a, 0x8e, 0x70 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SD_MMC_PASS_THRU_PROTOCOL
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SdMmcCommandTypeBc
block|,
comment|// Broadcast commands, no response
name|SdMmcCommandTypeBcr
block|,
comment|// Broadcast commands with response
name|SdMmcCommandTypeAc
block|,
comment|// Addressed(point-to-point) commands
name|SdMmcCommandTypeAdtc
comment|// Addressed(point-to-point) data transfer commands
block|}
name|EFI_SD_MMC_COMMAND_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SdMmcResponseTypeR1
block|,
name|SdMmcResponseTypeR1b
block|,
name|SdMmcResponseTypeR2
block|,
name|SdMmcResponseTypeR3
block|,
name|SdMmcResponseTypeR4
block|,
name|SdMmcResponseTypeR5
block|,
name|SdMmcResponseTypeR5b
block|,
name|SdMmcResponseTypeR6
block|,
name|SdMmcResponseTypeR7
block|}
name|EFI_SD_MMC_RESPONSE_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SD_MMC_COMMAND_BLOCK
block|{
name|UINT16
name|CommandIndex
decl_stmt|;
name|UINT32
name|CommandArgument
decl_stmt|;
name|UINT32
name|CommandType
decl_stmt|;
comment|// One of the EFI_SD_MMC_COMMAND_TYPE values
name|UINT32
name|ResponseType
decl_stmt|;
comment|// One of the EFI_SD_MMC_RESPONSE_TYPE values
block|}
name|EFI_SD_MMC_COMMAND_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SD_MMC_STATUS_BLOCK
block|{
name|UINT32
name|Resp0
decl_stmt|;
name|UINT32
name|Resp1
decl_stmt|;
name|UINT32
name|Resp2
decl_stmt|;
name|UINT32
name|Resp3
decl_stmt|;
block|}
name|EFI_SD_MMC_STATUS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SD_MMC_PASS_THRU_COMMAND_PACKET
block|{
name|UINT64
name|Timeout
decl_stmt|;
name|EFI_SD_MMC_COMMAND_BLOCK
modifier|*
name|SdMmcCmdBlk
decl_stmt|;
name|EFI_SD_MMC_STATUS_BLOCK
modifier|*
name|SdMmcStatusBlk
decl_stmt|;
name|VOID
modifier|*
name|InDataBuffer
decl_stmt|;
name|VOID
modifier|*
name|OutDataBuffer
decl_stmt|;
name|UINT32
name|InTransferLength
decl_stmt|;
name|UINT32
name|OutTransferLength
decl_stmt|;
name|EFI_STATUS
name|TransactionStatus
decl_stmt|;
block|}
name|EFI_SD_MMC_PASS_THRU_COMMAND_PACKET
typedef|;
end_typedef

begin_comment
comment|/**   Sends SD command to an SD card that is attached to the SD controller.    The PassThru() function sends the SD command specified by Packet to the SD card   specified by Slot.    If Packet is successfully sent to the SD card, then EFI_SUCCESS is returned.    If a device error occurs while sending the Packet, then EFI_DEVICE_ERROR is returned.    If Slot is not in a valid range for the SD controller, then EFI_INVALID_PARAMETER   is returned.    If Packet defines a data command but both InDataBuffer and OutDataBuffer are NULL,   EFI_INVALID_PARAMETER is returned.    @param[in]     This           A pointer to the EFI_SD_MMC_PASS_THRU_PROTOCOL instance.   @param[in]     Slot           The slot number of the SD card to send the command to.   @param[in,out] Packet         A pointer to the SD command data structure.   @param[in]     Event          If Event is NULL, blocking I/O is performed. If Event is                                 not NULL, then nonblocking I/O is performed, and Event                                 will be signaled when the Packet completes.    @retval EFI_SUCCESS           The SD Command Packet was sent by the host.   @retval EFI_DEVICE_ERROR      A device error occurred while attempting to send the SD                                 command Packet.   @retval EFI_INVALID_PARAMETER Packet, Slot, or the contents of the Packet is invalid.   @retval EFI_INVALID_PARAMETER Packet defines a data command but both InDataBuffer and                                 OutDataBuffer are NULL.   @retval EFI_NO_MEDIA          SD Device not present in the Slot.   @retval EFI_UNSUPPORTED       The command described by the SD Command Packet is not                                 supported by the host controller.   @retval EFI_BAD_BUFFER_SIZE   The InTransferLength or OutTransferLength exceeds the                                 limit supported by SD card ( i.e. if the number of bytes                                 exceed the Last LBA).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SD_MMC_PASS_THRU_PASSTHRU
function_decl|)
parameter_list|(
name|IN
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Slot
parameter_list|,
name|IN
name|OUT
name|EFI_SD_MMC_PASS_THRU_COMMAND_PACKET
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
comment|/**   Used to retrieve next slot numbers supported by the SD controller. The function   returns information about all available slots (populated or not-populated).    The GetNextSlot() function retrieves the next slot number on an SD controller.   If on input Slot is 0xFF, then the slot number of the first slot on the SD controller   is returned.    If Slot is a slot number that was returned on a previous call to GetNextSlot(), then   the slot number of the next slot on the SD controller is returned.    If Slot is not 0xFF and Slot was not returned on a previous call to GetNextSlot(),   EFI_INVALID_PARAMETER is returned.    If Slot is the slot number of the last slot on the SD controller, then EFI_NOT_FOUND   is returned.    @param[in]     This           A pointer to the EFI_SD_MMMC_PASS_THRU_PROTOCOL instance.   @param[in,out] Slot           On input, a pointer to a slot number on the SD controller.                                 On output, a pointer to the next slot number on the SD controller.                                 An input value of 0xFF retrieves the first slot number on the SD                                 controller.    @retval EFI_SUCCESS           The next slot number on the SD controller was returned in Slot.   @retval EFI_NOT_FOUND         There are no more slots on this SD controller.   @retval EFI_INVALID_PARAMETER Slot is not 0xFF and Slot was not returned on a previous call                                 to GetNextSlot().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SD_MMC_PASS_THRU_GET_NEXT_SLOT
function_decl|)
parameter_list|(
name|IN
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|Slot
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to allocate and build a device path node for an SD card on the SD controller.    The BuildDevicePath() function allocates and builds a single device node for the SD   card specified by Slot.    If the SD card specified by Slot is not present on the SD controller, then EFI_NOT_FOUND   is returned.    If DevicePath is NULL, then EFI_INVALID_PARAMETER is returned.    If there are not enough resources to allocate the device path node, then EFI_OUT_OF_RESOURCES   is returned.    Otherwise, DevicePath is allocated with the boot service AllocatePool(), the contents of   DevicePath are initialized to describe the SD card specified by Slot, and EFI_SUCCESS is   returned.    @param[in]     This           A pointer to the EFI_SD_MMMC_PASS_THRU_PROTOCOL instance.   @param[in]     Slot           Specifies the slot number of the SD card for which a device                                 path node is to be allocated and built.   @param[in,out] DevicePath     A pointer to a single device path node that describes the SD                                 card specified by Slot. This function is responsible for                                 allocating the buffer DevicePath with the boot service                                 AllocatePool(). It is the caller's responsibility to free                                 DevicePath when the caller is finished with DevicePath.    @retval EFI_SUCCESS           The device path node that describes the SD card specified by                                 Slot was allocated and returned in DevicePath.   @retval EFI_NOT_FOUND         The SD card specified by Slot does not exist on the SD controller.   @retval EFI_INVALID_PARAMETER DevicePath is NULL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to allocate DevicePath.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SD_MMC_PASS_THRU_BUILD_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Slot
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
comment|/**   This function retrieves an SD card slot number based on the input device path.    The GetSlotNumber() function retrieves slot number for the SD card specified by   the DevicePath node. If DevicePath is NULL, EFI_INVALID_PARAMETER is returned.    If DevicePath is not a device path node type that the SD Pass Thru driver supports,   EFI_UNSUPPORTED is returned.    @param[in]  This              A pointer to the EFI_SD_MMC_PASS_THRU_PROTOCOL instance.   @param[in]  DevicePath        A pointer to the device path node that describes a SD                                 card on the SD controller.   @param[out] Slot              On return, points to the slot number of an SD card on                                 the SD controller.    @retval EFI_SUCCESS           SD card slot number is returned in Slot.   @retval EFI_INVALID_PARAMETER Slot or DevicePath is NULL.   @retval EFI_UNSUPPORTED       DevicePath is not a device path node type that the SD                                 Pass Thru driver supports.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SD_MMC_PASS_THRU_GET_SLOT_NUMBER
function_decl|)
parameter_list|(
name|IN
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|Slot
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets an SD card that is connected to the SD controller.    The ResetDevice() function resets the SD card specified by Slot.    If this SD controller does not support a device reset operation, EFI_UNSUPPORTED is   returned.    If Slot is not in a valid slot number for this SD controller, EFI_INVALID_PARAMETER   is returned.    If the device reset operation is completed, EFI_SUCCESS is returned.    @param[in]  This              A pointer to the EFI_SD_MMC_PASS_THRU_PROTOCOL instance.   @param[in]  Slot              Specifies the slot number of the SD card to be reset.    @retval EFI_SUCCESS           The SD card specified by Slot was reset.   @retval EFI_UNSUPPORTED       The SD controller does not support a device reset operation.   @retval EFI_INVALID_PARAMETER Slot number is invalid.   @retval EFI_NO_MEDIA          SD Device not present in the Slot.   @retval EFI_DEVICE_ERROR      The reset command failed due to a device error  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SD_MMC_PASS_THRU_RESET_DEVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_SD_MMC_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Slot
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_SD_MMC_PASS_THRU_PROTOCOL
block|{
name|UINT32
name|IoAlign
decl_stmt|;
name|EFI_SD_MMC_PASS_THRU_PASSTHRU
name|PassThru
decl_stmt|;
name|EFI_SD_MMC_PASS_THRU_GET_NEXT_SLOT
name|GetNextSlot
decl_stmt|;
name|EFI_SD_MMC_PASS_THRU_BUILD_DEVICE_PATH
name|BuildDevicePath
decl_stmt|;
name|EFI_SD_MMC_PASS_THRU_GET_SLOT_NUMBER
name|GetSlotNumber
decl_stmt|;
name|EFI_SD_MMC_PASS_THRU_RESET_DEVICE
name|ResetDevice
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSdMmcPassThruProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

