begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Device IO protocol as defined in the EFI 1.10 specification.    Device IO is used to abstract hardware access to devices. It includes   memory mapped IO, IO, PCI Config space, and DMA.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVICE_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVICE_IO_H__
end_define

begin_define
define|#
directive|define
name|EFI_DEVICE_IO_PROTOCOL_GUID
define|\
value|{ \     0xaf6ac311, 0x84c3, 0x11d2, {0x8e, 0x3c, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DEVICE_IO_PROTOCOL
name|EFI_DEVICE_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DEVICE_IO_PROTOCOL
value|EFI_DEVICE_IO_PROTOCOL_GUID
end_define

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
name|EFI_DEVICE_IO_PROTOCOL
name|EFI_DEVICE_IO_INTERFACE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device IO Access Width
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IO_UINT8
init|=
literal|0
block|,
name|IO_UINT16
init|=
literal|1
block|,
name|IO_UINT32
init|=
literal|2
block|,
name|IO_UINT64
init|=
literal|3
block|,
comment|//
comment|// Below enumerations are added in "Extensible Firmware Interface Specification,
comment|// Version 1.10, Specification Update, Version 001".
comment|//
name|MMIO_COPY_UINT8
init|=
literal|4
block|,
name|MMIO_COPY_UINT16
init|=
literal|5
block|,
name|MMIO_COPY_UINT32
init|=
literal|6
block|,
name|MMIO_COPY_UINT64
init|=
literal|7
block|}
name|EFI_IO_WIDTH
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Enables a driver to access device registers in the appropriate memory or I/O space.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.   @param  Width                 Signifies the width of the I/O operations.                                                                      @param  Address               The base address of the I/O operations.    @param  Count                 The number of I/O operations to perform.   @param  Buffer                For read operations, the destination buffer to store the results. For write                                 operations, the source buffer to write data from. If                                 Width is MMIO_COPY_UINT8, MMIO_COPY_UINT16,                                 MMIO_COPY_UINT32, or MMIO_COPY_UINT64, then                                 Buffer is interpreted as a base address of an I/O operation such as Address.     @retval EFI_SUCCESS           The data was read from or written to the device.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.         @retval EFI_INVALID_PARAMETER Width is invalid.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_IO
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IO_WIDTH
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
name|EFI_DEVICE_IO
name|Read
decl_stmt|;
name|EFI_DEVICE_IO
name|Write
decl_stmt|;
block|}
name|EFI_IO_ACCESS
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Provides an EFI Device Path for a PCI device with the given PCI configuration space address.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.   @param  PciAddress            The PCI configuration space address of the device whose Device Path                                 is going to be returned.     @param  PciDevicePath         A pointer to the pointer for the EFI Device Path for PciAddress.                                 Memory for the Device Path is allocated from the pool.              @retval EFI_SUCCESS           The PciDevicePath returns a pointer to a valid EFI Device Path.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.         @retval EFI_UNSUPPORTED       The PciAddress does not map to a valid EFI Device Path.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|PciAddress
parameter_list|,
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|PciDevicePath
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A read operation from system memory by a bus master.
comment|///
name|EfiBusMasterRead
block|,
comment|///
comment|/// A write operation to system memory by a bus master.
comment|///
name|EfiBusMasterWrite
block|,
comment|///
comment|/// Provides both read and write access to system memory
comment|/// by both the processor and a bus master. The buffer is
comment|/// coherent from both the processor's and the bus master's
comment|/// point of view.
comment|///
name|EfiBusMasterCommonBuffer
block|}
name|EFI_IO_OPERATION_TYPE
typedef|;
end_typedef

begin_comment
comment|/**                                                                    Provides the device-specific addresses needed to access system memory.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.   @param  Operation             Indicates if the bus master is going to read or write to system memory.   @param  HostAddress           The system memory address to map to the device.   @param  NumberOfBytes         On input, the number of bytes to map.                                 On output, the number of bytes that were mapped.   @param  DeviceAddress         The resulting map address for the bus master device to use to access the                                 hosts HostAddress.   @param  Mapping               A resulting value to pass to Unmap().    @retval EFI_SUCCESS           The range was mapped for the returned NumberOfBytes.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.         @retval EFI_UNSUPPORTED       The HostAddress cannot be mapped as a common buffer.   @retval EFI_INVALID_PARAMETER The Operation or HostAddress is undefined.   @retval EFI_DEVICE_ERROR      The system hardware could not map the requested address.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IO_MAP
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IO_OPERATION_TYPE
name|Operation
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
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
comment|/**                                                                    Completes the Map() operation and releases any corresponding resources.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.   @param  Mapping               A resulting value to pass to Unmap().    @retval EFI_SUCCESS           The range was mapped for the returned NumberOfBytes.   @retval EFI_DEVICE_ERROR      The system hardware could not map the requested address.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IO_UNMAP
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
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
comment|/**                                                                    Allocates pages that are suitable for an EFIBusMasterCommonBuffer mapping.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.   @param  Type                  The type allocation to perform.   @param  MemoryType            The type of memory to allocate, EfiBootServicesData or                                 EfiRuntimeServicesData.   @param  Pages                 The number of pages to allocate.   @param  HostAddress           A pointer to store the base address of the allocated range.                                    @retval EFI_SUCCESS           The requested memory pages were allocated.   @retval EFI_OUT_OF_RESOURCES  The memory pages could not be allocated.   @retval EFI_INVALID_PARAMETER The requested memory type is invalid.   @retval EFI_UNSUPPORTED       The requested HostAddress is not supported on                                 this platform.                                                                    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IO_ALLOCATE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
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
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|HostAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Flushes any posted write data to the device.        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.    @retval EFI_SUCCESS           The buffers were flushed.   @retval EFI_DEVICE_ERROR      The buffers were not flushed due to a hardware error.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IO_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Frees pages that were allocated with AllocateBuffer().        @param  This                  A pointer to the EFI_DEVICE_IO_INTERFACE instance.     @param  Pages                 The number of pages to free.   @param  HostAddress           The base address of the range to free.    @retval EFI_SUCCESS           The requested memory pages were allocated.   @retval EFI_NOT_FOUND         The requested memory pages were not allocated with                                 AllocateBuffer().     @retval EFI_INVALID_PARAMETER HostAddress is not page aligned or Pages is invalid.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IO_FREE_BUFFER
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Pages
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|HostAddress
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the basic Memory, I/O, and PCI interfaces that
end_comment

begin_comment
comment|/// are used to abstract accesses to devices.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DEVICE_IO_PROTOCOL
block|{
comment|///
comment|/// Allows reads and writes to memory mapped I/O space.
comment|///
name|EFI_IO_ACCESS
name|Mem
decl_stmt|;
comment|///
comment|/// Allows reads and writes to I/O space.
comment|///
name|EFI_IO_ACCESS
name|Io
decl_stmt|;
comment|///
comment|/// Allows reads and writes to PCI configuration space.
comment|///
name|EFI_IO_ACCESS
name|Pci
decl_stmt|;
name|EFI_IO_MAP
name|Map
decl_stmt|;
name|EFI_PCI_DEVICE_PATH
name|PciDevicePath
decl_stmt|;
name|EFI_IO_UNMAP
name|Unmap
decl_stmt|;
name|EFI_IO_ALLOCATE_BUFFER
name|AllocateBuffer
decl_stmt|;
name|EFI_IO_FLUSH
name|Flush
decl_stmt|;
name|EFI_IO_FREE_BUFFER
name|FreeBuffer
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDeviceIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

