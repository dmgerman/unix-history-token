begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This protocol provides services that allow NVM Express commands to be sent to an   NVM Express controller or to a specific namespace in a NVM Express controller.   This protocol interface is optimized for storage.    Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UEFI_NVM_EXPRESS_PASS_THRU_H_
end_ifndef

begin_define
define|#
directive|define
name|_UEFI_NVM_EXPRESS_PASS_THRU_H_
end_define

begin_define
define|#
directive|define
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL_GUID
define|\
value|{ \     0x52c78312, 0x8edc, 0x4233, { 0x98, 0xf2, 0x1a, 0x1a, 0xa5, 0xe3, 0x88, 0xa5 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
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
name|UINT32
name|NvmeVersion
decl_stmt|;
block|}
name|EFI_NVM_EXPRESS_PASS_THRU_MODE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// If this bit is set, then the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL interface is
end_comment

begin_comment
comment|// for directly addressable namespaces.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NVM_EXPRESS_PASS_THRU_ATTRIBUTES_PHYSICAL
value|0x0001
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// If this bit is set, then the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL interface is
end_comment

begin_comment
comment|// for a single volume logical namespace comprised of multiple namespaces.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NVM_EXPRESS_PASS_THRU_ATTRIBUTES_LOGICAL
value|0x0002
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// If this bit is set, then the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL interface
end_comment

begin_comment
comment|// supports non-blocking I/O.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NVM_EXPRESS_PASS_THRU_ATTRIBUTES_NONBLOCKIO
value|0x0004
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// If this bit is set, then the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL interface
end_comment

begin_comment
comment|// supports NVM command set.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NVM_EXPRESS_PASS_THRU_ATTRIBUTES_CMD_SET_NVM
value|0x0008
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// FusedOperation
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NORMAL_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|FUSED_FIRST_CMD
value|0x01
end_define

begin_define
define|#
directive|define
name|FUSED_SECOND_CMD
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Opcode
range|:
literal|8
decl_stmt|;
name|UINT32
name|FusedOperation
range|:
literal|2
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|22
decl_stmt|;
block|}
name|NVME_CDW0
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CDW2_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|CDW3_VALID
value|0x02
end_define

begin_define
define|#
directive|define
name|CDW10_VALID
value|0x04
end_define

begin_define
define|#
directive|define
name|CDW11_VALID
value|0x08
end_define

begin_define
define|#
directive|define
name|CDW12_VALID
value|0x10
end_define

begin_define
define|#
directive|define
name|CDW13_VALID
value|0x20
end_define

begin_define
define|#
directive|define
name|CDW14_VALID
value|0x40
end_define

begin_define
define|#
directive|define
name|CDW15_VALID
value|0x80
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Queue Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NVME_ADMIN_QUEUE
value|0x00
end_define

