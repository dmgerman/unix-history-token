begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file describes the PPI which notifies other drivers    of the PEIM being initialized by the PEI Dispatcher.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LOADED_IMAGE_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__LOADED_IMAGE_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_LOADED_IMAGE_PPI_GUID
define|\
value|{ 0xc1fcd448, 0x6300, 0x4458, { 0xb8, 0x64, 0x28, 0xdf, 0x1, 0x53, 0x64, 0xbc } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_LOADED_IMAGE_PPI
name|EFI_PEI_LOADED_IMAGE_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This interface is installed by the PEI Dispatcher after the image has been
end_comment

begin_comment
comment|/// loaded and after all security checks have been performed,
end_comment

begin_comment
comment|/// to notify other PEIMs of the files which are being loaded.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_LOADED_IMAGE_PPI
block|{
comment|///
comment|/// Address of the image at the address where it will be executed.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|ImageAddress
decl_stmt|;
comment|///
comment|/// Size of the image as it will be executed.
comment|///
name|UINT64
name|ImageSize
decl_stmt|;
comment|///
comment|/// File handle from which the image was loaded.
comment|/// Can be NULL, indicating the image was not loaded from a handle.
comment|///
name|EFI_PEI_FILE_HANDLE
name|FileHandle
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiLoadedImagePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

