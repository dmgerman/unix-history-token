begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal include file of DXE CPU IO2 Library.      Copyright (c) 2010, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2017, AMD Incorporated. All rights reserved.<BR>    This program and the accompanying materials are licensed and made available   under the terms and conditions of the BSD License which accompanies this   distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DXE_CPUIO2_LIB_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DXE_CPUIO2_LIB_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/CpuIo2.h>
end_include

begin_include
include|#
directive|include
file|<Library/IoLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_comment
comment|/**   Reads registers in the EFI CPU I/O space.    Reads the I/O port specified by Port with registers width specified by Width.   The read value is returned.    This function must guarantee that all I/O read and write operations are serialized.   If such operations are not supported, then ASSERT().    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.    @return Data read from registers in the EFI CPU I/O space.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoReadWorker
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes registers in the EFI CPU I/O space.    Writes the I/O port specified by Port with registers width and value specified by Width   and Data respectively. Data is returned.    This function must guarantee that all I/O read and write operations are serialized.   If such operations are not supported, then ASSERT().    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.   @param  Data          The value to write to the I/O port.    @return The parameter of Data.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|IoWriteWorker
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads registers in the EFI CPU I/O space.    Reads the I/O port specified by Port with registers width specified by Width.   The port is read Count times, and the read data is stored in the provided Buffer.    This function must guarantee that all I/O read and write operations are serialized.   If such operations are not supported, then ASSERT().    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.   @param  Count         The number of times to read I/O port.   @param  Buffer        The buffer to store the read data into.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoReadFifoWorker
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes registers in the EFI CPU I/O space.    Writes the I/O port specified by Port with registers width specified by Width.   The port is written Count times, and the write data is retrieved from the provided Buffer.    This function must guarantee that all I/O read and write operations are serialized.   If such operations are not supported, then ASSERT().    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.   @param  Count         The number of times to write I/O port.   @param  Buffer        The buffer to store the read data into.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|IoWriteFifoWorker
parameter_list|(
name|IN
name|UINTN
name|Port
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads memory-mapped registers in the EFI system memory space.    Reads the MMIO registers specified by Address with registers width specified by Width.   The read value is returned. If such operations are not supported, then ASSERT().   This function must guarantee that all MMIO read and write operations are serialized.    @param  Address       The MMIO register to read.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.    @return Data read from registers in the EFI system memory space.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioReadWorker
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes memory-mapped registers in the EFI system memory space.    Writes the MMIO registers specified by Address with registers width and value specified by Width   and Data respectively. Data is returned. If such operations are not supported, then ASSERT().   This function must guarantee that all MMIO read and write operations are serialized.    @param  Address       The MMIO register to read.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.   @param  Data          The value to write to the I/O port.      @return Data read from registers in the EFI system memory space.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|MmioWriteWorker
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|EFI_CPU_IO_PROTOCOL_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

