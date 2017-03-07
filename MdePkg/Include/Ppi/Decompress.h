begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides decompression services to the PEI Foundatoin.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DECOMPRESS_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__DECOMPRESS_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_DECOMPRESS_PPI_GUID
define|\
value|{ 0x1a36e4e7, 0xfab6, 0x476a, { 0x8e, 0x75, 0x69, 0x5a, 0x5, 0x76, 0xfd, 0xd7 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_DECOMPRESS_PPI
name|EFI_PEI_DECOMPRESS_PPI
typedef|;
end_typedef

begin_comment
comment|/**    Decompress a single compression section in a firmware file.                                                                   Decompresses the data in a compressed section and returns it   as a series of standard PI Firmware File Sections. The   required memory is allocated from permanent memory.    @param This                   Points to this instance of the                                 EFI_PEI_DECOMPRESS_PEI PPI.   @param InputSection           Points to the compressed section.   @param OutputBuffer           Holds the returned pointer to the                                 decompressed sections.   @param OutputSize             Holds the returned size of the decompress                                 section streams.    @retval EFI_SUCCESS           The section was decompressed                                 successfully. OutputBuffer contains the                                 resulting data and OutputSize contains                                 the resulting size.   @retval EFI_OUT_OF_RESOURCES  Unable to allocate sufficient                                 memory to hold the decompressed data.   @retval EFI_UNSUPPORTED       The compression type specified                                 in the compression header is unsupported.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_DECOMPRESS_DECOMPRESS
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PEI_DECOMPRESS_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_COMPRESSION_SECTION
modifier|*
name|InputSection
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|OutputBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|OutputSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI's single member function decompresses a compression
end_comment

begin_comment
comment|/// encapsulated section. It is used by the PEI Foundation to
end_comment

begin_comment
comment|/// process sectioned files. Prior to the installation of this PPI,
end_comment

begin_comment
comment|/// compression sections will be ignored.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_DECOMPRESS_PPI
block|{
name|EFI_PEI_DECOMPRESS_DECOMPRESS
name|Decompress
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiDecompressPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

