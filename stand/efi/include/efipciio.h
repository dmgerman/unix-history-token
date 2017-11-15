begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/** @file   EFI PCI I/O Protocol provides the basic Memory, I/O, PCI configuration,    and DMA interfaces that a driver uses to access its PCI controller.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_IO_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the PCI I/O Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_PROTOCOL_GUID
define|\
value|{ 0x4cf5b200, 0x68b8, 0x4ca5, {0x9e, 0xec, 0xb2, 0x3e, 0x3f, 0x50, 0x2, 0x9a} }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PCI_IO_PROTOCOL
name|EFI_PCI_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|/// EFI_PCI_IO_PROTOCOL_WIDTH
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
name|EfiPciIoWidthUint8
init|=
literal|0
block|,
name|EfiPciIoWidthUint16
block|,
name|EfiPciIoWidthUint32
block|,
name|EfiPciIoWidthUint64
block|,
name|EfiPciIoWidthFifoUint8
block|,
name|EfiPciIoWidthFifoUint16
block|,
name|EfiPciIoWidthFifoUint32
block|,
name|EfiPciIoWidthFifoUint64
block|,
name|EfiPciIoWidthFillUint8
block|,
name|EfiPciIoWidthFillUint16
block|,
name|EfiPciIoWidthFillUint32
block|,
name|EfiPciIoWidthFillUint64
block|,
name|EfiPciIoWidthMaximum
block|}
name|EFI_PCI_IO_PROTOCOL_WIDTH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Complete PCI address generater
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_PASS_THROUGH_BAR
value|0xff
end_define

begin_comment
comment|///< Special BAR that passes a memory or I/O cycle through unchanged
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_MASK
value|0x077f
end_define

begin_comment
comment|///< All the following I/O and Memory cycles
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_ISA_MOTHERBOARD_IO
value|0x0001
end_define

begin_comment
comment|///< I/O cycles 0x0000-0x00FF (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_ISA_IO
value|0x0002
end_define

begin_comment
comment|///< I/O cycles 0x0100-0x03FF or greater (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO
value|0x0004
end_define

begin_comment
comment|///< I/O cycles 0x3C6, 0x3C8, 0x3C9 (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_VGA_MEMORY
value|0x0008
end_define

begin_comment
comment|///< MEM cycles 0xA0000-0xBFFFF (24 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_VGA_IO
value|0x0010
end_define

begin_comment
comment|///< I/O cycles 0x3B0-0x3BB and 0x3C0-0x3DF (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_IDE_PRIMARY_IO
value|0x0020
end_define

begin_comment
comment|///< I/O cycles 0x1F0-0x1F7, 0x3F6, 0x3F7 (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_IDE_SECONDARY_IO
value|0x0040
end_define

begin_comment
comment|///< I/O cycles 0x170-0x177, 0x376, 0x377 (10 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_MEMORY_WRITE_COMBINE
value|0x0080
end_define

begin_comment
comment|///< Map a memory range so writes are combined
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_IO
value|0x0100
end_define

begin_comment
comment|///< Enable the I/O decode bit in the PCI Config Header
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_MEMORY
value|0x0200
end_define

begin_comment
comment|///< Enable the Memory decode bit in the PCI Config Header
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_BUS_MASTER
value|0x0400
end_define

begin_comment
comment|///< Enable the DMA bit in the PCI Config Header
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_MEMORY_CACHED
value|0x0800
end_define

begin_comment
comment|///< Map a memory range so all r/w accesses are cached
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_MEMORY_DISABLE
value|0x1000
end_define

begin_comment
comment|///< Disable a memory range
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_EMBEDDED_DEVICE
value|0x2000
end_define

begin_comment
comment|///< Clear for an add-in PCI Device
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_EMBEDDED_ROM
value|0x4000
end_define

begin_comment
comment|///< Clear for a physical PCI Option ROM accessed through ROM BAR
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_DUAL_ADDRESS_CYCLE
value|0x8000
end_define

begin_comment
comment|///< Clear for PCI controllers that can not genrate a DAC
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_ISA_IO_16
value|0x10000
end_define

begin_comment
comment|///< I/O cycles 0x0100-0x03FF or greater (16 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO_16
value|0x20000
end_define

begin_comment
comment|///< I/O cycles 0x3C6, 0x3C8, 0x3C9 (16 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_IO_ATTRIBUTE_VGA_IO_16
value|0x40000
end_define

begin_comment
comment|///< I/O cycles 0x3B0-0x3BB and 0x3C0-0x3DF (16 bit decode)
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_DEVICE_ENABLE
value|(EFI_PCI_IO_ATTRIBUTE_IO | EFI_PCI_IO_ATTRIBUTE_MEMORY | EFI_PCI_IO_ATTRIBUTE_BUS_MASTER)
end_define

begin_define
define|#
directive|define
name|EFI_VGA_DEVICE_ENABLE
value|(EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO | EFI_PCI_IO_ATTRIBUTE_VGA_MEMORY | EFI_PCI_IO_ATTRIBUTE_VGA_IO | EFI_PCI_IO_ATTRIBUTE_IO)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|/// EFI_PCI_IO_PROTOCOL_OPERATION
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
comment|/// A read operation from system memory by a bus master.
comment|///
name|EfiPciIoOperationBusMasterRead
block|,
comment|///
comment|/// A write operation from system memory by a bus master.
comment|///
name|EfiPciIoOperationBusMasterWrite
block|,
comment|///
comment|/// Provides both read and write access to system memory by both the processor and a
comment|/// bus master. The buffer is coherent from both the processor's and the bus master's point of view.
comment|///
name|EfiPciIoOperationBusMasterCommonBuffer
block|,
name|EfiPciIoOperationMaximum
block|}
name|EFI_PCI_IO_PROTOCOL_OPERATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// *******************************************************
end_comment

begin_comment
comment|/// EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION
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
comment|/// Retrieve the PCI controller's current attributes, and return them in Result.
comment|///
name|EfiPciIoAttributeOperationGet
block|,
comment|///
comment|/// Set the PCI controller's current attributes to Attributes.
comment|///
name|EfiPciIoAttributeOperationSet
block|,
comment|///
comment|/// Enable the attributes specified by the bits that are set in Attributes for this PCI controller.
comment|///
name|EfiPciIoAttributeOperationEnable
block|,
comment|///
comment|/// Disable the attributes specified by the bits that are set in Attributes for this PCI controller.
comment|///
name|EfiPciIoAttributeOperationDisable
block|,
comment|///
comment|/// Retrieve the PCI controller's supported attributes, and return them in Result.
comment|///
name|EfiPciIoAttributeOperationSupported
block|,
name|EfiPciIoAttributeOperationMaximum
block|}
name|EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Reads from the memory space of a PCI controller. Returns either when the polling exit criteria is   satisfied or after a defined duration.                                                                         @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.   @param  Width                 Signifies the width of the memory or I/O operations.   @param  BarIndex              The BAR index of the standard PCI Configuration header to use as the                                 base address for the memory operation to perform.                      @param  Offset                The offset within the selected BAR to start the memory operation.   @param  Mask                  Mask used for the polling criteria.   @param  Value                 The comparison value used for the polling exit criteria.   @param  Delay                 The number of 100 ns units to poll.   @param  Result                Pointer to the last value read from the memory location.                                    @retval EFI_SUCCESS           The last data returned from the access matched the poll exit criteria.   @retval EFI_UNSUPPORTED       BarIndex not valid for this PCI controller.   @retval EFI_UNSUPPORTED       Offset is not valid for the BarIndex of this PCI controller.   @retval EFI_TIMEOUT           Delay expired before a match occurred.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_POLL_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT8
name|BarIndex
parameter_list|,
name|IN
name|UINT64
name|Offset
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
comment|/**                                                                    Enable a PCI driver to access PCI controller registers in the PCI memory or I/O space.              @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.   @param  Width                 Signifies the width of the memory or I/O operations.   @param  BarIndex              The BAR index of the standard PCI Configuration header to use as the                                 base address for the memory or I/O operation to perform.                       @param  Offset                The offset within the selected BAR to start the memory or I/O operation.                                   @param  Count                 The number of memory or I/O operations to perform.   @param  Buffer                For read operations, the destination buffer to store the results. For write                                 operations, the source buffer to write data from.                                @retval EFI_SUCCESS           The data was read from or written to the PCI controller.   @retval EFI_UNSUPPORTED       BarIndex not valid for this PCI controller.   @retval EFI_UNSUPPORTED       The address range specified by Offset, Width, and Count is not                                 valid for the PCI BAR specified by BarIndex.                     @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT8
name|BarIndex
parameter_list|,
name|IN
name|UINT64
name|Offset
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
comment|/// Read PCI controller registers in the PCI memory or I/O space.
comment|///
name|EFI_PCI_IO_PROTOCOL_IO_MEM
name|Read
decl_stmt|;
comment|///
comment|/// Write PCI controller registers in the PCI memory or I/O space.
comment|///
name|EFI_PCI_IO_PROTOCOL_IO_MEM
name|Write
decl_stmt|;
block|}
name|EFI_PCI_IO_PROTOCOL_ACCESS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Enable a PCI driver to access PCI controller registers in PCI configuration space.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  Width                 Signifies the width of the memory operations.   @param  Offset                The offset within the PCI configuration space for the PCI controller.   @param  Count                 The number of PCI configuration operations to perform.   @param  Buffer                For read operations, the destination buffer to store the results. For write                                 operations, the source buffer to write data from.                                         @retval EFI_SUCCESS           The data was read from or written to the PCI controller.   @retval EFI_UNSUPPORTED       The address range specified by Offset, Width, and Count is not                                 valid for the PCI configuration header of the PCI controller.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.                                    @retval EFI_INVALID_PARAMETER Buffer is NULL or Width is invalid.                                                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_CONFIG
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT32
name|Offset
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
comment|/// Read PCI controller registers in PCI configuration space.
comment|///
name|EFI_PCI_IO_PROTOCOL_CONFIG
name|Read
decl_stmt|;
comment|///
comment|/// Write PCI controller registers in PCI configuration space.
comment|///
name|EFI_PCI_IO_PROTOCOL_CONFIG
name|Write
decl_stmt|;
block|}
name|EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Enables a PCI driver to copy one region of PCI memory space to another region of PCI   memory space.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.   @param  Width                 Signifies the width of the memory operations.   @param  DestBarIndex          The BAR index in the standard PCI Configuration header to use as the                                 base address for the memory operation to perform.                      @param  DestOffset            The destination offset within the BAR specified by DestBarIndex to                                 start the memory writes for the copy operation.                      @param  SrcBarIndex           The BAR index in the standard PCI Configuration header to use as the                                 base address for the memory operation to perform.                      @param  SrcOffset             The source offset within the BAR specified by SrcBarIndex to start                                 the memory reads for the copy operation.                             @param  Count                 The number of memory operations to perform. Bytes moved is Width                                 size * Count, starting at DestOffset and SrcOffset.                                                 @retval EFI_SUCCESS           The data was copied from one memory region to another memory region.   @retval EFI_UNSUPPORTED       DestBarIndex not valid for this PCI controller.   @retval EFI_UNSUPPORTED       SrcBarIndex not valid for this PCI controller.   @retval EFI_UNSUPPORTED       The address range specified by DestOffset, Width, and Count                                 is not valid for the PCI BAR specified by DestBarIndex.       @retval EFI_UNSUPPORTED       The address range specified by SrcOffset, Width, and Count is                                 not valid for the PCI BAR specified by SrcBarIndex.             @retval EFI_INVALID_PARAMETER Width is invalid.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_COPY_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT8
name|DestBarIndex
parameter_list|,
name|IN
name|UINT64
name|DestOffset
parameter_list|,
name|IN
name|UINT8
name|SrcBarIndex
parameter_list|,
name|IN
name|UINT64
name|SrcOffset
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Provides the PCI controller-specific addresses needed to access system memory.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.   @param  Operation             Indicates if the bus master is going to read or write to system memory.   @param  HostAddress           The system memory address to map to the PCI controller.   @param  NumberOfBytes         On input the number of bytes to map. On output the number of bytes                                 that were mapped.                                                    @param  DeviceAddress         The resulting map address for the bus master PCI controller to use to                                 access the hosts HostAddress.                                           @param  Mapping               A resulting value to pass to Unmap().                                      @retval EFI_SUCCESS           The range was mapped for the returned NumberOfBytes.   @retval EFI_UNSUPPORTED       The HostAddress cannot be mapped as a common buffer.                                   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.   @retval EFI_DEVICE_ERROR      The system hardware could not map the requested address.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_MAP
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_OPERATION
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
comment|/**                                                                    Completes the Map() operation and releases any corresponding resources.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.                                         @param  Mapping               The mapping value returned from Map().                                      @retval EFI_SUCCESS           The range was unmapped.   @retval EFI_DEVICE_ERROR      The data was not committed to the target system memory.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_UNMAP
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
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
comment|/**                                                                    Allocates pages that are suitable for an EfiPciIoOperationBusMasterCommonBuffer   mapping.                                                                                       @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.   @param  Type                  This parameter is not used and must be ignored.   @param  MemoryType            The type of memory to allocate, EfiBootServicesData or                                 EfiRuntimeServicesData.                                  @param  Pages                 The number of pages to allocate.                                   @param  HostAddress           A pointer to store the base system memory address of the                                 allocated range.                                           @param  Attributes            The requested bit mask of attributes for the allocated range.                                      @retval EFI_SUCCESS           The requested memory pages were allocated.   @retval EFI_UNSUPPORTED       Attributes is unsupported. The only legal attribute bits are                                 MEMORY_WRITE_COMBINE and MEMORY_CACHED.                        @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The memory pages could not be allocated.                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_ALLOCATE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
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
comment|/**                                                                    Frees memory that was allocated with AllocateBuffer().                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  Pages                 The number of pages to free.                                   @param  HostAddress           The base system memory address of the allocated range.                                                                          @retval EFI_SUCCESS           The requested memory pages were freed.   @retval EFI_INVALID_PARAMETER The memory range specified by HostAddress and Pages                                 was not allocated with AllocateBuffer().                                       **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_FREE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
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
comment|/**                                                                    Flushes all PCI posted write transactions from a PCI host bridge to system memory.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.                                        @retval EFI_SUCCESS           The PCI posted write transactions were flushed from the PCI host                                 bridge to system memory.                                           @retval EFI_DEVICE_ERROR      The PCI posted write transactions were not flushed from the PCI                                 host bridge due to a hardware error.                                                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves this PCI controller's current PCI bus number, device number, and function number.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  SegmentNumber         The PCI controller's current PCI segment number.   @param  BusNumber             The PCI controller's current PCI bus number.   @param  DeviceNumber          The PCI controller's current PCI device number.   @param  FunctionNumber        The PCI controller's current PCI function number.                                      @retval EFI_SUCCESS           The PCI controller location was returned.                                                          @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_GET_LOCATION
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|SegmentNumber
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BusNumber
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DeviceNumber
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|FunctionNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Performs an operation on the attributes that this PCI controller supports. The operations include   getting the set of supported attributes, retrieving the current attributes, setting the current     attributes, enabling attributes, and disabling attributes.                                                       @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  Operation             The operation to perform on the attributes for this PCI controller.   @param  Attributes            The mask of attributes that are used for Set, Enable, and Disable                                 operations.                                                         @param  Result                A pointer to the result mask of attributes that are returned for the Get                                 and Supported operations.                                                                                     @retval EFI_SUCCESS           The operation on the PCI controller's attributes was completed.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.                                 @retval EFI_UNSUPPORTED       one or more of the bits set in                                                                Attributes are not supported by this PCI controller or one of                                 its parent bridges when Operation is Set, Enable or Disable.                                         **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION
name|Operation
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Result
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Gets the attributes that this PCI controller supports setting on a BAR using   SetBarAttributes(), and retrieves the list of resource descriptors for a BAR.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  BarIndex              The BAR index of the standard PCI Configuration header to use as the                                 base address for resource range. The legal range for this field is 0..5.   @param  Supports              A pointer to the mask of attributes that this PCI controller supports                                 setting for this BAR with SetBarAttributes().                           @param  Resources             A pointer to the ACPI 2.0 resource descriptors that describe the current                                 configuration of this BAR of the PCI controller.                                                              @retval EFI_SUCCESS           If Supports is not NULL, then the attributes that the PCI                                        controller supports are returned in Supports. If Resources                                       is not NULL, then the ACPI 2.0 resource descriptors that the PCI                                 controller is currently using are returned in Resources.             @retval EFI_INVALID_PARAMETER Both Supports and Attributes are NULL.   @retval EFI_UNSUPPORTED       BarIndex not valid for this PCI controller.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to allocate                                 Resources.                                                                                   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_GET_BAR_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|BarIndex
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Supports
parameter_list|,
name|OPTIONAL
name|OUT
name|VOID
modifier|*
modifier|*
name|Resources
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Sets the attributes for a range of a BAR on a PCI controller.                @param  This                  A pointer to the EFI_PCI_IO_PROTOCOL instance.     @param  Attributes            The mask of attributes to set for the resource range specified by                                 BarIndex, Offset, and Length.                                       @param  BarIndex              The BAR index of the standard PCI Configuration header to use as the                                 base address for resource range. The legal range for this field is 0..5.   @param  Offset                A pointer to the BAR relative base address of the resource range to be                                 modified by the attributes specified by Attributes.                      @param  Length                A pointer to the length of the resource range to be modified by the                                 attributes specified by Attributes.                                                                      @retval EFI_SUCCESS           The set of attributes specified by Attributes for the resource                                       range specified by BarIndex, Offset, and Length were                                                 set on the PCI controller, and the actual resource range is returned                                 in Offset and Length.                                                  @retval EFI_INVALID_PARAMETER Offset or Length is NULL.   @retval EFI_UNSUPPORTED       BarIndex not valid for this PCI controller.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to set the attributes on the                                 resource range specified by BarIndex, Offset, and                                           Length.                                                                                      **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_IO_PROTOCOL_SET_BAR_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|,
name|IN
name|UINT8
name|BarIndex
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|Offset
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_PCI_IO_PROTOCOL provides the basic Memory, I/O, PCI configuration,
end_comment

begin_comment
comment|/// and DMA interfaces used to abstract accesses to PCI controllers.
end_comment

begin_comment
comment|/// There is one EFI_PCI_IO_PROTOCOL instance for each PCI controller on a PCI bus.
end_comment

begin_comment
comment|/// A device driver that wishes to manage a PCI controller in a system will have to
end_comment

begin_comment
comment|/// retrieve the EFI_PCI_IO_PROTOCOL instance that is associated with the PCI controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PCI_IO_PROTOCOL
block|{
name|EFI_PCI_IO_PROTOCOL_POLL_IO_MEM
name|PollMem
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_POLL_IO_MEM
name|PollIo
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_ACCESS
name|Mem
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_ACCESS
name|Io
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS
name|Pci
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_COPY_MEM
name|CopyMem
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_MAP
name|Map
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_UNMAP
name|Unmap
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_ALLOCATE_BUFFER
name|AllocateBuffer
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_FREE_BUFFER
name|FreeBuffer
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_FLUSH
name|Flush
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_GET_LOCATION
name|GetLocation
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_ATTRIBUTES
name|Attributes
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_GET_BAR_ATTRIBUTES
name|GetBarAttributes
decl_stmt|;
name|EFI_PCI_IO_PROTOCOL_SET_BAR_ATTRIBUTES
name|SetBarAttributes
decl_stmt|;
comment|///
comment|/// The size, in bytes, of the ROM image.
comment|///
name|UINT64
name|RomSize
decl_stmt|;
comment|///
comment|/// A pointer to the in memory copy of the ROM image. The PCI Bus Driver is responsible
comment|/// for allocating memory for the ROM image, and copying the contents of the ROM to memory.
comment|/// The contents of this buffer are either from the PCI option ROM that can be accessed
comment|/// through the ROM BAR of the PCI controller, or it is from a platform-specific location.
comment|/// The Attributes() function can be used to determine from which of these two sources
comment|/// the RomImage buffer was initialized.
comment|///
name|VOID
modifier|*
name|RomImage
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

