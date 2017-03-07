begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM CPU I/O 2 protocol as defined in the PI 1.2 specification.    This protocol provides CPU I/O and memory access within SMM.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_CPU_IO2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_CPU_IO2_H_
end_define

begin_define
define|#
directive|define
name|EFI_SMM_CPU_IO2_PROTOCOL_GUID
define|\
value|{ \     0x3242A9D8, 0xCE70, 0x4AA0, { 0x95, 0x5D, 0x5E, 0x7B, 0x14, 0x0D, 0xE4, 0xD2 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_CPU_IO2_PROTOCOL
name|EFI_SMM_CPU_IO2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Width of the SMM CPU I/O operations
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SMM_IO_UINT8
init|=
literal|0
block|,
name|SMM_IO_UINT16
init|=
literal|1
block|,
name|SMM_IO_UINT32
init|=
literal|2
block|,
name|SMM_IO_UINT64
init|=
literal|3
block|}
name|EFI_SMM_IO_WIDTH
typedef|;
end_typedef

begin_comment
comment|/**   Provides the basic memory and I/O interfaces used toabstract accesses to devices.    The I/O operations are carried out exactly as requested.  The caller is    responsible for any alignment and I/O width issues that the bus, device,    platform, or type of I/O might require.    @param[in]      This     The EFI_SMM_CPU_IO2_PROTOCOL instance.   @param[in]      Width    Signifies the width of the I/O operations.   @param[in]      Address  The base address of the I/O operations.  The caller is                             responsible for aligning the Address if required.    @param[in]      Count    The number of I/O operations to perform.   @param[in,out]  Buffer   For read operations, the destination buffer to store                             the results.  For write operations, the source buffer                             from which to write data.    @retval EFI_SUCCESS            The data was read from or written to the device.   @retval EFI_UNSUPPORTED        The Address is not valid for this system.   @retval EFI_INVALID_PARAMETER  Width or Count, or both, were invalid.   @retval EFI_OUT_OF_RESOURCES   The request could not be completed due to a lack                                  of resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_CPU_IO2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_CPU_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMM_IO_WIDTH
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
comment|/// This service provides the various modalities of memory and I/O read.
comment|///
name|EFI_SMM_CPU_IO2
name|Read
decl_stmt|;
comment|///
comment|/// This service provides the various modalities of memory and I/O write.
comment|///
name|EFI_SMM_CPU_IO2
name|Write
decl_stmt|;
block|}
name|EFI_SMM_IO_ACCESS2
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SMM CPU I/O Protocol provides CPU I/O and memory access within SMM.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_CPU_IO2_PROTOCOL
block|{
comment|///
comment|/// Allows reads and writes to memory-mapped I/O space.
comment|///
name|EFI_SMM_IO_ACCESS2
name|Mem
decl_stmt|;
comment|///
comment|/// Allows reads and writes to I/O space.
comment|///
name|EFI_SMM_IO_ACCESS2
name|Io
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmCpuIo2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