begin_define
define|#
directive|define
name|NVME_IO_QUEUE
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|NVME_CDW0
name|Cdw0
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT32
name|Nsid
decl_stmt|;
name|UINT32
name|Cdw2
decl_stmt|;
name|UINT32
name|Cdw3
decl_stmt|;
name|UINT32
name|Cdw10
decl_stmt|;
name|UINT32
name|Cdw11
decl_stmt|;
name|UINT32
name|Cdw12
decl_stmt|;
name|UINT32
name|Cdw13
decl_stmt|;
name|UINT32
name|Cdw14
decl_stmt|;
name|UINT32
name|Cdw15
decl_stmt|;
block|}
name|EFI_NVM_EXPRESS_COMMAND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|DW0
decl_stmt|;
name|UINT32
name|DW1
decl_stmt|;
name|UINT32
name|DW2
decl_stmt|;
name|UINT32
name|DW3
decl_stmt|;
block|}
name|EFI_NVM_EXPRESS_COMPLETION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|CommandTimeout
decl_stmt|;
name|VOID
modifier|*
name|TransferBuffer
decl_stmt|;
name|UINT32
name|TransferLength
decl_stmt|;
name|VOID
modifier|*
name|MetadataBuffer
decl_stmt|;
name|UINT32
name|MetadataLength
decl_stmt|;
name|UINT8
name|QueueType
decl_stmt|;
name|EFI_NVM_EXPRESS_COMMAND
modifier|*
name|NvmeCmd
decl_stmt|;
name|EFI_NVM_EXPRESS_COMPLETION
modifier|*
name|NvmeCompletion
decl_stmt|;
block|}
name|EFI_NVM_EXPRESS_PASS_THRU_COMMAND_PACKET
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol function prototypes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Sends an NVM Express Command Packet to an NVM Express controller or namespace. This function supports   both blocking I/O and non-blocking I/O. The blocking I/O functionality is required, and the non-blocking   I/O functionality is optional.     @param[in]     This                A pointer to the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL instance.   @param[in]     NamespaceId         A 32 bit namespace ID as defined in the NVMe specification to which the NVM Express Command                                      Packet will be sent.  A value of 0 denotes the NVM Express controller, a value of all 0xFF's                                      (all bytes are 0xFF) in the namespace ID specifies that the command packet should be sent to                                      all valid namespaces.   @param[in,out] Packet              A pointer to the NVM Express Command Packet.   @param[in]     Event               If non-blocking I/O is not supported then Event is ignored, and blocking I/O is performed.                                      If Event is NULL, then blocking I/O is performed. If Event is not NULL and non-blocking I/O                                      is supported, then non-blocking I/O is performed, and Event will be signaled when the NVM                                      Express Command Packet completes.     @retval EFI_SUCCESS                The NVM Express Command Packet was sent by the host. TransferLength bytes were transferred                                      to, or from DataBuffer.   @retval EFI_BAD_BUFFER_SIZE        The NVM Express Command Packet was not executed. The number of bytes that could be transferred                                      is returned in TransferLength.   @retval EFI_NOT_READY              The NVM Express Command Packet could not be sent because the controller is not ready. The caller                                      may retry again later.   @retval EFI_DEVICE_ERROR           A device error occurred while attempting to send the NVM Express Command Packet.   @retval EFI_INVALID_PARAMETER      NamespaceId or the contents of EFI_NVM_EXPRESS_PASS_THRU_COMMAND_PACKET are invalid. The NVM                                      Express Command Packet was not sent, so no additional status information is available.   @retval EFI_UNSUPPORTED            The command described by the NVM Express Command Packet is not supported by the NVM Express                                      controller. The NVM Express Command Packet was not sent so no additional status information                                      is available.   @retval EFI_TIMEOUT                A timeout occurred while waiting for the NVM Express Command Packet to execute.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_NVM_EXPRESS_PASS_THRU_PASSTHRU
function_decl|)
parameter_list|(
name|IN
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|NamespaceId
parameter_list|,
name|IN
name|OUT
name|EFI_NVM_EXPRESS_PASS_THRU_COMMAND_PACKET
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
comment|/**   Used to retrieve the next namespace ID for this NVM Express controller.    The EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL.GetNextNamespace() function retrieves the next valid   namespace ID on this NVM Express controller.     If on input the value pointed to by NamespaceId is 0xFFFFFFFF, then the first valid namespace   ID defined on the NVM Express controller is returned in the location pointed to by NamespaceId   and a status of EFI_SUCCESS is returned.    If on input the value pointed to by NamespaceId is an invalid namespace ID other than 0xFFFFFFFF,   then EFI_INVALID_PARAMETER is returned.    If on input the value pointed to by NamespaceId is a valid namespace ID, then the next valid   namespace ID on the NVM Express controller is returned in the location pointed to by NamespaceId,   and EFI_SUCCESS is returned.    If the value pointed to by NamespaceId is the namespace ID of the last namespace on the NVM   Express controller, then EFI_NOT_FOUND is returned.    @param[in]     This           A pointer to the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL instance.   @param[in,out] NamespaceId    On input, a pointer to a legal NamespaceId for an NVM Express                                 namespace present on the NVM Express controller. On output, a                                 pointer to the next NamespaceId of an NVM Express namespace on                                 an NVM Express controller. An input value of 0xFFFFFFFF retrieves                                 the first NamespaceId for an NVM Express namespace present on an                                 NVM Express controller.    @retval EFI_SUCCESS           The Namespace ID of the next Namespace was returned.   @retval EFI_NOT_FOUND         There are no more namespaces defined on this controller.   @retval EFI_INVALID_PARAMETER NamespaceId is an invalid value other than 0xFFFFFFFF.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_NVM_EXPRESS_PASS_THRU_GET_NEXT_NAMESPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT32
modifier|*
name|NamespaceId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Used to allocate and build a device path node for an NVM Express namespace on an NVM Express controller.    The EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL.BuildDevicePath() function allocates and builds a single device   path node for the NVM Express namespace specified by NamespaceId.    If the NamespaceId is not valid, then EFI_NOT_FOUND is returned.    If DevicePath is NULL, then EFI_INVALID_PARAMETER is returned.     If there are not enough resources to allocate the device path node, then EFI_OUT_OF_RESOURCES is returned.    Otherwise, DevicePath is allocated with the boot service AllocatePool(), the contents of DevicePath are   initialized to describe the NVM Express namespace specified by NamespaceId, and EFI_SUCCESS is returned.    @param[in]     This                A pointer to the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL instance.   @param[in]     NamespaceId         The NVM Express namespace ID  for which a device path node is to be                                      allocated and built. Caller must set the NamespaceId to zero if the                                      device path node will contain a valid UUID.   @param[in,out] DevicePath          A pointer to a single device path node that describes the NVM Express                                      namespace specified by NamespaceId. This function is responsible for                                      allocating the buffer DevicePath with the boot service AllocatePool().                                      It is the caller's responsibility to free DevicePath when the caller                                      is finished with DevicePath.   @retval EFI_SUCCESS                The device path node that describes the NVM Express namespace specified                                      by NamespaceId was allocated and returned in DevicePath.   @retval EFI_NOT_FOUND              The NamespaceId is not valid.   @retval EFI_INVALID_PARAMETER      DevicePath is NULL.   @retval EFI_OUT_OF_RESOURCES       There are not enough resources to allocate the DevicePath node.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_NVM_EXPRESS_PASS_THRU_BUILD_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|NamespaceId
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
comment|/**   Used to translate a device path node to a namespace ID.    The EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL.GetNamespace() function determines the namespace ID associated with the   namespace described by DevicePath.    If DevicePath is a device path node type that the NVM Express Pass Thru driver supports, then the NVM Express   Pass Thru driver will attempt to translate the contents DevicePath into a namespace ID.    If this translation is successful, then that namespace ID is returned in NamespaceId, and EFI_SUCCESS is returned    @param[in]  This                A pointer to the EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL instance.   @param[in]  DevicePath          A pointer to the device path node that describes an NVM Express namespace on                                   the NVM Express controller.   @param[out] NamespaceId         The NVM Express namespace ID contained in the device path node.    @retval EFI_SUCCESS             DevicePath was successfully translated to NamespaceId.   @retval EFI_INVALID_PARAMETER   If DevicePath or NamespaceId are NULL, then EFI_INVALID_PARAMETER is returned.   @retval EFI_UNSUPPORTED         If DevicePath is not a device path node type that the NVM Express Pass Thru driver                                   supports, then EFI_UNSUPPORTED is returned.   @retval EFI_NOT_FOUND           If DevicePath is a device path node type that the NVM Express Pass Thru driver                                   supports, but there is not a valid translation from DevicePath to a namespace ID,                                   then EFI_NOT_FOUND is returned. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_NVM_EXPRESS_PASS_THRU_GET_NAMESPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
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
name|NamespaceId
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol Interface Structure
end_comment

begin_comment
comment|//
end_comment

begin_struct
struct|struct
name|_EFI_NVM_EXPRESS_PASS_THRU_PROTOCOL
block|{
name|EFI_NVM_EXPRESS_PASS_THRU_MODE
modifier|*
name|Mode
decl_stmt|;
name|EFI_NVM_EXPRESS_PASS_THRU_PASSTHRU
name|PassThru
decl_stmt|;
name|EFI_NVM_EXPRESS_PASS_THRU_GET_NEXT_NAMESPACE
name|GetNextNamespace
decl_stmt|;
name|EFI_NVM_EXPRESS_PASS_THRU_BUILD_DEVICE_PATH
name|BuildDevicePath
decl_stmt|;
name|EFI_NVM_EXPRESS_PASS_THRU_GET_NAMESPACE
name|GetNamespace
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiNvmExpressPassThruProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

