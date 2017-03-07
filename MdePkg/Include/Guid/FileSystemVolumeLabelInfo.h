begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a GUID and a data structure that can be used with EFI_FILE_PROTOCOL.GetInfo()   or EFI_FILE_PROTOCOL.SetInfo() to get or set the system's volume label.   This GUID is defined in UEFI specification.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FILE_SYSTEM_VOLUME_LABEL_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__FILE_SYSTEM_VOLUME_LABEL_INFO_H__
end_define

begin_define
define|#
directive|define
name|EFI_FILE_SYSTEM_VOLUME_LABEL_ID
define|\
value|{ \     0xDB47D7D3, 0xFE81, 0x11d3, {0x9A, 0x35, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Null-terminated string that is the volume's label.
comment|///
name|CHAR16
name|VolumeLabel
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_FILE_SYSTEM_VOLUME_LABEL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIZE_OF_EFI_FILE_SYSTEM_VOLUME_LABEL
define|\
value|OFFSET_OF (EFI_FILE_SYSTEM_VOLUME_LABEL, VolumeLabel)
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFileSystemVolumeLabelInfoIdGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

