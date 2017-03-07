begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI provides a set of memory and I/O-based services.    The perspective of the services is that of the processor, not the bus or system.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.0.    **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_CPUIO_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_CPUIO_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_CPU_IO_PPI_INSTALLED_GUID
define|\
value|{ 0xe6af1f7b, 0xfc3f, 0x46da, {0xa8, 0x28, 0xa3, 0xb4, 0x57, 0xa4, 0x42, 0x82 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_CPU_IO_PPI
name|EFI_PEI_CPU_IO_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_CPU_IO_PPI_WIDTH.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiPeiCpuIoWidthUint8
block|,
name|EfiPeiCpuIoWidthUint16
block|,
name|EfiPeiCpuIoWidthUint32
block|,
name|EfiPeiCpuIoWidthUint64
block|,
name|EfiPeiCpuIoWidthFifoUint8
block|,
name|EfiPeiCpuIoWidthFifoUint16
block|,
name|EfiPeiCpuIoWidthFifoUint32
block|,
name|EfiPeiCpuIoWidthFifoUint64
block|,
name|EfiPeiCpuIoWidthFillUint8
block|,
name|EfiPeiCpuIoWidthFillUint16
block|,
name|EfiPeiCpuIoWidthFillUint32
block|,
name|EfiPeiCpuIoWidthFillUint64
block|,
name|EfiPeiCpuIoWidthMaximum
block|}
name|EFI_PEI_CPU_IO_PPI_WIDTH
typedef|;
end_typedef

begin_comment
comment|/**   Memory-based access services and I/O-based access services.    @param[in]      PeiServices  An indirect pointer to the PEI Services Table                                published by the PEI Foundation.   @param[in]      This         The pointer to local data for the interface.   @param[in]      Width        The width of the access. Enumerated in bytes.   @param[in]      Address      The physical address of the access.   @param[in]      Count        The number of accesses to perform.   @param[in, out] Buffer       A pointer to the buffer of data.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_NOT_YET_AVAILABLE  The service has not been installed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_MEM
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PEI_CPU_IO_PPI_WIDTH
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
comment|/// EFI_PEI_CPU_IO_PPI_ACCESS
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
name|EFI_PEI_CPU_IO_PPI_IO_MEM
name|Read
decl_stmt|;
comment|///
comment|/// This service provides the various modalities of memory and I/O write.
comment|///
name|EFI_PEI_CPU_IO_PPI_IO_MEM
name|Write
decl_stmt|;
block|}
name|EFI_PEI_CPU_IO_PPI_ACCESS
typedef|;
end_typedef

begin_comment
comment|/**   8-bit I/O read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  An 8-bit value returned from the I/O space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT8
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_READ8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   16-bit I/O read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 16-bit value returned from the I/O space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT16
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_READ16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   32-bit I/O read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 32-bit value returned from the I/O space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_READ32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   64-bit I/O read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 64-bit value returned from the I/O space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT64
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_READ64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   8-bit I/O write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_WRITE8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   16-bit I/O write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_WRITE16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   32-bit I/O write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_WRITE32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   64-bit I/O write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_IO_WRITE64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT64
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   8-bit memory read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  An 8-bit value returned from the memory space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT8
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_READ8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   16-bit memory read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 16-bit value returned from the memory space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT16
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_READ16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   32-bit memory read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 32-bit value returned from the memory space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_READ32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   64-bit memory read operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.    @return  A 64-bit value returned from the memory space.  **/
end_comment

begin_typedef
typedef|typedef
name|UINT64
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_READ64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   8-bit memory write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE8
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   16-bit memory write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE16
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   32-bit memory write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE32
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   64-bit memory write operations.    @param[in] PeiServices  An indirect pointer to the PEI Services Table published                            by the PEI Foundation.   @param[in] This         The pointer to local data for the interface.   @param[in] Address      The physical address of the access.   @param[in] Data         The data to write.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE64
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|CONST
name|EFI_PEI_CPU_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT64
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_CPU_IO_PPI provides a set of memory and I/O-based services.
end_comment

begin_comment
comment|/// The perspective of the services is that of the processor, not that of the
end_comment

begin_comment
comment|/// bus or system.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_CPU_IO_PPI
block|{
comment|///
comment|/// Collection of memory-access services.
comment|///
name|EFI_PEI_CPU_IO_PPI_ACCESS
name|Mem
decl_stmt|;
comment|///
comment|/// Collection of I/O-access services.
comment|///
name|EFI_PEI_CPU_IO_PPI_ACCESS
name|Io
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_READ8
name|IoRead8
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_READ16
name|IoRead16
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_READ32
name|IoRead32
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_READ64
name|IoRead64
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_WRITE8
name|IoWrite8
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_WRITE16
name|IoWrite16
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_WRITE32
name|IoWrite32
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_IO_WRITE64
name|IoWrite64
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_READ8
name|MemRead8
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_READ16
name|MemRead16
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_READ32
name|MemRead32
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_READ64
name|MemRead64
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE8
name|MemWrite8
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE16
name|MemWrite16
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE32
name|MemWrite32
decl_stmt|;
name|EFI_PEI_CPU_IO_PPI_MEM_WRITE64
name|MemWrite64
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiCpuIoPpiInstalledGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

