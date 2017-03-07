begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guids used for the GPT (GUID Partition Table)    GPT defines a new disk partitioning scheme and also describes    usage of the legacy Master Boot Record (MBR) partitioning scheme.     Copyright (c) 2006 - 2007, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs defined in UEFI 2.1 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GPT_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__GPT_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_PART_TYPE_UNUSED_GUID
define|\
value|{ \     0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_PART_TYPE_EFI_SYSTEM_PART_GUID
define|\
value|{ \     0xc12a7328, 0xf81f, 0x11d2, {0xba, 0x4b, 0x00, 0xa0, 0xc9, 0x3e, 0xc9, 0x3b } \   }
end_define

begin_define
define|#
directive|define
name|EFI_PART_TYPE_LEGACY_MBR_GUID
define|\
value|{ \     0x024dee41, 0x33e7, 0x11d3, {0x9d, 0x69, 0x00, 0x08, 0xc7, 0x81, 0xf3, 0x9f } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPartTypeUnusedGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPartTypeSystemPartGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPartTypeLegacyMbrGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

