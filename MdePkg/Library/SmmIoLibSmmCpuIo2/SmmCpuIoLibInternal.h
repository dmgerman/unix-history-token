begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal include file of SMM CPU IO Library.   It includes all necessary protocol/library class's header file   for implementation of IoLib library instance. It is included    all source code of this library instance.      Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_CPUIO_LIB_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_CPUIO_LIB_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|<PiSmm.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SmmCpuIo2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SmmPciRootBridgeIo.h>
end_include

begin_include
include|#
directive|include
file|<Library/IoLib.h>
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

begin_include
include|#
directive|include
file|<Library/SmmServicesTableLib.h>
end_include

begin_comment
comment|/**   Reads registers in the EFI CPU I/O space.    Reads the I/O port specified by Port with registers width specified by Width.   The read value is returned. If such operations are not supported, then ASSERT().   This function must guarantee that all I/O read and write operations are serialized.    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.    @return Data read from registers in the EFI CPU I/O space.  **/
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
name|EFI_SMM_IO_WIDTH
name|Width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes registers in the EFI CPU I/O space.    Writes the I/O port specified by Port with registers width and value specified by Width   and Data respectively.  Data is returned. If such operations are not supported, then ASSERT().   This function must guarantee that all I/O read and write operations are serialized.    @param  Port          The base address of the I/O operation.                         The caller is responsible for aligning the Address if required.   @param  Width         The width of the I/O operation.   @param  Data          The value to write to the I/O port.    @return The parameter of Data.  **/
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
name|EFI_SMM_IO_WIDTH
name|Width
parameter_list|,
name|IN
name|UINT64
name|Data
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
name|EFI_SMM_IO_WIDTH
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
name|EFI_SMM_IO_WIDTH
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

