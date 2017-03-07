begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PCI Root Bridge I/O protocol as defined in the UEFI 2.0 specification.    PCI Root Bridge I/O protocol is used by PCI Bus Driver to perform PCI Memory, PCI I/O,    and PCI Configuration cycles on a PCI Root Bridge. It also provides services to perform    defferent types of bus mastering DMA.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_ROOT_BRIDGE_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_ROOT_BRIDGE_IO_H__
end_define

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_define
define|#
directive|define
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID
define|\
value|{ \     0x2f707ebb, 0x4a1a, 0x11d4, {0x9a, 0x38, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|/// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiPciWidthUint8
block|,
name|EfiPciWidthUint16
block|,
name|EfiPciWidthUint32
block|,
name|EfiPciWidthUint64
block|,
name|EfiPciWidthFifoUint8
block|,
name|EfiPciWidthFifoUint16
block|,
name|EfiPciWidthFifoUint32
block|,
name|EfiPciWidthFifoUint64
block|,
name|EfiPciWidthFillUint8
block|,
name|EfiPciWidthFillUint16
block|,
name|EfiPciWidthFillUint32
block|,
name|EfiPciWidthFillUint64
block|,
name|EfiPciWidthMaximum
block|}
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|/// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A read operation from system memory by a bus master that is not capable of producing
comment|/// PCI dual address cycles.
comment|///
name|EfiPciOperationBusMasterRead
block|,
comment|///
comment|/// A write operation from system memory by a bus master that is not capable of producing
comment|/// PCI dual address cycles.
comment|///
name|EfiPciOperationBusMasterWrite
block|,
comment|///
comment|/// Provides both read and write access to system memory by both the processor and a bus
comment|/// master that is not capable of producing PCI dual address cycles.
comment|///
name|EfiPciOperationBusMasterCommonBuffer
block|,
comment|///
comment|/// A read operation from system memory by a bus master that is capable of producing PCI
comment|/// dual address cycles.
comment|///
name|EfiPciOperationBusMasterRead64
block|,
comment|///
comment|/// A write operation to system memory by a bus master that is capable of producing PCI
comment|/// dual address cycles.
comment|///
name|EfiPciOperationBusMasterWrite64
block|,
comment|///
comment|/// Provides both read and write access to system memory by both the processor and a bus
comment|/// master that is capable of producing PCI dual address cycles.
comment|///
name|EfiPciOperationBusMasterCommonBuffer64
block|,
name|EfiPciOperationMaximum
block|}
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_ISA_MOTHERBOARD_IO
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_ISA_IO
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VGA_PALETTE_IO
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VGA_MEMORY
value|0x0008
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VGA_IO
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_IDE_PRIMARY_IO
value|0x0020
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_IDE_SECONDARY_IO
value|0x0040
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_MEMORY_WRITE_COMBINE
value|0x0080
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_MEMORY_CACHED
value|0x0800
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_MEMORY_DISABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_DUAL_ADDRESS_CYCLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_ISA_IO_16
value|0x10000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VGA_PALETTE_IO_16
value|0x20000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VGA_IO_16
value|0x40000
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_VALID_FOR_ALLOCATE_BUFFER
value|(EFI_PCI_ATTRIBUTE_MEMORY_WRITE_COMBINE | EFI_PCI_ATTRIBUTE_MEMORY_CACHED | EFI_PCI_ATTRIBUTE_DUAL_ADDRESS_CYCLE)
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ATTRIBUTE_INVALID_FOR_ALLOCATE_BUFFER
value|(~EFI_PCI_ATTRIBUTE_VALID_FOR_ALLOCATE_BUFFER)
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ADDRESS
parameter_list|(
name|bus
parameter_list|,
name|dev
parameter_list|,
name|func
parameter_list|,
name|reg
parameter_list|)
define|\
value|(UINT64) ( \   (((UINTN) bus)<< 24) | \   (((UINTN) dev)<< 16) | \   (((UINTN) func)<< 8) | \   (((UINTN) (reg))< 256 ? ((UINTN) (reg)) : (UINT64) (LShiftU64 ((UINT64) (reg), 32))))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Register
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|Device
decl_stmt|;
name|UINT8
name|Bus
decl_stmt|;
name|UINT32
name|ExtendedRegister
decl_stmt|;
block|}
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Reads from the I/O space of a PCI Root Bridge. Returns when either the polling exit criteria is   satisfied or after a defined duration.              @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Width                 Signifies the width of the memory or I/O operations.   @param  Address               The base address of the memory or I/O operations.     @param  Mask                  Mask used for the polling criteria.   @param  Value                 The comparison value used for the polling exit criteria.   @param  Delay                 The number of 100 ns units to poll.   @param  Result                Pointer to the last value read from the memory location.                                    @retval EFI_SUCCESS           The last data returned from the access matched the poll exit criteria.   @retval EFI_TIMEOUT           Delay expired before a match occurred.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT64
name|Mask
parameter_list|,
name|IN
name|UINT64
name|Value
parameter_list|,
name|IN
name|UINT64
name|Delay
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Result
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Enables a PCI driver to access PCI controller registers in the PCI root bridge memory space.              @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Width                 Signifies the width of the memory operations.   @param  Address               The base address of the memory operations.                                     @param  Count                 The number of memory operations to perform.   @param  Buffer                For read operations, the destination buffer to store the results. For write                                 operations, the source buffer to write data from.                                @retval EFI_SUCCESS           The data was read from or written to the PCI root bridge.     @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Read PCI controller registers in the PCI root bridge memory space.
comment|///
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM
name|Read
decl_stmt|;
comment|///
comment|/// Write PCI controller registers in the PCI root bridge memory space.
comment|///
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM
name|Write
decl_stmt|;
block|}
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Enables a PCI driver to copy one region of PCI root bridge memory space to another region of PCI   root bridge memory space.                                                                                       @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL instance.   @param  Width                 Signifies the width of the memory operations.   @param  DestAddress           The destination address of the memory operation.                                   @param  SrcAddress            The source address of the memory operation.                                   @param  Count                 The number of memory operations to perform.                                        @retval EFI_SUCCESS           The data was copied from one memory region to another memory region.     @retval EFI_INVALID_PARAMETER Width is invalid for this PCI root bridge.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|DestAddress
parameter_list|,
name|IN
name|UINT64
name|SrcAddress
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Provides the PCI controller-specific addresses required to access system memory from a   DMA bus master.                                                                                        @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Operation             Indicates if the bus master is going to read or write to system memory.   @param  HostAddress           The system memory address to map to the PCI controller.   @param  NumberOfBytes         On input the number of bytes to map. On output the number of bytes                                 that were mapped.                                                    @param  DeviceAddress         The resulting map address for the bus master PCI controller to use to                                 access the hosts HostAddress.                                           @param  Mapping               A resulting value to pass to Unmap().                                      @retval EFI_SUCCESS           The range was mapped for the returned NumberOfBytes.   @retval EFI_UNSUPPORTED       The HostAddress cannot be mapped as a common buffer.                                   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_DEVICE_ERROR      The system hardware could not map the requested address.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION
name|Operation
parameter_list|,
name|IN
name|VOID
modifier|*
name|HostAddress
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|NumberOfBytes
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|DeviceAddress
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Mapping
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Completes the Map() operation and releases any corresponding resources.                @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Mapping               The mapping value returned from Map().                                      @retval EFI_SUCCESS           The range was unmapped.   @retval EFI_INVALID_PARAMETER Mapping is not a value that was returned by Map().   @retval EFI_DEVICE_ERROR      The data was not committed to the target system memory.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Mapping
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Allocates pages that are suitable for an EfiPciOperationBusMasterCommonBuffer or   EfiPciOperationBusMasterCommonBuffer64 mapping.                                                 @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Type                  This parameter is not used and must be ignored.   @param  MemoryType            The type of memory to allocate, EfiBootServicesData or                                 EfiRuntimeServicesData.                                  @param  Pages                 The number of pages to allocate.                                   @param  HostAddress           A pointer to store the base system memory address of the                                 allocated range.                                           @param  Attributes            The requested bit mask of attributes for the allocated range.                                      @retval EFI_SUCCESS           The requested memory pages were allocated.   @retval EFI_UNSUPPORTED       Attributes is unsupported. The only legal attribute bits are                                 MEMORY_WRITE_COMBINE and MEMORY_CACHED.                        @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The memory pages could not be allocated.                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_ALLOCATE_TYPE
name|Type
parameter_list|,
name|IN
name|EFI_MEMORY_TYPE
name|MemoryType
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|HostAddress
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Frees memory that was allocated with AllocateBuffer().                @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Pages                 The number of pages to free.                                   @param  HostAddress           The base system memory address of the allocated range.                                                                          @retval EFI_SUCCESS           The requested memory pages were freed.   @retval EFI_INVALID_PARAMETER The memory range specified by HostAddress and Pages                                 was not allocated with AllocateBuffer().                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|VOID
modifier|*
name|HostAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Flushes all PCI posted write transactions from a PCI host bridge to system memory.                @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.                                      @retval EFI_SUCCESS           The PCI posted write transactions were flushed from the PCI host                                 bridge to system memory.                                           @retval EFI_DEVICE_ERROR      The PCI posted write transactions were not flushed from the PCI                                 host bridge due to a hardware error.                                                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Gets the attributes that a PCI root bridge supports setting with SetAttributes(), and the   attributes that a PCI root bridge is currently using.                                                    @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Supports              A pointer to the mask of attributes that this PCI root bridge supports                                 setting with SetAttributes().                                            @param  Attributes            A pointer to the mask of attributes that this PCI root bridge is currently                                 using.                                                                                                          @retval EFI_SUCCESS           If Supports is not NULL, then the attributes that the PCI root                                      bridge supports is returned in Supports. If Attributes is                                           not NULL, then the attributes that the PCI root bridge is currently                                 using is returned in Attributes.                                      @retval EFI_INVALID_PARAMETER Both Supports and Attributes are NULL.                                                                        **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Supports
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Sets attributes for a resource range on a PCI root bridge.                @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Attributes            The mask of attributes to set.   @param  ResourceBase          A pointer to the base address of the resource range to be modified by the                                 attributes specified by Attributes.   @param  ResourceLength        A pointer to the length of the resource range to be modified by the                                 attributes specified by Attributes.                                                                                                                                                  @retval EFI_SUCCESS           The set of attributes specified by Attributes for the resource                                    range specified by ResourceBase and ResourceLength                                                were set on the PCI root bridge, and the actual resource range is                                 returned in ResuourceBase and ResourceLength.                       @retval EFI_UNSUPPORTED       A bit is set in Attributes that is not supported by the PCI Root                                 Bridge.                                                            @retval EFI_OUT_OF_RESOURCES  There are not enough resources to set the attributes on the                                                               resource range specified by BaseAddress and Length.           @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                                                      **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|ResourceBase
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|ResourceLength
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the current resource settings of this PCI root bridge in the form of a set of ACPI 2.0   resource descriptors.                                                                                           @param  This                  A pointer to the EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL.   @param  Resources             A pointer to the ACPI 2.0 resource descriptors that describe the current                                 configuration of this PCI root bridge.                                                                      @retval EFI_SUCCESS           The current configuration of this PCI root bridge was returned in                                 Resources.                                                                                                                          @retval EFI_UNSUPPORTED       The current configuration of this PCI root bridge could not be                                 retrieved.                                                                                                                   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Resources
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the basic Memory, I/O, PCI configuration, and DMA interfaces that are
end_comment

begin_comment
comment|/// used to abstract accesses to PCI controllers behind a PCI Root Bridge Controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
block|{
comment|///
comment|/// The EFI_HANDLE of the PCI Host Bridge of which this PCI Root Bridge is a member.
comment|///
name|EFI_HANDLE
name|ParentHandle
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM
name|PollMem
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM
name|PollIo
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS
name|Mem
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS
name|Io
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS
name|Pci
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM
name|CopyMem
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP
name|Map
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP
name|Unmap
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER
name|AllocateBuffer
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER
name|FreeBuffer
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH
name|Flush
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES
name|GetAttributes
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES
name|SetAttributes
decl_stmt|;
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION
name|Configuration
decl_stmt|;
comment|///
comment|/// The segment number that this PCI root bridge resides.
comment|///
name|UINT32
name|SegmentNumber
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciRootBridgeIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

