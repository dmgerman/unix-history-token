begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This files describes the CPU I/O 2 Protocol.      This protocol provides an I/O abstraction for a system processor. This protocol   is used by a PCI root bridge I/O driver to perform memory-mapped I/O and I/O transactions.   The I/O or memory primitives can be used by the consumer of the protocol to materialize   bus-specific configuration cycles, such as the transitional configuration address and data   ports for PCI. Only drivers that require direct access to the entire system should use this    protocol.       Note: This is a boot-services only protocol and it may not be used by runtime drivers after   ExitBootServices(). It is different from the Framework CPU I/O Protocol, which is a runtime   protocol and can be used by runtime drivers after ExitBootServices().    Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CPU_IO2_H__
end_ifndef

begin_define
define|#
directive|define
name|__CPU_IO2_H__
end_define

begin_define
define|#
directive|define
name|EFI_CPU_IO2_PROTOCOL_GUID
define|\
value|{ \     0xad61f191, 0xae5f, 0x4c0e, {0xb9, 0xfa, 0xe8, 0x69, 0xd2, 0x88, 0xc6, 0x4f} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_CPU_IO2_PROTOCOL
name|EFI_CPU_IO2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration that defines the width of the I/O operation.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiCpuIoWidthUint8
block|,
name|EfiCpuIoWidthUint16
block|,
name|EfiCpuIoWidthUint32
block|,
name|EfiCpuIoWidthUint64
block|,
name|EfiCpuIoWidthFifoUint8
block|,
name|EfiCpuIoWidthFifoUint16
block|,
name|EfiCpuIoWidthFifoUint32
block|,
name|EfiCpuIoWidthFifoUint64
block|,
name|EfiCpuIoWidthFillUint8
block|,
name|EfiCpuIoWidthFillUint16
block|,
name|EfiCpuIoWidthFillUint32
block|,
name|EfiCpuIoWidthFillUint64
block|,
name|EfiCpuIoWidthMaximum
block|}
name|EFI_CPU_IO_PROTOCOL_WIDTH
typedef|;
end_typedef

begin_comment
comment|/**   Enables a driver to access registers in the PI CPU I/O space.     The Io.Read() and Io.Write() functions enable a driver to access PCI controller    registers in the PI CPU I/O space.     The I/O operations are carried out exactly as requested. The caller is responsible    for satisfying any alignment and I/O width restrictions that a PI System on a    platform might require. For example on some platforms, width requests of    EfiCpuIoWidthUint64 do not work. Misaligned buffers, on the other hand, will    be handled by the driver.      If Width is EfiCpuIoWidthUint8, EfiCpuIoWidthUint16, EfiCpuIoWidthUint32,    or EfiCpuIoWidthUint64, then both Address and Buffer are incremented for    each of the Count operations that is performed.      If Width is EfiCpuIoWidthFifoUint8, EfiCpuIoWidthFifoUint16,    EfiCpuIoWidthFifoUint32, or EfiCpuIoWidthFifoUint64, then only Buffer is    incremented for each of the Count operations that is performed. The read or    write operation is performed Count times on the same Address.      If Width is EfiCpuIoWidthFillUint8, EfiCpuIoWidthFillUint16,    EfiCpuIoWidthFillUint32, or EfiCpuIoWidthFillUint64, then only Address is    incremented for each of the Count operations that is performed. The read or    write operation is performed Count times from the first element of Buffer.    @param[in]       This     A pointer to the EFI_CPU_IO2_PROTOCOL instance.   @param[in]       Width    Signifies the width of the I/O or Memory operation.   @param[in]       Address  The base address of the I/O operation.    @param[in]       Count    The number of I/O operations to perform. The number                              of bytes moved is Width size * Count, starting at Address.   @param[in, out]  Buffer   For read operations, the destination buffer to store the results.                             For write operations, the source buffer from which to write data.    @retval EFI_SUCCESS            The data was read from or written to the PI system.   @retval EFI_INVALID_PARAMETER  Width is invalid for this PI system.   @retval EFI_INVALID_PARAMETER  Buffer is NULL.   @retval EFI_UNSUPPORTED        The Buffer is not aligned for the given Width.   @retval EFI_UNSUPPORTED        The address range specified by Address, Width,                                   and Count is not valid for this PI system.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CPU_IO_PROTOCOL_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|EFI_CPU_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// Service for read and write accesses.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This service provides the various modalities of memory and I/O read.
comment|///
name|EFI_CPU_IO_PROTOCOL_IO_MEM
name|Read
decl_stmt|;
comment|///
comment|/// This service provides the various modalities of memory and I/O write.
comment|///
name|EFI_CPU_IO_PROTOCOL_IO_MEM
name|Write
decl_stmt|;
block|}
name|EFI_CPU_IO_PROTOCOL_ACCESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the basic memory and I/O interfaces that are used to abstract
end_comment

begin_comment
comment|/// accesses to devices in a system.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_CPU_IO2_PROTOCOL
block|{
comment|///
comment|/// Enables a driver to access memory-mapped registers in the EFI system memory space.
comment|///
name|EFI_CPU_IO_PROTOCOL_ACCESS
name|Mem
decl_stmt|;
comment|///
comment|/// Enables a driver to access registers in the EFI CPU I/O space.
comment|///
name|EFI_CPU_IO_PROTOCOL_ACCESS
name|Io
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCpuIo2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

